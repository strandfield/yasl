// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_TIMER_H
#define YASL_CORE_TIMER_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QTimer>

namespace script {
template<> struct make_type_helper<QTimer> { inline static script::Type get() { return script::Type::QTimer; } };
template<> struct details::tag_resolver<QTimer> { typedef qobject_tag tag_type; };
} // namespace script

#endif // YASL_CORE_TIMER_H
