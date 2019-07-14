// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_VECTOR_SPECIALIZATIONS_H
#define YASL_COMMONS_VECTOR_SPECIALIZATIONS_H

#include "yasl/common/vector.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/common/proxy.h"

#include <script/classtemplatespecializationbuilder.h>
#include <script/namespace.h>
#include <script/userdata.h>
#include <script/interpreter/executioncontext.h>

namespace callbacks
{

namespace vector
{

template<typename T>
script::Value back(script::FunctionCall *c)
{
  QVector<T> & self = script::value_cast<QVector<T> &>(c->thisObject());
  return c->engine()->newPtr(c->callee().returnType(), &self.back());
}

template<typename T>
script::Value first(script::FunctionCall *c)
{
  QVector<T> & self = script::value_cast<QVector<T> &>(c->thisObject());
  return c->engine()->newPtr(c->callee().returnType(), &self.first());
}

template<typename T>
script::Value subscript(script::FunctionCall *c)
{
  QVector<T> & self = script::value_cast<QVector<T> &>(c->thisObject());
  const int index = c->arg(1).toInt();
  return c->engine()->newPtr(c->callee().returnType(), &self[index]);
}

} // namespace list

} // namespace callbacks


template<typename T>
void register_vector_specialization(script::ClassTemplate vector_template, script::Type::BuiltInType type_id)
{
  using namespace script;

  Class vector = vector_template.engine()->typeSystem()->getClass(type_id);
  if (!vector.isNull() && vector.id() == type_id)
    return;

  std::vector<TemplateArgument> targs{
    TemplateArgument{ script::make_type<T>() }
  };

  vector = vector_template.Specialization(std::move(targs))
    .setId(type_id)
    .setFinal()
    .get();

  // QVector();
  bind::default_constructor<QVector<T>>(vector).create();
  // QVector(int size);
  bind::constructor<QVector<T>, int>(vector).create();
  // QVector(int size, const T &value);
  bind::constructor<QVector<T>, int, const T &>(vector).create();
  // QVector(const QVector<T> &other);
  bind::copy_constructor<QVector<T>>(vector).create();
  /// TODO: QVector(QVector<T> &&other);
  /// TODO: QVector(std::initializer_list<T> args);
  // ~QVector();
  bind::destructor<QVector<T>>(vector).create();

  // void append(const T &value);
  bind::void_member_function<QVector<T>, const T &, &QVector<T>::append>(vector, "append").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: void append(T &&value);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
  // void append(const QVector<T> &value);
  bind::void_member_function<QVector<T>, const QVector<T> &, &QVector<T>::append>(vector, "append").create();
#endif
  // const T & at(int i) const;
  bind::member_function<QVector<T>, const T &, int, &QVector<T>::at>(vector, "at").create();
  // QVector::reference back();
  vector.newMethod("back", callbacks::vector::back<T>)
    .returns(script::make_type<Proxy<T>>())
    .create();
  // QVector::const_reference back() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::back>(vector, "back").create();
  /// TODO: QVector::iterator begin();
  /// TODO: QVector::const_iterator begin() const;
  // int capacity() const;
  bind::member_function<QVector<T>, int, &QVector<T>::capacity>(vector, "capacity").create();
  /// TODO: QVector::const_iterator cbegin() const;
  /// TODO: QVector::const_iterator cend() const;
  // void clear();
  bind::void_member_function<QVector<T>, &QVector<T>::clear>(vector, "clear").create();
  /// TODO: QVector::const_iterator constBegin() const;
  /// ignore: const T * constData() const;
  /// TODO: QVector::const_iterator constEnd() const;
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  // const T & constFirst() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::constFirst>(vector, "constFirst").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  // const T & constLast() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::constLast>(vector, "constLast").create();
#endif
  // bool contains(const T &value) const;
  bind::member_function<QVector<T>, bool, const T &, &QVector<T>::contains>(vector, "contains").create();
  // int count(const T &value) const;
  bind::member_function<QVector<T>, int, const T &, &QVector<T>::count>(vector, "count").create();
  // int count() const;
  bind::member_function<QVector<T>, int, &QVector<T>::count>(vector, "count").create();
  /// TODO: QVector::const_reverse_iterator crbegin() const;
  /// TODO: QVector::const_reverse_iterator crend() const;
  /// ignore: T * data();
  /// ignore: const T * data() const;
  // bool empty() const;
  bind::member_function<QVector<T>, bool, &QVector<T>::empty>(vector, "empty").create();
  /// TODO: QVector::iterator end();
  /// TODO: QVector::const_iterator end() const;
  // bool endsWith(const T &value) const;
  bind::member_function<QVector<T>, bool, const T &, &QVector<T>::endsWith>(vector, "endsWith").create();
  /// TODO: QVector::iterator erase(QVector::iterator pos);
  /// TODO; QVector::iterator erase(QVector::iterator begin, QVector::iterator end);
  // QVector<T> & fill(const T &value, int size = ...);
  bind::chainable_memfn<QVector<T>, const T&, int, &QVector<T>::fill>(vector, "fill")
    .apply(bind::default_arguments(-1)).create();
  // T & first();
  vector.newMethod("first", callbacks::vector::first<T>)
    .returns(script::make_type<Proxy<T>>())
    .create();
  // const T & first() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::first>(vector, "first");
  // T & front();
  vector.newMethod("front", callbacks::vector::first<T>)
    .returns(script::make_type<Proxy<T>>())
    .create();
  // QVector::const_reference front() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::front>(vector, "front").create();
  // int indexOf(const T &value, int from = ...) const;
  bind::member_function<QVector<T>, int, const T&, int, &QVector<T>::indexOf>(vector, "indexOf")
    .apply(bind::default_arguments(0)).create();
  /// TODO: void insert(int i, T &&value);
  // void insert(int i, const T &value);
  bind::void_member_function<QVector<T>, int, const T &, &QVector<T>::insert>(vector, "insert").create();
  // void insert(int i, int count, const T &value);
  bind::void_member_function<QVector<T>, int, int, const T &, &QVector<T>::insert>(vector, "insert").create();
  /// TODO: QVector::iterator insert(QVector::iterator before, int count, const T &value);
  /// TODO: QVector::iterator insert(QVector::iterator before, const T &value);
  /// TODO: QVector::iterator insert(QVector::iterator before, T &&value);
  // bool isEmpty() const;
  bind::member_function<QVector<T>, bool, &QVector<T>::isEmpty>(vector, "isEmpty").create();
  // T & last();
  vector.newMethod("last", callbacks::vector::back<T>)
    .returns(script::make_type<Proxy<T>>())
    .create();
  // const T & last() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::back>(vector, "last").create();
  // int lastIndexOf(const T &value, int from = ...) const;
  bind::member_function<QVector<T>, int, const T&, int, &QVector<T>::lastIndexOf>(vector, "lastIndexOf")
    .apply(bind::default_arguments(-1)).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // int length() const;
  bind::member_function<QVector<T>, int, &QVector<T>::length>(vector, "length").create();
#endif
  // QVector<T> mid(int pos, int length = ...) const;
  bind::member_function<QVector<T>, QVector<T>, int, int, &QVector<T>::mid>(vector, "mid")
    .apply(bind::default_arguments(-1)).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  // void move(int from, int to);
  bind::void_member_function<QVector<T>, int, int, &QVector<T>::move>(vector, "move").create();
#endif
  // void pop_back();
  bind::void_member_function<QVector<T>, &QVector<T>::pop_back>(vector, "pop_back").create();
  // void pop_front();
  bind::void_member_function<QVector<T>, &QVector<T>::pop_front>(vector, "pop_front").create();
  /// TODO: void prepend(T &&value);
  // void prepend(const T &value);
  bind::void_member_function<QVector<T>, const T &, &QVector<T>::prepend>(vector, "prepend").create();
  // void push_back(const T &value);
  bind::void_member_function<QVector<T>, const T &, &QVector<T>::push_back>(vector, "push_back").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: void push_back(T &&value);
#endif
  /// TODO: void push_front(T &&value);
  // void push_front(const T &value);
  bind::void_member_function<QVector<T>, const T &, &QVector<T>::push_front>(vector, "push_front").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: QVector::reverse_iterator rbegin();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: QVector::const_reverse_iterator rbegin() const;
#endif
  // void remove(int i);
  bind::void_member_function<QVector<T>, int, &QVector<T>::remove>(vector, "remove").create();
  // void remove(int i, int count);
  bind::void_member_function<QVector<T>, int, int, &QVector<T>::remove>(vector, "remove").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
  // int removeAll(const T &t);
  bind::member_function<QVector<T>, int, const T &, &QVector<T>::removeAll>(vector, "removeAll").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // void removeAt(int i);
  bind::void_member_function<QVector<T>, int, &QVector<T>::removeAt>(vector, "removeAt").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
  // void removeFirst();
  bind::void_member_function<QVector<T>, &QVector<T>::removeFirst>(vector, "removeFirst").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
  // void removeLast();
  bind::void_member_function<QVector<T>, &QVector<T>::removeLast>(vector, "removeLast").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
  // bool removeOne(const T &t);
  bind::member_function<QVector<T>, bool, const T&, &QVector<T>::removeOne>(vector, "removeOne").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: QVector::reverse_iterator rend();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: QVector::const_reverse_iterator rend() const;
#endif
  // void replace(int i, const T &value);
  bind::void_member_function<QVector<T>, int, const T&, &QVector<T>::replace>(vector, "replace").create();
  // void reserve(int size);
  bind::void_member_function<QVector<T>, int, &QVector<T>::reserve>(vector, "reserve").create();
  // void resize(int size);
  bind::void_member_function<QVector<T>, int, &QVector<T>::resize>(vector, "resize").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
  // void shrink_to_fit();
  bind::void_member_function<QVector<T>, &QVector<T>::shrink_to_fit>(vector, "shrink_to_fit").create();
#endif
  // int size() const;
  bind::member_function<QVector<T>, int, &QVector<T>::size>(vector, "size").create();
  // void squeeze();
  bind::void_member_function<QVector<T>, &QVector<T>::squeeze>(vector, "squeeze").create();
  // bool startsWith(const T &value) const;
  bind::member_function<QVector<T>, bool, const T &, &QVector<T>::startsWith>(vector, "startsWith").create();
  // void swap(QVector<T> &other);
  bind::void_member_function<QVector<T>, QVector<T>&, &QVector<T>::swap>(vector, "swap").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // T takeAt(int i);
  bind::member_function<QVector<T>, T, int, &QVector<T>::takeAt>(vector, "takeAt").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
  // T takeFirst();
  bind::member_function<QVector<T>, T, &QVector<T>::takeFirst>(vector, "takeFirst").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
  // T takeLast();
  bind::member_function<QVector<T>, T, &QVector<T>::takeLast>(vector, "takeLast").create();
#endif
  /// TODO: QList<T> toList() const;
  /// ignore: std::vector<T> toStdVector() const;
  // T value(int i) const;
  bind::member_function<QVector<T>, T, int, &QVector<T>::value>(vector, "value").create();
  // T value(int i, const T &defaultValue) const;
  bind::member_function<QVector<T>, T, int, const T &, &QVector<T>::value>(vector, "value").create();
  // bool operator!=(const QVector<T> &other) const;
  bind::memop_neq<QVector<T>, const QVector<T>&>(vector);
  // QVector<T> operator+(const QVector<T> &other) const;
  bind::memop_add<QVector<T>, QVector<T>, const QVector<T>&>(vector);
  // QVector<T> & operator+=(const QVector<T> &other);
  bind::memop_add_assign<QVector<T>, const T&>(vector);
  // QVector<T> & operator+=(const T &value);
  /// TODO: QVector<T> & operator+=(T &&value);
  // QVector<T> & operator<<(const T &value);
  bind::memop_put_to<QVector<T>, const T&>(vector);
  // QVector<T> & operator<<(const QVector<T> &other);
  bind::memop_put_to<QVector<T>, const QVector<T> &>(vector);
  /// TODO: QVector<T> & operator<<(T &&value);
  // QVector<T> & operator=(const QVector<T> &other);
  bind::memop_assign<QVector<T>, const QVector<T>&>(vector);
  /// TODO: QVector<T> & operator=(QVector<T> &&other);
  // bool operator==(const QVector<T> &other) const;
  bind::memop_eq<QVector<T>, const QVector<T> &>(vector);
  // T & operator[](int i);
  vector.newOperator(SubscriptOperator, callbacks::vector::subscript<T>)
    .returns(script::make_type<Proxy<T>>())
    .params(Type::cref(Type::Int))
    .create();
  // const T & operator[](int i) const
  bind::memop_subscript<QVector<T>, T, int>(vector);
}

#endif // YASL_COMMONS_VECTOR_SPECIALIZATIONS_H
