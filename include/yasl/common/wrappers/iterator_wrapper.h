// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WRAPPERS_ITERATOR_WRAPPER_H
#define YASL_WRAPPERS_ITERATOR_WRAPPER_H

#include "yasl/common/proxy.h"
#include "yasl/common/values.h"

#include <script/interpreter/executioncontext.h>

namespace script
{

namespace wrapper
{

template<typename T, typename Iter>
script::Value const_iter_deref_wrapper(script::FunctionCall *c)
{
  return make_value(*value_cast<Iter &>(c->arg(0)), c->engine());
}

template<typename T, typename Iter>
script::Value iter_deref_wrapper(script::FunctionCall *c)
{
  return c->engine()->newPtr(make_type<Proxy<T>>(), &(*value_cast<Iter &>(c->arg(0))));
}

} // namespace wrapper

} // namespace script

#endif // YASL_WRAPPERS_OPERATOR_WRAPPER_H
