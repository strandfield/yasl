// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_META_HEADERFILE_H
#define YASL_META_HEADERFILE_H

#include <QFileInfo>
#include <QMap>
#include <QSet>

#include "project/type.h"

class QTextStream;

class HeaderFile
{
public:
  QFileInfo file;

  QString moduleName;
  QSet<QString> bindingIncludes;
  QSet<QString> generalIncludes;

  QMap<QString, Type> types;

public:
  HeaderFile();

  void write();

  static void writeCopyrightMessage(QTextStream & out);
  static void writeInclude(QTextStream & out, const QString & inc);

protected:
  QStringList generateBindingDefinitions();
};

#endif // YASL_META_HEADERFILE_H
