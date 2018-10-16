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
  binder.ctors().ctor<const QJsonArray &>().create();
  // QJsonArray & operator=(const QJsonArray &);
  binder.operators().assign<const QJsonArray &>();
  // QJsonArray(QJsonArray &&);
  binder.ctors().ctor<QJsonArray &&>().create();
  // QJsonArray & operator=(QJsonArray &&);
  binder.operators().assign<QJsonArray &&>();
  // static QJsonArray fromStringList(const QStringList &);
  /// TODO: static QJsonArray fromStringList(const QStringList &);
  // static QJsonArray fromVariantList(const QVariantList &);
  /// TODO: static QJsonArray fromVariantList(const QVariantList &);
  // QVariantList toVariantList() const;
  /// TODO: QVariantList toVariantList() const;
  // int size() const;
  binder.fun<int, &QJsonArray::size>("size").create();
  // int count() const;
  binder.fun<int, &QJsonArray::count>("count").create();
  // bool isEmpty() const;
  binder.fun<bool, &QJsonArray::isEmpty>("isEmpty").create();
  // QJsonValue at(int) const;
  binder.fun<QJsonValue, int, &QJsonArray::at>("at").create();
  // QJsonValue first() const;
  binder.fun<QJsonValue, &QJsonArray::first>("first").create();
  // QJsonValue last() const;
  binder.fun<QJsonValue, &QJsonArray::last>("last").create();
  // void prepend(const QJsonValue &);
  binder.void_fun<const QJsonValue &, &QJsonArray::prepend>("prepend").create();
  // void append(const QJsonValue &);
  binder.void_fun<const QJsonValue &, &QJsonArray::append>("append").create();
  // void removeAt(int);
  binder.void_fun<int, &QJsonArray::removeAt>("removeAt").create();
  // QJsonValue takeAt(int);
  binder.fun<QJsonValue, int, &QJsonArray::takeAt>("takeAt").create();
  // void removeFirst();
  binder.void_fun<&QJsonArray::removeFirst>("removeFirst").create();
  // void removeLast();
  binder.void_fun<&QJsonArray::removeLast>("removeLast").create();
  // void insert(int, const QJsonValue &);
  binder.void_fun<int, const QJsonValue &, &QJsonArray::insert>("insert").create();
  // void replace(int, const QJsonValue &);
  binder.void_fun<int, const QJsonValue &, &QJsonArray::replace>("replace").create();
  // bool contains(const QJsonValue &) const;
  binder.fun<bool, const QJsonValue &, &QJsonArray::contains>("contains").create();
  // QJsonValueRef operator[](int);
  binder.operators().subscript<QJsonValueRef, int>();
  // QJsonValue operator[](int) const;
  binder.operators().const_subscript<QJsonValue, int>();
  // bool operator==(const QJsonArray &) const;
  binder.operators().eq<const QJsonArray &>();
  // bool operator!=(const QJsonArray &) const;
  binder.operators().neq<const QJsonArray &>();
  // void swap(QJsonArray &);
  binder.void_fun<QJsonArray &, &QJsonArray::swap>("swap").create();
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
  binder.void_fun<const QJsonValue &, &QJsonArray::push_back>("push_back").create();
  // void push_front(const QJsonValue &);
  binder.void_fun<const QJsonValue &, &QJsonArray::push_front>("push_front").create();
  // void pop_front();
  binder.void_fun<&QJsonArray::pop_front>("pop_front").create();
  // void pop_back();
  binder.void_fun<&QJsonArray::pop_back>("pop_back").create();
  // bool empty() const;
  binder.fun<bool, &QJsonArray::empty>("empty").create();
}


void register_jsonarray_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_array_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QJsonArray &, QJsonArray &);
  binder.void_fun<QJsonArray &, QJsonArray &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QJsonArray &);
  /// TODO: QDebug operator<<(QDebug, const QJsonArray &);
}

