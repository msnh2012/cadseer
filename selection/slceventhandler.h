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

#ifndef SLC_SELECTIONEVENTHANDLER_H
#define SLC_SELECTIONEVENTHANDLER_H

#include <memory>

#include <osgGA/GUIEventHandler>

#include "selection/slccontainer.h"
#include "selection/slcmessage.h"
#include "selection/slcvisitors.h"

namespace osg{class Switch;}
namespace mdv{class ShapeGeometry;}
namespace msg{struct Message; struct Node; struct Sift;}

namespace slc
{
  class EventHandler : public osgGA::GUIEventHandler
  {
  public:
    EventHandler(osg::Group* viewerRootIn);
    const Containers& getSelections() const {return selectionContainers;}
    void clearSelections();

    static slc::Container messageToContainer(const slc::Message &);
    static slc::Message containerToMessage(const slc::Container &);
    
  protected:
    virtual bool handle(const osgGA::GUIEventAdapter& eventAdapter,
                        osgGA::GUIActionAdapter& actionAdapter, osg::Object *object,
                        osg::NodeVisitor *nodeVistor);
    void setSelectionMask(Mask);
    void setPrehighlight(Container &selected);
    void clearPrehighlight();
    bool alreadySelected(const Container &testContainer);
    void selectionOperation(const boost::uuids::uuid&, const std::vector<boost::uuids::uuid>&, HighlightVisitor::Operation);
    Container lastPrehighlight;
    osg::Vec4 preHighlightColor;
    osg::Vec4 selectionColor;
    Containers selectionContainers;
    static osg::Geometry* buildTempPoint(const osg::Vec3d &pointIn);

    unsigned int nodeMask;
    Mask selectionMask;

    osg::ref_ptr<osg::Group> viewerRoot;
    
    std::unique_ptr<msg::Node> node;
    std::unique_ptr<msg::Sift> sift;
    void setupDispatcher();
    void requestPreselectionAdditionDispatched(const msg::Message &);
    void requestPreselectionSubtractionDispatched(const msg::Message &);
    void requestSelectionAdditionDispatched(const msg::Message &);
    void requestSelectionSubtractionDispatched(const msg::Message &);
    void requestSelectionClearDispatched(const msg::Message &);
    void selectionMaskDispatched(const msg::Message&);
  };
}

#endif // SLC_SELECTIONEVENTHANDLER_H
