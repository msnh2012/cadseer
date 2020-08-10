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

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "prjsrlchmschamfer.h"

namespace prj
{
  namespace srl
  {
    namespace chms
    {
      // Entry
      // 

      const Entry::StyleType& Entry::
      style () const
      {
        return this->style_.get ();
      }

      Entry::StyleType& Entry::
      style ()
      {
        return this->style_.get ();
      }

      void Entry::
      style (const StyleType& x)
      {
        this->style_.set (x);
      }

      const Entry::Parameter1Type& Entry::
      parameter1 () const
      {
        return this->parameter1_.get ();
      }

      Entry::Parameter1Type& Entry::
      parameter1 ()
      {
        return this->parameter1_.get ();
      }

      void Entry::
      parameter1 (const Parameter1Type& x)
      {
        this->parameter1_.set (x);
      }

      void Entry::
      parameter1 (::std::unique_ptr< Parameter1Type > x)
      {
        this->parameter1_.set (std::move (x));
      }

      const Entry::Parameter2Optional& Entry::
      parameter2 () const
      {
        return this->parameter2_;
      }

      Entry::Parameter2Optional& Entry::
      parameter2 ()
      {
        return this->parameter2_;
      }

      void Entry::
      parameter2 (const Parameter2Type& x)
      {
        this->parameter2_.set (x);
      }

      void Entry::
      parameter2 (const Parameter2Optional& x)
      {
        this->parameter2_ = x;
      }

      void Entry::
      parameter2 (::std::unique_ptr< Parameter2Type > x)
      {
        this->parameter2_.set (std::move (x));
      }

      const Entry::Label1Type& Entry::
      label1 () const
      {
        return this->label1_.get ();
      }

      Entry::Label1Type& Entry::
      label1 ()
      {
        return this->label1_.get ();
      }

      void Entry::
      label1 (const Label1Type& x)
      {
        this->label1_.set (x);
      }

      void Entry::
      label1 (::std::unique_ptr< Label1Type > x)
      {
        this->label1_.set (std::move (x));
      }

      const Entry::Label2Optional& Entry::
      label2 () const
      {
        return this->label2_;
      }

      Entry::Label2Optional& Entry::
      label2 ()
      {
        return this->label2_;
      }

      void Entry::
      label2 (const Label2Type& x)
      {
        this->label2_.set (x);
      }

      void Entry::
      label2 (const Label2Optional& x)
      {
        this->label2_ = x;
      }

      void Entry::
      label2 (::std::unique_ptr< Label2Type > x)
      {
        this->label2_.set (std::move (x));
      }

      const Entry::EdgePicksSequence& Entry::
      edgePicks () const
      {
        return this->edgePicks_;
      }

      Entry::EdgePicksSequence& Entry::
      edgePicks ()
      {
        return this->edgePicks_;
      }

      void Entry::
      edgePicks (const EdgePicksSequence& s)
      {
        this->edgePicks_ = s;
      }

      const Entry::FacePicksSequence& Entry::
      facePicks () const
      {
        return this->facePicks_;
      }

      Entry::FacePicksSequence& Entry::
      facePicks ()
      {
        return this->facePicks_;
      }

      void Entry::
      facePicks (const FacePicksSequence& s)
      {
        this->facePicks_ = s;
      }


      // Chamfer
      // 

      const Chamfer::BaseType& Chamfer::
      base () const
      {
        return this->base_.get ();
      }

      Chamfer::BaseType& Chamfer::
      base ()
      {
        return this->base_.get ();
      }

      void Chamfer::
      base (const BaseType& x)
      {
        this->base_.set (x);
      }

      void Chamfer::
      base (::std::unique_ptr< BaseType > x)
      {
        this->base_.set (std::move (x));
      }

      const Chamfer::SeerShapeType& Chamfer::
      seerShape () const
      {
        return this->seerShape_.get ();
      }

      Chamfer::SeerShapeType& Chamfer::
      seerShape ()
      {
        return this->seerShape_.get ();
      }

      void Chamfer::
      seerShape (const SeerShapeType& x)
      {
        this->seerShape_.set (x);
      }

      void Chamfer::
      seerShape (::std::unique_ptr< SeerShapeType > x)
      {
        this->seerShape_.set (std::move (x));
      }

      const Chamfer::ShapeMapSequence& Chamfer::
      shapeMap () const
      {
        return this->shapeMap_;
      }

      Chamfer::ShapeMapSequence& Chamfer::
      shapeMap ()
      {
        return this->shapeMap_;
      }

      void Chamfer::
      shapeMap (const ShapeMapSequence& s)
      {
        this->shapeMap_ = s;
      }

      const Chamfer::ModeType& Chamfer::
      mode () const
      {
        return this->mode_.get ();
      }

      Chamfer::ModeType& Chamfer::
      mode ()
      {
        return this->mode_.get ();
      }

      void Chamfer::
      mode (const ModeType& x)
      {
        this->mode_.set (x);
      }

      const Chamfer::EntriesSequence& Chamfer::
      entries () const
      {
        return this->entries_;
      }

      Chamfer::EntriesSequence& Chamfer::
      entries ()
      {
        return this->entries_;
      }

      void Chamfer::
      entries (const EntriesSequence& s)
      {
        this->entries_ = s;
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace chms
    {
      // Entry
      //

      Entry::
      Entry (const StyleType& style,
             const Parameter1Type& parameter1,
             const Label1Type& label1)
      : ::xml_schema::Type (),
        style_ (style, this),
        parameter1_ (parameter1, this),
        parameter2_ (this),
        label1_ (label1, this),
        label2_ (this),
        edgePicks_ (this),
        facePicks_ (this)
      {
      }

      Entry::
      Entry (const StyleType& style,
             ::std::unique_ptr< Parameter1Type > parameter1,
             ::std::unique_ptr< Label1Type > label1)
      : ::xml_schema::Type (),
        style_ (style, this),
        parameter1_ (std::move (parameter1), this),
        parameter2_ (this),
        label1_ (std::move (label1), this),
        label2_ (this),
        edgePicks_ (this),
        facePicks_ (this)
      {
      }

      Entry::
      Entry (const Entry& x,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        style_ (x.style_, f, this),
        parameter1_ (x.parameter1_, f, this),
        parameter2_ (x.parameter2_, f, this),
        label1_ (x.label1_, f, this),
        label2_ (x.label2_, f, this),
        edgePicks_ (x.edgePicks_, f, this),
        facePicks_ (x.facePicks_, f, this)
      {
      }

      Entry::
      Entry (const ::xercesc::DOMElement& e,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        style_ (this),
        parameter1_ (this),
        parameter2_ (this),
        label1_ (this),
        label2_ (this),
        edgePicks_ (this),
        facePicks_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void Entry::
      parse (::xsd::cxx::xml::dom::parser< char >& p,
             ::xml_schema::Flags f)
      {
        for (; p.more_content (); p.next_content (false))
        {
          const ::xercesc::DOMElement& i (p.cur_element ());
          const ::xsd::cxx::xml::qualified_name< char > n (
            ::xsd::cxx::xml::dom::name< char > (i));

          // style
          //
          if (n.name () == "style" && n.namespace_ ().empty ())
          {
            if (!style_.present ())
            {
              this->style_.set (StyleTraits::create (i, f, this));
              continue;
            }
          }

          // parameter1
          //
          if (n.name () == "parameter1" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< Parameter1Type > r (
              Parameter1Traits::create (i, f, this));

            if (!parameter1_.present ())
            {
              this->parameter1_.set (::std::move (r));
              continue;
            }
          }

          // parameter2
          //
          if (n.name () == "parameter2" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< Parameter2Type > r (
              Parameter2Traits::create (i, f, this));

            if (!this->parameter2_)
            {
              this->parameter2_.set (::std::move (r));
              continue;
            }
          }

          // label1
          //
          if (n.name () == "label1" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< Label1Type > r (
              Label1Traits::create (i, f, this));

            if (!label1_.present ())
            {
              this->label1_.set (::std::move (r));
              continue;
            }
          }

          // label2
          //
          if (n.name () == "label2" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< Label2Type > r (
              Label2Traits::create (i, f, this));

            if (!this->label2_)
            {
              this->label2_.set (::std::move (r));
              continue;
            }
          }

          // edgePicks
          //
          if (n.name () == "edgePicks" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< EdgePicksType > r (
              EdgePicksTraits::create (i, f, this));

            this->edgePicks_.push_back (::std::move (r));
            continue;
          }

          // facePicks
          //
          if (n.name () == "facePicks" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< FacePicksType > r (
              FacePicksTraits::create (i, f, this));

            this->facePicks_.push_back (::std::move (r));
            continue;
          }

          break;
        }

        if (!style_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "style",
            "");
        }

        if (!parameter1_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "parameter1",
            "");
        }

        if (!label1_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "label1",
            "");
        }
      }

      Entry* Entry::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class Entry (*this, f, c);
      }

      Entry& Entry::
      operator= (const Entry& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->style_ = x.style_;
          this->parameter1_ = x.parameter1_;
          this->parameter2_ = x.parameter2_;
          this->label1_ = x.label1_;
          this->label2_ = x.label2_;
          this->edgePicks_ = x.edgePicks_;
          this->facePicks_ = x.facePicks_;
        }

        return *this;
      }

      Entry::
      ~Entry ()
      {
      }

      // Chamfer
      //

      Chamfer::
      Chamfer (const BaseType& base,
               const SeerShapeType& seerShape,
               const ModeType& mode)
      : ::xml_schema::Type (),
        base_ (base, this),
        seerShape_ (seerShape, this),
        shapeMap_ (this),
        mode_ (mode, this),
        entries_ (this)
      {
      }

      Chamfer::
      Chamfer (::std::unique_ptr< BaseType > base,
               ::std::unique_ptr< SeerShapeType > seerShape,
               const ModeType& mode)
      : ::xml_schema::Type (),
        base_ (std::move (base), this),
        seerShape_ (std::move (seerShape), this),
        shapeMap_ (this),
        mode_ (mode, this),
        entries_ (this)
      {
      }

      Chamfer::
      Chamfer (const Chamfer& x,
               ::xml_schema::Flags f,
               ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        base_ (x.base_, f, this),
        seerShape_ (x.seerShape_, f, this),
        shapeMap_ (x.shapeMap_, f, this),
        mode_ (x.mode_, f, this),
        entries_ (x.entries_, f, this)
      {
      }

      Chamfer::
      Chamfer (const ::xercesc::DOMElement& e,
               ::xml_schema::Flags f,
               ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        base_ (this),
        seerShape_ (this),
        shapeMap_ (this),
        mode_ (this),
        entries_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void Chamfer::
      parse (::xsd::cxx::xml::dom::parser< char >& p,
             ::xml_schema::Flags f)
      {
        for (; p.more_content (); p.next_content (false))
        {
          const ::xercesc::DOMElement& i (p.cur_element ());
          const ::xsd::cxx::xml::qualified_name< char > n (
            ::xsd::cxx::xml::dom::name< char > (i));

          // base
          //
          if (n.name () == "base" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< BaseType > r (
              BaseTraits::create (i, f, this));

            if (!base_.present ())
            {
              this->base_.set (::std::move (r));
              continue;
            }
          }

          // seerShape
          //
          if (n.name () == "seerShape" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< SeerShapeType > r (
              SeerShapeTraits::create (i, f, this));

            if (!seerShape_.present ())
            {
              this->seerShape_.set (::std::move (r));
              continue;
            }
          }

          // shapeMap
          //
          if (n.name () == "shapeMap" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< ShapeMapType > r (
              ShapeMapTraits::create (i, f, this));

            this->shapeMap_.push_back (::std::move (r));
            continue;
          }

          // mode
          //
          if (n.name () == "mode" && n.namespace_ ().empty ())
          {
            if (!mode_.present ())
            {
              this->mode_.set (ModeTraits::create (i, f, this));
              continue;
            }
          }

          // entries
          //
          if (n.name () == "entries" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< EntriesType > r (
              EntriesTraits::create (i, f, this));

            this->entries_.push_back (::std::move (r));
            continue;
          }

          break;
        }

        if (!base_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "base",
            "");
        }

        if (!seerShape_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "seerShape",
            "");
        }

        if (!mode_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "mode",
            "");
        }
      }

      Chamfer* Chamfer::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class Chamfer (*this, f, c);
      }

      Chamfer& Chamfer::
      operator= (const Chamfer& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->base_ = x.base_;
          this->seerShape_ = x.seerShape_;
          this->shapeMap_ = x.shapeMap_;
          this->mode_ = x.mode_;
          this->entries_ = x.entries_;
        }

        return *this;
      }

      Chamfer::
      ~Chamfer ()
      {
      }
    }
  }
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

namespace prj
{
  namespace srl
  {
    namespace chms
    {
      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (const ::std::string& u,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::tree::error_handler< char > h;

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

        return ::std::unique_ptr< ::prj::srl::chms::Chamfer > (
          ::prj::srl::chms::chamfer (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (const ::std::string& u,
               ::xml_schema::ErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::chms::Chamfer > (
          ::prj::srl::chms::chamfer (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (const ::std::string& u,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::chms::Chamfer > (
          ::prj::srl::chms::chamfer (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::std::istream& is,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::chms::chamfer (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::std::istream& is,
               ::xml_schema::ErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::chms::chamfer (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::std::istream& is,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::chms::chamfer (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::std::istream& is,
               const ::std::string& sid,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::chms::chamfer (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::std::istream& is,
               const ::std::string& sid,
               ::xml_schema::ErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::chms::chamfer (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::std::istream& is,
               const ::std::string& sid,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::chms::chamfer (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::xercesc::InputSource& i,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::tree::error_handler< char > h;

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

        return ::std::unique_ptr< ::prj::srl::chms::Chamfer > (
          ::prj::srl::chms::chamfer (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::xercesc::InputSource& i,
               ::xml_schema::ErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::chms::Chamfer > (
          ::prj::srl::chms::chamfer (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::xercesc::InputSource& i,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::chms::Chamfer > (
          ::prj::srl::chms::chamfer (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (const ::xercesc::DOMDocument& doc,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
      {
        if (f & ::xml_schema::Flags::keep_dom)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

          return ::std::unique_ptr< ::prj::srl::chms::Chamfer > (
            ::prj::srl::chms::chamfer (
              std::move (d), f | ::xml_schema::Flags::own_dom, p));
        }

        const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "chamfer" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/chms")
        {
          ::std::unique_ptr< ::prj::srl::chms::Chamfer > r (
            ::xsd::cxx::tree::traits< ::prj::srl::chms::Chamfer, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "chamfer",
          "http://www.cadseer.com/prj/srl/chms");
      }

      ::std::unique_ptr< ::prj::srl::chms::Chamfer >
      chamfer (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties&)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > c (
          ((f & ::xml_schema::Flags::keep_dom) &&
           !(f & ::xml_schema::Flags::own_dom))
          ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
          : 0);

        ::xercesc::DOMDocument& doc (c.get () ? *c : *d);
        const ::xercesc::DOMElement& e (*doc.getDocumentElement ());

        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (f & ::xml_schema::Flags::keep_dom)
          doc.setUserData (::xml_schema::dom::tree_node_key,
                           (c.get () ? &c : &d),
                           0);

        if (n.name () == "chamfer" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/chms")
        {
          ::std::unique_ptr< ::prj::srl::chms::Chamfer > r (
            ::xsd::cxx::tree::traits< ::prj::srl::chms::Chamfer, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "chamfer",
          "http://www.cadseer.com/prj/srl/chms");
      }
    }
  }
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace chms
    {
      void
      operator<< (::xercesc::DOMElement& e, const Entry& i)
      {
        e << static_cast< const ::xml_schema::Type& > (i);

        // style
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "style",
              e));

          s << i.style ();
        }

        // parameter1
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "parameter1",
              e));

          s << i.parameter1 ();
        }

        // parameter2
        //
        if (i.parameter2 ())
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "parameter2",
              e));

          s << *i.parameter2 ();
        }

        // label1
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "label1",
              e));

          s << i.label1 ();
        }

        // label2
        //
        if (i.label2 ())
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "label2",
              e));

          s << *i.label2 ();
        }

        // edgePicks
        //
        for (Entry::EdgePicksConstIterator
             b (i.edgePicks ().begin ()), n (i.edgePicks ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "edgePicks",
              e));

          s << *b;
        }

        // facePicks
        //
        for (Entry::FacePicksConstIterator
             b (i.facePicks ().begin ()), n (i.facePicks ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "facePicks",
              e));

          s << *b;
        }
      }

      void
      operator<< (::xercesc::DOMElement& e, const Chamfer& i)
      {
        e << static_cast< const ::xml_schema::Type& > (i);

        // base
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "base",
              e));

          s << i.base ();
        }

        // seerShape
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "seerShape",
              e));

          s << i.seerShape ();
        }

        // shapeMap
        //
        for (Chamfer::ShapeMapConstIterator
             b (i.shapeMap ().begin ()), n (i.shapeMap ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "shapeMap",
              e));

          s << *b;
        }

        // mode
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "mode",
              e));

          s << i.mode ();
        }

        // entries
        //
        for (Chamfer::EntriesConstIterator
             b (i.entries ().begin ()), n (i.entries ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "entries",
              e));

          s << *b;
        }
      }

      void
      chamfer (::std::ostream& o,
               const ::prj::srl::chms::Chamfer& s,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::chms::chamfer (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      chamfer (::std::ostream& o,
               const ::prj::srl::chms::Chamfer& s,
               ::xml_schema::ErrorHandler& h,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::chms::chamfer (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      chamfer (::std::ostream& o,
               const ::prj::srl::chms::Chamfer& s,
               ::xercesc::DOMErrorHandler& h,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::chms::chamfer (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      chamfer (::xercesc::XMLFormatTarget& t,
               const ::prj::srl::chms::Chamfer& s,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::chms::chamfer (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      chamfer (::xercesc::XMLFormatTarget& t,
               const ::prj::srl::chms::Chamfer& s,
               ::xml_schema::ErrorHandler& h,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::chms::chamfer (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      chamfer (::xercesc::XMLFormatTarget& t,
               const ::prj::srl::chms::Chamfer& s,
               ::xercesc::DOMErrorHandler& h,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::chms::chamfer (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      chamfer (::xercesc::DOMDocument& d,
               const ::prj::srl::chms::Chamfer& s,
               ::xml_schema::Flags)
      {
        ::xercesc::DOMElement& e (*d.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "chamfer" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/chms")
        {
          e << s;
        }
        else
        {
          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "chamfer",
            "http://www.cadseer.com/prj/srl/chms");
        }
      }

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      chamfer (const ::prj::srl::chms::Chamfer& s,
               const ::xml_schema::NamespaceInfomap& m,
               ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::serialize< char > (
            "chamfer",
            "http://www.cadseer.com/prj/srl/chms",
            m, f));

        ::prj::srl::chms::chamfer (*d, s, f);
        return d;
      }
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

