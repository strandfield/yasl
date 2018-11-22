// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_VECTOR2D_H
#define YASL_GUI_VECTOR2D_H

#include "yasl/binding2/types.h"

#include <QVector2D>

namespace script { namespace bind {
template<> struct make_type_t<QVector2D> { inline static script::Type get() { return script::Type::QVector2D; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_VECTOR2D_H
