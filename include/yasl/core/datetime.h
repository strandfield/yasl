// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_DATETIME_H
#define YASL_CORE_DATETIME_H

#include "yasl/binding/utils.h"

#include <script/namespace.h>

#include <QDateTime>

void register_datetime_class(script::Namespace n);
script::Type get_datetime_type();

namespace binding
{
template<> struct make_type_t<QDateTime> { inline static script::Type get() { return get_datetime_type(); } };
} // namespace binding

#endif // YASL_CORE_DATETIME_H
