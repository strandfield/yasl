// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_SCREEN_H
#define YASL_GUI_SCREEN_H

#include "yasl/binding/types.h"

#include <QScreen>

namespace binding {
template<> struct make_type_t<QScreen> { inline static script::Type get() { return script::Type::QScreen; } };
} // namespace binding

#endif // YASL_GUI_SCREEN_H
