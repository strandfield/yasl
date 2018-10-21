// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_VECTOR_SPECIALIZATIONS_H
#define YASL_CORE_VECTOR_SPECIALIZATIONS_H

#include "yasl/core/vector.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"

#include "yasl/utils/ptr.h"

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
  QVector<T> & self = binding::value_cast<QVector<T> &>(c->thisObject());
  return c->engine()->newPtr(c->callee().returnType(), &self.back());
}

template<typename T>
script::Value first(script::FunctionCall *c)
{
  QVector<T> & self = binding::value_cast<QVector<T> &>(c->thisObject());
  return c->engine()->newPtr(c->callee().returnType(), &self.first());
}

template<typename T>
script::Value subscript(script::FunctionCall *c)
{
  QVector<T> & self = binding::value_cast<QVector<T> &>(c->thisObject());
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
    TemplateArgument{ binding::make_type<T>() }
  };

  Class vector = vector_template.Specialization(std::move(targs))
    .setId(type_id)
    .setFinal()
    .get();

  binding::Class<QVector<T>> binder{ vector };

  // QVector();
  binder.ctors().add_default();
  // QVector(int size);
  binder.ctors().add<int>();
  // QVector(int size, const T &value);
  binder.ctors().add<int, const T &>();
  // QVector(const QVector<T> &other);
  binder.ctors().add<const QVector<T> &>();
  /// TODO: QVector(QVector<T> &&other);
  /// TODO: QVector(std::initializer_list<T> args);
  // ~QVector();
  binder.add_dtor();
  // void append(const T &value);
  binder.add_void_fun<const T &, &QVector<T>::append>("append");
  /// TODO: void append(T &&value);
  // void append(const QVector<T> &value);
  binder.add_void_fun<const QVector<T> &, &QVector<T>::append>("append");
  // const T & at(int i) const;
  binder.add_fun<const T &, int, &QVector<T>::at>("at");
  // QVector::reference back();
  vector.Method("back", callbacks::vector::back<T>)
    .returns(binding::make_type<Ptr<T>>())
    .create();
  // QVector::const_reference back() const;
  binder.add_fun<const T &, &QVector<T>::back>("back");
  /// TODO: QVector::iterator begin();
  /// TODO: QVector::const_iterator begin() const;
  // int capacity() const;
  binder.add_fun<int, &QVector<T>::capacity>("capacity");
  /// TODO: QVector::const_iterator cbegin() const;
  /// TODO: QVector::const_iterator cend() const;
  // void clear();
  binder.add_void_fun<&QVector<T>::clear>("clear");
  /// TODO: QVector::const_iterator constBegin() const;
  /// ignore: const T * constData() const;
  /// TODO: QVector::const_iterator constEnd() const;
  // const T & constFirst() const;
  binder.add_fun<const T &, &QVector<T>::constFirst>("constFirst");
  // const T & constLast() const;
  binder.add_fun<const T &, &QVector<T>::constLast>("constLast");
  // bool contains(const T &value) const;
  binder.add_fun<bool, const T &, &QVector<T>::contains>("contains");
  // int count(const T &value) const;
  binder.add_fun<int, const T &, &QVector<T>::count>("count");
  // int count() const;
  binder.add_fun<int, &QVector<T>::count>("count");
  /// TODO: QVector::const_reverse_iterator crbegin() const;
  /// TODO: QVector::const_reverse_iterator crend() const;
  /// ignore: T * data();
  /// ignore: const T * data() const;
  // bool empty() const;
  binder.add_fun<bool, &QVector<T>::empty>("empty");
  /// TODO: QVector::iterator end();
  /// TODO: QVector::const_iterator end() const;
  // bool endsWith(const T &value) const;
  binder.add_fun<bool, const T &, &QVector<T>::endsWith>("endsWith");
  /// TODO: QVector::iterator erase(QVector::iterator pos);
  /// TODO; QVector::iterator erase(QVector::iterator begin, QVector::iterator end);
  // QVector<T> & fill(const T &value, int size = ...);
  binder.chainable<const T&, int, &QVector<T>::fill>("fill")
    .addDefaultArgument(binding::default_argument(vector.engine(), -1)).create();
  // T & first();
  vector.Method("first", callbacks::vector::first<T>)
    .returns(binding::make_type<Ptr<T>>())
    .create();
  // const T & first() const;
  binder.add_fun<const T &, &QVector<T>::first>("first");
  // T & front();
  vector.Method("front", callbacks::vector::first<T>)
    .returns(binding::make_type<Ptr<T>>())
    .create();
  // QVector::const_reference front() const;
  binder.add_fun<const T &, &QVector<T>::front>("front");
  // int indexOf(const T &value, int from = ...) const;
  binder.fun<int, const T&, int, &QVector<T>::indexOf>("indexOf")
    .addDefaultArgument(binding::default_argument(vector.engine(), 0)).create();
  /// TODO: void insert(int i, T &&value);
  // void insert(int i, const T &value);
  binder.add_void_fun<int, const T &, &QVector<T>::insert>("insert");
  // void insert(int i, int count, const T &value);
  binder.add_void_fun<int, int, const T &, &QVector<T>::insert>("insert");
  /// TODO: QVector::iterator insert(QVector::iterator before, int count, const T &value);
  /// TODO: QVector::iterator insert(QVector::iterator before, const T &value);
  /// TODO: QVector::iterator insert(QVector::iterator before, T &&value);
  // bool isEmpty() const;
  binder.add_fun<bool, &QVector<T>::isEmpty>("isEmpty");
  // T & last();
  vector.Method("last", callbacks::vector::back<T>)
    .returns(binding::make_type<Ptr<T>>())
    .create();
  // const T & last() const;
  binder.add_fun<const T &, &QVector<T>::back>("last");
  // int lastIndexOf(const T &value, int from = ...) const;
  binder.fun<int, const T&, int, &QVector<T>::lastIndexOf>("lastIndexOf")
    .addDefaultArgument(binding::default_argument(vector.engine(), -1)).create();
  // int length() const;
  binder.add_fun<int, &QVector<T>::length>("length");
  // QVector<T> mid(int pos, int length = ...) const;
  binder.fun<QVector<T>, int, int, &QVector<T>::mid>("mid")
    .addDefaultArgument(binding::default_argument(vector.engine(), -1)).create();
  // void move(int from, int to);
  binder.add_void_fun<int, int, &QVector<T>::move>("move");
  // void pop_back();
  binder.add_void_fun<&QVector<T>::pop_back>("pop_back");
  // void pop_front();
  binder.add_void_fun<&QVector<T>::pop_front>("pop_front");
  /// TODO: void prepend(T &&value);
  // void prepend(const T &value);
  binder.add_void_fun<const T &, &QVector<T>::prepend>("prepend");
  // void push_back(const T &value);
  binder.add_void_fun<const T &, &QVector<T>::push_back>("push_back");
  /// TODO: void push_back(T &&value);
  /// TODO: void push_front(T &&value);
  // void push_front(const T &value);
  binder.add_void_fun<const T &, &QVector<T>::push_front>("push_front");
  /// TODO: QVector::reverse_iterator rbegin();
  /// TODO: QVector::const_reverse_iterator rbegin() const;
  // void remove(int i);
  binder.add_void_fun<int, &QVector<T>::remove>("remove");
  // void remove(int i, int count);
  binder.add_void_fun<int, int, &QVector<T>::remove>("remove");
  // int removeAll(const T &t);
  binder.add_fun<int, const T &, &QVector<T>::removeAll>("removeAll");
  // void removeAt(int i);
  binder.add_void_fun<int, &QVector<T>::removeAt>("removeAt");
  // void removeFirst();
  binder.add_void_fun<&QVector<T>::removeFirst>("removeFirst");
  // void removeLast();
  binder.add_void_fun<&QVector<T>::removeLast>("removeLast");
  // bool removeOne(const T &t);
  binder.add_fun<bool, const T&, &QVector<T>::removeOne>("removeOne");
  /// TODO: QVector::reverse_iterator rend();
  /// TODO: QVector::const_reverse_iterator rend() const;
  // void replace(int i, const T &value);
  binder.add_void_fun<int, const T&, &QVector<T>::replace>("replace");
  // void reserve(int size);
  binder.add_void_fun<int, &QVector<T>::reserve>("reserve");
  // void resize(int size);
  binder.add_void_fun<int, &QVector<T>::resize>("resize");
  // void shrink_to_fit();
  binder.add_void_fun<&QVector<T>::shrink_to_fit>("shrink_to_fit");
  // int size() const;
  binder.add_fun<int, &QVector<T>::size>("size");
  // void squeeze();
  binder.add_void_fun<&QVector<T>::squeeze>("squeeze");
  // bool startsWith(const T &value) const;
  binder.add_fun<bool, const T &, &QVector<T>::startsWith>("startsWith");
  // void swap(QVector<T> &other);
  binder.add_void_fun<QVector<T>&, &QVector<T>::swap>("swap");
  // T takeAt(int i);
  binder.add_fun<T, int, &QVector<T>::takeAt>("takeAt");
  // T takeFirst();
  binder.add_fun<T, &QVector<T>::takeFirst>("takeFirst");
  // T takeLast();
  binder.add_fun<T, &QVector<T>::takeLast>("takeLast");
  /// TODO: QList<T> toList() const;
  /// ignore: std::vector<T> toStdVector() const;
  // T value(int i) const;
  binder.add_fun<T, int, &QVector<T>::value>("value");
  // T value(int i, const T &defaultValue) const;
  binder.add_fun<T, int, const T &, &QVector<T>::value>("value");
  // bool operator!=(const QVector<T> &other) const;
  binder.operators().neq<const QVector<T>&>();
  // QVector<T> operator+(const QVector<T> &other) const;
  binder.operators().add<QVector<T>, const QVector<T>&>();
  // QVector<T> & operator+=(const QVector<T> &other);
  binder.operators().add_assign<const T&>();
  // QVector<T> & operator+=(const T &value);
  /// TODO: QVector<T> & operator+=(T &&value);
  // QVector<T> & operator<<(const T &value);
  binder.operators().put_to<const T&>();
  // QVector<T> & operator<<(const QVector<T> &other);
  binder.operators().put_to<const QVector<T> &>();
  /// TODO: QVector<T> & operator<<(T &&value);
  // QVector<T> & operator=(const QVector<T> &other);
  binder.operators().assign<const QVector<T>&>();
  /// TODO: QVector<T> & operator=(QVector<T> &&other);
  // bool operator==(const QVector<T> &other) const;
  binder.operators().eq<const QVector<T> &>();
  // T & operator[](int i);
  vector.Operation(SubscriptOperator, callbacks::vector::subscript<T>)
    .returns(binding::make_type<Ptr<T>>())
    .params(Type::cref(Type::Int))
    .create();
  // const T & operator[](int i) const
  binder.operators().subscript<T, int>();
}

#endif // YASL_CORE_VECTOR_SPECIALIZATIONS_H
