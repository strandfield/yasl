// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/timezone.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/enums.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/datetime.h"
#include "yasl/core/locale.h"
#include "yasl/core/timezone.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_time_zone_time_type_enum(script::Class time_zone)
{
  using namespace script;

  Enum time_type = time_zone.newEnum("TimeType").setId(script::Type::QTimeZoneTimeType).get();

  time_type.addValue("StandardTime", QTimeZone::StandardTime);
  time_type.addValue("DaylightTime", QTimeZone::DaylightTime);
  time_type.addValue("GenericTime", QTimeZone::GenericTime);
}


static void register_time_zone_name_type_enum(script::Class time_zone)
{
  using namespace script;

  Enum name_type = time_zone.newEnum("NameType").setId(script::Type::QTimeZoneNameType).get();

  name_type.addValue("DefaultName", QTimeZone::DefaultName);
  name_type.addValue("LongName", QTimeZone::LongName);
  name_type.addValue("ShortName", QTimeZone::ShortName);
  name_type.addValue("OffsetName", QTimeZone::OffsetName);
}


static void register_time_zone_class(script::Namespace ns)
{
  using namespace script;

  Class time_zone = ns.newClass("TimeZone").setId(script::Type::QTimeZone).get();

  register_time_zone_time_type_enum(time_zone);
  register_time_zone_name_type_enum(time_zone);

  // QTimeZone();
  bind::default_constructor<QTimeZone>(time_zone).create();
  // QTimeZone(const QByteArray &);
  bind::constructor<QTimeZone, const QByteArray &>(time_zone).create();
  // QTimeZone(int);
  bind::constructor<QTimeZone, int>(time_zone).create();
  // QTimeZone(const QByteArray &, int, const QString &, const QString &, QLocale::Country, const QString &);
  bind::constructor<QTimeZone, const QByteArray &, int, const QString &, const QString &, QLocale::Country, const QString &>(time_zone)
    .apply(bind::default_arguments(QString(), QLocale::AnyCountry)).create();
  // QTimeZone(const QTimeZone &);
  bind::constructor<QTimeZone, const QTimeZone &>(time_zone).create();
  // ~QTimeZone();
  bind::destructor<QTimeZone>(time_zone).create();
  // QTimeZone & operator=(const QTimeZone &);
  bind::memop_assign<QTimeZone, const QTimeZone &>(time_zone);
  // QTimeZone & operator=(QTimeZone &&);
  bind::memop_assign<QTimeZone, QTimeZone &&>(time_zone);
  // void swap(QTimeZone &);
  bind::void_member_function<QTimeZone, QTimeZone &, &QTimeZone::swap>(time_zone, "swap").create();
  // bool operator==(const QTimeZone &) const;
  bind::memop_eq<QTimeZone, const QTimeZone &>(time_zone);
  // bool operator!=(const QTimeZone &) const;
  bind::memop_neq<QTimeZone, const QTimeZone &>(time_zone);
  // bool isValid() const;
  bind::member_function<QTimeZone, bool, &QTimeZone::isValid>(time_zone, "isValid").create();
  // QByteArray id() const;
  bind::member_function<QTimeZone, QByteArray, &QTimeZone::id>(time_zone, "id").create();
  // QLocale::Country country() const;
  bind::member_function<QTimeZone, QLocale::Country, &QTimeZone::country>(time_zone, "country").create();
  // QString comment() const;
  bind::member_function<QTimeZone, QString, &QTimeZone::comment>(time_zone, "comment").create();
  // QString displayName(const QDateTime &, QTimeZone::NameType, const QLocale &) const;
  bind::member_function<QTimeZone, QString, const QDateTime &, QTimeZone::NameType, const QLocale &, &QTimeZone::displayName>(time_zone, "displayName")
    .apply(bind::default_arguments(QLocale(),  QTimeZone::DefaultName)).create();
  // QString displayName(QTimeZone::TimeType, QTimeZone::NameType, const QLocale &) const;
  bind::member_function<QTimeZone, QString, QTimeZone::TimeType, QTimeZone::NameType, const QLocale &, &QTimeZone::displayName>(time_zone, "displayName")
    .apply(bind::default_arguments(QLocale(),  QTimeZone::DefaultName)).create();
  // QString abbreviation(const QDateTime &) const;
  bind::member_function<QTimeZone, QString, const QDateTime &, &QTimeZone::abbreviation>(time_zone, "abbreviation").create();
  // int offsetFromUtc(const QDateTime &) const;
  bind::member_function<QTimeZone, int, const QDateTime &, &QTimeZone::offsetFromUtc>(time_zone, "offsetFromUtc").create();
  // int standardTimeOffset(const QDateTime &) const;
  bind::member_function<QTimeZone, int, const QDateTime &, &QTimeZone::standardTimeOffset>(time_zone, "standardTimeOffset").create();
  // int daylightTimeOffset(const QDateTime &) const;
  bind::member_function<QTimeZone, int, const QDateTime &, &QTimeZone::daylightTimeOffset>(time_zone, "daylightTimeOffset").create();
  // bool hasDaylightTime() const;
  bind::member_function<QTimeZone, bool, &QTimeZone::hasDaylightTime>(time_zone, "hasDaylightTime").create();
  // bool isDaylightTime(const QDateTime &) const;
  bind::member_function<QTimeZone, bool, const QDateTime &, &QTimeZone::isDaylightTime>(time_zone, "isDaylightTime").create();
  // QTimeZone::OffsetData offsetData(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData offsetData(const QDateTime &) const;
  // bool hasTransitions() const;
  bind::member_function<QTimeZone, bool, &QTimeZone::hasTransitions>(time_zone, "hasTransitions").create();
  // QTimeZone::OffsetData nextTransition(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData nextTransition(const QDateTime &) const;
  // QTimeZone::OffsetData previousTransition(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData previousTransition(const QDateTime &) const;
  // QTimeZone::OffsetDataList transitions(const QDateTime &, const QDateTime &) const;
  /// TODO: QTimeZone::OffsetDataList transitions(const QDateTime &, const QDateTime &) const;
  // static QByteArray systemTimeZoneId();
  bind::static_member_function<QTimeZone, QByteArray, &QTimeZone::systemTimeZoneId>(time_zone, "systemTimeZoneId").create();
  // static QTimeZone systemTimeZone();
  bind::static_member_function<QTimeZone, QTimeZone, &QTimeZone::systemTimeZone>(time_zone, "systemTimeZone").create();
  // static QTimeZone utc();
  bind::static_member_function<QTimeZone, QTimeZone, &QTimeZone::utc>(time_zone, "utc").create();
  // static bool isTimeZoneIdAvailable(const QByteArray &);
  bind::static_member_function<QTimeZone, bool, const QByteArray &, &QTimeZone::isTimeZoneIdAvailable>(time_zone, "isTimeZoneIdAvailable").create();
  // static QList<QByteArray> availableTimeZoneIds();
  bind::static_member_function<QTimeZone, QList<QByteArray>, &QTimeZone::availableTimeZoneIds>(time_zone, "availableTimeZoneIds").create();
  // static QList<QByteArray> availableTimeZoneIds(QLocale::Country);
  bind::static_member_function<QTimeZone, QList<QByteArray>, QLocale::Country, &QTimeZone::availableTimeZoneIds>(time_zone, "availableTimeZoneIds").create();
  // static QList<QByteArray> availableTimeZoneIds(int);
  bind::static_member_function<QTimeZone, QList<QByteArray>, int, &QTimeZone::availableTimeZoneIds>(time_zone, "availableTimeZoneIds").create();
  // static QByteArray ianaIdToWindowsId(const QByteArray &);
  bind::static_member_function<QTimeZone, QByteArray, const QByteArray &, &QTimeZone::ianaIdToWindowsId>(time_zone, "ianaIdToWindowsId").create();
  // static QByteArray windowsIdToDefaultIanaId(const QByteArray &);
  bind::static_member_function<QTimeZone, QByteArray, const QByteArray &, &QTimeZone::windowsIdToDefaultIanaId>(time_zone, "windowsIdToDefaultIanaId").create();
  // static QByteArray windowsIdToDefaultIanaId(const QByteArray &, QLocale::Country);
  bind::static_member_function<QTimeZone, QByteArray, const QByteArray &, QLocale::Country, &QTimeZone::windowsIdToDefaultIanaId>(time_zone, "windowsIdToDefaultIanaId").create();
  // static QList<QByteArray> windowsIdToIanaIds(const QByteArray &);
  bind::static_member_function<QTimeZone, QList<QByteArray>, const QByteArray &, &QTimeZone::windowsIdToIanaIds>(time_zone, "windowsIdToIanaIds").create();
  // static QList<QByteArray> windowsIdToIanaIds(const QByteArray &, QLocale::Country);
  bind::static_member_function<QTimeZone, QList<QByteArray>, const QByteArray &, QLocale::Country, &QTimeZone::windowsIdToIanaIds>(time_zone, "windowsIdToIanaIds").create();
}


void register_timezone_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_time_zone_class(ns);

  // void swap(QTimeZone &, QTimeZone &);
  bind::void_function<QTimeZone &, QTimeZone &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QTimeZone &);
  bind::op_put_to<QDataStream &, const QTimeZone &>(ns);
  // QDataStream & operator>>(QDataStream &, QTimeZone &);
  bind::op_read_from<QDataStream &, QTimeZone &>(ns);
  // QDebug operator<<(QDebug, const QTimeZone &);
  /// TODO: QDebug operator<<(QDebug, const QTimeZone &);
}

