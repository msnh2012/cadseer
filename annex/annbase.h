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

#ifndef ANN_BASE_H
#define ANN_BASE_H

#include <map>

namespace ann
{
  enum class Type
  {
    Base,
    CSysDragger,
    SeerShape,
    IntersectionMapper,
    InstanceMapper,
    SurfaceMesh,
    SolidMesh,
    LawFunction
  };
  
  const std::string& toString(const Type &tIn);
  const Type& toType(const std::string &sIn);
  
  class Base
  {
  public:
    Base();
    virtual ~Base();
    virtual Type getType(){return Type::Base;}
  };
  
  //only 1 of a type per feature?
  typedef std::map<Type, Base*> Annexes; 
}

#endif // ANN_BASE_H
