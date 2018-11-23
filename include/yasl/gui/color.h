// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_COLOR_H
#define YASL_GUI_COLOR_H

#include "yasl/binding/types.h"

#include <QColor>

namespace script { namespace bind {
template<> struct make_type_t<QColor> { inline static script::Type get() { return script::Type::QColor; } };
template<> struct make_type_t<QColor::NameFormat> { inline static script::Type get() { return script::Type::QColorNameFormat; } };
template<> struct make_type_t<QColor::Spec> { inline static script::Type get() { return script::Type::QColorSpec; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_GUI_COLOR_H
