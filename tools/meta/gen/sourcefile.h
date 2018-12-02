// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_SOURCEFILE_H
#define YASL_META_SOURCEFILE_H

#include "headerfile.h"

class SourceFile
{
public:
  QFileInfo file;

  QString header;

  Includes bindingIncludes;
  Includes generalIncludes;
  Includes libscriptIncludes;

  QStringList functions;

  QMap<QString, QtVersion> includesVersion;

public:
  SourceFile(const QMap<QString, QtVersion> & incsver);
  
  void write();
};

#endif // YASL_META_SOURCEFILE_H
