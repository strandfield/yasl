// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_QEVENT_BINDING_H
#define YASL_CORE_QEVENT_BINDING_H

#include "yasl/common/values.h"
#include "yasl/core/makeevent.h"

#include <QEvent>

namespace script
{

struct qevent_tag {};

template<typename T>
struct make_value_t<T, qevent_tag>
{
  static script::Value make(T *input, script::Engine *e)
  {
    return make_event(e, make_type<T>(), input);
  }
};

template<typename T>
struct storage_type_default_impl<T, qevent_tag> : pointer_storage<T> { };

template<typename T>
struct get_helper<T, qevent_tag>
{
  typedef T* type;

  static T* get(const script::Value & val)
  {
    return static_cast<T*>(script::get<QEventWrapper>(val).p);
    //return static_cast<T*>(val.getPtr());
  }
};

} // namespace script

#endif // YASL_CORE_QEVENT_BINDING_H
