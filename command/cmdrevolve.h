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

#ifndef CMD_REVOLVE_H
#define CMD_REVOLVE_H

#include "command/cmdleafmanager.h"
#include "command/cmdbase.h"

namespace ftr{namespace Revolve{class Feature;}}

namespace cmd
{
  /**
  * @todo write docs
  */
  class Revolve : public Base
  {
  public:
    ftr::Revolve::Feature *feature = nullptr;
    
    Revolve();
    Revolve(ftr::Base*);
    ~Revolve() override;
    
    std::string getCommandName() override{return "Revolve";}
    std::string getStatusMessage() override;
    void activate() override;
    void deactivate() override;
    
    void localUpdate();
    void setToAxisPicks(const slc::Messages&, const slc::Messages&);
    void setToAxisParameter(const slc::Messages&);
  private:
    cmd::LeafManager leafManager;
    void go();
    ftr::Picks connect(const slc::Messages&, std::string_view);
  };
}

#endif // CMD_REVOLVE_H
