// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_NEW_FUNCTION_WRAPPER_H
#define YASL_BINDING_NEW_FUNCTION_WRAPPER_H

#include "yasl/binding/types.h"

#include <script/interpreter/executioncontext.h>
#include <script/value.h>

namespace script
{
namespace bind
{

template<typename T, typename...Args>
struct qclass_newfunction_wrapper_t;

template<typename T>
struct qclass_newfunction_wrapper_t<T> {
  static script::Value wrap(script::FunctionCall *c) {
    T *object = new T();
    return c->engine()->expose(object, make_type<T>());
  }
};

template<typename T, typename A1>
struct qclass_newfunction_wrapper_t<T, A1> {
  static script::Value wrap(script::FunctionCall *c) {
    T *object = new T(value_cast<A1>(c->arg(0)));
    return c->engine()->expose(object, make_type<T>());
  }
};

template<typename T, typename A1, typename A2>
struct qclass_newfunction_wrapper_t<T, A1, A2> {
  static script::Value wrap(script::FunctionCall *c) {
    T *object = new T(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)));
    return c->engine()->expose(object, make_type<T>());
  }
};

template<typename T, typename A1, typename A2, typename A3>
struct qclass_newfunction_wrapper_t<T, A1, A2, A3> {
  static script::Value wrap(script::FunctionCall *c) {
    T *object = new T(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)));
    return c->engine()->expose(object, make_type<T>());
  }
};

template<typename T, typename A1, typename A2, typename A3, typename A4>
struct qclass_newfunction_wrapper_t<T, A1, A2, A3, A4> {
  static script::Value wrap(script::FunctionCall *c) {
    T *object = new T(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)), value_cast<A4>(c->arg(3)));
    return c->engine()->expose(object, make_type<T>());
  }
};

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
struct qclass_newfunction_wrapper_t<T, A1, A2, A3, A4, A5> {
  static script::Value wrap(script::FunctionCall *c) {
    T *object = new T(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)), value_cast<A4>(c->arg(3)), value_cast<A5>(c->arg(4)));
    return c->engine()->expose(object, make_type<T>());
  }
};

} // namespace bind
} // namespace script

#endif // YASL_BINDING_NEW_FUNCTION_WRAPPER_H
