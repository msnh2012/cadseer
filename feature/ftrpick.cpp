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

#include <osg/Vec3d>

#include <TopoDS_Face.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Vertex.hxx>
#include <BRep_Tool.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepExtrema_DistShapeShape.hxx>

#include "tools/idtools.h"
#include "tools/occtools.h"
#include "globalutilities.h"
#include "project/serial/generated/prjsrlsptpick.h"
#include "feature/ftrpick.h"

using namespace ftr;
using boost::uuids::uuid;

Pick::Pick(const prj::srl::spt::Pick &spIn) : Pick()
{
  serialIn(spIn);
}

prj::srl::spt::Pick Pick::serialOut() const
{
  return prj::srl::spt::Pick
  (
    u, v
    , shapeHistory.serialOut()
    , static_cast<int>(selectionType)
    , tag
    , static_cast<int>(accrue)
  );
}

Pick::operator prj::srl::spt::Pick() const
{
  return serialOut();
}

void Pick::serialIn(const prj::srl::spt::Pick &sPickIn)
{
  u = sPickIn.u();
  v = sPickIn.v();
  shapeHistory.serialIn(sPickIn.history());
  selectionType = static_cast<slc::Type>(sPickIn.selectionType());
  tag = sPickIn.tag();
  accrue = slc::Accrue(sPickIn.accrue());
}

bool Pick::operator==(const Pick &rhs) const
{
  //this is pretty strict.
  if (shapeHistory != rhs.shapeHistory)
    return false;
       
  if (isParameterType() && rhs.isParameterType())
    return isParameterEqual(rhs);
  
  if (tag != rhs.tag)
    return false;
  
  return selectionType == rhs.selectionType;
}

bool Pick::isParameterType() const
{
  return
  (
    (selectionType == slc::Type::QuadrantPoint)
    || (selectionType == slc::Type::NearestPoint)
    || (selectionType == slc::Type::MidPoint)
  );
}

bool Pick::isParameterEqual(const Pick &rhs) const
{
  return (std::fabs(u - rhs.u) < std::numeric_limits<double>::epsilon());
}

bool Pick::isEmpty() const
{
  return shapeHistory.isEmpty();
}
std::vector<boost::uuids::uuid> Pick::resolvedOverlap(const Pick &other) const
{
//   assert(!isParameterType());
//   assert(!other.isParameterType());
  std::vector<uuid> c1 = resolvedIds;
  std::vector<uuid> c2 = other.resolvedIds;
  gu::uniquefy(c1);
  gu::uniquefy(c2);
  
  std::vector<uuid> out;
  std::set_intersection(c1.begin(), c1.end(), c2.begin(), c2.end(), std::back_inserter(out));
  return out;
}

/*! Set u parameter
 * @param edgeIn edge to evaluate.
 * @param pointIn closest point.
 * @see Pick::parameter
 */
void Pick::setParameter(const TopoDS_Edge &edgeIn, const osg::Vec3d &pointIn)
{
  u = Pick::parameter(edgeIn, pointIn);
}

/*! Set u and v parameters
 * @param faceIn face to evaluate.
 * @param pointIn closest point.
 * @see Pick::parameter
 */
void Pick::setParameter(const TopoDS_Face &faceIn, const osg::Vec3d &pointIn)
{
  std::tie(u, v) = Pick::parameter(faceIn, pointIn);
}

/*! Calculate point from u parameter
 * @param edgeIn edge to evaluate.
 * @return point on edge at u.
 * @see Pick::point
 */
osg::Vec3d Pick::getPoint(const TopoDS_Edge &edgeIn) const
{
  return Pick::point(edgeIn, u);
}

/*! Calculate point from parameters
 * @param faceIn face to evaluate.
 * @return point on face at u,v
 * @see Pick::point
 */
osg::Vec3d Pick::getPoint(const TopoDS_Face &faceIn) const
{
  return Pick::point(faceIn, u, v);
}

/*! Calculate closest parameter
 * @param edgeIn edge to evaluate.
 * @param pointIn closest point.
 * @return normalized parameter in range [0,1]
 */
double Pick::parameter(const TopoDS_Edge &edgeIn, const osg::Vec3d &pointIn)
{
  TopoDS_Shape aVertex = BRepBuilderAPI_MakeVertex(gp_Pnt(pointIn.x(), pointIn.y(), pointIn.z())).Vertex();
  BRepExtrema_DistShapeShape dist(edgeIn, aVertex);
  if (dist.NbSolution() < 1)
  {
    std::cout << "Warning: no solution for distshapeshape in Pick::Parameter(Edge)" << std::endl;
    return 0.0;
  }
  if (dist.SupportTypeShape1(1) != BRepExtrema_IsOnEdge)
  {
    std::cout << "Warning: wrong support type in Pick::Parameter(edge)" << std::endl;
    return 0.0;
  }
  
  double closestParameter;
  dist.ParOnEdgeS1(1, closestParameter);
  return occt::normalize(edgeIn, closestParameter);
}

/*! Calculate closest parameters
 * @param faceIn face to evaluate.
 * @param pointIn closest point.
 * @return u, v parameters
 */
std::pair<double, double> Pick::parameter(const TopoDS_Face &faceIn, const osg::Vec3d &pointIn)
{
  std::pair<double, double> out;
  out.first = 0.0;
  out.second = 0.0;
  
  TopoDS_Shape aVertex = BRepBuilderAPI_MakeVertex(gp_Pnt(pointIn.x(), pointIn.y(), pointIn.z())).Vertex();
  BRepExtrema_DistShapeShape dist(faceIn, aVertex);
  if (dist.NbSolution() < 1)
  {
    std::cout << "Warning: no solution for distshapeshape in Pick::Parameter(Face)" << std::endl;
    return out;
  }
  if (dist.SupportTypeShape1(1) != BRepExtrema_IsInFace)
  {
    std::cout << "Warning: wrong support type in Pick::Parameter(Face)" << std::endl;
    return out;
  }
  dist.ParOnFaceS1(1, out.first, out.second);
  
  return out;
}

/*! Calculate point from parameter
 * @param edgeIn edge to evaluate.
 * @param uIn parameter.
 * @return point on edge.
 */
osg::Vec3d Pick::point(const TopoDS_Edge &edgeIn, double uIn)
{
  double firstP, lastP;
  const Handle_Geom_Curve &curve = BRep_Tool::Curve(edgeIn, firstP, lastP);
  double parameterOut = occt::deNormalize(edgeIn, uIn);
  gp_Pnt occPoint;
  curve->D0(parameterOut, occPoint);
  return gu::toOsg(occPoint);
}

/*! Calculate point from parameters
 * @param faceIn face to evaluate.
 * @param uIn parameter.
 * @param vIn parameter.
 * @return point on face.
 */
osg::Vec3d Pick::point(const TopoDS_Face &faceIn, double uIn, double vIn)
{
  Handle_Geom_Surface surface = BRep_Tool::Surface(faceIn);
  gp_Pnt occPoint;
  surface->D0(uIn, vIn, occPoint);
  return gu::toOsg(occPoint);
}
