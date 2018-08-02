// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_VECTOR_4D_H
#define YASL_GUI_VECTOR_4D_H

#include "yasl/binding/types.h"

#include <QVector4D>

namespace binding {
template<> struct make_type_t<QVector4D> { inline static script::Type get() { return script::Type::QVector4D; } };
} // namespace binding

#endif // YASL_GUI_VECTOR_4D_H
