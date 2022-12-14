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

#ifndef FTR_TYPES_H
#define FTR_TYPES_H

#include <assert.h>
#include <map>
#include <string>

namespace ftr
{
  //! feature types. make sure and update function below.
  enum class Type
  {
    Base, //!< feature base class.
    CSys, //!< feature base class.
    Box, //!< feature box class.
    Sphere, //!< feature sphere class.
    Cone, //!< feature cone class.
    Cylinder, //!< feature cylinder class.
    Blend, //!< feature blend class.
    Chamfer, //!< feature chamfer class.
    Draft, //!< feature draft class.
    Inert, //!< feature inert class.
    Boolean, //!< feature boolean base class.
    Union, //!< feature union class.
    Subtract, //!< feature subtract class.
    Intersect, //!< feature intersect class.
    DatumPlane, //!< feature datum plane class.
    Hollow, //!< feature hollow class.
    Oblong, //!< feature oblong class.
    Extract, //!< feature extract class.
    Squash, //!< feature squash class.
    Strip, //!< feature strip class.
    Nest, //!< feature nest class.
    DieSet, //!< feature dieset class.
    Quote, //!< feature quote class.
    Refine, //!< feature refine class.
    InstanceLinear, //!< feature for linear patterns.
    InstanceMirror, //!< feature for mirrored patterns.
    InstancePolar, //!< feature for polar patterns.
    Offset, //!< feature for offset shapes.
    Thicken, //!< feature for thickening sheets.
    Sew, //!< feature for sewing sheets.
    Trim, //!< feature for trimming solids.
    RemoveFaces, //!< feature for simplifing solids.
    Torus, //!< feature for torus primitive
    Thread, //!< feature for screw threads
    DatumAxis, //!< feature for datum axis
    Sketch, //!< feature for sketch
    Extrude, //!< feature for extrude
    Revolve, //!< feature for revolve
    SurfaceMesh, //!< feature for surface mesh creation.
    Line, //!< feature for lines
    TransitionCurve, //!< feature for lines
    Ruled, //!< feature for ruled surfaces
    ImagePlane, //!< feature for image planes
    Sweep, //!< feature for sweep surfaces
    DatumSystem, //!< feature for datum coordinate systems
    SurfaceReMesh, //!< feature for surface remesh
    SurfaceMeshFill, //!< feature for surface remesh
    MapPCurve, //!< feature for mapping 2d pcurves to 3d surface curves
    Untrim, //!< feature for removing trim of faces.
    Face, //!< feature for creating a face. 
    Fill, //!< feature for creating a fill face. 
    Prism,
    UnderCut,
    Mutate,
    LawSpine
  };
  
  inline const static std::string& toString(Type typeIn)
  {
    typedef std::map<Type, const std::string> LocalMap;
    const static LocalMap strings = 
    {
      {Type::Base, "Base"},
      {Type::CSys, "CSys"},
      {Type::Box, "Box"},
      {Type::Sphere, "Sphere"},
      {Type::Cone, "Cone"},
      {Type::Cylinder, "Cylinder"},
      {Type::Blend, "Blend"},
      {Type::Chamfer, "Chamfer"},
      {Type::Draft, "Draft"},
      {Type::Inert, "Inert"},
      {Type::Boolean, "Boolean"},
      {Type::Union, "Union"},
      {Type::Subtract, "Subtract"},
      {Type::Intersect, "Intersect"},
      {Type::DatumPlane, "DatumPlane"},
      {Type::Hollow, "Hollow"},
      {Type::Oblong, "Oblong"},
      {Type::Extract, "Extract"},
      {Type::Squash, "Squash"},
      {Type::Strip, "Strip"},
      {Type::Nest, "Nest"},
      {Type::DieSet, "DieSet"},
      {Type::Quote, "Quote"},
      {Type::Refine, "Refine"},
      {Type::InstanceLinear, "InstanceLinear"},
      {Type::InstanceMirror, "InstanceMirror"},
      {Type::InstancePolar, "InstancePolar"},
      {Type::Offset, "Offset"},
      {Type::Thicken, "Thicken"},
      {Type::Sew, "Sew"},
      {Type::Trim, "Trim"},
      {Type::RemoveFaces, "RemoveFaces"},
      {Type::Torus, "Torus"},
      {Type::Thread, "Thread"},
      {Type::DatumAxis, "DatumAxis"},
      {Type::Sketch, "Sketch"},
      {Type::Extrude, "Extrude"},
      {Type::Revolve, "Revolve"},
      {Type::SurfaceMesh, "SurfaceMesh"},
      {Type::Line, "Line"},
      {Type::TransitionCurve, "TransitionCurve"},
      {Type::Ruled, "Ruled"},
      {Type::ImagePlane, "ImagePlane"},
      {Type::Sweep, "Sweep"},
      {Type::DatumSystem, "DatumSystem"},
      {Type::SurfaceReMesh, "SurfaceReMesh"},
      {Type::SurfaceMeshFill, "SurfaceMeshFill"},
      {Type::MapPCurve, "MapPCurve"},
      {Type::Untrim, "Untrim"},
      {Type::Face, "Face"},
      {Type::Fill, "Fill"},
      {Type::Prism, "Prism"},
      {Type::UnderCut, "UnderCut"},
      {Type::Mutate, "Mutate"},
      {Type::LawSpine, "LawSpine"}
    };
    
    assert(strings.count(typeIn) > 0);
    return strings.at(typeIn);
  }
}

#endif //FTR_TYPES_H
