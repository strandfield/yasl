// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_TRANSFORM_H
#define YASL_GUI_TRANSFORM_H

#include "yasl/binding/types.h"

#include <QTransform>

namespace binding {
template<> struct make_type_t<QTransform> { inline static script::Type get() { return script::Type::QTransform; } };
template<> struct make_type_t<QTransform::TransformationType> { inline static script::Type get() { return script::Type::QTransformTransformationType; } };
} // namespace binding

#endif // YASL_GUI_TRANSFORM_H
