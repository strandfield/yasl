// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_DIALOG_H
#define YASL_WIDGETS_DIALOG_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QDialog>

namespace script {
template<> struct make_type_helper<QDialog> { inline static script::Type get() { return script::Type::QDialog; } };
template<> struct details::tag_resolver<QDialog> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QDialog::DialogCode> { inline static script::Type get() { return script::Type::QDialogDialogCode; } };
} // namespace script

#endif // YASL_WIDGETS_DIALOG_H
