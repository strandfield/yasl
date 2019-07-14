// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/vector.h"
#include "yasl/common/vectorspecializations.h"

#include "yasl/common/value.h"

#include <script/classtemplate.h>
#include <script/classtemplateinstancebuilder.h>
#include <script/constructorbuilder.h>
#include <script/private/engine_p.h>
#include <script/templatebuilder.h>

#include <cstring>

using Vec = QVector<yasl::Value>;

static script::Value make_vector(const QVector<yasl::Value> & val, const script::Type & vector_type, script::Engine *e)
{
  script::Value ret = e->allocate(vector_type);
  script::ThisObject(ret).init<Vec>(val);
  return ret;
}

namespace callbacks
{

// QVector<T>();
static script::Value default_ctor(script::FunctionCall *c)
{
  using namespace script;
  c->thisObject().init<Vec>();
  return c->thisObject();
}

// QVector<T>(const QVector<T> &);
static script::Value copy_ctor(script::FunctionCall *c)
{
  using namespace script;
  QVector<yasl::Value> & other = script::get<QVector<yasl::Value>>(c->arg(1));
  c->thisObject().init<Vec>(other);
  return c->thisObject();
}

// ~QVector<T>();
static script::Value dtor(script::FunctionCall *c)
{
  using namespace script;
  c->thisObject().destroy<Vec>();
  return script::Value::Void;
}

// QVector(int size);
static script::Value size_ctor(script::FunctionCall *c)
{
  using namespace script;
  const int size = script::value_cast<int>(c->arg(1));
  c->thisObject().init<Vec>(size);
  return c->thisObject();
}

// QVector(int size, const T &value);
static script::Value size_value_ctor(script::FunctionCall *c)
{
  using namespace script;
  const int size = script::value_cast<int>(c->arg(1));
  auto ti = yasl::TypeInfo::get(c->callee().memberOf());
  c->thisObject().init<Vec>(size, yasl::Value{ ti, c->arg(2) });
  return c->thisObject();
}

/// TODO: QVector(QVector<T> &&other);
/// TODO: QVector(std::initializer_list<T> args);

// void append(const T &value);
// void push_back(const T &value);
static script::Value append_value(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  auto ti = yasl::TypeInfo::get(c->callee().memberOf());
  self.append(yasl::Value{ ti, c->arg(1) });
  return script::Value::Void;
}

/// TODO: void append(T &&value);

#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
// void append(const QVector<T> &value);
static script::Value append_vector(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  QVector<yasl::Value> & other = script::value_cast<QVector<yasl::Value> &>(c->arg(1));
  self.append(other);
  return script::Value::Void;
}
#endif

// const T & at(int i) const;
// const T & operator[](int i) const
static script::Value at(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  return self.at(c->arg(1).toInt()).get();
}

// QVector::reference back();
// QVector::const_reference back() const;
// const T & constLast() const;
// T & last();
// const T & last() const;
static script::Value back(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  return self.back().get();
}

/// TODO: QVector::iterator begin();
/// TODO: QVector::const_iterator begin() const;

// int capacity() const;
static script::Value capacity(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  return c->engine()->newInt(self.capacity());
}

/// TODO: QVector::const_iterator cbegin() const;
/// TODO: QVector::const_iterator cend() const;

// void clear();
static script::Value clear(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  self.clear();
  return script::Value::Void;
}

/// TODO: QVector::const_iterator constBegin() const;
/// ignore: const T * constData() const;
/// TODO: QVector::const_iterator constEnd() const;

#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
// const T & constFirst() const;
// T & first();
// const T & first() const;
// T & front();
// QVector::const_reference front() const;
static script::Value const_first(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  return self.constFirst().get();
}
#endif

// T & first();
// T & front();
static script::Value first(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  return self.first().get();
}

// bool contains(const T &value) const;
static script::Value contains(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const bool result = self.contains(value);
  return c->engine()->newBool(result);
}

// int count(const T &value) const;
static script::Value count_element(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int result = self.count(value);
  return c->engine()->newInt(result);
}

// int count() const;
// int length() const;
// int size() const;
static script::Value count(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
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
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  return c->engine()->newBool(self.isEmpty());
}

/// TODO: QVector::iterator end();
/// TODO: QVector::const_iterator end() const;

// bool endsWith(const T &value) const;
static script::Value ends_with(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const bool result = self.endsWith(value);
  return c->engine()->newBool(result);
}

/// TODO: QVector::iterator erase(QVector::iterator pos);
/// TODO; QVector::iterator erase(QVector::iterator begin, QVector::iterator end);

// QVector<T> & fill(const T &value, int size = ...);
static script::Value fill(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int size = c->arg(2).toInt();
  self.fill(value, size);
  return c->thisObject();
}

// int indexOf(const T &value, int from = ...) const;
static script::Value index_of(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int from = c->arg(2).toInt();
  const int result = self.indexOf(value, from);
  return c->engine()->newInt(result);
}

/// TODO: void insert(int i, T &&value);

// void insert(int i, const T &value);
static script::Value insert(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(2) };
  self.insert(i, value);
  return script::Value::Void;
}

// void insert(int i, int count, const T &value);
static script::Value insert_count(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  const int count = c->arg(2).toInt();
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(3) };
  self.insert(i, count, value);
  return script::Value::Void;
}

/// TODO: QVector::iterator insert(QVector::iterator before, int count, const T &value);
/// TODO: QVector::iterator insert(QVector::iterator before, const T &value);
/// TODO: QVector::iterator insert(QVector::iterator before, T &&value);

// int lastIndexOf(const T &value, int from = ...) const;
static script::Value last_index_of(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int from = c->arg(2).toInt();
  const int result = self.lastIndexOf(value, from);
  return c->engine()->newInt(result);
}

// QVector<T> mid(int pos, int length = ...) const;
static script::Value mid(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int pos = c->arg(1).toInt();
  const int length = c->arg(2).toInt();
  return make_vector(self.mid(pos, length), c->callee().returnType(), c->engine());
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
// void move(int from, int to);
static script::Value move(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int from = c->arg(1).toInt();
  const int to = c->arg(2).toInt();
  self.move(from, to);
  return script::Value::Void;
}
#endif

// void pop_back();
// void removeLast();
static script::Value pop_back(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  self.pop_back();
  return script::Value::Void;
}

// void pop_front();
// void removeFirst();
static script::Value pop_front(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  self.pop_front();
  return script::Value::Void;
}

/// TODO: void prepend(T &&value);

// void prepend(const T &value);
// void push_front(const T &value);
static script::Value prepend(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  auto ti = yasl::TypeInfo::get(c->callee().memberOf());
  self.prepend(yasl::Value{ ti, c->arg(1) });
  return script::Value::Void;
}


/// TODO: void push_back(T &&value);
/// TODO: void push_front(T &&value);

/// TODO: QVector::reverse_iterator rbegin();
/// TODO: QVector::const_reverse_iterator rbegin() const;

// void remove(int i);
static script::Value remove(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  self.remove(i);
  return script::Value::Void;
}

// void remove(int i, int count);
static script::Value remove_count(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  const int count = c->arg(2).toInt();
  self.remove(i, count);
  return script::Value::Void;
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
// int removeAll(const T &t);
static script::Value remove_all(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const int result = self.removeAll(value);
  return c->engine()->newInt(result);
}
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
// bool removeOne(const T &t);
static script::Value remove_one(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const bool result = self.removeOne(value);
  return c->engine()->newBool(result);
}
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
/// TODO: QVector::reverse_iterator rend();
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
/// TODO: QVector::const_reverse_iterator rend() const;
#endif

// void replace(int i, const T &value);
static script::Value replace(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(2) };
  self.replace(i, value);
  return script::Value::Void;
}

// void reserve(int size);
static script::Value reserve(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  self.reserve(i);
  return script::Value::Void;
}

// void resize(int size);
static script::Value resize(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  self.resize(i);
  return script::Value::Void;
}

// void shrink_to_fit();
// void squeeze();
static script::Value squeeze(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  self.squeeze();
  return script::Value::Void;
}

// bool startsWith(const T &value) const;
static script::Value starts_with(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  const bool result = self.startsWith(value);
  return c->engine()->newBool(result);
}

// void swap(QVector<T> &other);
static script::Value swap(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  QVector<yasl::Value> & other = script::value_cast<QVector<yasl::Value> &>(c->arg(1));
  self.swap(other);
  return script::Value::Void;
}

#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
// T takeAt(int i);
static script::Value take_at(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  auto ret = self.takeAt(i);
  return ret.release();
}
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
// T takeFirst();
static script::Value take_first(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  auto ret = self.takeFirst();
  return ret.release();
}
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
// T takeLast();
static script::Value take_last(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  auto ret = self.takeLast();
  return ret.release();
}
#endif

/// TODO: QList<T> toList() const;
/// ignore: std::vector<T> toStdVector() const;

// T value(int i) const;
static script::Value value(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  yasl::Value ret = self.value(i);
  if (ret.isValid())
    return ret.release();
  auto ti = yasl::TypeInfo::get(c->callee().memberOf());
  return c->engine()->construct(ti->element_type, {});
}

// T value(int i, const T &defaultValue) const;
static script::Value value_with_default(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  yasl::Value ret = self.value(i, yasl::Value{});
  if (ret.isValid())
    return ret.release();
  return c->engine()->copy(c->arg(2));
}

// bool operator!=(const QVector<T> &other) const;
static script::Value op_neq(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  QVector<yasl::Value> & other = script::value_cast<QVector<yasl::Value> &>(c->arg(1));
  const bool result = self != other;
  return c->engine()->newBool(result);
}

// QVector<T> operator+(const QVector<T> &other) const;
static script::Value op_add(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  QVector<yasl::Value> & other = script::value_cast<QVector<yasl::Value> &>(c->arg(1));
  return make_vector(self + other, c->callee().returnType(), c->engine());
}

// QVector<T> & operator+=(const QVector<T> &other);
static script::Value op_add_assign(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  QVector<yasl::Value> & other = script::value_cast<QVector<yasl::Value> &>(c->arg(1));
  self += other;
  return c->thisObject();
}

// QVector<T> & operator+=(const T &value);
static script::Value op_add_assign_value(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  yasl::ObserverValue value{ yasl::TypeInfo::get(c->callee().memberOf()), c->arg(1) };
  self += value;
  return c->thisObject();
}

/// TODO: QVector<T> & operator+=(T &&value);

// QVector<T> & operator<<(const T &value);
static script::Value op_put_value(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  QVector<yasl::Value> & other = script::value_cast<QVector<yasl::Value> &>(c->arg(1));
  self << other;
  return c->thisObject();
}

// QVector<T> & operator<<(const QVector<T> &other);
static script::Value op_put_vector(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  auto ti = yasl::TypeInfo::get(c->callee().memberOf());
  self.append(yasl::Value{ ti, c->arg(1) });
  return c->thisObject();
}

/// TODO: QVector<T> & operator<<(T &&value);

// QVector<T> & operator=(const QVector<T> &other);
static script::Value op_assign(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  QVector<yasl::Value> & other = script::value_cast<QVector<yasl::Value> &>(c->arg(1));
  self = other;
  return c->thisObject();
}

/// TODO: QVector<T> & operator=(QVector<T> &&other);

// bool operator==(const QVector<T> &other) const;
static script::Value op_eq(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  QVector<yasl::Value> & other = script::value_cast<QVector<yasl::Value> &>(c->arg(1));
  const bool result = self == other;
  return c->engine()->newBool(result);
}

// T & operator[](int i);
static script::Value op_subscript(script::FunctionCall *c)
{
  QVector<yasl::Value> & self = script::value_cast<QVector<yasl::Value> &>(c->thisObject());
  const int i = c->arg(1).toInt();
  return self[i].get();
}

} // namespace callbacks


namespace script
{

Class VectorTemplate::instantiate(ClassTemplateInstanceBuilder& builder)
{
  using namespace script;

  builder.setFinal();
  const Type element_type = builder.arguments().front().type;

  builder.setData(yasl::TypeInfo::get(builder.getTemplate().engine(), element_type));

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
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: void append(T &&value);
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
  // void append(const QVector<T> &value);
  vector.newMethod("append", callbacks::append_vector)
    .params(Type::cref(vector.id())).create();
#endif
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
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  // const T & constFirst() const;
  vector.newMethod("constFirst", callbacks::const_first)
    .returns(Type::cref(element_type)).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  // const T & constLast() const;
  vector.newMethod("constLast", callbacks::back)
    .returns(Type::cref(element_type)).create();
#endif
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
  vector.newMethod("first", callbacks::first)
    .returns(Type::ref(element_type)).create();
  // const T & first() const;
  vector.newMethod("first", callbacks::first)
    .setConst()
    .returns(Type::cref(element_type)).create();
  // T & front();
  vector.newMethod("front", callbacks::first)
    .returns(Type::ref(element_type)).create();
  // QVector::const_reference front() const;
  vector.newMethod("front", callbacks::first)
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
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // int length() const;
  vector.newMethod("length", callbacks::count)
    .setConst()
    .returns(Type::Int).create();
#endif
  // QVector<T> mid(int pos, int length = ...) const;
  vector.newMethod("mid", callbacks::mid)
    .setConst()
    .returns(vector.id())
    .params(Type::Int, Type::Int)
    .apply(bind::default_arguments(-1)).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  // void move(int from, int to);
  vector.newMethod("move", callbacks::move)
    .params(Type::Int, Type::Int).create();
#endif
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
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: void push_back(T &&value);
#endif
  /// TODO: void push_front(T &&value);
  // void push_front(const T &value);
  vector.newMethod("push_front", callbacks::prepend)
    .params(Type::cref(element_type)).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: QVector::reverse_iterator rbegin();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: QVector::const_reverse_iterator rbegin() const;
#endif
  // void remove(int i);
  vector.newMethod("remove", callbacks::remove)
    .params(Type::Int).create();
  // void remove(int i, int count);
  vector.newMethod("remove", callbacks::remove_count)
    .params(Type::Int, Type::Int).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
  // int removeAll(const T &t);
  vector.newMethod("removeAll", callbacks::remove_all)
    .returns(Type::Int)
    .params(Type::cref(element_type)).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // void removeAt(int i);
  vector.newMethod("removeAt", callbacks::remove)
    .params(Type::Int).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
  // void removeFirst();
  vector.newMethod("removeFirst", callbacks::pop_front).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
  // void removeLast();
  vector.newMethod("removeLast", callbacks::pop_back).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 4, 0)
  // bool removeOne(const T &t);
  vector.newMethod("removeOne", callbacks::remove_one)
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: QVector::reverse_iterator rend();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
  /// TODO: QVector::const_reverse_iterator rend() const;
#endif
  // void replace(int i, const T &value);
  vector.newMethod("replace", callbacks::replace)
    .params(Type::Int, Type::cref(element_type)).create();
  // void reserve(int size);
  vector.newMethod("reserve", callbacks::reserve)
    .params(Type::Int).create();
  // void resize(int size);
  vector.newMethod("resize", callbacks::resize)
    .params(Type::Int).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
  // void shrink_to_fit();
  vector.newMethod("shrink_to_fit", callbacks::squeeze).create();
#endif
  // int size() const;
  vector.newMethod("size", callbacks::count)
    .setConst()
    .returns(Type::Int).create();
  // void squeeze();
  vector.newMethod("squeeze", callbacks::squeeze).create();
  // bool startsWith(const T &value) const;
  vector.newMethod("startsWith", callbacks::starts_with)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(element_type)).create();
  // void swap(QVector<T> &other);
  vector.newMethod("swap", callbacks::swap)
    .params(Type::ref(vector.id())).create();
#if QT_VERSION >= QT_VERSION_CHECK(5, 2, 0)
  // T takeAt(int i);
  vector.newMethod("takeAt", callbacks::take_at)
    .returns(element_type)
    .params(Type::Int).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
  // T takeFirst();
  vector.newMethod("takeFirst", callbacks::take_first)
    .returns(element_type).create();
#endif
#if QT_VERSION >= QT_VERSION_CHECK(5, 1, 0)
  // T takeLast();
  vector.newMethod("takeLast", callbacks::take_last)
    .returns(element_type).create();
#endif
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

} // namespace script

void register_vector_template(script::Namespace n)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{TemplateParameter::TypeParameter{}, "T"},
  };

  ClassTemplate vector_template = Symbol{ n }.newClassTemplate("Vector")
    .setParams(std::move(params))
    .setScope(Scope{ n })
    .withBackend<VectorTemplate>()
    .get();

  // Registering full specializations
  register_vector_specialization<int>(vector_template, Type::QVectorInt);
  register_vector_specialization<float>(vector_template, Type::QVectorFloat);
  register_vector_specialization<double>(vector_template, Type::QVectorDouble);
}
