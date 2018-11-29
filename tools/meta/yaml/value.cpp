// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yaml/value.h"

namespace yaml
{

class ValueImpl
{
public:
  virtual ~ValueImpl() = default;
};

class StringValueImpl : public ValueImpl
{
public:
  QString value;

public:
  StringValueImpl(const QString & str)
    : value(str) { }

  ~StringValueImpl() = default;
};

class ArrayValueImpl : public ValueImpl
{
public:
  QList<Value> value;

public:
  ArrayValueImpl(const QList<Value> & v)
    : value(v) { }

  ~ArrayValueImpl() = default;
};

class ObjectValueImpl : public ValueImpl
{
public:
  QMap<QString, Value> value;

public:
  ObjectValueImpl(const QMap<QString, Value> & v)
    : value(v) { }

  ~ObjectValueImpl() = default;
};

static QStringList serialize_object(const yaml::Object & obj, int indent);
static QStringList serialize_array(const yaml::Array & list, int indent);
static QStringList serialize_value(const yaml::Value & val, int indent);

static QString serialize_get_indent(int n)
{
  static const QString single_indent = "  ";
  static QList<QString> indents = {};

  if (indents.size() > n && !indents.at(n).isNull())
    return indents.at(n);

  QString ret = single_indent.repeated(n);
  if (n = indents.size())
    indents.append(ret);

  return ret;
}

static QString serialize_string(QString str, int indent)
{
  QString indent_str = serialize_get_indent(indent);

  if (str.isEmpty())
    return indent_str + "\"\"";
  if (str.startsWith(' ') || str.endsWith(' '))
    return indent_str + QString("\"") + str + QString("\"");
  return indent_str + str;
}

QStringList serialize_object(const yaml::Object & obj, int indent)
{
  QStringList lines;

  if (obj.contains("name"))
  {
    lines << (serialize_get_indent(indent) + "name: " + serialize_string(obj.value("name").toString(), 0));
  }

  for (auto it = obj.underlyingMap().begin(); it != obj.underlyingMap().end(); ++it)
  {
    QString key = it.key();
    if (key == "name")
      continue;

    yaml::Value val = it.value();

    if (val.isNull() || val.isString())
    {
      lines << (serialize_get_indent(indent) + key + ": " + serialize_string(val.toString(), 0));
    }
    else
    {
      lines << (serialize_get_indent(indent) + key + ":");
      QStringList elem = serialize_value(val, indent + 1);
      lines << elem;
    }
  }

  return lines;
}

QStringList serialize_array(const yaml::Array & list, int indent)
{
  QStringList lines;

  for (int i(0); i < list.size(); ++i)
  {
    QStringList elem = serialize_value(list.at(i), indent + 1);
    QString & first_line = elem[0];
    first_line[2 * indent] = '-';
    lines << elem;
  }

  return lines;
}

QStringList serialize_value(const yaml::Value & val, int indent)
{
  if (val.isObject())
    return serialize_object(val.toObject(), indent);
  else if (val.isArray())
    return serialize_array(val.toArray(), indent);

  QStringList lines;
  lines << serialize_string(val.toString(), indent);
  return lines;
}


Value::Value(const QString & str)
  : d(QSharedPointer<StringValueImpl>::create(str))
{

}

Value::Value(const QList<Value> & list)
  : d(QSharedPointer<ArrayValueImpl>::create(list))
{

}

Value::Value(const QMap<QString, Value> & map)
  : d(QSharedPointer<ObjectValueImpl>::create(map))
{

}

Value::Value(QSharedPointer<ValueImpl> impl)
  : d(impl)
{

}


bool Value::isString() const
{
  return !isNull() && dynamic_cast<const StringValueImpl*>(d.data()) != nullptr;
}

bool Value::isObject() const
{
  return !isNull() && dynamic_cast<const ObjectValueImpl*>(d.data()) != nullptr;
}

bool Value::isArray() const
{
  return !isNull() && dynamic_cast<const ArrayValueImpl*>(d.data()) != nullptr;
}


QString Value::toString() const
{
  return isString() ? static_cast<const StringValueImpl*>(d.data())->value : QString();
}

Array Value::toArray() const
{
  return Array(d);
}

Object Value::toObject() const
{
  return Object(d);
}

QString Value::serialize() const
{
  if (isObject())
  {
    return serialize_object(toObject(), 0).join("\n");
  }
  else if(isArray())
  {
    return serialize_array(toArray(), 0).join("\n");
  }
  else
  {
    return serialize_string(toString(), 0).at(0);
  }
}

Value & Value::operator=(const QString & str)
{
  d = QSharedPointer<StringValueImpl>::create(str);
  return *this;
}

Value & Value::operator=(nullptr_t)
{
  d = nullptr;
  return *this;
}


Array::Array()
  : Value(QSharedPointer<ArrayValueImpl>::create(QList<Value>()))
{

}

Array::Array(QSharedPointer<ValueImpl> impl)
  : Value(qSharedPointerCast<ArrayValueImpl>(impl))
{

}

Array::Array(const QList<Value> & list)
  : Value(QSharedPointer<ArrayValueImpl>::create(list))
{

}

QList<Value> & Array::underlyingList() const
{
  return static_cast<ArrayValueImpl*>(d.data())->value;
}

Value Array::at(int index) const
{
  return underlyingList().at(index);
}

void Array::push(const Value & val)
{
  underlyingList().append(val);
}


Array & Array::operator=(const Array & other)
{
  d = other.d;
  return *this;
}

Object::Object()
  : Value(QSharedPointer<ObjectValueImpl>::create(QMap<QString, Value>()))
{

}

Object::Object(QSharedPointer<ValueImpl> impl)
  : Value(qSharedPointerCast<ObjectValueImpl>(impl))
{

}

Object::Object(const QMap<QString, Value> & map)
  : Value(QSharedPointer<ObjectValueImpl>::create(map))
{

}

QMap<QString, Value> & Object::underlyingMap() const
{
  return static_cast<ObjectValueImpl*>(d.data())->value;
}

bool Object::contains(const QString & key) const
{
  return underlyingMap().contains(key);
}

Value Object::value(const QString & key) const
{
  return underlyingMap().value(key, yaml::Value{});
}

void Object::insert(const QString & key, yaml::Value val)
{
  underlyingMap().insert(key, val);
}

void Object::remove(const QString & key)
{
  underlyingMap().remove(key);
}

Value & Object::operator[](const QString & str)
{
  return underlyingMap()[str];
}

Object & Object::operator=(const Object & other)
{
  d = other.d;
  return *this;
}

} // namespace yaml
