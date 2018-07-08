// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_NAMESPACE_H
#define YASL_BINDING_NAMESPACE_H

#include "yasl/binding/utils.h"
#include "yasl/binding/function_wrapper.h"

#include <script/functionbuilder.h>
#include <script/namespace.h>

namespace binding
{

class NamespaceOperator
{
public:
  script::Namespace namespace_;

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function add()
  {
    return namespace_.Operation(script::AdditionOperator, add_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function sub()
  {
    return namespace_.Operation(script::SubstractionOperator, sub_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function mul()
  {
    return namespace_.Operation(script::MultiplicationOperator, mul_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function div()
  {
    return namespace_.Operation(script::DivisionOperator, div_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename LHS, typename RHS>
  script::Function eq()
  {
    return namespace_.Operation(script::EqualOperator, eq_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename LHS, typename RHS>
  script::Function neq()
  {
    return namespace_.Operation(script::InequalOperator, neq_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename LHS, typename RHS>
  script::Function less()
  {
    return namespace_.Operation(script::LessOperator, less_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename LHS, typename RHS>
  script::Function leq()
  {
    return namespace_.Operation(script::LessEqualOperator, leq_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename LHS, typename RHS>
  script::Function greater()
  {
    return namespace_.Operation(script::GreaterOperator, greater_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }

  template<typename LHS, typename RHS>
  script::Function geq()
  {
    return namespace_.Operation(script::GreaterEqualOperator, geq_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
  }
};


class Namespace
{
public:
  script::Namespace namespace_;

  Namespace add_namespace(const std::string & name)
  {
    script::Namespace ns = namespace_.newNamespace(name);
    return Namespace{ ns };
  }

  NamespaceOperator operators() const { return NamespaceOperator{ namespace_ }; }

  template<typename ReturnType, ReturnType(*fun)()>
  script::Function add_fun(const std::string & name)
  {
    return namespace_.Function(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .create();
  }

  template<typename ReturnType, typename Arg, ReturnType(*fun)(Arg)>
  script::Function add_fun(const std::string & name)
  {
    return namespace_.Function(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<Arg>())
      .create();
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(A1, A2)>
  script::Function add_fun(const std::string & name)
  {
    return namespace_.Function(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
  }

  /****************************************************************
  Function returning void
  ****************************************************************/

  template<void(*fun)()>
  script::Function add_void_fun(const std::string & name)
  {
    return namespace_.Function(name, void_function_wrapper_t<decltype(fun), fun>::wrap)
      .create();
  }

  template<typename Arg, void(*fun)(Arg)>
  script::Function add_void_fun(const std::string & name)
  {
    return namespace_.Function(name, void_function_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<Arg>())
      .create();
  }

  template<typename A1, typename A2, void(*fun)(A1, A2)>
  script::Function add_void_fun(const std::string & name)
  {
    return namespace_.Function(name, void_function_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>())
      .create();
  }


};

} // namespace binding

#endif // YASL_BINDING_NAMESPACE_H
