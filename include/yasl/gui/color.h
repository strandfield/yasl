// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_COLOR_H
#define YASL_GUI_COLOR_H

#include "yasl/common/types.h"

#include <QColor>

namespace script {
template<> struct make_type_t<QColor> { inline static script::Type get() { return script::Type::QColor; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_t<QColor::NameFormat> { inline static script::Type get() { return script::Type::QColorNameFormat; } };
#endif
template<> struct make_type_t<QColor::Spec> { inline static script::Type get() { return script::Type::QColorSpec; } };
} // namespace script

#endif // YASL_GUI_COLOR_H
