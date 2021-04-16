/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2019 Thomas S. Anderson blobfish.at.gmx.com
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

#include <osg/Switch>

#include <TopoDS.hxx>
#include <BRep_Tool.hxx>
#include <GeomAPI_Interpolate.hxx>
#include <BRepAdaptor_Curve.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <Precision.hxx>
#include <TopExp.hxx>

#include "globalutilities.h"
#include "annex/annseershape.h"
#include "library/lbrplabel.h"
#include "parameter/prmparameter.h"
#include "tools/occtools.h"
#include "tools/featuretools.h"
#include "tools/idtools.h"
#include "feature/ftrshapecheck.h"
#include "feature/ftrupdatepayload.h"
#include "feature/ftrinputtype.h"
#include "project/serial/generated/prjsrltscstransitioncurve.h"
#include "feature/ftrtransitioncurve.h"

using namespace ftr;
using boost::uuids::uuid;

QIcon TransitionCurve::icon;

TransitionCurve::TransitionCurve():
Base()
, sShape(std::make_unique<ann::SeerShape>())
, pick0Direction(std::make_unique<prm::Parameter>(QObject::tr("Reversed"), false))
, pick1Direction(std::make_unique<prm::Parameter>(QObject::tr("Reversed"), false))
, pick0Magnitude(std::make_unique<prm::Parameter>(QObject::tr("Magnitude"), 1.0))
, pick1Magnitude(std::make_unique<prm::Parameter>(QObject::tr("Magnitude"), 1.0))
, directionLabel0(new lbr::PLabel(pick0Direction.get()))
, directionLabel1(new lbr::PLabel(pick1Direction.get()))
, magnitudeLabel0(new lbr::PLabel(pick0Magnitude.get()))
, magnitudeLabel1(new lbr::PLabel(pick1Magnitude.get()))
, curveId(gu::createRandomId())
, vertex0Id(gu::createRandomId())
, vertex1Id(gu::createRandomId())
{
  if (icon.isNull())
    icon = QIcon(":/resources/images/sketchBezeir.svg");
  
  name = QObject::tr("Transition Curve");
  mainSwitch->setUserValue<int>(gu::featureTypeAttributeTitle, static_cast<int>(getType()));
  
  pick0Direction->connectValue(std::bind(&TransitionCurve::setModelDirty, this));
  parameters.push_back(pick0Direction.get());
  pick1Direction->connectValue(std::bind(&TransitionCurve::setModelDirty, this));
  parameters.push_back(pick1Direction.get());
  pick0Magnitude->connectValue(std::bind(&TransitionCurve::setModelDirty, this));
  pick0Magnitude->setConstraint(prm::Constraint::buildNonZeroPositive());
  parameters.push_back(pick0Magnitude.get());
  pick1Magnitude->connectValue(std::bind(&TransitionCurve::setModelDirty, this));
  pick1Magnitude->setConstraint(prm::Constraint::buildNonZeroPositive());
  parameters.push_back(pick1Magnitude.get());
  
  annexes.insert(std::make_pair(ann::Type::SeerShape, sShape.get()));
  
  overlaySwitch->addChild(directionLabel0.get());
  overlaySwitch->addChild(directionLabel1.get());
  overlaySwitch->addChild(magnitudeLabel0.get());
  overlaySwitch->addChild(magnitudeLabel1.get());
}

TransitionCurve::~TransitionCurve(){}

void TransitionCurve::setPicks(const Picks &pIn)
{
  picks = pIn;
  setModelDirty();
}

void TransitionCurve::setDirection0(bool vIn)
{
  pick0Direction->setValue(vIn);
}

void TransitionCurve::setDirection1(bool vIn)
{
  pick1Direction->setValue(vIn);
}

/*! @brief Detects default direction for first pick
 * 
 * @param eIn is the edge used for detection
 * @details asserts that picks have been set. @see setPicks
 * 
 */
void TransitionCurve::gleanDirection0(const TopoDS_Edge &eIn)
{
  /* Note: StartPoint and EndPoint consider edge orientation. The
   * parameter driven selection types don't consider edge orientation.
   * see ftr::Pick
   */
  assert(picks.size() == 2);
  
  bool outValue = false;
  const Pick &p = picks.at(0);
  if (p.selectionType == slc::Type::StartPoint && eIn.Orientation() == TopAbs_FORWARD)
    outValue = !outValue;
  if (p.selectionType == slc::Type::EndPoint && eIn.Orientation() == TopAbs_REVERSED)
    outValue = !outValue;
  if (p.selectionType == slc::Type::NearestPoint || p.selectionType == slc::Type::QuadrantPoint)
  {
    if (p.u < 0.5)
      outValue = !outValue;
  }
  
  setDirection0(outValue);
}

/*! @brief Detects default direction for second pick
 * 
 * @param eIn is the edge used for detection
 * @details asserts that picks have been set. @see setPicks
 * 
 */
void TransitionCurve::gleanDirection1(const TopoDS_Edge &eIn)
{
  assert(picks.size() == 2);
  
  bool outValue = false;
  const Pick &p = picks.at(1);
  if (p.selectionType == slc::Type::StartPoint && eIn.Orientation() == TopAbs_REVERSED)
    outValue = !outValue;
  if (p.selectionType == slc::Type::EndPoint && eIn.Orientation() == TopAbs_FORWARD)
    outValue = !outValue;
  if (p.selectionType == slc::Type::NearestPoint || p.selectionType == slc::Type::QuadrantPoint)
  {
    if (p.u > 0.5)
      outValue = !outValue;
  }
  
  setDirection1(outValue);
}

void TransitionCurve::updateModel(const UpdatePayload &pIn)
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
    
    if (picks.size() != 2)
      throw std::runtime_error("wrong number of picks");
    tls::Resolver resolver(pIn);
    
    resolver.resolve(picks.front());
    auto rShapes0 = resolver.getShapes(false);
    if (rShapes0.empty())
      throw std::runtime_error("invalid first pick resolution");
    if (rShapes0.front().ShapeType() != TopAbs_EDGE)
      throw std::runtime_error("invalid first pick resolution shape type");
    const TopoDS_Edge &edge0 = TopoDS::Edge(rShapes0.front());
    BRepAdaptor_Curve adapt0(edge0);
    auto rPoints0 = resolver.getPoints();
    if (rPoints0.empty())
      throw std::runtime_error("invalid first point resolution");
    gp_Pnt p0 = gu::toOcc(rPoints0.front()).XYZ();
    
    resolver.resolve(picks.back());
    auto rShapes1 = resolver.getShapes(false);
    if (rShapes1.empty())
      throw std::runtime_error("invalid second pick resolution");
    if (rShapes1.front().ShapeType() != TopAbs_EDGE)
      throw std::runtime_error("invalid second pick resolution shape type");
    const TopoDS_Edge &edge1 = TopoDS::Edge(rShapes1.front());
    BRepAdaptor_Curve adapt1(edge1);
    auto rPoints1 = resolver.getPoints();
    if (rPoints1.empty())
      throw std::runtime_error("invalid second point resolution");
    gp_Pnt p1 = gu::toOcc(rPoints1.front()).XYZ();
    
    double prm0, prm1;
    bool result;
    std::tie(prm0, result) = occt::pointToParameter(edge0, p0);
    if (!result)
      throw std::runtime_error("couldn't get parameter for p0");
    std::tie(prm1, result) = occt::pointToParameter(edge1, p1);
    if (!result)
      throw std::runtime_error("couldn't get parameter for p1");
    
    gp_Vec v0 = adapt0.DN(prm0, 1);
    gp_Vec v1 = adapt1.DN(prm1, 1);
    
    p0.Transform(adapt0.Trsf());
    v0.Transform(adapt0.Trsf());
    p1.Transform(adapt1.Trsf());
    v1.Transform(adapt1.Trsf());
    
    if (pick0Direction->getBool())
      v0.Reverse();
    if (pick1Direction->getBool())
      v1.Reverse();
    
    v0 *= pick0Magnitude->getDouble();
    v1 *= pick1Magnitude->getDouble();
    
    directionLabel0->setMatrix(osg::Matrixd::translate(gu::toOsg(p0)));
    directionLabel1->setMatrix(osg::Matrixd::translate(gu::toOsg(p1)));
    magnitudeLabel0->setMatrix(osg::Matrixd::translate(gu::toOsg(p0) + gu::toOsg(v0) * pick0Magnitude->getDouble()));
    magnitudeLabel1->setMatrix(osg::Matrixd::translate(gu::toOsg(p1) + gu::toOsg(v1) * pick1Magnitude->getDouble()));
    
    opencascade::handle<TColgp_HArray1OfPnt> points = new TColgp_HArray1OfPnt(1,2);
    points->SetValue(1, p0);
    points->SetValue(2, p1);
    
    GeomAPI_Interpolate trans(points, Standard_False, Precision::Confusion());
    trans.Load(v0, v1, Standard_False);
    trans.Perform();
    if (!trans.IsDone())
      throw std::runtime_error("Perform failed");
    
    BRepBuilderAPI_MakeEdge edgeMaker(trans.Curve());
    if (!edgeMaker.IsDone())
      throw std::runtime_error("edgeMaker failed");
    
    sShape->setOCCTShape(edgeMaker.Edge(), getId());
    sShape->updateId(edgeMaker.Edge(), curveId);
    if (!sShape->hasEvolveRecordOut(curveId))
      sShape->insertEvolve(gu::createNilId(), curveId);
    
    TopoDS_Vertex vertex0 = TopExp::FirstVertex(edgeMaker.Edge(), Standard_True);
    assert(sShape->hasShape(vertex0));
    sShape->updateId(vertex0, vertex0Id);
    if (!sShape->hasEvolveRecordOut(vertex0Id))
      sShape->insertEvolve(gu::createNilId(), vertex0Id);
    
    TopoDS_Vertex vertex1 = TopExp::LastVertex(edgeMaker.Edge(), Standard_True);
    assert(sShape->hasShape(vertex1));
    sShape->updateId(vertex1, vertex1Id);
    if (!sShape->hasEvolveRecordOut(vertex1Id))
      sShape->insertEvolve(gu::createNilId(), vertex1Id);
    
    sShape->ensureNoNils();
    sShape->ensureNoDuplicates();
    setSuccess();
  }
  catch (const Standard_Failure &e)
  {
    std::ostringstream s; s << "OCC Error in " << getTypeString() << " update: " << e.GetMessageString() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (const std::exception &e)
  {
    std::ostringstream s; s << "Standard error in " << getTypeString() << " update: " << e.what() << std::endl;
    lastUpdateLog += s.str();
  }
  catch (...)
  {
    std::ostringstream s; s << "Unknown error in " << getTypeString() << " update." << std::endl;
    lastUpdateLog += s.str();
  }
  setModelClean();
  if (!lastUpdateLog.empty())
    std::cout << std::endl << lastUpdateLog;
}

void TransitionCurve::serialWrite(const boost::filesystem::path &dIn)
{
  prj::srl::tscs::TransitionCurve so
  (
    Base::serialOut()
    , sShape->serialOut()
    , pick0Direction->serialOut()
    , pick1Direction->serialOut()
    , pick0Magnitude->serialOut()
    , pick1Magnitude->serialOut()
    , directionLabel0->serialOut()
    , directionLabel1->serialOut()
    , magnitudeLabel0->serialOut()
    , magnitudeLabel1->serialOut()
    , gu::idToString(curveId)
    , gu::idToString(vertex0Id)
    , gu::idToString(vertex1Id)
  );
  for (const auto &p : picks)
    so.picks().push_back(p);
  
  xml_schema::NamespaceInfomap infoMap;
  std::ofstream stream(buildFilePathName(dIn).string());
  prj::srl::tscs::transitionCurve(stream, so, infoMap);
}

void TransitionCurve::serialRead(const prj::srl::tscs::TransitionCurve &so)
{
  Base::serialIn(so.base());
  sShape->serialIn(so.seerShape());
  pick0Direction->serialIn(so.pick0Direction());
  pick1Direction->serialIn(so.pick1Direction());
  pick0Magnitude->serialIn(so.pick0Magnitude());
  pick1Magnitude->serialIn(so.pick1Magnitude());
  directionLabel0->serialIn(so.directionLabel0());
  directionLabel1->serialIn(so.directionLabel1());
  magnitudeLabel0->serialIn(so.magnitudeLabel0());
  magnitudeLabel1->serialIn(so.magnitudeLabel1());
  curveId = gu::stringToId(so.curveId());
  vertex0Id = gu::stringToId(so.vertex0Id());
  vertex1Id = gu::stringToId(so.vertex1Id());
  for (const auto &p : so.picks())
    picks.emplace_back(p);
}
