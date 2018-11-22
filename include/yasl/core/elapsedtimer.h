// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_ELAPSEDTIMER_H
#define YASL_CORE_ELAPSEDTIMER_H

#include "yasl/binding2/types.h"

#include <QElapsedTimer>

namespace script { namespace bind {
template<> struct make_type_t<QElapsedTimer> { inline static script::Type get() { return script::Type::QElapsedTimer; } };
template<> struct make_type_t<QElapsedTimer::ClockType> { inline static script::Type get() { return script::Type::QElapsedTimerClockType; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_ELAPSEDTIMER_H
