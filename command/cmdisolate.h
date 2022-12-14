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

#ifndef CMD_ISOLATE_H
#define CMD_ISOLATE_H

#include "selection/slcdefinitions.h"
#include "message/msgmessage.h"
#include "command/cmdbase.h"

namespace cmd
{
  class Isolate : public Base
  {
  public:
    Isolate();
    virtual ~Isolate() override;
    
    virtual std::string getCommandName() override{return "Isolate";}
    virtual std::string getStatusMessage() override;
    virtual void activate() override;
    virtual void deactivate() override;
    
    void setFromMessage(const msg::Message&);
    boost::uuids::uuid id;
    msg::Mask mask;
  private:
    void setupDispatcher();
    void selectionAdditionDispatched(const msg::Message&);
    void go();
  };
}

#endif // CMD_ISOLATE_H
