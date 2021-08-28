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

#ifndef PRJ_SRL_QTS_PRJSRLQTSQUOTE_H
#define PRJ_SRL_QTS_PRJSRLQTSQUOTE_H

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
    namespace qts
    {
      class Quote;
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

#include "prjsrlsptbase.h"

#include "prjsrlsptoverlay.h"

namespace prj
{
  namespace srl
  {
    namespace qts
    {
      class Quote: public ::xml_schema::Type
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

        // stripPick
        //
        typedef ::prj::srl::spt::Parameter StripPickType;
        typedef ::xsd::cxx::tree::traits< StripPickType, char > StripPickTraits;

        const StripPickType&
        stripPick () const;

        StripPickType&
        stripPick ();

        void
        stripPick (const StripPickType& x);

        void
        stripPick (::std::unique_ptr< StripPickType > p);

        // diesetPick
        //
        typedef ::prj::srl::spt::Parameter DiesetPickType;
        typedef ::xsd::cxx::tree::traits< DiesetPickType, char > DiesetPickTraits;

        const DiesetPickType&
        diesetPick () const;

        DiesetPickType&
        diesetPick ();

        void
        diesetPick (const DiesetPickType& x);

        void
        diesetPick (::std::unique_ptr< DiesetPickType > p);

        // tFile
        //
        typedef ::prj::srl::spt::Parameter TFileType;
        typedef ::xsd::cxx::tree::traits< TFileType, char > TFileTraits;

        const TFileType&
        tFile () const;

        TFileType&
        tFile ();

        void
        tFile (const TFileType& x);

        void
        tFile (::std::unique_ptr< TFileType > p);

        // oFile
        //
        typedef ::prj::srl::spt::Parameter OFileType;
        typedef ::xsd::cxx::tree::traits< OFileType, char > OFileTraits;

        const OFileType&
        oFile () const;

        OFileType&
        oFile ();

        void
        oFile (const OFileType& x);

        void
        oFile (::std::unique_ptr< OFileType > p);

        // pFile
        //
        typedef ::prj::srl::spt::Parameter PFileType;
        typedef ::xsd::cxx::tree::traits< PFileType, char > PFileTraits;

        const PFileType&
        pFile () const;

        PFileType&
        pFile ();

        void
        pFile (const PFileType& x);

        void
        pFile (::std::unique_ptr< PFileType > p);

        // quoteNumber
        //
        typedef ::prj::srl::spt::Parameter QuoteNumberType;
        typedef ::xsd::cxx::tree::traits< QuoteNumberType, char > QuoteNumberTraits;

        const QuoteNumberType&
        quoteNumber () const;

        QuoteNumberType&
        quoteNumber ();

        void
        quoteNumber (const QuoteNumberType& x);

        void
        quoteNumber (::std::unique_ptr< QuoteNumberType > p);

        // customerName
        //
        typedef ::prj::srl::spt::Parameter CustomerNameType;
        typedef ::xsd::cxx::tree::traits< CustomerNameType, char > CustomerNameTraits;

        const CustomerNameType&
        customerName () const;

        CustomerNameType&
        customerName ();

        void
        customerName (const CustomerNameType& x);

        void
        customerName (::std::unique_ptr< CustomerNameType > p);

        // customerId
        //
        typedef ::prj::srl::spt::Parameter CustomerIdType;
        typedef ::xsd::cxx::tree::traits< CustomerIdType, char > CustomerIdTraits;

        const CustomerIdType&
        customerId () const;

        CustomerIdType&
        customerId ();

        void
        customerId (const CustomerIdType& x);

        void
        customerId (::std::unique_ptr< CustomerIdType > p);

        // partName
        //
        typedef ::prj::srl::spt::Parameter PartNameType;
        typedef ::xsd::cxx::tree::traits< PartNameType, char > PartNameTraits;

        const PartNameType&
        partName () const;

        PartNameType&
        partName ();

        void
        partName (const PartNameType& x);

        void
        partName (::std::unique_ptr< PartNameType > p);

        // partNumber
        //
        typedef ::prj::srl::spt::Parameter PartNumberType;
        typedef ::xsd::cxx::tree::traits< PartNumberType, char > PartNumberTraits;

        const PartNumberType&
        partNumber () const;

        PartNumberType&
        partNumber ();

        void
        partNumber (const PartNumberType& x);

        void
        partNumber (::std::unique_ptr< PartNumberType > p);

        // partSetup
        //
        typedef ::prj::srl::spt::Parameter PartSetupType;
        typedef ::xsd::cxx::tree::traits< PartSetupType, char > PartSetupTraits;

        const PartSetupType&
        partSetup () const;

        PartSetupType&
        partSetup ();

        void
        partSetup (const PartSetupType& x);

        void
        partSetup (::std::unique_ptr< PartSetupType > p);

        // partRevision
        //
        typedef ::prj::srl::spt::Parameter PartRevisionType;
        typedef ::xsd::cxx::tree::traits< PartRevisionType, char > PartRevisionTraits;

        const PartRevisionType&
        partRevision () const;

        PartRevisionType&
        partRevision ();

        void
        partRevision (const PartRevisionType& x);

        void
        partRevision (::std::unique_ptr< PartRevisionType > p);

        // materialType
        //
        typedef ::prj::srl::spt::Parameter MaterialTypeType;
        typedef ::xsd::cxx::tree::traits< MaterialTypeType, char > MaterialTypeTraits;

        const MaterialTypeType&
        materialType () const;

        MaterialTypeType&
        materialType ();

        void
        materialType (const MaterialTypeType& x);

        void
        materialType (::std::unique_ptr< MaterialTypeType > p);

        // materialThickness
        //
        typedef ::prj::srl::spt::Parameter MaterialThicknessType;
        typedef ::xsd::cxx::tree::traits< MaterialThicknessType, char > MaterialThicknessTraits;

        const MaterialThicknessType&
        materialThickness () const;

        MaterialThicknessType&
        materialThickness ();

        void
        materialThickness (const MaterialThicknessType& x);

        void
        materialThickness (::std::unique_ptr< MaterialThicknessType > p);

        // processType
        //
        typedef ::prj::srl::spt::Parameter ProcessTypeType;
        typedef ::xsd::cxx::tree::traits< ProcessTypeType, char > ProcessTypeTraits;

        const ProcessTypeType&
        processType () const;

        ProcessTypeType&
        processType ();

        void
        processType (const ProcessTypeType& x);

        void
        processType (::std::unique_ptr< ProcessTypeType > p);

        // annualVolume
        //
        typedef ::prj::srl::spt::Parameter AnnualVolumeType;
        typedef ::xsd::cxx::tree::traits< AnnualVolumeType, char > AnnualVolumeTraits;

        const AnnualVolumeType&
        annualVolume () const;

        AnnualVolumeType&
        annualVolume ();

        void
        annualVolume (const AnnualVolumeType& x);

        void
        annualVolume (::std::unique_ptr< AnnualVolumeType > p);

        // tFileLabel
        //
        typedef ::prj::srl::spt::PLabel TFileLabelType;
        typedef ::xsd::cxx::tree::traits< TFileLabelType, char > TFileLabelTraits;

        const TFileLabelType&
        tFileLabel () const;

        TFileLabelType&
        tFileLabel ();

        void
        tFileLabel (const TFileLabelType& x);

        void
        tFileLabel (::std::unique_ptr< TFileLabelType > p);

        // oFileLabel
        //
        typedef ::prj::srl::spt::PLabel OFileLabelType;
        typedef ::xsd::cxx::tree::traits< OFileLabelType, char > OFileLabelTraits;

        const OFileLabelType&
        oFileLabel () const;

        OFileLabelType&
        oFileLabel ();

        void
        oFileLabel (const OFileLabelType& x);

        void
        oFileLabel (::std::unique_ptr< OFileLabelType > p);

        // pFileLabel
        //
        typedef ::prj::srl::spt::PLabel PFileLabelType;
        typedef ::xsd::cxx::tree::traits< PFileLabelType, char > PFileLabelTraits;

        const PFileLabelType&
        pFileLabel () const;

        PFileLabelType&
        pFileLabel ();

        void
        pFileLabel (const PFileLabelType& x);

        void
        pFileLabel (::std::unique_ptr< PFileLabelType > p);

        // Constructors.
        //
        Quote (const BaseType&,
               const StripPickType&,
               const DiesetPickType&,
               const TFileType&,
               const OFileType&,
               const PFileType&,
               const QuoteNumberType&,
               const CustomerNameType&,
               const CustomerIdType&,
               const PartNameType&,
               const PartNumberType&,
               const PartSetupType&,
               const PartRevisionType&,
               const MaterialTypeType&,
               const MaterialThicknessType&,
               const ProcessTypeType&,
               const AnnualVolumeType&,
               const TFileLabelType&,
               const OFileLabelType&,
               const PFileLabelType&);

        Quote (::std::unique_ptr< BaseType >,
               ::std::unique_ptr< StripPickType >,
               ::std::unique_ptr< DiesetPickType >,
               ::std::unique_ptr< TFileType >,
               ::std::unique_ptr< OFileType >,
               ::std::unique_ptr< PFileType >,
               ::std::unique_ptr< QuoteNumberType >,
               ::std::unique_ptr< CustomerNameType >,
               ::std::unique_ptr< CustomerIdType >,
               ::std::unique_ptr< PartNameType >,
               ::std::unique_ptr< PartNumberType >,
               ::std::unique_ptr< PartSetupType >,
               ::std::unique_ptr< PartRevisionType >,
               ::std::unique_ptr< MaterialTypeType >,
               ::std::unique_ptr< MaterialThicknessType >,
               ::std::unique_ptr< ProcessTypeType >,
               ::std::unique_ptr< AnnualVolumeType >,
               ::std::unique_ptr< TFileLabelType >,
               ::std::unique_ptr< OFileLabelType >,
               ::std::unique_ptr< PFileLabelType >);

        Quote (const ::xercesc::DOMElement& e,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        Quote (const Quote& x,
               ::xml_schema::Flags f = 0,
               ::xml_schema::Container* c = 0);

        virtual Quote*
        _clone (::xml_schema::Flags f = 0,
                ::xml_schema::Container* c = 0) const;

        Quote&
        operator= (const Quote& x);

        virtual 
        ~Quote ();

        // Implementation.
        //
        protected:
        void
        parse (::xsd::cxx::xml::dom::parser< char >&,
               ::xml_schema::Flags);

        protected:
        ::xsd::cxx::tree::one< BaseType > base_;
        ::xsd::cxx::tree::one< StripPickType > stripPick_;
        ::xsd::cxx::tree::one< DiesetPickType > diesetPick_;
        ::xsd::cxx::tree::one< TFileType > tFile_;
        ::xsd::cxx::tree::one< OFileType > oFile_;
        ::xsd::cxx::tree::one< PFileType > pFile_;
        ::xsd::cxx::tree::one< QuoteNumberType > quoteNumber_;
        ::xsd::cxx::tree::one< CustomerNameType > customerName_;
        ::xsd::cxx::tree::one< CustomerIdType > customerId_;
        ::xsd::cxx::tree::one< PartNameType > partName_;
        ::xsd::cxx::tree::one< PartNumberType > partNumber_;
        ::xsd::cxx::tree::one< PartSetupType > partSetup_;
        ::xsd::cxx::tree::one< PartRevisionType > partRevision_;
        ::xsd::cxx::tree::one< MaterialTypeType > materialType_;
        ::xsd::cxx::tree::one< MaterialThicknessType > materialThickness_;
        ::xsd::cxx::tree::one< ProcessTypeType > processType_;
        ::xsd::cxx::tree::one< AnnualVolumeType > annualVolume_;
        ::xsd::cxx::tree::one< TFileLabelType > tFileLabel_;
        ::xsd::cxx::tree::one< OFileLabelType > oFileLabel_;
        ::xsd::cxx::tree::one< PFileLabelType > pFileLabel_;
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
    namespace qts
    {
      // Parse a URI or a local file.
      //

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (const ::std::string& uri,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (const ::std::string& uri,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (const ::std::string& uri,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse std::istream.
      //

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::std::istream& is,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::std::istream& is,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::std::istream& is,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::std::istream& is,
             const ::std::string& id,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::std::istream& is,
             const ::std::string& id,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::std::istream& is,
             const ::std::string& id,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::InputSource.
      //

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::xercesc::InputSource& is,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::xercesc::InputSource& is,
             ::xml_schema::ErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::xercesc::InputSource& is,
             ::xercesc::DOMErrorHandler& eh,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      // Parse xercesc::DOMDocument.
      //

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (const ::xercesc::DOMDocument& d,
             ::xml_schema::Flags f = 0,
             const ::xml_schema::Properties& p = ::xml_schema::Properties ());

      ::std::unique_ptr< ::prj::srl::qts::Quote >
      quote (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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
    namespace qts
    {
      void
      operator<< (::xercesc::DOMElement&, const Quote&);

      // Serialize to std::ostream.
      //

      void
      quote (::std::ostream& os,
             const ::prj::srl::qts::Quote& x, 
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      quote (::std::ostream& os,
             const ::prj::srl::qts::Quote& x, 
             ::xml_schema::ErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      quote (::std::ostream& os,
             const ::prj::srl::qts::Quote& x, 
             ::xercesc::DOMErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      // Serialize to xercesc::XMLFormatTarget.
      //

      void
      quote (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::qts::Quote& x, 
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      quote (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::qts::Quote& x, 
             ::xml_schema::ErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      void
      quote (::xercesc::XMLFormatTarget& ft,
             const ::prj::srl::qts::Quote& x, 
             ::xercesc::DOMErrorHandler& eh,
             const ::xml_schema::NamespaceInfomap& m = ::xml_schema::NamespaceInfomap (),
             const ::std::string& e = "UTF-8",
             ::xml_schema::Flags f = 0);

      // Serialize to an existing xercesc::DOMDocument.
      //

      void
      quote (::xercesc::DOMDocument& d,
             const ::prj::srl::qts::Quote& x,
             ::xml_schema::Flags f = 0);

      // Serialize to a new xercesc::DOMDocument.
      //

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      quote (const ::prj::srl::qts::Quote& x, 
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

#endif // PRJ_SRL_QTS_PRJSRLQTSQUOTE_H
