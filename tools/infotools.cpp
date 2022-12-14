/*
 * CadSeer. Parametric Solid Modeling.
 * Copyright (C) 2016  Thomas S. Anderson blobfish.at.gmx.com
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

#include <QTextStream>

#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>

#include <osg/Matrixd>

#include "globalutilities.h"
#include "tools/tlsstring.h"
#include "tools/infotools.h"

namespace
{
  QString ms(const double &number)
  {
    return QString::fromStdString(tls::prettyDouble(number));
  }
}

QTextStream& gu::osgMatrixOut(QTextStream &streamIn, const osg::Matrixd &m)
{
    streamIn << "Coordinate system: "
    << "["
    << "["
    << ms(gu::getXVector(m).x()) << ", "
    << ms(gu::getXVector(m).y()) << ", "
    << ms(gu::getXVector(m).z())
    << "], ["
    << ms(gu::getYVector(m).x()) << ", "
    << ms(gu::getYVector(m).y()) << ", "
    << ms(gu::getYVector(m).z())
    << "], ["
    << ms(gu::getZVector(m).x()) << ", "
    << ms(gu::getZVector(m).y()) << ", "
    << ms(gu::getZVector(m).z())
    << "], ["
    << ms(m.getTrans().x()) << ", "
    << ms(m.getTrans().y()) << ", "
    << ms(m.getTrans().z())
    << "]"
    << "]";
    
    return streamIn;
}

QTextStream& gu::osgQuatOut(QTextStream &s, const osg::Quat &qIn)
{
  s << "[" << ms(qIn.x()) << ", " << ms(qIn.y()) << ", " << ms(qIn.z()) << ", " << ms(qIn.w()) << "]";
  return s;
}

QTextStream& gu::osgVectorOut(QTextStream &s, const osg::Vec3d &vIn)
{
  s << "[" << ms(vIn.x()) << ", " << ms(vIn.y()) << ", " << ms(vIn.z()) << "]";
  return s;
}

QTextStream& gu::gpPntOut(QTextStream &sIn, const gp_Pnt &pIn)
{
  sIn << "[" << pIn.X() << ", " << pIn.Y() << ", " << pIn.Z() << "]";
  return sIn;
}

QTextStream& gu::gpDirOut(QTextStream &sIn, const gp_Dir &dIn)
{
  sIn << "[" << dIn.X() << ", " << dIn.Y() << ", " << dIn.Z() << "]";
  return sIn;
}

QString gu::osgMatrixOut(const osg::Matrixd &mIn)
{
  QString buffer;
  QTextStream stream(&buffer);
  gu::osgMatrixOut(stream, mIn);
  
  return buffer;
}

QString gu::osgQuatOut(const osg::Quat &qIn)
{
  QString buffer;
  QTextStream stream(&buffer);
  gu::osgQuatOut(stream, qIn);
  
  return buffer;
}

QString gu::osgVectorOut(const osg::Vec3d &vIn)
{
  QString buffer;
  QTextStream stream(&buffer);
  gu::osgVectorOut(stream, vIn);
  
  return buffer;
}

QString gu::gpPntOut(const gp_Pnt &pIn)
{
  QString buffer;
  QTextStream stream(&buffer);
  gu::gpPntOut(stream, pIn);
  
  return buffer;
}

QString gu::gpDirOut(const gp_Dir &dIn)
{
  QString buffer;
  QTextStream stream(&buffer);
  gu::gpDirOut(stream, dIn);
  
  return buffer;
}
