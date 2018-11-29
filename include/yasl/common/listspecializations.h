// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_LIST_SPECIALIZATIONS_H
#define YASL_COMMONS_LIST_SPECIALIZATIONS_H

#include "yasl/common/list.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/proxyspecialization.h"

template<typename T>
void register_list_specialization(script::Engine *e, script::Type::BuiltInType type_id)
{
  using namespace script;

  using List = QList<T>;

  script::ClassTemplate list_template = e->getTemplate(Engine::ListTemplate);

  std::vector<TemplateArgument> targs{
    TemplateArgument{ script::make_type<T>() }
  };

  Class list = list_template.Specialization(std::move(targs))
    .setId(type_id)
    .setFinal()
    .get();

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
  /// bind::member_function<List, QList<T>::iterator, &QList<T>::begin>(list, "begin").create();
  // const_iterator begin() const
  /// bind::member_function<List, QList<T>::const_iterator, &QList<T>::begin>(list, "begin").create();
  // const_iterator cbegin() const
  /// bind::member_function<List, QList<T>::const_iterator, &QList<T>::cbegin>(list, "cbegin").create();
  // const_iterator cend() const
  /// bind::member_function<List, QList<T>::const_iterator, &QList<T>::cend>(list, "cend").create();
  // void clear()
  bind::void_member_function<List, &QList<T>::clear>(list, "clear").create();
  // const_iterator constBegin() const
  /// bind::member_function<List, QList<T>::const_iterator, &QList<T>::constBegin>(list, "constBegin").create();
  // const_iterator constEnd() const
  /// bind::member_function<List, QList<T>::const_iterator, &QList<T>::constEnd>(list, "constEnd").create();
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
  /// bind::member_function<List, QList<T>::iterator, &QList<T>::end>(list, "end").create();
  // const_iterator end() const
  /// bind::member_function<List, QList<T>::const_iterator, &QList<T>::end>(list, "end").create();
  // bool endsWith(const T &value) const
  bind::member_function<List, bool, const T &, &QList<T>::endsWith>(list, "endsWith").create();
  // iterator erase(iterator pos)
  /// bind::member_function<List, QList<T>::iterator, QList<T>::iterator, &QList<T>::erase>(list, "erase").create();
  // iterator erase(iterator begin, iterator end)
  /// bind::member_function<List, QList<T>::iterator, QList<T>::iterator, QList<T>::iterator, &QList<T>::erase>(list, "erase").create();
  // T & first()
  /// TODO !!!
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
  /// bind::member_function<List, QList<T>::iterator, QList<T>::iterator, const T &, &QList<T>::insert>(list, "insert").create();
  // bool isEmpty() const
  bind::member_function<List, bool, &QList<T>::isEmpty>(list, "isEmpty").create();
  // T & last()
  /// TODO !!!
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
  /// TODO !!!
  // const T & operator[](int i) const
  /// TODO !!!
}

#endif // YASL_COMMONS_LIST_SPECIALIZATIONS_H
