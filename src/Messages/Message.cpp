// Copyright (c) 2009, Object Computing, Inc.
// All rights reserved.
// See the file license.txt for licensing information.
#include <quickfast/Common/QuickFASTPch.h>
#include <quickfast/Messages/Message.h>
#include <quickfast/Common/Exceptions.h>

using namespace ::QuickFAST;
using namespace ::QuickFAST::Messages;

Message::Message(size_t expectedNumberOfFields)
: FieldSet(expectedNumberOfFields)
{
  applicationType_ = "any";
}
