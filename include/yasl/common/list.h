// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_LIST_H
#define YASL_COMMONS_LIST_H

#include "yasl/common/types.h"

#include <QList>

namespace script
{
template<> struct make_type_t<QList<int>> { inline static script::Type get() { return script::Type::QListint; } };
template<> struct make_type_t<QList<float>> { inline static script::Type get() { return script::Type::QListfloat; } };
template<> struct make_type_t<QList<double>> { inline static script::Type get() { return script::Type::QListdouble; } };


class Namespace;
void register_qlist_template(Namespace n);

} // namespace script

#endif // YASL_COMMONS_LIST_H