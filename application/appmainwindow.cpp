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
#include <QCloseEvent>

#include "dagview/dagmodel.h"
#include "dagview/dagview.h"
#include "expressions/exprwidget.h"
#include "application/appapplication.h"
#include "dialogs/dlgsplitterdecorated.h"
#include "viewer/vwrwidget.h"
#include "selection/slcmanager.h"
#include "message/msgnode.h"
#include "message/msgsift.h"
#include "dialogs/dlgexpressionedit.h"
#include "application/appincrementwidget.h"
#include "preferences/preferencesXML.h"
#include "preferences/prfmanager.h"
#include "application/appinfowindow.h"
#include "ui_appmainwindow.h"
#include "application/appmainwindow.h"

using boost::uuids::uuid;
using namespace app;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    dagModel = new dag::Model(this);
    dagView = new dag::View(this);
    dagView->setScene(dagModel);
    expressionWidget = new expr::Widget(this);
    dlg::SplitterDecorated *subSplitter = new dlg::SplitterDecorated(this);
    subSplitter->setOrientation(Qt::Vertical);
    subSplitter->addWidget(expressionWidget);
    subSplitter->addWidget(dagView);
    subSplitter->restoreSettings("mainWindowSubSplitter");
    
    viewWidget = new vwr::Widget(osgViewer::ViewerBase::SingleThreaded);
    viewWidget->setGeometry( 100, 100, 800, 600 );
    viewWidget->setMinimumSize(QSize(100, 100)); //don't collapse view widget. osg nan erros.
    
    dlg::SplitterDecorated *splitter = new dlg::SplitterDecorated(this);
    splitter->setOpaqueResize(Qt::Horizontal);
    splitter->addWidget(viewWidget);
    splitter->addWidget(subSplitter);
    //size setup temp.
    QList<int> sizes;
    sizes.append(1000);
    sizes.append(300);
    splitter->setSizes(sizes);
    splitter->setCollapsible(0, false); //don't collapse view widget. osg nan erros.
    splitter->restoreSettings("mainWindowSplitter");
    
    QHBoxLayout *aLayout = new QHBoxLayout();
    aLayout->addWidget(splitter);
    ui->centralwidget->setLayout(aLayout);

    selectionManager = new slc::Manager(this);
    setupSelectionToolbar();
    
    //add increment widgets to toolbar.
    ui->toolBar->setContentsMargins(0, 0, 0, 0);
    ui->toolBar->addSeparator();
    incrementWidget = new IncrementWidgetAction
      (this, tr("Translation Increment:"), tr("Rotation Increment:"));
    ui->toolBar->addAction(incrementWidget);
    
    //build the info window.
    infoDialog = new InfoDialog(this);
    infoDialog->restoreSettings();
    infoDialog->hide();

    node = std::make_unique<msg::Node>();
    node->connect(msg::hub());
    sift = std::make_unique<msg::Sift>();
    sift->name = "app::MainWindow";
    node->setHandler(std::bind(&msg::Sift::receive, sift.get(), std::placeholders::_1));
    
    setupDispatcher();
    
    node->send(msg::buildSelectionMask(slc::AllEnabled));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent (QCloseEvent *event)
{
  node->send(msg::Message(msg::Request | msg::Command | msg::Clear));
  QMainWindow::closeEvent(event);
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

void MainWindow::setupDispatcher()
{
  sift->insert
  (
    {
      std::make_pair
      (
        msg::Request | msg::Info | msg::Text
        , std::bind(&MainWindow::infoTextDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Response | msg::Preferences
        , std::bind(&MainWindow::preferencesChanged, this, std::placeholders::_1)
      )
    }
  );
}

void MainWindow::preferencesChanged(const msg::Message&)
{
  incrementWidget->lineEdit1->lineEdit->setText(QString::number(prf::manager().rootPtr->dragger().linearIncrement(), 'f', 12));
  incrementWidget->lineEdit2->lineEdit->setText(QString::number(prf::manager().rootPtr->dragger().angularIncrement(), 'f', 12));
  incrementWidget->lineEdit1->lineEdit->setCursorPosition(0);
  incrementWidget->lineEdit2->lineEdit->setCursorPosition(0);
}

void MainWindow::infoTextDispatched(const msg::Message&)
{
    infoDialog->show();
    infoDialog->raise();
    infoDialog->activateWindow();
}