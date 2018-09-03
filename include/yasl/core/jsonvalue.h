// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_JSONVALUE_H
#define YASL_CORE_JSONVALUE_H

#include "yasl/binding/types.h"

#include <QJsonValue>

namespace binding {
template<> struct make_type_t<QJsonValue> { inline static script::Type get() { return script::Type::QJsonValue; } };
template<> struct make_type_t<QJsonValue::Type> { inline static script::Type get() { return script::Type::QJsonValueType; } };
template<> struct make_type_t<QJsonValueRef> { inline static script::Type get() { return script::Type::QJsonValueRef; } };
} // namespace binding

#endif // YASL_CORE_JSONVALUE_H