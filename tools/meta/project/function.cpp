// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/function.h"

#include "yaml/value.h"

#include <QJsonArray>

const QString Function::staticTypeCode = "function";
const QString Constructor::staticTypeCode = "constructor";
const QString Destructor::staticTypeCode = "destructor";


Function::Function(const QString & n, Qt::CheckState c)
  : Node(n, c)
  , isExplicit(false)
  , isStatic(false)
  , isConst(false)
  , isDeleted(false)
  , bindingMethod(Function::AutoBinding)
{

}

void Function::fillJson(QJsonObject & obj) const
{
  Node::fillJson(obj);

  if (!rename.isEmpty())
    obj["rename"] = rename;

  obj["signature"] = parameters.join(";") + "->" + returnType;

  if(isExplicit)
    obj["explicit"] = isExplicit;
  if(isStatic)
    obj["static"] = isStatic;
  if(isConst)
    obj["const"] = isConst;
  if(isDeleted)
    obj["deleted"] = isDeleted;
  json::writeBindingMethod(obj, bindingMethod);

  if (!defaultArguments.isEmpty())
    obj["defaults"] = defaultArguments.join(';');
}

QSharedPointer<Node> Function::fromJson(const QJsonObject & obj)
{
  auto ret = FunctionRef::create(obj.value("name").toString(), json::readCheckState(obj));
  ret->version = json::readQtVersion(obj);

  ret->rename = obj.value("rename").toString();

  QStringList signature = obj.value("signature").toString().split("->");
  ret->parameters = signature.front().split(';', QString::SkipEmptyParts);
  ret->returnType = signature.size() == 2 ? signature.back() : QString();
  if (ret->returnType.isEmpty())
    ret->returnType = "void";

  ret->isExplicit = obj.contains("explicit") ? obj.value("explicit").toBool() : false;
  ret->isStatic = obj.contains("static") ? obj.value("static").toBool() : false;
  ret->isConst = obj.contains("const") ? obj.value("const").toBool() : false;
  ret->isDeleted = obj.contains("deleted") ? obj.value("deleted").toBool() : false;
  ret->bindingMethod = json::readBindingMethod(obj);
  ret->defaultArguments = obj.contains("defaults") ? obj.value("defaults").toString().split(';', QString::SkipEmptyParts) : QStringList();

  return ret;
}

QString Function::yamlDescription() const
{
  QStringList elems;

  elems << name;

  if (!returnType.isEmpty())
    elems << yaml::createField("r", returnType);

  if (!parameters.isEmpty())
  {
    QStringList p = parameters;
    for (int i(0); i < defaultArguments.size(); ++i)
      p[p.size() - 1 - i].append("=" + defaultArguments.at(i));
    elems << yaml::createField("p", p.join(';'));
  }

  {
    QStringList specs = getSpecifiers();
    if (!specs.isEmpty())
      elems << yaml::createField("specs", specs.join(';'));
  }

  if (bindingMethod != AutoBinding)
    elems << yaml::createField("binding", serialize(bindingMethod));

  if (!rename.isEmpty())
    elems << yaml::createField("rename", rename);

  if (!version.isNull())
    elems << yaml::createField("v", version.toString());

  if (checkState != Qt::Checked)
    elems << "[unchecked]";

  return elems.join(QString());
}

yaml::Value Function::toYaml() const
{
  yaml::Object ret;
  ret["function"] = yaml::Value{ yamlDescription() };
  return ret;
}

QSharedPointer<Node> Function::fromYaml(const yaml::Object & obj)
{
  QString value = obj.value("function").toString();

  auto ret = FunctionRef::create(value.mid(0, yaml::firstFieldIndex(value)), yaml::checkstate(value));
  ret->version = QtVersion::fromString(yaml::extractField(value, "v"));

  ret->rename = yaml::extractField(value, "rename");
  ret->returnType = yaml::extractField(value, "r");
  ret->parameters = yaml::extractField(value, "p").split(';', QString::SkipEmptyParts);
  for (int i(ret->parameters.size() - 1); i >= 0; --i)
  {
    const int eqindex = ret->parameters[i].indexOf('=');
    if (eqindex == -1)
      break;
    ret->defaultArguments.append(ret->parameters[i].mid(eqindex + 1));
    ret->parameters[i] = ret->parameters[i].mid(0, eqindex);
  }

  ret->setSpecifiers(yaml::extractField(value, "specs").split(';'));
  ret->bindingMethod = deserialize<Function::BindingMethod>(yaml::extractField(value, "binding"));

  return ret;
}

QString Function::display() const
{
  QString result;
  if (isExplicit)
    result += "explicit ";
  if (isStatic)
    result += "static ";

  result += returnType;
  result += " " + name;
  result += "(";
  {
    QStringList params = parameters;
    for (int i(0); i < defaultArguments.size(); ++i)
      params[params.size() - i - 1] += " = " + defaultArguments.at(i);
    result += params.join(", ");
  }
  result += ")";

  if (isConst)
    result += " const";

  if (isDeleted)
    result += " = delete";

  result += ";";

  if (!version.isNull())
    result += " [" + version.toString() + "]";

  if (!rename.isEmpty())
    result += " [" + rename + "]";

  if (bindingMethod != Function::AutoBinding)
    result += " [" + serialize(bindingMethod) + "]";

  return result;
}

QStringList Function::getSpecifiers() const
{
  QStringList specifiers;
  if (isConst)
    specifiers << "const";
  if (isDeleted)
    specifiers << "delete";
  if (isExplicit)
    specifiers << "explicit";
  if (isStatic)
    specifiers << "static";
  return specifiers;
}

void Function::setSpecifiers(const QStringList & specs)
{
  isConst = specs.contains("const");
  isDeleted = specs.contains("delete");
  isExplicit = specs.contains("explicit");
  isStatic = specs.contains("static");
}

Constructor::Constructor(const QString & n, Qt::CheckState cs)
  : Function(n, cs)
{

}

void Constructor::fillJson(QJsonObject & obj) const
{
  Function::fillJson(obj);
  obj["signature"] = obj.value("signature").toString().chopped(2);
}

QSharedPointer<Node> Constructor::fromJson(const QJsonObject & obj)
{
  auto ret = ConstructorRef::create(obj.value("name").toString(), json::readCheckState(obj));
  ret->version = json::readQtVersion(obj);

  ret->parameters = obj.value("signature").toString().split(';', QString::SkipEmptyParts);
  ret->returnType = QString();

  ret->isExplicit = obj.value("explicit").toBool();
  ret->isStatic = obj.value("static").toBool();
  ret->isConst = obj.value("const").toBool();
  ret->isDeleted = obj.value("deleted").toBool();
  ret->bindingMethod = json::readBindingMethod(obj);
  ret->defaultArguments = obj.contains("defaults") ? obj.value("defaults").toString().split(';', QString::SkipEmptyParts) : QStringList();

  return ret;
}

yaml::Value Constructor::toYaml() const
{
  yaml::Object ret;
  ret["constructor"] = yaml::Value{ yamlDescription() };
  return ret;
}

QSharedPointer<Node> Constructor::fromYaml(const yaml::Object & obj)
{
  QString value = obj.value("constructor").toString();

  auto ret = ConstructorRef::create(value.mid(0, value.indexOf('[')), yaml::checkstate(value));
  ret->version = QtVersion::fromString(yaml::extractField(value, "v"));

  ret->parameters = yaml::extractField(value, "p").split(';', QString::SkipEmptyParts);
  for (int i(ret->parameters.size() - 1); i >= 0; --i)
  {
    const int eqindex = ret->parameters[i].indexOf('=');
    if (eqindex == -1)
      break;
    ret->defaultArguments.append(ret->parameters[i].mid(eqindex + 1));
    ret->parameters[i] = ret->parameters[i].mid(0, eqindex);
  }

  ret->setSpecifiers(yaml::extractField(value, "specs").split(';'));

  return ret;
}

QString Constructor::display() const
{
  QString result;
  if (isExplicit)
    result += "explicit ";
  result += name;
  result += "(";
  {
    QStringList params = parameters;
    for (int i(0); i < defaultArguments.size(); ++i)
      params[params.size() - i - 1] += " = " + defaultArguments.at(i);
    result += params.join(", ");
  }
  result += ")";

  if (isDeleted)
    result += " = delete";

  result += ";";

  if (!version.isNull())
    result += " [" + version.toString() + "]";

  return result;
}


Destructor::Destructor(const QString & n, Qt::CheckState cs)
  : Function(n, cs)
{

}

void Destructor::fillJson(QJsonObject & obj) const
{
  Function::fillJson(obj);

  obj.remove("returns");
  obj.remove("parameters");
  obj.remove("explicit");
  obj.remove("static");
  obj.remove("const");
  obj.remove("macros");
  obj.remove("signature");
}

QSharedPointer<Node> Destructor::fromJson(const QJsonObject & obj)
{
  auto ret = DestructorRef::create(obj.value("name").toString(), json::readCheckState(obj));
  ret->version = json::readQtVersion(obj);

  ret->isDeleted = obj.value("deleted").toBool();

  return ret;
}

yaml::Value Destructor::toYaml() const
{
  yaml::Object ret;
  ret["destructor"] = yaml::Value{ yamlDescription() };
  return ret;
}

QSharedPointer<Node> Destructor::fromYaml(const yaml::Object & obj)
{
  QString value = obj.value("destructor").toString();

  auto ret = DestructorRef::create(value.mid(0, value.indexOf('[')), yaml::checkstate(value));
  ret->version = QtVersion::fromString(yaml::extractField(value, "v"));

  ret->setSpecifiers(yaml::extractField(value, "specs").split(';'));

  return ret;
}

QString Destructor::display() const
{
  QString result;

  result += name;
  result += "()";

  if (isDeleted)
    result += " = delete";

  result += ";";
  return result;
}

namespace json
{

Function::BindingMethod readBindingMethod(const QJsonObject & obj)
{
  if (!obj.contains("binding"))
    return Function::AutoBinding;
  return Function::deserialize<Function::BindingMethod>(obj.value("binding").toString());
}

void writeBindingMethod(QJsonObject &obj, Function::BindingMethod bm)
{
  if (bm == Function::AutoBinding)
    return;

  obj["binding"] = Function::serialize(bm);
}

} // namespace json