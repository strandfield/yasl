// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/binding/signals.h"

#include <script/engine.h>
#include <script/function.h>
#include <script/interpreter/executioncontext.h>
#include <script/value.h>

namespace script
{

namespace callbacks
{

script::Value signal_callback(script::FunctionCall *c)
{
  yasl::emitSignal(c->thisObject(), c->callee(), c->args().begin() + 1, c->args().end());
  return script::Value::Void;
}

} // namespace callbacks

} // namespace script

