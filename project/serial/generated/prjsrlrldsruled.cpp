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

#include "prjsrlrldsruled.h"

namespace prj
{
  namespace srl
  {
    namespace rlds
    {
      // Ruled
      // 

      const Ruled::BaseType& Ruled::
      base () const
      {
        return this->base_.get ();
      }

      Ruled::BaseType& Ruled::
      base ()
      {
        return this->base_.get ();
      }

      void Ruled::
      base (const BaseType& x)
      {
        this->base_.set (x);
      }

      void Ruled::
      base (::std::unique_ptr< BaseType > x)
      {
        this->base_.set (std::move (x));
      }

      const Ruled::PicksType& Ruled::
      picks () const
      {
        return this->picks_.get ();
      }

      Ruled::PicksType& Ruled::
      picks ()
      {
        return this->picks_.get ();
      }

      void Ruled::
      picks (const PicksType& x)
      {
        this->picks_.set (x);
      }

      void Ruled::
      picks (::std::unique_ptr< PicksType > x)
      {
        this->picks_.set (std::move (x));
      }

      const Ruled::SeerShapeType& Ruled::
      seerShape () const
      {
        return this->seerShape_.get ();
      }

      Ruled::SeerShapeType& Ruled::
      seerShape ()
      {
        return this->seerShape_.get ();
      }

      void Ruled::
      seerShape (const SeerShapeType& x)
      {
        this->seerShape_.set (x);
      }

      void Ruled::
      seerShape (::std::unique_ptr< SeerShapeType > x)
      {
        this->seerShape_.set (std::move (x));
      }

      const Ruled::ParentIdType& Ruled::
      parentId () const
      {
        return this->parentId_.get ();
      }

      Ruled::ParentIdType& Ruled::
      parentId ()
      {
        return this->parentId_.get ();
      }

      void Ruled::
      parentId (const ParentIdType& x)
      {
        this->parentId_.set (x);
      }

      void Ruled::
      parentId (::std::unique_ptr< ParentIdType > x)
      {
        this->parentId_.set (std::move (x));
      }

      const Ruled::ParentIdType& Ruled::
      parentId_default_value ()
      {
        return parentId_default_value_;
      }

      const Ruled::EfMapSequence& Ruled::
      efMap () const
      {
        return this->efMap_;
      }

      Ruled::EfMapSequence& Ruled::
      efMap ()
      {
        return this->efMap_;
      }

      void Ruled::
      efMap (const EfMapSequence& s)
      {
        this->efMap_ = s;
      }

      const Ruled::VeMapSequence& Ruled::
      veMap () const
      {
        return this->veMap_;
      }

      Ruled::VeMapSequence& Ruled::
      veMap ()
      {
        return this->veMap_;
      }

      void Ruled::
      veMap (const VeMapSequence& s)
      {
        this->veMap_ = s;
      }

      const Ruled::OuterWireMapSequence& Ruled::
      outerWireMap () const
      {
        return this->outerWireMap_;
      }

      Ruled::OuterWireMapSequence& Ruled::
      outerWireMap ()
      {
        return this->outerWireMap_;
      }

      void Ruled::
      outerWireMap (const OuterWireMapSequence& s)
      {
        this->outerWireMap_ = s;
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace rlds
    {
      // Ruled
      //

      const Ruled::ParentIdType Ruled::parentId_default_value_ (
        "00000000-0000-0000-0000-000000000000");

      Ruled::
      Ruled (const BaseType& base,
             const PicksType& picks,
             const SeerShapeType& seerShape,
             const ParentIdType& parentId)
      : ::xml_schema::Type (),
        base_ (base, this),
        picks_ (picks, this),
        seerShape_ (seerShape, this),
        parentId_ (parentId, this),
        efMap_ (this),
        veMap_ (this),
        outerWireMap_ (this)
      {
      }

      Ruled::
      Ruled (::std::unique_ptr< BaseType > base,
             ::std::unique_ptr< PicksType > picks,
             ::std::unique_ptr< SeerShapeType > seerShape,
             const ParentIdType& parentId)
      : ::xml_schema::Type (),
        base_ (std::move (base), this),
        picks_ (std::move (picks), this),
        seerShape_ (std::move (seerShape), this),
        parentId_ (parentId, this),
        efMap_ (this),
        veMap_ (this),
        outerWireMap_ (this)
      {
      }

      Ruled::
      Ruled (const Ruled& x,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        base_ (x.base_, f, this),
        picks_ (x.picks_, f, this),
        seerShape_ (x.seerShape_, f, this),
        parentId_ (x.parentId_, f, this),
        efMap_ (x.efMap_, f, this),
        veMap_ (x.veMap_, f, this),
        outerWireMap_ (x.outerWireMap_, f, this)
      {
      }

      Ruled::
      Ruled (const ::xercesc::DOMElement& e,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        base_ (this),
        picks_ (this),
        seerShape_ (this),
        parentId_ (this),
        efMap_ (this),
        veMap_ (this),
        outerWireMap_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void Ruled::
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

          // picks
          //
          if (n.name () == "picks" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< PicksType > r (
              PicksTraits::create (i, f, this));

            if (!picks_.present ())
            {
              this->picks_.set (::std::move (r));
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

          // parentId
          //
          if (n.name () == "parentId" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< ParentIdType > r (
              ParentIdTraits::create (i, f, this));

            if (!parentId_.present ())
            {
              this->parentId_.set (::std::move (r));
              continue;
            }
          }

          // efMap
          //
          if (n.name () == "efMap" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< EfMapType > r (
              EfMapTraits::create (i, f, this));

            this->efMap_.push_back (::std::move (r));
            continue;
          }

          // veMap
          //
          if (n.name () == "veMap" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< VeMapType > r (
              VeMapTraits::create (i, f, this));

            this->veMap_.push_back (::std::move (r));
            continue;
          }

          // outerWireMap
          //
          if (n.name () == "outerWireMap" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< OuterWireMapType > r (
              OuterWireMapTraits::create (i, f, this));

            this->outerWireMap_.push_back (::std::move (r));
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

        if (!picks_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "picks",
            "");
        }

        if (!seerShape_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "seerShape",
            "");
        }

        if (!parentId_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "parentId",
            "");
        }
      }

      Ruled* Ruled::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class Ruled (*this, f, c);
      }

      Ruled& Ruled::
      operator= (const Ruled& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->base_ = x.base_;
          this->picks_ = x.picks_;
          this->seerShape_ = x.seerShape_;
          this->parentId_ = x.parentId_;
          this->efMap_ = x.efMap_;
          this->veMap_ = x.veMap_;
          this->outerWireMap_ = x.outerWireMap_;
        }

        return *this;
      }

      Ruled::
      ~Ruled ()
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
    namespace rlds
    {
      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::rlds::Ruled > (
          ::prj::srl::rlds::ruled (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::rlds::Ruled > (
          ::prj::srl::rlds::ruled (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (const ::std::string& u,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::rlds::Ruled > (
          ::prj::srl::rlds::ruled (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::std::istream& is,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::rlds::ruled (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::std::istream& is,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::rlds::ruled (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::std::istream& is,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::rlds::ruled (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::std::istream& is,
             const ::std::string& sid,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::rlds::ruled (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::std::istream& is,
             const ::std::string& sid,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::rlds::ruled (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::std::istream& is,
             const ::std::string& sid,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::rlds::ruled (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::xercesc::InputSource& i,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::tree::error_handler< char > h;

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

        return ::std::unique_ptr< ::prj::srl::rlds::Ruled > (
          ::prj::srl::rlds::ruled (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::xercesc::InputSource& i,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::rlds::Ruled > (
          ::prj::srl::rlds::ruled (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::xercesc::InputSource& i,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::rlds::Ruled > (
          ::prj::srl::rlds::ruled (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (const ::xercesc::DOMDocument& doc,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        if (f & ::xml_schema::Flags::keep_dom)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

          return ::std::unique_ptr< ::prj::srl::rlds::Ruled > (
            ::prj::srl::rlds::ruled (
              std::move (d), f | ::xml_schema::Flags::own_dom, p));
        }

        const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "ruled" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/rlds")
        {
          ::std::unique_ptr< ::prj::srl::rlds::Ruled > r (
            ::xsd::cxx::tree::traits< ::prj::srl::rlds::Ruled, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "ruled",
          "http://www.cadseer.com/prj/srl/rlds");
      }

      ::std::unique_ptr< ::prj::srl::rlds::Ruled >
      ruled (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

        if (n.name () == "ruled" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/rlds")
        {
          ::std::unique_ptr< ::prj::srl::rlds::Ruled > r (
            ::xsd::cxx::tree::traits< ::prj::srl::rlds::Ruled, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "ruled",
          "http://www.cadseer.com/prj/srl/rlds");
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
    namespace rlds
    {
      void
      operator<< (::xercesc::DOMElement& e, const Ruled& i)
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

        // picks
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "picks",
              e));

          s << i.picks ();
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

        // parentId
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "parentId",
              e));

          s << i.parentId ();
        }

        // efMap
        //
        for (Ruled::EfMapConstIterator
             b (i.efMap ().begin ()), n (i.efMap ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "efMap",
              e));

          s << *b;
        }

        // veMap
        //
        for (Ruled::VeMapConstIterator
             b (i.veMap ().begin ()), n (i.veMap ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "veMap",
              e));

          s << *b;
        }

        // outerWireMap
        //
        for (Ruled::OuterWireMapConstIterator
             b (i.outerWireMap ().begin ()), n (i.outerWireMap ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "outerWireMap",
              e));

          s << *b;
        }
      }

      void
      ruled (::std::ostream& o,
             const ::prj::srl::rlds::Ruled& s,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::rlds::ruled (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      ruled (::std::ostream& o,
             const ::prj::srl::rlds::Ruled& s,
             ::xml_schema::ErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::rlds::ruled (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      ruled (::std::ostream& o,
             const ::prj::srl::rlds::Ruled& s,
             ::xercesc::DOMErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::rlds::ruled (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      ruled (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::rlds::Ruled& s,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::rlds::ruled (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      ruled (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::rlds::Ruled& s,
             ::xml_schema::ErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::rlds::ruled (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      ruled (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::rlds::Ruled& s,
             ::xercesc::DOMErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::rlds::ruled (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      ruled (::xercesc::DOMDocument& d,
             const ::prj::srl::rlds::Ruled& s,
             ::xml_schema::Flags)
      {
        ::xercesc::DOMElement& e (*d.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "ruled" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/rlds")
        {
          e << s;
        }
        else
        {
          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "ruled",
            "http://www.cadseer.com/prj/srl/rlds");
        }
      }

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      ruled (const ::prj::srl::rlds::Ruled& s,
             const ::xml_schema::NamespaceInfomap& m,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::serialize< char > (
            "ruled",
            "http://www.cadseer.com/prj/srl/rlds",
            m, f));

        ::prj::srl::rlds::ruled (*d, s, f);
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

