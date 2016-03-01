// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#include <quickfast/Common/QuickFASTPch.h>
#include <quickfast/Messages/FieldIdentity.h>

#ifdef _MSC_VER
#pragma warning(disable:4355) // disable warning C4355: 'this' : used in base member initializer list
#endif
using namespace QuickFAST;
using namespace Messages;

static
std::string anonName(void * address)
{
  return boost::lexical_cast<std::string>(address);
}

void dummy(int)
{
	//std::cout << "callbackObject not set" << std::endl;
}

FieldIdentity::CallbackFunctionType * FieldIdentity::defaultObjectCallback = dummy;

FieldIdentity::FieldIdentity()
  : localName_(anonName(this))
  , refcount_(0)
  , objectCallback(defaultObjectCallback)
{
  qualifyName();
}

FieldIdentity::FieldIdentity(
  const std::string & name,
  const std::string & fieldNamespace /* = ""*/,
  const field_id_t & id /* = ""*/)
  : localName_(name)
  , fieldNamespace_(fieldNamespace)
  , id_(id)
  , int_id_(atoi(id.c_str()))
  , refcount_(0)
  , objectCallback(defaultObjectCallback)
{
  qualifyName();
}


FieldIdentity::~FieldIdentity()
{
}

void
FieldIdentity::freeFieldIdentity()const
{
  delete this;
}

void
FieldIdentity::display(std::ostream & output)const
{
  output << " name=\"" << localName_;
  if(!fieldNamespace_.empty())
  {
    output << "\" ns=\"" << fieldNamespace_;
  }
  if(!id_.empty())
  {
    output << "\" id=\"" << id_;
  }
  output << '"';
}
