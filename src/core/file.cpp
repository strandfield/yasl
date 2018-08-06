// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/file.h"

#include "yasl/binding/class.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/bytearray.h"

#include <script/classbuilder.h>
#include <script/engine.h>
#include <script/namespace.h>

void register_file_class(script::Namespace n)
{
  using namespace script;

  Class filedevice = n.engine()->getClass(script::Type::QFileDevice);

  Class file = n.Class("File").setId(Type::QFile).setBase(filedevice).get();

  binding::QClass<QFile> binder{ file, &QFile::staticMetaObject };

  /* Public functions */

  // bool copy(const QString &newName)
  binder.add_fun<bool, const QString &, &QFile::copy>("copy");
  // bool exists() const
  binder.add_fun<bool, &QFile::exists>("exists");
  // bool link(const QString &linkName)
  binder.add_fun<bool, const QString &, &QFile::link>("link");
  // bool open(FILE *fh, QIODevice::OpenMode mode, QFileDevice::FileHandleFlags handleFlags = DontCloseHandle)
  /// TODO !!!
  // bool open(int fd, QIODevice::OpenMode mode, QFileDevice::FileHandleFlags handleFlags = DontCloseHandle)
  binder.add_fun<bool, int, QIODevice::OpenMode, QFileDevice::FileHandleFlags, &QFile::open>("open");
  // bool remove()
  binder.add_fun<bool, &QFile::remove>("remove");
  // bool rename(const QString &newName)
  binder.add_fun<bool, const QString &, &QFile::rename>("rename");
  // void setFileName(const QString &name)
  binder.add_void_fun<const QString &, &QFile::setFileName>("setFileName");
  // QString symLinkTarget() const
  binder.add_fun<QString, &QFile::symLinkTarget>("symLinkTarget");


  /* Public static member functions */

  binding::Class<QFile> static_binder{ file };

  // static bool copy(const QString &fileName, const QString &newName)
  static_binder.add_static<bool, const QString &, const QString &, &QFile::copy>("copy");
  // static QString decodeName(const QByteArray &localFileName)
  static_binder.add_static<QString, const QByteArray &, &QFile::decodeName>("decodeName");
  // static QString decodeName(const char *localFileName)
  /// TODO !!!
  // static QByteArray encodeName(const QString &fileName)
  static_binder.add_static<QByteArray, const QString &, &QFile::encodeName>("encodeName");
  // static bool exists(const QString &fileName)
  static_binder.add_static<bool, const QString &, &QFile::exists>("exists");
  // static bool link(const QString &fileName, const QString &linkName)
  static_binder.add_static<bool, const QString &, const QString &, &QFile::link>("link");
  // static QFileDevice::Permissions permissions(const QString &fileName)
  static_binder.add_static<QFileDevice::Permissions, const QString &, &QFile::permissions>("permissions");
  // static bool remove(const QString &fileName)
  static_binder.add_static<bool, const QString &, &QFile::remove>("remove");
  // static bool rename(const QString &oldName, const QString &newName)
  static_binder.add_static<bool, const QString &, const QString &, &QFile::rename>("rename");
  // static bool resize(const QString &fileName, qint64 sz)
  static_binder.add_static<bool, const QString &, qint64, &QFile::resize>("resize");
  // static bool setPermissions(const QString &fileName, QFileDevice::Permissions permissions)
  static_binder.add_static<bool, const QString &, QFileDevice::Permissions, &QFile::setPermissions>("setPermissions");
  // static QString symLinkTarget(const QString &fileName)
  static_binder.add_static<QString, const QString &, &QFile::symLinkTarget>("symLinkTarget");


  /* MetaObject resgistration */

  n.engine()->registerQtType(&QFile::staticMetaObject, Type{ file.id() });
}
