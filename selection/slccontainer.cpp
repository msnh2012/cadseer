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

#include <algorithm>
#include <boost/optional/optional.hpp>

#include <osg/Geometry>
#include <osg/io_utils>

#include "selection/slccontainer.h"

using namespace slc;

Container::~Container() = default;

std::ostream& slc::operator<<(std::ostream& os, const Container& container)
{
  os << 
    "type is: " << getNameOfType(container.selectionType) <<
    "      accrue type is: " << static_cast<QString>(container.accrue).toStdString() <<
    "      featureid is: " << gu::idToString(container.featureId) <<
    "      shape id is: " << gu::idToString(container.shapeId) << std::endl <<
    "      point location: " << container.pointLocation << std::endl;
  return os;
}

std::ostream& slc::operator<<(std::ostream& os, const Containers& containers)
{
  for (const auto &current : containers)
    os << current;
  return os;
}

bool slc::has(Containers &containersIn, const Container &containerIn)
{
  return std::find(containersIn.begin(), containersIn.end(), containerIn) != containersIn.end();
}
void slc::add(Containers &containersIn, const Container &containerIn)
{
  if (!has(containersIn, containerIn))
    containersIn.push_back(containerIn);
}

void slc::remove(Containers& containersIn, const Container& containerIn)
{
  auto it = std::find(containersIn.begin(), containersIn.end(), containerIn);
  if (it != containersIn.end())
    containersIn.erase(it);
}

std::vector<Containers> slc::split(const Containers &csIn)
{
  std::vector<Containers> out;
  auto add = [&](const Container &cIn)
  {
    for (Containers &c : out)
    {
      if (c.front().featureId == cIn.featureId)
      {
        c.push_back(cIn);
        return;
      }
    }
    out.push_back(Containers(1, cIn));
    return;
  };
  
  for (const auto &c : csIn)
    add(c);
  
  return out;
}
