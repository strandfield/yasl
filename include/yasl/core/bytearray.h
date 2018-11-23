// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_BYTEARRAY_H
#define YASL_CORE_BYTEARRAY_H

#include "yasl/binding/proxy.h"
#include "yasl/binding/types.h"

#include <QByteArray>

namespace script { namespace bind {
template<> struct make_type_t<Proxy<QByteArray>> { inline static script::Type get() { return script::Type::ProxyQByteArray; } };
template<> struct make_type_t<QByteArray> { inline static script::Type get() { return script::Type::QByteArray; } };
template<> struct make_type_t<QByteArray::Base64Option> { inline static script::Type get() { return script::Type::QByteArrayBase64Option; } };
template<> struct make_type_t<QByteArray::Base64Options> { inline static script::Type get() { return script::Type::QByteArrayBase64Options; } };
template<> struct make_type_t<QByteRef> { inline static script::Type get() { return script::Type::QByteRef; } };
template<> struct make_type_t<QList<QByteArray>> { inline static script::Type get() { return script::Type::QListQByteArray; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_BYTEARRAY_H
