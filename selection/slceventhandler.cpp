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

#include <iostream>
#include <assert.h>

#include <boost/current_function.hpp>

#include <osg/Geometry>
#include <osg/View>
#include <osgViewer/View>
#include <osg/ValueObject>
#include <osg/Point>
#include <osg/Switch>
#include <osgUtil/PolytopeIntersector>

#include "modelviz/mdvnodemaskdefs.h"
#include "globalutilities.h"
#include "application/appapplication.h"
#include "project/prjproject.h"
#include "feature/ftrbase.h"
#include "annex/annseershape.h"
#include "message/msgnode.h"
#include "message/msgsift.h"
#include "selection/slcmessage.h"
#include "selection/slcdefinitions.h"
#include "selection/slcinterpreter.h"
#include "selection/slcintersection.h"
#include "selection/slceventhandler.h"

using namespace osg;
using namespace boost::uuids;
using namespace slc;

//build polytope at origin. 8 sided.
static osg::Polytope buildBasePolytope(double radius)
{
  //apparently the order of the addition matters. intersector
  //wants opposites sequenced. This seems to be working.
  osg::Polytope out;
  osg::Matrixd rotation = osg::Matrixd::rotate(osg::DegreesToRadians(45.0), osg::Vec3d(0.0, 0.0, 1.0));
  osg::Vec3d base = osg::Vec3d(1.0, 0.0, 0.0);
  
  out.add(osg::Plane(base, radius));
  out.add(osg::Plane(-base, radius));
  
  base = rotation * base;
  
  out.add(osg::Plane(base, radius));
  out.add(osg::Plane(-base, radius));
  
  base = rotation * base;
  
  out.add(osg::Plane(base, radius));
  out.add(osg::Plane(-base, radius));
  
  base = rotation * base;
  
  out.add(osg::Plane(base, radius));
  out.add(osg::Plane(-base, radius));
  
  out.add(osg::Plane(0.0,0.0,1.0, 0.0)); //last has to be 'cap'
  
  return out;
}

static osg::Polytope buildPolytope(double x, double y, double radius)
{
  static osg::Polytope base = buildBasePolytope(radius);
  osg::Polytope out(base);
  out.transform(osg::Matrixd::translate(x, y, 0.0));
  
  return out;
}

EventHandler::EventHandler(osg::Group *viewerRootIn) : osgGA::GUIEventHandler()
{
  node = std::make_unique<msg::Node>();
  node->connect(msg::hub());
  sift = std::make_unique<msg::Sift>();
  sift->name = "slc::EventHandler";
  node->setHandler(std::bind(&msg::Sift::receive, sift.get(), std::placeholders::_1));
  setupDispatcher();
  
  viewerRoot = viewerRootIn;
  
  preHighlightColor = Vec4(1.0, 1.0, 0.0, 1.0);
  selectionColor = Vec4(1.0, 1.0, 1.0, 1.0);
  nodeMask = ~(mdv::backGroundCamera | mdv::gestureCamera | mdv::csys | mdv::point | mdv::noIntersect);
  
  setSelectionMask(slc::AllEnabled);
}

void EventHandler::setSelectionMask(Mask maskIn)
{
  selectionMask = maskIn;

  if
  (
    canSelectWires(selectionMask) ||
    canSelectFaces(selectionMask) ||
    canSelectShells(selectionMask) ||
    canSelectSolids(selectionMask) ||
    canSelectFeatures(selectionMask) ||
    canSelectObjects(selectionMask) ||
    canSelectNearestPoints(selectionMask)
  )
      nodeMask |= mdv::face;
  else
      nodeMask &= ~mdv::face;

  if
  (
    canSelectEdges(selectionMask) ||
    canSelectWires(selectionMask) ||
    canSelectFeatures(selectionMask) ||
    canSelectObjects(selectionMask) ||
    canSelectPoints(selectionMask)
  )
      nodeMask |= mdv::edge;
  else
      nodeMask &= ~mdv::edge;

  //obsolete. we no longer generate vertices
//   if ((Selection::pointsSelectable & selectionMask) == Selection::pointsSelectable)
//       nodeMask |= NodeMaskDef::vertex;
//   else
//       nodeMask &= ~NodeMaskDef::vertex;
}

bool EventHandler::handle(const osgGA::GUIEventAdapter& eventAdapter,
                    osgGA::GUIActionAdapter& actionAdapter, osg::Object*,
                                   osg::NodeVisitor*)
{
  if (eventAdapter.getModKeyMask() & osgGA::GUIEventAdapter::MODKEY_LEFT_CTRL)
  {
    clearPrehighlight();
    return false;
  }
  
  if(eventAdapter.getHandled())
  {
    clearPrehighlight();
    return true; //overlay has taken event;
  }
    
  //escape key should dispatch to cancel command.
  if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::KEYUP)
  {
    if (eventAdapter.getKey() == osgGA::GUIEventAdapter::KEY_Escape)
    {
      node->send(msg::Message(msg::Request | msg::Command | msg::Done));
      return true;
    }
  }
  
  if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::MOVE)
  {
    osg::View* view = actionAdapter.asView();
    if (!view)
      return false;
      
    Intersections currentIntersections;
      
    //use poly on just the edges for now.
    if (nodeMask & mdv::edge)
    {
      osg::ref_ptr<osgUtil::PolytopeIntersector> polyPicker = new osgUtil::PolytopeIntersector
      (
        osgUtil::Intersector::WINDOW,
        buildPolytope(eventAdapter.getX(), eventAdapter.getY(), 16.0)
//         eventAdapter.getX() - 16.0,
//         eventAdapter.getY() - 16.0,
//         eventAdapter.getX() + 16.0,
//         eventAdapter.getY() + 16.0
      );
      osgUtil::IntersectionVisitor polyVisitor(polyPicker.get());
      polyVisitor.setTraversalMask(nodeMask & ~mdv::face);
      view->getCamera()->accept(polyVisitor);
      append(currentIntersections, polyPicker->getIntersections());
    }
      
    //use linesegment on just the faces for now.
    if (nodeMask & mdv::face)
    {
      osg::ref_ptr<osgUtil::LineSegmentIntersector> linePicker = new osgUtil::LineSegmentIntersector
      (
        osgUtil::Intersector::WINDOW,
        eventAdapter.getX(),
        eventAdapter.getY()
      );
      osgUtil::IntersectionVisitor lineVisitor(linePicker.get());
      lineVisitor.setTraversalMask(nodeMask & ~mdv::edge);
//         lineVisitor.setUseKdTreeWhenAvailable(false); //temp for testing.
      view->getCamera()->accept(lineVisitor);
      append(currentIntersections, linePicker->getIntersections());
    }

    if (!currentIntersections.empty())
    {
      Interpreter interpreter(currentIntersections, selectionMask);

      slc::Container newContainer;
      //loop to get first non selected geometry.
      for (const auto& container : interpreter.containersOut)
      {
        if(alreadySelected(container))
          continue;
        newContainer = container;
        break;
      }

      if (newContainer == lastPrehighlight)
      {
        //update the point location though.
        lastPrehighlight.pointLocation = newContainer.pointLocation;
        return false;
      }

      clearPrehighlight();

      if (newContainer.selectionType == slc::Type::None)
        return false;
        
      //this is here so we make sure we get through all selection
      //conditions before we construct point geometry.
      if (isPointType(newContainer.selectionType))
      {
        ref_ptr<Geometry> pointGeometry(buildTempPoint(newContainer.pointLocation));
        newContainer.pointGeometry = pointGeometry.get();
        viewerRoot->addChild(pointGeometry.get());
      }
      setPrehighlight(newContainer);
    }
    else
      clearPrehighlight();
  }

  if (eventAdapter.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON &&
          eventAdapter.getEventType() == osgGA::GUIEventAdapter::RELEASE)
  {
    if(lastPrehighlight.selectionType != slc::Type::None)
    {
      //prehighlight gets 'moved' into selections so can't call
      //clear prehighlight, but we still clear the prehighlight
      //selections we need to make observers aware of this 'hidden' change.
      msg::Message clearMessage
      (
        msg::Response | msg::Pre | msg::Preselection | msg::Remove
        , containerToMessage(lastPrehighlight)
      );
      node->send(clearMessage);
      
      if (slc::isPointType(lastPrehighlight.selectionType))
      {
        assert(lastPrehighlight.pointGeometry.valid());
        osg::Vec4Array *colors = dynamic_cast<osg::Vec4Array*>(lastPrehighlight.pointGeometry->getColorArray());
        assert(colors);
        (*colors)[0] = osg::Vec4(1.0, 1.0, 1.0, 1.0);
        colors->dirty();
        lastPrehighlight.pointGeometry->dirtyDisplayList();
      }
      else
      {
        selectionOperation
        (
          lastPrehighlight.featureId
          , lastPrehighlight.selectionIds
          , HighlightVisitor::Operation::Highlight
        );
      }
      
      slc::Message smOut = containerToMessage(lastPrehighlight);
      msg::Message preMessage(msg::Response | msg::Pre | msg::Selection | msg::Add, smOut);
      node->send(preMessage);
      
      add(selectionContainers, lastPrehighlight);
      
      msg::Message postMessage(msg::Response | msg::Post | msg::Selection | msg::Add, smOut);
      lastPrehighlight = Container(); //set to null before signal in case we end up in 'this' again.
      node->send(postMessage);
    }
    //not clearing the selection anymore on a empty pick.
//       else
//         clearSelections();
  }
    
  if (eventAdapter.getButton() == osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON &&
          eventAdapter.getEventType() == osgGA::GUIEventAdapter::RELEASE)
  {
    clearSelections();
  }

  if (eventAdapter.getButton() == osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON &&
          eventAdapter.getEventType() == osgGA::GUIEventAdapter::PUSH)
  {
      clearPrehighlight();
  }

  if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::DRAG)
  {
      //don't get button info here, need to cache.
  }

  return false;
}

void EventHandler::clearSelections()
{
  // clear in reverse order to fix wire issue were edges remained highlighted. edge was remembering already selected color.
  // something else will have to been when we get into delselection. maybe pool of selection and indexes for container?
  Containers::reverse_iterator it;
  for (it = selectionContainers.rbegin(); it != selectionContainers.rend(); ++it)
  {
    slc::Message smOut = containerToMessage(*it);
    msg::Message preMessage(msg::Response | msg::Pre | msg::Selection | msg::Remove, smOut);
    node->send(preMessage);
    
    if (slc::isPointType(it->selectionType))
    {
      assert(it->pointGeometry.valid());
      osg::Group *parent = it->pointGeometry->getParent(0)->asGroup();
      parent->removeChild(it->pointGeometry);
    }
    else
      selectionOperation(it->featureId, it->selectionIds, HighlightVisitor::Operation::Restore);
    
    msg::Message postMessage(msg::Response | msg::Post | msg::Selection | msg::Remove, smOut);
    node->send(postMessage);
  }
  selectionContainers.clear();
}

bool EventHandler::alreadySelected(const slc::Container &testContainer)
{
  Containers::const_iterator it;
  for (it = selectionContainers.begin(); it != selectionContainers.end(); ++it)
  {
    if ((*it) == testContainer)
      return true;
  }
  return false;
}

void EventHandler::setPrehighlight(slc::Container &selected)
{
  lastPrehighlight = selected;
  if (slc::isPointType(selected.selectionType))
  {
    assert(selected.pointGeometry.valid());
    osg::Vec4Array *colors = dynamic_cast<osg::Vec4Array*>(selected.pointGeometry->getColorArray());
    assert(colors);
    colors->at(0) = osg::Vec4(1.0, 1.0, 0.0, 1.0);
    colors->dirty();
  }
  else
    selectionOperation(selected.featureId, selected.selectionIds, HighlightVisitor::Operation::PreHighlight);
  
  msg::Message addMessage
  (
    msg::Response | msg::Post | msg::Preselection | msg::Add
    , containerToMessage(lastPrehighlight)
  );
  node->send(addMessage);
}

void EventHandler::clearPrehighlight()
{
  if (lastPrehighlight.selectionType == Type::None)
    return;
  
  msg::Message removeMessage
  (
    msg::Response | msg::Pre | msg::Preselection | msg::Remove
    , containerToMessage(lastPrehighlight)
  );
  node->send(removeMessage);
  
  if (slc::isPointType(lastPrehighlight.selectionType))
  {
    assert(lastPrehighlight.pointGeometry.valid());
    osg::Group *parent = lastPrehighlight.pointGeometry->getParent(0)->asGroup();
    parent->removeChild(lastPrehighlight.pointGeometry);
  }
  else
  {
    selectionOperation(lastPrehighlight.featureId, lastPrehighlight.selectionIds, HighlightVisitor::Operation::Restore);
    //certain situations, like selecting wires, where prehighlight can over write something already selected. Then
    //when the prehighlight gets cleared and the color restored the selection is lost. for now lets just re select
    //everything and do something different if we have performance problems.
    for (const auto &current : selectionContainers)
      selectionOperation(current.featureId, current.selectionIds, HighlightVisitor::Operation::Highlight);
  }
  
  lastPrehighlight = Container();
}

void EventHandler::setupDispatcher()
{
  sift->insert
  (
    {
      std::make_pair
      (
        msg::Request | msg::Preselection | msg::Add
        , std::bind(&EventHandler::requestPreselectionAdditionDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Request | msg::Preselection | msg::Remove
        , std::bind(&EventHandler::requestPreselectionSubtractionDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Request | msg::Selection | msg::Add
        , std::bind(&EventHandler::requestSelectionAdditionDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Request | msg::Selection | msg::Remove
        , std::bind(&EventHandler::requestSelectionSubtractionDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Request | msg::Selection | msg::Clear
        , std::bind(&EventHandler::requestSelectionClearDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Response | msg::Selection | msg::SetMask
        , std::bind(&EventHandler::selectionMaskDispatched, this, std::placeholders::_1)
      )
    }
  );
}

void EventHandler::selectionOperation
(
  const uuid &featureIdIn,
  const std::vector<uuid> &idsIn,
  HighlightVisitor::Operation operationIn
)
{
  MainSwitchVisitor sVisitor(featureIdIn);
  viewerRoot->accept(sVisitor);
  if (!sVisitor.out)
    return;
  HighlightVisitor hVisitor(idsIn, operationIn);
  sVisitor.out->accept(hVisitor);
}

void EventHandler::requestPreselectionAdditionDispatched(const msg::Message &messageIn)
{
  slc::Message sMessage = messageIn.getSLC();
  slc::Container container = messageToContainer(sMessage);
  if
  (
    (container == lastPrehighlight) ||
    (alreadySelected(container))
  )
    return;
  
  //setPrehighlight handles points
  clearPrehighlight();
  setPrehighlight(container);
}

void EventHandler::requestPreselectionSubtractionDispatched(const msg::Message &messageIn)
{
  slc::Message sMessage = messageIn.getSLC();
  
  slc::Container container = messageToContainer(sMessage);
  assert(container == lastPrehighlight);
  
  //clearPrehighlight handles points
  clearPrehighlight();
}

void EventHandler::requestSelectionAdditionDispatched(const msg::Message &messageIn)
{
  clearPrehighlight();
  
  slc::Message sMessage = messageIn.getSLC();
  slc::Container container = messageToContainer(sMessage);
  if (alreadySelected(container))
    return;
  
  if (slc::isPointType(container.selectionType))
  {
    assert(container.pointGeometry.valid());
    osg::Vec4Array *colors = dynamic_cast<osg::Vec4Array*>(container.pointGeometry->getColorArray());
    assert(colors);
    (*colors)[0] = osg::Vec4(1.0, 1.0, 1.0, 1.0);
    colors->dirty();
    container.pointGeometry->dirtyDisplayList();
    
    viewerRoot->addChild(container.pointGeometry.get());
  }
  else
    selectionOperation(sMessage.featureId, container.selectionIds, HighlightVisitor::Operation::Highlight);
  
  
  slc::Message smOut = containerToMessage(container);
  msg::Message preMessage(msg::Response | msg::Pre | msg::Selection | msg::Add, smOut);
  node->send(preMessage);
  
  add(selectionContainers, container);
  
  msg::Message postMessage(msg::Response | msg::Post | msg::Selection | msg::Add, smOut);
  node->send(postMessage);
}

void EventHandler::requestSelectionSubtractionDispatched(const msg::Message &messageIn)
{
  slc::Message sMessage = messageIn.getSLC();
  slc::Container container = messageToContainer(sMessage);
  
  Containers::iterator containIt = std::find(selectionContainers.begin(), selectionContainers.end(), container);
  assert(containIt != selectionContainers.end());
  if (containIt == selectionContainers.end())
    return;
  
  msg::Message messageOut = messageIn;
  messageOut.mask &= ~msg::Request;
  messageOut.mask |= msg::Response | msg::Pre;
  node->send(messageOut);
  
  if (slc::isPointType(containIt->selectionType))
  {
    assert(containIt->pointGeometry.valid());
    osg::Group *parent = containIt->pointGeometry->getParent(0)->asGroup();
    parent->removeChild(containIt->pointGeometry);
  }
    selectionOperation(sMessage.featureId, containIt->selectionIds, HighlightVisitor::Operation::Restore);
    
  selectionContainers.erase(containIt);
}

void EventHandler::requestSelectionClearDispatched(const msg::Message &)
{
  clearPrehighlight();
  clearSelections();
}

void EventHandler::selectionMaskDispatched(const msg::Message &messageIn)
{
  slc::Message sMsg = messageIn.getSLC();
  setSelectionMask(sMsg.selectionMask);
}

Geometry* EventHandler::buildTempPoint(const Vec3d& pointIn)
{
  osg::Geometry *geometry = new osg::Geometry();
  geometry->setNodeMask(mdv::point);
  geometry->setCullingActive(false);
  geometry->setDataVariance(osg::Object::DYNAMIC);
  osg::Vec3Array *vertices = new osg::Vec3Array();
  vertices->push_back(pointIn);
  geometry->setVertexArray(vertices);
  osg::Vec4Array *colors = new osg::Vec4Array();
  colors->push_back(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f));
  geometry->setColorArray(colors);
  geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
  geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, 1));
  
  geometry->getOrCreateStateSet()->setAttribute(new osg::Point(10.0));
  geometry->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
  geometry->getOrCreateStateSet()->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
  
  return geometry;
}

Message EventHandler::containerToMessage(const Container &containerIn)
{
  slc::Message out;
  out.type = containerIn.selectionType;
  out.featureId = containerIn.featureId;
  out.featureType = containerIn.featureType;
  out.shapeId = containerIn.shapeId;
  out.pointLocation = containerIn.pointLocation;
  
  return out;
}

Container EventHandler::messageToContainer(const Message &messageIn)
{
  //should incoming selection messages ignore selection mask?
  //I am thinking yes right now. Selection masks are only really
  //useful for cursor picking.
  
  assert(!messageIn.featureId.is_nil());
  const ftr::Base *feature = dynamic_cast<app::Application *>(qApp)->getProject()->findFeature(messageIn.featureId);
  assert(feature);
  
  slc::Container container;
  container.selectionType = messageIn.type;
  container.accrue = messageIn.accrue;
  container.featureId = messageIn.featureId;
  container.featureType = messageIn.featureType;
  container.shapeId = messageIn.shapeId;
  container.pointLocation = messageIn.pointLocation;
  if (container.featureType == ftr::Type::Base)
    container.featureType = feature->getType();
  
  if (feature->hasAnnex(ann::Type::SeerShape) && !feature->getAnnex<ann::SeerShape>().isNull())
  {
    const ann::SeerShape &seerShape = feature->getAnnex<ann::SeerShape>();
    if (messageIn.type == slc::Type::Object)
    {
      container.selectionIds = seerShape.useGetChildrenOfType(seerShape.getRootShapeId(), TopAbs_EDGE);
      auto faceIds = seerShape.useGetChildrenOfType(seerShape.getRootShapeId(), TopAbs_FACE);
      container.selectionIds.insert(container.selectionIds.end(), faceIds.begin(), faceIds.end());
    }
    //skip feature for now.
    else if
    (
      (messageIn.type == slc::Type::Solid) ||
      (messageIn.type == slc::Type::Shell)
    )
    {
      container.selectionIds = seerShape.useGetChildrenOfType(container.shapeId, TopAbs_FACE);
    }
    else if (messageIn.type == slc::Type::Face)
    {
      if (container.accrue == Accrue::Tangent)
        container.selectionIds = seerShape.useWalkTangentFaces(container.shapeId, container.accrue.angle);
      else
        container.selectionIds.push_back(container.shapeId);
    }
    else if (messageIn.type == slc::Type::Edge)
    {
      if (container.accrue == Accrue::Tangent)
        container.selectionIds = seerShape.useWalkTangentEdges(container.shapeId);
      else
        container.selectionIds.push_back(container.shapeId);
    }
    else if (messageIn.type == slc::Type::Wire)
    {
      container.selectionIds = seerShape.useGetChildrenOfType(container.shapeId, TopAbs_EDGE);
    }
    else if (isPointType(messageIn.type))
    {
      container.pointGeometry = buildTempPoint(messageIn.pointLocation);
    }
  }
  
  return container;
}
