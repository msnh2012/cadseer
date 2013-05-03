#ifndef SELECTIONEVENTHANDLER_H
#define SELECTIONEVENTHANDLER_H

#include <osgGA/GUIEventHandler>

class SelectionEventHandler : public osgGA::GUIEventHandler
{
public:
    SelectionEventHandler();
protected:
    virtual bool handle(const osgGA::GUIEventAdapter& eventAdapter,
                        osgGA::GUIActionAdapter& actionAdapter, osg::Object *object,
                        osg::NodeVisitor *nodeVistor);
    void setPrehighlight(osg::Geometry *geometry);
    void clearPrehighlight();
    osg::observer_ptr<osg::Geometry> lastPrehighlightGeometry;
    osg::Vec4 lastPrehighlightColor;
    int lastPrehighlightColorIndex;
    osg::Vec4 preHighlightColor;
};

#endif // SELECTIONEVENTHANDLER_H
