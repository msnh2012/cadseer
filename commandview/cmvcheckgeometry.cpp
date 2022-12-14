/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2020 Thomas S. Anderson blobfish.at.gmx.com
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

#include <QSettings>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QHideEvent>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>

#include <BRepCheck_Analyzer.hxx>
#include <BOPAlgo_ArgumentAnalyzer.hxx>
#include <BRepBndLib.hxx>
#include <Bnd_Box.hxx>
#include <TopoDS.hxx>
#include <TopExp_Explorer.hxx>
#include <TopExp.hxx>
#include <BRep_Tool.hxx>
#include <BRepTools_ShapeSet.hxx>

#include <osg/PositionAttitudeTransform>
#include <osg/Geometry>
#include <osg/BlendFunc>
#include <osg/PolygonMode>
#include <osg/Switch>

#include "application/appapplication.h"
#include "project/prjproject.h"
#include "annex/annseershape.h"
#include "message/msgnode.h"
#include "message/msgsift.h"
#include "library/lbrspherebuilder.h"
#include "tools/idtools.h"
#include "tools/occtools.h"
#include "globalutilities.h"
#include "feature/ftrbase.h"
#include "command/cmdcheckgeometry.h"
#include "commandview/cmvcheckgeometry.h"

using boost::uuids::uuid;

namespace
{
  QString checkStatusToString(BRepCheck_Status status)
  {
    static const std::map<BRepCheck_Status, QString> names
    {
      std::make_pair(BRepCheck_NoError, QObject::tr("No Error")),
      std::make_pair(BRepCheck_InvalidPointOnCurve, QObject::tr("Invalid Point On Curve")),
      std::make_pair(BRepCheck_InvalidPointOnCurveOnSurface, QObject::tr("Invalid Point On Curve On Surface")),
      std::make_pair(BRepCheck_InvalidPointOnSurface, QObject::tr("Invalid Point On Surface")),
      std::make_pair(BRepCheck_No3DCurve, QObject::tr("No 3D Curve")),
      std::make_pair(BRepCheck_Multiple3DCurve, QObject::tr("Multiple 3D Curve")),
      std::make_pair(BRepCheck_Invalid3DCurve, QObject::tr("Invalid 3D Curve")),
      std::make_pair(BRepCheck_NoCurveOnSurface, QObject::tr("No Curve On Surface")),
      std::make_pair(BRepCheck_InvalidCurveOnSurface, QObject::tr("Invalid Curve On Surface")),
      std::make_pair(BRepCheck_InvalidCurveOnClosedSurface, QObject::tr("Invalid Curve On Closed Surface")),
      std::make_pair(BRepCheck_InvalidSameRangeFlag, QObject::tr("Invalid Same Range Flag")),
      std::make_pair(BRepCheck_InvalidSameParameterFlag, QObject::tr("Invalid Same Parameter Flag")),
      std::make_pair(BRepCheck_InvalidDegeneratedFlag, QObject::tr("Invalid Degenerated Flag")),
      std::make_pair(BRepCheck_FreeEdge, QObject::tr("Free Edge")),
      std::make_pair(BRepCheck_InvalidMultiConnexity, QObject::tr("Invalid MultiConnexity")),
      std::make_pair(BRepCheck_InvalidRange, QObject::tr("Invalid Range")),
      std::make_pair(BRepCheck_EmptyWire, QObject::tr("Empty Wire")),
      std::make_pair(BRepCheck_RedundantEdge, QObject::tr("Redundant Edge")),
      std::make_pair(BRepCheck_SelfIntersectingWire, QObject::tr("Self Intersecting Wire")),
      std::make_pair(BRepCheck_NoSurface, QObject::tr("No Surface")),
      std::make_pair(BRepCheck_InvalidWire, QObject::tr("Invalid Wire")),
      std::make_pair(BRepCheck_RedundantWire, QObject::tr("Redundant Wire")),
      std::make_pair(BRepCheck_IntersectingWires, QObject::tr("Intersecting Wires")),
      std::make_pair(BRepCheck_InvalidImbricationOfWires, QObject::tr("Invalid Imbrication Of Wires")),
      std::make_pair(BRepCheck_EmptyShell, QObject::tr("Empty Shell")),
      std::make_pair(BRepCheck_RedundantFace, QObject::tr("Redundant Face")),
      std::make_pair(BRepCheck_InvalidImbricationOfShells, QObject::tr("Invalid Imbrication Of Shells")),
      std::make_pair(BRepCheck_UnorientableShape, QObject::tr("Unorientable Shape")),
      std::make_pair(BRepCheck_NotClosed, QObject::tr("Not Closed")),
      std::make_pair(BRepCheck_NotConnected, QObject::tr("Not Connected")),
      std::make_pair(BRepCheck_SubshapeNotInShape, QObject::tr("Sub Shape Not In Shape")),
      std::make_pair(BRepCheck_BadOrientation, QObject::tr("Bad Orientation")),
      std::make_pair(BRepCheck_BadOrientationOfSubshape, QObject::tr("Bad Orientation Of Sub Shape")),
      std::make_pair(BRepCheck_InvalidPolygonOnTriangulation, QObject::tr("Invalid Polygon On Triangulation")),
      std::make_pair(BRepCheck_InvalidToleranceValue, QObject::tr("Invalid Tolerance Value")),
      std::make_pair(BRepCheck_EnclosedRegion, QObject::tr("Enclosed Region")),
      std::make_pair(BRepCheck_CheckFail, QObject::tr("Check Failed"))
    };
    
    if (names.count(status) == 0)
      return (QObject::tr("Out Of Enum Range"));
    else
      return names.at(status);
  }

  QString BOPCheckStatusToString(BOPAlgo_CheckStatus status)
  {
    static const QStringList results =
    {
      QObject::tr("BOPAlgo CheckUnknown"),                //BOPAlgo_CheckUnknown
      QObject::tr("BOPAlgo BadType"),                     //BOPAlgo_BadType
      QObject::tr("BOPAlgo SelfIntersect"),               //BOPAlgo_SelfIntersect
      QObject::tr("BOPAlgo TooSmallEdge"),                //BOPAlgo_TooSmallEdge
      QObject::tr("BOPAlgo NonRecoverableFace"),          //BOPAlgo_NonRecoverableFace
      QObject::tr("BOPAlgo IncompatibilityOfVertex"),     //BOPAlgo_IncompatibilityOfVertex
      QObject::tr("BOPAlgo IncompatibilityOfEdge"),       //BOPAlgo_IncompatibilityOfEdge
      QObject::tr("BOPAlgo IncompatibilityOfFace"),       //BOPAlgo_IncompatibilityOfFace
      QObject::tr("BOPAlgo OperationAborted"),            //BOPAlgo_OperationAborted
      QObject::tr("BOPAlgo GeomAbs_C0"),                  //BOPAlgo_GeomAbs_C0
      QObject::tr("BOPAlgo InvalidCurveOnSurface"),       //BOPAlgo_InvalidCurveOnSurface
      QObject::tr("BOPAlgo NotValid")                     //BOPAlgo_NotValid
    };
    
    return results.at(static_cast<int>(status));
  }

  osg::BoundingSphered calculateBoundingSphere(const TopoDS_Shape& shape)
  {
    osg::BoundingSphered out;
    
    Bnd_Box bBox;
    BRepBndLib::Add(shape, bBox);
    if (bBox.IsVoid())
      return out;
    
    osg::Vec3d point1 = gu::toOsg(bBox.CornerMin());
    osg::Vec3d point2 = gu::toOsg(bBox.CornerMax());
    osg::Vec3d diagonalVec = point2 - point1;
    out.radius() = diagonalVec.length() / 2.0;
    diagonalVec.normalize();
    diagonalVec *= out.radius();
    out.center() = point1 + diagonalVec;
    
    return out;
  }

  osg::PositionAttitudeTransform* buildBoundingSphere(const osg::BoundingSphered &bSphere)
  {
    osg::ref_ptr<osg::PositionAttitudeTransform> transform = new osg::PositionAttitudeTransform();
    transform->setPosition(bSphere.center());
    lbr::SphereBuilder builder;
    builder.setRadius(bSphere.radius());
    builder.setDeviation(0.25);
    osg::Geometry *geometry = builder;
    osg::Vec4Array *color = new osg::Vec4Array();
    color->push_back(osg::Vec4(1.0, 1.0, 0.0, 0.2));
    geometry->setColorArray(color);
    geometry->setColorBinding(osg::Geometry::BIND_OVERALL);
    geometry->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
    osg::BlendFunc* bf = new osg::BlendFunc(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA); 
    geometry->getOrCreateStateSet()->setAttributeAndModes(bf);
    osg::PolygonMode *pm = new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::LINE);
    geometry->getOrCreateStateSet()->setAttribute(pm);
    transform->addChild(geometry);
    
    return transform.release();
  }

  bool convertVertexSelection
  (
    const ann::SeerShape& seerShapeIn,
    slc::Message &mInOut
  )
  {
    const TopoDS_Vertex vertex = TopoDS::Vertex(seerShapeIn.getOCCTShape(mInOut.shapeId));
    std::vector<uuid> parentEdges = seerShapeIn.useGetParentsOfType(mInOut.shapeId, TopAbs_EDGE);
    for (const auto &edge : parentEdges)
    {
      if (seerShapeIn.useGetStartVertex(edge) == mInOut.shapeId)
      {
        mInOut.shapeId = edge;
        mInOut.type = slc::Type::StartPoint;
        return true;
      }
      else if (seerShapeIn.useGetEndVertex(edge) == mInOut.shapeId)
      {
        mInOut.shapeId = edge;
        mInOut.type = slc::Type::EndPoint;
        return true;
      }
    }
    return false;
  }
}

using namespace cmv;

CheckPageBase::CheckPageBase(const ftr::Base &featureIn, QWidget *parent):
  QWidget(parent), feature(featureIn), seerShape(featureIn.getAnnex<ann::SeerShape>())
{
  minBoundingSphere = calculateBoundingSphere(seerShape.getRootOCCTShape());
  minBoundingSphere.radius() *= .1; //10 percent.
}

CheckPageBase::~CheckPageBase()
{
  if (boundingSphere.valid()) //remove current boundingSphere.
  {
    assert(boundingSphere->getParents().size() == 1);
    osg::Group *parent = boundingSphere->getParent(0);
    parent->removeChild(boundingSphere.get()); //this should make boundingSphere invalid.
  }
}

BasicCheckPage::BasicCheckPage(const ftr::Base &featureIn, QWidget *parent) :
  CheckPageBase(featureIn, parent)
{
  buildGui();
  
  QSettings &settings = app::instance()->getUserSettings();
  settings.beginGroup("CheckGeometry");
  settings.beginGroup("BasicPage");
  treeWidget->header()->restoreState(settings.value("header").toByteArray());
  settings.endGroup();
  settings.endGroup();
  
  connect(treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChangedSlot()));
}

BasicCheckPage::~BasicCheckPage()
{
  QSettings &settings = app::instance()->getUserSettings();
  settings.beginGroup("CheckGeometry");
  settings.beginGroup("BasicPage");
  settings.setValue("header", treeWidget->header()->saveState());
  settings.endGroup();
  settings.endGroup();
}

void BasicCheckPage::buildGui()
{
  treeWidget = new QTreeWidget(this);
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(treeWidget);
  this->setLayout(layout);
  treeWidget->setColumnCount(3);
  treeWidget->setHeaderLabels
  (
    QStringList
    {
      tr("Id"),
      tr("Type"),
      tr("Error")
    }
  );
}

void BasicCheckPage::hideEvent(QHideEvent *event)
{
  treeWidget->clearSelection();
  QWidget::hideEvent(event);
}

void BasicCheckPage::go()
{
  //these will have to adjusted for sub shape entry.
  const TopoDS_Shape &shape = seerShape.getRootOCCTShape();
  uuid rootId = seerShape.getRootShapeId();
  
  //probably need try catch here.
  BRepCheck_Analyzer shapeCheck(shape);
  QTreeWidgetItem *rootItem = new QTreeWidgetItem();
  rootItem->setData(0, Qt::DisplayRole, QString::fromStdString(gu::idToString(rootId)));
  rootItem->setData(1, Qt::DisplayRole, QString::fromStdString(occt::getShapeTypeString(shape)));
  treeWidget->addTopLevelItem(rootItem);
  itemStack.push(rootItem);
  
  if (shapeCheck.IsValid())
  {
    rootItem->setData(2, Qt::DisplayRole, tr("Valid"));
    Q_EMIT(basicCheckPassed());
    return;
  }
  
  rootItem->setData(2, Qt::DisplayRole, tr("Invalid"));
  Q_EMIT(basicCheckFailed());
  recursiveCheck(shapeCheck, shape);
  treeWidget->expandAll();
}

void BasicCheckPage::recursiveCheck(const BRepCheck_Analyzer &shapeCheck, const TopoDS_Shape &shape)
{
  if (seerShape.hasShape(shape))
  {
    uuid shapeId = seerShape.findId(shape);

    if
    (
      (!shapeCheck.Result(shape).IsNull()) &&
      (checkedIds.count(shapeId) == 0)
    )
    {
      
      BRepCheck_ListIteratorOfListOfStatus listIt;
      listIt.Initialize(shapeCheck.Result(shape)->Status());
      QTreeWidgetItem *entry = new QTreeWidgetItem(itemStack.top());
      entry->setData(0, Qt::DisplayRole, QString::fromStdString(gu::idToString(shapeId)));
      entry->setData(1, Qt::DisplayRole, QString::fromStdString(occt::getShapeTypeString(shape)));
      entry->setData(2, Qt::DisplayRole, checkStatusToString(listIt.Value()));
      itemStack.push(entry);
  
      if (shape.ShapeType() == TopAbs_SOLID)
        checkSub(shapeCheck, shape, TopAbs_SHELL);
      if (shape.ShapeType() == TopAbs_EDGE)
        checkSub(shapeCheck, shape, TopAbs_VERTEX);
      if (shape.ShapeType() == TopAbs_FACE)
      {
        checkSub(shapeCheck, shape, TopAbs_WIRE);
        checkSub(shapeCheck, shape, TopAbs_EDGE);
        checkSub(shapeCheck, shape, TopAbs_VERTEX);
      }
      
      if
      (
        (itemStack.top()->childCount() == 0) &&
        (listIt.Value() == BRepCheck_NoError)
      )
      {
        itemStack.top()->parent()->removeChild(itemStack.top());
        delete itemStack.top();
      }
      
      itemStack.pop();
    }
    //this happens to excess so no warning out. I believe this is the whole
    //orientation thing. we use TopExp::mapOfShapes in seer shape but this uses a TopoDS_Iterator.
//     else
//     {
//       std::cout << "Warning: no shapeIdRecord in BasicCheckPage::recursiveCheck" << std::endl;
//     }
    checkedIds.insert(shapeId);
  }
  for (TopoDS_Iterator it(shape); it.More(); it.Next())
    recursiveCheck(shapeCheck, it.Value());
}

void BasicCheckPage::checkSub(const BRepCheck_Analyzer &shapeCheck, const TopoDS_Shape &shape,
                                        TopAbs_ShapeEnum subType)
{
  BRepCheck_ListIteratorOfListOfStatus itl;
  TopExp_Explorer exp;
  for (exp.Init(shape,subType); exp.More(); exp.Next())
  {
    const TopoDS_Shape& sub = exp.Current();
    
    if (!seerShape.hasShape(sub))
    {
      std::cout << "Warning: no shapeIdRecord in BasicCheckPage::checkSub" << std::endl;
      continue;
    }
    uuid subId = seerShape.findId(sub);
    
    const Handle(BRepCheck_Result)& res = shapeCheck.Result(sub);
    for (res->InitContextIterator(); res->MoreShapeInContext(); res->NextShapeInContext())
    {
      if (res->ContextualShape().IsSame(shape))
      {
        for (itl.Initialize(res->StatusOnShape()); itl.More(); itl.Next())
        {
          if (itl.Value() == BRepCheck_NoError)
            break;
          checkedIds.insert(subId);
          QTreeWidgetItem *entry = new QTreeWidgetItem(itemStack.top());
          entry->setData(0, Qt::DisplayRole, QString::fromStdString(gu::idToString(subId)));
          entry->setData(1, Qt::DisplayRole, QString::fromStdString(occt::getShapeTypeString(sub)));
          entry->setData(2, Qt::DisplayRole, checkStatusToString(itl.Value()));
//           dispatchError(entry, itl.Value());
        }
      }
    }
  }
}

void BasicCheckPage::selectionChangedSlot()
{
  //right now we are building and destroy each bounding sphere upon
  //selection change. might want to cache.
  
  //remove previous bounding sphere and clear selection.
  if (boundingSphere.valid()) //remove current boundingSphere.
  {
    assert(boundingSphere->getParents().size() == 1);
    osg::Group *parent = boundingSphere->getParent(0);
    parent->removeChild(boundingSphere.get()); //this should make boundingSphere invalid.
  }
  app::instance()->messageSlot(msg::Message(msg::Request | msg::Selection | msg::Clear));
  
  //get the fresh id.
  QList<QTreeWidgetItem*> freshSelections = treeWidget->selectedItems();
  if (freshSelections.empty())
    return;
  uuid id = gu::stringToId(freshSelections.at(0)->data(0, Qt::DisplayRole).toString().toStdString());
  assert(!id.is_nil());
  assert(seerShape.hasId(id));
  
  slc::Message sMessage;
  sMessage.type = slc::convert(seerShape.getOCCTShape(id).ShapeType());
  sMessage.featureId = feature.getId();
  sMessage.featureType = feature.getType();
  sMessage.shapeId = id;
  
  osg::BoundingSphered bSphere;
  //if vertex convert to selection point and 'cheat' bounding sphere.
  if (seerShape.getOCCTShape(id).ShapeType() == TopAbs_VERTEX)
  {
    if (!convertVertexSelection(seerShape, sMessage)) //converts vertex id to edge id
    {
      std::cout << "vertex to selection failed: BasicCheckPage::selectionChangedSlot" << std::endl;
      return;
    }
    //just make bounding sphere a percentage of whole shape. what if whole shape is vertex?
    osg::Vec3d vertexPosition = gu::toOsg(BRep_Tool::Pnt(TopoDS::Vertex(seerShape.getOCCTShape(id))));
    bSphere = minBoundingSphere;
    bSphere.center() = vertexPosition;
    sMessage.pointLocation = vertexPosition;
  }
  else
  {
    bSphere = calculateBoundingSphere(seerShape.getOCCTShape(id));
    bSphere.radius() = std::max(bSphere.radius(), minBoundingSphere.radius());
  }
  
  //select the geometry.
  msg::Message message
  (
    msg::Request | msg::Selection | msg::Add
    , sMessage
  );
  app::instance()->messageSlot(message);
  
  if (!bSphere.valid())
  {
    app::instance()->messageSlot(msg::buildStatusMessage("Unable to calculate bounding sphere"));
    return;
  }
  
  boundingSphere = buildBoundingSphere(bSphere);
  if (feature.getOverlaySwitch()->addChild(boundingSphere.get()))
    feature.getOverlaySwitch()->setValue(feature.getOverlaySwitch()->getNumChildren() - 1, true);
}

BOPCheckPage::BOPCheckPage(const ftr::Base &featureIn, QWidget *parent) :
  CheckPageBase(featureIn, parent)
{
}

BOPCheckPage::~BOPCheckPage()
{
  if (tableWidget)
  {
    QSettings &settings = app::instance()->getUserSettings();
    settings.beginGroup("CheckGeometry");
    settings.beginGroup("BOPPage");
    settings.setValue("header", tableWidget->horizontalHeader()->saveState());
    settings.endGroup();
    settings.endGroup();
  }
}

void BOPCheckPage::basicCheckFailedSlot()
{
  QLabel *label = new QLabel(this);
  label->setText(tr("BOP check unavailble when basic check failed"));
  QHBoxLayout *hLayout = new QHBoxLayout();
  hLayout->addStretch();
  hLayout->addWidget(label);
  hLayout->addStretch();
  QVBoxLayout *vLayout = new QVBoxLayout();
  vLayout->addLayout(hLayout);
  this->setLayout(vLayout);
}

void BOPCheckPage::basicCheckPassedSlot()
{
  QPushButton *goButton = new QPushButton(tr("Launch BOP check"), this);
  QHBoxLayout *hLayout = new QHBoxLayout();
  hLayout->addStretch();
  hLayout->addWidget(goButton);
  hLayout->addStretch();
  QVBoxLayout *vLayout = new QVBoxLayout();
  vLayout->addLayout(hLayout);
  this->setLayout(vLayout);
  connect(goButton, SIGNAL(clicked()), goButton, SLOT(hide()));
  connect(goButton, SIGNAL(clicked()), this, SLOT(goSlot()));
}

void BOPCheckPage::hideEvent(QHideEvent *event)
{
  if (tableWidget)
    tableWidget->clearSelection();
  QWidget::hideEvent(event);
}

void BOPCheckPage::goSlot()
{
  //todo launch bopalgo check in another process.
  
  
  delete (this->layout());
  tableWidget = new QTableWidget(this);
  tableWidget->setColumnCount(3);
  tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
  tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
  tableWidget->setHorizontalHeaderLabels
  (
    QStringList
    {
      tr("Id"),
      tr("Type"),
      tr("Error")
    }
  );
  QVBoxLayout *vLayout = new QVBoxLayout();
  vLayout->addWidget(tableWidget);
  this->setLayout(vLayout);
  
  QSettings &settings = app::instance()->getUserSettings();
  settings.beginGroup("CheckGeometry");
  settings.beginGroup("BOPPage");
  tableWidget->horizontalHeader()->restoreState(settings.value("header").toByteArray());
  settings.endGroup();
  settings.endGroup();
  
  BOPAlgo_ArgumentAnalyzer BOPCheck;
  //   BOPCheck.StopOnFirstFaulty() = true; //this doesn't run any faster but gives us less results.
  BOPCheck.SetRunParallel(true);
  BOPCheck.SetShape1(seerShape.getRootOCCTShape());
  BOPCheck.ArgumentTypeMode() = true;
  BOPCheck.SelfInterMode() = true;
  BOPCheck.SmallEdgeMode() = true;
  BOPCheck.RebuildFaceMode() = true;
  BOPCheck.ContinuityMode() = true;
  BOPCheck.TangentMode() = true; //this only for more than 2 arguments
  BOPCheck.MergeVertexMode() = true; //this only for more than 2 arguments
  BOPCheck.CurveOnSurfaceMode() = true;
  BOPCheck.MergeEdgeMode() = true; //this only for more than 2 arguments
  
  QApplication::setOverrideCursor(Qt::WaitCursor);
  QApplication::processEvents(); //so wait cursor shows.
  //probably need try catch here.
  BOPCheck.Perform();
  QApplication::restoreOverrideCursor();
  
  const BOPAlgo_ListOfCheckResult &BOPResults = BOPCheck.GetCheckResult();
  std::vector<QTableWidgetItem> items;
  for (const auto &result : BOPResults)
  {
    for (const auto &resultShape : result.GetFaultyShapes1())
    {
      assert(seerShape.hasShape(resultShape));
      uuid sourceId = seerShape.findId(resultShape);
      items.push_back(QTableWidgetItem(QString::fromStdString(gu::idToString(sourceId))));
      items.push_back(QTableWidgetItem(QString::fromStdString
        (occt::getShapeTypeString(seerShape.getOCCTShape(sourceId)))));
      items.push_back(QTableWidgetItem(BOPCheckStatusToString(result.GetCheckStatus())));
    }
  }
  
  assert((items.size() % 3) == 0);
  tableWidget->setRowCount(items.size() / 3 + 1);
  
  QString overallStatus;
  if (!BOPCheck.HasFaulty())
    overallStatus = tr("Valid");
  else
    overallStatus = tr("Invalid");
  tableWidget->setItem(0, 0, new QTableWidgetItem
    (QString::fromStdString(gu::idToString(seerShape.getRootShapeId()))));
  tableWidget->setItem(0, 1, new QTableWidgetItem
    (QString::fromStdString(occt::getShapeTypeString(seerShape.getRootOCCTShape()))));
  tableWidget->setItem(0, 2, new QTableWidgetItem(overallStatus));
  
  auto it = items.begin();
  for (std::size_t row = 0; row < (items.size() / 3); ++row)
  {
    for (std::size_t column = 0; column < 3; ++column)
    {
      tableWidget->setItem(row + 1, column, new QTableWidgetItem(*it));
      it++;
    }
  }
  connect(tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChangedSlot()));
}

void BOPCheckPage::selectionChangedSlot()
{
  if (boundingSphere.valid()) //remove current boundingSphere.
  {
    assert(boundingSphere->getParents().size() == 1);
    osg::Group *parent = boundingSphere->getParent(0);
    parent->removeChild(boundingSphere.get()); //this should make boundingSphere invalid.
  }
  app::instance()->messageSlot(msg::Message(msg::Request | msg::Selection | msg::Clear));
  
  //get the fresh id.
  QList<QTableWidgetItem*> freshSelections = tableWidget->selectedItems();
  if (freshSelections.empty())
    return;
  uuid id = gu::stringToId(freshSelections.at(0)->data(Qt::DisplayRole).toString().toStdString());
  assert(!id.is_nil());
  assert(seerShape.hasId(id));
  
  slc::Message sMessage;
  sMessage.type = slc::convert(seerShape.getOCCTShape(id).ShapeType());
  sMessage.featureId = feature.getId();
  sMessage.featureType = feature.getType();
  sMessage.shapeId = id;
  
  osg::BoundingSphered bSphere;
  //if vertex convert to selection point and 'cheat' bounding sphere.
  if (seerShape.getOCCTShape(id).ShapeType() == TopAbs_VERTEX)
  {
    if (!convertVertexSelection(seerShape, sMessage)) //converts vertex id to edge id
    {
      std::cout << "vertex to selection failed: ToleranceCheckPage::selectionChangedSlot" << std::endl;
      return;
    }
    //just make bounding sphere a percentage of whole shape. what if whole shape is vertex?
    osg::Vec3d vertexPosition = gu::toOsg(BRep_Tool::Pnt(TopoDS::Vertex(seerShape.getOCCTShape(id))));
    bSphere = minBoundingSphere;
    bSphere.center() = vertexPosition;
    sMessage.pointLocation = vertexPosition;
  }
  else
  {
    bSphere = calculateBoundingSphere(seerShape.getOCCTShape(id));
    bSphere.radius() = std::max(bSphere.radius(), minBoundingSphere.radius());
  }
  
  //select the geometry.
  msg::Message message
  (
    msg::Request | msg::Selection | msg::Add
    , sMessage
  );
  app::instance()->messageSlot(message);
  
  if (!bSphere.valid())
  {
    app::instance()->messageSlot(msg::buildStatusMessage("Unable to calculate bounding sphere"));
    return;
  }
  
  boundingSphere = buildBoundingSphere(bSphere);
  if (feature.getOverlaySwitch()->addChild(boundingSphere.get()))
    feature.getOverlaySwitch()->setValue(feature.getOverlaySwitch()->getNumChildren() - 1, true);
}

ToleranceCheckPage::ToleranceCheckPage(const ftr::Base &featureIn, QWidget *parent) :
  CheckPageBase(featureIn, parent)
{
  buildGui();
  
  QSettings &settings = app::instance()->getUserSettings();
  settings.beginGroup("CheckGeometry");
  settings.beginGroup("TolerancePage");
  tableWidget->horizontalHeader()->restoreState(settings.value("header").toByteArray());
  settings.endGroup();
  settings.endGroup();
  
  connect(tableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(selectionChangedSlot()));
}

ToleranceCheckPage::~ToleranceCheckPage()
{
  QSettings &settings = app::instance()->getUserSettings();
  settings.beginGroup("CheckGeometry");
  settings.beginGroup("TolerancePage");
  settings.setValue("header", tableWidget->horizontalHeader()->saveState());
  settings.endGroup();
  settings.endGroup();
}

void ToleranceCheckPage::buildGui()
{
  tableWidget = new QTableWidget(this);
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(tableWidget);
  this->setLayout(layout);
  
  tableWidget->setColumnCount(3);
  tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
  tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
  tableWidget->setHorizontalHeaderLabels
  (
    QStringList
    {
      tr("Id"),
      tr("Type"),
      tr("Tolerance")
    }
  );
}

void ToleranceCheckPage::hideEvent(QHideEvent *event)
{
  tableWidget->clearSelection();
  QWidget::hideEvent(event);
}

void ToleranceCheckPage::go()
{
  tableWidget->clearContents();
  tableWidget->setSortingEnabled(false);
  
  std::vector<uuid> ids = seerShape.getAllShapeIds();
  
  //tablewidget has to have row size set before adding items. we are only adding
  //face edges and vertices, so we need to filter down ids so we can set the
  //row count before filling in values.
  std::vector<uuid> filteredIds;
  for (const auto &id : ids)
  {
    TopAbs_ShapeEnum shapeType = seerShape.getOCCTShape(id).ShapeType();
    if
    (
      (shapeType == TopAbs_FACE) ||
      (shapeType == TopAbs_EDGE) ||
      (shapeType == TopAbs_VERTEX)
    )
      filteredIds.push_back(id);
  }
  
  tableWidget->setRowCount(filteredIds.size());
  int row = 0;
  for (const auto &id : filteredIds)
  {
    TopAbs_ShapeEnum shapeType = seerShape.getOCCTShape(id).ShapeType();
    double tolerance = 0.0;
    if (shapeType == TopAbs_FACE)
      tolerance = BRep_Tool::Tolerance(TopoDS::Face(seerShape.getOCCTShape(id)));
    else if (shapeType == TopAbs_EDGE)
      tolerance = BRep_Tool::Tolerance(TopoDS::Edge(seerShape.getOCCTShape(id)));
    else if (shapeType == TopAbs_VERTEX)
      tolerance = BRep_Tool::Tolerance(TopoDS::Vertex(seerShape.getOCCTShape(id)));
    else
      continue;
    
    tableWidget->setItem(row, 0, new QTableWidgetItem
      (QString::fromStdString(gu::idToString(id))));
    tableWidget->setItem(row, 1, new QTableWidgetItem
      (QString::fromStdString(occt::getShapeTypeString(seerShape.getOCCTShape(id)))));
    tableWidget->setItem(row, 2, new QTableWidgetItem
      (QString::number(tolerance, 'f', 7))); //sorting doesn't work with sci notation.
    row++;
  }
  
  tableWidget->setSortingEnabled(true);
  tableWidget->sortItems(2, Qt::DescendingOrder);
}

void ToleranceCheckPage::selectionChangedSlot()
{
  if (boundingSphere.valid()) //remove current boundingSphere.
  {
    assert(boundingSphere->getParents().size() == 1);
    osg::Group *parent = boundingSphere->getParent(0);
    parent->removeChild(boundingSphere.get()); //this should make boundingSphere invalid.
  }
  app::instance()->messageSlot(msg::Message(msg::Request | msg::Selection | msg::Clear));
  
  //get the fresh id.
  QList<QTableWidgetItem*> freshSelections = tableWidget->selectedItems();
  if (freshSelections.empty())
    return;
  uuid id = gu::stringToId(freshSelections.at(0)->data(Qt::DisplayRole).toString().toStdString());
  assert(!id.is_nil());
  assert(seerShape.hasId(id));
  
  slc::Message sMessage;
  sMessage.type = slc::convert(seerShape.getOCCTShape(id).ShapeType());
  sMessage.featureId = feature.getId();
  sMessage.featureType = feature.getType();
  sMessage.shapeId = id;
  
  osg::BoundingSphered bSphere;
  //if vertex convert to selection point and 'cheat' bounding sphere.
  if (seerShape.getOCCTShape(id).ShapeType() == TopAbs_VERTEX)
  {
    if (!convertVertexSelection(seerShape, sMessage)) //converts vertex id to edge id
    {
      std::cout << "vertex to selection failed: ToleranceCheckPage::selectionChangedSlot" << std::endl;
      return;
    }
    //just make bounding sphere a percentage of whole shape. what if whole shape is vertex?
    osg::Vec3d vertexPosition = gu::toOsg(BRep_Tool::Pnt(TopoDS::Vertex(seerShape.getOCCTShape(id))));
    bSphere = minBoundingSphere;
    bSphere.center() = vertexPosition;
    sMessage.pointLocation = vertexPosition;
  }
  else
  {
    bSphere = calculateBoundingSphere(seerShape.getOCCTShape(id));
    bSphere.radius() = std::max(bSphere.radius(), minBoundingSphere.radius());
  }
  
  //select the geometry.
  msg::Message message
  (
    msg::Request | msg::Selection | msg::Add
    , sMessage
  );
  app::instance()->messageSlot(message);
  
  if (!bSphere.valid())
  {
    app::instance()->messageSlot(msg::buildStatusMessage("Unable to calculate bounding sphere"));
    return;
  }
  
  boundingSphere = buildBoundingSphere(bSphere);
  if (feature.getOverlaySwitch()->addChild(boundingSphere.get()))
    feature.getOverlaySwitch()->setValue(feature.getOverlaySwitch()->getNumChildren() - 1, true);
}

ShapesPage::ShapesPage(const ftr::Base &featureIn, QWidget *parent) :
  CheckPageBase(featureIn, parent)
{
  buildGui();
}

void ShapesPage::buildGui()
{
  QHBoxLayout *layout = new QHBoxLayout();
  
  QVBoxLayout *tl = new QVBoxLayout();
  tl->addWidget(new QLabel(tr("Content"), this));
  textEdit = new QTextEdit(this);
  textEdit->setReadOnly(true);
  tl->addWidget(textEdit);
  tl->addStretch();
  layout->addLayout(tl);
  
  QVBoxLayout *bl = new QVBoxLayout();
  bl->addWidget(new QLabel(tr("Boundaries"), this));
  boundaryTable = new QTableWidget(this);
  boundaryTable->setColumnCount(1);
  boundaryTable->setHorizontalHeaderLabels(QStringList{tr("Status")});
  boundaryTable->setSelectionBehavior(QAbstractItemView::SelectRows);
  boundaryTable->setSelectionMode(QAbstractItemView::SingleSelection);
  bl->addWidget(boundaryTable);
  bl->addStretch();
  layout->addLayout(bl);
  
  connect(boundaryTable, &QTableWidget::itemSelectionChanged, this, &ShapesPage::boundaryItemChangedSlot);
  
  this->setLayout(layout);
}

void ShapesPage::go()
{
  std::ostringstream stream;
  BRepTools_ShapeSet set;
  set.Add(seerShape.getRootOCCTShape());
  set.DumpExtent(stream);
  textEdit->setText(QString::fromStdString(stream.str()));
  
  auto processWire = [&](const TopoDS_Wire &w)
  {
    //these are wires only in the sense of a collection of edges.
    //the wires don't actually exist inside the seershape.
    TopTools_IndexedMapOfShape map;
    TopExp::MapShapes(w, TopAbs_EDGE, map);
    occt::EdgeVector ev = occt::ShapeVectorCast(map);
    std::vector<uuid> edges;
    for (const auto &e : ev)
    {
      if (!seerShape.hasShape(e))
      {
        std::cerr << "WARNING: skipping edge in ShapesPage::go()" << std::endl;
        continue;
      }
      edges.push_back(seerShape.findId(e));
    }
    gu::uniquefy(edges);
    boundaries.push_back(edges);
  };
  
  occt::WireVector closed, open;
  std::tie(closed, open) = occt::getBoundaryWires(seerShape.getRootOCCTShape());
  boundaryTable->setRowCount(open.size() + closed.size());
  int row = 0;
  for (const auto &w : closed)
  {
    processWire(w);
    boundaryTable->setItem(row, 0, new QTableWidgetItem(tr("Closed")));
    row++;
  }
  for (const auto &w : open)
  {
    processWire(w);
    boundaryTable->setItem(row, 0, new QTableWidgetItem(tr("Open")));
    row++;
  }
}

void ShapesPage::boundaryItemChangedSlot()
{
  //remove previous bounding sphere and clear selection.
  if (boundingSphere.valid()) //remove current boundingSphere.
  {
    assert(boundingSphere->getParents().size() == 1);
    osg::Group *parent = boundingSphere->getParent(0);
    parent->removeChild(boundingSphere.get()); //this should make boundingSphere invalid.
  }
  app::instance()->messageSlot(msg::Message(msg::Request | msg::Selection | msg::Clear));
  
  QList<QTableWidgetItem*> selected = boundaryTable->selectedItems();
  if (selected.isEmpty())
    return;
  int row = selected.front()->row();
  assert((row >= 0) && (row < static_cast<int>(boundaries.size())));
  const std::vector<uuid> &eids = boundaries.at(row);
  occt::ShapeVector ess;
  for (const auto &e : eids)
  {
    if (!seerShape.hasId(e))
    {
      std::cerr << "WARNING: skipping edge in ShapesPage::boundaryItemChangedSlot()" << std::endl;
      continue;
    }
    slc::Message sMessage;
    sMessage.type = slc::Type::Edge;
    sMessage.featureId = feature.getId();
    sMessage.featureType = feature.getType();
    sMessage.shapeId = e;
    msg::Message message
    (
      msg::Request | msg::Selection | msg::Add
      , sMessage
    );
    app::instance()->messageSlot(message);
    
    ess.push_back(seerShape.findShape(e));
  }
  TopoDS_Compound c = occt::ShapeVectorCast(ess);
  osg::BoundingSphered bs = calculateBoundingSphere(c);
  bs.radius() = std::max(bs.radius(), minBoundingSphere.radius());
  if (!bs.valid())
  {
    app::instance()->messageSlot(msg::buildStatusMessage("Unable to calculate bounding sphere"));
    return;
  }
  boundingSphere = buildBoundingSphere(bs);
  if (feature.getOverlaySwitch()->addChild(boundingSphere.get()))
    feature.getOverlaySwitch()->setValue(feature.getOverlaySwitch()->getNumChildren() - 1, true);
}

void ShapesPage::hideEvent(QHideEvent *event)
{
  boundaryTable->clearSelection();
  QWidget::hideEvent(event);
}

struct CheckGeometry::Stow
{
  const ftr::Base &feature;
  cmv::CheckGeometry *view;
  
  QTabWidget *tabWidget = nullptr;
  BasicCheckPage *basicCheckPage = nullptr;
  BOPCheckPage *bopCheckPage = nullptr;
  ToleranceCheckPage *toleranceCheckPage = nullptr;
  ShapesPage *shapesPage = nullptr;
  
  Stow(const ftr::Base &fIn, cmv::CheckGeometry *vIn)
  : feature(fIn)
  , view(vIn)
  {
    buildGui();
    
    QSettings &settings = app::instance()->getUserSettings();
    settings.beginGroup("cmv::CheckGeometry");
    //load settings
    settings.endGroup();
    
    //we don't call go for bop page because it is so slow.
    //we make the user launch it.
    basicCheckPage->go();
    toleranceCheckPage->go();
    shapesPage->go();
  }
  
  void buildGui()
  {
    QVBoxLayout *mainLayout = new QVBoxLayout();
    view->setLayout(mainLayout);
    tabWidget = new QTabWidget(view);
    mainLayout->addWidget(tabWidget);
    
    basicCheckPage = new BasicCheckPage(feature, view);
    tabWidget->addTab(basicCheckPage, tr("Basic"));
    
    bopCheckPage = new BOPCheckPage(feature, view);
    tabWidget->addTab(bopCheckPage, tr("Boolean"));
    connect(basicCheckPage, SIGNAL(basicCheckPassed()), bopCheckPage, SLOT(basicCheckPassedSlot()));
    connect(basicCheckPage, SIGNAL(basicCheckFailed()), bopCheckPage, SLOT(basicCheckFailedSlot()));
    
    toleranceCheckPage = new ToleranceCheckPage(feature, view);
    tabWidget->addTab(toleranceCheckPage, tr("Tolerance"));
    
    shapesPage = new ShapesPage(feature, view);
    tabWidget->addTab(shapesPage, tr("Shapes"));
  }
};

CheckGeometry::CheckGeometry(const ftr::Base &fIn)
: Base("cmv::CheckGeometry")
, stow(new Stow(fIn, this))
{}

CheckGeometry::~CheckGeometry() = default;
