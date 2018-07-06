// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/timezone.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/bytearray.h"
#include "yasl/core/datetime.h"
#include "yasl/core/enums.h"
#include "yasl/core/locale.h"

#include <script/engine.h>

static int timezone_type_id = 0;
static int name_type_type_id = 0;
static int time_type_type_id = 0;
static int anonymous_type_id = 0;


script::Type get_name_type_type()
{
  return name_type_type_id;
}

static void register_name_type_enum(script::Class timezone)
{
  using namespace script;

  Enum name_type = timezone.newEnum("NameType");
  name_type_type_id = name_type.id();

  name_type.addValue("DefaultName", QTimeZone::DefaultName);
  name_type.addValue("LongName", QTimeZone::LongName);
  name_type.addValue("ShortName", QTimeZone::ShortName);
  name_type.addValue("OffsetName", QTimeZone::OffsetName);
}


script::Type get_time_type_type()
{
  return time_type_type_id;
}

static void register_time_type_enum(script::Class timezone)
{
  using namespace script;

  Enum time_type = timezone.newEnum("TimeType");
  time_type_type_id = time_type.id();

  time_type.addValue("StandardTime", QTimeZone::StandardTime);
  time_type.addValue("DaylightTime", QTimeZone::DaylightTime);
  time_type.addValue("GenericTime", QTimeZone::GenericTime);
}


script::Type get_anonymous_type()
{
  return anonymous_type_id;
}

static void register_anonymous_enum(script::Class timezone)
{
  using namespace script;

  Enum anonymous = timezone.newEnum("anonymous");
  anonymous_type_id = anonymous.id();

  anonymous.addValue("MinUtcOffsetSecs", QTimeZone::MinUtcOffsetSecs);
  anonymous.addValue("MaxUtcOffsetSecs", QTimeZone::MaxUtcOffsetSecs);
}


script::Type get_timezone_type()
{
  return script::Type{ timezone_type_id };
}

void register_timezone_class(script::Namespace ns)
{
  using namespace script;

  Class timezone = ns.newClass(ClassBuilder::New("TimeZone").setFinal());
  timezone_type_id = timezone.id();

  register_name_type_enum(timezone);
  register_time_type_enum(timezone);
  register_anonymous_enum(timezone);


  binding::Class<QTimeZone> binder{ timezone };

  // ~QTimeZone();
  binder.add_dtor();


  /* Public member functions */

  // QString abbreviation(const QDateTime &atDateTime) const
  binder.add_fun<QString, const QDateTime &, &QTimeZone::abbreviation>("abbreviation");
  // QString comment() const
  binder.add_fun<QString, &QTimeZone::comment>("comment");
  // QLocale::Country country() const
  binder.add_fun<QLocale::Country, &QTimeZone::country>("country");
  // int daylightTimeOffset(const QDateTime &atDateTime) const
  binder.add_fun<int, const QDateTime &, &QTimeZone::daylightTimeOffset>("daylightTimeOffset");
  // QString displayName(const QDateTime &atDateTime, QTimeZone::NameType nameType = QTimeZone::DefaultName, const QLocale &locale = QLocale()) const
  binder.add_fun<QString, const QDateTime &, QTimeZone::NameType, const QLocale &, &QTimeZone::displayName>("displayName");
  // QString displayName(QTimeZone::TimeType timeType, QTimeZone::NameType nameType = QTimeZone::DefaultName, const QLocale &locale = QLocale()) const
  binder.add_fun<QString, QTimeZone::TimeType, QTimeZone::NameType, const QLocale &, &QTimeZone::displayName>("displayName");
  // bool hasDaylightTime() const
  binder.add_fun<bool, &QTimeZone::hasDaylightTime>("hasDaylightTime");
  // bool hasTransitions() const
  binder.add_fun<bool, &QTimeZone::hasTransitions>("hasTransitions");
  // QByteArray id() const
  binder.add_fun<QByteArray, &QTimeZone::id>("id");
  // bool isDaylightTime(const QDateTime &atDateTime) const
  binder.add_fun<bool, const QDateTime &, &QTimeZone::isDaylightTime>("isDaylightTime");
  // bool isValid() const
  binder.add_fun<bool, &QTimeZone::isValid>("isValid");
  // QTimeZone::OffsetData nextTransition(const QDateTime &afterDateTime) const
  /// binder.add_fun<QTimeZone::OffsetData, const QDateTime &, &QTimeZone::nextTransition>("nextTransition");
  // QTimeZone::OffsetData offsetData(const QDateTime &forDateTime) const
  /// binder.add_fun<QTimeZone::OffsetData, const QDateTime &, &QTimeZone::offsetData>("offsetData");
  // int offsetFromUtc(const QDateTime &atDateTime) const
  binder.add_fun<int, const QDateTime &, &QTimeZone::offsetFromUtc>("offsetFromUtc");
  // QTimeZone::OffsetData previousTransition(const QDateTime &beforeDateTime) const
  /// binder.add_fun<QTimeZone::OffsetData, const QDateTime &, &QTimeZone::previousTransition>("previousTransition");
  // int standardTimeOffset(const QDateTime &atDateTime) const
  binder.add_fun<int, const QDateTime &, &QTimeZone::standardTimeOffset>("standardTimeOffset");
  // void swap(QTimeZone &other)
  binder.add_void_fun<QTimeZone &, &QTimeZone::swap>("swap");
  // CFTimeZoneRef toCFTimeZone() const
  ///binder.add_fun<CFTimeZoneRef, &QTimeZone::toCFTimeZone>("toCFTimeZone");
  // NSTimeZone * toNSTimeZone() const
  /// TODO !!!
  // QTimeZone::OffsetDataList transitions(const QDateTime &fromDateTime, const QDateTime &toDateTime) const
  /// binder.add_fun<QTimeZone::OffsetDataList, const QDateTime &, const QDateTime &, &QTimeZone::transitions>("transitions");
  // bool operator!=(const QTimeZone &other) const
  /// TODO !!!
  // QTimeZone & operator=(const QTimeZone &other)
  /// TODO !!!
  // QTimeZone & operator=(QTimeZone &&other)
  /// TODO !!!
  // bool operator==(const QTimeZone &other) const
  /// TODO !!!



  /* Static public members */

  // static QList<QByteArray> availableTimeZoneIds()
  binder.add_static<QList<QByteArray>, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds");
  // static QList<QByteArray> availableTimeZoneIds(QLocale::Country country)
  binder.add_static<QList<QByteArray>, QLocale::Country, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds");
  // static QList<QByteArray> availableTimeZoneIds(int offsetSeconds)
  binder.add_static<QList<QByteArray>, int, &QTimeZone::availableTimeZoneIds>("availableTimeZoneIds");
  // static QTimeZone fromCFTimeZone(CFTimeZoneRef timeZone)
  ///binder.add_static<QTimeZone, CFTimeZoneRef, &QTimeZone::fromCFTimeZone>("fromCFTimeZone");
  // static QTimeZone fromNSTimeZone(const NSTimeZone *timeZone)
  /// TODO !!!
  // static QByteArray ianaIdToWindowsId(const QByteArray &ianaId)
  binder.add_static<QByteArray, const QByteArray &, &QTimeZone::ianaIdToWindowsId>("ianaIdToWindowsId");
  // static bool isTimeZoneIdAvailable(const QByteArray &ianaId)
  binder.add_static<bool, const QByteArray &, &QTimeZone::isTimeZoneIdAvailable>("isTimeZoneIdAvailable");
  // static QTimeZone systemTimeZone()
  binder.add_static<QTimeZone, &QTimeZone::systemTimeZone>("systemTimeZone");
  // static QByteArray systemTimeZoneId()
  binder.add_static<QByteArray, &QTimeZone::systemTimeZoneId>("systemTimeZoneId");
  // static QTimeZone utc()
  binder.add_static<QTimeZone, &QTimeZone::utc>("utc");
  // static QByteArray windowsIdToDefaultIanaId(const QByteArray &windowsId)
  binder.add_static<QByteArray, const QByteArray &, &QTimeZone::windowsIdToDefaultIanaId>("windowsIdToDefaultIanaId");
  // static QByteArray windowsIdToDefaultIanaId(const QByteArray &windowsId, QLocale::Country country)
  binder.add_static<QByteArray, const QByteArray &, QLocale::Country, &QTimeZone::windowsIdToDefaultIanaId>("windowsIdToDefaultIanaId");
  // static QList<QByteArray> windowsIdToIanaIds(const QByteArray &windowsId)
  binder.add_static<QList<QByteArray>, const QByteArray &, &QTimeZone::windowsIdToIanaIds>("windowsIdToIanaIds");
  // static QList<QByteArray> windowsIdToIanaIds(const QByteArray &windowsId, QLocale::Country country)
  binder.add_static<QList<QByteArray>, const QByteArray &, QLocale::Country, &QTimeZone::windowsIdToIanaIds>("windowsIdToIanaIds");


  /* Related non-members */
  binding::Namespace related{ ns };

}
