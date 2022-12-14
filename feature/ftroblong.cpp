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

#include "globalutilities.h"
#include "tools/idtools.h"
#include "preferences/preferencesXML.h"
#include "preferences/prfmanager.h"
#include "annex/annseershape.h"
#include "library/lbripgroup.h"
#include "library/lbrcsysdragger.h"
#include "project/serial/generated/prjsrloblsoblong.h"
#include "annex/anncsysdragger.h"
#include "feature/ftroblongbuilder.h"
#include "feature/ftrupdatepayload.h"
#include "feature/ftrinputtype.h"
#include "feature/ftrprimitive.h"
#include "tools/featuretools.h"
#include "parameter/prmconstants.h"
#include "parameter/prmparameter.h"
#include "feature/ftroblong.h"

using namespace ftr::Oblong;
using boost::uuids::uuid;

QIcon Feature::icon = QIcon(":/resources/images/constructionOblong.svg");

//duplicated from box.
enum class FeatureTag
{
  Root,         //!< compound
  Solid,        //!< solid
  Shell,        //!< shell
  FaceXP,       //!< x positive face
  FaceXN,       //!< x negative face
  FaceYP,       //!< y positive face
  FaceYN,       //!< y negative face
  FaceZP,       //!< z positive face
  FaceZN,       //!< z negative face
  WireXP,       //!< x positive wire
  WireXN,       //!< x negative wire
  WireYP,       //!< y positive wire
  WireYN,       //!< y negative wire
  WireZP,       //!< z positive wire
  WireZN,       //!< z negative wire
  EdgeXPYP,     //!< edge at intersection of x positive face and y positive face.
  EdgeXPZP,     //!< edge at intersection of x positive face and z positive face.
  EdgeXPYN,     //!< edge at intersection of x positive face and y negative face.
  EdgeXPZN,     //!< edge at intersection of x positive face and z negative face.
  EdgeXNYN,     //!< edge at intersection of x negative face and y negative face.
  EdgeXNZP,     //!< edge at intersection of x negative face and z positive face.
  EdgeXNYP,     //!< edge at intersection of x negative face and y positive face.
  EdgeXNZN,     //!< edge at intersection of x negative face and z negative face.
  EdgeYPZP,     //!< edge at intersection of y positive face and z positive face.
  EdgeYPZN,     //!< edge at intersection of y positive face and z negative face.
  EdgeYNZP,     //!< edge at intersection of y negative face and z positive face.
  EdgeYNZN,     //!< edge at intersection of y negative face and z negative face.
  VertexXPYPZP, //!< vertex at intersection of faces x+, y+, z+
  VertexXPYNZP, //!< vertex at intersection of faces x+, y-, z+
  VertexXPYNZN, //!< vertex at intersection of faces x+, y-, z-
  VertexXPYPZN, //!< vertex at intersection of faces x+, y+, z-
  VertexXNYNZP, //!< vertex at intersection of faces x-, y-, z+
  VertexXNYPZP, //!< vertex at intersection of faces x-, y+, z+
  VertexXNYPZN, //!< vertex at intersection of faces x-, y+, z-
  VertexXNYNZN  //!< vertex at intersection of faces x-, y-, z-
};

static const std::map<FeatureTag, std::string> featureTagMap = 
{
  {FeatureTag::Root, "Root"},
  {FeatureTag::Solid, "Solid"},
  {FeatureTag::Shell, "Shell"},
  {FeatureTag::FaceXP, "FaceXP"},
  {FeatureTag::FaceXN, "FaceXN"},
  {FeatureTag::FaceYP, "FaceYP"},
  {FeatureTag::FaceYN, "FaceYN"},
  {FeatureTag::FaceZP, "FaceZP"},
  {FeatureTag::FaceZN, "FaceZN"},
  {FeatureTag::WireXP, "WireXP"},
  {FeatureTag::WireXN, "WireXN"},
  {FeatureTag::WireYP, "WireYP"},
  {FeatureTag::WireYN, "WireYN"},
  {FeatureTag::WireZP, "WireZP"},
  {FeatureTag::WireZN, "WireZN"},
  {FeatureTag::EdgeXPYP, "EdgeXPYP"},
  {FeatureTag::EdgeXPZP, "EdgeXPZP"},
  {FeatureTag::EdgeXPYN, "EdgeXPYN"},
  {FeatureTag::EdgeXPZN, "EdgeXPZN"},
  {FeatureTag::EdgeXNYN, "EdgeXNYN"},
  {FeatureTag::EdgeXNZP, "EdgeXNZP"},
  {FeatureTag::EdgeXNYP, "EdgeXNYP"},
  {FeatureTag::EdgeXNZN, "EdgeXNZN"},
  {FeatureTag::EdgeYPZP, "EdgeYPZP"},
  {FeatureTag::EdgeYPZN, "EdgeYPZN"},
  {FeatureTag::EdgeYNZP, "EdgeYNZP"},
  {FeatureTag::EdgeYNZN, "EdgeYNZN"},
  {FeatureTag::VertexXPYPZP, "VertexXPYPZP"},
  {FeatureTag::VertexXPYNZP, "VertexXPYNZP"},
  {FeatureTag::VertexXPYNZN, "VertexXPYNZN"},
  {FeatureTag::VertexXPYPZN, "VertexXPYPZN"},
  {FeatureTag::VertexXNYNZP, "VertexXNYNZP"},
  {FeatureTag::VertexXNYPZP, "VertexXNYPZP"},
  {FeatureTag::VertexXNYPZN, "VertexXNYPZN"},
  {FeatureTag::VertexXNYNZN, "VertexXNYNZN"}
};

inline static const prf::Oblong& pOb(){return prf::manager().rootPtr->features().oblong().get();}

struct Feature::Stow
{
  Feature &feature;
  Primitive primitive;
  
  Stow() = delete;
  Stow(Feature &fIn)
  : feature(fIn)
  , primitive(Primitive::Input{fIn, fIn.parameters, fIn.annexes})
  {
    primitive.addLength(pOb().length());
    primitive.addWidth(pOb().width());
    primitive.addHeight(pOb().height());
    
    primitive.lengthIP->setMatrixDims(osg::Matrixd::rotate(osg::PI_2, osg::Vec3d(0.0, 0.0, -1.0)));
    primitive.lengthIP->setRotationAxis(osg::Vec3d(1.0, 0.0, 0.0), osg::Vec3d(0.0, 0.0, 1.0));
    
    // width matrixDims are good at default.
    primitive.widthIP->setRotationAxis(osg::Vec3d(0.0, 1.0, 0.0), osg::Vec3d(0.0, 0.0, -1.0));
    
    primitive.heightIP->setMatrixDims(osg::Matrixd::rotate(osg::PI_2, osg::Vec3d(1.0, 0.0, 0.0)));
    primitive.heightIP->setRotationAxis(osg::Vec3d(0.0, 0.0, 1.0), osg::Vec3d(0.0, 1.0, 0.0));
    
    initializeMaps();
  }

  
  void updateIPs()
  {
    primitive.IPsToCsys();
    
    double l = primitive.length->getDouble() / 2.0;
    double w = primitive.width->getDouble() / 2.0;
    double h = primitive.height->getDouble() / 2.0;
    
    {
      auto rotation = osg::Matrixd::rotate(osg::PI_2, osg::Vec3d(0.0, 1.0, 0.0));
      auto translation = osg::Matrixd::translate(0.0, w, h);
      primitive.lengthIP->setMatrixDragger(rotation * translation);
    }
    {
      auto rotation = osg::Matrixd::rotate(osg::PI_2, osg::Vec3d(-1.0, 0.0, 0.0));
      auto translation = osg::Matrixd::translate(l, 0.0, h);
      primitive.widthIP->setMatrixDragger(rotation * translation);
    }
    //no need to rotate
    primitive.heightIP->setMatrixDragger(osg::Matrixd::translate(l, w, 0.0));
  }
  
  //duplicate of box.
  void initializeMaps()
  {
    //result 
    std::vector<uuid> tempIds; //save ids for later.
    for (unsigned int index = 0; index < 35; ++index)
    {
      uuid tempId = gu::createRandomId();
      tempIds.push_back(tempId);
      primitive.sShape.insertEvolve(gu::createNilId(), tempId);
    }
    
    //helper lamda
    auto insertIntoFeatureMap = [this](const uuid &idIn, FeatureTag featureTagIn)
    {
      primitive.sShape.insertFeatureTag(idIn, featureTagMap.at(featureTagIn));
    };
    
    insertIntoFeatureMap(tempIds.at(0), FeatureTag::Root);
    insertIntoFeatureMap(tempIds.at(1), FeatureTag::Solid);
    insertIntoFeatureMap(tempIds.at(2), FeatureTag::Shell);
    insertIntoFeatureMap(tempIds.at(3), FeatureTag::FaceXP);
    insertIntoFeatureMap(tempIds.at(4), FeatureTag::FaceXN);
    insertIntoFeatureMap(tempIds.at(5), FeatureTag::FaceYP);
    insertIntoFeatureMap(tempIds.at(6), FeatureTag::FaceYN);
    insertIntoFeatureMap(tempIds.at(7), FeatureTag::FaceZP);
    insertIntoFeatureMap(tempIds.at(8), FeatureTag::FaceZN);
    insertIntoFeatureMap(tempIds.at(9), FeatureTag::WireXP);
    insertIntoFeatureMap(tempIds.at(10), FeatureTag::WireXN);
    insertIntoFeatureMap(tempIds.at(11), FeatureTag::WireYP);
    insertIntoFeatureMap(tempIds.at(12), FeatureTag::WireYN);
    insertIntoFeatureMap(tempIds.at(13), FeatureTag::WireZP);
    insertIntoFeatureMap(tempIds.at(14), FeatureTag::WireZN);
    insertIntoFeatureMap(tempIds.at(15), FeatureTag::EdgeXPYP);
    insertIntoFeatureMap(tempIds.at(16), FeatureTag::EdgeXPZP);
    insertIntoFeatureMap(tempIds.at(17), FeatureTag::EdgeXPYN);
    insertIntoFeatureMap(tempIds.at(18), FeatureTag::EdgeXPZN);
    insertIntoFeatureMap(tempIds.at(19), FeatureTag::EdgeXNYN);
    insertIntoFeatureMap(tempIds.at(20), FeatureTag::EdgeXNZP);
    insertIntoFeatureMap(tempIds.at(21), FeatureTag::EdgeXNYP);
    insertIntoFeatureMap(tempIds.at(22), FeatureTag::EdgeXNZN);
    insertIntoFeatureMap(tempIds.at(23), FeatureTag::EdgeYPZP);
    insertIntoFeatureMap(tempIds.at(24), FeatureTag::EdgeYPZN);
    insertIntoFeatureMap(tempIds.at(25), FeatureTag::EdgeYNZP);
    insertIntoFeatureMap(tempIds.at(26), FeatureTag::EdgeYNZN);
    insertIntoFeatureMap(tempIds.at(27), FeatureTag::VertexXPYPZP);
    insertIntoFeatureMap(tempIds.at(28), FeatureTag::VertexXPYNZP);
    insertIntoFeatureMap(tempIds.at(29), FeatureTag::VertexXPYNZN);
    insertIntoFeatureMap(tempIds.at(30), FeatureTag::VertexXPYPZN);
    insertIntoFeatureMap(tempIds.at(31), FeatureTag::VertexXNYNZP);
    insertIntoFeatureMap(tempIds.at(32), FeatureTag::VertexXNYPZP);
    insertIntoFeatureMap(tempIds.at(33), FeatureTag::VertexXNYPZN);
    insertIntoFeatureMap(tempIds.at(34), FeatureTag::VertexXNYNZN);
  }
  
  void updateResult(const OblongBuilder& oblongMakerIn)
  {
    //helper lamda
    auto updateShapeByTag = [this](const TopoDS_Shape &shapeIn, FeatureTag featureTagIn)
    {
      uuid localId = primitive.sShape.featureTagId(featureTagMap.at(featureTagIn));
      primitive.sShape.updateId(shapeIn, localId);
    };
    
  //   updateShapeByTag(sShape->getRootOCCTShape(), FeatureTag::Root);
    updateShapeByTag(oblongMakerIn.getSolid(), FeatureTag::Solid);
    updateShapeByTag(oblongMakerIn.getShell(), FeatureTag::Shell);
    updateShapeByTag(oblongMakerIn.getFaceXP(), FeatureTag::FaceXP);
    updateShapeByTag(oblongMakerIn.getFaceXN(), FeatureTag::FaceXN);
    updateShapeByTag(oblongMakerIn.getFaceYP(), FeatureTag::FaceYP);
    updateShapeByTag(oblongMakerIn.getFaceYN(), FeatureTag::FaceYN);
    updateShapeByTag(oblongMakerIn.getFaceZP(), FeatureTag::FaceZP);
    updateShapeByTag(oblongMakerIn.getFaceZN(), FeatureTag::FaceZN);
    updateShapeByTag(oblongMakerIn.getWireXP(), FeatureTag::WireXP);
    updateShapeByTag(oblongMakerIn.getWireXN(), FeatureTag::WireXN);
    updateShapeByTag(oblongMakerIn.getWireYP(), FeatureTag::WireYP);
    updateShapeByTag(oblongMakerIn.getWireYN(), FeatureTag::WireYN);
    updateShapeByTag(oblongMakerIn.getWireZP(), FeatureTag::WireZP);
    updateShapeByTag(oblongMakerIn.getWireZN(), FeatureTag::WireZN);
    updateShapeByTag(oblongMakerIn.getEdgeXPYP(), FeatureTag::EdgeXPYP);
    updateShapeByTag(oblongMakerIn.getEdgeXPZP(), FeatureTag::EdgeXPZP);
    updateShapeByTag(oblongMakerIn.getEdgeXPYN(), FeatureTag::EdgeXPYN);
    updateShapeByTag(oblongMakerIn.getEdgeXPZN(), FeatureTag::EdgeXPZN);
    updateShapeByTag(oblongMakerIn.getEdgeXNYN(), FeatureTag::EdgeXNYN);
    updateShapeByTag(oblongMakerIn.getEdgeXNZP(), FeatureTag::EdgeXNZP);
    updateShapeByTag(oblongMakerIn.getEdgeXNYP(), FeatureTag::EdgeXNYP);
    updateShapeByTag(oblongMakerIn.getEdgeXNZN(), FeatureTag::EdgeXNZN);
    updateShapeByTag(oblongMakerIn.getEdgeYPZP(), FeatureTag::EdgeYPZP);
    updateShapeByTag(oblongMakerIn.getEdgeYPZN(), FeatureTag::EdgeYPZN);
    updateShapeByTag(oblongMakerIn.getEdgeYNZP(), FeatureTag::EdgeYNZP);
    updateShapeByTag(oblongMakerIn.getEdgeYNZN(), FeatureTag::EdgeYNZN);
    updateShapeByTag(oblongMakerIn.getVertexXPYPZP(), FeatureTag::VertexXPYPZP);
    updateShapeByTag(oblongMakerIn.getVertexXPYNZP(), FeatureTag::VertexXPYNZP);
    updateShapeByTag(oblongMakerIn.getVertexXPYNZN(), FeatureTag::VertexXPYNZN);
    updateShapeByTag(oblongMakerIn.getVertexXPYPZN(), FeatureTag::VertexXPYPZN);
    updateShapeByTag(oblongMakerIn.getVertexXNYNZP(), FeatureTag::VertexXNYNZP);
    updateShapeByTag(oblongMakerIn.getVertexXNYPZP(), FeatureTag::VertexXNYPZP);
    updateShapeByTag(oblongMakerIn.getVertexXNYPZN(), FeatureTag::VertexXNYPZN);
    updateShapeByTag(oblongMakerIn.getVertexXNYNZN(), FeatureTag::VertexXNYNZN);
  }
};

Feature::Feature()
: Base()
, stow(std::make_unique<Stow>(*this))
{
  name = QObject::tr("Oblong");
  mainSwitch->setUserValue<int>(gu::featureTypeAttributeTitle, static_cast<int>(getType()));
}

Feature::~Feature() = default;

/*
void Feature::setCSys(const osg::Matrixd &csysIn)
{
  osg::Matrixd oldSystem = csys->getMatrix();
  if (!csys->setValue(csysIn))
    return; // already at this csys
    
  //apply the same transformation to dragger, so dragger moves with it.
  osg::Matrixd diffMatrix = osg::Matrixd::inverse(oldSystem) * csysIn;
  csysDragger->draggerUpdate(csysDragger->dragger->getMatrix() * diffMatrix);
}
*/

void Feature::updateModel(const UpdatePayload &plIn)
{
  setFailure();
  lastUpdateLog.clear();
  stow->primitive.sShape.reset();
  try
  {
    if (isSkipped())
    {
      setSuccess();
      throw std::runtime_error("feature is skipped");
    }
    
    if (!(stow->primitive.length->getDouble() > stow->primitive.width->getDouble()))
      throw std::runtime_error("length must be greater than width");
    
    //nothing for constant.
    if (static_cast<CSysType>(stow->primitive.csysType.getInt()) == Linked)
    {
      const auto &picks = stow->primitive.csysLinked.getPicks();
      if (picks.empty())
        throw std::runtime_error("No picks for csys link");
      tls::Resolver resolver(plIn);
      if (!resolver.resolve(picks.front()))
        throw std::runtime_error("Couldn't resolve csys link pick");
      auto csysPrms = resolver.getFeature()->getParameters(prm::Tags::CSys);
      if (csysPrms.empty())
        throw std::runtime_error("csys link feature has no csys parameter");
      prm::ObserverBlocker(stow->primitive.csysObserver);
      stow->primitive.csys.setValue(csysPrms.front()->getMatrix());
      stow->primitive.csysDragger.draggerUpdate();
    }
    
    OblongBuilder oblongMaker
    (
      stow->primitive.length->getDouble(),
      stow->primitive.width->getDouble(),
      stow->primitive.height->getDouble(),
      gu::toOcc(stow->primitive.csys.getMatrix())
    );
    stow->primitive.sShape.setOCCTShape(oblongMaker.getSolid(), getId());
    stow->updateResult(oblongMaker);
    mainTransform->setMatrix(osg::Matrixd::identity());
    setSuccess();
  }
  catch (const Standard_Failure &e)
  {
    std::ostringstream s; s << "OCC Error in oblong update: " << e.GetMessageString() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (const std::exception &e)
  {
    std::ostringstream s; s << "Standard error in oblong update: " << e.what() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (...)
  {
    std::ostringstream s; s << "Unknown error in oblong update." << std::endl;
    lastUpdateLog += s.str();
  }
  setModelClean();
  stow->updateIPs();
  if (!lastUpdateLog.empty())
    std::cout << std::endl << lastUpdateLog;
}

void Feature::serialWrite(const boost::filesystem::path &dIn)
{
  prj::srl::obls::Oblong oblongOut
  (
    Base::serialOut(),
    stow->primitive.csysType.serialOut(),
    stow->primitive.length->serialOut(),
    stow->primitive.width->serialOut(),
    stow->primitive.height->serialOut(),
    stow->primitive.csys.serialOut(),
    stow->primitive.csysLinked.serialOut(),
    stow->primitive.csysDragger.serialOut(),
    stow->primitive.sShape.serialOut(),
    stow->primitive.lengthIP->serialOut(),
    stow->primitive.widthIP->serialOut(),
    stow->primitive.heightIP->serialOut()
  );
  
  xml_schema::NamespaceInfomap infoMap;
  std::ofstream stream(buildFilePathName(dIn).string());
  prj::srl::obls::oblong(stream, oblongOut, infoMap);
}

void Feature::serialRead(const prj::srl::obls::Oblong &sOblong)
{
  Base::serialIn(sOblong.base());
  stow->primitive.csysType.serialIn(sOblong.csysType());
  stow->primitive.length->serialIn(sOblong.length());
  stow->primitive.width->serialIn(sOblong.width());
  stow->primitive.height->serialIn(sOblong.height());
  stow->primitive.csys.serialIn(sOblong.csys());
  stow->primitive.csysLinked.serialIn(sOblong.csysLinked());
  stow->primitive.csysDragger.serialIn(sOblong.csysDragger());
  stow->primitive.sShape.serialIn(sOblong.seerShape());
  stow->primitive.lengthIP->serialIn(sOblong.lengthIP());
  stow->primitive.widthIP->serialIn(sOblong.widthIP());
  stow->primitive.heightIP->serialIn(sOblong.heightIP());
}
