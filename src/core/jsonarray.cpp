// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/jsonarray.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/namespace.h"

#include "yasl/core/jsonarray.h"
#include "yasl/core/jsonvalue.h"

#include <script/classbuilder.h>

static void register_json_array_class(script::Namespace ns)
{
  using namespace script;

  Class json_array = ns.newClass("JsonArray").setId(script::Type::QJsonArray).get();


  // QJsonArray();
  bind::default_constructor<QJsonArray>(json_array).create();
  // QJsonArray(std::initializer_list<QJsonValue>);
  /// TODO: QJsonArray(std::initializer_list<QJsonValue>);
  // ~QJsonArray();
  bind::destructor<QJsonArray>(json_array).create();
  // QJsonArray(const QJsonArray &);
  bind::constructor<QJsonArray, const QJsonArray &>(json_array).create();
  // QJsonArray & operator=(const QJsonArray &);
  bind::memop_assign<QJsonArray, const QJsonArray &>(json_array);
  // QJsonArray(QJsonArray &&);
  bind::constructor<QJsonArray, QJsonArray &&>(json_array).create();
  // QJsonArray & operator=(QJsonArray &&);
  bind::memop_assign<QJsonArray, QJsonArray &&>(json_array);
  // static QJsonArray fromStringList(const QStringList &);
  /// TODO: static QJsonArray fromStringList(const QStringList &);
  // static QJsonArray fromVariantList(const QVariantList &);
  /// TODO: static QJsonArray fromVariantList(const QVariantList &);
  // QVariantList toVariantList() const;
  /// TODO: QVariantList toVariantList() const;
  // int size() const;
  bind::member_function<QJsonArray, int, &QJsonArray::size>(json_array, "size").create();
  // int count() const;
  bind::member_function<QJsonArray, int, &QJsonArray::count>(json_array, "count").create();
  // bool isEmpty() const;
  bind::member_function<QJsonArray, bool, &QJsonArray::isEmpty>(json_array, "isEmpty").create();
  // QJsonValue at(int) const;
  bind::member_function<QJsonArray, QJsonValue, int, &QJsonArray::at>(json_array, "at").create();
  // QJsonValue first() const;
  bind::member_function<QJsonArray, QJsonValue, &QJsonArray::first>(json_array, "first").create();
  // QJsonValue last() const;
  bind::member_function<QJsonArray, QJsonValue, &QJsonArray::last>(json_array, "last").create();
  // void prepend(const QJsonValue &);
  bind::void_member_function<QJsonArray, const QJsonValue &, &QJsonArray::prepend>(json_array, "prepend").create();
  // void append(const QJsonValue &);
  bind::void_member_function<QJsonArray, const QJsonValue &, &QJsonArray::append>(json_array, "append").create();
  // void removeAt(int);
  bind::void_member_function<QJsonArray, int, &QJsonArray::removeAt>(json_array, "removeAt").create();
  // QJsonValue takeAt(int);
  bind::member_function<QJsonArray, QJsonValue, int, &QJsonArray::takeAt>(json_array, "takeAt").create();
  // void removeFirst();
  bind::void_member_function<QJsonArray, &QJsonArray::removeFirst>(json_array, "removeFirst").create();
  // void removeLast();
  bind::void_member_function<QJsonArray, &QJsonArray::removeLast>(json_array, "removeLast").create();
  // void insert(int, const QJsonValue &);
  bind::void_member_function<QJsonArray, int, const QJsonValue &, &QJsonArray::insert>(json_array, "insert").create();
  // void replace(int, const QJsonValue &);
  bind::void_member_function<QJsonArray, int, const QJsonValue &, &QJsonArray::replace>(json_array, "replace").create();
  // bool contains(const QJsonValue &) const;
  bind::member_function<QJsonArray, bool, const QJsonValue &, &QJsonArray::contains>(json_array, "contains").create();
  // QJsonValueRef operator[](int);
  bind::memop_subscript<QJsonArray, QJsonValueRef, int>(json_array);
  // QJsonValue operator[](int) const;
  bind::memop_const_subscript<QJsonArray, QJsonValue, int>(json_array);
  // bool operator==(const QJsonArray &) const;
  bind::memop_eq<QJsonArray, const QJsonArray &>(json_array);
  // bool operator!=(const QJsonArray &) const;
  bind::memop_neq<QJsonArray, const QJsonArray &>(json_array);
  // void swap(QJsonArray &);
  bind::void_member_function<QJsonArray, QJsonArray &, &QJsonArray::swap>(json_array, "swap").create();
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
  bind::memop_add<QJsonArray, QJsonArray, const QJsonValue &>(json_array);
  // QJsonArray & operator+=(const QJsonValue &);
  bind::memop_add_assign<QJsonArray, const QJsonValue &>(json_array);
  // void push_back(const QJsonValue &);
  bind::void_member_function<QJsonArray, const QJsonValue &, &QJsonArray::push_back>(json_array, "push_back").create();
  // void push_front(const QJsonValue &);
  bind::void_member_function<QJsonArray, const QJsonValue &, &QJsonArray::push_front>(json_array, "push_front").create();
  // void pop_front();
  bind::void_member_function<QJsonArray, &QJsonArray::pop_front>(json_array, "pop_front").create();
  // void pop_back();
  bind::void_member_function<QJsonArray, &QJsonArray::pop_back>(json_array, "pop_back").create();
  // bool empty() const;
  bind::member_function<QJsonArray, bool, &QJsonArray::empty>(json_array, "empty").create();
}


void register_jsonarray_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_json_array_class(ns);

  // void swap(QJsonArray &, QJsonArray &);
  bind::void_function<QJsonArray &, QJsonArray &, &swap>(ns, "swap").create();
  // QDebug operator<<(QDebug, const QJsonArray &);
  /// TODO: QDebug operator<<(QDebug, const QJsonArray &);
}

