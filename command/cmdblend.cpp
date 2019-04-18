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

#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>

#include "application/appapplication.h"
#include "application/appmainwindow.h"
#include "project/prjproject.h"
#include "selection/slceventhandler.h"
#include "annex/annseershape.h"
#include "message/msgnode.h"
#include "parameter/prmparameter.h"
#include "feature/ftrinputtype.h"
#include "feature/ftrblend.h"
#include "dialogs/dlgparameter.h"
#include "dialogs/dlgblend.h"
#include "command/cmdblend.h"

using namespace cmd;

using boost::uuids::uuid;

Blend::Blend() : Base() {}

Blend::~Blend()
{
  if (blendDialog)
    blendDialog->deleteLater();
}

std::string Blend::getStatusMessage()
{
  return QObject::tr("Select edge to blend").toStdString();
}

void Blend::activate()
{
  isActive = true;
  
  /* first time the command is activated we will check for a valid preselection.
   * if there is one then we will just build a simple blend feature and call
   * the parameter dialog. Otherwise we will call the blend dialog.
   */
  if (firstRun)
  {
    firstRun = false;
    go();
  }
  
  if (blendDialog)
  {
    blendDialog->show();
    blendDialog->raise();
    blendDialog->activateWindow();
  }
  else sendDone();
}

void Blend::deactivate()
{
  isActive = false;
  if (blendDialog)
    blendDialog->hide();
}

void Blend::go()
{
  assert(project);
  
  const slc::Containers &containers = eventHandler->getSelections();
  if (!containers.empty())
  {
    //get targetId and filter out edges not belonging to first target.
    uuid targetFeatureId = containers.at(0).featureId;
    const ann::SeerShape &targetSeerShape = project->findFeature(targetFeatureId)->getAnnex<ann::SeerShape>();
    ftr::SimpleBlend simpleBlend;
    //no variable blend for pick first scenario
    for (const auto &currentSelection : containers)
    {
      if
      (
        currentSelection.featureId != targetFeatureId ||
        currentSelection.selectionType != slc::Type::Edge //just edges for now.
      )
        continue;
      
      TopoDS_Edge edge = TopoDS::Edge(targetSeerShape.getOCCTShape(currentSelection.shapeId));  
      ftr::Pick pick;
      pick.id = currentSelection.shapeId;
      pick.setParameter(edge, currentSelection.pointLocation);
      pick.shapeHistory = project->getShapeHistory().createDevolveHistory(pick.id);
      
      //simple radius test  
      simpleBlend.picks.push_back(pick);
      auto simpleRadius = ftr::Blend::buildRadiusParameter();
      simpleBlend.radius = simpleRadius;
    }
    if (!simpleBlend.picks.empty())
    {
      std::shared_ptr<ftr::Blend> blend(new ftr::Blend());
      project->addFeature(blend);
      project->connectInsert(targetFeatureId, blend->getId(), ftr::InputType{ftr::InputType::target});
      if (!simpleBlend.picks.empty())
        blend->addSimpleBlend(simpleBlend);
      
      ftr::Base *targetFeature = project->findFeature(targetFeatureId);
      
      node->sendBlocked(msg::buildHideThreeD(targetFeature->getId()));
      node->sendBlocked(msg::buildHideOverlay(targetFeature->getId()));
      
      blend->setColor(targetFeature->getColor());
                
      dlg::Parameter *dialog = new dlg::Parameter(simpleBlend.radius.get(), blend->getId());
      dialog->show();
      dialog->raise();
      dialog->activateWindow();
      
      node->send(msg::Message(msg::Request | msg::Selection | msg::Clear));
      return; 
    }
  }
  
  //if we make it here. we didn't build a blend feature from pre selection.
  blendDialog = new dlg::Blend(mainWindow);
  shouldUpdate = false; //dialog calls update
}


BlendEdit::BlendEdit(ftr::Base *feature) : Base()
{
  blend = dynamic_cast<ftr::Blend*>(feature);
  assert(blend);
}

BlendEdit::~BlendEdit()
{
  if (blendDialog)
    blendDialog->deleteLater();
}

std::string BlendEdit::getStatusMessage()
{
  return "Editing Blend Feature";
}

void BlendEdit::activate()
{
  if (!blendDialog)
    blendDialog = new dlg::Blend(blend, mainWindow);
  
  isActive = true;
  blendDialog->show();
  blendDialog->raise();
  blendDialog->activateWindow();
  
  shouldUpdate = false;
}

void BlendEdit::deactivate()
{
  blendDialog->hide();
  isActive = false;
}
