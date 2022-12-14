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

#ifndef PRJ_SRL_PRSM_PRJSRLPRSMPRISM_H
#define PRJ_SRL_PRSM_PRJSRLPRSMPRISM_H

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
    namespace prsm
    {
      class Prism;
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
    namespace prsm
    {
      class Prism: public ::xml_schema::Type
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

        // radiusType
        //
        typedef ::prj::srl::spt::Parameter RadiusTypeType;
        typedef ::xsd::cxx::tree::traits< RadiusTypeType, char > RadiusTypeTraits;

        const RadiusTypeType&
        radiusType () const;

        RadiusTypeType&
        radiusType ();

        void
        radiusType (const RadiusTypeType& x);

        void
        radiusType (::std::unique_ptr< RadiusTypeType > p);

        // sides
        //
        typedef ::prj::srl::spt::Parameter SidesType;
        typedef ::xsd::cxx::tree::traits< SidesType, char > SidesTraits;

        const SidesType&
        sides () const;

        SidesType&
        sides ();

        void
        sides (const SidesType& x);

        void
        sides (::std::unique_ptr< SidesType > p);

        // pyramid
        //
        typedef ::prj::srl::spt::Parameter PyramidType;
        typedef ::xsd::cxx::tree::traits< PyramidType, char > PyramidTraits;

        const PyramidType&
        pyramid () const;

        PyramidType&
        pyramid ();

        void
        pyramid (const PyramidType& x);

        void
        pyramid (::std::unique_ptr< PyramidType > p);

        // radius
        //
        typedef ::prj::srl::spt::Parameter RadiusType;
        typedef ::xsd::cxx::tree::traits< RadiusType, char > RadiusTraits;

        const RadiusType&
        radius () const;

        RadiusType&
        radius ();

        void
        radius (const RadiusType& x);

        void
        radius (::std::unique_ptr< RadiusType > p);

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

        // radiusIP
        //
        typedef ::prj::srl::spt::IPGroup RadiusIPType;
        typedef ::xsd::cxx::tree::traits< RadiusIPType, char > RadiusIPTraits;

        const RadiusIPType&
        radiusIP () const;

        RadiusIPType&
        radiusIP ();

        void
        radiusIP (const RadiusIPType& x);

        void
        radiusIP (::std::unique_ptr< RadiusIPType > p);

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

        // radiusTypeLabel
        //
        typedef ::prj::srl::spt::PLabel RadiusTypeLabelType;
        typedef ::xsd::cxx::tree::traits< RadiusTypeLabelType, char > RadiusTypeLabelTraits;

        const RadiusTypeLabelType&
        radiusTypeLabel () const;

        RadiusTypeLabelType&
        radiusTypeLabel ();

        void
        radiusTypeLabel (const RadiusTypeLabelType& x);

        void
        radiusTypeLabel (::std::unique_ptr< RadiusTypeLabelType > p);

        // sidesLabel
        //
        typedef ::prj::srl::spt::PLabel SidesLabelType;
        typedef ::xsd::cxx::tree::traits< SidesLabelType, char > SidesLabelTraits;

        const SidesLabelType&
        sidesLabel () const;

        SidesLabelType&
        sidesLabel ();

        void
        sidesLabel (const SidesLabelType& x);

        void
        sidesLabel (::std::unique_ptr< SidesLabelType > p);

        // pyramidLabel
        //
        typedef ::prj::srl::spt::PLabel PyramidLabelType;
        typedef ::xsd::cxx::tree::traits< PyramidLabelType, char > PyramidLabelTraits;

        const PyramidLabelType&
        pyramidLabel () const;

        PyramidLabelType&
        pyramidLabel ();

        void
        pyramidLabel (const PyramidLabelType& x);

        void
        pyramidLabel (::std::unique_ptr< PyramidLabelType > p);

        // apexId
        //
        typedef ::xml_schema::String ApexIdType;
        typedef ::xsd::cxx::tree::traits< ApexIdType, char > ApexIdTraits;

        const ApexIdType&
        apexId () const;

        ApexIdType&
        apexId ();

        void
        apexId (const ApexIdType& x);

        void
        apexId (::std::unique_ptr< ApexIdType > p);

        // bottomWireId
        //
        typedef ::xml_schema::String BottomWireIdType;
        typedef ::xsd::cxx::tree::traits< BottomWireIdType, char > BottomWireIdTraits;

        const BottomWireIdType&
        bottomWireId () const;

        BottomWireIdType&
        bottomWireId ();

        void
        bottomWireId (const BottomWireIdType& x);

        void
        bottomWireId (::std::unique_ptr< BottomWireIdType > p);

        // topWireId
        //
        typedef ::xml_schema::String TopWireIdType;
        typedef ::xsd::cxx::tree::traits< TopWireIdType, char > TopWireIdTraits;

        const TopWireIdType&
        topWireId () const;

        TopWireIdType&
        topWireId ();

        void
        topWireId (const TopWireIdType& x);

        void
        topWireId (::std::unique_ptr< TopWireIdType > p);

        // bottomFaceId
        //
        typedef ::xml_schema::String BottomFaceIdType;
        typedef ::xsd::cxx::tree::traits< BottomFaceIdType, char > BottomFaceIdTraits;

        const BottomFaceIdType&
        bottomFaceId () const;

        BottomFaceIdType&
        bottomFaceId ();

        void
        bottomFaceId (const BottomFaceIdType& x);

        void
        bottomFaceId (::std::unique_ptr< BottomFaceIdType > p);

        // topFaceId
        //
        typedef ::xml_schema::String TopFaceIdType;
        typedef ::xsd::cxx::tree::traits< TopFaceIdType, char > TopFaceIdTraits;

        const TopFaceIdType&
        topFaceId () const;

        TopFaceIdType&
        topFaceId ();

        void
        topFaceId (const TopFaceIdType& x);

        void
        topFaceId (::std::unique_ptr< TopFaceIdType > p);

        // shellId
        //
        typedef ::xml_schema::String ShellIdType;
        typedef ::xsd::cxx::tree::traits< ShellIdType, char > ShellIdTraits;

        const ShellIdType&
        shellId () const;

        ShellIdType&
        shellId ();

        void
        shellId (const ShellIdType& x);

        void
        shellId (::std::unique_ptr< ShellIdType > p);

        // solidId
        //
        typedef ::xml_schema::String SolidIdType;
        typedef ::xsd::cxx::tree::traits< SolidIdType, char > SolidIdTraits;

        const SolidIdType&
        solidId () const;

        SolidIdType&
        solidId ();

        void
        solidId (const SolidIdType& x);

        void
        solidId (::std::unique_ptr< SolidIdType > p);

        // bottomVertexIds
        //
        typedef ::xml_schema::String BottomVertexIdsType;
        typedef ::xsd::cxx::tree::sequence< BottomVertexIdsType > BottomVertexIdsSequence;
        typedef BottomVertexIdsSequence::iterator BottomVertexIdsIterator;
        typedef BottomVertexIdsSequence::const_iterator BottomVertexIdsConstIterator;
        typedef ::xsd::cxx::tree::traits< BottomVertexIdsType, char > BottomVertexIdsTraits;

        const BottomVertexIdsSequence&
        bottomVertexIds () const;

        BottomVertexIdsSequence&
        bottomVertexIds ();

        void
        bottomVertexIds (const BottomVertexIdsSequence& s);

        // topVertexIds
        //
        typedef ::xml_schema::String TopVertexIdsType;
        typedef ::xsd::cxx::tree::sequence< TopVertexIdsType > TopVertexIdsSequence;
        typedef TopVertexIdsSequence::iterator TopVertexIdsIterator;
        typedef TopVertexIdsSequence::const_iterator TopVertexIdsConstIterator;
        typedef ::xsd::cxx::tree::traits< TopVertexIdsType, char > TopVertexIdsTraits;

        const TopVertexIdsSequence&
        topVertexIds () const;

        TopVertexIdsSequence&
        topVertexIds ();

        void
        topVertexIds (const TopVertexIdsSequence& s);

        // bottomEdgeIds
        //
        typedef ::xml_schema::String BottomEdgeIdsType;
        typedef ::xsd::cxx::tree::sequence< BottomEdgeIdsType > BottomEdgeIdsSequence;
        typedef BottomEdgeIdsSequence::iterator BottomEdgeIdsIterator;
        typedef BottomEdgeIdsSequence::const_iterator BottomEdgeIdsConstIterator;
        typedef ::xsd::cxx::tree::traits< BottomEdgeIdsType, char > BottomEdgeIdsTraits;

        const BottomEdgeIdsSequence&
        bottomEdgeIds () const;

        BottomEdgeIdsSequence&
        bottomEdgeIds ();

        void
        bottomEdgeIds (const BottomEdgeIdsSequence& s);

        // topEdgeIds
        //
        typedef ::xml_schema::String TopEdgeIdsType;
        typedef ::xsd::cxx::tree::sequence< TopEdgeIdsType > TopEdgeIdsSequence;
        typedef TopEdgeIdsSequence::iterator TopEdgeIdsIterator;
        typedef TopEdgeIdsSequence::const_iterator TopEdgeIdsConstIterator;
        typedef ::xsd::cxx::tree::traits< TopEdgeIdsType, char > TopEdgeIdsTraits;

        const TopEdgeIdsSequence&
        topEdgeIds () const;

        TopEdgeIdsSequence&
        topEdgeIds ();

        void
        topEdgeIds (const TopEdgeIdsSequence& s);

        // verticalEdgeIds
        //
        typedef ::xml_schema::String VerticalEdgeIdsType;
        typedef ::xsd::cxx::tree::sequence< VerticalEdgeIdsType > VerticalEdgeIdsSequence;
        typedef VerticalEdgeIdsSequence::iterator VerticalEdgeIdsIterator;
        typedef VerticalEdgeIdsSequence::const_iterator VerticalEdgeIdsConstIterator;
        typedef ::xsd::cxx::tree::traits< VerticalEdgeIdsType, char > VerticalEdgeIdsTraits;

        const VerticalEdgeIdsSequence&
        verticalEdgeIds () const;

        VerticalEdgeIdsSequence&
        verticalEdgeIds ();

        void
        verticalEdgeIds (const VerticalEdgeIdsSequence& s);

        // wireIds
        //
        typedef ::xml_schema::String WireIdsType;
        typedef ::xsd::cxx::tree::sequence< WireIdsType > WireIdsSequence;
        typedef WireIdsSequence::iterator WireIdsIterator;
        typedef WireIdsSequence::const_iterator WireIdsConstIterator;
        typedef ::xsd::cxx::tree::traits< WireIdsType, char > WireIdsTraits;

        const WireIdsSequence&
        wireIds () const;

        WireIdsSequence&
        wireIds ();

        void
        wireIds (const WireIdsSequence& s);

        // faceIds
        //
        typedef ::xml_schema::String FaceIdsType;
        typedef ::xsd::cxx::tree::sequence< FaceIdsType > FaceIdsSequence;
        typedef FaceIdsSequence::iterator FaceIdsIterator;
        typedef FaceIdsSequence::const_iterator FaceIdsConstIterator;
        typedef ::xsd::cxx::tree::traits< FaceIdsType, char > FaceIdsTraits;

        const FaceIdsSequence&
        faceIds () const;

        FaceIdsSequence&
        faceIds ();

        void
        faceIds (const FaceIdsSequence& s);

        // Constructors.
        //
        Prism (const BaseType&,
               const RadiusTypeType&,
               const SidesType&,
               const PyramidType&,
               const RadiusType&,
               const HeightType&,
               const CsysTypeType&,
               const CsysType&,
               const CsysLinkedType&,
               const CsysDraggerType&,
               const SeerShapeType&,
               const RadiusIPType&,
               const HeightIPType&,
               const RadiusTypeLabelType&,
               const SidesLabelType&,
               const PyramidLabelType&,
               const ApexIdType&,
               const BottomWireIdType&,
               const TopWireIdType&,
               const BottomFaceIdType&,
               const TopFaceIdType&,
               const ShellIdType&,
               const SolidIdType&);

        Prism (::std::unique_ptr< BaseType >,
               ::std::unique_ptr< RadiusTypeType >,
               ::std::unique_ptr< SidesType >,
               ::std::unique_ptr< PyramidType >,
               ::std::unique_ptr< RadiusType >,
               ::std::unique_ptr< HeightType >,
               ::std::unique_ptr< CsysTypeType >,
               ::std::unique_ptr< CsysType >,
               ::std::unique_ptr< CsysLinkedType >,
               ::std::unique_ptr< CsysDraggerType >,
               ::std::unique_ptr< SeerShapeType >,
               ::std::unique_ptr< RadiusIPType >,
               ::std::unique_ptr< HeightIPType >,
               ::std::unique_ptr< RadiusTypeLabelType >,
               ::std::unique_ptr< SidesLabelType >,
               ::std::unique_ptr< PyramidLabelType >,
               const ApexIdType&,
               const BottomWireIdType&,
               const TopWireIdType&,
               const BottomFaceIdType&,
               const TopFaceIdType&,
               const ShellIdType&,
               const SolidIdType&);

        Prism (const ::xercesc::DOMElement& e,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        Prism (const Prism& x,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        virtual Prism*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Prism&
        operator= (const Prism& x);

        virtual 
        ~Prism ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< BaseType > base_;
        ::xsd::cxx::tree::one< RadiusTypeType > radiusType_;
        ::xsd::cxx::tree::one< SidesType > sides_;
        ::xsd::cxx::tree::one< PyramidType > pyramid_;
        ::xsd::cxx::tree::one< RadiusType > radius_;
        ::xsd::cxx::tree::one< HeightType > height_;
        ::xsd::cxx::tree::one< CsysTypeType > csysType_;
        ::xsd::cxx::tree::one< CsysType > csys_;
        ::xsd::cxx::tree::one< CsysLinkedType > csysLinked_;
        ::xsd::cxx::tree::one< CsysDraggerType > csysDragger_;
        ::xsd::cxx::tree::one< SeerShapeType > seerShape_;
        ::xsd::cxx::tree::one< RadiusIPType > radiusIP_;
        ::xsd::cxx::tree::one< HeightIPType > heightIP_;
        ::xsd::cxx::tree::one< RadiusTypeLabelType > radiusTypeLabel_;
        ::xsd::cxx::tree::one< SidesLabelType > sidesLabel_;
        ::xsd::cxx::tree::one< PyramidLabelType > pyramidLabel_;
        ::xsd::cxx::tree::one< ApexIdType > apexId_;
        ::xsd::cxx::tree::one< BottomWireIdType > bottomWireId_;
        ::xsd::cxx::tree::one< TopWireIdType > topWireId_;
        ::xsd::cxx::tree::one< BottomFaceIdType > bottomFaceId_;
        ::xsd::cxx::tree::one< TopFaceIdType > topFaceId_;
        ::xsd::cxx::tree::one< ShellIdType > shellId_;
        ::xsd::cxx::tree::one< SolidIdType > solidId_;
        BottomVertexIdsSequence bottomVertexIds_;
        TopVertexIdsSequence topVertexIds_;
        BottomEdgeIdsSequence bottomEdgeIds_;
        TopEdgeIdsSequence topEdgeIds_;
        VerticalEdgeIdsSequence verticalEdgeIds_;
        WireIdsSequence wireIds_;
        FaceIdsSequence faceIds_;
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
    namespace prsm
    {
      // Parse a URI or a local file.
      //

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (const ::std::string& uri,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (const ::std::string& uri,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (const ::std::string& uri,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse std::istream.
      //

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::std::istream& is,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::std::istream& is,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::std::istream& is,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::std::istream& is,
             const ::std::string& id,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::std::istream& is,
             const ::std::string& id,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::std::istream& is,
             const ::std::string& id,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::InputSource.
      //

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::xercesc::InputSource& is,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::xercesc::InputSource& is,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::xercesc::InputSource& is,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::DOMDocument.
      //

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (const ::xercesc::DOMDocument& d,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::prsm::Prism >
      prism (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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
    namespace prsm
    {
      void
      operator<< (::xercesc::DOMElement&, const Prism&);

      // Serialize to std::ostream.
      //

      void
      prism (::std::ostream& os,
             const ::prj::srl::prsm::Prism& x, 
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      prism (::std::ostream& os,
             const ::prj::srl::prsm::Prism& x, 
             ::xml_schema::ErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      prism (::std::ostream& os,
             const ::prj::srl::prsm::Prism& x, 
             ::xercesc::DOMErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      // Serialize to xercesc::XMLFormatTarget.
      //

      void
      prism (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::prsm::Prism& x, 
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      prism (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::prsm::Prism& x, 
             ::xml_schema::ErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      prism (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::prsm::Prism& x, 
             ::xercesc::DOMErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      // Serialize to an existing xercesc::DOMDocument.
      //

      void
      prism (::xercesc::DOMDocument& d,
             const ::prj::srl::prsm::Prism& x,
             ::xml_schema::Flags f = 0);

      // Serialize to a new xercesc::DOMDocument.
      //

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      prism (const ::prj::srl::prsm::Prism& x, 
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

#endif // PRJ_SRL_PRSM_PRJSRLPRSMPRISM_H
