/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2018  Thomas S. Anderson blobfish.at.gmx.com
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

#include <TopoDS.hxx>

#include "project/prjproject.h"
#include "message/msgnode.h"
#include "selection/slceventhandler.h"
#include "annex/annseershape.h"
#include "feature/ftrinputtype.h"
#include "feature/ftrremovefaces.h"
#include "command/cmdremovefaces.h"

using boost::uuids::uuid;

using namespace cmd;

RemoveFaces::RemoveFaces() : Base() {}
RemoveFaces::~RemoveFaces() {}

std::string RemoveFaces::getStatusMessage()
{
  return QObject::tr("Select faces to remove").toStdString();
}

void RemoveFaces::activate()
{
  isActive = true;
  go();
  sendDone();
}

void RemoveFaces::deactivate()
{
  isActive = false;
}

void RemoveFaces::go()
{
  const slc::Containers &containers = eventHandler->getSelections();
  if (containers.empty())
  {
    node->sendBlocked(msg::buildStatusMessage("Wrong pre selection for remove faces", 2.0));
    shouldUpdate = false;
    return;
  }
  uuid fId = gu::createNilId();
  ftr::Picks picks;
  for (const auto &c : containers)
  {
    //make sure all selections belong to the same feature.
    if (fId.is_nil())
      fId = c.featureId;
    if (fId != c.featureId)
      continue;
    
    ftr::Base *bf = project->findFeature(c.featureId);
    if (!bf->hasAnnex(ann::Type::SeerShape))
      continue;
    const ann::SeerShape &ss = bf->getAnnex<ann::SeerShape>();
    if (!c.shapeId.is_nil())
    {
      assert(ss.hasId(c.shapeId));
      if (!ss.hasId(c.shapeId))
      {
        std::cerr << "WARNING: seershape doesn't have id from selection in cmd::RemoveFaces::go" << std::endl;
        continue;
      }
      const TopoDS_Shape &fs = ss.getOCCTShape(c.shapeId);
      assert(fs.ShapeType() == TopAbs_FACE);
      if (fs.ShapeType() != TopAbs_FACE)
        continue;
      ftr::Pick p(c.shapeId, 0.0, 0.0);
      p.setParameter(TopoDS::Face(fs), c.pointLocation);
      p.shapeHistory = project->getShapeHistory().createDevolveHistory(p.id);
      picks.push_back(p);
    }
  }
  if (fId.is_nil())
  {
    node->sendBlocked(msg::buildStatusMessage("No feature id for remove face", 2.0));
    shouldUpdate = false;
    return;
  }
    
  std::shared_ptr<ftr::RemoveFaces> remove(new ftr::RemoveFaces());
  remove->setPicks(picks);
  project->addFeature(remove);
  project->connectInsert(fId, remove->getId(), ftr::InputType{ftr::InputType::target});
  
  node->sendBlocked(msg::buildHideThreeD(fId));
  node->sendBlocked(msg::buildHideOverlay(fId));
  
  node->send(msg::Message(msg::Request | msg::Selection | msg::Clear));
}
