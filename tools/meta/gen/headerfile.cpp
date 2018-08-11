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

void HeaderFile::writeInclude(QTextStream & out, const QString & inc)
{
  if (inc.startsWith("<") || inc.startsWith("\""))
    out << "#include " << inc << endl;
  else
    out << "#include \"" << inc << "\"" << endl;
}

HeaderFile::HeaderFile()
{
  bindingIncludes.insert("yasl/binding/types.h");
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

  QStringList bindings = generateBindingDefinitions();

  for (const auto & inc : bindingIncludes)
    writeInclude(out, inc);
  out << endl;

  for (const auto inc : generalIncludes)
    writeInclude(out, inc);
  if(!generalIncludes.isEmpty())
    out << endl;

  for (const auto & l : bindings)
    out << l << endl;

  out << endl;

  out << "#endif // " << header_guard << endl;
  out.flush();
  f.close();
}

QStringList HeaderFile::generateBindingDefinitions()
{
  if (types.empty())
    return QStringList{};

  QStringList out;
  out << "namespace binding {";
  for (const auto & t : types)
  {
    out << ("template<> struct make_type_t<" + t.name + "> { inline static script::Type get() { return script::Type::" + t.id + "; } };");
    if (!t.starid.isEmpty())
      out << ("template<> struct make_type_t<" + t.name + "*> { inline static script::Type get() { return script::Type::" + t.starid + "; } };");
    if (!t.ptrid.isEmpty())
    {
      bindingIncludes.insert("yasl/utils/ptr.h");

      if(!t.starid.isEmpty())
        out << ("template<> struct make_type_t<Ptr<" + t.name + "*>> { inline static script::Type get() { return script::Type::" + t.ptrid + "; } };");
      else
        out << ("template<> struct make_type_t<Ptr<" + t.name + ">> { inline static script::Type get() { return script::Type::" + t.ptrid + "; } };");
    }


    if (!t.storage.isEmpty())
    {
      bindingIncludes.insert("yasl/binding/values.h");

      out << ("template<> struct storage_type<" + t.id + "> { typedef " + t.storage + " type; };");
      out << ("template<> inline " + t.storage + " get<" + t.id + ">(const script::Value & val) { static_assert(false); }");
    }
  }
  out << "} // namespace binding";

  return out;
}