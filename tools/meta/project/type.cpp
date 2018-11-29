// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/type.h"

#include "yaml/value.h"

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
  if (!header.isEmpty())
    ret["header"] = header;
  if (!tag.isEmpty())
    ret["tag"] = tag;
  if (!links.isEmpty())
    ret["links"] = links;
  if (!metatype.isEmpty())
    ret["metatype"] = metatype;

  return ret;
}

Type Type::fromJson(const QJsonObject & obj)
{
  Type ret{ obj.value("name").toString(), obj.value("id").toString() };
  ret.rename = obj.value("rename").toString();
  ret.header = obj.value("header").toString();
  ret.tag = obj.value("tag").toString();
  ret.links = obj.value("links").toString();
  ret.metatype = obj.value("metatype").toString();
  return ret;
}

static QString quote(QString str)
{
  if (str.contains(','))
    return QString("\"%1\"").arg(str);
  return str;
}

QString Type::toYaml() const
{
  QStringList elems;

  elems << ("id: " + id);
  elems << ("name: " + quote(name));

  if (!rename.isEmpty())
    elems << ("rename: " + rename);
  if (!header.isEmpty())
    elems << ("header: " + header);
  if (!tag.isEmpty())
    elems << ("tag: " + tag);
  if (!links.isEmpty())
    elems << ("links: " + quote(links));
  if (!metatype.isEmpty())
    elems << ("metatype: " + metatype);

  return "{" + elems.join(", ") + "}";
}

Type Type::fromYaml(const yaml::Object & obj)
{
  Type ret;
  ret.id = obj.value("id").toString();
  ret.name = obj.value("name").toString();
  ret.rename = obj.value("rename").toString();
  ret.header = obj.value("header").toString();
  ret.tag = obj.value("tag").toString();
  ret.links = obj.value("links").toString();
  ret.metatype = obj.value("metatype").toString();
  return ret;
}
