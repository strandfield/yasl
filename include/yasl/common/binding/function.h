// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_FUNCTION_H
#define YASL_BINDING_FUNCTION_H

#include "yasl/common/values.h"

#include "yasl/common/wrappers/function_wrapper.h"

#include <script/namespace.h>
#include <script/functionbuilder.h>

namespace script
{

namespace bind
{

/* Non-void functions */

template<typename R, R(*F)()>
script::FunctionBuilder function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::function_wrapper_t<decltype(F), F>::wrap)
    .returns(make_type<R>());
}

template<typename R, typename A1, R(*F)(A1)>
script::FunctionBuilder function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::function_wrapper_t<decltype(F), F>::wrap)
    .returns(make_type<R>())
    .params(make_type<A1>());
}

template<typename R, typename A1, typename A2, R(*F)(A1, A2)>
script::FunctionBuilder function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::function_wrapper_t<decltype(F), F>::wrap)
    .returns(make_type<R>())
    .params(make_type<A1>(), make_type<A2>());
}

template<typename R, typename A1, typename A2, typename A3, R(*F)(A1, A2, A3)>
script::FunctionBuilder function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::function_wrapper_t<decltype(F), F>::wrap)
    .returns(make_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename R, typename A1, typename A2, typename A3, typename A4, R(*F)(A1, A2, A3, A4)>
script::FunctionBuilder function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::function_wrapper_t<decltype(F), F>::wrap)
    .returns(make_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename R, typename A1, typename A2, typename A3, typename A4, typename A5, R(*F)(A1, A2, A3, A4, A5)>
script::FunctionBuilder function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::function_wrapper_t<decltype(F), F>::wrap)
    .returns(make_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}


/* void functions */

template<void(*F)()>
script::FunctionBuilder void_function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::void_function_wrapper_t<decltype(F), F>::wrap);
}

template<typename A1, void(*F)(A1)>
script::FunctionBuilder void_function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::void_function_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>());
}

template<typename A1, typename A2, void(*F)(A1, A2)>
script::FunctionBuilder void_function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::void_function_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>(), make_type<A2>());
}

template<typename A1, typename A2, typename A3, void(*F)(A1, A2, A3)>
script::FunctionBuilder void_function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::void_function_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename A1, typename A2, typename A3, typename A4, void(*F)(A1, A2, A3, A4)>
script::FunctionBuilder void_function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::void_function_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename A1, typename A2, typename A3, typename A4, typename A5, void(*F)(A1, A2, A3, A4, A5)>
script::FunctionBuilder void_function(script::Namespace & ns, std::string && name)
{
  return ns.newFunction(std::move(name), wrapper::void_function_wrapper_t<decltype(F), F>::wrap)
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING_FUNCTION_H
