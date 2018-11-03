// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QCLASS_H
#define YASL_BINDING_QCLASS_H

#include "yasl/binding/class.h"
#include "yasl/binding/qclass_constructor_wrapper.h"
#include "yasl/binding/qclass_destructor_wrapper.h"
#include "yasl/binding/qclass_member_wrapper.h"
#include "yasl/binding/qsignal.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/constructorbuilder.h>
#include <script/destructorbuilder.h>
#include <script/functionbuilder.h>
#include <script/operatorbuilder.h>
#include <script/value.h>
#include <script/private/value_p.h>

#include <string>

struct QMetaObject;

namespace binding
{

template<typename T>
class ClassBinder<T, qobject_tag> : public GenericClassBinder<T>
{
public:
  const QMetaObject *meta_;

  ClassBinder(const script::Class c, const QMetaObject *m) 
    : GenericClassBinder<T>(c)
    , meta_(m)
  { }

public:

  /****************************************************************
  Signals
  ****************************************************************/

  QSignal sigs() const { return QSignal{ class_, meta_ }; }

  /****************************************************************
  Constructors
  ****************************************************************/

  script::ConstructorBuilder default_ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T>::wrap);
  }

  template<typename A1>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1>::wrap)
      .params(make_type<A1>());
  }

  template<typename A1, typename A2>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2>::wrap)
      .params(make_type<A1>(), make_type<A2>());
  }

  template<typename A1, typename A2, typename A3>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>());
  }

  template<typename A1, typename A2, typename A3, typename A4>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3, A4>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>());
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  script::ConstructorBuilder ctor()
  {
    return class_.Constructor(qclass_constructor_wrapper_t<T, A1, A2, A3, A4, A5>::wrap)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>(), make_type<A5>());
  }

  /****************************************************************
  Destructor
  ****************************************************************/

  script::DestructorBuilder dtor()
  {
    return class_.Destructor(qclass_destructor_wrapper_t<T>::wrap);
  }

};

} // namespace binding

#endif // YASL_BINDING_QCLASS_H
