// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/statement.h"

#include "yaml/value.h"

#include <QJsonArray>

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

yaml::Value Statement::toYaml() const
{
  QStringList elems;

  elems << name;
  elems << yaml::checkStateField(checkState);

  yaml::Object ret;
  ret["statement"] = elems.join(QString());
  return ret;
}

QSharedPointer<Node> Statement::fromYaml(const yaml::Object & inputobj)
{
  QString value = inputobj.value("statement").toString();

  auto ret = StatementRef::create(value.mid(0, value.indexOf('[')), yaml::checkstate(value));
  return ret;
}
