// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_TIMER_H
#define YASL_CORE_TIMER_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QTimer>

namespace binding {
template<> struct make_type_t<QTimer> { inline static script::Type get() { return script::Type::QTimer; } };
template<> struct tag_resolver<QTimer> { typedef qobject_tag tag_type; };
} // namespace binding

#endif // YASL_CORE_TIMER_H
