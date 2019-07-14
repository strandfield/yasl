// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_DATETIME_H
#define YASL_CORE_DATETIME_H

#include "yasl/common/types.h"

#include <QDateTime>

namespace script {
template<> struct make_type_helper<QDate> { inline static script::Type get() { return script::Type::QDate; } };
template<> struct make_type_helper<QDate::MonthNameType> { inline static script::Type get() { return script::Type::QDateMonthNameType; } };
template<> struct make_type_helper<QDateTime> { inline static script::Type get() { return script::Type::QDateTime; } };
template<> struct make_type_helper<QTime> { inline static script::Type get() { return script::Type::QTime; } };
} // namespace script

#endif // YASL_CORE_DATETIME_H
