// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_DESTRUCTOR_BINDER_H
#define YASL_BINDING_DESTRUCTOR_BINDER_H

#include "yasl/common/values.h"

#include <script/interpreter/executioncontext.h>

namespace script
{

namespace bind
{

template<typename T, typename Tag>
struct destructor_binder;

template<typename T>
struct destructor_binder<T, details::small_object_tag>
{
  static script::Value destructor(script::FunctionCall *c) 
  {
    c->thisObject().destroy<T>();
    return script::Value::Void;
  }
};

template<typename T>
struct destructor_binder<T, details::large_object_tag>
{
  static script::Value destructor(script::FunctionCall *c)
  {
    c->thisObject().destroy<T>();
    return script::Value::Void;
  }
};

} // namespace bind

} // namespace script

#endif // YASL_BINDING_DESTRUCTOR_BINDER_H
