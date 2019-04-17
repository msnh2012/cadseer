/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2016  Thomas S. Anderson blobfish.at.gmx.com
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

#include <boost/current_function.hpp>

#include <QTabWidget>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include <QHeaderView>
#include <QToolBar>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextEdit>
#include <QTextStream>

#include "tools/idtools.h"
#include "application/appapplication.h"
#include "dialogs/dlgsplitterdecorated.h"
#include "message/msgnode.h"
#include "message/msgsift.h"
#include "expressions/exprtablemodel.h"
#include "expressions/exprtableview.h"
#include "expressions/exprmanager.h"
#include "expressions/exprwidget.h"
#include "project/prjproject.h"

using namespace expr;

Widget::Widget(QWidget* parent, Qt::WindowFlags f):
  QWidget(parent, f)
{
  node = std::make_unique<msg::Node>();
  node->connect(msg::hub());
  sift = std::make_unique<msg::Sift>();
  sift->name = "expr::Widget";
  node->setHandler(std::bind(&msg::Sift::receive, sift.get(), std::placeholders::_1));
  setupDispatcher();
    
  setupGui();
}

Widget::~Widget()
{

}

void Widget::setupGui()
{
  QVBoxLayout *mainLayout = new QVBoxLayout();
  this->setLayout(mainLayout);
  
  toolbar = new QToolBar(this);
  toolbar->addAction(QIcon(":/resources/images/debugExpressionGraph.svg"), tr("Write Graph"), this, SLOT(writeOutGraphSlot()));
  toolbar->addAction(QIcon(":/resources/images/viewExpressionExamples.svg"), tr("Toggle View Examples"), this, SLOT(goExamplesTabSlot()));
  toolbar->addAction(QIcon(":/resources/images/loadExpressionExamples.svg"), tr("Load Examples"), this, SLOT(fillInTestManagerSlot()));
  toolbar->addAction(tr("Dump Links"), this, SLOT(dumpLinksSlot()));
  
  tabWidget = new QTabWidget(this);
  
  dlg::SplitterDecorated *splitter = new dlg::SplitterDecorated(this);
  splitter->setOrientation(Qt::Vertical);
  splitter->addWidget(toolbar);
  splitter->addWidget(tabWidget);
  splitter->restoreSettings("ExpressionsSplitter");
  mainLayout->addWidget(splitter);
}

void Widget::writeOutGraphSlot()
{
  boost::filesystem::path p = app::instance()->getApplicationDirectory() / "expressionGraph.dot";
  eManager->writeOutGraph(p.string());
}

void Widget::groupRenamedSlot(QWidget *tab, const QString &newName)
{
  int index = tabWidget->indexOf(tab);
  assert(index >= 0); //no such widget
  tabWidget->setTabText(index, newName);
}

void Widget::addGroupSlot()
{
  bool ok;
  QString newName = QInputDialog::getText(this, tr("Enter Group Name"), tr("Name:"), QLineEdit::Normal, "Group Name", &ok);
  if (!ok || newName.isEmpty())
    return;
  if (eManager->hasUserGroup(newName.toStdString()))
  {
    QMessageBox::critical(this, tr("Error:"), tr("Name Already Exists"));
    return;
  }
  boost::uuids::uuid groupId;
  groupId = eManager->createUserGroup(newName.toStdString());
  
  addGroupView(groupId, newName);
}

void Widget::removeGroupSlot(QWidget *tab)
{
  int tabIndex = tabWidget->indexOf(tab);
  assert(tabIndex >= 0); //no such widget
  tabWidget->removeTab(tabIndex);
  tab->deleteLater();
}

void Widget::addGroupView(const boost::uuids::uuid& idIn, const QString &name)
{
  TableViewGroup *userView = new TableViewGroup(tableViewAll);
  userView->setDragEnabled(true);
  GroupProxyModel *userProxyModel = new GroupProxyModel(*eManager, idIn, userView);
  userProxyModel->setSourceModel(mainTable);
  userView->setModel(userProxyModel);
  NameDelegate *nameDelegate = new NameDelegate(userView);
  userView->setItemDelegateForColumn(0, nameDelegate);
  ExpressionDelegate *userDelegate = new ExpressionDelegate(userView);
  userView->setItemDelegateForColumn(1, userDelegate);
  tabWidget->addTab(userView, name);
  userView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
  connect(userView, SIGNAL(groupRenamedSignal(QWidget*,QString)), this, SLOT(groupRenamedSlot(QWidget*,QString)));
  connect(userView, SIGNAL(groupRemovedSignal(QWidget*)), this, SLOT(removeGroupSlot(QWidget*)));
}

void Widget::fillInTestManagerSlot()
{
  std::string examplesString = buildExamplesString();
  std::istringstream inStream(examplesString.c_str());
  mainTable->importExpressions(inStream, gu::createNilId());
  
  eManager->update();
  
  std::vector<boost::uuids::uuid> ids = eManager->getAllFormulaIds();
  boost::uuids::uuid groupId;
  if (!eManager->hasUserGroup("Group 1") && ids.size() > 2)
  {
    groupId= eManager->createUserGroup("Group 1");
    eManager->addFormulaToUserGroup(groupId, *(ids.begin()));
    eManager->addFormulaToUserGroup(groupId, *(ids.begin() + 1));
    eManager->addFormulaToUserGroup(groupId, *(ids.begin() + 2));
    addGroupView(groupId, "Group 1");
  }
  
  if (!eManager->hasUserGroup("Group 2") && ids.size() > 5)
  {
    groupId = eManager->createUserGroup("Group 2");
    eManager->addFormulaToUserGroup(groupId, *(ids.begin() + 3));
    eManager->addFormulaToUserGroup(groupId, *(ids.begin() + 4));
    eManager->addFormulaToUserGroup(groupId, *(ids.begin() + 5));
    addGroupView(groupId, "Group 2");
  }
}

void Widget::dumpLinksSlot()
{
  std::cout << std::endl << "expression links: " << std::endl;
  eManager->dumpLinks(std::cout);
  std::cout << std::endl;
}

void Widget::goExamplesTabSlot()
{
  static bool added = false;
  static QTextEdit *examplesTab = nullptr;
  if (!examplesTab)
  {
    examplesTab = new QTextEdit(this);
    examplesTab->setReadOnly(true);
    examplesTab->setLineWrapMode(QTextEdit::NoWrap);
    examplesTab->setText(QString::fromStdString(buildExamplesString()));
    examplesTab->setObjectName("examples");
  }
  
  if (!added)
  {
    tabWidget->insertTab(2, examplesTab, tr("Examples"));
    tabWidget->setCurrentIndex(2);
    added = true;
  }
  else
  {
    int index = tabWidget->indexOf(examplesTab);
    assert(!(index < 0));
    tabWidget->removeTab(index);
    added = false;
  }
}

std::string Widget::buildExamplesString()
{
  std::ostringstream stream;
  stream << 
  "exampleJunk1 = 1" << std::endl <<
  "exampleJunk2 = 2" << std::endl <<
  "exampleJunk3 = 3" << std::endl <<
  "exampleJunk4 = 4" << std::endl <<
  "exampleJunk5 = 5" << std::endl <<
  "exampleJunk6 = 6" << std::endl <<
  "exampleJunk7 = 7" << std::endl <<
  "exampleJunk8 = 8" << std::endl <<
  "exampleTantest = 10 * (2 + tan(0.52359878)) - 4" << std::endl <<
  "exampleSintest = 8 + 3 - sin(0.75) * 4 / 2.1 + 3" << std::endl <<
  "exampleCostest = cos(0.75) * ((8 / 3.547) + 1)" << std::endl <<
  "exampleAsintest = asin(0.5)" << std::endl <<
  "exampleAcostest = acos(0.5)" << std::endl <<
  "exampleAtantest = atan(1)" << std::endl <<
  "exampleCombotest = exampleSintest + exampleCostest + (exampleTantest - exampleJunk3) - exampleJunk4 * exampleJunk5" << std::endl <<
  "examplePowtest = pow(2, 3)" << std::endl <<
  "exampleAtan2test = atan2(1, 1)" << std::endl <<
  "exampleAbstest = 10 * abs(-1.2)+ 2" << std::endl <<
  "exampleMintest = min(1.4, 4.8)" << std::endl <<
  "exampleMaxtest = max(1.4, 4.8)" << std::endl <<
  "exampleFloortest1 = floor(1.374, 0.125)" << std::endl <<
  "exampleFloortest2 = floor(1.375, 0.125)" << std::endl <<
  "exampleFloortest3 = floor(1.376, 0.125)" << std::endl <<
  "exampleCeiltest1 = ceil(1.374, 0.125)" << std::endl <<
  "exampleCeiltest2 = ceil(1.375, 0.125)" << std::endl <<
  "exampleCeiltest3 = ceil(1.376, 0.125)" << std::endl <<
  "exampleRoundtest1 = round(1.0624, 0.125)" << std::endl <<
  "exampleRoundtest2 = round(1.0625, 0.125)" << std::endl <<
  "exampleRoundtest3 = round(1.0626, 0.125)" << std::endl <<
  "exampleRadtodegtest = radtodeg(3.14159)" << std::endl <<
  "exampleDegtoradtest = degtorad(180)" << std::endl <<
  "exampleLogtest = log(2.0)" << std::endl <<
  "exampleExptest = exp(2.0)" << std::endl <<
  "exampleSqrtest = sqrt(25.0)" << std::endl <<
  "exampleHypottest = hypot(3,4)" << std::endl <<
  "exampleIftest1 = if(3 > 3) then(1.0) else(0.0)" << std::endl <<
  "exampleIftest2 = if(3 < 3) then(1.0) else(0.0)" << std::endl <<
  "exampleIftest3 = if(3 >= 3) then(1.0) else(0.0)" << std::endl <<
  "exampleIftest4 = if(3 <= 3) then(1.0) else(0.0)" << std::endl <<
  "exampleIftest5 = if(3 == 3) then(1.0) else(0.0)" << std::endl <<
  "exampleIftest6 = if(3 != 3) then(1.0) else(0.0)" << std::endl <<
  "exampleIftest7 = if(sin(degtorad(44)) < sin(degtorad(46))) then(exampleJunk1) else(exampleJunk2)" << std::endl;
  
  return stream.str();
}

void Widget::setupDispatcher()
{
  sift->insert
  (
    {
      std::make_pair
      (
        msg::Response | msg::Pre | msg::Close | msg::Project
        , std::bind(&Widget::closeProjectDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Response | msg::Post | msg::Open | msg::Project
        , std::bind(&Widget::openNewProjectDispatched, this, std::placeholders::_1)
      )
      , std::make_pair
      (
        msg::Response | msg::Post | msg::New | msg::Project
        , std::bind(&Widget::openNewProjectDispatched, this, std::placeholders::_1)
      )
    }
  );
}

void Widget::closeProjectDispatched(const msg::Message&)
{
  
  tabWidget->clear();
  tableViewAll->deleteLater(); //should delete all child models and views.
  tableViewAll = nullptr;
  mainTable = nullptr; //was a child of tabwidget, so should be deleted.
  eManager = nullptr; //Manager owned by project. should be deleted there.
}

void Widget::openNewProjectDispatched(const msg::Message&)
{
  assert(!eManager);
  eManager = &(static_cast<app::Application *>(qApp)->getProject()->getManager());
  assert(eManager);
  
  assert(!tableViewAll);
  tableViewAll = new TableViewAll(tabWidget);
  tableViewAll->setDragEnabled(true);
  
  assert(!mainTable);
  mainTable = new TableModel(*eManager, tableViewAll);
  
  
  AllProxyModel *allModel = new AllProxyModel(tableViewAll);
  allModel->setSourceModel(mainTable);
  tableViewAll->setModel(allModel);
  NameDelegate *nameDelegate1 = new NameDelegate(tableViewAll);
  tableViewAll->setItemDelegateForColumn(0, nameDelegate1);
  ExpressionDelegate *expressionDelegate1 = new ExpressionDelegate(tableViewAll);
  tableViewAll->setItemDelegateForColumn(1, expressionDelegate1);
  tabWidget->addTab(tableViewAll, tr("All"));
  tableViewAll->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); //has to be done after the model is set.
  connect(tableViewAll, SIGNAL(addGroupSignal()), this, SLOT(addGroupSlot()));
  
  TableViewSelection *selectionView = new TableViewSelection(tableViewAll);
  SelectionProxyModel *selectionModel = new SelectionProxyModel(*eManager, selectionView);
  selectionModel->setSourceModel(mainTable);
  selectionView->setModel(selectionModel);
  selectionView->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch); //has to be done after the model is set.
  NameDelegate *nameDelegate2 = new NameDelegate(selectionView);
  tableViewAll->setItemDelegateForColumn(0, nameDelegate2);
  ExpressionDelegate *expressionDelegate2 = new ExpressionDelegate(selectionView);
  tableViewAll->setItemDelegateForColumn(1, expressionDelegate2);
  tabWidget->addTab(selectionView, tr("Selection"));
  
  for(std::vector<Group>::iterator it = eManager->userDefinedGroups.begin(); it != eManager->userDefinedGroups.end(); ++it)
    addGroupView(it->id, QString::fromStdString(it->name));
}
