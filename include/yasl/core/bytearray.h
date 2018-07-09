// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_BYTEARRAY_H
#define YASL_CORE_BYTEARRAY_H

#include "yasl/binding/types.h"
#include "yasl/utils/ptr.h"

#include <QByteArray>

namespace binding
{
//template<> inline script::Value make_value<QByteArray>(const QByteArray & ba, script::Engine *e) { return make_bytearray(ba, e); }
template<> struct make_type_t<QByteArray> { inline static script::Type get() { return script::Type::QByteArray; } };
template<> struct make_type_t<Ptr<QByteArray>> { inline static script::Type get() { return script::Type::PtrQByteArray; } };
template<> struct make_type_t<QList<QByteArray>> { inline static script::Type get() { return script::Type::QListQByteArray; } };

} // namespace binding

#endif // YASL_CORE_BYTEARRAY_H
