// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "project.h"

#include <clang-c/Index.h>

#include <QByteArray>
#include <QFileInfo>
#include <QQueue>

#include <QDebug>

namespace gen
{

Node::Node(const QString & n, Qt::CheckState c)
  : checkState(c)
  , name(n)
{

}

EnumConstant::EnumConstant(const QString & n)
  : Node(n)
{

}

Enum::Enum(const QString & n)
  : Node(n)
{

}

Function::Function(const QString & n)
  : Node(n)
  , isExplicit(false)
  , isStatic(false)
  , isConst(false)
  , isDeleted(false)
{

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

Constructor::Constructor(const QString & n)
  : Function(n)
{

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

Class::Class(const QString & n)
  : Node(n)
  , derivedFromQObject(false)
{

}

bool Class::isEmpty() const
{
  return this->enums.empty() && this->functions.empty();
}

ConstructorRef Class::addConstructor(const QString & name)
{
  auto result = ConstructorRef::create(name);
  functions.append(result);
  return result;
}

FunctionRef Class::addFunction(const QString & name)
{
  auto result = FunctionRef::create(name);
  functions.append(result);
  return result;
}

EnumRef Class::getEnum(const QString & name)
{
  if (!enums.contains(name))
    enums[name] = EnumRef::create(name);
  return enums[name];
}


Namespace::Namespace()
  : Node("")
{

}

Namespace::Namespace(const QString & n)
  : Node(n)
{

}

QSharedPointer<Namespace> Namespace::getNamespace(const QString & name)
{
  if (!namespaces.contains(name))
    namespaces[name] = NamespaceRef::create(name);
  return namespaces[name];
}

ClassRef Namespace::getClass(const QString & name)
{
  if (!classes.contains(name))
    classes[name] = ClassRef::create(name);
  return classes[name];
}

EnumRef Namespace::getEnum(const QString & name)
{
  if (!enums.contains(name))
    enums[name] = EnumRef::create(name);
  return enums[name];
}

FunctionRef Namespace::addFunction(const QString & name)
{
  auto result = FunctionRef::create(name);
  functions.append(result);
  return result;
}

File::File(const QString & p)
  : Node("")
  , path(p)
{
  QFileInfo info{ p };
  this->name = info.fileName();
}

} // namespace gen


static QString gCurrentFile = QString{};

QString convert(CXString str)
{
  QString result = clang_getCString(str);
  clang_disposeString(str);
  return result;
}

QString getCursorFile(CXCursor cursor)
{
  CXSourceLocation location = clang_getCursorLocation(cursor);
  CXFile file;
  unsigned int line, col, offset;
  clang_getSpellingLocation(location, &file, &line, &col, &offset);
  QString result = convert(clang_getFileName(file));
  return result;
}


QString getCursorSpelling(CXCursor cursor)
{
  return convert(clang_getCursorSpelling(cursor));
}

static bool is_forward_declaration(CXCursor cursor)
{
  return clang_equalCursors(clang_getCursorDefinition(cursor), clang_getNullCursor());
}

static CXChildVisitResult get_base_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  if (clang_getCXXAccessSpecifier(cursor) != CX_CXXPublic)
    return CXChildVisit_Continue;

  CXCursorKind kind = clang_getCursorKind(cursor);
  if (kind != CXCursor_CXXBaseSpecifier)
    return CXChildVisit_Continue;

  QQueue<CXCursor> & result = *(QQueue<CXCursor>*)client_data;
  result.append(cursor);

  return CXChildVisit_Continue;
}

static void get_bases(CXCursor class_decl, QQueue<CXCursor> & result)
{
  clang_visitChildren(class_decl, get_base_visitor, (void*)&result);
}

static bool is_derived_from_qobject(CXCursor class_decl)
{
  QQueue<CXCursor> bases;
  get_bases(class_decl, bases);
  while (!bases.empty())
  {
    CXType type = clang_getCursorType(bases.takeFirst());
    QString type_name = convert(clang_getTypeSpelling(type));
    if (type_name == "QObject")
      return true;

    get_bases(clang_getTypeDeclaration(type), bases);
  }

  return false;
}


static CXChildVisitResult enum_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  gen::Enum & enm = *(gen::Enum*)client_data;

  CXCursorKind kind = clang_getCursorKind(cursor);
  if (kind == CXCursor_EnumConstantDecl)
  {
    const QString & n = getCursorSpelling(cursor);
    enm.values[n] = gen::EnumConstantRef::create(n);
  }

  return CXChildVisit_Continue;
}

static CXChildVisitResult class_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  gen::Class & cla = *(gen::Class*)client_data;

  if (clang_getCXXAccessSpecifier(cursor) != CX_CXXPublic)
    return CXChildVisit_Continue;

  CXCursorKind kind = clang_getCursorKind(cursor);
  if (kind == CXCursor_CXXMethod || kind == CXCursor_FunctionDecl || kind == CXCursor_Constructor)
  {
    gen::FunctionRef func = nullptr;
    if (kind == CXCursor_Constructor)
    {
      func = cla.addConstructor(getCursorSpelling(cursor));
    }
    else
    {
      func = cla.addFunction(getCursorSpelling(cursor));
      func->isConst = clang_CXXMethod_isConst(cursor);
      func->isStatic = clang_CXXMethod_isStatic(cursor);
    }

    auto type = clang_getCursorType(cursor);
    func->returnType = convert(clang_getTypeSpelling(clang_getResultType(type)));

    const int num_args = clang_Cursor_getNumArguments(cursor);
    for (int i = 0; i < num_args; ++i)
    {
      auto arg_cursor = clang_Cursor_getArgument(cursor, i);
      auto arg_data_type = convert(clang_getTypeSpelling(clang_getArgType(type, i)));
      func->parameters.push_back(arg_data_type);
    }
  }
  else if (clang_getCursorKind(cursor) == CXCursor_EnumDecl)
  {
    auto e = cla.getEnum(getCursorSpelling(cursor));
    clang_visitChildren(cursor, enum_visitor, (void*)e.data());
  }

  return CXChildVisit_Continue;
}

static CXChildVisitResult namespace_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  if (getCursorFile(cursor) != gCurrentFile)
    return CXChildVisit_Continue;

  gen::Namespace & ns = *(gen::Namespace*)client_data;

  if (clang_getCursorKind(cursor) == CXCursor_Namespace)
  {
    auto inner = ns.getNamespace(getCursorSpelling(cursor));
    clang_visitChildren(cursor, namespace_visitor, (void*)inner.data());
  }
  else if (clang_getCursorKind(cursor) == CXCursor_ClassDecl)
  {
    if (is_forward_declaration(cursor))
      return CXChildVisit_Continue;

    auto c = ns.getClass(getCursorSpelling(cursor));
    c->derivedFromQObject = is_derived_from_qobject(cursor);
    clang_visitChildren(cursor, class_visitor, (void*)c.data());

    if (c->isEmpty())
      ns.classes.remove(c->name);
  }
  else if (clang_getCursorKind(cursor) == CXCursor_FunctionDecl)
  {
    auto func = ns.addFunction(getCursorSpelling(cursor));

    auto type = clang_getCursorType(cursor);
    func->returnType = convert(clang_getTypeSpelling(clang_getResultType(type)));

    const int num_args = clang_Cursor_getNumArguments(cursor);
    for (int i = 0; i < num_args; ++i)
    {
      auto arg_cursor = clang_Cursor_getArgument(cursor, i);
      auto arg_data_type = convert(clang_getTypeSpelling(clang_getArgType(type, i)));
      func->parameters.push_back(arg_data_type);
    }
  }
  else if (clang_getCursorKind(cursor) == CXCursor_EnumDecl)
  {
    if (is_forward_declaration(cursor))
      return CXChildVisit_Continue;

    auto e = ns.getEnum(getCursorSpelling(cursor));
    clang_visitChildren(cursor, enum_visitor, (void*)e.data());
  }

  return CXChildVisit_Continue;
}

static CXChildVisitResult translation_unit_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  return namespace_visitor(cursor, parent, client_data);
}

void read_content(gen::Namespace & ns, CXTranslationUnit & tu)
{
  CXCursor cursor = clang_getTranslationUnitCursor(tu);
  clang_visitChildren(cursor, translation_unit_visitor, (void*)&ns);
}

struct DisposeTranslationUnit
{
  CXTranslationUnit & translation_unit;
  DisposeTranslationUnit(CXTranslationUnit & tu)
    : translation_unit(tu) { }
  ~DisposeTranslationUnit() {
    clang_disposeTranslationUnit(translation_unit);
  }
};

static void include_visitor(CXFile included_file, CXSourceLocation *inclusion_stack, unsigned include_len, CXClientData client_data)
{
  qDebug() << "#include " << convert(clang_getFileName(included_file));
}

void process_file(Project & project, CXIndex index, const QString & path)
{
  qDebug() << "Processing: " << path;

  auto file = gen::FileRef::create(path);

  CXTranslationUnit tu;
  const int options = CXTranslationUnit_SkipFunctionBodies;

  const char *command_line_args[128] = { nullptr };
  QList<QByteArray> argv;
  argv += {"-x", "c++", "-Xclang", "-ast-dump", "-fsyntax-only"};
  for (const QString & f : project.includeDirs)
  {
    argv.append("--include-directory");
    argv.append(f.toUtf8());
  }
  for (int i(0); i < argv.size(); ++i)
    command_line_args[i] = argv.at(i).data();

  file->error = clang_parseTranslationUnit2(index, file->path.toUtf8().data(), command_line_args, argv.size(), nullptr, 0, options, &tu);
  DisposeTranslationUnit guard{ tu };
  if (file->error)
    return;

  //clang_getInclusions(tu, include_visitor, nullptr);

  gCurrentFile = path;
  read_content(file->globalNamespace, tu);

  project.files.push_back(file);
}

void Project::addFiles(const QStringList & files)
{
  qDebug() << "Clang version: " << convert(clang_getClangVersion());

  CXIndex index = clang_createIndex(1, 1);

  for (const auto & f : files)
    process_file(*this, index, f);

  clang_disposeIndex(index);
}
