// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_TIMEZONE_H
#define YASL_CORE_TIMEZONE_H

#include "yasl/binding/types.h"

#include <QTimeZone>

namespace script { namespace bind {
template<> struct make_type_t<QTimeZone> { inline static script::Type get() { return script::Type::QTimeZone; } };
template<> struct make_type_t<QTimeZone::NameType> { inline static script::Type get() { return script::Type::QTimeZoneNameType; } };
template<> struct make_type_t<QTimeZone::TimeType> { inline static script::Type get() { return script::Type::QTimeZoneTimeType; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_TIMEZONE_H
