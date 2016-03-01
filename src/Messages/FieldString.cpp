// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#include <quickfast/Common/QuickFASTPch.h>
#include <quickfast/Messages/FieldString.h>
#include <quickfast/Common/Exceptions.h>

using namespace ::QuickFAST;
using namespace ::QuickFAST::Messages;

FieldString::FieldString(const std::string & value)
  : Field(ValueType::ASCII, true)
{
  string_ = value;
}

FieldString::FieldString(const uchar * value, size_t length)
  : Field(ValueType::ASCII, true)
{
  string_.assign((const char*)value, length);
}

FieldString::FieldString()
  : Field(ValueType::ASCII, false)
{
}

FieldString::~FieldString()
{
}

bool
FieldString::isString() const
{
  return true;
}

const StringBuffer &
FieldString::toAscii() const
{
  return toString();
}

const StringBuffer &
FieldString::toUtf8() const
{
  return toString();
}

const StringBuffer &
FieldString::toByteVector() const
{
  return toString();
}

FieldCPtr
FieldString::create(const std::string & value)
{
  return new FieldString(value);
}

FieldCPtr
FieldString::create(const uchar * buffer, size_t length)
{
  return new FieldString(buffer, length);
}

FieldCPtr
FieldString::createNull()
{
  return new FieldString;
}

