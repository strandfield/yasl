// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_QVARIANT_VALUES_H
#define YASL_CORE_QVARIANT_VALUES_H

#include "yasl/common/values.h"

#include <QVariant>

namespace script
{

struct qvariant_tag {};

template<>
struct make_value_t<QVariant, qvariant_tag>
{
  static script::Value make(const QVariant & input, script::Engine *e)
  {
    return e->construct(script::Type::QVariant, [&input](script::Value & val) {
      val.setVariant(input);
    });
  }
};

template<>
struct storage_type_default_impl<QVariant, qvariant_tag> : buffer_storage<QVariant> { };

template<>
struct get_helper<QVariant, qvariant_tag>
{
  static QVariant & get(script::Value val)
  {
    return val.toVariant();
  }
};

} // namespace script

#endif // YASL_CORE_QVARIANT_VALUES_H
