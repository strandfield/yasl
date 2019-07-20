// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_INPUTDIALOG_H
#define YASL_WIDGETS_INPUTDIALOG_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QInputDialog>

namespace script {
template<> struct make_type_helper<QInputDialog> { inline static script::Type get() { return script::Type::QInputDialog; } };
namespace details { template<> struct tag_resolver<QInputDialog> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QInputDialog::InputDialogOption> { inline static script::Type get() { return script::Type::QInputDialogInputDialogOption; } };
template<> struct make_type_helper<QInputDialog::InputDialogOptions> { inline static script::Type get() { return script::Type::QInputDialogInputDialogOptions; } };
template<> struct make_type_helper<QInputDialog::InputMode> { inline static script::Type get() { return script::Type::QInputDialogInputMode; } };
} // namespace script

#endif // YASL_WIDGETS_INPUTDIALOG_H
