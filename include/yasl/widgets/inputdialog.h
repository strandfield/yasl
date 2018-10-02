// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_INPUTDIALOG_H
#define YASL_WIDGETS_INPUTDIALOG_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QInputDialog>

namespace binding {
template<> struct make_type_t<QInputDialog> { inline static script::Type get() { return script::Type::QInputDialog; } };
template<> struct tag_resolver<QInputDialog> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QInputDialog::InputDialogOption> { inline static script::Type get() { return script::Type::QInputDialogInputDialogOption; } };
template<> struct make_type_t<QInputDialog::InputDialogOptions> { inline static script::Type get() { return script::Type::QInputDialogInputDialogOptions; } };
template<> struct make_type_t<QInputDialog::InputMode> { inline static script::Type get() { return script::Type::QInputDialogInputMode; } };
} // namespace binding

#endif // YASL_WIDGETS_INPUTDIALOG_H
