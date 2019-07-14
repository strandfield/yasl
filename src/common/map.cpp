// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/map.h"
#include "yasl/common/mapspecializations.h"

#include "yasl/common/list.h"
#include "yasl/common/value.h"

#include <script/classtemplate.h>
#include <script/classtemplateinstancebuilder.h>
#include <script/constructorbuilder.h>
#include <script/templatebuilder.h>

#include <cstring>

using Map = QMap<yasl::Value, yasl::Value>;
using ConstIterator = QMap<yasl::Value, yasl::Value>::const_iterator;
using Iterator = QMap<yasl::Value, yasl::Value>::iterator;

struct MapData : public script::UserData
{
  ~MapData() = default;

  std::shared_ptr<yasl::TypeInfo> Key;
  std::shared_ptr<yasl::TypeInfo> T;

  static std::shared_ptr<MapData> get(script::Engine *e, const script::Type & Key, const script::Type & T)
  {
    auto ret = std::make_shared<MapData>();
    ret->Key = yasl::TypeInfo::get(e, Key);
    ret->T = yasl::TypeInfo::get(e, T);

    if (!ret->Key->hasLess())
      throw script::TemplateInstantiationError{"Map key must have operator<"};

    return ret;
  }
};

static script::Value make_map(const QMap<yasl::Value, yasl::Value> & val, const script::Type & map_type, script::Engine *e)
{
  script::Value ret = e->allocate(map_type);

  script::ThisObject(ret).init<QMap<yasl::Value, yasl::Value>>(val);

  return ret;
}

static script::Value make_iter(const Iterator& val, const script::Type& iter_type, script::Engine* e)
{
  script::Value ret = e->allocate(iter_type);

  script::ThisObject(ret).init<Iterator>(val);

  return ret;
}

static script::Value make_const_iter(const ConstIterator & val, const script::Type & iter_type, script::Engine *e)
{
  script::Value ret = e->allocate(iter_type);

  script::ThisObject(ret).init<ConstIterator>(val);

  return ret;
}

static Map & get_map(const script::Value & val)
{
  return script::get<Map>(val);
}

static Iterator & get_iter(const script::Value & val)
{
  return script::get<Iterator>(val);
}

static ConstIterator & get_const_iter(const script::Value & val)
{
  return script::get<ConstIterator>(val);
}

namespace script
{

namespace callbacks
{

namespace map
{

namespace const_iterator
{

// const_iterator()
script::Value default_ctor(script::FunctionCall *c)
{
  c->thisObject().init<ConstIterator>();
  return c->thisObject();
}

// const_iterator(const const_iterator &)
script::Value copy_ctor(script::FunctionCall *c)
{
  const ConstIterator & other = get_const_iter(c->arg(1));
  c->thisObject().init<ConstIterator>(other);
  return c->thisObject();
}

// ~const_iterator()
script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().destroy<ConstIterator>();
  return script::Value::Void;
}

// const Key& key() const
script::Value key(script::FunctionCall *c)
{
  const ConstIterator & self = get_const_iter(c->thisObject());
  return self.key().get();
}

// const T & value() const
script::Value value(script::FunctionCall *c)
{
  const ConstIterator & self = get_const_iter(c->thisObject());
  return self.value().get();
}

// const_iterator & operator=(const const_iterator &);
script::Value op_assign(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->thisObject());
  const ConstIterator & other = get_const_iter(c->arg(1));
  self = other;
  return c->thisObject();
}

// bool operator!=(const const_iterator & other) const;
script::Value op_neq(script::FunctionCall *c)
{
  const ConstIterator & self = get_const_iter(c->arg(0));
  const ConstIterator & other = get_const_iter(c->arg(1));
  return c->engine()->newBool(self != other);
}

// bool operator==(const const_iterator & other) const;
script::Value op_eq(script::FunctionCall *c)
{
  const ConstIterator & self = get_const_iter(c->arg(0));
  const ConstIterator & other = get_const_iter(c->arg(1));
  return c->engine()->newBool(self == other);
}

// const_iterator operator+(int n) const;
script::Value op_add(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->arg(0));
  int n = c->arg(1).toInt();
  return make_const_iter(self + n, c->callee().returnType(), c->engine());
}

// const_iterator & operator++()
script::Value op_preincr(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->arg(0));
  ++self;
  return c->thisObject();
}

// const_iterator operator++(int)
script::Value op_postincr(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->arg(0));
  return make_const_iter(self++, c->callee().returnType(), c->engine());
}

// const_iterator & operator+=(int n);
script::Value op_addassign(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->arg(0));
  int n = c->arg(1).toInt();
  self += n;
  return c->thisObject();
}

// const_iterator operator-(int n) const;
script::Value op_sub(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->arg(0));
  int n = c->arg(1).toInt();
  return make_const_iter(self - n, c->callee().returnType(), c->engine());
}

// const_iterator & operator--()
script::Value op_predecr(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->arg(0));
  --self;
  return c->thisObject();
}

// const_iterator operator--(int)
script::Value op_postdecr(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->arg(0));
  return make_const_iter(self--, c->callee().returnType(), c->engine());
}

// const_iterator & operator-=(int n);
script::Value op_subassign(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->arg(0));
  int n = c->arg(1).toInt();
  self -= n;
  return c->thisObject();
}

} // namespace const_iterator

namespace iterator
{

// iterator()
script::Value default_ctor(script::FunctionCall *c)
{
  c->thisObject().init<Iterator>();
  return c->thisObject();
}

// iterator(const iterator &)
script::Value copy_ctor(script::FunctionCall *c)
{
  const Iterator& other = get_iter(c->arg(1));
  c->thisObject().init<Iterator>(other);
  return c->thisObject();
}

// ~iterator()
script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().destroy<Iterator>();
  return script::Value::Void;
}

// const Key& key() const
script::Value key(script::FunctionCall *c)
{
  const Iterator & self = get_iter(c->thisObject());
  return self.key().get();
}

// T & value() const
script::Value value(script::FunctionCall *c)
{
  const Iterator & self = get_iter(c->thisObject());
  return self.value().get();
}

// iterator & operator=(const iterator &);
script::Value op_assign(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->thisObject());
  const Iterator & other = get_iter(c->arg(1));
  self = other;
  return c->thisObject();
}

// bool operator!=(const iterator & other) const;
script::Value op_neq(script::FunctionCall *c)
{
  const Iterator & self = get_iter(c->arg(0));
  const Iterator & other = get_iter(c->arg(1));
  return c->engine()->newBool(self != other);
}

// bool operator==(const iterator & other) const;
script::Value op_eq(script::FunctionCall *c)
{
  const Iterator & self = get_iter(c->arg(0));
  const Iterator & other = get_iter(c->arg(1));
  return c->engine()->newBool(self == other);
}

// iterator operator+(int n) const;
script::Value op_add(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->arg(0));
  int n = c->arg(1).toInt();
  return make_const_iter(self + n, c->callee().returnType(), c->engine());
}

// iterator & operator++()
script::Value op_preincr(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->arg(0));
  ++self;
  return c->thisObject();
}

// iterator operator++(int)
script::Value op_postincr(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->arg(0));
  return make_const_iter(self++, c->callee().returnType(), c->engine());
}

// iterator & operator+=(int n);
script::Value op_addassign(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->arg(0));
  int n = c->arg(1).toInt();
  self += n;
  return c->thisObject();
}

// iterator operator-(int n) const;
script::Value op_sub(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->arg(0));
  int n = c->arg(1).toInt();
  return make_const_iter(self - n, c->callee().returnType(), c->engine());
}

// iterator & operator--()
script::Value op_predecr(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->arg(0));
  --self;
  return c->thisObject();
}

// iterator operator--(int)
script::Value op_postdecr(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->arg(0));
  return make_const_iter(self--, c->callee().returnType(), c->engine());
}

// iterator & operator-=(int n);
script::Value op_subassign(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->arg(0));
  int n = c->arg(1).toInt();
  self -= n;
  return c->thisObject();
}

} // namespace iterator


// QMap()
script::Value default_ctor(script::FunctionCall *c)
{
  c->thisObject().init<QMap<yasl::Value, yasl::Value>>();
  return c->thisObject();
}

// QMap(const QMap &)
script::Value copy_ctor(script::FunctionCall *c)
{
  auto & other = script::get<QMap<yasl::Value, yasl::Value>>(c->arg(1));
  c->thisObject().init<QMap<yasl::Value, yasl::Value>>(other);
  return c->thisObject();
}

// ~QMap()
script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().destroy<QMap<yasl::Value, yasl::Value>>();
  return script::Value::Void;
}

// iterator begin();
script::Value begin(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return make_iter(self.begin(), c->callee().returnType(), c->engine());
}

// const_iterator cbegin();
// const_iterator constBegin() const;
script::Value cbegin(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return make_const_iter(self.cbegin(), c->callee().returnType(), c->engine());
}

// const_iterator cend();
// const_iterator constEnd() const;
// const_iterator end() const;
script::Value cend(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return make_const_iter(self.cend(), c->callee().returnType(), c->engine());
}

// void clear();
script::Value clear(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  self.clear();
  return script::Value::Void;
}

// const_iterator constFind(const Key &) const;
// const_iterator find(const Key &) const;
script::Value constFind(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  return make_const_iter(self.constFind(key), c->callee().returnType(), c->engine());
}

// bool contains(const Key & k) const;
script::Value contains(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  return c->engine()->newBool(self.contains(key));
}

// int count(const Key & k) const;
script::Value count(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  return c->engine()->newInt(self.count(key));
}

// bool empty() const;
// bool isEmpty() const;
script::Value empty(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return c->engine()->newBool(self.empty());
}

// iterator end();
script::Value end(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return make_iter(self.end(), c->callee().returnType(), c->engine());
}

// iterator erase(iterator pos);
script::Value erase(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  const Iterator & iter = get_iter(c->arg(1));
  return make_iter(self.erase(iter), c->callee().returnType(), c->engine());
}

// iterator find(const Key &);
script::Value find(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  return make_iter(self.find(key), c->callee().returnType(), c->engine());
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
// T & first()
// const T & first() const
script::Value first(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return self.first().get();
}
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
// const Key & firstKey() const;
script::Value firstKey(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return self.firstKey().get();
}
#endif

// iterator insert(const Key & k, const T & value);
script::Value insert(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  yasl::ObserverValue value{ info->T, c->arg(2) };
  return make_iter(self.insert(key, value), c->callee().returnType(), c->engine());
}

// iterator insertMulti(const Key & k, const T & value);
script::Value insertMulti(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  yasl::ObserverValue value{ info->T, c->arg(2) };
  return make_iter(self.insertMulti(key, value), c->callee().returnType(), c->engine());
}

// const Key key(const T & value, const Key & defaultKey = Key{});
script::Value key(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue value{ info->T, c->arg(1) };
  yasl::Value result = self.key(value);
  if (result.isNull())
    return c->engine()->copy(c->arg(2));
  return result.release();
}

// QList<Key> keys() const;
script::Value keys(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  QList<yasl::Value> result = self.keys();
  return script::make_list(result, c->callee().returnType(), c->engine());
}

// QList<Key> keys(const T & value) const;
script::Value keys_value(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue value{ info->T, c->arg(1) };
  QList<yasl::Value> result = self.keys(value);
  return script::make_list(result, c->callee().returnType(), c->engine());
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
// T & last()
// const T & last() const
script::Value last(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return self.last().get();
}
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
// const Key & lastKey() const;
script::Value lastKey(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return self.lastKey().get();
}
#endif

// int remove(const Key & k);
script::Value remove(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  return c->engine()->newInt(self.remove(key));
}

// int count() const;
// int size() const;
script::Value size(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  return c->engine()->newInt(self.size());
}

// void swap(QMap & other);
script::Value swap(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  Map & other = get_map(c->arg(1));
  self.swap(other);
  return script::Value::Void;
}

// T take(const Key & k);
script::Value take(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  return self.take(key).release();
}

// QList<Key> uniqueKeys() const;
script::Value uniqueKeys(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  QList<yasl::Value> result = self.uniqueKeys();
  return script::make_list(result, c->callee().returnType(), c->engine());
}

// Map & unite(const Map &);
script::Value unite(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  const Map & other = get_map(c->arg(1));
  self.unite(other);
  return c->thisObject();
}


// const T value(const Key & k, const T & defaultValue = T{})
script::Value value(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  yasl::Value result = self.value(key);
  if (result.isNull())
    return c->engine()->copy(c->arg(2));
  return result.release();
}

// QList<T> values() const;
script::Value values(script::FunctionCall *c)
{
  Map & self = get_map(c->thisObject());
  QList<yasl::Value> result = self.values();
  return script::make_list(result, c->callee().returnType(), c->engine());
}

// QList<T> values(const Key & k) const;
script::Value values_key(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  QList<yasl::Value> result = self.values(key);
  return script::make_list(result, c->callee().returnType(), c->engine());
}

// QMap & operator=(const QMap &)
script::Value op_assign(script::FunctionCall *c)
{
  auto & self = script::value_cast<QMap<yasl::Value, yasl::Value> &>(c->thisObject());
  const auto & other = script::value_cast<const QMap<yasl::Value, yasl::Value> &>(c->arg(1));
  self = other;
  return c->thisObject();
}

// bool operator==(const QMap &) const
script::Value op_eq(script::FunctionCall *c)
{
  auto & self = script::value_cast<QMap<yasl::Value, yasl::Value> &>(c->thisObject());
  const auto & other = script::value_cast<const QMap<yasl::Value, yasl::Value> &>(c->arg(1));
  return c->engine()->newBool(self == other);
}

// bool operator!=(const QMap &) const
script::Value op_neq(script::FunctionCall *c)
{
  auto & self = script::value_cast<QMap<yasl::Value, yasl::Value> &>(c->thisObject());
  const auto & other = script::value_cast<const QMap<yasl::Value, yasl::Value> &>(c->arg(1));
  return c->engine()->newBool(self != other);
}

// T & operator[](const Key &)
script::Value op_subscript(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<MapData>(c->callee().memberOf().data());
  Map & self = get_map(c->thisObject());
  yasl::ObserverValue key{ info->Key, c->arg(1) };
  yasl::Value & ret = self[key];
  if (ret.isNull())
    ret = yasl::Value{ info->T, c->engine()->construct(info->T->element_type,{}) };
  return ret.get();
}

} // namespace map

} // namespace callbacks

} // namespace script


static script::Type map_template_instantiate_const_iterator(script::Class & map)
{
  using namespace script;

  const Type Key = map.arguments().front().type;
  const Type T = map.arguments().back().type;

  Class iterator = map.newNestedClass("const_iterator").get();

  // const_iterator();
  iterator.newConstructor(callbacks::map::const_iterator::default_ctor).create();
  // const_iterator(const const_iterator &)
  iterator.newConstructor(callbacks::map::const_iterator::copy_ctor)
    .params(Type::cref(iterator.id())).create();
  // ~const_iterator();
  iterator.newDestructor(callbacks::map::const_iterator::dtor).create();

  // const Key & key() const
  iterator.newMethod("key", callbacks::map::const_iterator::key)
    .setConst()
    .returns(Type::cref(Key))
    .create();
  // const T & value() const
  iterator.newMethod("value", callbacks::map::const_iterator::value)
    .setConst()
    .returns(Type::cref(T))
    .create();

  // const_iterator & operator=(const const_iterator &)
  iterator.newOperator(AssignmentOperator, callbacks::map::const_iterator::op_assign)
    .returns(Type::ref(iterator.id()))
    .params(Type::cref(iterator.id())).create();
  // bool operator!=(const const_iterator & other) const
  iterator.newOperator(InequalOperator, callbacks::map::const_iterator::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // bool operator==(const const_iterator & other) const
  iterator.newOperator(EqualOperator, callbacks::map::const_iterator::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // const_iterator operator+(int n) const;
  iterator.newOperator(AdditionOperator, callbacks::map::const_iterator::op_add)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // const_iterator & operator++()
  iterator.newOperator(PreIncrementOperator, callbacks::map::const_iterator::op_preincr)
    .returns(Type::ref(iterator.id())).create();
  // const_iterator operator++(int)
  iterator.newOperator(PostIncrementOperator, callbacks::map::const_iterator::op_postincr)
    .returns(iterator.id()).create();
  // const_iterator & operator+=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::map::const_iterator::op_addassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();
  // const_iterator operator-(int n) const;
  iterator.newOperator(SubstractionOperator, callbacks::map::const_iterator::op_sub)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // const_iterator & operator--()
  iterator.newOperator(PreDecrementOperator, callbacks::map::const_iterator::op_predecr)
    .returns(Type::ref(iterator.id())).create();
  // const_iterator operator--(int)
  iterator.newOperator(PostDecrementOperator, callbacks::map::const_iterator::op_postdecr)
    .returns(iterator.id()).create();
  // const_iterator & operator-=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::map::const_iterator::op_subassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();

  return iterator.id();
}

static script::Type map_template_instantiate_iterator(script::Class & map)
{
  using namespace script;

  const Type Key = map.arguments().front().type;
  const Type T = map.arguments().back().type;

  Class iterator = map.newNestedClass("iterator").get();

  // iterator();
  iterator.newConstructor(callbacks::map::iterator::default_ctor).create();
  // iterator(const iterator &)
  iterator.newConstructor(callbacks::map::iterator::copy_ctor)
    .params(Type::cref(iterator.id())).create();
  // ~iterator();
  iterator.newDestructor(callbacks::map::iterator::dtor).create();

  // const Key & key() const
  iterator.newMethod("key", callbacks::map::iterator::key)
    .setConst()
    .returns(Type::cref(Key))
    .create();
  // T & value() const
  iterator.newMethod("value", callbacks::map::iterator::value)
    .setConst()
    .returns(Type::cref(T))
    .create();

  // iterator & operator=(const iterator &)
  iterator.newOperator(AssignmentOperator, callbacks::map::iterator::op_assign)
    .returns(Type::ref(iterator.id()))
    .params(Type::cref(iterator.id())).create();
  // bool operator!=(const iterator & other) const
  iterator.newOperator(InequalOperator, callbacks::map::iterator::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // bool operator==(const iterator & other) const
  iterator.newOperator(EqualOperator, callbacks::map::iterator::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // iterator operator+(int n) const;
  iterator.newOperator(AdditionOperator, callbacks::map::iterator::op_add)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // iterator & operator++()
  iterator.newOperator(PreIncrementOperator, callbacks::map::iterator::op_preincr)
    .returns(Type::ref(iterator.id())).create();
  // iterator operator++(int)
  iterator.newOperator(PostIncrementOperator, callbacks::map::iterator::op_postincr)
    .returns(iterator.id()).create();
  // iterator & operator+=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::map::iterator::op_addassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();
  // iterator operator-(int n) const;
  iterator.newOperator(SubstractionOperator, callbacks::map::iterator::op_sub)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // iterator & operator--()
  iterator.newOperator(PreDecrementOperator, callbacks::map::iterator::op_predecr)
    .returns(Type::ref(iterator.id())).create();
  // iterator operator--(int)
  iterator.newOperator(PostDecrementOperator, callbacks::map::iterator::op_postdecr)
    .returns(iterator.id()).create();
  // iterator & operator-=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::map::iterator::op_subassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();

  return iterator.id();
}

static script::Type get_list_type(script::Engine *e, const script::Type & T)
{
  using namespace script;

  ClassTemplate list = ClassTemplate::get<ListTemplate>(e);

  std::vector<TemplateArgument> targs{
    TemplateArgument{T}
  };

  Class list_T = list.getInstance(targs);
  return list_T.id();
}

namespace script
{ 

Class MapTemplate::instantiate(ClassTemplateInstanceBuilder& builder)
{
  builder.setFinal();
  const Type Key = builder.arguments().front().type;
  const Type T = builder.arguments().back().type;

  builder.setData(MapData::get(builder.getTemplate().engine(), Key, T));

  Class map = builder.get();

  const Type const_iterator = map_template_instantiate_const_iterator(map);
  const Type iterator = map_template_instantiate_iterator(map);

  const Type list_key = get_list_type(map.engine(), Key);
  const Type list_T = get_list_type(map.engine(), T);

  // QMap();
  map.newConstructor(callbacks::map::default_ctor).create();
  // QMap(const QMap &)
  map.newConstructor(callbacks::map::copy_ctor)
    .params(Type::cref(map.id())).create();
  // ~QMap();
  map.newDestructor(callbacks::map::dtor).create();

  // iterator begin();
  map.newMethod("begin", callbacks::map::begin)
    .returns(iterator).create();
  // const_iterator begin() const;
  map.newMethod("begin", callbacks::map::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator cbegin() const;
  map.newMethod("cbegin", callbacks::map::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator cend() const;
  map.newMethod("cend", callbacks::map::cend)
    .setConst()
    .returns(const_iterator).create();
  // void clear();
  map.newMethod("clear", callbacks::map::clear).create();
  // const_iterator constBegin() const;
  map.newMethod("constBegin", callbacks::map::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator constEnd() const;
  map.newMethod("constEnd", callbacks::map::cend)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator constFind(const Key &) const;
  map.newMethod("constFind", callbacks::map::constFind)
    .setConst()
    .returns(const_iterator)
    .params(Type::cref(Key)).create();
  // bool contains(const Key & k) const;
  map.newMethod("contains", callbacks::map::contains)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(Key)).create();
  // int count(const Key & k) const;
  map.newMethod("count", callbacks::map::count)
    .setConst()
    .returns(Type::Int)
    .params(Type::cref(Key)).create();
  // int count() const;
  map.newMethod("count", callbacks::map::size)
    .setConst()
    .returns(Type::Int).create();
  // bool empty() const;
  map.newMethod("empty", callbacks::map::empty)
    .setConst()
    .returns(Type::Boolean).create();
  // iterator end();
  map.newMethod("end", callbacks::map::end)
    .returns(iterator).create();
  // const_iterator end() const;
  map.newMethod("end", callbacks::map::cend)
    .setConst()
    .returns(const_iterator).create();
  // iterator erase(iterator pos);
  map.newMethod("erase", callbacks::map::erase)
    .returns(iterator)
    .params(iterator).create();
  // iterator find(const Key &);
  map.newMethod("find", callbacks::map::find)
    .returns(iterator)
    .params(Type::cref(Key)).create();
  // const_iterator find(const Key &) const;
  map.newMethod("find", callbacks::map::constFind)
    .setConst()
    .returns(const_iterator)
    .params(Type::cref(Key)).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // T & first()
  map.newMethod("first", callbacks::map::first)
    .returns(Type::ref(T)).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // const T & first() const
  map.newMethod("first", callbacks::map::first)
    .setConst()
    .returns(Type::cref(T)).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // const Key & firstKey() const;
  map.newMethod("firstKey", callbacks::map::firstKey)
    .setConst()
    .returns(Type::cref(Key)).create();
#endif
  // iterator insert(const Key & k, const T & value);
  map.newMethod("insert", callbacks::map::insert)
    .returns(iterator)
    .params(Type::cref(Key), Type::cref(T)).create();
  // iterator insertMulti(const Key & k, const T & value);
  map.newMethod("insertMulti", callbacks::map::insertMulti)
    .returns(iterator)
    .params(Type::cref(Key), Type::cref(T)).create();
  // bool isEmpty() const;
  map.newMethod("isEmpty", callbacks::map::empty)
    .setConst()
    .returns(Type::Boolean).create();
  // const Key key(const T & value, const Key & defaultKey = Key{});
  map.newMethod("key", callbacks::map::key)
    .returns(Key.withConst())
    .params(Type::cref(T), Type::cref(Key)).create();
  // QList<Key> keys() const;
  map.newMethod("keys", callbacks::map::keys)
    .returns(list_key).create();
  // QList<Key> keys(const T & value) const;
  map.newMethod("keys", callbacks::map::keys_value)
    .returns(list_key)
    .params(Type::cref(T)).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // T & last()
  map.newMethod("last", callbacks::map::last)
    .returns(Type::ref(T)).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // const T & last() const
  map.newMethod("last", callbacks::map::last)
    .returns(Type::cref(T)).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // const Key & lastKey() const;
  map.newMethod("lastKey", callbacks::map::lastKey)
    .setConst()
    .returns(Type::cref(Key)).create();
#endif
  // int remove(const Key & k);
  map.newMethod("remove", callbacks::map::remove)
    .returns(Type::Int)
    .params(Type::cref(Key)).create();
  // int size() const;
  map.newMethod("size", callbacks::map::size)
    .setConst()
    .returns(Type::Int).create();
  // void swap(QMap & other);
  map.newMethod("swap", callbacks::map::swap)
    .params(Type::ref(map.id())).create();
  // T take(const Key & k);
  map.newMethod("take", callbacks::map::take)
    .returns(T)
    .params(Type::cref(Key)).create();
  // QList<Key> uniqueKeys() const;
  map.newMethod("uniqueKeys", callbacks::map::uniqueKeys)
    .returns(list_key).create();
  // Map & unite(const Map &);
  map.newMethod("unite", callbacks::map::unite)
    .returns(Type::ref(map.id()))
    .params(Type::cref(map.id())).create();
  // const T value(const Key & k, const T & defaultValue = T{})
  map.newMethod("value", callbacks::map::value)
    .returns(T.withConst())
    .params(Type::cref(Key), Type::cref(T)).create();
  // QList<T> values() const;
  map.newMethod("values", callbacks::map::values)
    .setConst()
    .returns(list_T).create();
  // QList<T> values(const Key & k) const;
  map.newMethod("values", callbacks::map::values)
    .setConst()
    .returns(list_T)
    .params(Type::cref(Key)).create();

  // QMap & operator=(const QMap &other);
  map.newOperator(AssignmentOperator, callbacks::map::op_assign)
    .returns(Type::ref(map.id()))
    .params(Type::cref(map.id())).create();
  // bool operator!=(const QMap &other) const;
  map.newOperator(InequalOperator, callbacks::map::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(map.id())).create();
  // bool operator==(const QMap &other) const;
  map.newOperator(EqualOperator, callbacks::map::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(map.id())).create();
  // T & operator[](const Key & k);
  map.newOperator(SubscriptOperator, callbacks::map::op_subscript)
    .returns(Type::ref(T))
    .params(Type::cref(Key)).create();

  return map;
}

} // namespace script


void register_map_template(script::Namespace n)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{ TemplateParameter::TypeParameter{}, "Key" },
    TemplateParameter{ TemplateParameter::TypeParameter{}, "T" },
  };

  ClassTemplate map_template = Symbol{ n }.newClassTemplate("Map")
    .setParams(std::move(params))
    .setScope(Scope{ n })
    .withBackend<script::MapTemplate>()
    .get();

  // Registering full specializations

}
