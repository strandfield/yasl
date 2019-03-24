// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_SET_SPECIALIZATIONS_H
#define YASL_COMMONS_SET_SPECIALIZATIONS_H

#include "yasl/common/set.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/listspecializations.h"
#include "yasl/common/proxy.h"

#include <script/classtemplatespecializationbuilder.h>
#include <script/namespace.h>
#include <script/userdata.h>
#include <script/interpreter/executioncontext.h>

namespace script
{
namespace callbacks
{

namespace set
{

} // namespace set

} // namespace callbacks
} // namespace script

template<typename T>
void register_set_const_iterator(script::Class & map)
{
  using namespace script;

  using Set = QSet<T>;
  using Iter = typename Set::const_iterator;

  Class iterator = map.newNestedClass("const_iterator").setId(make_type<Iter>().data()).get();

  // const_iterator()
  bind::default_constructor<Iter>(iterator).create();
  // const_iterator(const const_iterator &)
  bind::copy_constructor<Iter>(iterator).create();
  // ~const_iterator()
  bind::destructor<Iter>(iterator).create();

  // T value() const
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
void register_set_iterator(script::Class & map)
{
  using namespace script;

  using Set = QSet<T>;
  using Iter = typename Set::const_iterator;
  using ConstIterator = typename Set::const_iterator;

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

  // bool operator!=(const iterator & other) const;
  bind::memop_neq<Iter, const ConstIterator &>(iterator);
  // bool operator==(const iterator & other) const;
  bind::memop_eq<Iter, const ConstIterator &>(iterator);
}

template<typename T>
script::Type register_set_specialization(script::Engine *engine)
{
  using namespace script;

  using Set = QSet<T>;
  using Iterator = typename Set::const_iterator;
  using ConstIterator = typename Set::const_iterator;

  const Type type_id = script::make_type<Set>();
  Class set = engine->getClass(type_id);
  if (!set.isNull() && type_id == set.id())
    return type_id;

  std::vector<TemplateArgument> targs{
    TemplateArgument{ script::make_type<T>() }
  };

  ClassTemplate set_template = engine->getTemplate(Engine::SetTemplate);

  set = set_template.Specialization(std::move(targs))
    .setId(type_id.data())
    .setFinal()
    .get();

  register_set_const_iterator<T>(set);
  register_set_iterator<T>(set);

  register_list_specialization<T>(engine);

  // QSet();
  bind::default_constructor<Set>(set).create();
  // QSet(const QSet &);
  bind::copy_constructor<Set>(set).create();
  // ~QSet();
  bind::destructor<Set>(set).create();

  // iterator begin();
  bind::member_function<Set, Iterator, &Set::begin>(set, "begin").create();
  // const_iterator begin() const;
  bind::member_function<Set, ConstIterator, &Set::begin>(set, "begin").create();
  // int capacity() const;
  bind::member_function<Set, int, &Set::capacity>(set, "capacity").create();
  // const_iterator cbegin() const;
  bind::member_function<Set, ConstIterator, &Set::cbegin>(set, "cbegin").create();
  // const_iterator cend() const;
  bind::member_function<Set, ConstIterator, &Set::cend>(set, "cend").create();
  // void clear();
  bind::void_member_function<Set, &Set::clear>(set, "clear").create();
  // const_iterator constBegin() const;
  bind::member_function<Set, ConstIterator, &Set::constBegin>(set, "constBegin").create();
  // const_iterator constEnd() const;
  bind::member_function<Set, ConstIterator, &Set::constEnd>(set, "constEnd").create();
  // const_iterator constFind(const T &) const;
  bind::member_function<Set, ConstIterator, const T &, &Set::constFind>(set, "constFind").create();
  // bool contains(const T & value) const;
  bind::member_function<Set, bool, const T &, &Set::contains>(set, "contains").create();
  // bool contains(const QSet<T> & other) const;
  bind::member_function<Set, bool, const QSet<T> &, &Set::contains>(set, "contains").create();
  // int count() const;
  bind::member_function<Set, int, &Set::count>(set, "count").create();
  // bool empty() const;
  bind::member_function<Set, bool, &Set::empty>(set, "empty").create();
  // iterator end();
  bind::member_function<Set, Iterator, &Set::end>(set, "end").create();
  // const_iterator end() const;
  bind::member_function<Set, ConstIterator, &Set::end>(set, "end").create();
  // iterator erase(iterator pos);
  bind::member_function<Set, Iterator, Iterator, &Set::erase>(set, "erase").create();
  // iterator find(const T &);
  bind::member_function<Set, Iterator, const T &, &Set::find>(set, "find").create();
  // const_iterator find(const Key &) const;
  bind::member_function<Set, ConstIterator, const T &, &Set::find>(set, "find").create();
  // iterator insert(const T & value);
  bind::member_function<Set, Iterator, const T &, &Set::insert>(set, "insert").create();
  // QSet<T> & intersect(const QSet<T> & other);
  bind::chainable_memfn<Set, const QSet<T> &, &Set::intersect>(set, "intersect").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // bool intersects(const QSet<T> & other) const;
  bind::member_function<Set, bool, const QSet<T> &, &Set::intersects>(set, "intersects").create();
#endif
  // bool isEmpty() const;
  bind::member_function<Set, bool, &Set::isEmpty>(set, "isEmpty").create();
  // bool remove(const T & value);
  bind::member_function<Set, bool, const T &, &Set::remove>(set, "remove").create();
  // void reserve(int size);
  bind::void_member_function<Set, int, &Set::reserve>(set, "reserve").create();
  // int size() const;
  bind::member_function<Set, int, &Set::size>(set, "size").create();
  // void squeeze();
  bind::void_member_function<Set, &Set::squeeze>(set, "squeeze").create();
  // QSet<T> & subtract(const QSet<T> & other);
  bind::chainable_memfn<Set, const QSet<T> &, &Set::subtract>(set, "subtract").create();
  // void swap(QSet<T> & other);
  bind::void_member_function<Set, Set &, &Set::swap>(set, "swap").create();
  // QList<T> toList() const;
  bind::member_function<Set, QList<T>, &Set::toList>(set, "toList").create();
  // QSet & unite(const QSet &);
  bind::chainable_memfn<Set, const Set &, &Set::unite>(set, "unite").create();
  // QList<T> values() const;
  bind::member_function<Set, QList<T>, &Set::values>(set, "values").create();

  // QSet & operator=(const QSet &);
  bind::memop_assign<Set, const Set &>(set);
  // bool operator!=(const QSet &) const;
  bind::memop_neq<Set, const Set &>(set);
  // bool operator==(const QSet &) const;
  bind::memop_eq<Set, const Set &>(set);
  // QSet<T> operator&(const QSet<T> & other) const;
  bind::memop_bitand<Set, Set, const Set &>(set);
  // QSet<T> & operator&=(const QSet<T> & other);
  bind::memop_and_assign<Set, const Set &>(set);
  // QSet<T> & operator&=(const T & value);
  bind::memop_and_assign<Set, const T &>(set);
  // QSet<T> operator+(const QSet<T> & other) const;
  bind::memop_add<Set, Set, const Set &>(set);
  // QSet<T> & operator+=(const QSet<T> & other);
  bind::memop_add_assign<Set, const Set &>(set);
  // QSet<T> & operator+=(const T & value);
  bind::memop_add_assign<Set, const T &>(set);
  // QSet<T> operator-(const QSet<T> & other) const;
  bind::memop_sub<Set, Set, const Set &>(set);
  // QSet<T> & operator-=(const QSet<T> & other);
  bind::memop_sub_assign<Set, const Set &>(set);
  // QSet<T> & operator-=(const T & value);
  bind::memop_sub_assign<Set, const T &>(set);
  // QSet<T> & operator<<(const T & value);
  bind::memop_put_to<Set, const T &>(set);
  // QSet<T> operator|(const QSet<T> & other) const;
  bind::memop_bitor<Set, Set, const Set &>(set);
  // QSet<T> & operator|=(const QSet<T> & other);
  bind::memop_or_assign<Set, const Set &>(set);
  // QSet<T> & operator|=(const T & value);
  bind::memop_or_assign<Set, const T &>(set);

  return set.id();
}

#endif // YASL_COMMONS_SET_SPECIALIZATIONS_H
