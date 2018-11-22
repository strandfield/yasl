// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_PAINTER_H
#define YASL_GUI_PAINTER_H

#include "yasl/binding2/types.h"

#include <QPainter>

namespace script { namespace bind {
template<> struct make_type_t<QPainter> { inline static script::Type get() { return script::Type::QPainter; } };
template<> struct make_type_t<QPainter::CompositionMode> { inline static script::Type get() { return script::Type::QPainterCompositionMode; } };
template<> struct make_type_t<QPainter::PixmapFragmentHint> { inline static script::Type get() { return script::Type::QPainterPixmapFragmentHint; } };
template<> struct make_type_t<QPainter::PixmapFragmentHints> { inline static script::Type get() { return script::Type::QPainterPixmapFragmentHints; } };
template<> struct make_type_t<QPainter::RenderHint> { inline static script::Type get() { return script::Type::QPainterRenderHint; } };
template<> struct make_type_t<QPainter::RenderHints> { inline static script::Type get() { return script::Type::QPainterRenderHints; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_PAINTER_H
