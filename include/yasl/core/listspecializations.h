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
  l.ctors().default_ctor().create();
  // QList<T>(const QList<T> &);
  l.ctors().ctor<const QList<T> &>().create();
  // ~QList<T>();
  l.add_dtor();

  // void append(const T &value)
  l.void_fun<const T &, &QList<T>::append>("append").create();
  // void append(const QList<T> &value)
  l.void_fun<const QList<T> &, &QList<T>::append>("append").create();
  // const T & at(int i) const
  l.fun<const T &, int, &QList<T>::at>("at").create();
  // T & back()
  l.ref_mem_getter<T&, &QList<T>::back>("back").create();
  // const T & back() const
  l.fun<const T &, &QList<T>::back>("back").create();
  // iterator begin()
  /// l.fun<QList<T>::iterator, &QList<T>::begin>("begin").create();
  // const_iterator begin() const
  /// l.fun<QList<T>::const_iterator, &QList<T>::begin>("begin").create();
  // const_iterator cbegin() const
  /// l.fun<QList<T>::const_iterator, &QList<T>::cbegin>("cbegin").create();
  // const_iterator cend() const
  /// l.fun<QList<T>::const_iterator, &QList<T>::cend>("cend").create();
  // void clear()
  l.void_fun<&QList<T>::clear>("clear").create();
  // const_iterator constBegin() const
  /// l.fun<QList<T>::const_iterator, &QList<T>::constBegin>("constBegin").create();
  // const_iterator constEnd() const
  /// l.fun<QList<T>::const_iterator, &QList<T>::constEnd>("constEnd").create();
  // const T & constFirst() const
  l.fun<const T &, &QList<T>::constFirst>("constFirst").create();
  // const T & constLast() const
  l.fun<const T &, &QList<T>::constLast>("constLast").create();
  // bool contains(const T &value) const
  l.fun<bool, const T &, &QList<T>::contains>("contains").create();
  // int count(const T &value) const
  l.fun<int, const T &, &QList<T>::count>("count").create();
  // int count() const
  l.fun<int, &QList<T>::count>("count").create();
  // const_reverse_iterator crbegin() const
  /// l.fun<QList<T>::const_reverse_iterator, &QList<T>::crbegin>("crbegin").create();
  // const_reverse_iterator crend() const
  /// l.fun<QList<T>::const_reverse_iterator, &QList<T>::crend>("crend").create();
  // bool empty() const
  l.fun<bool, &QList<T>::empty>("empty").create();
  // iterator end()
  /// l.fun<QList<T>::iterator, &QList<T>::end>("end").create();
  // const_iterator end() const
  /// l.fun<QList<T>::const_iterator, &QList<T>::end>("end").create();
  // bool endsWith(const T &value) const
  l.fun<bool, const T &, &QList<T>::endsWith>("endsWith").create();
  // iterator erase(iterator pos)
  /// l.fun<QList<T>::iterator, QList<T>::iterator, &QList<T>::erase>("erase").create();
  // iterator erase(iterator begin, iterator end)
  /// l.fun<QList<T>::iterator, QList<T>::iterator, QList<T>::iterator, &QList<T>::erase>("erase").create();
  // T & first()
  /// TODO !!!
  // const T & first() const
  l.fun<const T &, &QList<T>::first>("first").create();
  // T & front()
  l.ref_mem_getter<T&, &QList<T>::front>("front").create();
  // const T & front() const
  l.fun<const T &, &QList<T>::front>("front").create();
  // int indexOf(const T &value, int from = 0) const
  l.fun<int, const T &, int, &QList<T>::indexOf>("indexOf").create();
  // void insert(int i, const T &value)
  l.void_fun<int, const T &, &QList<T>::insert>("insert").create();
  // iterator insert(iterator before, const T &value)
  /// l.fun<QList<T>::iterator, QList<T>::iterator, const T &, &QList<T>::insert>("insert").create();
  // bool isEmpty() const
  l.fun<bool, &QList<T>::isEmpty>("isEmpty").create();
  // T & last()
  /// TODO !!!
  // const T & last() const
  l.fun<const T &, &QList<T>::last>("last").create();
  // int lastIndexOf(const T &value, int from = -1) const
  l.fun<int, const T &, int, &QList<T>::lastIndexOf>("lastIndexOf").create();
  // int length() const
  l.fun<int, &QList<T>::length>("length").create();
  // QList<T> mid(int pos, int length = -1) const
  l.fun<QList<T>, int, int, &QList<T>::mid>("mid").create();
  // void move(int from, int to)
  l.void_fun<int, int, &QList<T>::move>("move").create();
  // void pop_back()
  l.void_fun<&QList<T>::pop_back>("pop_back").create();
  // void pop_front()
  l.void_fun<&QList<T>::pop_front>("pop_front").create();
  // void prepend(const T &value)
  l.void_fun<const T &, &QList<T>::prepend>("prepend").create();
  // void push_back(const T &value)
  l.void_fun<const T &, &QList<T>::push_back>("push_back").create();
  // void push_front(const T &value)
  l.void_fun<const T &, &QList<T>::push_front>("push_front").create();
  // reverse_iterator rbegin()
  /// l.fun<QList<T>::reverse_iterator, &QList<T>::rbegin>("rbegin").create();
  // const_reverse_iterator rbegin() const
  /// l.fun<QList<T>::const_reverse_iterator, &QList<T>::rbegin>("rbegin").create();
  // int removeAll(const T &value)
  l.fun<int, const T &, &QList<T>::removeAll>("removeAll").create();
  // void removeAt(int i)
  l.void_fun<int, &QList<T>::removeAt>("removeAt").create();
  // void removeFirst()
  l.void_fun<&QList<T>::removeFirst>("removeFirst").create();
  // void removeLast()
  l.void_fun<&QList<T>::removeLast>("removeLast").create();
  // bool removeOne(const T &value)
  l.fun<bool, const T &, &QList<T>::removeOne>("removeOne").create();
  // reverse_iterator rend()
  /// l.fun<QList<T>::reverse_iterator, &QList<T>::rend>("rend").create();
  // const_reverse_iterator rend() const
  /// l.fun<QList<T>::const_reverse_iterator, &QList<T>::rend>("rend").create();
  // void replace(int i, const T &value)
  l.void_fun<int, const T &, &QList<T>::replace>("replace").create();
  // void reserve(int alloc)
  l.void_fun<int, &QList<T>::reserve>("reserve").create();
  // int size() const
  l.fun<int, &QList<T>::size>("size").create();
  // bool startsWith(const T &value) const
  l.fun<bool, const T &, &QList<T>::startsWith>("startsWith").create();
  // void swap(QList<T> &other)
  l.void_fun<QList<T> &, &QList<T>::swap>("swap").create();
  // void swap(int i, int j)
  l.void_fun<int, int, &QList<T>::swap>("swap").create();
  // T takeAt(int i)
  l.fun<T, int, &QList<T>::takeAt>("takeAt").create();
  // T takeFirst()
  l.fun<T, &QList<T>::takeFirst>("takeFirst").create();
  // T takeLast()
  l.fun<T, &QList<T>::takeLast>("takeLast").create();
  // QSet<T> toSet() const
  /// l.fun<QSet<T>, &QList<T>::toSet>("toSet").create();
  // std::list<T> toStdList() const
  /// l.fun<std::list<T>, &QList<T>::toStdList>("toStdList").create();
  // QVector<T> toVector() const
  /// l.fun<QVector<T>, &QList<T>::toVector>("toVector").create();
  // T value(int i) const
  l.fun<T, int, &QList<T>::value>("value").create();
  // T value(int i, const T &defaultValue) const
  l.fun<T, int, const T &, &QList<T>::value>("value").create();


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
