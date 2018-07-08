// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QCLASS_H
#define YASL_BINDING_QCLASS_H

#include "yasl/binding/qclass_constructor_wrapper.h"
#include "yasl/binding/qclass_destructor_wrapper.h"
#include "yasl/binding/qclass_member_wrapper.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/value.h>
#include <script/private/value_p.h>

#include <string>

#if !defined(YASL_BINDING_COMPILE_TIME_CHECK)
#define YASL_BINDING_BEGIN_RUNTIME_CHECK try {
#define YASL_BINDING_END_RUNTIME_CHECK } catch(UnknownTypeException &) { return; }
#else
#define YASL_BINDING_BEGIN_RUNTIME_CHECK 
#define YASL_BINDING_END_RUNTIME_CHECK
#endif // !defined(YASL_BINDING_COMPILE_TIME_CHECK)

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
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    class_.Constructor(qclass_constructor_wrapper_t<T, A1>::wrap)
      .params(make_type<A1>()).create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2>
  void add()
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>()).create();
    YASL_BINDING_END_RUNTIME_CHECK
  }
};

template<typename T>
class QClass
{
public:
  script::Class class_;


  QClass(const script::Class c)
    : class_(c)
  {

  }

  QClassConstructor<T> ctors() const { return QClassConstructor<T>{class_}; }

  void add_dtor()
  {
    class_.newDestructor(qclass_destructor_wrapper_t<T>::wrap);
  }

  /****************************************************************
  Zero-arg member functions
  ****************************************************************/

  template<typename ReturnType, ReturnType(T::*fun)()const>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, ReturnType(T::*fun)()>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<void(T::*fun)()>
  void add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap);

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }


  /****************************************************************
  1-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)const>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, ReturnType(T::*fun)(A1)>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, void(T::*fun)(A1)>
  void add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }


  /****************************************************************
  2-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)const>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, ReturnType(T::*fun)(A1, A2)>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, void(T::*fun)(A1, A2)>
  void add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  /****************************************************************
  3-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)const>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, ReturnType(T::*fun)(A1, A2, A3)>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, void(T::*fun)(A1, A2, A3)>
  void add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }


  /****************************************************************
  4-arg member functions
  ****************************************************************/

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)const>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .setConst()
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename ReturnType, typename A1, typename A2, typename A3, typename A4, ReturnType(T::*fun)(A1, A2, A3, A4)>
  void add_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_member_wrapper_t<decltype(fun), fun>::wrap)
      .returns(make_type<ReturnType>())
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

  template<typename A1, typename A2, typename A3, typename A4, void(T::*fun)(A1, A2, A3, A4)>
  void add_void_fun(const std::string & name)
  {
    YASL_BINDING_BEGIN_RUNTIME_CHECK
    auto builder = class_.Method(name, qclass_void_member_wrapper_t<decltype(fun), fun>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());

    builder.create();
    YASL_BINDING_END_RUNTIME_CHECK
  }

};


} // namespace binding

#undef YASL_BINDING_BEGIN_RUNTIME_CHECK 
#undef YASL_BINDING_END_RUNTIME_CHECK

#endif // YASL_BINDING_QCLASS_H
