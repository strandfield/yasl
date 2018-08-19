// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_QOBJECT_BINDING_H
#define YASL_CORE_QOBJECT_BINDING_H

#include "yasl/binding/values.h"
#include "yasl/utils/ref.h"

#include <QObject>

namespace binding
{

struct qobject_tag {};

} // namespace binding


namespace binding
{

template<typename T>
struct make_value_t<T, qobject_tag>
{
  static script::Value make(T *input, script::Engine *e)
  {
    return make_ref(e, make_type<T*>(), input);
  }
};

} // namespace binding

namespace binding
{

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

} // namespace binding

#endif // YASL_CORE_QOBJECT_BINDING_H
