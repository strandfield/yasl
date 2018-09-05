// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/mimetype.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/mimetype.h"

#include <script/classbuilder.h>

static void register_mime_type_class(script::Namespace ns)
{
  using namespace script;

  Class mime_type = ns.Class("MimeType").setId(script::Type::QMimeType).get();

  binding::Class<QMimeType> binder{ mime_type };

  // QMimeType();
  binder.ctors().add_default();
  // QMimeType(const QMimeType &);
  binder.ctors().add<const QMimeType &>();
  // QMimeType & operator=(const QMimeType &);
  binder.operators().assign<const QMimeType &>();
  // QMimeType & operator=(QMimeType &&);
  binder.operators().assign<QMimeType &&>();
  // void swap(QMimeType &);
  binder.add_void_fun<QMimeType &, &QMimeType::swap>("swap");
  // QMimeType(const QMimeTypePrivate &);
  /// TODO: QMimeType(const QMimeTypePrivate &);
  // ~QMimeType();
  binder.add_dtor();
  // bool operator==(const QMimeType &) const;
  binder.operators().eq<const QMimeType &>();
  // bool operator!=(const QMimeType &) const;
  binder.operators().neq<const QMimeType &>();
  // bool isValid() const;
  binder.add_fun<bool, &QMimeType::isValid>("isValid");
  // bool isDefault() const;
  binder.add_fun<bool, &QMimeType::isDefault>("isDefault");
  // QString name() const;
  binder.add_fun<QString, &QMimeType::name>("name");
  // QString comment() const;
  binder.add_fun<QString, &QMimeType::comment>("comment");
  // QString genericIconName() const;
  binder.add_fun<QString, &QMimeType::genericIconName>("genericIconName");
  // QString iconName() const;
  binder.add_fun<QString, &QMimeType::iconName>("iconName");
  // QStringList globPatterns() const;
  /// TODO: QStringList globPatterns() const;
  // QStringList parentMimeTypes() const;
  /// TODO: QStringList parentMimeTypes() const;
  // QStringList allAncestors() const;
  /// TODO: QStringList allAncestors() const;
  // QStringList aliases() const;
  /// TODO: QStringList aliases() const;
  // QStringList suffixes() const;
  /// TODO: QStringList suffixes() const;
  // QString preferredSuffix() const;
  binder.add_fun<QString, &QMimeType::preferredSuffix>("preferredSuffix");
  // bool inherits(const QString &) const;
  binder.add_fun<bool, const QString &, &QMimeType::inherits>("inherits");
  // QString filterString() const;
  binder.add_fun<QString, &QMimeType::filterString>("filterString");
}


void register_mimetype_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_mime_type_class(ns);
  binding::Namespace binder{ ns };

  // uint qHash(const QMimeType &, uint);
  binder.add_fun<uint, const QMimeType &, uint, &qHash>("qHash");
  // void swap(QMimeType &, QMimeType &);
  binder.add_void_fun<QMimeType &, QMimeType &, &swap>("swap");
  // QDebug operator<<(QDebug, const QMimeType &);
  /// TODO: QDebug operator<<(QDebug, const QMimeType &);
}

