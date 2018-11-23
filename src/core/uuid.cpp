// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/uuid.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/uuid.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_uuid_variant_enum(script::Class uuid)
{
  using namespace script;

  Enum variant = uuid.newEnum("Variant").setId(script::Type::QUuidVariant).get();

  variant.addValue("VarUnknown", QUuid::VarUnknown);
  variant.addValue("NCS", QUuid::NCS);
  variant.addValue("DCE", QUuid::DCE);
  variant.addValue("Microsoft", QUuid::Microsoft);
  variant.addValue("Reserved", QUuid::Reserved);
}


static void register_uuid_version_enum(script::Class uuid)
{
  using namespace script;

  Enum version = uuid.newEnum("Version").setId(script::Type::QUuidVersion).get();

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

  Class uuid = ns.newClass("Uuid").setId(script::Type::QUuid).get();

  register_uuid_variant_enum(uuid);
  register_uuid_version_enum(uuid);

  // QUuid();
  bind::default_constructor<QUuid>(uuid).create();
  // QUuid(const QUuid &);
  bind::constructor<QUuid, const QUuid &>(uuid).create();
  // ~QUuid();
  bind::destructor<QUuid>(uuid).create();
  // QUuid(uint, ushort, ushort, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar);
  /// TODO: QUuid(uint, ushort, ushort, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar);
  // QUuid(const QString &);
  bind::constructor<QUuid, const QString &>(uuid).create();
  // QUuid(const char *);
  /// TODO: QUuid(const char *);
  // QString toString() const;
  bind::member_function<QUuid, QString, &QUuid::toString>(uuid, "toString").create();
  // QUuid(const QByteArray &);
  bind::constructor<QUuid, const QByteArray &>(uuid).create();
  // QByteArray toByteArray() const;
  bind::member_function<QUuid, QByteArray, &QUuid::toByteArray>(uuid, "toByteArray").create();
  // QByteArray toRfc4122() const;
  bind::member_function<QUuid, QByteArray, &QUuid::toRfc4122>(uuid, "toRfc4122").create();
  // static QUuid fromRfc4122(const QByteArray &);
  bind::static_member_function<QUuid, QUuid, const QByteArray &, &QUuid::fromRfc4122>(uuid, "fromRfc4122").create();
  // bool isNull() const;
  bind::member_function<QUuid, bool, &QUuid::isNull>(uuid, "isNull").create();
  // QUuid & operator=(const QUuid &);
  bind::memop_assign<QUuid, const QUuid &>(uuid);
  // bool operator==(const QUuid &) const;
  bind::memop_eq<QUuid, const QUuid &>(uuid);
  // bool operator!=(const QUuid &) const;
  bind::memop_neq<QUuid, const QUuid &>(uuid);
  // bool operator<(const QUuid &) const;
  bind::memop_less<QUuid, const QUuid &>(uuid);
  // bool operator>(const QUuid &) const;
  bind::memop_greater<QUuid, const QUuid &>(uuid);
  // QUuid(const GUID &);
  /// TODO: QUuid(const GUID &);
  // QUuid & operator=(const GUID &);
  /// TODO: QUuid & operator=(const GUID &);
  // bool operator==(const GUID &) const;
  /// TODO: bool operator==(const GUID &) const;
  // bool operator!=(const GUID &) const;
  /// TODO: bool operator!=(const GUID &) const;
  // static QUuid createUuid();
  bind::static_member_function<QUuid, QUuid, &QUuid::createUuid>(uuid, "createUuid").create();
  // static QUuid createUuidV3(const QUuid &, const QByteArray &);
  bind::static_member_function<QUuid, QUuid, const QUuid &, const QByteArray &, &QUuid::createUuidV3>(uuid, "createUuidV3").create();
  // static QUuid createUuidV5(const QUuid &, const QByteArray &);
  bind::static_member_function<QUuid, QUuid, const QUuid &, const QByteArray &, &QUuid::createUuidV5>(uuid, "createUuidV5").create();
  // static QUuid createUuidV3(const QUuid &, const QString &);
  bind::static_member_function<QUuid, QUuid, const QUuid &, const QString &, &QUuid::createUuidV3>(uuid, "createUuidV3").create();
  // static QUuid createUuidV5(const QUuid &, const QString &);
  bind::static_member_function<QUuid, QUuid, const QUuid &, const QString &, &QUuid::createUuidV5>(uuid, "createUuidV5").create();
  // QUuid::Variant variant() const;
  bind::member_function<QUuid, QUuid::Variant, &QUuid::variant>(uuid, "variant").create();
  // QUuid::Version version() const;
  bind::member_function<QUuid, QUuid::Version, &QUuid::version>(uuid, "version").create();
}


void register_uuid_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_uuid_class(ns);

  // QDataStream & operator<<(QDataStream &, const QUuid &);
  bind::op_put_to<QDataStream &, const QUuid &>(ns);
  // QDataStream & operator>>(QDataStream &, QUuid &);
  bind::op_read_from<QDataStream &, QUuid &>(ns);
  // QDebug operator<<(QDebug, const QUuid &);
  /// TODO: QDebug operator<<(QDebug, const QUuid &);
  // uint qHash(const QUuid &, uint);
  bind::function<uint, const QUuid &, uint, &qHash>(ns, "qHash").create();
  // bool operator<=(const QUuid &, const QUuid &);
  bind::op_leq<const QUuid &, const QUuid &>(ns);
  // bool operator>=(const QUuid &, const QUuid &);
  bind::op_geq<const QUuid &, const QUuid &>(ns);
}

