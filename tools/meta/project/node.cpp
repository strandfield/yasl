// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/node.h"

#include "project/file.h"
#include "project/function.h"
#include "project/module.h"

QMap<QString, Node::JsonDeserializer> Node::staticFactory = QMap<QString, Node::JsonDeserializer>{};

namespace json
{

Qt::CheckState readCheckState(const QJsonObject & obj)
{
  if(obj.contains("checked"))
    return static_cast<Qt::CheckState>(obj.value("checked").toInt());
  return Qt::Checked;
}

void writeCheckState(QJsonObject & obj, Qt::CheckState cs)
{
  if(cs != Qt::Checked)
    obj["checked"] = static_cast<int>(cs);
}

QtVersion readQtVersion(const QJsonObject & obj)
{
  if (!obj.contains("version"))
    return {};

  QString version = obj.value("version").toString();
  return QtVersion::fromString(version);
}

void writeQtVersion(QJsonObject & obj, QtVersion v)
{
  if (v.isNull())
    return;

  obj["version"] = v.toString();
}

} // namespace json

Node::Node(const QString & n, Qt::CheckState c)
  : checkState(c)
  , name(n)
{

}

void Node::fillJson(QJsonObject & obj) const
{
  obj["name"] = this->name;
  json::writeCheckState(obj, this->checkState);
  obj["type"] = typeCode();
  json::writeQtVersion(obj, this->version);
}

QJsonObject Node::toJson() const
{
  QJsonObject result;
  fillJson(result);
  return result;
}

QSharedPointer<Node> Node::fromJson(const QJsonObject & obj)
{
  return staticFactory.value(obj.value("type").toString(), nullptr)(obj);
}

void Node::registerDeserializer(const QString & name, JsonDeserializer func)
{
  staticFactory[name] = func;
}

QString Node::nameQualification(const QStack<QSharedPointer<Node>> & nodes)
{
  if (nodes.isEmpty())
    return "";

  QStringList names;
  for (const auto & node : nodes)
  {
    if (node->is<File>() || node->is<Module>())
      continue;

    names << node->name;
  }

  if (names.empty())
    return "";
  return names.join("::") + "::";
}

bool eq(const NodeRef & lhs, const NodeRef & rhs)
{
  if (lhs->is<Function>() || rhs->is<Function>())
    return false;

  if (lhs->typeCode() != rhs->typeCode())
    return false;

  if (lhs->name != rhs->name)
    return false;

  if (lhs->display() != rhs->display())
    return false;

  return true;
}