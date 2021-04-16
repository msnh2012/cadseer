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

#ifndef FTR_STRIP_H
#define FTR_STRIP_H

#include "parameter/prmparameter.h"
#include "library/lbrplabel.h"
#include "feature/ftrbase.h"

class TopoDS_Shape;

namespace prj{namespace srl{namespace stps{class Strip;}}}
namespace ann{class SeerShape;}
namespace occt{class BoundingBox;}
namespace prm{struct Observer;}
namespace ftr
{
  class Strip : public Base
  {
  public:
    constexpr static const char *part = "Part";
    constexpr static const char *blank = "Blank";
    constexpr static const char *nest = "Nest";
    
    Strip();
    virtual ~Strip() override;
    
    virtual void updateModel(const UpdatePayload&) override;
    virtual Type getType() const override {return Type::Strip;}
    virtual const std::string& getTypeString() const override {return toString(Type::Strip);}
    virtual const QIcon& getIcon() const override {return icon;}
    virtual Descriptor getDescriptor() const override {return Descriptor::Create;}
    virtual void serialWrite(const boost::filesystem::path&) override;
    void serialRead(const prj::srl::stps::Strip&);
    
    void setAutoCalc(bool acIn){autoCalc->setValue(acIn);}
    bool isAutoCalc() const {return autoCalc->getBool();}
    double getPitch() const {return pitch->getDouble();}
    double getWidth() const {return width->getDouble();}
    double getHeight() const {return stripHeight;}
    
    std::vector<QString> stations;
    
  protected:
    std::unique_ptr<prm::Parameter> feedDirection;
    std::unique_ptr<prm::Parameter> pitch;
    std::unique_ptr<prm::Parameter> width;
    std::unique_ptr<prm::Parameter> widthOffset;
    std::unique_ptr<prm::Parameter> gap;
    std::unique_ptr<prm::Parameter> autoCalc;
    
    std::unique_ptr<prm::Observer> prmObserver;
    
    std::unique_ptr<ann::SeerShape> sShape;
    
    osg::ref_ptr<lbr::PLabel> feedDirectionLabel;
    osg::ref_ptr<lbr::PLabel> pitchLabel;
    osg::ref_ptr<lbr::PLabel> widthLabel;
    osg::ref_ptr<lbr::PLabel> widthOffsetLabel; //!< centerline of die.
    osg::ref_ptr<lbr::PLabel> gapLabel;
    osg::ref_ptr<lbr::PLabel> autoCalcLabel;
    std::vector<osg::ref_ptr<osg::MatrixTransform>> stationLabels;
    
    double stripHeight; //!< used by quote to get travel.
    
    void goAutoCalc(const TopoDS_Shape&, occt::BoundingBox&);
    
  private:
    static QIcon icon;
  };
}

#endif // FTR_STRIP_H
