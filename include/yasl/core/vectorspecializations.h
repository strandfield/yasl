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

  binding::ClassBinder<QVector<T>> binder{ vector };

  // QVector();
  binder.default_ctor().create();
  // QVector(int size);
  binder.ctor<int>().create();
  // QVector(int size, const T &value);
  binder.ctor<int, const T &>().create();
  // QVector(const QVector<T> &other);
  binder.ctor<const QVector<T> &>().create();
  /// TODO: QVector(QVector<T> &&other);
  /// TODO: QVector(std::initializer_list<T> args);
  // ~QVector();
  binder.dtor().create();
  // void append(const T &value);
  binder.void_fun<const T &, &QVector<T>::append>("append").create();
  /// TODO: void append(T &&value);
  // void append(const QVector<T> &value);
  binder.void_fun<const QVector<T> &, &QVector<T>::append>("append").create();
  // const T & at(int i) const;
  binder.fun<const T &, int, &QVector<T>::at>("at").create();
  // QVector::reference back();
  vector.Method("back", callbacks::vector::back<T>)
    .returns(binding::make_type<Ptr<T>>())
    .create();
  // QVector::const_reference back() const;
  binder.fun<const T &, &QVector<T>::back>("back").create();
  /// TODO: QVector::iterator begin();
  /// TODO: QVector::const_iterator begin() const;
  // int capacity() const;
  binder.fun<int, &QVector<T>::capacity>("capacity").create();
  /// TODO: QVector::const_iterator cbegin() const;
  /// TODO: QVector::const_iterator cend() const;
  // void clear();
  binder.void_fun<&QVector<T>::clear>("clear").create();
  /// TODO: QVector::const_iterator constBegin() const;
  /// ignore: const T * constData() const;
  /// TODO: QVector::const_iterator constEnd() const;
  // const T & constFirst() const;
  binder.fun<const T &, &QVector<T>::constFirst>("constFirst").create();
  // const T & constLast() const;
  binder.fun<const T &, &QVector<T>::constLast>("constLast").create();
  // bool contains(const T &value) const;
  binder.fun<bool, const T &, &QVector<T>::contains>("contains").create();
  // int count(const T &value) const;
  binder.fun<int, const T &, &QVector<T>::count>("count").create();
  // int count() const;
  binder.fun<int, &QVector<T>::count>("count").create();
  /// TODO: QVector::const_reverse_iterator crbegin() const;
  /// TODO: QVector::const_reverse_iterator crend() const;
  /// ignore: T * data();
  /// ignore: const T * data() const;
  // bool empty() const;
  binder.fun<bool, &QVector<T>::empty>("empty").create();
  /// TODO: QVector::iterator end();
  /// TODO: QVector::const_iterator end() const;
  // bool endsWith(const T &value) const;
  binder.fun<bool, const T &, &QVector<T>::endsWith>("endsWith").create();
  /// TODO: QVector::iterator erase(QVector::iterator pos);
  /// TODO; QVector::iterator erase(QVector::iterator begin, QVector::iterator end);
  // QVector<T> & fill(const T &value, int size = ...);
  binder.chainable<const T&, int, &QVector<T>::fill>("fill")
    .apply(binding::default_arguments(-1)).create();
  // T & first();
  vector.Method("first", callbacks::vector::first<T>)
    .returns(binding::make_type<Ptr<T>>())
    .create();
  // const T & first() const;
  binder.fun<const T &, &QVector<T>::first>("first");
  // T & front();
  vector.Method("front", callbacks::vector::first<T>)
    .returns(binding::make_type<Ptr<T>>())
    .create();
  // QVector::const_reference front() const;
  binder.fun<const T &, &QVector<T>::front>("front").create();
  // int indexOf(const T &value, int from = ...) const;
  binder.fun<int, const T&, int, &QVector<T>::indexOf>("indexOf")
    .apply(binding::default_arguments(0)).create();
  /// TODO: void insert(int i, T &&value);
  // void insert(int i, const T &value);
  binder.void_fun<int, const T &, &QVector<T>::insert>("insert").create();
  // void insert(int i, int count, const T &value);
  binder.void_fun<int, int, const T &, &QVector<T>::insert>("insert").create();
  /// TODO: QVector::iterator insert(QVector::iterator before, int count, const T &value);
  /// TODO: QVector::iterator insert(QVector::iterator before, const T &value);
  /// TODO: QVector::iterator insert(QVector::iterator before, T &&value);
  // bool isEmpty() const;
  binder.fun<bool, &QVector<T>::isEmpty>("isEmpty").create();
  // T & last();
  vector.Method("last", callbacks::vector::back<T>)
    .returns(binding::make_type<Ptr<T>>())
    .create();
  // const T & last() const;
  binder.fun<const T &, &QVector<T>::back>("last").create();
  // int lastIndexOf(const T &value, int from = ...) const;
  binder.fun<int, const T&, int, &QVector<T>::lastIndexOf>("lastIndexOf")
    .apply(binding::default_arguments(-1)).create();
  // int length() const;
  binder.fun<int, &QVector<T>::length>("length").create();
  // QVector<T> mid(int pos, int length = ...) const;
  binder.fun<QVector<T>, int, int, &QVector<T>::mid>("mid")
    .apply(binding::default_arguments(-1)).create();
  // void move(int from, int to);
  binder.void_fun<int, int, &QVector<T>::move>("move").create();
  // void pop_back();
  binder.void_fun<&QVector<T>::pop_back>("pop_back").create();
  // void pop_front();
  binder.void_fun<&QVector<T>::pop_front>("pop_front").create();
  /// TODO: void prepend(T &&value);
  // void prepend(const T &value);
  binder.void_fun<const T &, &QVector<T>::prepend>("prepend").create();
  // void push_back(const T &value);
  binder.void_fun<const T &, &QVector<T>::push_back>("push_back").create();
  /// TODO: void push_back(T &&value);
  /// TODO: void push_front(T &&value);
  // void push_front(const T &value);
  binder.void_fun<const T &, &QVector<T>::push_front>("push_front").create();
  /// TODO: QVector::reverse_iterator rbegin();
  /// TODO: QVector::const_reverse_iterator rbegin() const;
  // void remove(int i);
  binder.void_fun<int, &QVector<T>::remove>("remove").create();
  // void remove(int i, int count);
  binder.void_fun<int, int, &QVector<T>::remove>("remove").create();
  // int removeAll(const T &t);
  binder.fun<int, const T &, &QVector<T>::removeAll>("removeAll").create();
  // void removeAt(int i);
  binder.void_fun<int, &QVector<T>::removeAt>("removeAt").create();
  // void removeFirst();
  binder.void_fun<&QVector<T>::removeFirst>("removeFirst").create();
  // void removeLast();
  binder.void_fun<&QVector<T>::removeLast>("removeLast").create();
  // bool removeOne(const T &t);
  binder.fun<bool, const T&, &QVector<T>::removeOne>("removeOne").create();
  /// TODO: QVector::reverse_iterator rend();
  /// TODO: QVector::const_reverse_iterator rend() const;
  // void replace(int i, const T &value);
  binder.void_fun<int, const T&, &QVector<T>::replace>("replace").create();
  // void reserve(int size);
  binder.void_fun<int, &QVector<T>::reserve>("reserve").create();
  // void resize(int size);
  binder.void_fun<int, &QVector<T>::resize>("resize").create();
  // void shrink_to_fit();
  binder.void_fun<&QVector<T>::shrink_to_fit>("shrink_to_fit").create();
  // int size() const;
  binder.fun<int, &QVector<T>::size>("size").create();
  // void squeeze();
  binder.void_fun<&QVector<T>::squeeze>("squeeze").create();
  // bool startsWith(const T &value) const;
  binder.fun<bool, const T &, &QVector<T>::startsWith>("startsWith").create();
  // void swap(QVector<T> &other);
  binder.void_fun<QVector<T>&, &QVector<T>::swap>("swap").create();
  // T takeAt(int i);
  binder.fun<T, int, &QVector<T>::takeAt>("takeAt").create();
  // T takeFirst();
  binder.fun<T, &QVector<T>::takeFirst>("takeFirst").create();
  // T takeLast();
  binder.fun<T, &QVector<T>::takeLast>("takeLast").create();
  /// TODO: QList<T> toList() const;
  /// ignore: std::vector<T> toStdVector() const;
  // T value(int i) const;
  binder.fun<T, int, &QVector<T>::value>("value").create();
  // T value(int i, const T &defaultValue) const;
  binder.fun<T, int, const T &, &QVector<T>::value>("value").create();
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
