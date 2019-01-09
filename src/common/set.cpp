// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/set.h"
#include "yasl/common/set-specializations.h"

#include "yasl/common/list.h"
#include "yasl/common/value.h"

#include <script/classtemplate.h>
#include <script/classtemplateinstancebuilder.h>
#include <script/constructorbuilder.h>
#include <script/templatebuilder.h>

#include <cstring>

using Set = QSet<yasl::Value>;
using ConstIterator = QSet<yasl::Value>::const_iterator;
using Iterator = QSet<yasl::Value>::iterator;

struct SetData : public script::UserData
{
  ~SetData() = default;

  std::shared_ptr<yasl::TypeInfo> T;

  static std::shared_ptr<SetData> get(script::Engine *e, const script::Type & T)
  {
    auto ret = std::make_shared<SetData>();
    ret->T = yasl::TypeInfo::get(e, T);

    if (!ret->T->supportsHashing())
      throw script::TemplateInstantiationError{"Set element must support hashing"};

    return ret;
  }
};

static script::Value make_set(const QSet<yasl::Value> & val, const script::Type & set_type, script::Engine *e)
{
  return e->construct(set_type, [&val](script::Value & ret) {
    new (ret.getMemory(script::passkey{})) QSet<yasl::Value>{val};
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
    new (ret.getMemory(script::passkey{})) ConstIterator{val};
  });
}

static Set & get_set(const script::Value & val)
{
  return *static_cast<Set*>(val.memory());
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

namespace callbacks
{

namespace set
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


// QSet()
script::Value default_ctor(script::FunctionCall *c)
{
  new (c->thisObject().getMemory(script::passkey{})) Set{};
  return c->thisObject();
}

// QSet(const QSet &)
script::Value copy_ctor(script::FunctionCall *c)
{
  auto & other = get_set(c->arg(1));
  new (c->thisObject().getMemory(script::passkey{})) Set{other};
  return c->thisObject();
}

// ~QSet()
script::Value dtor(script::FunctionCall *c)
{
  auto & self = get_set(c->thisObject());
  self.~QSet<yasl::Value>();
  c->thisObject().releaseMemory(script::passkey{});
  return script::Value::Void;
}

// iterator begin();
script::Value begin(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  return make_iter(self.begin(), c->callee().returnType(), c->engine());
}

// int capacity() const;
script::Value capacity(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  return c->engine()->newInt(self.capacity());
}

// const_iterator cbegin();
// const_iterator constBegin() const;
script::Value cbegin(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  return make_const_iter(self.cbegin(), c->callee().returnType(), c->engine());
}

// const_iterator cend();
// const_iterator constEnd() const;
// const_iterator end() const;
script::Value cend(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  return make_const_iter(self.cend(), c->callee().returnType(), c->engine());
}

// void clear();
script::Value clear(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  self.clear();
  return script::Value::Void;
}

// const_iterator constFind(const T &) const;
// const_iterator find(const T &) const;
script::Value constFind(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<SetData>(c->callee().memberOf().data());
  Set & self = get_set(c->thisObject());
  yasl::ObserverValue key{ info->T, c->arg(1) };
  return make_const_iter(self.constFind(key), c->callee().returnType(), c->engine());
}

// bool contains(const T & value) const;
script::Value contains_value(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<SetData>(c->callee().memberOf().data());
  Set & self = get_set(c->thisObject());
  yasl::ObserverValue value{ info->T, c->arg(1) };
  return c->engine()->newBool(self.contains(value));
}

// bool contains(const T & value) const;
script::Value contains_other(script::FunctionCall *c)
{
  const Set & self = get_set(c->thisObject());
  Set & other = get_set(c->arg(1));
  return c->engine()->newBool(self.contains(other));
}

// bool empty() const;
// bool isEmpty() const;
script::Value empty(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  return c->engine()->newBool(self.empty());
}

// iterator end();
script::Value end(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  return make_iter(self.end(), c->callee().returnType(), c->engine());
}

// iterator erase(iterator pos);
script::Value erase(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  const Iterator & iter = get_iter(c->arg(1));
  return make_iter(self.erase(iter), c->callee().returnType(), c->engine());
}

// iterator find(const T & value);
script::Value find(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<SetData>(c->callee().memberOf().data());
  Set & self = get_set(c->thisObject());
  yasl::ObserverValue key{ info->T, c->arg(1) };
  return make_iter(self.find(key), c->callee().returnType(), c->engine());
}

// iterator insert(const T & value);
script::Value insert(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<SetData>(c->callee().memberOf().data());
  Set & self = get_set(c->thisObject());
  yasl::ObserverValue value{ info->T, c->arg(1) };
  return make_iter(self.insert(value), c->callee().returnType(), c->engine());
}

// Set<T> & intersect(const QSet<T> & other);
script::Value intersect(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  const Set & other = get_set(c->arg(1));
  self.intersect(other);
  return c->thisObject();
}

// bool intersects(const QSet<T> & other) const;
script::Value intersects(script::FunctionCall *c)
{
  const Set & self = get_set(c->thisObject());
  const Set & other = get_set(c->arg(1));
  return c->engine()->newBool(self.intersects(other));
}

// bool remove(const T & value);
script::Value remove(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<SetData>(c->callee().memberOf().data());
  Set & self = get_set(c->thisObject());
  yasl::ObserverValue value{ info->T, c->arg(1) };
  return c->engine()->newBool(self.remove(value));
}

// void reserve(int size)
static script::Value reserve(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  const int i = c->arg(1).toInt();
  self.reserve(i);
  return script::Value::Void;
}

// int count() const;
// int size() const;
script::Value size(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  return c->engine()->newInt(self.size());
}

// void squeeze();
script::Value squeeze(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  self.squeeze();
  return script::Value::Void;
}

// Set & subtract(const Set &);
script::Value subtract(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  const Set & other = get_set(c->arg(1));
  self.subtract(other);
  return c->thisObject();
}

// void swap(Set & other);
script::Value swap(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  Set & other = get_set(c->arg(1));
  self.swap(other);
  return script::Value::Void;
}

// Set & unite(const Set &);
script::Value unite(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  const Set & other = get_set(c->arg(1));
  self.unite(other);
  return c->thisObject();
}

// QList<T> values() const;
script::Value values(script::FunctionCall *c)
{
  Set & self = get_set(c->thisObject());
  QList<yasl::Value> result = self.values();
  return script::make_list(result, c->callee().returnType(), c->engine());
}

// QSet & operator=(const QSet<T> &)
script::Value op_assign(script::FunctionCall *c)
{
  auto & self = get_set(c->thisObject());
  const auto & other = get_set(c->arg(1));
  self = other;
  return c->thisObject();
}

// bool operator==(const QSet<T> &) const
script::Value op_eq(script::FunctionCall *c)
{
  auto & self = get_set(c->thisObject());
  const auto & other = get_set(c->arg(1));
  return c->engine()->newBool(self == other);
}

// bool operator!=(const QSet<T> &) const
script::Value op_neq(script::FunctionCall *c)
{
  auto & self = get_set(c->thisObject());
  const auto & other = get_set(c->arg(1));
  return c->engine()->newBool(self != other);
}

// QSet<T> operator&(const QSet<T> &) const
script::Value op_bitand(script::FunctionCall *c)
{
  const auto & self = get_set(c->thisObject());
  const auto & other = get_set(c->arg(1));
  return make_set(self & other, c->callee().returnType(), c->engine());
}

// QSet<T> & operator&=(const T & value)
script::Value op_bitand_assign_value(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<SetData>(c->callee().memberOf().data());
  Set & self = get_set(c->thisObject());
  yasl::ObserverValue value{ info->T, c->arg(1) };
  self &= value;
  return c->thisObject();
}

// QSet<T> operator|(const QSet<T> &) const
script::Value op_bitor(script::FunctionCall *c)
{
  const auto & self = get_set(c->thisObject());
  const auto & other = get_set(c->arg(1));
  return make_set(self | other, c->callee().returnType(), c->engine());
}

// QSet<T> & operator|=(const T & value)
script::Value op_bitor_assign_value(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<SetData>(c->callee().memberOf().data());
  Set & self = get_set(c->thisObject());
  yasl::ObserverValue value{ info->T, c->arg(1) };
  self |= value;
  return c->thisObject();
}

// QSet<T> operator-(const QSet<T> &) const
script::Value op_sub(script::FunctionCall *c)
{
  const auto & self = get_set(c->thisObject());
  const auto & other = get_set(c->arg(1));
  return make_set(self - other, c->callee().returnType(), c->engine());
}

// QSet<T> & operator-=(const T & value)
script::Value op_subassign_value(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<SetData>(c->callee().memberOf().data());
  Set & self = get_set(c->thisObject());
  yasl::ObserverValue value{ info->T, c->arg(1) };
  self -= value;
  return c->thisObject();
}

} // namespace set

} // namespace callbacks

} // namespace script


static script::Type map_template_instantiate_const_iterator(script::Class & set)
{
  using namespace script;

  const Type T = set.arguments().front().type;

  Class iterator = set.newNestedClass("const_iterator").get();

  // const_iterator();
  iterator.newConstructor(callbacks::set::const_iterator::default_ctor).create();
  // const_iterator(const const_iterator &)
  iterator.newConstructor(callbacks::set::const_iterator::copy_ctor)
    .params(Type::cref(iterator.id())).create();
  // ~const_iterator();
  iterator.newDestructor(callbacks::set::const_iterator::dtor).create();

  // const T & value() const
  iterator.newMethod("value", callbacks::set::const_iterator::value)
    .setConst()
    .returns(Type::cref(T))
    .create();

  // const_iterator & operator=(const const_iterator &)
  iterator.newOperator(AssignmentOperator, callbacks::set::const_iterator::op_assign)
    .returns(Type::ref(iterator.id()))
    .params(Type::cref(iterator.id())).create();
  // bool operator!=(const const_iterator & other) const
  iterator.newOperator(InequalOperator, callbacks::set::const_iterator::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // bool operator==(const const_iterator & other) const
  iterator.newOperator(EqualOperator, callbacks::set::const_iterator::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // const_iterator operator+(int n) const;
  iterator.newOperator(AdditionOperator, callbacks::set::const_iterator::op_add)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // const_iterator & operator++()
  iterator.newOperator(PreIncrementOperator, callbacks::set::const_iterator::op_preincr)
    .returns(Type::ref(iterator.id())).create();
  // const_iterator operator++(int)
  iterator.newOperator(PostIncrementOperator, callbacks::set::const_iterator::op_postincr)
    .returns(iterator.id()).create();
  // const_iterator & operator+=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::set::const_iterator::op_addassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();
  // const_iterator operator-(int n) const;
  iterator.newOperator(SubstractionOperator, callbacks::set::const_iterator::op_sub)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // const_iterator & operator--()
  iterator.newOperator(PreDecrementOperator, callbacks::set::const_iterator::op_predecr)
    .returns(Type::ref(iterator.id())).create();
  // const_iterator operator--(int)
  iterator.newOperator(PostDecrementOperator, callbacks::set::const_iterator::op_postdecr)
    .returns(iterator.id()).create();
  // const_iterator & operator-=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::set::const_iterator::op_subassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();

  return iterator.id();
}

static script::Type map_template_instantiate_iterator(script::Class & set)
{
  using namespace script;

  const Type T = set.arguments().front().type;

  Class iterator = set.newNestedClass("iterator").get();

  // iterator();
  iterator.newConstructor(callbacks::set::iterator::default_ctor).create();
  // iterator(const iterator &)
  iterator.newConstructor(callbacks::set::iterator::copy_ctor)
    .params(Type::cref(iterator.id())).create();
  // ~iterator();
  iterator.newDestructor(callbacks::set::iterator::dtor).create();

  // T & value() const
  iterator.newMethod("value", callbacks::set::iterator::value)
    .setConst()
    .returns(Type::cref(T))
    .create();

  // iterator & operator=(const iterator &)
  iterator.newOperator(AssignmentOperator, callbacks::set::iterator::op_assign)
    .returns(Type::ref(iterator.id()))
    .params(Type::cref(iterator.id())).create();
  // bool operator!=(const iterator & other) const
  iterator.newOperator(InequalOperator, callbacks::set::iterator::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // bool operator==(const iterator & other) const
  iterator.newOperator(EqualOperator, callbacks::set::iterator::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(iterator.id())).create();
  // iterator operator+(int n) const;
  iterator.newOperator(AdditionOperator, callbacks::set::iterator::op_add)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // iterator & operator++()
  iterator.newOperator(PreIncrementOperator, callbacks::set::iterator::op_preincr)
    .returns(Type::ref(iterator.id())).create();
  // iterator operator++(int)
  iterator.newOperator(PostIncrementOperator, callbacks::set::iterator::op_postincr)
    .returns(iterator.id()).create();
  // iterator & operator+=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::set::iterator::op_addassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();
  // iterator operator-(int n) const;
  iterator.newOperator(SubstractionOperator, callbacks::set::iterator::op_sub)
    .setConst()
    .returns(iterator.id())
    .params(Type::Int).create();
  // iterator & operator--()
  iterator.newOperator(PreDecrementOperator, callbacks::set::iterator::op_predecr)
    .returns(Type::ref(iterator.id())).create();
  // iterator operator--(int)
  iterator.newOperator(PostDecrementOperator, callbacks::set::iterator::op_postdecr)
    .returns(iterator.id()).create();
  // iterator & operator-=(int n)
  iterator.newOperator(AdditionAssignmentOperator, callbacks::set::iterator::op_subassign)
    .returns(Type::ref(iterator.id()))
    .params(Type::Int).create();

  return iterator.id();
}

static script::Type get_list_type(script::Engine *e, const script::Type & T)
{
  using namespace script;

  ClassTemplate list = e->getTemplate(Engine::ListTemplate);

  std::vector<TemplateArgument> targs{
    TemplateArgument{T}
  };

  Class list_T = list.getInstance(targs);
  return list_T.id();
}

script::Class set_template_instantiate(script::ClassTemplateInstanceBuilder & builder)
{
  using namespace script;

  builder.setFinal();
  const Type T = builder.arguments().front().type;

  builder.setData(SetData::get(builder.getTemplate().engine(), T));

  Class set = builder.get();

  const Type const_iterator = map_template_instantiate_const_iterator(set);
  const Type iterator = map_template_instantiate_iterator(set);

  const Type list_T = get_list_type(set.engine(), T);

  // QSet();
  set.newConstructor(callbacks::set::default_ctor).create();
  // QSet(const QSet &)
  set.newConstructor(callbacks::set::copy_ctor)
    .params(Type::cref(set.id())).create();
  // ~QSet();
  set.newDestructor(callbacks::set::dtor).create();

  // iterator begin();
  set.newMethod("begin", callbacks::set::begin)
    .returns(iterator).create();
  // const_iterator begin() const;
  set.newMethod("begin", callbacks::set::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // int capacity() const;
  set.newMethod("capacity", callbacks::set::capacity)
    .setConst()
    .returns(Type::Int).create();
  // const_iterator cbegin() const;
  set.newMethod("cbegin", callbacks::set::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator cend() const;
  set.newMethod("cend", callbacks::set::cend)
    .setConst()
    .returns(const_iterator).create();
  // void clear();
  set.newMethod("clear", callbacks::set::clear).create();
  // const_iterator constBegin() const;
  set.newMethod("constBegin", callbacks::set::cbegin)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator constEnd() const;
  set.newMethod("constEnd", callbacks::set::cend)
    .setConst()
    .returns(const_iterator).create();
  // const_iterator constFind(const T &) const;
  set.newMethod("constFind", callbacks::set::constFind)
    .setConst()
    .returns(const_iterator)
    .params(Type::cref(T)).create();
  // bool contains(const T & value) const;
  set.newMethod("contains", callbacks::set::contains_value)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(T)).create();
  // bool contains(const QSet<T> & other) const;
  set.newMethod("contains", callbacks::set::contains_other)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(set.id())).create();
  // int count() const;
  set.newMethod("count", callbacks::set::size)
    .setConst()
    .returns(Type::Int).create();
  // bool empty() const;
  set.newMethod("empty", callbacks::set::empty)
    .setConst()
    .returns(Type::Boolean).create();
  // iterator end();
  set.newMethod("end", callbacks::set::end)
    .returns(iterator).create();
  // const_iterator end() const;
  set.newMethod("end", callbacks::set::cend)
    .setConst()
    .returns(const_iterator).create();
  // iterator erase(iterator pos);
  set.newMethod("erase", callbacks::set::erase)
    .returns(iterator)
    .params(iterator).create();
  // iterator find(const T &);
  set.newMethod("find", callbacks::set::find)
    .returns(iterator)
    .params(Type::cref(T)).create();
  // const_iterator find(const T &) const;
  set.newMethod("find", callbacks::set::constFind)
    .setConst()
    .returns(const_iterator)
    .params(Type::cref(T)).create();
  // iterator insert(const T & value);
  set.newMethod("insert", callbacks::set::insert)
    .returns(iterator)
    .params(Type::cref(T)).create();
  // Set & intersect(const Set &);
  set.newMethod("intersect", callbacks::set::intersect)
    .returns(Type::ref(set.id()))
    .params(Type::cref(set.id())).create();
  // bool intersects(const Set &) const;
  set.newMethod("intersects", callbacks::set::intersects)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(set.id())).create();
  // bool isEmpty() const;
  set.newMethod("isEmpty", callbacks::set::empty)
    .setConst()
    .returns(Type::Boolean).create();
  // bool remove(const T & value);
  set.newMethod("remove", callbacks::set::remove)
    .returns(Type::Boolean)
    .params(Type::cref(T)).create();
  // void reserve(int size);
  set.newMethod("reserve", callbacks::set::reserve)
    .params(Type::Int).create();
  // int size() const;
  set.newMethod("size", callbacks::set::size)
    .setConst()
    .returns(Type::Int).create();
  // void squeeze();
  set.newMethod("squeeze", callbacks::set::squeeze).create();
  // Set & subtract(const Set &);
  set.newMethod("subtract", callbacks::set::subtract)
    .returns(Type::ref(set.id()))
    .params(Type::cref(set.id())).create();
  // void swap(Set & other);
  set.newMethod("swap", callbacks::set::swap)
    .params(Type::ref(set.id())).create();
  // QList<T> toList() const;
  set.newMethod("toList", callbacks::set::values)
    .setConst()
    .returns(list_T).create();
  // Set & unite(const Set &);
  set.newMethod("unite", callbacks::set::unite)
    .returns(Type::ref(set.id()))
    .params(Type::cref(set.id())).create();
  // QList<T> values() const;
  set.newMethod("values", callbacks::set::values)
    .setConst()
    .returns(list_T).create();

  // Set & operator=(const Set &other);
  set.newOperator(AssignmentOperator, callbacks::set::op_assign)
    .returns(Type::ref(set.id()))
    .params(Type::cref(set.id())).create();
  // bool operator!=(const Set &other) const;
  set.newOperator(InequalOperator, callbacks::set::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(set.id())).create();
  // bool operator==(const Set &other) const;
  set.newOperator(EqualOperator, callbacks::set::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(set.id())).create();
  // QSet<T> operator&(const QSet<T> & other) const;
  set.newOperator(BitwiseAndOperator, callbacks::set::op_bitand)
    .setConst()
    .returns(set.id())
    .params(Type::cref(set.id())).create();
  // QSet<T> & operator&=(const QSet<T> & other);
  set.newOperator(BitwiseAndAssignmentOperator, callbacks::set::intersect)
    .returns(Type::ref(set.id()))
    .params(Type::cref(set.id())).create();
  // QSet<T> & operator&=(const T & value);
  set.newOperator(BitwiseAndAssignmentOperator, callbacks::set::op_bitand_assign_value)
    .returns(Type::ref(set.id()))
    .params(Type::cref(T)).create();
  // QSet<T> operator|(const QSet<T> & other) const;
  set.newOperator(BitwiseOrOperator, callbacks::set::op_bitor)
    .setConst()
    .returns(set.id())
    .params(Type::cref(set.id())).create();
  // QSet<T> & operator|=(const QSet<T> & other);
  set.newOperator(BitwiseOrAssignmentOperator, callbacks::set::unite)
    .returns(Type::ref(set.id()))
    .params(Type::cref(set.id())).create();
  // QSet<T> & operator|=(const T & value);
  set.newOperator(BitwiseOrAssignmentOperator, callbacks::set::op_bitor_assign_value)
    .returns(Type::ref(set.id()))
    .params(Type::cref(T)).create();
  // QSet<T> operator+(const QSet<T> & other) const;
  set.newOperator(AdditionOperator, callbacks::set::op_bitor)
    .setConst()
    .returns(set.id())
    .params(Type::cref(set.id())).create();
  // QSet<T> & operator+=(const QSet<T> & other);
  set.newOperator(AdditionAssignmentOperator, callbacks::set::unite)
    .returns(Type::ref(set.id()))
    .params(Type::cref(set.id())).create();
  // QSet<T> & operator+=(const T & value);
  set.newOperator(AdditionAssignmentOperator, callbacks::set::op_bitor_assign_value)
    .returns(Type::ref(set.id()))
    .params(Type::cref(T)).create();
  // QSet<T> operator-(const QSet<T> & other) const;
  set.newOperator(SubstractionOperator, callbacks::set::op_sub)
    .setConst()
    .returns(set.id())
    .params(Type::cref(set.id())).create();
  // QSet<T> & operator-=(const QSet<T> & other);
  set.newOperator(SubstractionAssignmentOperator, callbacks::set::subtract)
    .returns(Type::ref(set.id()))
    .params(Type::cref(set.id())).create();
  // QSet<T> & operator-=(const T & value);
  set.newOperator(SubstractionAssignmentOperator, callbacks::set::op_subassign_value)
    .returns(Type::ref(set.id()))
    .params(Type::cref(T)).create();
  // QSet<T> & operator<<(const T & value);
  set.newOperator(LeftShiftOperator, callbacks::set::op_bitor_assign_value)
    .returns(Type::ref(set.id()))
    .params(Type::cref(T)).create();

  return set;
}

void register_set_template(script::Namespace n)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{ TemplateParameter::TypeParameter{}, "T" },
  };

  ClassTemplate set_template = Symbol{ n }.newClassTemplate("Set")
    .setParams(std::move(params))
    .setScope(Scope{ n })
    .setCallback(set_template_instantiate)
    .get();

  n.engine()->setTemplate(script::passkey{}, Engine::SetTemplate, set_template);

  // Registering full specializations

}
