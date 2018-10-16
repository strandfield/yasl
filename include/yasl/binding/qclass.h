// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QCLASS_H
#define YASL_BINDING_QCLASS_H

#include "yasl/binding/qclass_constructor_wrapper.h"
#include "yasl/binding/qclass_destructor_wrapper.h"
#include "yasl/binding/qclass_member_wrapper.h"
#include "yasl/binding/qsignal.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/value.h>
#include <script/private/value_p.h>

#include <string>

struct QMetaObject;

namespace binding
{

template<typename T>
class QClassConstructor
{
public:
  script::Class class_;

  script::Function add_default()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T>::wrap).create();
  }

  template<typename A1>
  void add()
  {
    class_.Constructor(qclass_constructor_wrapper_t<T, A1>::wrap)
      .params(make_type<A1>()).create();
  }

  template<typename A1, typename A2>
  void add()
  {
    class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>()).create();
  }

  template<typename A1, typename A2, typename A3>
  void add()
  {
    class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>()).create();
  }

  template<typename A1, typename A2, typename A3, typename A4>
  void add()
  {
    class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3, A4>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>()).create();
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  void add()
  {
    class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3, A4, A5>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>()).create();
  }

  /****************************************************************
  Constructors
  ****************************************************************/

  script::FunctionBuilder default_ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T>::wrap);
  }

  template<typename A1>
  script::FunctionBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1>::wrap)
      .params(make_type<A1>());
  }

  template<typename A1, typename A2>
  script::FunctionBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, typename A3>
  script::FunctionBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, typename A4>
  script::FunctionBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3, A4>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  script::FunctionBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3, A4, A5>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }
};

template<typename T>
class QClass
{
public:
  script::Class class_;
  const QMetaObject *meta_;

  QClass(const script::Class c, const QMetaObject *m)
    : class_(c)
    , meta_(m)
  {

  }

  QClassConstructor<T> ctors() const { return QClassConstructor<T>{class_}; }

  QSignal sigs() const { return QSignal{ class_, meta_ }; }

  void add_dtor()
  {
    class_.Destructor(qclass_destructor_wrapper_t<T>::wrap).create();
  }

  /****************************************************************
  Zero-arg member functions
  ****************************************************************/

  template<typename ReturnType, ReturnType(T::*fun)()const>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>());

    builder.create();
  }

  template<typename ReturnType, ReturnType(T::*fun)()const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>());
  }

  template<typename ReturnType, ReturnType(T::*fun)()>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>());

    builder.create();
  }

  template<typename ReturnType, ReturnType(T::*fun)()>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>());
  }

  template<void(T::*fun)()>
  void add_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap);

    builder.create();
  }

  template<void(T::*fun)()>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap);
  }

  template<void(T::*fun)() const>
  void add_const_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_const_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst();

    builder.create();
  }

  template<void(T::*fun)() const>
  script::FunctionBuilder const_void_fun(const std::string & name)
  {
    return class_.Method(name, qclass_const_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst();
  }

  template<typename ReturnType, ReturnType(*fun)(), typename FunType = decltype(fun)>
  void add_static(const std::string & name)
  {
    auto builder = class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>());

    builder.create();
  }

  template<typename ReturnType, ReturnType(*fun)(), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>());
  }

  template<void(*fun)(), typename FunType = decltype(fun)>
  void add_static_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic();

    builder.create();
  }

  template<void(*fun)(), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic();
  }

  /****************************************************************
  1-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)const>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>());

    builder.create();
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>());
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>());

    builder.create();
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>());
  }

  template<typename A1, void(T::*fun)(A1)>
  void add_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>());

    builder.create();
  }

  template<typename A1, void(T::*fun)(A1)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>());
  }

  template<typename A1, void(T::*fun)(A1) const>
  void add_const_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_const_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>());

    builder.create();
  }

  template<typename A1, void(T::*fun)(A1) const>
  script::FunctionBuilder const_void_fun(const std::string & name)
  {
    return class_.Method(name, qclass_const_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>());
  }

  template<typename ReturnType, typename A1, ReturnType(*fun)(A1), typename FunType = decltype(fun)>
  void add_static(const std::string & name)
  {
    auto binder = class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>());

    binder.create();
  }

  template<typename ReturnType, typename A1, ReturnType(*fun)(A1), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>());
  }

  template<typename A1, void(*fun)(A1), typename FunType = decltype(fun)>
  void add_static_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>());

    builder.create();
  }

  template<typename A1, void(*fun)(A1), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>());
  }

  /****************************************************************
  2-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)const>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());

    builder.create();
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());

    builder.create();
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, void(T::*fun)(A1, A2)>
  void add_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>());

    builder.create();
  }

  template<typename A1, typename A2, void(T::*fun)(A1, A2)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(A1, A2), typename FunType = decltype(fun)>
  void add_static(const std::string & name)
  {
    auto binder = class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());

    binder.create();
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(*fun)(A1, A2), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, void(*fun)(A1, A2), typename FunType = decltype(fun)>
  void add_static_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>());

    builder.create();
  }

  template<typename A1, typename A2, void(*fun)(A1, A2), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>());
  }

  /****************************************************************
  3-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)const>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());

    builder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());

    builder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, void(T::*fun)(A1, A2, A3)>
  void add_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());

    builder.create();
  }

  template<typename A1, typename A2, typename A3, void(T::*fun)(A1, A2, A3)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(*fun)(A1, A2, A3), typename FunType = decltype(fun)>
  void add_static(const std::string & name)
  {
    auto binder = class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());

    binder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(*fun)(A1, A2, A3), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, void(*fun)(A1, A2, A3), typename FunType = decltype(fun)>
  void add_static_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());

    builder.create();
  }

  template<typename A1, typename A2, typename A3, void(*fun)(A1, A2, A3), typename FunType = decltype(fun)>
  script::FunctionBuilder static_void_fun(const std::string & name)
  {
    return class_.Method(name, void_function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  /****************************************************************
  4-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)const>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());

    builder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());

    builder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, void(T::*fun)(A1, A2, A3, A4)>
  void add_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());

    builder.create();
  }

  template<typename A1, typename A2, typename A3, typename A4, void(T::*fun)(A1, A2, A3, A4)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(*fun)(A1, A2, A3, A4), typename FunType = decltype(fun)>
  void add_static(const std::string & name)
  {
    auto binder = class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());

    binder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(*fun)(A1, A2, A3, A4), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  /****************************************************************
  5-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(T::*fun)(A1, A2, A3, A4, A5)const>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());

    builder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(T::*fun)(A1, A2, A3, A4, A5)const>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(T::*fun)(A1, A2, A3, A4, A5)>
  void add_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());

    builder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(T::*fun)(A1, A2, A3, A4, A5)>
  script::FunctionBuilder fun(const std::string & name)
  {
    return class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, void(T::*fun)(A1, A2, A3, A4, A5)>
  void add_void_fun(const std::string & name)
  {
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());

    builder.create();
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, void(T::*fun)(A1, A2, A3, A4, A5)>
  script::FunctionBuilder void_fun(const std::string & name)
  {
    return class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(*fun)(A1, A2, A3, A4, A5), typename FunType = decltype(fun)>
  void add_static(const std::string & name)
  {
    auto binder = class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());

    binder.create();
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, typename A5, ReturnType(*fun)(A1, A2, A3, A4, A5), typename FunType = decltype(fun)>
  script::FunctionBuilder static_fun(const std::string & name)
  {
    return class_.Method(name, function_wrapper_t<FunType, fun>::wrap)
      .setStatic()
      .returns(make_return_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }
};

} // namespace binding

#endif // YASL_BINDING_QCLASS_H
