// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project.h"

#include "project/class.h"
#include "project/enum.h"
#include "project/namespace.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QStack>

#include <QDebug>

QJsonObject Project::toJson() const
{
  QJsonObject ret;

  QJsonArray modulesjson;
  for (const auto & f : modules)
    modulesjson.append(f->toJson());

  ret["modules"] = modulesjson;

  QJsonObject typesjson;

  {
    QJsonArray fundamentals;
    for (const auto & t : types.fundamentals)
      fundamentals.append(t.toJson());
    typesjson["fundamentals"] = fundamentals;
  }

  {
    QJsonArray enums;
    for (const auto & t : types.enums)
      enums.append(t.toJson());
    typesjson["enums"] = enums;
  }

  {
    QJsonArray classes;
    for (const auto & t : types.classes)
      classes.append(t.toJson());
    typesjson["classes"] = classes;
  }

  ret["types"] = typesjson;

  return ret;
}

QSharedPointer<Project> Project::fromJson(const QJsonObject & obj)
{
  auto ret = ProjectRef::create();
  
  QJsonArray modules = obj.value("modules").toArray();
  ret->modules.reserve(modules.size());
  for (const auto & f : modules)
    ret->modules.append(qSharedPointerCast<Module>(Module::fromJson(f.toObject())));

  QJsonArray types = obj.value("types").toObject().value("fundamentals").toArray();
  for (const auto & t : types)
    ret->types.fundamentals.append(Type::fromJson(t.toObject()));

  types = obj.value("types").toObject().value("enums").toArray();
  for (const auto & t : types)
    ret->types.enums.append(Type::fromJson(t.toObject()));

  types = obj.value("types").toObject().value("classes").toArray();
  for (const auto & t : types)
    ret->types.classes.append(Type::fromJson(t.toObject()));

  return ret;
}

QSharedPointer<Project> Project::load(const QString & filename)
{
  QFile file{ filename };
  if (!file.exists() || !file.open(QIODevice::ReadOnly))
    return nullptr;

  QJsonParseError error;
  QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
  file.close();

  return fromJson(doc.object());
}

void Project::save(const QString & filename)
{
  sort(types.classes);
  sort(types.enums);

  QFile file{ filename };
  if (!file.open(QIODevice::WriteOnly))
    return;

  file.write(QJsonDocument{ toJson() }.toJson());
  file.close();
}

template<typename T>
T find_or_set(QList<T> & list, const NodeRef & elem)
{
  for (const auto & item : list)
  {
    if (eq(item, elem))
      return item;
  }

  list.append(elem);
  return elem;
}


static void merge_recursively(QList<NodeRef> & target, const QList<NodeRef> & src)
{
  for (const auto & srcItem : src)
  {
    if (srcItem->checkState == Qt::Unchecked)
      continue;

    NodeRef node = find_or_set(target, srcItem);
    if (node == srcItem)
      continue;

    if (node->is<Module>())
    {
      ModuleRef targetModule = qSharedPointerCast<Module>(node);
      ModuleRef srcModule = qSharedPointerCast<Module>(srcItem);

      merge_recursively(targetModule->elements, srcModule->elements);
    }
    else if (node->is<Namespace>())
    {
      NamespaceRef targetNamespace = qSharedPointerCast<Namespace>(node);
      NamespaceRef srcNamespace = qSharedPointerCast<Namespace>(srcItem);

      merge_recursively(targetNamespace->elements, srcNamespace->elements);
    }
    else
    {
      qDebug() << "Element already exists in project";
    }
  }
}

ModuleRef find_or_set(QList<ModuleRef> & list, const ModuleRef & elem)
{
  for (const auto & item : list)
  {
    if (item->name == elem->name)
      return item;
  }

  list.append(elem);
  return elem;
}

void merge_recursively(QList<ModuleRef> & target, const QList<ModuleRef> & src)
{
  for (const auto & srcItem : src)
  {
    if (srcItem->checkState == Qt::Unchecked)
      continue;

    ModuleRef m = find_or_set(target, srcItem);
    if (m == srcItem)
      continue;

    merge_recursively(m->elements, srcItem->elements);
  }
}

void Project::importSymbols(const QSharedPointer<Project> symbols)
{
  for (const auto & t : symbols->types.classes)
  {
    if (!hasClassType(t.name))
      types.classes.append(t);
  }

  for (const auto & t : symbols->types.enums)
  {
    if (!hasEnumType(t.name))
      types.enums.append(t);
  }

  merge_recursively(this->modules, symbols->modules);
}


template<typename T>
void remove_unchekced_recursively(QList<T> & nodes)
{
  for (int i(0); i < nodes.size(); ++i)
  {
    if (nodes.at(i)->checkState == Qt::Unchecked)
    {
      nodes.removeAt(i);
      --i;
    }
    else
    {
      remove_unchekced_recursively(nodes.at(i));
    }
  }
}

static void remove_unchekced_recursively(const NodeRef & node)
{
  if (node->is<Namespace>())
  {
    Namespace & ns = node->as<Namespace>();
    remove_unchekced_recursively(ns.elements);
  }
  else if (node->is<Module>())
  {
    Module &m = node->as<Module>();
    remove_unchekced_recursively(m.elements);
  }
  else if (node->is<Class>())
  {
    Class &cla = node->as<Class>();
    remove_unchekced_recursively(cla.elements);
  }
  else if (node->is<Enum>())
  {
    Enum &enm = node->as<Enum>();
    remove_unchekced_recursively(enm.enumerators);
  }
}

void Project::removeUncheckedSymbols()
{
  remove_unchekced_recursively(this->modules);
}

template<typename T>
void fetch_types_recursively(Project & pro, QStack<NodeRef> & stack, const QList<T> & nodes)
{
  for (const auto & n : nodes)
    fetch_types_recursively(pro, stack, n);
}

static void fetch_types_recursively(Project & pro, QStack<NodeRef> & stack, const NodeRef & node)
{
  stack.push(node);

  if (node->is<Namespace>())
  {
    Namespace & ns = node->as<Namespace>();
    fetch_types_recursively(pro, stack, ns.elements);
  }
  else if (node->is<Module>())
  {
    Module &m = node->as<Module>();
    fetch_types_recursively(pro, stack, m.elements);
  }
  else if (node->is<Class>())
  {
    if (pro.hasClassType(node->name))
      return;

    stack.pop();
    const QString name = Node::nameQualification(stack) + node->name;
    pro.types.classes.append(Type{ name, QString{ name }.remove("::") });
    stack.push(node);

    fetch_types_recursively(pro, stack, node->as<Class>().elements);
  }
  else if (node->is<Enum>())
  {
    if (pro.hasEnumType(node->name))
      return;

    stack.pop();
    const QString name = Node::nameQualification(stack) + node->name;
    pro.types.enums.append(Type{ name, QString{ name }.remove("::") });
    stack.push(node);
  }

  stack.pop();
}

void Project::fetchTypes()
{
  QStack<NodeRef> stack;
  fetch_types_recursively(*this, stack, this->modules);
}

bool Project::hasEnumType(const QString & name) const
{
  for (const auto & t : types.enums)
  {
    if (t.name == name)
      return true;
  }

  return false;
}

bool Project::hasClassType(const QString & name) const
{
  for (const auto & t : types.classes)
  {
    if (t.name == name)
      return true;
  }

  return false;
}

Type & Project::getType(const QString & name)
{
  for (auto & t : types.fundamentals)
  {
    if (t.name == name)
      return t;
  }

  for (auto & t : types.classes)
  {
    if (t.name == name)
      return t;
  }

  for (auto & t : types.enums)
  {
    if (t.name == name)
      return t;
  }

  throw std::runtime_error{ "Project::getType() : Unsupported type" };
}

void Project::sort(QList<Type> & types)
{
  struct LessThan
  {
    bool operator()(const Type & a, const Type & b)
    {
      return QString::compare(a.name, b.name, Qt::CaseInsensitive) < 0;
    }
  };

  qSort(types.begin(), types.end(), LessThan{});
}
