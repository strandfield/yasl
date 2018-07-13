// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_NAMESPACE_H
#define YASL_BINDING_NAMESPACE_H

#include "yasl/binding/function_wrapper.h"

#include <script/functionbuilder.h>
#include <script/namespace.h>

#if !defined(YASL_BINDING_COMPILE_TIME_CHECK)
#define YASL_BINDING_BEGIN_RUNTIME_CHECK try {
#define YASL_BINDING_END_RUNTIME_CHECK } catch(UnknownTypeException &) { return script::Function{}; }
#else
#define YASL_BINDING_BEGIN_RUNTIME_CHECK 
#define YASL_BINDING_END_RUNTIME_CHECK
#endif // !defined(YASL_BINDING_COMPILE_TIME_CHECK)

namespace binding
{

class NamespaceOperator
{
public:
  script::Namespace namespace_;

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::AdditionOperator, add_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function sub()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::SubstractionOperator, sub_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function mul()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::MultiplicationOperator, mul_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function div()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::DivisionOperator, div_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename LHS, typename RHS>
  script::Function eq()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::EqualOperator, eq_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename LHS, typename RHS>
  script::Function neq()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::InequalOperator, neq_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename LHS, typename RHS>
  script::Function less()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::LessOperator, less_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename LHS, typename RHS>
  script::Function leq()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::LessEqualOperator, leq_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename LHS, typename RHS>
  script::Function greater()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::GreaterOperator, greater_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename LHS, typename RHS>
  script::Function geq()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Operation(script::GreaterEqualOperator, geq_wrapper<LHS, RHS>)
      .returns(script::Type::Boolean)
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function left_shift()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return namespace_.Operation(script::LeftShiftOperator, left_shift_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function right_shift()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return namespace_.Operation(script::RightShiftOperator, right_shift_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function or()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return namespace_.Operation(script::BitwiseOrOperator, or_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename LHS, typename RHS>
  script::Function and()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return namespace_.Operation(script::BitwiseAndOperator, and_wrapper<LHS, RHS>)
      .returns(make_return_type<ReturnType>())
      .params(make_type<LHS>(), make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
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
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Function(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename Arg, ReturnType(*fun)(Arg)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Function(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<Arg>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(A1, A2)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Function(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  Function returning void
  ****************************************************************/

  template<void(*fun)()>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Function(name, void_function_wrapper_t<decltype(fun), fun>::wrap)
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename Arg, void(*fun)(Arg)>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Function(name, void_function_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<Arg>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, void(*fun)(A1, A2)>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return namespace_.Function(name, void_function_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }


};

} // namespace binding

#undef YASL_BINDING_BEGIN_RUNTIME_CHECK 
#undef YASL_BINDING_END_RUNTIME_CHECK

#endif // YASL_BINDING_NAMESPACE_H
