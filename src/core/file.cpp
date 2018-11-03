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
  binder.ctors().default_ctor().create();
  // QFile(const QString &);
  binder.ctors().ctor<const QString &>().create();
  // QFile(QObject *);
  binder.ctors().ctor<QObject *>().create();
  // QFile(const QString &, QObject *);
  binder.ctors().ctor<const QString &, QObject *>().create();
  // ~QFile();
  binder.add_dtor();
  // QString fileName() const;
  binder.fun<QString, &QFile::fileName>("fileName").create();
  // void setFileName(const QString &);
  binder.void_fun<const QString &, &QFile::setFileName>("setFileName").create();
  // static QByteArray encodeName(const QString &);
  binder.static_fun<QByteArray, const QString &, &QFile::encodeName>("encodeName").create();
  // static QString decodeName(const QByteArray &);
  binder.static_fun<QString, const QByteArray &, &QFile::decodeName>("decodeName").create();
  // static QString decodeName(const char *);
  /// TODO: static QString decodeName(const char *);
  // bool exists() const;
  binder.fun<bool, &QFile::exists>("exists").create();
  // static bool exists(const QString &);
  binder.static_fun<bool, const QString &, &QFile::exists>("exists").create();
  // QString readLink() const;
  binder.fun<QString, &QFile::readLink>("readLink").create();
  // static QString readLink(const QString &);
  binder.static_fun<QString, const QString &, &QFile::readLink>("readLink").create();
  // QString symLinkTarget() const;
  binder.fun<QString, &QFile::symLinkTarget>("symLinkTarget").create();
  // static QString symLinkTarget(const QString &);
  binder.static_fun<QString, const QString &, &QFile::symLinkTarget>("symLinkTarget").create();
  // bool remove();
  binder.fun<bool, &QFile::remove>("remove").create();
  // static bool remove(const QString &);
  binder.static_fun<bool, const QString &, &QFile::remove>("remove").create();
  // bool rename(const QString &);
  binder.fun<bool, const QString &, &QFile::rename>("rename").create();
  // static bool rename(const QString &, const QString &);
  binder.static_fun<bool, const QString &, const QString &, &QFile::rename>("rename").create();
  // bool link(const QString &);
  binder.fun<bool, const QString &, &QFile::link>("link").create();
  // static bool link(const QString &, const QString &);
  binder.static_fun<bool, const QString &, const QString &, &QFile::link>("link").create();
  // bool copy(const QString &);
  binder.fun<bool, const QString &, &QFile::copy>("copy").create();
  // static bool copy(const QString &, const QString &);
  binder.static_fun<bool, const QString &, const QString &, &QFile::copy>("copy").create();
  // bool open(QIODevice::OpenMode);
  binder.fun<bool, QIODevice::OpenMode, &QFile::open>("open").create();
  // bool open(FILE *, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  /// TODO: bool open(FILE *, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  // bool open(int, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  binder.fun<bool, int, QIODevice::OpenMode, QFileDevice::FileHandleFlags, &QFile::open>("open").create();
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // bool resize(qint64);
  /// TODO: bool resize(qint64);
  // static bool resize(const QString &, qint64);
  /// TODO: static bool resize(const QString &, qint64);
  // QFileDevice::Permissions permissions() const;
  binder.fun<QFileDevice::Permissions, &QFile::permissions>("permissions").create();
  // static QFileDevice::Permissions permissions(const QString &);
  binder.static_fun<QFileDevice::Permissions, const QString &, &QFile::permissions>("permissions").create();
  // bool setPermissions(QFileDevice::Permissions);
  binder.fun<bool, QFileDevice::Permissions, &QFile::setPermissions>("setPermissions").create();
  // static bool setPermissions(const QString &, QFileDevice::Permissions);
  binder.static_fun<bool, const QString &, QFileDevice::Permissions, &QFile::setPermissions>("setPermissions").create();

  file.engine()->registerQtType(&QFile::staticMetaObject, file.id());
}


void register_file_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_file_class(ns);
  binding::Namespace binder{ ns };

}

