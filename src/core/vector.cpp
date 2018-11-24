// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/vector.h"
#include "yasl/core/vectorspecializations.h"

#include "yasl/application.h"
#include "yasl/core/object.h"
#include "yasl/core/enums.h"
#include "yasl/utils/containervalue.h"

#include <script/classtemplate.h>
#include <script/classtemplateinstancebuilder.h>
#include <script/constructorbuilder.h>
#include <script/private/engine_p.h>
#include <script/templatebuilder.h>

#include <cstring>

static script::Value make_vector(const QVector<ContainerValue> & val, const script::Type & vector_type, script::Engine *e)
{
  return e->construct(vector_type, [&val](script::Value & ret) {
    new (&ret.impl()->data.memory) QVector<ContainerValue>{val};
  });
}

namespace callbacks
{

// QVector<T>();
static script::Value default_ctor(script::FunctionCall *c)
{
  using namespace script;
  new (&c->thisObject().impl()->data.memory) QVector<ContainerValue>{};
  return c->thisObject();
}

// QVector<T>(const QVector<T> &);
static script::Value copy_ctor(script::FunctionCall *c)
{
  using namespace script;
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  new (&c->thisObject().impl()->data.memory) QVector<ContainerValue>{other};
  return c->thisObject();
}

// ~QVector<T>();
static script::Value dtor(script::FunctionCall *c)
{
  using namespace script;
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  self.~QVector<ContainerValue>();
  std::memset(&c->thisObject().impl()->data.memory, 0, sizeof(script::ValueImpl::BuiltIn));
  return script::Value::Void;
}

// QVector(int size);
static script::Value size_ctor(script::FunctionCall *c)
{
  using namespace script;
  const int size = script::value_cast<int>(c->arg(1));
  new (&c->thisObject().impl()->data.memory) QVector<ContainerValue>(size);
  return c->thisObject();
}

// QVector(int size, const T &value);
static script::Value size_value_ctor(script::FunctionCall *c)
{
  using namespace script;
  const int size = script::value_cast<int>(c->arg(1));
  auto container = ContainerData::get(c->callee());
  new (&c->thisObject().impl()->data.memory) QVector<ContainerValue>(size, ContainerValue{ container, c->arg(2) });
  return c->thisObject();
}

/// TODO: QVector(QVector<T> &&other);
/// TODO: QVector(std::initializer_list<T> args);

// void append(const T &value);
// void push_back(const T &value);
static script::Value append_value(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  auto container = ContainerData::get(c->callee());
  self.append(ContainerValue{ container, c->arg(1) });
  return script::Value::Void;
}

/// TODO: void append(T &&value);

// void append(const QVector<T> &value);
static script::Value append_vector(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  self.append(other);
  return script::Value::Void;
}

// const T & at(int i) const;
// const T & operator[](int i) const
static script::Value at(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  return self.at(c->arg(1).toInt()).value;
}

// QVector::reference back();
// QVector::const_reference back() const;
// const T & constLast() const;
// T & last();
// const T & last() const;
static script::Value back(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  return self.back().value;
}

/// TODO: QVector::iterator begin();
/// TODO: QVector::const_iterator begin() const;

// int capacity() const;
static script::Value capacity(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  return c->engine()->newInt(self.capacity());
}

/// TODO: QVector::const_iterator cbegin() const;
/// TODO: QVector::const_iterator cend() const;

// void clear();
static script::Value clear(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  self.clear();
  return script::Value::Void;
}

/// TODO: QVector::const_iterator constBegin() const;
/// ignore: const T * constData() const;
/// TODO: QVector::const_iterator constEnd() const;

// const T & constFirst() const;
// T & first();
// const T & first() const;
// T & front();
// QVector::const_reference front() const;
static script::Value const_first(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  return self.constFirst().value;
}

// bool contains(const T &value) const;
static script::Value contains(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const bool result = self.contains(value);
  return c->engine()->newBool(result);
}

// int count(const T &value) const;
static script::Value count_element(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const int result = self.count(value);
  return c->engine()->newInt(result);
}

// int count() const;
// int length() const;
// int size() const;
static script::Value count(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  return c->engine()->newInt(self.count());
}

/// TODO: QVector::const_reverse_iterator crbegin() const;
/// TODO: QVector::const_reverse_iterator crend() const;
/// ignore: T * data();
/// ignore: const T * data() const;

// bool empty() const;
// bool isEmpty() const;
static script::Value empty(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  return c->engine()->newBool(self.isEmpty());
}

/// TODO: QVector::iterator end();
/// TODO: QVector::const_iterator end() const;

// bool endsWith(const T &value) const;
static script::Value ends_with(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const bool result = self.endsWith(value);
  return c->engine()->newBool(result);
}

/// TODO: QVector::iterator erase(QVector::iterator pos);
/// TODO; QVector::iterator erase(QVector::iterator begin, QVector::iterator end);

// QVector<T> & fill(const T &value, int size = ...);
static script::Value fill(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const int size = c->arg(2).toInt();
  self.fill(value, size);
  return c->thisObject();
}

// int indexOf(const T &value, int from = ...) const;
static script::Value index_of(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const int from = c->arg(2).toInt();
  const int result = self.indexOf(value, from);
  return c->engine()->newInt(result);
}

/// TODO: void insert(int i, T &&value);

// void insert(int i, const T &value);
static script::Value insert(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(2) };
  self.insert(i, value);
  return script::Value::Void;
}

// void insert(int i, int count, const T &value);
static script::Value insert_count(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  const int count = c->arg(2).toInt();
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(3) };
  self.insert(i, count, value);
  return script::Value::Void;
}

/// TODO: QVector::iterator insert(QVector::iterator before, int count, const T &value);
/// TODO: QVector::iterator insert(QVector::iterator before, const T &value);
/// TODO: QVector::iterator insert(QVector::iterator before, T &&value);

// int lastIndexOf(const T &value, int from = ...) const;
static script::Value last_index_of(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const int from = c->arg(2).toInt();
  const int result = self.lastIndexOf(value, from);
  return c->engine()->newInt(result);
}

// QVector<T> mid(int pos, int length = ...) const;
static script::Value mid(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int pos = c->arg(1).toInt();
  const int length = c->arg(2).toInt();
  return make_vector(self.mid(pos, length), c->callee().returnType(), c->engine());
}

// void move(int from, int to);
static script::Value move(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int from = c->arg(1).toInt();
  const int to = c->arg(2).toInt();
  self.move(from, to);
  return script::Value::Void;
}

// void pop_back();
// void removeLast();
static script::Value pop_back(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  self.pop_back();
  return script::Value::Void;
}

// void pop_front();
// void removeFirst();
static script::Value pop_front(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  self.pop_front();
  return script::Value::Void;
}

/// TODO: void prepend(T &&value);

// void prepend(const T &value);
// void push_front(const T &value);
static script::Value prepend(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  auto container = ContainerData::get(c->callee());
  self.prepend(ContainerValue{ container, c->arg(1) });
  return script::Value::Void;
}


/// TODO: void push_back(T &&value);
/// TODO: void push_front(T &&value);

/// TODO: QVector::reverse_iterator rbegin();
/// TODO: QVector::const_reverse_iterator rbegin() const;

// void remove(int i);
// void removeAt(int i);
static script::Value remove_at(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  self.removeAt(i);
  return script::Value::Void;
}

// void remove(int i, int count);
static script::Value remove_count(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  const int count = c->arg(2).toInt();
  self.remove(i, count);
  return script::Value::Void;
}

// int removeAll(const T &t);
static script::Value remove_all(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const int result = self.removeAll(value);
  return c->engine()->newInt(result);
}

// bool removeOne(const T &t);
static script::Value remove_one(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const bool result = self.removeOne(value);
  return c->engine()->newBool(result);
}

/// TODO: QVector::reverse_iterator rend();
/// TODO: QVector::const_reverse_iterator rend() const;

// void replace(int i, const T &value);
static script::Value replace(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(2) };
  self.replace(i, value);
  return script::Value::Void;
}

// void reserve(int size);
static script::Value reserve(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  self.reserve(i);
  return script::Value::Void;
}

// void resize(int size);
static script::Value resize(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  self.resize(i);
  return script::Value::Void;
}

// void shrink_to_fit();
// void squeeze();
static script::Value shrink_to_fit(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  self.squeeze();
  return script::Value::Void;
}

// bool startsWith(const T &value) const;
static script::Value starts_with(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  const bool result = self.startsWith(value);
  return c->engine()->newBool(result);
}

// void swap(QVector<T> &other);
static script::Value swap(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  self.swap(other);
  return script::Value::Void;
}

// T takeAt(int i);
static script::Value take_at(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  auto ret = self.takeAt(i);
  return ret.release();
}

// T takeFirst();
static script::Value take_first(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  auto ret = self.takeFirst();
  return ret.release();
}

// T takeLast();
static script::Value take_last(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  auto ret = self.takeLast();
  return ret.release();
}

/// TODO: QList<T> toList() const;
/// ignore: std::vector<T> toStdVector() const;

// T value(int i) const;
static script::Value value(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  ContainerValue ret = self.value(i);
  if (ret.isValid())
    return ret.release();
  auto container = ContainerData::get(c->callee());
  return c->engine()->construct(container->element_type, {});
}

// T value(int i, const T &defaultValue) const;
static script::Value value_with_default(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  ContainerValue ret = self.value(i, ContainerValue{});
  if (ret.isValid())
    return ret.release();
  return c->engine()->copy(c->arg(2));
}

// bool operator!=(const QVector<T> &other) const;
static script::Value op_neq(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  const bool result = self != other;
  return c->engine()->newBool(result);
}

// QVector<T> operator+(const QVector<T> &other) const;
static script::Value op_add(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  return make_vector(self + other, c->callee().returnType(), c->engine());
}

// QVector<T> & operator+=(const QVector<T> &other);
static script::Value op_add_assign(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  self += other;
  return c->thisObject();
}

// QVector<T> & operator+=(const T &value);
static script::Value op_add_assign_value(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  TemporaryContainerValueWrap value{ ContainerData::get(c->callee()), c->arg(1) };
  self += value;
  return c->thisObject();
}

/// TODO: QVector<T> & operator+=(T &&value);

// QVector<T> & operator<<(const T &value);
static script::Value op_put_value(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  self << other;
  return c->thisObject();
}

// QVector<T> & operator<<(const QVector<T> &other);
static script::Value op_put_vector(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  auto container = ContainerData::get(c->callee());
  self.append(ContainerValue{ container, c->arg(1) });
  return c->thisObject();
}

/// TODO: QVector<T> & operator<<(T &&value);

// QVector<T> & operator=(const QVector<T> &other);
static script::Value op_assign(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  self = other;
  return c->thisObject();
}

/// TODO: QVector<T> & operator=(QVector<T> &&other);

// bool operator==(const QVector<T> &other) const;
static script::Value op_eq(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  QVector<ContainerValue> & other = script::value_cast<QVector<ContainerValue> &>(c->arg(1));
  const bool result = self == other;
  return c->engine()->newBool(result);
}

// T & operator[](int i);
static script::Value op_subscript(script::FunctionCall *c)
{
  QVector<ContainerValue> & self = script::value_cast<QVector<ContainerValue> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  return self[i].value;
}

} // namespace callbacks


script::Class vector_template_instantiate(script::ClassTemplateInstanceBuilder & builder)
{
  using namespace script;

  builder.setFinal();
  const Type element_type = builder.arguments().front().type;

  Class vector = builder.get();


  // QVector();
  vector.newConstructor(callbacks::default_ctor).create();
  // QVector(int size);
  vector.newConstructor(callbacks::size_ctor)
    .params(Type::Int).create();
  // QVector(int size, const T &value);
  vector.newConstructor(callbacks::size_value_ctor)
    .params(Type::Int, Type::cref(element_type)).create();
  // QVector(const QVector<T> &other);
  vector.newConstructor(callbacks::copy_ctor)
    .params(Type::cref(vector.id())).create();
  /// TODO: QVector(QVector<T> &&other);
  /// TODO: QVector(std::initializer_list<T> args);
  // ~QVector();
  vector.newDestructor(callbacks::dtor).create();
  // void append(const T &value);
  vector.newMethod("append", callbacks::append_value)
    .params(Type::cref(element_type)).create();
  /// TODO: void append(T &&value);
  // void append(const QVector<T> &value);
  vector.newMethod("append", callbacks::append_vector)
    .params(Type::cref(vector.id())).create();
  // const T & at(int i) const;
  vector.newMethod("at", callbacks::at)
    .setConst()
    .returns(Type::cref(element_type))
    .params(Type::Int).create();
  // QVector::reference back();
  vector.newMethod("back", callbacks::back)
    .returns(Type::ref(element_type)).create();
  // QVector::const_reference back() const;
  vector.newMethod("back", callbacks::back)
    .setConst()
    .returns(Type::cref(element_type)).create();
  /// TODO: QVector::iterator begin();
  /// TODO: QVector::const_iterator begin() const;
  // int capacity() const;
  vector.newMethod("capacity", callbacks::capacity)
    .setConst()
    .returns(Type::Int)
    .create();
  /// TODO: QVector::const_iterator cbegin() const;
  /// TODO: QVector::const_iterator cend() const;
  // void clear();
  vector.newMethod("clear", callbacks::clear).create();
  /// TODO: QVector::const_iterator constBegin() const;
  /// ignore: const T * constData() const;
  /// TODO: QVector::const_iterator constEnd() const;
  // const T & constFirst() const;
  vector.newMethod("constFirst", callbacks::const_first)
    .returns(Type::cref(element_type)).create();
  // const T & constLast() const;
  vector.newMethod("constLast", callbacks::back)
    .returns(Type::cref(element_type)).create();
  // bool contains(const T &value) const;
  vector.newMethod("contains", callbacks::contains)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  // int count(const T &value) const;
  vector.newMethod("count", callbacks::count_element)
    .setConst()
    .returns(Type::Int)
    .params(Type::cref(element_type)).create();
  // int count() const;
  vector.newMethod("count", callbacks::count)
    .setConst()
    .returns(Type::Int).create();
  /// TODO: QVector::const_reverse_iterator crbegin() const;
  /// TODO: QVector::const_reverse_iterator crend() const;
  /// ignore: T * data();
  /// ignore: const T * data() const;
  // bool empty() const;
  vector.newMethod("empty", callbacks::empty)
    .setConst()
    .returns(Type::Boolean).create();
  /// TODO: QVector::iterator end();
  /// TODO: QVector::const_iterator end() const;
  // bool endsWith(const T &value) const;
  vector.newMethod("endsWith", callbacks::ends_with)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  /// TODO: QVector::iterator erase(QVector::iterator pos);
  /// TODO; QVector::iterator erase(QVector::iterator begin, QVector::iterator end);
  // QVector<T> & fill(const T &value, int size = ...);
  vector.newMethod("fill", callbacks::fill)
    .returns(Type::ref(vector.id()))
    .params(Type::cref(element_type), Type::Int)
    .apply(bind::default_arguments(-1)).create();
  // T & first();
  vector.newMethod("first", callbacks::const_first)
    .returns(Type::ref(element_type)).create();
  // const T & first() const;
  vector.newMethod("first", callbacks::const_first)
    .setConst()
    .returns(Type::cref(element_type)).create();
  // T & front();
  vector.newMethod("front", callbacks::const_first)
    .returns(Type::ref(element_type)).create();
  // QVector::const_reference front() const;
  vector.newMethod("front", callbacks::const_first)
    .setConst()
    .returns(Type::cref(element_type)).create();
  // int indexOf(const T &value, int from = ...) const;
  vector.newMethod("indexOf", callbacks::index_of)
    .setConst()
    .returns(Type::Int)
    .params(Type::cref(element_type), Type::Int)
    .apply(bind::default_arguments(0)).create();
  /// TODO: void insert(int i, T &&value);
  // void insert(int i, const T &value);
  vector.newMethod("insert", callbacks::insert)
    .params(Type::Int, Type::cref(element_type)).create();
  // void insert(int i, int count, const T &value);
  vector.newMethod("insert", callbacks::insert_count)
    .params(Type::Int, Type::Int, Type::cref(element_type)).create();
  /// TODO: QVector::iterator insert(QVector::iterator before, int count, const T &value);
  /// TODO: QVector::iterator insert(QVector::iterator before, const T &value);
  /// TODO: QVector::iterator insert(QVector::iterator before, T &&value);
  // bool isEmpty() const;
  vector.newMethod("isEmpty", callbacks::empty)
    .setConst()
    .returns(Type::Boolean).create();
  // T & last();
  vector.newMethod("last", callbacks::back)
    .returns(Type::ref(element_type)).create();
  // const T & last() const;
  vector.newMethod("last", callbacks::back)
    .setConst()
    .returns(Type::cref(element_type)).create();
  // int lastIndexOf(const T &value, int from = ...) const;
  vector.newMethod("lastIndexOf", callbacks::last_index_of)
    .setConst()
    .returns(Type::Int)
    .params(Type::cref(element_type), Type::Int)
    .apply(bind::default_arguments(-1)).create();
  // int length() const;
  vector.newMethod("length", callbacks::count)
    .setConst()
    .returns(Type::Int).create();
  // QVector<T> mid(int pos, int length = ...) const;
  vector.newMethod("mid", callbacks::mid)
    .setConst()
    .returns(vector.id())
    .params(Type::Int, Type::Int)
    .apply(bind::default_arguments(-1)).create();
  // void move(int from, int to);
  vector.newMethod("move", callbacks::move)
    .params(Type::Int, Type::Int).create();
  // void pop_back();
  vector.newMethod("pop_back", callbacks::pop_back).create();
  // void pop_front();
  vector.newMethod("pop_front", callbacks::pop_front).create();
  /// TODO: void prepend(T &&value);
  // void prepend(const T &value);
  vector.newMethod("prepend", callbacks::prepend)
    .params(Type::cref(element_type)).create();
  // void push_back(const T &value);
  vector.newMethod("push_back", callbacks::append_value)
    .params(Type::cref(element_type)).create();
  /// TODO: void push_back(T &&value);
  /// TODO: void push_front(T &&value);
  // void push_front(const T &value);
  vector.newMethod("push_front", callbacks::prepend)
    .params(Type::cref(element_type)).create();
  /// TODO: QVector::reverse_iterator rbegin();
  /// TODO: QVector::const_reverse_iterator rbegin() const;
  // void remove(int i);
  vector.newMethod("remove", callbacks::remove_at)
    .params(Type::Int).create();
  // void remove(int i, int count);
  vector.newMethod("remove", callbacks::remove_count)
    .params(Type::Int, Type::Int).create();
  // int removeAll(const T &t);
  vector.newMethod("removeAll", callbacks::remove_all)
    .returns(Type::Int)
    .params(Type::cref(element_type)).create();
  // void removeAt(int i);
  vector.newMethod("removeAt", callbacks::remove_at)
    .params(Type::Int).create();
  // void removeFirst();
  vector.newMethod("removeFirst", callbacks::pop_front).create();
  // void removeLast();
  vector.newMethod("removeLast", callbacks::pop_back).create();
  // bool removeOne(const T &t);
  vector.newMethod("removeOne", callbacks::remove_one)
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  /// TODO: QVector::reverse_iterator rend();
  /// TODO: QVector::const_reverse_iterator rend() const;
  // void replace(int i, const T &value);
  vector.newMethod("replace", callbacks::replace)
    .params(Type::Int, Type::cref(element_type)).create();
  // void reserve(int size);
  vector.newMethod("reserve", callbacks::reserve)
    .params(Type::Int).create();
  // void resize(int size);
  vector.newMethod("resize", callbacks::resize)
    .params(Type::Int).create();
  // void shrink_to_fit();
  vector.newMethod("shrink_to_fit", callbacks::shrink_to_fit).create();
  // int size() const;
  vector.newMethod("size", callbacks::count)
    .setConst()
    .returns(Type::Int).create();
  // void squeeze();
  vector.newMethod("squeeze", callbacks::shrink_to_fit).create();
  // bool startsWith(const T &value) const;
  vector.newMethod("startsWith", callbacks::starts_with)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  // void swap(QVector<T> &other);
  vector.newMethod("swap", callbacks::swap)
    .params(Type::ref(vector.id())).create();
  // T takeAt(int i);
  vector.newMethod("takeAt", callbacks::take_at)
    .returns(element_type)
    .params(Type::Int).create();
  // T takeFirst();
  vector.newMethod("takeFirst", callbacks::take_first)
    .returns(element_type).create();
  // T takeLast();
  vector.newMethod("takeLast", callbacks::take_last)
    .returns(element_type).create();
  /// TODO: QList<T> toList() const;
  /// ignore: std::vector<T> toStdVector() const;
  // T value(int i) const;
  vector.newMethod("value", callbacks::value)
    .setConst()
    .returns(element_type)
    .params(Type::Int).create();
  // T value(int i, const T &defaultValue) const;
  vector.newMethod("value", callbacks::value_with_default)
    .setConst()
    .returns(element_type)
    .params(Type::Int, Type::cref(element_type)).create();
  // bool operator!=(const QVector<T> &other) const;
  vector.newOperator(InequalOperator, callbacks::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(vector.id())).create();
  // QVector<T> operator+(const QVector<T> &other) const;
  vector.newOperator(AdditionOperator, callbacks::op_add)
    .setConst()
    .returns(vector.id())
    .params(Type::cref(vector.id())).create();
  // QVector<T> & operator+=(const QVector<T> &other);
  vector.newOperator(AdditionAssignmentOperator, callbacks::op_add_assign)
    .returns(Type::ref(vector.id()))
    .params(Type::cref(vector.id())).create();
  // QVector<T> & operator+=(const T &value);
  vector.newOperator(AdditionAssignmentOperator, callbacks::op_add_assign_value)
    .returns(Type::ref(vector.id()))
    .params(Type::cref(element_type)).create();
  /// TODO: QVector<T> & operator+=(T &&value);
  // QVector<T> & operator<<(const T &value);
  vector.newOperator(LeftShiftOperator, callbacks::op_put_value)
    .returns(Type::ref(vector.id()))
    .params(Type::cref(element_type)).create();
  // QVector<T> & operator<<(const QVector<T> &other);
  vector.newOperator(LeftShiftOperator, callbacks::op_put_vector)
    .returns(Type::ref(vector.id()))
    .params(Type::cref(vector.id())).create();
  /// TODO: QVector<T> & operator<<(T &&value);
  // QVector<T> & operator=(const QVector<T> &other);
  vector.newOperator(AssignmentOperator, callbacks::op_assign)
    .returns(Type::ref(vector.id()))
    .params(Type::cref(vector.id())).create();
  /// TODO: QVector<T> & operator=(QVector<T> &&other);
  // bool operator==(const QVector<T> &other) const;
  vector.newOperator(EqualOperator, callbacks::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(vector.id())).create();
  // T & operator[](int i);
  vector.newOperator(SubscriptOperator, callbacks::op_subscript)
    .returns(Type::ref(element_type))
    .params(Type::Int).create();
  // const T & operator[](int i) const
  vector.newOperator(SubscriptOperator, callbacks::at)
    .setConst()
    .returns(Type::cref(element_type))
    .params(Type::Int).create();

  return vector;
}

void register_vector_template(script::Namespace n)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{TemplateParameter::TypeParameter{}, "T"},
  };

  ClassTemplate vector_template = Symbol{ n }.newClassTemplate("Vector")
    .setParams(std::move(params))
    .setScope(Scope{ n })
    .setCallback(vector_template_instantiate)
    .get();

  n.engine()->implementation()->vector_template_ = vector_template;

  // Registering full specializations
  register_vector_specialization<int>(vector_template, Type::QVectorInt);
  register_vector_specialization<float>(vector_template, Type::QVectorFloat);
  register_vector_specialization<double>(vector_template, Type::QVectorDouble);
}
