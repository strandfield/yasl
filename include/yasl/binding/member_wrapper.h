// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_MEMBER_FUN_WRAPPER_H
#define YASL_BINDING_MEMBER_FUN_WRAPPER_H

#include "yasl/binding/values.h"

#include <script/interpreter/executioncontext.h>

namespace binding
{

/****************************************************************
Non-void member functions
****************************************************************/


template<typename MemberType, MemberType f>
struct member_wrapper_t;

template<typename R, typename ClassType, R(ClassType::*f)()const>
struct member_wrapper_t<R(ClassType::*)()const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(), c->engine());
  }
};

template<typename R, typename ClassType, R(ClassType::*f)()>
struct member_wrapper_t<R(ClassType::*)(), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, R(ClassType::*f)(A1)const>
struct member_wrapper_t<R(ClassType::*)(A1)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, R(ClassType::*f)(A1)>
struct member_wrapper_t<R(ClassType::*)(A1), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, R(ClassType::*f)(A1, A2)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, R(ClassType::*f)(A1, A2)>
struct member_wrapper_t<R(ClassType::*)(A1, A2), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, R(ClassType::*f)(A1, A2, A3)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, R(ClassType::*f)(A1, A2, A3)>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, R(ClassType::*f)(A1, A2, A3, A4)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, R(ClassType::*f)(A1, A2, A3, A4)>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, R(ClassType::*f)(A1, A2, A3, A4, A5)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4, A5)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, R(ClassType::*f)(A1, A2, A3, A4, A5)>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4, A5), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, R(ClassType::*f)(A1, A2, A3, A4, A5, A6)const>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4, A5, A6)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6))), c->engine());
  }
};

template<typename R, typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, R(ClassType::*f)(A1, A2, A3, A4, A5, A6)>
struct member_wrapper_t<R(ClassType::*)(A1, A2, A3, A4, A5, A6), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    return make_value<std::decay<R>::type>(((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6))), c->engine());
  }
};

/****************************************************************
void member functions
****************************************************************/

template<typename MemberType, MemberType f>
struct void_member_wrapper_t;

template<typename ClassType, void(ClassType::*f)()>
struct void_member_wrapper_t<void(ClassType::*)(), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))();
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, void(ClassType::*f)(A1)>
struct void_member_wrapper_t<void(ClassType::*)(A1), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, void(ClassType::*f)(A1, A2)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, void(ClassType::*f)(A1, A2, A3)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2, A3), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, void(ClassType::*f)(A1, A2, A3, A4)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2, A3, A4), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, void(ClassType::*f)(A1, A2, A3, A4, A5)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2, A3, A4, A5), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, void(ClassType::*f)(A1, A2, A3, A4, A5, A6)>
struct void_member_wrapper_t<void(ClassType::*)(A1, A2, A3, A4, A5, A6), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6)));
    return script::Value::Void;
  }
};

/****************************************************************
const void member functions
****************************************************************/

template<typename MemberType, MemberType f>
struct const_void_member_wrapper_t;

template<typename ClassType, void(ClassType::*f)()const>
struct const_void_member_wrapper_t<void(ClassType::*)()const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))();
    return script::Value::Void;
  }
};

template<typename ClassType, typename A1, void(ClassType::*f)(A1)const>
struct const_void_member_wrapper_t<void(ClassType::*)(A1)const, f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)));
    return script::Value::Void;
  }
};

/****************************************************************
"chainable" member functions
****************************************************************/

template<typename MemberType, MemberType f>
struct chainable_member_wrapper_t;

template<typename ClassType, typename A1, ClassType&(ClassType::*f)(A1)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, ClassType&(ClassType::*f)(A1, A2)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, ClassType&(ClassType::*f)(A1, A2, A3)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2, A3), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, ClassType&(ClassType::*f)(A1, A2, A3, A4)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2, A3, A4), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, ClassType&(ClassType::*f)(A1, A2, A3, A4, A5)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2, A3, A4, A5), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    return c->thisObject();
  }
};

template<typename ClassType, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, ClassType&(ClassType::*f)(A1, A2, A3, A4, A5, A6)>
struct chainable_member_wrapper_t<ClassType&(ClassType::*)(A1, A2, A3, A4, A5, A6), f> {
  static script::Value wrap(script::FunctionCall *c) {
    ClassType & ref = *value_cast<ClassType*>(c->arg(0));
    ((ref).*(f))(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6)));
    return c->thisObject();
  }
};

} // namespace binding

#endif // YASL_BINDING_MEMBER_FUN_WRAPPER_H
