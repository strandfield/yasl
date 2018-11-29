// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/class.h"

#include "yaml/value.h"

#include <QJsonArray>

const QString Class::staticTypeCode = "class";

Class::Class(const QString & n, Qt::CheckState c)
  : Node(n, c)
  , isFinal(false)
{

}

QString Class::display() const
{
  QString ret = name;
  if (isFinal)
    ret += " final";
  if (!base.isEmpty())
    ret += " : " + base;

  if (!version.isNull())
    ret += " [" + version.toString() + "]";

  return ret;
}

void Class::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  QJsonArray elems;
  for (const auto & e : elements)
    elems.append(e->toJson());

  obj["elements"] = elems;

  if (!base.isEmpty())
    obj["base"] = base;

  if (isFinal)
    obj["final"] = isFinal;
}

QSharedPointer<Node> Class::fromJson(const QJsonObject & obj)
{
  auto ret = ClassRef::create(obj.value("name").toString(), json::readCheckState(obj));
  ret->version = json::readQtVersion(obj);

  QJsonArray elements = obj.value("elements").toArray();
  ret->elements.reserve(elements.size());
  for (const auto & item : elements)
    ret->elements.push_back(Node::fromJson(item.toObject()));

  ret->base = obj.value("base").toString();

  if (!obj.contains("final"))
    ret->isFinal = false;
  else
    ret->isFinal = obj.value("final").toBool();

  return ret;
}

yaml::Value Class::toYaml() const
{
  yaml::Object content;

  content["name"] = name;
  yaml::writeCheckstate(content, checkState);
  yaml::writeQtVersion(content, version);

  if (!base.isEmpty())
    content["base"] = base;

  if (isFinal)
    content["final"] = "true";

  {
    yaml::Array elems;

    for (const auto & e : elements)
    {
      elems.push(e->toYaml());
    }

    content["elements"] = elems;
  }

  yaml::Object ret;
  ret["class"] = content;
  return ret;
}

QSharedPointer<Node> Class::fromYaml(const yaml::Object & inputobj)
{
  yaml::Object obj = inputobj.value("class").toObject();

  auto ret = ClassRef::create(obj.value("name").toString(), yaml::readCheckState(obj));
  ret->version = yaml::readQtVersion(obj);

  yaml::Array elements = obj.value("elements").toArray();
  ret->elements.reserve(elements.size());
  for (const auto & item : elements.underlyingList())
    ret->elements.push_back(Node::fromYaml(item.toObject()));

  ret->base = obj.value("base").toString();
  ret->isFinal = obj.value("final").toString() == "true";

  return ret;
}
