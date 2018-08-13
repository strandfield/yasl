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
#include <script/functionbuilder.h>

#if !defined(YASL_BINDING_COMPILE_TIME_CHECK)
#define YASL_BINDING_BEGIN_RUNTIME_CHECK try {
#define YASL_BINDING_END_RUNTIME_CHECK } catch(UnknownTypeException &) { return script::Function{}; }
#else
#define YASL_BINDING_BEGIN_RUNTIME_CHECK 
#define YASL_BINDING_END_RUNTIME_CHECK
#endif // !defined(YASL_BINDING_COMPILE_TIME_CHECK)

namespace binding
{

template<typename T, typename SizeTag = typename tag_resolver<T>::tag_type >
class ClassConstructor;

template<typename T>
class ClassConstructor<T, small_object_tag>
{
public:
  script::Class class_;

  script::Function add_default()
  {
    return class_.Constructor(constructor_wrapper_small_object_t<T>::wrap).create();
  }

  script::Function add_copy()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_small_object_t<T, const T&>::wrap)
      .params(script::Type::cref(make_type<T>()))
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_small_object_t<T, A1>::wrap)
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_small_object_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_small_object_t<T, A1, A2, A3>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_small_object_t<T, A1, A2, A3, A4>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_small_object_t<T, A1, A2, A3, A4, A5>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_small_object_t<T, A1, A2, A3, A4, A5, A6>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }
};

template<typename T>
class ClassConstructor<T, large_object_tag>
{
public:
  script::Class class_;

  script::Function add_default()
  {
    return class_.Constructor(constructor_wrapper_large_object_t<T>::wrap).create();
  }

  template<typename A1>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_large_object_t<T, A1>::wrap)
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Constructor(constructor_wrapper_large_object_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }
};



template<typename T, typename SizeTag = typename tag_resolver<T>::tag_type >
class ClassDestructor;

template<typename T>
class ClassDestructor<T, small_object_tag>
{
public:
  script::Class class_;

  script::Function add()
  {
    return class_.newDestructor(destructor_wrapper_small_object_t<T>::wrap);
  }
};

template<typename T>
class ClassDestructor<T, large_object_tag>
{
public:
  script::Class class_;

  script::Function add()
  {
    return class_.newDestructor(destructor_wrapper_large_object_t<T>::wrap);
  }
};


template<typename T>
class ClassOperator
{
public:
  script::Class class_;

  template<typename ReturnType, typename RHS>
  script::Function add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::AdditionOperator, add_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename RHS>
  script::Function sub()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::SubstractionOperator, sub_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename RHS>
  script::Function mul()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::MultiplicationOperator, mul_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename RHS>
  script::Function div()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::DivisionOperator, div_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function assign()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::AssignmentOperator, assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function add_assign()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::AdditionAssignmentOperator, add_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function sub_assign()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::AdditionAssignmentOperator, sub_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function mul_assign()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::MultiplicationAssignmentOperator, mul_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function div_assign()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::DivisionAssignmentOperator, div_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function eq()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::EqualOperator, eq_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function neq()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::InequalOperator, neq_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function less()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::LessOperator, less_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function leq()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::LessEqualOperator, leq_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function greater()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::GreaterOperator, greater_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function geq()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::GreaterEqualOperator, geq_wrapper<const T&, RHS>)
      .setConst()
      .returns(script::Type::Boolean)
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename RHS>
  script::Function and()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::BitwiseAndOperator, and_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename RHS>
  script::Function or()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::BitwiseOrOperator, or_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename RHS>
  script::Function xor()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::BitwiseXorOperator, xor_wrapper<const T&, RHS>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function and_assign()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::BitwiseAndAssignmentOperator, and_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function or_assign()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::BitwiseOrAssignmentOperator, or_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function xor_assign()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::BitwiseXorAssignmentOperator, xor_assign_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename IndexType>
  script::Function subscript()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Operation(script::SubscriptOperator, subscript_wrapper<ReturnType, T&, IndexType>)
      .returns(make_type<ReturnType>())
      .params(make_type<IndexType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename IndexType>
  script::Function const_subscript()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::SubscriptOperator, subscript_wrapper<ReturnType, const T&, IndexType>)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<IndexType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType>
  script::Function logical_not()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::LogicalNotOperator, logical_not_wrapper<ReturnType, const T&>)
      .setConst()
      .returns(make_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType>
  script::Function unary_plus()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::UnaryPlusOperator, unary_plus_wrapper<T&>)
      .setConst()
      .returns(make_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType>
  script::Function unary_minus()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::UnaryMinusOperator, unary_minus_wrapper<T&>)
      .setConst()
      .returns(make_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function put_to()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::LeftShiftOperator, put_to_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename RHS>
  script::Function read_from()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Operation(script::RightShiftOperator, read_from_wrapper<T&, RHS>)
      .returns(make_type<T&>())
      .params(make_type<RHS>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }
};


template<typename T>
class Class
{
public:
  script::Class class_;

  ClassConstructor<T> ctors() const { return ClassConstructor<T>{class_}; }

  void add_dtor()
  {
    ClassDestructor<T>{class_}.add();
  }

  void add(script::FunctionBuilder & builder)
  {
    builder.create();
  }


  /****************************************************************
  Zero-arg member functions
  ****************************************************************/


  template<typename ReturnType, ReturnType(T::*fun)()const>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, ReturnType(T::*fun)()>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<void(T::*fun)() const>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, const_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<void(T::*fun)()>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, ReturnType(*fun)(), typename FunType = decltype(fun)>
  script::Function add_static(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<void(*fun)(), typename FunType = decltype(fun)>
  script::Function add_static_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, ReturnType(T::*fun)()const>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, ReturnType(T::*fun)()>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, ReturnType(*fun)(T&)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, ReturnType(*fun)(const T&)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  1-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)const>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, void(T::*fun)(A1)>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, void(T::*fun)(A1) const>
  script::Function add_const_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, const_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, T&(T::*fun)(A1)>
  script::Function add_chainable(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, ReturnType(*fun)(A1), typename FunType = decltype(fun)>
  script::Function add_static(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, void(*fun)(A1), typename FunType = decltype(fun)>
  script::Function add_static_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)const>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, ReturnType(*fun)(T&, A1)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, ReturnType(*fun)(const T&, A1)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  2-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)const>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, void(T::*fun)(A1, A2)>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, T&(T::*fun)(A1, A2)>
  script::Function add_chainable(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(A1, A2), typename FunType = decltype(fun)>
  script::Function add_static(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, void(*fun)(A1, A2), typename FunType = decltype(fun)>
  script::Function add_static_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)const>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(T&, A1, A2)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(const T&, A1, A2)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, function_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  3-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)const>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, void(T::*fun)(A1, A2, A3)>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, T&(T::*fun)(A1, A2, A3)>
  script::Function add_chainable(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(*fun)(A1, A2, A3), typename FunType = decltype(fun)>
  script::Function add_static(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, void(*fun)(A1, A2, A3), typename FunType = decltype(fun)>
  script::Function add_static_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)const>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  4-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)const>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, void(T::*fun)(A1, A2, A3, A4)>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, T&(T::*fun)(A1, A2, A3, A4)>
  script::Function add_chainable(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(*fun)(A1, A2, A3, A4), typename FunType = decltype(fun)>
  script::Function add_static(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, void(*fun)(A1, A2, A3, A4), typename FunType = decltype(fun)>
  script::Function add_static_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)const>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)>
  script::Function add_ref_mem(const std::string & name)
  {
    static_assert(std::is_reference<ReturnType>::value, "Return type must be a reference");

    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, ref_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<Ptr<std::remove_reference<ReturnType>::type>>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  5-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(T::*fun)(A1, A2, A3, A4, A5)const>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(T::*fun)(A1, A2, A3, A4, A5)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, void(T::*fun)(A1, A2, A3, A4, A5)>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, T&(T::*fun)(A1, A2, A3, A4, A5)>
  script::Function add_chainable(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(*fun)(A1, A2, A3, A4, A5), typename FunType = decltype(fun)>
  script::Function add_static(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, void(*fun)(A1, A2, A3, A4, A5), typename FunType = decltype(fun)>
  script::Function add_static_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  6-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, ReturnType(T::*fun)(A1, A2, A3, A4, A5, A6)const>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, ReturnType(T::*fun)(A1, A2, A3, A4, A5, A6)>
  script::Function add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, void(T::*fun)(A1, A2, A3, A4, A5, A6)>
  script::Function add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, T&(T::*fun)(A1, A2, A3, A4, A5, A6)>
  script::Function add_chainable(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, chainable_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(script::Type::cref(make_type<T>()))
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, ReturnType(*fun)(A1, A2, A3, A4, A5, A6), typename FunType = decltype(fun)>
  script::Function add_static(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, void(*fun)(A1, A2, A3, A4, A5, A6), typename FunType = decltype(fun)>
  script::Function add_static_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
      return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>(), make_type<A6>())
      .create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  Operators
  ****************************************************************/

  ClassOperator<T> operators() { return ClassOperator<T>{class_}; }
};


} // namespace binding

#undef YASL_BINDING_BEGIN_RUNTIME_CHECK 
#undef YASL_BINDING_END_RUNTIME_CHECK

#endif // YASL_BINDING_CLASS_H
