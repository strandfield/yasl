// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsonarray.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/jsonarray.h"
#include "yasl/core/jsonvalue.h"

#include <script/classbuilder.h>

static void register_json_array_class(script::Namespace ns)
{
  using namespace script;

  Class json_array = ns.Class("JsonArray").setId(script::Type::QJsonArray).get();

  binding::Class<QJsonArray> binder{ json_array };

  // QJsonArray();
  binder.ctors().add_default();
  // QJsonArray(std::initializer_list<QJsonValue>);
  /// TODO: QJsonArray(std::initializer_list<QJsonValue>);
  // ~QJsonArray();
  binder.add_dtor();
  // QJsonArray(const QJsonArray &);
  binder.ctors().add<const QJsonArray &>();
  // QJsonArray & operator=(const QJsonArray &);
  binder.operators().assign<const QJsonArray &>();
  // QJsonArray(QJsonArray &&);
  binder.ctors().add<QJsonArray &&>();
  // QJsonArray & operator=(QJsonArray &&);
  binder.operators().assign<QJsonArray &&>();
  // static QJsonArray fromStringList(const QStringList &);
  /// TODO: static QJsonArray fromStringList(const QStringList &);
  // static QJsonArray fromVariantList(const QVariantList &);
  /// TODO: static QJsonArray fromVariantList(const QVariantList &);
  // QVariantList toVariantList() const;
  /// TODO: QVariantList toVariantList() const;
  // int size() const;
  binder.add_fun<int, &QJsonArray::size>("size");
  // int count() const;
  binder.add_fun<int, &QJsonArray::count>("count");
  // bool isEmpty() const;
  binder.add_fun<bool, &QJsonArray::isEmpty>("isEmpty");
  // QJsonValue at(int) const;
  binder.add_fun<QJsonValue, int, &QJsonArray::at>("at");
  // QJsonValue first() const;
  binder.add_fun<QJsonValue, &QJsonArray::first>("first");
  // QJsonValue last() const;
  binder.add_fun<QJsonValue, &QJsonArray::last>("last");
  // void prepend(const QJsonValue &);
  binder.add_void_fun<const QJsonValue &, &QJsonArray::prepend>("prepend");
  // void append(const QJsonValue &);
  binder.add_void_fun<const QJsonValue &, &QJsonArray::append>("append");
  // void removeAt(int);
  binder.add_void_fun<int, &QJsonArray::removeAt>("removeAt");
  // QJsonValue takeAt(int);
  binder.add_fun<QJsonValue, int, &QJsonArray::takeAt>("takeAt");
  // void removeFirst();
  binder.add_void_fun<&QJsonArray::removeFirst>("removeFirst");
  // void removeLast();
  binder.add_void_fun<&QJsonArray::removeLast>("removeLast");
  // void insert(int, const QJsonValue &);
  binder.add_void_fun<int, const QJsonValue &, &QJsonArray::insert>("insert");
  // void replace(int, const QJsonValue &);
  binder.add_void_fun<int, const QJsonValue &, &QJsonArray::replace>("replace");
  // bool contains(const QJsonValue &) const;
  binder.add_fun<bool, const QJsonValue &, &QJsonArray::contains>("contains");
  // QJsonValueRef operator[](int);
  binder.operators().subscript<QJsonValueRef, int>();
  // QJsonValue operator[](int) const;
  binder.operators().const_subscript<QJsonValue, int>();
  // bool operator==(const QJsonArray &) const;
  binder.operators().eq<const QJsonArray &>();
  // bool operator!=(const QJsonArray &) const;
  binder.operators().neq<const QJsonArray &>();
  // void swap(QJsonArray &);
  binder.add_void_fun<QJsonArray &, &QJsonArray::swap>("swap");
  // QJsonArray::iterator begin();
  /// TODO: QJsonArray::iterator begin();
  // QJsonArray::const_iterator begin() const;
  /// TODO: QJsonArray::const_iterator begin() const;
  // QJsonArray::const_iterator constBegin() const;
  /// TODO: QJsonArray::const_iterator constBegin() const;
  // QJsonArray::iterator end();
  /// TODO: QJsonArray::iterator end();
  // QJsonArray::const_iterator end() const;
  /// TODO: QJsonArray::const_iterator end() const;
  // QJsonArray::const_iterator constEnd() const;
  /// TODO: QJsonArray::const_iterator constEnd() const;
  // QJsonArray::iterator insert(QJsonArray::iterator, const QJsonValue &);
  /// TODO: QJsonArray::iterator insert(QJsonArray::iterator, const QJsonValue &);
  // QJsonArray::iterator erase(QJsonArray::iterator);
  /// TODO: QJsonArray::iterator erase(QJsonArray::iterator);
  // QJsonArray operator+(const QJsonValue &) const;
  binder.operators().add<QJsonArray, const QJsonValue &>();
  // QJsonArray & operator+=(const QJsonValue &);
  binder.operators().add_assign<const QJsonValue &>();
  // void push_back(const QJsonValue &);
  binder.add_void_fun<const QJsonValue &, &QJsonArray::push_back>("push_back");
  // void push_front(const QJsonValue &);
  binder.add_void_fun<const QJsonValue &, &QJsonArray::push_front>("push_front");
  // void pop_front();
  binder.add_void_fun<&QJsonArray::pop_front>("pop_front");
  // void pop_back();
  binder.add_void_fun<&QJsonArray::pop_back>("pop_back");
  // bool empty() const;
  binder.add_fun<bool, &QJsonArray::empty>("empty");
}


void register_jsonarray_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_array_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QJsonArray &, QJsonArray &);
  binder.add_void_fun<QJsonArray &, QJsonArray &, &swap>("swap");
  // QDebug operator<<(QDebug, const QJsonArray &);
  /// TODO: QDebug operator<<(QDebug, const QJsonArray &);
}

