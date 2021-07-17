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

#include "prjsrldrfsdraft.h"

namespace prj
{
  namespace srl
  {
    namespace drfs
    {
      // Draft
      // 

      const Draft::BaseType& Draft::
      base () const
      {
        return this->base_.get ();
      }

      Draft::BaseType& Draft::
      base ()
      {
        return this->base_.get ();
      }

      void Draft::
      base (const BaseType& x)
      {
        this->base_.set (x);
      }

      void Draft::
      base (::std::unique_ptr< BaseType > x)
      {
        this->base_.set (std::move (x));
      }

      const Draft::NeutralPickType& Draft::
      neutralPick () const
      {
        return this->neutralPick_.get ();
      }

      Draft::NeutralPickType& Draft::
      neutralPick ()
      {
        return this->neutralPick_.get ();
      }

      void Draft::
      neutralPick (const NeutralPickType& x)
      {
        this->neutralPick_.set (x);
      }

      void Draft::
      neutralPick (::std::unique_ptr< NeutralPickType > x)
      {
        this->neutralPick_.set (std::move (x));
      }

      const Draft::TargetPicksType& Draft::
      targetPicks () const
      {
        return this->targetPicks_.get ();
      }

      Draft::TargetPicksType& Draft::
      targetPicks ()
      {
        return this->targetPicks_.get ();
      }

      void Draft::
      targetPicks (const TargetPicksType& x)
      {
        this->targetPicks_.set (x);
      }

      void Draft::
      targetPicks (::std::unique_ptr< TargetPicksType > x)
      {
        this->targetPicks_.set (std::move (x));
      }

      const Draft::AngleType& Draft::
      angle () const
      {
        return this->angle_.get ();
      }

      Draft::AngleType& Draft::
      angle ()
      {
        return this->angle_.get ();
      }

      void Draft::
      angle (const AngleType& x)
      {
        this->angle_.set (x);
      }

      void Draft::
      angle (::std::unique_ptr< AngleType > x)
      {
        this->angle_.set (std::move (x));
      }

      const Draft::SeerShapeType& Draft::
      seerShape () const
      {
        return this->seerShape_.get ();
      }

      Draft::SeerShapeType& Draft::
      seerShape ()
      {
        return this->seerShape_.get ();
      }

      void Draft::
      seerShape (const SeerShapeType& x)
      {
        this->seerShape_.set (x);
      }

      void Draft::
      seerShape (::std::unique_ptr< SeerShapeType > x)
      {
        this->seerShape_.set (std::move (x));
      }

      const Draft::PlabelType& Draft::
      plabel () const
      {
        return this->plabel_.get ();
      }

      Draft::PlabelType& Draft::
      plabel ()
      {
        return this->plabel_.get ();
      }

      void Draft::
      plabel (const PlabelType& x)
      {
        this->plabel_.set (x);
      }

      void Draft::
      plabel (::std::unique_ptr< PlabelType > x)
      {
        this->plabel_.set (std::move (x));
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace drfs
    {
      // Draft
      //

      Draft::
      Draft (const BaseType& base,
             const NeutralPickType& neutralPick,
             const TargetPicksType& targetPicks,
             const AngleType& angle,
             const SeerShapeType& seerShape,
             const PlabelType& plabel)
      : ::xml_schema::Type (),
        base_ (base, this),
        neutralPick_ (neutralPick, this),
        targetPicks_ (targetPicks, this),
        angle_ (angle, this),
        seerShape_ (seerShape, this),
        plabel_ (plabel, this)
      {
      }

      Draft::
      Draft (::std::unique_ptr< BaseType > base,
             ::std::unique_ptr< NeutralPickType > neutralPick,
             ::std::unique_ptr< TargetPicksType > targetPicks,
             ::std::unique_ptr< AngleType > angle,
             ::std::unique_ptr< SeerShapeType > seerShape,
             ::std::unique_ptr< PlabelType > plabel)
      : ::xml_schema::Type (),
        base_ (std::move (base), this),
        neutralPick_ (std::move (neutralPick), this),
        targetPicks_ (std::move (targetPicks), this),
        angle_ (std::move (angle), this),
        seerShape_ (std::move (seerShape), this),
        plabel_ (std::move (plabel), this)
      {
      }

      Draft::
      Draft (const Draft& x,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        base_ (x.base_, f, this),
        neutralPick_ (x.neutralPick_, f, this),
        targetPicks_ (x.targetPicks_, f, this),
        angle_ (x.angle_, f, this),
        seerShape_ (x.seerShape_, f, this),
        plabel_ (x.plabel_, f, this)
      {
      }

      Draft::
      Draft (const ::xercesc::DOMElement& e,
             ::xml_schema::Flags f,
             ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        base_ (this),
        neutralPick_ (this),
        targetPicks_ (this),
        angle_ (this),
        seerShape_ (this),
        plabel_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void Draft::
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

          // neutralPick
          //
          if (n.name () == "neutralPick" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< NeutralPickType > r (
              NeutralPickTraits::create (i, f, this));

            if (!neutralPick_.present ())
            {
              this->neutralPick_.set (::std::move (r));
              continue;
            }
          }

          // targetPicks
          //
          if (n.name () == "targetPicks" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< TargetPicksType > r (
              TargetPicksTraits::create (i, f, this));

            if (!targetPicks_.present ())
            {
              this->targetPicks_.set (::std::move (r));
              continue;
            }
          }

          // angle
          //
          if (n.name () == "angle" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< AngleType > r (
              AngleTraits::create (i, f, this));

            if (!angle_.present ())
            {
              this->angle_.set (::std::move (r));
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

          // plabel
          //
          if (n.name () == "plabel" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< PlabelType > r (
              PlabelTraits::create (i, f, this));

            if (!plabel_.present ())
            {
              this->plabel_.set (::std::move (r));
              continue;
            }
          }

          break;
        }

        if (!base_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "base",
            "");
        }

        if (!neutralPick_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "neutralPick",
            "");
        }

        if (!targetPicks_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "targetPicks",
            "");
        }

        if (!angle_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "angle",
            "");
        }

        if (!seerShape_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "seerShape",
            "");
        }

        if (!plabel_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "plabel",
            "");
        }
      }

      Draft* Draft::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class Draft (*this, f, c);
      }

      Draft& Draft::
      operator= (const Draft& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->base_ = x.base_;
          this->neutralPick_ = x.neutralPick_;
          this->targetPicks_ = x.targetPicks_;
          this->angle_ = x.angle_;
          this->seerShape_ = x.seerShape_;
          this->plabel_ = x.plabel_;
        }

        return *this;
      }

      Draft::
      ~Draft ()
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
    namespace drfs
    {
      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::drfs::Draft > (
          ::prj::srl::drfs::draft (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::drfs::Draft > (
          ::prj::srl::drfs::draft (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (const ::std::string& u,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::drfs::Draft > (
          ::prj::srl::drfs::draft (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::std::istream& is,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::drfs::draft (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::std::istream& is,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::drfs::draft (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::std::istream& is,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::drfs::draft (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::std::istream& is,
             const ::std::string& sid,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::drfs::draft (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::std::istream& is,
             const ::std::string& sid,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::drfs::draft (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::std::istream& is,
             const ::std::string& sid,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::drfs::draft (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::xercesc::InputSource& i,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::tree::error_handler< char > h;

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

        return ::std::unique_ptr< ::prj::srl::drfs::Draft > (
          ::prj::srl::drfs::draft (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::xercesc::InputSource& i,
             ::xml_schema::ErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::drfs::Draft > (
          ::prj::srl::drfs::draft (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::xercesc::InputSource& i,
             ::xercesc::DOMErrorHandler& h,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::drfs::Draft > (
          ::prj::srl::drfs::draft (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (const ::xercesc::DOMDocument& doc,
             ::xml_schema::Flags f,
             const ::xml_schema::Properties& p)
      {
        if (f & ::xml_schema::Flags::keep_dom)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

          return ::std::unique_ptr< ::prj::srl::drfs::Draft > (
            ::prj::srl::drfs::draft (
              std::move (d), f | ::xml_schema::Flags::own_dom, p));
        }

        const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "draft" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/drfs")
        {
          ::std::unique_ptr< ::prj::srl::drfs::Draft > r (
            ::xsd::cxx::tree::traits< ::prj::srl::drfs::Draft, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "draft",
          "http://www.cadseer.com/prj/srl/drfs");
      }

      ::std::unique_ptr< ::prj::srl::drfs::Draft >
      draft (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

        if (n.name () == "draft" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/drfs")
        {
          ::std::unique_ptr< ::prj::srl::drfs::Draft > r (
            ::xsd::cxx::tree::traits< ::prj::srl::drfs::Draft, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "draft",
          "http://www.cadseer.com/prj/srl/drfs");
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
    namespace drfs
    {
      void
      operator<< (::xercesc::DOMElement& e, const Draft& i)
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

        // neutralPick
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "neutralPick",
              e));

          s << i.neutralPick ();
        }

        // targetPicks
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "targetPicks",
              e));

          s << i.targetPicks ();
        }

        // angle
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "angle",
              e));

          s << i.angle ();
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

        // plabel
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "plabel",
              e));

          s << i.plabel ();
        }
      }

      void
      draft (::std::ostream& o,
             const ::prj::srl::drfs::Draft& s,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::drfs::draft (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      draft (::std::ostream& o,
             const ::prj::srl::drfs::Draft& s,
             ::xml_schema::ErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::drfs::draft (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      draft (::std::ostream& o,
             const ::prj::srl::drfs::Draft& s,
             ::xercesc::DOMErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::drfs::draft (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      draft (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::drfs::Draft& s,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::drfs::draft (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      draft (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::drfs::Draft& s,
             ::xml_schema::ErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::drfs::draft (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      draft (::xercesc::XMLFormatTarget& t,
             const ::prj::srl::drfs::Draft& s,
             ::xercesc::DOMErrorHandler& h,
             const ::xml_schema::NamespaceInfomap& m,
             const ::std::string& e,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::drfs::draft (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      draft (::xercesc::DOMDocument& d,
             const ::prj::srl::drfs::Draft& s,
             ::xml_schema::Flags)
      {
        ::xercesc::DOMElement& e (*d.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "draft" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/drfs")
        {
          e << s;
        }
        else
        {
          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "draft",
            "http://www.cadseer.com/prj/srl/drfs");
        }
      }

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      draft (const ::prj::srl::drfs::Draft& s,
             const ::xml_schema::NamespaceInfomap& m,
             ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::serialize< char > (
            "draft",
            "http://www.cadseer.com/prj/srl/drfs",
            m, f));

        ::prj::srl::drfs::draft (*d, s, f);
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

