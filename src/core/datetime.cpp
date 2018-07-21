// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/datetime.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/macros.h"
#include "yasl/core/date.h"
#include "yasl/core/enums.h"
#include "yasl/core/time.h"
#include "yasl/core/timezone.h"

#include <script/classbuilder.h>
#include <script/engine.h>

void register_datetime_class(script::Namespace ns)
{
  using namespace script;

  Class datetime = ns.Class("DateTime").setId(Type::QDateTime).setFinal().get();

  binding::Class<QDateTime> binder{ datetime };

  // ~QDateTime();
  binder.add_dtor();

  
  /* Public member functions */

  // QDateTime addDays(qint64 ndays) const
  binder.add_fun<QDateTime, qint64, &QDateTime::addDays>("addDays");
  // QDateTime addMSecs(qint64 msecs) const
  binder.add_fun<QDateTime, qint64, &QDateTime::addMSecs>("addMSecs");
  // QDateTime addMonths(int nmonths) const
  binder.add_fun<QDateTime, int, &QDateTime::addMonths>("addMonths");
  // QDateTime addSecs(qint64 s) const
  binder.add_fun<QDateTime, qint64, &QDateTime::addSecs>("addSecs");
  // QDateTime addYears(int nyears) const
  binder.add_fun<QDateTime, int, &QDateTime::addYears>("addYears");
  // QDate date() const
  binder.add_fun<QDate, &QDateTime::date>("date");
  // qint64 daysTo(const QDateTime &other) const
  binder.add_fun<qint64, const QDateTime &, &QDateTime::daysTo>("daysTo");
  // bool isDaylightTime() const
  binder.add_fun<bool, &QDateTime::isDaylightTime>("isDaylightTime");
  // bool isNull() const
  binder.add_fun<bool, &QDateTime::isNull>("isNull");
  // bool isValid() const
  binder.add_fun<bool, &QDateTime::isValid>("isValid");
  // qint64 msecsTo(const QDateTime &other) const
  binder.add_fun<qint64, const QDateTime &, &QDateTime::msecsTo>("msecsTo");
  // int offsetFromUtc() const
  binder.add_fun<int, &QDateTime::offsetFromUtc>("offsetFromUtc");
  // qint64 secsTo(const QDateTime &other) const
  binder.add_fun<qint64, const QDateTime &, &QDateTime::secsTo>("secsTo");
  // void setDate(const QDate &date)
  binder.add_void_fun<const QDate &, &QDateTime::setDate>("setDate");
  // void setMSecsSinceEpoch(qint64 msecs)
  binder.add_void_fun<qint64, &QDateTime::setMSecsSinceEpoch>("setMSecsSinceEpoch");
  // void setOffsetFromUtc(int offsetSeconds)
  binder.add_void_fun<int, &QDateTime::setOffsetFromUtc>("setOffsetFromUtc");
  // void setSecsSinceEpoch(qint64 secs)
  binder.add_void_fun<qint64, &QDateTime::setSecsSinceEpoch>("setSecsSinceEpoch");
  // void setTime(const QTime &time)
  binder.add_void_fun<const QTime &, &QDateTime::setTime>("setTime");
  // void setTimeSpec(Qt::TimeSpec spec)
  binder.add_void_fun<Qt::TimeSpec, &QDateTime::setTimeSpec>("setTimeSpec");
  // void setTimeZone(const QTimeZone &toZone)
  binder.add_void_fun<const QTimeZone &, &QDateTime::setTimeZone>("setTimeZone");
  // void swap(QDateTime &other)
  binder.add_void_fun<QDateTime &, &QDateTime::swap>("swap");
  // QTime time() const
  binder.add_fun<QTime, &QDateTime::time>("time");
  // Qt::TimeSpec timeSpec() const
  binder.add_fun<Qt::TimeSpec, &QDateTime::timeSpec>("timeSpec");
  // QTimeZone timeZone() const
  binder.add_fun<QTimeZone, &QDateTime::timeZone>("timeZone");
  // QString timeZoneAbbreviation() const
  binder.add_fun<QString, &QDateTime::timeZoneAbbreviation>("timeZoneAbbreviation");
  // CFDateRef toCFDate() const
  ///binder.add_fun<CFDateRef, &QDateTime::toCFDate>("toCFDate");
  // QDateTime toLocalTime() const
  binder.add_fun<QDateTime, &QDateTime::toLocalTime>("toLocalTime");
  // qint64 toMSecsSinceEpoch() const
  binder.add_fun<qint64, &QDateTime::toMSecsSinceEpoch>("toMSecsSinceEpoch");
  // NSDate * toNSDate() const
  /// TODO !!!
  // QDateTime toOffsetFromUtc(int offsetSeconds) const
  binder.add_fun<QDateTime, int, &QDateTime::toOffsetFromUtc>("toOffsetFromUtc");
  // qint64 toSecsSinceEpoch() const
  binder.add_fun<qint64, &QDateTime::toSecsSinceEpoch>("toSecsSinceEpoch");
  // QString toString(const QString &format) const
  binder.add_fun<QString, const QString &, &QDateTime::toString>("toString");
  // QString toString(Qt::DateFormat format = Qt::TextDate) const
  binder.add_fun<QString, Qt::DateFormat, &QDateTime::toString>("toString");
  // QString toString(QStringView format) const
  /// binder.add_fun<QString, QStringView, &QDateTime::toString>("toString");
  // QDateTime toTimeSpec(Qt::TimeSpec spec) const
  binder.add_fun<QDateTime, Qt::TimeSpec, &QDateTime::toTimeSpec>("toTimeSpec");
  // QDateTime toTimeZone(const QTimeZone &timeZone) const
  binder.add_fun<QDateTime, const QTimeZone &, &QDateTime::toTimeZone>("toTimeZone");
  // QDateTime toUTC() const
  binder.add_fun<QDateTime, &QDateTime::toUTC>("toUTC");
  // bool operator!=(const QDateTime &other) const
  /// TODO !!!
  // bool operator<(const QDateTime &other) const
  /// TODO !!!
  // bool operator<=(const QDateTime &other) const
  /// TODO !!!
  // QDateTime & operator=(QDateTime &&other)
  /// TODO !!!
  // QDateTime & operator=(const QDateTime &other)
  /// TODO !!!
  // bool operator==(const QDateTime &other) const
  /// TODO !!!
  // bool operator>(const QDateTime &other) const
  /// TODO !!!
  // bool operator>=(const QDateTime &other) const
  /// TODO !!!

  
  /* Static public members */

  // static QDateTime currentDateTime()
  binder.add_static<QDateTime, QDateTime::currentDateTime>("currentDateTime");
  // static QDateTime currentDateTimeUtc()
  binder.add_static<QDateTime, &QDateTime::currentDateTimeUtc>("currentDateTimeUtc");
  // static qint64 currentMSecsSinceEpoch()
  binder.add_static<qint64, &QDateTime::currentMSecsSinceEpoch>("currentMSecsSinceEpoch");
  // static qint64 currentSecsSinceEpoch()
  binder.add_static<qint64, &QDateTime::currentSecsSinceEpoch>("currentSecsSinceEpoch");
  // static QDateTime fromCFDate(CFDateRef date)
  ///binder.add_static<QDateTime, CFDateRef, &QDateTime::fromCFDate>("fromCFDate");
  // static QDateTime fromMSecsSinceEpoch(qint64 msecs)
  binder.add_static<QDateTime, qint64, &QDateTime::fromMSecsSinceEpoch>("fromMSecsSinceEpoch");
  // static QDateTime fromMSecsSinceEpoch(qint64 msecs, Qt::TimeSpec spec, int offsetSeconds = 0)
  binder.add_static<QDateTime, qint64, Qt::TimeSpec, int, &QDateTime::fromMSecsSinceEpoch>("fromMSecsSinceEpoch");
  // static QDateTime fromMSecsSinceEpoch(qint64 msecs, const QTimeZone &timeZone)
  binder.add_static<QDateTime, qint64, const QTimeZone &, &QDateTime::fromMSecsSinceEpoch>("fromMSecsSinceEpoch");
  // static QDateTime fromNSDate(const NSDate *date)
  /// TODO !!!
  // static QDateTime fromSecsSinceEpoch(qint64 secs, Qt::TimeSpec spec = Qt::LocalTime, int offsetSeconds = 0)
  binder.add_static<QDateTime, qint64, Qt::TimeSpec, int, &QDateTime::fromSecsSinceEpoch>("fromSecsSinceEpoch");
  // static QDateTime fromSecsSinceEpoch(qint64 secs, const QTimeZone &timeZone)
  binder.add_static<QDateTime, qint64, const QTimeZone &, &QDateTime::fromSecsSinceEpoch>("fromSecsSinceEpoch");
  // static QDateTime fromString(const QString &string, Qt::DateFormat format = Qt::TextDate)
  binder.add_static<QDateTime, const QString &, Qt::DateFormat, &QDateTime::fromString>("fromString");
  // static QDateTime fromString(const QString &string, const QString &format)
  binder.add_static<QDateTime, const QString &, const QString &, &QDateTime::fromString>("fromString");

}
