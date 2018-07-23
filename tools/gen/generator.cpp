// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "generator.h"

#include <QFile>
#include <QJsonObject>
#include <QTextStream>

Generator::Generator(QJsonObject &db)
  : mDatabase(db)
{

}

void Generator::generate(Project & p)
{
  for (const auto & f : p.files)
    generate(f);
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
  { "add", true, 2 },
  { "unary_plus", true, 1 },
  { "invalid", false, 0 }, // minus
  { "sub", true, 2 },
  { "unary_minus", true, 1 },
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

void Generator::generate(gen::FileRef file)
{
  Q_ASSERT(file->name != file->path);

  mCurrentFileName = file->name;
  mCurrentFileName.remove(".h");

  generateHeader(file);

  QFile source_file{ mCurrentFileName + ".cpp" };
  if (!source_file.open(QFileDevice::WriteOnly))
    return;

  QTextStream source_stream{ &source_file };

  writeCopyrightMessage(source_stream);
  source_stream << endl;
  source_stream << "#include \"" << currentFileName() << ".h\"" << endl;
  source_stream << endl;

  {
    QSet<QString> headers;
    fetchHeaderList(headers, file);
    for(const auto & h : headers)
      source_stream << "#include \"" << h << ".h\"" << endl;
  }

  source_stream << "#include \"yasl/binding/class.h\"" << endl;
  source_stream << "#include \"yasl/binding/enum.h\"" << endl;
  source_stream << "#include \"yasl/binding/macros.h\"" << endl;
  source_stream << "#include \"yasl/binding/namespace.h\"" << endl;
  source_stream << endl;
  source_stream << "#include <script/class.h>" << endl;
  source_stream << "#include <script/classbuilder.h>" << endl;
  source_stream << "#include <script/enumbuilder.h>" << endl;
  source_stream << "#include <script/namespace.h>" << endl;

  source_stream << endl;

  generate(source_stream, file);

  source_file.close();
}

void Generator::generate(QTextStream & out, gen::FileRef file)
{
  if (file->checkState == Qt::Unchecked)
    return;

  const QString pre = prefix();
  const QString enclosing_snake = enclosing_snake_name();

  QString snake = to_snake_case(currentFileName());

  {
    for (const auto n : file->globalNamespace.namespaces)
      generate(out, n);
    for (const auto n : file->globalNamespace.classes)
      generate(out, n);
    for (const auto n : file->globalNamespace.enums)
      generate(out, n);
  }

  out << "static void register_" << snake << "_file(script::Namespace root)" << endl;
  out << "{" << endl;
  out << "  using namespace script;" << endl;
  out << endl;

  {
    for (const auto n : file->globalNamespace.enums)
    {
      if(n->checkState != Qt::Unchecked)
        out << "  register_" << to_snake_case(n->name) << "_enum(root);" << endl;
    }

    for (const auto n : file->globalNamespace.classes)
    {
      if (n->checkState != Qt::Unchecked)
        out << "  register_" << to_snake_case(n->name) << "_class(root);" << endl;
    }
  }

  out << "  binding::Namespace binder{ root };" << endl;
  out << endl;

  for (const auto n : file->globalNamespace.functions)
    generate(out, n);

  out << "}" << endl;
  out << endl;
}

void Generator::generate(QTextStream & out, gen::ClassRef cla)
{
  if (cla->checkState == Qt::Unchecked)
    return;
  
  registerHeader(cla->name);

  const QString pre = prefix();
  const QString enclosing_snake = enclosing_snake_name();
  const QString enclosing_entity = enclosingEntity();
  mProcessingStack.push(cla);


  QString snake = to_snake_case(cla->name);

  {
    for (const auto n : cla->enums)
      generate(out, n);
  }

  out << "static void register_" << pre + snake << "_class(script::" << enclosing_entity << " " << enclosing_snake  << ")" << endl;
  out << "{" << endl;
  out << "  using namespace script;" << endl;
  out << endl;
  out << "  Class " << snake << " = " << enclosing_snake;
  if (enclosing_entity == "Namespace")
    out << ".Class";
  else
    out << ".NestedClass";
  out << "(\"" << cla->name << "\").setId(script::Type::" << QString(nameQualification()).remove("::") << ").get();" << endl;
  out << endl;

  {
    for (const auto n : cla->enums)
    {
      if (n->checkState == Qt::Unchecked)
        continue;
      out << "  register_" << prefix() + to_snake_case(n->name) << "_enum(" << snake << ");" << endl;
    }
  }



  if(cla->derivedFromQObject)
    out << "  binding::QClass<" << cla->name << "> binder{ " << snake << " };" << endl;
  else
    out << "  binding::Class<" << cla->name << "> binder{ " << snake << " };" << endl;

  out << endl;

  for (const auto n : cla->functions)
    generate(out, n);

  if (cla->derivedFromQObject)
  {
    out << endl;
    out << "  register_object_type(&" << cla->name << "::staticMetaObject, " << snake << ");" << endl;
  }

  out << "}" << endl;
  out << endl;

  mProcessingStack.pop();
}

void Generator::generate(QTextStream & out, gen::FunctionRef fun)
{
  if (fun->checkState == Qt::Unchecked)
    return;

  out << "  // " << fun->displayedName() << endl;

  if (fun->useBindingMacros)
    generateWithMacros(out, fun);
  else
    generateWithTemplates(out, fun);
}

void Generator::generateWithTemplates(QTextStream & out, gen::FunctionRef fun)
{
  if (fun->is<gen::Constructor>())
  {
    if (fun->parameters.isEmpty())
    {
      out << "  binder.ctors().add_default();" << endl;
    }
    else
    {
      out << "  binder.ctors().add<";
      QString params;
      for (const auto & p : fun->parameters)
      {
        params += p + ", ";
      }
      params.chop(2);
      out << params << ">();" << endl;
    }
  }
  else
  {
    if (fun->name.startsWith("operator"))
    {
      OperatorSymbol sym = getOperatorSymbol(fun->name);
      if (sym != Invalid)
        return generateOperator(out, fun, sym);
    }

    if (fun->returnType == "void")
    {
      if(fun->isStatic)
        out << "  binder.add_static_void_fun<";
      else if(fun->isConst)
        out << "  binder.add_const_void_fun<";
      else
        out << "  binder.add_void_fun<";
    }
    else if(fun->returnType == enclosingName() + " &")
    {
      out << "  binder.add_chainable<";
    }
    else
    {
      if (fun->isStatic)
        out << "  binder.add_static<";
      else
        out << "  binder.add_fun<";

      out << fun->returnType << ", ";
    }

    QString params;
    for (const auto & p : fun->parameters)
    {
      params += p + ", ";
    }

    out << params;

    out << "&" << nameQualification() << fun->name << ">(\"" << fun->name << "\");" << endl;
  }
}

void Generator::generateWithMacros(QTextStream & out, gen::FunctionRef fun)
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
      out << "  /// TODO !!!" << endl;
      return;
    }
  }

  QString result = get_format()
    .replace("__nb_params__", QString::number(fun->parameters.size()))
    .replace("__parameters__", fun->parameters.isEmpty() ? "" : ", " + fun->parameters.join(", "))
    .replace("__script_symbol__", isMember() ? "binder.class_" : "binder.namespace_")
    .replace("__name__", fun->name)
    .replace("__return_type__", fun->returnType)
    .replace("__cpp_class__", enclosingName())
    .replace("__func_name__", isMember() && !fun->isStatic ? fun->name : nameQualification() + fun->name)
    .append(fun->isConst ? ".setConst()" : "")
    .append(fun->isStatic ? ".setStatic()" : "")
    .append(".create()");

  out << "  " << result << ";" << endl;
}

void Generator::generateOperator(QTextStream & out, gen::FunctionRef fun, OperatorSymbol op)
{
  out << "  binder.operators().";

  if (op == Plus)
    op = fun->parameters.count() == 0 ? UnaryPlus : Add;
  else if (op == Minus)
    op = fun->parameters.count() == 0 ? UnaryMinus : Sub;
  else if (op == PlusPlus)
    op = fun->parameters.count() == 0 ? PreIncrement : PostIncrement;
  else if (op == MinusMinus)
    op = fun->parameters.count() == 0 ? PreDecrement : PostDecrement;

  if (op == FunctionCall)
  {
    out << static_operator_infos[op].short_name << "<";
    QStringList targs;
    if (static_operator_infos[op].print_return_type)
      targs << fun->returnType;
    for (int i(0); i < fun->parameters.size(); ++i)
      targs << fun->parameters.at(i);
    out << targs.join(", ");
    out << ">();" << endl;
  }
  else
  {
    if (!isMember() && (op == LeftShift || op == RightShift))
    {
      if (fun->returnType == fun->parameters.at(0))
      {
        out << (op == LeftShift ? "put_to" : "read_from") << "<";
        QStringList targs;
        targs << fun->parameters.first() << fun->parameters.at(1);
        out << targs.join(", ");
        out << ">();" << endl;
        return;
      }
    }

    const int implicit_arg_count = isMember() ? 1 : 0;

    out << static_operator_infos[op].short_name << "<";
    QStringList targs;
    if (static_operator_infos[op].print_return_type)
      targs << fun->returnType;
    if (static_operator_infos[op].nargs - implicit_arg_count == 1)
      targs << fun->parameters.first();
    else if (static_operator_infos[op].nargs - implicit_arg_count  == 2)
      targs << fun->parameters.first() << fun->parameters.at(1);
    out << targs.join(", ");
    out << ">();" << endl;
  }
}

void Generator::generate(QTextStream & out, gen::NamespaceRef ns)
{
  if (ns->checkState == Qt::Unchecked)
    return;

  const QString pre = prefix();
  const QString enclosing_snake = enclosing_snake_name();

  mProcessingStack.push(ns);


  QString snake = to_snake_case(ns->name);

  {
    for (const auto n : ns->namespaces)
      generate(out, n);
    for (const auto n : ns->classes)
      generate(out, n);
    for (const auto n : ns->enums)
      generate(out, n);
  }

  out << "static void register_" << pre + snake << "_namespace(script::Namespace " << enclosing_snake << ")" << endl;
  out << "{" << endl;
  out << "  using namespace script;" << endl;
  out << endl;
  out << "  Namespace " << snake << " = " << enclosing_snake << ".getNamespace(\"" << ns->name << "\");" << endl;
  out << endl;

  {
    for (const auto n : ns->enums)
    {
      if (n->checkState == Qt::Unchecked)
        continue;

      out << "  register_" << prefix() + to_snake_case(n->name) << "_enum(" << snake << ");" << endl;
    }

    for (const auto n : ns->classes)
    {
      if (n->checkState == Qt::Unchecked)
        continue;

      out << "  register_" << prefix() + to_snake_case(n->name) << "_class(" << snake << ");" << endl;
    }
  }

  out << "  binding::Namespace binder{ " << snake << " };" << endl;
  out << endl;

  for (const auto n : ns->functions)
    generate(out, n);

  out << "}" << endl;
  out << endl;

  mProcessingStack.pop();
}

void Generator::generate(QTextStream & out, gen::EnumRef enm)
{
  if (enm->checkState == Qt::Unchecked)
    return;

  registerHeader(enm->name);

  const QString pre = prefix();

  QString snake = to_snake_case(enm->name);

  out << "static void register_" << pre + snake << "_enum(script::" << enclosingEntity() << " " << enclosing_snake_name() << ")" << endl;
  out << "{" << endl;
  out << "  using namespace script;" << endl;
  out << endl;
  out << "  Enum " << snake << " = " << enclosing_snake_name() << ".Enum(\"" << enm->name << "\").setId(script::Type::" << QString(nameQualification() + enm->name).remove("::") << ").get();" << endl;
  out << endl;

  for (const auto & v : enm->values)
  {
    if (v->checkState == Qt::Unchecked)
      continue;

    out << "  " << snake << ".addValue(\"" << v->name << "\", " << nameQualification() + v->name << ");" << endl;
  }

  out << "}" << endl;
  out << endl;
}

void Generator::fetchHeaderList(QSet<QString> & headers, gen::NodeRef node)
{
  if (node->checkState == Qt::Unchecked)
    return;

  if (node->is<gen::File>())
  {
    gen::File & f = node->as<gen::File>();
    for (const auto & n : f.globalNamespace.namespaces)
      fetchHeaderList(headers, n);
    for (const auto & n : f.globalNamespace.classes)
      fetchHeaderList(headers, n);
    for (const auto & n : f.globalNamespace.functions)
      fetchHeaderList(headers, n);
  }
  else if (node->is<gen::Namespace>())
  {
    gen::Namespace & ns = node->as<gen::Namespace>();
    for (const auto & n : ns.namespaces)
      fetchHeaderList(headers, n);
    for (const auto & n : ns.classes)
      fetchHeaderList(headers, n);
    for (const auto & n : ns.functions)
      fetchHeaderList(headers, n);
  }
  else if (node->is<gen::Class>())
  {
    gen::Class & cla = node->as<gen::Class>();
    for (const auto & n : cla.functions)
      fetchHeaderList(headers, n);
  }
  else if (node->is<gen::Function>())
  {
    gen::Function & func = node->as<gen::Function>();
    getHeader(headers, func.returnType);
    for (const auto & param : func.parameters)
      getHeader(headers, param);
  }
}

void Generator::getHeader(QSet<QString> & headers, QString type) const
{
  if (type.startsWith("const "))
    type.remove(0, 6);
  if (type.endsWith(" &"))
    type.chop(2);

  QString str = mDatabase["headers"].toObject()[type].toString();
  if (str.isEmpty() || str == currentFileName())
    return;
  headers.insert(str);
}

void Generator::registerHeader(const QString & type)
{
  QJsonObject headers = mDatabase["headers"].toObject();
  headers[type] = currentFileName();
  mDatabase["headers"] = headers;
}

void Generator::fetchGeneratedTypes(QStringList & types, gen::NodeRef node)
{
  if (node->checkState == Qt::Unchecked)
    return;

  if (node->is<gen::File>())
  {
    gen::File & f = node->as<gen::File>();
    for (const auto & n : f.globalNamespace.namespaces)
      fetchGeneratedTypes(types, n);
    for (const auto & n : f.globalNamespace.classes)
      fetchGeneratedTypes(types, n);
    for (const auto & n : f.globalNamespace.enums)
      fetchGeneratedTypes(types, n);
  }
  else if (node->is<gen::Namespace>())
  {
    gen::Namespace & ns = node->as<gen::Namespace>();
    mProcessingStack.push(node);
    for (const auto & n : ns.namespaces)
      fetchGeneratedTypes(types, n);
    for (const auto & n : ns.classes)
      fetchGeneratedTypes(types, n);
    for (const auto & n : ns.enums)
      fetchGeneratedTypes(types, n);
    mProcessingStack.pop();
  }
  else if (node->is<gen::Class>())
  {
    gen::Class & cla = node->as<gen::Class>();
    types << nameQualification() + cla.name;
    mProcessingStack.push(node);
    for (const auto & n : cla.enums)
      fetchGeneratedTypes(types, n);
    mProcessingStack.pop();
  }
  else if (node->is<gen::Enum>())
  {
    gen::Enum & e = node->as<gen::Enum>();
    types << nameQualification() + e.name;
  }
}

void Generator::generateHeader(gen::FileRef file)
{
  QFile header_file{ mCurrentFileName + ".h" };
  if (!header_file.open(QFileDevice::WriteOnly))
    return;

  QTextStream out{ &header_file };
  
  QStringList types;
  fetchGeneratedTypes(types, file);

  writeCopyrightMessage(out);
  out << endl;
  out << "#ifndef __CUSTOM_HEADER_GUARD__" << endl;
  out << "#define __CUSTOM_HEADER_GUARD__" << endl;
  out << endl;
  out << "#include \"yasl/binding/types.h\"" << endl;
  out << endl;
  out << "#include <__external_header__>" << endl;
  out << endl;
  out << "namespace binding {" << endl;

  for (const auto & t : types)
  {
    QString tt = t;
    tt.remove("::");
    out << "template<> struct make_type_t<" << t << "> { inline static script::Type get() { return script::Type::" << tt << "; } };" << endl;
  }

  out << "} // namespace binding" << endl;

  out << endl;
  out << "#endif // __CUSTOM_HEADER_GUARD__" << endl;

  header_file.close();
}

void Generator::writeCopyrightMessage(QTextStream & out)
{
  out << "// Copyright (C) 2018 Vincent Chambrin" << endl;
  out << "// This file is part of the Yasl project" << endl;
  out << "// For conditions of distribution and use, see copyright notice in LICENSE" << endl;
}

QString Generator::prefix() const
{
  if (mProcessingStack.isEmpty())
    return "";

  QString result = to_snake_case(mProcessingStack.first()->name);
  for (int i(1); i < mProcessingStack.size(); ++i)
    result += "_" + to_snake_case(mProcessingStack.at(i)->name);
  result += "_";
  return result;
}

QString Generator::enclosingEntity() const
{
  if (mProcessingStack.isEmpty() || mProcessingStack.top()->is<gen::Namespace>())
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
  if (mProcessingStack.isEmpty())
    return "ns";

  return to_snake_case(mProcessingStack.top()->name);
}

QString Generator::nameQualification() const
{
  if (mProcessingStack.isEmpty())
    return "";

  QString result = mProcessingStack.first()->name + "::";
  for (int i(1); i < mProcessingStack.size(); ++i)
    result += mProcessingStack.at(i)->name + "::";
  return result;
}

bool Generator::isMember() const
{
  return !mProcessingStack.isEmpty() && mProcessingStack.top()->is<gen::Class>();
}