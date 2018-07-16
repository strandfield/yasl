// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_VARIANT_H
#define YASL_CORE_VARIANT_H

#include "yasl/binding/types.h"

#include <QVariant>

namespace binding {
template<> struct make_type_t<QVariant> { inline static script::Type get() { return script::Type::QVariant; } };
template<> struct make_type_t<QVariant::Type> { inline static script::Type get() { return script::Type::QVariantType; } };
} // namespace binding

#endif // YASL_CORE_VARIANT_H
