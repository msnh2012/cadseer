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

#ifndef DLG_PARAMETER_H
#define DLG_PARAMETER_H

#include <memory>

#include <QDialog>
#include <QLineEdit>

class QKeyEvent;
class QButton;
class QEnterEvent;
class QDropEvent;
class QLabel;

namespace boost{namespace uuids{struct uuid;}}

namespace ftr{class Base;}
namespace prm{class Parameter; struct Observer;}
namespace msg{struct Message; struct Node; struct Sift;}

namespace dlg
{
  class Parameter : public QDialog
  {
    Q_OBJECT
  public:
    Parameter(prm::Parameter *parameterIn, const boost::uuids::uuid &idIn);
    virtual ~Parameter() override;
    prm::Parameter *parameter = nullptr;
    QWidget *editWidget;

    //triggered from parameter being changed. Source can be either internal or external.
    //called from the visitor, so need public access.
    void valueHasChangedDouble();
    void valueHasChangedInt();
    void valueHasChangedBool();
    void valueHasChangedPath();
    void valueHasChangedVector();
    
    void constantHasChangedDouble();
    void constantHasChangedInt();
  private:
    void buildGui();
    void valueHasChanged();
    void constantHasChanged();
    std::unique_ptr<prm::Observer> pObserver;
    std::unique_ptr<msg::Node> node;
    std::unique_ptr<msg::Sift> sift;
    void featureRemovedDispatched(const msg::Message &);
    ftr::Base *feature;
    double lastValue;
  private Q_SLOTS:
    void requestLinkSlot(const QString &);
    void requestUnlinkSlot();
    
    void updateDoubleSlot();
    void textEditedDoubleSlot(const QString &);
    
    void boolChangedSlot(int);
    void browseForPathSlot();
    void vectorChangedSlot();
    void intChangedSlot();
    void intChangedSlot(int);
  };
}

#endif // DLG_PARAMETER_H
