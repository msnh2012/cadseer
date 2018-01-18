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

#include "instancemapper.h"

namespace prj
{
  namespace srl
  {
    // OutIds
    // 

    const OutIds::ArraySequence& OutIds::
    array () const
    {
      return this->array_;
    }

    OutIds::ArraySequence& OutIds::
    array ()
    {
      return this->array_;
    }

    void OutIds::
    array (const ArraySequence& s)
    {
      this->array_ = s;
    }


    // HistoryOut
    // 

    const HistoryOut::HistoryType& HistoryOut::
    history () const
    {
      return this->history_.get ();
    }

    HistoryOut::HistoryType& HistoryOut::
    history ()
    {
      return this->history_.get ();
    }

    void HistoryOut::
    history (const HistoryType& x)
    {
      this->history_.set (x);
    }

    void HistoryOut::
    history (::std::unique_ptr< HistoryType > x)
    {
      this->history_.set (std::move (x));
    }

    const HistoryOut::OutIdsType& HistoryOut::
    outIds () const
    {
      return this->outIds_.get ();
    }

    HistoryOut::OutIdsType& HistoryOut::
    outIds ()
    {
      return this->outIds_.get ();
    }

    void HistoryOut::
    outIds (const OutIdsType& x)
    {
      this->outIds_.set (x);
    }

    void HistoryOut::
    outIds (::std::unique_ptr< OutIdsType > x)
    {
      this->outIds_.set (std::move (x));
    }


    // HistoryOuts
    // 

    const HistoryOuts::ArraySequence& HistoryOuts::
    array () const
    {
      return this->array_;
    }

    HistoryOuts::ArraySequence& HistoryOuts::
    array ()
    {
      return this->array_;
    }

    void HistoryOuts::
    array (const ArraySequence& s)
    {
      this->array_ = s;
    }


    // InstanceData
    // 

    const InstanceData::HistoryOutsType& InstanceData::
    historyOuts () const
    {
      return this->historyOuts_.get ();
    }

    InstanceData::HistoryOutsType& InstanceData::
    historyOuts ()
    {
      return this->historyOuts_.get ();
    }

    void InstanceData::
    historyOuts (const HistoryOutsType& x)
    {
      this->historyOuts_.set (x);
    }

    void InstanceData::
    historyOuts (::std::unique_ptr< HistoryOutsType > x)
    {
      this->historyOuts_.set (std::move (x));
    }
  }
}

#include <xsd/cxx/xml/dom/parsing-source.hxx>

namespace prj
{
  namespace srl
  {
    // OutIds
    //

    OutIds::
    OutIds ()
    : ::xml_schema::Type (),
      array_ (this)
    {
    }

    OutIds::
    OutIds (const OutIds& x,
            ::xml_schema::Flags f,
            ::xml_schema::Container* c)
    : ::xml_schema::Type (x, f, c),
      array_ (x.array_, f, this)
    {
    }

    OutIds::
    OutIds (const ::xercesc::DOMElement& e,
            ::xml_schema::Flags f,
            ::xml_schema::Container* c)
    : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
      array_ (this)
    {
      if ((f & ::xml_schema::Flags::base) == 0)
      {
        ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
        this->parse (p, f);
      }
    }

    void OutIds::
    parse (::xsd::cxx::xml::dom::parser< char >& p,
           ::xml_schema::Flags f)
    {
      for (; p.more_content (); p.next_content (false))
      {
        const ::xercesc::DOMElement& i (p.cur_element ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (i));

        // array
        //
        if (n.name () == "array" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< ArrayType > r (
            ArrayTraits::create (i, f, this));

          this->array_.push_back (::std::move (r));
          continue;
        }

        break;
      }
    }

    OutIds* OutIds::
    _clone (::xml_schema::Flags f,
            ::xml_schema::Container* c) const
    {
      return new class OutIds (*this, f, c);
    }

    OutIds& OutIds::
    operator= (const OutIds& x)
    {
      if (this != &x)
      {
        static_cast< ::xml_schema::Type& > (*this) = x;
        this->array_ = x.array_;
      }

      return *this;
    }

    OutIds::
    ~OutIds ()
    {
    }

    // HistoryOut
    //

    HistoryOut::
    HistoryOut (const HistoryType& history,
                const OutIdsType& outIds)
    : ::xml_schema::Type (),
      history_ (history, this),
      outIds_ (outIds, this)
    {
    }

    HistoryOut::
    HistoryOut (::std::unique_ptr< HistoryType > history,
                ::std::unique_ptr< OutIdsType > outIds)
    : ::xml_schema::Type (),
      history_ (std::move (history), this),
      outIds_ (std::move (outIds), this)
    {
    }

    HistoryOut::
    HistoryOut (const HistoryOut& x,
                ::xml_schema::Flags f,
                ::xml_schema::Container* c)
    : ::xml_schema::Type (x, f, c),
      history_ (x.history_, f, this),
      outIds_ (x.outIds_, f, this)
    {
    }

    HistoryOut::
    HistoryOut (const ::xercesc::DOMElement& e,
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

    void HistoryOut::
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

          if (!outIds_.present ())
          {
            this->outIds_.set (::std::move (r));
            continue;
          }
        }

        break;
      }

      if (!history_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "history",
          "");
      }

      if (!outIds_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "outIds",
          "");
      }
    }

    HistoryOut* HistoryOut::
    _clone (::xml_schema::Flags f,
            ::xml_schema::Container* c) const
    {
      return new class HistoryOut (*this, f, c);
    }

    HistoryOut& HistoryOut::
    operator= (const HistoryOut& x)
    {
      if (this != &x)
      {
        static_cast< ::xml_schema::Type& > (*this) = x;
        this->history_ = x.history_;
        this->outIds_ = x.outIds_;
      }

      return *this;
    }

    HistoryOut::
    ~HistoryOut ()
    {
    }

    // HistoryOuts
    //

    HistoryOuts::
    HistoryOuts ()
    : ::xml_schema::Type (),
      array_ (this)
    {
    }

    HistoryOuts::
    HistoryOuts (const HistoryOuts& x,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
    : ::xml_schema::Type (x, f, c),
      array_ (x.array_, f, this)
    {
    }

    HistoryOuts::
    HistoryOuts (const ::xercesc::DOMElement& e,
                 ::xml_schema::Flags f,
                 ::xml_schema::Container* c)
    : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
      array_ (this)
    {
      if ((f & ::xml_schema::Flags::base) == 0)
      {
        ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
        this->parse (p, f);
      }
    }

    void HistoryOuts::
    parse (::xsd::cxx::xml::dom::parser< char >& p,
           ::xml_schema::Flags f)
    {
      for (; p.more_content (); p.next_content (false))
      {
        const ::xercesc::DOMElement& i (p.cur_element ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (i));

        // array
        //
        if (n.name () == "array" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< ArrayType > r (
            ArrayTraits::create (i, f, this));

          this->array_.push_back (::std::move (r));
          continue;
        }

        break;
      }
    }

    HistoryOuts* HistoryOuts::
    _clone (::xml_schema::Flags f,
            ::xml_schema::Container* c) const
    {
      return new class HistoryOuts (*this, f, c);
    }

    HistoryOuts& HistoryOuts::
    operator= (const HistoryOuts& x)
    {
      if (this != &x)
      {
        static_cast< ::xml_schema::Type& > (*this) = x;
        this->array_ = x.array_;
      }

      return *this;
    }

    HistoryOuts::
    ~HistoryOuts ()
    {
    }

    // InstanceData
    //

    InstanceData::
    InstanceData (const HistoryOutsType& historyOuts)
    : ::xml_schema::Type (),
      historyOuts_ (historyOuts, this)
    {
    }

    InstanceData::
    InstanceData (::std::unique_ptr< HistoryOutsType > historyOuts)
    : ::xml_schema::Type (),
      historyOuts_ (std::move (historyOuts), this)
    {
    }

    InstanceData::
    InstanceData (const InstanceData& x,
                  ::xml_schema::Flags f,
                  ::xml_schema::Container* c)
    : ::xml_schema::Type (x, f, c),
      historyOuts_ (x.historyOuts_, f, this)
    {
    }

    InstanceData::
    InstanceData (const ::xercesc::DOMElement& e,
                  ::xml_schema::Flags f,
                  ::xml_schema::Container* c)
    : ::xml_schema::Type (e, f | ::xml_schema::Flags::base, c),
      historyOuts_ (this)
    {
      if ((f & ::xml_schema::Flags::base) == 0)
      {
        ::xsd::cxx::xml::dom::parser< char > p (e, true, false, false);
        this->parse (p, f);
      }
    }

    void InstanceData::
    parse (::xsd::cxx::xml::dom::parser< char >& p,
           ::xml_schema::Flags f)
    {
      for (; p.more_content (); p.next_content (false))
      {
        const ::xercesc::DOMElement& i (p.cur_element ());
        const ::xsd::cxx::xml::qualified_name< char > n (
          ::xsd::cxx::xml::dom::name< char > (i));

        // historyOuts
        //
        if (n.name () == "historyOuts" && n.namespace_ ().empty ())
        {
          ::std::unique_ptr< HistoryOutsType > r (
            HistoryOutsTraits::create (i, f, this));

          if (!historyOuts_.present ())
          {
            this->historyOuts_.set (::std::move (r));
            continue;
          }
        }

        break;
      }

      if (!historyOuts_.present ())
      {
        throw ::xsd::cxx::tree::expected_element< char > (
          "historyOuts",
          "");
      }
    }

    InstanceData* InstanceData::
    _clone (::xml_schema::Flags f,
            ::xml_schema::Container* c) const
    {
      return new class InstanceData (*this, f, c);
    }

    InstanceData& InstanceData::
    operator= (const InstanceData& x)
    {
      if (this != &x)
      {
        static_cast< ::xml_schema::Type& > (*this) = x;
        this->historyOuts_ = x.historyOuts_;
      }

      return *this;
    }

    InstanceData::
    ~InstanceData ()
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
    operator<< (::xercesc::DOMElement& e, const OutIds& i)
    {
      e << static_cast< const ::xml_schema::Type& > (i);

      // array
      //
      for (OutIds::ArrayConstIterator
           b (i.array ().begin ()), n (i.array ().end ());
           b != n; ++b)
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "array",
            e));

        s << *b;
      }
    }

    void
    operator<< (::xercesc::DOMElement& e, const HistoryOut& i)
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
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "outIds",
            e));

        s << i.outIds ();
      }
    }

    void
    operator<< (::xercesc::DOMElement& e, const HistoryOuts& i)
    {
      e << static_cast< const ::xml_schema::Type& > (i);

      // array
      //
      for (HistoryOuts::ArrayConstIterator
           b (i.array ().begin ()), n (i.array ().end ());
           b != n; ++b)
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "array",
            e));

        s << *b;
      }
    }

    void
    operator<< (::xercesc::DOMElement& e, const InstanceData& i)
    {
      e << static_cast< const ::xml_schema::Type& > (i);

      // historyOuts
      //
      {
        ::xercesc::DOMElement& s (
          ::xsd::cxx::xml::dom::create_element (
            "historyOuts",
            e));

        s << i.historyOuts ();
      }
    }
  }
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

