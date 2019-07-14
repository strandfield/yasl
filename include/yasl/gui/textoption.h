// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_TEXTOPTION_H
#define YASL_GUI_TEXTOPTION_H

#include "yasl/common/types.h"

#include <QTextOption>

namespace script {
template<> struct make_type_helper<QTextOption> { inline static script::Type get() { return script::Type::QTextOption; } };
template<> struct make_type_helper<QTextOption::Flag> { inline static script::Type get() { return script::Type::QTextOptionFlag; } };
template<> struct make_type_helper<QTextOption::Flags> { inline static script::Type get() { return script::Type::QTextOptionFlags; } };
template<> struct make_type_helper<QTextOption::TabType> { inline static script::Type get() { return script::Type::QTextOptionTabType; } };
template<> struct make_type_helper<QTextOption::WrapMode> { inline static script::Type get() { return script::Type::QTextOptionWrapMode; } };
} // namespace script

#endif // YASL_GUI_TEXTOPTION_H
