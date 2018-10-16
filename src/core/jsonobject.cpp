// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsonobject.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/jsonobject.h"
#include "yasl/core/jsonvalue.h"

#include <script/classbuilder.h>

static void register_json_object_class(script::Namespace ns)
{
  using namespace script;

  Class json_object = ns.Class("JsonObject").setId(script::Type::QJsonObject).get();

  binding::Class<QJsonObject> binder{ json_object };

  // QJsonObject();
  binder.ctors().add_default();
  // QJsonObject(std::initializer_list<QPair<QString, QJsonValue> >);
  /// TODO: QJsonObject(std::initializer_list<QPair<QString, QJsonValue> >);
  // ~QJsonObject();
  binder.add_dtor();
  // QJsonObject(const QJsonObject &);
  binder.ctors().ctor<const QJsonObject &>().create();
  // QJsonObject & operator=(const QJsonObject &);
  binder.operators().assign<const QJsonObject &>();
  // QJsonObject(QJsonObject &&);
  binder.ctors().ctor<QJsonObject &&>().create();
  // QJsonObject & operator=(QJsonObject &&);
  binder.operators().assign<QJsonObject &&>();
  // void swap(QJsonObject &);
  binder.void_fun<QJsonObject &, &QJsonObject::swap>("swap").create();
  // static QJsonObject fromVariantMap(const QVariantMap &);
  /// TODO: static QJsonObject fromVariantMap(const QVariantMap &);
  // QVariantMap toVariantMap() const;
  /// TODO: QVariantMap toVariantMap() const;
  // static QJsonObject fromVariantHash(const QVariantHash &);
  /// TODO: static QJsonObject fromVariantHash(const QVariantHash &);
  // QVariantHash toVariantHash() const;
  /// TODO: QVariantHash toVariantHash() const;
  // QStringList keys() const;
  /// TODO: QStringList keys() const;
  // int size() const;
  binder.fun<int, &QJsonObject::size>("size").create();
  // int count() const;
  binder.fun<int, &QJsonObject::count>("count").create();
  // int length() const;
  binder.fun<int, &QJsonObject::length>("length").create();
  // bool isEmpty() const;
  binder.fun<bool, &QJsonObject::isEmpty>("isEmpty").create();
  // QJsonValue value(const QString &) const;
  binder.fun<QJsonValue, const QString &, &QJsonObject::value>("value").create();
  // QJsonValue value(QLatin1String) const;
  /// TODO: QJsonValue value(QLatin1String) const;
  // QJsonValue operator[](const QString &) const;
  binder.operators().const_subscript<QJsonValue, const QString &>();
  // QJsonValue operator[](QLatin1String) const;
  /// TODO: QJsonValue operator[](QLatin1String) const;
  // QJsonValueRef operator[](const QString &);
  binder.operators().subscript<QJsonValueRef, const QString &>();
  // QJsonValueRef operator[](QLatin1String);
  /// TODO: QJsonValueRef operator[](QLatin1String);
  // void remove(const QString &);
  binder.void_fun<const QString &, &QJsonObject::remove>("remove").create();
  // QJsonValue take(const QString &);
  binder.fun<QJsonValue, const QString &, &QJsonObject::take>("take").create();
  // bool contains(const QString &) const;
  binder.fun<bool, const QString &, &QJsonObject::contains>("contains").create();
  // bool contains(QLatin1String) const;
  /// TODO: bool contains(QLatin1String) const;
  // bool operator==(const QJsonObject &) const;
  binder.operators().eq<const QJsonObject &>();
  // bool operator!=(const QJsonObject &) const;
  binder.operators().neq<const QJsonObject &>();
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
  binder.fun<bool, &QJsonObject::empty>("empty").create();
}


void register_jsonobject_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_object_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QJsonObject &, QJsonObject &);
  binder.void_fun<QJsonObject &, QJsonObject &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QJsonObject &);
  /// TODO: QDebug operator<<(QDebug, const QJsonObject &);
}

