/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2022 Thomas S. Anderson blobfish.at.gmx.com
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

#ifndef FTR_MUTATE_H
#define FTR_MUTATE_H

#include "feature/ftrbase.h"

namespace prj{namespace srl{namespace mtts{class Mutate;}}}

namespace ftr
{
  namespace Mutate
  {
    namespace InputTags
    {
      inline constexpr std::string_view shape = "shape";
    }
    
    namespace PrmTags
    {
      inline constexpr std::string_view shape = "shape";
    }
    
    class Feature : public Base
    {
    public:
      Feature();
      ~Feature() override;
      
      void updateModel(const UpdatePayload&) override;
      Type getType() const override {return Type::Mutate;}
      const std::string& getTypeString() const override {return toString(Type::Mutate);}
      const QIcon& getIcon() const override {return icon;}
      Descriptor getDescriptor() const override {return Descriptor::Alter;}
      
      void serialWrite(const boost::filesystem::path&) override;
      void serialRead(const prj::srl::mtts::Mutate&);
    private:
      static QIcon icon;
      struct Stow;
      std::unique_ptr<Stow> stow;
    };
  }
}

#endif //FTR_MUTATE_H
