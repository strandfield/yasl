// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PAINTER_H
#define YASL_GUI_PAINTER_H

#include "yasl/common/types.h"

#include <QPainter>

namespace script {
template<> struct make_type_helper<QPainter> { inline static script::Type get() { return script::Type::QPainter; } };
template<> struct make_type_helper<QPainter::CompositionMode> { inline static script::Type get() { return script::Type::QPainterCompositionMode; } };
template<> struct make_type_helper<QPainter::PixmapFragmentHint> { inline static script::Type get() { return script::Type::QPainterPixmapFragmentHint; } };
template<> struct make_type_helper<QPainter::PixmapFragmentHints> { inline static script::Type get() { return script::Type::QPainterPixmapFragmentHints; } };
template<> struct make_type_helper<QPainter::RenderHint> { inline static script::Type get() { return script::Type::QPainterRenderHint; } };
template<> struct make_type_helper<QPainter::RenderHints> { inline static script::Type get() { return script::Type::QPainterRenderHints; } };
} // namespace script

#endif // YASL_GUI_PAINTER_H
