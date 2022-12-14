/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2019 Thomas S. Anderson blobfish.at.gmx.com
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

#include "tools/featuretools.h"
#include "project/prjproject.h"
#include "message/msgnode.h"
#include "selection/slceventhandler.h"
#include "annex/annseershape.h"
#include "parameter/prmconstants.h"
#include "parameter/prmparameter.h"
#include "feature/ftrinputtype.h"
#include "feature/ftrruled.h"
#include "commandview/cmvmessage.h"
#include "commandview/cmvruled.h"
#include "command/cmdruled.h"

using namespace cmd;

Ruled::Ruled()
: Base("cmd::Ruled")
, leafManager()
{
  feature = new ftr::Ruled::Feature();
  project->addFeature(std::unique_ptr<ftr::Ruled::Feature>(feature));
  node->sendBlocked(msg::Request | msg::DAG | msg::View | msg::Update);
  isEdit = false;
  isFirstRun = true;
}

Ruled::Ruled(ftr::Base *fIn)
: Base("cmd::Ruled")
, leafManager(fIn)
{
  feature = dynamic_cast<ftr::Ruled::Feature*>(fIn);
  assert(feature);
  viewBase = std::make_unique<cmv::Ruled>(this);
  node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
  isEdit = true;
  isFirstRun = false; //bypass go() in activate.
}

Ruled::~Ruled() = default;

std::string Ruled::getStatusMessage()
{
  return QObject::tr("Select geometry for Ruled feature").toStdString();
}

void Ruled::activate()
{
  isActive = true;
  leafManager.rewind();
  if (isFirstRun.get())
  {
    isFirstRun = false;
    go();
  }
  if (viewBase)
  {
    feature->setEditing();
    cmv::Message vm(viewBase.get(), viewBase->getPaneWidth());
    msg::Message out(msg::Mask(msg::Request | msg::Command | msg::View | msg::Show), vm);
    node->sendBlocked(out);
  }
  else
    sendDone();
}

void Ruled::deactivate()
{
  if (viewBase)
  {
    feature->setNotEditing();
    msg::Message out(msg::Mask(msg::Request | msg::Command | msg::View | msg::Hide));
    node->sendBlocked(out);
  }
  leafManager.fastForward();
  if (!isEdit.get())
  {
    node->sendBlocked(msg::buildShowThreeD(feature->getId()));
    node->sendBlocked(msg::buildShowOverlay(feature->getId()));
  }
  isActive = false;
}

bool Ruled::isValidSelection(const slc::Message &mIn)
{
  const ftr::Base *lf = project->findFeature(mIn.featureId);
  if (!lf->hasAnnex(ann::Type::SeerShape) || lf->getAnnex<ann::SeerShape>().isNull())
    return false;
  
  auto t = mIn.type;
  if
  (
    (t != slc::Type::Object)
    && (t != slc::Type::Wire)
    && (t != slc::Type::Edge)
  )
    return false;
  return true;
}

void Ruled::setSelections(const slc::Messages &targets)
{
  assert(isActive);
  
  auto *pickPrm = feature->getParameter(prm::Tags::Picks);
  auto reset = [&]()
  {
    project->clearAllInputs(feature->getId());
    pickPrm->setValue(ftr::Picks());
  };
  reset();
  
  if (targets.empty())
    return;
  
  ftr::Picks freshPicks;
  for (const auto &m : targets)
  {
    if (!isValidSelection(m))
      continue;

    const ftr::Base *lf = project->findFeature(m.featureId);
    freshPicks.push_back(tls::convertToPick(m, *lf, project->getShapeHistory()));
    freshPicks.back().tag = indexTag(ftr::Ruled::InputTags::pick, freshPicks.size() - 1);
    project->connect(lf->getId(), feature->getId(), {freshPicks.back().tag});
  }
  pickPrm->setValue(freshPicks);
  
  if (freshPicks.size() != 2)
    reset();
}

void Ruled::localUpdate()
{
  assert(isActive);
  feature->updateModel(project->getPayload(feature->getId()));
  feature->updateVisual();
  feature->setModelDirty();
  node->sendBlocked(msg::Request | msg::DAG | msg::View | msg::Update);
}

void Ruled::go()
{
  const slc::Containers &cs = eventHandler->getSelections();
  
  std::vector<slc::Message> tm; //target messages
  for (const auto &c : cs)
  {
    auto m = slc::EventHandler::containerToMessage(c);
    if (isValidSelection(m))
      tm.push_back(m);
  }
  
  if (tm.size() == 2)
  {
    setSelections(tm);
    node->sendBlocked(msg::buildStatusMessage("Ruled Added", 2.0));
    node->sendBlocked(msg::Message(msg::Request | msg::Selection | msg::Clear));
    return;
  }
  
  node->send(msg::Message(msg::Request | msg::Selection | msg::Clear));
  node->sendBlocked(msg::buildShowThreeD(feature->getId()));
  node->sendBlocked(msg::buildShowOverlay(feature->getId()));
  viewBase = std::make_unique<cmv::Ruled>(this);
}
