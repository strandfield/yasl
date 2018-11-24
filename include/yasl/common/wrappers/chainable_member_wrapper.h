// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WRAPPERS_CHAINABLE_MEMBER_FUN_WRAPPER_H
#define YASL_WRAPPERS_CHAINABLE_MEMBER_FUN_WRAPPER_H

#include "yasl/common/values.h"

#include <script/interpreter/executioncontext.h>

namespace script
{

namespace wrapper
{

/****************************************************************
"chainable" member functions
****************************************************************/

template<typename MemberType, MemberType f>
struct chainable_member_wrapper_t;

template<typename ClassType, typename A1, ClassType&(ClassType::*F)(A1)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, ClassType&(ClassType::*F)(A1, A2)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, ClassType&(ClassType::*F)(A1, A2, A3)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2, A3), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, ClassType&(ClassType::*F)(A1, A2, A3, A4)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2, A3, A4), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, ClassType&(ClassType::*F)(A1, A2, A3, A4, A5)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2, A3, A4, A5), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, ClassType&(ClassType::*F)(A1, A2, A3, A4, A5, A6)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2, A3, A4, A5, A6), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6)));
    return c->thisObject();
  }
};

} // namespace wrapper

} // namespace script

#endif // YASL_WRAPPERS_CHAINABLE_MEMBER_FUN_WRAPPER_H
