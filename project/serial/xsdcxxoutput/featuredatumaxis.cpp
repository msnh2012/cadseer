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

#include "featuredatumaxis.h"

namespace prj
{
  namespace srl
  {
    // FeatureDatumAxis
    // 

    const FeatureDatumAxis::FeatureBaseType& FeatureDatumAxis::
    featureBase () const
    {
      return this->featureBase_.get ();
    }

    FeatureDatumAxis::FeatureBaseType& FeatureDatumAxis::
    featureBase ()
    {
      return this->featureBase_.get ();
    }

    void FeatureDatumAxis::
    featureBase (const FeatureBaseType& x)
    {
      this->featureBase_.set (x);
    }

    void FeatureDatumAxis::
    featureBase (::std::unique_ptr< FeatureBaseType > x)
    {
      this->featureBase_.set (std::move (x));
    }

    const FeatureDatumAxis::AxisTypeType& FeatureDatumAxis::
    axisType () const
    {
      return this->axisType_.get ();
    }

    FeatureDatumAxis::AxisTypeType& FeatureDatumAxis::
    axisType ()
    {
      return this->axisType_.get ();
    }

    void FeatureDatumAxis::
    axisType (const AxisTypeType& x)
    {
      this->axisType_.set (x);
    }

    const FeatureDatumAxis::PicksType& FeatureDatumAxis::
    picks () const
    {
      return this->picks_.get ();
    }

    FeatureDatumAxis::PicksType& FeatureDatumAxis::
    picks ()
    {
      return this->picks_.get ();
    }

    void FeatureDatumAxis::
    picks (const PicksType& x)
    {
      this->picks_.set (x);
    }

    void FeatureDatumAxis::
    picks (::std::unique_ptr< PicksType > x)
    {
      this->picks_.set (std::move (x));
    }

    const FeatureDatumAxis::OriginType& FeatureDatumAxis::
    origin () const
    {
      return this->origin_.get ();
    }

    FeatureDatumAxis::OriginType& FeatureDatumAxis::
    origin ()
    {
      return this->origin_.get ();
    }

    void FeatureDatumAxis::
    origin (const OriginType& x)
    {
      this->origin_.set (x);
    }

    void FeatureDatumAxis::
    origin (::std::unique_ptr< OriginType > x)
    {
      this->origin_.set (std::move (x));
    }

    const FeatureDatumAxis::DirectionType& FeatureDatumAxis::
    direction () const
    {
      return this->direction_.get ();
    }

    FeatureDatumAxis::DirectionType& FeatureDatumAxis::
    direction ()
    {
      return this->direction_.get ();
    }

    void FeatureDatumAxis::
    direction (const DirectionType& x)
    {
      this->direction_.set (x);
    }

    void FeatureDatumAxis::
    direction (::std::unique_ptr< DirectionType > x)
    {
      this->direction_.set (std::move (x));
    }

    const FeatureDatumAxis::CsysType& FeatureDatumAxis::
    csys () const
    {
      return this->csys_.get ();
    }

    FeatureDatumAxis::CsysType& FeatureDatumAxis::
    csys ()
    {
      return this->csys_.get ();
    }

    void FeatureDatumAxis::
    csys (const CsysType& x)
    {
      this->csys_.set (x);
    }

    void FeatureDatumAxis::
    csys (::std::unique_ptr< CsysType > x)
    {
      this->csys_.set (std::move (x));
    }

    const FeatureDatumAxis::AutoSizeType& FeatureDatumAxis::
    autoSize () const
    {
      return this->autoSize_.get ();
    }

    FeatureDatumAxis::AutoSizeType& FeatureDatumAxis::
    autoSize ()
    {
      return this->autoSize_.get ();
    }

    void FeatureDatumAxis::
    autoSize (const AutoSizeType& x)
    {
      this->autoSize_.set (x);
    }

    void FeatureDatumAxis::
    autoSize (::std::unique_ptr< AutoSizeType > x)
    {
      this->autoSize_.set (std::move (x));
    }

    const FeatureDatumAxis::SizeType& FeatureDatumAxis::
    size () const
    {
      return this->size_.get ();
    }

    FeatureDatumAxis::SizeType& FeatureDatumAxis::
    size ()
    {
      return this->size_.get ();
    }

    void FeatureDatumAxis::
    size (const SizeType& x)
    {
      this->size_.set (x);
    }

    void FeatureDatumAxis::
    size (::std::unique_ptr< SizeType > x)
    {
      this->size_.set (std::move (x));
    }

    const FeatureDatumAxis::CsysDraggerType& FeatureDatumAxis::
    csysDragger () const
    {
      return this->csysDragger_.get ();
    }

    FeatureDatumAxis::CsysDraggerType& FeatureDatumAxis::
    csysDragger ()
    {
      return this->csysDragger_.get ();
    }

    void FeatureDatumAxis::
    csysDragger (const CsysDraggerType& x)
    {
      this->csysDragger_.set (x);
    }

    void FeatureDatumAxis::
    csysDragger (::std::unique_ptr< CsysDraggerType > x)
    {
      this->csysDragger_.set (std::move (x));
    }

    const FeatureDatumAxis::AutoSizeLabelType& FeatureDatumAxis::
    autoSizeLabel () const
    {
      return this->autoSizeLabel_.get ();
    }

    FeatureDatumAxis::AutoSizeLabelType& FeatureDatumAxis::
    autoSizeLabel ()
    {
      return this->autoSizeLabel_.get ();
    }

    void FeatureDatumAxis::
    autoSizeLabel (const AutoSizeLabelType& x)
    {
      this->autoSizeLabel_.set (x);
    }

    void FeatureDatumAxis::
    autoSizeLabel (::std::unique_ptr< AutoSizeLabelType > x)
    {
      this->autoSizeLabel_.set (std::move (x));
    }

    const FeatureDatumAxis::SizeLabelType& FeatureDatumAxis::
    sizeLabel () const
    {
      return this->sizeLabel_.get ();
    }

    FeatureDatumAxis::SizeLabelType& FeatureDatumAxis::
    sizeLabel ()
    {
      return this->sizeLabel_.get ();
    }

    void FeatureDatumAxis::
    sizeLabel (const SizeLabelType& x)
    {
      this->sizeLabel_.set (x);
    }

    void FeatureDatumAxis::
    sizeLabel (::std::unique_ptr< SizeLabelType > x)
    {
      this->sizeLabel_.set (std::move (x));
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    // FeatureDatumAxis
    //

    FeatureDatumAxis::
    FeatureDatumAxis (const FeatureBaseType& featureBase,
                      const AxisTypeType& axisType,
                      const PicksType& picks,
                      const OriginType& origin,
                      const DirectionType& direction,
                      const CsysType& csys,
                      const AutoSizeType& autoSize,
                      const SizeType& size,
                      const CsysDraggerType& csysDragger,
                      const AutoSizeLabelType& autoSizeLabel,
                      const SizeLabelType& sizeLabel)
    : ::xml_schema::Type (),
      featureBase_ (featureBase, this),
      axisType_ (axisType, this),
      picks_ (picks, this),
      origin_ (origin, this),
      direction_ (direction, this),
      csys_ (csys, this),
      autoSize_ (autoSize, this),
      size_ (size, this),
      csysDragger_ (csysDragger, this),
      autoSizeLabel_ (autoSizeLabel, this),
      sizeLabel_ (sizeLabel, this)
    {
    }

    FeatureDatumAxis::
    FeatureDatumAxis (::std::unique_ptr< FeatureBaseType > featureBase,
                      const AxisTypeType& axisType,
                      ::std::unique_ptr< PicksType > picks,
                      ::std::unique_ptr< OriginType > origin,
                      ::std::unique_ptr< DirectionType > direction,
                      ::std::unique_ptr< CsysType > csys,
                      ::std::unique_ptr< AutoSizeType > autoSize,
                      ::std::unique_ptr< SizeType > size,
                      ::std::unique_ptr< CsysDraggerType > csysDragger,
                      ::std::unique_ptr< AutoSizeLabelType > autoSizeLabel,
                      ::std::unique_ptr< SizeLabelType > sizeLabel)
    : ::xml_schema::Type (),
      featureBase_ (std::move (featureBase), this),
      axisType_ (axisType, this),
      picks_ (std::move (picks), this),
      origin_ (std::move (origin), this),
      direction_ (std::move (direction), this),
      csys_ (std::move (csys), this),
      autoSize_ (std::move (autoSize), this),
      size_ (std::move (size), this),
      csysDragger_ (std::move (csysDragger), this),
      autoSizeLabel_ (std::move (autoSizeLabel), this),
      sizeLabel_ (std::move (sizeLabel), this)
    {
    }

    FeatureDatumAxis::
    FeatureDatumAxis (const FeatureDatumAxis& x,
                      ::xml_schema::Flags f,
                      ::xml_schema::Container* c)
    : ::xml_schema::Type (x, f, c),
      featureBase_ (x.featureBase_, f, this),
      axisType_ (x.axisType_, f, this),
      picks_ (x.picks_, f, this),
      origin_ (x.origin_, f, this),
      direction_ (x.direction_, f, this),
      csys_ (x.csys_, f, this),
      autoSize_ (x.autoSize_, f, this),
      size_ (x.size_, f, this),
      csysDragger_ (x.csysDragger_, f, this),
      autoSizeLabel_ (x.autoSizeLabel_, f, this),
      sizeLabel_ (x.sizeLabel_, f, this)
    {
    }

    FeatureDatumAxis::
    FeatureDatumAxis (const ::xercesc::DOMElement& e,
                      ::xml_schema::Flags f,
                      ::xml_schema::Container* c)
    : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
      featureBase_ (this),
      axisType_ (this),
      picks_ (this),
      origin_ (this),
      direction_ (this),
      csys_ (this),
      autoSize_ (this),
      size_ (this),
      csysDragger_ (this),
      autoSizeLabel_ (this),
      sizeLabel_ (this)
    {
      if ((f & ::xml_schema::Flags::base) == 0)
      {
        ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
        this->parse (p, f);
      }
    }

    void FeatureDatumAxis::
    parse (::xsd::cxx::xml::dom::parser< char >& p,
           ::xml_schema::Flags f)
    {
      for (; p.more_content (); p.next_content (false))
      {
        const ::xercesc::DOMElement& i (p.cur_element ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (i));

        // featureBase
        //
        if (n.name () == "featureBase" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< FeatureBaseType > r (
            FeatureBaseTraits::create (i, f, this));

          if (!featureBase_.present ())
          {
            this->featureBase_.set (::std::move (r));
            continue;
          }
        }

        // axisType
        //
        if (n.name () == "axisType" && n.namespace_ ().empty ())
        {
          if (!axisType_.present ())
          {
            this->axisType_.set (AxisTypeTraits::create (i, f, this));
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

        // origin
        //
        if (n.name () == "origin" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< OriginType > r (
            OriginTraits::create (i, f, this));

          if (!origin_.present ())
          {
            this->origin_.set (::std::move (r));
            continue;
          }
        }

        // direction
        //
        if (n.name () == "direction" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< DirectionType > r (
            DirectionTraits::create (i, f, this));

          if (!direction_.present ())
          {
            this->direction_.set (::std::move (r));
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

        // autoSize
        //
        if (n.name () == "autoSize" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< AutoSizeType > r (
            AutoSizeTraits::create (i, f, this));

          if (!autoSize_.present ())
          {
            this->autoSize_.set (::std::move (r));
            continue;
          }
        }

        // size
        //
        if (n.name () == "size" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< SizeType > r (
            SizeTraits::create (i, f, this));

          if (!size_.present ())
          {
            this->size_.set (::std::move (r));
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

        // autoSizeLabel
        //
        if (n.name () == "autoSizeLabel" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< AutoSizeLabelType > r (
            AutoSizeLabelTraits::create (i, f, this));

          if (!autoSizeLabel_.present ())
          {
            this->autoSizeLabel_.set (::std::move (r));
            continue;
          }
        }

        // sizeLabel
        //
        if (n.name () == "sizeLabel" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< SizeLabelType > r (
            SizeLabelTraits::create (i, f, this));

          if (!sizeLabel_.present ())
          {
            this->sizeLabel_.set (::std::move (r));
            continue;
          }
        }

        break;
      }

      if (!featureBase_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "featureBase",
          "");
      }

      if (!axisType_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "axisType",
          "");
      }

      if (!picks_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "picks",
          "");
      }

      if (!origin_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "origin",
          "");
      }

      if (!direction_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "direction",
          "");
      }

      if (!csys_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "csys",
          "");
      }

      if (!autoSize_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "autoSize",
          "");
      }

      if (!size_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "size",
          "");
      }

      if (!csysDragger_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "csysDragger",
          "");
      }

      if (!autoSizeLabel_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "autoSizeLabel",
          "");
      }

      if (!sizeLabel_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "sizeLabel",
          "");
      }
    }

    FeatureDatumAxis* FeatureDatumAxis::
    _clone (::xml_schema::Flags f,
            ::xml_schema::Container* c) const
    {
      return new class FeatureDatumAxis (*this, f, c);
    }

    FeatureDatumAxis& FeatureDatumAxis::
    operator= (const FeatureDatumAxis& x)
    {
      if (this != &x)
      {
        static_cast< ::xml_schema::Type& > (*this) = x;
        this->featureBase_ = x.featureBase_;
        this->axisType_ = x.axisType_;
        this->picks_ = x.picks_;
        this->origin_ = x.origin_;
        this->direction_ = x.direction_;
        this->csys_ = x.csys_;
        this->autoSize_ = x.autoSize_;
        this->size_ = x.size_;
        this->csysDragger_ = x.csysDragger_;
        this->autoSizeLabel_ = x.autoSizeLabel_;
        this->sizeLabel_ = x.sizeLabel_;
      }

      return *this;
    }

    FeatureDatumAxis::
    ~FeatureDatumAxis ()
    {
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
    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (const ::std::string& u,
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

      return ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > (
        ::prj::srl::datumAxis (
          std::move (d), f | ::xml_schema::Flags::own_dom, p));
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (const ::std::string& u,
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

      return ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > (
        ::prj::srl::datumAxis (
          std::move (d), f | ::xml_schema::Flags::own_dom, p));
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (const ::std::string& u,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::xsd::cxx::xml::dom::parse< char > (
          u, h, p, f));

      if (!d.get ())
        throw ::xsd::cxx::tree::parsing< char > ();

      return ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > (
        ::prj::srl::datumAxis (
          std::move (d), f | ::xml_schema::Flags::own_dom, p));
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::std::istream& is,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xsd::cxx::xml::auto_initializer i (
        (f & ::xml_schema::Flags::dont_initialize) == 0,
        (f & ::xml_schema::Flags::keep_dom) == 0);

      ::xsd::cxx::xml::sax::std_input_source isrc (is);
      return ::prj::srl::datumAxis (isrc, f, p);
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::std::istream& is,
               ::xml_schema::ErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xsd::cxx::xml::auto_initializer i (
        (f & ::xml_schema::Flags::dont_initialize) == 0,
        (f & ::xml_schema::Flags::keep_dom) == 0);

      ::xsd::cxx::xml::sax::std_input_source isrc (is);
      return ::prj::srl::datumAxis (isrc, h, f, p);
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::std::istream& is,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xsd::cxx::xml::sax::std_input_source isrc (is);
      return ::prj::srl::datumAxis (isrc, h, f, p);
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::std::istream& is,
               const ::std::string& sid,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xsd::cxx::xml::auto_initializer i (
        (f & ::xml_schema::Flags::dont_initialize) == 0,
        (f & ::xml_schema::Flags::keep_dom) == 0);

      ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
      return ::prj::srl::datumAxis (isrc, f, p);
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::std::istream& is,
               const ::std::string& sid,
               ::xml_schema::ErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xsd::cxx::xml::auto_initializer i (
        (f & ::xml_schema::Flags::dont_initialize) == 0,
        (f & ::xml_schema::Flags::keep_dom) == 0);

      ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
      return ::prj::srl::datumAxis (isrc, h, f, p);
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::std::istream& is,
               const ::std::string& sid,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
      return ::prj::srl::datumAxis (isrc, h, f, p);
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::xercesc::InputSource& i,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xsd::cxx::tree::error_handler< char > h;

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::xsd::cxx::xml::dom::parse< char > (
          i, h, p, f));

      h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

      return ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > (
        ::prj::srl::datumAxis (
          std::move (d), f | ::xml_schema::Flags::own_dom, p));
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::xercesc::InputSource& i,
               ::xml_schema::ErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::xsd::cxx::xml::dom::parse< char > (
          i, h, p, f));

      if (!d.get ())
        throw ::xsd::cxx::tree::parsing< char > ();

      return ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > (
        ::prj::srl::datumAxis (
          std::move (d), f | ::xml_schema::Flags::own_dom, p));
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::xercesc::InputSource& i,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::xsd::cxx::xml::dom::parse< char > (
          i, h, p, f));

      if (!d.get ())
        throw ::xsd::cxx::tree::parsing< char > ();

      return ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > (
        ::prj::srl::datumAxis (
          std::move (d), f | ::xml_schema::Flags::own_dom, p));
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (const ::xercesc::DOMDocument& doc,
               ::xml_schema::Flags f,
               const ::xml_schema::Properties& p)
    {
      if (f & ::xml_schema::Flags::keep_dom)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

        return ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > (
          ::prj::srl::datumAxis (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (e));

      if (n.name () == "datumAxis" &&
          n.namespace_ () == "http://www.cadseer.com/prj/srl")
      {
        ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > r (
          ::xsd::cxx::tree::traits< ::prj::srl::FeatureDatumAxis, char >::create (
            e, f, 0));
        return r;
      }

      throw ::xsd::cxx::tree::unexpected_element < char > (
        n.name (),
        n.namespace_ (),
        "datumAxis",
        "http://www.cadseer.com/prj/srl");
    }

    ::std::unique_ptr< ::prj::srl::FeatureDatumAxis >
    datumAxis (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

      if (n.name () == "datumAxis" &&
          n.namespace_ () == "http://www.cadseer.com/prj/srl")
      {
        ::std::unique_ptr< ::prj::srl::FeatureDatumAxis > r (
          ::xsd::cxx::tree::traits< ::prj::srl::FeatureDatumAxis, char >::create (
            e, f, 0));
        return r;
      }

      throw ::xsd::cxx::tree::unexpected_element < char > (
        n.name (),
        n.namespace_ (),
        "datumAxis",
        "http://www.cadseer.com/prj/srl");
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
    void
    operator<< (::xercesc::DOMElement& e, const FeatureDatumAxis& i)
    {
      e << static_cast< const ::xml_schema::Type& > (i);

      // featureBase
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "featureBase",
            e));

        s << i.featureBase ();
      }

      // axisType
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "axisType",
            e));

        s << i.axisType ();
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

      // origin
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "origin",
            e));

        s << i.origin ();
      }

      // direction
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "direction",
            e));

        s << i.direction ();
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

      // autoSize
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "autoSize",
            e));

        s << i.autoSize ();
      }

      // size
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "size",
            e));

        s << i.size ();
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

      // autoSizeLabel
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "autoSizeLabel",
            e));

        s << i.autoSizeLabel ();
      }

      // sizeLabel
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "sizeLabel",
            e));

        s << i.sizeLabel ();
      }
    }

    void
    datumAxis (::std::ostream& o,
               const ::prj::srl::FeatureDatumAxis& s,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
    {
      ::xsd::cxx::xml::auto_initializer i (
        (f & ::xml_schema::Flags::dont_initialize) == 0);

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::prj::srl::datumAxis (s, m, f));

      ::xsd::cxx::tree::error_handler< char > h;

      ::xsd::cxx::xml::dom::ostream_format_target t (o);
      if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
      {
        h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
      }
    }

    void
    datumAxis (::std::ostream& o,
               const ::prj::srl::FeatureDatumAxis& s,
               ::xml_schema::ErrorHandler& h,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
    {
      ::xsd::cxx::xml::auto_initializer i (
        (f & ::xml_schema::Flags::dont_initialize) == 0);

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::prj::srl::datumAxis (s, m, f));
      ::xsd::cxx::xml::dom::ostream_format_target t (o);
      if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
      {
        throw ::xsd::cxx::tree::serialization< char > ();
      }
    }

    void
    datumAxis (::std::ostream& o,
               const ::prj::srl::FeatureDatumAxis& s,
               ::xercesc::DOMErrorHandler& h,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::prj::srl::datumAxis (s, m, f));
      ::xsd::cxx::xml::dom::ostream_format_target t (o);
      if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
      {
        throw ::xsd::cxx::tree::serialization< char > ();
      }
    }

    void
    datumAxis (::xercesc::XMLFormatTarget& t,
               const ::prj::srl::FeatureDatumAxis& s,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::prj::srl::datumAxis (s, m, f));

      ::xsd::cxx::tree::error_handler< char > h;

      if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
      {
        h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
      }
    }

    void
    datumAxis (::xercesc::XMLFormatTarget& t,
               const ::prj::srl::FeatureDatumAxis& s,
               ::xml_schema::ErrorHandler& h,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::prj::srl::datumAxis (s, m, f));
      if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
      {
        throw ::xsd::cxx::tree::serialization< char > ();
      }
    }

    void
    datumAxis (::xercesc::XMLFormatTarget& t,
               const ::prj::srl::FeatureDatumAxis& s,
               ::xercesc::DOMErrorHandler& h,
               const ::xml_schema::NamespaceInfomap& m,
               const ::std::string& e,
               ::xml_schema::Flags f)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::prj::srl::datumAxis (s, m, f));
      if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
      {
        throw ::xsd::cxx::tree::serialization< char > ();
      }
    }

    void
    datumAxis (::xercesc::DOMDocument& d,
               const ::prj::srl::FeatureDatumAxis& s,
               ::xml_schema::Flags)
    {
      ::xercesc::DOMElement& e (*d.getDocumentElement ());
      const ::xsd::cxx::xml::qualified_name< char > n (
        ::xsd::cxx::xml::dom::name< char > (e));

      if (n.name () == "datumAxis" &&
          n.namespace_ () == "http://www.cadseer.com/prj/srl")
      {
        e << s;
      }
      else
      {
        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "datumAxis",
          "http://www.cadseer.com/prj/srl");
      }
    }

    ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
    datumAxis (const ::prj::srl::FeatureDatumAxis& s,
               const ::xml_schema::NamespaceInfomap& m,
               ::xml_schema::Flags f)
    {
      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
        ::xsd::cxx::xml::dom::serialize< char > (
          "datumAxis",
          "http://www.cadseer.com/prj/srl",
          m, f));

      ::prj::srl::datumAxis (*d, s, f);
      return d;
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.
