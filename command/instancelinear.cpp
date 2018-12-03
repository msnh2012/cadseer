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

#include <memory>

#include <application/application.h>
#include <application/mainwindow.h>
#include <viewer/widget.h>
#include <project/project.h>
#include <message/node.h>
#include <selection/eventhandler.h>
#include <parameter/parameter.h>
#include <feature/inputtype.h>
#include <feature/instancelinear.h>
#include <command/instancelinear.h>

using namespace cmd;

InstanceLinear::InstanceLinear() : Base() {}
InstanceLinear::~InstanceLinear() {}

std::string InstanceLinear::getStatusMessage()
{
  return QObject::tr("Select feature or geometry for linear instance").toStdString();
}

void InstanceLinear::activate()
{
  isActive = true;
  go();
  sendDone();
}

void InstanceLinear::deactivate()
{
  isActive = false;
}

void InstanceLinear::go()
{
  bool created = false;
  
  const slc::Containers &containers = eventHandler->getSelections();
  for (const auto &c : containers)
  {
    ftr::Base *bf = project->findFeature(c.featureId);
    if (!bf->hasAnnex(ann::Type::SeerShape))
      continue;
    
    std::shared_ptr<ftr::InstanceLinear> instance(new ftr::InstanceLinear());
    
    ftr::Pick pick;
    pick.id = c.shapeId;
    if (!pick.id.is_nil())
      pick.shapeHistory = project->getShapeHistory().createDevolveHistory(pick.id);
    instance->setPick(pick);
    
    instance->setCSys(viewer->getCurrentSystem());
    
    project->addFeature(instance);
    project->connect(c.featureId, instance->getId(), ftr::InputType{ftr::InputType::target});
    created = true;
    
    node->sendBlocked(msg::buildHideThreeD(c.featureId));
    node->sendBlocked(msg::buildHideOverlay(c.featureId));
    
    node->sendBlocked(msg::Request | msg::DAG | msg::View | msg::Update);
    
    break;
  }
  
  if (!created)
    shouldUpdate = false;
  else
    node->send(msg::Message(msg::Request | msg::Selection | msg::Clear));
}

