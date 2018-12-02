// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "gen/sourcefile.h"

#include "gen/headerfile.h"

#include <QFile>
#include <QTextStream>

#include <QDebug>

SourceFile::SourceFile(const QMap<QString, QtVersion> & incsver)
  : includesVersion(incsver)
{

}

void SourceFile::write()
{
  QFile f{ this->file.absoluteFilePath() + "gen" };
  if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    qDebug() << "Error while opening file " << this->file.absoluteFilePath() << " for writing";
    return;
  }

  QTextStream out{ &f };

  HeaderFile::writeCopyrightMessage(out);
  out << endl;

  if (!header.isEmpty())
    HeaderFile::writeInclude(out, header, includesVersion);

  out << endl;

  for (const auto inc : bindingIncludes.get())
  {
    if (inc.startsWith("<") || inc.startsWith("\""))
      out << "#include " << inc << endl;
    else
      out << "#include \"" << inc << "\"" << endl;
  }
  if (!bindingIncludes.isEmpty())
    out << endl;

  for (const auto inc : generalIncludes.get())
  {
    if (inc.startsWith("<") || inc.startsWith("\""))
      out << "#include " << inc << endl;
    else
      out << "#include \"" << inc << "\"" << endl;
  }
  if (!generalIncludes.isEmpty())
    out << endl;


  for (const auto inc : libscriptIncludes.get())
  {
    if (inc.startsWith("<") || inc.startsWith("\""))
      out << "#include " << inc << endl;
    else
      out << "#include \"" << inc << "\"" << endl;
  }
  if (!libscriptIncludes.isEmpty())
    out << endl;

  for (const auto & f : functions)
  {
    out << f << endl;
  }

  out.flush();
  f.close();

  HeaderFile::validate(this->file);
}
