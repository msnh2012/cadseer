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

#ifndef DLG_PROJECT_H
#define DLG_PROJECT_H

#include <boost/filesystem/path.hpp>

#include <QDialog>

namespace Ui{ class projectDialog; }

namespace dlg
{
  class Project : public QDialog
  {
      Q_OBJECT
  public:
    enum class Result
    {
      None = 0, //!< error
      Open, //!< open a project
      New, //!< create a project
      Recent, //!< picked from recent list
      Cancel //!< dialog was cancelled
    };
    Project(QWidget* = 0);
    ~Project();
    Result getResult(){return result;}
    boost::filesystem::path getDirectory(){return directory;}
  private:
    Ui::projectDialog* ui;
    Result result;
    boost::filesystem::path directory;
    
    void addToRecentList();
    void populateRecentList();
    bool validateDir(const boost::filesystem::path &dir);
    
  private Q_SLOTS:
    void goNewSlot();
    void goOpenSlot();
    void goRecentSlot(int, int);
  };
}

#endif // DLG_PROJECT_H
