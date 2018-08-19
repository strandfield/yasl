// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "gen/headerfile.h"

#include <QFile>
#include <QTextStream>

#include <QDebug>

void Includes::insert(const QString & inc)
{
  data[inc] = true;
}

void Includes::remove(const QString & inc)
{
  data.remove(inc);
}

QStringList Includes::get() const
{
  QStringList result;
  for (auto it = data.begin(); it != data.end(); ++it)
  {
    if (it.value())
      result.append(it.key());
  }
  return result;
}

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

QByteArray HeaderFile::readall(const QString & filepath)
{
  QFile f{ filepath };
  if (!f.open(QIODevice::ReadOnly))
    return QByteArray{};

  QByteArray ret = f.readAll();
  f.close();
  return ret;
}

void HeaderFile::validate(const QFileInfo & finfo)
{
  if (!finfo.exists())
  {
    QFile::rename(finfo.absoluteFilePath() + "gen", finfo.absoluteFilePath());
    return;
  }

  QByteArray old = HeaderFile::readall(finfo.absoluteFilePath());
  QByteArray last = HeaderFile::readall(finfo.absoluteFilePath() + "gen");
  if (old == last)
  {
    QFile::remove(finfo.absoluteFilePath() + "gen");
    return;
  }
  
  QFile::remove(finfo.absoluteFilePath());
  QFile::rename(finfo.absoluteFilePath() + "gen", finfo.absoluteFilePath());
}

void HeaderFile::write()
{
  QFile f{ this->file.absoluteFilePath() + "gen" };
  if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
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

  for (const auto & inc : bindingIncludes.get())
    writeInclude(out, inc);
  out << endl;

  for (const auto inc : generalIncludes.get())
    writeInclude(out, inc);
  if(!generalIncludes.isEmpty())
    out << endl;

  for (const auto & l : bindings)
    out << l << endl;

  out << endl;

  out << "#endif // " << header_guard << endl;
  out.flush();
  f.close();

  validate(this->file);
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

    if (!t.tag.isEmpty())
    {
      if (t.tag == "qobject_tag")
      {
        bindingIncludes.insert("yasl/core/qobject-binding.h");
        out << ("template<> struct tag_resolver<" + t.name + "> { typedef qobject_tag tag_type; };");
      }
    }
  }
  out << "} // namespace binding";

  return out;
}