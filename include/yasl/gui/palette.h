// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PALETTE_H
#define YASL_GUI_PALETTE_H

#include "yasl/common/types.h"

#include <QPalette>

namespace script {
template<> struct make_type_helper<QPalette> { inline static script::Type get() { return script::Type::QPalette; } };
template<> struct make_type_helper<QPalette::ColorGroup> { inline static script::Type get() { return script::Type::QPaletteColorGroup; } };
template<> struct make_type_helper<QPalette::ColorRole> { inline static script::Type get() { return script::Type::QPaletteColorRole; } };
} // namespace script

#endif // YASL_GUI_PALETTE_H
