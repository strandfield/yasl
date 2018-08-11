// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/type.h"

Type::Type(const QString & n, const QString & id)
  : name(n)
  , id(id)
{

}

QJsonObject Type::toJson() const
{
  QJsonObject ret;
  ret["name"] = name;
  ret["id"] = id;

  if(!rename.isEmpty())
    ret["rename"] = rename;
  if (!starid.isEmpty())
    ret["starid"] = starid;
  if (!header.isEmpty())
    ret["header"] = header;
  if (!storage.isEmpty())
    ret["storage"] = storage;
  if (!ptrid.isEmpty())
    ret["ptrid"] = ptrid;

  return ret;
}

Type Type::fromJson(const QJsonObject & obj)
{
  Type ret{ obj.value("name").toString(), obj.value("id").toString() };
  ret.rename = obj.value("rename").toString();
  ret.header = obj.value("header").toString();
  ret.starid = obj.value("starid").toString();
  ret.storage = obj.value("storage").toString();
  ret.ptrid = obj.value("ptrid").toString();
  return ret;
}