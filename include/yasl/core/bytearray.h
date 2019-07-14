// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_BYTEARRAY_H
#define YASL_CORE_BYTEARRAY_H

#include "yasl/common/proxy.h"
#include "yasl/common/types.h"

#include <QByteArray>
#include <QList>

namespace script {
template<> struct make_type_helper<Proxy<QByteArray>> { inline static script::Type get() { return script::Type::ProxyQByteArray; } };
template<> struct make_type_helper<QByteArray> { inline static script::Type get() { return script::Type::QByteArray; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_helper<QByteArray::Base64Option> { inline static script::Type get() { return script::Type::QByteArrayBase64Option; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_helper<QByteArray::Base64Options> { inline static script::Type get() { return script::Type::QByteArrayBase64Options; } };
#endif
template<> struct make_type_helper<QByteRef> { inline static script::Type get() { return script::Type::QByteRef; } };
template<> struct make_type_helper<QList<QByteArray>> { inline static script::Type get() { return script::Type::QListQByteArray; } };
template<> struct make_type_helper<QList<QByteArray>::const_iterator> { inline static script::Type get() { return script::Type::QListQByteArrayConstIterator; } };
template<> struct make_type_helper<QList<QByteArray>::iterator> { inline static script::Type get() { return script::Type::QListQByteArrayIterator; } };
} // namespace script

#endif // YASL_CORE_BYTEARRAY_H
