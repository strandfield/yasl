// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "generator.h"

#include "gen/headerfile.h"
#include "gen/sourcefile.h"

#include <QDir>
#include <QFile>
#include <QJsonObject>
#include <QTextStream>

#include <QDebug>

const QString Generator::endl = "\r\n";
const QString Generator::ClassBinderInclude = "yasl/binding/class.h";
const QString Generator::EnumBinderInclude = "yasl/binding/enum.h";;
const QString Generator::NamespaceBinderInclude = "yasl/binding/namespace.h";;
const QString Generator::ClassBuilderInclude = "<script/classbuilder.h>";;
const QString Generator::EnumBuilderInclude = "<script/enumbuilder.h>";;


class StateGuard
{
public:
  Generator *gen;
  NodeRef node;
  QString current_module;
  HeaderFile *header;
  SourceFile *source;

  StateGuard(Generator *g, const NodeRef & n)
    : gen(g)
    , node(n)
  {
    current_module = gen->mCurrentModule;
    header = gen->mCurrentHeader;
    source = gen->mCurrentSource;

    if (node != nullptr)
    {
      gen->mProcessingStack.append(n);
      if (node->is<Module>())
      {
        if (gen->mCurrentModule.isEmpty())
          gen->mCurrentModule = node->name;
        else
          gen->mCurrentModule += "." + node->name;
      }
    }
  }

  ~StateGuard()
  {
    if(node != nullptr)
      gen->mProcessingStack.pop();
    gen->mCurrentModule = current_module;
    gen->mCurrentHeader = header;
    gen->mCurrentSource = source;
  }
};


Generator::TypeInfo::TypeInfo(const Type & t)
  : Type(t)
{

}


Generator::Generator(const QString & dir, QObject *parent)
  : QObject(parent)
  , mRootDirectory(dir)
  , mCurrentHeader(nullptr)
  , mCurrentSource(nullptr)
{

}

void Generator::generate(const ProjectRef & p)
{
  mProject = p;
  buildTypeInfo();

  {
    QDir dir{ mRootDirectory };
    if (!dir.exists("src"))
      dir.mkdir("src");

    if (!dir.exists("include"))
      dir.mkdir("include");

    dir.cd("include");
    if (!dir.exists("yasl"))
      dir.mkdir("yasl");
  }

  for (const auto & m : p->modules)
    generate(m);

  generateInjectedTypeList();
}

QString Generator::to_snake_case(const QString & camelCaseName)
{
  QString result;

  for (const auto & c : camelCaseName)
  {
    if (c.isUpper())
    {
      result += "_";
      result += c.toLower();
    }
    else
    {
      result += c;
    }
  }

  if (result.startsWith("_"))
    result.remove(0, 1);
  if (result.startsWith("q_"))
    result.remove(0, 2);

  return result;
}

Generator::OperatorSymbol Generator::getOperatorSymbol(const QString & str)
{
  static const QMap<QString, OperatorSymbol> symbols = {
    {"operator=", Assign},
  { "operator==", Eq },
  { "operator!=", Neq },
  { "operator<", Less },
  { "operator<=", Leq },
  { "operator>", Greater },
  { "operator>=", Geq },
  { "operator+", Plus },
  { "operator-", Minus },
  { "operator*", Mul },
  { "operator/", Div },
  { "operator%", Modulo },
  { "operator+=", AddAssign },
  { "operator-=", SubAssign },
  { "operator*=", MulAssign },
  { "operator/=", DivAssign },
  { "operator&", And },
  { "operator|", Or },
  { "operator&=", AndAssign },
  { "operator|=", OrAssign },
  { "operator[]", Subscript },
  { "operator()", FunctionCall },
  { "operator++", PlusPlus },
  { "operator--", MinusMinus },
  { "operator<<", LeftShift },
  { "operator>>", RightShift },
  { "operator<<=", LeftShiftAssign },
  { "operator>>=", RightShiftAssign },
  { "operator^", Xor },
  { "operator^=", XorAssign },
  { "operator~", BitwiseNot },
  };

  return symbols.value(str, Invalid);
}

struct OperatorInfo {
  QString short_name;
  bool print_return_type;
  int nargs;
};

static const OperatorInfo static_operator_infos[]{
  { "invalid", false, 0 },
  { "assign", false, 2 },
  { "eq", false,  2},
  { "neq", false, 2 },
  { "less", false, 2 },
  { "leq", false, 2 },
  { "greater", false, 2 },
  { "geq", false, 2 },
  { "invalid", false, 0 }, // plus
  { "unary_plus", true, 1 },
  { "add", true, 2 },
  { "invalid", false, 0 }, // minus
  { "unary_minus", true, 1 },
  { "sub", true, 2 },
  { "mul", true, 2 },
  { "div", true, 2 },
  { "mod", true, 2 },
  { "add_assign", false, 2 },
  { "sub_assign", false, 2 },
  { "mul_assign", false, 2 },
  { "div_assign", false, 2 },
  { "and", true, 2 },
  { "or", true, 2 },
  { "and_assign", false, 2 },
  { "or_assign", false, 2 },
  { "subscript", true, 2 },
  { "call", true, -1 },
  { "invalid", false, 0 }, // plusplus
  { "pre_increment", true, 1 },
  { "post_increment", true, 1 },
  { "invalid", false, 0 }, // minusminus
  { "pre_decrement", true, 1 },
  { "post_decrement", true, 1 },
  { "left_shift", true, 2 },
  { "right_shift", true, 2 },
  { "left_shift_assign", false, 2 },
  { "right_shift_assign", false, 2 },
  { "xor", true, 2 },
  { "xor_assign", false, 2 },
  { "bitwise_not", true, 1 },
};


void Generator::generate(ModuleRef mod)
{
  //HeaderFile header;
  SourceFile source;
  source.file = QFileInfo{ currentSourceDirectory() + "/" + mod->name + "module.cpp" };

  {
    QDir dir{ currentSourceDirectory() };
    if (!dir.exists(mod->name))
      dir.mkdir(mod->name);
  }
  {
    QDir dir{ currentHeaderDirectory() };
    if (!dir.exists(mod->name))
      dir.mkdir(mod->name);
  }

  StateGuard state{ this, mod };

  QString decls;
  
  QString load_func = "void load_" + mod->name + "_module(script::Module " + mod->name + ")" + endl;
  load_func += "{" + endl;


  for (const auto & n : mod->elements)
  {
    if (n->checkState == Qt::Unchecked)
      continue;

    if (n->is<File>())
    {
      generate(qSharedPointerCast<File>(n));

      Q_EMIT generated(qSharedPointerCast<File>(n));

      decls += "void register_" + n->name + "_file(script::Namespace n); // defined in " + n->name + ".cpp" + endl;
      load_func += "  register_" + n->name + "_file(" + mod->name + ".root());" + endl;
    }
    else
    {
      qDebug() << "TODO in generate(ModuleRef mod)";
    }
  }

  load_func += "}" + endl;

  source.functions.append(decls);
  source.functions.append(load_func);

  source.write();
}

void Generator::generate(FileRef file)
{
  StateGuard state{ this, nullptr };

  HeaderFile header;
  header.file = QFileInfo{ currentHeaderDirectory() + "/" + file->name + ".h" };
  header.moduleName = mCurrentModule;
  for (const auto & inc : file->hincludes)
    header.generalIncludes.insert(inc);
  SourceFile source;
  source.file = QFileInfo{ currentSourceDirectory() + "/" + file->name + ".cpp" };
  source.header = "yasl/" + QString{ mCurrentModule }.replace(".", "/") +"/" + file->name + ".h";
  for (const auto & inc : file->cppincludes)
    source.generalIncludes.insert(inc);

  mCurrentSource = &source;
  mCurrentHeader = &header;

  generate(NamespaceRef{ file });



  header.write();
  source.write();
}

QString Generator::generate(FunctionRef fun)
{
  return generate(fun, getBindingMethod(fun));
}

QString Generator::generate(FunctionRef fun, Function::BindingMethod bm)
{
  if (bm == Function::ConstructorBinding)
  {
    if (fun->parameters.isEmpty())
      return "  binder.ctors().add_default();";
    else
      return "  binder.ctors().add<" + fparams(fun->parameters) + ">();";
  }
  else if (bm == Function::DestructorBinding)
  {
    return "  binder.add_dtor();";
  }
  else if (bm == Function::OperatorBinding)
  {
    return generateOperator(fun, getOperatorSymbol(fun->name));
  }
  else if (fun->bindingMethod == Function::MacroBinding)
  {
    return generateWithMacros(fun);
  }
  else if (fun->bindingMethod == Function::SignalBinding)
  {
    return generateSignal(fun);
  }

  const QString funname = fun->rename.isEmpty() ? fun->name : fun->rename;
  const QString params = fparamscomma(fun);
  const QString funaddr = "&" + nameQualification() + fun->name;
  const QString fret = fparam(fun->returnType);

  if (bm == Function::StaticVoidBinding)
    return QString("  binder.add_static_void_fun<%1%2>(\"%3\");").arg(params, funaddr, funname);
  else if(bm == Function::ConstVoidBinding)
    return QString("  binder.add_const_void<%2%3>(\"%4\");").arg(params, funaddr, funname);
  else if (bm == Function::VoidBinding)
    return QString("  binder.add_void_fun<%2%3>(\"%4\");").arg(params, funaddr, funname);
  else if (bm == Function::ChainableBinding)
    return QString("  binder.add_chainable<%2%3>(\"%4\");").arg(params, funaddr, funname);
  else if (bm == Function::StaticBinding)
    return QString("  binder.add_static<%1, %2%3>(\"%4\");").arg(fret, params, funaddr, funname);
  else if (bm == Function::SimpleBinding)
    return QString("  binder.add_fun<%1, %2%3>(\"%4\");").arg(fret, params, funaddr, funname);
  else if (bm == Function::ReferenceBinding)
    return QString("  binder.add_ref_mem<%1, %2%3>(\"%4\");").arg(fret, params, funaddr, funname);
  else if (bm == Function::FreeFunctionBinding)
    return QString("  binder.add_fun<%1, %2%3>(\"%4\");").arg(fret, params, "&" + fun->name, funname);

  throw std::runtime_error{ "Unsupported bind method !" };
}

QString Generator::generateWithMacros(FunctionRef fun)
{
  auto get_format = [&]() -> QString {
    if (isMember() && !fun->isStatic)
    {
      if (fun->returnType == "void")
        return "YASL_VOID_METHOD___nb_params__(__script_symbol__, \"__name__\", void, __cpp_class__, __func_name____parameters__)";
      else if (fun->returnType == enclosingName() + " &")
        return "YASL_CHAINABLE_METHOD___nb_params__(__script_symbol__, \"__name__\", __return_type__, __cpp_class__, __func_name____parameters__)";
      else
        return "YASL_METHOD___nb_params__(__script_symbol__, \"__name__\", __return_type__, __cpp_class__, __func_name____parameters__)";
    }
    else
    {
      if (fun->returnType == "void")
        return "YASL_VOID_FUN___nb_params__(__script_symbol__, \"__name__\", void, __func_name____parameters__)";
      else
        return "YASL_FUNCTION___nb_params__(__script_symbol__, \"__name__\", __return_type__, __func_name____parameters__)";
    }
  };

  if (fun->name.startsWith("operator"))
  {
    OperatorSymbol sym = getOperatorSymbol(fun->name);
    if (sym != Invalid)
    {
      throw std::runtime_error{ "Argh!" };
      //out << "  /// TODO !!!" << endl;
      
      return "";
    }
  }

  QString result = "  " + get_format()
    .replace("__nb_params__", QString::number(fun->parameters.size()))
    .replace("__parameters__", fun->parameters.isEmpty() ? "" : ", " + fparams(fun))
    .replace("__script_symbol__", isMember() ? "binder.class_" : "binder.namespace_")
    .replace("__name__", fun->rename.isEmpty() ? fun->name : fun->rename)
    .replace("__return_type__", fun->returnType)
    .replace("__cpp_class__", enclosingName())
    .replace("__func_name__", isMember() && !fun->isStatic ? fun->name : nameQualification() + fun->name)
    .append(fun->isConst ? ".setConst()" : "")
    .append(fun->isStatic ? ".setStatic()" : "")
    .append(".create()");

  currentSource().bindingIncludes.insert("yasl/binding/macros.h");

  return result + ";";
}

QString Generator::generateSignal(FunctionRef fun)
{
  const QString funname = fun->rename.isEmpty() ? fun->name : fun->rename;
  const QString signature = fun->name + "(" + fun->parameters.join(",") + ")";

  if (fun->parameters.size() == 0)
  {
    QString format = "binder.sigs().add(\"%1\", \"%2\");";
    return format.arg(funname, signature);
  }
  else
  {
    QString format = "binder.sigs().add<%1>(\"%2\", \"%3\");";
    const QString params = fun->parameters.join(", ");
    return format.arg(params, funname, signature);
  }
}

QString Generator::generateOperator(FunctionRef fun, OperatorSymbol op)
{
  QString out = "  binder.operators().";

  const int implicit_param_count = isMember() ? 1 : 0;

  if (op == Plus)
    op = fun->parameters.count() + implicit_param_count == 1 ? UnaryPlus : Add;
  else if (op == Minus)
    op = fun->parameters.count() + implicit_param_count == 1 ? UnaryMinus : Sub;
  else if (op == PlusPlus)
    op = fun->parameters.count() + implicit_param_count == 1 ? PreIncrement : PostIncrement;
  else if (op == MinusMinus)
    op = fun->parameters.count() + implicit_param_count == 1 ? PreDecrement : PostDecrement;

  if (op == FunctionCall)
  {
    out += static_operator_infos[op].short_name + QString("<");
    QStringList targs;
    if (static_operator_infos[op].print_return_type)
      targs << fparam(fun->returnType);
    for (int i(0); i < fun->parameters.size(); ++i)
      targs << fparam(fun, i);
    out += targs.join(", ");
    out += ">();";
    return out;
  }
  else
  {
    if (!isMember() && (op == LeftShift || op == RightShift))
    {
      if (fun->returnType == fun->parameters.at(0))
      {
        out += (op == LeftShift ? "put_to" : "read_from") + QString("<");
        QStringList targs;
        targs << fparam(fun->parameters.first()) << fparam(fun->parameters.at(1));
        out += targs.join(", ");
        out += ">();";
        return out;
      }
    }

    out += static_operator_infos[op].short_name + QString("<");
    QStringList targs;
    if (static_operator_infos[op].print_return_type)
      targs << fparam(fun->returnType);
    if (static_operator_infos[op].nargs - implicit_param_count == 1)
      targs << fparam(fun->parameters.first());
    else if (static_operator_infos[op].nargs - implicit_param_count == 2)
      targs << fparam(fun->parameters.first()) << fparam(fun->parameters.at(1));
    out += targs.join(", ");
    out += ">();";
    return out;
  }
}

QString Generator::fparam(FunctionRef fun, int n)
{
  return fparam(fun->parameters.at(n));
}

QString Generator::fparam(const QString & p)
{
  QString pp = p;

  bool is_const = false;
  bool is_ref = false;
  bool is_refref = false;

  if (pp.startsWith("const "))
  {
    is_const = true;
    pp.remove(0, 6);
  }
  if (pp.endsWith("&&"))
  {
    is_refref = true;
    pp.chop(2);
  }
  if (pp.endsWith("&"))
  {
    is_ref = true;
    pp.chop(1);
  }

  pp = pp.simplified();

  const Type & info = typeinfo(pp);

  if (!info.header.isEmpty())
    currentSource().generalIncludes.insert(info.header);

  return p;
}

QString Generator::fparams(const QStringList & params)
{
  QStringList ret;
  for (const auto & p : params)
    ret << fparam(p);
  return ret.join(", ");
}

QString Generator::fparams(const FunctionRef fun)
{
  return fparams(fun->parameters);
}

QString Generator::fparamscomma(const FunctionRef fun)
{
  QString ret = fparams(fun);
  if (!ret.isEmpty())
    return ret + ", ";
  return ret;
}

Function::BindingMethod Generator::getBindingMethod(FunctionRef fun) const
{
  if (fun->bindingMethod == Function::AutoBinding)
    return guessBindingMethod(fun);
  return fun->bindingMethod;
}

Function::BindingMethod Generator::guessBindingMethod(FunctionRef fun) const
{
  if (fun->is<Constructor>())
    return Function::ConstructorBinding;

  if (fun->name.startsWith("operator"))
  {
    OperatorSymbol sym = getOperatorSymbol(fun->name);
    if (sym != Invalid)
      return Function::OperatorBinding;
  }

  if (fun->name == "~" + enclosingName())
    return Function::DestructorBinding;

  if (fun->returnType == "void")
  {
    if (fun->isStatic)
      return Function::StaticVoidBinding;
    else if (fun->isConst)
      return Function::ConstVoidBinding;
    else
      return Function::VoidBinding;
  }
  else if (fun->returnType == enclosingName() + " &")
  {
    return Function::ChainableBinding;
  }

  if (fun->isStatic)
    return Function::StaticBinding;
  else
    return Function::SimpleBinding;
}

QList<QPair<QString, QString>> Generator::extractLinks(const QString & str)
{
  QList<QPair<QString, QString>> ret;

  QStringList links = str.split(";", QString::SkipEmptyParts);
  for (auto lstr : links)
  {
    const int at_index = lstr.indexOf("@");
    if (at_index == -1)
      continue;

    QPair<QString, QString> link;
    link.first = lstr.mid(0, at_index).simplified();
    link.second = lstr.mid(at_index + 1).simplified();
    ret.append(link);
  }

  return ret;
}

void Generator::generate(ClassRef cla)
{
  if (cla->checkState == Qt::Unchecked)
    return;

  currentSource().libscriptIncludes.insert(ClassBuilderInclude);
  currentSource().bindingIncludes.insert(ClassBinderInclude);

  const QString pre = prefix();
  const QString enclosing_snake = enclosing_snake_name();
  const QString enclosing_entity = enclosingEntity();
  const QString qual = nameQualification();
 
  StateGuard state{ this, cla };


  QString snake = to_snake_case(cla->name);
  Type class_info = typeinfo(qual + cla->name);
  QString claname = class_info.rename.isEmpty() ? class_info.name : class_info.rename;

  for (const auto n : cla->elements)
  {
    if (n->is<Class>() || n->is<Enum>())
      generate(n);
  }

  QString out;
  out += "static void register_" + pre + snake + "_class(script::" + enclosing_entity + " " + enclosing_snake + ")" + endl;
  out += "{" + endl;
  out += "  using namespace script;" + endl;
  out += endl;
  out += "  Class " + snake + " = " + enclosing_snake;
  if (enclosing_entity == "Namespace")
    out += ".Class";
  else
    out += ".NestedClass";
  out += "(\"" + claname + "\").setId(script::Type::" + class_info.id + ")";
  if (!cla->base.isEmpty()) 
  {
    Type base_class_info = typeinfo(cla->base);
    out += endl + ".setBase(script::Type::" + base_class_info.id + ")";
  }
  if (cla->isFinal)
  {
    out += endl + ".setFinal()";
  }
  out += ".get();" + endl;
  out += endl;

  Links links = extractLinks(class_info.links);
  for (const auto & l : links)
  {
    if (l.first == "ref")
    {
      Type ref_info = typeinfo(l.second);
      currentSource().bindingIncludes.insert("yasl/utils/ref.h");
      const QString format = "  register_ref_specialization(%1.engine(), script::Type::%2, script::Type::%3);" + endl;
      out += format.arg(snake, class_info.id, ref_info.id);
      recordGeneratedClass(ref_info.name);
    }
    else if (l.first == "ptr")
    {
      Type ptr_info = typeinfo(l.second);
      currentHeader().bindingIncludes.insert("yasl/utils/ptr.h");
      const QString format = "  register_ptr_specialization<%1>(%2.engine()->getTemplate(Engine::PtrTemplate), script::Type::%3);" + endl;
      QString ptrelem = ptr_info.name;
      ptrelem.chop(QString(">").length());
      ptrelem.remove(0, QString("Ptr<").length());
      out += format.arg(ptrelem, snake, ptr_info.id);
      recordGeneratedClass(ptr_info.name);
    }
    else if (l.first == "list")
    {
      Type list_info = typeinfo(l.second);
      currentSource().bindingIncludes.insert("yasl/core/listspecializations.h");
      const QString format = "  register_list_specialization<%1>(%2.engine(), script::Type::%3);" + endl;
      QString listelement = list_info.name;
      listelement.chop(QString(">").length());
      listelement.remove(0, QString("QList<").length());
      out += format.arg(listelement, snake, list_info.id);
      recordGeneratedClass(list_info.name);
    }
  }

  for (const auto n : cla->elements)
  {
    if (n->is<Enum>())
      out += "  register_" + prefix() + to_snake_case(n->name) + "_enum(" + snake + ");" + endl;
    else if(n->is<Class>())
      out += "  register_" + prefix() + to_snake_case(n->name) + "_class(" + snake + ");" + endl;
  }


  if (cla->derivedFromQObject)
    out += "  binding::QClass<" + cla->name + "> binder{ " + snake + ", &" + cla->name + "::staticMetaObject };" + endl;
  else
    out += "  binding::Class<" + cla->name + "> binder{ " + snake + " };" + endl;

  out += endl;


  for (const auto n : cla->elements)
  {
    if (n->checkState == Qt::Unchecked || !n->is<Function>())
      continue;
      
    FunctionRef fun = qSharedPointerCast<Function>(n);
    out += "  // " + fun->displayedName() + endl;
    try
    {
      out += generate(fun) + endl;
    }
    catch (...)
    {
      out += "  /// TODO: " + fun->displayedName() + endl;
    }
  }

  if (cla->derivedFromQObject)
  {
    out += endl;
    out += "  " + snake + ".engine()->registerQtType(&" + cla->name + "::staticMetaObject, " + snake + ".id());" + endl;
  }

  out += "}" + endl;
  out += endl;

  currentSource().functions.append(out);
  recordGeneratedClass(qual + cla->name);
}

void Generator::generate(EnumRef enm)
{
  if (enm->checkState == Qt::Unchecked)
    return;

  currentSource().libscriptIncludes.insert(EnumBuilderInclude);
  currentSource().bindingIncludes.insert(EnumBinderInclude);

  const QString pre = prefix();

  QString snake = to_snake_case(enm->name);
  Type enum_info = typeinfo(nameQualification() + enm->name);
  QString enmname = enum_info.rename.isEmpty() ? removeQualification(enum_info.name) : enum_info.rename;

  QString out;
  out += "static void register_" + pre + snake + "_enum(script::" + enclosingEntity() + " " + enclosing_snake_name() + ")" + endl;
  out += "{" + endl;
  out += "  using namespace script;" + endl;
  out += endl;
  out += "  Enum " + snake + " = " + enclosing_snake_name() + ".Enum(\"" + enmname + "\").setId(script::Type::" + enum_info.id + ")";
  if (enm->isEnumClass)
    out += endl + ".setEnumClass()";
  out += ".get();" + endl;
  out += endl;


  Links links = extractLinks(enum_info.links);
  for (const auto & l : links)
  {
    if (l.first == "flags")
    {
      Type flags_info = typeinfo(l.second);
      const QString flagname = flags_info.rename.isEmpty() ? flags_info.name : flags_info.rename;
      currentSource().bindingIncludes.insert("yasl/core/flags.h");
      const QString format = "  register_qflags_type<%1>(%2, \"%3\", script::Type::%4);" + endl;
      out += format.arg(enum_info.name, enclosing_snake_name(), flagname, flags_info.id);
      recordGeneratedClass(flags_info.name);
    }
  }


  for (const auto & v : enm->enumerators)
  {
    if (v->checkState == Qt::Unchecked)
      continue;

    out += "  " + snake + ".addValue(\"" + v->name + "\", " + nameQualification() + v->name + ");" + endl;
  }

  out += "}" + endl;
  out += endl;

  currentSource().functions.append(out);
  recordGeneratedEnum(nameQualification() + enm->name);
}

void Generator::generate(NamespaceRef ns)
{
  if (ns->checkState == Qt::Unchecked)
    return;

  //currentSource().libscriptIncludes.insert();
  currentSource().bindingIncludes.insert(NamespaceBinderInclude);

  const QString pre = prefix();
  const QString enclosing_snake = enclosing_snake_name();

  StateGuard guard{ this, ns };

  QString snake = ns->is<File>() ? "ns" : to_snake_case(ns->name);

  for (const auto n : ns->elements)
  {
    if(n->is<Namespace>() || n->is<Class>() || n->is<Enum>())
      generate(n);
  }

  QString out;
  if(ns->is<File>())
    out +=  "void register_" + pre + to_snake_case(ns->name) + "_file(script::Namespace " + enclosing_snake + ")" + endl;
  else
    out += "static void register_" + pre + snake + "_namespace(script::Namespace " + enclosing_snake + ")" + endl;
  out += "{" + endl;
  out += "  using namespace script;" + endl;
  out += endl;
  if(ns->is<File>())
    out += "  Namespace " + snake + " = " + enclosing_snake + ";" + endl;
  else
    out += "  Namespace " + snake + " = " + enclosing_snake + ".getNamespace(\"" + ns->name + "\");" + endl;
  out += endl;

  for (const auto n : ns->elements)
  {
    if (n->checkState == Qt::Unchecked)
      continue;

    if (n->is<Enum>())
      out += "  register_" + prefix() + to_snake_case(n->name) + "_enum(" + snake + ");" + endl;
    else if (n->is<Class>())
      out += "  register_" + prefix() + to_snake_case(n->name) + "_class(" + snake + ");" + endl;
  }

  out += "  binding::Namespace binder{ " + snake + " };" + endl;
  out += endl;

  for (const auto n : ns->elements)
  {
    if (n->checkState == Qt::Unchecked)
      continue;

    if (!n->is<Function>())
      continue;

    FunctionRef fun = qSharedPointerCast<Function>(n);
    out += "  // " + fun->displayedName() + endl;
    try
    {
      out += generate(fun) + endl;
    }
    catch (...)
    {
      out += "  /// TODO: " + fun->displayedName() + endl;
    }
  }

  out += "}" + endl;
  
  currentSource().functions.append(out);
}

void Generator::generate(NodeRef n)
{
  if (n->is<File>())
  {
    qDebug() << "Error in generate(NodeRef) : input is a file";
    return;
  }

  if(n->is<Module>())
    generate(qSharedPointerCast<Module>(n));
  else if (n->is<Namespace>())
    generate(qSharedPointerCast<Namespace>(n));
  else if(n->is<Class>())
    generate(qSharedPointerCast<Class>(n));
  else if (n->is<Enum>())
    generate(qSharedPointerCast<Enum>(n));
  else
  {
    qDebug() << "Error in generate(NodeRef)";
  }
}

QString Generator::prefix() const
{
  if (mProcessingStack.isEmpty())
    return "";

  QStringList names;
  for (const auto & node : mProcessingStack)
  {
    if (node->is<File>() || node->is<Module>())
      continue;

    names << to_snake_case(node->name);
  }

  if (names.empty())
    return "";
  return names.join("_") + "_";
}

QString Generator::enclosingEntity() const
{
  if (mProcessingStack.isEmpty() || mProcessingStack.top()->is<Namespace>())
    return "Namespace";

  return "Class";
}

QString Generator::enclosingName() const
{
  if (mProcessingStack.isEmpty())
    return "";

  return mProcessingStack.top()->name;
}

QString Generator::enclosing_snake_name() const
{
  if (mProcessingStack.isEmpty() || mProcessingStack.top()->is<File>())
    return "ns";

  return to_snake_case(mProcessingStack.top()->name);
}

QString Generator::nameQualification() const
{
  return Node::nameQualification(mProcessingStack);
}

QString Generator::removeQualification(QString name) const
{
  const int index = name.lastIndexOf("::");
  if (index == -1)
    return name;
  return name.mid(index + 2);
}

bool Generator::isMember() const
{
  return !mProcessingStack.isEmpty() && mProcessingStack.top()->is<Class>();
}

HeaderFile & Generator::currentHeader()
{
  return *mCurrentHeader;
}

SourceFile & Generator::currentSource()
{
  return *mCurrentSource;
}

QString Generator::currentHeaderDirectory()
{
  return mRootDirectory + "/include/yasl/" + QString{ mCurrentModule }.replace(".", "/");
}

QString Generator::currentSourceDirectory()
{
  return mRootDirectory + "/src/" + QString{ mCurrentModule }.replace(".", "/");
}

void Generator::recordGeneratedEnum(const QString & name)
{
  TypeInfo & info = typeinfo(name);
  currentHeader().types[name] = info;

  mProject->getType(name).header = +"yasl/" + QString{ mCurrentModule }.replace(".", "/") + "/" + currentHeader().file.fileName();

  mGeneratedTypes.enums[mCurrentModule].insert(info.id);
}

void Generator::recordGeneratedClass(const QString & name)
{
  TypeInfo & info = typeinfo(name);
  currentHeader().types[name] = info;

  mProject->getType(name).header = +"yasl/" + QString{ mCurrentModule }.replace(".", "/") + "/" + currentHeader().file.fileName();

  mGeneratedTypes.classes[mCurrentModule].insert(info.id);
}

void Generator::generateInjectedTypeList()
{
  QFile file{ mRootDirectory + "/types.injected" };
  if (!file.open(QIODevice::WriteOnly))
  {
    qDebug() << "Generator::generateInjectedTypeList() failed to open file";
    return;
  }

  QTextStream out{ &file };

  out << "FirstEnumType = 66 | EnumTypeFlag," << endl;
  for (auto it = mGeneratedTypes.enums.begin(); it != mGeneratedTypes.enums.end(); ++it)
  {
    out << "/* " << it.key() << " module */" << endl;
    for (const auto & t : it.value())
      out << t << "," << endl;
  }
  out << "LastEnumType," << endl;

  out << "FirstClassType = 66 | ObjectTypeFlag," << endl;
  for (auto it = mGeneratedTypes.classes.begin(); it != mGeneratedTypes.classes.end(); ++it)
  {
    out << "/* " << it.key() << " module */" << endl;
    for (const auto & t : it.value())
      out << t << "," << endl;
  }
  out << "LastClassType," << endl;

  out.flush();
  file.close();
}

void Generator::buildTypeInfo()
{
  mTypeInfos.clear();
  
  for (const auto & t : mProject->types.fundamentals)
    mTypeInfos[t.name] = t;

  for (const auto & t : mProject->types.enums)
    mTypeInfos[t.name] = t;

  for (const auto & t : mProject->types.classes)
    mTypeInfos[t.name] = t;

}

Generator::TypeInfo & Generator::typeinfo(const QString & t)
{
  if (t.isEmpty())
    throw UnsupportedType{ t };

  auto it = mTypeInfos.find(t);
  if (it == mTypeInfos.end()) 
    throw UnsupportedType{ t };
  return it.value();
}