// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/uuid.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/uuid.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_uuid_variant_enum(script::Class uuid)
{
  using namespace script;

  Enum variant = uuid.Enum("Variant").setId(script::Type::QUuidVariant).get();

  variant.addValue("VarUnknown", QUuid::VarUnknown);
  variant.addValue("NCS", QUuid::NCS);
  variant.addValue("DCE", QUuid::DCE);
  variant.addValue("Microsoft", QUuid::Microsoft);
  variant.addValue("Reserved", QUuid::Reserved);
}


static void register_uuid_version_enum(script::Class uuid)
{
  using namespace script;

  Enum version = uuid.Enum("Version").setId(script::Type::QUuidVersion).get();

  version.addValue("VerUnknown", QUuid::VerUnknown);
  version.addValue("Time", QUuid::Time);
  version.addValue("EmbeddedPOSIX", QUuid::EmbeddedPOSIX);
  version.addValue("Md5", QUuid::Md5);
  version.addValue("Name", QUuid::Name);
  version.addValue("Random", QUuid::Random);
  version.addValue("Sha1", QUuid::Sha1);
}


static void register_uuid_class(script::Namespace ns)
{
  using namespace script;

  Class uuid = ns.Class("Uuid").setId(script::Type::QUuid).get();

  register_uuid_variant_enum(uuid);
  register_uuid_version_enum(uuid);
  binding::Class<QUuid> binder{ uuid };

  // QUuid();
  binder.ctors().add_default();
  // QUuid(const QUuid &);
  binder.ctors().add<const QUuid &>();
  // ~QUuid();
  binder.add_dtor();
  // QUuid(uint, ushort, ushort, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar);
  /// TODO: QUuid(uint, ushort, ushort, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar);
  // QUuid(const QString &);
  binder.ctors().add<const QString &>();
  // static QUuid fromString(QStringView);
  /// TODO: static QUuid fromString(QStringView);
  // static QUuid fromString(QLatin1String);
  /// TODO: static QUuid fromString(QLatin1String);
  // QUuid(const char *);
  /// TODO: QUuid(const char *);
  // QString toString() const;
  binder.add_fun<QString, &QUuid::toString>("toString");
  // QUuid(const QByteArray &);
  binder.ctors().add<const QByteArray &>();
  // QByteArray toByteArray() const;
  binder.add_fun<QByteArray, &QUuid::toByteArray>("toByteArray");
  // QByteArray toRfc4122() const;
  binder.add_fun<QByteArray, &QUuid::toRfc4122>("toRfc4122");
  // static QUuid fromRfc4122(const QByteArray &);
  binder.add_static<QUuid, const QByteArray &, &QUuid::fromRfc4122>("fromRfc4122");
  // bool isNull() const;
  binder.add_fun<bool, &QUuid::isNull>("isNull");
  // QUuid & operator=(const QUuid &);
  binder.operators().assign<const QUuid &>();
  // bool operator==(const QUuid &) const;
  binder.operators().eq<const QUuid &>();
  // bool operator!=(const QUuid &) const;
  binder.operators().neq<const QUuid &>();
  // bool operator<(const QUuid &) const;
  binder.operators().less<const QUuid &>();
  // bool operator>(const QUuid &) const;
  binder.operators().greater<const QUuid &>();
  // QUuid(const GUID &);
  /// TODO: QUuid(const GUID &);
  // QUuid & operator=(const GUID &);
  /// TODO: QUuid & operator=(const GUID &);
  // bool operator==(const GUID &) const;
  /// TODO: bool operator==(const GUID &) const;
  // bool operator!=(const GUID &) const;
  /// TODO: bool operator!=(const GUID &) const;
  // static QUuid createUuid();
  binder.add_static<QUuid, &QUuid::createUuid>("createUuid");
  // static QUuid createUuidV3(const QUuid &, const QByteArray &);
  binder.add_static<QUuid, const QUuid &, const QByteArray &, &QUuid::createUuidV3>("createUuidV3");
  // static QUuid createUuidV5(const QUuid &, const QByteArray &);
  binder.add_static<QUuid, const QUuid &, const QByteArray &, &QUuid::createUuidV5>("createUuidV5");
  // static QUuid createUuidV3(const QUuid &, const QString &);
  binder.add_static<QUuid, const QUuid &, const QString &, &QUuid::createUuidV3>("createUuidV3");
  // static QUuid createUuidV5(const QUuid &, const QString &);
  binder.add_static<QUuid, const QUuid &, const QString &, &QUuid::createUuidV5>("createUuidV5");
  // QUuid::Variant variant() const;
  binder.add_fun<QUuid::Variant, &QUuid::variant>("variant");
  // QUuid::Version version() const;
  binder.add_fun<QUuid::Version, &QUuid::version>("version");
}


void register_uuid_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_uuid_class(ns);
  binding::Namespace binder{ ns };

  // QDataStream & operator<<(QDataStream &, const QUuid &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QUuid &);
  // QDataStream & operator>>(QDataStream &, QUuid &);
  /// TODO: QDataStream & operator>>(QDataStream &, QUuid &);
  // QDebug operator<<(QDebug, const QUuid &);
  /// TODO: QDebug operator<<(QDebug, const QUuid &);
  // uint qHash(const QUuid &, uint);
  binder.add_fun<uint, const QUuid &, uint, &qHash>("qHash");
  // bool operator<=(const QUuid &, const QUuid &);
  binder.operators().leq<const QUuid &, const QUuid &>();
  // bool operator>=(const QUuid &, const QUuid &);
  binder.operators().geq<const QUuid &, const QUuid &>();
}

