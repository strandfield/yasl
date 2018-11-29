// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/datetime.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/datastream.h"
#include "yasl/core/datetime.h"
#include "yasl/core/enums.h"
#include "yasl/core/timezone.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_date_month_name_type_enum(script::Class date)
{
  using namespace script;

  Enum month_name_type = date.newEnum("MonthNameType").setId(script::Type::QDateMonthNameType).get();

  month_name_type.addValue("DateFormat", QDate::DateFormat);
  month_name_type.addValue("StandaloneFormat", QDate::StandaloneFormat);
}


static void register_date_class(script::Namespace ns)
{
  using namespace script;

  Class date = ns.newClass("Date").setId(script::Type::QDate).get();

  register_date_month_name_type_enum(date);

  // QDate();
  bind::default_constructor<QDate>(date).create();
  // QDate(const QDate &);
  bind::constructor<QDate, const QDate &>(date).create();
  // ~QDate();
  bind::destructor<QDate>(date).create();
  // QDate(int, int, int);
  bind::constructor<QDate, int, int, int>(date).create();
  // bool isNull() const;
  bind::member_function<QDate, bool, &QDate::isNull>(date, "isNull").create();
  // bool isValid() const;
  bind::member_function<QDate, bool, &QDate::isValid>(date, "isValid").create();
  // int year() const;
  bind::member_function<QDate, int, &QDate::year>(date, "year").create();
  // int month() const;
  bind::member_function<QDate, int, &QDate::month>(date, "month").create();
  // int day() const;
  bind::member_function<QDate, int, &QDate::day>(date, "day").create();
  // int dayOfWeek() const;
  bind::member_function<QDate, int, &QDate::dayOfWeek>(date, "dayOfWeek").create();
  // int dayOfYear() const;
  bind::member_function<QDate, int, &QDate::dayOfYear>(date, "dayOfYear").create();
  // int daysInMonth() const;
  bind::member_function<QDate, int, &QDate::daysInMonth>(date, "daysInMonth").create();
  // int daysInYear() const;
  bind::member_function<QDate, int, &QDate::daysInYear>(date, "daysInYear").create();
  // int weekNumber(int *) const;
  /// TODO: int weekNumber(int *) const;
  // static QString shortMonthName(int, QDate::MonthNameType);
  bind::static_member_function<QDate, QString, int, QDate::MonthNameType, &QDate::shortMonthName>(date, "shortMonthName").create();
  // static QString shortDayName(int, QDate::MonthNameType);
  bind::static_member_function<QDate, QString, int, QDate::MonthNameType, &QDate::shortDayName>(date, "shortDayName").create();
  // static QString longMonthName(int, QDate::MonthNameType);
  bind::static_member_function<QDate, QString, int, QDate::MonthNameType, &QDate::longMonthName>(date, "longMonthName").create();
  // static QString longDayName(int, QDate::MonthNameType);
  bind::static_member_function<QDate, QString, int, QDate::MonthNameType, &QDate::longDayName>(date, "longDayName").create();
  // QString toString(Qt::DateFormat = Qt::TextDate) const;
  bind::member_function<QDate, QString, Qt::DateFormat, &QDate::toString>(date, "toString")
    .apply(bind::default_arguments(Qt::TextDate)).create();
  // QString toString(const QString &) const;
  bind::member_function<QDate, QString, const QString &, &QDate::toString>(date, "toString").create();
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // bool setDate(int, int, int);
  bind::member_function<QDate, bool, int, int, int, &QDate::setDate>(date, "setDate").create();
  // void getDate(int *, int *, int *);
  /// TODO: void getDate(int *, int *, int *);
  // void getDate(int *, int *, int *) const;
  /// TODO: void getDate(int *, int *, int *) const;
  // QDate addDays(qint64) const;
  /// TODO: QDate addDays(qint64) const;
  // QDate addMonths(int) const;
  bind::member_function<QDate, QDate, int, &QDate::addMonths>(date, "addMonths").create();
  // QDate addYears(int) const;
  bind::member_function<QDate, QDate, int, &QDate::addYears>(date, "addYears").create();
  // qint64 daysTo(const QDate &) const;
  /// TODO: qint64 daysTo(const QDate &) const;
  // QDate & operator=(const QDate &);
  bind::memop_assign<QDate, const QDate &>(date);
  // bool operator==(const QDate &) const;
  bind::memop_eq<QDate, const QDate &>(date);
  // bool operator!=(const QDate &) const;
  bind::memop_neq<QDate, const QDate &>(date);
  // bool operator<(const QDate &) const;
  bind::memop_less<QDate, const QDate &>(date);
  // bool operator<=(const QDate &) const;
  bind::memop_leq<QDate, const QDate &>(date);
  // bool operator>(const QDate &) const;
  bind::memop_greater<QDate, const QDate &>(date);
  // bool operator>=(const QDate &) const;
  bind::memop_geq<QDate, const QDate &>(date);
  // static QDate currentDate();
  bind::static_member_function<QDate, QDate, &QDate::currentDate>(date, "currentDate").create();
  // static QDate fromString(const QString &, Qt::DateFormat = Qt::TextDate);
  bind::static_member_function<QDate, QDate, const QString &, Qt::DateFormat, &QDate::fromString>(date, "fromString")
    .apply(bind::default_arguments(Qt::TextDate)).create();
  // static QDate fromString(const QString &, const QString &);
  bind::static_member_function<QDate, QDate, const QString &, const QString &, &QDate::fromString>(date, "fromString").create();
  // static bool isValid(int, int, int);
  bind::static_member_function<QDate, bool, int, int, int, &QDate::isValid>(date, "isValid").create();
  // static bool isLeapYear(int);
  bind::static_member_function<QDate, bool, int, &QDate::isLeapYear>(date, "isLeapYear").create();
  // static QDate fromJulianDay(qint64);
  /// TODO: static QDate fromJulianDay(qint64);
  // qint64 toJulianDay() const;
  /// TODO: qint64 toJulianDay() const;

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QDate, QMetaType::QDate>>();
}


static void register_time_class(script::Namespace ns)
{
  using namespace script;

  Class time = ns.newClass("Time").setId(script::Type::QTime).get();


  // QTime();
  bind::default_constructor<QTime>(time).create();
  // QTime(const QTime &);
  bind::constructor<QTime, const QTime &>(time).create();
  // ~QTime();
  bind::destructor<QTime>(time).create();
  // QTime(int, int, int = 0, int = 0);
  bind::constructor<QTime, int, int, int, int>(time)
    .apply(bind::default_arguments(0, 0)).create();
  // bool isNull() const;
  bind::member_function<QTime, bool, &QTime::isNull>(time, "isNull").create();
  // bool isValid() const;
  bind::member_function<QTime, bool, &QTime::isValid>(time, "isValid").create();
  // int hour() const;
  bind::member_function<QTime, int, &QTime::hour>(time, "hour").create();
  // int minute() const;
  bind::member_function<QTime, int, &QTime::minute>(time, "minute").create();
  // int second() const;
  bind::member_function<QTime, int, &QTime::second>(time, "second").create();
  // int msec() const;
  bind::member_function<QTime, int, &QTime::msec>(time, "msec").create();
  // QString toString(Qt::DateFormat = Qt::TextDate) const;
  bind::member_function<QTime, QString, Qt::DateFormat, &QTime::toString>(time, "toString")
    .apply(bind::default_arguments(Qt::TextDate)).create();
  // QString toString(const QString &) const;
  bind::member_function<QTime, QString, const QString &, &QTime::toString>(time, "toString").create();
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // bool setHMS(int, int, int, int = 0);
  bind::member_function<QTime, bool, int, int, int, int, &QTime::setHMS>(time, "setHMS")
    .apply(bind::default_arguments(0)).create();
  // QTime addSecs(int) const;
  bind::member_function<QTime, QTime, int, &QTime::addSecs>(time, "addSecs").create();
  // int secsTo(const QTime &) const;
  bind::member_function<QTime, int, const QTime &, &QTime::secsTo>(time, "secsTo").create();
  // QTime addMSecs(int) const;
  bind::member_function<QTime, QTime, int, &QTime::addMSecs>(time, "addMSecs").create();
  // int msecsTo(const QTime &) const;
  bind::member_function<QTime, int, const QTime &, &QTime::msecsTo>(time, "msecsTo").create();
  // QTime & operator=(const QTime &);
  bind::memop_assign<QTime, const QTime &>(time);
  // bool operator==(const QTime &) const;
  bind::memop_eq<QTime, const QTime &>(time);
  // bool operator!=(const QTime &) const;
  bind::memop_neq<QTime, const QTime &>(time);
  // bool operator<(const QTime &) const;
  bind::memop_less<QTime, const QTime &>(time);
  // bool operator<=(const QTime &) const;
  bind::memop_leq<QTime, const QTime &>(time);
  // bool operator>(const QTime &) const;
  bind::memop_greater<QTime, const QTime &>(time);
  // bool operator>=(const QTime &) const;
  bind::memop_geq<QTime, const QTime &>(time);
  // static QTime fromMSecsSinceStartOfDay(int);
  bind::static_member_function<QTime, QTime, int, &QTime::fromMSecsSinceStartOfDay>(time, "fromMSecsSinceStartOfDay").create();
  // int msecsSinceStartOfDay() const;
  bind::member_function<QTime, int, &QTime::msecsSinceStartOfDay>(time, "msecsSinceStartOfDay").create();
  // static QTime currentTime();
  bind::static_member_function<QTime, QTime, &QTime::currentTime>(time, "currentTime").create();
  // static QTime fromString(const QString &, Qt::DateFormat = Qt::TextDate);
  bind::static_member_function<QTime, QTime, const QString &, Qt::DateFormat, &QTime::fromString>(time, "fromString")
    .apply(bind::default_arguments(Qt::TextDate)).create();
  // static QTime fromString(const QString &, const QString &);
  bind::static_member_function<QTime, QTime, const QString &, const QString &, &QTime::fromString>(time, "fromString").create();
  // static bool isValid(int, int, int, int = 0);
  bind::static_member_function<QTime, bool, int, int, int, int, &QTime::isValid>(time, "isValid")
    .apply(bind::default_arguments(0)).create();
  // void start();
  bind::void_member_function<QTime, &QTime::start>(time, "start").create();
  // int restart();
  bind::member_function<QTime, int, &QTime::restart>(time, "restart").create();
  // int elapsed() const;
  bind::member_function<QTime, int, &QTime::elapsed>(time, "elapsed").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QTime, QMetaType::QTime>>();
}


static void register_date_time_class(script::Namespace ns)
{
  using namespace script;

  Class date_time = ns.newClass("DateTime").setId(script::Type::QDateTime).get();


  // QDateTime();
  bind::default_constructor<QDateTime>(date_time).create();
  // QDateTime(const QDate &);
  bind::constructor<QDateTime, const QDate &>(date_time).create();
  // QDateTime(const QDate &, const QTime &, Qt::TimeSpec = Qt::LocalTime);
  bind::constructor<QDateTime, const QDate &, const QTime &, Qt::TimeSpec>(date_time)
    .apply(bind::default_arguments(Qt::LocalTime)).create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QDateTime(const QDate &, const QTime &, Qt::TimeSpec, int);
  bind::constructor<QDateTime, const QDate &, const QTime &, Qt::TimeSpec, int>(date_time).create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QDateTime(const QDate &, const QTime &, const QTimeZone &);
  bind::constructor<QDateTime, const QDate &, const QTime &, const QTimeZone &>(date_time).create();
#endif
  // QDateTime(const QDateTime &);
  bind::constructor<QDateTime, const QDateTime &>(date_time).create();
  // QDateTime(QDateTime &&);
  bind::constructor<QDateTime, QDateTime &&>(date_time).create();
  // ~QDateTime();
  bind::destructor<QDateTime>(date_time).create();
  // QDateTime & operator=(QDateTime &&);
  bind::memop_assign<QDateTime, QDateTime &&>(date_time);
  // QDateTime & operator=(const QDateTime &);
  bind::memop_assign<QDateTime, const QDateTime &>(date_time);
  // void swap(QDateTime &);
  bind::void_member_function<QDateTime, QDateTime &, &QDateTime::swap>(date_time, "swap").create();
  // bool isNull() const;
  bind::member_function<QDateTime, bool, &QDateTime::isNull>(date_time, "isNull").create();
  // bool isValid() const;
  bind::member_function<QDateTime, bool, &QDateTime::isValid>(date_time, "isValid").create();
  // QDate date() const;
  bind::member_function<QDateTime, QDate, &QDateTime::date>(date_time, "date").create();
  // QTime time() const;
  bind::member_function<QDateTime, QTime, &QDateTime::time>(date_time, "time").create();
  // Qt::TimeSpec timeSpec() const;
  bind::member_function<QDateTime, Qt::TimeSpec, &QDateTime::timeSpec>(date_time, "timeSpec").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // int offsetFromUtc() const;
  bind::member_function<QDateTime, int, &QDateTime::offsetFromUtc>(date_time, "offsetFromUtc").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QTimeZone timeZone() const;
  bind::member_function<QDateTime, QTimeZone, &QDateTime::timeZone>(date_time, "timeZone").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QString timeZoneAbbreviation() const;
  bind::member_function<QDateTime, QString, &QDateTime::timeZoneAbbreviation>(date_time, "timeZoneAbbreviation").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // bool isDaylightTime() const;
  bind::member_function<QDateTime, bool, &QDateTime::isDaylightTime>(date_time, "isDaylightTime").create();
#endif
  // qint64 toMSecsSinceEpoch() const;
  /// TODO: qint64 toMSecsSinceEpoch() const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // qint64 toSecsSinceEpoch() const;
  /// TODO: qint64 toSecsSinceEpoch() const;
#endif
  // void setDate(const QDate &);
  bind::void_member_function<QDateTime, const QDate &, &QDateTime::setDate>(date_time, "setDate").create();
  // void setTime(const QTime &);
  bind::void_member_function<QDateTime, const QTime &, &QDateTime::setTime>(date_time, "setTime").create();
  // void setTimeSpec(Qt::TimeSpec);
  bind::void_member_function<QDateTime, Qt::TimeSpec, &QDateTime::setTimeSpec>(date_time, "setTimeSpec").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // void setOffsetFromUtc(int);
  bind::void_member_function<QDateTime, int, &QDateTime::setOffsetFromUtc>(date_time, "setOffsetFromUtc").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // void setTimeZone(const QTimeZone &);
  bind::void_member_function<QDateTime, const QTimeZone &, &QDateTime::setTimeZone>(date_time, "setTimeZone").create();
#endif
  // void setMSecsSinceEpoch(qint64);
  /// TODO: void setMSecsSinceEpoch(qint64);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // void setSecsSinceEpoch(qint64);
  /// TODO: void setSecsSinceEpoch(qint64);
#endif
  // QString toString(Qt::DateFormat = Qt::TextDate) const;
  bind::member_function<QDateTime, QString, Qt::DateFormat, &QDateTime::toString>(date_time, "toString")
    .apply(bind::default_arguments(Qt::TextDate)).create();
  // QString toString(const QString &) const;
  bind::member_function<QDateTime, QString, const QString &, &QDateTime::toString>(date_time, "toString").create();
  // QString toString(QStringView) const;
  /// TODO: QString toString(QStringView) const;
  // QDateTime addDays(qint64) const;
  /// TODO: QDateTime addDays(qint64) const;
  // QDateTime addMonths(int) const;
  bind::member_function<QDateTime, QDateTime, int, &QDateTime::addMonths>(date_time, "addMonths").create();
  // QDateTime addYears(int) const;
  bind::member_function<QDateTime, QDateTime, int, &QDateTime::addYears>(date_time, "addYears").create();
  // QDateTime addSecs(qint64) const;
  /// TODO: QDateTime addSecs(qint64) const;
  // QDateTime addMSecs(qint64) const;
  /// TODO: QDateTime addMSecs(qint64) const;
  // QDateTime toTimeSpec(Qt::TimeSpec) const;
  bind::member_function<QDateTime, QDateTime, Qt::TimeSpec, &QDateTime::toTimeSpec>(date_time, "toTimeSpec").create();
  // QDateTime toLocalTime() const;
  bind::member_function<QDateTime, QDateTime, &QDateTime::toLocalTime>(date_time, "toLocalTime").create();
  // QDateTime toUTC() const;
  bind::member_function<QDateTime, QDateTime, &QDateTime::toUTC>(date_time, "toUTC").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QDateTime toOffsetFromUtc(int) const;
  bind::member_function<QDateTime, QDateTime, int, &QDateTime::toOffsetFromUtc>(date_time, "toOffsetFromUtc").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QDateTime toTimeZone(const QTimeZone &) const;
  bind::member_function<QDateTime, QDateTime, const QTimeZone &, &QDateTime::toTimeZone>(date_time, "toTimeZone").create();
#endif
  // qint64 daysTo(const QDateTime &) const;
  /// TODO: qint64 daysTo(const QDateTime &) const;
  // qint64 secsTo(const QDateTime &) const;
  /// TODO: qint64 secsTo(const QDateTime &) const;
  // qint64 msecsTo(const QDateTime &) const;
  /// TODO: qint64 msecsTo(const QDateTime &) const;
  // bool operator==(const QDateTime &) const;
  bind::memop_eq<QDateTime, const QDateTime &>(date_time);
  // bool operator!=(const QDateTime &) const;
  bind::memop_neq<QDateTime, const QDateTime &>(date_time);
  // bool operator<(const QDateTime &) const;
  bind::memop_less<QDateTime, const QDateTime &>(date_time);
  // bool operator<=(const QDateTime &) const;
  bind::memop_leq<QDateTime, const QDateTime &>(date_time);
  // bool operator>(const QDateTime &) const;
  bind::memop_greater<QDateTime, const QDateTime &>(date_time);
  // bool operator>=(const QDateTime &) const;
  bind::memop_geq<QDateTime, const QDateTime &>(date_time);
  // void setUtcOffset(int);
  bind::void_member_function<QDateTime, int, &QDateTime::setUtcOffset>(date_time, "setUtcOffset").create();
  // int utcOffset() const;
  bind::member_function<QDateTime, int, &QDateTime::utcOffset>(date_time, "utcOffset").create();
  // static QDateTime currentDateTime();
  bind::static_member_function<QDateTime, QDateTime, &QDateTime::currentDateTime>(date_time, "currentDateTime").create();
  // static QDateTime currentDateTimeUtc();
  bind::static_member_function<QDateTime, QDateTime, &QDateTime::currentDateTimeUtc>(date_time, "currentDateTimeUtc").create();
  // static QDateTime fromString(const QString &, Qt::DateFormat = Qt::TextDate);
  bind::static_member_function<QDateTime, QDateTime, const QString &, Qt::DateFormat, &QDateTime::fromString>(date_time, "fromString")
    .apply(bind::default_arguments(Qt::TextDate)).create();
  // static QDateTime fromString(const QString &, const QString &);
  bind::static_member_function<QDateTime, QDateTime, const QString &, const QString &, &QDateTime::fromString>(date_time, "fromString").create();
  // uint toTime_t() const;
  bind::member_function<QDateTime, uint, &QDateTime::toTime_t>(date_time, "toTime_t").create();
  // void setTime_t(uint);
  bind::void_member_function<QDateTime, uint, &QDateTime::setTime_t>(date_time, "setTime_t").create();
  // static QDateTime fromTime_t(uint);
  bind::static_member_function<QDateTime, QDateTime, uint, &QDateTime::fromTime_t>(date_time, "fromTime_t").create();
  // static QDateTime fromTime_t(uint, Qt::TimeSpec, int);
  bind::static_member_function<QDateTime, QDateTime, uint, Qt::TimeSpec, int, &QDateTime::fromTime_t>(date_time, "fromTime_t").create();
  // static QDateTime fromTime_t(uint, const QTimeZone &);
  bind::static_member_function<QDateTime, QDateTime, uint, const QTimeZone &, &QDateTime::fromTime_t>(date_time, "fromTime_t").create();
  // static QDateTime fromMSecsSinceEpoch(qint64);
  /// TODO: static QDateTime fromMSecsSinceEpoch(qint64);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // static QDateTime fromMSecsSinceEpoch(qint64, Qt::TimeSpec, int = 0);
  /// TODO: static QDateTime fromMSecsSinceEpoch(qint64, Qt::TimeSpec, int = 0);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // static QDateTime fromSecsSinceEpoch(qint64, Qt::TimeSpec = Qt::LocalTime, int = 0);
  /// TODO: static QDateTime fromSecsSinceEpoch(qint64, Qt::TimeSpec = Qt::LocalTime, int = 0);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // static QDateTime fromMSecsSinceEpoch(qint64, const QTimeZone &);
  /// TODO: static QDateTime fromMSecsSinceEpoch(qint64, const QTimeZone &);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // static QDateTime fromSecsSinceEpoch(qint64, const QTimeZone &);
  /// TODO: static QDateTime fromSecsSinceEpoch(qint64, const QTimeZone &);
#endif
  // static qint64 currentMSecsSinceEpoch();
  /// TODO: static qint64 currentMSecsSinceEpoch();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // static qint64 currentSecsSinceEpoch();
  /// TODO: static qint64 currentSecsSinceEpoch();
#endif

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QDateTime, QMetaType::QDateTime>>();
}


void register_datetime_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_date_class(ns);
  register_time_class(ns);
  register_date_time_class(ns);

  // void swap(QDateTime &, QDateTime &);
  bind::void_function<QDateTime &, QDateTime &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QDate &);
  bind::op_put_to<QDataStream &, const QDate &>(ns);
  // QDataStream & operator>>(QDataStream &, QDate &);
  bind::op_read_from<QDataStream &, QDate &>(ns);
  // QDataStream & operator<<(QDataStream &, const QTime &);
  bind::op_put_to<QDataStream &, const QTime &>(ns);
  // QDataStream & operator>>(QDataStream &, QTime &);
  bind::op_read_from<QDataStream &, QTime &>(ns);
  // QDataStream & operator<<(QDataStream &, const QDateTime &);
  bind::op_put_to<QDataStream &, const QDateTime &>(ns);
  // QDataStream & operator>>(QDataStream &, QDateTime &);
  bind::op_read_from<QDataStream &, QDateTime &>(ns);
  // QDebug operator<<(QDebug, const QDate &);
  /// TODO: QDebug operator<<(QDebug, const QDate &);
  // QDebug operator<<(QDebug, const QTime &);
  /// TODO: QDebug operator<<(QDebug, const QTime &);
  // QDebug operator<<(QDebug, const QDateTime &);
  /// TODO: QDebug operator<<(QDebug, const QDateTime &);
  // uint qHash(const QDateTime &, uint);
  bind::function<uint, const QDateTime &, uint, &qHash>(ns, "qHash").create();
  // uint qHash(const QDate &, uint);
  bind::function<uint, const QDate &, uint, &qHash>(ns, "qHash").create();
  // uint qHash(const QTime &, uint);
  bind::function<uint, const QTime &, uint, &qHash>(ns, "qHash").create();
}

