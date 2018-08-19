// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/file.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/filedevice.h"
#include "yasl/core/iodevice.h"
#include "yasl/core/object.h"

#include <script/classbuilder.h>

static void register_file_class(script::Namespace ns)
{
  using namespace script;

  Class file = ns.Class("File").setId(script::Type::QFile)
    .setBase(script::Type::QFileDevice).get();

  binding::QClass<QFile> binder{ file, &QFile::staticMetaObject };

  // QFile();
  binder.ctors().add_default();
  // QFile(const QString &);
  binder.ctors().add<const QString &>();
  // QFile(QObject *);
  binder.ctors().add<QObject *>();
  // QFile(const QString &, QObject *);
  binder.ctors().add<const QString &, QObject *>();
  // ~QFile();
  binder.add_dtor();
  // QString fileName() const;
  binder.add_fun<QString, &QFile::fileName>("fileName");
  // void setFileName(const QString &);
  binder.add_void_fun<const QString &, &QFile::setFileName>("setFileName");
  // static QByteArray encodeName(const QString &);
  binder.add_static<QByteArray, const QString &, &QFile::encodeName>("encodeName");
  // static QString decodeName(const QByteArray &);
  binder.add_static<QString, const QByteArray &, &QFile::decodeName>("decodeName");
  // static QString decodeName(const char *);
  /// TODO: static QString decodeName(const char *);
  // bool exists() const;
  binder.add_fun<bool, &QFile::exists>("exists");
  // static bool exists(const QString &);
  binder.add_static<bool, const QString &, &QFile::exists>("exists");
  // QString readLink() const;
  binder.add_fun<QString, &QFile::readLink>("readLink");
  // static QString readLink(const QString &);
  binder.add_static<QString, const QString &, &QFile::readLink>("readLink");
  // QString symLinkTarget() const;
  binder.add_fun<QString, &QFile::symLinkTarget>("symLinkTarget");
  // static QString symLinkTarget(const QString &);
  binder.add_static<QString, const QString &, &QFile::symLinkTarget>("symLinkTarget");
  // bool remove();
  binder.add_fun<bool, &QFile::remove>("remove");
  // static bool remove(const QString &);
  binder.add_static<bool, const QString &, &QFile::remove>("remove");
  // bool rename(const QString &);
  binder.add_fun<bool, const QString &, &QFile::rename>("rename");
  // static bool rename(const QString &, const QString &);
  binder.add_static<bool, const QString &, const QString &, &QFile::rename>("rename");
  // bool link(const QString &);
  binder.add_fun<bool, const QString &, &QFile::link>("link");
  // static bool link(const QString &, const QString &);
  binder.add_static<bool, const QString &, const QString &, &QFile::link>("link");
  // bool copy(const QString &);
  binder.add_fun<bool, const QString &, &QFile::copy>("copy");
  // static bool copy(const QString &, const QString &);
  binder.add_static<bool, const QString &, const QString &, &QFile::copy>("copy");
  // bool open(QIODevice::OpenMode);
  binder.add_fun<bool, QIODevice::OpenMode, &QFile::open>("open");
  // bool open(FILE *, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  /// TODO: bool open(FILE *, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  // bool open(int, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  binder.add_fun<bool, int, QIODevice::OpenMode, QFileDevice::FileHandleFlags, &QFile::open>("open");
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // bool resize(qint64);
  /// TODO: bool resize(qint64);
  // static bool resize(const QString &, qint64);
  /// TODO: static bool resize(const QString &, qint64);
  // QFileDevice::Permissions permissions() const;
  binder.add_fun<QFileDevice::Permissions, &QFile::permissions>("permissions");
  // static QFileDevice::Permissions permissions(const QString &);
  binder.add_static<QFileDevice::Permissions, const QString &, &QFile::permissions>("permissions");
  // bool setPermissions(QFileDevice::Permissions);
  binder.add_fun<bool, QFileDevice::Permissions, &QFile::setPermissions>("setPermissions");
  // static bool setPermissions(const QString &, QFileDevice::Permissions);
  binder.add_static<bool, const QString &, QFileDevice::Permissions, &QFile::setPermissions>("setPermissions");

  file.engine()->registerQtType(&QFile::staticMetaObject, file.id());
}


void register_file_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_file_class(ns);
  binding::Namespace binder{ ns };

}

