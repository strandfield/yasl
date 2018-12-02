// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_TIMEZONE_H
#define YASL_CORE_TIMEZONE_H

#include "yasl/common/types.h"

#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
#include <QTimeZone>
#endif

namespace script {
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_t<QTimeZone> { inline static script::Type get() { return script::Type::QTimeZone; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_t<QTimeZone::NameType> { inline static script::Type get() { return script::Type::QTimeZoneNameType; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_t<QTimeZone::TimeType> { inline static script::Type get() { return script::Type::QTimeZoneTimeType; } };
#endif
} // namespace script

#endif // YASL_CORE_TIMEZONE_H
