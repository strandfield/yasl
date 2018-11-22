// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_VECTOR_H
#define YASL_CORE_VECTOR_H

#include "yasl/binding2/types.h"

#include <QVector>

namespace script
{

namespace bind
{

template<> struct make_type_t<QVector<int>> { inline static script::Type get() { return script::Type::QVectorInt; } };
template<> struct make_type_t<QVector<float>> { inline static script::Type get() { return script::Type::QVectorFloat; } };
template<> struct make_type_t<QVector<double>> { inline static script::Type get() { return script::Type::QVectorDouble; } };

} // namespace bind
} // namespace script

#endif // YASL_CORE_VECTOR_H
