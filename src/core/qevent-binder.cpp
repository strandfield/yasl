// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/qevent-binder.h"

namespace callbacks
{

script::Value qevent_dtor(script::FunctionCall *c)
{
  auto self = c->thisObject();
  if (self.impl()->data.ptr != nullptr)
  {
    delete static_cast<QEvent*>(self.impl()->data.ptr);
    self.impl()->data.ptr = nullptr;
  }

  return script::Value::Void;
}

} // namespace callbacks
