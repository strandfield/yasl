// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_DIALOG_H
#define YASL_WIDGETS_DIALOG_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QDialog>

namespace script { namespace bind {
template<> struct make_type_t<QDialog> { inline static script::Type get() { return script::Type::QDialog; } };
template<> struct tag_resolver<QDialog> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QDialog::DialogCode> { inline static script::Type get() { return script::Type::QDialogDialogCode; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_DIALOG_H
