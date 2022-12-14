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
#include <memory>

#include <osgViewer/View>
#include <osgUtil/PolytopeIntersector>

#include "viewer/vwroverlay.h"
#include "library/lbrcsysdragger.h"
#include "library/lbripgroup.h"
#include "library/lbrplabel.h"
#include "parameter/prmparameter.h"
#include "dialogs/dlgparameter.h"
#include "selection/slcvisitors.h"
#include "modelviz/mdvnodemaskdefs.h"
#include "globalutilities.h"
#include "message/msgnode.h"
#include "message/msgsift.h"
#include "command/cmdmanager.h"
#include "command/cmdcsysedit.h"
#include "selection/slcoverlayhandler.h"

using namespace slc;


//copied from eventhandler.
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

OverlayHandler::OverlayHandler(vwr::Overlay* cameraIn):
camera(cameraIn)
{
  node = std::make_unique<msg::Node>();
  node->connect(msg::hub());
  sift = std::make_unique<msg::Sift>();
  sift->name = "slc::OverlayHandler";
  node->setHandler(std::bind(&msg::Sift::receive, sift.get(), std::placeholders::_1));
  setupDispatcher();
}

bool OverlayHandler::handle
(
  const osgGA::GUIEventAdapter& eventAdapter,
  osgGA::GUIActionAdapter& actionAdapter,
  osg::Object* /*object*/,
  osg::NodeVisitor* /*nodeVistor*/
)
{
  //control key 'shuts off' the overlay handler unless it is in
  //the middle of a drag.
  if
  (
    !isDrag
    && (eventAdapter.getModKeyMask() & osgGA::GUIEventAdapter::MODKEY_LEFT_CTRL)
  )
  {
    return false;
  }
  
  if (!isActive)
    return false;
  
  auto doIntersection = [&]() -> osgUtil::PolytopeIntersector::Intersections
  {
    osgViewer::View *viewer = dynamic_cast<osgViewer::View *>(actionAdapter.asView());
    assert(viewer);
    
    osg::ref_ptr<osgUtil::PolytopeIntersector> polyPicker = new osgUtil::PolytopeIntersector
    (
      osgUtil::Intersector::WINDOW,
      buildPolytope(eventAdapter.getX(), eventAdapter.getY(), 16.0)
    );
    osgUtil::IntersectionVisitor polyVisitor(polyPicker.get());
    polyVisitor.setTraversalMask(~mdv::noIntersect);
    camera->accept(polyVisitor);
    return polyPicker->getIntersections();
  };
  
  auto findDragger = [&](const osgUtil::PolytopeIntersector::Intersections &intersections)
  {
    this->dragger = nullptr;
    
    for (auto i : intersections)
    {
      for (auto n: i.nodePath)
      {
        if
        (
            (!dynamic_cast<osgManipulator::Translate1DDragger *>(n)) &&
            (!dynamic_cast<lbr::RotateCircularDragger *>(n))
        )
            continue;

        this->dragger = dynamic_cast<osgManipulator::Dragger *>(n);
        if (this->dragger)
        {
            pointer.addIntersection(i.nodePath, i.localIntersectionPoint);
            pointer.setCamera(camera);
            pointer.setMousePosition(eventAdapter.getX(), eventAdapter.getY());
            
            path = i.nodePath;
        
            return;
        }
      }
    }
  };
  
  auto findIcon = [&](const osgUtil::PolytopeIntersector::Intersections &intersections)
  {
    for (auto i : intersections)
    {
      for (auto n: i.nodePath)
      {
        if
        (
            (n->getName() == "LinkIcon") ||
            (n->getName() == "UnlinkIcon")
        )
        {
            path = i.nodePath;
            return;
        }
      }
    }
  };
  
  auto findDimension = [&](const osgUtil::PolytopeIntersector::Intersections &intersections)
  {
    for (auto i : intersections)
    {
      for (auto n: i.nodePath)
      {
        dimension = dynamic_cast<lbr::IPGroup *>(n);
        if(dimension)
        {
            path = i.nodePath;
            return;
        }
      }
    }
  };
  
  auto findCSysOrigin = [&](const osgUtil::PolytopeIntersector::Intersections &intersections)
  {
    for (auto i : intersections)
    {
      bool foundOrigin = false;
      bool foundDragger = false;
      for (auto n: i.nodePath)
      {
        if (dynamic_cast<lbr::CSysDragger *>(n))
            foundDragger = true;
        if (n->getName() == "origin")
            foundOrigin = true;
        if (foundDragger && foundOrigin)
        {
            path = i.nodePath;
            return;
        }
      }
    }
  };
  
  auto findPLabel = [&](const osgUtil::PolytopeIntersector::Intersections &intersections)
  {
    for (const auto &i : intersections)
    {
      for (const auto &n : i.nodePath)
      {
        pLabel = dynamic_cast<lbr::PLabel *>(n);
        if (pLabel)
        {
            path = i.nodePath;
            return;
        }
      }
    }
  };
  
  bool out= false;
  bool shouldRedraw = false;
  
  //when we are over, overlay geometry we want to absorb the preselection.
  if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::MOVE)
  {
    assert(!dragger);
    assert(!dimension);
    assert(!pLabel);
    assert(path.empty());
    osgUtil::PolytopeIntersector::Intersections intersections = doIntersection();
    findDragger(intersections);
    findIcon(intersections);
    findDimension(intersections);
    findCSysOrigin(intersections);
    findPLabel(intersections);
    out = !path.empty();
    
    pointer.reset();
    dragger = nullptr;
    dimension.release();
    pLabel.release();
    path.clear();
  }
  
  if
  (
    (eventAdapter.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON) &&
    (eventAdapter.getEventType() == osgGA::GUIEventAdapter::PUSH)
  )
  {
    assert(!dragger);
    assert(path.empty());
    osgUtil::PolytopeIntersector::Intersections intersections = doIntersection();
    findDragger(intersections);
    if (dragger)
    {
      if (dragger->handle(pointer, eventAdapter, actionAdapter))
      {
        dragger->setDraggerActive(true);
        out = true;
      }
    }
    else //no dragger
    {
      assert(path.empty());
      findIcon(intersections);
      if (!path.empty())
      {
        std::string nodeName;
        lbr::CSysDragger *csysDragger = nullptr;
        for (auto it = path.rbegin(); it != path.rend(); ++it)
        {
            if (nodeName.empty())
                nodeName = (*it)->getName();
            if (!csysDragger)
                csysDragger = dynamic_cast<lbr::CSysDragger*>(*it);
        }
        
        if (!nodeName.empty() && csysDragger)
        {
            if (nodeName == "LinkIcon")
                csysDragger->setUnlink();
            if (nodeName == "UnlinkIcon")
                csysDragger->setLink();
            shouldRedraw = true;
            path.clear(); //don't need to save path for icon.
        }
      }
    }
  }
  
  //drag is button independent
  if(eventAdapter.getEventType() == osgGA::GUIEventAdapter::DRAG)
  {
    if (dragger)
    {
      pointer.setMousePosition(eventAdapter.getX(), eventAdapter.getY());
      dragger->handle(pointer, eventAdapter, actionAdapter);
      isDrag = true;
      out = true;
    }
  }
  
  if
  (
    (eventAdapter.getButton() == osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON) &&
    (eventAdapter.getEventType() == osgGA::GUIEventAdapter::RELEASE)
  )
  {
    if (dragger)
    {
      //this leaves the dragger highlighted in a non drag(select) scenario.

      pointer.setMousePosition(eventAdapter.getX(), eventAdapter.getY());
      dragger->handle(pointer, eventAdapter, actionAdapter);
      dragger->setDraggerActive(false);
      
      if (!isDrag)
      {
        osgManipulator::Translate1DDragger *tDragger = dynamic_cast<osgManipulator::Translate1DDragger*>(dragger);
        if (tDragger)
        {
            //look for csysdragger.
            ParentMaskVisitor visitor(mdv::csys);
            dragger->accept(visitor);
            if (visitor.out)
            {
                lbr::CSysDragger *csysDragger = dynamic_cast<lbr::CSysDragger*>(visitor.out);
                assert(csysDragger); //might not assert, just test and continue if ok.
                
                std::shared_ptr<cmd::CSysEdit> csysEdit(new cmd::CSysEdit());
                csysEdit->csysDragger = csysDragger;
                csysEdit->translateDragger = tDragger;
                csysEdit->type = cmd::CSysEdit::Type::Vector;
                cmd::manager().addCommand(csysEdit);
            }
        }
      }
      
      isDrag = false;
      out = true;
      pointer.reset();
      dragger = nullptr;
    }
    else
    {
      osgUtil::PolytopeIntersector::Intersections intersections = doIntersection();
      findDimension(intersections);
      if (dimension)
      {
        ParentMaskVisitor visitor(mdv::overlaySwitch);
        dimension->accept(visitor);
        assert(visitor.out);
        
        dlg::Parameter *dialog = new dlg::Parameter(dimension->getParameter(), gu::getId(visitor.out));
        dialog->show();
        dialog->raise();
        dialog->activateWindow();
        dimension.release();
      }
      else
      {
        findCSysOrigin(intersections);
        if (!path.empty())
        {
            assert(path.back()->getName() == "origin");
            ParentMaskVisitor visitor(mdv::csys);
            path.back()->accept(visitor);
            assert(visitor.out);
            lbr::CSysDragger *lDragger = dynamic_cast<lbr::CSysDragger*>(visitor.out);
            assert(lDragger);
            
            std::shared_ptr<cmd::CSysEdit> csysEdit(new cmd::CSysEdit());
            csysEdit->csysDragger = lDragger;
            csysEdit->type = cmd::CSysEdit::Type::Origin;
            cmd::manager().addCommand(csysEdit);
        }
        else
        {
            findPLabel(intersections);
            if (pLabel)
            {
                ParentMaskVisitor visitor(mdv::overlaySwitch);
                pLabel->accept(visitor);
                assert(visitor.out);
                
                dlg::Parameter *dialog = new dlg::Parameter(pLabel->getParameter(), gu::getId(visitor.out));
                dialog->show();
                dialog->raise();
                dialog->activateWindow();
                pLabel.release();
            }
        }
      }
    }
    path.clear();
  }

  if (shouldRedraw)
    actionAdapter.requestRedraw();
  return out;  //default to not handled.
}

void OverlayHandler::setupDispatcher()
{
  sift->insert
  (
    {
      std::make_pair
      (
        msg::Request | msg::Overlay | msg::Selection | msg::Freeze
        , std::bind(&OverlayHandler::requestFreezeDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Request | msg::Overlay | msg::Selection | msg::Thaw
        , std::bind(&OverlayHandler::requestThawDispatched, this, std::placeholders::_1)
      )
    }
  );
}

void OverlayHandler::requestFreezeDispatched(const msg::Message&)
{
  //this really should consider drag state. However, this whole mess is going to be
  //refactored as some point in the future and I will address it then.
  isActive = false;
  node->sendBlocked(msg::Message(msg::Response | msg::Overlay | msg::Selection | msg::Freeze));
}

void OverlayHandler::requestThawDispatched(const msg::Message&)
{
  isActive = true;
  node->sendBlocked(msg::Message(msg::Response | msg::Overlay | msg::Selection | msg::Thaw));
}
