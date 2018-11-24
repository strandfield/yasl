// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/mimetype.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/core/mimetype.h"

#include <script/classbuilder.h>

static void register_mime_type_class(script::Namespace ns)
{
  using namespace script;

  Class mime_type = ns.newClass("MimeType").setId(script::Type::QMimeType).get();


  // QMimeType();
  bind::default_constructor<QMimeType>(mime_type).create();
  // QMimeType(const QMimeType &);
  bind::constructor<QMimeType, const QMimeType &>(mime_type).create();
  // QMimeType & operator=(const QMimeType &);
  bind::memop_assign<QMimeType, const QMimeType &>(mime_type);
  // QMimeType & operator=(QMimeType &&);
  bind::memop_assign<QMimeType, QMimeType &&>(mime_type);
  // void swap(QMimeType &);
  bind::void_member_function<QMimeType, QMimeType &, &QMimeType::swap>(mime_type, "swap").create();
  // QMimeType(const QMimeTypePrivate &);
  /// TODO: QMimeType(const QMimeTypePrivate &);
  // ~QMimeType();
  bind::destructor<QMimeType>(mime_type).create();
  // bool operator==(const QMimeType &) const;
  bind::memop_eq<QMimeType, const QMimeType &>(mime_type);
  // bool operator!=(const QMimeType &) const;
  bind::memop_neq<QMimeType, const QMimeType &>(mime_type);
  // bool isValid() const;
  bind::member_function<QMimeType, bool, &QMimeType::isValid>(mime_type, "isValid").create();
  // bool isDefault() const;
  bind::member_function<QMimeType, bool, &QMimeType::isDefault>(mime_type, "isDefault").create();
  // QString name() const;
  bind::member_function<QMimeType, QString, &QMimeType::name>(mime_type, "name").create();
  // QString comment() const;
  bind::member_function<QMimeType, QString, &QMimeType::comment>(mime_type, "comment").create();
  // QString genericIconName() const;
  bind::member_function<QMimeType, QString, &QMimeType::genericIconName>(mime_type, "genericIconName").create();
  // QString iconName() const;
  bind::member_function<QMimeType, QString, &QMimeType::iconName>(mime_type, "iconName").create();
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
  bind::member_function<QMimeType, QString, &QMimeType::preferredSuffix>(mime_type, "preferredSuffix").create();
  // bool inherits(const QString &) const;
  bind::member_function<QMimeType, bool, const QString &, &QMimeType::inherits>(mime_type, "inherits").create();
  // QString filterString() const;
  bind::member_function<QMimeType, QString, &QMimeType::filterString>(mime_type, "filterString").create();
}


void register_mimetype_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_mime_type_class(ns);

  // uint qHash(const QMimeType &, uint);
  bind::function<uint, const QMimeType &, uint, &qHash>(ns, "qHash").create();
  // void swap(QMimeType &, QMimeType &);
  bind::void_function<QMimeType &, QMimeType &, &swap>(ns, "swap").create();
  // QDebug operator<<(QDebug, const QMimeType &);
  /// TODO: QDebug operator<<(QDebug, const QMimeType &);
}

