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

#include <boost/filesystem.hpp>

#include <QFile>

#include <osgDB/ReadFile>
#include <osgManipulator/Dragger>

#include <modelviz/nodemaskdefs.h>
#include "circlebuilder.h"
#include "cylinderbuilder.h"
#include "spherebuilder.h"
#include "conebuilder.h"
#include "torusbuilder.h"
#include "iconbuilder.h"
#include "geometrylibraryprivate.h"
#include "geometrylibrary.h"

using namespace lbr;

Manager& Manager::getManager()
{
  static Manager manager;
  return manager;
}

Manager::Manager() : mapWrapper(new MapWrapper)
{
  setup();
}

void Manager::link(const Tag& tagIn, osg::Geometry *geometryIn)
{
  MapRecord record;
  record.tag = tagIn;
  record.geometry = geometryIn;
  mapWrapper->mapContainer.insert(record);
  
  assert(record.geometry.valid());
}

bool Manager::isLinked(const Tag& tagIn)
{
  typedef MapContainer::index<MapRecord::ByTag>::type List;
  const List &list = mapWrapper->mapContainer.get<MapRecord::ByTag>();
  List::const_iterator it = list.find(tagIn);
  if(it == list.end())
    return false;
  return true;
}

void Manager::setup()
{
  this->link(lbr::csys::TranslationLineTag, lbr::csys::buildTranslationLine());
  this->link(lbr::csys::TranslationCylinderTag, lbr::csys::buildTranslationCylinder());
  this->link(lbr::csys::TranslationConeTag, lbr::csys::buildTranslationCone());
  this->link(lbr::csys::SphereTag, lbr::csys::buildSphere());
  this->link(lbr::csys::RotationLineTag, lbr::csys::buildRotationLine());
  this->link(lbr::csys::RotationTorusTag, lbr::csys::buildRotationTorus());
  this->link(lbr::csys::IconLinkTag, lbr::csys::buildIconLink());
  this->link(lbr::csys::IconUnlinkTag, lbr::csys::buildIconUnlink());
  
  //there seems to be someking of bug with the openscenegraph svg loader.
  //getting artifacts in background. Going to leave for now as we are going
  //to use qt to load icons anyway.
  
  this->link(lbr::dim::ArrowTag, lbr::dim::buildArrow());
}

osg::Geometry* Manager::getGeometry(const Tag& tagIn)
{
  typedef MapContainer::index<MapRecord::ByTag>::type List;
  List &list = mapWrapper->mapContainer.get<MapRecord::ByTag>();
  List::iterator it = list.find(tagIn);
  assert(it != list.end());
  
  return it->geometry.get();
}

osg::Geometry* lbr::csys::buildTranslationLine()
{
  osg::Geometry *out = new osg::Geometry();
  out->setNodeMask(mdv::noIntersect);
  osg::Vec3Array* vertices = new osg::Vec3Array(2);
  (*vertices)[0] = osg::Vec3(0.0f,0.0f,0.0f);
  (*vertices)[1] = osg::Vec3(0.0f,0.0f,1.0f);
  out->setVertexArray(vertices);
  out->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::LINES,0,2));
  out->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
  
  return out;
}

osg::Geometry* lbr::csys::buildTranslationCylinder()
{
  CylinderBuilder cBuilder;
  cBuilder.setRadius(0.05);
  cBuilder.setHeight(1.0);
  cBuilder.setIsoLines(16);
  osg::Geometry *out = cBuilder;
  
  osgManipulator::setDrawableToAlwaysCull(*out);
  
  return out;
}

osg::Geometry* lbr::csys::buildTranslationCone()
{
  ConeBuilder builder;
  builder.setRadius(0.05);
  builder.setHeight(0.2f);
  builder.setIsoLines(16);
  osg::Geometry *coneGeometry = builder;
  
  //translate all points 1 unit in z.
  osg::Vec3d translation(0.0, 0.0, 1.0);
  osg::Vec3Array *conePoints = dynamic_cast<osg::Vec3Array *>(coneGeometry->getVertexArray());
  assert(conePoints);
  for (auto &point : *conePoints)
    point += translation;
  
  return coneGeometry;
}

osg::Geometry* lbr::csys::buildSphere()
{
  SphereBuilder sBuilder;
  sBuilder.setRadius(0.05);
  sBuilder.setIsoLines(16);
  
  return sBuilder;
}

osg::Geometry* lbr::csys::buildRotationLine()
{
  CircleBuilder cBuilder;
  cBuilder.setSegments(16);
  cBuilder.setRadius(0.75);
  cBuilder.setAngularSpanDegrees(90.0);
  std::vector<osg::Vec3d> circlePoints = cBuilder;
  
  osg::Vec3Array *points = new osg::Vec3Array();
  std::copy(circlePoints.begin(), circlePoints.end(), std::back_inserter(*points));
  
  osg::Geometry *out = new osg::Geometry();
  out->setNodeMask(mdv::noIntersect);
  out->setVertexArray(points);
  out->setUseDisplayList(false);
  out->setUseVertexBufferObjects(true);
  
  osg::PrimitiveSet::Mode mode = (cBuilder.isCompleteCircle()) ? osg::PrimitiveSet::LINE_LOOP :
    osg::PrimitiveSet::LINE_STRIP;

  out->addPrimitiveSet(new osg::DrawArrays(mode, 0, points->size()));
  
  out->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
  
  return out;
}

osg::Geometry* lbr::csys::buildRotationTorus()
{
  TorusBuilder tBuilder;
  tBuilder.setMajorRadius(0.75);
  tBuilder.setMajorIsoLines(16);
  tBuilder.setMinorRadius(0.0375);
  tBuilder.setMinorIsoLines(16);
  tBuilder.setAngularSpanDegrees(90.0);
  
  osg::Geometry *torus = tBuilder;
  osgManipulator::setDrawableToAlwaysCull(*torus);
  
  return torus;
}

osg::Geometry* lbr::csys::buildIconLink()
{
  std::string resourceName = ":/resources/images/linkIcon.svg";
  resourceName = fileNameFromResource(resourceName);
  osg::Image *linkImage = osgDB::readImageFile(resourceName);
  assert(linkImage);
  IconBuilder iBuilder(linkImage);
  return iBuilder;
}

osg::Geometry* lbr::csys::buildIconUnlink()
{
  std::string resourceName = ":/resources/images/unlinkIcon.svg";
  resourceName = fileNameFromResource(resourceName);
  osg::Image *unlinkImage = osgDB::readImageFile(resourceName);
  assert(unlinkImage);
  IconBuilder iBuilder(unlinkImage);
  return iBuilder;
}

std::string lbr::csys::fileNameFromResource(const std::string &resourceName)
{
  std::string fileName(resourceName);
  fileName.erase(fileName.begin(), fileName.begin()); //remove starting ':'
  std::replace(fileName.begin(), fileName.end(), '/', '_');
  
  boost::filesystem::path filePath = boost::filesystem::temp_directory_path();
  filePath /= fileName;

  if (!boost::filesystem::exists(filePath))
  {
    QFile resourceFile(resourceName.c_str());
    if (!resourceFile.open(QIODevice::ReadOnly | QIODevice::Text))
      std::cout << "couldn't resource file" << std::endl;
    QByteArray buffer = resourceFile.readAll();
    resourceFile.close();
     
    QFile newFile(QString::fromStdString(filePath.string()));
    if (!newFile.open(QIODevice::WriteOnly | QIODevice::Text))
      std::cout << "couldn't open new temp file" << std::endl;
    std::cout << "newfilename is: " << filePath.string() << std::endl;
    newFile.write(buffer);
    newFile.close();
  }
  return filePath.string();
}

/*! @brief build an arrow for a dimension
 * 
 * @details The arrow is built along the x direction. 
 * Symmetrical around the x axis with the point at 0,0,0 and 
 * the base from 0, .5, 0 to 0, -.5, 0. Height and width are both 
 * 1 unit and designed to be added to a scale node for sizing. 
 * color is not established and designed to be used with
 * material state.
 * 
 * @return geometry pointer. caller is responsible for memory.
 * 
 */
osg::Geometry* lbr::dim::buildArrow()
{
  osg::Geometry *out = new osg::Geometry();
  
  osg::Vec3Array *array = new osg::Vec3Array();
  array->push_back(osg::Vec3(0.0, 0.0, 0.0));
  array->push_back(osg::Vec3(-1.0, 0.5, 0.0));
  array->push_back(osg::Vec3(-1.0, -0.5, 0.0));
  out->setVertexArray(array);
  
  osg::Vec3Array *normalArray = new osg::Vec3Array();
  normalArray->push_back(osg::Vec3(0.0, 0.0, 1.0));
  out->setNormalArray(normalArray);
  out->setNormalBinding(osg::Geometry::BIND_OVERALL);
  
  out->setUseDisplayList(false);
  out->setUseVertexBufferObjects(true);
  
  out->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::TRIANGLES, 0, 3));
  return out;
}
