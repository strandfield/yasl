// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FILEDIALOG_H
#define YASL_WIDGETS_FILEDIALOG_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QFileDialog>

namespace binding {
template<> struct make_type_t<QFileDialog> { inline static script::Type get() { return script::Type::QFileDialog; } };
template<> struct tag_resolver<QFileDialog> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QFileDialog::AcceptMode> { inline static script::Type get() { return script::Type::QFileDialogAcceptMode; } };
template<> struct make_type_t<QFileDialog::DialogLabel> { inline static script::Type get() { return script::Type::QFileDialogDialogLabel; } };
template<> struct make_type_t<QFileDialog::FileMode> { inline static script::Type get() { return script::Type::QFileDialogFileMode; } };
template<> struct make_type_t<QFileDialog::Option> { inline static script::Type get() { return script::Type::QFileDialogOption; } };
template<> struct make_type_t<QFileDialog::Options> { inline static script::Type get() { return script::Type::QFileDialogOptions; } };
template<> struct make_type_t<QFileDialog::ViewMode> { inline static script::Type get() { return script::Type::QFileDialogViewMode; } };
} // namespace binding

#endif // YASL_WIDGETS_FILEDIALOG_H
