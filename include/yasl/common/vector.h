// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_VECTOR_H
#define YASL_COMMONS_VECTOR_H

#include "yasl/common/types.h"

#include <script/classtemplatenativebackend.h>

#include <QVector>

namespace script
{

template<> struct make_type_helper<QVector<int>> { inline static script::Type get() { return script::Type::QVectorInt; } };
template<> struct make_type_helper<QVector<float>> { inline static script::Type get() { return script::Type::QVectorFloat; } };
template<> struct make_type_helper<QVector<double>> { inline static script::Type get() { return script::Type::QVectorDouble; } };

class VectorTemplate : public ClassTemplateNativeBackend
{
  Class instantiate(ClassTemplateInstanceBuilder& builder) override;
};

} // namespace script

#endif // YASL_COMMONS_VECTOR_H
