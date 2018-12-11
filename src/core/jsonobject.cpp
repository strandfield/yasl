// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsonobject.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/jsonobject.h"
#include "yasl/core/jsonvalue.h"

#include <script/classbuilder.h>

static void register_json_object_class(script::Namespace ns)
{
  using namespace script;

  Class json_object = ns.newClass("JsonObject").setId(script::Type::QJsonObject).get();


  // QJsonObject();
  bind::default_constructor<QJsonObject>(json_object).create();
  // QJsonObject(std::initializer_list<QPair<QString, QJsonValue> >);
  /// TODO: QJsonObject(std::initializer_list<QPair<QString, QJsonValue> >);
  // ~QJsonObject();
  bind::destructor<QJsonObject>(json_object).create();
  // QJsonObject(const QJsonObject &);
  bind::constructor<QJsonObject, const QJsonObject &>(json_object).create();
  // QJsonObject & operator=(const QJsonObject &);
  bind::memop_assign<QJsonObject, const QJsonObject &>(json_object);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // void swap(QJsonObject &);
  bind::void_member_function<QJsonObject, QJsonObject &, &QJsonObject::swap>(json_object, "swap").create();
#endif
  // static QJsonObject fromVariantMap(const QVariantMap &);
  /// TODO: static QJsonObject fromVariantMap(const QVariantMap &);
  // QVariantMap toVariantMap() const;
  /// TODO: QVariantMap toVariantMap() const;
  // static QJsonObject fromVariantHash(const QVariantHash &);
  /// TODO: static QJsonObject fromVariantHash(const QVariantHash &);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QVariantHash toVariantHash() const;
  /// TODO: QVariantHash toVariantHash() const;
#endif
  // QStringList keys() const;
  /// TODO: QStringList keys() const;
  // int size() const;
  bind::member_function<QJsonObject, int, &QJsonObject::size>(json_object, "size").create();
  // int count() const;
  bind::member_function<QJsonObject, int, &QJsonObject::count>(json_object, "count").create();
  // int length() const;
  bind::member_function<QJsonObject, int, &QJsonObject::length>(json_object, "length").create();
  // bool isEmpty() const;
  bind::member_function<QJsonObject, bool, &QJsonObject::isEmpty>(json_object, "isEmpty").create();
  // QJsonValue value(const QString &) const;
  bind::member_function<QJsonObject, QJsonValue, const QString &, &QJsonObject::value>(json_object, "value").create();
  // QJsonValue value(QLatin1String) const;
  /// TODO: QJsonValue value(QLatin1String) const;
  // QJsonValue operator[](const QString &) const;
  bind::memop_const_subscript<QJsonObject, QJsonValue, const QString &>(json_object);
  // QJsonValue operator[](QLatin1String) const;
  /// TODO: QJsonValue operator[](QLatin1String) const;
  // QJsonValueRef operator[](const QString &);
  bind::memop_subscript<QJsonObject, QJsonValueRef, const QString &>(json_object);
  // QJsonValueRef operator[](QLatin1String);
  /// TODO: QJsonValueRef operator[](QLatin1String);
  // void remove(const QString &);
  bind::void_member_function<QJsonObject, const QString &, &QJsonObject::remove>(json_object, "remove").create();
  // QJsonValue take(const QString &);
  bind::member_function<QJsonObject, QJsonValue, const QString &, &QJsonObject::take>(json_object, "take").create();
  // bool contains(const QString &) const;
  bind::member_function<QJsonObject, bool, const QString &, &QJsonObject::contains>(json_object, "contains").create();
  // bool contains(QLatin1String) const;
  /// TODO: bool contains(QLatin1String) const;
  // bool operator==(const QJsonObject &) const;
  bind::memop_eq<QJsonObject, const QJsonObject &>(json_object);
  // bool operator!=(const QJsonObject &) const;
  bind::memop_neq<QJsonObject, const QJsonObject &>(json_object);
  // QJsonObject::iterator begin();
  /// TODO: QJsonObject::iterator begin();
  // QJsonObject::const_iterator begin() const;
  /// TODO: QJsonObject::const_iterator begin() const;
  // QJsonObject::const_iterator constBegin() const;
  /// TODO: QJsonObject::const_iterator constBegin() const;
  // QJsonObject::iterator end();
  /// TODO: QJsonObject::iterator end();
  // QJsonObject::const_iterator end() const;
  /// TODO: QJsonObject::const_iterator end() const;
  // QJsonObject::const_iterator constEnd() const;
  /// TODO: QJsonObject::const_iterator constEnd() const;
  // QJsonObject::iterator erase(QJsonObject::iterator);
  /// TODO: QJsonObject::iterator erase(QJsonObject::iterator);
  // QJsonObject::iterator find(const QString &);
  /// TODO: QJsonObject::iterator find(const QString &);
  // QJsonObject::iterator find(QLatin1String);
  /// TODO: QJsonObject::iterator find(QLatin1String);
  // QJsonObject::const_iterator find(const QString &) const;
  /// TODO: QJsonObject::const_iterator find(const QString &) const;
  // QJsonObject::const_iterator find(QLatin1String) const;
  /// TODO: QJsonObject::const_iterator find(QLatin1String) const;
  // QJsonObject::const_iterator constFind(const QString &) const;
  /// TODO: QJsonObject::const_iterator constFind(const QString &) const;
  // QJsonObject::const_iterator constFind(QLatin1String) const;
  /// TODO: QJsonObject::const_iterator constFind(QLatin1String) const;
  // QJsonObject::iterator insert(const QString &, const QJsonValue &);
  /// TODO: QJsonObject::iterator insert(const QString &, const QJsonValue &);
  // bool empty() const;
  bind::member_function<QJsonObject, bool, &QJsonObject::empty>(json_object, "empty").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QJsonObject, QMetaType::QJsonObject>>();
}


void register_jsonobject_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_object_class(ns);

  // QDebug operator<<(QDebug, const QJsonObject &);
  /// TODO: QDebug operator<<(QDebug, const QJsonObject &);
}
