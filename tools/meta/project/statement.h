// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_STATEMENT_H
#define YASL_META_STATEMENT_H

#include "project/node.h"

class Statement : public Node
{
public:
  Statement(const QString & val, Qt::CheckState c = Qt::Checked);
  ~Statement() = default;

  static const QString staticTypeCode;

  void fillJson(QJsonObject & obj) const override;
  static QSharedPointer<Node> fromJson(const QJsonObject & val);

  QString typeCode() const override { return staticTypeCode; }

};
typedef QSharedPointer<Statement> StatementRef;

#endif // YASL_META_STATEMENT_H
