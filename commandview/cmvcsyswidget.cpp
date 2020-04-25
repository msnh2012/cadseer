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

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QLabel>
#include <QRadioButton>

#include "application/appapplication.h"
#include "tools/idtools.h"
#include "parameter/prmparameter.h"
#include "message/msgmessage.h"
#include "selection/slcmessage.h"
#include "dialogs/dlgselectionbutton.h"
#include "dialogs/dlgselectionwidget.h"
#include "dialogs/dlgexpressionedit.h"
#include "dialogs/dlgvizfilter.h"
#include "commandview/cmvcsyswidget.h"

struct cmv::CSysWidget::Stow
{
  QWidget *parent = nullptr;
  prm::Parameter *parameter = nullptr;
  QRadioButton *byConstant = nullptr;
  QRadioButton *byFeature = nullptr;
  dlg::ExpressionEdit *expressionWidget = nullptr;
  dlg::SelectionWidget *selectionWidget = nullptr;
  QStackedLayout *stackLayout = nullptr;
  
  Stow() = delete;
  Stow(QWidget *parentIn, prm::Parameter* parameterIn)
  : parent(parentIn)
  , parameter(parameterIn)
  {
    buildGui();
  }
  
  void buildGui()
  {
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    parent->setLayout(mainLayout);
    parent->setContentsMargins(0, 0, 0, 0);
    
    //the label and radio buttons
    byConstant = new QRadioButton(tr("Parameter"), parent);
    byFeature = new QRadioButton(tr("Feature"), parent);
    QHBoxLayout *csysLayout = new QHBoxLayout();
    csysLayout->addWidget(byConstant);
    csysLayout->addWidget(byFeature);
    csysLayout->addStretch();
    mainLayout->addLayout(csysLayout);
    
    //stacked widgets
    expressionWidget = new dlg::ExpressionEdit(parent);
    expressionWidget->setDisabled(true); //we can't parse coordinate systems yet
    dlg::SelectionWidgetCue cue;
    cue.name.clear();
    cue.singleSelection = true;
    cue.showAccrueColumn = false;
    cue.mask = slc::ObjectsEnabled | slc::ObjectsSelectable;
    cue.statusPrompt = tr("Select Feature To Link Coordinate System");
    QWidget *dummy = new QWidget(parent); //to keep parameter widget pushed 'up'
    dummy->setContentsMargins(0, 0, 0, 0);
    QVBoxLayout *dummyLayout = new QVBoxLayout();
    dummyLayout->setContentsMargins(0, 0, 0, 0);
    dummyLayout->addWidget(expressionWidget);
    dummyLayout->addStretch();
    dummy->setLayout(dummyLayout);
    
    selectionWidget = new dlg::SelectionWidget(parent, std::vector<dlg::SelectionWidgetCue>(1, cue));
    stackLayout = new QStackedLayout();
    stackLayout->addWidget(dummy);
    stackLayout->addWidget(selectionWidget);
    mainLayout->addLayout(stackLayout);
    mainLayout->addStretch();
    
    selectionWidget->getButton(0)->setChecked(true);
  }
};

using namespace cmv;

CSysWidget::CSysWidget(QWidget *parentIn, prm::Parameter *parameterIn)
: QWidget(parentIn)
, stow(std::make_unique<Stow>(this, parameterIn))
{
  dlg::VizFilter *vFilter = new dlg::VizFilter(this);
  this->installEventFilter(vFilter);
  connect(vFilter, &dlg::VizFilter::shown, this, &CSysWidget::statusChanged);
  connect(vFilter, &dlg::VizFilter::enabled, this, &CSysWidget::statusChanged);
  connect(stow->byConstant, &QRadioButton::toggled, this, &CSysWidget::radioSlot);
  connect(stow->byFeature, &QRadioButton::toggled, this, &CSysWidget::radioSlot);
  connect(stow->selectionWidget->getButton(0), &dlg::SelectionButton::dirty, this, &CSysWidget::dirty);
}

CSysWidget::~CSysWidget() = default;

void CSysWidget::setCSysLinkId(const boost::uuids::uuid &idIn)
{
  QSignalBlocker cBlocker(stow->byConstant);
  QSignalBlocker fBlocker(stow->byFeature);
  
  if (idIn.is_nil())
  {
    stow->byConstant->setChecked(true);
    stow->stackLayout->setCurrentIndex(0);
    return;
  }
  //else
  slc::Message s;
  s.type = slc::Type::Feature;
  s.accrue = slc::Accrue::None;
  s.featureType = ftr::Type::Base; //we don't care what type of feature it is.
  s.featureId = idIn;
  s.shapeId = gu::createNilId();
  //don't care about point location
  //don't care about selection mask
  stow->selectionWidget->initializeButton(0, s); //don't send 'dirty'
  stow->byFeature->setChecked(true);
  stow->stackLayout->setCurrentIndex(1);
}

boost::uuids::uuid CSysWidget::getCSysLinkId() const
{
  const slc::Messages &msgs = stow->selectionWidget->getButton(0)->getMessages();
  if (!stow->byFeature->isChecked() || msgs.empty())
    return gu::createNilId();
  return msgs.front().featureId;
}

void CSysWidget::radioSlot()
{
  //gets called when states of both buttons change.
  //so we need both tests and can't use 'else'
  if (stow->byConstant->isChecked())
  {
    stow->stackLayout->setCurrentIndex(0);
    statusChanged();
    dirty();
  }
  if (stow->byFeature->isChecked())
  {
    stow->stackLayout->setCurrentIndex(1);
    dirty();
  }
}

void CSysWidget::statusChanged()
{
  if (isVisible() && isEnabled() && stow->byConstant->isChecked())
  {
    app::instance()->messageSlot(msg::buildSelectionMask(slc::None));
    app::instance()->messageSlot(msg::buildStatusMessage(tr("Enter Coordinate System Values").toStdString()));
  }
  //button on feature link should take care of itself
}