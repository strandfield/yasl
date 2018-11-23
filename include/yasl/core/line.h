// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_LINE_H
#define YASL_CORE_LINE_H

#include "yasl/binding/types.h"

#include <QLine>

namespace script { namespace bind {
template<> struct make_type_t<QLine> { inline static script::Type get() { return script::Type::QLine; } };
template<> struct make_type_t<QLineF> { inline static script::Type get() { return script::Type::QLineF; } };
template<> struct make_type_t<QLineF::IntersectType> { inline static script::Type get() { return script::Type::QLineFIntersectType; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_LINE_H
