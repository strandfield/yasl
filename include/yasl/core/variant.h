// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_VARIANT_H
#define YASL_CORE_VARIANT_H

#include "yasl/common/proxy.h"
#include "yasl/common/types.h"

#include "yasl/core/qvariant-values.h"

namespace script {
template<> struct make_type_t<Proxy<QVariant>> { inline static script::Type get() { return script::Type::ProxyQVariant; } };
template<> struct make_type_t<QList<QVariant>> { inline static script::Type get() { return script::Type::QListQVariant; } };
template<> struct make_type_t<QMap<QString, QVariant>> { inline static script::Type get() { return script::Type::QMapQStringQVariant; } };
template<> struct make_type_t<QMap<QString, QVariant>::const_iterator> { inline static script::Type get() { return script::Type::QMapQStringQVariantConstIterator; } };
template<> struct make_type_t<QMap<QString, QVariant>::iterator> { inline static script::Type get() { return script::Type::QMapQStringQVariantIterator; } };
template<> struct make_type_t<QVariant> { inline static script::Type get() { return script::Type::QVariant; } };
template<> struct tag_resolver<QVariant> { typedef qvariant_tag tag_type; };
} // namespace script

#endif // YASL_CORE_VARIANT_H
