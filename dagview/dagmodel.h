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

#ifndef DAG_MODEL_H
#define DAG_MODEL_H

#include <memory>
#include <vector>
#include <bitset>

#include <QGraphicsScene>
#include <QBrush>
#include <QLineEdit>

#include "selection/slcdefinitions.h"
// #include "DAGFilter.h"

namespace boost{namespace uuids{struct uuid;}}

class QFocusEvent;

namespace msg{struct Message; struct Node; struct Sift;}

namespace dag
{
  class LineEdit : public QLineEdit
  {
    Q_OBJECT
    public:
      LineEdit(QWidget *parentIn = 0);
    Q_SIGNALS:
      void acceptedSignal();
      void rejectedSignal();
    protected:
    virtual void keyPressEvent(QKeyEvent*) override;
    virtual void focusOutEvent(QFocusEvent*) override;
  };
  
  class Stow;
  class RectItem;
  typedef unsigned long Vertex; //!< kind of a hack to keep graph definition out
  struct DragData;
  
  class Model : public QGraphicsScene
  {
    Q_OBJECT
  public:
    Model(QObject *parentIn);
    virtual ~Model() override;
    
  protected:
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;
    
  private Q_SLOTS:
    void setCurrentLeafSlot();
    void removeFeatureSlot();
    void toggleOverlaySlot();
    void toggleSelectableSlot();
    void viewIsolateSlot();
    void editColorSlot();
    void editRenameSlot();
    void editFeatureSlot();
    void dissolveSlot();
    void infoFeatureSlot();
    void checkGeometrySlot();
    void toggleSkippedSlot();
    
  private:
    std::unique_ptr<msg::Node> node;
    std::unique_ptr<msg::Sift> sift;
    void setupDispatcher();
    void featureAddedDispatched(const msg::Message &);
    void featureRemovedDispatched(const msg::Message &);
    void connectionAddedDispatched(const msg::Message &);
    void connectionRemovedDispatched(const msg::Message &);
    void projectUpdatedDispatched(const msg::Message &); //!< don't use message but need for function signature.
    void preselectionAdditionDispatched(const msg::Message &);
    void preselectionSubtractionDispatched(const msg::Message &);
    void selectionAdditionDispatched(const msg::Message &);
    void selectionSubtractionDispatched(const msg::Message &);
    void selectionMaskDispatched(const msg::Message &);
    void closeProjectDispatched(const msg::Message&);
    void featureStateChangedDispatched(const msg::Message &);
    void projectFeatureStateChangedDispatched(const msg::Message &);
    void featureRenamedDispatched(const msg::Message &);
    void dumpDAGViewGraphDispatched(const msg::Message &);
    void threeDShowDispatched(const msg::Message &);
    void threeDHideDispatched(const msg::Message &);
    void overlayShowDispatched(const msg::Message &);
    void overlayHideDispatched(const msg::Message &);
    void featureSelectionThawDispatched(const msg::Message &);
    void featureSelectionFreezeDispatched(const msg::Message &);
    void commandActiveDispatched(const msg::Message &);
    void commandInactiveDispatched(const msg::Message &);
    
    std::unique_ptr<Stow> stow;
    
    void removeAllItems();
    void stateUpdate(Vertex);
    void addItemsToScene(std::vector<QGraphicsItem*>);
    void removeItemsFromScene(std::vector<QGraphicsItem*>);
//     
    RectItem* getRectFromPosition(const QPointF &position); //!< can be nullptr
//     
  //! @name View Constants for spacing
  //@{
    float fontHeight;                           //!< height of the current qApp default font.
    float direction;                            //!< controls top to bottom or bottom to top direction.
    float verticalSpacing;                      //!< pixels between top and bottom of text to background rectangle.
    float rowHeight;                            //!< height of background rectangle.
    float iconSize;                             //!< size of icon to match font.
    float pointSize;                            //!< size of the connection point.
    float pointSpacing;                         //!< spacing between pofloat columns.
    float pointToIcon;                          //!< spacing from last column points to first icon.
    float iconToIcon;                           //!< spacing between icons.
    float iconToText;                           //!< spacing between last icon and text.
    float rowPadding;                           //!< spaces added to rectangle bacground width ends.
    float maxTextLength;                        //!< used for setting edit box for rename.
    std::vector<QBrush> backgroundBrushes;      //!< brushes to paint background rectangles.
    std::vector<QBrush> forgroundBrushes;       //!< brushes to paint points, connectors, text.
    void setupViewConstants();
  //@}
    
    RectItem *currentPrehighlight;

    QPointF lastPick;
    bool lastPickValid = false;
    slc::Mask selectionMask;
    bool commandActive = false;
    
    QPixmap visiblePixmapEnabled;
    QPixmap visiblePixmapDisabled;
    QPixmap overlayPixmapEnabled;
    QPixmap overlayPixmapDisabled;
    QPixmap selectablePixmapEnabled;
    QPixmap selectablePixmapDisabled;
    QPixmap passPixmap;
    QPixmap failPixmap;
    QPixmap pendingPixmap;
    QPixmap inactivePixmap;
    QPixmap skippedPixmap;
    
    QAction *renameAction;
    QAction *editingFinishedAction;
    void finishRename();
    
    std::shared_ptr<DragData> dragData; //!< valid means a drag in progress.

//     
//     //filters
//     void setupFilters();
//     typedef std::vector<std::shared_ptr<FilterBase> > FilterContainer;
//     FilterContainer filters;
  };
}

#endif // DAG_MODEL_H
