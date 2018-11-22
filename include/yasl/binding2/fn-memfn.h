// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING2_FN_AS_MEMFN_H
#define YASL_BINDING2_FN_AS_MEMFN_H

#include "yasl/binding2/values.h"

#include "yasl/binding2/function_wrapper.h"

#include <script/class.h>
#include <script/functionbuilder.h>

namespace script
{

namespace bind
{

/* Non-void non-static non-const member functions */

template<typename T, typename R, R(*F)(T &)>
script::FunctionBuilder fn_as_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), function_wrapper_t<decltype(F), F>::wrap)
    .returns(make_type<R>());
}

template<typename T, typename R, typename A1, R(*F)(T &, A1)>
script::FunctionBuilder fn_as_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), function_wrapper_t<decltype(F), F>::wrap)
    .returns(make_type<R>())
    .params(make_type<A1>());
}


/* Non-void non-static const member functions */

template<typename T, typename R, R(*F)(const T &)>
script::FunctionBuilder fn_as_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), function_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .returns(make_type<R>());
}

template<typename T, typename R, typename A1, R(*F)(const T &, A1)>
script::FunctionBuilder fn_as_memfn(Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), function_wrapper_t<decltype(F), F>::wrap)
    .setConst()
    .returns(make_type<R>())
    .params(make_type<A1>());
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_FN_AS_MEMFN_H
