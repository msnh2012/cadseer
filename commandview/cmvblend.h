/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2020 Thomas S. Anderson blobfish.at.gmx.com
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

#ifndef CMV_BLEND_H
#define CMV_BLEND_H

#include <memory>

#include "commandview/cmvbase.h"

namespace cmd{class Blend;}

namespace cmv
{
  /**
  * @todo write docs
  */
  class Blend : public Base
  {
    Q_OBJECT
  public:
    Blend(cmd::Blend*);
    ~Blend() override;
  protected:
    bool eventFilter(QObject*, QEvent*) override;
  public Q_SLOTS:
    void closeAllPersistent();
    void modelChanged(const QModelIndex&, const QModelIndex&);
    void constantChanged(const QModelIndex&, const QModelIndex&);
    void constantsSelectionChanged();
    void variableContoursChanged(const QModelIndex&, const QModelIndex&);
    void variableEntriesChanged(const QModelIndex&, const QModelIndex&);
    void removeEntry();
    void entriesSelectionChanged();
  private:
    struct Stow;
    std::unique_ptr<Stow> stow;
    
    void addConstant();
    void removeConstant();
  };
}

#endif // CMV_BLEND_H
