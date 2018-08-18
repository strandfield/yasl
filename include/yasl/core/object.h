// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_OBJECT_H
#define YASL_CORE_OBJECT_H

#include "yasl/binding/values.h"
#include "yasl/utils/ptr.h"
#include "yasl/utils/ref.h"

#include <QObject>

namespace callbacks
{

script::Value connect(script::FunctionCall *c);

} // namespace callbacks

namespace binding
{

template<> struct make_type_t<QObject*> { inline static script::Type get() { return script::Type::QObjectStar; } };
template<> struct make_type_t<QList<QObject*>> { inline static script::Type get() { return script::Type::QListQObject; } };
template<> struct make_type_t<Ptr<QObject*>> { inline static script::Type get() { return script::Type::PtrQObject; } };

static_assert(std::is_same<binding::storage_type<QObject>::type, QObject*>::value, "QObject must be stored as QObject*");

} // namespace binding

#endif // YASL_CORE_OBJECT_H
