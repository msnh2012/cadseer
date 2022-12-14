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

#ifndef PRJ_SRL_RFNS_PRJSRLRFNSREFINE_H
#define PRJ_SRL_RFNS_PRJSRLRFNSREFINE_H

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
    namespace rfns
    {
      class Refine;
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
    namespace rfns
    {
      class Refine: public ::xml_schema::Type
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

        // sShape
        //
        typedef ::prj::srl::spt::SeerShape SShapeType;
        typedef ::xsd::cxx::tree::traits< SShapeType, char > SShapeTraits;

        const SShapeType&
        sShape () const;

        SShapeType&
        sShape ();

        void
        sShape (const SShapeType& x);

        void
        sShape (::std::unique_ptr< SShapeType > p);

        // shapeMap
        //
        typedef ::prj::srl::spt::EvolveRecord ShapeMapType;
        typedef ::xsd::cxx::tree::sequence< ShapeMapType > ShapeMapSequence;
        typedef ShapeMapSequence::iterator ShapeMapIterator;
        typedef ShapeMapSequence::const_iterator ShapeMapConstIterator;
        typedef ::xsd::cxx::tree::traits< ShapeMapType, char > ShapeMapTraits;

        const ShapeMapSequence&
        shapeMap () const;

        ShapeMapSequence&
        shapeMap ();

        void
        shapeMap (const ShapeMapSequence& s);

        // unifyFaces
        //
        typedef ::prj::srl::spt::Parameter UnifyFacesType;
        typedef ::xsd::cxx::tree::traits< UnifyFacesType, char > UnifyFacesTraits;

        const UnifyFacesType&
        unifyFaces () const;

        UnifyFacesType&
        unifyFaces ();

        void
        unifyFaces (const UnifyFacesType& x);

        void
        unifyFaces (::std::unique_ptr< UnifyFacesType > p);

        // unifyEdges
        //
        typedef ::prj::srl::spt::Parameter UnifyEdgesType;
        typedef ::xsd::cxx::tree::traits< UnifyEdgesType, char > UnifyEdgesTraits;

        const UnifyEdgesType&
        unifyEdges () const;

        UnifyEdgesType&
        unifyEdges ();

        void
        unifyEdges (const UnifyEdgesType& x);

        void
        unifyEdges (::std::unique_ptr< UnifyEdgesType > p);

        // concatBSplines
        //
        typedef ::prj::srl::spt::Parameter ConcatBSplinesType;
        typedef ::xsd::cxx::tree::traits< ConcatBSplinesType, char > ConcatBSplinesTraits;

        const ConcatBSplinesType&
        concatBSplines () const;

        ConcatBSplinesType&
        concatBSplines ();

        void
        concatBSplines (const ConcatBSplinesType& x);

        void
        concatBSplines (::std::unique_ptr< ConcatBSplinesType > p);

        // tightenFaces
        //
        typedef ::prj::srl::spt::Parameter TightenFacesType;
        typedef ::xsd::cxx::tree::traits< TightenFacesType, char > TightenFacesTraits;

        const TightenFacesType&
        tightenFaces () const;

        TightenFacesType&
        tightenFaces ();

        void
        tightenFaces (const TightenFacesType& x);

        void
        tightenFaces (::std::unique_ptr< TightenFacesType > p);

        // tightenEdges
        //
        typedef ::prj::srl::spt::Parameter TightenEdgesType;
        typedef ::xsd::cxx::tree::traits< TightenEdgesType, char > TightenEdgesTraits;

        const TightenEdgesType&
        tightenEdges () const;

        TightenEdgesType&
        tightenEdges ();

        void
        tightenEdges (const TightenEdgesType& x);

        void
        tightenEdges (::std::unique_ptr< TightenEdgesType > p);

        // tightenVertices
        //
        typedef ::prj::srl::spt::Parameter TightenVerticesType;
        typedef ::xsd::cxx::tree::traits< TightenVerticesType, char > TightenVerticesTraits;

        const TightenVerticesType&
        tightenVertices () const;

        TightenVerticesType&
        tightenVertices ();

        void
        tightenVertices (const TightenVerticesType& x);

        void
        tightenVertices (::std::unique_ptr< TightenVerticesType > p);

        // sameParameter
        //
        typedef ::prj::srl::spt::Parameter SameParameterType;
        typedef ::xsd::cxx::tree::traits< SameParameterType, char > SameParameterTraits;

        const SameParameterType&
        sameParameter () const;

        SameParameterType&
        sameParameter ();

        void
        sameParameter (const SameParameterType& x);

        void
        sameParameter (::std::unique_ptr< SameParameterType > p);

        // unifyFacesLabel
        //
        typedef ::prj::srl::spt::PLabel UnifyFacesLabelType;
        typedef ::xsd::cxx::tree::traits< UnifyFacesLabelType, char > UnifyFacesLabelTraits;

        const UnifyFacesLabelType&
        unifyFacesLabel () const;

        UnifyFacesLabelType&
        unifyFacesLabel ();

        void
        unifyFacesLabel (const UnifyFacesLabelType& x);

        void
        unifyFacesLabel (::std::unique_ptr< UnifyFacesLabelType > p);

        // unifyEdgesLabel
        //
        typedef ::prj::srl::spt::PLabel UnifyEdgesLabelType;
        typedef ::xsd::cxx::tree::traits< UnifyEdgesLabelType, char > UnifyEdgesLabelTraits;

        const UnifyEdgesLabelType&
        unifyEdgesLabel () const;

        UnifyEdgesLabelType&
        unifyEdgesLabel ();

        void
        unifyEdgesLabel (const UnifyEdgesLabelType& x);

        void
        unifyEdgesLabel (::std::unique_ptr< UnifyEdgesLabelType > p);

        // concatBSplinesLabel
        //
        typedef ::prj::srl::spt::PLabel ConcatBSplinesLabelType;
        typedef ::xsd::cxx::tree::traits< ConcatBSplinesLabelType, char > ConcatBSplinesLabelTraits;

        const ConcatBSplinesLabelType&
        concatBSplinesLabel () const;

        ConcatBSplinesLabelType&
        concatBSplinesLabel ();

        void
        concatBSplinesLabel (const ConcatBSplinesLabelType& x);

        void
        concatBSplinesLabel (::std::unique_ptr< ConcatBSplinesLabelType > p);

        // tightenFacesLabel
        //
        typedef ::prj::srl::spt::PLabel TightenFacesLabelType;
        typedef ::xsd::cxx::tree::traits< TightenFacesLabelType, char > TightenFacesLabelTraits;

        const TightenFacesLabelType&
        tightenFacesLabel () const;

        TightenFacesLabelType&
        tightenFacesLabel ();

        void
        tightenFacesLabel (const TightenFacesLabelType& x);

        void
        tightenFacesLabel (::std::unique_ptr< TightenFacesLabelType > p);

        // tightenEdgesLabel
        //
        typedef ::prj::srl::spt::PLabel TightenEdgesLabelType;
        typedef ::xsd::cxx::tree::traits< TightenEdgesLabelType, char > TightenEdgesLabelTraits;

        const TightenEdgesLabelType&
        tightenEdgesLabel () const;

        TightenEdgesLabelType&
        tightenEdgesLabel ();

        void
        tightenEdgesLabel (const TightenEdgesLabelType& x);

        void
        tightenEdgesLabel (::std::unique_ptr< TightenEdgesLabelType > p);

        // tightenVerticesLabel
        //
        typedef ::prj::srl::spt::PLabel TightenVerticesLabelType;
        typedef ::xsd::cxx::tree::traits< TightenVerticesLabelType, char > TightenVerticesLabelTraits;

        const TightenVerticesLabelType&
        tightenVerticesLabel () const;

        TightenVerticesLabelType&
        tightenVerticesLabel ();

        void
        tightenVerticesLabel (const TightenVerticesLabelType& x);

        void
        tightenVerticesLabel (::std::unique_ptr< TightenVerticesLabelType > p);

        // sameParameterLabel
        //
        typedef ::prj::srl::spt::PLabel SameParameterLabelType;
        typedef ::xsd::cxx::tree::traits< SameParameterLabelType, char > SameParameterLabelTraits;

        const SameParameterLabelType&
        sameParameterLabel () const;

        SameParameterLabelType&
        sameParameterLabel ();

        void
        sameParameterLabel (const SameParameterLabelType& x);

        void
        sameParameterLabel (::std::unique_ptr< SameParameterLabelType > p);

        // gridLocation
        //
        typedef ::prj::srl::spt::Vec3d GridLocationType;
        typedef ::xsd::cxx::tree::traits< GridLocationType, char > GridLocationTraits;

        const GridLocationType&
        gridLocation () const;

        GridLocationType&
        gridLocation ();

        void
        gridLocation (const GridLocationType& x);

        void
        gridLocation (::std::unique_ptr< GridLocationType > p);

        // Constructors.
        //
        Refine (const BaseType&,
                const SShapeType&,
                const UnifyFacesType&,
                const UnifyEdgesType&,
                const ConcatBSplinesType&,
                const TightenFacesType&,
                const TightenEdgesType&,
                const TightenVerticesType&,
                const SameParameterType&,
                const UnifyFacesLabelType&,
                const UnifyEdgesLabelType&,
                const ConcatBSplinesLabelType&,
                const TightenFacesLabelType&,
                const TightenEdgesLabelType&,
                const TightenVerticesLabelType&,
                const SameParameterLabelType&,
                const GridLocationType&);

        Refine (::std::unique_ptr< BaseType >,
                ::std::unique_ptr< SShapeType >,
                ::std::unique_ptr< UnifyFacesType >,
                ::std::unique_ptr< UnifyEdgesType >,
                ::std::unique_ptr< ConcatBSplinesType >,
                ::std::unique_ptr< TightenFacesType >,
                ::std::unique_ptr< TightenEdgesType >,
                ::std::unique_ptr< TightenVerticesType >,
                ::std::unique_ptr< SameParameterType >,
                ::std::unique_ptr< UnifyFacesLabelType >,
                ::std::unique_ptr< UnifyEdgesLabelType >,
                ::std::unique_ptr< ConcatBSplinesLabelType >,
                ::std::unique_ptr< TightenFacesLabelType >,
                ::std::unique_ptr< TightenEdgesLabelType >,
                ::std::unique_ptr< TightenVerticesLabelType >,
                ::std::unique_ptr< SameParameterLabelType >,
                ::std::unique_ptr< GridLocationType >);

        Refine (const ::xercesc::DOMElement& e,
                ::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0);

        Refine (const Refine& x,
                ::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0);

        virtual Refine*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Refine&
        operator= (const Refine& x);

        virtual 
        ~Refine ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< BaseType > base_;
        ::xsd::cxx::tree::one< SShapeType > sShape_;
        ShapeMapSequence shapeMap_;
        ::xsd::cxx::tree::one< UnifyFacesType > unifyFaces_;
        ::xsd::cxx::tree::one< UnifyEdgesType > unifyEdges_;
        ::xsd::cxx::tree::one< ConcatBSplinesType > concatBSplines_;
        ::xsd::cxx::tree::one< TightenFacesType > tightenFaces_;
        ::xsd::cxx::tree::one< TightenEdgesType > tightenEdges_;
        ::xsd::cxx::tree::one< TightenVerticesType > tightenVertices_;
        ::xsd::cxx::tree::one< SameParameterType > sameParameter_;
        ::xsd::cxx::tree::one< UnifyFacesLabelType > unifyFacesLabel_;
        ::xsd::cxx::tree::one< UnifyEdgesLabelType > unifyEdgesLabel_;
        ::xsd::cxx::tree::one< ConcatBSplinesLabelType > concatBSplinesLabel_;
        ::xsd::cxx::tree::one< TightenFacesLabelType > tightenFacesLabel_;
        ::xsd::cxx::tree::one< TightenEdgesLabelType > tightenEdgesLabel_;
        ::xsd::cxx::tree::one< TightenVerticesLabelType > tightenVerticesLabel_;
        ::xsd::cxx::tree::one< SameParameterLabelType > sameParameterLabel_;
        ::xsd::cxx::tree::one< GridLocationType > gridLocation_;
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
    namespace rfns
    {
      // Parse a URI or a local file.
      //

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (const ::std::string& uri,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (const ::std::string& uri,
              ::xml_schema::ErrorHandler& eh,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (const ::std::string& uri,
              ::xercesc::DOMErrorHandler& eh,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse std::istream.
      //

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::std::istream& is,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::std::istream& is,
              ::xml_schema::ErrorHandler& eh,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::std::istream& is,
              ::xercesc::DOMErrorHandler& eh,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::std::istream& is,
              const ::std::string& id,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::std::istream& is,
              const ::std::string& id,
              ::xml_schema::ErrorHandler& eh,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::std::istream& is,
              const ::std::string& id,
              ::xercesc::DOMErrorHandler& eh,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::InputSource.
      //

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::xercesc::InputSource& is,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::xercesc::InputSource& is,
              ::xml_schema::ErrorHandler& eh,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::xercesc::InputSource& is,
              ::xercesc::DOMErrorHandler& eh,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::DOMDocument.
      //

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (const ::xercesc::DOMDocument& d,
              ::xml_schema::Flags f = 0,
              const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::rfns::Refine >
      refine (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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
    namespace rfns
    {
      void
      operator<< (::xercesc::DOMElement&, const Refine&);

      // Serialize to std::ostream.
      //

      void
      refine (::std::ostream& os,
              const ::prj::srl::rfns::Refine& x, 
              const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
              const ::std::string& e = "UTF-8",
              ::xml_schema::Flags f = 0);

      void
      refine (::std::ostream& os,
              const ::prj::srl::rfns::Refine& x, 
              ::xml_schema::ErrorHandler& eh,
              const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
              const ::std::string& e = "UTF-8",
              ::xml_schema::Flags f = 0);

      void
      refine (::std::ostream& os,
              const ::prj::srl::rfns::Refine& x, 
              ::xercesc::DOMErrorHandler& eh,
              const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
              const ::std::string& e = "UTF-8",
              ::xml_schema::Flags f = 0);

      // Serialize to xercesc::XMLFormatTarget.
      //

      void
      refine (::xercesc::XMLFormatTarget& ft,
              const ::prj::srl::rfns::Refine& x, 
              const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
              const ::std::string& e = "UTF-8",
              ::xml_schema::Flags f = 0);

      void
      refine (::xercesc::XMLFormatTarget& ft,
              const ::prj::srl::rfns::Refine& x, 
              ::xml_schema::ErrorHandler& eh,
              const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
              const ::std::string& e = "UTF-8",
              ::xml_schema::Flags f = 0);

      void
      refine (::xercesc::XMLFormatTarget& ft,
              const ::prj::srl::rfns::Refine& x, 
              ::xercesc::DOMErrorHandler& eh,
              const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
              const ::std::string& e = "UTF-8",
              ::xml_schema::Flags f = 0);

      // Serialize to an existing xercesc::DOMDocument.
      //

      void
      refine (::xercesc::DOMDocument& d,
              const ::prj::srl::rfns::Refine& x,
              ::xml_schema::Flags f = 0);

      // Serialize to a new xercesc::DOMDocument.
      //

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      refine (const ::prj::srl::rfns::Refine& x, 
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

#endif // PRJ_SRL_RFNS_PRJSRLRFNSREFINE_H
