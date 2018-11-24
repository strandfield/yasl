// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_CLIPBOARD_H
#define YASL_GUI_CLIPBOARD_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QClipboard>

namespace script {
template<> struct make_type_t<QClipboard> { inline static script::Type get() { return script::Type::QClipboard; } };
template<> struct tag_resolver<QClipboard> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QClipboard::Mode> { inline static script::Type get() { return script::Type::QClipboardMode; } };
} // namespace script

#endif // YASL_GUI_CLIPBOARD_H
