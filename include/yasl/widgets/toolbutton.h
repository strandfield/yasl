// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_TOOLBUTTON_H
#define YASL_WIDGETS_TOOLBUTTON_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QToolButton>

namespace binding {
template<> struct make_type_t<QToolButton> { inline static script::Type get() { return script::Type::QToolButton; } };
template<> struct tag_resolver<QToolButton> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QToolButton::ToolButtonPopupMode> { inline static script::Type get() { return script::Type::QToolButtonToolButtonPopupMode; } };
} // namespace binding

#endif // YASL_WIDGETS_TOOLBUTTON_H
