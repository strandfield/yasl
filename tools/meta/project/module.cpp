// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/module.h"

#include "yaml/value.h"

#include <QJsonArray>
#include <QJsonObject>

const QString Module::staticTypeCode = "module";

Module::Module(const QString & n, Qt::CheckState c)
  : Node(n, c)
{

}

void Module::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  QJsonArray elems;
  for (const auto & e : elements)
    elems.append(e->toJson());

  obj["elements"] = elems;
}

QSharedPointer<Node> Module::fromJson(const QJsonObject & obj)
{
  ModuleRef ret = ModuleRef::create(obj.value("name").toString(), json::readCheckState(obj));

  QJsonArray elements = obj.value("elements").toArray();
  ret->elements.reserve(elements.size());
  for (const auto & item : elements)
    ret->elements.push_back(Node::fromJson(item.toObject()));

  return ret;
}

yaml::Value Module::toYaml() const
{
  yaml::Array elems;
  for (const auto & e : elements)
  {
    elems.push(e->toYaml());
  }

  yaml::Object ret;
  ret[name] = elems;
  return ret;
}

QSharedPointer<Module> Module::fromYaml(const yaml::Object & inputobj)
{
  auto it = inputobj.underlyingMap().begin();

  ModuleRef ret = ModuleRef::create(it.key(), Qt::Checked);

  yaml::Array elements = it.value().toArray();
  ret->elements.reserve(elements.size());
  for (const auto & item : elements)
    ret->elements.push_back(Node::fromYaml(item.toObject()));

  return ret;
}
