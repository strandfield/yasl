// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_TEXTOPTION_H
#define YASL_GUI_TEXTOPTION_H

#include "yasl/binding/types.h"

#include <QTextOption>

namespace binding {
template<> struct make_type_t<QTextOption> { inline static script::Type get() { return script::Type::QTextOption; } };
template<> struct make_type_t<QTextOption::Flag> { inline static script::Type get() { return script::Type::QTextOptionFlag; } };
template<> struct make_type_t<QTextOption::Flags> { inline static script::Type get() { return script::Type::QTextOptionFlags; } };
template<> struct make_type_t<QTextOption::TabType> { inline static script::Type get() { return script::Type::QTextOptionTabType; } };
template<> struct make_type_t<QTextOption::WrapMode> { inline static script::Type get() { return script::Type::QTextOptionWrapMode; } };
} // namespace binding

#endif // YASL_GUI_TEXTOPTION_H
