// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_CONSTRUCTOR_BINDER_H
#define YASL_BINDING_CONSTRUCTOR_BINDER_H

#include "yasl/common/values.h"

#include <script/interpreter/executioncontext.h>

namespace script
{

namespace bind
{

template<typename T, typename Tag>
struct constructor_binder;


template<typename T>
struct constructor_binder<T, details::small_object_tag> 
{
  static script::Value default_ctor(script::FunctionCall *c) 
  {
    c->thisObject().init<T>();
    return c->arg(0);
  }

  static script::Value copy_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<const T&>(c->arg(1)));
    return c->arg(0);
  }

  template<typename A1>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)));
    return c->arg(0);
  }

  template<typename A1, typename A2>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    return c->arg(0);
  }

  template<typename A1, typename A2, typename A3>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    return c->arg(0);
  }

  template<typename A1, typename A2, typename A3, typename A4>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    return c->arg(0);
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    return c->arg(0);
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6)));
    return c->arg(0);
  }
};


template<typename T>
struct constructor_binder<T, details::large_object_tag>
{
  static script::Value default_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>();
    return c->arg(0);
  }

  static script::Value copy_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<const T &>(c->arg(1)));
    return c->arg(0);
  }

  template<typename A1>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)));
    return c->arg(0);
  }

  template<typename A1, typename A2>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    return c->arg(0);
  }

  template<typename A1, typename A2, typename A3>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    return c->arg(0);
  }

  template<typename A1, typename A2, typename A3, typename A4>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    return c->arg(0);
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    return c->arg(0);
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    c->thisObject().init<T>(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6)));
    return c->arg(0);
  }
};

} // namespace bind

} // namespace script

#endif // YASL_BINDING_CONSTRUCTOR_BINDER_H
