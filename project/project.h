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

#ifndef PROJECT_H
#define PROJECT_H

#include <map>
#include <memory>

#include <project/projectgraph.h>

class TopoDS_Shape;

namespace msg{class Message; class Observer;}

typedef std::map<boost::uuids::uuid, prg::Vertex> IdVertexMap;

namespace prj
{
  class GitManager;
  
class Project
{
public:
    Project();
    ~Project();
    void readOCC(const std::string &fileName);
    void addOCCShape(const TopoDS_Shape &shapeIn);
    ftr::Base* findFeature(const boost::uuids::uuid &idIn);
    void updateModel();
    void updateVisual();
    void writeGraphViz(const std::string &fileName);
    void setAllVisualDirty();
    
    void addFeature(std::shared_ptr<ftr::Base> feature);
    void removeFeature(const boost::uuids::uuid &idIn);
    void setFeatureActive(const boost::uuids::uuid &idIn);
    void connect(const boost::uuids::uuid &parentIn, const boost::uuids::uuid &childIn, ftr::InputTypes type);
    
    void setSaveDirectory(const std::string &directoryIn);
    std::string getSaveDirectory() const {return saveDirectory;}
    void save();
    void open(); //!< call setSaveDirectory prior.
    void initializeNew(); //!< call setSaveDirectory prior.
    
    void stateChangedSlot(const boost::uuids::uuid &featureIdIn, std::size_t stateIn); //!< received from each feature.
    
private:
    //! index all the vertices of the graph. needed for algorthims when using listS.
    void indexVerticesEdges();
    prg::Edge connect(prg::Vertex parentIn, prg::Vertex childIn, ftr::InputTypes type);
    prg::Edge connectVertices(prg::Vertex parent, prg::Vertex child, ftr::InputTypes type);
    prg::Vertex findVertex(const boost::uuids::uuid &idIn);
    typedef std::pair<prg::Vertex, prg::Edge> VertexEdgePair;
    typedef std::vector<VertexEdgePair> VertexEdgePairs;
    VertexEdgePairs getParents(prg::Vertex);
    VertexEdgePairs getChildren(prg::Vertex);
    void updateLeafStatus();
    
    IdVertexMap map;
    prg::Graph projectGraph;
    std::string saveDirectory;
    void serialWrite();
    std::unique_ptr<GitManager> gitManager;
    bool isLoading = false;
    
    std::unique_ptr<msg::Observer> observer;
    void setupDispatcher();
    void setCurrentLeafDispatched(const msg::Message &);
    void removeFeatureDispatched(const msg::Message &);
    void updateDispatched(const msg::Message &);
    void forceUpdateDispatched(const msg::Message &);
    void updateModelDispatched(const msg::Message &);
    void updateVisualDispatched(const msg::Message &);
    void saveProjectRequestDispatched(const msg::Message &);
    void gitMessageRequestDispatched(const msg::Message &);
};
}

#endif // PROJECT_H
