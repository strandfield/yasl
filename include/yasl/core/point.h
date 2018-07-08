// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_POINT_H
#define YASL_CORE_POINT_H

#include "yasl/binding/utils.h"

#include <script/namespace.h>

#include <QPoint>

void register_qpoint(script::Namespace n);

namespace binding
{

template<> struct make_type_t<QPoint> { inline static script::Type get() { return script::Type::QPoint; } };

} // namespace binding

#endif // YASL_CORE_POINT_H
