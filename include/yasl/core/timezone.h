// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_TIMEZONE_H
#define YASL_CORE_TIMEZONE_H

#include "yasl/binding/utils.h"

#include <script/namespace.h>

#include <QTimeZone>

void register_timezone_class(script::Namespace n);
script::Type get_timezone_type();

script::Type get_name_type_type();
script::Type get_time_type_type();
script::Type get_anonymous_type();

namespace binding
{
template<> struct make_type_t<QTimeZone> { inline static script::Type get() { return get_timezone_type(); } };
template<> struct make_type_t<QTimeZone::NameType> { inline static script::Type get() { return get_name_type_type(); } };
template<> struct make_type_t<QTimeZone::TimeType> { inline static script::Type get() { return get_time_type_type(); } };
template<> struct make_type_t<decltype(QTimeZone::MinUtcOffsetSecs)> { inline static script::Type get() { return get_anonymous_type(); } };
} // namespace binding

#endif // YASL_CORE_TIMEZONE_H
