// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_RECT_H
#define YASL_CORE_RECT_H

#include "yasl/binding/types.h"

#include <script/namespace.h>

#include <QRect>

void register_qrect(script::Namespace n);

namespace binding
{

template<> struct make_type_t<QRect> { inline static script::Type get() { return script::Type::QRect; } };

} // namespace binding

#endif // YASL_CORE_RECT_H
