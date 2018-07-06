// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_OBJECT_H
#define YASL_CORE_OBJECT_H

#include "yasl/binding/utils.h"
#include "yasl/utils/ptr.h"

#include <script/namespace.h>
#include <script/value.h>

class QObject;

void register_qobject(script::Namespace n);
QObject* get_qobject(const script::Value & val);
script::Type get_qobject_type();
script::Type get_ref_qobject_type();
script::Type get_ptr_qobject_type();
script::Type get_qlist_qobject_type();
script::Value make_object(script::Engine *e, script::Type object_type, QObject *value);

namespace callbacks
{

script::Value connect(script::FunctionCall *c);

} // namespace callbacks

namespace binding
{

template<> struct make_type_t<QObject*> { inline static script::Type get() { return get_ref_qobject_type(); } };
template<> struct make_type_t<QList<QObject*>> { inline static script::Type get() { return get_qlist_qobject_type(); } };
template<> struct make_type_t<Ptr<QObject*>> { inline static script::Type get() { return get_ptr_qobject_type(); } };

//template<> inline QObject* value_cast(const script::Value & val)
//{
//  return get_qobject(val);
//}

template<> inline script::Value make_value(QObject *obj, script::Engine *e)
{
  return make_object(e, get_qobject_type(), obj);
}

extern template QObject* value_cast(const script::Value & val);
template<> inline Ptr<QObject*> value_cast<Ptr<QObject*>>(const script::Value & v) { return static_cast<QObject**>(get_ptr(v)); }

} // namespace binding

#endif // YASL_CORE_OBJECT_H
