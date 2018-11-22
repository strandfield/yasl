// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FONTDIALOG_H
#define YASL_WIDGETS_FONTDIALOG_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QFontDialog>

namespace script { namespace bind {
template<> struct make_type_t<QFontDialog> { inline static script::Type get() { return script::Type::QFontDialog; } };
template<> struct tag_resolver<QFontDialog> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QFontDialog::FontDialogOption> { inline static script::Type get() { return script::Type::QFontDialogFontDialogOption; } };
template<> struct make_type_t<QFontDialog::FontDialogOptions> { inline static script::Type get() { return script::Type::QFontDialogFontDialogOptions; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_FONTDIALOG_H
