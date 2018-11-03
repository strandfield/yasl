// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/datetime.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/datetime.h"
#include "yasl/core/enums.h"
#include "yasl/core/timezone.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_date_month_name_type_enum(script::Class date)
{
  using namespace script;

  Enum month_name_type = date.Enum("MonthNameType").setId(script::Type::QDateMonthNameType).get();

  month_name_type.addValue("DateFormat", QDate::DateFormat);
  month_name_type.addValue("StandaloneFormat", QDate::StandaloneFormat);
}


static void register_date_class(script::Namespace ns)
{
  using namespace script;

  Class date = ns.Class("Date").setId(script::Type::QDate).get();

  register_date_month_name_type_enum(date);
  binding::ClassBinder<QDate> binder{ date };

  // QDate();
  binder.default_ctor().create();
  // QDate(const QDate &);
  binder.ctor<const QDate &>().create();
  // ~QDate();
  binder.dtor().create();
  // QDate(int, int, int);
  binder.ctor<int, int, int>().create();
  // bool isNull() const;
  binder.fun<bool, &QDate::isNull>("isNull").create();
  // bool isValid() const;
  binder.fun<bool, &QDate::isValid>("isValid").create();
  // int year() const;
  binder.fun<int, &QDate::year>("year").create();
  // int month() const;
  binder.fun<int, &QDate::month>("month").create();
  // int day() const;
  binder.fun<int, &QDate::day>("day").create();
  // int dayOfWeek() const;
  binder.fun<int, &QDate::dayOfWeek>("dayOfWeek").create();
  // int dayOfYear() const;
  binder.fun<int, &QDate::dayOfYear>("dayOfYear").create();
  // int daysInMonth() const;
  binder.fun<int, &QDate::daysInMonth>("daysInMonth").create();
  // int daysInYear() const;
  binder.fun<int, &QDate::daysInYear>("daysInYear").create();
  // int weekNumber(int *) const;
  /// TODO: int weekNumber(int *) const;
  // static QString shortMonthName(int, QDate::MonthNameType);
  binder.static_fun<QString, int, QDate::MonthNameType, &QDate::shortMonthName>("shortMonthName").create();
  // static QString shortDayName(int, QDate::MonthNameType);
  binder.static_fun<QString, int, QDate::MonthNameType, &QDate::shortDayName>("shortDayName").create();
  // static QString longMonthName(int, QDate::MonthNameType);
  binder.static_fun<QString, int, QDate::MonthNameType, &QDate::longMonthName>("longMonthName").create();
  // static QString longDayName(int, QDate::MonthNameType);
  binder.static_fun<QString, int, QDate::MonthNameType, &QDate::longDayName>("longDayName").create();
  // QString toString(Qt::DateFormat) const;
  binder.fun<QString, Qt::DateFormat, &QDate::toString>("toString")
    .apply(binding::default_arguments(Qt::TextDate)).create();
  // QString toString(const QString &) const;
  binder.fun<QString, const QString &, &QDate::toString>("toString").create();
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // bool setDate(int, int, int);
  binder.fun<bool, int, int, int, &QDate::setDate>("setDate").create();
  // void getDate(int *, int *, int *);
  /// TODO: void getDate(int *, int *, int *);
  // void getDate(int *, int *, int *) const;
  /// TODO: void getDate(int *, int *, int *) const;
  // QDate addDays(qint64) const;
  /// TODO: QDate addDays(qint64) const;
  // QDate addMonths(int) const;
  binder.fun<QDate, int, &QDate::addMonths>("addMonths").create();
  // QDate addYears(int) const;
  binder.fun<QDate, int, &QDate::addYears>("addYears").create();
  // qint64 daysTo(const QDate &) const;
  /// TODO: qint64 daysTo(const QDate &) const;
  // QDate & operator=(const QDate &);
  binder.operators().assign<const QDate &>();
  // bool operator==(const QDate &) const;
  binder.operators().eq<const QDate &>();
  // bool operator!=(const QDate &) const;
  binder.operators().neq<const QDate &>();
  // bool operator<(const QDate &) const;
  binder.operators().less<const QDate &>();
  // bool operator<=(const QDate &) const;
  binder.operators().leq<const QDate &>();
  // bool operator>(const QDate &) const;
  binder.operators().greater<const QDate &>();
  // bool operator>=(const QDate &) const;
  binder.operators().geq<const QDate &>();
  // static QDate currentDate();
  binder.static_fun<QDate, &QDate::currentDate>("currentDate").create();
  // static QDate fromString(const QString &, Qt::DateFormat);
  binder.static_fun<QDate, const QString &, Qt::DateFormat, &QDate::fromString>("fromString")
    .apply(binding::default_arguments(Qt::TextDate)).create();
  // static QDate fromString(const QString &, const QString &);
  binder.static_fun<QDate, const QString &, const QString &, &QDate::fromString>("fromString").create();
  // static bool isValid(int, int, int);
  binder.static_fun<bool, int, int, int, &QDate::isValid>("isValid").create();
  // static bool isLeapYear(int);
  binder.static_fun<bool, int, &QDate::isLeapYear>("isLeapYear").create();
  // static QDate fromJulianDay(qint64);
  /// TODO: static QDate fromJulianDay(qint64);
  // qint64 toJulianDay() const;
  /// TODO: qint64 toJulianDay() const;
}


static void register_time_class(script::Namespace ns)
{
  using namespace script;

  Class time = ns.Class("Time").setId(script::Type::QTime).get();

  binding::ClassBinder<QTime> binder{ time };

  // QTime();
  binder.default_ctor().create();
  // QTime(const QTime &);
  binder.ctor<const QTime &>().create();
  // ~QTime();
  binder.dtor().create();
  // QTime(int, int, int, int);
  binder.ctor<int, int, int, int>()
    .apply(binding::default_arguments(0, 0)).create();
  // bool isNull() const;
  binder.fun<bool, &QTime::isNull>("isNull").create();
  // bool isValid() const;
  binder.fun<bool, &QTime::isValid>("isValid").create();
  // int hour() const;
  binder.fun<int, &QTime::hour>("hour").create();
  // int minute() const;
  binder.fun<int, &QTime::minute>("minute").create();
  // int second() const;
  binder.fun<int, &QTime::second>("second").create();
  // int msec() const;
  binder.fun<int, &QTime::msec>("msec").create();
  // QString toString(Qt::DateFormat) const;
  binder.fun<QString, Qt::DateFormat, &QTime::toString>("toString")
    .apply(binding::default_arguments(Qt::TextDate)).create();
  // QString toString(const QString &) const;
  binder.fun<QString, const QString &, &QTime::toString>("toString").create();
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // bool setHMS(int, int, int, int);
  binder.fun<bool, int, int, int, int, &QTime::setHMS>("setHMS")
    .apply(binding::default_arguments(0)).create();
  // QTime addSecs(int) const;
  binder.fun<QTime, int, &QTime::addSecs>("addSecs").create();
  // int secsTo(const QTime &) const;
  binder.fun<int, const QTime &, &QTime::secsTo>("secsTo").create();
  // QTime addMSecs(int) const;
  binder.fun<QTime, int, &QTime::addMSecs>("addMSecs").create();
  // int msecsTo(const QTime &) const;
  binder.fun<int, const QTime &, &QTime::msecsTo>("msecsTo").create();
  // QTime & operator=(const QTime &);
  binder.operators().assign<const QTime &>();
  // bool operator==(const QTime &) const;
  binder.operators().eq<const QTime &>();
  // bool operator!=(const QTime &) const;
  binder.operators().neq<const QTime &>();
  // bool operator<(const QTime &) const;
  binder.operators().less<const QTime &>();
  // bool operator<=(const QTime &) const;
  binder.operators().leq<const QTime &>();
  // bool operator>(const QTime &) const;
  binder.operators().greater<const QTime &>();
  // bool operator>=(const QTime &) const;
  binder.operators().geq<const QTime &>();
  // static QTime fromMSecsSinceStartOfDay(int);
  binder.static_fun<QTime, int, &QTime::fromMSecsSinceStartOfDay>("fromMSecsSinceStartOfDay").create();
  // int msecsSinceStartOfDay() const;
  binder.fun<int, &QTime::msecsSinceStartOfDay>("msecsSinceStartOfDay").create();
  // static QTime currentTime();
  binder.static_fun<QTime, &QTime::currentTime>("currentTime").create();
  // static QTime fromString(const QString &, Qt::DateFormat);
  binder.static_fun<QTime, const QString &, Qt::DateFormat, &QTime::fromString>("fromString")
    .apply(binding::default_arguments(Qt::TextDate)).create();
  // static QTime fromString(const QString &, const QString &);
  binder.static_fun<QTime, const QString &, const QString &, &QTime::fromString>("fromString").create();
  // static bool isValid(int, int, int, int);
  binder.static_fun<bool, int, int, int, int, &QTime::isValid>("isValid")
    .apply(binding::default_arguments(0)).create();
  // void start();
  binder.void_fun<&QTime::start>("start").create();
  // int restart();
  binder.fun<int, &QTime::restart>("restart").create();
  // int elapsed() const;
  binder.fun<int, &QTime::elapsed>("elapsed").create();
}


static void register_date_time_class(script::Namespace ns)
{
  using namespace script;

  Class date_time = ns.Class("DateTime").setId(script::Type::QDateTime).get();

  binding::ClassBinder<QDateTime> binder{ date_time };

  // QDateTime();
  binder.default_ctor().create();
  // QDateTime(const QDate &);
  binder.ctor<const QDate &>().create();
  // QDateTime(const QDate &, const QTime &, Qt::TimeSpec);
  binder.ctor<const QDate &, const QTime &, Qt::TimeSpec>()
    .apply(binding::default_arguments(Qt::LocalTime)).create();
  // QDateTime(const QDate &, const QTime &, Qt::TimeSpec, int);
  binder.ctor<const QDate &, const QTime &, Qt::TimeSpec, int>().create();
  // QDateTime(const QDate &, const QTime &, const QTimeZone &);
  binder.ctor<const QDate &, const QTime &, const QTimeZone &>().create();
  // QDateTime(const QDateTime &);
  binder.ctor<const QDateTime &>().create();
  // QDateTime(QDateTime &&);
  binder.ctor<QDateTime &&>().create();
  // ~QDateTime();
  binder.dtor().create();
  // QDateTime & operator=(QDateTime &&);
  binder.operators().assign<QDateTime &&>();
  // QDateTime & operator=(const QDateTime &);
  binder.operators().assign<const QDateTime &>();
  // void swap(QDateTime &);
  binder.void_fun<QDateTime &, &QDateTime::swap>("swap").create();
  // bool isNull() const;
  binder.fun<bool, &QDateTime::isNull>("isNull").create();
  // bool isValid() const;
  binder.fun<bool, &QDateTime::isValid>("isValid").create();
  // QDate date() const;
  binder.fun<QDate, &QDateTime::date>("date").create();
  // QTime time() const;
  binder.fun<QTime, &QDateTime::time>("time").create();
  // Qt::TimeSpec timeSpec() const;
  binder.fun<Qt::TimeSpec, &QDateTime::timeSpec>("timeSpec").create();
  // int offsetFromUtc() const;
  binder.fun<int, &QDateTime::offsetFromUtc>("offsetFromUtc").create();
  // QTimeZone timeZone() const;
  binder.fun<QTimeZone, &QDateTime::timeZone>("timeZone").create();
  // QString timeZoneAbbreviation() const;
  binder.fun<QString, &QDateTime::timeZoneAbbreviation>("timeZoneAbbreviation").create();
  // bool isDaylightTime() const;
  binder.fun<bool, &QDateTime::isDaylightTime>("isDaylightTime").create();
  // qint64 toMSecsSinceEpoch() const;
  /// TODO: qint64 toMSecsSinceEpoch() const;
  // qint64 toSecsSinceEpoch() const;
  /// TODO: qint64 toSecsSinceEpoch() const;
  // void setDate(const QDate &);
  binder.void_fun<const QDate &, &QDateTime::setDate>("setDate").create();
  // void setTime(const QTime &);
  binder.void_fun<const QTime &, &QDateTime::setTime>("setTime").create();
  // void setTimeSpec(Qt::TimeSpec);
  binder.void_fun<Qt::TimeSpec, &QDateTime::setTimeSpec>("setTimeSpec").create();
  // void setOffsetFromUtc(int);
  binder.void_fun<int, &QDateTime::setOffsetFromUtc>("setOffsetFromUtc").create();
  // void setTimeZone(const QTimeZone &);
  binder.void_fun<const QTimeZone &, &QDateTime::setTimeZone>("setTimeZone").create();
  // void setMSecsSinceEpoch(qint64);
  /// TODO: void setMSecsSinceEpoch(qint64);
  // void setSecsSinceEpoch(qint64);
  /// TODO: void setSecsSinceEpoch(qint64);
  // QString toString(Qt::DateFormat) const;
  binder.fun<QString, Qt::DateFormat, &QDateTime::toString>("toString")
    .apply(binding::default_arguments(Qt::TextDate)).create();
  // QString toString(const QString &) const;
  binder.fun<QString, const QString &, &QDateTime::toString>("toString").create();
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // QDateTime addDays(qint64) const;
  /// TODO: QDateTime addDays(qint64) const;
  // QDateTime addMonths(int) const;
  binder.fun<QDateTime, int, &QDateTime::addMonths>("addMonths").create();
  // QDateTime addYears(int) const;
  binder.fun<QDateTime, int, &QDateTime::addYears>("addYears").create();
  // QDateTime addSecs(qint64) const;
  /// TODO: QDateTime addSecs(qint64) const;
  // QDateTime addMSecs(qint64) const;
  /// TODO: QDateTime addMSecs(qint64) const;
  // QDateTime toTimeSpec(Qt::TimeSpec) const;
  binder.fun<QDateTime, Qt::TimeSpec, &QDateTime::toTimeSpec>("toTimeSpec").create();
  // QDateTime toLocalTime() const;
  binder.fun<QDateTime, &QDateTime::toLocalTime>("toLocalTime").create();
  // QDateTime toUTC() const;
  binder.fun<QDateTime, &QDateTime::toUTC>("toUTC").create();
  // QDateTime toOffsetFromUtc(int) const;
  binder.fun<QDateTime, int, &QDateTime::toOffsetFromUtc>("toOffsetFromUtc").create();
  // QDateTime toTimeZone(const QTimeZone &) const;
  binder.fun<QDateTime, const QTimeZone &, &QDateTime::toTimeZone>("toTimeZone").create();
  // qint64 daysTo(const QDateTime &) const;
  /// TODO: qint64 daysTo(const QDateTime &) const;
  // qint64 secsTo(const QDateTime &) const;
  /// TODO: qint64 secsTo(const QDateTime &) const;
  // qint64 msecsTo(const QDateTime &) const;
  /// TODO: qint64 msecsTo(const QDateTime &) const;
  // bool operator==(const QDateTime &) const;
  binder.operators().eq<const QDateTime &>();
  // bool operator!=(const QDateTime &) const;
  binder.operators().neq<const QDateTime &>();
  // bool operator<(const QDateTime &) const;
  binder.operators().less<const QDateTime &>();
  // bool operator<=(const QDateTime &) const;
  binder.operators().leq<const QDateTime &>();
  // bool operator>(const QDateTime &) const;
  binder.operators().greater<const QDateTime &>();
  // bool operator>=(const QDateTime &) const;
  binder.operators().geq<const QDateTime &>();
  // void setUtcOffset(int);
  binder.void_fun<int, &QDateTime::setUtcOffset>("setUtcOffset").create();
  // int utcOffset() const;
  binder.fun<int, &QDateTime::utcOffset>("utcOffset").create();
  // static QDateTime currentDateTime();
  binder.static_fun<QDateTime, &QDateTime::currentDateTime>("currentDateTime").create();
  // static QDateTime currentDateTimeUtc();
  binder.static_fun<QDateTime, &QDateTime::currentDateTimeUtc>("currentDateTimeUtc").create();
  // static QDateTime fromString(const QString &, Qt::DateFormat);
  binder.static_fun<QDateTime, const QString &, Qt::DateFormat, &QDateTime::fromString>("fromString")
    .apply(binding::default_arguments(Qt::TextDate)).create();
  // static QDateTime fromString(const QString &, const QString &);
  binder.static_fun<QDateTime, const QString &, const QString &, &QDateTime::fromString>("fromString").create();
  // uint toTime_t() const;
  binder.fun<uint, &QDateTime::toTime_t>("toTime_t").create();
  // void setTime_t(uint);
  binder.void_fun<uint, &QDateTime::setTime_t>("setTime_t").create();
  // static QDateTime fromTime_t(uint);
  binder.static_fun<QDateTime, uint, &QDateTime::fromTime_t>("fromTime_t").create();
  // static QDateTime fromTime_t(uint, Qt::TimeSpec, int);
  binder.static_fun<QDateTime, uint, Qt::TimeSpec, int, &QDateTime::fromTime_t>("fromTime_t").create();
  // static QDateTime fromTime_t(uint, const QTimeZone &);
  binder.static_fun<QDateTime, uint, const QTimeZone &, &QDateTime::fromTime_t>("fromTime_t").create();
  // static QDateTime fromMSecsSinceEpoch(qint64);
  /// TODO: static QDateTime fromMSecsSinceEpoch(qint64);
  // static QDateTime fromMSecsSinceEpoch(qint64, Qt::TimeSpec, int);
  /// TODO: static QDateTime fromMSecsSinceEpoch(qint64, Qt::TimeSpec, int);
  // static QDateTime fromSecsSinceEpoch(qint64, Qt::TimeSpec, int);
  /// TODO: static QDateTime fromSecsSinceEpoch(qint64, Qt::TimeSpec, int);
  // static QDateTime fromMSecsSinceEpoch(qint64, const QTimeZone &);
  /// TODO: static QDateTime fromMSecsSinceEpoch(qint64, const QTimeZone &);
  // static QDateTime fromSecsSinceEpoch(qint64, const QTimeZone &);
  /// TODO: static QDateTime fromSecsSinceEpoch(qint64, const QTimeZone &);
  // static qint64 currentMSecsSinceEpoch();
  /// TODO: static qint64 currentMSecsSinceEpoch();
  // static qint64 currentSecsSinceEpoch();
  /// TODO: static qint64 currentSecsSinceEpoch();
}


void register_datetime_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_date_class(ns);
  register_time_class(ns);
  register_date_time_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QDateTime &, QDateTime &);
  binder.void_fun<QDateTime &, QDateTime &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QDate &);
  binder.operators().put_to<QDataStream &, const QDate &>();
  // QDataStream & operator>>(QDataStream &, QDate &);
  binder.operators().read_from<QDataStream &, QDate &>();
  // QDataStream & operator<<(QDataStream &, const QTime &);
  binder.operators().put_to<QDataStream &, const QTime &>();
  // QDataStream & operator>>(QDataStream &, QTime &);
  binder.operators().read_from<QDataStream &, QTime &>();
  // QDataStream & operator<<(QDataStream &, const QDateTime &);
  binder.operators().put_to<QDataStream &, const QDateTime &>();
  // QDataStream & operator>>(QDataStream &, QDateTime &);
  binder.operators().read_from<QDataStream &, QDateTime &>();
  // QDebug operator<<(QDebug, const QDate &);
  /// TODO: QDebug operator<<(QDebug, const QDate &);
  // QDebug operator<<(QDebug, const QTime &);
  /// TODO: QDebug operator<<(QDebug, const QTime &);
  // QDebug operator<<(QDebug, const QDateTime &);
  /// TODO: QDebug operator<<(QDebug, const QDateTime &);
  // uint qHash(const QDateTime &, uint);
  binder.fun<uint, const QDateTime &, uint, &qHash>("qHash").create();
  // uint qHash(const QDate &, uint);
  binder.fun<uint, const QDate &, uint, &qHash>("qHash").create();
  // uint qHash(const QTime &, uint);
  binder.fun<uint, const QTime &, uint, &qHash>("qHash").create();
}

