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

#ifndef PRF_MANAGER_H
#define PRF_MANAGER_H

#include <memory>

#include <boost/filesystem/path.hpp>

class Root;

namespace prf
{
  class Manager
  {
  public:
    Manager();
    std::unique_ptr<Root> rootPtr;
    void saveConfig();
    bool isOk(){return ok;}
    
    //spaceball buttons.
    void setSpaceballButton(int, unsigned int);
    unsigned int getSpaceballButton(int) const; //!< empty string means not assigned.
    //hot keys
    void setHotKey(int, unsigned int);
    unsigned int getHotKey(int) const; //!< empty string means not assigned.
    std::string getMenuConfigPath() const; //!< return maybe empty.
  private:
    bool createDefaultXml();
    bool createDefaultXsd();
    void setup();
    bool readConfig();
    void ensureDefaults();
    boost::filesystem::path xmlPath;
    boost::filesystem::path xsdPath;
    bool ok;
  };
  Manager& manager();
}

#endif // PRF_MANAGER_H
