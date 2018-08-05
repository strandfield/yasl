// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/enum.h"

#include <QJsonArray>

const QString Enum::staticTypeCode = "enum";
const QString Enumerator::staticTypeCode = "enumerator";

Enumerator::Enumerator(const QString & n, Qt::CheckState c)
  : Node(n, c)
{

}

void Enumerator::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  obj.remove("type");

  if (!rename.isEmpty())
    obj["rename"] = rename;
}

QSharedPointer<Node> Enumerator::fromJson(const QJsonObject & obj)
{
  auto ret = EnumeratorRef::create(obj.value("name").toString(), json::readCheckState(obj));
  if (obj.contains("rename"))
    ret->rename = obj.value("rename").toString();
  return ret;
}


Enum::Enum(const QString & n, Qt::CheckState c)
  : Node(n, c)
{

}

void Enum::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  QJsonArray enms;
  for (const auto & e : enumerators)
  {
    enms.append(e->toJson());
  }
  obj["enumerators"] = enms;
}

QSharedPointer<Node> Enum::fromJson(const QJsonObject & obj)
{
  auto ret = EnumRef::create(obj.value("name").toString(), json::readCheckState(obj));

  QJsonArray enumerators = obj.value("enumerators").toArray();
  for (const auto & item : enumerators)
    ret->enumerators.push_back(qSharedPointerCast<Enumerator>(Enumerator::fromJson(item.toObject())));

  return ret;
}
