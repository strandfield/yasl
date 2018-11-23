// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/fileinfo.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/namespace.h"

#include "yasl/core/datetime.h"
#include "yasl/core/dir.h"
#include "yasl/core/file.h"
#include "yasl/core/fileinfo.h"

#include <script/classbuilder.h>

static void register_file_info_class(script::Namespace ns)
{
  using namespace script;

  Class file_info = ns.newClass("FileInfo").setId(script::Type::QFileInfo).get();


  // QFileInfo(QFileInfoPrivate *);
  /// TODO: QFileInfo(QFileInfoPrivate *);
  // QFileInfo();
  bind::default_constructor<QFileInfo>(file_info).create();
  // QFileInfo(const QString &);
  bind::constructor<QFileInfo, const QString &>(file_info).create();
  // QFileInfo(const QFile &);
  bind::constructor<QFileInfo, const QFile &>(file_info).create();
  // QFileInfo(const QDir &, const QString &);
  bind::constructor<QFileInfo, const QDir &, const QString &>(file_info).create();
  // QFileInfo(const QFileInfo &);
  bind::constructor<QFileInfo, const QFileInfo &>(file_info).create();
  // ~QFileInfo();
  bind::destructor<QFileInfo>(file_info).create();
  // QFileInfo & operator=(const QFileInfo &);
  bind::memop_assign<QFileInfo, const QFileInfo &>(file_info);
  // QFileInfo & operator=(QFileInfo &&);
  bind::memop_assign<QFileInfo, QFileInfo &&>(file_info);
  // void swap(QFileInfo &);
  bind::void_member_function<QFileInfo, QFileInfo &, &QFileInfo::swap>(file_info, "swap").create();
  // bool operator==(const QFileInfo &) const;
  bind::memop_eq<QFileInfo, const QFileInfo &>(file_info);
  // bool operator!=(const QFileInfo &) const;
  bind::memop_neq<QFileInfo, const QFileInfo &>(file_info);
  // void setFile(const QString &);
  bind::void_member_function<QFileInfo, const QString &, &QFileInfo::setFile>(file_info, "setFile").create();
  // void setFile(const QFile &);
  bind::void_member_function<QFileInfo, const QFile &, &QFileInfo::setFile>(file_info, "setFile").create();
  // void setFile(const QDir &, const QString &);
  bind::void_member_function<QFileInfo, const QDir &, const QString &, &QFileInfo::setFile>(file_info, "setFile").create();
  // bool exists() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::exists>(file_info, "exists").create();
  // static bool exists(const QString &);
  bind::static_member_function<QFileInfo, bool, const QString &, &QFileInfo::exists>(file_info, "exists").create();
  // void refresh();
  bind::void_member_function<QFileInfo, &QFileInfo::refresh>(file_info, "refresh").create();
  // QString filePath() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::filePath>(file_info, "filePath").create();
  // QString absoluteFilePath() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::absoluteFilePath>(file_info, "absoluteFilePath").create();
  // QString canonicalFilePath() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::canonicalFilePath>(file_info, "canonicalFilePath").create();
  // QString fileName() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::fileName>(file_info, "fileName").create();
  // QString baseName() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::baseName>(file_info, "baseName").create();
  // QString completeBaseName() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::completeBaseName>(file_info, "completeBaseName").create();
  // QString suffix() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::suffix>(file_info, "suffix").create();
  // QString bundleName() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::bundleName>(file_info, "bundleName").create();
  // QString completeSuffix() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::completeSuffix>(file_info, "completeSuffix").create();
  // QString path() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::path>(file_info, "path").create();
  // QString absolutePath() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::absolutePath>(file_info, "absolutePath").create();
  // QString canonicalPath() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::canonicalPath>(file_info, "canonicalPath").create();
  // QDir dir() const;
  bind::member_function<QFileInfo, QDir, &QFileInfo::dir>(file_info, "dir").create();
  // QDir absoluteDir() const;
  bind::member_function<QFileInfo, QDir, &QFileInfo::absoluteDir>(file_info, "absoluteDir").create();
  // bool isReadable() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isReadable>(file_info, "isReadable").create();
  // bool isWritable() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isWritable>(file_info, "isWritable").create();
  // bool isExecutable() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isExecutable>(file_info, "isExecutable").create();
  // bool isHidden() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isHidden>(file_info, "isHidden").create();
  // bool isNativePath() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isNativePath>(file_info, "isNativePath").create();
  // bool isRelative() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isRelative>(file_info, "isRelative").create();
  // bool isAbsolute() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isAbsolute>(file_info, "isAbsolute").create();
  // bool makeAbsolute();
  bind::member_function<QFileInfo, bool, &QFileInfo::makeAbsolute>(file_info, "makeAbsolute").create();
  // bool isFile() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isFile>(file_info, "isFile").create();
  // bool isDir() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isDir>(file_info, "isDir").create();
  // bool isSymLink() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isSymLink>(file_info, "isSymLink").create();
  // bool isRoot() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isRoot>(file_info, "isRoot").create();
  // bool isBundle() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::isBundle>(file_info, "isBundle").create();
  // QString readLink() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::readLink>(file_info, "readLink").create();
  // QString symLinkTarget() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::symLinkTarget>(file_info, "symLinkTarget").create();
  // QString owner() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::owner>(file_info, "owner").create();
  // uint ownerId() const;
  bind::member_function<QFileInfo, uint, &QFileInfo::ownerId>(file_info, "ownerId").create();
  // QString group() const;
  bind::member_function<QFileInfo, QString, &QFileInfo::group>(file_info, "group").create();
  // uint groupId() const;
  bind::member_function<QFileInfo, uint, &QFileInfo::groupId>(file_info, "groupId").create();
  // bool permission(QFile::Permissions) const;
  /// TODO: bool permission(QFile::Permissions) const;
  // QFile::Permissions permissions() const;
  /// TODO: QFile::Permissions permissions() const;
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // QDateTime created() const;
  bind::member_function<QFileInfo, QDateTime, &QFileInfo::created>(file_info, "created").create();
  // QDateTime lastModified() const;
  bind::member_function<QFileInfo, QDateTime, &QFileInfo::lastModified>(file_info, "lastModified").create();
  // QDateTime lastRead() const;
  bind::member_function<QFileInfo, QDateTime, &QFileInfo::lastRead>(file_info, "lastRead").create();
  // bool caching() const;
  bind::member_function<QFileInfo, bool, &QFileInfo::caching>(file_info, "caching").create();
  // void setCaching(bool);
  bind::void_member_function<QFileInfo, bool, &QFileInfo::setCaching>(file_info, "setCaching").create();
}


void register_fileinfo_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_file_info_class(ns);

  // void swap(QFileInfo &, QFileInfo &);
  bind::void_function<QFileInfo &, QFileInfo &, &swap>(ns, "swap").create();
  // QDebug operator<<(QDebug, const QFileInfo &);
  /// TODO: QDebug operator<<(QDebug, const QFileInfo &);
}

