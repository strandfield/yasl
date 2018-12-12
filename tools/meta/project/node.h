// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_NODE_H
#define YASL_META_NODE_H

#include <QJsonObject>
#include <QMap>
#include <QSharedPointer>
#include <QStack>

#include "qtversion.h"

namespace yaml
{
class Value;
class Object;
QString extractField(QString str, const QString & fieldName);
QString createField(const QString &fieldName, const QString & content);
QString checkStateField(Qt::CheckState cs);
Qt::CheckState checkstate(const QString & str);
void writeCheckstate(yaml::Object & obj, Qt::CheckState cs);
Qt::CheckState readCheckState(const yaml::Object & obj);
QtVersion readQtVersion(const yaml::Object & obj);
void writeQtVersion(yaml::Object & obj, QtVersion v);
int firstFieldIndex(const QString & str);
QString extractName(QString str);
} // namespace yaml

namespace json
{
Qt::CheckState readCheckState(const QJsonObject & obj);
void writeCheckState(QJsonObject & obj, Qt::CheckState cs);
QtVersion readQtVersion(const QJsonObject & obj);
void writeQtVersion(QJsonObject & obj, QtVersion v);
} //  namespace json

enum class NodeType
{
  Module,
  File,
  Namespace,
  Enum,
  Enumerator,
  Class,
  Constructor,
  Destructor,
  Function,
  Statement,
};

class Node
{
public:
  Node(const QString & n, Qt::CheckState c = Qt::Checked);
  virtual ~Node() = default;

  template<typename T>
  bool is() const
  {
    return dynamic_cast<const T*>(this) != nullptr;
  }

  template<typename T>
  T & as()
  {
    return *dynamic_cast<T*>(this);
  }

  virtual void fillJson(QJsonObject & obj) const;
  QJsonObject toJson() const;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  virtual yaml::Value toYaml() const = 0;
  static QSharedPointer<Node> fromYaml(const yaml::Object & val);
  typedef QSharedPointer<Node>(*YamlDeserializer)(const yaml::Object &);
  static QMap<QString, YamlDeserializer> staticYamlFactory;
  static void registerDeserializer(const QString & name, YamlDeserializer func);

  virtual QString display() const { return name; }
  virtual QString typeName() const = 0;
  virtual NodeType typeCode() const = 0;

  typedef QSharedPointer<Node>(*JsonDeserializer)(const QJsonObject &);
  static QMap<QString, JsonDeserializer> staticFactory;
  static void registerDeserializer(const QString & name, JsonDeserializer func);

  static QString nameQualification(const QStack<QSharedPointer<Node>> & nodes);

  static int compare(const Node & a, const Node & b);

  QString name;
  Qt::CheckState checkState;
  QtVersion version;

protected:
  virtual int compareTo(const Node & other) const;
};
typedef QSharedPointer<Node> NodeRef;

Q_DECLARE_METATYPE(QSharedPointer<Node>);

/// TODO: this seems to be dead code, remove!
class NodeValue
{
public:
  NodeRef value;

  NodeValue();
  NodeValue(const NodeRef & val) : value(val) { }
  NodeValue(const NodeValue & ) = default;

  NodeValue & operator=(const NodeValue &) = default;
};

bool eq(const NodeRef & lhs, const NodeRef & rhs);
inline bool neq(const NodeRef & lhs, const NodeRef & rhs)
{
  return !eq(lhs, rhs);
}

void sort(QList<NodeRef> & list);

#endif // YASL_META_NODE_H
