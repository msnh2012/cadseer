/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2016  Thomas S. Anderson blobfish.at.gmx.com
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

#include <BRepFilletAPI_MakeChamfer.hxx>
#include <TopExp.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <BRepTools.hxx>
#include <BRep_Tool.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepExtrema_DistShapeShape.hxx>
#include <Geom_Curve.hxx>

#include <osg/Switch>

#include "globalutilities.h"
#include "tools/idtools.h"
#include "preferences/preferencesXML.h"
#include "preferences/prfmanager.h"
#include "project/serial/xsdcxxoutput/featurechamfer.h"
#include "annex/annseershape.h"
#include "feature/ftrshapecheck.h"
#include "feature/ftrinputtype.h"
#include "feature/ftrupdatepayload.h"
#include "parameter/prmparameter.h"
#include "tools/featuretools.h"
#include "feature/ftrchamfer.h"

using namespace ftr;
using boost::uuids::uuid;

QIcon Chamfer::icon;

boost::uuids::uuid Chamfer::referenceFaceId(const ann::SeerShape &seerShapeIn, const boost::uuids::uuid &edgeIdIn)
{
  assert(seerShapeIn.hasId(edgeIdIn));
  TopoDS_Shape edgeShape = seerShapeIn.findShape(edgeIdIn);
  assert(edgeShape.ShapeType() == TopAbs_EDGE);
  
  std::vector<boost::uuids::uuid> faceIds = seerShapeIn.useGetParentsOfType(edgeIdIn, TopAbs_FACE);
  assert(!faceIds.empty());
  return faceIds.front();
}

std::shared_ptr< prm::Parameter > Chamfer::buildSymParameter()
{
  std::shared_ptr<prm::Parameter> out(new prm::Parameter(prm::Names::Distance, prf::manager().rootPtr->features().chamfer().get().distance()));
  out->setConstraint(prm::Constraint::buildNonZeroPositive());
  return out;
}

Chamfer::Chamfer() : Base(), sShape(new ann::SeerShape())
{
  if (icon.isNull())
    icon = QIcon(":/resources/images/constructionChamfer.svg");
  
  name = QObject::tr("Chamfer");
  mainSwitch->setUserValue<int>(gu::featureTypeAttributeTitle, static_cast<int>(getType()));
  
  annexes.insert(std::make_pair(ann::Type::SeerShape, sShape.get()));
}

Chamfer::~Chamfer(){}

void Chamfer::addSymChamfer(const SymChamfer &chamferIn)
{
  symChamfers.push_back(chamferIn);
  
  if (!symChamfers.back().distance)
    symChamfers.back().distance = buildSymParameter();
  symChamfers.back().distance->connectValue(std::bind(&Chamfer::setModelDirty, this));
  
  if (!symChamfers.back().label)
  {
    symChamfers.back().label = new lbr::PLabel(symChamfers.back().distance.get());
    symChamfers.back().label->showName = true;
  }
  symChamfers.back().label->valueHasChanged();
  symChamfers.back().label->constantHasChanged();
  overlaySwitch->addChild(symChamfers.back().label.get());
}

void Chamfer::updateModel(const UpdatePayload &payloadIn)
{
  setFailure();
  lastUpdateLog.clear();
  sShape->reset();
  try
  {
    std::vector<const Base*> targetFeatures = payloadIn.getFeatures(InputType::target);
    if (targetFeatures.size() != 1)
      throw std::runtime_error("wrong number of parents");
    const Base* tf = targetFeatures.front();
    if (!tf->hasAnnex(ann::Type::SeerShape))
      throw std::runtime_error("parent doesn't have seer shape");
    const ann::SeerShape &targetSeerShape = tf->getAnnex<ann::SeerShape>(ann::Type::SeerShape);
    if (targetSeerShape.isNull())
      throw std::runtime_error("target seer shape is null");
    
    //setup failure state.
    sShape->setOCCTShape(targetSeerShape.getRootOCCTShape());
    sShape->shapeMatch(targetSeerShape);
    sShape->uniqueTypeMatch(targetSeerShape);
    sShape->outerWireMatch(targetSeerShape);
    sShape->derivedMatch();
    sShape->ensureNoNils();
    sShape->ensureNoDuplicates();
    
    if (isSkipped())
    {
      setSuccess();
      throw std::runtime_error("feature is skipped");
    }
    
    BRepFilletAPI_MakeChamfer chamferMaker(targetSeerShape.getRootOCCTShape());
    for (const auto &chamfer : symChamfers)
    {
      assert(chamfer.distance);
      bool labelDone = false; //set label position to first pick.
      for (const auto &pick : chamfer.picks)
      {
        auto resolvedEdgePicks = tls::resolvePicks(tf, pick.edgePick, payloadIn.shapeHistory);
        std::vector<uuid> edgeIds;
        for (const auto &resolved : resolvedEdgePicks)
        {
          if (resolved.resultId.is_nil())
            continue;
          edgeIds.push_back(resolved.resultId);
        }
        
        auto resolvedFacePicks = tls::resolvePicks(tf, pick.facePick, payloadIn.shapeHistory);
        std::vector<uuid> faceIds;
        for (const auto &resolved : resolvedFacePicks)
        {
          if (resolved.resultId.is_nil())
            continue;
          faceIds.push_back(resolved.resultId);
        }
        
        for (const auto &eid : edgeIds)
        {
          uuid faceId = gu::createNilId();
          std::vector<uuid> parentFaces = targetSeerShape.useGetParentsOfType(eid, TopAbs_FACE);
          if (parentFaces.empty())
            throw std::runtime_error("no parent faces of edge");
          std::vector<uuid> intersectionSet;
          std::set_intersection(faceIds.begin(), faceIds.end(), parentFaces.begin(), parentFaces.end(), std::back_inserter(intersectionSet));
          if (intersectionSet.empty())
            faceId = parentFaces.front();
          else
            faceId = intersectionSet.front();
          if (intersectionSet.size() > 1)
            std::cerr << "WARNING: more than 1 reference face in Chamfer::updateModel" << std::endl;
          
          assert(targetSeerShape.hasId(eid));
          assert(targetSeerShape.hasId(faceId));
          
          updateShapeMap(eid, pick.edgePick.shapeHistory);
          updateShapeMap(faceId, pick.facePick.shapeHistory);
          TopoDS_Edge edge = TopoDS::Edge(targetSeerShape.findShape(eid));
          TopoDS_Face face = TopoDS::Face(targetSeerShape.findShape(faceId));
          chamferMaker.Add(static_cast<double>(*(chamfer.distance)), edge, face);
          //update location of parameter label.
          if (!labelDone)
          {
            labelDone = true;
            chamfer.label->setMatrix(osg::Matrixd::translate(pick.edgePick.getPoint(TopoDS::Edge(edge))));
          }
        }
      }
    }
    chamferMaker.Build();
    if (!chamferMaker.IsDone())
      throw std::runtime_error("chamferMaker failed");
    ShapeCheck check(chamferMaker.Shape());
    if (!check.isValid())
      throw std::runtime_error("shapeCheck failed");

    sShape->setOCCTShape(chamferMaker.Shape());
    sShape->shapeMatch(targetSeerShape);
    sShape->uniqueTypeMatch(targetSeerShape);
    sShape->modifiedMatch(chamferMaker, targetSeerShape);
    generatedMatch(chamferMaker, targetSeerShape);
    sShape->outerWireMatch(targetSeerShape);
    sShape->derivedMatch();
    sShape->dumpNils("chamfer feature"); //only if there are shapes with nil ids.
    sShape->dumpDuplicates("chamfer feature");
    sShape->ensureNoNils();
    sShape->ensureNoDuplicates();
    
    setSuccess();
  }
  catch (const Standard_Failure &e)
  {
    std::ostringstream s; s << "OCC Error in chamfer update: " << e.GetMessageString() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (const std::exception &e)
  {
    std::ostringstream s; s << "Standard error in chamfer update: " << e.what() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (...)
  {
    std::ostringstream s; s << "Unknown error in chamfer update." << std::endl;
    lastUpdateLog += s.str();
  }
  setModelClean();
  if (!lastUpdateLog.empty())
    std::cout << std::endl << lastUpdateLog;
}

//duplicated with blend.
void Chamfer::generatedMatch(BRepFilletAPI_MakeChamfer &chamferMakerIn, const ann::SeerShape &targetShapeIn)
{
  using boost::uuids::uuid;
  
  std::vector<uuid> targetShapeIds = targetShapeIn.getAllShapeIds();
  
  for (const auto &cId : targetShapeIds)
  {
    const TopoDS_Shape &currentShape = targetShapeIn.findShape(cId);
    TopTools_ListOfShape generated = chamferMakerIn.Generated(currentShape);
    if (generated.IsEmpty())
      continue;
    if(generated.Extent() != 1)
    {
      std::ostringstream s; s << "Warning: more than one generated shape in chamfer::generatedMatch" << std::endl;
      lastUpdateLog += s.str();
    }
    const TopoDS_Shape &chamferFace = generated.First();
    assert(!chamferFace.IsNull());
    assert(chamferFace.ShapeType() == TopAbs_FACE);
    
    std::map<uuid, uuid>::iterator mapItFace;
    bool dummy;
    std::tie(mapItFace, dummy) = shapeMap.insert(std::make_pair(cId, gu::createRandomId()));
    sShape->updateId(chamferFace, mapItFace->second);
    if (dummy) //insertion took place.
      sShape->insertEvolve(gu::createNilId(), mapItFace->second);
    
    //now look for outerwire for newly generated face.
    //we use the generated face id to map to outer wire.
    std::map<uuid, uuid>::iterator mapItWire;
    std::tie(mapItWire, dummy) = shapeMap.insert(std::make_pair(mapItFace->second, gu::createRandomId()));
    //now get the wire and update the result to id.
    const TopoDS_Shape &chamferedFaceWire = BRepTools::OuterWire(TopoDS::Face(chamferFace));
    sShape->updateId(chamferedFaceWire, mapItWire->second);
    if (dummy) //insertion took place.
      sShape->insertEvolve(gu::createNilId(), mapItWire->second);
  }
}

void Chamfer::updateShapeMap(const boost::uuids::uuid &resolvedId, const ShapeHistory &pick)
{
  for (const auto &historyId : pick.getAllIds())
  {
    assert(shapeMap.count(historyId) < 2);
    auto it = shapeMap.find(historyId);
    if (it == shapeMap.end())
      continue;
    auto entry = std::make_pair(resolvedId, it->second);
    shapeMap.erase(it);
    shapeMap.insert(entry);
  }
}

void Chamfer::serialWrite(const boost::filesystem::path &dIn)
{
  prj::srl::FeatureChamfer::ShapeMapType shapeMapOut;
  for (const auto &p : shapeMap)
  {
    prj::srl::EvolveRecord eRecord
    (
      gu::idToString(p.first),
      gu::idToString(p.second)
    );
    shapeMapOut.evolveRecord().push_back(eRecord);
  }
  
  prj::srl::SymChamfers sSymChamfersOut;
  for (const auto &sSymChamfer : symChamfers)
  {
    prj::srl::ChamferPicks cPicksOut;
    for (const auto &cPick : sSymChamfer.picks)
    {
      prj::srl::ChamferPick cPickOut
      (
        cPick.edgePick.serialOut(),
        cPick.facePick.serialOut()
      );
      cPicksOut.array().push_back(cPickOut);
    }
    prj::srl::SymChamfer sChamferOut
    (
      cPicksOut,
      sSymChamfer.distance->serialOut(),
      sSymChamfer.label->serialOut()
    );
    sSymChamfersOut.array().push_back(sChamferOut);
  }
  
  prj::srl::FeatureChamfer chamferOut
  (
    Base::serialOut(),
    shapeMapOut,
    sSymChamfersOut
  );
  
  xml_schema::NamespaceInfomap infoMap;
  std::ofstream stream(buildFilePathName(dIn).string());
  prj::srl::chamfer(stream, chamferOut, infoMap);
}

void Chamfer::serialRead(const prj::srl::FeatureChamfer &sChamferIn)
{
  Base::serialIn(sChamferIn.featureBase());
  
  shapeMap.clear();
  for (const prj::srl::EvolveRecord &sERecord : sChamferIn.shapeMap().evolveRecord())
  {
    std::pair<uuid, uuid> record;
    record.first = gu::stringToId(sERecord.idIn());
    record.second = gu::stringToId(sERecord.idOut());
    shapeMap.insert(record);
  }
  
  for (const auto &symChamferIn : sChamferIn.symChamfers().array())
  {
    SymChamfer symChamfer;
    for (const auto &cPickIn : symChamferIn.chamferPicks().array())
    {
      ChamferPick pick;
      pick.edgePick.serialIn(cPickIn.edgePick());
      pick.facePick.serialIn(cPickIn.facePick());
      symChamfer.picks.push_back(pick);
    }
    symChamfer.distance = buildSymParameter();
    symChamfer.distance->serialIn(symChamferIn.distance());
    symChamfer.label = new lbr::PLabel(symChamfer.distance.get());
    symChamfer.label->showName = true;
    symChamfer.label->serialIn(symChamferIn.plabel());
    addSymChamfer(symChamfer);
  }
}