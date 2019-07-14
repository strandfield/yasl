// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_MAP_SPECIALIZATIONS_H
#define YASL_COMMONS_MAP_SPECIALIZATIONS_H

#include "yasl/common/map.h"

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

namespace map
{

} // namespace map

} // namespace callbacks
} // namespace script

template<typename Key, typename T>
void register_map_const_iterator(script::Class & map)
{
  using namespace script;

  using Map = QMap<Key, T>;
  using Iter = typename Map::const_iterator;

  Class iterator = map.newNestedClass("const_iterator").setId(make_type<Iter>().data()).get();

  // const_iterator()
  bind::default_constructor<Iter>(iterator).create();
  // const_iterator(const const_iterator &)
  bind::copy_constructor<Iter>(iterator).create();
  // ~const_iterator()
  bind::destructor<Iter>(iterator).create();

  // Key key() const
  bind::member_function<Iter, const Key &, &Iter::key>(iterator, "key").create();
  // T value() const
  bind::member_function<Iter, const T &, &Iter::value>(iterator, "value").create();

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

template<typename Key, typename T>
void register_map_iterator(script::Class & map)
{
  using namespace script;

  using Map = QMap<Key, T>;
  using Iter = typename Map::iterator;
  using ConstIterator = typename Map::const_iterator;

  Class iterator = map.newNestedClass("iterator").setId(make_type<Iter>().data()).get();

  // iterator()
  bind::default_constructor<Iter>(iterator).create();
  // iterator(const iterator &)
  bind::copy_constructor<Iter>(iterator).create();
  // ~iterator()
  bind::destructor<Iter>(iterator).create();

  // Key key() const
  bind::member_function<Iter, const Key &, &Iter::key>(iterator, "key").create();
  // T & value() const
  bind::getter<Iter, T&, &Iter::value>(iterator, "value").create();

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

template<typename Key, typename T>
script::Type register_map_specialization(script::Engine *engine)
{
  using namespace script;

  using Map = QMap<Key, T>;
  using Iterator = typename QMap<Key, T>::iterator;
  using ConstIterator = typename QMap<Key, T>::const_iterator;

  const Type type_id = script::make_type<Map>();
  Class map = engine->typeSystem()->getClass(type_id);
  if (!map.isNull() && type_id == map.id())
    return type_id;

  std::vector<TemplateArgument> targs{
    TemplateArgument{ script::make_type<Key>() },
    TemplateArgument{ script::make_type<T>() }
  };

  ClassTemplate map_template = ClassTemplate::get<MapTemplate>(engine);

  map = map_template.Specialization(std::move(targs))
    .setId(type_id.data())
    .setFinal()
    .get();

  register_map_const_iterator<Key, T>(map);
  register_map_iterator<Key, T>(map);

  register_list_specialization<Key>(engine);
  register_list_specialization<T>(engine);

  // QMap();
  bind::default_constructor<Map>(map).create();
  // QMap(const QMap &);
  bind::copy_constructor<Map>(map).create();
  // ~QMap();
  bind::destructor<Map>(map).create();

  // iterator begin();
  bind::member_function<Map, Iterator, &Map::begin>(map, "begin").create();
  // const_iterator begin() const;
  bind::member_function<Map, ConstIterator, &Map::begin>(map, "begin").create();
  // const_iterator cbegin() const;
  bind::member_function<Map, ConstIterator, &Map::cbegin>(map, "cbegin").create();
  // const_iterator cend() const;
  bind::member_function<Map, ConstIterator, &Map::cend>(map, "cend").create();
  // void clear();
  bind::void_member_function<Map, &Map::clear>(map, "clear").create();
  // const_iterator constBegin() const;
  bind::member_function<Map, ConstIterator, &Map::constBegin>(map, "constBegin").create();
  // const_iterator constEnd() const;
  bind::member_function<Map, ConstIterator, &Map::constEnd>(map, "constEnd").create();
  // const_iterator constFind(const Key &) const;
  bind::member_function<Map, ConstIterator, const Key &, &Map::constFind>(map, "constFind").create();
  // bool contains(const Key & k) const;
  bind::member_function<Map, bool, const Key &, &Map::contains>(map, "contains").create();
  // int count(const Key & k) const;
  bind::member_function<Map, int, const Key &, &Map::count>(map, "count").create();
  // int count() const;
  bind::member_function<Map, int, &Map::count>(map, "count").create();
  // bool empty() const;
  bind::member_function<Map, bool, &Map::empty>(map, "empty").create();
  // iterator end();
  bind::member_function<Map, Iterator, &Map::end>(map, "end").create();
  // const_iterator end() const;
  bind::member_function<Map, ConstIterator, &Map::end>(map, "end").create();
  // iterator erase(iterator pos);
  bind::member_function<Map, Iterator, Iterator, &Map::erase>(map, "erase").create();
  // iterator find(const Key &);
  bind::member_function<Map, Iterator, const Key &, &Map::find>(map, "find").create();
  // const_iterator find(const Key &) const;
  bind::member_function<Map, ConstIterator, const Key &, &Map::find>(map, "find").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // T & first()
  bind::non_const_getter<Map, T&, &Map::first>(map, "first").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // T first() const
  bind::member_function<Map, const T &, &Map::first>(map, "first").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // Key firstKey() const;
  bind::member_function<Map, const Key &, &Map::firstKey>(map, "firstKey").create();
#endif
  // iterator insert(const Key & k, const T & value);
  bind::member_function<Map, Iterator, const Key &, const T &, &Map::insert>(map, "insert").create();
  // iterator insertMulti(const Key & k, const T & value);
  bind::member_function<Map, Iterator, const Key &, const T &, &Map::insertMulti>(map, "insert").create();
  // bool isEmpty() const;
  bind::member_function<Map, bool, &Map::isEmpty>(map, "isEmpty").create();
  // const Key key(const T & value, const Key & defaultKey = Key{});
  bind::member_function<Map, const Key, const T &, const Key &, &Map::key>(map, "key")
    .apply(bind::default_arguments(Key{})).create();
  // QList<Key> keys() const;
  bind::member_function<Map, QList<Key>, &Map::keys>(map, "keys").create();
  // QList<Key> keys(const T & value) const;
  bind::member_function<Map, QList<Key>, const T &, &Map::keys>(map, "keys").create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // T & last()
  bind::non_const_getter<Map, T&, &Map::last>(map, "last").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // T last() const
  bind::member_function<Map, const T &, &Map::last>(map, "last").create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // Key lastKey() const;
  bind::member_function<Map, const Key &, &Map::lastKey>(map, "lastKey").create();
#endif
  // int remove(const Key & k);
  bind::member_function<Map, int, const Key &, &Map::remove>(map, "remove").create();
  // int size() const;
  bind::member_function<Map, int, &Map::size>(map, "size").create();
  // void swap(QMap & other);
  bind::void_member_function<Map, Map &, &Map::swap>(map, "swap").create();
  // T take(const Key & k);
  bind::member_function<Map, T, const Key &, &Map::take>(map, "take").create();
  // QList<Key> uniqueKeys() const;
  bind::member_function<Map, QList<Key>, &Map::uniqueKeys>(map, "uniqueKeys").create();
  // Map & unite(const Map &);
  bind::chainable_memfn<Map, const Map &, &Map::unite>(map, "unite").create();
  // const T value(const Key & k, const T & defaultValue = T{})
  bind::member_function<Map, const T, const Key &, const T &, &Map::value>(map, "value")
    .apply(bind::default_arguments(T{})).create();
  // QList<T> values() const;
  bind::member_function<Map, QList<T>, &Map::values>(map, "values").create();
  // QList<T> values(const Key & k) const;
  bind::member_function<Map, QList<T>, const Key &, &Map::values>(map, "values").create();

  // QMap & operator=(const QMap &);
  bind::memop_assign<Map, const Map &>(map);
  // bool operator!=(const QMap &) const;
  bind::memop_neq<Map, const Map &>(map);
  // bool operator==(const QMap &) const;
  bind::memop_eq<Map, const Map &>(map);
  // T & operator[](const Key & k);
  bind::memop_proxy_subscript<Map, T&, const Key &>(map);
  // T operator[](const Key & k) const;
  bind::memop_subscript<Map, T, const Key &>(map);

  return map.id();
}

#endif // YASL_COMMONS_MAP_SPECIALIZATIONS_H
