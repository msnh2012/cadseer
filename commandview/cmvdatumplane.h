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

#ifndef CMV_DATUMPLANE_H
#define CMV_DATUMPLANE_H

#include <memory>

#include "commandview/cmvbase.h"

namespace cmd{class DatumPlane;}

namespace cmv
{
  /**
  * @todo write docs
  */
  class DatumPlane : public Base
  {
    Q_OBJECT
  public:
    DatumPlane(cmd::DatumPlane*);
    ~DatumPlane() override;
  public Q_SLOTS:
    void stackedChanged(int);
    void planarOffsetSelectionChanged();
    void planarCenterSelectionChanged();
    void axisAngleSelectionChanged();
    void average3PlaneSelectionChanged();
    void through3PointsSelectionChanged();
  private:
    struct Stow;
    std::unique_ptr<Stow> stow;
  };
}

#endif // CMV_DATUMPLANE_H