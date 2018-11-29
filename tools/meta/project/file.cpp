// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/file.h"

#include "yaml/value.h"

#include <QJsonArray>
#include <QJsonObject>

const QString File::staticTypeCode = "file";

File::File(const QString & n, Qt::CheckState c)
  : Namespace(n, c)
{

}

QString File::display() const
{
  QString ret = this->name;

  if (!hincludes.isEmpty())
  {
    ret += " [h-includes:" + hincludes.join(",") + "]";
  }

  if (!cppincludes.isEmpty())
  {
    ret += " [cpp-includes:" + cppincludes.join(",") + "]";
  }

  return ret;
}

void File::fillJson(QJsonObject & obj) const
{
  Namespace::fillJson(obj);

  if (!hincludes.empty())
    obj["hincludes"] = hincludes.join(",");

  if (!cppincludes.empty())
    obj["cppincludes"] = cppincludes.join(",");
}

QSharedPointer<Node> File::fromJson(const QJsonObject & obj)
{
  FileRef ret = FileRef::create(obj.value("name").toString(), json::readCheckState(obj));

  QJsonArray elements = obj.value("elements").toArray();
  ret->elements.reserve(elements.size());
  for (const auto & item : elements)
    ret->elements.push_back(Node::fromJson(item.toObject()));

  if (obj.contains("hincludes"))
    ret->hincludes = obj.value("hincludes").toString().split(",", QString::SkipEmptyParts);

  if (obj.contains("cppincludes"))
    ret->cppincludes = obj.value("cppincludes").toString().split(",", QString::SkipEmptyParts);

  return ret;
}

yaml::Value File::toYaml() const
{
  yaml::Object content;

  content["name"] = name;
  yaml::writeCheckstate(content, checkState);

  if (!rename.isEmpty())
    content["rename"] = rename;

  {
    yaml::Array elems;

    for (const auto & e : elements)
    {
      elems.push(e->toYaml());
    }

    content["elements"] = elems;
  }

  if (!hincludes.empty())
  {
    content["hincludes"] = hincludes.join(";");
  }

  if (!cppincludes.empty())
  {
    content["cppincludes"] = cppincludes.join(";");
  }

  yaml::Object ret;
  ret[File::staticTypeCode] = content;
  return ret;
}

QSharedPointer<Node> File::fromYaml(const yaml::Object & inputobj)
{
  yaml::Object obj = inputobj.value("file").toObject();

  auto ret = FileRef::create(obj.value("name").toString(), yaml::readCheckState(obj));

  yaml::Array elements = obj.value("elements").toArray();
  ret->elements.reserve(elements.size());
  for (const auto & item : elements)
    ret->elements.push_back(Node::fromYaml(item.toObject()));

  ret->hincludes = obj.value("hincludes").toString().split(';', QString::SkipEmptyParts);
  ret->cppincludes = obj.value("cppincludes").toString().split(';', QString::SkipEmptyParts);

  return ret;
}
