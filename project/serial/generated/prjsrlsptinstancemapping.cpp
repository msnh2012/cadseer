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

#include "prjsrlsptinstancemapping.h"

namespace prj
{
  namespace srl
  {
    namespace spt
    {
      // InstanceMap
      // 

      const InstanceMap::HistoryType& InstanceMap::
      history () const
      {
        return this->history_.get ();
      }

      InstanceMap::HistoryType& InstanceMap::
      history ()
      {
        return this->history_.get ();
      }

      void InstanceMap::
      history (const HistoryType& x)
      {
        this->history_.set (x);
      }

      void InstanceMap::
      history (::std::unique_ptr< HistoryType > x)
      {
        this->history_.set (std::move (x));
      }

      const InstanceMap::OutIdsSequence& InstanceMap::
      outIds () const
      {
        return this->outIds_;
      }

      InstanceMap::OutIdsSequence& InstanceMap::
      outIds ()
      {
        return this->outIds_;
      }

      void InstanceMap::
      outIds (const OutIdsSequence& s)
      {
        this->outIds_ = s;
      }


      // InstanceMaps
      // 

      const InstanceMaps::InstanceMapsSequence& InstanceMaps::
      instanceMaps () const
      {
        return this->instanceMaps_;
      }

      InstanceMaps::InstanceMapsSequence& InstanceMaps::
      instanceMaps ()
      {
        return this->instanceMaps_;
      }

      void InstanceMaps::
      instanceMaps (const InstanceMapsSequence& s)
      {
        this->instanceMaps_ = s;
      }
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    namespace spt
    {
      // InstanceMap
      //

      InstanceMap::
      InstanceMap (const HistoryType& history)
      : ::xml_schema::Type (),
        history_ (history, this),
        outIds_ (this)
      {
      }

      InstanceMap::
      InstanceMap (::std::unique_ptr< HistoryType > history)
      : ::xml_schema::Type (),
        history_ (std::move (history), this),
        outIds_ (this)
      {
      }

      InstanceMap::
      InstanceMap (const InstanceMap& x,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        history_ (x.history_, f, this),
        outIds_ (x.outIds_, f, this)
      {
      }

      InstanceMap::
      InstanceMap (const ::xercesc::DOMElement& e,
                   ::xml_schema::Flags f,
                   ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        history_ (this),
        outIds_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void InstanceMap::
      parse (::xsd::cxx::xml::dom::parser< char >& p,
             ::xml_schema::Flags f)
      {
        for (; p.more_content (); p.next_content (false))
        {
          const ::xercesc::DOMElement& i (p.cur_element ());
          const ::xsd::cxx::xml::qualified_name< char > n (
            ::xsd::cxx::xml::dom::name< char > (i));

          // history
          //
          if (n.name () == "history" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< HistoryType > r (
              HistoryTraits::create (i, f, this));

            if (!history_.present ())
            {
              this->history_.set (::std::move (r));
              continue;
            }
          }

          // outIds
          //
          if (n.name () == "outIds" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< OutIdsType > r (
              OutIdsTraits::create (i, f, this));

            this->outIds_.push_back (::std::move (r));
            continue;
          }

          break;
        }

        if (!history_.present ())
        {
          throw ::xsd::cxx::tree::expected_element< char > (
            "history",
            "");
        }
      }

      InstanceMap* InstanceMap::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class InstanceMap (*this, f, c);
      }

      InstanceMap& InstanceMap::
      operator= (const InstanceMap& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->history_ = x.history_;
          this->outIds_ = x.outIds_;
        }

        return *this;
      }

      InstanceMap::
      ~InstanceMap ()
      {
      }

      // InstanceMaps
      //

      InstanceMaps::
      InstanceMaps ()
      : ::xml_schema::Type (),
        instanceMaps_ (this)
      {
      }

      InstanceMaps::
      InstanceMaps (const InstanceMaps& x,
                    ::xml_schema::Flags f,
                    ::xml_schema::Container* c)
      : ::xml_schema::Type (x, f, c),
        instanceMaps_ (x.instanceMaps_, f, this)
      {
      }

      InstanceMaps::
      InstanceMaps (const ::xercesc::DOMElement& e,
                    ::xml_schema::Flags f,
                    ::xml_schema::Container* c)
      : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
        instanceMaps_ (this)
      {
        if ((f & ::xml_schema::Flags::base) == 0)
        {
          ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
          this->parse (p, f);
        }
      }

      void InstanceMaps::
      parse (::xsd::cxx::xml::dom::parser< char >& p,
             ::xml_schema::Flags f)
      {
        for (; p.more_content (); p.next_content (false))
        {
          const ::xercesc::DOMElement& i (p.cur_element ());
          const ::xsd::cxx::xml::qualified_name< char > n (
            ::xsd::cxx::xml::dom::name< char > (i));

          // instanceMaps
          //
          if (n.name () == "instanceMaps" && n.namespace_ ().empty ())
          {
            ::std::unique_ptr< InstanceMapsType > r (
              InstanceMapsTraits::create (i, f, this));

            this->instanceMaps_.push_back (::std::move (r));
            continue;
          }

          break;
        }
      }

      InstanceMaps* InstanceMaps::
      _clone (::xml_schema::Flags f,
              ::xml_schema::Container* c) const
      {
        return new class InstanceMaps (*this, f, c);
      }

      InstanceMaps& InstanceMaps::
      operator= (const InstanceMaps& x)
      {
        if (this != &x)
        {
          static_cast< ::xml_schema::Type& > (*this) = x;
          this->instanceMaps_ = x.instanceMaps_;
        }

        return *this;
      }

      InstanceMaps::
      ~InstanceMaps ()
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
    namespace spt
    {
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
    namespace spt
    {
      void
      operator<< (::xercesc::DOMElement& e, const InstanceMap& i)
      {
        e << static_cast< const ::xml_schema::Type& > (i);

        // history
        //
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "history",
              e));

          s << i.history ();
        }

        // outIds
        //
        for (InstanceMap::OutIdsConstIterator
             b (i.outIds ().begin ()), n (i.outIds ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "outIds",
              e));

          s << *b;
        }
      }

      void
      operator<< (::xercesc::DOMElement& e, const InstanceMaps& i)
      {
        e << static_cast< const ::xml_schema::Type& > (i);

        // instanceMaps
        //
        for (InstanceMaps::InstanceMapsConstIterator
             b (i.instanceMaps ().begin ()), n (i.instanceMaps ().end ());
             b != n; ++b)
        {
          ::xercesc::DOMElement& s (
            ::xsd::cxx::xml::dom::create_element (
              "instanceMaps",
              e));

          s << *b;
        }
      }
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

