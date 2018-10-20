// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/timezone.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

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
  binder.ctors().ctor<const QByteArray &>().create();
  // QTimeZone(int);
  binder.ctors().ctor<int>().create();
  // QTimeZone(const QByteArray &, int, const QString &, const QString &, QLocale::Country, const QString &);
  binder.ctors().ctor<const QByteArray &, int, const QString &, const QString &, QLocale::Country, const QString &>()
    .addDefaultArgument(binding::default_argument(time_zone.engine(), QString()))
    .addDefaultArgument(binding::default_argument(time_zone.engine(), QLocale::AnyCountry)).create();
  // QTimeZone(const QTimeZone &);
  binder.ctors().ctor<const QTimeZone &>().create();
  // ~QTimeZone();
  binder.add_dtor();
  // QTimeZone & operator=(const QTimeZone &);
  binder.operators().assign<const QTimeZone &>();
  // QTimeZone & operator=(QTimeZone &&);
  binder.operators().assign<QTimeZone &&>();
  // void swap(QTimeZone &);
  binder.void_fun<QTimeZone &, &QTimeZone::swap>("swap").create();
  // bool operator==(const QTimeZone &) const;
  binder.operators().eq<const QTimeZone &>();
  // bool operator!=(const QTimeZone &) const;
  binder.operators().neq<const QTimeZone &>();
  // bool isValid() const;
  binder.fun<bool, &QTimeZone::isValid>("isValid").create();
  // QByteArray id() const;
  binder.fun<QByteArray, &QTimeZone::id>("id").create();
  // QLocale::Country country() const;
  binder.fun<QLocale::Country, &QTimeZone::country>("country").create();
  // QString comment() const;
  binder.fun<QString, &QTimeZone::comment>("comment").create();
  // QString displayName(const QDateTime &, QTimeZone::NameType, const QLocale &) const;
  binder.fun<QString, const QDateTime &, QTimeZone::NameType, const QLocale &, &QTimeZone::displayName>("displayName")
    .addDefaultArgument(binding::default_argument(time_zone.engine(), QLocale()))
    .addDefaultArgument(binding::default_argument(time_zone.engine(),  QTimeZone::DefaultName)).create();
  // QString displayName(QTimeZone::TimeType, QTimeZone::NameType, const QLocale &) const;
  binder.fun<QString, QTimeZone::TimeType, QTimeZone::NameType, const QLocale &, &QTimeZone::displayName>("displayName")
    .addDefaultArgument(binding::default_argument(time_zone.engine(), QLocale()))
    .addDefaultArgument(binding::default_argument(time_zone.engine(),  QTimeZone::DefaultName)).create();
  // QString abbreviation(const QDateTime &) const;
  binder.fun<QString, const QDateTime &, &QTimeZone::abbreviation>("abbreviation").create();
  // int offsetFromUtc(const QDateTime &) const;
  binder.fun<int, const QDateTime &, &QTimeZone::offsetFromUtc>("offsetFromUtc").create();
  // int standardTimeOffset(const QDateTime &) const;
  binder.fun<int, const QDateTime &, &QTimeZone::standardTimeOffset>("standardTimeOffset").create();
  // int daylightTimeOffset(const QDateTime &) const;
  binder.fun<int, const QDateTime &, &QTimeZone::daylightTimeOffset>("daylightTimeOffset").create();
  // bool hasDaylightTime() const;
  binder.fun<bool, &QTimeZone::hasDaylightTime>("hasDaylightTime").create();
  // bool isDaylightTime(const QDateTime &) const;
  binder.fun<bool, const QDateTime &, &QTimeZone::isDaylightTime>("isDaylightTime").create();
  // QTimeZone::OffsetData offsetData(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData offsetData(const QDateTime &) const;
  // bool hasTransitions() const;
  binder.fun<bool, &QTimeZone::hasTransitions>("hasTransitions").create();
  // QTimeZone::OffsetData nextTransition(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData nextTransition(const QDateTime &) const;
  // QTimeZone::OffsetData previousTransition(const QDateTime &) const;
  /// TODO: QTimeZone::OffsetData previousTransition(const QDateTime &) const;
  // QTimeZone::OffsetDataList transitions(const QDateTime &, const QDateTime &) const;
  /// TODO: QTimeZone::OffsetDataList transitions(const QDateTime &, const QDateTime &) const;
  // static QByteArray systemTimeZoneId();
  binder.static_fun<QByteArray, &QTimeZone::systemTimeZoneId>("systemTimeZoneId").create();
  // static QTimeZone systemTimeZone();
  binder.static_fun<QTimeZone, &QTimeZone::systemTimeZone>("systemTimeZone").create();
  // static QTimeZone utc();
  binder.static_fun<QTimeZone, &QTimeZone::utc>("utc").create();
  // static bool isTimeZoneIdAvailable(const QByteArray &);
  binder.static_fun<bool, const QByteArray &, &QTimeZone::isTimeZoneIdAvailable>("isTimeZoneIdAvailable").create();
  // static QList<QByteArray> availableTimeZoneIds();
  binder.static_fun<QList<QByteArray>, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds").create();
  // static QList<QByteArray> availableTimeZoneIds(QLocale::Country);
  binder.static_fun<QList<QByteArray>, QLocale::Country, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds").create();
  // static QList<QByteArray> availableTimeZoneIds(int);
  binder.static_fun<QList<QByteArray>, int, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds").create();
  // static QByteArray ianaIdToWindowsId(const QByteArray &);
  binder.static_fun<QByteArray, const QByteArray &, &QTimeZone::ianaIdToWindowsId>("ianaIdToWindowsId").create();
  // static QByteArray windowsIdToDefaultIanaId(const QByteArray &);
  binder.static_fun<QByteArray, const QByteArray &, &QTimeZone::windowsIdToDefaultIanaId>("windowsIdToDefaultIanaId").create();
  // static QByteArray windowsIdToDefaultIanaId(const QByteArray &, QLocale::Country);
  binder.static_fun<QByteArray, const QByteArray &, QLocale::Country, &QTimeZone::windowsIdToDefaultIanaId>("windowsIdToDefaultIanaId").create();
  // static QList<QByteArray> windowsIdToIanaIds(const QByteArray &);
  binder.static_fun<QList<QByteArray>, const QByteArray &, &QTimeZone::windowsIdToIanaIds>("windowsIdToIanaIds").create();
  // static QList<QByteArray> windowsIdToIanaIds(const QByteArray &, QLocale::Country);
  binder.static_fun<QList<QByteArray>, const QByteArray &, QLocale::Country, &QTimeZone::windowsIdToIanaIds>("windowsIdToIanaIds").create();
}


void register_timezone_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_time_zone_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QTimeZone &, QTimeZone &);
  binder.void_fun<QTimeZone &, QTimeZone &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QTimeZone &);
  binder.operators().put_to<QDataStream &, const QTimeZone &>();
  // QDataStream & operator>>(QDataStream &, QTimeZone &);
  binder.operators().read_from<QDataStream &, QTimeZone &>();
  // QDebug operator<<(QDebug, const QTimeZone &);
  /// TODO: QDebug operator<<(QDebug, const QTimeZone &);
}

