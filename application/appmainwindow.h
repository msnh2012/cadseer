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

#ifndef APP_MAINWINDOW_H
#define APP_MAINWINDOW_H

#include <memory>

#include <QMainWindow>

class QCloseEvent;

namespace vwr{class Widget;}
namespace slc{class Manager;}
namespace msg{struct Message;}

namespace app
{
  class MainWindow : public QMainWindow
  {
    Q_OBJECT
  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    vwr::Widget* getViewer();
    slc::Manager* getSelectionManager();
      
  protected:
    void closeEvent (QCloseEvent*) override;
    bool eventFilter(QObject*, QEvent*) override;
    
  private Q_SLOTS:
    void actionTriggeredSlot();

  private:
    struct Stow;
    std::unique_ptr<Stow> stow;
    
    void setupDispatcher();
    void preferencesChanged(const msg::Message&);
    void infoTextDispatched(const msg::Message&);
    void showCommandViewDispatched(const msg::Message&);
    void hideCommandViewDispatched(const msg::Message&);
    void commandViewWidth(int, int);
    void setupSelectionToolbar();
  };
}

#endif // APP_MAINWINDOW_H
