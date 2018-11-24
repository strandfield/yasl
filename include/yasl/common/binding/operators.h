// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_OPERATORS_H
#define YASL_BINDING_OPERATORS_H

#include "yasl/common/values.h"

#include "yasl/common/wrappers/operator_wrapper.h"

#include <script/namespace.h>
#include <script/operator.h>
#include <script/operatorbuilder.h>

namespace script
{

namespace bind
{

/* Non-member operators */

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_add(script::Namespace & ns)
{
  return ns.newOperator(script::AdditionOperator, wrapper::add_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_sub(script::Namespace & ns)
{
  return ns.newOperator(script::SubstractionOperator, wrapper::sub_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_mul(script::Namespace & ns)
{
  return ns.newOperator(script::MultiplicationOperator, wrapper::mul_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_div(script::Namespace & ns)
{
  return ns.newOperator(script::DivisionOperator, wrapper::div_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_eq(script::Namespace & ns)
{
  return ns.newOperator(script::EqualOperator, wrapper::eq_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_neq(script::Namespace & ns)
{
  return ns.newOperator(script::InequalOperator, wrapper::neq_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_less(script::Namespace & ns)
{
  return ns.newOperator(script::LessOperator, wrapper::less_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_leq(script::Namespace & ns)
{
  return ns.newOperator(script::LessEqualOperator, wrapper::leq_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_greater(script::Namespace & ns)
{
  return ns.newOperator(script::GreaterOperator, wrapper::greater_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_geq(script::Namespace & ns)
{
  return ns.newOperator(script::GreaterEqualOperator, wrapper::geq_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_lshift(script::Namespace & ns)
{
  return ns.newOperator(script::LeftShiftOperator, wrapper::left_shift_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_rshift(script::Namespace & ns)
{
  return ns.newOperator(script::RightShiftOperator, wrapper::right_shift_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_put_to(script::Namespace & ns)
{
  return ns.newOperator(script::LeftShiftOperator, wrapper::put_to_wrapper<LHS, RHS>)
    .returns(make_type<LHS>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_read_from(script::Namespace & ns)
{
  return ns.newOperator(script::RightShiftOperator, wrapper::read_from_wrapper<LHS, RHS>)
    .returns(make_type<LHS>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_bitor(script::Namespace & ns)
{
  return ns.newOperator(script::BitwiseOrOperator, wrapper::or_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_bitand(script::Namespace & ns)
{
  return ns.newOperator(script::BitwiseAndOperator, wrapper::and_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_or_assign(script::Namespace & ns)
{
  return ns.newOperator(script::BitwiseOrAssignmentOperator, wrapper::or_assign_wrapper<LHS, RHS>)
    .returns(make_type<LHS&>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_and_assign(script::Namespace & ns)
{
  return ns.newOperator(script::BitwiseAndAssignmentOperator, wrapper::and_assign_wrapper<LHS, RHS>)
    .returns(make_type<LHS&>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename Arg>
script::Function op_unary_plus(script::Namespace & ns)
{
  return ns.newOperator(script::UnaryPlusOperator, wrapper::unary_plus_wrapper<Arg>)
    .returns(make_type<ReturnType>())
    .params(make_type<Arg>())
    .get();
}

template<typename ReturnType, typename Arg>
script::Function op_unary_minus(script::Namespace & ns)
{
  return ns.newOperator(script::UnaryMinusOperator, wrapper::unary_minus_wrapper<Arg>)
    .returns(make_type<ReturnType>())
    .params(make_type<Arg>())
    .get();
}


/* Member operators */

template<typename T, typename RHS>
script::Function memop_assign(script::Class & cla)
{
  return cla.newOperator(script::AssignmentOperator, wrapper::assign_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_subscript(script::Class & cla)
{
  return cla.newOperator(script::SubscriptOperator, wrapper::subscript_wrapper<R, T&, RHS>)
    .returns(make_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_const_subscript(script::Class & cla)
{
  return cla.newOperator(script::SubscriptOperator, wrapper::subscript_wrapper<R, const T&, RHS>)
    .setConst()
    .returns(make_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_add_assign(script::Class & cla)
{
  return cla.newOperator(script::AdditionAssignmentOperator, wrapper::add_assign_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_sub_assign(script::Class & cla)
{
  return cla.newOperator(script::AdditionAssignmentOperator, wrapper::sub_assign_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_mul_assign(script::Class & cla)
{
  return cla.newOperator(script::MultiplicationAssignmentOperator, wrapper::mul_assign_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}


template<typename T, typename RHS>
script::Function memop_div_assign(script::Class & cla)
{
  return cla.newOperator(script::DivisionAssignmentOperator, wrapper::div_assign_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_xor_assign(script::Class & cla)
{
  return cla.newOperator(script::BitwiseXorAssignmentOperator, wrapper::xor_assign_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_add(script::Class & cla)
{
  return cla.newOperator(script::AdditionOperator, wrapper::add_wrapper<const T &, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_sub(script::Class & cla)
{
  return cla.newOperator(script::SubstractionOperator, wrapper::sub_wrapper<const T &, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_mul(script::Class & cla)
{
  return cla.newOperator(script::MultiplicationOperator, wrapper::mul_wrapper<const T &, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_div(script::Class & cla)
{
  return cla.newOperator(script::DivisionOperator, wrapper::div_wrapper<const T &, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_eq(script::Class & cla)
{
  return cla.newOperator(script::EqualOperator, wrapper::eq_wrapper<const T &, RHS>)
    .setConst()
    .returns(script::Type::Boolean)
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_neq(script::Class & cla)
{
  return cla.newOperator(script::InequalOperator, wrapper::neq_wrapper<const T &, RHS>)
    .setConst()
    .returns(script::Type::Boolean)
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_less(script::Class & cla)
{
  return cla.newOperator(script::LessOperator, wrapper::less_wrapper<const T&, RHS>)
    .setConst()
    .returns(script::Type::Boolean)
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_leq(script::Class & cla)
{
  return cla.newOperator(script::LessEqualOperator, wrapper::leq_wrapper<const T &, RHS>)
    .setConst()
    .returns(script::Type::Boolean)
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_greater(script::Class & cla)
{
  return cla.newOperator(script::GreaterOperator, wrapper::greater_wrapper<const T &, RHS>)
    .setConst()
    .returns(script::Type::Boolean)
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_geq(script::Class & cla)
{
  return cla.newOperator(script::GreaterEqualOperator, wrapper::geq_wrapper<const T &, RHS>)
    .setConst()
    .returns(script::Type::Boolean)
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_lshift(script::Class & cla)
{
  return cla.newOperator(script::LeftShiftOperator, wrapper::left_shift_wrapper<const T &, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_rshift(script::Class & cla)
{
  return cla.newOperator(script::RightShiftOperator, wrapper::right_shift_wrapper<const T &, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_put_to(script::Class & cla)
{
  return cla.newOperator(script::LeftShiftOperator, wrapper::put_to_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_read_from(script::Class & cla)
{
  return cla.newOperator(script::RightShiftOperator, wrapper::read_from_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_bitor(script::Class & cla)
{
  return cla.newOperator(script::BitwiseOrOperator, wrapper::or_wrapper<const T&, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_bitand(script::Class & cla)
{
  return cla.newOperator(script::BitwiseAndOperator, wrapper::and_wrapper<const T&, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R, typename RHS>
script::Function memop_bitxor(script::Class & cla)
{
  return cla.newOperator(script::BitwiseXorOperator, wrapper::xor_wrapper<const T&, RHS>)
    .setConst()
    .returns(make_return_type<R>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_or_assign(script::Class & cla)
{
  return cla.newOperator(script::BitwiseOrAssignmentOperator, wrapper::or_assign_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename RHS>
script::Function memop_and_assign(script::Class & cla)
{
  return cla.newOperator(script::BitwiseAndAssignmentOperator, wrapper::and_assign_wrapper<T&, RHS>)
    .returns(make_type<T&>())
    .params(make_type<RHS>())
    .get();
}

template<typename T, typename R>
script::Function memop_unary_plus(script::Class & cla)
{
  return cla.newOperator(script::UnaryPlusOperator, wrapper::unary_plus_wrapper<const T&>)
    .returns(make_type<R>())
    .get();
}

template<typename T, typename R>
script::Function memop_unary_minus(script::Class & cla)
{
  return cla.newOperator(script::UnaryMinusOperator, wrapper::unary_minus_wrapper<const T &>)
    .returns(make_type<R>())
    .get();
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING_OPERATORS_H
