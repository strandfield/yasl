// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QCLASS_MEMBER_FUN_WRAPPER_H
#define YASL_BINDING_QCLASS_MEMBER_FUN_WRAPPER_H

#include "yasl/binding/utils.h"

#include <script/interpreter/executioncontext.h>
#include <script/private/value_p.h>

namespace binding
{

/****************************************************************
Non-void member functions
****************************************************************/


template<typename MemberType, MemberType f>
struct qclass_member_wrapper_t;

template<typename R, typename ClassType, R(ClassType::*f)()const>
struct qclass_member_wrapper_t<R(ClassType::*)()const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(), c->engine());
  }
};

template<typename R, typename ClassType, R(ClassType::*f)()>
struct qclass_member_wrapper_t<R(ClassType::*)(), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, R(ClassType::*f)(A1)const>
struct qclass_member_wrapper_t<R(ClassType::*)(A1)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(value_cast<A1>(c->arg(1))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, R(ClassType::*f)(A1)>
struct qclass_member_wrapper_t<R(ClassType::*)(A1), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(value_cast<A1>(c->arg(1))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, R(ClassType::*f)(A1, A2)const>
struct qclass_member_wrapper_t<R(ClassType::*)(A1, A2)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, R(ClassType::*f)(A1, A2)>
struct qclass_member_wrapper_t<R(ClassType::*)(A1, A2), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, R(ClassType::*f)(A1, A2, A3)const>
struct qclass_member_wrapper_t<R(ClassType::*)(A1, A2, A3)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, R(ClassType::*f)(A1, A2, A3)>
struct qclass_member_wrapper_t<R(ClassType::*)(A1, A2, A3), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, R(ClassType::*f)(A1, A2, A3, A4)const>
struct qclass_member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, R(ClassType::*f)(A1, A2, A3, A4)>
struct qclass_member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    return make_value(((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4))), c->engine());
  }
};


/****************************************************************
void member functions
****************************************************************/

template<typename MemberType, MemberType f>
struct qclass_void_member_wrapper_t;

template<typename ClassType, void(ClassType::*f)()>
struct qclass_void_member_wrapper_t<void(ClassType::*)(), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    ((*ref).*(f))();
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, void(ClassType::*f)(A1)>
struct qclass_void_member_wrapper_t<void(ClassType::*)(A1), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    ((*ref).*(f))(value_cast<A1>(c->arg(1)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, void(ClassType::*f)(A1, A2)>
struct qclass_void_member_wrapper_t<void(ClassType::*)(A1, A2), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    ((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, void(ClassType::*f)(A1, A2, A3)>
struct qclass_void_member_wrapper_t<void(ClassType::*)(A1, A2, A3), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    ((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, void(ClassType::*f)(A1, A2, A3, A4)>
struct qclass_void_member_wrapper_t<void(ClassType::*)(A1, A2, A3, A4), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType *ref = qobject_cast<ClassType*>(c->arg(0).impl()->data.builtin.qobject);
    ((*ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    return script::Value::Void;
  }
};

} // namespace binding

#endif // YASL_BINDING_QCLASS_MEMBER_FUN_WRAPPER_H
