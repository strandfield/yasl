// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FONTDIALOG_H
#define YASL_WIDGETS_FONTDIALOG_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QFontDialog>

namespace script {
template<> struct make_type_helper<QFontDialog> { inline static script::Type get() { return script::Type::QFontDialog; } };
namespace details { template<> struct tag_resolver<QFontDialog> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QFontDialog::FontDialogOption> { inline static script::Type get() { return script::Type::QFontDialogFontDialogOption; } };
template<> struct make_type_helper<QFontDialog::FontDialogOptions> { inline static script::Type get() { return script::Type::QFontDialogFontDialogOptions; } };
} // namespace script

#endif // YASL_WIDGETS_FONTDIALOG_H
