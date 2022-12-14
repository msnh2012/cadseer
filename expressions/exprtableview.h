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

#ifndef EXPR_TABLEVIEW_H
#define EXPR_TABLEVIEW_H

#include <QTableView>
#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QWidget>

class QContextMenuEvent;
class QShowEvent;
class QAction;

namespace expr{

//! @class TableViewBase @brief common code for syncing headerview widths
class TableViewBase : public QTableView
{
  Q_OBJECT
public:
  explicit TableViewBase(QWidget *parentIn = 0);
protected:
  void showEvent(QShowEvent*) override;
private Q_SLOTS:
  void columnResizedSlot(int, int, int);
private:
  void restoreSettings();
};
  
//! @brief Table view for all the expressions.
class TableViewAll : public TableViewBase
{
  Q_OBJECT
public:
  explicit TableViewAll(QWidget *parentIn = 0);
protected:
  //! Show the menu.
  void contextMenuEvent(QContextMenuEvent*) override;
public Q_SLOTS:
  //! Add selected expressions to group.
  void addToGroupSlot();
  //! Remove expression.
  void removeFormulaSlot();
  //! Export selected expressions to file.
  void exportFormulaSlot();
  //! Import expressions from file.
  void importFormulaSlot();
  //! Copy the formulas value to clipboard.
  void copyFormulaValueSlot();
  void addScalarSlot(); //!< Add new scalar expression.
  void addVectorSlot(); //!< Add new vector expression.
  void addRotationSlot(); //!< Add new rotation expression.
  void addCSysSlot(); //!< Add new csys expression.
  
Q_SIGNALS:
  void addGroupSignal();
private:
  void buildActions();
  
  QAction *removeFormulaAction;
  QAction *exportFormulaAction;
  QAction *importFormulaAction;
  QAction *addGroupAction;
  QAction *copyFormulaValueAction;
  
  QAction *addScalarAction;
  QAction *addVectorAction;
  QAction *addRotationAction;
  QAction *addCSysAction;
};

//! @brief Table view for a group of expressions.
class TableViewGroup : public TableViewBase
{
  Q_OBJECT
public:
  explicit TableViewGroup(QWidget *parentIn = 0);
protected:
  //! Show the menu.
  void contextMenuEvent(QContextMenuEvent*) override;
public Q_SLOTS:
  //! Remove expression.
  void removeFormulaSlot();
  //! Remove expression from group. Expression still exists.
  void removeFromGroupSlot();
  //! Rename the group.
  void renameGroupSlot();
  //! Remove the group.
  void removeGroupSlot();
  //! Export selected expressions to file.
  void exportFormulaSlot();
  //! Import expressions from file.
  void importFormulaSlot();
  //! Copy the formulas value to clipboard.
  void copyFormulaValueSlot();
  void addScalarSlot(); //!< Add new scalar expression.
  void addVectorSlot(); //!< Add new vector expression.
  void addRotationSlot(); //!< Add new rotation expression.
  void addCSysSlot(); //!< Add new csys expression.
Q_SIGNALS:
  //! Notify the tab widget about renamed group.
  void groupRenamedSignal(QWidget *tab, const QString &newName);
  //! Notify the tab widget about removed group.
  void groupRemovedSignal(QWidget *tab);
private:
  void buildActions();
  
  QAction *removeFormulaAction;
  QAction *exportFormulaAction;
  QAction *importFormulaAction;
  QAction *removeFromGroupAction;
  QAction *renameGroupAction;
  QAction *removeGroupAction;
  QAction *copyFormulaValueAction;
  
  QAction *addScalarAction;
  QAction *addVectorAction;
  QAction *addRotationAction;
  QAction *addCSysAction;
};

//! @brief view for selection context expressions.
class TableViewSelection : public TableViewBase
{
  Q_OBJECT
public:
  explicit TableViewSelection(QWidget *parent = 0);
  //! Show the menu.
  virtual void contextMenuEvent(QContextMenuEvent *event);
  
public Q_SLOTS:
  //! Copy the formulas value to clipboard.
  void copyFormulaValueSlot();
  
private:
  QAction *copyFormulaValueAction;
};

//! @brief Delegate for editing the expression in the table.
class ExpressionDelegate : public QStyledItemDelegate
{
  Q_OBJECT
public:
  //! Parent must be the table view.
  explicit ExpressionDelegate(QObject *parent);
  //! Creates the editor.
  virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;
  //! Fill editor with text to edit.
  virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;
  //! Match editor to cell size.
  virtual void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;
  //! Set the model data or re-edit upon failure.
  virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;
};

//! @brief Delegate for editing the expression name.
class NameDelegate : public QStyledItemDelegate
{
  Q_OBJECT
public:
  explicit NameDelegate(QObject *parent = 0);
  //! @brief set the new name or re-edit upon failure.
  virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;
};
}


#endif // EXPR_TABLEVIEW_H
