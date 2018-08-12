// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_LIST_H
#define YASL_CORE_LIST_H

#include "yasl/binding/types.h"

#include <QList>

namespace binding
{

template<> struct make_type_t<QList<int>> { inline static script::Type get() { return script::Type::QListint; } };
template<> struct make_type_t<QList<float>> { inline static script::Type get() { return script::Type::QListfloat; } };
template<> struct make_type_t<QList<double>> { inline static script::Type get() { return script::Type::QListdouble; } };

} // namespace binding

#endif // YASL_CORE_LIST_H
