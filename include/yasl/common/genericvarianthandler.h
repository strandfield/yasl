// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_GENERICVARIANTHANDLER_H
#define YASL_COMMONS_GENERICVARIANTHANDLER_H

#include "yasl/common/variant-utils.h"

#include "yasl/common/values.h"

#include <QMetaType>

namespace yasl
{

template<typename T, QMetaType::Type MT>
class GenericVariantHandler : public VariantHandler
{
public:
  GenericVariantHandler() = default;
  ~GenericVariantHandler() = default;

  script::Type script_type() const override { return script::make_type<T>(); }
  
  int qt_type() const override
  {
    /* We could also return qMetaTypeId<T>() */
    return MT; 
  }

  QVariant to_qvariant(const script::Value & v) override
  {
    return QVariant::fromValue<T>(script::value_cast<T>(v));
  }

  script::Value from_qvariant(script::Engine *e, const QVariant & v) override
  {
    return script::make_value(v.value<T>(), e);
  }
};

} // namespace yasl

#endif // YASL_COMMONS_GENERICVARIANTHANDLER_H
