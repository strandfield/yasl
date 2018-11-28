// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_CPPPARSER_H
#define YASL_META_CPPPARSER_H

#ifdef YASL_META_HAS_LIBCLANG

#include "project.h"

#include "project/module.h"

class CppParser
{
private:
  QStringList mIncludeDirectories;
  ProjectRef mProject;
  ModuleRef mActiveModule;
public:
  CppParser(const ProjectRef & pro);

  void addIncludeDirectory(const QString & str);
  inline void setIncludeDirectories(const QStringList & incdirs) { mIncludeDirectories = incdirs; }
  inline const QStringList & includeDirectories() const { return mIncludeDirectories; }

  inline const ProjectRef & project() const { return mProject; }
  inline const ModuleRef & activeModule() const { return mActiveModule; }

  void parse(const QString & file, const ModuleRef & mo);
};

#endif // YASL_META_HAS_LIBCLANG

#endif // YASL_META_CPPPARSER_H
