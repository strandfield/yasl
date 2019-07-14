// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_MESSAGEBOX_H
#define YASL_WIDGETS_MESSAGEBOX_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QMessageBox>

namespace script {
template<> struct make_type_helper<QMessageBox> { inline static script::Type get() { return script::Type::QMessageBox; } };
template<> struct details::tag_resolver<QMessageBox> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QMessageBox::ButtonRole> { inline static script::Type get() { return script::Type::QMessageBoxButtonRole; } };
template<> struct make_type_helper<QMessageBox::Icon> { inline static script::Type get() { return script::Type::QMessageBoxIcon; } };
template<> struct make_type_helper<QMessageBox::StandardButton> { inline static script::Type get() { return script::Type::QMessageBoxStandardButton; } };
template<> struct make_type_helper<QMessageBox::StandardButtons> { inline static script::Type get() { return script::Type::QMessageBoxStandardButtons; } };
} // namespace script

#endif // YASL_WIDGETS_MESSAGEBOX_H
