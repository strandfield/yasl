// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_GLYPH_RUN_H
#define YASL_GUI_GLYPH_RUN_H

#include "yasl/binding/types.h"

#include <QGlyphRun>

namespace binding {
template<> struct make_type_t<QGlyphRun> { inline static script::Type get() { return script::Type::QGlyphRun; } };
template<> struct make_type_t<QGlyphRun::GlyphRunFlag> { inline static script::Type get() { return script::Type::QGlyphRunGlyphRunFlag; } };
} // namespace binding

#endif // YASL_GUI_GLYPH_RUN_H
