// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsonvalue.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/jsonarray.h"
#include "yasl/core/jsonobject.h"
#include "yasl/core/jsonvalue.h"
#include "yasl/core/variant.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_json_value_type_enum(script::Class json_value)
{
  using namespace script;

  Enum type = json_value.newEnum("Type").setId(script::Type::QJsonValueType).get();

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

  Class json_value = ns.newClass("JsonValue").setId(script::Type::QJsonValue).get();

  register_json_value_type_enum(json_value);

  // QJsonValue(QJsonValue::Type = QJsonValue::Null);
  bind::constructor<QJsonValue, QJsonValue::Type>(json_value)
    .apply(bind::default_arguments(QJsonValue::Null)).create();
  // QJsonValue(bool);
  bind::constructor<QJsonValue, bool>(json_value).create();
  // QJsonValue(double);
  bind::constructor<QJsonValue, double>(json_value).create();
  // QJsonValue(int);
  bind::constructor<QJsonValue, int>(json_value).create();
  // QJsonValue(qint64);
  /// TODO: QJsonValue(qint64);
  // QJsonValue(const QString &);
  bind::constructor<QJsonValue, const QString &>(json_value).create();
  // QJsonValue(QLatin1String);
  /// TODO: QJsonValue(QLatin1String);
  // QJsonValue(const char *);
  /// TODO: QJsonValue(const char *);
  // QJsonValue(const QJsonArray &);
  bind::constructor<QJsonValue, const QJsonArray &>(json_value).create();
  // QJsonValue(const QJsonObject &);
  bind::constructor<QJsonValue, const QJsonObject &>(json_value).create();
  // ~QJsonValue();
  bind::destructor<QJsonValue>(json_value).create();
  // QJsonValue(const QJsonValue &);
  bind::constructor<QJsonValue, const QJsonValue &>(json_value).create();
  // QJsonValue & operator=(const QJsonValue &);
  bind::memop_assign<QJsonValue, const QJsonValue &>(json_value);
  // static QJsonValue fromVariant(const QVariant &);
  bind::static_member_function<QJsonValue, QJsonValue, const QVariant &, &QJsonValue::fromVariant>(json_value, "fromVariant").create();
  // QVariant toVariant() const;
  bind::member_function<QJsonValue, QVariant, &QJsonValue::toVariant>(json_value, "toVariant").create();
  // QJsonValue::Type type() const;
  bind::member_function<QJsonValue, QJsonValue::Type, &QJsonValue::type>(json_value, "type").create();
  // bool isNull() const;
  bind::member_function<QJsonValue, bool, &QJsonValue::isNull>(json_value, "isNull").create();
  // bool isBool() const;
  bind::member_function<QJsonValue, bool, &QJsonValue::isBool>(json_value, "isBool").create();
  // bool isDouble() const;
  bind::member_function<QJsonValue, bool, &QJsonValue::isDouble>(json_value, "isDouble").create();
  // bool isString() const;
  bind::member_function<QJsonValue, bool, &QJsonValue::isString>(json_value, "isString").create();
  // bool isArray() const;
  bind::member_function<QJsonValue, bool, &QJsonValue::isArray>(json_value, "isArray").create();
  // bool isObject() const;
  bind::member_function<QJsonValue, bool, &QJsonValue::isObject>(json_value, "isObject").create();
  // bool isUndefined() const;
  bind::member_function<QJsonValue, bool, &QJsonValue::isUndefined>(json_value, "isUndefined").create();
  // bool toBool(bool = false) const;
  bind::member_function<QJsonValue, bool, bool, &QJsonValue::toBool>(json_value, "toBool")
    .apply(bind::default_arguments(false)).create();
  // int toInt(int = 0) const;
  bind::member_function<QJsonValue, int, int, &QJsonValue::toInt>(json_value, "toInt")
    .apply(bind::default_arguments(0)).create();
  // double toDouble(double = double(0)) const;
  bind::member_function<QJsonValue, double, double, &QJsonValue::toDouble>(json_value, "toDouble")
    .apply(bind::default_arguments(double(0))).create();
  // QString toString() const;
  bind::member_function<QJsonValue, QString, &QJsonValue::toString>(json_value, "toString").create();
  // QString toString(const QString & = QString()) const;
  bind::member_function<QJsonValue, QString, const QString &, &QJsonValue::toString>(json_value, "toString")
    .apply(bind::default_arguments(QString())).create();
  // QJsonArray toArray() const;
  bind::member_function<QJsonValue, QJsonArray, &QJsonValue::toArray>(json_value, "toArray").create();
  // QJsonArray toArray(const QJsonArray & = QJsonArray()) const;
  bind::member_function<QJsonValue, QJsonArray, const QJsonArray &, &QJsonValue::toArray>(json_value, "toArray")
    .apply(bind::default_arguments(QJsonArray())).create();
  // QJsonObject toObject() const;
  bind::member_function<QJsonValue, QJsonObject, &QJsonValue::toObject>(json_value, "toObject").create();
  // QJsonObject toObject(const QJsonObject &) const;
  bind::member_function<QJsonValue, QJsonObject, const QJsonObject &, &QJsonValue::toObject>(json_value, "toObject").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // const QJsonValue operator[](const QString &) const;
  bind::memop_const_subscript<QJsonValue, const QJsonValue, const QString &>(json_value);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // const QJsonValue operator[](int) const;
  bind::memop_const_subscript<QJsonValue, const QJsonValue, int>(json_value);
#endif
  // bool operator==(const QJsonValue &) const;
  bind::memop_eq<QJsonValue, const QJsonValue &>(json_value);
  // bool operator!=(const QJsonValue &) const;
  bind::memop_neq<QJsonValue, const QJsonValue &>(json_value);

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QJsonValue, QMetaType::QJsonValue>>();
}


static void register_json_value_ref_class(script::Namespace ns)
{
  using namespace script;

  Class json_value_ref = ns.newClass("JsonValueRef").setId(script::Type::QJsonValueRef).get();


  // QJsonValueRef(QJsonArray *, int);
  /// TODO: QJsonValueRef(QJsonArray *, int);
  // QJsonValueRef(QJsonObject *, int);
  /// TODO: QJsonValueRef(QJsonObject *, int);
  // QJsonValueRef & operator=(const QJsonValue &);
  bind::memop_assign<QJsonValueRef, const QJsonValue &>(json_value_ref);
  // QJsonValueRef & operator=(const QJsonValueRef &);
  bind::memop_assign<QJsonValueRef, const QJsonValueRef &>(json_value_ref);
  // QVariant toVariant() const;
  bind::member_function<QJsonValueRef, QVariant, &QJsonValueRef::toVariant>(json_value_ref, "toVariant").create();
  // QJsonValue::Type type() const;
  bind::member_function<QJsonValueRef, QJsonValue::Type, &QJsonValueRef::type>(json_value_ref, "type").create();
  // bool isNull() const;
  bind::member_function<QJsonValueRef, bool, &QJsonValueRef::isNull>(json_value_ref, "isNull").create();
  // bool isBool() const;
  bind::member_function<QJsonValueRef, bool, &QJsonValueRef::isBool>(json_value_ref, "isBool").create();
  // bool isDouble() const;
  bind::member_function<QJsonValueRef, bool, &QJsonValueRef::isDouble>(json_value_ref, "isDouble").create();
  // bool isString() const;
  bind::member_function<QJsonValueRef, bool, &QJsonValueRef::isString>(json_value_ref, "isString").create();
  // bool isArray() const;
  bind::member_function<QJsonValueRef, bool, &QJsonValueRef::isArray>(json_value_ref, "isArray").create();
  // bool isObject() const;
  bind::member_function<QJsonValueRef, bool, &QJsonValueRef::isObject>(json_value_ref, "isObject").create();
  // bool isUndefined() const;
  bind::member_function<QJsonValueRef, bool, &QJsonValueRef::isUndefined>(json_value_ref, "isUndefined").create();
  // bool toBool() const;
  bind::member_function<QJsonValueRef, bool, &QJsonValueRef::toBool>(json_value_ref, "toBool").create();
  // int toInt() const;
  bind::member_function<QJsonValueRef, int, &QJsonValueRef::toInt>(json_value_ref, "toInt").create();
  // double toDouble() const;
  bind::member_function<QJsonValueRef, double, &QJsonValueRef::toDouble>(json_value_ref, "toDouble").create();
  // QString toString() const;
  bind::member_function<QJsonValueRef, QString, &QJsonValueRef::toString>(json_value_ref, "toString").create();
  // QJsonArray toArray() const;
  bind::member_function<QJsonValueRef, QJsonArray, &QJsonValueRef::toArray>(json_value_ref, "toArray").create();
  // QJsonObject toObject() const;
  bind::member_function<QJsonValueRef, QJsonObject, &QJsonValueRef::toObject>(json_value_ref, "toObject").create();
  // bool toBool(bool) const;
  bind::member_function<QJsonValueRef, bool, bool, &QJsonValueRef::toBool>(json_value_ref, "toBool").create();
  // int toInt(int) const;
  bind::member_function<QJsonValueRef, int, int, &QJsonValueRef::toInt>(json_value_ref, "toInt").create();
  // double toDouble(double) const;
  bind::member_function<QJsonValueRef, double, double, &QJsonValueRef::toDouble>(json_value_ref, "toDouble").create();
  // QString toString(const QString &) const;
  bind::member_function<QJsonValueRef, QString, const QString &, &QJsonValueRef::toString>(json_value_ref, "toString").create();
  // bool operator==(const QJsonValue &) const;
  bind::memop_eq<QJsonValueRef, const QJsonValue &>(json_value_ref);
  // bool operator!=(const QJsonValue &) const;
  bind::memop_neq<QJsonValueRef, const QJsonValue &>(json_value_ref);
}


void register_jsonvalue_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_value_class(ns);
  register_json_value_ref_class(ns);

  // QDebug operator<<(QDebug, const QJsonValue &);
  /// TODO: QDebug operator<<(QDebug, const QJsonValue &);
}

