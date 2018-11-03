// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/fileinfo.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datetime.h"
#include "yasl/core/dir.h"
#include "yasl/core/file.h"
#include "yasl/core/fileinfo.h"

#include <script/classbuilder.h>

static void register_file_info_class(script::Namespace ns)
{
  using namespace script;

  Class file_info = ns.Class("FileInfo").setId(script::Type::QFileInfo).get();

  binding::ClassBinder<QFileInfo> binder{ file_info };

  // QFileInfo(QFileInfoPrivate *);
  /// TODO: QFileInfo(QFileInfoPrivate *);
  // QFileInfo();
  binder.default_ctor().create();
  // QFileInfo(const QString &);
  binder.ctor<const QString &>().create();
  // QFileInfo(const QFile &);
  binder.ctor<const QFile &>().create();
  // QFileInfo(const QDir &, const QString &);
  binder.ctor<const QDir &, const QString &>().create();
  // QFileInfo(const QFileInfo &);
  binder.ctor<const QFileInfo &>().create();
  // ~QFileInfo();
  binder.dtor().create();
  // QFileInfo & operator=(const QFileInfo &);
  binder.operators().assign<const QFileInfo &>();
  // QFileInfo & operator=(QFileInfo &&);
  binder.operators().assign<QFileInfo &&>();
  // void swap(QFileInfo &);
  binder.void_fun<QFileInfo &, &QFileInfo::swap>("swap").create();
  // bool operator==(const QFileInfo &) const;
  binder.operators().eq<const QFileInfo &>();
  // bool operator!=(const QFileInfo &) const;
  binder.operators().neq<const QFileInfo &>();
  // void setFile(const QString &);
  binder.void_fun<const QString &, &QFileInfo::setFile>("setFile").create();
  // void setFile(const QFile &);
  binder.void_fun<const QFile &, &QFileInfo::setFile>("setFile").create();
  // void setFile(const QDir &, const QString &);
  binder.void_fun<const QDir &, const QString &, &QFileInfo::setFile>("setFile").create();
  // bool exists() const;
  binder.fun<bool, &QFileInfo::exists>("exists").create();
  // static bool exists(const QString &);
  binder.static_fun<bool, const QString &, &QFileInfo::exists>("exists").create();
  // void refresh();
  binder.void_fun<&QFileInfo::refresh>("refresh").create();
  // QString filePath() const;
  binder.fun<QString, &QFileInfo::filePath>("filePath").create();
  // QString absoluteFilePath() const;
  binder.fun<QString, &QFileInfo::absoluteFilePath>("absoluteFilePath").create();
  // QString canonicalFilePath() const;
  binder.fun<QString, &QFileInfo::canonicalFilePath>("canonicalFilePath").create();
  // QString fileName() const;
  binder.fun<QString, &QFileInfo::fileName>("fileName").create();
  // QString baseName() const;
  binder.fun<QString, &QFileInfo::baseName>("baseName").create();
  // QString completeBaseName() const;
  binder.fun<QString, &QFileInfo::completeBaseName>("completeBaseName").create();
  // QString suffix() const;
  binder.fun<QString, &QFileInfo::suffix>("suffix").create();
  // QString bundleName() const;
  binder.fun<QString, &QFileInfo::bundleName>("bundleName").create();
  // QString completeSuffix() const;
  binder.fun<QString, &QFileInfo::completeSuffix>("completeSuffix").create();
  // QString path() const;
  binder.fun<QString, &QFileInfo::path>("path").create();
  // QString absolutePath() const;
  binder.fun<QString, &QFileInfo::absolutePath>("absolutePath").create();
  // QString canonicalPath() const;
  binder.fun<QString, &QFileInfo::canonicalPath>("canonicalPath").create();
  // QDir dir() const;
  binder.fun<QDir, &QFileInfo::dir>("dir").create();
  // QDir absoluteDir() const;
  binder.fun<QDir, &QFileInfo::absoluteDir>("absoluteDir").create();
  // bool isReadable() const;
  binder.fun<bool, &QFileInfo::isReadable>("isReadable").create();
  // bool isWritable() const;
  binder.fun<bool, &QFileInfo::isWritable>("isWritable").create();
  // bool isExecutable() const;
  binder.fun<bool, &QFileInfo::isExecutable>("isExecutable").create();
  // bool isHidden() const;
  binder.fun<bool, &QFileInfo::isHidden>("isHidden").create();
  // bool isNativePath() const;
  binder.fun<bool, &QFileInfo::isNativePath>("isNativePath").create();
  // bool isRelative() const;
  binder.fun<bool, &QFileInfo::isRelative>("isRelative").create();
  // bool isAbsolute() const;
  binder.fun<bool, &QFileInfo::isAbsolute>("isAbsolute").create();
  // bool makeAbsolute();
  binder.fun<bool, &QFileInfo::makeAbsolute>("makeAbsolute").create();
  // bool isFile() const;
  binder.fun<bool, &QFileInfo::isFile>("isFile").create();
  // bool isDir() const;
  binder.fun<bool, &QFileInfo::isDir>("isDir").create();
  // bool isSymLink() const;
  binder.fun<bool, &QFileInfo::isSymLink>("isSymLink").create();
  // bool isRoot() const;
  binder.fun<bool, &QFileInfo::isRoot>("isRoot").create();
  // bool isBundle() const;
  binder.fun<bool, &QFileInfo::isBundle>("isBundle").create();
  // QString readLink() const;
  binder.fun<QString, &QFileInfo::readLink>("readLink").create();
  // QString symLinkTarget() const;
  binder.fun<QString, &QFileInfo::symLinkTarget>("symLinkTarget").create();
  // QString owner() const;
  binder.fun<QString, &QFileInfo::owner>("owner").create();
  // uint ownerId() const;
  binder.fun<uint, &QFileInfo::ownerId>("ownerId").create();
  // QString group() const;
  binder.fun<QString, &QFileInfo::group>("group").create();
  // uint groupId() const;
  binder.fun<uint, &QFileInfo::groupId>("groupId").create();
  // bool permission(QFile::Permissions) const;
  /// TODO: bool permission(QFile::Permissions) const;
  // QFile::Permissions permissions() const;
  /// TODO: QFile::Permissions permissions() const;
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // QDateTime created() const;
  binder.fun<QDateTime, &QFileInfo::created>("created").create();
  // QDateTime birthTime() const;
  binder.fun<QDateTime, &QFileInfo::birthTime>("birthTime").create();
  // QDateTime metadataChangeTime() const;
  binder.fun<QDateTime, &QFileInfo::metadataChangeTime>("metadataChangeTime").create();
  // QDateTime lastModified() const;
  binder.fun<QDateTime, &QFileInfo::lastModified>("lastModified").create();
  // QDateTime lastRead() const;
  binder.fun<QDateTime, &QFileInfo::lastRead>("lastRead").create();
  // QDateTime fileTime(QFile::FileTime) const;
  /// TODO: QDateTime fileTime(QFile::FileTime) const;
  // bool caching() const;
  binder.fun<bool, &QFileInfo::caching>("caching").create();
  // void setCaching(bool);
  binder.void_fun<bool, &QFileInfo::setCaching>("setCaching").create();
}


void register_fileinfo_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_file_info_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QFileInfo &, QFileInfo &);
  binder.void_fun<QFileInfo &, QFileInfo &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QFileInfo &);
  /// TODO: QDebug operator<<(QDebug, const QFileInfo &);
}

