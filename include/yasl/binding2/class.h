// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_CLASS_H
#define YASL_BINDING_CLASS_H

#include "yasl/binding/constructor_wrapper.h"
#include "yasl/binding/destructor_wrapper.h"
#include "yasl/binding/function_wrapper.h"
#include "yasl/binding/member_wrapper.h"
#include "yasl/binding/operator_wrapper.h"
#include "yasl/binding/reference_member_wrapper.h"

#include <script/class.h>
#include <script/constructorbuilder.h>
#include <script/destructorbuilder.h>
#include <script/functionbuilder.h>
#include <script/operator.h>
#include <script/operatorbuilder.h>

namespace binding
{

/// TODO: move to dedicated file
template<typename T>
class ClassOperator
{
public:
  script::Class class_;

  template<typename ReturnType, typename RHS>
  script::Function add()
  {
    return class_.newOperator(script::AdditionOperator, add_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename ReturnType, typename RHS>
  script::Function sub()
  {
    return class_.newOperator(script::SubstractionOperator, sub_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename ReturnType, typename RHS>
  script::Function mul()
  {
    return class_.newOperator(script::MultiplicationOperator, mul_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename ReturnType, typename RHS>
  script::Function div()
  {
    return class_.newOperator(script::DivisionOperator, div_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function assign()
  {
    return class_.newOperator(script::AssignmentOperator, assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function add_assign()
  {
    return class_.newOperator(script::AdditionAssignmentOperator, add_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function sub_assign()
  {
    return class_.newOperator(script::AdditionAssignmentOperator, sub_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function mul_assign()
  {
    return class_.newOperator(script::MultiplicationAssignmentOperator, mul_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function div_assign()
  {
    return class_.newOperator(script::DivisionAssignmentOperator, div_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function eq()
  {
    return class_.newOperator(script::EqualOperator, eq_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function neq()
  {
    return class_.newOperator(script::InequalOperator, neq_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function less()
  {
    return class_.newOperator(script::LessOperator, less_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function leq()
  {
    return class_.newOperator(script::LessEqualOperator, leq_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function greater()
  {
    return class_.newOperator(script::GreaterOperator, greater_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function geq()
  {
    return class_.newOperator(script::GreaterEqualOperator, geq_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .get();
  }

  template<typename ReturnType, typename RHS>
  script::Function and ()
  {
    return class_.newOperator(script::BitwiseAndOperator, and_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename ReturnType, typename RHS>
  script::Function or ()
  {
    return class_.newOperator(script::BitwiseOrOperator, or_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename ReturnType, typename RHS>
  script::Function xor ()
  {
    return class_.newOperator(script::BitwiseXorOperator, xor_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function and_assign()
  {
    return class_.newOperator(script::BitwiseAndAssignmentOperator, and_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function or_assign()
  {
    return class_.newOperator(script::BitwiseOrAssignmentOperator, or_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function xor_assign()
  {
    return class_.newOperator(script::BitwiseXorAssignmentOperator, xor_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename ReturnType, typename IndexType>
  script::Function subscript()
  {
    /// TODO : consider the case were ReturnType is a non-const reference.
    return class_.newOperator(script::SubscriptOperator, subscript_wrapper<ReturnType, T&, IndexType>)
      .returns(make_type<ReturnType>())
      .params(make_type<IndexType>())
      .get();
  }

  template<typename ReturnType, typename IndexType>
  script::Function const_subscript()
  {
    return class_.newOperator(script::SubscriptOperator, subscript_wrapper<ReturnType, const T&, IndexType>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<IndexType>())
      .get();
  }

  template<typename ReturnType>
  script::Function logical_not()
  {
    return class_.newOperator(script::LogicalNotOperator, logical_not_wrapper<ReturnType, const T&>)
      .setConst()
      .returns(make_type<ReturnType>())
      .get();
  }

  template<typename ReturnType>
  script::Function unary_plus()
  {
    return class_.newOperator(script::UnaryPlusOperator, unary_plus_wrapper<T&>)
      .setConst()
      .returns(make_type<ReturnType>())
      .get();
  }

  template<typename ReturnType>
  script::Function unary_minus()
  {
    return class_.newOperator(script::UnaryMinusOperator, unary_minus_wrapper<T&>)
      .setConst()
      .returns(make_type<ReturnType>())
      .get();
  }

  template<typename RHS>
  script::Function put_to()
  {
    return class_.newOperator(script::LeftShiftOperator, put_to_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }

  template<typename RHS>
  script::Function read_from()
  {
    return class_.newOperator(script::RightShiftOperator, read_from_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .get();
  }
};


template<typename T>
class GenericClassBinder
{
public:
  script::Class class_;

  GenericClassBinder(const script::Class & cla)
    : class_(cla)
  {

  }

public:

  /****************************************************************
  Operators
  ****************************************************************/

  ClassOperator<T> operators() { return ClassOperator<T>{class_}; }

  /****************************************************************
  Zero-arg member functions
  ****************************************************************/

  template<typename ReturnType, ReturnType(T::*fun)()const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>());
  }

  template<typename ReturnType, ReturnType(T::*fun)()>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>());
  }

  template<void(T::*fun)() const>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.newMethod(name, const_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst();
  }

  template<void(T::*fun)()>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_member_wrapper_t<decltype(fun), fun>::wrap);
  }

  template<void(T::*fun)()const>
  script::FunctionBuilder const_void_fun(const std::string & name)
  {
    return class_.newMethod(name, const_void_member_wrapper_t<decltype(fun), fun>::wrap);
  }

  template<typename ReturnType, ReturnType(*fun)(), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>());
  }

  template<void(*fun)(), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic();
  }

  template<typename ReturnType, ReturnType(T::*fun)()const>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>());
  }

  template<typename ReturnType, ReturnType(T::*fun)()>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>());
  }

  template<typename ReturnType, ReturnType(*fun)(T&)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>());
  }

  template<typename ReturnType, ReturnType(*fun)(const T&)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>());
  }

  /****************************************************************
  1-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>());
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>());
  }

  template<typename A1, void(T::*fun)(A1)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>());
  }

  template<typename A1, void(T::*fun)(A1) const>
  script::FunctionBuilder const_void_fun(const std::string & name)
  {
    return class_.newMethod(name, const_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>());
  }

  template<typename A1, T&(T::*fun)(A1)>
  script::FunctionBuilder chainable(const std::string & name)
  {
    return class_.newMethod(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>());
  }

  template<typename ReturnType, typename A1, ReturnType(*fun)(A1), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>());
  }

  template<typename A1, void(*fun)(A1), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>());
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)const>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>());
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>());
  }

  template<typename ReturnType, typename A1, ReturnType(*fun)(T&, A1)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>());
  }

  template<typename ReturnType, typename A1, ReturnType(*fun)(const T&, A1)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>());
  }

  /****************************************************************
  2-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, void(T::*fun)(A1, A2)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, T&(T::*fun)(A1, A2)>
  script::FunctionBuilder chainable(const std::string & name)
  {
    return class_.newMethod(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(A1, A2), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, void(*fun)(A1, A2), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)const>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(T&, A1, A2)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(const T&, A1, A2)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());
  }

  /****************************************************************
  3-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, void(T::*fun)(A1, A2, A3)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, T&(T::*fun)(A1, A2, A3)>
  script::FunctionBuilder chainable(const std::string & name)
  {
    return class_.newMethod(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(*fun)(A1, A2, A3), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, void(*fun)(A1, A2, A3), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)const>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  /****************************************************************
  4-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, void(T::*fun)(A1, A2, A3, A4)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, T&(T::*fun)(A1, A2, A3, A4)>
  script::FunctionBuilder chainable(const std::string & name)
  {
    return class_.newMethod(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(*fun)(A1, A2, A3, A4), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, void(*fun)(A1, A2, A3, A4), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)const>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)>
  script::FunctionBuilder ref_mem_getter(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    return class_.newMethod(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Proxy<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  /****************************************************************
  5-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(T::*fun)(A1, A2, A3, A4, A5)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(T::*fun)(A1, A2, A3, A4, A5)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, void(T::*fun)(A1, A2, A3, A4, A5)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, T&(T::*fun)(A1, A2, A3, A4, A5)>
  script::FunctionBuilder chainable(const std::string & name)
  {
    return class_.newMethod(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(*fun)(A1, A2, A3, A4, A5), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, void(*fun)(A1, A2, A3, A4, A5), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  /****************************************************************
  6-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, ReturnType(T::*fun)(A1, A2, A3, A4, A5, A6)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, ReturnType(T::*fun)(A1, A2, A3, A4, A5, A6)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.newMethod(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, void(T::*fun)(A1, A2, A3, A4, A5, A6)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, T&(T::*fun)(A1, A2, A3, A4, A5, A6)>
  script::FunctionBuilder chainable(const std::string & name)
  {
    return class_.newMethod(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, ReturnType(*fun)(A1, A2, A3, A4, A5, A6), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.newMethod(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, void(*fun)(A1, A2, A3, A4, A5, A6), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.newMethod(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

};

template<typename T, typename Tag = typename tag_resolver<T>::tag_type>
class ClassBinder;


template<typename T>
class ClassBinder<T, small_object_tag> : public GenericClassBinder<T>
{
public:

  ClassBinder(const script::Class & cla) : GenericClassBinder<T>(cla) { }

public:

  /****************************************************************
  Constructors
  ****************************************************************/

  script::ConstructorBuilder default_ctor()
  {
    return class_.newConstructor(constructor_wrapper_small_object_t<T>::wrap);
  }

  script::ConstructorBuilder copy_ctor()
  {
    return class_.newConstructor(constructor_wrapper_small_object_t<T, const T&>::wrap)
      .params(script::Type::cref(make_type<T>()));
  }

  template<typename A1>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_small_object_t<T, A1>::wrap)
      .params(make_type<A1>());
  }

  template<typename A1, typename A2>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_small_object_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, typename A3>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_small_object_t<T, A1, A2, A3>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, typename A4>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_small_object_t<T, A1, A2, A3, A4>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_small_object_t<T, A1, A2, A3, A4, A5>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_small_object_t<T, A1, A2, A3, A4, A5, A6>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

  /****************************************************************
  Destructor
  ****************************************************************/

  script::DestructorBuilder dtor()
  {
    return class_.newDestructor(destructor_wrapper_small_object_t<T>::wrap);
  }

};


template<typename T>
class ClassBinder<T, large_object_tag> : public GenericClassBinder<T>
{
public:

  ClassBinder(const script::Class & cla) : GenericClassBinder<T>(cla) { }


public:

  /****************************************************************
  Constructors
  ****************************************************************/
  script::ConstructorBuilder default_ctor()
  {
    return class_.newConstructor(constructor_wrapper_large_object_t<T>::wrap);
  }

  script::ConstructorBuilder copy_ctor()
  {
    return class_.newConstructor(constructor_wrapper_large_object_t<T, const T&>::wrap)
      .params(script::Type::cref(make_type<T>()));
  }

  template<typename A1>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_large_object_t<T, A1>::wrap)
      .params(make_type<A1>());
  }

  template<typename A1, typename A2>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_large_object_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, typename A3>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_large_object_t<T, A1, A2, A3>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, typename A4>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_large_object_t<T, A1, A2, A3, A4>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_large_object_t<T, A1, A2, A3, A4, A5>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
  script::ConstructorBuilder ctor()
  {
    return class_.newConstructor(constructor_wrapper_large_object_t<T, A1, A2, A3, A4, A5, A6>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>());
  }

  /****************************************************************
  Destructor
  ****************************************************************/

  script::DestructorBuilder dtor()
  {
    return class_.newDestructor(destructor_wrapper_large_object_t<T>::wrap);
  }
};

} // namespace binding

#endif // YASL_BINDING_CLASS_H
