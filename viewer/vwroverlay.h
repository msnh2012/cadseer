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

#ifndef VWR_OVERLAY_H
#define VWR_OVERLAY_H

#include <memory>

#include <osg/Camera>
#include <osg/Switch>

namespace msg{struct Message; struct Node; struct Sift;}
namespace vwr
{
class Overlay : public osg::Camera
{
public:
    Overlay();

private:
  std::unique_ptr<msg::Node> node;
  std::unique_ptr<msg::Sift> sift;
  void setupDispatcher();
  void featureAddedDispatched(const msg::Message &);
  void featureRemovedDispatched(const msg::Message &);
  void closeProjectDispatched(const msg::Message&);
  void addOverlayGeometryDispatched(const msg::Message&);
  void clearOverlayGeometryDispatched(const msg::Message&); //!< only fleeting, not features.
  void overlayToggleDispatched(const msg::Message &);
  void showOverlayDispatched(const msg::Message &);
  void hideOverlayDispatched(const msg::Message &);
  void projectOpenedDispatched(const msg::Message &);
  void projectUpdatedDispatched(const msg::Message &);
  
  void serialRead();
  void serialWrite();
  
  osg::ref_ptr<osg::Switch> fleetingGeometry;
};
}

#endif // VWR_OVERLAY_H
