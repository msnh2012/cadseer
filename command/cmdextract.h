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

#ifndef CMD_EXTRACT_H
#define CMD_EXTRACT_H

#include "command/cmdbase.h"

namespace dlg{class Extract;}
namespace ftr{class Extract;}

namespace cmd
{
  class Extract : public Base
  {
  public:
    Extract();
    ~Extract() override;
    
    virtual std::string getCommandName() override{return "Extract";}
    virtual std::string getStatusMessage() override;
    virtual void activate() override;
    virtual void deactivate() override;
  private:
    void go();
    bool firstRun = true;
    dlg::Extract *dialog = nullptr;
    ftr::Extract *feature = nullptr;
  };
  
  /**
  * @todo write docs
  */
  class ExtractEdit : public Base
  {
  public:
    ExtractEdit(ftr::Base*);
    ~ExtractEdit() override;
    
    std::string getCommandName() override{return "Extract Edit";}
    std::string getStatusMessage() override;
    void activate() override;
    void deactivate() override;
  private:
    dlg::Extract *dialog = nullptr;
    ftr::Extract *feature = nullptr;
  };
}

#endif // CMD_EXTRACT_H
