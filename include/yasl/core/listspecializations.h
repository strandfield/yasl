// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_LIST_SPECIALIZATIONS_H
#define YASL_CORE_LIST_SPECIALIZATIONS_H

#include "yasl/core/list.h"

#include "yasl/binding/class.h"
#include "yasl/utils/ptr.h"

template<typename T>
void register_list_specialization(script::Engine *e, script::Type::BuiltInType type_id)
{
  using namespace script;

  script::ClassTemplate list_template = e->getTemplate(Engine::ListTemplate);

  std::vector<TemplateArgument> targs{
    TemplateArgument{ binding::make_type<T>() }
  };

  Class list = list_template.Specialization(std::move(targs))
    .setId(type_id)
    .setFinal()
    .get();

  binding::Class<QList<T>> l{ list };

  // QList<T>();
  l.ctors().add_default();
  // QList<T>(const QList<T> &);
  l.ctors().add<const QList<T> &>();
  // ~QList<T>();
  l.add_dtor();

  // void append(const T &value)
  l.add_void_fun<const T &, &QList<T>::append>("append");
  // void append(const QList<T> &value)
  l.add_void_fun<const QList<T> &, &QList<T>::append>("append");
  // const T & at(int i) const
  l.add_fun<const T &, int, &QList<T>::at>("at");
  // T & back()
  l.add_ref_mem<T&, &QList<T>::back>("back");
  // const T & back() const
  l.add_fun<const T &, &QList<T>::back>("back");
  // iterator begin()
  /// l.add_fun<QList<T>::iterator, &QList<T>::begin>("begin");
  // const_iterator begin() const
  /// l.add_fun<QList<T>::const_iterator, &QList<T>::begin>("begin");
  // const_iterator cbegin() const
  /// l.add_fun<QList<T>::const_iterator, &QList<T>::cbegin>("cbegin");
  // const_iterator cend() const
  /// l.add_fun<QList<T>::const_iterator, &QList<T>::cend>("cend");
  // void clear()
  l.add_void_fun<&QList<T>::clear>("clear");
  // const_iterator constBegin() const
  /// l.add_fun<QList<T>::const_iterator, &QList<T>::constBegin>("constBegin");
  // const_iterator constEnd() const
  /// l.add_fun<QList<T>::const_iterator, &QList<T>::constEnd>("constEnd");
  // const T & constFirst() const
  l.add_fun<const T &, &QList<T>::constFirst>("constFirst");
  // const T & constLast() const
  l.add_fun<const T &, &QList<T>::constLast>("constLast");
  // bool contains(const T &value) const
  l.add_fun<bool, const T &, &QList<T>::contains>("contains");
  // int count(const T &value) const
  l.add_fun<int, const T &, &QList<T>::count>("count");
  // int count() const
  l.add_fun<int, &QList<T>::count>("count");
  // const_reverse_iterator crbegin() const
  /// l.add_fun<QList<T>::const_reverse_iterator, &QList<T>::crbegin>("crbegin");
  // const_reverse_iterator crend() const
  /// l.add_fun<QList<T>::const_reverse_iterator, &QList<T>::crend>("crend");
  // bool empty() const
  l.add_fun<bool, &QList<T>::empty>("empty");
  // iterator end()
  /// l.add_fun<QList<T>::iterator, &QList<T>::end>("end");
  // const_iterator end() const
  /// l.add_fun<QList<T>::const_iterator, &QList<T>::end>("end");
  // bool endsWith(const T &value) const
  l.add_fun<bool, const T &, &QList<T>::endsWith>("endsWith");
  // iterator erase(iterator pos)
  /// l.add_fun<QList<T>::iterator, QList<T>::iterator, &QList<T>::erase>("erase");
  // iterator erase(iterator begin, iterator end)
  /// l.add_fun<QList<T>::iterator, QList<T>::iterator, QList<T>::iterator, &QList<T>::erase>("erase");
  // T & first()
  /// TODO !!!
  // const T & first() const
  l.add_fun<const T &, &QList<T>::first>("first");
  // T & front()
  l.add_ref_mem<T&, &QList<T>::front>("front");
  // const T & front() const
  l.add_fun<const T &, &QList<T>::front>("front");
  // int indexOf(const T &value, int from = 0) const
  l.add_fun<int, const T &, int, &QList<T>::indexOf>("indexOf");
  // void insert(int i, const T &value)
  l.add_void_fun<int, const T &, &QList<T>::insert>("insert");
  // iterator insert(iterator before, const T &value)
  /// l.add_fun<QList<T>::iterator, QList<T>::iterator, const T &, &QList<T>::insert>("insert");
  // bool isEmpty() const
  l.add_fun<bool, &QList<T>::isEmpty>("isEmpty");
  // T & last()
  /// TODO !!!
  // const T & last() const
  l.add_fun<const T &, &QList<T>::last>("last");
  // int lastIndexOf(const T &value, int from = -1) const
  l.add_fun<int, const T &, int, &QList<T>::lastIndexOf>("lastIndexOf");
  // int length() const
  l.add_fun<int, &QList<T>::length>("length");
  // QList<T> mid(int pos, int length = -1) const
  l.add_fun<QList<T>, int, int, &QList<T>::mid>("mid");
  // void move(int from, int to)
  l.add_void_fun<int, int, &QList<T>::move>("move");
  // void pop_back()
  l.add_void_fun<&QList<T>::pop_back>("pop_back");
  // void pop_front()
  l.add_void_fun<&QList<T>::pop_front>("pop_front");
  // void prepend(const T &value)
  l.add_void_fun<const T &, &QList<T>::prepend>("prepend");
  // void push_back(const T &value)
  l.add_void_fun<const T &, &QList<T>::push_back>("push_back");
  // void push_front(const T &value)
  l.add_void_fun<const T &, &QList<T>::push_front>("push_front");
  // reverse_iterator rbegin()
  /// l.add_fun<QList<T>::reverse_iterator, &QList<T>::rbegin>("rbegin");
  // const_reverse_iterator rbegin() const
  /// l.add_fun<QList<T>::const_reverse_iterator, &QList<T>::rbegin>("rbegin");
  // int removeAll(const T &value)
  l.add_fun<int, const T &, &QList<T>::removeAll>("removeAll");
  // void removeAt(int i)
  l.add_void_fun<int, &QList<T>::removeAt>("removeAt");
  // void removeFirst()
  l.add_void_fun<&QList<T>::removeFirst>("removeFirst");
  // void removeLast()
  l.add_void_fun<&QList<T>::removeLast>("removeLast");
  // bool removeOne(const T &value)
  l.add_fun<bool, const T &, &QList<T>::removeOne>("removeOne");
  // reverse_iterator rend()
  /// l.add_fun<QList<T>::reverse_iterator, &QList<T>::rend>("rend");
  // const_reverse_iterator rend() const
  /// l.add_fun<QList<T>::const_reverse_iterator, &QList<T>::rend>("rend");
  // void replace(int i, const T &value)
  l.add_void_fun<int, const T &, &QList<T>::replace>("replace");
  // void reserve(int alloc)
  l.add_void_fun<int, &QList<T>::reserve>("reserve");
  // int size() const
  l.add_fun<int, &QList<T>::size>("size");
  // bool startsWith(const T &value) const
  l.add_fun<bool, const T &, &QList<T>::startsWith>("startsWith");
  // void swap(QList<T> &other)
  l.add_void_fun<QList<T> &, &QList<T>::swap>("swap");
  // void swap(int i, int j)
  l.add_void_fun<int, int, &QList<T>::swap>("swap");
  // T takeAt(int i)
  l.add_fun<T, int, &QList<T>::takeAt>("takeAt");
  // T takeFirst()
  l.add_fun<T, &QList<T>::takeFirst>("takeFirst");
  // T takeLast()
  l.add_fun<T, &QList<T>::takeLast>("takeLast");
  // QSet<T> toSet() const
  /// l.add_fun<QSet<T>, &QList<T>::toSet>("toSet");
  // std::list<T> toStdList() const
  /// l.add_fun<std::list<T>, &QList<T>::toStdList>("toStdList");
  // QVector<T> toVector() const
  /// l.add_fun<QVector<T>, &QList<T>::toVector>("toVector");
  // T value(int i) const
  l.add_fun<T, int, &QList<T>::value>("value");
  // T value(int i, const T &defaultValue) const
  l.add_fun<T, int, const T &, &QList<T>::value>("value");


  // bool operator!=(const QList<T> &other) const
  l.operators().neq<const QList<T> &>();
  // QList<T> operator+(const QList<T> &other) const
  l.operators().add<QList<T>, const QList<T> &>();
  // QList<T> & operator+=(const QList<T> &other)
  l.operators().add_assign<const QList<T> &>();
  // QList<T> & operator+=(const T &value)
  l.operators().add_assign<const T &>();
  // QList<T> & operator<<(const QList<T> &other)
  /// TODO !!!
  // QList<T> & operator<<(const T &value)
  /// TODO !!!
  // QList<T> & operator=(const QList<T> &other)
  l.operators().assign<const QList<T> &>();
  // QList & operator=(QList<T> &&other)
  /// TODO !!!
  // bool operator==(const QList<T> &other) const
  l.operators().eq<const QList<T> &>();
  // T & operator[](int i)
  /// TODO !!!
  // const T & operator[](int i) const
  /// TODO !!!

}

#endif // YASL_CORE_LIST_SPECIALIZATIONS_H
