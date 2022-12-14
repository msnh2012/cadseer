/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2019  Thomas S. Anderson blobfish.at.gmx.com
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

#include <boost/optional/optional.hpp>

#include "tools/featuretools.h"
#include "message/msgnode.h"
#include "project/prjproject.h"
#include "selection/slceventhandler.h"
#include "annex/annseershape.h"
#include "feature/ftrinputtype.h"
#include "feature/ftrline.h"
#include "command/cmdline.h"

using namespace cmd;

Line::Line() : Base() {}

Line::~Line() {}

std::string Line::getStatusMessage()
{
  return QObject::tr("Select geometry for line feature").toStdString();
}

void Line::activate()
{
  isActive = true;
  go();
  sendDone();
}

void Line::deactivate()
{
  isActive = false;
}

void Line::go()
{
  shouldUpdate = false;
  
  const slc::Containers &cs = eventHandler->getSelections();
  if (cs.size() != 2)
  {
    node->sendBlocked(msg::buildStatusMessage("Incorrect selection for line", 2.0));
    return;
  }
  
  ftr::Base const *bf0 = project->findFeature(cs.front().featureId);
  if (!bf0 || !bf0->hasAnnex(ann::Type::SeerShape))
  {
    node->sendBlocked(msg::buildStatusMessage("Invalid first selection", 2.0));
    return;
  }
  const ann::SeerShape &ss0 = bf0->getAnnex<ann::SeerShape>();
  
  ftr::Base const *bf1 = project->findFeature(cs.back().featureId);
  if (!bf1 || !bf1->hasAnnex(ann::Type::SeerShape))
  {
    node->sendBlocked(msg::buildStatusMessage("Invalid second selection", 2.0));
    return;
  }
  const ann::SeerShape &ss1 = bf1->getAnnex<ann::SeerShape>();
  
  ftr::Picks picks;
  picks.push_back(tls::convertToPick(cs.front(), ss0, project->getShapeHistory()));
  picks.back().tag = ftr::Line::pickZero;
  picks.push_back(tls::convertToPick(cs.back(), ss1, project->getShapeHistory()));
  picks.back().tag = ftr::Line::pickOne;
  
  auto *fl = new ftr::Line();
  fl->setPicks(picks);
  project->addFeature(std::unique_ptr<ftr::Line>(fl));
  project->connectInsert(cs.front().featureId, fl->getId(), ftr::InputType{ftr::Line::pickZero});
  project->connectInsert(cs.back().featureId, fl->getId(), ftr::InputType{ftr::Line::pickOne});
  
  shouldUpdate = true;
}
