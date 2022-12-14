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

#ifndef PRJ_SRL_BLNS_PRJSRLBLNSBLEND_H
#define PRJ_SRL_BLNS_PRJSRLBLNSBLEND_H

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
    namespace blns
    {
      class Constant;
      class Entry;
      class Variable;
      class Blend;
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
    namespace blns
    {
      class Constant: public ::xml_schema::Type
      {
        public:
        // contourPicks
        //
        typedef ::prj::srl::spt::Parameter ContourPicksType;
        typedef ::xsd::cxx::tree::traits< ContourPicksType, char > ContourPicksTraits;

        const ContourPicksType&
        contourPicks () const;

        ContourPicksType&
        contourPicks ();

        void
        contourPicks (const ContourPicksType& x);

        void
        contourPicks (::std::unique_ptr< ContourPicksType > p);

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

        // radiusLabel
        //
        typedef ::prj::srl::spt::PLabel RadiusLabelType;
        typedef ::xsd::cxx::tree::traits< RadiusLabelType, char > RadiusLabelTraits;

        const RadiusLabelType&
        radiusLabel () const;

        RadiusLabelType&
        radiusLabel ();

        void
        radiusLabel (const RadiusLabelType& x);

        void
        radiusLabel (::std::unique_ptr< RadiusLabelType > p);

        // Constructors.
        //
        Constant (const ContourPicksType&,
                  const RadiusType&,
                  const RadiusLabelType&);

        Constant (::std::unique_ptr< ContourPicksType >,
                  ::std::unique_ptr< RadiusType >,
                  ::std::unique_ptr< RadiusLabelType >);

        Constant (const ::xercesc::DOMElement& e,
                  ::xml_schema::Flags f = 0,
                  ::xml_schema::Container* c = 0);

        Constant (const Constant& x,
                  ::xml_schema::Flags f = 0,
                  ::xml_schema::Container* c = 0);

        virtual Constant*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Constant&
        operator= (const Constant& x);

        virtual 
        ~Constant ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< ContourPicksType > contourPicks_;
        ::xsd::cxx::tree::one< RadiusType > radius_;
        ::xsd::cxx::tree::one< RadiusLabelType > radiusLabel_;
      };

      class Entry: public ::xml_schema::Type
      {
        public:
        // entryPick
        //
        typedef ::prj::srl::spt::Parameter EntryPickType;
        typedef ::xsd::cxx::tree::traits< EntryPickType, char > EntryPickTraits;

        const EntryPickType&
        entryPick () const;

        EntryPickType&
        entryPick ();

        void
        entryPick (const EntryPickType& x);

        void
        entryPick (::std::unique_ptr< EntryPickType > p);

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

        // position
        //
        typedef ::prj::srl::spt::Parameter PositionType;
        typedef ::xsd::cxx::tree::traits< PositionType, char > PositionTraits;

        const PositionType&
        position () const;

        PositionType&
        position ();

        void
        position (const PositionType& x);

        void
        position (::std::unique_ptr< PositionType > p);

        // radiusLabel
        //
        typedef ::prj::srl::spt::PLabel RadiusLabelType;
        typedef ::xsd::cxx::tree::traits< RadiusLabelType, char > RadiusLabelTraits;

        const RadiusLabelType&
        radiusLabel () const;

        RadiusLabelType&
        radiusLabel ();

        void
        radiusLabel (const RadiusLabelType& x);

        void
        radiusLabel (::std::unique_ptr< RadiusLabelType > p);

        // positionLabel
        //
        typedef ::prj::srl::spt::PLabel PositionLabelType;
        typedef ::xsd::cxx::tree::traits< PositionLabelType, char > PositionLabelTraits;

        const PositionLabelType&
        positionLabel () const;

        PositionLabelType&
        positionLabel ();

        void
        positionLabel (const PositionLabelType& x);

        void
        positionLabel (::std::unique_ptr< PositionLabelType > p);

        // Constructors.
        //
        Entry (const EntryPickType&,
               const RadiusType&,
               const PositionType&,
               const RadiusLabelType&,
               const PositionLabelType&);

        Entry (::std::unique_ptr< EntryPickType >,
               ::std::unique_ptr< RadiusType >,
               ::std::unique_ptr< PositionType >,
               ::std::unique_ptr< RadiusLabelType >,
               ::std::unique_ptr< PositionLabelType >);

        Entry (const ::xercesc::DOMElement& e,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        Entry (const Entry& x,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        virtual Entry*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Entry&
        operator= (const Entry& x);

        virtual 
        ~Entry ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< EntryPickType > entryPick_;
        ::xsd::cxx::tree::one< RadiusType > radius_;
        ::xsd::cxx::tree::one< PositionType > position_;
        ::xsd::cxx::tree::one< RadiusLabelType > radiusLabel_;
        ::xsd::cxx::tree::one< PositionLabelType > positionLabel_;
      };

      class Variable: public ::xml_schema::Type
      {
        public:
        // contourPicks
        //
        typedef ::prj::srl::spt::Parameter ContourPicksType;
        typedef ::xsd::cxx::tree::traits< ContourPicksType, char > ContourPicksTraits;

        const ContourPicksType&
        contourPicks () const;

        ContourPicksType&
        contourPicks ();

        void
        contourPicks (const ContourPicksType& x);

        void
        contourPicks (::std::unique_ptr< ContourPicksType > p);

        // entries
        //
        typedef ::prj::srl::blns::Entry EntriesType;
        typedef ::xsd::cxx::tree::sequence< EntriesType > EntriesSequence;
        typedef EntriesSequence::iterator EntriesIterator;
        typedef EntriesSequence::const_iterator EntriesConstIterator;
        typedef ::xsd::cxx::tree::traits< EntriesType, char > EntriesTraits;

        const EntriesSequence&
        entries () const;

        EntriesSequence&
        entries ();

        void
        entries (const EntriesSequence& s);

        // Constructors.
        //
        Variable (const ContourPicksType&);

        Variable (::std::unique_ptr< ContourPicksType >);

        Variable (const ::xercesc::DOMElement& e,
                  ::xml_schema::Flags f = 0,
                  ::xml_schema::Container* c = 0);

        Variable (const Variable& x,
                  ::xml_schema::Flags f = 0,
                  ::xml_schema::Container* c = 0);

        virtual Variable*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Variable&
        operator= (const Variable& x);

        virtual 
        ~Variable ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< ContourPicksType > contourPicks_;
        EntriesSequence entries_;
      };

      class Blend: public ::xml_schema::Type
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

        // filletShape
        //
        typedef ::prj::srl::spt::Parameter FilletShapeType;
        typedef ::xsd::cxx::tree::traits< FilletShapeType, char > FilletShapeTraits;

        const FilletShapeType&
        filletShape () const;

        FilletShapeType&
        filletShape ();

        void
        filletShape (const FilletShapeType& x);

        void
        filletShape (::std::unique_ptr< FilletShapeType > p);

        // blendType
        //
        typedef ::prj::srl::spt::Parameter BlendTypeType;
        typedef ::xsd::cxx::tree::traits< BlendTypeType, char > BlendTypeTraits;

        const BlendTypeType&
        blendType () const;

        BlendTypeType&
        blendType ();

        void
        blendType (const BlendTypeType& x);

        void
        blendType (::std::unique_ptr< BlendTypeType > p);

        // lawSpinePick
        //
        typedef ::prj::srl::spt::Parameter LawSpinePickType;
        typedef ::xsd::cxx::tree::traits< LawSpinePickType, char > LawSpinePickTraits;

        const LawSpinePickType&
        lawSpinePick () const;

        LawSpinePickType&
        lawSpinePick ();

        void
        lawSpinePick (const LawSpinePickType& x);

        void
        lawSpinePick (::std::unique_ptr< LawSpinePickType > p);

        // lawEdgePick
        //
        typedef ::prj::srl::spt::Parameter LawEdgePickType;
        typedef ::xsd::cxx::tree::traits< LawEdgePickType, char > LawEdgePickTraits;

        const LawEdgePickType&
        lawEdgePick () const;

        LawEdgePickType&
        lawEdgePick ();

        void
        lawEdgePick (const LawEdgePickType& x);

        void
        lawEdgePick (::std::unique_ptr< LawEdgePickType > p);

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

        // constants
        //
        typedef ::prj::srl::blns::Constant ConstantsType;
        typedef ::xsd::cxx::tree::sequence< ConstantsType > ConstantsSequence;
        typedef ConstantsSequence::iterator ConstantsIterator;
        typedef ConstantsSequence::const_iterator ConstantsConstIterator;
        typedef ::xsd::cxx::tree::traits< ConstantsType, char > ConstantsTraits;

        const ConstantsSequence&
        constants () const;

        ConstantsSequence&
        constants ();

        void
        constants (const ConstantsSequence& s);

        // variable
        //
        typedef ::prj::srl::blns::Variable VariableType;
        typedef ::xsd::cxx::tree::optional< VariableType > VariableOptional;
        typedef ::xsd::cxx::tree::traits< VariableType, char > VariableTraits;

        const VariableOptional&
        variable () const;

        VariableOptional&
        variable ();

        void
        variable (const VariableType& x);

        void
        variable (const VariableOptional& x);

        void
        variable (::std::unique_ptr< VariableType > p);

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

        // Constructors.
        //
        Blend (const BaseType&,
               const FilletShapeType&,
               const BlendTypeType&,
               const LawSpinePickType&,
               const LawEdgePickType&,
               const SeerShapeType&);

        Blend (::std::unique_ptr< BaseType >,
               ::std::unique_ptr< FilletShapeType >,
               ::std::unique_ptr< BlendTypeType >,
               ::std::unique_ptr< LawSpinePickType >,
               ::std::unique_ptr< LawEdgePickType >,
               ::std::unique_ptr< SeerShapeType >);

        Blend (const ::xercesc::DOMElement& e,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        Blend (const Blend& x,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        virtual Blend*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Blend&
        operator= (const Blend& x);

        virtual 
        ~Blend ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< BaseType > base_;
        ::xsd::cxx::tree::one< FilletShapeType > filletShape_;
        ::xsd::cxx::tree::one< BlendTypeType > blendType_;
        ::xsd::cxx::tree::one< LawSpinePickType > lawSpinePick_;
        ::xsd::cxx::tree::one< LawEdgePickType > lawEdgePick_;
        ::xsd::cxx::tree::one< SeerShapeType > seerShape_;
        ConstantsSequence constants_;
        VariableOptional variable_;
        ShapeMapSequence shapeMap_;
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
    namespace blns
    {
      // Parse a URI or a local file.
      //

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (const ::std::string& uri,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (const ::std::string& uri,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (const ::std::string& uri,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse std::istream.
      //

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::std::istream& is,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::std::istream& is,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::std::istream& is,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::std::istream& is,
             const ::std::string& id,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::std::istream& is,
             const ::std::string& id,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::std::istream& is,
             const ::std::string& id,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::InputSource.
      //

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::xercesc::InputSource& is,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::xercesc::InputSource& is,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::xercesc::InputSource& is,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::DOMDocument.
      //

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (const ::xercesc::DOMDocument& d,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::blns::Blend >
      blend (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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
    namespace blns
    {
      void
      operator<< (::xercesc::DOMElement&, const Constant&);

      void
      operator<< (::xercesc::DOMElement&, const Entry&);

      void
      operator<< (::xercesc::DOMElement&, const Variable&);

      void
      operator<< (::xercesc::DOMElement&, const Blend&);

      // Serialize to std::ostream.
      //

      void
      blend (::std::ostream& os,
             const ::prj::srl::blns::Blend& x, 
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      blend (::std::ostream& os,
             const ::prj::srl::blns::Blend& x, 
             ::xml_schema::ErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      blend (::std::ostream& os,
             const ::prj::srl::blns::Blend& x, 
             ::xercesc::DOMErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      // Serialize to xercesc::XMLFormatTarget.
      //

      void
      blend (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::blns::Blend& x, 
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      blend (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::blns::Blend& x, 
             ::xml_schema::ErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      blend (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::blns::Blend& x, 
             ::xercesc::DOMErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      // Serialize to an existing xercesc::DOMDocument.
      //

      void
      blend (::xercesc::DOMDocument& d,
             const ::prj::srl::blns::Blend& x,
             ::xml_schema::Flags f = 0);

      // Serialize to a new xercesc::DOMDocument.
      //

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      blend (const ::prj::srl::blns::Blend& x, 
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

#endif // PRJ_SRL_BLNS_PRJSRLBLNSBLEND_H
