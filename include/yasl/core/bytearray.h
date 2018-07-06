// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_BYTEARRAY_H
#define YASL_CORE_BYTEARRAY_H

#include "yasl/binding/utils.h"

#include "yasl/utils/ptr.h"

#include <script/namespace.h>

class QByteArray;

void register_qbytearray(script::Namespace n);
script::Type get_qbytearray_type();
script::Type get_ptr_bytearray_type();
script::Type get_list_bytearray_type();

namespace binding
{
//template<> inline script::Value make_value<QByteArray>(const QByteArray & ba, script::Engine *e) { return make_bytearray(ba, e); }
template<> struct make_type_t<QByteArray> { inline static script::Type get() { return get_qbytearray_type(); } };
template<> struct make_type_t<Ptr<QByteArray>> { inline static script::Type get() { return get_ptr_bytearray_type(); } };
template<> struct make_type_t<QList<QByteArray>> { inline static script::Type get() { return get_list_bytearray_type(); } };

} // namespace binding

#endif // YASL_CORE_BYTEARRAY_H
