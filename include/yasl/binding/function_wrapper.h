// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_FUNCTION_WRAPPER_H
#define YASL_BINDING_FUNCTION_WRAPPER_H

#include "yasl/binding/values.h"

#include <script/interpreter/executioncontext.h>

namespace binding
{

/****************************************************************
Non-void functions
****************************************************************/

template<typename FuncType, FuncType f>
struct function_wrapper_t
{
  static script::Value wrap(script::FunctionCall *c) = delete;
};


template<typename R, R(*f)()>
struct function_wrapper_t<R(*)(), f> {
  static script::Value wrap(script::FunctionCall *c) {
    return make_value<R>(f(), c->engine());
  }
};

template<typename R, typename Arg, R(*f)(Arg)>
struct function_wrapper_t<R(*)(Arg), f> {
  static script::Value wrap(script::FunctionCall *c) {
    return make_value<R>(f(value_cast<Arg>(c->arg(0))), c->engine());
  }
};

template<typename R, typename A1, typename A2, R(*f)(A1, A2)>
struct function_wrapper_t<R(*)(A1, A2), f> {
  static script::Value wrap(script::FunctionCall *c) {
    return make_value<R>(f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1))), c->engine());
  }
};

template<typename R, typename A1, typename A2, typename A3, R(*f)(A1, A2, A3)>
struct function_wrapper_t<R(*)(A1, A2, A3), f> {
  static script::Value wrap(script::FunctionCall *c) {
    return make_value<R>(f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2))), c->engine());
  }
};

template<typename R, typename A1, typename A2, typename A3, typename A4, R(*f)(A1, A2, A3, A4)>
struct function_wrapper_t<R(*)(A1, A2, A3, A4), f> {
  static script::Value wrap(script::FunctionCall *c) {
    return make_value<R>(f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)), value_cast<A4>(c->arg(3))), c->engine());
  }
};

template<typename R, typename A1, typename A2, typename A3, typename A4, typename A5, R(*f)(A1, A2, A3, A4, A5)>
struct function_wrapper_t<R(*)(A1, A2, A3, A4, A5), f> {
  static script::Value wrap(script::FunctionCall *c) {
    return make_value<R>(f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)), value_cast<A4>(c->arg(3)), value_cast<A5>(c->arg(4))), c->engine());
  }
};

template<typename R, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, R(*f)(A1, A2, A3, A4, A5, A6)>
struct function_wrapper_t<R(*)(A1, A2, A3, A4, A5, A6), f> {
  static script::Value wrap(script::FunctionCall *c) {
    return make_value<R>(f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)), value_cast<A4>(c->arg(3)), value_cast<A5>(c->arg(4)), value_cast<A6>(c->arg(5))), c->engine());
  }
};


/****************************************************************
Function returning void
****************************************************************/

template<typename FuncType, FuncType f>
struct void_function_wrapper_t;

template<void(*f)()>
struct void_function_wrapper_t<void(*)(), f> {
  static script::Value wrap(script::FunctionCall *c) {
    f();
    return script::Value::Void;
  }
};

template<typename Arg, void(*f)(Arg)>
struct void_function_wrapper_t<void(*)(Arg), f> {
  static script::Value wrap(script::FunctionCall *c) {
    f(value_cast<Arg>(c->arg(0)));
    return script::Value::Void;
  }
};

template<typename A1, typename A2, void(*f)(A1, A2)>
struct void_function_wrapper_t<void(*)(A1, A2), f> {
  static script::Value wrap(script::FunctionCall *c) {
    f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)));
    return script::Value::Void;
  }
};

template<typename A1, typename A2, typename A3, void(*f)(A1, A2, A3)>
struct void_function_wrapper_t<void(*)(A1, A2, A3), f> {
  static script::Value wrap(script::FunctionCall *c) {
    f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)));
    return script::Value::Void;
  }
};

template<typename A1, typename A2, typename A3, typename A4, void(*f)(A1, A2, A3, A4)>
struct void_function_wrapper_t<void(*)(A1, A2, A3, A4), f> {
  static script::Value wrap(script::FunctionCall *c) {
    f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)), value_cast<A4>(c->arg(3)));
    return script::Value::Void;
  }
};

template<typename A1, typename A2, typename A3, typename A4, typename A5, void(*f)(A1, A2, A3, A4, A5)>
struct void_function_wrapper_t<void(*)(A1, A2, A3, A4, A5), f> {
  static script::Value wrap(script::FunctionCall *c) {
    f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)), value_cast<A4>(c->arg(3)), value_cast<A5>(c->arg(4)));
    return script::Value::Void;
  }
};

template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, void(*f)(A1, A2, A3, A4, A5, A6)>
struct void_function_wrapper_t<void(*)(A1, A2, A3, A4, A5, A6), f> {
  static script::Value wrap(script::FunctionCall *c) {
    f(value_cast<A1>(c->arg(0)), value_cast<A2>(c->arg(1)), value_cast<A3>(c->arg(2)), value_cast<A4>(c->arg(3)), value_cast<A5>(c->arg(4)), value_cast<A6>(c->arg(5)));
    return script::Value::Void;
  }
};

} // namespace binding

#endif // YASL_BINDING_FUNCTION_WRAPPER_H
