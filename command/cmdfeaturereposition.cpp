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

#include "globalutilities.h"
#include "project/prjproject.h"
#include "application/appmainwindow.h"
#include "selection/slceventhandler.h"
#include "viewer/vwrwidget.h"
#include "library/lbrcsysdragger.h"
#include "annex/anncsysdragger.h"
#include "parameter/prmparameter.h"
#include "feature/ftrbase.h"
#include "command/cmdfeaturereposition.h"

using namespace cmd;

FeatureReposition::FeatureReposition() : Base() {}

FeatureReposition::~FeatureReposition(){}

std::string FeatureReposition::getStatusMessage()
{
  return QObject::tr("Select feature to reposition").toStdString();
}

void FeatureReposition::activate()
{
  isActive = true;
  
  go();
  
  sendDone();
}

void FeatureReposition::deactivate()
{
  isActive = false;
}

void FeatureReposition::go()
{
  bool moved = false;
  //only works with preselection for now.
  const osg::Matrixd& cs = mainWindow->getViewer()->getCurrentSystem();
  const slc::Containers &containers = eventHandler->getSelections();
  for (const auto &container : containers)
  {
    if (container.selectionType != slc::Type::Object)
      continue;
    ftr::Base *baseFeature = project->findFeature(container.featureId);
    assert(baseFeature);
    if (!baseFeature->hasAnnex(ann::Type::CSysDragger))
      continue;
    ann::CSysDragger &da = baseFeature->getAnnex<ann::CSysDragger>(ann::Type::CSysDragger);
    
    osg::Matrixd dm = osg::Matrixd::inverse(da.dragger->getMatrix()); //dragger matrix
    osg::Matrixd ns = da.parameter->getMatrix() * dm * cs;
    da.setCSys(ns);
    moved = true;
  }
  
  if (!moved)
    shouldUpdate = false;
}
