// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "cppparser.h"

#ifdef YASL_META_HAS_LIBCLANG

#include "project/class.h"
#include "project/enum.h"
#include "project/file.h"
#include "project/function.h"
#include "project/module.h"
#include "project/namespace.h"

#include <clang-c/Index.h>

#include <QDebug>
#include <QFileInfo>
#include <QQueue>

static QString gCurrentFile = QString{};
static QtVersion gCurrentVersion = QtVersion{};

static QString convert(CXString str)
{
  QString result = clang_getCString(str);
  clang_disposeString(str);
  return result;
}

static QString getCursorFile(CXCursor cursor)
{
  CXSourceLocation location = clang_getCursorLocation(cursor);
  CXFile file;
  unsigned int line, col, offset;
  clang_getSpellingLocation(location, &file, &line, &col, &offset);
  QString result = convert(clang_getFileName(file));
  result.replace("\\", "/");
  return result;
}


static QString getCursorSpelling(CXCursor cursor)
{
  return convert(clang_getCursorSpelling(cursor));
}

static bool is_forward_declaration(CXCursor cursor)
{
  return clang_equalCursors(clang_getCursorDefinition(cursor), clang_getNullCursor());
}

static CXChildVisitResult enum_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  Enum & enm = *(Enum*)client_data;

  CXCursorKind kind = clang_getCursorKind(cursor);
  if (kind == CXCursor_EnumConstantDecl)
  {
    const QString & n = getCursorSpelling(cursor);
    enm.enumerators.append(EnumeratorRef::create(n));
    enm.enumerators.back()->version = gCurrentVersion;
  }

  return CXChildVisit_Continue;
}

static CXChildVisitResult class_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  Class & cla = *(Class*)client_data;

  if (clang_getCXXAccessSpecifier(cursor) != CX_CXXPublic)
    return CXChildVisit_Continue;

  CXCursorKind kind = clang_getCursorKind(cursor);
  if (kind == CXCursor_CXXMethod || kind == CXCursor_FunctionDecl || kind == CXCursor_Constructor || kind == CXCursor_Destructor)
  {
    FunctionRef func = nullptr;
    if (kind == CXCursor_Constructor)
    {
      func = cla.add<Constructor>(getCursorSpelling(cursor), gCurrentVersion);
    }
    else if (kind == CXCursor_Destructor)
    {
      func = cla.add<Destructor>(getCursorSpelling(cursor), gCurrentVersion);
    }
    else
    {
      func = cla.add<Function>(getCursorSpelling(cursor), gCurrentVersion);
      func->isConst = clang_CXXMethod_isConst(cursor);
      func->isStatic = clang_CXXMethod_isStatic(cursor);
    }

    auto type = clang_getCursorType(cursor);

    if (kind != CXCursor_Constructor && kind != CXCursor_Destructor)
      func->returnType = convert(clang_getTypeSpelling(clang_getResultType(type)));

    const int num_args = clang_Cursor_getNumArguments(cursor);
    for (int i = 0; i < num_args; ++i)
    {
      auto arg_cursor = clang_Cursor_getArgument(cursor, i);
      auto arg_data_type = convert(clang_getTypeSpelling(clang_getArgType(type, i)));
      func->parameters.push_back(arg_data_type);
    }
  }
  else if (kind == CXCursor_ClassDecl || kind == CXCursor_StructDecl)
  {
    if (is_forward_declaration(cursor))
      return CXChildVisit_Continue;

    auto c = cla.get<Class>(getCursorSpelling(cursor), gCurrentVersion);
    clang_visitChildren(cursor, class_visitor, (void*)c.data());

    if (c->elements.isEmpty())
      cla.remove<Class>(c->name);
  }
  else if (clang_getCursorKind(cursor) == CXCursor_EnumDecl)
  {
    auto e = cla.get<Enum>(getCursorSpelling(cursor), gCurrentVersion);
    clang_visitChildren(cursor, enum_visitor, (void*)e.data());
  }

  return CXChildVisit_Continue;
}

static CXChildVisitResult namespace_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  if (getCursorFile(cursor) != gCurrentFile)
    return CXChildVisit_Continue;

  Namespace *ns = (Namespace*)client_data;

  if (clang_getCursorKind(cursor) == CXCursor_Namespace)
  {
    auto inner = ns->getNamespace(getCursorSpelling(cursor));
    clang_visitChildren(cursor, namespace_visitor, (void*)inner.data());
  }
  else if (clang_getCursorKind(cursor) == CXCursor_ClassDecl)
  {
    if (is_forward_declaration(cursor))
      return CXChildVisit_Continue;

    auto c = ns->get<Class>(getCursorSpelling(cursor), gCurrentVersion);
    clang_visitChildren(cursor, class_visitor, (void*)c.data());

    if (c->elements.isEmpty())
      ns->remove<Class>(c->name);
  }
  else if (clang_getCursorKind(cursor) == CXCursor_FunctionDecl)
  {
    auto func = ns->add<Function>(getCursorSpelling(cursor), gCurrentVersion);

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

    auto e = ns->get<Enum>(getCursorSpelling(cursor), gCurrentVersion);
    clang_visitChildren(cursor, enum_visitor, (void*)e.data());
  }

  return CXChildVisit_Continue;
}

static CXChildVisitResult translation_unit_visitor(CXCursor cursor, CXCursor parent, CXClientData client_data)
{
  return namespace_visitor(cursor, parent, client_data);
}

static void read_content(const FileRef & f, CXTranslationUnit & tu)
{
  CXCursor cursor = clang_getTranslationUnitCursor(tu);
  clang_visitChildren(cursor, translation_unit_visitor, (void*)f.data());
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

static void process_file(CppParser & parser, CXIndex index, const QString & path)
{
  qDebug() << "Processing: " << path;

  QFileInfo fileinfo{ path };

  auto file = FileRef::create(fileinfo.fileName());
  file->version = parser.version();

  CXTranslationUnit tu;
  const int options = CXTranslationUnit_SkipFunctionBodies;

  const char *command_line_args[128] = { nullptr };
  QList<QByteArray> argv;
  argv += {"-x", "c++", "-Xclang", "-ast-dump", "-fsyntax-only"};
  for (const QString & f : parser.includeDirectories())
  {
    argv.append("--include-directory");
    argv.append(f.toUtf8());
  }
  for (int i(0); i < argv.size(); ++i)
    command_line_args[i] = argv.at(i).data();

  CXErrorCode error = clang_parseTranslationUnit2(index, fileinfo.absoluteFilePath().toUtf8().data(), command_line_args, argv.size(), nullptr, 0, options, &tu);
  DisposeTranslationUnit guard{ tu };
  if (error)
    return;

  //clang_getInclusions(tu, include_visitor, nullptr);

  gCurrentFile = path;
  gCurrentVersion = parser.version();
  read_content(file, tu);

  parser.activeModule()->elements.append(file);
}


CppParser::CppParser(const ProjectRef & pro)
  : mProject(pro)
{

}

void CppParser::addIncludeDirectory(const QString & str)
{
  mIncludeDirectories.append(str);
}

void CppParser::parse(const QString & file, const ModuleRef & mo)
{
  mActiveModule = mo;

  CXIndex index = clang_createIndex(1, 1);

  process_file(*this, index, file);

  clang_disposeIndex(index);

  mActiveModule = nullptr;
}

#endif // YASL_META_HAS_LIBCLANG
