// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_OBJECT_H
#define YASL_CORE_OBJECT_H

#include "yasl/binding/values.h"
#include "yasl/utils/ptr.h"
#include "yasl/utils/ref.h"

class QObject;

script::Value make_object(script::Engine *e, script::Type object_type, QObject *value);

namespace callbacks
{

script::Value connect(script::FunctionCall *c);

} // namespace callbacks

namespace binding
{

template<> struct make_type_t<QObject*> { inline static script::Type get() { return script::Type::QObjectStar; } };
template<> struct make_type_t<QList<QObject*>> { inline static script::Type get() { return script::Type::QListQObject; } };
template<> struct make_type_t<Ptr<QObject*>> { inline static script::Type get() { return script::Type::PtrQObject; } };

template<> inline script::Value make_value(QObject *obj, script::Engine *e)
{
  return make_ref(e, script::Type::QObjectStar, obj);
}

template<> struct storage_type<QObject> { typedef QObject* type; };
template<> inline QObject* get<QObject>(const script::Value & val) { return val.toQObject(); }
template<> inline Ptr<QObject*> value_cast<Ptr<QObject*>>(const script::Value & v) { return static_cast<QObject**>(get_ptr(v)); }

} // namespace binding

#endif // YASL_CORE_OBJECT_H
