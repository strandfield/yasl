// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_SOURCEFILE_H
#define YASL_META_SOURCEFILE_H

#include <QFileInfo>
#include <QSet>

class SourceFile
{
public:
  QFileInfo file;

  QString header;

  QSet<QString> bindingIncludes;
  QSet<QString> generalIncludes;
  QSet<QString> libscriptIncludes;

  QStringList functions;

public:
  
  void write();
};

#endif // YASL_META_SOURCEFILE_H
