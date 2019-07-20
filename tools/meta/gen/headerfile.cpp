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

HeaderFile::HeaderFile(const QMap<QString, QtVersion> & incsver)
  : includesVersion(incsver)
{
  bindingIncludes.insert("yasl/common/types.h");
}

void HeaderFile::writeCopyrightMessage(QTextStream & out)
{
  out << "// Copyright (C) 2018 Vincent Chambrin" << endl;
  out << "// This file is part of the Yasl project" << endl;
  out << "// For conditions of distribution and use, see copyright notice in LICENSE" << endl;
}

void HeaderFile::writeInclude(QTextStream & out, const QString & inc, const QMap<QString, QtVersion> & versions)
{
  if (inc.startsWith("<"))
  {
    QString file = inc.mid(1);
    file.chop(1);

    QtVersion v = versions.value(file, QtVersion{});

    if (!v.isNull())
      out << "#if " << versionCheck(v) << endl;

    out << "#include " << inc << endl;

    if (!v.isNull())
      out << "#endif" << endl;
  }
  else if (inc.startsWith("\""))
  {
    out << "#include " << inc << endl;
  }
  else
  {
    out << "#include \"" << inc << "\"" << endl;
  }
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

QString HeaderFile::versionCheck(QtVersion v)
{
  return QString("(QT_VERSION >= QT_VERSION_CHECK(%1, %2, %3))").arg(int(v.major)).arg(int(v.minor)).arg(int(v.patch));
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
    writeInclude(out, inc, includesVersion);
  out << endl;

  for (const auto inc : generalIncludes.get())
    writeInclude(out, inc, includesVersion);
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
  out << "namespace script {";
  for (const auto & t : types)
  {
    if (!t.version.isNull())
      out << QString("#if %1").arg(versionCheck(t.version));

    out << ("template<> struct make_type_helper<" + t.name + "> { inline static script::Type get() { return script::Type::" + t.id + "; } };");

    if (!t.tag.isEmpty())
    {
      if (t.tag == "qobject_tag")
      {
        bindingIncludes.insert("yasl/common/qobject-values.h");
        out << ("namespace details { template<> struct tag_resolver<" + t.name + "> { typedef qobject_tag tag_type; }; }");
      }
      else if (t.tag == "qevent_tag")
      {
        bindingIncludes.insert("yasl/core/qevent-binding.h");
        out << ("namespace details { template<> struct tag_resolver<" + t.name + "> { typedef qevent_tag tag_type; }; }");
      }
      else
      {
        out << ("namespace details { template<> struct tag_resolver<" + t.name + "> { typedef " + t.tag + " tag_type; }; }");
      }
    }

    if (!t.version.isNull())
      out << QString("#endif");
  }
  out << "} // namespace script";

  return out;
}