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


#include "tools/idtools.h"
#include "project/prjproject.h"
#include "message/msgnode.h"
#include "message/msgsift.h"
#include "selection/slceventhandler.h"
#include "viewer/vwrmessage.h"
#include "command/cmdisolate.h"

using namespace cmd;

Isolate::Isolate() : Base("cmd::Isolate"), id(gu::createNilId()), mask(msg::ThreeD | msg::Overlay)
{
  setupDispatcher();
  shouldUpdate = false;
}

Isolate::~Isolate() {}

void Isolate::setFromMessage(const msg::Message &mIn)
{
  mask = mIn.mask;
  
  if (mIn.isVWR())
  {
    vwr::Message vm = mIn.getVWR();
    id = vm.featureId;
  }
}

std::string Isolate::getStatusMessage()
{
  return QObject::tr("Select features for isolate").toStdString();
}

void Isolate::activate()
{
  isActive = true;
  go();
}

void Isolate::deactivate()
{
  isActive = false;
}

void Isolate::go()
{
  if (id.is_nil()) //try to get feature id from selection.
  {
    const slc::Containers &containers = eventHandler->getSelections();
    for (const auto &container : containers)
    {
      if (container.selectionType != slc::Type::Object)
        continue;
      id = container.featureId;
      break; //only works on the first selected object.
    }
  }
  if (id.is_nil())
  {
    node->send(msg::buildSelectionMask(slc::ObjectsEnabled | slc::ObjectsSelectable));
    return;
  }
  
  for (const auto &lid : project->getAllFeatureIds())
  {
    if (id == lid)
    {
      if ((mask & msg::ThreeD).any() && project->isFeatureLeaf(lid))
        node->sendBlocked(msg::buildShowThreeD(lid));
      if ((mask & msg::Overlay).any())
        node->sendBlocked(msg::buildShowOverlay(lid));
    }
    else
    {
      if ((mask & msg::ThreeD).any() && project->isFeatureLeaf(lid))
        node->sendBlocked(msg::buildHideThreeD(lid));
      if ((mask & msg::Overlay).any())
        node->sendBlocked(msg::buildHideOverlay(lid));
    }
  }
  node->sendBlocked(msg::Message(msg::Request | msg::View | msg::Fit));
  sendDone();
}

void Isolate::setupDispatcher()
{
  sift->insert
  (
    msg::Response | msg::Post | msg::Selection | msg::Add
    , std::bind(&Isolate::selectionAdditionDispatched, this, std::placeholders::_1)
  );
}

void Isolate::selectionAdditionDispatched(const msg::Message&)
{
  if (!isActive)
    return;
  
  go();
}
