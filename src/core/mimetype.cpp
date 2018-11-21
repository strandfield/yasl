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

  Class mime_type = ns.newClass("MimeType").setId(script::Type::QMimeType).get();

  binding::ClassBinder<QMimeType> binder{ mime_type };

  // QMimeType();
  binder.default_ctor().create();
  // QMimeType(const QMimeType &);
  binder.ctor<const QMimeType &>().create();
  // QMimeType & operator=(const QMimeType &);
  binder.operators().assign<const QMimeType &>();
  // QMimeType & operator=(QMimeType &&);
  binder.operators().assign<QMimeType &&>();
  // void swap(QMimeType &);
  binder.void_fun<QMimeType &, &QMimeType::swap>("swap").create();
  // QMimeType(const QMimeTypePrivate &);
  /// TODO: QMimeType(const QMimeTypePrivate &);
  // ~QMimeType();
  binder.dtor().create();
  // bool operator==(const QMimeType &) const;
  binder.operators().eq<const QMimeType &>();
  // bool operator!=(const QMimeType &) const;
  binder.operators().neq<const QMimeType &>();
  // bool isValid() const;
  binder.fun<bool, &QMimeType::isValid>("isValid").create();
  // bool isDefault() const;
  binder.fun<bool, &QMimeType::isDefault>("isDefault").create();
  // QString name() const;
  binder.fun<QString, &QMimeType::name>("name").create();
  // QString comment() const;
  binder.fun<QString, &QMimeType::comment>("comment").create();
  // QString genericIconName() const;
  binder.fun<QString, &QMimeType::genericIconName>("genericIconName").create();
  // QString iconName() const;
  binder.fun<QString, &QMimeType::iconName>("iconName").create();
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
  binder.fun<QString, &QMimeType::preferredSuffix>("preferredSuffix").create();
  // bool inherits(const QString &) const;
  binder.fun<bool, const QString &, &QMimeType::inherits>("inherits").create();
  // QString filterString() const;
  binder.fun<QString, &QMimeType::filterString>("filterString").create();
}


void register_mimetype_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_mime_type_class(ns);
  binding::Namespace binder{ ns };

  // uint qHash(const QMimeType &, uint);
  binder.fun<uint, const QMimeType &, uint, &qHash>("qHash").create();
  // void swap(QMimeType &, QMimeType &);
  binder.void_fun<QMimeType &, QMimeType &, &swap>("swap").create();
  // QDebug operator<<(QDebug, const QMimeType &);
  /// TODO: QDebug operator<<(QDebug, const QMimeType &);
}

