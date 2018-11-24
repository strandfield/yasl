// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_STATICMEMFUN_H
#define YASL_BINDING_STATICMEMFUN_H

#include "yasl/common/wrappers/function_wrapper.h"

#include <script/namespace.h>
#include <script/functionbuilder.h>

namespace script
{

namespace bind
{

/* Non-void static member functions */

template<typename T, typename R, R(*F)(), typename FT = decltype(F)>
script::FunctionBuilder static_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .returns(make_return_type<R>());
}

template<typename T, typename R, typename A1, R(*F)(A1), typename FT = decltype(F)>
script::FunctionBuilder static_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .returns(make_return_type<R>())
    .params(make_type<A1>());
}

template<typename T, typename R, typename A1, typename A2, R(*F)(A1, A2), typename FT = decltype(F)>
script::FunctionBuilder static_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, R(*F)(A1, A2, A3), typename FT = decltype(F)>
script::FunctionBuilder static_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, typename A4, R(*F)(A1, A2, A3, A4), typename FT = decltype(F)>
script::FunctionBuilder static_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, typename A4, typename A5, R(*F)(A1, A2, A3, A4, A5), typename FT = decltype(F)>
script::FunctionBuilder static_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}

template<typename T, typename R, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, R(*F)(A1, A2, A3, A4, A5, A6), typename FT = decltype(F)>
script::FunctionBuilder static_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .returns(make_return_type<R>())
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
}


/* void functions */

template<typename T, void(*F)(), typename FT = decltype(F)>
script::FunctionBuilder static_void_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::void_function_wrapper_t<FT, F>::wrap)
    .setStatic();
}

template<typename T, typename A1, void(*F)(A1), typename FT = decltype(F)>
script::FunctionBuilder static_void_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::void_function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .params(make_type<A1>());
}

template<typename T, typename A1, typename A2, void(*F)(A1, A2), typename FT = decltype(F)>
script::FunctionBuilder static_void_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::void_function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .params(make_type<A1>(), make_type<A2>());
}

template<typename T, typename A1, typename A2, typename A3, void(*F)(A1, A2, A3), typename FT = decltype(F)>
script::FunctionBuilder static_void_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::void_function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, void(*F)(A1, A2, A3, A4), typename FT = decltype(F)>
script::FunctionBuilder static_void_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::void_function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, void(*F)(A1, A2, A3, A4, A5), typename FT = decltype(F)>
script::FunctionBuilder static_void_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::void_function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, void(*F)(A1, A2, A3, A4, A5, A6), typename FT = decltype(F)>
script::FunctionBuilder static_void_member_function(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::void_function_wrapper_t<FT, F>::wrap)
    .setStatic()
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING_STATICMEMFUN_H
