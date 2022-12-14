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

#ifndef EXPR_WIDGET_H
#define EXPR_WIDGET_H

#include <memory>

#include <QWidget>

namespace boost{namespace uuids{struct uuid;}}
namespace msg{struct Message; struct Node; struct Sift;}
class QTabWidget;
class QToolBar;

namespace expr
{
  class Manager;
  class TableModel;
  class TableViewAll;

/*! @brief Widget for interacting with one Manager
 * 
 * Contains a tab widget containing a widget for each group.
 */
class Widget : public QWidget
{
  Q_OBJECT
public:
    explicit Widget(QWidget* parent = 0);
    ~Widget() override;
    
    //! acts as a parent of all widgets and allows us to remove all the widgets between close and open of projects.
    TableViewAll *tableViewAll = nullptr;
    //! Model interface between the Manager and the Qt MVC framework.
    TableModel *mainTable = nullptr;
    //! Each tab will be a group. Will have at least one, the allGroup.
    QTabWidget *tabWidget = nullptr;
    //! Temp for develop convenience.
    QToolBar *toolbar = nullptr;
    
public Q_SLOTS:
  //! Slot invoked upon renaming a group.
  void groupRenamedSlot(QWidget *tab, const QString &newName);
  //! Slot invoked upon the command to create a group.
  void addGroupSlot();
  //! Slot invoked upon the command to remove a group.
  void removeGroupSlot(QWidget *tab);
  //! Slot invoked upon the command to write out the graphviz file.
  void writeOutGraphSlot();
  //! Temp for testing, fills in example expressions
  void fillInTestManagerSlot();
  //! Temp for testing, dump list of links.
  void dumpLinksSlot();
  //! Show a tab demonstrating syntax
  void goExamplesTabSlot();
  
private:
  //! Build the GUI.
  void setupGui();
  //! Setting up the view.
  void addGroupView(int, const QString &name);
  //! Manager to interface with.
  Manager *eManager = nullptr;
  std::unique_ptr<msg::Node> node;
  std::unique_ptr<msg::Sift> sift;
  void setupDispatcher();
  void closeProjectDispatched(const msg::Message &);
  void openNewProjectDispatched(const msg::Message &);
};
}

#endif // EXPR_WIDGET_H
