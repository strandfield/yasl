// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_VARIANTUTILS_H
#define YASL_COMMONS_VARIANTUTILS_H

#include <script/value.h>

#include <QVariant>

namespace yasl
{

class VariantHandler
{
public:
  virtual ~VariantHandler() = default;

  virtual script::Type script_type() const = 0;
  virtual int qt_type() const = 0;

  virtual QVariant to_qvariant(const script::Value & v) = 0;
  virtual script::Value from_qvariant(script::Engine *e, const QVariant & v) = 0;
};

void register_variant_handler(VariantHandler *handler);

template<typename T>
void registerVariantHandler()
{
  register_variant_handler(new T{});
}

QVariant make_qvariant(const script::Value & v);
script::Value get_variant_value(script::Engine *e, const QVariant & v);
script::Type get_variant_value_type(const QVariant & v);

void complete_variant_class(script::Engine *e);

} // namespace yasl

#endif // YASL_COMMONS_VARIANTUTILS_H
