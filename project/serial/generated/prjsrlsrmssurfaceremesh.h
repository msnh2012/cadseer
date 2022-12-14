// Copyright (c) 2005-2014 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef PRJ_SRL_SRMS_PRJSRLSRMSSURFACEREMESH_H
#define PRJ_SRL_SRMS_PRJSRLSRMSSURFACEREMESH_H

#ifndef XSD_CXX11
#define XSD_CXX11
#endif

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4000000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include "../../../xmlbase.h"

// Forward declarations.
//
namespace prj
{
  namespace srl
  {
    namespace srms
    {
      class SurfaceReMesh;
    }
  }
}


#include <memory>    // ::std::unique_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search
#include <utility>   // std::move

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#include "prjsrlsptbase.h"

#include "prjsrlsptparameter.h"

#include "prjsrlsptoverlay.h"

#include "prjsrlmshsmesh.h"

namespace prj
{
  namespace srl
  {
    namespace srms
    {
      class SurfaceReMesh: public ::xml_schema::Type
      {
        public:
        // base
        //
        typedef ::prj::srl::spt::Base BaseType;
        typedef ::xsd::cxx::tree::traits< BaseType, char > BaseTraits;

        const BaseType&
        base () const;

        BaseType&
        base ();

        void
        base (const BaseType& x);

        void
        base (::std::unique_ptr< BaseType > p);

        // mesh
        //
        typedef ::prj::srl::mshs::Surface MeshType;
        typedef ::xsd::cxx::tree::traits< MeshType, char > MeshTraits;

        const MeshType&
        mesh () const;

        MeshType&
        mesh ();

        void
        mesh (const MeshType& x);

        void
        mesh (::std::unique_ptr< MeshType > p);

        // reMeshType
        //
        typedef ::prj::srl::spt::Parameter ReMeshTypeType;
        typedef ::xsd::cxx::tree::traits< ReMeshTypeType, char > ReMeshTypeTraits;

        const ReMeshTypeType&
        reMeshType () const;

        ReMeshTypeType&
        reMeshType ();

        void
        reMeshType (const ReMeshTypeType& x);

        void
        reMeshType (::std::unique_ptr< ReMeshTypeType > p);

        // minEdgeLength
        //
        typedef ::prj::srl::spt::Parameter MinEdgeLengthType;
        typedef ::xsd::cxx::tree::traits< MinEdgeLengthType, char > MinEdgeLengthTraits;

        const MinEdgeLengthType&
        minEdgeLength () const;

        MinEdgeLengthType&
        minEdgeLength ();

        void
        minEdgeLength (const MinEdgeLengthType& x);

        void
        minEdgeLength (::std::unique_ptr< MinEdgeLengthType > p);

        // maxEdgeLength
        //
        typedef ::prj::srl::spt::Parameter MaxEdgeLengthType;
        typedef ::xsd::cxx::tree::traits< MaxEdgeLengthType, char > MaxEdgeLengthTraits;

        const MaxEdgeLengthType&
        maxEdgeLength () const;

        MaxEdgeLengthType&
        maxEdgeLength ();

        void
        maxEdgeLength (const MaxEdgeLengthType& x);

        void
        maxEdgeLength (::std::unique_ptr< MaxEdgeLengthType > p);

        // iterations
        //
        typedef ::prj::srl::spt::Parameter IterationsType;
        typedef ::xsd::cxx::tree::traits< IterationsType, char > IterationsTraits;

        const IterationsType&
        iterations () const;

        IterationsType&
        iterations ();

        void
        iterations (const IterationsType& x);

        void
        iterations (::std::unique_ptr< IterationsType > p);

        // reMeshTypeLabel
        //
        typedef ::prj::srl::spt::PLabel ReMeshTypeLabelType;
        typedef ::xsd::cxx::tree::traits< ReMeshTypeLabelType, char > ReMeshTypeLabelTraits;

        const ReMeshTypeLabelType&
        reMeshTypeLabel () const;

        ReMeshTypeLabelType&
        reMeshTypeLabel ();

        void
        reMeshTypeLabel (const ReMeshTypeLabelType& x);

        void
        reMeshTypeLabel (::std::unique_ptr< ReMeshTypeLabelType > p);

        // minEdgeLengthLabel
        //
        typedef ::prj::srl::spt::PLabel MinEdgeLengthLabelType;
        typedef ::xsd::cxx::tree::traits< MinEdgeLengthLabelType, char > MinEdgeLengthLabelTraits;

        const MinEdgeLengthLabelType&
        minEdgeLengthLabel () const;

        MinEdgeLengthLabelType&
        minEdgeLengthLabel ();

        void
        minEdgeLengthLabel (const MinEdgeLengthLabelType& x);

        void
        minEdgeLengthLabel (::std::unique_ptr< MinEdgeLengthLabelType > p);

        // maxEdgeLengthLabel
        //
        typedef ::prj::srl::spt::PLabel MaxEdgeLengthLabelType;
        typedef ::xsd::cxx::tree::traits< MaxEdgeLengthLabelType, char > MaxEdgeLengthLabelTraits;

        const MaxEdgeLengthLabelType&
        maxEdgeLengthLabel () const;

        MaxEdgeLengthLabelType&
        maxEdgeLengthLabel ();

        void
        maxEdgeLengthLabel (const MaxEdgeLengthLabelType& x);

        void
        maxEdgeLengthLabel (::std::unique_ptr< MaxEdgeLengthLabelType > p);

        // iterationsLabel
        //
        typedef ::prj::srl::spt::PLabel IterationsLabelType;
        typedef ::xsd::cxx::tree::traits< IterationsLabelType, char > IterationsLabelTraits;

        const IterationsLabelType&
        iterationsLabel () const;

        IterationsLabelType&
        iterationsLabel ();

        void
        iterationsLabel (const IterationsLabelType& x);

        void
        iterationsLabel (::std::unique_ptr< IterationsLabelType > p);

        // Constructors.
        //
        SurfaceReMesh (const BaseType&,
                       const MeshType&,
                       const ReMeshTypeType&,
                       const MinEdgeLengthType&,
                       const MaxEdgeLengthType&,
                       const IterationsType&,
                       const ReMeshTypeLabelType&,
                       const MinEdgeLengthLabelType&,
                       const MaxEdgeLengthLabelType&,
                       const IterationsLabelType&);

        SurfaceReMesh (::std::unique_ptr< BaseType >,
                       ::std::unique_ptr< MeshType >,
                       ::std::unique_ptr< ReMeshTypeType >,
                       ::std::unique_ptr< MinEdgeLengthType >,
                       ::std::unique_ptr< MaxEdgeLengthType >,
                       ::std::unique_ptr< IterationsType >,
                       ::std::unique_ptr< ReMeshTypeLabelType >,
                       ::std::unique_ptr< MinEdgeLengthLabelType >,
                       ::std::unique_ptr< MaxEdgeLengthLabelType >,
                       ::std::unique_ptr< IterationsLabelType >);

        SurfaceReMesh (const ::xercesc::DOMElement& e,
                       ::xml_schema::Flags f = 0,
                       ::xml_schema::Container* c = 0);

        SurfaceReMesh (const SurfaceReMesh& x,
                       ::xml_schema::Flags f = 0,
                       ::xml_schema::Container* c = 0);

        virtual SurfaceReMesh*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        SurfaceReMesh&
        operator= (const SurfaceReMesh& x);

        virtual 
        ~SurfaceReMesh ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< BaseType > base_;
        ::xsd::cxx::tree::one< MeshType > mesh_;
        ::xsd::cxx::tree::one< ReMeshTypeType > reMeshType_;
        ::xsd::cxx::tree::one< MinEdgeLengthType > minEdgeLength_;
        ::xsd::cxx::tree::one< MaxEdgeLengthType > maxEdgeLength_;
        ::xsd::cxx::tree::one< IterationsType > iterations_;
        ::xsd::cxx::tree::one< ReMeshTypeLabelType > reMeshTypeLabel_;
        ::xsd::cxx::tree::one< MinEdgeLengthLabelType > minEdgeLengthLabel_;
        ::xsd::cxx::tree::one< MaxEdgeLengthLabelType > maxEdgeLengthLabel_;
        ::xsd::cxx::tree::one< IterationsLabelType > iterationsLabel_;
      };
    }
  }
}

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

namespace prj
{
  namespace srl
  {
    namespace srms
    {
      // Parse a URI or a local file.
      //

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (const ::std::string& uri,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (const ::std::string& uri,
                     ::xml_schema::ErrorHandler& eh,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (const ::std::string& uri,
                     ::xercesc::DOMErrorHandler& eh,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse std::istream.
      //

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::std::istream& is,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::std::istream& is,
                     ::xml_schema::ErrorHandler& eh,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::std::istream& is,
                     ::xercesc::DOMErrorHandler& eh,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::std::istream& is,
                     const ::std::string& id,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::std::istream& is,
                     const ::std::string& id,
                     ::xml_schema::ErrorHandler& eh,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::std::istream& is,
                     const ::std::string& id,
                     ::xercesc::DOMErrorHandler& eh,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::InputSource.
      //

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::xercesc::InputSource& is,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::xercesc::InputSource& is,
                     ::xml_schema::ErrorHandler& eh,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::xercesc::InputSource& is,
                     ::xercesc::DOMErrorHandler& eh,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::DOMDocument.
      //

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (const ::xercesc::DOMDocument& d,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::srms::SurfaceReMesh >
      surfaceremesh (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
                     ::xml_schema::Flags f = 0,
                     const ::xml_schema::Properties& p = ::xml_schema::Properties ());
    }
  }
}

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

namespace prj
{
  namespace srl
  {
    namespace srms
    {
      void
      operator<< (::xercesc::DOMElement&, const SurfaceReMesh&);

      // Serialize to std::ostream.
      //

      void
      surfaceremesh (::std::ostream& os,
                     const ::prj::srl::srms::SurfaceReMesh& x, 
                     const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                     const ::std::string& e = "UTF-8",
                     ::xml_schema::Flags f = 0);

      void
      surfaceremesh (::std::ostream& os,
                     const ::prj::srl::srms::SurfaceReMesh& x, 
                     ::xml_schema::ErrorHandler& eh,
                     const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                     const ::std::string& e = "UTF-8",
                     ::xml_schema::Flags f = 0);

      void
      surfaceremesh (::std::ostream& os,
                     const ::prj::srl::srms::SurfaceReMesh& x, 
                     ::xercesc::DOMErrorHandler& eh,
                     const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                     const ::std::string& e = "UTF-8",
                     ::xml_schema::Flags f = 0);

      // Serialize to xercesc::XMLFormatTarget.
      //

      void
      surfaceremesh (::xercesc::XMLFormatTarget& ft,
                     const ::prj::srl::srms::SurfaceReMesh& x, 
                     const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                     const ::std::string& e = "UTF-8",
                     ::xml_schema::Flags f = 0);

      void
      surfaceremesh (::xercesc::XMLFormatTarget& ft,
                     const ::prj::srl::srms::SurfaceReMesh& x, 
                     ::xml_schema::ErrorHandler& eh,
                     const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                     const ::std::string& e = "UTF-8",
                     ::xml_schema::Flags f = 0);

      void
      surfaceremesh (::xercesc::XMLFormatTarget& ft,
                     const ::prj::srl::srms::SurfaceReMesh& x, 
                     ::xercesc::DOMErrorHandler& eh,
                     const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                     const ::std::string& e = "UTF-8",
                     ::xml_schema::Flags f = 0);

      // Serialize to an existing xercesc::DOMDocument.
      //

      void
      surfaceremesh (::xercesc::DOMDocument& d,
                     const ::prj::srl::srms::SurfaceReMesh& x,
                     ::xml_schema::Flags f = 0);

      // Serialize to a new xercesc::DOMDocument.
      //

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      surfaceremesh (const ::prj::srl::srms::SurfaceReMesh& x, 
                     const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
                     ::xml_schema::Flags f = 0);
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // PRJ_SRL_SRMS_PRJSRLSRMSSURFACEREMESH_H
