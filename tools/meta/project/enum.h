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

  static const QString staticTypeCode;

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  QString typeCode() const override { return staticTypeCode; }
};
typedef QSharedPointer<Enumerator> EnumeratorRef;


class Enum : public Node
{
public:
  QList<EnumeratorRef> enumerators;

public:
  Enum(const QString & n, Qt::CheckState c = Qt::Checked);
  ~Enum() = default;

  static const QString staticTypeCode;

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  QString typeCode() const override { return staticTypeCode; }

};
typedef QSharedPointer<Enum> EnumRef;

#endif // YASL_META_ENUM_H