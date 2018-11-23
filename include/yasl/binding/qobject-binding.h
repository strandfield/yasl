// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QOBJECT_BINDING_H
#define YASL_BINDING_QOBJECT_BINDING_H

#include "yasl/binding/values.h"
#include "yasl/binding/ref.h"

#include <QObject>

namespace script
{

namespace bind
{

struct qobject_tag {};

template<typename T>
struct make_value_t<T, qobject_tag>
{
  static script::Value make(T *input, script::Engine *e)
  {
    return make_ref(e, make_type<T*>(), input);
  }
};


template<typename T>
struct qobject_storage : heap_storage<T> { };

template<typename T>
struct storage_type_default_impl<T, qobject_tag> : qobject_storage<T> { };

template<typename T>
struct get_helper<T, qobject_tag>
{
  static T* get(const script::Value & val)
  {
    return qobject_cast<T*>(val.toQObject());
  }
};

} // namespace bind

} // namespace script

#endif // YASL_BINDING_QOBJECT_BINDING_H
