// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_MARGINS_H
#define YASL_CORE_MARGINS_H

#include "yasl/binding/utils.h"

#include <script/namespace.h>

#include <QMargins>

void register_qmargins(script::Namespace n);

namespace binding
{

template<> struct make_type_t<QMargins> { inline static script::Type get() { return script::Type::QMargins; } };

} // namespace binding

#endif // YASL_CORE_MARGINS_H
