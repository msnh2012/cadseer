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

#ifndef PRJ_SRL_SPT_PRJSRLSPTCOLOR_H
#define PRJ_SRL_SPT_PRJSRLSPTCOLOR_H

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
    namespace spt
    {
      class ColorValue;
      class Color;
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

namespace prj
{
  namespace srl
  {
    namespace spt
    {
      class ColorValue: public ::xsd::cxx::tree::fundamental_base< ::xml_schema::Decimal, char, ::xml_schema::SimpleType, ::xsd::cxx::tree::schema_type::decimal >
      {
        public:
        // Constructors.
        //
        ColorValue (const ::xml_schema::Decimal&);

        ColorValue (const ::xercesc::DOMElement& e,
                    ::xml_schema::Flags f = 0,
                    ::xml_schema::Container* c = 0);

        ColorValue (const ::xercesc::DOMAttr& a,
                    ::xml_schema::Flags f = 0,
                    ::xml_schema::Container* c = 0);

        ColorValue (const ::std::string& s,
                    const ::xercesc::DOMElement* e,
                    ::xml_schema::Flags f = 0,
                    ::xml_schema::Container* c = 0);

        ColorValue (const ColorValue& x,
                    ::xml_schema::Flags f = 0,
                    ::xml_schema::Container* c = 0);

        virtual ColorValue*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        virtual 
        ~ColorValue ();
      };

      class Color: public ::xml_schema::Type
      {
        public:
        // r
        //
        typedef ::prj::srl::spt::ColorValue RType;
        typedef ::xsd::cxx::tree::traits< RType, char > RTraits;

        const RType&
        r () const;

        RType&
        r ();

        void
        r (const RType& x);

        void
        r (::std::unique_ptr< RType > p);

        // g
        //
        typedef ::prj::srl::spt::ColorValue GType;
        typedef ::xsd::cxx::tree::traits< GType, char > GTraits;

        const GType&
        g () const;

        GType&
        g ();

        void
        g (const GType& x);

        void
        g (::std::unique_ptr< GType > p);

        // b
        //
        typedef ::prj::srl::spt::ColorValue BType;
        typedef ::xsd::cxx::tree::traits< BType, char > BTraits;

        const BType&
        b () const;

        BType&
        b ();

        void
        b (const BType& x);

        void
        b (::std::unique_ptr< BType > p);

        // a
        //
        typedef ::prj::srl::spt::ColorValue AType;
        typedef ::xsd::cxx::tree::traits< AType, char > ATraits;

        const AType&
        a () const;

        AType&
        a ();

        void
        a (const AType& x);

        void
        a (::std::unique_ptr< AType > p);

        // Constructors.
        //
        Color (const RType&,
               const GType&,
               const BType&,
               const AType&);

        Color (const ::xercesc::DOMElement& e,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        Color (const Color& x,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        virtual Color*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Color&
        operator= (const Color& x);

        virtual 
        ~Color ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< RType > r_;
        ::xsd::cxx::tree::one< GType > g_;
        ::xsd::cxx::tree::one< BType > b_;
        ::xsd::cxx::tree::one< AType > a_;
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
    namespace spt
    {
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
    namespace spt
    {
      void
      operator<< (::xercesc::DOMElement&, const ColorValue&);

      void
      operator<< (::xercesc::DOMAttr&, const ColorValue&);

      void
      operator<< (::xml_schema::ListStream&,
                  const ColorValue&);

      void
      operator<< (::xercesc::DOMElement&, const Color&);
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // PRJ_SRL_SPT_PRJSRLSPTCOLOR_H
