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

#ifndef SLC_SELECTIONMESSAGE_H
#define SLC_SELECTIONMESSAGE_H

#include <vector>

#include <boost/uuid/uuid.hpp>

#include <osg/Vec3d>

#include "feature/ftrtypes.h"
#include "selection/slcaccrue.h"
#include "selection/slcdefinitions.h"

namespace slc
{
  struct Message
  {
    Message() = default;
    Message(Mask);
    Message(const boost::uuids::uuid& fIdIn); //feature id
    Type type = {Type::None};
    Accrue accrue = {Accrue::None};
    Mask selectionMask = {None};
    ftr::Type featureType = {ftr::Type::Base};
    boost::uuids::uuid featureId;
    boost::uuids::uuid shapeId;
    osg::Vec3d pointLocation;
  };
  
  inline bool operator==(const Message& lhs, const Message& rhs)
  {
    bool out =
    (
        (lhs.type == rhs.type) &&
        (lhs.featureId == rhs.featureId) &&
        (lhs.shapeId == rhs.shapeId)
        //shouldn't need to test featureType if id's are the same
        //selection mask is meaningless for equality test.
    );
    
    if (slc::isPointType(lhs.type))
        out = (out && (lhs.pointLocation == rhs.pointLocation));
    
    return out;
  }
  
  inline bool operator!=(const Message& lhs, const Message& rhs)
  {
    return !(lhs == rhs);
  }
  
  typedef std::vector<Message> Messages;
  bool has(const Messages &messagesIn, const Message &messageIn);
  void add(Messages &messagesIn, const Message &messageIn);
  int remove(Messages &messagesIn, const Message &messageIn);
  std::vector<Messages> split(const Messages&); //!< group messages by feature id
}

#endif // SLC_SELECTIONMESSAGE_H
