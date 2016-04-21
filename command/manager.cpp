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

#include <functional>

#include <osg/Geometry> //need this for containers.

#include <command/featuretosystem.h>
#include <command/systemtofeature.h>
#include <command/featuretodragger.h>
#include <command/draggertofeature.h>
#include <message/dispatch.h>
#include <message/observer.h>
#include <preferences/preferencesXML.h>
#include <preferences/manager.h>
#include <viewer/message.h>
#include <command/manager.h>

using namespace cmd;

Manager& cmd::manager()
{
  static Manager localManager;
  return localManager;
}

Manager::Manager()
{
  observer = std::move(std::unique_ptr<msg::Observer>(new msg::Observer()));
  observer->name = "cmd::Manager";
  setupDispatcher();
}

void Manager::setupDispatcher()
{
  msg::Mask mask;
  
  mask = msg::Request | msg::Command | msg::Cancel;
  observer->dispatcher.insert(std::make_pair(mask, boost::bind(&Manager::cancelCommandDispatched, this, _1)));
  
  mask = msg::Request | msg::Command | msg::Done;
  observer->dispatcher.insert(std::make_pair(mask, boost::bind(&Manager::doneCommandDispatched, this, _1)));
  
  mask = msg::Request | msg::FeatureToSystem;
  observer->dispatcher.insert(std::make_pair(mask, boost::bind(&Manager::featureToSystemDispatched, this, _1)));
  
  mask = msg::Request | msg::SystemToFeature;
  observer->dispatcher.insert(std::make_pair(mask, boost::bind(&Manager::systemToFeatureDispatched, this, _1)));
  
  mask = msg::Request | msg::FeatureToDragger;
  observer->dispatcher.insert(std::make_pair(mask, boost::bind(&Manager::featureToDraggerDispatched, this, _1)));
  
  mask = msg::Request | msg::DraggerToFeature;
  observer->dispatcher.insert(std::make_pair(mask, boost::bind(&Manager::draggerToFeatureDispatched, this, _1)));
}

void Manager::cancelCommandDispatched(const msg::Message &)
{
  //we might not want the update triggered inside done slot
  //from this handler? but leave for now.
  doneSlot();
}

void Manager::doneCommandDispatched(const msg::Message&)
{
  //same as above for now, but might be different in the future.
  doneSlot();
}

void Manager::addCommand(BasePtr pointerIn)
{
  //preselection will only work if the command stack is empty.
  if (!stack.empty())
  {
    stack.top()->deactivate();
    clearSelection();
  }
  stack.push(pointerIn);
  activateTop();
}

void Manager::doneSlot()
{
  //only active command should trigger it is done.
  if (!stack.empty())
  {
    stack.top()->deactivate();
    stack.pop();
  }
  clearSelection();
  sendStatusMessage("");
  
  if (prf::manager().rootPtr->dragger().triggerUpdateOnFinish())
  {
    msg::Message uMessage;
    uMessage.mask = msg::Request | msg::Update;
    observer->messageOutSignal(uMessage);
  }
  
  if (!stack.empty())
    activateTop();
  else
    sendCommandMessage("Active command count: 0");
}

void Manager::activateTop()
{
  sendStatusMessage(stack.top()->getStatusMessage());
  
  std::ostringstream stream;
  stream << 
    "Active command count: " << stack.size() << std::endl <<
    "Command: " << stack.top()->getCommandName();
  sendCommandMessage(stream.str());
  
  stack.top()->activate();
}

void Manager::sendStatusMessage(const std::string& messageIn)
{
  msg::Message statusMessage;
  statusMessage.mask = msg::Request | msg::StatusText;
  vwr::Message statusVMessage;
  statusVMessage.text = messageIn;
  statusMessage.payload = statusVMessage;
  observer->messageOutSignal(statusMessage);
}

void Manager::sendCommandMessage(const std::string& messageIn)
{
  msg::Message statusMessage;
  statusMessage.mask = msg::Request | msg::CommandText;
  vwr::Message statusVMessage;
  statusVMessage.text = messageIn;
  statusMessage.payload = statusVMessage;
  observer->messageOutSignal(statusMessage);
}

void Manager::clearSelection()
{
  msg::Message clearMessage;
  clearMessage.mask = msg::Request | msg::Selection | msg::Clear;
  observer->messageOutSignal(clearMessage);
}

void Manager::featureToSystemDispatched(const msg::Message&)
{
  std::shared_ptr<cmd::FeatureToSystem> featureToSystem(new cmd::FeatureToSystem());
  cmd::manager().addCommand(featureToSystem);
}

void Manager::systemToFeatureDispatched(const msg::Message&)
{
  std::shared_ptr<cmd::SystemToFeature> systemToFeature(new cmd::SystemToFeature());
  cmd::manager().addCommand(systemToFeature);
}

void Manager::draggerToFeatureDispatched(const msg::Message&)
{
  std::shared_ptr<cmd::DraggerToFeature> draggerToFeature(new cmd::DraggerToFeature());
  cmd::manager().addCommand(draggerToFeature);
}

void Manager::featureToDraggerDispatched(const msg::Message&)
{
  std::shared_ptr<cmd::FeatureToDragger> featureToDragger(new cmd::FeatureToDragger());
  cmd::manager().addCommand(featureToDragger);
}
