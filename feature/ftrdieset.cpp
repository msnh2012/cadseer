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

#include <osg/Switch>

#include "globalutilities.h"
#include "library/lbrplabel.h"
#include "tools/occtools.h"
#include "preferences/preferencesXML.h"
#include "preferences/prfmanager.h"
#include "parameter/prmconstants.h"
#include "parameter/prmparameter.h"
#include "annex/annseershape.h"
#include "feature/ftrshapecheck.h"
#include "feature/ftrboxbuilder.h"
#include "project/serial/generated/prjsrldstsdieset.h"
#include "feature/ftrinputtype.h"
#include "feature/ftrupdatepayload.h"
#include "feature/ftrdieset.h"

using namespace ftr;

using boost::uuids::uuid;

QIcon DieSet::icon = QIcon(":/resources/images/constructionDieSet.svg");

DieSet::DieSet()
: Base()
, prmObserver(std::make_unique<prm::Observer>(std::bind(&DieSet::setModelDirty, this)))
, sShape(std::make_unique<ann::SeerShape>())
{
  name = QObject::tr("DieSet");
  mainSwitch->setUserValue<int>(gu::featureTypeAttributeTitle, static_cast<int>(getType()));
  
  length = std::make_shared<prm::Parameter>(prm::Names::Length, 1.0, prm::Tags::Length);
  length->setConstraint(prm::Constraint::buildNonZeroPositive());
  length->connect(*prmObserver);
  parameters.push_back(length.get());
  
  width = std::make_shared<prm::Parameter>(prm::Names::Width, 1.0, prm::Tags::Width);
  width->setConstraint(prm::Constraint::buildNonZeroPositive());
  width->connect(*prmObserver);
  parameters.push_back(width.get());
  
  lengthPadding = std::make_shared<prm::Parameter>
  (
    QObject::tr("Length Padding")
    , prf::manager().rootPtr->features().dieset().get().lengthPadding()
  );
  lengthPadding->setConstraint(prm::Constraint::buildZeroPositive());
  lengthPadding->connectValue(std::bind(&DieSet::setModelDirty, this));
  parameters.push_back(lengthPadding.get());
  
  widthPadding = std::make_shared<prm::Parameter>
  (
    QObject::tr("Width Padding")
    , prf::manager().rootPtr->features().dieset().get().widthPadding()
  );
  widthPadding->setConstraint(prm::Constraint::buildZeroPositive());
  widthPadding->connectValue(std::bind(&DieSet::setModelDirty, this));
  parameters.push_back(widthPadding.get());
  
  origin = std::make_shared<prm::Parameter>
  (
    prm::Names::Origin
    , osg::Vec3d(-1.0, -1.0, -1.0)
    , prm::Tags::Origin
  );
  origin->connect(*prmObserver);
  parameters.push_back(origin.get());
  
  autoCalc = std::make_shared<prm::Parameter>
  (
    prm::Names::AutoSize
    , true
    , prm::Tags::AutoSize
  );
  autoCalc->connectValue(std::bind(&DieSet::setModelDirty, this));
  parameters.push_back(autoCalc.get());
  
  annexes.insert(std::make_pair(ann::Type::SeerShape, sShape.get()));
  
  lengthLabel = new lbr::PLabel(length.get());
  overlaySwitch->addChild(lengthLabel.get());
  
  widthLabel = new lbr::PLabel(width.get());
  overlaySwitch->addChild(widthLabel.get());
  
  lengthPaddingLabel = new lbr::PLabel(lengthPadding.get());
  overlaySwitch->addChild(lengthPaddingLabel.get());
  
  widthPaddingLabel = new lbr::PLabel(widthPadding.get());
  overlaySwitch->addChild(widthPaddingLabel.get());
  
  originLabel = new lbr::PLabel(origin.get());
  overlaySwitch->addChild(originLabel.get());
  
  autoCalcLabel = new lbr::PLabel(autoCalc.get());
  overlaySwitch->addChild(autoCalcLabel.get());
}

DieSet::~DieSet()
{
}

double DieSet::getLength() const
{
  return length->getDouble();
}

double DieSet::getWidth() const
{
  return width->getDouble();
}

void DieSet::updateModel(const UpdatePayload &payloadIn)
{
  setFailure();
  lastUpdateLog.clear();
  sShape->reset();
  try
  {
    prm::ObserverBlocker block(*prmObserver);
    
    double h = 50.0; //height
    double zPadding = 50.0; //distance from bottom of bounding box to top of set.
    if (autoCalc->getBool())
    {
      if (payloadIn.updateMap.count(strip) != 1)
        throw std::runtime_error("couldn't find 'strip' input");
      const ftr::Base *sbf = payloadIn.updateMap.equal_range(strip).first->second;
      if(!sbf->hasAnnex(ann::Type::SeerShape))
        throw std::runtime_error("no seer shape for strip");
      const ann::SeerShape &sss = sbf->getAnnex<ann::SeerShape>(); //part seer shape.
      const TopoDS_Shape &ss = sss.getRootOCCTShape(); //part shape.
      
      occt::BoundingBox sbbox(ss); //blank bounding box.
      
      gp_Pnt bbc = sbbox.getCorners().front();
      gp_Vec xVec(-lengthPadding->getDouble(), 0.0, 0.0);
      gp_Vec yVec(0.0, -widthPadding->getDouble(), 0.0);
      gp_Vec zVec(0.0, 0.0, -zPadding - h);
      
      gp_Pnt corner = bbc.Translated(xVec).Translated(yVec).Translated(zVec);
      origin->setValue(osg::Vec3d(corner.X(), corner.Y(), corner.Z()));
      double l = sbbox.getLength() + 2 * lengthPadding->getDouble();
      double w = sbbox.getWidth() + 2 * widthPadding->getDouble();
      length->setValue(l);
      width->setValue(w);
    }
    
    //assumptions on orientation.
    osg::Vec3d to = origin->getVector(); //temp origin.
    gp_Ax2 sys(gp_Pnt(to.x(), to.y(), to.z()), gp_Dir(0.0, 0.0, 1.0), gp_Dir(1.0, 0.0, 0.0));
    BoxBuilder b(length->getDouble(), width->getDouble(), h, sys);
    TopoDS_Shape out = b.getSolid();
    ShapeCheck check(out);
    if (!check.isValid())
      throw std::runtime_error("shapeCheck failed");
    
    //No shape consistency yet.
    sShape->setOCCTShape(out, getId());
    sShape->ensureNoNils();
    
    //update label locations
    osg::Vec3d lLoc = //length label location.
      origin->getVector()
      + osg::Vec3d(1.0, 0.0, 0.0) * length->getDouble() / 2.0
      + osg::Vec3d(0.0, 0.0, 1.0) * h;
    lengthLabel->setMatrix(osg::Matrixd::translate(lLoc));
    
    osg::Vec3d wLoc = //length label location.
      origin->getVector()
      + osg::Vec3d(1.0, 0.0, 0.0) * length->getDouble()
      + osg::Vec3d(0.0, 1.0, 0.0) * width->getDouble() / 2.0
      + osg::Vec3d(0.0, 0.0, 1.0) * h;
    widthLabel->setMatrix(osg::Matrixd::translate(wLoc));
    
    osg::Vec3d lpLoc = //length padding label location.
      origin->getVector()
      + osg::Vec3d(0.0, 1.0, 0.0) * width->getDouble() / 2.0
      + osg::Vec3d(0.0, 0.0, 1.0) * h;
    lengthPaddingLabel->setMatrix(osg::Matrixd::translate(lpLoc));
    
    osg::Vec3d wpLoc = //width padding label location.
      origin->getVector()
      + osg::Vec3d(1.0, 0.0, 0.0) * length->getDouble() / 2.0
      + osg::Vec3d(0.0, 1.0, 0.0) * width->getDouble()
      + osg::Vec3d(0.0, 0.0, 1.0) * h;
    widthPaddingLabel->setMatrix(osg::Matrixd::translate(wpLoc));
    
    originLabel->setMatrix(osg::Matrixd::translate(origin->getVector()));
    
    osg::Vec3d acLoc = //auto calc label location
      origin->getVector()
      + osg::Vec3d(length->getDouble() / 2.0, 0.0, 0.0)
      + osg::Vec3d(0.0, width->getDouble() / 2.0, 0.0);
    autoCalcLabel->setMatrix(osg::Matrixd::translate(acLoc));
    
    updateLabelColors();
    
    setSuccess();
  }
  catch (const Standard_Failure &e)
  {
    std::ostringstream s; s << "OCC Error in DieSet update: " << e.GetMessageString() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (const std::exception &e)
  {
    std::ostringstream s; s << "Standard error in DieSet update: " << e.what() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (...)
  {
    std::ostringstream s; s << "Unknown error in DieSet update. " << std::endl;
    lastUpdateLog += s.str();
  }
  setModelClean();
  if (!lastUpdateLog.empty())
    std::cout << std::endl << lastUpdateLog;
}

void DieSet::updateLabelColors()
{
  if (autoCalc->getBool())
  {
    //red while auto calculation.
    lengthLabel->setTextColor(osg::Vec4(1.0, 0.0, 0.0, 1.0));
    widthLabel->setTextColor(osg::Vec4(1.0, 0.0, 0.0, 1.0));
    originLabel->setTextColor(osg::Vec4(1.0, 0.0, 0.0, 1.0));
    
    lengthPaddingLabel->setTextColor();
    widthPaddingLabel->setTextColor();
    
  }
  else
  {
    lengthLabel->setTextColor();
    widthLabel->setTextColor();
    originLabel->setTextColor();
    
    lengthPaddingLabel->setTextColor(osg::Vec4(1.0, 0.0, 0.0, 1.0));
    widthPaddingLabel->setTextColor(osg::Vec4(1.0, 0.0, 0.0, 1.0));
  }
}

void DieSet::serialWrite(const boost::filesystem::path &dIn)
{
  prj::srl::dsts::DieSet dso
  (
    Base::serialOut(),
    sShape->serialOut(),
    length->serialOut(),
    lengthPadding->serialOut(),
    width->serialOut(),
    widthPadding->serialOut(),
    origin->serialOut(),
    autoCalc->serialOut(),
    lengthLabel->serialOut(),
    widthLabel->serialOut(),
    lengthPaddingLabel->serialOut(),
    widthPaddingLabel->serialOut(),
    originLabel->serialOut(),
    autoCalcLabel->serialOut()
  );
  
  xml_schema::NamespaceInfomap infoMap;
  std::ofstream stream(buildFilePathName(dIn).string());
  prj::srl::dsts::dieset(stream, dso, infoMap);
}

void DieSet::serialRead(const prj::srl::dsts::DieSet &dsIn)
{
  Base::serialIn(dsIn.base());
  sShape->serialIn(dsIn.seerShape());
  length->serialIn(dsIn.length());
  lengthPadding->serialIn(dsIn.lengthPadding());
  width->serialIn(dsIn.width());
  widthPadding->serialIn(dsIn.widthPadding());
  origin->serialIn(dsIn.origin());
  autoCalc->serialIn(dsIn.autoCalc());
  
  lengthLabel->serialIn(dsIn.lengthPLabel());
  lengthPaddingLabel->serialIn(dsIn.lengthPaddingPLabel());
  widthLabel->serialIn(dsIn.widthPLabel());
  widthPaddingLabel->serialIn(dsIn.widthPaddingPLabel());
  originLabel->serialIn(dsIn.originPLabel());
  autoCalcLabel->serialIn(dsIn.autoCalcPLabel());
}
