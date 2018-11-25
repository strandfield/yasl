// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_QVARIANT_BINDER_H
#define YASL_CORE_QVARIANT_BINDER_H

#include "yasl/common/binding/constructor_binder.h"
#include "yasl/common/binding/destructor_binder.h"
#include "yasl/core/qvariant-values.h"

namespace script
{

namespace bind
{

template<typename T>
struct constructor_binder<T, qvariant_tag>
{
  static script::Value default_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    self.setVariant(QVariant());
    return self;
  }

  static script::Value copy_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    self.setVariant(QVariant(c->arg(1).toVariant()));
    return self;
  }

  template<typename A1>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    self.setVariant(QVariant(value_cast<A1>(c->arg(1))));
    return self;
  }

  template<typename A1, typename A2>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    self.setVariant(QVariant(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2))));
    return self;
  }

  template<typename A1, typename A2, typename A3>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    self.setVariant(QVariant(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3))));
    return self;
  }

  template<typename A1, typename A2, typename A3, typename A4>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    self.setVariant(QVariant(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4))));
    return self;
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    self.setVariant(QVariant(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5))));
    return self;
  }

  template<typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
  static script::Value generic_ctor(script::FunctionCall *c)
  {
    script::Value self = c->thisObject();
    self.setVariant(QVariant(value_cast<A1>(c->arg(1)), value_cast<A2>(c->arg(2)), value_cast<A3>(c->arg(3)), value_cast<A4>(c->arg(4)), value_cast<A5>(c->arg(5)), value_cast<A6>(c->arg(6))));
    return self;
  }
};

template<typename T>
struct destructor_binder<T, qvariant_tag>
{
  static script::Value destructor(script::FunctionCall *c)
  {
    auto self = c->thisObject();
    self.clear(passkey{});
    return script::Value::Void;
  }
};

} // namespace bind

} // namespace script

#endif // YASL_CORE_QVARIANT_BINDER_H
