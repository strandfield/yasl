// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/file.h"

#include "yasl/binding2/namespace.h"
#include "yasl/binding2/qclass.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/filedevice.h"
#include "yasl/core/iodevice.h"
#include "yasl/core/object.h"

#include <script/classbuilder.h>

static void register_file_class(script::Namespace ns)
{
  using namespace script;

  Class file = ns.newClass("File").setId(script::Type::QFile)
    .setBase(script::Type::QFileDevice).get();


  // QFile();
  bind::default_constructor<QFile>(file).create();
  // QFile(const QString &);
  bind::constructor<QFile, const QString &>(file).create();
  // QFile(QObject *);
  bind::constructor<QFile, QObject *>(file).create();
  // QFile(const QString &, QObject *);
  bind::constructor<QFile, const QString &, QObject *>(file).create();
  // ~QFile();
  bind::destructor<QFile>(file).create();
  // QString fileName() const;
  bind::member_function<QFile, QString, &QFile::fileName>(file, "fileName").create();
  // void setFileName(const QString &);
  bind::void_member_function<QFile, const QString &, &QFile::setFileName>(file, "setFileName").create();
  // static QByteArray encodeName(const QString &);
  bind::static_member_function<QFile, QByteArray, const QString &, &QFile::encodeName>(file, "encodeName").create();
  // static QString decodeName(const QByteArray &);
  bind::static_member_function<QFile, QString, const QByteArray &, &QFile::decodeName>(file, "decodeName").create();
  // static QString decodeName(const char *);
  /// TODO: static QString decodeName(const char *);
  // bool exists() const;
  bind::member_function<QFile, bool, &QFile::exists>(file, "exists").create();
  // static bool exists(const QString &);
  bind::static_member_function<QFile, bool, const QString &, &QFile::exists>(file, "exists").create();
  // QString readLink() const;
  bind::member_function<QFile, QString, &QFile::readLink>(file, "readLink").create();
  // static QString readLink(const QString &);
  bind::static_member_function<QFile, QString, const QString &, &QFile::readLink>(file, "readLink").create();
  // QString symLinkTarget() const;
  bind::member_function<QFile, QString, &QFile::symLinkTarget>(file, "symLinkTarget").create();
  // static QString symLinkTarget(const QString &);
  bind::static_member_function<QFile, QString, const QString &, &QFile::symLinkTarget>(file, "symLinkTarget").create();
  // bool remove();
  bind::member_function<QFile, bool, &QFile::remove>(file, "remove").create();
  // static bool remove(const QString &);
  bind::static_member_function<QFile, bool, const QString &, &QFile::remove>(file, "remove").create();
  // bool rename(const QString &);
  bind::member_function<QFile, bool, const QString &, &QFile::rename>(file, "rename").create();
  // static bool rename(const QString &, const QString &);
  bind::static_member_function<QFile, bool, const QString &, const QString &, &QFile::rename>(file, "rename").create();
  // bool link(const QString &);
  bind::member_function<QFile, bool, const QString &, &QFile::link>(file, "link").create();
  // static bool link(const QString &, const QString &);
  bind::static_member_function<QFile, bool, const QString &, const QString &, &QFile::link>(file, "link").create();
  // bool copy(const QString &);
  bind::member_function<QFile, bool, const QString &, &QFile::copy>(file, "copy").create();
  // static bool copy(const QString &, const QString &);
  bind::static_member_function<QFile, bool, const QString &, const QString &, &QFile::copy>(file, "copy").create();
  // bool open(QIODevice::OpenMode);
  bind::member_function<QFile, bool, QIODevice::OpenMode, &QFile::open>(file, "open").create();
  // bool open(FILE *, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  /// TODO: bool open(FILE *, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  // bool open(int, QIODevice::OpenMode, QFileDevice::FileHandleFlags);
  bind::member_function<QFile, bool, int, QIODevice::OpenMode, QFileDevice::FileHandleFlags, &QFile::open>(file, "open").create();
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // bool resize(qint64);
  /// TODO: bool resize(qint64);
  // static bool resize(const QString &, qint64);
  /// TODO: static bool resize(const QString &, qint64);
  // QFileDevice::Permissions permissions() const;
  bind::member_function<QFile, QFileDevice::Permissions, &QFile::permissions>(file, "permissions").create();
  // static QFileDevice::Permissions permissions(const QString &);
  bind::static_member_function<QFile, QFileDevice::Permissions, const QString &, &QFile::permissions>(file, "permissions").create();
  // bool setPermissions(QFileDevice::Permissions);
  bind::member_function<QFile, bool, QFileDevice::Permissions, &QFile::setPermissions>(file, "setPermissions").create();
  // static bool setPermissions(const QString &, QFileDevice::Permissions);
  bind::static_member_function<QFile, bool, const QString &, QFileDevice::Permissions, &QFile::setPermissions>(file, "setPermissions").create();

  bind::link(file, &QFile::staticMetaObject);
}


void register_file_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_file_class(ns);

}

