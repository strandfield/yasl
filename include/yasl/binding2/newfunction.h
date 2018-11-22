// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING2_NEW_FUNCTION_H
#define YASL_BINDING2_NEW_FUNCTION_H

#include "yasl/binding/newfunction_wrapper.h"

#include <script/namespace.h>
#include <script/function.h>
#include <script/functionbuilder.h>

namespace script
{

namespace bind
{

template<typename T, typename... Args>
script::Function new_function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), qclass_newfunction_wrapper_t<T, Args...>::wrap)
    .returns(make_type<T&>())
    .params(make_type<Args>()...)
    .get();
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_NEW_FUNCTION_H
