// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/timezone.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datetime.h"
#include "yasl/core/locale.h"
#include "yasl/core/timezone.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_time_zone_time_type_enum(script::Class time_zone)
{
  using namespace script;

  Enum time_type = time_zone.Enum("TimeType").setId(script::Type::QTimeZoneTimeType).get();

  time_type.addValue("StandardTime", QTimeZone::StandardTime);
  time_type.addValue("DaylightTime", QTimeZone::DaylightTime);
  time_type.addValue("GenericTime", QTimeZone::GenericTime);
}


static void register_time_zone_name_type_enum(script::Class time_zone)
{
  using namespace script;

  Enum name_type = time_zone.Enum("NameType").setId(script::Type::QTimeZoneNameType).get();

  name_type.addValue("DefaultName", QTimeZone::DefaultName);
  name_type.addValue("LongName", QTimeZone::LongName);
  name_type.addValue("ShortName", QTimeZone::ShortName);
  name_type.addValue("OffsetName", QTimeZone::OffsetName);
}


static void register_time_zone_class(script::Namespace ns)
{
  using namespace script;

  Class time_zone = ns.Class("TimeZone").setId(script::Type::QTimeZone).get();

  register_time_zone_time_type_enum(time_zone);
  register_time_zone_name_type_enum(time_zone);
  binding::Class<QTimeZone> binder{ time_zone };

  // QTimeZone();
  binder.ctors().add_default();
  // QTimeZone(const QByteArray &);
  binder.ctors().add<const QByteArray &>();
  // QTimeZone(int);
  binder.ctors().add<int>();
  // QTimeZone(const QByteArray &, int, const QString &, const QString &, QLocale::Country, const QString &);
  binder.ctors().add<const QByteArray &, int, const QString &, const QString &, QLocale::Country, const QString &>();
  // QTimeZone(const QTimeZone &);
  binder.ctors().add<const QTimeZone &>();
  // ~QTimeZone();
  binder.add_dtor();
  // QTimeZone & operator=(const QTimeZone &);
  binder.operators().assign<const QTimeZone &>();
  // QTimeZone & operator=(QTimeZone &&);
  binder.operators().assign<QTimeZone &&>();
  // void swap(QTimeZone &);
  binder.add_void_fun<QTimeZone &, &QTimeZone::swap>("swap");
  // bool operator==(const QTimeZone &) const;
  binder.operators().eq<const QTimeZone &>();
  // bool operator!=(const QTimeZone &) const;
  binder.operators().neq<const QTimeZone &>();
  // bool isValid() const;
  binder.add_fun<bool, &QTimeZone::isValid>("isValid");
  // QByteArray id() const;
  binder.add_fun<QByteArray, &QTimeZone::id>("id");
  // QLocale::Country country() const;
  binder.add_fun<QLocale::Country, &QTimeZone::country>("country");
  // QString comment() const;
  binder.add_fun<QString, &QTimeZone::comment>("comment");
  // QString displayName(const QDateTime &, QTimeZone::NameType, const QLocale &) const;
  binder.add_fun<QString, const QDateTime &, QTimeZone::NameType, const QLocale &, &QTimeZone::displayName>("displayName");
  // QString displayName(QTimeZone::TimeType, QTimeZone::NameType, const QLocale &) const;
  binder.add_fun<QString, QTimeZone::TimeType, QTimeZone::NameType, const QLocale &, &QTimeZone::displayName>("displayName");
  // QString abbreviation(const QDateTime &) const;
  binder.add_fun<QString, const QDateTime &, &QTimeZone::abbreviation>("abbreviation");
  // int offsetFromUtc(const QDateTime &) const;
  binder.add_fun<int, const QDateTime &, &QTimeZone::offsetFromUtc>("offsetFromUtc");
  // int standardTimeOffset(const QDateTime &) const;
  binder.add_fun<int, const QDateTime &, &QTimeZone::standardTimeOffset>("standardTimeOffset");
  // int daylightTimeOffset(const QDateTime &) const;
  binder.add_fun<int, const QDateTime &, &QTimeZone::daylightTimeOffset>("daylightTimeOffset");
  // bool hasDaylightTime() const;
  binder.add_fun<bool, &QTimeZone::hasDaylightTime>("hasDaylightTime");
  // bool isDaylightTime(const QDateTime &) const;
  binder.add_fun<bool, const QDateTime &, &QTimeZone::isDaylightTime>("isDaylightTime");
  // QTimeZone::OffsetData offsetData(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData offsetData(const QDateTime &) const;
  // bool hasTransitions() const;
  binder.add_fun<bool, &QTimeZone::hasTransitions>("hasTransitions");
  // QTimeZone::OffsetData nextTransition(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData nextTransition(const QDateTime &) const;
  // QTimeZone::OffsetData previousTransition(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData previousTransition(const QDateTime &) const;
  // QTimeZone::OffsetDataList transitions(const QDateTime &, const QDateTime &) const;
  /// TODO: QTimeZone::OffsetDataList transitions(const QDateTime &, const QDateTime &) const;
  // static QByteArray systemTimeZoneId();
  binder.add_static<QByteArray, &QTimeZone::systemTimeZoneId>("systemTimeZoneId");
  // static QTimeZone systemTimeZone();
  binder.add_static<QTimeZone, &QTimeZone::systemTimeZone>("systemTimeZone");
  // static QTimeZone utc();
  binder.add_static<QTimeZone, &QTimeZone::utc>("utc");
  // static bool isTimeZoneIdAvailable(const QByteArray &);
  binder.add_static<bool, const QByteArray &, &QTimeZone::isTimeZoneIdAvailable>("isTimeZoneIdAvailable");
  // static QList<QByteArray> availableTimeZoneIds();
  binder.add_static<QList<QByteArray>, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds");
  // static QList<QByteArray> availableTimeZoneIds(QLocale::Country);
  binder.add_static<QList<QByteArray>, QLocale::Country, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds");
  // static QList<QByteArray> availableTimeZoneIds(int);
  binder.add_static<QList<QByteArray>, int, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds");
  // static QByteArray ianaIdToWindowsId(const QByteArray &);
  binder.add_static<QByteArray, const QByteArray &, &QTimeZone::ianaIdToWindowsId>("ianaIdToWindowsId");
  // static QByteArray windowsIdToDefaultIanaId(const QByteArray &);
  binder.add_static<QByteArray, const QByteArray &, &QTimeZone::windowsIdToDefaultIanaId>("windowsIdToDefaultIanaId");
  // static QByteArray windowsIdToDefaultIanaId(const QByteArray &, QLocale::Country);
  binder.add_static<QByteArray, const QByteArray &, QLocale::Country, &QTimeZone::windowsIdToDefaultIanaId>("windowsIdToDefaultIanaId");
  // static QList<QByteArray> windowsIdToIanaIds(const QByteArray &);
  binder.add_static<QList<QByteArray>, const QByteArray &, &QTimeZone::windowsIdToIanaIds>("windowsIdToIanaIds");
  // static QList<QByteArray> windowsIdToIanaIds(const QByteArray &, QLocale::Country);
  binder.add_static<QList<QByteArray>, const QByteArray &, QLocale::Country, &QTimeZone::windowsIdToIanaIds>("windowsIdToIanaIds");
}


void register_timezone_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_time_zone_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QTimeZone &, QTimeZone &);
  binder.add_void_fun<QTimeZone &, QTimeZone &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QTimeZone &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QTimeZone &);
  // QDataStream & operator>>(QDataStream &, QTimeZone &);
  /// TODO: QDataStream & operator>>(QDataStream &, QTimeZone &);
  // QDebug operator<<(QDebug, const QTimeZone &);
  /// TODO: QDebug operator<<(QDebug, const QTimeZone &);
}

