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

#ifndef MDV_DATUMAXIS_H
#define MDV_DATUMAXIS_H

#include <modelviz/base.h>

namespace mdv
{
  /**
  * @todo write docs
  */
  class DatumAxis : public Base
  {
  public:
    DatumAxis();
    DatumAxis(const DatumAxis &rhs, const osg::CopyOp& copyOperation = osg::CopyOp::SHALLOW_COPY);

    virtual osg::Object* cloneType() const override {return new DatumAxis();}
    virtual osg::Object* clone(const osg::CopyOp& copyOperation) const override {return new DatumAxis(*this, copyOperation);}
    virtual bool isSameKindAs(const osg::Object* obj) const override {return dynamic_cast<const DatumAxis*>(obj)!=NULL;}
    virtual const char* libraryName() const override {return "osg";}
    virtual const char* className() const override {return "Geometry";}
    
    virtual void setToColor() override;
    virtual void setToPreHighlight() override;
    virtual void setToHighlight() override;
    
    void setHeight(double);
    
  protected:
    void setAxisColor(const osg::Vec4&);
    void buildGeometry();
    
    double height = 1.0;
  };
}

#endif // MDV_DATUMAXIS_H