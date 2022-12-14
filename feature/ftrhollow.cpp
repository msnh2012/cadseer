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

#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepExtrema_DistShapeShape.hxx>
#include <BRep_Tool.hxx>
#include <BRepTools.hxx>
#include <Geom_Surface.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Wire.hxx>
#include <Precision.hxx>

#include <osg/Switch>

#include "globalutilities.h"
#include "preferences/preferencesXML.h"
#include "preferences/prfmanager.h"
#include "annex/annseershape.h"
#include "feature/ftrshapecheck.h"
#include "library/lbrplabel.h"
#include "project/serial/generated/prjsrlhllshollow.h"
#include "tools/featuretools.h"
#include "tools/idtools.h"
#include "tools/occtools.h"
#include "feature/ftrupdatepayload.h"
#include "feature/ftrinputtype.h"
#include "parameter/prmconstants.h"
#include "parameter/prmparameter.h"
#include "feature/ftrhollow.h"

using boost::uuids::uuid;
using namespace ftr::Hollow;

QIcon Feature::icon = QIcon(":/resources/images/constructionHollow.svg");

struct Feature::Stow
{
  Feature &feature;
  prm::Parameter offset{prm::Names::Offset, prf::manager().rootPtr->features().hollow().get().offset(), prm::Tags::Offset};
  prm::Parameter picks{prm::Names::Picks, ftr::Picks(), prm::Tags::Picks};
  ann::SeerShape sShape;
  osg::ref_ptr<lbr::PLabel> offsetLabel{new lbr::PLabel(&offset)};
  /*! used to map new geometry to old geometry. this will end up
   * more complicated than this as hollow can make splits.
   */ 
  std::map<uuid, uuid> shapeMap;
  
  Stow() = delete;
  Stow(Feature &fIn)
  : feature(fIn)
  {
    offset.setConstraint(prm::Constraint::buildNonZero());
    offset.connectValue(std::bind(&Feature::setModelDirty, &feature));
    feature.parameters.push_back(&offset);
    
    picks.connectValue(std::bind(&Feature::setModelDirty, &feature));
    feature.parameters.push_back(&picks);
    
    feature.annexes.insert(std::make_pair(ann::Type::SeerShape, &sShape));
    
    feature.overlaySwitch->addChild(offsetLabel.get());
  }
  
  void generatedMatch(BRepOffsetAPI_MakeThickSolid &operationIn, const ann::SeerShape &targetShapeIn)
  {
    //note: makeThickSolid::generated is returning all kinds of shapes.
    for (const auto &targetId : targetShapeIn.getAllShapeIds())
    {
      const TopoDS_Shape &originalShape = targetShapeIn.getOCCTShape(targetId);
      const TopTools_ListOfShape &list = operationIn.Generated(originalShape);
      if (list.IsEmpty())
        continue;
      if (list.Size() > 1)
      {
        std::ostringstream s; s << "Warning: unexpected list size: " << list.Size()
        << "    in Hollow::generatedMatch " << std::endl;
        feature.lastUpdateLog += s.str();
      }
      const TopoDS_Shape &newShape = list.First();
      assert(!newShape.IsNull());
      
      //I think generated is returning all the geometry from operation
      //so we have to skip non-existing geometry. like other half of a split.
      if (!sShape.hasShape(newShape))
        continue;
      
      if (!sShape.findId(newShape).is_nil())
        continue; //only set ids for shapes with nil ids.
        
      //should only have faces left to assign. why don't nil wires come through?
      //occt 7.4 started producing vertices here. Just going to skip for now.
      //but maybe we want to map those also.
      //     assert(newShape.ShapeType() == TopAbs_FACE);
      if (newShape.ShapeType() != TopAbs_FACE)
        continue;
        
      uuid freshFaceId = gu::createRandomId();
      bool results;
      std::map<uuid, uuid>::iterator it;
      std::tie(it, results) = shapeMap.insert(std::make_pair(targetId, freshFaceId));
      if (!results)
        freshFaceId = it->second;
      sShape.updateId(newShape, freshFaceId);
      
      //in a hollow these generated entities are actually new entities, whereas for
      //other features, like draft and blend, this is not the case. So these get a nil evolve in.
      if (!sShape.hasEvolveRecordOut(freshFaceId))
        sShape.insertEvolve(gu::createNilId(), freshFaceId);
      
      //update the outerwire.
      uuid freshWireId = gu::createRandomId();
      std::tie(it, results) = shapeMap.insert(std::make_pair(freshFaceId, freshWireId));
      if (!results)
        freshWireId = it->second;
      
      const TopoDS_Shape &wireShape = BRepTools::OuterWire(TopoDS::Face(newShape));
      sShape.updateId(wireShape, freshWireId);
    }
  }
};

Feature::Feature()
: Base()
, stow(std::make_unique<Stow>(*this))
{
  name = QObject::tr("Hollow");
  mainSwitch->setUserValue<int>(gu::featureTypeAttributeTitle, static_cast<int>(getType()));
}

Feature::~Feature() = default;

/* as occt v7.1(actually commit 4d97335) there seems to be a tolerance bug
 * in BRepOffsetAPI_MakeThickSolid. to reproduce the bug in drawexe:
 * 
 * pload MODELING
 * box aBox 20 10 6
 * explode aBox f
 * offsetshape result aBox 1.0 aBox_1
 * maxtolerance aBox
 * maxtolerance result
 * 
 * for both 'aBox' and 'result' the max tolerances for both edge and vertex
 * are 1.00000e-03. way too loose. going to let one point release go by
 * and check these results again before trying to get a bug report.
 * 
 * will this work with no removal faces?
 */
void Feature::updateModel(const UpdatePayload &payloadIn)
{
  setFailure();
  lastUpdateLog.clear();
  stow->sShape.reset();
  try
  {
    std::vector<const Base*> tfs = payloadIn.getFeatures(std::string());
    if (tfs.size() != 1)
      throw std::runtime_error("no parent for hollow");
    if (!tfs.front()->hasAnnex(ann::Type::SeerShape))
      throw std::runtime_error("parent doesn't have seer shape");
    const ann::SeerShape &tss= tfs.front()->getAnnex<ann::SeerShape>();
    if (tss.isNull())
      throw std::runtime_error("target seer shape is null");
    
    //setup new failure state.
    stow->sShape.setOCCTShape(tss.getRootOCCTShape(), getId());
    stow->sShape.shapeMatch(tss);
    stow->sShape.uniqueTypeMatch(tss);
    stow->sShape.outerWireMatch(tss);
    stow->sShape.derivedMatch();
    stow->sShape.ensureNoNils(); //just in case
    stow->sShape.ensureNoDuplicates(); //just in case
    stow->sShape.ensureEvolve();
    
    if (isSkipped())
    {
      setSuccess();
      throw std::runtime_error("feature is skipped");
    }
    
    bool labelSet = false;
    occt::ShapeVector closingFaceShapes;
    tls::Resolver resolver(payloadIn);
    for (const auto &p : stow->picks.getPicks())
    {
      resolver.resolve(p);
      if (!resolver.getFeature() || !resolver.getSeerShape() || resolver.getResolvedIds().empty())
      {
        std::ostringstream s; s << "Failed to resolve a pick." << std::endl;
        lastUpdateLog += s.str();
        continue;
      }
      for (const auto &rs : resolver.getShapes())
      {
        if (rs.ShapeType() != TopAbs_FACE)
          continue;
        closingFaceShapes.push_back(rs);
        if (!labelSet)
        {
          labelSet = true;
          stow->offsetLabel->setMatrix(osg::Matrixd::translate(p.getPoint(TopoDS::Face(rs))));
        }
      }
    }

    if (closingFaceShapes.empty())
      throw std::runtime_error("no closing faces");
    
    BRepOffsetAPI_MakeThickSolid operation;
    operation.MakeThickSolidByJoin
    (
      tss.getRootOCCTShape(),
      occt::ShapeVectorCast(closingFaceShapes),
      -stow->offset.getDouble(), //default direction sucks.
      Precision::Confusion(),
      BRepOffset_Skin,
      Standard_False,
      Standard_False,
      GeomAbs_Intersection,
      Standard_True
    );
    operation.Check();
    
    TopoDS_Shape workShape = operation.Shape();
    ShapeCheck check(workShape);
    if (!check.isValid())
      throw std::runtime_error("shapeCheck failed in hollow feature");
    if (!occt::tightenTolerance(workShape))
      throw std::runtime_error("tighten tolerances failed");
    
    stow->sShape.setOCCTShape(workShape, getId());
    stow->sShape.shapeMatch(tss);
    stow->sShape.uniqueTypeMatch(tss);
    stow->sShape.modifiedMatch(operation, tss);
    stow->generatedMatch(operation, tss);
    stow->sShape.outerWireMatch(tss);
    stow->sShape.derivedMatch();
    stow->sShape.dumpNils("hollow feature");
    stow->sShape.dumpDuplicates("hollow feature");
    stow->sShape.ensureNoNils();
    stow->sShape.ensureNoDuplicates();
    stow->sShape.ensureEvolve();
    
    setSuccess();
  }
  catch (const Standard_Failure &e)
  {
    std::ostringstream s; s << "OCC Error in hollow update: " << e.GetMessageString() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (const std::exception &e)
  {
    std::ostringstream s; s << "Standard error in hollow update: " << e.what() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (...)
  {
    std::ostringstream s; s << "Unknown error in hollow update." << std::endl;
    lastUpdateLog += s.str();
  }
  setModelClean();
  if (!lastUpdateLog.empty())
    std::cout << std::endl << lastUpdateLog;
}

void Feature::serialWrite(const boost::filesystem::path &dIn)
{
  using prj::srl::hlls::Hollow;
  
  Hollow hollowOut
  (
    Base::serialOut(),
    stow->offset.serialOut(),
    stow->picks.serialOut(),
    stow->sShape.serialOut(),
    stow->offsetLabel->serialOut()
  );

  for (const auto &p : stow->shapeMap)
    hollowOut.shapeMap().push_back(Hollow::ShapeMapType(gu::idToString(p.first), gu::idToString(p.second)));
  
  xml_schema::NamespaceInfomap infoMap;
  std::ofstream stream(buildFilePathName(dIn).string());
  prj::srl::hlls::hollow(stream, hollowOut, infoMap);
}

void Feature::serialRead(const prj::srl::hlls::Hollow &sHollowIn)
{
  Base::serialIn(sHollowIn.base());
  stow->offset.serialIn(sHollowIn.offset());
  stow->picks.serialIn(sHollowIn.picks());
  stow->sShape.serialIn(sHollowIn.seerShape());
  stow->offsetLabel->serialIn(sHollowIn.offsetLabel());
  for (const auto &p : sHollowIn.shapeMap())
    stow->shapeMap.insert(std::make_pair(gu::stringToId(p.idIn()), gu::stringToId(p.idOut())));
}
