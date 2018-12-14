// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_LIST_H
#define YASL_COMMONS_LIST_H

#include "yasl/common/types.h"

#include <QList>

namespace yasl
{
class Value;
} // namespace yasl

namespace script
{
template<> struct make_type_t<QList<int>> { inline static script::Type get() { return script::Type::QListint; } };
template<> struct make_type_t<QList<int>::iterator> { inline static script::Type get() { return script::Type::QListintIterator; } };
template<> struct make_type_t<QList<int>::const_iterator> { inline static script::Type get() { return script::Type::QListintConstIterator; } };
template<> struct make_type_t<QList<float>> { inline static script::Type get() { return script::Type::QListfloat; } };
template<> struct make_type_t<QList<float>::iterator> { inline static script::Type get() { return script::Type::QListfloatIterator; } };
template<> struct make_type_t<QList<float>::const_iterator> { inline static script::Type get() { return script::Type::QListfloatConstIterator; } };
template<> struct make_type_t<QList<double>> { inline static script::Type get() { return script::Type::QListdouble; } };
template<> struct make_type_t<QList<double>::iterator> { inline static script::Type get() { return script::Type::QListdoubleIterator; } };
template<> struct make_type_t<QList<double>::const_iterator> { inline static script::Type get() { return script::Type::QListdoubleConstIterator; } };

class Engine;
class Value;

script::Value make_list(const QList<yasl::Value> & val, const script::Type & list_type, script::Engine *e);

class Namespace;
void register_qlist_template(Namespace n);

} // namespace script

#endif // YASL_COMMONS_LIST_H
