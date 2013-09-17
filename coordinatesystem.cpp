/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2013  tanderson <email>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <osg/Switch>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/PositionAttitudeTransform>
#include <osg/BlendFunc>

#include "nodemaskdefs.h"
#include "coordinatesystem.h"


osg::Node* CoordinateSystem::buildCoordinateSystemNode()
{
  osg::ref_ptr<osg::AutoTransform> base = new osg::AutoTransform();
  base->setAutoScaleToScreen(true);
  osg::ref_ptr<osg::Switch> theSwitch = new osg::Switch();
  base->addChild(theSwitch);
  base->setNodeMask(NodeMask::noSelect);//temp
  
  
  double size = 100.0; 
  
  osg::ref_ptr<osg::PositionAttitudeTransform> arrowTransformX = new osg::PositionAttitudeTransform();
  arrowTransformX->setAttitude(osg::Quat(osg::DegreesToRadians(90.0), osg::Vec3(0.0, 1.0, 0.0)));
  arrowTransformX->addChild(buildArrow(size, osg::Vec4(1.0, 0.0, 0.0, 1.0)));
  theSwitch->addChild(arrowTransformX);
  
  osg::ref_ptr<osg::PositionAttitudeTransform> arrowTransformY = new osg::PositionAttitudeTransform();
  arrowTransformY->setAttitude(osg::Quat(osg::DegreesToRadians(90.0), osg::Vec3(-1.0, 0.0, 0.0)));
  arrowTransformY->addChild(buildArrow(size, osg::Vec4(0.0, 1.0, 0.0, 1.0)));
  theSwitch->addChild(arrowTransformY);
  
  osg::ref_ptr<osg::PositionAttitudeTransform> arrowTransformZ = new osg::PositionAttitudeTransform();
  //define in z so leave tranform at identity.
  arrowTransformZ->addChild(buildArrow(size, osg::Vec4(0.0, 0.0, 1.0, 1.0)));
  theSwitch->addChild(arrowTransformZ);
  
  osg::ref_ptr<osg::PositionAttitudeTransform> planeTransformXY = new osg::PositionAttitudeTransform();
  planeTransformXY->addChild(buildPlane(size, osg::Vec4(1.0, 1.0, 0.0, 0.5)));
  theSwitch->addChild(planeTransformXY);
  
  osg::ref_ptr<osg::PositionAttitudeTransform> planeTransformXZ = new osg::PositionAttitudeTransform();
  planeTransformXZ->setAttitude(osg::Quat(osg::DegreesToRadians(90.0), osg::Vec3(1.0, 0.0, 0.0)));
  planeTransformXZ->addChild(buildPlane(size, osg::Vec4(1.0, 0.0, 1.0, 0.5)));
  theSwitch->addChild(planeTransformXZ);
  
  osg::ref_ptr<osg::PositionAttitudeTransform> planeTransformYZ = new osg::PositionAttitudeTransform();
  planeTransformYZ->setAttitude(osg::Quat(osg::DegreesToRadians(90.0), osg::Vec3(0.0, 1.0, 0.0)));
  planeTransformYZ->addChild(buildPlane(size, osg::Vec4(0.0, 1.0, 1.0, 0.5)));
  theSwitch->addChild(planeTransformYZ);
  
  return base.release();
}

osg::Node* CoordinateSystem::buildArrow(const double &size, const osg::Vec4 &color)
{
  osg::ref_ptr<osg::Group> arrowGroup = new osg::Group();
  
  osg::ref_ptr<osg::ShapeDrawable> arrowCylinderDrawable = new osg::ShapeDrawable
    (new osg::Cylinder(osg::Vec3(0.0, 0.0, size/2.0), size/40.0, size));
  arrowCylinderDrawable->setColor(color);
  osg::ref_ptr<osg::Geode> arrowCylinderGeode = new osg::Geode();
  arrowCylinderGeode->addDrawable(arrowCylinderDrawable);
  
  osg::ref_ptr<osg::ShapeDrawable> arrowConeDrawable = new osg::ShapeDrawable
    (new osg::Cone(osg::Vec3(0.0, 0.0, size), size/20.0, size/10.0));
  arrowConeDrawable->setColor(color);
  osg::ref_ptr<osg::Geode> arrowConeGeode = new osg::Geode();
  arrowConeGeode->addDrawable(arrowConeDrawable);
  
  arrowGroup->addChild(arrowCylinderGeode);
  arrowGroup->addChild(arrowConeGeode);
  
  return arrowGroup.release();
}

osg::Node* CoordinateSystem::buildPlane(const double &size, const osg::Vec4 &color)
{
  double halfSize = size/2.0;
  osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array();
  vertices->push_back(osg::Vec3(halfSize, halfSize, 0.0));
  vertices->push_back(osg::Vec3(-halfSize, halfSize, 0.0));
  vertices->push_back(osg::Vec3(-halfSize, -halfSize, 0.0));
  vertices->push_back(osg::Vec3(halfSize, -halfSize, 0.0));
  
  osg::ref_ptr<osg::Geometry> geomFaces = new osg::Geometry();
  geomFaces->setVertexArray(vertices);
  geomFaces->setUseDisplayList(false);
  geomFaces->setUseVertexBufferObjects(true);
  
  osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
  colors->push_back(color);
  geomFaces->setColorArray(colors.get());
  geomFaces->setColorBinding(osg::Geometry::BIND_OVERALL);
  
  osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array();
  normals->push_back(osg::Vec3(0.0, 0.0, 1.0));
  normals->push_back(osg::Vec3(0.0, 0.0, 1.0));
  normals->push_back(osg::Vec3(0.0, 0.0, 1.0));
  normals->push_back(osg::Vec3(0.0, 0.0, 1.0));
  geomFaces->setNormalArray(normals.get());
  geomFaces->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);
  
  osg::ref_ptr<osg::DrawElementsUInt> indices = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 4);
  (*indices)[0] = 0;
  (*indices)[1] = 1;
  (*indices)[2] = 2;
  (*indices)[3] = 3;
  geomFaces->addPrimitiveSet(indices.get());
  
  osg::ref_ptr<osg::Geode> geode = new osg::Geode;
  geode->addDrawable(geomFaces);
  osg::StateSet* ss = geode->getOrCreateStateSet();
  ss->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
  osg::ref_ptr<osg::BlendFunc> blend = new osg::BlendFunc();
  blend->setFunction(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  ss->setAttributeAndModes(blend);
  
  return geode.release();
}