// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_ENUM_H
#define YASL_META_ENUM_H

#include "project/node.h"

class Enumerator : public Node
{
public:
  QString rename;

public:
  Enumerator(const QString & n, Qt::CheckState c = Qt::Checked);
  ~Enumerator() = default;

  QString typeName() const override { return "enumerator"; }
  static const NodeType staticTypeCode = NodeType::Enumerator;
  NodeType typeCode() const override { return staticTypeCode; }

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  yaml::Value toYaml() const override;
  static QSharedPointer<Enumerator> fromYaml(const QString & str);
};

typedef QSharedPointer<Enumerator> EnumeratorRef;


class Enum : public Node
{
public:
  QList<EnumeratorRef> enumerators;
  bool isCppEnumClass;
  bool isEnumClass;

public:
  Enum(const QString & n, Qt::CheckState c = Qt::Checked);
  ~Enum() = default;

  QString display() const override;

  QString typeName() const override { return "enum"; }
  static const NodeType staticTypeCode = NodeType::Enum;
  NodeType typeCode() const override { return staticTypeCode; }

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  yaml::Value toYaml() const override;
  static QSharedPointer<Node> fromYaml(const yaml::Object & val);

  void merge(const Enum & other);
};
typedef QSharedPointer<Enum> EnumRef;

#endif // YASL_META_ENUM_H
