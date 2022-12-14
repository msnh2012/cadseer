/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2019  Thomas S. Anderson blobfish.at.gmx.com
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

#ifndef FTR_SURFACEMESH_H
#define FTR_SURFACEMESH_H

#include "mesh/mshparameters.h"
#include "feature/ftrbase.h"

namespace ann{class SurfaceMesh;}
namespace prj{namespace srl{namespace sfms{class SurfaceMesh;}}}

namespace ftr
{
  namespace SurfaceMesh
  {
    enum MeshType //keep in sync with parameter.
    {
      Inert, //!< creation is done some where else. Think import.
      Occt, //!< construct from parent feature shape and use occt mesher.
      Netgen, //!< construct from parent feature shape and use netgen mesher.
      Gmsh //!< construct from parent feature shape and use gmsh mesher.
    };
    namespace Tags
    {
      inline constexpr std::string_view MeshType = "MeshType";
      inline constexpr std::string_view Source = "Source";
    }
    
    class Feature : public Base
    {
    public:
      Feature();
      ~Feature() override;
      
      void updateModel(const UpdatePayload&) override;
      void updateVisual() override;
      Type getType() const override {return Type::SurfaceMesh;}
      const std::string& getTypeString() const override {return toString(Type::SurfaceMesh);}
      const QIcon& getIcon() const override {return icon;}
      Descriptor getDescriptor() const override {return Descriptor::Create;}
      
      void serialWrite(const boost::filesystem::path&) override;
      void serialRead(const prj::srl::sfms::SurfaceMesh&);
      
      //use Base::getAnnex to get mesh.
      void setMesh(std::unique_ptr<ann::SurfaceMesh> mIn, bool setToInert = true);
      const msh::prm::OCCT& getOcctParameters() const;
      void setOcctParameters(const msh::prm::OCCT&);
      const msh::prm::Netgen& getNetgenParameters() const;
      void setNetgenParameters(const msh::prm::Netgen&);
      
    private:
      static QIcon icon;
      struct Stow;
      std::unique_ptr<Stow> stow;
    };
  }
}

#endif //FTR_SURFACEMESH_H
