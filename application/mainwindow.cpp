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

#include <iostream>
#include <assert.h>
#include <limits>


#include <QHBoxLayout>
#include <QSplitter>
#include <QDir>

#include <message/dispatch.h>
#include <dagview/dagmodel.h>
#include <dagview/dagview.h>
#include <application/application.h>
#include <viewer/viewerwidget.h>
#include <selection/manager.h>
#include <message/dispatch.h>
#include <application/incrementwidget.h>
#include <preferences/preferencesXML.h>
#include <preferences/manager.h>
#include <ui_mainwindow.h>
#include <application/mainwindow.h>

using boost::uuids::uuid;
using namespace app;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    viewWidget = new ViewerWidget(osgViewer::ViewerBase::SingleThreaded);
    viewWidget->setGeometry( 100, 100, 800, 600 );
    
    dagModel = new dag::Model(this);
    dagView = new dag::View(this);
    dagView->setScene(dagModel);
    
    QSplitter *splitter = new QSplitter(Qt::Horizontal, this);
    splitter->addWidget(viewWidget);
    splitter->addWidget(dagView);
    //size setup temp.
    QList<int> sizes;
    sizes.append(1000);
    sizes.append(300);
    splitter->setSizes(sizes);
    
    QHBoxLayout *aLayout = new QHBoxLayout();
    aLayout->addWidget(splitter);
    ui->centralwidget->setLayout(aLayout);

    selectionManager = new slc::Manager(this);
    setupSelectionToolbar();
    connect(selectionManager, SIGNAL(setSelectionMask(int)), viewWidget, SLOT(setSelectionMask(int)));
    selectionManager->setState
    (
      slc::All &
      ~slc::ObjectsSelectable &
      ~slc::FeaturesSelectable &
      ~slc::SolidsSelectable &
      ~slc::ShellsSelectable &
      ~slc::FacesSelectable &
      ~slc::WiresSelectable &
      ~slc::EdgesSelectable &
      ~slc::MidPointsSelectable &
      ~slc::CenterPointsSelectable &
      ~slc::QuadrantPointsSelectable &
      ~slc::NearestPointsSelectable &
      ~slc::ScreenPointsSelectable
    );
    
    //add increment widgets to toolbar.
    ui->toolBar->setContentsMargins(0, 0, 0, 0);
    ui->toolBar->addSeparator();
    incrementWidget = new IncrementWidgetAction
      (this, tr("Translation Increment:"), tr("Rotation Increment:"));
    ui->toolBar->addAction(incrementWidget);
    incrementWidget->lineEdit1->setText(QString::number(prf::manager().rootPtr->dragger().linearIncrement(), 'f', 12));
    incrementWidget->lineEdit2->setText(QString::number(prf::manager().rootPtr->dragger().angularIncrement(), 'f', 12));
    incrementWidget->lineEdit1->setCursorPosition(0);
    incrementWidget->lineEdit2->setCursorPosition(0);
    connect(incrementWidget->lineEdit1, SIGNAL(editingFinished()), this, SLOT(incrementChangedSlot()));
    connect(incrementWidget->lineEdit2, SIGNAL(editingFinished()), this, SLOT(incrementChangedSlot()));

    //new message system.
    dagModel->connectMessageOut(boost::bind(&msg::Dispatch::messageInSlot, &msg::dispatch(), _1));
    msg::dispatch().connectMessageOut(boost::bind(&dag::Model::messageInSlot, dagModel, _1));
    viewWidget->getSelectionEventHandler()->connectMessageOut
      (boost::bind(&msg::Dispatch::messageInSlot, &msg::dispatch(), _1));
    msg::dispatch().connectMessageOut(boost::bind(&slc::EventHandler::messageInSlot,
						  viewWidget->getSelectionEventHandler(), _1));
    viewWidget->connectMessageOut(boost::bind(&msg::Dispatch::messageInSlot, &msg::dispatch(), _1));
    msg::dispatch().connectMessageOut(boost::bind(&ViewerWidget::messageInSlot, viewWidget, _1));
    
    setupDispatcher();
    this->connectMessageOut(boost::bind(&msg::Dispatch::messageInSlot, &msg::dispatch(), _1));
    msg::dispatch().connectMessageOut(boost::bind(&MainWindow::messageInSlot, this, _1));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupSelectionToolbar()
{
    selectionManager->actionSelectObjects = ui->actionSelectObjects;
    selectionManager->actionSelectFeatures = ui->actionSelectFeatures;
    selectionManager->actionSelectSolids = ui->actionSelectSolids;
    selectionManager->actionSelectShells = ui->actionSelectShells;
    selectionManager->actionSelectFaces = ui->actionSelectFaces;
    selectionManager->actionSelectWires = ui->actionSelectWires;
    selectionManager->actionSelectEdges = ui->actionSelectEdges;
    selectionManager->actionSelectVertices = ui->actionSelectVertices;
    selectionManager->actionSelectEndPoints = ui->actionSelectEndPoints;
    selectionManager->actionSelectMidPoints = ui->actionSelectMidPoints;
    selectionManager->actionSelectCenterPoints = ui->actionSelectCenterPoints;
    selectionManager->actionSelectQuadrantPoints = ui->actionSelectQuandrantPoints;
    selectionManager->actionSelectNearestPoints = ui->actionSelectNearestPoints;
    selectionManager->actionSelectScreenPoints = ui->actionSelectScreenPoints;

    connect(ui->actionSelectObjects, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredObjects(bool)));
    connect(ui->actionSelectFeatures, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredFeatures(bool)));
    connect(ui->actionSelectSolids, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredSolids(bool)));
    connect(ui->actionSelectShells, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredShells(bool)));
    connect(ui->actionSelectFaces, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredFaces(bool)));
    connect(ui->actionSelectWires, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredWires(bool)));
    connect(ui->actionSelectEdges, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredEdges(bool)));
    connect(ui->actionSelectVertices, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredVertices(bool)));
    connect(ui->actionSelectEndPoints, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredEndPoints(bool)));
    connect(ui->actionSelectMidPoints, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredMidPoints(bool)));
    connect(ui->actionSelectCenterPoints, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredCenterPoints(bool)));
    connect(ui->actionSelectQuandrantPoints, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredQuadrantPoints(bool)));
    connect(ui->actionSelectNearestPoints, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredNearestPoints(bool)));
    connect(ui->actionSelectScreenPoints, SIGNAL(triggered(bool)), selectionManager, SLOT(triggeredScreenPoints(bool)));
}

void MainWindow::incrementChangedSlot()
{
  double temp;
  
  temp = incrementWidget->lineEdit1->text().toDouble();
  if (temp != 0.0)
    prf::manager().rootPtr->dragger().linearIncrement() = temp;
  else
    incrementWidget->lineEdit1->setText(QString::number(prf::manager().rootPtr->dragger().linearIncrement(), 'f', 12));
  
  temp = incrementWidget->lineEdit2->text().toDouble();
  if (temp != 0.0)
    prf::manager().rootPtr->dragger().angularIncrement() = temp;
  else
    incrementWidget->lineEdit2->setText(QString::number(prf::manager().rootPtr->dragger().angularIncrement(), 'f', 12));
  
  incrementWidget->lineEdit1->setCursorPosition(0);
  incrementWidget->lineEdit2->setCursorPosition(0);
  
  prf::manager().saveConfig();
}

void MainWindow::setupDispatcher()
{
  msg::Mask mask;
  
  mask = msg::Response | msg::Preferences;
  dispatcher.insert(std::make_pair(mask, boost::bind(&MainWindow::preferencesChanged, this, _1)));
}

void MainWindow::messageInSlot(const msg::Message &messageIn)
{
  msg::MessageDispatcher::iterator it = dispatcher.find(messageIn.mask);
  if (it == dispatcher.end())
    return;
  
  it->second(messageIn);
}

void MainWindow::preferencesChanged(const msg::Message&)
{
  incrementWidget->lineEdit1->setText(QString::number(prf::manager().rootPtr->dragger().linearIncrement(), 'f', 12));
  incrementWidget->lineEdit2->setText(QString::number(prf::manager().rootPtr->dragger().angularIncrement(), 'f', 12));
  incrementWidget->lineEdit1->setCursorPosition(0);
  incrementWidget->lineEdit2->setCursorPosition(0);
}