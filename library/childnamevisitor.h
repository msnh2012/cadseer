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

#include <osg/NodeVisitor>

namespace lbr
{
  class ChildNameVisitor : public osg::NodeVisitor
  {
  public:
    ChildNameVisitor(const char *nameIn) :
      osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN), name(nameIn){}
    virtual void apply(osg::Node &node) override
    {
      if (node.getName() == std::string(name))
      {
        out = &node;
        return; //only finds first occurrence of name.
      }
      traverse(node);
    }
    
    template <typename T>
    T* castResult()
    {
      T* result = dynamic_cast<T*>(out);
      assert(result);
      return result;
    }
    
    osg::Node *out = nullptr;
  protected:
    const char *name;
  };
}
