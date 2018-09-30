// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/statement.h"

#include <QJsonArray>

const QString Statement::staticTypeCode = "statement";

Statement::Statement(const QString & val, Qt::CheckState c)
  : Node(val, c)
{

}

void Statement::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);
  obj.remove("name");
  obj["value"] = this->name;
}

QSharedPointer<Node> Statement::fromJson(const QJsonObject & val)
{
  return StatementRef::create(val.value("value").toString(), json::readCheckState(val));
}