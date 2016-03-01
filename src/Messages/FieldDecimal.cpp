// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#include <quickfast/Common/QuickFASTPch.h>
#include <quickfast/Messages/FieldDecimal.h>
#include <quickfast/Common/Exceptions.h>

using namespace ::QuickFAST;
using namespace ::QuickFAST::Messages;

FieldDecimal::FieldDecimal()
  : Field(ValueType::DECIMAL, false)
{
}

FieldDecimal::FieldDecimal(const Decimal & value)
  : Field(ValueType::DECIMAL, true)
{
  signedInteger_ = value.getMantissa();
  exponent_ = value.getExponent();
}

FieldDecimal::FieldDecimal(mantissa_t mantissa, exponent_t exponent)
  : Field(ValueType::DECIMAL, true)
{
  signedInteger_ = mantissa;
  exponent_ = exponent;
}

FieldDecimal::~FieldDecimal()
{
}

const Decimal
FieldDecimal::toDecimal() const
{
  if(!valid_)
  {
    FieldNotPresent ex("Field not present");
  }
  return Decimal(signedInteger_, exponent_);
}

FieldCPtr
FieldDecimal::create(const Decimal & value)
{
  return new FieldDecimal(value);
}

FieldCPtr
FieldDecimal::create(mantissa_t mantissa, exponent_t exponent)
{
  return new FieldDecimal(mantissa, exponent);
}

FieldCPtr
FieldDecimal::createNull()
{
  return new FieldDecimal;
}

void
FieldDecimal::valueToStringBuffer() const
{
  std::stringstream buffer;
  buffer << signedInteger_ << "E" << exponent_;
  string_.assign(reinterpret_cast<const char *>(buffer.str().data()), buffer.str().size());
}
