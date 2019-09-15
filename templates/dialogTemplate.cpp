/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) %YEAR% Thomas S. Anderson blobfish.at.gmx.com
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

#include <QSettings>
// #include <QDialogButtonBox>
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QLineEdit>

#include "application/appapplication.h"
#include "project/prjproject.h"
// #include "annex/annseershape.h"
// #include "preferences/preferencesXML.h"
// #include "preferences/prfmanager.h"
// #include "message/msgmessage.h"
// #include "message/msgnode.h"
// #include "dialogs/dlgselectionbutton.h"
// #include "dialogs/dlgselectionlist.h"
// #include "dialogs/dlgselectionwidget.h"
// #include "dialogs/dlgparameterwidget.h"
// #include "parameter/prmparameter.h"
// #include "expressions/exprmanager.h"
// #include "expressions/exprstringtranslator.h"
// #include "expressions/exprvalue.h"
// #include "library/lbrplabel.h"
// #include "tools/featuretools.h"
// #include "tools/idtools.h"
// #include "feature/ftrinputtype.h"
#include "feature/ftr%CLASSNAMELOWERCASE%.h"
#include "dialogs/dlg%CLASSNAMELOWERCASE%.h"

using boost::uuids::uuid;

using namespace dlg;

struct %CLASSNAME%::Stow
{
  Stow(ftr::%CLASSNAME% *fIn)
  : feature(fIn)
//   , parameter(std::make_shared<prm::Parameter>(*feature->getParameter()))
  {}
  
  ftr::%CLASSNAME% *feature;
//   SelectionWidget *selectionWidget = nullptr;
//   ParameterWidget *parameterWidget = nullptr;
//   std::shared_ptr<prm::Parameter> parameter;
};

%CLASSNAME%::%CLASSNAME%(ftr::%CLASSNAME% *fIn, QWidget *pIn, bool isEditIn)
: Base(fIn, pIn, isEditIn)
, stow(new Stow(fIn))
{
  init();
}

%CLASSNAME%::~%CLASSNAME%() = default;

void %CLASSNAME%::init()
{
  buildGui();
  
  QSettings &settings = app::instance()->getUserSettings();
  settings.beginGroup("dlg::%CLASSNAME%");

  settings.endGroup();
  
  loadFeatureData();
//   stow->selectionWidget->activate(0);
}

void %CLASSNAME%::buildGui()
{

}

void %CLASSNAME%::loadFeatureData()
{
  if (isEditDialog)
  {

  }
}

void %CLASSNAME%::reject()
{
  isAccepted = false;
  finishDialog();
  QDialog::reject();
}

void %CLASSNAME%::accept()
{
  isAccepted = true;
  finishDialog();
  QDialog::accept();
}

void %CLASSNAME%::finishDialog()
{
  prj::Project *p = app::instance()->getProject();
  
  auto restoreState = [&]()
  {
    if (isEditDialog)
    {
      for (const auto &id : leafChildren)
        p->setCurrentLeaf(id);
    }
  };
  auto bail = [&]()
  {
    if (!isEditDialog)
      p->removeFeature(stow->feature->getId());
    commandDone();
    restoreState();
  };
  
  if(!isAccepted)
  {
    bail();
    return;
  }
  

  
  queueUpdate();
  commandDone();
  restoreState();
}