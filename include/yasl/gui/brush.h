// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_BRUSH_H
#define YASL_GUI_BRUSH_H

#include "yasl/binding/types.h"

#include <QBrush>

namespace binding {
template<> struct make_type_t<QBrush> { inline static script::Type get() { return script::Type::QBrush; } };
template<> struct make_type_t<QConicalGradient> { inline static script::Type get() { return script::Type::QConicalGradient; } };
template<> struct make_type_t<QGradient> { inline static script::Type get() { return script::Type::QGradient; } };
template<> struct make_type_t<QGradient::CoordinateMode> { inline static script::Type get() { return script::Type::QGradientCoordinateMode; } };
template<> struct make_type_t<QGradient::InterpolationMode> { inline static script::Type get() { return script::Type::QGradientInterpolationMode; } };
template<> struct make_type_t<QGradient::Spread> { inline static script::Type get() { return script::Type::QGradientSpread; } };
template<> struct make_type_t<QGradient::Type> { inline static script::Type get() { return script::Type::QGradientType; } };
template<> struct make_type_t<QLinearGradient> { inline static script::Type get() { return script::Type::QLinearGradient; } };
template<> struct make_type_t<QRadialGradient> { inline static script::Type get() { return script::Type::QRadialGradient; } };
} // namespace binding

#endif // YASL_GUI_BRUSH_H
