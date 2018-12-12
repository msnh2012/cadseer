/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2018  Thomas S. Anderson blobfish.at.gmx.com
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

#include <boost/optional/optional.hpp>
#include <boost/filesystem/path.hpp>

#include <gp_Ax2.hxx>
#include <gp_Circ.hxx>
#include <BRep_Builder.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <TopExp_Explorer.hxx>
#include <TopExp.hxx>
#include <TopoDS.hxx>
#include <ShapeFix_Wire.hxx>

#include <osg/Switch>
#include <osg/MatrixTransform>
#include <osg/PositionAttitudeTransform>

#include "globalutilities.h"
#include "tools/idtools.h"
#include "tools/occtools.h"
#include "library/csysdragger.h"
#include "annex/seershape.h"
#include "annex/csysdragger.h"
#include "sketch/solver.h"
#include "sketch/visual.h"
#include "project/serial/xsdcxxoutput/featuresketch.h"
#include "parameter/parameter.h"
#include "feature/shapecheck.h"
#include "feature/sketch.h"

using namespace ftr;

using boost::uuids::uuid;

QIcon Sketch::icon;

Sketch::Sketch():
Base()
, sShape(new ann::SeerShape())
, solver(new skt::Solver())
, visual(new skt::Visual(*solver))
, csys(new prm::Parameter(prm::Names::CSys, osg::Matrixd::identity()))
, csysDragger(new ann::CSysDragger(this, csys.get()))
, draggerSwitch(new osg::Switch())
{
  if (icon.isNull())
    icon = QIcon(":/resources/images/constructionSketch.svg");
  
  name = QObject::tr("Sketch");
  mainSwitch->setUserValue<int>(gu::featureTypeAttributeTitle, static_cast<int>(getType()));
  
  annexes.insert(std::make_pair(ann::Type::SeerShape, sShape.get()));
  annexes.insert(std::make_pair(ann::Type::CSysDragger, csysDragger.get()));
  parameters.push_back(csys.get());
  
  csys->connectValue(std::bind(&Sketch::setModelDirty, this));
  
  csysDragger->dragger->linkToMatrix(visual->getTransform());
  draggerSwitch->addChild(csysDragger->dragger);
  overlaySwitch->addChild(draggerSwitch.get());
  
  overlaySwitch->addChild(visual->getTransform());
  visual->update();
}

Sketch::~Sketch(){}

void Sketch::draggerShow()
{
  draggerSwitch->setAllChildrenOn();
}

void Sketch::draggerHide()
{
  draggerSwitch->setAllChildrenOff();
}

//! @details Setup a default sketch.
void Sketch::buildDefault()
{
  solver->setWorkPlane();
  solver->createXAxis();
  solver->createYAxis();
  solver->groupIncrement();
}

bool Sketch::hasHPPair(uint32_t hIn)
{
  for (const auto &p : hpPairs)
  {
    if (p.first == hIn)
      return true;
  }
  return false;
}

bool Sketch::hasHPPair(const prm::Parameter *pIn)
{
  for (const auto &p : hpPairs)
  {
    if (p.second.get() == pIn)
      return true;
  }
  return false;
}

void Sketch::addHPPair(uint32_t hIn, const std::shared_ptr<prm::Parameter> &pIn)
{
  assert(!hasHPPair(hIn));
  hpPairs.push_back(std::make_pair(hIn, pIn));
  parameters.push_back(pIn.get());
  pIn->connectValue(std::bind(&Sketch::setModelDirty, this));
}

void Sketch::removeHPPair(uint32_t hIn)
{
  for (auto it = hpPairs.begin(); it != hpPairs.end(); ++it)
  {
    if (it->first == hIn)
    {
      hpPairs.erase(it);
      return;
    }
  }
}

prm::Parameter* Sketch::getHPParameter(uint32_t hIn)
{
  assert(hasHPPair(hIn));
  for (const auto &p : hpPairs)
  {
    if (p.first == hIn)
      return p.second.get();
  }
  return nullptr;
}

uint32_t Sketch::getHPHandle(const prm::Parameter *pIn)
{
  assert(hasHPPair(pIn));
  for (const auto &p : hpPairs)
  {
    if (p.second.get() == pIn)
      return p.first;
  }
  return 0;
}

void Sketch::updateModel(const UpdatePayload &/*payloadIn*/)
{
  setFailure();
  lastUpdateLog.clear();
  sShape->reset();
  try
  {
    if (isSkipped())
    {
      setSuccess();
      throw std::runtime_error("feature is skipped");
    }
    
    //set solver constraints to parameters.
    for (const auto &p : hpPairs)
      solver->updateConstraintValue(p.first, static_cast<double>(*p.second));
    
    solver->solve(solver->getGroup(), true);
    if (solver->getResultCode() != 0)
      throw std::runtime_error(solver->getResultMessage());
    visual->update();
    
    updateSeerShape();
    mainTransform->setMatrix(osg::Matrixd::identity());
    visual->getTransform()->setMatrix(static_cast<osg::Matrixd>(*csys));
    
    setSuccess();
  }
  catch (const Standard_Failure &e)
  {
    std::ostringstream s; s << "OCC Error in sketch update: " << e.GetMessageString() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (const std::exception &e)
  {
    std::ostringstream s; s << "Standard error in sketch update: " << e.what() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (...)
  {
    std::ostringstream s; s << "Unknown error in sketch update. " << std::endl;
    lastUpdateLog += s.str();
  }
  setModelClean();
  if (!lastUpdateLog.empty())
    std::cout << std::endl << lastUpdateLog;
}

void Sketch::updateSeerShape()
{
  osg::Matrixd toWorld = static_cast<osg::Matrixd>(*csys);
  
  //we only want entities that are in the current group, the target of the solve.
  //also, only non construction entities also.
  typedef std::vector<skt::SSHandle> Handles;
  typedef std::vector<Handles> HandleSets;
  HandleSets handleSets;
  typedef std::allocator<std::pair<skt::SSHandle, NCollection_StdAllocator<TopoDS_Vertex>>> VMapAlloc;
  std::map<skt::SSHandle, TopoDS_Vertex, std::less<skt::SSHandle>, VMapAlloc> vMap;
  
  auto findHandleSetIndex = [&](skt::SSHandle ch) -> boost::optional<std::size_t>
  {
    std::size_t indexOut = 0;
    for (const auto &hs : handleSets)
    {
      for (const auto &h : hs)
      {
        if (h == ch)
          return indexOut;
      }
      indexOut++;
    }
    
    return boost::none;
  };
  
  auto findCurveOfPoint = [&](skt::SSHandle ph) -> boost::optional<skt::SSHandle>
  {
    for (const auto &e : solver->getEntities())
    {
      if (e.group != solver->getGroup())
        continue;
      if (visual->isConstruction(e.h))
        continue;
      for (int index = 0; index < 4; ++index)
        if (e.point[index] == ph)
          return e.h;
    }
    return boost::none;
  };
  
  auto convertVertex = [&](skt::SSHandle pIn) -> TopoDS_Vertex
  {
    auto pe = solver->findEntity(pIn);
    assert(pe);
    osg::Vec3d point = osg::Vec3d(solver->getParameterValue(pe.get().param[0]).get(), solver->getParameterValue(pe.get().param[1]).get(), 0.0);
    point = point * toWorld;
    return BRepBuilderAPI_MakeVertex(gu::toOcc(point).XYZ());
  };
  
  auto convertPoint = [&](skt::SSHandle pIn) -> osg::Vec3d
  {
    auto pe = solver->findEntity(pIn);
    assert(pe);
    osg::Vec3d point = osg::Vec3d(solver->getParameterValue(pe.get().param[0]).get(), solver->getParameterValue(pe.get().param[1]).get(), 0.0);
    return point * toWorld;
  };
  
  for (const auto &c : solver->getConstraints())
  {
    if (c.type != SLVS_C_POINTS_COINCIDENT)
      continue;
    
    auto oca = findCurveOfPoint(c.ptA);
    if (!oca)
      continue;
    auto ocb = findCurveOfPoint(c.ptB);
    if (!ocb)
      continue;
    
    TopoDS_Vertex v = convertVertex(c.ptA);
    vMap.insert(std::make_pair(c.ptA, v));
    vMap.insert(std::make_pair(c.ptB, v));
    
    auto oia = findHandleSetIndex(oca.get());
    auto oib = findHandleSetIndex(ocb.get());
    
    if (!oia && !oib)
    {
      //neither edge is contained so create a new one.
      Handles temp;
      temp.push_back(oca.get());
      temp.push_back(ocb.get());
      handleSets.push_back(temp);
    }
    else if (oia && !oib)
      handleSets.at(oia.get()).push_back(ocb.get());
    else if (!oia && oib)
      handleSets.at(oib.get()).push_back(oca.get());
    else //both already belong to a set.
    {
      if (oia.get() == oib.get())
      {
//         std::cout << "closed set" << std::endl;
      }
      else
      {
        //merge these separate sets.
        Handles merged;
        for (const auto &h : handleSets.at(oia.get()))
          merged.push_back(h);
        for (const auto &h : handleSets.at(oib.get()))
          merged.push_back(h);
        if (oia.get() > oib.get())
        {
          handleSets.erase(handleSets.begin() + oia.get());
          handleSets.erase(handleSets.begin() + oib.get());
        }
        else
        {
          handleSets.erase(handleSets.begin() + oib.get());
          handleSets.erase(handleSets.begin() + oia.get());
        }
        handleSets.push_back(merged);
      }
    }
  }
  
  //unconnected geometry
  for (const auto &e : solver->getEntities())
  {
    if (e.group != solver->getGroup())
      continue;
    if (visual->isConstruction(e.h))
      continue;
    if (e.type == SLVS_E_POINT_IN_2D)
    {
      if (vMap.count(e.h) != 0)
        continue;
      TopoDS_Vertex v = convertVertex(e.h);
      vMap.insert(std::make_pair(e.h, v));
      continue;
    }
    if (e.type < SLVS_E_LINE_SEGMENT)
      continue;
    
    auto oi = findHandleSetIndex(e.h);
    if (oi)
      continue;
    Handles temp;
    temp.push_back(e.h);
    handleSets.push_back(temp);
  }
  
  auto convert = [&](skt::SSHandle hIn) -> boost::optional<TopoDS_Edge>
  {
    auto entity = solver->findEntity(hIn);
    assert(entity);
    
    if (entity.get().type == SLVS_E_LINE_SEGMENT)
    {
      assert(vMap.count(entity.get().point[0]) == 1);
      assert(vMap.count(entity.get().point[1]) == 1);
      
      BRepBuilderAPI_MakeEdge em(vMap[entity.get().point[0]], vMap[entity.get().point[1]]);
      return em.Edge();
    }
    if (entity.get().type == SLVS_E_CIRCLE)
    {
      auto de = solver->findEntity(entity.get().distance);
      assert(de);
      double radius = solver->getParameterValue(de.get().param[0]).get();
      //this doesn't need connection
      osg::Vec3d p0 = convertPoint(entity.get().point[0]);
      gp_Ax2 orientation = gu::toOcc(toWorld);
      orientation.SetLocation(gp_Pnt(gu::toOcc(p0).XYZ()));
      gp_Circ circle(orientation, radius);
      
      BRepBuilderAPI_MakeEdge em(circle);
      return em.Edge();
    }
    if (entity.get().type == SLVS_E_ARC_OF_CIRCLE)
    {
      //center doesn't need connection.
      osg::Vec3d p0 = convertPoint(entity.get().point[0]);
      gp_Ax2 orientation = gu::toOcc(toWorld);
      orientation.SetLocation(gp_Pnt(gu::toOcc(p0).XYZ()));
      
      osg::Vec3d p1 = convertPoint(entity.get().point[1]);
      gp_Circ circle(orientation, (p1 - p0).length());
      
      assert(vMap.count(entity.get().point[1]) == 1);
      assert(vMap.count(entity.get().point[2]) == 1);
      BRepBuilderAPI_MakeEdge em(circle, vMap[entity.get().point[1]], vMap[entity.get().point[2]]);
      return em.Edge();
    }
    if (entity.get().type == SLVS_E_CUBIC)
    {
      //todo
    }
    return boost::none;
  };
  
  //convert sketch geometry to opencascade
  std::vector<std::pair<TopoDS_Edge, uuid>> pairs; //associate id contained in visual to edge created.
  occt::WireVector wires;
  for (const auto &hs : handleSets)
  {
    occt::EdgeVector ev;
    for (const auto &h : hs)
    {
      auto oe = convert(h);
      if (!oe)
      {
        std::ostringstream s; s << "Warning: couldn't convert sketch geometry to occ" << std::endl;
        lastUpdateLog += s.str();
        continue;
      }
      ev.push_back(oe.get());
      pairs.push_back(std::make_pair(ev.back(), visual->getEntityId(h)));
    }
    
    BRepBuilderAPI_MakeWire wm;
    TopTools_ListOfShape list = occt::ShapeVectorCast(ev);
    wm.Add(list);
    
    //see note about how a disconnected wire 'is done'
    //https://dev.opencascade.org/doc/refman/html/class_b_rep_builder_a_p_i___make_wire.html#ae9dd6e34dfd1bc0df8dc3b9c01bb97c2
    if (!wm.IsDone())
    {
      std::ostringstream s; s << "Warning: couldn't create wire" << std::endl;
      lastUpdateLog += s.str();
      continue;
    }
    if (wm.Error() != BRepBuilderAPI_WireDone)
    {
      std::ostringstream s; s << "Warning: wire error: " << wm.Error() << std::endl;
      lastUpdateLog += s.str();
    }
    wires.push_back(wm.Wire());
  }
  
  sShape->setOCCTShape(static_cast<TopoDS_Compound>(occt::ShapeVectorCast(wires)));
  if (!sShape->hasEvolveRecord(gu::createNilId(), sShape->getRootShapeId()))
  {
    assert(!sShape->hasEvolveRecordOut(sShape->getRootShapeId()));
    sShape->insertEvolve(gu::createNilId(), sShape->getRootShapeId());
  }
  
  while (wireIds.size() < wires.size())
    wireIds.push_back(gu::createRandomId());
  std::size_t wi = 0;
  for (const auto &w : wires)
  {
    sShape->updateId(w, wireIds.at(wi));
    if (!sShape->hasEvolveRecord(gu::createNilId(), wireIds.at(wi)))
    {
      assert(!sShape->hasEvolveRecordOut(wireIds.at(wi)));
      sShape->insertEvolve(gu::createNilId(), wireIds.at(wi));
    }
    wi++;
  }
  
  //Shapes may be modified in making wire, so normal id update won't work.
  occt::ShapeVector nilShapes = sShape->getAllNilShapes();
  for (const auto &s : nilShapes)
  {
    for (const auto &p : pairs)
    {
      if (p.first.IsSame(s))
      {
        sShape->updateId(s, p.second);
        if (!sShape->hasEvolveRecord(gu::createNilId(), p.second))
        {
          assert(!sShape->hasEvolveRecordOut(p.second));
          sShape->insertEvolve(gu::createNilId(), p.second);
        }
        break;
      }
    }
  }
  
//   sShape->dumpShapeIdContainer(std::cout);

  sShape->derivedMatch(); //ids vertices.
  sShape->ensureNoNils();
}

void Sketch::serialWrite(const boost::filesystem::path &dIn)
{
  prj::srl::WireIds wIds;
  for (const auto &wId : wireIds)
    wIds.array().push_back(gu::idToString(wId));
  
  prj::srl::HandleParameterPairs sHPPairs;
  for (const auto &hp : hpPairs)
    sHPPairs.array().push_back(prj::srl::HandleParameterPair(hp.first, hp.second->serialOut()));
  
  prj::srl::FeatureSketch so
  (
    Base::serialOut()
    , solver->serialOut()
    , visual->serialOut()
    , csys->serialOut()
    , csysDragger->serialOut()
    , wIds
    , sHPPairs
  );
  
  xml_schema::NamespaceInfomap infoMap;
  std::ofstream stream(buildFilePathName(dIn).string());
  prj::srl::sketch(stream, so, infoMap);
}

void Sketch::serialRead(const prj::srl::FeatureSketch &sIn)
{
  Base::serialIn(sIn.featureBase());
  solver->serialIn(sIn.solver());
  visual->serialIn(sIn.visual());
  csys->serialIn(sIn.csys());
  csysDragger->serialIn(sIn.csysDragger());
  
  for (const auto &wId : sIn.wireIds().array())
    wireIds.push_back(gu::stringToId(wId));
  
  //kind of a hack, having to look up location.
  auto findLocation = [&](skt::SSHandle h) -> boost::optional<osg::Vec3d>
  {
    for (const auto &r : sIn.visual().constraintMap().array())
    {
      if (r.handle() == h)
        return osg::Vec3d(r.location().x(), r.location().y(), r.location().z());
    }
    return boost::none;
  };
  for (const auto &pair : sIn.handleParameterPairs().array())
  {
    std::shared_ptr<prm::Parameter> p = std::make_shared<prm::Parameter>(QString(), 0.0);
    p->serialIn(pair.parameter());
    hpPairs.push_back(std::make_pair(pair.handle(), p));
    auto location = findLocation(hpPairs.back().first);
    if (location)
      visual->connect(hpPairs.back().first, p.get(), location.get());
    else
      std::cout << "ERROR: in finding location of constraint in: " << BOOST_CURRENT_FUNCTION << std::endl;
  }
  
  visual->getTransform()->setMatrix(static_cast<osg::Matrixd>(*csys));
  solver->solve(solver->getGroup(), true);
  visual->update();
}