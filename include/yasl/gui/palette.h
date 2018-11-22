// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PALETTE_H
#define YASL_GUI_PALETTE_H

#include "yasl/binding2/types.h"

#include <QPalette>

namespace script { namespace bind {
template<> struct make_type_t<QPalette> { inline static script::Type get() { return script::Type::QPalette; } };
template<> struct make_type_t<QPalette::ColorGroup> { inline static script::Type get() { return script::Type::QPaletteColorGroup; } };
template<> struct make_type_t<QPalette::ColorRole> { inline static script::Type get() { return script::Type::QPaletteColorRole; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_PALETTE_H
