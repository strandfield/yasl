// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/application.h"

#include <script/cast.h>
#include <script/class.h>
#include <script/enum.h>
#include <script/function.h>
#include <script/literals.h>
#include <script/module.h>
#include <script/name.h>
#include <script/namespace.h>
#include <script/operator.h>

#include <QDebug>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <iostream>

QString repr(const script::Type & t, const script::Engine *e);
QString get_type_name(const script::Type & t, const script::Engine *e);

QString repr(const script::TemplateArgument & targ, script::Engine *e)
{
  using namespace script;

  if (targ.kind == TemplateArgument::BoolArgument)
    return targ.boolean ? "true" : "false";
  else if (targ.kind == TemplateArgument::IntegerArgument)
    return QString::number(targ.integer);

  return get_type_name(targ.type, e);
}

QString get_class_name(const script::Class & cla)
{
  if (!cla.isTemplateInstance())
    return QString::fromUtf8(cla.name().data());

  QString base = cla.instanceOf().name().data();
  QStringList args;
  for (const auto & targ : cla.arguments())
    args << repr(targ, cla.engine());
  return base + "<" + args.join(", ") + ">";
}


QString get_type_name(const script::Type & t, const script::Engine *e)
{
  if (t.isObjectType())
    return get_class_name(e->getClass(t));
  return e->typeName(t).data();
}


QString repr(const script::Type & t, const script::Engine *e)
{
  QString base = get_type_name(t, e);
  QString const_qualifier = t.isConst() ? "const " : "";
  QString ref = t.isReference() ? " &" : (t.isRefRef() ? " &&" : "");

  return const_qualifier + base + ref;
}

QString repr(const script::Name & n, const script::Engine *e)
{
  using namespace script;

  if (n.kind() == Name::StringName)
    return QString::fromUtf8(n.string().data());
  else if (n.kind() == Name::OperatorName)
    return QString::fromUtf8(Operator::getFullName(n.operatorName()).data());
  else if (n.kind() == Name::CastName)
    return QString("operator ") + repr(n.asType(), e);
  else if (n.kind() == Name::LiteralOperatorName)
    return "operator\"\"" + QString::fromUtf8(n.string().data());

  throw std::runtime_error{ "Not implemented" };
}


QString repr(const script::Function & f, script::Engine *e = nullptr)
{
  if (e == nullptr)
    e = f.engine();

  const QString explicit_specifier = f.isExplicit() ? "explicit " : "";
  const QString static_specifier = f.isStatic() ? "static " : "";
  const QString virtual_specifier = f.isVirtual() ? "virtual " : "";
  const QString return_type = f.isSpecial() || f.isCast() ? "" : repr(f.returnType(), e) + " ";
  const QString const_qualifier = f.isConst() ? " const" : "";
  const QString delete_specifier = f.isDeleted() ? " = delete" : "";
  
  QStringList params;
  for (const auto & p : f.prototype())
  {
    params << repr(p, e);
  }

  if (f.hasImplicitObject())
    params.pop_front();

  QString name = repr(f.getName(), e);

  return explicit_specifier + static_specifier + virtual_specifier
    + return_type + name + "(" + params.join(", ") + ")" + const_qualifier + delete_specifier + ";";
}


QJsonObject json_export(const script::Enum & enm)
{
  QJsonObject result;
  result["type"] = "enum";
  result["name"] = QString::fromUtf8(enm.name().data());

  {
    QJsonArray values;
    for (const auto & n : enm.values())
      values.push_back(QString::fromUtf8(n.first.data()));

    result["values"] = values;
  }

  return result;
}

QJsonObject json_export(const script::Class & cla)
{
  QJsonObject result;
  result["type"] = "class";
  result["name"] = get_class_name(cla);

  result["default_constructible"] = !cla.defaultConstructor().isNull();
  result["copy_constructible"] = !cla.copyConstructor().isNull();
  result["destructible"] = !cla.destructor().isNull();


  {
    QJsonArray enums;
    for (const auto & n : cla.enums())
      enums.push_back(json_export(n));

    result["enums"] = enums;
  }

  {
    QJsonArray constructors;
    for (const auto & f : cla.constructors())
      constructors.push_back(repr(f));

    result["constructors"] = constructors;
  }

  {
    QJsonArray functions;
    for (const auto & f : cla.memberFunctions())
      functions.push_back(repr(f));

    result["functions"] = functions;
  }

  {
    QJsonArray operators;
    for (const auto & f : cla.operators())
      operators.push_back(repr(f));

    result["operators"] = operators;
  }

  {
    QJsonArray conversions;
    for (const auto & f : cla.casts())
      conversions.push_back(repr(f));

    result["conversions"] = conversions;
  }

  return result;
}

QJsonObject json_export(const script::Namespace & ns)
{
  QJsonObject result;
  result["type"] = "namespace";
  result["name"] = QString::fromUtf8(ns.name().data());


  {
    QJsonArray enums;
    for (const auto & n : ns.enums())
      enums.push_back(json_export(n));

    result["enums"] = enums;
  }

  {
    /*QJsonArray classes;
    for (const auto & n : ns.classes())
      classes.push_back(json_export(n));*/
    QJsonObject classes;
    for (const auto & n : ns.classes())
    {
      auto cla = json_export(n);
      classes[cla["name"].toString()] = cla;
    }

    result["classes"] = classes;
  }

  {
    QJsonArray functions;
    for (const auto & f : ns.functions())
      functions.push_back(repr(f));

    result["functions"] = functions;
  }

  {
    QJsonArray operators;
    for (const auto & f : ns.operators())
      operators.push_back(repr(f));

    result["operators"] = operators;
  }

  {
    QJsonArray literals;
    for (const auto & f : ns.literalOperators())
      literals.push_back(repr(f));

    result["literals"] = literals;
  }

  return result;
}

QJsonObject json_export(const script::Module & mod)
{
  QJsonObject result;
  result["type"] = "module";
  result["name"] = QString::fromUtf8(mod.name().data());

  script::Namespace ns = mod.root();

  {
    QJsonArray enums;
    for (const auto & n : ns.enums())
      enums.push_back(json_export(n));

    result["enums"] = enums;
  }

  {
    /*QJsonArray classes;
    for (const auto & n : ns.classes())
    classes.push_back(json_export(n));*/
    QJsonObject classes;
    for (const auto & n : ns.classes())
    {
      auto cla = json_export(n);
      classes[cla["name"].toString()] = cla;
    }

    result["classes"] = classes;
  }

  {
    QJsonArray functions;
    for (const auto & f : ns.functions())
      functions.push_back(repr(f));

    result["functions"] = functions;
  }

  {
    QJsonArray operators;
    for (const auto & f : ns.operators())
      operators.push_back(repr(f));

    result["operators"] = operators;
  }

  {
    QJsonArray literals;
    for (const auto & f : ns.literalOperators())
      literals.push_back(repr(f));

    result["literals"] = literals;
  }

  return result;
}

void dump_tree(script::Engine *engine)
{
  QJsonObject result;
  result["root"] = json_export(engine->rootNamespace());

  {
    //QJsonArray modules;
    //for (const auto & n : engine->modules())
    //  modules.push_back(json_export(n));
    QJsonObject modules;
    for (const auto & n : engine->modules())
    {
      auto mod = json_export(n);
      modules[mod["name"].toString()] = mod;
    }

    result["modules"] = modules;
  }

  QJsonDocument doc{ result };
  QTextStream(stdout) << doc.toJson();

}


struct Agglomerate
{
  int nb_enumerators = 0;
  int nb_enums = 0;
  int nb_operators = 0;
  int nb_conversions = 0;
  int nb_constructors = 0;
  int nb_literals = 0;
  int nb_classes = 0;
  int nb_functions = 0;

  void read(const QJsonObject & obj);
  void write(QJsonObject & out);
};

void Agglomerate::read(const QJsonObject & obj)
{
  if (obj.keys().contains("nb_enumerators"))
    nb_enumerators += obj["nb_enumerators"].toInt();

  if (obj.keys().contains("nb_enums"))
    nb_enums += obj["nb_enums"].toInt();

  if (obj.keys().contains("nb_operators"))
    nb_operators += obj["nb_operators"].toInt();

  if (obj.keys().contains("nb_conversions"))
    nb_conversions += obj["nb_conversions"].toInt();

  if (obj.keys().contains("nb_constructors"))
    nb_constructors += obj["nb_constructors"].toInt();

  if (obj.keys().contains("nb_literals"))
    nb_literals += obj["nb_literals"].toInt();

  if (obj.keys().contains("nb_classes"))
    nb_classes += obj["nb_classes"].toInt();

  if (obj.keys().contains("nb_functions"))
    nb_functions += obj["nb_functions"].toInt();
}

void Agglomerate::write(QJsonObject & out)
{
  QJsonObject agglomerate;
  agglomerate["nb_enumerators"] = nb_enumerators;
  agglomerate["nb_enums"] = nb_enums;
  agglomerate["nb_operators"] = nb_operators;
  agglomerate["nb_conversions"] = nb_conversions;
  agglomerate["nb_constructors"] = nb_constructors;
  agglomerate["nb_literals"] = nb_literals;
  agglomerate["nb_classes"] = nb_classes;
  agglomerate["nb_functions"] = nb_functions;

  out["agglomerate"] = agglomerate;
}

void write_agglomerate_stats(QJsonObject & obj)
{
  Agglomerate agglomerate;

  if (obj.keys().contains("classes"))
  {
    for (const auto & cla : obj["classes"].toObject())
    {
      if (cla.toObject().keys().contains("agglomerate"))
        agglomerate.read(cla.toObject().value("agglomerate").toObject());
    }
  }

  if (obj.keys().contains("enums"))
  {
    for (const auto & enm : obj["enums"].toArray())
      agglomerate.read(enm.toObject());
  }

  agglomerate.read(obj);
  
  agglomerate.write(obj);
}


QJsonObject stats_export(const script::Enum & enm)
{
  QJsonObject result;
  result["type"] = "enum";
  result["name"] = QString::fromUtf8(enm.name().data());

  result["nb_enumerators"] = (int) enm.values().size();

  return result;
}

void write_enum_stats(QJsonObject & out, const std::vector<script::Enum> & list)
{
  QJsonArray enums;
  for (const auto & n : list)
    enums.push_back(stats_export(n));

  out["enums"] = enums;
  out["nb_enums"] = (int)enums.size();
}

QJsonObject stats_export(const script::Class & cla)
{
  QJsonObject result;
  result["type"] = "class";
  result["name"] = get_class_name(cla);

  result["default_constructible"] = !cla.defaultConstructor().isNull();
  result["copy_constructible"] = !cla.copyConstructor().isNull();
  result["destructible"] = !cla.destructor().isNull();

  write_enum_stats(result, cla.enums());

  result["nb_constructors"] = (int) cla.constructors().size();

  {
    int nb_static_functions = 0;
    int nb_const_functions = 0;
    for (const auto & f : cla.memberFunctions())
    {
      nb_static_functions += f.isStatic() ? 1 : 0;
      nb_const_functions += f.isConst() ? 1 : 0;
    }

    result["nb_functions"] = (int) cla.memberFunctions().size();
    result["nb_static_functions"] = nb_static_functions;
    result["nb_const_functions"] = nb_const_functions;
  }

  {
    result["nb_operators"] = (int) cla.operators().size();
  }

  {
    result["nb_conversions"] = (int) cla.casts().size();
  }


  write_agglomerate_stats(result);

  return result;
}

QJsonObject stats_export(const script::Namespace & ns)
{
  QJsonObject result;
  result["type"] = "namespace";
  result["name"] = QString::fromUtf8(ns.name().data());

  write_enum_stats(result, ns.enums());

  {
    //QJsonArray classes;
    //for (const auto & n : ns.classes())
    //{
    //  classes.push_back(stats_export(n));
    //}
    QJsonObject classes;
    for (const auto & n : ns.classes())
    {
      auto cla = stats_export(n);
      classes[cla["name"].toString()] = cla;
    }

    result["classes"] = classes;
  }

  {
    result["nb_functions"] = (int)ns.functions().size();
  }

  {
    result["nb_operators"] = (int)ns.operators().size();
  }

  {
    result["nb_literals"] = (int)ns.literalOperators().size();
  }

  write_agglomerate_stats(result);

  return result;
}

QJsonObject stats_export(const script::Module & mod)
{
  QJsonObject result;
  result["type"] = "module";
  result["name"] = QString::fromUtf8(mod.name().data());

  script::Namespace ns = mod.root();

  write_enum_stats(result, ns.enums());

  {
    //QJsonArray classes;
    //for (const auto & n : ns.classes())
    //{
    //  classes.push_back(stats_export(n));
    //}
    QJsonObject classes;
    for (const auto & n : ns.classes())
    {
      auto cla = stats_export(n);
      classes[cla["name"].toString()] = cla;
    }

    result["classes"] = classes;
    result["nb_classes"] = classes.size();
  }

  {
    result["nb_functions"] = (int)ns.functions().size();
  }

  {
    result["nb_operators"] = (int)ns.operators().size();
  }

  {
    result["nb_literals"] = (int)ns.literalOperators().size();
  }

  write_agglomerate_stats(result);

  return result;
}

void dump_stats(script::Engine *engine)
{
  QJsonObject result;
  result["root"] = stats_export(engine->rootNamespace());

  {
    //QJsonArray modules;
    //for (const auto & n : engine->modules())
    //  modules.push_back(stats_export(n));
    //QJsonArray modules;
    //for (const auto & n : engine->modules())
    //  modules.push_back(json_export(n));
    QJsonObject modules;
    for (const auto & n : engine->modules())
    {
      auto mod = stats_export(n);
      modules[mod["name"].toString()] = mod;
    }

    result["modules"] = modules;
  }

  QJsonDocument doc{ result };
  QTextStream(stdout) << doc.toJson();
}

/**************************************************************
 Short stats
***************************************************************/

struct short_stats_t
{
  int num_class;
  int num_constructors;
  int num_ctors_with_default_args;
  int num_ctors_default_args;
  int num_functions;
  int num_functions_with_default_args;
  int num_default_args;
  int num_parameters;
  int num_operators;

  short_stats_t()
    : num_class(0)
    , num_constructors(0)
    , num_ctors_with_default_args(0)
    , num_ctors_default_args(0)
    , num_functions(0)
    , num_functions_with_default_args(0)
    , num_default_args(0)
    , num_parameters(0)
    , num_operators(0)
  {

  }


  short_stats_t(const script::Class & cla)
    : short_stats_t()
  {
    addClass(cla);
  }

  short_stats_t(const script::Namespace & ns)
    : short_stats_t()
  {
    addNamespace(ns);
  }

  short_stats_t & numberOfClasses(int n) { num_class = n; return *this; }
  short_stats_t & numberOfConstructors(int n) { num_constructors = n; return *this; }
  short_stats_t & numberOfConstructorsWithDefaults(int n) { num_ctors_with_default_args = n; return *this; }
  short_stats_t & numberOfDefaultsInConstructors(int n) { num_ctors_default_args = n; return *this; }
  short_stats_t & numberOfFunctions(int n) { num_functions = n; return *this; }
  short_stats_t & numberOfFunctionsWithDefaults(int n) { num_functions_with_default_args = n; return *this; }
  short_stats_t & numberOfDefaultsInFunction(int n) { num_default_args = n; return *this; }
  short_stats_t & numberOfParameters(int n) { num_parameters = n; return *this; }
  short_stats_t & numberOfOperators(int n) { num_operators = n; return *this; }

  short_stats_t & addFunction(const script::Function & f)
  {
    if (f.isConstructor())
    {
      num_constructors += 1;
      num_ctors_with_default_args += (f.defaultArguments().size() > 0 ? 1 : 0);
      num_ctors_default_args += f.defaultArguments().size();
    }
    else if (f.isOperator())
    {
      num_operators += 1;
    }
    else
    {
      num_functions += 1;
      num_functions_with_default_args += (f.defaultArguments().size() > 0 ? 1 : 0);
      num_default_args += f.defaultArguments().size();
      num_parameters += f.prototype().count();
    }

    return *this;
  }

  short_stats_t & addClass(const script::Class & cla)
  {
    num_class += 1;

    for (const auto & f : cla.constructors())
      addFunction(f);

    for (const auto & f : cla.memberFunctions())
      addFunction(f);

    for (const auto & f : cla.operators())
      addFunction(f);

    for (const auto & c : cla.classes())
      addClass(c);

    return *this;
  }


  short_stats_t & addNamespace(const script::Namespace & ns)
  {
    for (const auto & c : ns.classes())
      addClass(c);

    for (const auto & f : ns.functions())
      addFunction(f);

    for (const auto & f : ns.operators())
      addFunction(f);

    return *this;
  }

};

short_stats_t operator+(const short_stats_t &a, const short_stats_t &b)
{
  return short_stats_t().numberOfClasses(a.num_class + b.num_class)
    .numberOfConstructors(a.num_constructors + b.num_constructors)
    .numberOfConstructorsWithDefaults(a.num_ctors_with_default_args + b.num_ctors_with_default_args)
    .numberOfDefaultsInConstructors(a.num_ctors_default_args + b.num_ctors_default_args)
    .numberOfFunctions(a.num_functions + b.num_functions)
    .numberOfFunctionsWithDefaults(a.num_functions_with_default_args + b.num_functions_with_default_args)
    .numberOfDefaultsInFunction(a.num_default_args + b.num_default_args)
    .numberOfParameters(a.num_parameters + b.num_parameters)
    .numberOfOperators(a.num_operators + b.num_operators);
}

void print_short_stats(script::Engine *e)
{
  auto stats = short_stats_t(e->rootNamespace());

  for (const auto & m : e->modules())
  {
    stats = stats + short_stats_t(m.root());
  }

  std::cout << "Number of classes : " << stats.num_class << std::endl;
  std::cout << "Number of constructors : " << stats.num_constructors << std::endl;
  std::cout << "with default args : " << stats.num_ctors_with_default_args << std::endl;
  std::cout << "total number of default args : " << stats.num_ctors_default_args << std::endl;
  std::cout << "Number of functions : " << stats.num_functions << std::endl;
  std::cout << "with default args : " << stats.num_functions_with_default_args << std::endl;
  std::cout << "total number of default args : " << stats.num_default_args << std::endl;
  std::cout << "total number of parameters : " << stats.num_parameters << std::endl;
  std::cout << "average number of parameters per function : " << (stats.num_parameters / float(stats.num_functions)) << std::endl;
  std::cout << "Number of operators: " << stats.num_operators << std::endl;
}

int main(int argc, char *argv[])
{
  Application app(argc, argv);

  app.scriptEngine()->getModule("widgets").load();

  if (app.arguments().size() < 2)
  {
    print_short_stats(app.scriptEngine());
  }

  for (const auto & arg : app.arguments())
  {
    if (arg == "-dump-tree")
      dump_tree(app.scriptEngine());
    if (arg == "-dump-stats")
      dump_stats(app.scriptEngine());
  }

  return 0;
}