/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2017  Thomas S. Anderson blobfish.at.gmx.com
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

#ifndef CMD_FEATUREREPOSITION_H
#define CMD_FEATUREREPOSITION_H

#include "command/cmdbase.h"

namespace cmd
{
  /*! @brief reposition feature from dragger to the current coordinate system
   * 
   * for now, this will be only used in a pick first scenario.
   * should this ignore the draggers linked value? yes for now.
   */
  class FeatureReposition : public Base
  {
  public:
    FeatureReposition();
    virtual ~FeatureReposition() override;
    
    virtual std::string getCommandName() override{return "Feature Reposition";}
    virtual std::string getStatusMessage() override;
    virtual void activate() override;
    virtual void deactivate() override;
  private:
    void go();
  };
}

#endif // CMD_FEATUREREPOSITION_H
