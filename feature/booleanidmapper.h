/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2016  Thomas S. Anderson blobfish.at.gmx.com
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

#ifndef FTR_BOOLEANIDMAPPER_H
#define FTR_BOOLEANIDMAPPER_H

#include <map>

#include <feature/inputtypes.h>

class BOPAlgo_Builder;
class TopoDS_Shape;

namespace ftr
{
  class Base;
  class ResultContainerWrapper;
  typedef std::map<InputTypes, const Base*> UpdateMap;
  
  class BooleanIdMapper
  {
  public:
    BooleanIdMapper(const UpdateMap &, const BOPAlgo_Builder &, ResultContainerWrapper &);
    void go();
    
    const UpdateMap &updateMap;
    const BOPAlgo_Builder &builder; //couldn't make const. accessor functions not const.
    ResultContainerWrapper &outContainer;
  };
}


#endif // FTR_BOOLEANIDMAPPER_H
