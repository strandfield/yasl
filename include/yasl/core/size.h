// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_SIZE_H
#define YASL_CORE_SIZE_H

#include "yasl/binding/utils.h"

#include <script/namespace.h>

#include <QSize>

void register_qsize(script::Namespace n);

namespace binding
{
template<> struct make_type_t<QSize> { inline static script::Type get() { return script::Type::QSize; } };
} // namespace binding

#endif // YASL_CORE_SIZE_H
