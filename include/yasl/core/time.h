// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_TIME_H
#define YASL_CORE_TIME_H

#include "yasl/binding/utils.h"

#include <script/namespace.h>

#include <QTime>

void register_time_class(script::Namespace n);

namespace binding
{
template<> struct make_type_t<QTime> { inline static script::Type get() { return script::Type::QTime; } };
} // namespace binding

#endif // YASL_CORE_TIME_H
