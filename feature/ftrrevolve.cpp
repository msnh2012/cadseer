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

#include <boost/filesystem/path.hpp>
#include <boost/optional/optional.hpp>

#include <osg/Switch>

#include <TopoDS.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>

#include "globalutilities.h"
#include "tools/occtools.h"
#include "library/lbrplabel.h"
#include "annex/annseershape.h"
#include "feature/ftrshapecheck.h"
#include "parameter/prmparameter.h"
#include "feature/ftrupdatepayload.h"
#include "feature/ftrinputtype.h"
#include "feature/ftrdatumaxis.h"
#include "tools/featuretools.h"
#include "tools/idtools.h"
#include "project/serial/xsdcxxoutput/featurerevolve.h"
#include "feature/ftrrevolve.h"

using namespace ftr;
using boost::uuids::uuid;

QIcon Revolve::icon;

Revolve::Revolve():
Base()
, sShape(new ann::SeerShape())
, axisOrigin(new prm::Parameter(QObject::tr("Axis Origin"), osg::Vec3d(0.0, 0.0, 0.0)))
, axisDirection(new prm::Parameter(QObject::tr("Axis Direction"), osg::Vec3d(0.0, 1.0, 0.0)))
, angle(new prm::Parameter(prm::Names::Angle, 360.0))
, axisOriginLabel(new lbr::PLabel(axisOrigin.get()))
, axisDirectionLabel(new lbr::PLabel(axisDirection.get()))
, angleLabel(new lbr::PLabel(angle.get()))
, internalSwitch(new osg::Switch())
{
  if (icon.isNull())
    icon = QIcon(":/resources/images/constructionRevolve.svg");
  
  name = QObject::tr("Revolve");
  mainSwitch->setUserValue<int>(gu::featureTypeAttributeTitle, static_cast<int>(getType()));
  
  axisOrigin->connectValue(std::bind(&Revolve::setModelDirty, this));
  parameters.push_back(axisOrigin.get());
  
  axisDirection->connectValue(std::bind(&Revolve::setModelDirty, this));
  parameters.push_back(axisDirection.get());
  
  angle->setConstraint(prm::Constraint::buildNonZeroAngle());
  angle->connectValue(std::bind(&Revolve::setModelDirty, this));
  parameters.push_back(angle.get());
  
  auto labelInit = [&](lbr::PLabel *pl)
  {
    pl->showName = true;
    pl->valueHasChanged();
    pl->constantHasChanged();
    internalSwitch->addChild(pl);
  };
  labelInit(axisOriginLabel);
  labelInit(axisDirectionLabel);
  labelInit(angleLabel);
  
  overlaySwitch->addChild(internalSwitch.get());
  
  annexes.insert(std::make_pair(ann::Type::SeerShape, sShape.get()));
}

Revolve::~Revolve(){}

void Revolve::setPicks(const Picks &pIn)
{
  picks = pIn;
  setModelDirty();
}

void Revolve::setAxisPicks(const Picks &pIn)
{
  axisPicks = pIn;
  setAxisType(AxisType::Picks);
}

void Revolve::setAxisType(AxisType ai)
{
  axisType = ai;
  setModelDirty();
  updateLabelVisibility();
}

void Revolve::updateLabelVisibility()
{
  if (axisType == AxisType::Picks)
  {
    internalSwitch->setChildValue(axisOriginLabel.get(), false);
    internalSwitch->setChildValue(axisDirectionLabel.get(), false);
  }
  else
  {
    internalSwitch->setChildValue(axisOriginLabel.get(), true);
    internalSwitch->setChildValue(axisDirectionLabel.get(), true);
  }
}

void Revolve::updateLabels(occt::BoundingBox &bb)
{
  updateLabelVisibility();
  
  axisOriginLabel->setMatrix(osg::Matrixd::translate(static_cast<osg::Vec3d>(*axisOrigin)));
  axisDirectionLabel->setMatrix(osg::Matrixd::translate(static_cast<osg::Vec3d>(*axisDirection)));
  angleLabel->setMatrix(osg::Matrixd::translate(gu::toOsg(bb.getCenter())));
}

void Revolve::updateModel(const UpdatePayload &pIn)
{
  setFailure();
  lastUpdateLog.clear();
  sShape->reset();
  try
  {
    if (isSkipped())
    {
      setSuccess();
      throw std::runtime_error("feature is skipped");
    }
    
    if (picks.size() != 1) //only 1 for now.
      throw std::runtime_error("wrong number of target picks.");
    tls::Resolver tResolver(pIn);
    tResolver.resolve(picks.front());
    if (!tResolver.getFeature() || !tResolver.getSeerShape() || tResolver.getShapes().empty())
      throw std::runtime_error("target resolution failed.");
    
    occt::ShapeVector str; //shapes to revolve
    if (slc::isObjectType(picks.front().selectionType))
    {
      //treat sketches special
      if (tResolver.getFeature()->getType() == Type::Sketch)
      {
        occt::ShapeVectorCast cast(TopoDS::Compound(tResolver.getSeerShape()->getRootOCCTShape()));
        occt::WireVector wv = static_cast<occt::WireVector>(cast);
        if (wv.empty())
          throw std::runtime_error("No wires found in sketch");
        TopoDS_Face ftr = occt::buildFace(wv);
        if (ftr.IsNull())
          throw std::runtime_error("Face construction for sketch failed");
        ShapeCheck fc(ftr);
        if (!fc.isValid())
          throw std::runtime_error("Face check failed");
        str.push_back(ftr);
      }
      else //not a sketch
      {
        occt::ShapeVector shapes = tResolver.getSeerShape()->useGetNonCompoundChildren();
        for (const auto &s : shapes)
        {
          TopAbs_ShapeEnum t = s.ShapeType();
          if
          (
            t == TopAbs_SHELL
            || t == TopAbs_FACE
            || t == TopAbs_WIRE
            || t == TopAbs_EDGE
            || t == TopAbs_VERTEX
          )
          str.push_back(s);
        }
      }
    }
    else
    {
      str = tResolver.getShapes();
    }
    
    if (str.empty())
      throw std::runtime_error("Nothing to revolve");
    occt::BoundingBox bb;
    bb.add(str);
    
    if (axisType == AxisType::Picks)
    {
      if (axisPicks.empty() || axisPicks.size() > 2)
        throw std::runtime_error("Wrong number of axis picks");
      tls::Resolver aResolver(pIn);
      if (axisPicks.size() == 1)
      {
        aResolver.resolve(axisPicks.front());
        if (!aResolver.getFeature())
          throw std::runtime_error("Unable to resolve single axis pick");
        if (slc::isObjectType(axisPicks.front().selectionType))
        {
          if (aResolver.getFeature()->getType() != Type::DatumAxis)
            throw std::runtime_error("Wrong feature type for single axis pick");
          const DatumAxis *da = dynamic_cast<const DatumAxis*>(aResolver.getFeature());
          assert(da);
          axisOrigin->setValueQuiet(da->getOrigin());
          axisDirection->setValueQuiet(da->getDirection());
        }
        else
        {
          if (!aResolver.getSeerShape())
            throw std::runtime_error("No seer shape for single axis pick");
          auto rShapes = aResolver.getShapes();
          if (rShapes.empty())
            throw std::runtime_error("No resolved shapes from single axis pick");
          if (rShapes.size() > 1)
          {
            std::ostringstream s; s << "WARNING: Multiple resolve shapes from single axis pick " << std::endl;
            lastUpdateLog += s.str();
          }
          auto glean = occt::gleanAxis(rShapes.front());
          if (!glean.second)
            throw std::runtime_error("Couldn't glean axis from single axis pick");
          axisOrigin->setValueQuiet(gu::toOsg(glean.first.Location()));
          axisDirection->setValueQuiet(gu::toOsg(glean.first.Direction()));
        }
      }
      else //axisPicks size == 2
      {
        if (!slc::isPointType(axisPicks.front().selectionType) || !slc::isPointType(axisPicks.back().selectionType))
          throw std::runtime_error("Wrong type for 2 pick axis");
        aResolver.resolve(axisPicks.front());
        auto points0 = aResolver.getPoints();
        aResolver.resolve(axisPicks.back());
        auto points1 = aResolver.getPoints();
        if (points0.empty() || points1.empty())
          throw std::runtime_error("Failed to resolve 2 axis pick points");
        if (points0.size() > 1 || points1.size() > 1)
        {
          std::ostringstream s; s << "WARNING: More than 1 shape resolved for 2 pick axis." << std::endl;
          lastUpdateLog += s.str();
        }
        osg::Vec3d tAxis = points0.front() - points1.front();
        tAxis.normalize();
        axisOrigin->setValueQuiet(points1.front());
        axisDirection->setValueQuiet(tAxis);
      }
    }
    
    TopoDS_Compound strc = static_cast<TopoDS_Compound>(occt::ShapeVectorCast(str));
    gp_Ax1 axis
    (
      gp_Pnt(gu::toOcc(static_cast<osg::Vec3d>(*axisOrigin)).XYZ()),
      gp_Dir(gu::toOcc(static_cast<osg::Vec3d>(*axisDirection)))
    );
    double la = static_cast<double>(*angle);
    BRepPrimAPI_MakeRevol revolver(strc, axis, osg::DegreesToRadians(la));
    revolver.Check(); //throw occ exception if failed
    
    sShape->setOCCTShape(revolver.Shape(), getId());
    sShape->shapeMatch(*tResolver.getSeerShape());
    
    int count = -1;
    for (const auto &s : occt::mapShapes(strc))
    {
      count++;
      if (!tResolver.getSeerShape()->hasShape(s))
        continue; //skip at least the generated compound.
      uuid oldId = tResolver.getSeerShape()->findId(s);
      
      //because we don't move the original shapes we use SeerShape::shapeMatch
      //and we can ignore id mapping for the original shapes.
      
      //this is for the 'transition' shapes and uses generated map.
      //transition from FirstShapes to LastShapes.
      //I am getting a wire that generates a shell but the shell is not in the shape. bug?
      const TopTools_ListOfShape &generated = revolver.Generated(s);
      if (!generated.IsEmpty() && sShape->hasShape(generated.First()))
      {
        uuid gId = gu::createRandomId();
        auto gIt = generatedMap.find(oldId);
        if (gIt == generatedMap.end())
          generatedMap.insert(std::make_pair(oldId, gId));
        else
          gId = gIt->second;
        sShape->updateId(generated.First(), gId);
        if (!sShape->hasEvolveRecord(gu::createNilId(), gId))
        {
          assert(!sShape->hasEvolveRecordOut(gId));
          sShape->insertEvolve(gu::createNilId(), gId);
        }
        if (generated.Extent() > 1)
          std::cout << "Warning: more than 1 generated shape in revolve." << std::endl;
      }
      
      //this is for the new shapes at the top of the prism.
      //in BRepPrimAPI_MakePrism terminology these are 'LastShape'
      const TopoDS_Shape &last = revolver.LastShape(s);
      if (!last.IsNull() && sShape->hasShape(last))
      {
        uuid lId = gu::createRandomId();
        auto lIt = lastMap.find(oldId);
        if (lIt == lastMap.end())
          lastMap.insert(std::make_pair(oldId, lId));
        else
          lId = lIt->second;
        sShape->updateId(last, lId);
        if (!sShape->hasEvolveRecord(gu::createNilId(), lId))
        {
          assert(!sShape->hasEvolveRecordOut(lId));
          sShape->insertEvolve(gu::createNilId(), lId);
        }
      }
    }
    
    sShape->outerWireMatch(*tResolver.getSeerShape());
    
    //this should assign ids to nil outerwires based upon parent face id.
    occt::ShapeVector ns = sShape->getAllNilShapes();
    for (const auto &s : ns)
    {
      if (s.ShapeType() != TopAbs_WIRE)
        continue;
      occt::ShapeVector ps = sShape->useGetParentsOfType(s, TopAbs_FACE);
      if (ps.empty())
        continue;
      uuid fId = sShape->findId(ps.front());
      if (fId.is_nil())
        continue;
      uuid wId = gu::createRandomId();
      auto it = oWireMap.find(fId);
      if (it == oWireMap.end())
        oWireMap.insert(std::make_pair(fId, wId));
      else
        wId = it->second;
      sShape->updateId(s, wId);
      if (!sShape->hasEvolveRecord(gu::createNilId(), wId))
      {
        assert(!sShape->hasEvolveRecordOut(wId));
        sShape->insertEvolve(gu::createNilId(), wId);
      }
    }
    
    sShape->derivedMatch();
    sShape->uniqueTypeMatch(*tResolver.getSeerShape());
    sShape->dumpNils("revolve feature");
    sShape->dumpDuplicates("revolve feature");
    sShape->ensureNoNils();
    sShape->ensureNoDuplicates();
    
    updateLabels(bb);
    setSuccess();
  }
  catch (const Standard_Failure &e)
  {
    std::ostringstream s; s << "OCC Error in revolve update: " << e.GetMessageString() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (const std::exception &e)
  {
    std::ostringstream s; s << "Standard error in revolve update: " << e.what() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (...)
  {
    std::ostringstream s; s << "Unknown error in revolve update. " << std::endl;
    lastUpdateLog += s.str();
  }
  setModelClean();
  if (!lastUpdateLog.empty())
    std::cout << std::endl << lastUpdateLog;
}

void Revolve::serialWrite(const boost::filesystem::path &dIn)
{
  auto serializeMap = [](const std::map<uuid, uuid> &map) -> prj::srl::EvolveContainer
  {
    prj::srl::EvolveContainer out;
    for (const auto &p : map)
    {
      prj::srl::EvolveRecord r
      (
        gu::idToString(p.first),
        gu::idToString(p.second)
      );
      out.evolveRecord().push_back(r);
    }
    return out;
  };
  
  prj::srl::FeatureRevolve so
  (
    Base::serialOut(),
    ftr::serialOut(picks),
    ftr::serialOut(axisPicks),
    axisOrigin->serialOut(),
    axisOriginLabel->serialOut(),
    axisDirection->serialOut(),
    axisDirectionLabel->serialOut(),
    angle->serialOut(),
    angleLabel->serialOut(),
    static_cast<int>(axisType),
    serializeMap(generatedMap),
    serializeMap(lastMap),
    serializeMap(oWireMap)
  );
  
  xml_schema::NamespaceInfomap infoMap;
  std::ofstream stream(buildFilePathName(dIn).string());
  prj::srl::revolve(stream, so, infoMap);
}

void Revolve::serialRead(const prj::srl::FeatureRevolve &so)
{
  auto serializeMap = [](const prj::srl::EvolveContainer &container) -> std::map<uuid, uuid>
  {
    std::map<uuid, uuid> out;
    for (const auto &r : container.evolveRecord())
      out.insert(std::make_pair(gu::stringToId(r.idIn()), gu::stringToId(r.idOut())));
    return out;
  };
  
  Base::serialIn(so.featureBase());
  picks = ftr::serialIn(so.picks());
  axisPicks = ftr::serialIn(so.axisPicks());
  axisOrigin->serialIn(so.axisOrigin());
  axisOriginLabel->serialIn(so.axisOriginLabel());
  axisDirection->serialIn(so.axisDirection());
  axisDirectionLabel->serialIn(so.axisDirectionLabel());
  angle->serialIn(so.angle());
  angleLabel->serialIn(so.angleLabel());
  axisType = static_cast<AxisType>(so.axisType());
  generatedMap = serializeMap(so.generatedMap());
  lastMap = serializeMap(so.lastMap());
  oWireMap = serializeMap(so.oWireMap());
  
  axisOriginLabel->valueHasChanged();
  axisOriginLabel->constantHasChanged();
  axisDirectionLabel->valueHasChanged();
  axisDirectionLabel->constantHasChanged();
  angleLabel->valueHasChanged();
  angleLabel->constantHasChanged();
  updateLabelVisibility();
}
