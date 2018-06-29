/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2018  Thomas S. Anderson blobfish.at.gmx.com
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

#ifndef CMD_DISSOLVE_H
#define CMD_DISSOLVE_H

#include <command/base.h>

namespace cmd
{
  /**
  * @brief to make a feature inert.
  */
  class Dissolve : public Base
  {
    public:
      Dissolve();
      virtual ~Dissolve() override;
      
      virtual std::string getCommandName() override{return "Dissolve";}
      virtual std::string getStatusMessage() override;
      virtual void activate() override;
      virtual void deactivate() override;
    private:
      void go();
  };
}

#endif // CMD_DISSOLVE_H
