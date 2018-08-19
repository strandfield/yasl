// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/class.h"

#include <QJsonArray>

const QString Class::staticTypeCode = "class";

Class::Class(const QString & n, Qt::CheckState c)
  : Node(n, c)
  , isFinal(false)
{

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

