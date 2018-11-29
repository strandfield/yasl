// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_YAML_VALUE_H
#define YASL_META_YAML_VALUE_H

#include <QList>
#include <QMap>
#include <QSharedPointer>
#include <QString>

namespace yaml
{

class Array;
class Object;

class ValueImpl;

class Value
{
public:
  Value() = default;
  Value(const Value &) = default;
  ~Value() = default;

  Value(const QString & str);
  explicit Value(const QList<Value> & list);
  explicit Value(const QMap<QString, Value> & map);
  explicit Value(QSharedPointer<ValueImpl> impl);

  inline bool isNull() const { return d == nullptr; }

  bool isString() const;
  bool isObject() const;
  bool isArray() const;

  QString toString() const;
  Array toArray() const;
  Object toObject() const;

  QString serialize() const;

  Value & operator=(const Value &) = default;
  Value & operator=(const QString & str);
  Value & operator=(nullptr_t);

protected:
  QSharedPointer<ValueImpl> d;
};

class Array : public Value
{
public:
  Array();
  Array(const Array &) = default;
  ~Array() = default;
  explicit Array(QSharedPointer<ValueImpl> impl);

  explicit Array(const QList<Value> & list);

  QList<Value> & underlyingList() const;

  inline QList<Value>::Iterator begin() { return underlyingList().begin(); }
  inline QList<Value>::Iterator end() { return underlyingList().end(); }

  inline int size() const { return underlyingList().size(); }
  Value at(int index) const;
  void push(const Value & val);

  Array & operator=(const Array & other);
};

class Object : public Value
{
public:
  Object();
  Object(const Object &) = default;
  ~Object() = default;
  explicit Object(QSharedPointer<ValueImpl> impl);

  explicit Object(const QMap<QString, Value> & map);

  QMap<QString, Value> & underlyingMap() const;

  bool contains(const QString & key) const;
  Value value(const QString & key) const;
  inline int size() const { return underlyingMap().size(); }
  void insert(const QString & key, yaml::Value val);
  void remove(const QString & key);

  Value & operator[](const QString & str);

  Object & operator=(const Object & other);
};

} // namespace yaml

#endif // YASL_META_YAML_VALUE_H