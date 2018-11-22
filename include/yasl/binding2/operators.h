// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING2_OPERATORS_H
#define YASL_BINDING2_OPERATORS_H

#include "yasl/binding2/values.h"

#include "yasl/binding2/operator_wrapper.h"

#include <script/namespace.h>
#include <script/operatorbuilder.h>

namespace script
{

namespace bind
{

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_add(script::Namespace & ns)
{
  return ns.newOperator(script::AdditionOperator, add_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_sub(script::Namespace & ns)
{
  return ns.newOperator(script::SubstractionOperator, sub_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_mul(script::Namespace & ns)
{
  return ns.newOperator(script::MultiplicationOperator, mul_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_div(script::Namespace & ns)
{
  return ns.newOperator(script::DivisionOperator, div_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_eq(script::Namespace & ns)
{
  return ns.newOperator(script::EqualOperator, eq_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_neq(script::Namespace & ns)
{
  return ns.newOperator(script::InequalOperator, neq_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_less(script::Namespace & ns)
{
  return ns.newOperator(script::LessOperator, less_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_leq(script::Namespace & ns)
{
  return ns.newOperator(script::LessEqualOperator, leq_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_greater(script::Namespace & ns)
{
  return ns.newOperator(script::GreaterOperator, greater_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_geq(script::Namespace & ns)
{
  return ns.newOperator(script::GreaterEqualOperator, geq_wrapper<LHS, RHS>)
    .returns(script::Type::Boolean)
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_lshift(script::Namespace & ns)
{
  return ns.newOperator(script::LeftShiftOperator, left_shift_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_rshift(script::Namespace & ns)
{
  return ns.newOperator(script::RightShiftOperator, right_shift_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_put_to(script::Namespace & ns)
{
  return ns.newOperator(script::LeftShiftOperator, put_to_wrapper<LHS, RHS>)
    .returns(make_type<LHS>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_read_from(script::Namespace & ns)
{
  return ns.newOperator(script::RightShiftOperator, read_from_wrapper<LHS, RHS>)
    .returns(make_type<LHS>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_bitor(script::Namespace & ns)
{
  return ns.newOperator(script::BitwiseOrOperator, or_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename LHS, typename RHS>
script::Function op_bitand(script::Namespace & ns)
{
  return ns.newOperator(script::BitwiseAndOperator, and_wrapper<LHS, RHS>)
    .returns(make_return_type<ReturnType>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_or_assign(script::Namespace & ns)
{
  return ns.newOperator(script::BitwiseOrAssignmentOperator, or_assign_wrapper<LHS, RHS>)
    .returns(make_type<LHS&>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename LHS, typename RHS>
script::Function op_and_assign(script::Namespace & ns)
{
  return ns.newOperator(script::BitwiseAndAssignmentOperator, and_assign_wrapper<LHS, RHS>)
    .returns(make_type<LHS&>())
    .params(make_type<LHS>(), make_type<RHS>())
    .get();
}

template<typename ReturnType, typename Arg>
script::Function op_unary_plus(script::Namespace & ns)
{
  return ns.newOperator(script::UnaryPlusOperator, unary_plus_wrapper<Arg>)
    .returns(make_type<ReturnType>())
    .params(make_type<Arg>())
    .get();
}

template<typename ReturnType, typename Arg>
script::Function op_unary_minus(script::Namespace & ns)
{
  return ns.newOperator(script::UnaryMinusOperator, unary_minus_wrapper<Arg>)
    .returns(make_type<ReturnType>())
    .params(make_type<Arg>())
    .get();
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_OPERATORS_H
