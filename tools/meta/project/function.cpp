// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project/function.h"

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

  if(!returnType.isEmpty() && returnType != "void")
    obj["returns"] = returnType;

  QJsonArray params;
  for (const auto & p : parameters)
    params.append(p);

  if(!params.isEmpty())
    obj["parameters"] = params;

  if(isExplicit)
    obj["explicit"] = isExplicit;
  if(isStatic)
    obj["static"] = isStatic;
  if(isConst)
    obj["const"] = isConst;
  if(isDeleted)
    obj["deleted"] = isDeleted;
  json::writeBindingMethod(obj, bindingMethod);
}

QSharedPointer<Node> Function::fromJson(const QJsonObject & obj)
{
  auto ret = FunctionRef::create(obj.value("name").toString(), json::readCheckState(obj));

  ret->rename = obj.value("rename").toString();

  ret->returnType = obj.value("returns").toString();
  if (ret->returnType.isEmpty())
    ret->returnType = "void";

  if (obj.contains("parameters"))
  {
    QJsonArray parameters = obj.value("parameters").toArray();
    ret->parameters.reserve(parameters.size());
    for (const auto & item : parameters)
      ret->parameters.push_back(item.toString());
  }

  ret->isExplicit = obj.contains("explicit") ? obj.value("explicit").toBool() : false;
  ret->isStatic = obj.contains("static") ? obj.value("static").toBool() : false;
  ret->isConst = obj.contains("const") ? obj.value("const").toBool() : false;
  ret->isDeleted = obj.contains("deleted") ? obj.value("deleted").toBool() : false;
  ret->bindingMethod = json::readBindingMethod(obj);

  return ret;
}

QString Function::displayedName() const
{
  QString result;
  if (isExplicit)
    result += "explicit ";
  if (isStatic)
    result += "static ";

  result += returnType;
  result += " " + name;
  result += "(";
  for (const auto & p : parameters)
    result += p + ", ";
  if (result.endsWith(", "))
    result.chop(2);
  result += ")";

  if (isConst)
    result += " const";

  if (isDeleted)
    result += " = delete";

  result += ";";
  return result;
}

Constructor::Constructor(const QString & n, Qt::CheckState cs)
  : Function(n, cs)
{

}

void Constructor::fillJson(QJsonObject & obj) const
{
  Function::fillJson(obj);
}

QSharedPointer<Node> Constructor::fromJson(const QJsonObject & obj)
{
  auto ret = ConstructorRef::create(obj.value("name").toString(), json::readCheckState(obj));

  ret->returnType = obj.value("returns").toString();

  QJsonArray parameters = obj.value("parameters").toArray();
  ret->parameters.reserve(parameters.size());
  for (const auto & item : parameters)
    ret->parameters.push_back(item.toString());

  ret->isExplicit = obj.value("explicit").toBool();
  ret->isStatic = obj.value("static").toBool();
  ret->isConst = obj.value("const").toBool();
  ret->isDeleted = obj.value("deleted").toBool();
  ret->bindingMethod = json::readBindingMethod(obj);

  return ret;
}

QString Constructor::displayedName() const
{
  QString result;
  if (isExplicit)
    result += "explicit ";
  if (isStatic)
    result += "static ";

  result += name;
  result += "(";
  for (const auto & p : parameters)
    result += p + ", ";
  if (result.endsWith(", "))
    result.chop(2);
  result += ")";

  if (isDeleted)
    result += " = delete";

  result += ";";
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
}

QSharedPointer<Node> Destructor::fromJson(const QJsonObject & obj)
{
  auto ret = DestructorRef::create(obj.value("name").toString(), json::readCheckState(obj));

  ret->isDeleted = obj.value("deleted").toBool();

  return ret;
}

QString Destructor::displayedName() const
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