// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QCLASS_DESTRUCTOR_WRAPPER_H
#define YASL_BINDING_QCLASS_DESTRUCTOR_WRAPPER_H

#include <script/interpreter/executioncontext.h>
#include <script/private/value_p.h>

namespace binding
{

/****************************************************************
Destructor
****************************************************************/

template<typename T>
struct qclass_destructor_wrapper_t {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *ref = qobject_cast<T*>(self.impl()->data.builtin.qobject);
    if(ref != nullptr)
      delete ref;
    self.impl()->data.builtin.qobject = nullptr;
    return script::Value::Void;
  }
};

} // namespace binding

#endif // YASL_BINDING_QCLASS_DESTRUCTOR_WRAPPER_H
