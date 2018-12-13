// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/mimetype.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/core/mimetype.h"
#include "yasl/core/string.h"

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
  bind::member_function<QMimeType, QStringList, &QMimeType::globPatterns>(mime_type, "globPatterns").create();
  // QStringList parentMimeTypes() const;
  bind::member_function<QMimeType, QStringList, &QMimeType::parentMimeTypes>(mime_type, "parentMimeTypes").create();
  // QStringList allAncestors() const;
  bind::member_function<QMimeType, QStringList, &QMimeType::allAncestors>(mime_type, "allAncestors").create();
  // QStringList aliases() const;
  bind::member_function<QMimeType, QStringList, &QMimeType::aliases>(mime_type, "aliases").create();
  // QStringList suffixes() const;
  bind::member_function<QMimeType, QStringList, &QMimeType::suffixes>(mime_type, "suffixes").create();
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

#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // uint qHash(const QMimeType &, uint);
  bind::function<uint, const QMimeType &, uint, &qHash>(ns, "qHash").create();
#endif
  // QDebug operator<<(QDebug, const QMimeType &);
  /// TODO: QDebug operator<<(QDebug, const QMimeType &);
}
