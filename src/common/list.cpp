// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/list.h"
#include "yasl/common/listspecializations.h"

#include "yasl/common/value.h"

#include <script/classtemplate.h>
#include <script/classtemplateinstancebuilder.h>
#include <script/templatebuilder.h>

#include <cstring>

using List = QList<yasl::Value>;
using ConstIterator = List::const_iterator;
using Iterator = List::iterator;

static List & get_list(const script::Value & val)
{
  return *static_cast<List*>(val.memory());
}

static Iterator & get_iter(const script::Value & val)
{
  return *static_cast<Iterator*>(val.memory());
}

static ConstIterator & get_const_iter(const script::Value & val)
{
  return *static_cast<ConstIterator*>(val.memory());
}

namespace script
{

script::Value make_list(const QList<yasl::Value> & val, const script::Type & list_type, script::Engine *e)
{
  return e->construct(list_type, [&val](script::Value & ret) {
    new (ret.getMemory(passkey{})) QList<yasl::Value>{val};
  });
}

static script::Value make_iter(const Iterator & val, const script::Type & iter_type, script::Engine *e)
{
  return e->construct(iter_type, [&val](script::Value & ret) {
    new (ret.getMemory(script::passkey{})) Iterator{ val };
  });
}

static script::Value make_const_iter(const ConstIterator & val, const script::Type & iter_type, script::Engine *e)
{
  return e->construct(iter_type, [&val](script::Value & ret) {
    new (ret.getMemory(script::passkey{})) ConstIterator{ val };
  });
}

namespace callbacks
{

namespace list
{

namespace const_iterator
{

// const_iterator()
script::Value default_ctor(script::FunctionCall *c)
{
  new (c->thisObject().getMemory(script::passkey{})) ConstIterator{};
  return c->thisObject();
}

// const_iterator(const const_iterator &)
script::Value copy_ctor(script::FunctionCall *c)
{
  const ConstIterator & other = get_const_iter(c->arg(1));
  new (c->thisObject().getMemory(script::passkey{})) ConstIterator{ other };
  return c->thisObject();
}

// ~const_iterator()
script::Value dtor(script::FunctionCall *c)
{
  ConstIterator & self = get_const_iter(c->thisObject());
  self.~const_iterator();
  c->thisObject().releaseMemory(script::passkey{});
  return script::Value::Void;
}

// const T & value() const
script::Value value(script::FunctionCall *c)
{
  const ConstIterator & self = get_const_iter(c->thisObject());
  return (*self).get();
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
  new (c->thisObject().getMemory(script::passkey{})) Iterator{};
  return c->thisObject();
}

// iterator(const iterator &)
script::Value copy_ctor(script::FunctionCall *c)
{
  const Iterator & other = get_iter(c->arg(1));
  new (c->thisObject().getMemory(script::passkey{})) Iterator{ other };
  return c->thisObject();
}

// ~iterator()
script::Value dtor(script::FunctionCall *c)
{
  Iterator & self = get_iter(c->thisObject());
  self.~iterator();
  c->thisObject().releaseMemory(script::passkey{});
  return script::Value::Void;
}

// T & value() const
script::Value value(script::FunctionCall *c)
{
  const Iterator & self = get_iter(c->thisObject());
  return (*self).get();
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

} // namespace list

// QList<T>();
static script::Value default_ctor(script::FunctionCall *c)
{
  using namespace script;
  new (c->thisObject().getMemory(passkey{})) QList<yasl::Value>{};
  return c->thisObject();
}

// QList<T>(const QList<T> &);
static script::Value copy_ctor(script::FunctionCall *c)
{
  using namespace script;
  QList<yasl::Value> & other = script::value_cast<QList<yasl::Value> &>(c->arg(1));
  new (c->thisObject().getMemory(passkey{})) QList<yasl::Value>{other};
  return c->thisObject();
}

// ~QList<T>();
static script::Value dtor(script::FunctionCall *c)
{
  using namespace script;
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  self.~QList<yasl::Value>();
  c->thisObject().releaseMemory(passkey{});
  return script::Value::Void;
}

// void append(const T &value)
// void push_back(const T &value)
static script::Value append_value(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  auto ti = std::static_pointer_cast<yasl::TypeInfo>(c->callee().memberOf().data());
  self.append(yasl::Value{ ti, c->arg(1) });
  return script::Value::Void;
}

// void append(const QList<T> &value)
static script::Value append_list(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  QList<yasl::Value> & other = script::value_cast<QList<yasl::Value> &>(c->arg(1));
  self.append(other);
  return script::Value::Void;
}

// const T & at(int i) const
// const T & operator[](int i) const
static script::Value at(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  return self.at(c->arg(1).toInt()).get();
}

// T & back()
// const T & back() const
static script::Value back(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  return self.back().get();
}

// iterator begin()
static script::Value begin(script::FunctionCall *c)
{
  QList<yasl::Value> & self = get_list(c->thisObject());
  return make_iter(self.begin(), c->callee().returnType(), c->engine());
}

// const_iterator begin() const
// const_iterator cbegin() const
// const_iterator constBegin() const
static script::Value cbegin(script::FunctionCall *c)
{
  const QList<yasl::Value> & self = get_list(c->thisObject());
  return make_const_iter(self.cbegin(), c->callee().returnType(), c->engine());
}

// const_iterator cend() const
// const_iterator constEnd() const
// const_iterator end() const
static script::Value cend(script::FunctionCall *c)
{
  const QList<yasl::Value> & self = get_list(c->thisObject());
  return make_const_iter(self.cend(), c->callee().returnType(), c->engine());
}

// void clear()
static script::Value clear(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  self.clear();
  return script::Value::Void;
}

// bool contains(const T &value) const
static script::Value contains(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const bool result = self.contains(value);
  return c->engine()->newBool(result);
}

// int count(const T &value) const
static script::Value count_element(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int result = self.count(value);
  return c->engine()->newInt(result);
}

// int count() const
// int length() const
// int size() const
static script::Value count(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  return c->engine()->newInt(self.count());
}

// const_reverse_iterator crbegin() const

// const_reverse_iterator crend() const

// bool empty() const
// bool isEmpty() const
static script::Value empty(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  return c->engine()->newBool(self.isEmpty());
}

// iterator end()
static script::Value end(script::FunctionCall *c)
{
  QList<yasl::Value> & self = get_list(c->thisObject());
  return make_iter(self.end(), c->callee().returnType(), c->engine());
}

// bool endsWith(const T &value) const
static script::Value ends_with(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const bool result = self.endsWith(value);
  return c->engine()->newBool(result);
}

// iterator erase(iterator pos)
static script::Value erase(script::FunctionCall *c)
{
  QList<yasl::Value> & self = get_list(c->thisObject());
  const Iterator & pos = get_iter(c->arg(1));
  return make_iter(self.erase(pos), c->callee().returnType(), c->engine());
}

// iterator erase(iterator begin, iterator end)
static script::Value erase_range(script::FunctionCall *c)
{
  QList<yasl::Value> & self = get_list(c->thisObject());
  const Iterator & begin = get_iter(c->arg(1));
  const Iterator & end = get_iter(c->arg(2));
  return make_iter(self.erase(begin, end), c->callee().returnType(), c->engine());
}

// T & first()
// const T & first() const
// const T & constFirst() const
// T & front()
// const T & front() const
static script::Value first(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  return self.first().get();
}

// int indexOf(const T &value, int from = 0) const
static script::Value index_of(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int from = c->arg(2).toInt();
  const int result = self.indexOf(value, from);
  return c->engine()->newInt(result);
}

// void insert(int i, const T &value)
static script::Value insert(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(2) };
  self.insert(i, value);
  return script::Value::Void;
}

// iterator insert(iterator before, const T &value)
static script::Value insert_iterator(script::FunctionCall *c)
{
  auto info = yasl::TypeInfo::get(c->callee().memberOf());
  QList<yasl::Value> & self = get_list(c->thisObject());
  const Iterator & before = get_iter(c->arg(1));
  yasl::Value value{ info, c->arg(2) };
  return make_iter(self.insert(before, value), c->callee().returnType(), c->engine());
}

// T & last()
// const T & last() const
// const T & constLast() const
static script::Value last(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  return self.last().get();
}

// int lastIndexOf(const T &value, int from = -1) const
static script::Value last_index_of(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int from = c->arg(2).toInt();
  const int result = self.lastIndexOf(value, from);
  return c->engine()->newInt(result);
}

// QList<T> mid(int pos, int length = -1) const
static script::Value mid(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int pos = c->arg(1).toInt();
  const int length = c->arg(2).toInt();
  return make_list(self.mid(pos, length), c->callee().returnType(), c->engine());
}

// void move(int from, int to)
static script::Value move(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int from = c->arg(1).toInt();
  const int to = c->arg(2).toInt();
  self.move(from, to);
  return script::Value::Void;
}

// void pop_back()
static script::Value pop_back(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  self.pop_back();
  return script::Value::Void;
}

// void pop_front()
static script::Value pop_front(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  self.pop_front();
  return script::Value::Void;
}

// void prepend(const T &value)
// void push_front(const T &value)
static script::Value prepend(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  auto ti = yasl::TypeInfo::get(c->callee().memberOf());
  self.prepend(yasl::Value{ ti, c->arg(1) });
  return script::Value::Void;
}

// reverse_iterator rbegin()
// const_reverse_iterator rbegin() const

// int removeAll(const T &value)
static script::Value remove_all(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int result = self.removeAll(value);
  return c->engine()->newInt(result);
}

// void removeAt(int i)
static script::Value remove_at(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  self.removeAt(i);
  return script::Value::Void;
}

// void removeFirst()
static script::Value remove_first(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  self.removeFirst();
  return script::Value::Void;
}

// void removeLast()
static script::Value remove_last(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  self.removeLast();
  return script::Value::Void;
}

// bool removeOne(const T &value)
static script::Value remove_one(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const bool result = self.removeOne(value);
  return c->engine()->newBool(result);
}

// reverse_iterator rend()
// const_reverse_iterator rend() const

// void replace(int i, const T &value)
static script::Value replace(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(2) };
  self.replace(i, value);
  return script::Value::Void;
}

// void reserve(int alloc)
static script::Value reserve(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  self.reserve(i);
  return script::Value::Void;
}

// bool startsWith(const T &value) const
static script::Value starts_with(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const bool result = self.startsWith(value);
  return c->engine()->newBool(result);
}

// void swap(QList<T> &other)
static script::Value swap_list(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  QList<yasl::Value> & other = script::value_cast<QList<yasl::Value> &>(c->arg(1));
  self.swap(other);
  return script::Value::Void;
}

// void swap(int i, int j)
static script::Value swap_element(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  const int j = c->arg(2).toInt();
  self.swap(i, j);
  return script::Value::Void;
}

// T takeAt(int i)
static script::Value take_at(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  auto ret = self.takeAt(i);
  return ret.release();
}

// T takeFirst()
static script::Value take_first(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  auto ret = self.takeFirst();
  return ret.release();
}

// T takeLast()
static script::Value take_last(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  auto ret = self.takeLast();
  return ret.release();
}

// QSet<T> toSet() const
// std::list<T> toStdList() const
// QVector<T> toVector() const

// T value(int i) const
static script::Value value(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  yasl::Value ret = self.value(i);
  if (ret.isValid())
    return ret.release();
  auto ti = yasl::TypeInfo::get(c->callee().memberOf());
  return c->engine()->construct(ti->element_type, {});
}

// T value(int i, const T &defaultValue) const
static script::Value value_with_default(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  yasl::Value ret = self.value(i, yasl::Value{});
  if (ret.isValid())
    return ret.release();
  return c->engine()->copy(c->arg(2));
}


// bool operator!=(const QList<T> &other) const
static script::Value op_neq(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  QList<yasl::Value> & other = script::value_cast<QList<yasl::Value> &>(c->arg(1));
  const bool result = self != other;
  return c->engine()->newBool(result);
}

// QList<T> operator+(const QList<T> &other) const
static script::Value op_add(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  QList<yasl::Value> & other = script::value_cast<QList<yasl::Value> &>(c->arg(1));
  return make_list(self + other, c->callee().returnType(), c->engine());
}

// QList<T> & operator+=(const QList<T> &other)
static script::Value op_add_assign(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  QList<yasl::Value> & other = script::value_cast<QList<yasl::Value> &>(c->arg(1));
  self += other;
  return c->thisObject();
}

// QList<T> & operator+=(const T &value)
static script::Value op_add_assign_value(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  self += value;
  return c->thisObject();
}

// QList<T> & operator<<(const QList<T> &other)
/// TODO !!!
// QList<T> & operator<<(const T &value)
/// TODO !!!
// QList<T> & operator=(const QList<T> &other)
static script::Value op_assign(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  QList<yasl::Value> & other = script::value_cast<QList<yasl::Value> &>(c->arg(1));
  self = other;
  return c->thisObject();
}

// QList & operator=(QList<T> &&other)
/// TODO !!!

// bool operator==(const QList<T> &other) const
static script::Value op_eq(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  QList<yasl::Value> & other = script::value_cast<QList<yasl::Value> &>(c->arg(1));
  const bool result = self == other;
  return c->engine()->newBool(result);
}

// T & operator[](int i)
static script::Value op_subscript(script::FunctionCall *c)
{
  QList<yasl::Value> & self = script::value_cast<QList<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  return self[i].get();
}

} // namespace callbacks


static script::Type list_template_instantiate_const_iterator(script::Class & list)
{
  using namespace script;

  const Type T = list.arguments().front().type;

  Class iterator = list.newNestedClass("const_iterator").get();

  // const_iterator();
  iterator.newConstructor(callbacks::list::const_iterator::default_ctor).create();
  // const_iterator(const const_iterator &)
  iterator.newConstructor(callbacks::list::const_iterator::copy_ctor)
    .params(Type::cref(iterator.id())).create();
  // ~const_iterator();
  iterator.newDestructor(callbacks::list::const_iterator::dtor).create();

  // const T & value() const
  iterator.newMethod("value", callbacks::list::const_iterator::value)
    .setConst()
    .returns(Type::cref(T))
    .create();

  // const_iterator & operator=(const const_iterator &)
  iterator.newOperator(AssignmentOperator, callbacks::list::const_iterator::op_assign)
    .returns(Type::ref(iterator.id()))
    .params(Type::cref(iterator.id())).create();
  // bool operator!=(const const_iterator & other) const
  iterator.newOperator(InequalOperator, callbacks::list::const_iterator::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // bool operator==(const const_iterator & other) const
  iterator.newOperator(EqualOperator, callbacks::list::const_iterator::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // const_iterator operator+(int n) const;
  iterator.newOperator(AdditionOperator, callbacks::list::const_iterator::op_add)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // const_iterator & operator++()
  iterator.newOperator(PreIncrementOperator, callbacks::list::const_iterator::op_preincr)
    .returns(Type::ref(iterator.id())).create();
  // const_iterator operator++(int)
  iterator.newOperator(PostIncrementOperator, callbacks::list::const_iterator::op_postincr)
    .returns(iterator.id()).create();
  // const_iterator & operator+=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::list::const_iterator::op_addassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();
  // const_iterator operator-(int n) const;
  iterator.newOperator(SubstractionOperator, callbacks::list::const_iterator::op_sub)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // const_iterator & operator--()
  iterator.newOperator(PreDecrementOperator, callbacks::list::const_iterator::op_predecr)
    .returns(Type::ref(iterator.id())).create();
  // const_iterator operator--(int)
  iterator.newOperator(PostDecrementOperator, callbacks::list::const_iterator::op_postdecr)
    .returns(iterator.id()).create();
  // const_iterator & operator-=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::list::const_iterator::op_subassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();

  return iterator.id();
}

static script::Type list_template_instantiate_iterator(script::Class & list)
{
  using namespace script;

  const Type T = list.arguments().front().type;

  Class iterator = list.newNestedClass("iterator").get();

  // iterator();
  iterator.newConstructor(callbacks::list::iterator::default_ctor).create();
  // iterator(const iterator &)
  iterator.newConstructor(callbacks::list::iterator::copy_ctor)
    .params(Type::cref(iterator.id())).create();
  // ~iterator();
  iterator.newDestructor(callbacks::list::iterator::dtor).create();

  // T & value() const
  iterator.newMethod("value", callbacks::list::iterator::value)
    .setConst()
    .returns(Type::cref(T))
    .create();

  // iterator & operator=(const iterator &)
  iterator.newOperator(AssignmentOperator, callbacks::list::iterator::op_assign)
    .returns(Type::ref(iterator.id()))
    .params(Type::cref(iterator.id())).create();
  // bool operator!=(const iterator & other) const
  iterator.newOperator(InequalOperator, callbacks::list::iterator::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // bool operator==(const iterator & other) const
  iterator.newOperator(EqualOperator, callbacks::list::iterator::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // iterator operator+(int n) const;
  iterator.newOperator(AdditionOperator, callbacks::list::iterator::op_add)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // iterator & operator++()
  iterator.newOperator(PreIncrementOperator, callbacks::list::iterator::op_preincr)
    .returns(Type::ref(iterator.id())).create();
  // iterator operator++(int)
  iterator.newOperator(PostIncrementOperator, callbacks::list::iterator::op_postincr)
    .returns(iterator.id()).create();
  // iterator & operator+=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::list::iterator::op_addassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();
  // iterator operator-(int n) const;
  iterator.newOperator(SubstractionOperator, callbacks::list::iterator::op_sub)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // iterator & operator--()
  iterator.newOperator(PreDecrementOperator, callbacks::list::iterator::op_predecr)
    .returns(Type::ref(iterator.id())).create();
  // iterator operator--(int)
  iterator.newOperator(PostDecrementOperator, callbacks::list::iterator::op_postdecr)
    .returns(iterator.id()).create();
  // iterator & operator-=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::list::iterator::op_subassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();

  return iterator.id();
}


script::Class list_template_instantiate(script::ClassTemplateInstanceBuilder & builder)
{
  using namespace script;

  builder.setFinal();
  const Type element_type = builder.arguments().front().type;

  builder.setData(yasl::TypeInfo::get(builder.getTemplate().engine(), element_type));

  Class list = builder.get();

  const Type T = element_type;
  const Type const_iterator = list_template_instantiate_const_iterator(list);
  const Type iterator = list_template_instantiate_iterator(list);

  // QList<T>();
  list.newConstructor(callbacks::default_ctor).create();
  // QList<T>(const QList<T> &);
  list.newConstructor(callbacks::copy_ctor)
    .params(Type::cref(list.id())).create();
  // ~QList<T>();
  list.newDestructor(callbacks::dtor).create();

  // void append(const T &value)
  list.newMethod("append", callbacks::append_value)
    .params(Type::cref(element_type)).create();
  // void append(const QList<T> &value)
  list.newMethod("append", callbacks::append_list)
    .params(Type::cref(list.id())).create();
  // const T & at(int i) const
  list.newMethod("at", callbacks::at)
    .setConst()
    .returns(Type::cref(element_type))
    .params(Type::Int).create();
  // T & back()
  list.newMethod("back", callbacks::back)
    .returns(Type::ref(element_type)).create();
  // const T & back() const
  list.newMethod("back", callbacks::back)
    .setConst()
    .returns(Type::cref(element_type)).create();
  // iterator begin()
  list.newMethod("begin", callbacks::begin)
    .returns(iterator).create();
  // const_iterator begin() const
  list.newMethod("begin", callbacks::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator cbegin() const
  list.newMethod("cbegin", callbacks::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator cend() const
  list.newMethod("cend", callbacks::cend)
    .setConst()
    .returns(const_iterator).create();
  // void clear()
  list.newMethod("clear", callbacks::clear).create();
  // const_iterator constBegin() const
  list.newMethod("constBegin", callbacks::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator constEnd() const
  list.newMethod("constEnd", callbacks::cend)
    .setConst()
    .returns(const_iterator).create();
  // const T & constFirst() const
  list.newMethod("constFirst", callbacks::first)
    .returns(Type::cref(element_type)).create();
  // const T & constLast() const
  list.newMethod("constLast", callbacks::last)
    .returns(Type::cref(element_type)).create();
  // bool contains(const T &value) const
  list.newMethod("contains", callbacks::contains)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  // int count(const T &value) const
  list.newMethod("count", callbacks::count_element)
    .setConst()
    .returns(Type::Int)
    .params(Type::cref(element_type)).create();
  // int count() const
  list.newMethod("count", callbacks::count)
    .setConst()
    .returns(Type::Int).create();
  // const_reverse_iterator crbegin() const
  /// TODO !!!
  // const_reverse_iterator crend() const
  /// TODO !!!
  // bool empty() const
  list.newMethod("empty", callbacks::empty)
    .setConst()
    .returns(Type::Boolean).create();
  // iterator end()
  list.newMethod("end", callbacks::end)
    .returns(iterator).create();
  // const_iterator end() const
  list.newMethod("end", callbacks::cend)
    .setConst()
    .returns(const_iterator).create();
  // bool endsWith(const T &value) const
  list.newMethod("endsWith", callbacks::ends_with)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  // iterator erase(iterator pos)
  list.newMethod("erase", callbacks::erase)
    .returns(iterator)
    .params(iterator).create();
  // iterator erase(iterator begin, iterator end)
  list.newMethod("erase", callbacks::erase_range)
    .returns(iterator)
    .params(iterator, iterator).create();
  // T & first()
  list.newMethod("first", callbacks::first)
    .returns(Type::ref(element_type)).create();
  // const T & first() const
  list.newMethod("first", callbacks::first)
    .setConst()
    .returns(Type::cref(element_type)).create();
  // T & front()
  list.newMethod("front", callbacks::first)
    .returns(Type::ref(element_type)).create();
  // const T & front() const
  list.newMethod("front", callbacks::first)
    .setConst()
    .returns(Type::cref(element_type)).create();
  // int indexOf(const T &value, int from = 0) const
  list.newMethod("indexOf", callbacks::index_of)
    .setConst()
    .returns(Type::Int)
    .params(Type::cref(element_type), Type::Int).create();
  // void insert(int i, const T &value)
  list.newMethod("insert", callbacks::insert)
    .params(Type::Int, Type::cref(element_type)).create();
  // iterator insert(iterator before, const T &value)
  list.newMethod("insert", callbacks::insert_iterator)
    .returns(iterator)
    .params(iterator, Type::cref(T)).create();
  // bool isEmpty() const
  list.newMethod("isEmpty", callbacks::empty)
    .setConst()
    .returns(Type::Boolean).create();
  // T & last()
  list.newMethod("last", callbacks::last)
    .returns(Type::ref(element_type)).create();
  // const T & last() const
  list.newMethod("last", callbacks::last)
    .setConst()
    .returns(Type::cref(element_type)).create();
  // int lastIndexOf(const T &value, int from = -1) const
  list.newMethod("lastIndexOf", callbacks::last_index_of)
    .setConst()
    .returns(Type::Int)
    .params(Type::cref(element_type), Type::Int).create();
  // int length() const
  list.newMethod("length", callbacks::count)
    .setConst()
    .returns(Type::Int).create();
  // QList<T> mid(int pos, int length = -1) const
  list.newMethod("mid", callbacks::mid)
    .setConst()
    .returns(list.id())
    .params(Type::Int, Type::Int).create();
  // void move(int from, int to)
  list.newMethod("move", callbacks::move)
    .params(Type::Int, Type::Int).create();
  // void pop_back()
  list.newMethod("pop_back", callbacks::pop_back).create();
  // void pop_front()
  list.newMethod("pop_front", callbacks::pop_front).create();
  // void prepend(const T &value)
  list.newMethod("prepend", callbacks::prepend)
    .params(Type::cref(element_type)).create();
  // void push_back(const T &value)
  list.newMethod("push_back", callbacks::append_value)
    .params(Type::cref(element_type)).create();
  // void push_front(const T &value)
  list.newMethod("push_front", callbacks::prepend)
    .params(Type::cref(element_type)).create();
  // reverse_iterator rbegin()
  /// TODO !!!
  // const_reverse_iterator rbegin() const
  /// TODO !!!
  // int removeAll(const T &value)
  list.newMethod("removeAll", callbacks::remove_all)
    .returns(Type::Int)
    .params(Type::cref(element_type)).create();
  // void removeAt(int i)
  list.newMethod("removeAt", callbacks::remove_at)
    .params(Type::Int).create();
  // void removeFirst()
  list.newMethod("removeFirst", callbacks::remove_first).create();
  // void removeLast()
  list.newMethod("removeLast", callbacks::remove_last).create();
  // bool removeOne(const T &value)
  list.newMethod("removeOne", callbacks::remove_one)
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  // reverse_iterator rend()
  /// TODO !!!
  // const_reverse_iterator rend() const
  /// TODO !!!
  // void replace(int i, const T &value)
  list.newMethod("replace", callbacks::replace)
    .params(Type::Int, Type::cref(element_type)).create();
  // void reserve(int alloc)
  list.newMethod("reserve", callbacks::reserve)
    .params(Type::Int).create();
  // int size() const
  list.newMethod("size", callbacks::count)
    .setConst()
    .returns(Type::Int).create();
  // bool startsWith(const T &value) const
  list.newMethod("startsWith", callbacks::starts_with)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  // void swap(QList<T> &other)
  list.newMethod("swap", callbacks::swap_list)
    .params(Type::ref(list.id())).create();
  // void swap(int i, int j)
  list.newMethod("swap", callbacks::swap_element)
    .params(Type::Int, Type::Int).create();
  // T takeAt(int i)
  list.newMethod("takeAt", callbacks::take_at)
    .returns(element_type)
    .params(Type::Int).create();
  // T takeFirst()
  list.newMethod("takeFirst", callbacks::take_first)
    .returns(element_type).create();
  // T takeLast()
  list.newMethod("takeLast", callbacks::take_last)
    .returns(element_type).create();
  // QSet<T> toSet() const
  /// TODO !!!
  // std::list<T> toStdList() const
  /// TODO !!!
  // QVector<T> toVector() const
  /// TODO !!!
  // T value(int i) const
  list.newMethod("value", callbacks::value)
    .setConst()
    .returns(element_type)
    .params(Type::Int).create();
  // T value(int i, const T &defaultValue) const
  list.newMethod("value", callbacks::value_with_default)
    .setConst()
    .returns(element_type)
    .params(Type::Int, Type::cref(element_type)).create();


  // bool operator!=(const QList<T> &other) const
  list.newOperator(InequalOperator, callbacks::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(list.id())).create();
  // QList<T> operator+(const QList<T> &other) const
  list.newOperator(AdditionOperator, callbacks::op_add)
    .setConst()
    .returns(list.id())
    .params(Type::cref(list.id())).create();
  // QList<T> & operator+=(const QList<T> &other)
  list.newOperator(AdditionAssignmentOperator, callbacks::op_add_assign)
    .returns(Type::ref(list.id()))
    .params(Type::cref(list.id())).create();
  // QList<T> & operator+=(const T &value)
  list.newOperator(AdditionAssignmentOperator, callbacks::op_add_assign_value)
    .returns(Type::ref(list.id()))
    .params(Type::cref(element_type)).create();
  // QList<T> & operator<<(const QList<T> &other)
  /// TODO !!!
  // QList<T> & operator<<(const T &value)
  /// TODO !!!
  // QList<T> & operator=(const QList<T> &other)
  list.newOperator(AssignmentOperator, callbacks::op_assign)
    .returns(Type::ref(list.id()))
    .params(Type::cref(list.id())).create();
  // QList & operator=(QList<T> &&other)
  /// TODO !!!
  // bool operator==(const QList<T> &other) const
  list.newOperator(EqualOperator, callbacks::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(list.id())).create();
  // T & operator[](int i)
  list.newOperator(SubscriptOperator, callbacks::op_subscript)
    .returns(Type::ref(element_type))
    .params(Type::Int).create();
  // const T & operator[](int i) const
  list.newOperator(SubscriptOperator, callbacks::at)
    .setConst()
    .returns(Type::cref(element_type))
    .params(Type::Int).create();

  return list;
}

void register_qlist_template(script::Namespace n)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{TemplateParameter::TypeParameter{}, "T"},
  };

  ClassTemplate list_template = Symbol{ n }.newClassTemplate("List")
    .setParams(std::move(params))
    .setScope(Scope{ n })
    .setCallback(list_template_instantiate)
    .get();

  n.engine()->setTemplate(passkey{}, Engine::ListTemplate, list_template);

  // Registering full specializations
  register_list_specialization<int>(n.engine());
  register_list_specialization<float>(n.engine());
  register_list_specialization<double>(n.engine());
}

} // namespace script
