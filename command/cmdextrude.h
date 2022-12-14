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

#ifndef CMD_EXTRUDE_H
#define CMD_EXTRUDE_H

#include "command/cmdleafmanager.h"
#include "command/cmdbase.h"

namespace ftr{namespace Extrude{class Feature;} struct Pick; typedef std::vector<Pick> Picks;}

namespace cmd
{
  /**
  * @todo write docs
  */
  class Extrude : public Base
  {
  public:
    ftr::Extrude::Feature *feature = nullptr;
    
    Extrude();
    Extrude(ftr::Base*);
    ~Extrude() override;
    
    virtual std::string getCommandName() override{return "Extrude";}
    virtual std::string getStatusMessage() override;
    virtual void activate() override;
    virtual void deactivate() override;
    
    void setToAxisInfer(const std::vector<slc::Message>&);
    void setToAxisPicks(const std::vector<slc::Message>&, const std::vector<slc::Message>&);
    void setToAxisParameter(const std::vector<slc::Message>&);
    void localUpdate();
  private:
    cmd::LeafManager leafManager;
    void go();
    ftr::Picks connect(const std::vector<slc::Message>&, std::string_view);
  };
}

#endif // CMD_EXTRUDE_H
