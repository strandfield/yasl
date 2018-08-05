// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "gen/headerfile.h"

#include <QFile>
#include <QTextStream>

#include <QDebug>

void HeaderFile::writeCopyrightMessage(QTextStream & out)
{
  out << "// Copyright (C) 2018 Vincent Chambrin" << endl;
  out << "// This file is part of the Yasl project" << endl;
  out << "// For conditions of distribution and use, see copyright notice in LICENSE" << endl;
}

void HeaderFile::write()
{
  QFile f{ this->file.absoluteFilePath() };
  if (!f.open(QIODevice::WriteOnly))
  {
    qDebug() << "Error while opening file " << this->file.absoluteFilePath() << " for writing";
    return;
  }

  QTextStream out{ &f };

  writeCopyrightMessage(out);
  out << endl;

  const QString header_guard = "YASL_" + moduleName.toUpper().replace(".", "_") + "_" + this->file.fileName().toUpper().remove(".H") + "_H";
  out << "#ifndef " << header_guard << endl;
  out << "#define " << header_guard << endl;

  out << endl;

  out << "#include \"yasl/binding/types.h\"" << endl;

  out << endl;

  for (const auto inc : generalIncludes)
  {
    if (inc.startsWith("<") || inc.startsWith("\""))
      out << "#include " << inc << endl;
    else
      out << "#include \"" << inc << "\"" << endl;
  }
  if(!generalIncludes.isEmpty())
    out << endl;

  if (!types.isEmpty())
  {
    out << "namespace binding {" << endl;
    for (const auto & t : types)
    {
      out << "template<> struct make_type_t<" << t.name << "> { inline static script::Type get() { return script::Type::" << t.id << "; } };" << endl;
      if(!t.starid.isEmpty())
        out << "template<> struct make_type_t<" << t.name << "*> { inline static script::Type get() { return script::Type::" << t.starid << "; } };" << endl;

    }
    out << "} // namespace binding" << endl;
    out << endl;
  }

  out << "#endif // " << header_guard << endl;
  out.flush();
  f.close();
}
