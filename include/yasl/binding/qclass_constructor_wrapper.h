// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QCLASS_CONSTRUCTOR_WRAPPER_H
#define YASL_BINDING_QCLASS_CONSTRUCTOR_WRAPPER_H

#include "yasl/binding/values.h"

#include <script/interpreter/executioncontext.h>
#include <script/private/value_p.h>

namespace binding
{

/****************************************************************
Constructors
****************************************************************/

template<typename T, typename...Args>
struct qclass_constructor_wrapper_t;

template<typename T>
struct qclass_constructor_wrapper_t<T> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *obj = new T;
    self.impl()->set_qobject(obj);
    expose(obj, self);
    return self;
  }
};

template<typename T, typename A1>
struct qclass_constructor_wrapper_t<T, A1> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(0)));
    self.impl()->set_qobject(obj);
    expose(obj, self);
    return self;
  }
};

template<typename T, typename A1, typename A2>
struct qclass_constructor_wrapper_t<T, A1, A2> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)));
    self.impl()->set_qobject(obj);
    expose(obj, self);
    return self;
  }
};

} // namespace binding

#endif // YASL_BINDING_QCLASS_CONSTRUCTOR_WRAPPER_H
