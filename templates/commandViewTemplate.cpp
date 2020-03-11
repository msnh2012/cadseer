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
// #include "commandview/cmvparameterwidget.h"
// #include "parameter/prmparameter.h"
// #include "expressions/exprmanager.h"
// #include "expressions/exprstringtranslator.h"
// #include "expressions/exprvalue.h"
// #include "library/lbrplabel.h"
// #include "tools/featuretools.h"
// #include "tools/idtools.h"
// #include "feature/ftrinputtype.h"
#include "feature/ftr%CLASSNAMELOWERCASE%.h"
#include "command/cmd%CLASSNAMELOWERCASE%.h"
#include "commandview/cmv%CLASSNAMELOWERCASE%.h"

using boost::uuids::uuid;

using namespace cmv;

struct %CLASSNAME%::Stow
{
  cmd::%CLASSNAME% *command;
  cmv::%CLASSNAME% *view;
//   dlg::SelectionWidget *selectionWidget = nullptr;
//   dlg::ParameterWidget *parameterWidget = nullptr;
  
  Stow(cmd::%CLASSNAME% *cIn, cmv::%CLASSNAME% *vIn)
  : command(cIn)
  , view(vIn)
  {
    buildGui();
    
    QSettings &settings = app::instance()->getUserSettings();
    settings.beginGroup("cmv::%CLASSNAME%");
    //load settings
    settings.endGroup();
    
    loadFeatureData();
//     stow->selectionWidget->activate(0);
  }
  
  void buildGui()
  {}
  
  void loadFeatureData()
  {}
};

%CLASSNAME%::%CLASSNAME%(cmd::%CLASSNAME% *cIn)
: Base("cmv::%CLASSNAME%")
, stow(new Stow(cIn, this))
{}

%CLASSNAME%::~%CLASSNAME%() = default;
