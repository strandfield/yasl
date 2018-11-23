// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_INPUTDIALOG_H
#define YASL_WIDGETS_INPUTDIALOG_H

#include "yasl/binding/qobject-binding.h"
#include "yasl/binding/types.h"

#include <QInputDialog>

namespace script { namespace bind {
template<> struct make_type_t<QInputDialog> { inline static script::Type get() { return script::Type::QInputDialog; } };
template<> struct tag_resolver<QInputDialog> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QInputDialog::InputDialogOption> { inline static script::Type get() { return script::Type::QInputDialogInputDialogOption; } };
template<> struct make_type_t<QInputDialog::InputDialogOptions> { inline static script::Type get() { return script::Type::QInputDialogInputDialogOptions; } };
template<> struct make_type_t<QInputDialog::InputMode> { inline static script::Type get() { return script::Type::QInputDialogInputMode; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_INPUTDIALOG_H
