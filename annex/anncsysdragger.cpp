/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2017  Thomas S. Anderson blobfish.at.gmx.com
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

#include <iomanip>

#include "globalutilities.h"
#include "tools/idtools.h"
#include "application/appapplication.h"
#include "parameter/prmparameter.h"
#include "feature/ftrbase.h"
#include "library/lbrcsysdragger.h"
#include "message/msgmessage.h"
#include "preferences/preferencesXML.h"
#include "preferences/prfmanager.h"
#include "project/serial/generated/prjsrlsptoverlay.h"
#include "annex/anncsysdragger.h"

namespace ann
{
  class DCallBack : public osgManipulator::DraggerTransformCallback
  {
  public:
    DCallBack() = delete;
    DCallBack(osg::MatrixTransform *t, ftr::Base *fIn, prm::Parameter *parameterIn) :
    osgManipulator::DraggerTransformCallback(t),
    feature(fIn),
    parameter(parameterIn)
    {}
    
    virtual bool receive(const osgManipulator::MotionCommand &commandIn) override
    {
      bool out = osgManipulator::DraggerCallback::receive(commandIn);
  
      static double lastTranslation = 0.0;
      static int lastRotation = 0.0;
      
      const osgManipulator::TranslateInLineCommand *tCommand = 
        dynamic_cast<const osgManipulator::TranslateInLineCommand *>(&commandIn);
      const osgManipulator::Rotate3DCommand *rCommand = 
        dynamic_cast<const osgManipulator::Rotate3DCommand *>(&commandIn);
      
      std::ostringstream stream;
      if (commandIn.getStage() == osgManipulator::MotionCommand::START)
      {
        if (tCommand)
          originStart = tCommand->getTranslation() * tCommand->getLocalToWorld();
        lastTranslation = 0.0;
        lastRotation = 0.0;
        cachedMatrix = this->getTransform()->getMatrix();
        
        lbr::CSysDragger *dragger = dynamic_cast<lbr::CSysDragger*>(this->getTransform());
        assert(dragger);
        dragger->setTranslationIncrement(prf::manager().rootPtr->dragger().linearIncrement());
        dragger->setRotationIncrement(prf::manager().rootPtr->dragger().angularIncrement());
      }
        
      if (commandIn.getStage() == osgManipulator::MotionCommand::MOVE)
      {
        if (tCommand)
        {
          osg::Vec3d tVec = tCommand->getTranslation() * tCommand->getLocalToWorld();
          double diff = (tVec-originStart).length();
          if (std::fabs(diff - lastTranslation) < std::numeric_limits<float>::epsilon())
            return out;
          lastTranslation = diff;
          stream << QObject::tr("Translation Increment: ").toUtf8().data() << std::setprecision(3) << std::fixed <<
            prf::manager().rootPtr->dragger().linearIncrement() << std::endl <<
            QObject::tr("Translation: ").toUtf8().data() << std::setprecision(3) << std::fixed << diff;
        }
        if (rCommand)
        {
          double w = rCommand->getRotation().asVec4().w();
          int angle = static_cast<int>(std::round(osg::RadiansToDegrees(2.0 * std::acos(w))));
          if (angle == lastRotation)
            return out;
          lastRotation = angle;
          stream << QObject::tr("Rotation Increment: ").toUtf8().data() << 
            static_cast<int>(prf::manager().rootPtr->dragger().angularIncrement()) <<
            std::endl << QObject::tr("Rotation: ").toUtf8().data() << angle;
        }
      }
      
      //assuming at this point the transform matrix has been updated.
      //so copy it back to gp_Ax2 and mark the feature dirty.
      if (commandIn.getStage() == osgManipulator::MotionCommand::FINISH)
      {
        lbr::CSysDragger *dragger = dynamic_cast<lbr::CSysDragger*>(this->getTransform());
        assert(dragger);
        if (dragger->isLinked())
        {
          if (lastTranslation != 0.0 || lastRotation != 0.0)
          {
            osg::Matrixd diffMatrix = osg::Matrixd::inverse(cachedMatrix) * this->getTransform()->getMatrix();
            parameter->setValue(parameter->getMatrix() * diffMatrix);
            
            //add git message.
            std::ostringstream gitStream;
            gitStream << QObject::tr("Reposition feature: ").toStdString()
              << feature->getName().toStdString()
              << "    " << gu::idToShortString(feature->getId());
            app::instance()->messageSlot(msg::buildGitMessage(gitStream.str()));
            
            if (prf::manager().rootPtr->dragger().triggerUpdateOnFinish())
            {
              msg::Message messageOut(msg::Request | msg::Project | msg::Update);
              app::instance()->queuedMessage(messageOut);
            }
          }
        }
      }
      
      app::instance()->messageSlot(msg::buildStatusMessage(stream.str()));
      return out;
    }
    
    
  private:
    ftr::Base *feature;
    QString featureName;
    prm::Parameter *parameter;
    osg::Vec3d originStart;
    osg::Matrixd cachedMatrix;
  };
}

using namespace ann;

CSysDragger::CSysDragger(ftr::Base *fIn, prm::Parameter *pIn) :
Base(),
dragger(new lbr::CSysDragger()),
parameter(pIn),
callBack(new DCallBack(dragger.get(), fIn, pIn)),
prmObserver(std::make_unique<prm::Observer>())
{
  dragger->setScreenScale(75.0);
  dragger->setRotationIncrement(prf::manager().rootPtr->dragger().angularIncrement());
  dragger->setTranslationIncrement(prf::manager().rootPtr->dragger().linearIncrement());
  dragger->setHandleEvents(false);
  dragger->setupDefaultGeometry();
  dragger->linkToMatrix(fIn->getMainTransform());
  dragger->setUserValue<std::string>(gu::idAttributeTitle, gu::idToString(fIn->getId()));
  
  dragger->addDraggerCallback(callBack.get());
  
  prmObserver->constantHandler = std::bind(&CSysDragger::csysActiveChanged, this);
  prmObserver->activeHandler = std::bind(&CSysDragger::csysActiveChanged, this);
  parameter->connect(*prmObserver);
}

CSysDragger::~CSysDragger() = default;

void CSysDragger::draggerUpdate()
{
  draggerUpdate(parameter->getMatrix());
}

void CSysDragger::draggerUpdate(const osg::Matrixd &mIn)
{
  bool wasDraggerLinked = dragger->isLinked();
  dragger->setUnlink();
  dragger->setMatrix(mIn);
  if (wasDraggerLinked)
    dragger->setLink();
}

void CSysDragger::setCSys(const osg::Matrixd &mIn)
{
  osg::Matrixd oldSystem = parameter->getMatrix();
  if (!parameter->setValue(mIn))
    return; // already at this csys
    
  //apply the same transformation to dragger, so dragger moves with it.
  osg::Matrixd diffMatrix = osg::Matrixd::inverse(oldSystem) * mIn;
  draggerUpdate(dragger->getMatrix() * diffMatrix);
}

void CSysDragger::csysActiveChanged()
{
  if (parameter->isActive() && parameter->isConstant())
    dragger->show();
  else
    dragger->hide();
}

prj::srl::spt::CSysDragger CSysDragger::serialOut()
{
  osg::Matrixd m = dragger->getMatrix();
  prj::srl::spt::Matrixd mOut
  (
    m(0,0), m(0,1), m(0,2), m(0,3),
    m(1,0), m(1,1), m(1,2), m(1,3),
    m(2,0), m(2,1), m(2,2), m(2,3),
    m(3,0), m(3,1), m(3,2), m(3,3)
  );
  std::string featureId;
  bool results = dragger->getUserValue<std::string>(gu::idAttributeTitle, featureId);
  assert(results);
  
  return prj::srl::spt::CSysDragger(mOut, dragger->isLinked(), featureId);
}

void CSysDragger::serialIn(const prj::srl::spt::CSysDragger &si)
{
  const auto &mIn = si.matrix();
  osg::Matrixd m
  (
    mIn.i0j0(), mIn.i0j1(), mIn.i0j2(), mIn.i0j3(),
    mIn.i1j0(), mIn.i1j1(), mIn.i1j2(), mIn.i1j3(),
    mIn.i2j0(), mIn.i2j1(), mIn.i2j2(), mIn.i2j3(),
    mIn.i3j0(), mIn.i3j1(), mIn.i3j2(), mIn.i3j3()
  );
  draggerUpdate(m);
  
  if (si.linked())
    dragger->setLink();
  else
    dragger->setUnlink();
  csysActiveChanged();
  
  dragger->setUserValue<std::string>(gu::idAttributeTitle, si.featureId());
}
