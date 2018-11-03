// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsonvalue.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
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
  binding::ClassBinder<QJsonValue> binder{ json_value };

  // QJsonValue(QJsonValue::Type);
  binder.ctor<QJsonValue::Type>()
    .apply(binding::default_arguments(QJsonValue::Null)).create();
  // QJsonValue(bool);
  binder.ctor<bool>().create();
  // QJsonValue(double);
  binder.ctor<double>().create();
  // QJsonValue(int);
  binder.ctor<int>().create();
  // QJsonValue(qint64);
  /// TODO: QJsonValue(qint64);
  // QJsonValue(const QString &);
  binder.ctor<const QString &>().create();
  // QJsonValue(QLatin1String);
  /// TODO: QJsonValue(QLatin1String);
  // QJsonValue(const char *);
  /// TODO: QJsonValue(const char *);
  // QJsonValue(const QJsonArray &);
  binder.ctor<const QJsonArray &>().create();
  // QJsonValue(const QJsonObject &);
  binder.ctor<const QJsonObject &>().create();
  // ~QJsonValue();
  binder.dtor().create();
  // QJsonValue(const QJsonValue &);
  binder.ctor<const QJsonValue &>().create();
  // QJsonValue & operator=(const QJsonValue &);
  binder.operators().assign<const QJsonValue &>();
  // QJsonValue(QJsonValue &&);
  binder.ctor<QJsonValue &&>().create();
  // QJsonValue & operator=(QJsonValue &&);
  binder.operators().assign<QJsonValue &&>();
  // void swap(QJsonValue &);
  binder.void_fun<QJsonValue &, &QJsonValue::swap>("swap").create();
  // static QJsonValue fromVariant(const QVariant &);
  binder.static_fun<QJsonValue, const QVariant &, &QJsonValue::fromVariant>("fromVariant").create();
  // QVariant toVariant() const;
  binder.fun<QVariant, &QJsonValue::toVariant>("toVariant").create();
  // QJsonValue::Type type() const;
  binder.fun<QJsonValue::Type, &QJsonValue::type>("type").create();
  // bool isNull() const;
  binder.fun<bool, &QJsonValue::isNull>("isNull").create();
  // bool isBool() const;
  binder.fun<bool, &QJsonValue::isBool>("isBool").create();
  // bool isDouble() const;
  binder.fun<bool, &QJsonValue::isDouble>("isDouble").create();
  // bool isString() const;
  binder.fun<bool, &QJsonValue::isString>("isString").create();
  // bool isArray() const;
  binder.fun<bool, &QJsonValue::isArray>("isArray").create();
  // bool isObject() const;
  binder.fun<bool, &QJsonValue::isObject>("isObject").create();
  // bool isUndefined() const;
  binder.fun<bool, &QJsonValue::isUndefined>("isUndefined").create();
  // bool toBool(bool) const;
  binder.fun<bool, bool, &QJsonValue::toBool>("toBool")
    .apply(binding::default_arguments(false)).create();
  // int toInt(int) const;
  binder.fun<int, int, &QJsonValue::toInt>("toInt")
    .apply(binding::default_arguments(0)).create();
  // double toDouble(double) const;
  binder.fun<double, double, &QJsonValue::toDouble>("toDouble")
    .apply(binding::default_arguments(double(0))).create();
  // QString toString() const;
  binder.fun<QString, &QJsonValue::toString>("toString").create();
  // QString toString(const QString &) const;
  binder.fun<QString, const QString &, &QJsonValue::toString>("toString")
    .apply(binding::default_arguments(QString())).create();
  // QJsonArray toArray() const;
  binder.fun<QJsonArray, &QJsonValue::toArray>("toArray").create();
  // QJsonArray toArray(const QJsonArray &) const;
  binder.fun<QJsonArray, const QJsonArray &, &QJsonValue::toArray>("toArray")
    .apply(binding::default_arguments(QJsonArray())).create();
  // QJsonObject toObject() const;
  binder.fun<QJsonObject, &QJsonValue::toObject>("toObject").create();
  // QJsonObject toObject(const QJsonObject &) const;
  binder.fun<QJsonObject, const QJsonObject &, &QJsonValue::toObject>("toObject").create();
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

  binding::ClassBinder<QJsonValueRef> binder{ json_value_ref };

  // QJsonValueRef(QJsonArray *, int);
  /// TODO: QJsonValueRef(QJsonArray *, int);
  // QJsonValueRef(QJsonObject *, int);
  /// TODO: QJsonValueRef(QJsonObject *, int);
  // QJsonValueRef & operator=(const QJsonValue &);
  binder.operators().assign<const QJsonValue &>();
  // QJsonValueRef & operator=(const QJsonValueRef &);
  binder.operators().assign<const QJsonValueRef &>();
  // QVariant toVariant() const;
  binder.fun<QVariant, &QJsonValueRef::toVariant>("toVariant").create();
  // QJsonValue::Type type() const;
  binder.fun<QJsonValue::Type, &QJsonValueRef::type>("type").create();
  // bool isNull() const;
  binder.fun<bool, &QJsonValueRef::isNull>("isNull").create();
  // bool isBool() const;
  binder.fun<bool, &QJsonValueRef::isBool>("isBool").create();
  // bool isDouble() const;
  binder.fun<bool, &QJsonValueRef::isDouble>("isDouble").create();
  // bool isString() const;
  binder.fun<bool, &QJsonValueRef::isString>("isString").create();
  // bool isArray() const;
  binder.fun<bool, &QJsonValueRef::isArray>("isArray").create();
  // bool isObject() const;
  binder.fun<bool, &QJsonValueRef::isObject>("isObject").create();
  // bool isUndefined() const;
  binder.fun<bool, &QJsonValueRef::isUndefined>("isUndefined").create();
  // bool toBool() const;
  binder.fun<bool, &QJsonValueRef::toBool>("toBool").create();
  // int toInt() const;
  binder.fun<int, &QJsonValueRef::toInt>("toInt").create();
  // double toDouble() const;
  binder.fun<double, &QJsonValueRef::toDouble>("toDouble").create();
  // QString toString() const;
  binder.fun<QString, &QJsonValueRef::toString>("toString").create();
  // QJsonArray toArray() const;
  binder.fun<QJsonArray, &QJsonValueRef::toArray>("toArray").create();
  // QJsonObject toObject() const;
  binder.fun<QJsonObject, &QJsonValueRef::toObject>("toObject").create();
  // bool toBool(bool) const;
  binder.fun<bool, bool, &QJsonValueRef::toBool>("toBool").create();
  // int toInt(int) const;
  binder.fun<int, int, &QJsonValueRef::toInt>("toInt").create();
  // double toDouble(double) const;
  binder.fun<double, double, &QJsonValueRef::toDouble>("toDouble").create();
  // QString toString(const QString &) const;
  binder.fun<QString, const QString &, &QJsonValueRef::toString>("toString").create();
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
  binder.void_fun<QJsonValue &, QJsonValue &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QJsonValue &);
  /// TODO: QDebug operator<<(QDebug, const QJsonValue &);
}

