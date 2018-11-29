// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_TYPE_H
#define YASL_META_TYPE_H

#include <QJsonObject>
#include <QString>

#include "qtversion.h"

namespace yaml
{
class Object;
}

class Type
{
public:
  QString name;
  QString id;
  QString rename;
  QString header;
  QString tag;
  QString links;
  QString metatype;
  QtVersion version;

public:
  Type() = default;
  Type(const QString & n, const QString & id);
  ~Type() = default;

  enum Category {
    FundamentalType,
    ClassType,
    EnumType,
  };

  QJsonObject toJson() const;
  static Type fromJson(const QJsonObject & obj);

  QString toYaml() const;
  static Type fromYaml(const yaml::Object & obj);
};

#endif // YASL_META_TYPE_H
