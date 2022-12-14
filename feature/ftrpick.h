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

#ifndef FTR_PICK_H
#define FTR_PICK_H

#include <vector>
#include <utility>

#include "selection/slcdefinitions.h"
#include "selection/slcaccrue.h"
#include "feature/ftrshapehistory.h"

class TopoDS_Edge;
class TopoDS_Face;
namespace osg{class Vec3d;}

namespace prj{namespace srl{namespace spt{class Pick;}}}

namespace ftr
{
  /*! @struct Pick
   * @brief Selection for a feature.
   * 
   * @details Picks are stored and used in features
   * to resolve what entities from the parents
   * are to be used in modeling algorithms.
   * 
   * @note:
   * StartPoint and EndPoint consider edge orientation where the
   * parameter driven types don't.
   */
  struct Pick
  {
    Pick() = default;
    Pick(const prj::srl::spt::Pick&);
    double u = 0.0; //!< u parameter on edge or face
    double v = 0.0;//!< v parameter on face
    ShapeHistory shapeHistory;
    std::vector<boost::uuids::uuid> highlightIds; //!< highlight ids. up to user to uniquefy
    std::vector<boost::uuids::uuid> resolvedIds; //!< storage for resolved ids from id and history.
    slc::Type selectionType = slc::Type::None; //!< this is needed for fictious shapes: midpoint, center, quadrant, nearest etc..
    std::string tag; //!< this should us link the pick to input feature for isolated pick resolution.
    slc::Accrue accrue; //!< defaults to none
    
    bool operator==(const Pick&) const;
    bool isParameterType() const; //!< midpoint, quadrant and nearest are really same pick with different u.
    bool isParameterEqual(const Pick&) const;
    bool isEmpty() const; //!< an empty pick has empty shapehistory.
    std::vector<boost::uuids::uuid> resolvedOverlap(const Pick&) const; //!< not applicable to parameter types.
    void setParameter(const TopoDS_Edge&, const osg::Vec3d&);
    void setParameter(const TopoDS_Face&, const osg::Vec3d&);
    osg::Vec3d getPoint(const TopoDS_Edge&) const;
    osg::Vec3d getPoint(const TopoDS_Face&) const;
    
    operator prj::srl::spt::Pick() const;
    prj::srl::spt::Pick serialOut() const; //serial rename
    void serialIn(const prj::srl::spt::Pick&); //serial rename
    
    static double parameter(const TopoDS_Edge&, const osg::Vec3d&);
    static std::pair<double, double> parameter(const TopoDS_Face&, const osg::Vec3d&);
    
    static osg::Vec3d point(const TopoDS_Edge&, double);
    static osg::Vec3d point(const TopoDS_Face&, double, double);
  };
  
  typedef std::vector<Pick> Picks;
}

#endif // FTR_PICK_H
