// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PEN_H
#define YASL_GUI_PEN_H

#include "yasl/common/types.h"

#include <QPen>

namespace script {
template<> struct make_type_helper<QPen> { inline static script::Type get() { return script::Type::QPen; } };
} // namespace script

#endif // YASL_GUI_PEN_H
