// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_RECT_H
#define YASL_CORE_RECT_H

#include "yasl/common/types.h"

#include <QRect>

namespace script {
template<> struct make_type_t<QRect> { inline static script::Type get() { return script::Type::QRect; } };
template<> struct make_type_t<QRectF> { inline static script::Type get() { return script::Type::QRectF; } };
} // namespace script

#endif // YASL_CORE_RECT_H
