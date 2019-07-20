// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_FILEDIALOG_H
#define YASL_WIDGETS_FILEDIALOG_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QFileDialog>

namespace script {
template<> struct make_type_helper<QFileDialog> { inline static script::Type get() { return script::Type::QFileDialog; } };
namespace details { template<> struct tag_resolver<QFileDialog> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QFileDialog::AcceptMode> { inline static script::Type get() { return script::Type::QFileDialogAcceptMode; } };
template<> struct make_type_helper<QFileDialog::DialogLabel> { inline static script::Type get() { return script::Type::QFileDialogDialogLabel; } };
template<> struct make_type_helper<QFileDialog::FileMode> { inline static script::Type get() { return script::Type::QFileDialogFileMode; } };
template<> struct make_type_helper<QFileDialog::Option> { inline static script::Type get() { return script::Type::QFileDialogOption; } };
template<> struct make_type_helper<QFileDialog::Options> { inline static script::Type get() { return script::Type::QFileDialogOptions; } };
template<> struct make_type_helper<QFileDialog::ViewMode> { inline static script::Type get() { return script::Type::QFileDialogViewMode; } };
} // namespace script

#endif // YASL_WIDGETS_FILEDIALOG_H
