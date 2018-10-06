// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_NEW_FUNCTION_H
#define YASL_BINDING_NEW_FUNCTION_H

#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction_wrapper.h"

namespace binding
{

class NewFunctionBinder
{
public:
  script::Namespace namespace_;

  NewFunctionBinder(Namespace ns)
    : namespace_(ns.namespace_)
  {

  }

  template<typename T>
  script::Function add(const std::string & name)
  {
    return namespace_.Function(name, binding::qclass_newfunction_wrapper_t<T>::wrap)
      .returns(make_type<T&>())
      .create();
  }

  template<typename T, typename A1>
  script::Function add(const std::string & name)
  {
    return namespace_.Function(name, binding::qclass_newfunction_wrapper_t<T, A1>::wrap)
      .returns(make_type<T&>())
      .params(make_type<A1>())
      .create();
  }

  template<typename T, typename A1, typename A2>
  script::Function add(const std::string & name)
  {
    return namespace_.Function(name, binding::qclass_newfunction_wrapper_t<T, A1, A2>::wrap)
      .returns(make_type<T&>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
  }

  template<typename T, typename A1, typename A2, typename A3>
  script::Function add(const std::string & name)
  {
    return namespace_.Function(name, binding::qclass_newfunction_wrapper_t<T, A1, A2, A3>::wrap)
      .returns(make_type<T&>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
  }

  template<typename T, typename A1, typename A2, typename A3, typename A4>
  script::Function add(const std::string & name)
  {
    return namespace_.Function(name, binding::qclass_newfunction_wrapper_t<T, A1, A2, A3, A4>::wrap)
      .returns(make_type<T&>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
  }

  template<typename T, typename A1, typename A2, typename A3, typename A4, typename A5>
  script::Function add(const std::string & name)
  {
    return namespace_.Function(name, binding::qclass_newfunction_wrapper_t<T, A1, A2, A3, A4, A5>::wrap)
      .returns(make_type<T&>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>())
      .create();
  }
};

inline NewFunctionBinder NewFunction(const Namespace & binder) { return NewFunctionBinder{ binder }; }

} // namespace binding

#endif // YASL_BINDING_NEW_FUNCTION_H
