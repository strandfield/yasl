// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_MEMBER_FUN_WRAPPER_H
#define YASL_BINDING_MEMBER_FUN_WRAPPER_H

#include "yasl/binding/values.h"

#include <script/interpreter/executioncontext.h>

namespace script
{

namespace bind
{

/****************************************************************
Non-void member functions
****************************************************************/


template<typename MemberType, MemberType f>
struct member_wrapper_t;

template<typename R, typename ClassType, R(ClassType::*F)()const>
struct member_wrapper_t<R(ClassType::*)()const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(), c->engine());
  }
};

template<typename R, typename ClassType, R(ClassType::*F)()>
struct member_wrapper_t<R(ClassType::*)(), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, R(ClassType::*F)(A1)const>
struct member_wrapper_t<R(ClassType::*)(A1)const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, R(ClassType::*F)(A1)>
struct member_wrapper_t<R(ClassType::*)(A1), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, R(ClassType::*F)(A1, A2)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2)const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, R(ClassType::*F)(A1, A2)>
struct member_wrapper_t<R(ClassType::*)(A1, A2), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, R(ClassType::*F)(A1, A2, A3)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3)const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, R(ClassType::*F)(A1, A2, A3)>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, R(ClassType::*F)(A1, A2, A3, A4)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4)const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, R(ClassType::*F)(A1, A2, A3, A4)>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, R(ClassType::*F)(A1, A2, A3, A4, A5)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4, A5)const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, R(ClassType::*F)(A1, A2, A3, A4, A5)>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4, A5), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, R(ClassType::*F)(A1, A2, A3, A4, A5, A6)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4, A5, A6)const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, R(ClassType::*F)(A1, A2, A3, A4, A5, A6)>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4, A5, A6), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<typename std::decay<R>::type>(((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6))), c->engine());
  }
};

/****************************************************************
void member functions
****************************************************************/

template<typename MemberType, MemberType f>
struct void_member_wrapper_t;

template<typename ClassType, void(ClassType::*F)()>
struct void_member_wrapper_t<void(ClassType::*)(), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))();
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, void(ClassType::*F)(A1)>
struct void_member_wrapper_t<void(ClassType::*)(A1), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, void(ClassType::*F)(A1, A2)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, void(ClassType::*F)(A1, A2, A3)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2, A3), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, void(ClassType::*F)(A1, A2, A3, A4)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2, A3, A4), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, void(ClassType::*F)(A1, A2, A3, A4, A5)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2, A3, A4, A5), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, void(ClassType::*F)(A1, A2, A3, A4, A5, A6)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2, A3, A4, A5, A6), F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6)));
    return script::Value::Void;
  }
};

/****************************************************************
const void member functions
****************************************************************/

template<typename MemberType, MemberType f>
struct const_void_member_wrapper_t;

template<typename ClassType, void(ClassType::*F)()const>
struct const_void_member_wrapper_t<void(ClassType::*)()const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))();
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, void(ClassType::*F)(A1)const>
struct const_void_member_wrapper_t<void(ClassType::*)(A1)const, F> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(F))(value_cast<A1>(c->arg(1)));
    return script::Value::Void;
  }
};

} // namespace bind

} // namespace script

#endif // YASL_BINDING_MEMBER_FUN_WRAPPER_H
