// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_MARGINS_H
#define YASL_CORE_MARGINS_H

#include "yasl/binding/types.h"

#include <QMargins>

namespace script { namespace bind {
template<> struct make_type_t<QMargins> { inline static script::Type get() { return script::Type::QMargins; } };
template<> struct make_type_t<QMarginsF> { inline static script::Type get() { return script::Type::QMarginsF; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_MARGINS_H
