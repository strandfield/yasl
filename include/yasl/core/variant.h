// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_VARIANT_H
#define YASL_CORE_VARIANT_H

#include "yasl/common/proxy.h"
#include "yasl/common/types.h"

#include <QVariant>

namespace script {
template<> struct make_type_helper<Proxy<QVariant>> { inline static script::Type get() { return script::Type::ProxyQVariant; } };
template<> struct make_type_helper<QList<QVariant>> { inline static script::Type get() { return script::Type::QListQVariant; } };
template<> struct make_type_helper<QList<QVariant>::const_iterator> { inline static script::Type get() { return script::Type::QListQVariantConstIterator; } };
template<> struct make_type_helper<QList<QVariant>::iterator> { inline static script::Type get() { return script::Type::QListQVariantIterator; } };
template<> struct make_type_helper<QMap<QString, QVariant>> { inline static script::Type get() { return script::Type::QMapQStringQVariant; } };
template<> struct make_type_helper<QMap<QString, QVariant>::const_iterator> { inline static script::Type get() { return script::Type::QMapQStringQVariantConstIterator; } };
template<> struct make_type_helper<QMap<QString, QVariant>::iterator> { inline static script::Type get() { return script::Type::QMapQStringQVariantIterator; } };
template<> struct make_type_helper<QVariant> { inline static script::Type get() { return script::Type::QVariant; } };
} // namespace script

#endif // YASL_CORE_VARIANT_H
