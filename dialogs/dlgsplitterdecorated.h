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

#ifndef DLG_SPLITTERDECORATED_H
#define DLG_SPLITTERDECORATED_H

#include <QSplitter>

namespace dlg
{
  /*! @class SplitterDecorated
   * @brief A QSplitter with a visual cue to user.
   * @details A QSplitter with a visual cue to user.
   * Heads up! QSplitter incorporates the orientation into
   * reading and writing of settings. So what can happen:
   * Programmer forgets to set the orientation of the splitter
   * before first run. Now the settings have the orientation
   * and when the programmer sets the orientation it appears
   * to have no affect as the settings read override the
   * the orientation setting. Very confusing.
   */
class SplitterDecorated : public QSplitter
{
  Q_OBJECT
  public:
    explicit SplitterDecorated(QWidget *parent = 0);
    ~SplitterDecorated();
    void restoreSettings(const QString &nameIn);
    void saveSettings();
  protected:
    virtual QSplitterHandle* createHandle() override;
};
}

#endif // DLG_SPLITTERDECORATED_H
