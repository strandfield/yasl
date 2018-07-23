// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/uuid.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_uuid_variant_enum(script::Class uuid)
{
  using namespace script;

  Enum variant = uuid.Enum("Variant").setId(script::Type::QUuidVariant).get();

  variant.addValue("DCE", QUuid::DCE);
  variant.addValue("Microsoft", QUuid::Microsoft);
  variant.addValue("NCS", QUuid::NCS);
  variant.addValue("Reserved", QUuid::Reserved);
  variant.addValue("VarUnknown", QUuid::VarUnknown);
}

static void register_uuid_version_enum(script::Class uuid)
{
  using namespace script;

  Enum version = uuid.Enum("Version").setId(script::Type::QUuidVersion).get();

  version.addValue("EmbeddedPOSIX", QUuid::EmbeddedPOSIX);
  version.addValue("Md5", QUuid::Md5);
  version.addValue("Name", QUuid::Name);
  version.addValue("Random", QUuid::Random);
  version.addValue("Sha1", QUuid::Sha1);
  version.addValue("Time", QUuid::Time);
  version.addValue("VerUnknown", QUuid::VerUnknown);
}

static void register_uuid_class(script::Namespace ns)
{
  using namespace script;

  Class uuid = ns.Class("Uuid").setId(script::Type::QUuid).get();

  register_uuid_variant_enum(uuid);
  register_uuid_version_enum(uuid);
  binding::Class<QUuid> binder{ uuid };

  // ~QUuid();
  binder.add_dtor();
  // QUuid();
  binder.ctors().add_default();
  // QUuid(uint, ushort, ushort, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar);
  /// TODO: binder.ctors().add<uint, ushort, ushort, uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar>();
  // QUuid(const QString &);
  binder.ctors().add<const QString &>();
  // static QUuid fromString(QStringView);
  binder.add_static<QUuid, QStringView, &QUuid::fromString>("fromString");
  // static QUuid fromString(QLatin1String);
  binder.add_static<QUuid, QLatin1String, &QUuid::fromString>("fromString");
  // QUuid(const char *);
  binder.ctors().add<const char *>();
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
  // bool operator==(const QUuid &) const;
  binder.operators().eq<const QUuid &>();
  // bool operator!=(const QUuid &) const;
  binder.operators().neq<const QUuid &>();
  // bool operator<(const QUuid &) const;
  binder.operators().less<const QUuid &>();
  // bool operator>(const QUuid &) const;
  binder.operators().greater<const QUuid &>();
  // QUuid(const GUID &);
  binder.ctors().add<const GUID &>();
  // QUuid & operator=(const GUID &);
  binder.operators().assign<const GUID &>();
  // bool operator==(const GUID &) const;
  binder.operators().eq<const GUID &>();
  // bool operator!=(const GUID &) const;
  binder.operators().neq<const GUID &>();
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

void register_uuid_file(script::Namespace root)
{
  using namespace script;

  register_uuid_class(root);
  binding::Namespace binder{ root };

  // QDataStream & operator<<(QDataStream &, const QUuid &);
  binder.operators().put_to<QDataStream &, const QUuid &>();
  // QDataStream & operator>>(QDataStream &, QUuid &);
  binder.operators().read_from<QDataStream &, QUuid &>();
  // QDebug operator<<(QDebug, const QUuid &);
  binder.operators().left_shift<QDebug, QDebug, const QUuid &>();
  // uint qHash(const QUuid &, uint);
  binder.add_fun<uint, const QUuid &, uint, &qHash>("qHash");
  // bool operator<=(const QUuid &, const QUuid &);
  binder.operators().leq<const QUuid &, const QUuid &>();
  // bool operator>=(const QUuid &, const QUuid &);
  binder.operators().geq<const QUuid &, const QUuid &>();
}

