// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_LIST_SPECIALIZATIONS_H
#define YASL_COMMONS_LIST_SPECIALIZATIONS_H

#include "yasl/common/list.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/iterators.h"
#include "yasl/common/proxyspecialization.h"

namespace script
{
namespace callbacks
{

namespace list
{


} // namespace list

} // namespace callbacks
} // namespace script

template<typename T>
void register_list_const_iterator(script::Class & map)
{
  using namespace script;

  using List = QList<T>;
  using Iter = typename List::const_iterator;

  Class iterator = map.newNestedClass("const_iterator").setId(make_type<Iter>().data()).get();

  // const_iterator()
  bind::default_constructor<Iter>(iterator).create();
  // const_iterator(const const_iterator &)
  bind::copy_constructor<Iter>(iterator).create();
  // ~const_iterator()
  bind::destructor<Iter>(iterator).create();

  // const T value() const
  bind::const_iter_deref<Iter, T>(iterator, "value");

  // const_iterator & operator=(const const_iterator &);
  bind::memop_assign<Iter, const Iter &>(iterator);
  // bool operator!=(const const_iterator & other) const;
  bind::memop_neq<Iter, const Iter &>(iterator);
  // bool operator==(const const_iterator & other) const;
  bind::memop_eq<Iter, const Iter &>(iterator);
  // const_iterator operator+(int n) const;
  bind::memop_add<Iter, Iter, int>(iterator);
  // const_iterator & operator++()
  bind::memop_preincr<Iter>(iterator);
  // const_iterator operator++(int)
  bind::memop_postincr<Iter>(iterator);
  // const_iterator & operator+=(int n);
  bind::memop_add_assign<Iter, int>(iterator);
  // const_iterator operator-(int n) const;
  bind::memop_sub<Iter, Iter, int>(iterator);
  // const_iterator & operator--()
  bind::memop_predecr<Iter>(iterator);
  // const_iterator operator--(int)
  bind::memop_postdecr<Iter>(iterator);
  // const_iterator & operator-=(int n);
  bind::memop_sub_assign<Iter, int>(iterator);
}

template<typename T>
void register_list_iterator(script::Class & map)
{
  using namespace script;

  using List = QList<T>;
  using Iter = typename List::iterator;

  Class iterator = map.newNestedClass("iterator").setId(make_type<Iter>().data()).get();

  // iterator()
  bind::default_constructor<Iter>(iterator).create();
  // iterator(const iterator &)
  bind::copy_constructor<Iter>(iterator).create();
  // ~iterator()
  bind::destructor<Iter>(iterator).create();

  // T & value() const
  bind::iter_deref<Iter, T>(iterator, "value");

  // iterator & operator=(const iterator &);
  bind::memop_assign<Iter, const Iter &>(iterator);
  // bool operator!=(const iterator & other) const;
  bind::memop_neq<Iter, const Iter &>(iterator);
  // bool operator==(const iterator & other) const;
  bind::memop_eq<Iter, const Iter &>(iterator);
  // iterator operator+(int n) const;
  bind::memop_add<Iter, Iter, int>(iterator);
  // iterator & operator++()
  bind::memop_preincr<Iter>(iterator);
  // iterator operator++(int)
  bind::memop_postincr<Iter>(iterator);
  // iterator & operator+=(int n);
  bind::memop_add_assign<Iter, int>(iterator);
  // iterator operator-(int n) const;
  bind::memop_sub<Iter, Iter, int>(iterator);
  // iterator & operator--()
  bind::memop_predecr<Iter>(iterator);
  // iterator operator--(int)
  bind::memop_postdecr<Iter>(iterator);
  // iterator & operator-=(int n);
  bind::memop_sub_assign<Iter, int>(iterator);
}

template<typename T>
script::Type register_list_specialization(script::Engine *e)
{
  using namespace script;

  using List = QList<T>;
  using Iterator = typename QList<T>::iterator;
  using ConstIterator = typename QList<T>::const_iterator;

  register_proxy_specialization<T>(e);

  script::Type type_id = make_type<QList<T>>();
  Class list = e->typeSystem()->getClass(type_id);
  if (!list.isNull() && type_id == list.id())
    return type_id;

  script::ClassTemplate list_template = ClassTemplate::get<ListTemplate>(e);

  std::vector<TemplateArgument> targs{
    TemplateArgument{ script::make_type<T>() }
  };

  list = list_template.Specialization(std::move(targs))
    .setId(type_id.data())
    .setFinal()
    .get();

  register_list_const_iterator<T>(list);
  register_list_iterator<T>(list);

  // QList<T>();
  bind::default_constructor<List>(list).create();
  // QList<T>(const QList<T> &);
  bind::copy_constructor<List>(list).create();
  // ~QList<T>();
  bind::destructor<List>(list).create();

  // void append(const T &value)
  bind::void_member_function<List, const T &, &QList<T>::append>(list, "append").create();
  // void append(const QList<T> &value)
  bind::void_member_function<List, const QList<T> &, &QList<T>::append>(list, "append").create();
  // const T & at(int i) const
  bind::member_function<List, const T &, int, &QList<T>::at>(list, "at").create();
  // T & back()
  bind::non_const_getter<List, T&, &QList<T>::back>(list, "back").create();
  // const T & back() const
  bind::member_function<List, const T &, &QList<T>::back>(list, "back").create();
  // iterator begin()
  bind::member_function<List, Iterator, &QList<T>::begin>(list, "begin").create();
  // const_iterator begin() const
  bind::member_function<List, ConstIterator, &QList<T>::begin>(list, "begin").create();
  // const_iterator cbegin() const
  bind::member_function<List, ConstIterator, &QList<T>::cbegin>(list, "cbegin").create();
  // const_iterator cend() const
  bind::member_function<List, ConstIterator, &QList<T>::cend>(list, "cend").create();
  // void clear()
  bind::void_member_function<List, &QList<T>::clear>(list, "clear").create();
  // const_iterator constBegin() const
  bind::member_function<List, ConstIterator, &QList<T>::constBegin>(list, "constBegin").create();
  // const_iterator constEnd() const
  bind::member_function<List, ConstIterator, &QList<T>::constEnd>(list, "constEnd").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  // const T & constFirst() const
  bind::member_function<List, const T &, &QList<T>::constFirst>(list, "constFirst").create();
  // const T & constLast() const
  bind::member_function<List, const T &, &QList<T>::constLast>(list, "constLast").create();
#endif
  // bool contains(const T &value) const
  bind::member_function<List, bool, const T &, &QList<T>::contains>(list, "contains").create();
  // int count(const T &value) const
  bind::member_function<List, int, const T &, &QList<T>::count>(list, "count").create();
  // int count() const
  bind::member_function<List, int, &QList<T>::count>(list, "count").create();
  // const_reverse_iterator crbegin() const
  /// bind::member_function<List, QList<T>::const_reverse_iterator, &QList<T>::crbegin>(list, "crbegin").create();
  // const_reverse_iterator crend() const
  /// bind::member_function<List, QList<T>::const_reverse_iterator, &QList<T>::crend>(list, "crend").create();
  // bool empty() const
  bind::member_function<List, bool, &QList<T>::empty>(list, "empty").create();
  // iterator end()
  bind::member_function<List, Iterator, &QList<T>::end>(list, "end").create();
  // const_iterator end() const
  bind::member_function<List, ConstIterator, &QList<T>::end>(list, "end").create();
  // bool endsWith(const T &value) const
  bind::member_function<List, bool, const T &, &QList<T>::endsWith>(list, "endsWith").create();
  // iterator erase(iterator pos)
  bind::member_function<List, Iterator, Iterator, &QList<T>::erase>(list, "erase").create();
  // iterator erase(iterator begin, iterator end)
  bind::member_function<List, Iterator, Iterator, Iterator, &QList<T>::erase>(list, "erase").create();
  // T & first()
  bind::non_const_getter<List, T&, &List::first>(list, "first");
  // const T & first() const
  bind::member_function<List, const T &, &QList<T>::first>(list, "first").create();
  // T & front()
  bind::non_const_getter<List, T&, &QList<T>::front>(list, "front").create();
  // const T & front() const
  bind::member_function<List, const T &, &QList<T>::front>(list, "front").create();
  // int indexOf(const T &value, int from = 0) const
  bind::member_function<List, int, const T &, int, &QList<T>::indexOf>(list, "indexOf").create();
  // void insert(int i, const T &value)
  bind::void_member_function<List, int, const T &, &QList<T>::insert>(list, "insert").create();
  // iterator insert(iterator before, const T &value)
  bind::member_function<List, Iterator, Iterator, const T &, &QList<T>::insert>(list, "insert").create();
  // bool isEmpty() const
  bind::member_function<List, bool, &QList<T>::isEmpty>(list, "isEmpty").create();
  // T & last()
  bind::non_const_getter<List, T&, &QList<T>::last>(list, "last").create();
  // const T & last() const
  bind::member_function<List, const T &, &QList<T>::last>(list, "last").create();
  // int lastIndexOf(const T &value, int from = -1) const
  bind::member_function<List, int, const T &, int, &QList<T>::lastIndexOf>(list, "lastIndexOf").create();
  // int length() const
  bind::member_function<List, int, &QList<T>::length>(list, "length").create();
  // QList<T> mid(int pos, int length = -1) const
  bind::member_function<List, QList<T>, int, int, &QList<T>::mid>(list, "mid").create();
  // void move(int from, int to)
  bind::void_member_function<List, int, int, &QList<T>::move>(list, "move").create();
  // void pop_back()
  bind::void_member_function<List, &QList<T>::pop_back>(list, "pop_back").create();
  // void pop_front()
  bind::void_member_function<List, &QList<T>::pop_front>(list, "pop_front").create();
  // void prepend(const T &value)
  bind::void_member_function<List, const T &, &QList<T>::prepend>(list, "prepend").create();
  // void push_back(const T &value)
  bind::void_member_function<List, const T &, &QList<T>::push_back>(list, "push_back").create();
  // void push_front(const T &value)
  bind::void_member_function<List, const T &, &QList<T>::push_front>(list, "push_front").create();
  // reverse_iterator rbegin()
  /// bind::member_function<List, QList<T>::reverse_iterator, &QList<T>::rbegin>(list, "rbegin").create();
  // const_reverse_iterator rbegin() const
  /// bind::member_function<List, QList<T>::const_reverse_iterator, &QList<T>::rbegin>(list, "rbegin").create();
  // int removeAll(const T &value)
  bind::member_function<List, int, const T &, &QList<T>::removeAll>(list, "removeAll").create();
  // void removeAt(int i)
  bind::void_member_function<List, int, &QList<T>::removeAt>(list, "removeAt").create();
  // void removeFirst()
  bind::void_member_function<List, &QList<T>::removeFirst>(list, "removeFirst").create();
  // void removeLast()
  bind::void_member_function<List, &QList<T>::removeLast>(list, "removeLast").create();
  // bool removeOne(const T &value)
  bind::member_function<List, bool, const T &, &QList<T>::removeOne>(list, "removeOne").create();
  // reverse_iterator rend()
  /// bind::member_function<List, QList<T>::reverse_iterator, &QList<T>::rend>(list, "rend").create();
  // const_reverse_iterator rend() const
  /// bind::member_function<List, QList<T>::const_reverse_iterator, &QList<T>::rend>(list, "rend").create();
  // void replace(int i, const T &value)
  bind::void_member_function<List, int, const T &, &QList<T>::replace>(list, "replace").create();
  // void reserve(int alloc)
  bind::void_member_function<List, int, &QList<T>::reserve>(list, "reserve").create();
  // int size() const
  bind::member_function<List, int, &QList<T>::size>(list, "size").create();
  // bool startsWith(const T &value) const
  bind::member_function<List, bool, const T &, &QList<T>::startsWith>(list, "startsWith").create();
  // void swap(QList<T> &other)
  bind::void_member_function<List, QList<T> &, &QList<T>::swap>(list, "swap").create();
  // void swap(int i, int j)
  bind::void_member_function<List, int, int, &QList<T>::swap>(list, "swap").create();
  // T takeAt(int i)
  bind::member_function<List, T, int, &QList<T>::takeAt>(list, "takeAt").create();
  // T takeFirst()
  bind::member_function<List, T, &QList<T>::takeFirst>(list, "takeFirst").create();
  // T takeLast()
  bind::member_function<List, T, &QList<T>::takeLast>(list, "takeLast").create();
  // QSet<T> toSet() const
  /// bind::member_function<List, QSet<T>, &QList<T>::toSet>(list, "toSet").create();
  // std::list<T> toStdList() const
  /// bind::member_function<List, std::list<T>, &QList<T>::toStdList>(list, "toStdList").create();
  // QVector<T> toVector() const
  /// bind::member_function<List, QVector<T>, &QList<T>::toVector>(list, "toVector").create();
  // T value(int i) const
  bind::member_function<List, T, int, &QList<T>::value>(list, "value").create();
  // T value(int i, const T &defaultValue) const
  bind::member_function<List, T, int, const T &, &QList<T>::value>(list, "value").create();


  // bool operator!=(const QList<T> &other) const
  bind::memop_neq<List, const QList<T> &>(list);
  // QList<T> operator+(const QList<T> &other) const
  bind::memop_add<List, QList<T>, const QList<T> &>(list);
  // QList<T> & operator+=(const QList<T> &other)
  bind::memop_add_assign<List, const QList<T> &>(list);
  // QList<T> & operator+=(const T &value)
  bind::memop_add_assign<List, const T &>(list);
  // QList<T> & operator<<(const QList<T> &other)
  /// TODO !!!
  // QList<T> & operator<<(const T &value)
  /// TODO !!!
  // QList<T> & operator=(const QList<T> &other)
  bind::memop_assign<List, const QList<T> &>(list);
  // QList & operator=(QList<T> &&other)
  /// TODO !!!
  // bool operator==(const QList<T> &other) const
  bind::memop_eq<List, const QList<T> &>(list);
  // T & operator[](int i)
  bind::memop_proxy_subscript<List, T&, int>(list);
  // const T & operator[](int i) const
  /// TODO !!!

  return list.id();
}

#endif // YASL_COMMONS_LIST_SPECIALIZATIONS_H
