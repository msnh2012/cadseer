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

#include "prjsrlbxsbox.h"

namespace prj
{
  namespace srl
  {
    namespace bxs
    {
      // Box
      // 

      const Box::BaseType& Box::
      base () const
      {
        return this->base_.get ();
      }

      Box::BaseType& Box::
      base ()
      {
        return this->base_.get ();
      }

      void Box::
      base (const BaseType& x)
      {
        this->base_.set (x);
      }

      void Box::
      base (::std::unique_ptr< BaseType > x)
      {
        this->base_.set (std::move (x));
      }

      const Box::SeerShapeType& Box::
      seerShape () const
      {
        return this->seerShape_.get ();
      }

      Box::SeerShapeType& Box::
      seerShape ()
      {
        return this->seerShape_.get ();
      }

      void Box::
      seerShape (const SeerShapeType& x)
      {
        this->seerShape_.set (x);
      }

      void Box::
      seerShape (::std::unique_ptr< SeerShapeType > x)
      {
        this->seerShape_.set (std::move (x));
      }

      const Box::LengthType& Box::
      length () const
      {
        return this->length_.get ();
      }

      Box::LengthType& Box::
      length ()
      {
        return this->length_.get ();
      }

      void Box::
      length (const LengthType& x)
      {
        this->length_.set (x);
      }

      void Box::
      length (::std::unique_ptr< LengthType > x)
      {
        this->length_.set (std::move (x));
      }

      const Box::WidthType& Box::
      width () const
      {
        return this->width_.get ();
      }

      Box::WidthType& Box::
      width ()
      {
        return this->width_.get ();
      }

      void Box::
      width (const WidthType& x)
      {
        this->width_.set (x);
      }

      void Box::
      width (::std::unique_ptr< WidthType > x)
      {
        this->width_.set (std::move (x));
      }

      const Box::HeightType& Box::
      height () const
      {
        return this->height_.get ();
      }

      Box::HeightType& Box::
      height ()
      {
        return this->height_.get ();
      }

      void Box::
      height (const HeightType& x)
      {
        this->height_.set (x);
      }

      void Box::
      height (::std::unique_ptr< HeightType > x)
      {
        this->height_.set (std::move (x));
      }

      const Box::CsysType& Box::
      csys () const
      {
        return this->csys_.get ();
      }

      Box::CsysType& Box::
      csys ()
      {
        return this->csys_.get ();
      }

      void Box::
      csys (const CsysType& x)
      {
        this->csys_.set (x);
      }

      void Box::
      csys (::std::unique_ptr< CsysType > x)
      {
        this->csys_.set (std::move (x));
      }

      const Box::CsysDraggerType& Box::
      csysDragger () const
      {
        return this->csysDragger_.get ();
      }

      Box::CsysDraggerType& Box::
      csysDragger ()
      {
        return this->csysDragger_.get ();
      }

      void Box::
      csysDragger (const CsysDraggerType& x)
      {
        this->csysDragger_.set (x);
      }

      void Box::
      csysDragger (::std::unique_ptr< CsysDraggerType > x)
      {
        this->csysDragger_.set (std::move (x));
      }

      const Box::LengthIPType& Box::
      lengthIP () const
      {
        return this->lengthIP_.get ();
      }

      Box::LengthIPType& Box::
      lengthIP ()
      {
        return this->lengthIP_.get ();
      }

      void Box::
      lengthIP (const LengthIPType& x)
      {
        this->lengthIP_.set (x);
      }

      void Box::
      lengthIP (::std::unique_ptr< LengthIPType > x)
      {
        this->lengthIP_.set (std::move (x));
      }

      const Box::WidthIPType& Box::
      widthIP () const
      {
        return this->widthIP_.get ();
      }

      Box::WidthIPType& Box::
      widthIP ()
      {
        return this->widthIP_.get ();
      }

      void Box::
      widthIP (const WidthIPType& x)
      {
        this->widthIP_.set (x);
      }

      void Box::
      widthIP (::std::unique_ptr< WidthIPType > x)
      {
        this->widthIP_.set (std::move (x));
      }

      const Box::HeightIPType& Box::
      heightIP () const
      {
        return this->heightIP_.get ();
      }

      Box::HeightIPType& Box::
      heightIP ()
      {
        return this->heightIP_.get ();
      }

      void Box::
      heightIP (const HeightIPType& x)
      {
        this->heightIP_.set (x);
      }

      void Box::
      heightIP (::std::unique_ptr< HeightIPType > x)
      {
        this->heightIP_.set (std::move (x));
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace bxs
    {
      // Box
      //

      Box::
      Box (const BaseType& base,
           const SeerShapeType& seerShape,
           const LengthType& length,
           const WidthType& width,
           const HeightType& height,
           const CsysType& csys,
           const CsysDraggerType& csysDragger,
           const LengthIPType& lengthIP,
           const WidthIPType& widthIP,
           const HeightIPType& heightIP)
      : ::xml_schema::Type (),
        base_ (base, this),
        seerShape_ (seerShape, this),
        length_ (length, this),
        width_ (width, this),
        height_ (height, this),
        csys_ (csys, this),
        csysDragger_ (csysDragger, this),
        lengthIP_ (lengthIP, this),
        widthIP_ (widthIP, this),
        heightIP_ (heightIP, this)
      {
      }

      Box::
      Box (::std::unique_ptr< BaseType > base,
           ::std::unique_ptr< SeerShapeType > seerShape,
           ::std::unique_ptr< LengthType > length,
           ::std::unique_ptr< WidthType > width,
           ::std::unique_ptr< HeightType > height,
           ::std::unique_ptr< CsysType > csys,
           ::std::unique_ptr< CsysDraggerType > csysDragger,
           ::std::unique_ptr< LengthIPType > lengthIP,
           ::std::unique_ptr< WidthIPType > widthIP,
           ::std::unique_ptr< HeightIPType > heightIP)
      : ::xml_schema::Type (),
        base_ (std::move (base), this),
        seerShape_ (std::move (seerShape), this),
        length_ (std::move (length), this),
        width_ (std::move (width), this),
        height_ (std::move (height), this),
        csys_ (std::move (csys), this),
        csysDragger_ (std::move (csysDragger), this),
        lengthIP_ (std::move (lengthIP), this),
        widthIP_ (std::move (widthIP), this),
        heightIP_ (std::move (heightIP), this)
      {
      }

      Box::
      Box (const Box& x,
           ::xml_schema::Flags f,
           ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        base_ (x.base_, f, this),
        seerShape_ (x.seerShape_, f, this),
        length_ (x.length_, f, this),
        width_ (x.width_, f, this),
        height_ (x.height_, f, this),
        csys_ (x.csys_, f, this),
        csysDragger_ (x.csysDragger_, f, this),
        lengthIP_ (x.lengthIP_, f, this),
        widthIP_ (x.widthIP_, f, this),
        heightIP_ (x.heightIP_, f, this)
      {
      }

      Box::
      Box (const ::xercesc::DOMElement& e,
           ::xml_schema::Flags f,
           ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        base_ (this),
        seerShape_ (this),
        length_ (this),
        width_ (this),
        height_ (this),
        csys_ (this),
        csysDragger_ (this),
        lengthIP_ (this),
        widthIP_ (this),
        heightIP_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void Box::
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

          // length
          //
          if (n.name () == "length" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< LengthType > r (
              LengthTraits::create (i, f, this));

            if (!length_.present ())
            {
              this->length_.set (::std::move (r));
              continue;
            }
          }

          // width
          //
          if (n.name () == "width" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< WidthType > r (
              WidthTraits::create (i, f, this));

            if (!width_.present ())
            {
              this->width_.set (::std::move (r));
              continue;
            }
          }

          // height
          //
          if (n.name () == "height" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< HeightType > r (
              HeightTraits::create (i, f, this));

            if (!height_.present ())
            {
              this->height_.set (::std::move (r));
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

          // lengthIP
          //
          if (n.name () == "lengthIP" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< LengthIPType > r (
              LengthIPTraits::create (i, f, this));

            if (!lengthIP_.present ())
            {
              this->lengthIP_.set (::std::move (r));
              continue;
            }
          }

          // widthIP
          //
          if (n.name () == "widthIP" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< WidthIPType > r (
              WidthIPTraits::create (i, f, this));

            if (!widthIP_.present ())
            {
              this->widthIP_.set (::std::move (r));
              continue;
            }
          }

          // heightIP
          //
          if (n.name () == "heightIP" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< HeightIPType > r (
              HeightIPTraits::create (i, f, this));

            if (!heightIP_.present ())
            {
              this->heightIP_.set (::std::move (r));
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

        if (!seerShape_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "seerShape",
            "");
        }

        if (!length_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "length",
            "");
        }

        if (!width_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "width",
            "");
        }

        if (!height_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "height",
            "");
        }

        if (!csys_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "csys",
            "");
        }

        if (!csysDragger_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "csysDragger",
            "");
        }

        if (!lengthIP_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "lengthIP",
            "");
        }

        if (!widthIP_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "widthIP",
            "");
        }

        if (!heightIP_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "heightIP",
            "");
        }
      }

      Box* Box::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class Box (*this, f, c);
      }

      Box& Box::
      operator= (const Box& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->base_ = x.base_;
          this->seerShape_ = x.seerShape_;
          this->length_ = x.length_;
          this->width_ = x.width_;
          this->height_ = x.height_;
          this->csys_ = x.csys_;
          this->csysDragger_ = x.csysDragger_;
          this->lengthIP_ = x.lengthIP_;
          this->widthIP_ = x.widthIP_;
          this->heightIP_ = x.heightIP_;
        }

        return *this;
      }

      Box::
      ~Box ()
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
    namespace bxs
    {
      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::bxs::Box > (
          ::prj::srl::bxs::box (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::bxs::Box > (
          ::prj::srl::bxs::box (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (const ::std::string& u,
           ::xercesc::DOMErrorHandler& h,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::bxs::Box > (
          ::prj::srl::bxs::box (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::bxs::box (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           ::xml_schema::ErrorHandler& h,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::bxs::box (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           ::xercesc::DOMErrorHandler& h,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::bxs::box (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           const ::std::string& sid,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::bxs::box (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           const ::std::string& sid,
           ::xml_schema::ErrorHandler& h,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::bxs::box (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::std::istream& is,
           const ::std::string& sid,
           ::xercesc::DOMErrorHandler& h,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::bxs::box (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::xercesc::InputSource& i,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::tree::error_handler< char > h;

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

        return ::std::unique_ptr< ::prj::srl::bxs::Box > (
          ::prj::srl::bxs::box (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::xercesc::InputSource& i,
           ::xml_schema::ErrorHandler& h,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::bxs::Box > (
          ::prj::srl::bxs::box (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::xercesc::InputSource& i,
           ::xercesc::DOMErrorHandler& h,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::bxs::Box > (
          ::prj::srl::bxs::box (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (const ::xercesc::DOMDocument& doc,
           ::xml_schema::Flags f,
           const ::xml_schema::Properties& p)
      {
        if (f & ::xml_schema::Flags::keep_dom)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

          return ::std::unique_ptr< ::prj::srl::bxs::Box > (
            ::prj::srl::bxs::box (
              std::move (d), f | ::xml_schema::Flags::own_dom, p));
        }

        const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "box" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/bxs")
        {
          ::std::unique_ptr< ::prj::srl::bxs::Box > r (
            ::xsd::cxx::tree::traits< ::prj::srl::bxs::Box, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "box",
          "http://www.cadseer.com/prj/srl/bxs");
      }

      ::std::unique_ptr< ::prj::srl::bxs::Box >
      box (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

        if (n.name () == "box" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/bxs")
        {
          ::std::unique_ptr< ::prj::srl::bxs::Box > r (
            ::xsd::cxx::tree::traits< ::prj::srl::bxs::Box, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "box",
          "http://www.cadseer.com/prj/srl/bxs");
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
    namespace bxs
    {
      void
      operator<< (::xercesc::DOMElement& e, const Box& i)
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

        // length
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "length",
              e));

          s << i.length ();
        }

        // width
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "width",
              e));

          s << i.width ();
        }

        // height
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "height",
              e));

          s << i.height ();
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

        // csysDragger
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "csysDragger",
              e));

          s << i.csysDragger ();
        }

        // lengthIP
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "lengthIP",
              e));

          s << i.lengthIP ();
        }

        // widthIP
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "widthIP",
              e));

          s << i.widthIP ();
        }

        // heightIP
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "heightIP",
              e));

          s << i.heightIP ();
        }
      }

      void
      box (::std::ostream& o,
           const ::prj::srl::bxs::Box& s,
           const ::xml_schema::NamespaceInfomap& m,
           const ::std::string& e,
           ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::bxs::box (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      box (::std::ostream& o,
           const ::prj::srl::bxs::Box& s,
           ::xml_schema::ErrorHandler& h,
           const ::xml_schema::NamespaceInfomap& m,
           const ::std::string& e,
           ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::bxs::box (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      box (::std::ostream& o,
           const ::prj::srl::bxs::Box& s,
           ::xercesc::DOMErrorHandler& h,
           const ::xml_schema::NamespaceInfomap& m,
           const ::std::string& e,
           ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::bxs::box (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      box (::xercesc::XMLFormatTarget& t,
           const ::prj::srl::bxs::Box& s,
           const ::xml_schema::NamespaceInfomap& m,
           const ::std::string& e,
           ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::bxs::box (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      box (::xercesc::XMLFormatTarget& t,
           const ::prj::srl::bxs::Box& s,
           ::xml_schema::ErrorHandler& h,
           const ::xml_schema::NamespaceInfomap& m,
           const ::std::string& e,
           ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::bxs::box (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      box (::xercesc::XMLFormatTarget& t,
           const ::prj::srl::bxs::Box& s,
           ::xercesc::DOMErrorHandler& h,
           const ::xml_schema::NamespaceInfomap& m,
           const ::std::string& e,
           ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::bxs::box (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      box (::xercesc::DOMDocument& d,
           const ::prj::srl::bxs::Box& s,
           ::xml_schema::Flags)
      {
        ::xercesc::DOMElement& e (*d.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "box" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/bxs")
        {
          e << s;
        }
        else
        {
          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "box",
            "http://www.cadseer.com/prj/srl/bxs");
        }
      }

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      box (const ::prj::srl::bxs::Box& s,
           const ::xml_schema::NamespaceInfomap& m,
           ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::serialize< char > (
            "box",
            "http://www.cadseer.com/prj/srl/bxs",
            m, f));

        ::prj::srl::bxs::box (*d, s, f);
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
