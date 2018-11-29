// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/enum.h"

#include "yaml/value.h"

#include <QDebug>
#include <QJsonArray>

const QString Enum::staticTypeCode = "enum";
const QString Enumerator::staticTypeCode = "enumerator";

Enumerator::Enumerator(const QString & n, Qt::CheckState c)
  : Node(n, c)
{

}

void Enumerator::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  obj.remove("type");

  if (!rename.isEmpty())
    obj["rename"] = rename;
}

QSharedPointer<Node> Enumerator::fromJson(const QJsonObject & obj)
{
  auto ret = EnumeratorRef::create(obj.value("name").toString(), json::readCheckState(obj));
  if (obj.contains("rename"))
    ret->rename = obj.value("rename").toString();
  return ret;
}

yaml::Value Enumerator::toYaml() const
{
  QStringList elems;

  elems << name;

  if (!rename.isEmpty())
    elems << yaml::createField("rename", rename);

  if (checkState != Qt::Checked)
    elems << "[unchecked]";

  if (!version.isNull())
    elems << yaml::createField("v", version.toString());

  return elems.join(QString());
}

QSharedPointer<Enumerator> Enumerator::fromYaml(const QString & str)
{
  QString name = str.mid(0, str.indexOf('['));
  auto ret = EnumeratorRef::create(name, yaml::checkstate(str));
  ret->rename = yaml::extractField(str, "rename");
  ret->version = QtVersion::fromString(yaml::extractField(str, "v"));
  return ret;
}


Enum::Enum(const QString & n, Qt::CheckState c)
  : Node(n, c)
  , isEnumClass(false)
  , isCppEnumClass(false)
{

}

QString Enum::display() const
{
  QString ret = name;
  if (isCppEnumClass)
    ret += " [from-enum-class]";
  if (isEnumClass)
    ret += " [to-enum-class]";
  return ret;
}

void Enum::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  QJsonArray enms;
  for (const auto & e : enumerators)
  {
    QString entry = e->name + "@" + e->rename;
    if (entry.endsWith('@'))
      entry.chop(1);
    if (e->checkState == Qt::Unchecked)
      entry.append('-');
    enms.append(entry);
  }
  obj["enumerators"] = enms;

  if (isEnumClass)
    obj["enumclass"] = isEnumClass;

  if (isCppEnumClass)
    obj["cppenumclass"] = isCppEnumClass;
}

QSharedPointer<Node> Enum::fromJson(const QJsonObject & obj)
{
  auto ret = EnumRef::create(obj.value("name").toString(), json::readCheckState(obj));

  QJsonArray enumerators = obj.value("enumerators").toArray();
  for (const auto & item : enumerators)
  {
    QString str = item.toString();
    Qt::CheckState check = Qt::Checked;
    if (str.endsWith('-'))
      str.chop(1), check = Qt::Unchecked;
    QStringList fields = str.split('@', QString::SkipEmptyParts);
    auto enumerator = QSharedPointer<Enumerator>::create(fields.front(), check);
    if (fields.size() == 2)
      enumerator->rename = fields.back();
    ret->enumerators.append(enumerator);
  }

  if (!obj.contains("enumclass"))
    ret->isEnumClass = false;
  else
    ret->isEnumClass = obj.value("enumclass").toBool();

  if (!obj.contains("cppenumclass"))
    ret->isCppEnumClass = false;
  else
    ret->isCppEnumClass = obj.value("cppenumclass").toBool();

  return ret;
}

yaml::Value Enum::toYaml() const
{
  yaml::Object content;

  content["name"] = name;

  yaml::writeCheckstate(content, checkState);
  yaml::writeQtVersion(content, version);
  
  if (isEnumClass)
    content["toEnumClass"] = "true";

  if(isCppEnumClass)
    content["fromEnumClass"] = "true";

  {
    yaml::Array elist;

    for (const auto & e : enumerators)
      elist.push(e->toYaml());

    content["enumerators"] = elist;
  }

  yaml::Object ret;
  ret["enum"] = content;
  return ret;
}

QSharedPointer<Node> Enum::fromYaml(const yaml::Object & inputobj)
{
  yaml::Object obj = inputobj.value("enum").toObject();

  auto ret = EnumRef::create(obj.value("name").toString(), yaml::readCheckState(obj));
  ret->version = yaml::readQtVersion(obj);

  yaml::Array enumerators = obj.value("enumerators").toArray();
  for (const auto & item : enumerators)
  {
    ret->enumerators.append(Enumerator::fromYaml(item.toString()));
  }

  ret->isEnumClass = obj.value("toEnumClass").toString() == "true";
  ret->isCppEnumClass = obj.value("fromEnumClass").toString() == "true";

  return ret;
}
