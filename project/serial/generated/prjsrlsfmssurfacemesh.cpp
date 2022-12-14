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

#include "prjsrlsfmssurfacemesh.h"

namespace prj
{
  namespace srl
  {
    namespace sfms
    {
      // SurfaceMesh
      // 

      const SurfaceMesh::BaseType& SurfaceMesh::
      base () const
      {
        return this->base_.get ();
      }

      SurfaceMesh::BaseType& SurfaceMesh::
      base ()
      {
        return this->base_.get ();
      }

      void SurfaceMesh::
      base (const BaseType& x)
      {
        this->base_.set (x);
      }

      void SurfaceMesh::
      base (::std::unique_ptr< BaseType > x)
      {
        this->base_.set (std::move (x));
      }

      const SurfaceMesh::MeshTypeType& SurfaceMesh::
      meshType () const
      {
        return this->meshType_.get ();
      }

      SurfaceMesh::MeshTypeType& SurfaceMesh::
      meshType ()
      {
        return this->meshType_.get ();
      }

      void SurfaceMesh::
      meshType (const MeshTypeType& x)
      {
        this->meshType_.set (x);
      }

      void SurfaceMesh::
      meshType (::std::unique_ptr< MeshTypeType > x)
      {
        this->meshType_.set (std::move (x));
      }

      const SurfaceMesh::CsysType& SurfaceMesh::
      csys () const
      {
        return this->csys_.get ();
      }

      SurfaceMesh::CsysType& SurfaceMesh::
      csys ()
      {
        return this->csys_.get ();
      }

      void SurfaceMesh::
      csys (const CsysType& x)
      {
        this->csys_.set (x);
      }

      void SurfaceMesh::
      csys (::std::unique_ptr< CsysType > x)
      {
        this->csys_.set (std::move (x));
      }

      const SurfaceMesh::SourceType& SurfaceMesh::
      source () const
      {
        return this->source_.get ();
      }

      SurfaceMesh::SourceType& SurfaceMesh::
      source ()
      {
        return this->source_.get ();
      }

      void SurfaceMesh::
      source (const SourceType& x)
      {
        this->source_.set (x);
      }

      void SurfaceMesh::
      source (::std::unique_ptr< SourceType > x)
      {
        this->source_.set (std::move (x));
      }

      const SurfaceMesh::CsysDraggerType& SurfaceMesh::
      csysDragger () const
      {
        return this->csysDragger_.get ();
      }

      SurfaceMesh::CsysDraggerType& SurfaceMesh::
      csysDragger ()
      {
        return this->csysDragger_.get ();
      }

      void SurfaceMesh::
      csysDragger (const CsysDraggerType& x)
      {
        this->csysDragger_.set (x);
      }

      void SurfaceMesh::
      csysDragger (::std::unique_ptr< CsysDraggerType > x)
      {
        this->csysDragger_.set (std::move (x));
      }

      const SurfaceMesh::SurfaceType& SurfaceMesh::
      surface () const
      {
        return this->surface_.get ();
      }

      SurfaceMesh::SurfaceType& SurfaceMesh::
      surface ()
      {
        return this->surface_.get ();
      }

      void SurfaceMesh::
      surface (const SurfaceType& x)
      {
        this->surface_.set (x);
      }

      void SurfaceMesh::
      surface (::std::unique_ptr< SurfaceType > x)
      {
        this->surface_.set (std::move (x));
      }

      const SurfaceMesh::ParametersOCCTOptional& SurfaceMesh::
      parametersOCCT () const
      {
        return this->parametersOCCT_;
      }

      SurfaceMesh::ParametersOCCTOptional& SurfaceMesh::
      parametersOCCT ()
      {
        return this->parametersOCCT_;
      }

      void SurfaceMesh::
      parametersOCCT (const ParametersOCCTType& x)
      {
        this->parametersOCCT_.set (x);
      }

      void SurfaceMesh::
      parametersOCCT (const ParametersOCCTOptional& x)
      {
        this->parametersOCCT_ = x;
      }

      void SurfaceMesh::
      parametersOCCT (::std::unique_ptr< ParametersOCCTType > x)
      {
        this->parametersOCCT_.set (std::move (x));
      }

      const SurfaceMesh::ParametersNetgenOptional& SurfaceMesh::
      parametersNetgen () const
      {
        return this->parametersNetgen_;
      }

      SurfaceMesh::ParametersNetgenOptional& SurfaceMesh::
      parametersNetgen ()
      {
        return this->parametersNetgen_;
      }

      void SurfaceMesh::
      parametersNetgen (const ParametersNetgenType& x)
      {
        this->parametersNetgen_.set (x);
      }

      void SurfaceMesh::
      parametersNetgen (const ParametersNetgenOptional& x)
      {
        this->parametersNetgen_ = x;
      }

      void SurfaceMesh::
      parametersNetgen (::std::unique_ptr< ParametersNetgenType > x)
      {
        this->parametersNetgen_.set (std::move (x));
      }

      const SurfaceMesh::ParametersGMSHOptional& SurfaceMesh::
      parametersGMSH () const
      {
        return this->parametersGMSH_;
      }

      SurfaceMesh::ParametersGMSHOptional& SurfaceMesh::
      parametersGMSH ()
      {
        return this->parametersGMSH_;
      }

      void SurfaceMesh::
      parametersGMSH (const ParametersGMSHType& x)
      {
        this->parametersGMSH_.set (x);
      }

      void SurfaceMesh::
      parametersGMSH (const ParametersGMSHOptional& x)
      {
        this->parametersGMSH_ = x;
      }

      void SurfaceMesh::
      parametersGMSH (::std::unique_ptr< ParametersGMSHType > x)
      {
        this->parametersGMSH_.set (std::move (x));
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace sfms
    {
      // SurfaceMesh
      //

      SurfaceMesh::
      SurfaceMesh (const BaseType& base,
                   const MeshTypeType& meshType,
                   const CsysType& csys,
                   const SourceType& source,
                   const CsysDraggerType& csysDragger,
                   const SurfaceType& surface)
      : ::xml_schema::Type (),
        base_ (base, this),
        meshType_ (meshType, this),
        csys_ (csys, this),
        source_ (source, this),
        csysDragger_ (csysDragger, this),
        surface_ (surface, this),
        parametersOCCT_ (this),
        parametersNetgen_ (this),
        parametersGMSH_ (this)
      {
      }

      SurfaceMesh::
      SurfaceMesh (::std::unique_ptr< BaseType > base,
                   ::std::unique_ptr< MeshTypeType > meshType,
                   ::std::unique_ptr< CsysType > csys,
                   ::std::unique_ptr< SourceType > source,
                   ::std::unique_ptr< CsysDraggerType > csysDragger,
                   ::std::unique_ptr< SurfaceType > surface)
      : ::xml_schema::Type (),
        base_ (std::move (base), this),
        meshType_ (std::move (meshType), this),
        csys_ (std::move (csys), this),
        source_ (std::move (source), this),
        csysDragger_ (std::move (csysDragger), this),
        surface_ (std::move (surface), this),
        parametersOCCT_ (this),
        parametersNetgen_ (this),
        parametersGMSH_ (this)
      {
      }

      SurfaceMesh::
      SurfaceMesh (const SurfaceMesh& x,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        base_ (x.base_, f, this),
        meshType_ (x.meshType_, f, this),
        csys_ (x.csys_, f, this),
        source_ (x.source_, f, this),
        csysDragger_ (x.csysDragger_, f, this),
        surface_ (x.surface_, f, this),
        parametersOCCT_ (x.parametersOCCT_, f, this),
        parametersNetgen_ (x.parametersNetgen_, f, this),
        parametersGMSH_ (x.parametersGMSH_, f, this)
      {
      }

      SurfaceMesh::
      SurfaceMesh (const ::xercesc::DOMElement& e,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        base_ (this),
        meshType_ (this),
        csys_ (this),
        source_ (this),
        csysDragger_ (this),
        surface_ (this),
        parametersOCCT_ (this),
        parametersNetgen_ (this),
        parametersGMSH_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void SurfaceMesh::
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

          // meshType
          //
          if (n.name () == "meshType" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< MeshTypeType > r (
              MeshTypeTraits::create (i, f, this));

            if (!meshType_.present ())
            {
              this->meshType_.set (::std::move (r));
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

          // source
          //
          if (n.name () == "source" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< SourceType > r (
              SourceTraits::create (i, f, this));

            if (!source_.present ())
            {
              this->source_.set (::std::move (r));
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

          // surface
          //
          if (n.name () == "surface" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< SurfaceType > r (
              SurfaceTraits::create (i, f, this));

            if (!surface_.present ())
            {
              this->surface_.set (::std::move (r));
              continue;
            }
          }

          // parametersOCCT
          //
          if (n.name () == "parametersOCCT" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< ParametersOCCTType > r (
              ParametersOCCTTraits::create (i, f, this));

            if (!this->parametersOCCT_)
            {
              this->parametersOCCT_.set (::std::move (r));
              continue;
            }
          }

          // parametersNetgen
          //
          if (n.name () == "parametersNetgen" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< ParametersNetgenType > r (
              ParametersNetgenTraits::create (i, f, this));

            if (!this->parametersNetgen_)
            {
              this->parametersNetgen_.set (::std::move (r));
              continue;
            }
          }

          // parametersGMSH
          //
          if (n.name () == "parametersGMSH" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< ParametersGMSHType > r (
              ParametersGMSHTraits::create (i, f, this));

            if (!this->parametersGMSH_)
            {
              this->parametersGMSH_.set (::std::move (r));
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

        if (!meshType_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "meshType",
            "");
        }

        if (!csys_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "csys",
            "");
        }

        if (!source_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "source",
            "");
        }

        if (!csysDragger_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "csysDragger",
            "");
        }

        if (!surface_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "surface",
            "");
        }
      }

      SurfaceMesh* SurfaceMesh::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class SurfaceMesh (*this, f, c);
      }

      SurfaceMesh& SurfaceMesh::
      operator= (const SurfaceMesh& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->base_ = x.base_;
          this->meshType_ = x.meshType_;
          this->csys_ = x.csys_;
          this->source_ = x.source_;
          this->csysDragger_ = x.csysDragger_;
          this->surface_ = x.surface_;
          this->parametersOCCT_ = x.parametersOCCT_;
          this->parametersNetgen_ = x.parametersNetgen_;
          this->parametersGMSH_ = x.parametersGMSH_;
        }

        return *this;
      }

      SurfaceMesh::
      ~SurfaceMesh ()
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
    namespace sfms
    {
      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > (
          ::prj::srl::sfms::surfaceMesh (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > (
          ::prj::srl::sfms::surfaceMesh (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (const ::std::string& u,
                   ::xercesc::DOMErrorHandler& h,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > (
          ::prj::srl::sfms::surfaceMesh (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::std::istream& is,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::sfms::surfaceMesh (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::std::istream& is,
                   ::xml_schema::ErrorHandler& h,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::sfms::surfaceMesh (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::std::istream& is,
                   ::xercesc::DOMErrorHandler& h,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::sfms::surfaceMesh (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::std::istream& is,
                   const ::std::string& sid,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::sfms::surfaceMesh (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::std::istream& is,
                   const ::std::string& sid,
                   ::xml_schema::ErrorHandler& h,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::sfms::surfaceMesh (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::std::istream& is,
                   const ::std::string& sid,
                   ::xercesc::DOMErrorHandler& h,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::sfms::surfaceMesh (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::xercesc::InputSource& i,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::tree::error_handler< char > h;

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

        return ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > (
          ::prj::srl::sfms::surfaceMesh (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::xercesc::InputSource& i,
                   ::xml_schema::ErrorHandler& h,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > (
          ::prj::srl::sfms::surfaceMesh (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::xercesc::InputSource& i,
                   ::xercesc::DOMErrorHandler& h,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > (
          ::prj::srl::sfms::surfaceMesh (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (const ::xercesc::DOMDocument& doc,
                   ::xml_schema::Flags f,
                   const ::xml_schema::Properties& p)
      {
        if (f & ::xml_schema::Flags::keep_dom)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

          return ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > (
            ::prj::srl::sfms::surfaceMesh (
              std::move (d), f | ::xml_schema::Flags::own_dom, p));
        }

        const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "surfaceMesh" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/sfms")
        {
          ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > r (
            ::xsd::cxx::tree::traits< ::prj::srl::sfms::SurfaceMesh, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "surfaceMesh",
          "http://www.cadseer.com/prj/srl/sfms");
      }

      ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh >
      surfaceMesh (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

        if (n.name () == "surfaceMesh" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/sfms")
        {
          ::std::unique_ptr< ::prj::srl::sfms::SurfaceMesh > r (
            ::xsd::cxx::tree::traits< ::prj::srl::sfms::SurfaceMesh, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "surfaceMesh",
          "http://www.cadseer.com/prj/srl/sfms");
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
    namespace sfms
    {
      void
      operator<< (::xercesc::DOMElement& e, const SurfaceMesh& i)
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

        // meshType
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "meshType",
              e));

          s << i.meshType ();
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

        // source
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "source",
              e));

          s << i.source ();
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

        // surface
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "surface",
              e));

          s << i.surface ();
        }

        // parametersOCCT
        //
        if (i.parametersOCCT ())
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "parametersOCCT",
              e));

          s << *i.parametersOCCT ();
        }

        // parametersNetgen
        //
        if (i.parametersNetgen ())
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "parametersNetgen",
              e));

          s << *i.parametersNetgen ();
        }

        // parametersGMSH
        //
        if (i.parametersGMSH ())
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "parametersGMSH",
              e));

          s << *i.parametersGMSH ();
        }
      }

      void
      surfaceMesh (::std::ostream& o,
                   const ::prj::srl::sfms::SurfaceMesh& s,
                   const ::xml_schema::NamespaceInfomap& m,
                   const ::std::string& e,
                   ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::sfms::surfaceMesh (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      surfaceMesh (::std::ostream& o,
                   const ::prj::srl::sfms::SurfaceMesh& s,
                   ::xml_schema::ErrorHandler& h,
                   const ::xml_schema::NamespaceInfomap& m,
                   const ::std::string& e,
                   ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::sfms::surfaceMesh (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      surfaceMesh (::std::ostream& o,
                   const ::prj::srl::sfms::SurfaceMesh& s,
                   ::xercesc::DOMErrorHandler& h,
                   const ::xml_schema::NamespaceInfomap& m,
                   const ::std::string& e,
                   ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::sfms::surfaceMesh (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      surfaceMesh (::xercesc::XMLFormatTarget& t,
                   const ::prj::srl::sfms::SurfaceMesh& s,
                   const ::xml_schema::NamespaceInfomap& m,
                   const ::std::string& e,
                   ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::sfms::surfaceMesh (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      surfaceMesh (::xercesc::XMLFormatTarget& t,
                   const ::prj::srl::sfms::SurfaceMesh& s,
                   ::xml_schema::ErrorHandler& h,
                   const ::xml_schema::NamespaceInfomap& m,
                   const ::std::string& e,
                   ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::sfms::surfaceMesh (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      surfaceMesh (::xercesc::XMLFormatTarget& t,
                   const ::prj::srl::sfms::SurfaceMesh& s,
                   ::xercesc::DOMErrorHandler& h,
                   const ::xml_schema::NamespaceInfomap& m,
                   const ::std::string& e,
                   ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::sfms::surfaceMesh (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      surfaceMesh (::xercesc::DOMDocument& d,
                   const ::prj::srl::sfms::SurfaceMesh& s,
                   ::xml_schema::Flags)
      {
        ::xercesc::DOMElement& e (*d.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "surfaceMesh" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/sfms")
        {
          e << s;
        }
        else
        {
          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "surfaceMesh",
            "http://www.cadseer.com/prj/srl/sfms");
        }
      }

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      surfaceMesh (const ::prj::srl::sfms::SurfaceMesh& s,
                   const ::xml_schema::NamespaceInfomap& m,
                   ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::serialize< char > (
            "surfaceMesh",
            "http://www.cadseer.com/prj/srl/sfms",
            m, f));

        ::prj::srl::sfms::surfaceMesh (*d, s, f);
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

