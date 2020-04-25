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

#include "prjsrltrsstorus.h"

namespace prj
{
  namespace srl
  {
    namespace trss
    {
      // Torus
      // 

      const Torus::BaseType& Torus::
      base () const
      {
        return this->base_.get ();
      }

      Torus::BaseType& Torus::
      base ()
      {
        return this->base_.get ();
      }

      void Torus::
      base (const BaseType& x)
      {
        this->base_.set (x);
      }

      void Torus::
      base (::std::unique_ptr< BaseType > x)
      {
        this->base_.set (std::move (x));
      }

      const Torus::SeerShapeType& Torus::
      seerShape () const
      {
        return this->seerShape_.get ();
      }

      Torus::SeerShapeType& Torus::
      seerShape ()
      {
        return this->seerShape_.get ();
      }

      void Torus::
      seerShape (const SeerShapeType& x)
      {
        this->seerShape_.set (x);
      }

      void Torus::
      seerShape (::std::unique_ptr< SeerShapeType > x)
      {
        this->seerShape_.set (std::move (x));
      }

      const Torus::Radius1Type& Torus::
      radius1 () const
      {
        return this->radius1_.get ();
      }

      Torus::Radius1Type& Torus::
      radius1 ()
      {
        return this->radius1_.get ();
      }

      void Torus::
      radius1 (const Radius1Type& x)
      {
        this->radius1_.set (x);
      }

      void Torus::
      radius1 (::std::unique_ptr< Radius1Type > x)
      {
        this->radius1_.set (std::move (x));
      }

      const Torus::Radius2Type& Torus::
      radius2 () const
      {
        return this->radius2_.get ();
      }

      Torus::Radius2Type& Torus::
      radius2 ()
      {
        return this->radius2_.get ();
      }

      void Torus::
      radius2 (const Radius2Type& x)
      {
        this->radius2_.set (x);
      }

      void Torus::
      radius2 (::std::unique_ptr< Radius2Type > x)
      {
        this->radius2_.set (std::move (x));
      }

      const Torus::SeamType& Torus::
      seam () const
      {
        return this->seam_.get ();
      }

      Torus::SeamType& Torus::
      seam ()
      {
        return this->seam_.get ();
      }

      void Torus::
      seam (const SeamType& x)
      {
        this->seam_.set (x);
      }

      void Torus::
      seam (::std::unique_ptr< SeamType > x)
      {
        this->seam_.set (std::move (x));
      }

      const Torus::CsysType& Torus::
      csys () const
      {
        return this->csys_.get ();
      }

      Torus::CsysType& Torus::
      csys ()
      {
        return this->csys_.get ();
      }

      void Torus::
      csys (const CsysType& x)
      {
        this->csys_.set (x);
      }

      void Torus::
      csys (::std::unique_ptr< CsysType > x)
      {
        this->csys_.set (std::move (x));
      }

      const Torus::Radius1IPType& Torus::
      radius1IP () const
      {
        return this->radius1IP_.get ();
      }

      Torus::Radius1IPType& Torus::
      radius1IP ()
      {
        return this->radius1IP_.get ();
      }

      void Torus::
      radius1IP (const Radius1IPType& x)
      {
        this->radius1IP_.set (x);
      }

      void Torus::
      radius1IP (::std::unique_ptr< Radius1IPType > x)
      {
        this->radius1IP_.set (std::move (x));
      }

      const Torus::Radius2IPType& Torus::
      radius2IP () const
      {
        return this->radius2IP_.get ();
      }

      Torus::Radius2IPType& Torus::
      radius2IP ()
      {
        return this->radius2IP_.get ();
      }

      void Torus::
      radius2IP (const Radius2IPType& x)
      {
        this->radius2IP_.set (x);
      }

      void Torus::
      radius2IP (::std::unique_ptr< Radius2IPType > x)
      {
        this->radius2IP_.set (std::move (x));
      }

      const Torus::SeamLabelType& Torus::
      seamLabel () const
      {
        return this->seamLabel_.get ();
      }

      Torus::SeamLabelType& Torus::
      seamLabel ()
      {
        return this->seamLabel_.get ();
      }

      void Torus::
      seamLabel (const SeamLabelType& x)
      {
        this->seamLabel_.set (x);
      }

      void Torus::
      seamLabel (::std::unique_ptr< SeamLabelType > x)
      {
        this->seamLabel_.set (std::move (x));
      }

      const Torus::CsysDraggerType& Torus::
      csysDragger () const
      {
        return this->csysDragger_.get ();
      }

      Torus::CsysDraggerType& Torus::
      csysDragger ()
      {
        return this->csysDragger_.get ();
      }

      void Torus::
      csysDragger (const CsysDraggerType& x)
      {
        this->csysDragger_.set (x);
      }

      void Torus::
      csysDragger (::std::unique_ptr< CsysDraggerType > x)
      {
        this->csysDragger_.set (std::move (x));
      }

      const Torus::OffsetIdsSequence& Torus::
      offsetIds () const
      {
        return this->offsetIds_;
      }

      Torus::OffsetIdsSequence& Torus::
      offsetIds ()
      {
        return this->offsetIds_;
      }

      void Torus::
      offsetIds (const OffsetIdsSequence& s)
      {
        this->offsetIds_ = s;
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace trss
    {
      // Torus
      //

      Torus::
      Torus (const BaseType& base,
             const SeerShapeType& seerShape,
             const Radius1Type& radius1,
             const Radius2Type& radius2,
             const SeamType& seam,
             const CsysType& csys,
             const Radius1IPType& radius1IP,
             const Radius2IPType& radius2IP,
             const SeamLabelType& seamLabel,
             const CsysDraggerType& csysDragger)
      : ::xml_schema::Type (),
        base_ (base, this),
        seerShape_ (seerShape, this),
        radius1_ (radius1, this),
        radius2_ (radius2, this),
        seam_ (seam, this),
        csys_ (csys, this),
        radius1IP_ (radius1IP, this),
        radius2IP_ (radius2IP, this),
        seamLabel_ (seamLabel, this),
        csysDragger_ (csysDragger, this),
        offsetIds_ (this)
      {
      }

      Torus::
      Torus (::std::unique_ptr< BaseType > base,
             ::std::unique_ptr< SeerShapeType > seerShape,
             ::std::unique_ptr< Radius1Type > radius1,
             ::std::unique_ptr< Radius2Type > radius2,
             ::std::unique_ptr< SeamType > seam,
             ::std::unique_ptr< CsysType > csys,
             ::std::unique_ptr< Radius1IPType > radius1IP,
             ::std::unique_ptr< Radius2IPType > radius2IP,
             ::std::unique_ptr< SeamLabelType > seamLabel,
             ::std::unique_ptr< CsysDraggerType > csysDragger)
      : ::xml_schema::Type (),
        base_ (std::move (base), this),
        seerShape_ (std::move (seerShape), this),
        radius1_ (std::move (radius1), this),
        radius2_ (std::move (radius2), this),
        seam_ (std::move (seam), this),
        csys_ (std::move (csys), this),
        radius1IP_ (std::move (radius1IP), this),
        radius2IP_ (std::move (radius2IP), this),
        seamLabel_ (std::move (seamLabel), this),
        csysDragger_ (std::move (csysDragger), this),
        offsetIds_ (this)
      {
      }

      Torus::
      Torus (const Torus& x,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        base_ (x.base_, f, this),
        seerShape_ (x.seerShape_, f, this),
        radius1_ (x.radius1_, f, this),
        radius2_ (x.radius2_, f, this),
        seam_ (x.seam_, f, this),
        csys_ (x.csys_, f, this),
        radius1IP_ (x.radius1IP_, f, this),
        radius2IP_ (x.radius2IP_, f, this),
        seamLabel_ (x.seamLabel_, f, this),
        csysDragger_ (x.csysDragger_, f, this),
        offsetIds_ (x.offsetIds_, f, this)
      {
      }

      Torus::
      Torus (const ::xercesc::DOMElement& e,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        base_ (this),
        seerShape_ (this),
        radius1_ (this),
        radius2_ (this),
        seam_ (this),
        csys_ (this),
        radius1IP_ (this),
        radius2IP_ (this),
        seamLabel_ (this),
        csysDragger_ (this),
        offsetIds_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void Torus::
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

          // radius1
          //
          if (n.name () == "radius1" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< Radius1Type > r (
              Radius1Traits::create (i, f, this));

            if (!radius1_.present ())
            {
              this->radius1_.set (::std::move (r));
              continue;
            }
          }

          // radius2
          //
          if (n.name () == "radius2" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< Radius2Type > r (
              Radius2Traits::create (i, f, this));

            if (!radius2_.present ())
            {
              this->radius2_.set (::std::move (r));
              continue;
            }
          }

          // seam
          //
          if (n.name () == "seam" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< SeamType > r (
              SeamTraits::create (i, f, this));

            if (!seam_.present ())
            {
              this->seam_.set (::std::move (r));
              continue;
            }
          }

          // csys
          //
          if (n.name () == "csys" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< CsysType > r (
              CsysTraits::create (i, f, this));

            if (!csys_.present ())
            {
              this->csys_.set (::std::move (r));
              continue;
            }
          }

          // radius1IP
          //
          if (n.name () == "radius1IP" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< Radius1IPType > r (
              Radius1IPTraits::create (i, f, this));

            if (!radius1IP_.present ())
            {
              this->radius1IP_.set (::std::move (r));
              continue;
            }
          }

          // radius2IP
          //
          if (n.name () == "radius2IP" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< Radius2IPType > r (
              Radius2IPTraits::create (i, f, this));

            if (!radius2IP_.present ())
            {
              this->radius2IP_.set (::std::move (r));
              continue;
            }
          }

          // seamLabel
          //
          if (n.name () == "seamLabel" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< SeamLabelType > r (
              SeamLabelTraits::create (i, f, this));

            if (!seamLabel_.present ())
            {
              this->seamLabel_.set (::std::move (r));
              continue;
            }
          }

          // csysDragger
          //
          if (n.name () == "csysDragger" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< CsysDraggerType > r (
              CsysDraggerTraits::create (i, f, this));

            if (!csysDragger_.present ())
            {
              this->csysDragger_.set (::std::move (r));
              continue;
            }
          }

          // offsetIds
          //
          if (n.name () == "offsetIds" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< OffsetIdsType > r (
              OffsetIdsTraits::create (i, f, this));

            this->offsetIds_.push_back (::std::move (r));
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

        if (!radius1_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "radius1",
            "");
        }

        if (!radius2_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "radius2",
            "");
        }

        if (!seam_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "seam",
            "");
        }

        if (!csys_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "csys",
            "");
        }

        if (!radius1IP_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "radius1IP",
            "");
        }

        if (!radius2IP_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "radius2IP",
            "");
        }

        if (!seamLabel_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "seamLabel",
            "");
        }

        if (!csysDragger_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "csysDragger",
            "");
        }
      }

      Torus* Torus::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class Torus (*this, f, c);
      }

      Torus& Torus::
      operator= (const Torus& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->base_ = x.base_;
          this->seerShape_ = x.seerShape_;
          this->radius1_ = x.radius1_;
          this->radius2_ = x.radius2_;
          this->seam_ = x.seam_;
          this->csys_ = x.csys_;
          this->radius1IP_ = x.radius1IP_;
          this->radius2IP_ = x.radius2IP_;
          this->seamLabel_ = x.seamLabel_;
          this->csysDragger_ = x.csysDragger_;
          this->offsetIds_ = x.offsetIds_;
        }

        return *this;
      }

      Torus::
      ~Torus ()
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
    namespace trss
    {
      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::trss::Torus > (
          ::prj::srl::trss::torus (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::trss::Torus > (
          ::prj::srl::trss::torus (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (const ::std::string& u,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::trss::Torus > (
          ::prj::srl::trss::torus (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::std::istream& is,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::trss::torus (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::std::istream& is,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::trss::torus (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::std::istream& is,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::trss::torus (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::std::istream& is,
             const ::std::string& sid,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::trss::torus (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::std::istream& is,
             const ::std::string& sid,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::trss::torus (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::std::istream& is,
             const ::std::string& sid,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::trss::torus (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::xercesc::InputSource& i,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::tree::error_handler< char > h;

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

        return ::std::unique_ptr< ::prj::srl::trss::Torus > (
          ::prj::srl::trss::torus (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::xercesc::InputSource& i,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::trss::Torus > (
          ::prj::srl::trss::torus (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::xercesc::InputSource& i,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::trss::Torus > (
          ::prj::srl::trss::torus (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (const ::xercesc::DOMDocument& doc,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        if (f & ::xml_schema::Flags::keep_dom)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

          return ::std::unique_ptr< ::prj::srl::trss::Torus > (
            ::prj::srl::trss::torus (
              std::move (d), f | ::xml_schema::Flags::own_dom, p));
        }

        const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "torus" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/trss")
        {
          ::std::unique_ptr< ::prj::srl::trss::Torus > r (
            ::xsd::cxx::tree::traits< ::prj::srl::trss::Torus, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "torus",
          "http://www.cadseer.com/prj/srl/trss");
      }

      ::std::unique_ptr< ::prj::srl::trss::Torus >
      torus (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

        if (n.name () == "torus" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/trss")
        {
          ::std::unique_ptr< ::prj::srl::trss::Torus > r (
            ::xsd::cxx::tree::traits< ::prj::srl::trss::Torus, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "torus",
          "http://www.cadseer.com/prj/srl/trss");
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
    namespace trss
    {
      void
      operator<< (::xercesc::DOMElement& e, const Torus& i)
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

        // radius1
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "radius1",
              e));

          s << i.radius1 ();
        }

        // radius2
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "radius2",
              e));

          s << i.radius2 ();
        }

        // seam
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "seam",
              e));

          s << i.seam ();
        }

        // csys
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "csys",
              e));

          s << i.csys ();
        }

        // radius1IP
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "radius1IP",
              e));

          s << i.radius1IP ();
        }

        // radius2IP
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "radius2IP",
              e));

          s << i.radius2IP ();
        }

        // seamLabel
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "seamLabel",
              e));

          s << i.seamLabel ();
        }

        // csysDragger
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "csysDragger",
              e));

          s << i.csysDragger ();
        }

        // offsetIds
        //
        for (Torus::OffsetIdsConstIterator
             b (i.offsetIds ().begin ()), n (i.offsetIds ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "offsetIds",
              e));

          s << *b;
        }
      }

      void
      torus (::std::ostream& o,
             const ::prj::srl::trss::Torus& s,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::trss::torus (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      torus (::std::ostream& o,
             const ::prj::srl::trss::Torus& s,
             ::xml_schema::ErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::trss::torus (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      torus (::std::ostream& o,
             const ::prj::srl::trss::Torus& s,
             ::xercesc::DOMErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::trss::torus (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      torus (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::trss::Torus& s,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::trss::torus (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      torus (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::trss::Torus& s,
             ::xml_schema::ErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::trss::torus (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      torus (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::trss::Torus& s,
             ::xercesc::DOMErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::trss::torus (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      torus (::xercesc::DOMDocument& d,
             const ::prj::srl::trss::Torus& s,
             ::xml_schema::Flags)
      {
        ::xercesc::DOMElement& e (*d.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "torus" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/trss")
        {
          e << s;
        }
        else
        {
          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "torus",
            "http://www.cadseer.com/prj/srl/trss");
        }
      }

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      torus (const ::prj::srl::trss::Torus& s,
             const ::xml_schema::NamespaceInfomap& m,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::serialize< char > (
            "torus",
            "http://www.cadseer.com/prj/srl/trss",
            m, f));

        ::prj::srl::trss::torus (*d, s, f);
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
