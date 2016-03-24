/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2015  Thomas S. Anderson blobfish.at.gmx.com
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

#ifndef VIEWERWIDGET_H
#define VIEWERWIDGET_H

#include <QWidget>
#include <QTimer>

#include <osg/ref_ptr>
#include <osgViewer/CompositeViewer>

#ifndef Q_MOC_RUN
#include <library/csysdragger.h>
#include <selection/eventhandler.h>
#include <selection/overlayhandler.h>
#endif

namespace osgQt{class GraphicsWindowQt;}
namespace vwr{class SpaceballManipulator;}

class ViewerWidget : public QWidget, public osgViewer::CompositeViewer
{
    Q_OBJECT
public:
    ViewerWidget(osgViewer::ViewerBase::ThreadingModel threadingModel=osgViewer::CompositeViewer::SingleThreaded);
    virtual ~ViewerWidget() override;
    
    virtual void paintEvent(QPaintEvent* event);
    void update();
    osg::Group* getRoot(){return root;}
    slc::EventHandler* getSelectionEventHandler(){return selectionHandler.get();}
    const slc::Containers& getSelections() const {return selectionHandler->getSelections();}
    void clearSelections() const {selectionHandler->clearSelections();}
    const osg::Matrixd& getCurrentSystem() const {return currentSystem->getMatrix();}
    void setCurrentSystem(const osg::Matrixd &mIn){currentSystem->setMatrix(mIn);}
    
    //new messaging system
    void messageInSlot(const msg::Message &);
    typedef boost::signals2::signal<void (const msg::Message &)> MessageOutSignal;
    boost::signals2::connection connectMessageOut(const MessageOutSignal::slot_type &subscriber)
    {
      return messageOutSignal.connect(subscriber);
    }

public Q_SLOTS:
    void setSelectionMask(const int &maskIn);

protected:
    void createMainCamera(osg::Camera *camera);
    osg::Camera* createBackgroundCamera();
    osg::Camera* createGestureCamera();
    QTimer _timer;
    osg::ref_ptr<osg::Group> root;
    osg::ref_ptr<osg::Switch> infoSwitch;
    osg::ref_ptr<slc::EventHandler> selectionHandler;
    osg::ref_ptr<slc::OverlayHandler> overlayHandler;
    osg::ref_ptr<vwr::SpaceballManipulator> spaceballManipulator;
    osg::ref_ptr<osg::Switch> systemSwitch;
    osg::ref_ptr<lbr::CSysDragger> currentSystem;
    osg::ref_ptr<lbr::CSysCallBack> currentSystemCallBack;
    int glWidgetWidth;
    int glWidgetHeight;
    osgQt::GraphicsWindowQt *windowQt;
    MessageOutSignal messageOutSignal;
    msg::MessageDispatcher dispatcher;
    void setupDispatcher();
    void featureAddedDispatched(const msg::Message &);
    void featureRemovedDispatched(const msg::Message &);
    void visualUpdatedDispatched(const msg::Message &);
    void viewTopDispatched(const msg::Message &);
    void viewFrontDispatched(const msg::Message &);
    void viewRightDispatched(const msg::Message &);
    void viewFitDispatched(const msg::Message &);
    void viewFillDispatched(const msg::Message &);
    void viewLineDispatched(const msg::Message &);
    void exportOSGDispatched(const msg::Message &);
    void closeProjectDispatched(const msg::Message &);
    void systemResetDispatched(const msg::Message &);
    void systemToggleDispatched(const msg::Message &);
};

class VisibleVisitor : public osg::NodeVisitor
{
public:
    VisibleVisitor(bool visIn);
    virtual void apply(osg::Switch &aSwitch);
protected:
    bool visibility;
};

#endif // VIEWERWIDGET_H
