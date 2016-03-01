// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#include <quickfast/Common/QuickFASTPch.h>
#include <quickfast/Messages/FieldSequence.h>
#include <quickfast/Messages/Sequence.h>

using namespace ::QuickFAST;
using namespace ::QuickFAST::Messages;

FieldSequence::FieldSequence(Messages::SequenceCPtr sequence)
  : Field(ValueType::SEQUENCE, true)
  , sequence_(sequence)
{
}

FieldSequence::~FieldSequence()
{
}

uint32
FieldSequence::toUInt32()const
{
  return static_cast<uint32>(sequence_->size());
}

const Messages::SequenceCPtr &
FieldSequence::toSequence() const
{
  return sequence_;
}

FieldCPtr
FieldSequence::create(Messages::SequenceCPtr sequence)
{
  return new FieldSequence(sequence);
}

bool
FieldSequence::operator == (const Field & rhs) const
{
  if(getType() != rhs.getType())
  {
    return false;
  }
///@TODO  int todo_improve_comparison;
  return true;
}

void
FieldSequence::valueToStringBuffer() const
{
  static const char msg[] = "Sequence: ";
  string_.assign(msg, sizeof(msg)-1);
}


