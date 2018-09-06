// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/datetime.h"

#include "yasl/binding/class.h"
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
  binding::Class<QDate> binder{ date };

  // QDate();
  binder.ctors().add_default();
  // QDate(const QDate &);
  binder.ctors().add<const QDate &>();
  // ~QDate();
  binder.add_dtor();
  // QDate(int, int, int);
  binder.ctors().add<int, int, int>();
  // bool isNull() const;
  binder.add_fun<bool, &QDate::isNull>("isNull");
  // bool isValid() const;
  binder.add_fun<bool, &QDate::isValid>("isValid");
  // int year() const;
  binder.add_fun<int, &QDate::year>("year");
  // int month() const;
  binder.add_fun<int, &QDate::month>("month");
  // int day() const;
  binder.add_fun<int, &QDate::day>("day");
  // int dayOfWeek() const;
  binder.add_fun<int, &QDate::dayOfWeek>("dayOfWeek");
  // int dayOfYear() const;
  binder.add_fun<int, &QDate::dayOfYear>("dayOfYear");
  // int daysInMonth() const;
  binder.add_fun<int, &QDate::daysInMonth>("daysInMonth");
  // int daysInYear() const;
  binder.add_fun<int, &QDate::daysInYear>("daysInYear");
  // int weekNumber(int *) const;
  /// TODO: int weekNumber(int *) const;
  // static QString shortMonthName(int, QDate::MonthNameType);
  binder.add_static<QString, int, QDate::MonthNameType, &QDate::shortMonthName>("shortMonthName");
  // static QString shortDayName(int, QDate::MonthNameType);
  binder.add_static<QString, int, QDate::MonthNameType, &QDate::shortDayName>("shortDayName");
  // static QString longMonthName(int, QDate::MonthNameType);
  binder.add_static<QString, int, QDate::MonthNameType, &QDate::longMonthName>("longMonthName");
  // static QString longDayName(int, QDate::MonthNameType);
  binder.add_static<QString, int, QDate::MonthNameType, &QDate::longDayName>("longDayName");
  // QString toString(Qt::DateFormat) const;
  binder.add_fun<QString, Qt::DateFormat, &QDate::toString>("toString");
  // QString toString(const QString &) const;
  binder.add_fun<QString, const QString &, &QDate::toString>("toString");
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // bool setDate(int, int, int);
  binder.add_fun<bool, int, int, int, &QDate::setDate>("setDate");
  // void getDate(int *, int *, int *);
  /// TODO: void getDate(int *, int *, int *);
  // void getDate(int *, int *, int *) const;
  /// TODO: void getDate(int *, int *, int *) const;
  // QDate addDays(qint64) const;
  /// TODO: QDate addDays(qint64) const;
  // QDate addMonths(int) const;
  binder.add_fun<QDate, int, &QDate::addMonths>("addMonths");
  // QDate addYears(int) const;
  binder.add_fun<QDate, int, &QDate::addYears>("addYears");
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
  binder.add_static<QDate, &QDate::currentDate>("currentDate");
  // static QDate fromString(const QString &, Qt::DateFormat);
  binder.add_static<QDate, const QString &, Qt::DateFormat, &QDate::fromString>("fromString");
  // static QDate fromString(const QString &, const QString &);
  binder.add_static<QDate, const QString &, const QString &, &QDate::fromString>("fromString");
  // static bool isValid(int, int, int);
  binder.add_static<bool, int, int, int, &QDate::isValid>("isValid");
  // static bool isLeapYear(int);
  binder.add_static<bool, int, &QDate::isLeapYear>("isLeapYear");
  // static QDate fromJulianDay(qint64);
  /// TODO: static QDate fromJulianDay(qint64);
  // qint64 toJulianDay() const;
  /// TODO: qint64 toJulianDay() const;
}


static void register_time_class(script::Namespace ns)
{
  using namespace script;

  Class time = ns.Class("Time").setId(script::Type::QTime).get();

  binding::Class<QTime> binder{ time };

  // QTime();
  binder.ctors().add_default();
  // QTime(const QTime &);
  binder.ctors().add<const QTime &>();
  // ~QTime();
  binder.add_dtor();
  // QTime(int, int, int, int);
  binder.ctors().add<int, int, int, int>();
  // bool isNull() const;
  binder.add_fun<bool, &QTime::isNull>("isNull");
  // bool isValid() const;
  binder.add_fun<bool, &QTime::isValid>("isValid");
  // int hour() const;
  binder.add_fun<int, &QTime::hour>("hour");
  // int minute() const;
  binder.add_fun<int, &QTime::minute>("minute");
  // int second() const;
  binder.add_fun<int, &QTime::second>("second");
  // int msec() const;
  binder.add_fun<int, &QTime::msec>("msec");
  // QString toString(Qt::DateFormat) const;
  binder.add_fun<QString, Qt::DateFormat, &QTime::toString>("toString");
  // QString toString(const QString &) const;
  binder.add_fun<QString, const QString &, &QTime::toString>("toString");
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // bool setHMS(int, int, int, int);
  binder.add_fun<bool, int, int, int, int, &QTime::setHMS>("setHMS");
  // QTime addSecs(int) const;
  binder.add_fun<QTime, int, &QTime::addSecs>("addSecs");
  // int secsTo(const QTime &) const;
  binder.add_fun<int, const QTime &, &QTime::secsTo>("secsTo");
  // QTime addMSecs(int) const;
  binder.add_fun<QTime, int, &QTime::addMSecs>("addMSecs");
  // int msecsTo(const QTime &) const;
  binder.add_fun<int, const QTime &, &QTime::msecsTo>("msecsTo");
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
  binder.add_static<QTime, int, &QTime::fromMSecsSinceStartOfDay>("fromMSecsSinceStartOfDay");
  // int msecsSinceStartOfDay() const;
  binder.add_fun<int, &QTime::msecsSinceStartOfDay>("msecsSinceStartOfDay");
  // static QTime currentTime();
  binder.add_static<QTime, &QTime::currentTime>("currentTime");
  // static QTime fromString(const QString &, Qt::DateFormat);
  binder.add_static<QTime, const QString &, Qt::DateFormat, &QTime::fromString>("fromString");
  // static QTime fromString(const QString &, const QString &);
  binder.add_static<QTime, const QString &, const QString &, &QTime::fromString>("fromString");
  // static bool isValid(int, int, int, int);
  binder.add_static<bool, int, int, int, int, &QTime::isValid>("isValid");
  // void start();
  binder.add_void_fun<&QTime::start>("start");
  // int restart();
  binder.add_fun<int, &QTime::restart>("restart");
  // int elapsed() const;
  binder.add_fun<int, &QTime::elapsed>("elapsed");
}


static void register_date_time_class(script::Namespace ns)
{
  using namespace script;

  Class date_time = ns.Class("DateTime").setId(script::Type::QDateTime).get();

  binding::Class<QDateTime> binder{ date_time };

  // QDateTime();
  binder.ctors().add_default();
  // QDateTime(const QDate &);
  binder.ctors().add<const QDate &>();
  // QDateTime(const QDate &, const QTime &, Qt::TimeSpec);
  binder.ctors().add<const QDate &, const QTime &, Qt::TimeSpec>();
  // QDateTime(const QDate &, const QTime &, Qt::TimeSpec, int);
  binder.ctors().add<const QDate &, const QTime &, Qt::TimeSpec, int>();
  // QDateTime(const QDate &, const QTime &, const QTimeZone &);
  binder.ctors().add<const QDate &, const QTime &, const QTimeZone &>();
  // QDateTime(const QDateTime &);
  binder.ctors().add<const QDateTime &>();
  // QDateTime(QDateTime &&);
  binder.ctors().add<QDateTime &&>();
  // ~QDateTime();
  binder.add_dtor();
  // QDateTime & operator=(QDateTime &&);
  binder.operators().assign<QDateTime &&>();
  // QDateTime & operator=(const QDateTime &);
  binder.operators().assign<const QDateTime &>();
  // void swap(QDateTime &);
  binder.add_void_fun<QDateTime &, &QDateTime::swap>("swap");
  // bool isNull() const;
  binder.add_fun<bool, &QDateTime::isNull>("isNull");
  // bool isValid() const;
  binder.add_fun<bool, &QDateTime::isValid>("isValid");
  // QDate date() const;
  binder.add_fun<QDate, &QDateTime::date>("date");
  // QTime time() const;
  binder.add_fun<QTime, &QDateTime::time>("time");
  // Qt::TimeSpec timeSpec() const;
  binder.add_fun<Qt::TimeSpec, &QDateTime::timeSpec>("timeSpec");
  // int offsetFromUtc() const;
  binder.add_fun<int, &QDateTime::offsetFromUtc>("offsetFromUtc");
  // QTimeZone timeZone() const;
  binder.add_fun<QTimeZone, &QDateTime::timeZone>("timeZone");
  // QString timeZoneAbbreviation() const;
  binder.add_fun<QString, &QDateTime::timeZoneAbbreviation>("timeZoneAbbreviation");
  // bool isDaylightTime() const;
  binder.add_fun<bool, &QDateTime::isDaylightTime>("isDaylightTime");
  // qint64 toMSecsSinceEpoch() const;
  /// TODO: qint64 toMSecsSinceEpoch() const;
  // qint64 toSecsSinceEpoch() const;
  /// TODO: qint64 toSecsSinceEpoch() const;
  // void setDate(const QDate &);
  binder.add_void_fun<const QDate &, &QDateTime::setDate>("setDate");
  // void setTime(const QTime &);
  binder.add_void_fun<const QTime &, &QDateTime::setTime>("setTime");
  // void setTimeSpec(Qt::TimeSpec);
  binder.add_void_fun<Qt::TimeSpec, &QDateTime::setTimeSpec>("setTimeSpec");
  // void setOffsetFromUtc(int);
  binder.add_void_fun<int, &QDateTime::setOffsetFromUtc>("setOffsetFromUtc");
  // void setTimeZone(const QTimeZone &);
  binder.add_void_fun<const QTimeZone &, &QDateTime::setTimeZone>("setTimeZone");
  // void setMSecsSinceEpoch(qint64);
  /// TODO: void setMSecsSinceEpoch(qint64);
  // void setSecsSinceEpoch(qint64);
  /// TODO: void setSecsSinceEpoch(qint64);
  // QString toString(Qt::DateFormat) const;
  binder.add_fun<QString, Qt::DateFormat, &QDateTime::toString>("toString");
  // QString toString(const QString &) const;
  binder.add_fun<QString, const QString &, &QDateTime::toString>("toString");
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // QDateTime addDays(qint64) const;
  /// TODO: QDateTime addDays(qint64) const;
  // QDateTime addMonths(int) const;
  binder.add_fun<QDateTime, int, &QDateTime::addMonths>("addMonths");
  // QDateTime addYears(int) const;
  binder.add_fun<QDateTime, int, &QDateTime::addYears>("addYears");
  // QDateTime addSecs(qint64) const;
  /// TODO: QDateTime addSecs(qint64) const;
  // QDateTime addMSecs(qint64) const;
  /// TODO: QDateTime addMSecs(qint64) const;
  // QDateTime toTimeSpec(Qt::TimeSpec) const;
  binder.add_fun<QDateTime, Qt::TimeSpec, &QDateTime::toTimeSpec>("toTimeSpec");
  // QDateTime toLocalTime() const;
  binder.add_fun<QDateTime, &QDateTime::toLocalTime>("toLocalTime");
  // QDateTime toUTC() const;
  binder.add_fun<QDateTime, &QDateTime::toUTC>("toUTC");
  // QDateTime toOffsetFromUtc(int) const;
  binder.add_fun<QDateTime, int, &QDateTime::toOffsetFromUtc>("toOffsetFromUtc");
  // QDateTime toTimeZone(const QTimeZone &) const;
  binder.add_fun<QDateTime, const QTimeZone &, &QDateTime::toTimeZone>("toTimeZone");
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
  binder.add_void_fun<int, &QDateTime::setUtcOffset>("setUtcOffset");
  // int utcOffset() const;
  binder.add_fun<int, &QDateTime::utcOffset>("utcOffset");
  // static QDateTime currentDateTime();
  binder.add_static<QDateTime, &QDateTime::currentDateTime>("currentDateTime");
  // static QDateTime currentDateTimeUtc();
  binder.add_static<QDateTime, &QDateTime::currentDateTimeUtc>("currentDateTimeUtc");
  // static QDateTime fromString(const QString &, Qt::DateFormat);
  binder.add_static<QDateTime, const QString &, Qt::DateFormat, &QDateTime::fromString>("fromString");
  // static QDateTime fromString(const QString &, const QString &);
  binder.add_static<QDateTime, const QString &, const QString &, &QDateTime::fromString>("fromString");
  // uint toTime_t() const;
  binder.add_fun<uint, &QDateTime::toTime_t>("toTime_t");
  // void setTime_t(uint);
  binder.add_void_fun<uint, &QDateTime::setTime_t>("setTime_t");
  // static QDateTime fromTime_t(uint);
  binder.add_static<QDateTime, uint, &QDateTime::fromTime_t>("fromTime_t");
  // static QDateTime fromTime_t(uint, Qt::TimeSpec, int);
  binder.add_static<QDateTime, uint, Qt::TimeSpec, int, &QDateTime::fromTime_t>("fromTime_t");
  // static QDateTime fromTime_t(uint, const QTimeZone &);
  binder.add_static<QDateTime, uint, const QTimeZone &, &QDateTime::fromTime_t>("fromTime_t");
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
  binder.add_void_fun<QDateTime &, QDateTime &, &swap>("swap");
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
  binder.add_fun<uint, const QDateTime &, uint, &qHash>("qHash");
  // uint qHash(const QDate &, uint);
  binder.add_fun<uint, const QDate &, uint, &qHash>("qHash");
  // uint qHash(const QTime &, uint);
  binder.add_fun<uint, const QTime &, uint, &qHash>("qHash");
}

