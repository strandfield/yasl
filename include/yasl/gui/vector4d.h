// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_VECTOR4D_H
#define YASL_GUI_VECTOR4D_H

#include "yasl/common/types.h"

#include <QVector4D>

namespace script {
template<> struct make_type_helper<QVector4D> { inline static script::Type get() { return script::Type::QVector4D; } };
} // namespace script

#endif // YASL_GUI_VECTOR4D_H
