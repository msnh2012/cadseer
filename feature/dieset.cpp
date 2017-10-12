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

#include <globalutilities.h>
#include <library/plabel.h>
#include <tools/occtools.h>
#include <feature/seershape.h>
#include <feature/shapecheck.h>
#include <feature/boxbuilder.h>
#include <project/serial/xsdcxxoutput/featuredieset.h>
#include <feature/dieset.h>

using namespace ftr;

using boost::uuids::uuid;

QIcon DieSet::icon;

DieSet::DieSet()
{
  if (icon.isNull())
    icon = QIcon(":/resources/images/constructionDieSet.svg");
  
  name = QObject::tr("DieSet");
  mainSwitch->setUserValue(gu::featureTypeAttributeTitle, static_cast<int>(getType()));
  
  length = std::shared_ptr<Parameter>(new Parameter(ParameterNames::Length, 1.0));
  length->setConstraint(ParameterConstraint::buildNonZeroPositive());
  length->connectValue(boost::bind(&DieSet::setModelDirty, this));
  parameterVector.push_back(length.get());
  
  width = std::shared_ptr<Parameter>(new Parameter(ParameterNames::Width, 1.0));
  width->setConstraint(ParameterConstraint::buildNonZeroPositive());
  width->connectValue(boost::bind(&DieSet::setModelDirty, this));
  parameterVector.push_back(width.get());
  
  lengthPadding = std::shared_ptr<Parameter>(new Parameter(QObject::tr("Length Padding"), 25.0));
  lengthPadding->setConstraint(ParameterConstraint::buildZeroPositive());
  lengthPadding->connectValue(boost::bind(&DieSet::setModelDirty, this));
  parameterVector.push_back(lengthPadding.get());
  
  widthPadding = std::shared_ptr<Parameter>(new Parameter(QObject::tr("Width Padding"), 200.0));
  widthPadding->setConstraint(ParameterConstraint::buildZeroPositive());
  widthPadding->connectValue(boost::bind(&DieSet::setModelDirty, this));
  parameterVector.push_back(widthPadding.get());
  
  lengthLabel = new lbr::PLabel(length.get());
  lengthLabel->showName = true;
  lengthLabel->valueHasChanged();
  overlaySwitch->addChild(lengthLabel.get());
  
  widthLabel = new lbr::PLabel(width.get());
  widthLabel->showName = true;
  widthLabel->valueHasChanged();
  overlaySwitch->addChild(widthLabel.get());
  
  lengthPaddingLabel = new lbr::PLabel(lengthPadding.get());
  lengthPaddingLabel->showName = true;
  lengthPaddingLabel->valueHasChanged();
  overlaySwitch->addChild(lengthPaddingLabel.get());
  
  widthPaddingLabel = new lbr::PLabel(widthPadding.get());
  widthPaddingLabel->showName = true;
  widthPaddingLabel->valueHasChanged();
  overlaySwitch->addChild(widthPaddingLabel.get());
}

DieSet::~DieSet()
{
}

double DieSet::getLength() const
{
  return length->getValue();
}

double DieSet::getWidth() const
{
  return width->getValue();
}

void DieSet::updateModel(const UpdatePayload &payloadIn)
{
  setFailure();
  try
  {
    if (payloadIn.updateMap.count(strip) != 1)
      throw std::runtime_error("couldn't find 'strip' input");
    const ftr::Base *sbf = payloadIn.updateMap.equal_range(strip).first->second;
    if(!sbf->hasSeerShape())
      throw std::runtime_error("no seer shape for strip");
    const SeerShape &sss = sbf->getSeerShape(); //part seer shape.
    const TopoDS_Shape &ss = sss.getRootOCCTShape(); //part shape.
    
    occt::BoundingBox sbbox(ss); //blank bounding box.
    
    //assumptions on orientation.
    //always auto calc for now.
    double h = 50.0; //height
    double zPadding = 50.0; //distance from bottom of bounding box to top of set.
    gp_Pnt bbc = sbbox.getCorners().front();
    gp_Vec xVec(-lengthPadding->getValue(), 0.0, 0.0);
    gp_Vec yVec(0.0, -widthPadding->getValue(), 0.0);
    gp_Vec zVec(0.0, 0.0, -zPadding - h);
    
    gp_Pnt corner = bbc.Translated(xVec).Translated(yVec).Translated(zVec);
    double l = sbbox.getLength() + 2 * lengthPadding->getValue();
    double w = sbbox.getWidth() + 2 * widthPadding->getValue();
    length->setValueQuiet(l);
    lengthLabel->valueHasChanged();
    lengthLabel->setTextColor(osg::Vec4(1.0, 0.0, 0.0, 1.0)); //red while always autocalc.
    width->setValueQuiet(w);
    widthLabel->valueHasChanged();
    widthLabel->setTextColor(osg::Vec4(1.0, 0.0, 0.0, 1.0)); //red while always autocalc.
    gp_Ax2 sys(corner, gp_Dir(0.0, 0.0, 1.0), gp_Dir(1.0, 0.0, 0.0));
    BoxBuilder b(l, w, h, sys);
    TopoDS_Shape out = b.getSolid();
    ShapeCheck check(out);
    if (!check.isValid())
      throw std::runtime_error("shapeCheck failed");
    
    //No shape consistency yet.
    seerShape->setOCCTShape(out);
    seerShape->ensureNoNils();
    
    //update label locations
    osg::Vec3d lLoc = //length label location.
      gu::toOsg(corner)
      + osg::Vec3d(1.0, 0.0, 0.0) * l / 2.0
      + osg::Vec3d(0.0, 0.0, 1.0) * h;
    lengthLabel->setMatrix(osg::Matrixd::translate(lLoc));
    
    osg::Vec3d wLoc = //length label location.
      gu::toOsg(corner)
      + osg::Vec3d(1.0, 0.0, 0.0) * l
      + osg::Vec3d(0.0, 1.0, 0.0) * w / 2.0
      + osg::Vec3d(0.0, 0.0, 1.0) * h;
    widthLabel->setMatrix(osg::Matrixd::translate(wLoc));
    
    osg::Vec3d lpLoc = //length padding label location.
      gu::toOsg(corner)
      + osg::Vec3d(0.0, 1.0, 0.0) * w / 2.0
      + osg::Vec3d(0.0, 0.0, 1.0) * h;
    lengthPaddingLabel->setMatrix(osg::Matrixd::translate(lpLoc));
    
    osg::Vec3d wpLoc = //width padding label location.
      gu::toOsg(corner)
      + osg::Vec3d(1.0, 0.0, 0.0) * l / 2.0
      + osg::Vec3d(0.0, 1.0, 0.0) * w
      + osg::Vec3d(0.0, 0.0, 1.0) * h;
    widthPaddingLabel->setMatrix(osg::Matrixd::translate(wpLoc));
    
    
    setSuccess();
  }
  catch (const Standard_Failure &e)
  {
    std::cout << std::endl << "Error in DieSet update. " << e.GetMessageString() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << std::endl << "Error in DieSet update. " << e.what() << std::endl;
  }
  catch (...)
  {
    std::cout << std::endl << "Unknown error in DieSet update. " << std::endl;
  }
  setModelClean();
}

void DieSet::serialWrite(const QDir &dIn)
{
  prj::srl::FeatureDieSet dso
  (
    Base::serialOut(),
   length->serialOut(),
   lengthPadding->serialOut(),
   width->serialOut(),
   widthPadding->serialOut(),
   autoCalc
  );
  
  xml_schema::NamespaceInfomap infoMap;
  std::ofstream stream(buildFilePathName(dIn).toUtf8().constData());
  prj::srl::dieset(stream, dso, infoMap);
}

void DieSet::serialRead(const prj::srl::FeatureDieSet &dsIn)
{
  Base::serialIn(dsIn.featureBase());
  length->serialIn(dsIn.length());
  lengthPadding->serialIn(dsIn.lengthPadding());
  width->serialIn(dsIn.width());
  widthPadding->serialIn(dsIn.widthPadding());
  autoCalc = dsIn.autoCalc();
}