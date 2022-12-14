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

#include "prjsrlflsfill.h"

namespace prj
{
  namespace srl
  {
    namespace fls
    {
      // Boundary
      // 

      const Boundary::EdgePickType& Boundary::
      edgePick () const
      {
        return this->edgePick_.get ();
      }

      Boundary::EdgePickType& Boundary::
      edgePick ()
      {
        return this->edgePick_.get ();
      }

      void Boundary::
      edgePick (const EdgePickType& x)
      {
        this->edgePick_.set (x);
      }

      void Boundary::
      edgePick (::std::unique_ptr< EdgePickType > x)
      {
        this->edgePick_.set (std::move (x));
      }

      const Boundary::FacePickType& Boundary::
      facePick () const
      {
        return this->facePick_.get ();
      }

      Boundary::FacePickType& Boundary::
      facePick ()
      {
        return this->facePick_.get ();
      }

      void Boundary::
      facePick (const FacePickType& x)
      {
        this->facePick_.set (x);
      }

      void Boundary::
      facePick (::std::unique_ptr< FacePickType > x)
      {
        this->facePick_.set (std::move (x));
      }

      const Boundary::ContinuityType& Boundary::
      continuity () const
      {
        return this->continuity_.get ();
      }

      Boundary::ContinuityType& Boundary::
      continuity ()
      {
        return this->continuity_.get ();
      }

      void Boundary::
      continuity (const ContinuityType& x)
      {
        this->continuity_.set (x);
      }

      void Boundary::
      continuity (::std::unique_ptr< ContinuityType > x)
      {
        this->continuity_.set (std::move (x));
      }

      const Boundary::ContinuityLabelType& Boundary::
      continuityLabel () const
      {
        return this->continuityLabel_.get ();
      }

      Boundary::ContinuityLabelType& Boundary::
      continuityLabel ()
      {
        return this->continuityLabel_.get ();
      }

      void Boundary::
      continuityLabel (const ContinuityLabelType& x)
      {
        this->continuityLabel_.set (x);
      }

      void Boundary::
      continuityLabel (::std::unique_ptr< ContinuityLabelType > x)
      {
        this->continuityLabel_.set (std::move (x));
      }


      // Fill
      // 

      const Fill::BaseType& Fill::
      base () const
      {
        return this->base_.get ();
      }

      Fill::BaseType& Fill::
      base ()
      {
        return this->base_.get ();
      }

      void Fill::
      base (const BaseType& x)
      {
        this->base_.set (x);
      }

      void Fill::
      base (::std::unique_ptr< BaseType > x)
      {
        this->base_.set (std::move (x));
      }

      const Fill::InitialPickType& Fill::
      initialPick () const
      {
        return this->initialPick_.get ();
      }

      Fill::InitialPickType& Fill::
      initialPick ()
      {
        return this->initialPick_.get ();
      }

      void Fill::
      initialPick (const InitialPickType& x)
      {
        this->initialPick_.set (x);
      }

      void Fill::
      initialPick (::std::unique_ptr< InitialPickType > x)
      {
        this->initialPick_.set (std::move (x));
      }

      const Fill::InternalPicksType& Fill::
      internalPicks () const
      {
        return this->internalPicks_.get ();
      }

      Fill::InternalPicksType& Fill::
      internalPicks ()
      {
        return this->internalPicks_.get ();
      }

      void Fill::
      internalPicks (const InternalPicksType& x)
      {
        this->internalPicks_.set (x);
      }

      void Fill::
      internalPicks (::std::unique_ptr< InternalPicksType > x)
      {
        this->internalPicks_.set (std::move (x));
      }

      const Fill::BoundariesSequence& Fill::
      boundaries () const
      {
        return this->boundaries_;
      }

      Fill::BoundariesSequence& Fill::
      boundaries ()
      {
        return this->boundaries_;
      }

      void Fill::
      boundaries (const BoundariesSequence& s)
      {
        this->boundaries_ = s;
      }

      const Fill::SeerShapeType& Fill::
      seerShape () const
      {
        return this->seerShape_.get ();
      }

      Fill::SeerShapeType& Fill::
      seerShape ()
      {
        return this->seerShape_.get ();
      }

      void Fill::
      seerShape (const SeerShapeType& x)
      {
        this->seerShape_.set (x);
      }

      void Fill::
      seerShape (::std::unique_ptr< SeerShapeType > x)
      {
        this->seerShape_.set (std::move (x));
      }

      const Fill::WireIdType& Fill::
      wireId () const
      {
        return this->wireId_.get ();
      }

      Fill::WireIdType& Fill::
      wireId ()
      {
        return this->wireId_.get ();
      }

      void Fill::
      wireId (const WireIdType& x)
      {
        this->wireId_.set (x);
      }

      void Fill::
      wireId (::std::unique_ptr< WireIdType > x)
      {
        this->wireId_.set (std::move (x));
      }

      const Fill::FaceIdType& Fill::
      faceId () const
      {
        return this->faceId_.get ();
      }

      Fill::FaceIdType& Fill::
      faceId ()
      {
        return this->faceId_.get ();
      }

      void Fill::
      faceId (const FaceIdType& x)
      {
        this->faceId_.set (x);
      }

      void Fill::
      faceId (::std::unique_ptr< FaceIdType > x)
      {
        this->faceId_.set (std::move (x));
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace fls
    {
      // Boundary
      //

      Boundary::
      Boundary (const EdgePickType& edgePick,
                const FacePickType& facePick,
                const ContinuityType& continuity,
                const ContinuityLabelType& continuityLabel)
      : ::xml_schema::Type (),
        edgePick_ (edgePick, this),
        facePick_ (facePick, this),
        continuity_ (continuity, this),
        continuityLabel_ (continuityLabel, this)
      {
      }

      Boundary::
      Boundary (::std::unique_ptr< EdgePickType > edgePick,
                ::std::unique_ptr< FacePickType > facePick,
                ::std::unique_ptr< ContinuityType > continuity,
                ::std::unique_ptr< ContinuityLabelType > continuityLabel)
      : ::xml_schema::Type (),
        edgePick_ (std::move (edgePick), this),
        facePick_ (std::move (facePick), this),
        continuity_ (std::move (continuity), this),
        continuityLabel_ (std::move (continuityLabel), this)
      {
      }

      Boundary::
      Boundary (const Boundary& x,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        edgePick_ (x.edgePick_, f, this),
        facePick_ (x.facePick_, f, this),
        continuity_ (x.continuity_, f, this),
        continuityLabel_ (x.continuityLabel_, f, this)
      {
      }

      Boundary::
      Boundary (const ::xercesc::DOMElement& e,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        edgePick_ (this),
        facePick_ (this),
        continuity_ (this),
        continuityLabel_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void Boundary::
      parse (::xsd::cxx::xml::dom::parser< char >& p,
             ::xml_schema::Flags f)
      {
        for (; p.more_content (); p.next_content (false))
        {
          const ::xercesc::DOMElement& i (p.cur_element ());
          const ::xsd::cxx::xml::qualified_name< char > n (
            ::xsd::cxx::xml::dom::name< char > (i));

          // edgePick
          //
          if (n.name () == "edgePick" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< EdgePickType > r (
              EdgePickTraits::create (i, f, this));

            if (!edgePick_.present ())
            {
              this->edgePick_.set (::std::move (r));
              continue;
            }
          }

          // facePick
          //
          if (n.name () == "facePick" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< FacePickType > r (
              FacePickTraits::create (i, f, this));

            if (!facePick_.present ())
            {
              this->facePick_.set (::std::move (r));
              continue;
            }
          }

          // continuity
          //
          if (n.name () == "continuity" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< ContinuityType > r (
              ContinuityTraits::create (i, f, this));

            if (!continuity_.present ())
            {
              this->continuity_.set (::std::move (r));
              continue;
            }
          }

          // continuityLabel
          //
          if (n.name () == "continuityLabel" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< ContinuityLabelType > r (
              ContinuityLabelTraits::create (i, f, this));

            if (!continuityLabel_.present ())
            {
              this->continuityLabel_.set (::std::move (r));
              continue;
            }
          }

          break;
        }

        if (!edgePick_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "edgePick",
            "");
        }

        if (!facePick_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "facePick",
            "");
        }

        if (!continuity_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "continuity",
            "");
        }

        if (!continuityLabel_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "continuityLabel",
            "");
        }
      }

      Boundary* Boundary::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class Boundary (*this, f, c);
      }

      Boundary& Boundary::
      operator= (const Boundary& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->edgePick_ = x.edgePick_;
          this->facePick_ = x.facePick_;
          this->continuity_ = x.continuity_;
          this->continuityLabel_ = x.continuityLabel_;
        }

        return *this;
      }

      Boundary::
      ~Boundary ()
      {
      }

      // Fill
      //

      Fill::
      Fill (const BaseType& base,
            const InitialPickType& initialPick,
            const InternalPicksType& internalPicks,
            const SeerShapeType& seerShape,
            const WireIdType& wireId,
            const FaceIdType& faceId)
      : ::xml_schema::Type (),
        base_ (base, this),
        initialPick_ (initialPick, this),
        internalPicks_ (internalPicks, this),
        boundaries_ (this),
        seerShape_ (seerShape, this),
        wireId_ (wireId, this),
        faceId_ (faceId, this)
      {
      }

      Fill::
      Fill (::std::unique_ptr< BaseType > base,
            ::std::unique_ptr< InitialPickType > initialPick,
            ::std::unique_ptr< InternalPicksType > internalPicks,
            ::std::unique_ptr< SeerShapeType > seerShape,
            const WireIdType& wireId,
            const FaceIdType& faceId)
      : ::xml_schema::Type (),
        base_ (std::move (base), this),
        initialPick_ (std::move (initialPick), this),
        internalPicks_ (std::move (internalPicks), this),
        boundaries_ (this),
        seerShape_ (std::move (seerShape), this),
        wireId_ (wireId, this),
        faceId_ (faceId, this)
      {
      }

      Fill::
      Fill (const Fill& x,
            ::xml_schema::Flags f,
            ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        base_ (x.base_, f, this),
        initialPick_ (x.initialPick_, f, this),
        internalPicks_ (x.internalPicks_, f, this),
        boundaries_ (x.boundaries_, f, this),
        seerShape_ (x.seerShape_, f, this),
        wireId_ (x.wireId_, f, this),
        faceId_ (x.faceId_, f, this)
      {
      }

      Fill::
      Fill (const ::xercesc::DOMElement& e,
            ::xml_schema::Flags f,
            ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        base_ (this),
        initialPick_ (this),
        internalPicks_ (this),
        boundaries_ (this),
        seerShape_ (this),
        wireId_ (this),
        faceId_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void Fill::
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

          // initialPick
          //
          if (n.name () == "initialPick" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< InitialPickType > r (
              InitialPickTraits::create (i, f, this));

            if (!initialPick_.present ())
            {
              this->initialPick_.set (::std::move (r));
              continue;
            }
          }

          // internalPicks
          //
          if (n.name () == "internalPicks" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< InternalPicksType > r (
              InternalPicksTraits::create (i, f, this));

            if (!internalPicks_.present ())
            {
              this->internalPicks_.set (::std::move (r));
              continue;
            }
          }

          // boundaries
          //
          if (n.name () == "boundaries" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< BoundariesType > r (
              BoundariesTraits::create (i, f, this));

            this->boundaries_.push_back (::std::move (r));
            continue;
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

          // wireId
          //
          if (n.name () == "wireId" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< WireIdType > r (
              WireIdTraits::create (i, f, this));

            if (!wireId_.present ())
            {
              this->wireId_.set (::std::move (r));
              continue;
            }
          }

          // faceId
          //
          if (n.name () == "faceId" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< FaceIdType > r (
              FaceIdTraits::create (i, f, this));

            if (!faceId_.present ())
            {
              this->faceId_.set (::std::move (r));
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

        if (!initialPick_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "initialPick",
            "");
        }

        if (!internalPicks_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "internalPicks",
            "");
        }

        if (!seerShape_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "seerShape",
            "");
        }

        if (!wireId_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "wireId",
            "");
        }

        if (!faceId_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "faceId",
            "");
        }
      }

      Fill* Fill::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class Fill (*this, f, c);
      }

      Fill& Fill::
      operator= (const Fill& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->base_ = x.base_;
          this->initialPick_ = x.initialPick_;
          this->internalPicks_ = x.internalPicks_;
          this->boundaries_ = x.boundaries_;
          this->seerShape_ = x.seerShape_;
          this->wireId_ = x.wireId_;
          this->faceId_ = x.faceId_;
        }

        return *this;
      }

      Fill::
      ~Fill ()
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
    namespace fls
    {
      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::fls::Fill > (
          ::prj::srl::fls::fill (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (const ::std::string& u,
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

        return ::std::unique_ptr< ::prj::srl::fls::Fill > (
          ::prj::srl::fls::fill (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (const ::std::string& u,
            ::xercesc::DOMErrorHandler& h,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            u, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::fls::Fill > (
          ::prj::srl::fls::fill (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::std::istream& is,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::fls::fill (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::std::istream& is,
            ::xml_schema::ErrorHandler& h,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::fls::fill (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::std::istream& is,
            ::xercesc::DOMErrorHandler& h,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is);
        return ::prj::srl::fls::fill (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::std::istream& is,
            const ::std::string& sid,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::fls::fill (isrc, f, p);
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::std::istream& is,
            const ::std::string& sid,
            ::xml_schema::ErrorHandler& h,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0,
          (f & ::xml_schema::Flags::keep_dom) == 0);

        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::fls::fill (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::std::istream& is,
            const ::std::string& sid,
            ::xercesc::DOMErrorHandler& h,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
        return ::prj::srl::fls::fill (isrc, h, f, p);
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::xercesc::InputSource& i,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xsd::cxx::tree::error_handler< char > h;

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

        return ::std::unique_ptr< ::prj::srl::fls::Fill > (
          ::prj::srl::fls::fill (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::xercesc::InputSource& i,
            ::xml_schema::ErrorHandler& h,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::fls::Fill > (
          ::prj::srl::fls::fill (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::xercesc::InputSource& i,
            ::xercesc::DOMErrorHandler& h,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::parse< char > (
            i, h, p, f));

        if (!d.get ())
          throw ::xsd::cxx::tree::parsing< char > ();

        return ::std::unique_ptr< ::prj::srl::fls::Fill > (
          ::prj::srl::fls::fill (
            std::move (d), f | ::xml_schema::Flags::own_dom, p));
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (const ::xercesc::DOMDocument& doc,
            ::xml_schema::Flags f,
            const ::xml_schema::Properties& p)
      {
        if (f & ::xml_schema::Flags::keep_dom)
        {
          ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
            static_cast< ::xercesc::DOMDocument* > (doc.cloneNode (true)));

          return ::std::unique_ptr< ::prj::srl::fls::Fill > (
            ::prj::srl::fls::fill (
              std::move (d), f | ::xml_schema::Flags::own_dom, p));
        }

        const ::xercesc::DOMElement& e (*doc.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "fill" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/fls")
        {
          ::std::unique_ptr< ::prj::srl::fls::Fill > r (
            ::xsd::cxx::tree::traits< ::prj::srl::fls::Fill, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "fill",
          "http://www.cadseer.com/prj/srl/fls");
      }

      ::std::unique_ptr< ::prj::srl::fls::Fill >
      fill (::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d,
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

        if (n.name () == "fill" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/fls")
        {
          ::std::unique_ptr< ::prj::srl::fls::Fill > r (
            ::xsd::cxx::tree::traits< ::prj::srl::fls::Fill, char >::create (
              e, f, 0));
          return r;
        }

        throw ::xsd::cxx::tree::unexpected_element < char > (
          n.name (),
          n.namespace_ (),
          "fill",
          "http://www.cadseer.com/prj/srl/fls");
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
    namespace fls
    {
      void
      operator<< (::xercesc::DOMElement& e, const Boundary& i)
      {
        e << static_cast< const ::xml_schema::Type& > (i);

        // edgePick
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "edgePick",
              e));

          s << i.edgePick ();
        }

        // facePick
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "facePick",
              e));

          s << i.facePick ();
        }

        // continuity
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "continuity",
              e));

          s << i.continuity ();
        }

        // continuityLabel
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "continuityLabel",
              e));

          s << i.continuityLabel ();
        }
      }

      void
      operator<< (::xercesc::DOMElement& e, const Fill& i)
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

        // initialPick
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "initialPick",
              e));

          s << i.initialPick ();
        }

        // internalPicks
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "internalPicks",
              e));

          s << i.internalPicks ();
        }

        // boundaries
        //
        for (Fill::BoundariesConstIterator
             b (i.boundaries ().begin ()), n (i.boundaries ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "boundaries",
              e));

          s << *b;
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

        // wireId
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "wireId",
              e));

          s << i.wireId ();
        }

        // faceId
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "faceId",
              e));

          s << i.faceId ();
        }
      }

      void
      fill (::std::ostream& o,
            const ::prj::srl::fls::Fill& s,
            const ::xml_schema::NamespaceInfomap& m,
            const ::std::string& e,
            ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::fls::fill (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      fill (::std::ostream& o,
            const ::prj::srl::fls::Fill& s,
            ::xml_schema::ErrorHandler& h,
            const ::xml_schema::NamespaceInfomap& m,
            const ::std::string& e,
            ::xml_schema::Flags f)
      {
        ::xsd::cxx::xml::auto_initializer i (
          (f & ::xml_schema::Flags::dont_initialize) == 0);

        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::fls::fill (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      fill (::std::ostream& o,
            const ::prj::srl::fls::Fill& s,
            ::xercesc::DOMErrorHandler& h,
            const ::xml_schema::NamespaceInfomap& m,
            const ::std::string& e,
            ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::fls::fill (s, m, f));
        ::xsd::cxx::xml::dom::ostream_format_target t (o);
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      fill (::xercesc::XMLFormatTarget& t,
            const ::prj::srl::fls::Fill& s,
            const ::xml_schema::NamespaceInfomap& m,
            const ::std::string& e,
            ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::fls::fill (s, m, f));

        ::xsd::cxx::tree::error_handler< char > h;

        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
        }
      }

      void
      fill (::xercesc::XMLFormatTarget& t,
            const ::prj::srl::fls::Fill& s,
            ::xml_schema::ErrorHandler& h,
            const ::xml_schema::NamespaceInfomap& m,
            const ::std::string& e,
            ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::fls::fill (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      fill (::xercesc::XMLFormatTarget& t,
            const ::prj::srl::fls::Fill& s,
            ::xercesc::DOMErrorHandler& h,
            const ::xml_schema::NamespaceInfomap& m,
            const ::std::string& e,
            ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::prj::srl::fls::fill (s, m, f));
        if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
        {
          throw ::xsd::cxx::tree::serialization< char > ();
        }
      }

      void
      fill (::xercesc::DOMDocument& d,
            const ::prj::srl::fls::Fill& s,
            ::xml_schema::Flags)
      {
        ::xercesc::DOMElement& e (*d.getDocumentElement ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (e));

        if (n.name () == "fill" &&
            n.namespace_ () == "http://www.cadseer.com/prj/srl/fls")
        {
          e << s;
        }
        else
        {
          throw ::xsd::cxx::tree::unexpected_element < char > (
            n.name (),
            n.namespace_ (),
            "fill",
            "http://www.cadseer.com/prj/srl/fls");
        }
      }

      ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument >
      fill (const ::prj::srl::fls::Fill& s,
            const ::xml_schema::NamespaceInfomap& m,
            ::xml_schema::Flags f)
      {
        ::xml_schema::dom::unique_ptr< ::xercesc::DOMDocument > d (
          ::xsd::cxx::xml::dom::serialize< char > (
            "fill",
            "http://www.cadseer.com/prj/srl/fls",
            m, f));

        ::prj::srl::fls::fill (*d, s, f);
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

