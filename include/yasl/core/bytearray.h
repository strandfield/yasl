// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_BYTEARRAY_H
#define YASL_CORE_BYTEARRAY_H

#include "yasl/common/proxy.h"
#include "yasl/common/types.h"

#include <QByteArray>

namespace script {
template<> struct make_type_t<Proxy<QByteArray>> { inline static script::Type get() { return script::Type::ProxyQByteArray; } };
template<> struct make_type_t<QByteArray> { inline static script::Type get() { return script::Type::QByteArray; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_t<QByteArray::Base64Option> { inline static script::Type get() { return script::Type::QByteArrayBase64Option; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_t<QByteArray::Base64Options> { inline static script::Type get() { return script::Type::QByteArrayBase64Options; } };
#endif
template<> struct make_type_t<QByteRef> { inline static script::Type get() { return script::Type::QByteRef; } };
template<> struct make_type_t<QList<QByteArray>> { inline static script::Type get() { return script::Type::QListQByteArray; } };
} // namespace script

#endif // YASL_CORE_BYTEARRAY_H
