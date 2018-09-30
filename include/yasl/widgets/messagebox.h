// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_MESSAGEBOX_H
#define YASL_WIDGETS_MESSAGEBOX_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QMessageBox>

namespace binding {
template<> struct make_type_t<QMessageBox> { inline static script::Type get() { return script::Type::QMessageBox; } };
template<> struct tag_resolver<QMessageBox> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QMessageBox::ButtonRole> { inline static script::Type get() { return script::Type::QMessageBoxButtonRole; } };
template<> struct make_type_t<QMessageBox::Icon> { inline static script::Type get() { return script::Type::QMessageBoxIcon; } };
template<> struct make_type_t<QMessageBox::StandardButton> { inline static script::Type get() { return script::Type::QMessageBoxStandardButton; } };
template<> struct make_type_t<QMessageBox::StandardButtons> { inline static script::Type get() { return script::Type::QMessageBoxStandardButtons; } };
} // namespace binding

#endif // YASL_WIDGETS_MESSAGEBOX_H
