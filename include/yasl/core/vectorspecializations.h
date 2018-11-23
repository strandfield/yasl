// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_VECTOR_SPECIALIZATIONS_H
#define YASL_CORE_VECTOR_SPECIALIZATIONS_H

#include "yasl/core/vector.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/namespace.h"

#include "yasl/binding2/proxy.h"

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
  QVector<T> & self = script::bind::value_cast<QVector<T> &>(c->thisObject());
  return c->engine()->newPtr(c->callee().returnType(), &self.back());
}

template<typename T>
script::Value first(script::FunctionCall *c)
{
  QVector<T> & self = script::bind::value_cast<QVector<T> &>(c->thisObject());
  return c->engine()->newPtr(c->callee().returnType(), &self.first());
}

template<typename T>
script::Value subscript(script::FunctionCall *c)
{
  QVector<T> & self = script::bind::value_cast<QVector<T> &>(c->thisObject());
  const int index = c->arg(1).toInt();
  return c->engine()->newPtr(c->callee().returnType(), &self[index]);
}

} // namespace list

} // namespace callbacks


template<typename T>
void register_vector_specialization(script::ClassTemplate vector_template, script::Type::BuiltInType type_id)
{
  using namespace script;

  std::vector<TemplateArgument> targs{
    TemplateArgument{ bind::make_type<T>() }
  };

  Class vector = vector_template.Specialization(std::move(targs))
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
  /// TODO: void append(T &&value);
  // void append(const QVector<T> &value);
  bind::void_member_function<QVector<T>, const QVector<T> &, &QVector<T>::append>(vector, "append").create();
  // const T & at(int i) const;
  bind::member_function<QVector<T>, const T &, int, &QVector<T>::at>(vector, "at").create();
  // QVector::reference back();
  vector.newMethod("back", callbacks::vector::back<T>)
    .returns(bind::make_type<bind::Proxy<T>>())
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
  // const T & constFirst() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::constFirst>(vector, "constFirst").create();
  // const T & constLast() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::constLast>(vector, "constLast").create();
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
    .returns(bind::make_type<bind::Proxy<T>>())
    .create();
  // const T & first() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::first>(vector, "first");
  // T & front();
  vector.newMethod("front", callbacks::vector::first<T>)
    .returns(bind::make_type<bind::Proxy<T>>())
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
    .returns(bind::make_type<bind::Proxy<T>>())
    .create();
  // const T & last() const;
  bind::member_function<QVector<T>, const T &, &QVector<T>::back>(vector, "last").create();
  // int lastIndexOf(const T &value, int from = ...) const;
  bind::member_function<QVector<T>, int, const T&, int, &QVector<T>::lastIndexOf>(vector, "lastIndexOf")
    .apply(bind::default_arguments(-1)).create();
  // int length() const;
  bind::member_function<QVector<T>, int, &QVector<T>::length>(vector, "length").create();
  // QVector<T> mid(int pos, int length = ...) const;
  bind::member_function<QVector<T>, QVector<T>, int, int, &QVector<T>::mid>(vector, "mid")
    .apply(bind::default_arguments(-1)).create();
  // void move(int from, int to);
  bind::void_member_function<QVector<T>, int, int, &QVector<T>::move>(vector, "move").create();
  // void pop_back();
  bind::void_member_function<QVector<T>, &QVector<T>::pop_back>(vector, "pop_back").create();
  // void pop_front();
  bind::void_member_function<QVector<T>, &QVector<T>::pop_front>(vector, "pop_front").create();
  /// TODO: void prepend(T &&value);
  // void prepend(const T &value);
  bind::void_member_function<QVector<T>, const T &, &QVector<T>::prepend>(vector, "prepend").create();
  // void push_back(const T &value);
  bind::void_member_function<QVector<T>, const T &, &QVector<T>::push_back>(vector, "push_back").create();
  /// TODO: void push_back(T &&value);
  /// TODO: void push_front(T &&value);
  // void push_front(const T &value);
  bind::void_member_function<QVector<T>, const T &, &QVector<T>::push_front>(vector, "push_front").create();
  /// TODO: QVector::reverse_iterator rbegin();
  /// TODO: QVector::const_reverse_iterator rbegin() const;
  // void remove(int i);
  bind::void_member_function<QVector<T>, int, &QVector<T>::remove>(vector, "remove").create();
  // void remove(int i, int count);
  bind::void_member_function<QVector<T>, int, int, &QVector<T>::remove>(vector, "remove").create();
  // int removeAll(const T &t);
  bind::member_function<QVector<T>, int, const T &, &QVector<T>::removeAll>(vector, "removeAll").create();
  // void removeAt(int i);
  bind::void_member_function<QVector<T>, int, &QVector<T>::removeAt>(vector, "removeAt").create();
  // void removeFirst();
  bind::void_member_function<QVector<T>, &QVector<T>::removeFirst>(vector, "removeFirst").create();
  // void removeLast();
  bind::void_member_function<QVector<T>, &QVector<T>::removeLast>(vector, "removeLast").create();
  // bool removeOne(const T &t);
  bind::member_function<QVector<T>, bool, const T&, &QVector<T>::removeOne>(vector, "removeOne").create();
  /// TODO: QVector::reverse_iterator rend();
  /// TODO: QVector::const_reverse_iterator rend() const;
  // void replace(int i, const T &value);
  bind::void_member_function<QVector<T>, int, const T&, &QVector<T>::replace>(vector, "replace").create();
  // void reserve(int size);
  bind::void_member_function<QVector<T>, int, &QVector<T>::reserve>(vector, "reserve").create();
  // void resize(int size);
  bind::void_member_function<QVector<T>, int, &QVector<T>::resize>(vector, "resize").create();
  // void shrink_to_fit();
  /// Qt 5.10
  ///bind::void_member_function<QVector<T>, &QVector<T>::shrink_to_fit>(vector, "shrink_to_fit").create();
  // int size() const;
  bind::member_function<QVector<T>, int, &QVector<T>::size>(vector, "size").create();
  // void squeeze();
  bind::void_member_function<QVector<T>, &QVector<T>::squeeze>(vector, "squeeze").create();
  // bool startsWith(const T &value) const;
  bind::member_function<QVector<T>, bool, const T &, &QVector<T>::startsWith>(vector, "startsWith").create();
  // void swap(QVector<T> &other);
  bind::void_member_function<QVector<T>, QVector<T>&, &QVector<T>::swap>(vector, "swap").create();
  // T takeAt(int i);
  bind::member_function<QVector<T>, T, int, &QVector<T>::takeAt>(vector, "takeAt").create();
  // T takeFirst();
  bind::member_function<QVector<T>, T, &QVector<T>::takeFirst>(vector, "takeFirst").create();
  // T takeLast();
  bind::member_function<QVector<T>, T, &QVector<T>::takeLast>(vector, "takeLast").create();
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
    .returns(bind::make_type<bind::Proxy<T>>())
    .params(Type::cref(Type::Int))
    .create();
  // const T & operator[](int i) const
  bind::memop_subscript<QVector<T>, T, int>(vector);
}

#endif // YASL_CORE_VECTOR_SPECIALIZATIONS_H
