// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "qfileinfo.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datetime.h"
#include "yasl/core/dir.h"
#include "yasl/core/file.h"

#include <script/classbuilder.h>

#include <QDebug>

static void register_file_info_class(script::Namespace ns)
{
  using namespace script;

  Class file_info = ns.Class("FileInfo").setId(script::Type::QFileInfo).get();

  binding::Class<QFileInfo> binder{ file_info };

  // QFileInfo();
  binder.ctors().add_default();
  // QFileInfo(const QString &);
  binder.ctors().add<const QString &>();
  // QFileInfo(const QFile &);
  binder.ctors().add<const QFile &>();
  // QFileInfo(const QDir &, const QString &);
  binder.ctors().add<const QDir &, const QString &>();
  // QFileInfo(const QFileInfo &);
  binder.ctors().add<const QFileInfo &>();
  // QFileInfo & operator=(const QFileInfo &);
  binder.operators().assign<const QFileInfo &>();
  // QFileInfo & operator=(QFileInfo &&);
  /// TODO binder.operators().assign<QFileInfo &&>();
  // void swap(QFileInfo &);
  binder.add_void_fun<QFileInfo &, &QFileInfo::swap>("swap");
  // bool operator==(const QFileInfo &) const;
  binder.operators().eq<const QFileInfo &>();
  // bool operator!=(const QFileInfo &) const;
  binder.operators().neq<const QFileInfo &>();
  // void setFile(const QString &);
  binder.add_void_fun<const QString &, &QFileInfo::setFile>("setFile");
  // void setFile(const QFile &);
  binder.add_void_fun<const QFile &, &QFileInfo::setFile>("setFile");
  // void setFile(const QDir &, const QString &);
  binder.add_void_fun<const QDir &, const QString &, &QFileInfo::setFile>("setFile");
  // bool exists() const;
  binder.add_fun<bool, &QFileInfo::exists>("exists");
  // static bool exists(const QString &);
  binder.add_static<bool, const QString &, &QFileInfo::exists>("exists");
  // void refresh();
  binder.add_void_fun<&QFileInfo::refresh>("refresh");
  // QString filePath() const;
  binder.add_fun<QString, &QFileInfo::filePath>("filePath");
  // QString absoluteFilePath() const;
  binder.add_fun<QString, &QFileInfo::absoluteFilePath>("absoluteFilePath");
  // QString canonicalFilePath() const;
  binder.add_fun<QString, &QFileInfo::canonicalFilePath>("canonicalFilePath");
  // QString fileName() const;
  binder.add_fun<QString, &QFileInfo::fileName>("fileName");
  // QString baseName() const;
  binder.add_fun<QString, &QFileInfo::baseName>("baseName");
  // QString completeBaseName() const;
  binder.add_fun<QString, &QFileInfo::completeBaseName>("completeBaseName");
  // QString suffix() const;
  binder.add_fun<QString, &QFileInfo::suffix>("suffix");
  // QString bundleName() const;
  binder.add_fun<QString, &QFileInfo::bundleName>("bundleName");
  // QString completeSuffix() const;
  binder.add_fun<QString, &QFileInfo::completeSuffix>("completeSuffix");
  // QString path() const;
  binder.add_fun<QString, &QFileInfo::path>("path");
  // QString absolutePath() const;
  binder.add_fun<QString, &QFileInfo::absolutePath>("absolutePath");
  // QString canonicalPath() const;
  binder.add_fun<QString, &QFileInfo::canonicalPath>("canonicalPath");
  // QDir dir() const;
  binder.add_fun<QDir, &QFileInfo::dir>("dir");
  // QDir absoluteDir() const;
  binder.add_fun<QDir, &QFileInfo::absoluteDir>("absoluteDir");
  // bool isReadable() const;
  binder.add_fun<bool, &QFileInfo::isReadable>("isReadable");
  // bool isWritable() const;
  binder.add_fun<bool, &QFileInfo::isWritable>("isWritable");
  // bool isExecutable() const;
  binder.add_fun<bool, &QFileInfo::isExecutable>("isExecutable");
  // bool isHidden() const;
  binder.add_fun<bool, &QFileInfo::isHidden>("isHidden");
  // bool isNativePath() const;
  binder.add_fun<bool, &QFileInfo::isNativePath>("isNativePath");
  // bool isRelative() const;
  binder.add_fun<bool, &QFileInfo::isRelative>("isRelative");
  // bool isAbsolute() const;
  binder.add_fun<bool, &QFileInfo::isAbsolute>("isAbsolute");
  // bool makeAbsolute();
  binder.add_fun<bool, &QFileInfo::makeAbsolute>("makeAbsolute");
  // bool isFile() const;
  binder.add_fun<bool, &QFileInfo::isFile>("isFile");
  // bool isDir() const;
  binder.add_fun<bool, &QFileInfo::isDir>("isDir");
  // bool isSymLink() const;
  binder.add_fun<bool, &QFileInfo::isSymLink>("isSymLink");
  // bool isRoot() const;
  binder.add_fun<bool, &QFileInfo::isRoot>("isRoot");
  // bool isBundle() const;
  binder.add_fun<bool, &QFileInfo::isBundle>("isBundle");
  // QString readLink() const;
  binder.add_fun<QString, &QFileInfo::readLink>("readLink");
  // QString symLinkTarget() const;
  binder.add_fun<QString, &QFileInfo::symLinkTarget>("symLinkTarget");
  // QString owner() const;
  binder.add_fun<QString, &QFileInfo::owner>("owner");
  // uint ownerId() const;
  binder.add_fun<uint, &QFileInfo::ownerId>("ownerId");
  // QString group() const;
  binder.add_fun<QString, &QFileInfo::group>("group");
  // uint groupId() const;
  binder.add_fun<uint, &QFileInfo::groupId>("groupId");
  // bool permission(QFile::Permissions) const;
  binder.add_fun<bool, QFile::Permissions, &QFileInfo::permission>("permission");
  // QFile::Permissions permissions() const;
  binder.add_fun<QFile::Permissions, &QFileInfo::permissions>("permissions");
  // qint64 size() const;
  binder.add_fun<qint64, &QFileInfo::size>("size");
  // QDateTime created() const;
  binder.add_fun<QDateTime, &QFileInfo::created>("created");
  // QDateTime birthTime() const;
  binder.add_fun<QDateTime, &QFileInfo::birthTime>("birthTime");
  // QDateTime metadataChangeTime() const;
  binder.add_fun<QDateTime, &QFileInfo::metadataChangeTime>("metadataChangeTime");
  // QDateTime lastModified() const;
  binder.add_fun<QDateTime, &QFileInfo::lastModified>("lastModified");
  // QDateTime lastRead() const;
  binder.add_fun<QDateTime, &QFileInfo::lastRead>("lastRead");
  // QDateTime fileTime(QFile::FileTime) const;
  binder.add_fun<QDateTime, QFile::FileTime, &QFileInfo::fileTime>("fileTime");
  // bool caching() const;
  binder.add_fun<bool, &QFileInfo::caching>("caching");
  // void setCaching(bool);
  binder.add_void_fun<bool, &QFileInfo::setCaching>("setCaching");
}

void register_fileinfo_file(script::Namespace root)
{
  using namespace script;

  register_file_info_class(root);
  binding::Namespace binder{ root };

  // void swap(QFileInfo &, QFileInfo &);
  binder.add_void_fun<QFileInfo &, QFileInfo &, &swap>("swap");
  // QDebug operator<<(QDebug, const QFileInfo &);
  binder.operators().left_shift<QDebug, QDebug, const QFileInfo &>();
}

