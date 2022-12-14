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

#include <QImage>
#include <QGLWidget>

#include <osgViewer/View>
#include <osg/Texture2D>
#include <osg/MatrixTransform>
#include <osgUtil/LineSegmentIntersector>
#include <osg/ValueObject>
#include <osg/Depth>
// #include <osgDB/WriteFile>

#include "application/appapplication.h"
#include "viewer/vwrmessage.h"
#include "gesture/gsnnode.h"
#include "modelviz/mdvnodemaskdefs.h"
#include "message/msgnode.h"
#include "message/msgsift.h"
#include "preferences/preferencesXML.h"
#include "preferences/prfmanager.h"
#include "gesture/gsnanimations.h"
#include "menu/mnumanager.h"
#include "menu/mnuserial.h"
#include "viewer/vwrspaceballosgevent.h"
#include "gesture/gsnhandler.h"

using namespace gsn;

static const std::string attributeMask = "CommandAttributeTitle";
static const std::string attributeStatus = "CommandAttributeStatus";

// static void dumpMenuGraphViz(const osg::Node &root, const std::string &fileName)
// {
//   osg::ref_ptr<osgDB::Options> options(new osgDB::Options());
//   options->setOptionString("rankdir = TB;");
//   
//   osgDB::writeNodeFile(root, fileName, options);
// }

class GestureAllSwitchesOffVisitor : public osg::NodeVisitor
{
public:
  GestureAllSwitchesOffVisitor() : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN) {}
  virtual void apply(osg::Switch &aSwitch)
  {
    traverse(aSwitch);
    aSwitch.setAllChildrenOff();
  }
};

Handler::Handler(osg::Camera *cameraIn) : osgGA::GUIEventHandler(), rightButtonDown(false),
    dragStarted(false), currentNodeLeft(false), iconRadius(32.0), includedAngle(90.0)
{
  node = std::make_unique<msg::Node>();
  node->connect(msg::hub());
  sift = std::make_unique<msg::Sift>();
  sift->name = "gsn::Handler";
  node->setHandler(std::bind(&msg::Sift::receive, sift.get(), std::placeholders::_1));
  setupDispatcher();

  gestureCamera = cameraIn;
  if (!gestureCamera.valid())
      return;
  gestureSwitch = dynamic_cast<osg::Switch *>(gestureCamera->getChild(0));
  if (!gestureSwitch.valid())
      return;
  
  updateVariables();
  constructMenu();
//   dumpMenuGraphViz(*startNode, "SOMEPATH");
}

bool Handler::handle(const osgGA::GUIEventAdapter& eventAdapter,
                            osgGA::GUIActionAdapter&, osg::Object *,
                            osg::NodeVisitor *)
{
  if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::USER)
  {
    const vwr::SpaceballOSGEvent *event = 
      dynamic_cast<const vwr::SpaceballOSGEvent *>(eventAdapter.getUserData());
    assert (event);
    
    if (event->theType == vwr::SpaceballOSGEvent::Button)
    {
      int currentButton = event->buttonNumber;
      vwr::SpaceballOSGEvent::ButtonState currentState = event->theButtonState;
      if (currentState == vwr::SpaceballOSGEvent::Pressed)
      {
        spaceballButton = currentButton;
        if (!rightButtonDown)
        {
          unsigned int commandId = prf::manager().getSpaceballButton(spaceballButton);
          if (commandId != 0)
          {
            msg::Mask msgMask = mnu::manager().getMask(commandId);
            msg::Message messageOut;
            messageOut.mask = msgMask;
            app::instance()->queuedMessage(messageOut);
          }
        }
        else
        {
          std::ostringstream stream;
          stream << QObject::tr("Link to spaceball button ").toStdString() << spaceballButton;
          node->send(msg::buildStatusMessage(stream.str()));
        }
      }
      else
      {
        assert(currentState == vwr::SpaceballOSGEvent::Released);
        spaceballButton = -1;
      }
      return true;
    }
  }
  
  /* hot keys are a little different than the spaceball buttons. Originally we were launching the hotkey
   * command when the right mouse button is down, but not dragged combined with the key up event. This was
   * problematic because the keyboard and mouse focus can be taken away from osg and the gesture handler
   * by a command launching a dialog. This results in never receiving  the 'key up' and 'right mouse button up'
   * messages and the hot key value not reaching -1 as it should and we get drag messages as osg thinks
   * the mouse button is still pressed. So now we are launching the command on the right mouse button up
   * event and this seems to be working better.
   */
  if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::KEYDOWN)
  {
    if (!rightButtonDown)
      return false;
    hotKey = eventAdapter.getKey();
    if (dragStarted)
    {
      std::ostringstream stream;
      stream << QObject::tr("Link to key ").toStdString() << hotKey;
      node->send(msg::buildStatusMessage(stream.str()));
    }
    else //drag not started
    {
      std::ostringstream stream;
      stream << QObject::tr("Launch command linked to key ").toStdString() << hotKey;
      node->send(msg::buildStatusMessage(stream.str()));
    }
    return true;
  }
  
  //lambda to clear status.
  auto clearStatus = [&]()
  {
    //clear any status message
    node->send(msg::buildStatusMessage(""));
  };
    
  if (eventAdapter.getModKeyMask() & osgGA::GUIEventAdapter::MODKEY_LEFT_CTRL)
  {
    if (dragStarted)
    {
      clearStatus();
      GestureAllSwitchesOffVisitor visitor;
      gestureCamera->accept(visitor);
      dragStarted = false;
      gestureSwitch->setAllChildrenOff();
    }
    return false;
  }
  
  if (!gestureSwitch.valid())
  {
    std::cout << "gestureSwitch is invalid in Handler::handle" << std::endl;
    return false;
  }

  if (eventAdapter.getButton() == osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON)
  {
    if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::PUSH)
    {
      GestureAllSwitchesOffVisitor visitor;
      gestureCamera->accept(visitor);
      rightButtonDown = true;
    }

    if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::RELEASE)
    {
      clearStatus();
      rightButtonDown = false;
      if (!dragStarted)
      {
        if (hotKey != -1)
        {
          //launch command
          unsigned int commandId = prf::manager().getHotKey(hotKey);
          if (commandId != 0)
          {
            msg::Mask msgMask = mnu::manager().getMask(commandId);
            if (msgMask.any())
            {
              msg::Message messageOut(msgMask);
              app::instance()->queuedMessage(messageOut);
            }
          }
          hotKey = -1;
        }
        return false;
      }
      dragStarted = false;
      gestureSwitch->setAllChildrenOff();
      if (currentNode && (currentNode->getNodeMask() & mdv::gestureCommand))
      {
        unsigned int commandId;
        if (currentNode->getUserValue<unsigned int>(attributeMask, commandId))
        {
          if (spaceballButton != -1)
          {
            prf::manager().setSpaceballButton(spaceballButton, commandId);
            prf::manager().saveConfig();
          }
          if (hotKey != -1)
          {
            prf::manager().setHotKey(hotKey, commandId);
            prf::manager().saveConfig();
            hotKey = -1;
          }
          msg::Mask msgMask = mnu::manager().getMask(commandId);
          if (msgMask.any())
          {
            msg::Message messageOut;
            messageOut.mask = msgMask;
            app::instance()->queuedMessage(messageOut);
          }
        }
        else
          assert(0); //gesture node doesn't have msgMask attribute;
      }
      hotKey = -1;
    }
  }

  if (eventAdapter.getEventType() == osgGA::GUIEventAdapter::DRAG)
  {
    if (!rightButtonDown) //only right button drag
        return false;
    if (!dragStarted)
    {
      dragStarted = true;
      startDrag(eventAdapter);
      hotKey = -1;
      clearStatus();
    }

    osg::Matrixd transformation = osg::Matrixd::inverse
      (gestureCamera->getProjectionMatrix() * gestureCamera->getViewport()->computeWindowMatrix());
    osg::Vec3d temp(eventAdapter.getX(), eventAdapter.getY(), 0.0);
    temp = transformation * temp;
    temp.z() = 0.0;

    osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector = new osgUtil::LineSegmentIntersector
            (osgUtil::Intersector::WINDOW, temp.x(), temp.y());
    osgUtil::IntersectionVisitor iv(intersector);
    iv.setTraversalMask(~mdv::noIntersect);
    gestureSwitch->accept(iv);
    
    //look for icon intersection, but send message when intersecting lines for user feedback.
    osg::ref_ptr<osg::Drawable> drawable;
    osg::ref_ptr<osg::MatrixTransform> tnode;
    osg::Vec3 hPoint;
    for (auto &intersection : intersector->getIntersections())
    {
      osg::ref_ptr<osg::Drawable> tempDrawable = intersection.drawable;
      assert(tempDrawable.valid());
      osg::ref_ptr<osg::MatrixTransform> tempNode = dynamic_cast<osg::MatrixTransform*>
        (tempDrawable->getParent(0)->getParent(0));
      assert(temp.valid());
      
      std::string statusString;
      if (tempNode->getUserValue<std::string>(attributeStatus, statusString))
        node->send(msg::buildStatusMessage(statusString));
      
      if (tempDrawable->getName() != "Line")
      {
        drawable = tempDrawable;
        tnode = tempNode;
        hPoint = intersection.getLocalIntersectPoint();
        break;
      }
    }
    
    if (!drawable.valid()) //no icon intersection found.
    {
      if (currentNodeLeft == false)
      {
        currentNodeLeft = true;
        if (currentNode && (currentNode->getNodeMask() & mdv::gestureMenu))
          spraySubNodes(temp);
      }
      
      return false;
    }
    
    if (tnode == currentNode)
    {
      if (currentNodeLeft == true)
      {
        currentNodeLeft = false;
        if (currentNode->getNodeMask() & mdv::gestureMenu)
            contractSubNodes();
      }
    }
    else
    {
      //here we are entering an already sprayed node.
      osg::MatrixTransform *parentNode = currentNode;
      currentNode = tnode;

      osg::Switch *geometrySwitch = dynamic_cast<osg::Switch*>(parentNode->getChild(parentNode->getNumChildren() - 1));
      assert(geometrySwitch);
      geometrySwitch->setAllChildrenOff();

      unsigned int childIndex = parentNode->getChildIndex(currentNode);
      for (unsigned int index = 0; index < parentNode->getNumChildren() - 1; ++index)
      {
        osg::MatrixTransform *childNode = dynamic_cast<osg::MatrixTransform*>(parentNode->getChild(index));
        assert(childNode);
        
        osg::Switch *lineNodeSwitch = childNode->getChild(childNode->getNumChildren() - 1)->asSwitch();
        assert(lineNodeSwitch);
        lineNodeSwitch->setAllChildrenOff();

        if (index == childIndex)
          lineNodeSwitch->setValue(1, true);
      }

      currentNodeLeft = false;
      aggregateMatrix = currentNode->getMatrix() * aggregateMatrix;
    }
  }
  return false;
}

void Handler::spraySubNodes(osg::Vec3 cursorLocation)
{
  cursorLocation = cursorLocation * osg::Matrixd::inverse(aggregateMatrix);
  osg::Vec3 direction = cursorLocation;

  int childCount = currentNode->getNumChildren();
  assert(childCount > 1);//line, icon and sub items.
  if (childCount < 2)
    return;
  std::vector<osg::Vec3> locations = buildNodeLocations(direction, childCount - 1);
  for (unsigned int index = 0; index < locations.size(); ++index)
  {
    osg::MatrixTransform *tempLocation = dynamic_cast<osg::MatrixTransform *>
            (currentNode->getChild(index));
    assert(tempLocation);
    
    osg::Vec3d startLocation = osg::Vec3d(0.0, 0.0, -0.001); //cheat in z to be under parent.
    tempLocation->setMatrix(osg::Matrixd::translate(startLocation));
    
    gsn::NodeExpand *childAnimation = new gsn::NodeExpand(startLocation, locations.at(index), time());
    tempLocation->setUpdateCallback(childAnimation);

    osg::Switch *tempSwitch = dynamic_cast<osg::Switch *>
            (tempLocation->getChild(tempLocation->getNumChildren() - 1));
    assert(tempSwitch);
    tempSwitch->setAllChildrenOn();
    
    osg::Geometry *geometry = tempSwitch->getChild(0)->asGeometry();
    assert(geometry);
    osg::Vec3Array *pointArray = dynamic_cast<osg::Vec3Array *>(geometry->getVertexArray());
    assert(pointArray);
    (*pointArray)[1] = locations.at(index) * -1.0;
    geometry->dirtyDisplayList();
    geometry->dirtyBound();
    
    gsn::GeometryExpand *lineAnimate = new gsn::GeometryExpand
      (osg::Vec3d(0.0, 0.0, 0.0), -locations.at(index), time());
    geometry->setUpdateCallback(lineAnimate);
  }
}

void Handler::contractSubNodes()
{
  int childCount = currentNode->getNumChildren();
  assert(childCount > 1);//line, icon and sub items.
  for (int index = 0; index < childCount - 1; ++index)
  {
    osg::MatrixTransform *tempLocation = dynamic_cast<osg::MatrixTransform *>(currentNode->getChild(index));
    assert(tempLocation);
    
    gsn::NodeCollapse *childAnimation = new gsn::NodeCollapse
      (tempLocation->getMatrix().getTrans(), osg::Vec3d(0.0, 0.0, -0.001), time());
    tempLocation->setUpdateCallback(childAnimation);
    
    osg::Geometry *geometry = tempLocation->getChild(tempLocation->getNumChildren() - 1)->
      asSwitch()->getChild(0)->asGeometry();
    assert(geometry);
    
    gsn::GeometryCollapse *lineAnimate = new gsn::GeometryCollapse
      (osg::Vec3d(0.0, 0.0, 0.0), -(tempLocation->getMatrix().getTrans()), time());
      
    geometry->setUpdateCallback(lineAnimate);
  }
}

float Handler::time()
{
  return static_cast<float>(prf::manager().rootPtr->gesture().animationSeconds());
}

void Handler::constructMenu()
{
  if (startNode)
  {
    gestureSwitch->removeChild(startNode.get());
    startNode.release();
  }
  
  gsn::NodeBuilder builder(iconRadius);
  
  if (!mnu::manager().getCueRead().gestureNode())
    return;
  const mnu::srl::MenuNode *mNode = &mnu::manager().getCueRead().gestureNode().get();
  
  auto constructNode = [&]
  (
    unsigned int nodeMask,
    const char *resource,
    const std::string &statusText,
    unsigned int commandId,
    osg::MatrixTransform *parent
  ) -> osg::MatrixTransform*
  {
    assert(nodeMask == mdv::gestureMenu || nodeMask == mdv::gestureCommand);
    assert(!statusText.empty());
    assert(parent);
    if (nodeMask == mdv::gestureCommand)
      assert(mnu::manager().getMask(commandId).any());
    
    osg::MatrixTransform *out = builder.buildNode(resource, nodeMask);
    out->setUserValue<std::string>(attributeStatus, statusText);
    if (nodeMask == mdv::gestureCommand)
      out->setUserValue<unsigned int>(attributeMask, commandId);
    parent->insertChild(parent->getNumChildren() - 1, out);
    
    return out;
  };
  
  std::function<void(const mnu::srl::MenuNode*, osg::MatrixTransform*)> recurse;
  recurse = [&](const mnu::srl::MenuNode *mCNode, osg::MatrixTransform *oCNode)
  {
    assert(mCNode);
    //nullptr means this is the root start node so we build that here.
    if (!oCNode)
    {
      startNode = builder.buildNode(mCNode->icon(), mdv::gestureMenu);
      startNode->setUserValue<std::string>(attributeStatus, mCNode->text());
      gestureSwitch->insertChild(0, startNode);
      oCNode = startNode.get();
    }
    for (const auto &sn : mCNode->subMenus())
    {
      auto *subMenuNode = constructNode
      (
        mdv::gestureMenu,
        sn.icon().c_str(),
        sn.text(),
        0,
        oCNode
      );
      recurse(&sn, subMenuNode);
    }
    for (const auto &cId : mCNode->commandIds())
    {
      const mnu::srl::Command &cc = mnu::manager().getCommand(cId);
      if (cc.id() == 0) //no such command.
        continue;
      std::string icon = ":/resources/images/start.svg"; //default to start.
      std::string text = QObject::tr("No Text").toStdString();
      if (cc.visual())
      {
        if (cc.visual()->icon())
          icon = cc.visual()->icon().get();
        if (cc.visual()->statusText())
          text = cc.visual()->statusText().get();
      }
      if (mnu::manager().getMask(cId).none())
        continue;
      constructNode
      (
        mdv::gestureCommand,
        icon.c_str(),
        text,
        cId,
        oCNode
      );
    }
  };
  
  recurse(mNode, nullptr);
}

std::vector<osg::Vec3> Handler::buildNodeLocations(osg::Vec3 direction, int nodeCount)
{
  double sprayRadius = calculateSprayRadius(nodeCount);
  
  osg::Vec3 point = direction;
  point.normalize();
  point *= sprayRadius;

  double localIncludedAngle = includedAngle;
  if (sprayRadius == minimumSprayRadius)
  {
    //now we limit the angle to get node separation.
    double singleAngle = osg::RadiansToDegrees(2 * asin(nodeSpread / (sprayRadius * 2)));
    localIncludedAngle = singleAngle * (nodeCount -1);
  }

  double incrementAngle = localIncludedAngle / (nodeCount - 1);
  double startAngle = localIncludedAngle / 2.0;
  if (nodeCount < 2)
      startAngle = 0;
  //I am missing something why are the following 2 vectors are opposite of what I would expect?
  osg::Matrixd startRotation = osg::Matrixd::rotate(osg::DegreesToRadians(startAngle), osg::Vec3d(0.0, 0.0, -1.0));
  osg::Matrixd incrementRotation = osg::Matrixd::rotate(osg::DegreesToRadians(incrementAngle), osg::Vec3d(0.0, 0.0, 1.0));
  point = (startRotation * point);
  std::vector<osg::Vec3> pointArray;
  pointArray.push_back(point);
  for (int index = 0; index < nodeCount - 1; index++)
  {
    point = (incrementRotation * point);
    pointArray.push_back(point);
  }
  return pointArray;
}

double Handler::calculateSprayRadius(int nodeCount)
{
  double segmentCount = nodeCount - 1;
  if (segmentCount < 1)
      return minimumSprayRadius;
  
  double angle = 0.0;
  double includedAngleRadians = osg::DegreesToRadians(includedAngle);
  
  //try to use minimum spray radius and check against include angle.
  angle = std::asin(nodeSpread / 2.0 / minimumSprayRadius) * 2.0;
  if ((angle * segmentCount) < includedAngleRadians)
    return minimumSprayRadius;
  
  //that didn't work so calculate angle and use to determin spray radius for node spread.
  double halfAngle = includedAngleRadians / segmentCount / 2.0;
  double hypt = nodeSpread / 2.0 / std::sin(halfAngle);
  return hypt;
}

void Handler::startDrag(const osgGA::GUIEventAdapter& eventAdapter)
{
  //send status
  node->send(msg::buildStatusMessage(QObject::tr("Start Menu").toStdString()));

  gestureSwitch->setAllChildrenOn();
  osg::Switch *startSwitch = dynamic_cast<osg::Switch *>(startNode->getChild(startNode->getNumChildren() - 1));
  assert(startSwitch);
  startSwitch->setValue(1, true);
  currentNode = startNode;
  currentNodeLeft = false;

  osg::Matrixd t = gestureCamera->getProjectionMatrix() * gestureCamera->getViewport()->computeWindowMatrix();
  t = osg::Matrixd::inverse(t);
  osg::Vec3d position(osg::Vec3d(eventAdapter.getX(), eventAdapter.getY(), 0.0) * t);
  position.z() = 0.0;
  
  osg::Matrixd temp = osg::Matrixd::scale(t.getScale()) * osg::Matrixd::translate(position);
  startNode->setMatrix(temp);
  aggregateMatrix = startNode->getMatrix();
}

void Handler::setupDispatcher()
{
  sift->insert
  (
    msg::Response | msg::Preferences
    , std::bind(&Handler::preferencesChangedDispatched, this, std::placeholders::_1)
  );
}

void Handler::updateVariables()
{
  iconRadius = prf::manager().rootPtr->gesture().iconRadius();
  iconRadius = std::max(iconRadius, 16.0);
  iconRadius = std::min(iconRadius, 128.0);
  
  includedAngle = static_cast<double>(prf::manager().rootPtr->gesture().includeAngle());
  includedAngle = std::max(includedAngle, 15.0);
  includedAngle = std::min(includedAngle, 360.0);
  
  double iconDiameter = iconRadius * 2.0;
  nodeSpread = iconDiameter + iconDiameter * prf::manager().rootPtr->gesture().spreadFactor();
  minimumSprayRadius = iconDiameter + iconDiameter * prf::manager().rootPtr->gesture().sprayFactor();
}

void Handler::preferencesChangedDispatched(const msg::Message&)
{
  
  if (iconRadius != prf::manager().rootPtr->gesture().iconRadius())
  {
    updateVariables();
    constructMenu();
  }
  else
    updateVariables();
}
