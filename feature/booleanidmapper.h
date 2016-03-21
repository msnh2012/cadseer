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
#include <set>

#include <boost/uuid/uuid.hpp>

#include <feature/inputtypes.h>

class BOPAlgo_Builder;
class TopoDS_Shape;

namespace ftr
{
  class Base;
  class ResultContainerWrapper;
  class IMapWrapper;
  typedef std::map<InputTypes, const Base*> UpdateMap;
  
  class BooleanIdMapper
  {
  public:
    BooleanIdMapper(const UpdateMap &, BOPAlgo_Builder &, IMapWrapper &, ResultContainerWrapper &);
    void go();
    
    const UpdateMap &updateMap;
    BOPAlgo_Builder &builder; //couldn't make const. accessor functions not const.
    IMapWrapper &iMapWrapper;
    ResultContainerWrapper &outContainer;
  private:
    void goIntersectionEdges();
    void goSingleSplits();
    
    std::set<boost::uuids::uuid> iEdgeCache;
    void goSplitFaces();
    
    TopoDS_Shape rootShape; //!< root shape(compound) of the result container. used for mapping.
  };
}


#endif // FTR_BOOLEANIDMAPPER_H