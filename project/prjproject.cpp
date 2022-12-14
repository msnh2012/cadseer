/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2015  Thomas S. Anderson blobfish.at.gmx.com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <assert.h>
#include <iostream>
#include <stack>

#include <QTextStream>

#include <boost/graph/topological_sort.hpp>
#include <boost/graph/filtered_graph.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/signals2/shared_connection_block.hpp>
#include <boost/filesystem.hpp>
#include <boost/optional.hpp>
#include <boost/current_function.hpp>

#include <BRep_Builder.hxx>
#include <BRepTools.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <TopoDS.hxx>

#include <osg/ValueObject>

#include "application/appapplication.h"
#include "globalutilities.h"
#include "tools/idtools.h"
#include "tools/occtools.h"
#include "feature/ftrbase.h"
#include "annex/annseershape.h"
#include "annex/anncsysdragger.h"
#include "feature/ftrinert.h"
#include "feature/ftrmessage.h"
#include "parameter/prmparameter.h"
#include "message/msgmessage.h"
#include "project/prjmessage.h"
#include "tools/graphtools.h"
#include "tools/tlsnameindexer.h"
#include "project/prjfeatureload.h"
// #include "project/serial/xsdcxxoutput/shapehistory.h"
#include "project/serial/generated/prjsrlprjsproject.h"
#include "project/prjstow.h"
#include "project/prjproject.h"

using namespace boost::filesystem;

using namespace prj;
using boost::uuids::uuid;

Project::Project()
: stow(new Stow(*this))
{
  
}

Project::~Project() = default;

QTextStream& Project::getInfo(QTextStream &stream) const
{
  stream
  << QObject::tr("Project Directory: ") << QString::fromStdString(getSaveDirectory().string()) << Qt::endl;
  //maybe some git stuff.
  
  stow->expressionManager.getInfo(stream);
  
  return stream;
}

expr::Manager& Project::getManager()
{
  return stow->expressionManager;
}

GitManager& Project::getGitManager()
{
  return stow->gitManager;
}

void Project::updateModel()
{
  stow->node.send(msg::Message(msg::Response | msg::Pre | msg::Project | msg::Update | msg::Model));
  
  Vertices sorted;
  try
  {
//     indexVerticesEdges();
    boost::topological_sort(stow->graph, std::back_inserter(sorted));
  }
  catch(const boost::not_a_dag &)
  {
    std::cout << std::endl << "Graph is not a dag exception in Project::updateModel()" << std::endl << std::endl;
    return;
  }
  
  //the update of a feature will trigger a state change signal.
  //we don't want to handle that state change here in the project
  //so we block.
  auto block = stow->node.createBlocker();
  
  stow->shapeHistory.clear(); //reset history structure.
  
  //loop through and update each feature.
  for (auto it = sorted.rbegin(); it != sorted.rend(); ++it)
  {
    Vertex currentVertex = *it;
    ftr::Base *cFeature = stow->graph[currentVertex].feature.get();
    
    if (!stow->graph[currentVertex].alive)
      continue;
    
    if
    (
      (cFeature->isModelClean()) ||
      (stow->isFeatureInactive(currentVertex))
    )
    {
      cFeature->fillInHistory(stow->shapeHistory);
      continue;
    }
    
    std::ostringstream messageStream;
    messageStream << "Updating: " << cFeature->getName().toStdString() << "    Id: " << gu::idToShortString(cFeature->getId());
    stow->node.send(msg::buildStatusMessage(messageStream.str()));
    qApp->processEvents(); //need this or we won't see messages.
    
    RemovedGraph removedGraph = buildRemovedGraph(stow->graph);
    ReversedGraph reversedGraph = boost::make_reverse_graph(removedGraph);
    ftr::UpdatePayload::UpdateMap updateMap =
    buildAjacentUpdateMap
    <
      ReversedGraph,
      boost::graph_traits<ReversedGraph>::vertex_descriptor
    >(reversedGraph, currentVertex);
    
    ftr::UpdatePayload payload(updateMap, stow->shapeHistory);
    cFeature->updateModel(payload);
    cFeature->serialWrite(stow->saveDirectory);
    cFeature->fillInHistory(stow->shapeHistory);
  }
  
  stow->updateLeafStatus();
  serialWrite();
  /* this is here to give others a chance to make changes before git makes a commit.
   * if this causes problems, then we will want git manager to use more messaging.
   */
  stow->node.send(msg::Message(msg::Response | msg::Post | msg::Project | msg::Update | msg::Model));
  stow->gitManager.update();
  
//   stow->shapeHistory.writeGraphViz("/home/tanderson/.CadSeer/ShapeHistory.dot");
  
  stow->node.send(msg::buildStatusMessage("Model Update Complete", 2.0));
}

void Project::updateVisual()
{
  //if we have selection and then destroy the geometry when the
  //the visual updates, things get out of sync. so clear the selection.
  stow->node.send(msg::Message(msg::Request | msg::Selection | msg::Clear));
  stow->node.send(msg::Message(msg::Response | msg::Pre | msg::Project | msg::Update | msg::Visual));
  
  auto block = stow->node.createBlocker();
  
  //don't think we need to topo sort for visual.
  for(auto its = boost::vertices(stow->graph); its.first != its.second; ++its.first)
  {
    if (!stow->graph[*its.first].alive)
      continue;
    auto *feature = stow->graph[*its.first].feature.get();
    if
    (
      feature->isModelClean() &&
      feature->isVisible3D() &&
      stow->isFeatureActive(*its.first) &&
//       feature->isSuccess() && //regenerate from parent shape on failure.
      feature->isVisualDirty()
    )
      feature->updateVisual();
  }
  
  stow->node.send(msg::Message(msg::Response | msg::Post | msg::Project | msg::Update | msg::Visual));
  
  stow->node.send(msg::buildStatusMessage("Visual Update Complete", 2.0));
}

void Project::writeGraphViz(const std::string& fileName)
{
  stow->writeGraphViz(fileName);
}

void Project::readOCC(const std::string &fileName)
{
  TopoDS_Shape base;
  BRep_Builder junk;
  std::fstream file(fileName.c_str());
  BRepTools::Read(base, file, junk);
  
  boost::filesystem::path p = fileName;
  addOCCShape(base, p.stem().string());
}

bool Project::hasFeature(const boost::uuids::uuid &idIn) const
{
  return stow->hasFeature(idIn);
}

ftr::Base* Project::findFeature(const uuid &idIn) const
{
  return stow->findFeature(idIn);
}

prm::Parameter* Project::findParameter(const uuid &idIn) const
{
  return stow->findParameter(idIn);
}

void Project::addOCCShape(const TopoDS_Shape &shapeIn, std::string name)
{
  if (name.empty())
    name = QObject::tr("Dummy").toStdString();
  occt::ShapeVector shapes = occt::getNonCompounds(shapeIn);
  
  auto addShape = [&](const TopoDS_Shape &shapeIn, const std::string &nameIn)
  {
    auto inert = std::make_unique<ftr::Inert::Feature>(shapeIn);
    addFeature(std::move(inert))->setName(QString::fromStdString(nameIn));
  };
  
  if (shapes.empty())
    return;
  else if (shapes.size() == 1)
  {
    if (shapes.front().IsNull())
      return;
    addShape(shapes.front(), name);
    return;
  }
  
  tls::NameIndexer ni(shapes.size());
  for (const auto &s : shapes)
  {
    if (s.IsNull())
    {
      ni.bump(); //to show the skipped item.
      continue;
    }
    addShape(s, name + "_" + ni.buildSuffix());
  }
}

ftr::Base* Project::addFeature(std::unique_ptr<ftr::Base> feature)
{
  //no pre message.
  auto nfv = stow->addFeature(std::move(feature));
  
  //log action to git if not loading.
  if (!stow->isLoading)
  {
    std::ostringstream gitMessage;
    gitMessage << QObject::tr("Adding feature ").toStdString() << stow->graph[nfv].feature->getTypeString();
    stow->gitManager.appendGitMessage(gitMessage.str());
  }
  
  prj::Message pMessage;
  pMessage.feature = stow->graph[nfv].feature.get();
  msg::Message postMessage
  (
    msg::Response | msg::Post | msg::Add | msg::Feature
    , pMessage
  );
  stow->node.send(postMessage);
  return stow->graph[nfv].feature.get();
}

void Project::removeFeature(const uuid& idIn)
{
  Vertex vertex = stow->findVertex(idIn);
  stow->graph[vertex].feature->setModelDirty(); //this will make all children dirty. Do before block.
  
  //shouldn't need anymore messages into project for this function call.
  auto block = stow->node.createBlocker().front();
  
  auto workGraph = buildRemovedSeveredGraph(stow->graph); //removed and Severed
  auto workGraphReversed = boost::make_reverse_graph(workGraph);
  
  //results are based upon parent and child count and create vs alter feature. See delete.svg
  //note that we counting from a 'severed' graph.
  auto parentCount = boost::in_degree(vertex, workGraph);
//   std::cout << "parent count: " << parentCount << std::endl;
//   auto childCount = boost::out_degree(vertex, workGraph);
  
  
  //edge from parent to self will be deleted.
  //edge from self to child will be removed and replace with edge from parent to child with copied tags.
  //parent child refer to forward graph.
  //only one level deep! No skipping of 'generations'.
  auto switchChildToParent = [&](Vertex parent, Vertex self, Vertex child)
  {
    auto parentEdgePair = boost::edge(parent, self, workGraph);
    assert(parentEdgePair.second); //don't set me up
    Edge parentEdge = parentEdgePair.first;
    auto childEdgePair = boost::edge(self, child, workGraph);
    assert(childEdgePair.second); //don't set me up
    Edge childEdge = childEdgePair.first;
    
    auto input = workGraph[childEdge].inputType;
    stow->disconnect(parentEdge);
    stow->disconnect(childEdge);
    stow->connect(parent, child, input);
  };
  
  //log action to git.
  auto removeGitMessage = [&](Vertex vIn)
  {
    std::ostringstream gitMessage;
    const auto *lf = stow->graph[vIn].feature.get();
    gitMessage
      << QObject::tr("Removing feature ").toStdString()
      << lf->getName().toStdString()
      << ". With id: "
      << gu::idToShortString(lf->getId());
    stow->gitManager.appendGitMessage(gitMessage.str());
  };
  
  //remove file if exists.
  auto removeFile = [&](Vertex vIn)
  {
    assert(exists(stow->saveDirectory));
    path filePath = stow->saveDirectory / stow->graph[vIn].feature->getFileName();
    if (exists(filePath))
      remove(filePath);
  };
  
  //bundle of calls for remove operation
  auto localRemove = [&](Vertex vIn)
  {
    removeGitMessage(vIn);
    stow->clearVertex(vIn);
    stow->removeFeature(vIn);
    removeFile(vIn);
  };
  
  //we are not considering 'sever' edges with counts.
  //so there maybe actual 'sever' parents and or children and we have to clear those.
  if (parentCount == 0)
  {
    //we can't assume a feature with no parents is a create.
    //It might be an alter in a bad state and we don't want to walk an alter path like we do for create.
    if (workGraph[vertex].feature->getDescriptor() == ftr::Descriptor::Create)
    {
      std::vector<Vertex> alters(1, vertex); //also has the root vertex which is create.
      AlterVisitor av(alters, AlterVisitor::Create::Exclusion);
      boost::depth_first_search(workGraph, visitor(av).root_vertex(vertex));
      for (auto v : alters)
        localRemove(v);
    }
    else if (workGraph[vertex].feature->getDescriptor() == ftr::Descriptor::Alter) //what else could it be. future proof
    {
      //an alter with no parents is in a bad state. just delete it and don't walk alter path
      localRemove(vertex);
    }
  }
  else if (parentCount == 1)
  {
    Vertex parent = Graph::null_vertex();
    for (auto v : boost::make_iterator_range(boost::adjacent_vertices(vertex, workGraphReversed)))
    {
      parent = v;
      break;
    }
    assert(parent != Graph::null_vertex());
    
    if (workGraph[vertex].feature->getDescriptor() == ftr::Descriptor::Create)
    {
      std::vector<Vertex> alters(1, vertex); //also has the root vertex which is create.
      AlterVisitor av(alters, AlterVisitor::Create::Exclusion);
      boost::depth_first_search(workGraph, visitor(av).root_vertex(vertex));
      
      auto isAlter = [&](Vertex vIn) -> bool
      {
        for (auto v : alters)
        {
          if (v == vIn)
            return true;
        }
        return false;
      };
      
      //look for all child vertices of alters to connect back to parent.
      //notice we are using the original graph as we want 'sever' also.
      std::vector<std::pair<Edge, Vertex>> newChildren;
      for (auto v : alters)
      {
        for (auto oe : boost::make_iterator_range(boost::out_edges(v, stow->graph)))
        {
          auto cv = boost::target(oe, stow->graph);
          if (!isAlter(cv))
            newChildren.push_back(std::make_pair(oe, cv));
        }
      }
      
      for (auto p : newChildren)
        stow->connect(vertex, p.second, stow->graph[p.first].inputType);
      for (auto a : alters)
        localRemove(a);
    }
    else if (workGraph[vertex].feature->getDescriptor() == ftr::Descriptor::Alter) //what else could it be. future proof
    {
      for (auto cv : boost::make_iterator_range(boost::adjacent_vertices(vertex, workGraph)))
        switchChildToParent(parent, vertex, cv);
      localRemove(vertex);
    }
  }
  else //parent count > 1 and we don't know who to connect to. see delete.svg
  {
    if (workGraph[vertex].feature->getDescriptor() == ftr::Descriptor::Create)
    {
      std::vector<Vertex> alters(1, vertex); //also has the root vertex which is create.
      AlterVisitor av(alters, AlterVisitor::Create::Exclusion);
      boost::depth_first_search(workGraph, visitor(av).root_vertex(vertex));
      for (auto v : alters)
        localRemove(v);
    }
    else if (workGraph[vertex].feature->getDescriptor() == ftr::Descriptor::Alter) //what else could it be. future proof
    {
      //just remove the one alter and let features fail. User has to sort out.
      localRemove(vertex);
    }
  }
  
  //no post message.
  
  /* notes about rewrite 3/27/2020
   * 
   * Originally I had:
      //make parents have same visible state as the feature being removed.
      if (feature->isVisible3D())
      {
        block.unblock();
        stow->node.send(msg::buildShowThreeD(reversedGraph[*its.first].feature->getId()));
        block.block();
      }
      else
        stow->node.send(msg::buildHideThreeD(reversedGraph[*its.first].feature->getId()));
   * 
   * I don't think this was correct. How can we know what should be shown as we don't
   * know leaf status of other features. Left this out for now. Notice the call to 'unblock'
   * this is explained in 'setCurrentLeaf'.
   *
   * Originally I was using 'replaceId' from feature and seerShape. I believe this is
   * obsolete see "Id mapping:" in todo.txt
   */
}

void Project::setCurrentLeaf(const uuid& idIn)
{
  //sometimes the visual of a feature is dirty and doesn't get updated 
  //until we try to show it. However it might be selected meaning that
  //we will destroy the old geometry that is highlighted. So clear the seleciton.
  stow->node.send(msg::Message(msg::Request | msg::Selection | msg::Clear));
  
  //the visitor will be setting features to an inactive state which
  //triggers the signal and we would end up back into this->stateChangedSlot.
  //so we block all the connections to avoid this.
  auto block = stow->node.createBlocker().front();
  
  auto vertex = stow->findVertex(idIn);
  RemovedGraph removedGraph = buildRemovedGraph(stow->graph); //children
  ReversedGraph reversedGraph = boost::make_reverse_graph(removedGraph); //parents
  
  //parents
  Vertices aVertices;
  gu::BFSLimitVisitor<Vertex> activeVisitor(aVertices);
  boost::breadth_first_search(reversedGraph, vertex, boost::visitor(activeVisitor));
  
  //filter on the accumulated vertexes.
  gu::SubsetFilter<ReversedGraph> vertexFilter(reversedGraph, aVertices);
  typedef boost::filtered_graph<ReversedGraph, boost::keep_all, gu::SubsetFilter<ReversedGraph> > FilteredGraph;
  FilteredGraph fg(reversedGraph, boost::keep_all(), vertexFilter);
  
  for (auto its = boost::vertices(fg); its.first != its.second; ++its.first)
  {
    stow->setFeatureActive(*its.first);
    stow->node.send(msg::buildHideThreeD(stow->graph[*its.first].feature->getId()));
  }
  
  stow->setFeatureActive(vertex);
  //project is responsible for generating visuals, so buildShowThreeD
  //can cause us to be back her in project. in short, don't block.
  block.unblock();
  stow->node.send(msg::buildShowThreeD(stow->graph[vertex].feature->getId()));
  block.block();
  
  //children
  Vertices iVertices;
  gu::BFSLimitVisitor<Vertex> inactiveVisitor(iVertices);
  boost::breadth_first_search(removedGraph, vertex, boost::visitor(inactiveVisitor));
  for (const auto &v : iVertices)
  {
    if (v == vertex) //don't hide the new current.
      continue;
    stow->setFeatureInactive(v);
    stow->node.send(msg::buildHideThreeD(removedGraph[v].feature->getId()));
  }
  
  stow->updateLeafStatus();
}

void Project::connect(const boost::uuids::uuid& parentIn, const boost::uuids::uuid& childIn, const ftr::InputType &type)
{
  Vertex parent = stow->findVertex(parentIn);
  Vertex child = stow->findVertex(childIn);
  stow->connect(parent, child, type);
}

//inserts child between all parents current children that are 'alters'. note this uses a severed graph. Maybe it shouldn't?
void Project::connectInsert(const uuid& parentIn, const uuid& childIn, const ftr::InputType &type)
{
  Vertex parent = stow->findVertex(parentIn);
  Vertex child = stow->findVertex(childIn);
  
  ComboFilterVertex<Graph> vf(stow->graph); //filters for alive vertices by default.
  ComboFilterEdge<Graph> ef(stow->graph);
  ef.sever = true;
  boost::filtered_graph<Graph, decltype(ef), decltype(vf)> fg(stow->graph, ef, vf);
  
  //creation features don't get inserted
  if (fg[child].feature->getDescriptor() == ftr::Descriptor::Alter)
  {
    std::vector<Edge> edgesToRemove;
    for (auto av : boost::make_iterator_range(boost::adjacent_vertices(parent, fg)))
    {
      if (av == child)
        continue;
      if (fg[av].feature->getDescriptor() != ftr::Descriptor::Alter)
        continue;
      auto mce = boost::edge(parent, av, fg);
      assert(mce.second);
      Edge ce = mce.first;
      edgesToRemove.push_back(ce);
      stow->connect(child, av, fg[ce].inputType);
    }
    stow->removeEdges(edgesToRemove);
  }
  stow->connect(parent, child, type);
  stow->graph[child].feature->setModelDirty();
}

void Project::removeParentTag(const uuid &targetIn, const std::string &tagIn)
{
  RemovedGraph removedGraph = buildRemovedGraph(stow->graph); //children
  ReversedGraph reversedGraph = boost::make_reverse_graph(removedGraph); //parents
  
  Vertex vertex = stow->findVertex(targetIn);
  for (auto its = boost::adjacent_vertices(vertex, reversedGraph); its.first != its.second; ++its.first)
  {
    //edge references original graph. 'forward'. remove_edge wouldn't work on reversed graph.
    auto ce = boost::edge(*its.first, vertex, stow->graph);
    assert(ce.second);
    stow->graph[ce.first].inputType.remove(tagIn);
    if (stow->graph[ce.first].inputType.isEmpty())
      stow->disconnect(ce.first);
  }
}

void Project::clearAllInputs(const boost::uuids::uuid &idIn)
{
  Vertex vertex = stow->findVertex(idIn);
  Edges inEdges;
  for (auto its = boost::in_edges(vertex, stow->graph); its.first != its.second; ++its.first)
    inEdges.push_back(*its.first);
  stow->removeEdges(inEdges);
}

void Project::setAllVisualDirty()
{
  for (auto its = boost::vertices(stow->graph); its.first != its.second; ++its.first)
  {
    stow->graph[*its.first].feature->setVisualDirty();
  }
}

void Project::setColor(const boost::uuids::uuid &featureIdIn, const osg::Vec4 &colorIn)
{
  //this doesn't work can't go up and down and call it good. See document.svg
  Vertex baseVertex = stow->findVertex(featureIdIn);
  auto rmg = buildRemovedSeveredGraph(stow->graph);
  auto rvg = boost::make_reverse_graph(rmg);
  
  //walk down alters and filter and get leaves
  Vertices downVertices(1, baseVertex); //filter vertices.
  AlterVisitor downVisitor(downVertices, AlterVisitor::Create::Exclusion);
  boost::depth_first_search(rmg, visitor(downVisitor).root_vertex(baseVertex));
  ComboFilterVertex <decltype(rmg)> downFilter(rmg);
  downFilter.removed = false; //already done
  downFilter.vertexSubset = downVertices;
  boost::filtered_graph<decltype(rmg), boost::keep_all, decltype(downFilter)> downGraph(rmg, boost::keep_all(), downFilter);
  Vertices downLeaves;
  for (auto v : boost::make_iterator_range(boost::vertices(downGraph)))
  {
    if (boost::out_degree(v, downGraph) == 0)
      downLeaves.push_back(v);
  }
  
  //walk up from down leaves and filter using bfs.
  Vertices upFilterVertices;
  for (auto v : downLeaves)
  {
    gu::BFSLimitVisitor<Vertex> upLimitVisitor(upFilterVertices);
    boost::breadth_first_search(rvg, v, visitor(upLimitVisitor));
  }
  gu::uniquefy(upFilterVertices);
  ComboFilterVertex <decltype(rvg)> upFilter(rvg);
  upFilter.removed = false; //already done
  upFilter.vertexSubset = upFilterVertices;
  boost::filtered_graph<decltype(rvg), boost::keep_all, decltype(upFilter)> upGraph(rvg, boost::keep_all(), upFilter);
  
  //now we can do a alter dfs on the filtered reversed graph.
  Vertices changeVertices;
  for (auto v : downLeaves)
  {
    if (upGraph[v].feature->getDescriptor() == ftr::Descriptor::Create)
    {
      changeVertices.push_back(v);
      continue; //we want create leaf but we don't want to walk it up.
    }
    Vertices upTemp;
    upTemp.push_back(v);
    AlterVisitor apv(upTemp, AlterVisitor::Create::Inclusion);
    boost::depth_first_search(upGraph, visitor(apv).root_vertex(v));
    changeVertices.insert(changeVertices.end(), upTemp.begin(), upTemp.end());
  }
  gu::uniquefy(changeVertices);
  
  for (auto v : changeVertices)
  {
    stow->graph[v].feature->setColor(colorIn);
    //this is a hack. Currently, in order for this color change to be serialized
    //at next update we would have to mark the feature dirty. Marking the feature dirty
    //and causing models to be recalculated seems excessive for such a minor change as
    //object color. So here we just serialize the changed features to 'sneak' the
    //color change into the git commit.
    stow->graph[v].feature->serialWrite(stow->saveDirectory);
    
    //log action to git.
    std::ostringstream gitMessage;
    gitMessage << QObject::tr("Changing color of feature: ").toStdString()
      << findFeature(featureIdIn)->getName().toStdString()
      << "    Id: "
      << gu::idToShortString(featureIdIn);
    stow->gitManager.appendGitMessage(gitMessage.str());
  }
}

std::vector<boost::uuids::uuid> Project::getAllFeatureIds() const
{
  std::vector<uuid> out;
  
  for (auto its = boost::vertices(stow->graph); its.first != its.second; ++its.first)
  {
    if (!stow->graph[*its.first].alive)
      continue;
    out.push_back(stow->graph[*its.first].feature->getId());
  }
  
  return out;
}

void Project::setSaveDirectory(const boost::filesystem::path& directoryIn)
{
  stow->saveDirectory = directoryIn;
}

const boost::filesystem::path& Project::getSaveDirectory() const
{
  return stow->saveDirectory;
}

void Project::serialWrite()
{
  //we accumulate all feature occt shapes into 1 master compound and write
  //that to disk. We do this in an effort for occt to keep it's implicit
  //sharing between saves and opens.
  TopoDS_Compound compound;
  std::size_t offset = 0;
  BRep_Builder builder;
  builder.MakeCompound(compound);
  
  srl::prjs::Project po
  (
    srl::prjs::AppVersion(0, 0, 0),
    0,
    stow->expressionManager.serialOut()
  );
  
  RemovedGraph removedGraph = buildRemovedGraph(stow->graph);
  for (auto its = boost::vertices(removedGraph); its.first != its.second; ++its.first)
  {
    ftr::Base *f = removedGraph[*its.first].feature.get();
    
    //save the state
    po.states().push_back(srl::prjs::FeatureState(gu::idToString(f->getId()), removedGraph[*its.first].state.to_string()));
    
    //we can't add a null shape to the compound.
    //so we check for null and add 1 vertex as a place holder.
    TopoDS_Shape shapeOut;
    if (f->hasAnnex(ann::Type::SeerShape))
    {
      const ann::SeerShape &sShape = f->getAnnex<ann::SeerShape>();
      if (sShape.isNull() || sShape.getRootOCCTShape().IsNull())
        std::cout << "WARNING: trying to write out null shape in: Project::serialWrite" << std::endl;
      else
        shapeOut = sShape.getRootOCCTShape();
    }
    if (shapeOut.IsNull())
      shapeOut = BRepBuilderAPI_MakeVertex(gp_Pnt(0.0, 0.0, 0.0)).Vertex();
    
    po.features().push_back(srl::prjs::Feature(gu::idToString(f->getId()), f->getTypeString(), offset));
    
    //add to master compound
    builder.Add(compound, shapeOut);
    
    offset++;
  }
  
  //write out master compound
  path cPath = stow->saveDirectory / "project.brep";
  BRepTools::Clean(compound);
  BRepTools::Write(compound, cPath.string().c_str());
  
  for (auto its = boost::edges(removedGraph); its.first != its.second; ++its.first)
  {
    srl::prjs::Connection connection
    (
      gu::idToString(removedGraph[boost::source(*its.first, removedGraph)].feature.get()->getId())
      , gu::idToString(removedGraph[boost::target(*its.first, removedGraph)].feature.get()->getId())
    );
    for (const auto &tag : removedGraph[*its.first].inputType.getTags())
      connection.inputType().push_back(tag);
    po.connections().push_back(connection);
  }

  path pPath = stow->saveDirectory / "project.prjt";
  std::ofstream stream(pPath.string());
  xml_schema::NamespaceInfomap infoMap;
  srl::prjs::project(stream, po, infoMap);
}

void Project::save()
{
  stow->node.send(msg::Message(msg::Response | msg::Pre | msg::Save | msg::Project));
  
  stow->gitManager.save();
  
  stow->node.send(msg::Message(msg::Response | msg::Post | msg::Save | msg::Project));
}

void Project::initializeNew()
{
  serialWrite();
  stow->gitManager.create(stow->saveDirectory.string());
}

void Project::open()
{
  app::WaitCursor waitCursor;
  
  stow->isLoading = true;
  stow->node.send(msg::Message(msg::Request | msg::Git | msg::Freeze));
  
  path pPath = stow->saveDirectory / "project.prjt";
  path sPath = stow->saveDirectory / "project.brep";
  
  stow->gitManager.open((stow->saveDirectory / ".git").string());
  
  try
  {
    //read master shape.
    TopoDS_Shape masterShape;
    BRep_Builder junk;
    std::fstream file(sPath.string());
    BRepTools::Read(masterShape, file, junk);
    
    auto project = srl::prjs::project(pPath.string(), ::xml_schema::Flags::dont_validate);
    FeatureLoad fLoader(stow->saveDirectory, masterShape);
    for (const auto &feature : project->features())
    {
      std::ostringstream messageStream;
      messageStream << "Loading: " << feature.type() << "    Id: " << feature.id();
      stow->node.sendBlocked(msg::buildStatusMessage(messageStream.str()));
      qApp->processEvents(); //need this or we won't see messages.
      
      std::unique_ptr<ftr::Base> featurePtr = fLoader.load(feature.id(), feature.type(), feature.shapeOffset());
      if (featurePtr)
      {
        ftr::Base * f = addFeature(std::move(featurePtr));
        
        //send state message
        ftr::Message fMessage(f->getId(), f->getState(), ftr::StateOffset::Loading);
        msg::Message mMessage(msg::Response | msg::Feature | msg::Status, fMessage);
        stow->node.sendBlocked(mMessage);
      }
    }
    
    stow->node.sendBlocked(msg::buildStatusMessage("Loading: Project States"));
    qApp->processEvents();
    for (const auto &state : project->states())
    {
      uuid fId = gu::stringToId(state.id());
      ftr::State fState(state.state());
      stow->graph[stow->findVertex(fId)].state = fState;
      
      //send state message
      ftr::Message fMessage(fId, fState, ftr::StateOffset::Loading);
      msg::Message mMessage(msg::Response | msg::Project | msg::Feature | msg::Status, fMessage);
      stow->node.sendBlocked(mMessage);
    }
    
    stow->node.sendBlocked(msg::buildStatusMessage("Loading: Feature Connections"));
    qApp->processEvents();
    for (const auto &fConnection : project->connections())
    {
      uuid source = gu::stringToId(fConnection.sourceId());
      uuid target = gu::stringToId(fConnection.targetId());
      
      ftr::InputType inputType;
      for (const auto &sInputType : fConnection.inputType())
        inputType.add(sInputType);
      connect(source, target, inputType);
    }
    
    stow->node.sendBlocked(msg::buildStatusMessage("Loading: Expressions"));
    qApp->processEvents();
    stow->expressionManager.serialIn(project->expression());
    
    stow->node.sendBlocked(msg::buildStatusMessage("Building: Shape History"));
    qApp->processEvents();
    stow->buildShapeHistory();
    
    stow->node.sendBlocked(msg::Request | msg::DAG | msg::View | msg::Update);
    stow->node.sendBlocked(msg::buildStatusMessage(std::string()));
    stow->node.sendBlocked(msg::buildStatusMessage("Project Opened", 2.0));
  }
  catch (const xsd::cxx::xml::invalid_utf16_string&)
  {
    std::cerr << "invalid UTF-16 text in DOM model" << std::endl;
  }
  catch (const xsd::cxx::xml::invalid_utf8_string&)
  {
    std::cerr << "invalid UTF-8 text in object model" << std::endl;
  }
  catch (const xml_schema::Exception& e)
  {
    std::cerr << e << std::endl;
  }
  
  stow->node.send(msg::Message(msg::Request | msg::Git | msg::Thaw));
  stow->isLoading = false;
}

const ftr::ShapeHistory& Project::getShapeHistory() const
{
  return stow->shapeHistory;
}

void Project::shapeTrackDump(const uuid &shapeId, const path &directory) const
{
  if (!exists(directory) || !is_directory(directory))
    return;
  
  ftr::ShapeHistory devolve = stow->shapeHistory.createDevolveHistory(shapeId);
  devolve.writeGraphViz((directory / "devolveHistory.dot").string());
  
  ftr::ShapeHistory evolve = stow->shapeHistory.createEvolveHistory(shapeId);
  evolve.writeGraphViz((directory / "evolveHistory.dot").string());
}

ftr::UpdatePayload::UpdateMap Project::getParentMap(const boost::uuids::uuid &idIn) const
{
  ftr::UpdatePayload::UpdateMap updateMap;
  
  auto vertex = stow->findVertex(idIn);
  assert(vertex != NullVertex());
  RemovedGraph removedGraph = buildRemovedGraph(stow->graph); //children
  ReversedGraph reversedGraph = boost::make_reverse_graph(removedGraph); //parents
  
  return buildAjacentUpdateMap
  <
    ReversedGraph,
    boost::graph_traits<ReversedGraph>::vertex_descriptor
  >(reversedGraph, vertex);
}

ftr::UpdatePayload Project::getPayload(const boost::uuids::uuid &idIn) const
{
  return ftr::UpdatePayload(getParentMap(idIn), stow->shapeHistory);
}

template <typename VertexT>
class LeafChildrenVisitor : public boost::default_dfs_visitor
{
public:
  LeafChildrenVisitor(std::vector<VertexT> &leafChildrenIn) :
    leafChildren(leafChildrenIn)
  {
  }
  
  template <typename GraphT >
  void start_vertex(VertexT vertexIn, const GraphT&) const
  {
    startVertex = vertexIn;
  }
  
  template <typename GraphT >
  void discover_vertex(VertexT vertexIn, const GraphT & graphIn) const
  {
//     if (foundLeaf)
//       return;
    if (vertexIn == startVertex)
      return;
    if (!graphIn[vertexIn].state.test(ftr::StateOffset::NonLeaf))
    {
//       foundLeaf = true;
      leafChildren.push_back(vertexIn);
    }
  }
  
//   template <typename GraphT >
//   void finish_vertex(VertexT vertexIn, const GraphT &graphIn) const
//   {
//     if (!graphIn[vertexIn].state.test(ftr::StateOffset::Inactive))
//       foundLeaf = false;
//   }
  
private:
  std::vector<VertexT> &leafChildren;
//   mutable bool foundLeaf = false;
  mutable VertexT startVertex;
};

/*! editing a feature uses setCurrentLeaf to 'rewind' to state
 * when feature was created. When editing is done we want to return
 * leaf states to previous state before editing. this is where this
 * function comes in. It gets leaf status of each path so it can be
 * 'reset' after editing'. doesn't work. We can't call this function
 * on each input independently. We need to do all at once with a DFS.
 * see editWithRewind.svg
 */
std::vector<uuid> Project::getLeafChildren(const uuid &parentIn) const
{
  Vertex startVertex = stow->findVertex(parentIn);
  RemovedGraph removedGraph = buildRemovedGraph(stow->graph);
  
  Vertices limitVertices;
  gu::BFSLimitVisitor<Vertex>limitVisitor(limitVertices);
  boost::breadth_first_search(removedGraph, startVertex, visitor(limitVisitor));
  
  gu::SubsetFilter<RemovedGraph> filter(removedGraph, limitVertices);
  typedef boost::filtered_graph<RemovedGraph, boost::keep_all, gu::SubsetFilter<RemovedGraph> > FilteredGraph;
  typedef boost::graph_traits<FilteredGraph>::vertex_descriptor FilteredVertex;
  FilteredGraph filteredGraph(removedGraph, boost::keep_all(), filter);
  
  std::vector<Vertex> leafChildren;
  LeafChildrenVisitor<FilteredVertex> leafVisitor(leafChildren);
  boost::depth_first_search(filteredGraph, visitor(leafVisitor));
  
  std::vector<uuid> out;
  for (const auto &v : leafChildren)
    out.push_back(stow->graph[v].feature->getId());
  
  return out;
}

/*! @brief Get the current leaf id of all related paths.
 * 
 * @param editFeatureId is the source of exploration.
 * @return input leaf ids topo sorted.
 */
std::vector<uuid> Project::getRelatedLeafs(const uuid &editFeatureId) const
{
  assert(stow->hasFeature(editFeatureId));
  Vertex editFeatureVertex = stow->findVertex(editFeatureId);
  
  auto weakGraphVertices = getWeakComponents<decltype(stow->graph)>(stow->graph, editFeatureVertex);
  
  RemovedGraph baseGraph = buildRemovedGraph(stow->graph);
  gu::SubsetFilter<decltype(baseGraph)> filter(baseGraph, weakGraphVertices);
  boost::filtered_graph<decltype(baseGraph), boost::keep_all, decltype(filter)> filteredGraph(baseGraph, boost::keep_all(), filter);
  
  std::vector<Vertex> temp;
  boost::topological_sort(filteredGraph, std::back_inserter(temp));
  std::reverse(temp.begin(), temp.end()); //topo sort is reversed.
  
  std::vector<uuid> out;
  for (const auto &v : temp)
  {
    if (!stow->graph[v].state.test(ftr::StateOffset::NonLeaf))
      out.push_back(stow->graph[v].feature->getId());
  }
  
  return out;
}

/*! @brief Get the 'rewind' ids of input features.
 * 
 * @param editFeatureId is the feature that is being edited.
 * @return Input ids to make current. Not topo sorted, but shouldn't need to be.
 * 
 * @details When rewinding for editing a feature, we need to 
 * 'setCurrentLeaf' on the inputs so selection is intuitive (not hidden).
 * A problem arises when feature inputs are dependent on each other. We can
 * end up having inactive inputs and confusion. So we can topo sort the inputs
 * so we always 'make current' the 'closest' input to ensure inputs active state.
 * That works, however there is some fallout by 'making current' an older input than
 * needed. We can end up having inactive features later in the graph. Not a huge deal
 * but ugly and unnecessary. So we filter a reversed graph for each input, topo sort
 * and look for other inputs to avoid. see 'editWithRewind.svg'
 */
std::vector<uuid> Project::getRewindInputs(const uuid &editFeatureId) const
{
  assert(stow->hasFeature(editFeatureId));
  Vertex editFeatureVertex = stow->findVertex(editFeatureId);
  
  RemovedGraph baseGraph = buildRemovedGraph(stow->graph);
  ReversedGraph rBaseGraph = boost::make_reverse_graph(baseGraph);
  
  //get a topo sorted list from the reverse graph. passed in vertex is an input of the editing feature.
  auto sortedInput = [&](Vertex v) -> std::vector<Vertex>
  {
    Vertices limitVertices;
    gu::BFSLimitVisitor<Vertex>limitVisitor(limitVertices);
    boost::breadth_first_search(rBaseGraph, v, visitor(limitVisitor));
    gu::SubsetFilter<decltype(rBaseGraph)> filter(rBaseGraph, limitVertices);
    boost::filtered_graph<decltype(rBaseGraph), boost::keep_all, decltype(filter)> filteredGraph(rBaseGraph, boost::keep_all(), filter);
    
    std::vector<Vertex> sorted;
    boost::topological_sort(filteredGraph, std::back_inserter(sorted));
    //topo sort is reversed so remove back to remove the edit feature input
    assert(v == sorted.back());
    sorted.pop_back();
    return sorted;
  };
  
  //get input vertices.
  std::vector<Vertex> adjVertices;
  for (auto its = boost::adjacent_vertices(editFeatureVertex, rBaseGraph); its.first != its.second; ++its.first)
    adjVertices.push_back(*its.first);
  
  //cleansed
  std::vector<Vertex> adjVerticesCleansed = adjVertices;
  auto clean = [&](Vertex v)
  {
    auto it = std::find(adjVerticesCleansed.begin(), adjVerticesCleansed.end(), v);
    if (it != adjVerticesCleansed.end())
      adjVerticesCleansed.erase(it);
  };
  for (auto v : adjVertices)
  {
    for (auto s : sortedInput(v))
      clean(s);
  }
  
  //get output ids
  std::vector<uuid> outIds;
  for (const auto &v : adjVerticesCleansed)
    outIds.push_back(baseGraph[v].feature->getId());
  return outIds;
}

/*! @brief Hide parents features.
 * 
 * @param childIdIn is the target for parent search.
 * 
 * @details When creating a new feature we want to hide the
 * 'non-sever' inputs/parent features of an 'alter'.
 */
void Project::hideAlterParents(const boost::uuids::uuid &childIdIn) const
{
  assert(stow->hasFeature(childIdIn));
  Vertex editFeatureVertex = stow->findVertex(childIdIn);
  if (stow->graph[editFeatureVertex].feature->getDescriptor() != ftr::Descriptor::Alter)
    return;
  
  auto baseGraph = buildRemovedSeveredGraph(stow->graph);
  auto rBaseGraph = boost::make_reverse_graph(baseGraph);
  for (auto p : boost::make_iterator_range(boost::adjacent_vertices(editFeatureVertex, rBaseGraph)))
  {
    stow->node.send(msg::buildHideThreeD(stow->graph[p].feature->getId()));
    stow->node.send(msg::buildHideOverlay(stow->graph[p].feature->getId()));
  }
}

void Project::setFeatureActive(const boost::uuids::uuid &idIn)
{
  stow->setFeatureActive(stow->findVertex(idIn));
}

void Project::setFeatureInactive(const boost::uuids::uuid &idIn)
{
  stow->setFeatureInactive(stow->findVertex(idIn));
}

bool Project::isFeatureActive(const boost::uuids::uuid &idIn)
{
  return stow->isFeatureActive(stow->findVertex(idIn));
}

bool Project::isFeatureInactive(const boost::uuids::uuid &idIn)
{
  return stow->isFeatureInactive(stow->findVertex(idIn));
}

void Project::setFeatureLeaf(const boost::uuids::uuid &idIn)
{
  stow->setFeatureLeaf(stow->findVertex(idIn));
}

void Project::setFeatureNonLeaf(const boost::uuids::uuid &idIn)
{
  stow->setFeatureNonLeaf(stow->findVertex(idIn));
}

bool Project::isFeatureLeaf(const boost::uuids::uuid &idIn)
{
  return stow->isFeatureLeaf(stow->findVertex(idIn));
}

bool Project::isFeatureNonLeaf(const boost::uuids::uuid &idIn)
{
  return stow->isFeatureNonLeaf(stow->findVertex(idIn));
}

/*! @brief Link a parameter to an expression.
 * 
 * @param pId the id of the parameter.
 * @param eId the id of the expression.
 */
void Project::expressionLink(const boost::uuids::uuid &pId, int eId)
{
  /* expression manager takes care of everything. Checks if parameter is already links and removes
   * sets the parameter value if types match and expression contains a valid value for the parameter.
   * even writes the git message.
   */
  stow->expressionManager.addLink(pId, eId);
}

/*! @brief Unlink a parameter to an expression.
 * 
 * @param pId the id of the parameter.
 */
void Project::expressionUnlink(const boost::uuids::uuid &pId)
{
  stow->expressionManager.removeLink(pId);
}
