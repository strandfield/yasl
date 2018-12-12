// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project.h"

#include "project/class.h"
#include "project/enum.h"
#include "project/file.h"
#include "project/namespace.h"

#include "yaml/parser.h"
#include "yaml/value.h"

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
  if(filename.endsWith(".json"))
  {
    QFile file{ filename };
    if (!file.exists() || !file.open(QIODevice::ReadOnly))
      return nullptr;

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();

    return fromJson(doc.object());
  }
  else if(filename.endsWith(".yaml"))
  {
    QFile file{ filename };
    if (!file.exists() || !file.open(QIODevice::ReadOnly))
      return nullptr;

    QTextStream textstream{ &file };

    yaml::Parser yamlparser;
    yaml::Object pro = yamlparser.parse(textstream).toObject();
    return fromYaml(pro);
  }

  return nullptr;
}

QString Project::toYaml() const
{
  QStringList lines;
  lines << "types:";
  lines << "  fundamentals:";
  for (const auto t : types.fundamentals)
    lines << ("    - " + t.toYaml());
  lines << "  enums:";
  for (const auto t : types.enums)
    lines << ("    - " + t.toYaml());
  lines << "  classes:";
  for (const auto t : types.classes)
    lines << ("    - " + t.toYaml());

  QString ret = lines.join("\n");
  ret += "\n";

  {
    yaml::Array includesArray;
    for (auto it = this->includes.begin(); it != this->includes.end(); ++it)
      includesArray.push(it.key() + yaml::createField("v", it.value().toString()));

    yaml::Object obj;
    obj["includes"] = includesArray;
    QString str = obj.serialize();
    ret += str;
  }

  ret += "\n";

  {
    yaml::Array modulesyaml;
    for (const auto & m : modules)
      modulesyaml.push(m->toYaml());

    yaml::Object obj;
    obj["modules"] = modulesyaml;
    QString modulesyamlstr = obj.serialize();
    ret += modulesyamlstr;
  }

  return ret;
}

QList<Type> Project::typelistFromYaml(yaml::Array list)
{
  QList<Type> ret;
  for (auto e : list)
    ret.append(Type::fromYaml(e.toObject()));
  return ret;
}

QSharedPointer<Project> Project::fromYaml(const yaml::Object & obj)
{
  auto ret = ProjectRef::create();

  yaml::Array modules = obj.value("modules").toArray();
  ret->modules.reserve(modules.size());
  for (const auto & m : modules)
    ret->modules.append(qSharedPointerCast<Module>(Module::fromYaml(m.toObject())));

  yaml::Array types = obj.value("types").toObject().value("fundamentals").toArray();
  ret->types.fundamentals = typelistFromYaml(types);

  types = obj.value("types").toObject().value("enums").toArray();
  ret->types.enums = typelistFromYaml(types);

  types = obj.value("types").toObject().value("classes").toArray();
  ret->types.classes = typelistFromYaml(types);
  
  {
    yaml::Array includes = obj.value("includes").toArray();
    for (auto elem : includes)
    {
      QString item = elem.toString();
      ret->includes[yaml::extractName(item)] = QtVersion::fromString(yaml::extractField(item, "v"));
    }
  }
  
  return ret;
}

void Project::save(const QString & filename)
{
  sort(types.classes);
  sort(types.enums);

  QString fn = filename;
  if (fn.endsWith(".json"))
    fn.chop(5);
  else if (fn.endsWith(".yaml"))
    fn.chop(5);

  QFile file{ fn + ".json" };
  //if (!file.open(QIODevice::WriteOnly))
  //  return;

  //file.write(QJsonDocument{ toJson() }.toJson());
  //file.close();

  // Yaml save
  file.setFileName(fn + ".yaml");
  if (!file.open(QIODevice::WriteOnly))
    return;

  file.write(toYaml().toUtf8());
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
    else if (node->is<Class>())
    {
      ClassRef target_class = qSharedPointerCast<Class>(node);
      ClassRef src_class = qSharedPointerCast<Class>(srcItem);

      merge_recursively(target_class->elements, src_class->elements);
    }
    else if (node->is<Enum>())
    {
      EnumRef target_enum = qSharedPointerCast<Enum>(node);
      EnumRef src_enum = qSharedPointerCast<Enum>(srcItem);

      target_enum->merge(*src_enum);
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

int Project::fileCount() const
{
  int n = 0;

  for (const auto & m : modules)
  {
    for (const auto & e : m->elements)
    {
      if (e->is<File>())
        n++;
    }
  }

  return n;
}
