// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING2_CHAINABLE_MEMFN_H
#define YASL_BINDING2_CHAINABLE_MEMFN_H

#include "yasl/binding2/values.h"

#include "yasl/binding2/chainable_member_wrapper.h"

#include <script/class.h>
#include <script/functionbuilder.h>

namespace script
{

namespace bind
{

/* Chainable member functions; i.e. function returning a reference to 'this' */

template<typename T, typename A1, T&(T::*F)(A1)>
script::FunctionBuilder chainable_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), chainable_member_wrapper_t<decltype(F), F>::wrap)
    .returns(script::Type::ref(make_type<T>()))
    .params(make_type<A1>());
}

template<typename T, typename A1, typename A2, T&(T::*F)(A1, A2)>
script::FunctionBuilder chainable_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), chainable_member_wrapper_t<decltype(F), F>::wrap)
    .returns(script::Type::ref(make_type<T>()))
    .params(make_type<A1>(), make_type<A2>());
}

template<typename T, typename A1, typename A2, typename A3, T&(T::*F)(A1, A2, A3)>
script::FunctionBuilder chainable_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), chainable_member_wrapper_t<decltype(F), F>::wrap)
    .returns(script::Type::ref(make_type<T>()))
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, T&(T::*F)(A1, A2, A3, A4)>
script::FunctionBuilder chainable_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), chainable_member_wrapper_t<decltype(F), F>::wrap)
    .returns(script::Type::ref(make_type<T>()))
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, T&(T::*F)(A1, A2, A3, A4, A5)>
script::FunctionBuilder chainable_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), chainable_member_wrapper_t<decltype(F), F>::wrap)
    .returns(script::Type::ref(make_type<T>()))
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
}

template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, T&(T::*F)(A1, A2, A3, A4, A5, A6)>
script::FunctionBuilder chainable_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), chainable_member_wrapper_t<decltype(F), F>::wrap)
    .returns(script::Type::ref(make_type<T>()))
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_CHAINABLE_MEMFN_H
