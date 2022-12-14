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

#ifndef PRJ_SRL_BXS_PRJSRLBXSBOX_H
#define PRJ_SRL_BXS_PRJSRLBXSBOX_H

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
    namespace bxs
    {
      class Box;
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

#include "prjsrlsptparameter.h"

#include "prjsrlsptoverlay.h"

#include "prjsrlsptseershape.h"

#include "prjsrlsptbase.h"

namespace prj
{
  namespace srl
  {
    namespace bxs
    {
      class Box: public ::xml_schema::Type
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

        // csysType
        //
        typedef ::prj::srl::spt::Parameter CsysTypeType;
        typedef ::xsd::cxx::tree::traits< CsysTypeType, char > CsysTypeTraits;

        const CsysTypeType&
        csysType () const;

        CsysTypeType&
        csysType ();

        void
        csysType (const CsysTypeType& x);

        void
        csysType (::std::unique_ptr< CsysTypeType > p);

        // length
        //
        typedef ::prj::srl::spt::Parameter LengthType;
        typedef ::xsd::cxx::tree::traits< LengthType, char > LengthTraits;

        const LengthType&
        length () const;

        LengthType&
        length ();

        void
        length (const LengthType& x);

        void
        length (::std::unique_ptr< LengthType > p);

        // width
        //
        typedef ::prj::srl::spt::Parameter WidthType;
        typedef ::xsd::cxx::tree::traits< WidthType, char > WidthTraits;

        const WidthType&
        width () const;

        WidthType&
        width ();

        void
        width (const WidthType& x);

        void
        width (::std::unique_ptr< WidthType > p);

        // height
        //
        typedef ::prj::srl::spt::Parameter HeightType;
        typedef ::xsd::cxx::tree::traits< HeightType, char > HeightTraits;

        const HeightType&
        height () const;

        HeightType&
        height ();

        void
        height (const HeightType& x);

        void
        height (::std::unique_ptr< HeightType > p);

        // csys
        //
        typedef ::prj::srl::spt::Parameter CsysType;
        typedef ::xsd::cxx::tree::traits< CsysType, char > CsysTraits;

        const CsysType&
        csys () const;

        CsysType&
        csys ();

        void
        csys (const CsysType& x);

        void
        csys (::std::unique_ptr< CsysType > p);

        // csysLinked
        //
        typedef ::prj::srl::spt::Parameter CsysLinkedType;
        typedef ::xsd::cxx::tree::traits< CsysLinkedType, char > CsysLinkedTraits;

        const CsysLinkedType&
        csysLinked () const;

        CsysLinkedType&
        csysLinked ();

        void
        csysLinked (const CsysLinkedType& x);

        void
        csysLinked (::std::unique_ptr< CsysLinkedType > p);

        // csysDragger
        //
        typedef ::prj::srl::spt::CSysDragger CsysDraggerType;
        typedef ::xsd::cxx::tree::traits< CsysDraggerType, char > CsysDraggerTraits;

        const CsysDraggerType&
        csysDragger () const;

        CsysDraggerType&
        csysDragger ();

        void
        csysDragger (const CsysDraggerType& x);

        void
        csysDragger (::std::unique_ptr< CsysDraggerType > p);

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

        // lengthIP
        //
        typedef ::prj::srl::spt::IPGroup LengthIPType;
        typedef ::xsd::cxx::tree::traits< LengthIPType, char > LengthIPTraits;

        const LengthIPType&
        lengthIP () const;

        LengthIPType&
        lengthIP ();

        void
        lengthIP (const LengthIPType& x);

        void
        lengthIP (::std::unique_ptr< LengthIPType > p);

        // widthIP
        //
        typedef ::prj::srl::spt::IPGroup WidthIPType;
        typedef ::xsd::cxx::tree::traits< WidthIPType, char > WidthIPTraits;

        const WidthIPType&
        widthIP () const;

        WidthIPType&
        widthIP ();

        void
        widthIP (const WidthIPType& x);

        void
        widthIP (::std::unique_ptr< WidthIPType > p);

        // heightIP
        //
        typedef ::prj::srl::spt::IPGroup HeightIPType;
        typedef ::xsd::cxx::tree::traits< HeightIPType, char > HeightIPTraits;

        const HeightIPType&
        heightIP () const;

        HeightIPType&
        heightIP ();

        void
        heightIP (const HeightIPType& x);

        void
        heightIP (::std::unique_ptr< HeightIPType > p);

        // Constructors.
        //
        Box (const BaseType&,
             const CsysTypeType&,
             const LengthType&,
             const WidthType&,
             const HeightType&,
             const CsysType&,
             const CsysLinkedType&,
             const CsysDraggerType&,
             const SeerShapeType&,
             const LengthIPType&,
             const WidthIPType&,
             const HeightIPType&);

        Box (::std::unique_ptr< BaseType >,
             ::std::unique_ptr< CsysTypeType >,
             ::std::unique_ptr< LengthType >,
             ::std::unique_ptr< WidthType >,
             ::std::unique_ptr< HeightType >,
             ::std::unique_ptr< CsysType >,
             ::std::unique_ptr< CsysLinkedType >,
             ::std::unique_ptr< CsysDraggerType >,
             ::std::unique_ptr< SeerShapeType >,
             ::std::unique_ptr< LengthIPType >,
             ::std::unique_ptr< WidthIPType >,
             ::std::unique_ptr< HeightIPType >);

        Box (const ::xercesc::DOMElement& e,
             ::xml_schema::Flags f = 0,
             ::xml_schema::Container* c = 0);

        Box (const Box& x,
             ::xml_schema::Flags f = 0,
             ::xml_schema::Container* c = 0);

        virtual Box*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Box&
        operator= (const Box& x);

        virtual 
        ~Box ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< BaseType > base_;
        ::xsd::cxx::tree::one< CsysTypeType > csysType_;
        ::xsd::cxx::tree::one< LengthType > length_;
        ::xsd::cxx::tree::one< WidthType > width_;
        ::xsd::cxx::tree::one< HeightType > height_;
        ::xsd::cxx::tree::one< CsysType > csys_;
        ::xsd::cxx::tree::one< CsysLinkedType > csysLinked_;
        ::xsd::cxx::tree::one< CsysDraggerType > csysDragger_;
        ::xsd::cxx::tree::one< SeerShapeType > seerShape_;
        ::xsd::cxx::tree::one< LengthIPType > lengthIP_;
        ::xsd::cxx::tree::one< WidthIPType > widthIP_;
        ::xsd::cxx::tree::one< HeightIPType > heightIP_;
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
    namespace bxs
    {
      // Parse a URI or a local file.
      //

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (const ::std::string& uri,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (const ::std::string& uri,
           ::xml_schema::ErrorHandler& eh,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (const ::std::string& uri,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse std::istream.
      //

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           ::xml_schema::ErrorHandler& eh,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           const ::std::string& id,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           const ::std::string& id,
           ::xml_schema::ErrorHandler& eh,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           const ::std::string& id,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::InputSource.
      //

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::xercesc::InputSource& is,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::xercesc::InputSource& is,
           ::xml_schema::ErrorHandler& eh,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::xercesc::InputSource& is,
           ::xercesc::DOMErrorHandler& eh,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::DOMDocument.
      //

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (const ::xercesc::DOMDocument& d,
           ::xml_schema::Flags f = 0,
           const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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
    namespace bxs
    {
      void
      operator<< (::xercesc::DOMElement&, const Box&);

      // Serialize to std::ostream.
      //

      void
      box (::std::ostream& os,
           const ::prj::srl::bxs::Box& x, 
           const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
           const ::std::string& e = "UTF-8",
           ::xml_schema::Flags f = 0);

      void
      box (::std::ostream& os,
           const ::prj::srl::bxs::Box& x, 
           ::xml_schema::ErrorHandler& eh,
           const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
           const ::std::string& e = "UTF-8",
           ::xml_schema::Flags f = 0);

      void
      box (::std::ostream& os,
           const ::prj::srl::bxs::Box& x, 
           ::xercesc::DOMErrorHandler& eh,
           const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
           const ::std::string& e = "UTF-8",
           ::xml_schema::Flags f = 0);

      // Serialize to xercesc::XMLFormatTarget.
      //

      void
      box (::xercesc::XMLFormatTarget& ft,
           const ::prj::srl::bxs::Box& x, 
           const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
           const ::std::string& e = "UTF-8",
           ::xml_schema::Flags f = 0);

      void
      box (::xercesc::XMLFormatTarget& ft,
           const ::prj::srl::bxs::Box& x, 
           ::xml_schema::ErrorHandler& eh,
           const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
           const ::std::string& e = "UTF-8",
           ::xml_schema::Flags f = 0);

      void
      box (::xercesc::XMLFormatTarget& ft,
           const ::prj::srl::bxs::Box& x, 
           ::xercesc::DOMErrorHandler& eh,
           const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
           const ::std::string& e = "UTF-8",
           ::xml_schema::Flags f = 0);

      // Serialize to an existing xercesc::DOMDocument.
      //

      void
      box (::xercesc::DOMDocument& d,
           const ::prj::srl::bxs::Box& x,
           ::xml_schema::Flags f = 0);

      // Serialize to a new xercesc::DOMDocument.
      //

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      box (const ::prj::srl::bxs::Box& x, 
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

#endif // PRJ_SRL_BXS_PRJSRLBXSBOX_H
