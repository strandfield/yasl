// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsonvalue.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/jsonarray.h"
#include "yasl/core/jsonobject.h"
#include "yasl/core/jsonvalue.h"
#include "yasl/core/variant.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_json_value_type_enum(script::Class json_value)
{
  using namespace script;

  Enum type = json_value.Enum("Type").setId(script::Type::QJsonValueType).get();

  type.addValue("Null", QJsonValue::Null);
  type.addValue("Bool", QJsonValue::Bool);
  type.addValue("Double", QJsonValue::Double);
  type.addValue("String", QJsonValue::String);
  type.addValue("Array", QJsonValue::Array);
  type.addValue("Object", QJsonValue::Object);
  type.addValue("Undefined", QJsonValue::Undefined);
}


static void register_json_value_class(script::Namespace ns)
{
  using namespace script;

  Class json_value = ns.Class("JsonValue").setId(script::Type::QJsonValue).get();

  register_json_value_type_enum(json_value);
  binding::Class<QJsonValue> binder{ json_value };

  // QJsonValue(QJsonValue::Type);
  binder.ctors().add<QJsonValue::Type>();
  // QJsonValue(bool);
  binder.ctors().add<bool>();
  // QJsonValue(double);
  binder.ctors().add<double>();
  // QJsonValue(int);
  binder.ctors().add<int>();
  // QJsonValue(qint64);
  /// TODO: QJsonValue(qint64);
  // QJsonValue(const QString &);
  binder.ctors().add<const QString &>();
  // QJsonValue(QLatin1String);
  /// TODO: QJsonValue(QLatin1String);
  // QJsonValue(const char *);
  /// TODO: QJsonValue(const char *);
  // QJsonValue(const QJsonArray &);
  binder.ctors().add<const QJsonArray &>();
  // QJsonValue(const QJsonObject &);
  binder.ctors().add<const QJsonObject &>();
  // ~QJsonValue();
  binder.add_dtor();
  // QJsonValue(const QJsonValue &);
  binder.ctors().add<const QJsonValue &>();
  // QJsonValue & operator=(const QJsonValue &);
  binder.operators().assign<const QJsonValue &>();
  // QJsonValue(QJsonValue &&);
  binder.ctors().add<QJsonValue &&>();
  // QJsonValue & operator=(QJsonValue &&);
  binder.operators().assign<QJsonValue &&>();
  // void swap(QJsonValue &);
  binder.add_void_fun<QJsonValue &, &QJsonValue::swap>("swap");
  // static QJsonValue fromVariant(const QVariant &);
  binder.add_static<QJsonValue, const QVariant &, &QJsonValue::fromVariant>("fromVariant");
  // QVariant toVariant() const;
  binder.add_fun<QVariant, &QJsonValue::toVariant>("toVariant");
  // QJsonValue::Type type() const;
  binder.add_fun<QJsonValue::Type, &QJsonValue::type>("type");
  // bool isNull() const;
  binder.add_fun<bool, &QJsonValue::isNull>("isNull");
  // bool isBool() const;
  binder.add_fun<bool, &QJsonValue::isBool>("isBool");
  // bool isDouble() const;
  binder.add_fun<bool, &QJsonValue::isDouble>("isDouble");
  // bool isString() const;
  binder.add_fun<bool, &QJsonValue::isString>("isString");
  // bool isArray() const;
  binder.add_fun<bool, &QJsonValue::isArray>("isArray");
  // bool isObject() const;
  binder.add_fun<bool, &QJsonValue::isObject>("isObject");
  // bool isUndefined() const;
  binder.add_fun<bool, &QJsonValue::isUndefined>("isUndefined");
  // bool toBool(bool) const;
  binder.add_fun<bool, bool, &QJsonValue::toBool>("toBool");
  // int toInt(int) const;
  binder.add_fun<int, int, &QJsonValue::toInt>("toInt");
  // double toDouble(double) const;
  binder.add_fun<double, double, &QJsonValue::toDouble>("toDouble");
  // QString toString() const;
  binder.add_fun<QString, &QJsonValue::toString>("toString");
  // QString toString(const QString &) const;
  binder.add_fun<QString, const QString &, &QJsonValue::toString>("toString");
  // QJsonArray toArray() const;
  binder.add_fun<QJsonArray, &QJsonValue::toArray>("toArray");
  // QJsonArray toArray(const QJsonArray &) const;
  binder.add_fun<QJsonArray, const QJsonArray &, &QJsonValue::toArray>("toArray");
  // QJsonObject toObject() const;
  binder.add_fun<QJsonObject, &QJsonValue::toObject>("toObject");
  // QJsonObject toObject(const QJsonObject &) const;
  binder.add_fun<QJsonObject, const QJsonObject &, &QJsonValue::toObject>("toObject");
  // const QJsonValue operator[](const QString &) const;
  binder.operators().const_subscript<const QJsonValue, const QString &>();
  // const QJsonValue operator[](QLatin1String) const;
  /// TODO: const QJsonValue operator[](QLatin1String) const;
  // const QJsonValue operator[](int) const;
  binder.operators().const_subscript<const QJsonValue, int>();
  // bool operator==(const QJsonValue &) const;
  binder.operators().eq<const QJsonValue &>();
  // bool operator!=(const QJsonValue &) const;
  binder.operators().neq<const QJsonValue &>();
}


static void register_json_value_ref_class(script::Namespace ns)
{
  using namespace script;

  Class json_value_ref = ns.Class("JsonValueRef").setId(script::Type::QJsonValueRef).get();

  binding::Class<QJsonValueRef> binder{ json_value_ref };

  // QJsonValueRef(QJsonArray *, int);
  /// TODO: QJsonValueRef(QJsonArray *, int);
  // QJsonValueRef(QJsonObject *, int);
  /// TODO: QJsonValueRef(QJsonObject *, int);
  // QJsonValueRef & operator=(const QJsonValue &);
  binder.operators().assign<const QJsonValue &>();
  // QJsonValueRef & operator=(const QJsonValueRef &);
  binder.operators().assign<const QJsonValueRef &>();
  // QVariant toVariant() const;
  binder.add_fun<QVariant, &QJsonValueRef::toVariant>("toVariant");
  // QJsonValue::Type type() const;
  binder.add_fun<QJsonValue::Type, &QJsonValueRef::type>("type");
  // bool isNull() const;
  binder.add_fun<bool, &QJsonValueRef::isNull>("isNull");
  // bool isBool() const;
  binder.add_fun<bool, &QJsonValueRef::isBool>("isBool");
  // bool isDouble() const;
  binder.add_fun<bool, &QJsonValueRef::isDouble>("isDouble");
  // bool isString() const;
  binder.add_fun<bool, &QJsonValueRef::isString>("isString");
  // bool isArray() const;
  binder.add_fun<bool, &QJsonValueRef::isArray>("isArray");
  // bool isObject() const;
  binder.add_fun<bool, &QJsonValueRef::isObject>("isObject");
  // bool isUndefined() const;
  binder.add_fun<bool, &QJsonValueRef::isUndefined>("isUndefined");
  // bool toBool() const;
  binder.add_fun<bool, &QJsonValueRef::toBool>("toBool");
  // int toInt() const;
  binder.add_fun<int, &QJsonValueRef::toInt>("toInt");
  // double toDouble() const;
  binder.add_fun<double, &QJsonValueRef::toDouble>("toDouble");
  // QString toString() const;
  binder.add_fun<QString, &QJsonValueRef::toString>("toString");
  // QJsonArray toArray() const;
  binder.add_fun<QJsonArray, &QJsonValueRef::toArray>("toArray");
  // QJsonObject toObject() const;
  binder.add_fun<QJsonObject, &QJsonValueRef::toObject>("toObject");
  // bool toBool(bool) const;
  binder.add_fun<bool, bool, &QJsonValueRef::toBool>("toBool");
  // int toInt(int) const;
  binder.add_fun<int, int, &QJsonValueRef::toInt>("toInt");
  // double toDouble(double) const;
  binder.add_fun<double, double, &QJsonValueRef::toDouble>("toDouble");
  // QString toString(const QString &) const;
  binder.add_fun<QString, const QString &, &QJsonValueRef::toString>("toString");
  // bool operator==(const QJsonValue &) const;
  binder.operators().eq<const QJsonValue &>();
  // bool operator!=(const QJsonValue &) const;
  binder.operators().neq<const QJsonValue &>();
}


void register_jsonvalue_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_value_class(ns);
  register_json_value_ref_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QJsonValue &, QJsonValue &);
  binder.add_void_fun<QJsonValue &, QJsonValue &, &swap>("swap");
  // QDebug operator<<(QDebug, const QJsonValue &);
  /// TODO: QDebug operator<<(QDebug, const QJsonValue &);
}

