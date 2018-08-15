// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/namespace.h"

#include <QJsonArray>

const QString Namespace::staticTypeCode = "namespace";

Namespace::Namespace(const QString & n, Qt::CheckState c)
  : Node(n, c)
{

}

void Namespace::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  QJsonArray elems;
  for (const auto & e : elements)
    elems.append(e->toJson());

  obj["elements"] = elems;

  if (!rename.isEmpty())
    obj["rename"] = rename;
}

QSharedPointer<Node> Namespace::fromJson(const QJsonObject & obj)
{
  auto ret = NamespaceRef::create(obj.value("name").toString(), json::readCheckState(obj));

  QJsonArray elements = obj.value("elements").toArray();
  ret->elements.reserve(elements.size());
  for (const auto & item : elements)
    ret->elements.push_back(Node::fromJson(item.toObject()));

  ret->rename = obj.value("rename").toString();

  return ret;
}

QSharedPointer<Namespace> Namespace::getNamespace(const QString & name)
{
  for (const auto & e : elements)
  {
    if (e->is<Namespace>() && e->name == name)
      return qSharedPointerCast<Namespace>(e);
  }

  auto ret = NamespaceRef::create(name);
  elements.append(ret);
  return ret;
}

