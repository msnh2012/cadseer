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

#ifndef PRJ_SRL_FCE_PRJSRLFCEFACE_H
#define PRJ_SRL_FCE_PRJSRLFCEFACE_H

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
    namespace fce
    {
      class Face;
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

#include "prjsrlsptseershape.h"

#include "prjsrlsptparameter.h"

#include "prjsrlsptbase.h"

namespace prj
{
  namespace srl
  {
    namespace fce
    {
      class Face: public ::xml_schema::Type
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

        // picks
        //
        typedef ::prj::srl::spt::Parameter PicksType;
        typedef ::xsd::cxx::tree::traits< PicksType, char > PicksTraits;

        const PicksType&
        picks () const;

        PicksType&
        picks ();

        void
        picks (const PicksType& x);

        void
        picks (::std::unique_ptr< PicksType > p);

        // seerShape
        //
        typedef ::prj::srl::spt::SeerShape SeerShapeType;
        typedef ::xsd::cxx::tree::traits< SeerShapeType, char > SeerShapeTraits;

        const SeerShapeType&
        seerShape () const;

        SeerShapeType&
        seerShape ();

        void
        seerShape (const SeerShapeType& x);

        void
        seerShape (::std::unique_ptr< SeerShapeType > p);

        // wireId
        //
        typedef ::xml_schema::String WireIdType;
        typedef ::xsd::cxx::tree::traits< WireIdType, char > WireIdTraits;

        const WireIdType&
        wireId () const;

        WireIdType&
        wireId ();

        void
        wireId (const WireIdType& x);

        void
        wireId (::std::unique_ptr< WireIdType > p);

        // faceId
        //
        typedef ::xml_schema::String FaceIdType;
        typedef ::xsd::cxx::tree::traits< FaceIdType, char > FaceIdTraits;

        const FaceIdType&
        faceId () const;

        FaceIdType&
        faceId ();

        void
        faceId (const FaceIdType& x);

        void
        faceId (::std::unique_ptr< FaceIdType > p);

        // Constructors.
        //
        Face (const BaseType&,
              const PicksType&,
              const SeerShapeType&,
              const WireIdType&,
              const FaceIdType&);

        Face (::std::unique_ptr< BaseType >,
              ::std::unique_ptr< PicksType >,
              ::std::unique_ptr< SeerShapeType >,
              const WireIdType&,
              const FaceIdType&);

        Face (const ::xercesc::DOMElement& e,
              ::xml_schema::Flags f = 0,
              ::xml_schema::Container* c = 0);

        Face (const Face& x,
              ::xml_schema::Flags f = 0,
              ::xml_schema::Container* c = 0);

        virtual Face*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Face&
        operator= (const Face& x);

        virtual 
        ~Face ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< BaseType > base_;
        ::xsd::cxx::tree::one< PicksType > picks_;
        ::xsd::cxx::tree::one< SeerShapeType > seerShape_;
        ::xsd::cxx::tree::one< WireIdType > wireId_;
        ::xsd::cxx::tree::one< FaceIdType > faceId_;
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
    namespace fce
    {
      // Parse a URI or a local file.
      //

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (const ::std::string& uri,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (const ::std::string& uri,
            ::xml_schema::ErrorHandler& eh,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (const ::std::string& uri,
            ::xercesc::DOMErrorHandler& eh,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse std::istream.
      //

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::std::istream& is,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::std::istream& is,
            ::xml_schema::ErrorHandler& eh,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::std::istream& is,
            ::xercesc::DOMErrorHandler& eh,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::std::istream& is,
            const ::std::string& id,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::std::istream& is,
            const ::std::string& id,
            ::xml_schema::ErrorHandler& eh,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::std::istream& is,
            const ::std::string& id,
            ::xercesc::DOMErrorHandler& eh,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::InputSource.
      //

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::xercesc::InputSource& is,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::xercesc::InputSource& is,
            ::xml_schema::ErrorHandler& eh,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::xercesc::InputSource& is,
            ::xercesc::DOMErrorHandler& eh,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::DOMDocument.
      //

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (const ::xercesc::DOMDocument& d,
            ::xml_schema::Flags f = 0,
            const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::fce::Face >
      face (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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
    namespace fce
    {
      void
      operator<< (::xercesc::DOMElement&, const Face&);

      // Serialize to std::ostream.
      //

      void
      face (::std::ostream& os,
            const ::prj::srl::fce::Face& x, 
            const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
            const ::std::string& e = "UTF-8",
            ::xml_schema::Flags f = 0);

      void
      face (::std::ostream& os,
            const ::prj::srl::fce::Face& x, 
            ::xml_schema::ErrorHandler& eh,
            const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
            const ::std::string& e = "UTF-8",
            ::xml_schema::Flags f = 0);

      void
      face (::std::ostream& os,
            const ::prj::srl::fce::Face& x, 
            ::xercesc::DOMErrorHandler& eh,
            const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
            const ::std::string& e = "UTF-8",
            ::xml_schema::Flags f = 0);

      // Serialize to xercesc::XMLFormatTarget.
      //

      void
      face (::xercesc::XMLFormatTarget& ft,
            const ::prj::srl::fce::Face& x, 
            const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
            const ::std::string& e = "UTF-8",
            ::xml_schema::Flags f = 0);

      void
      face (::xercesc::XMLFormatTarget& ft,
            const ::prj::srl::fce::Face& x, 
            ::xml_schema::ErrorHandler& eh,
            const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
            const ::std::string& e = "UTF-8",
            ::xml_schema::Flags f = 0);

      void
      face (::xercesc::XMLFormatTarget& ft,
            const ::prj::srl::fce::Face& x, 
            ::xercesc::DOMErrorHandler& eh,
            const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
            const ::std::string& e = "UTF-8",
            ::xml_schema::Flags f = 0);

      // Serialize to an existing xercesc::DOMDocument.
      //

      void
      face (::xercesc::DOMDocument& d,
            const ::prj::srl::fce::Face& x,
            ::xml_schema::Flags f = 0);

      // Serialize to a new xercesc::DOMDocument.
      //

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      face (const ::prj::srl::fce::Face& x, 
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

#endif // PRJ_SRL_FCE_PRJSRLFCEFACE_H
