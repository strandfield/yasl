// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/file.h"

#include <QJsonArray>
#include <QJsonObject>

const QString File::staticTypeCode = "file";

File::File(const QString & n, Qt::CheckState c)
  : Namespace(n, c)
{

}

void File::fillJson(QJsonObject & obj) const
{
  Namespace::fillJson(obj);

  if (!includes.empty())
    obj["includes"] = includes.join(",");
}

QSharedPointer<Node> File::fromJson(const QJsonObject & obj)
{
  FileRef ret = FileRef::create(obj.value("name").toString(), json::readCheckState(obj));

  QJsonArray elements = obj.value("elements").toArray();
  ret->elements.reserve(elements.size());
  for (const auto & item : elements)
    ret->elements.push_back(Node::fromJson(item.toObject()));

  if (obj.contains("includes"))
    ret->includes = obj.value("includes").toString().split(",", QString::SkipEmptyParts);

  return ret;
}
