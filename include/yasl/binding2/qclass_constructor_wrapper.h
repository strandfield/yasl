// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QCLASS_CONSTRUCTOR_WRAPPER_H
#define YASL_BINDING_QCLASS_CONSTRUCTOR_WRAPPER_H

#include "yasl/binding/values.h"

#include <script/interpreter/executioncontext.h>

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
    c->engine()->bind(self, obj);
    return self;
  }
};

template<typename T, typename A1>
struct qclass_constructor_wrapper_t<T, A1> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)));
    c->engine()->bind(self, obj);
    return self;
  }
};

template<typename T, typename A1, typename A2>
struct qclass_constructor_wrapper_t<T, A1, A2> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    c->engine()->bind(self, obj);
    return self;
  }
};

template<typename T, typename A1, typename A2, typename A3>
struct qclass_constructor_wrapper_t<T, A1, A2, A3> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    c->engine()->bind(self, obj);
    return self;
  }
};

template<typename T, typename A1, typename A2, typename A3, typename A4>
struct qclass_constructor_wrapper_t<T, A1, A2, A3, A4> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    c->engine()->bind(self, obj);
    return self;
  }
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
struct qclass_constructor_wrapper_t<T, A1, A2, A3, A4, A5> {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    c->engine()->bind(self, obj);
    return self;
  }
};

} // namespace binding

#endif // YASL_BINDING_QCLASS_CONSTRUCTOR_WRAPPER_H
