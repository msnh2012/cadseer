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

#include <tools/idtools.h>
#include <feature/message.h>

using namespace ftr;

using boost::uuids::uuid;

Message::Message() :
  featureId(gu::createNilId()),
  state(0),
  stateOffset(0),
  freshValue(false)
{}

Message::Message(const uuid &idIn, State stateIn, unsigned long stateOffsetIn, bool freshValueIn) :
  featureId(idIn),
  state(stateIn),
  stateOffset(stateOffsetIn),
  freshValue(freshValueIn)
{}

Message::Message(const uuid &idIn, const QString &stringIn) :
  featureId(idIn),
  string(stringIn)
{}