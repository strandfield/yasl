// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QCLASS_H
#define YASL_BINDING_QCLASS_H

#include "yasl/binding2/constructor_binder.h"
#include "yasl/binding2/destructor_binder.h"
#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/signals.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/constructorbuilder.h>
#include <script/destructorbuilder.h>
#include <script/value.h>

struct QMetaObject;

namespace script
{

namespace bind
{

inline void link(script::Class & cla, const QMetaObject *mo)
{
  cla.engine()->registerQtType(mo, cla.id());
}

template<typename T>
struct constructor_binder<T, qobject_tag>
{
  static script::Value default_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *obj = new T;
    c->engine()->bind(self, obj);
    return self;
  }

  static script::Value copy_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<const T &>(c->arg(1)));
    c->engine()->bind(self, obj);
    return self;
  }

  template<typename A1>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)));
    c->engine()->bind(self, obj);
    return self;
  }

  template<typename A1, typename A2>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)));
    c->engine()->bind(self, obj);
    return self;
  }

  template<typename A1, typename A2, typename A3>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)));
    c->engine()->bind(self, obj);
    return self;
  }

  template<typename A1, typename A2, typename A3, typename A4>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)));
    c->engine()->bind(self, obj);
    return self;
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)));
    c->engine()->bind(self, obj);
    return self;
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *obj = new T(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6)));
    c->engine()->bind(self, obj);
    return self;
  }
};

template<typename T>
struct destructor_binder<T, qobject_tag>
{
  static script::Value destructor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    T *ref = qobject_cast<T*>(self.impl()->data.builtin.qobject);
    if (ref != nullptr)
      delete ref;
    self.impl()->data.builtin.qobject = nullptr;
    return script::Value::Void;
  }
};

} // namespace bind

} // namespace script

#endif // YASL_BINDING_QCLASS_H
