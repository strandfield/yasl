// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/date.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/enums.h"

#include <script/engine.h>

void register_date_class(script::Namespace ns)
{
  using namespace script;

  Class date = ns.newClass(ClassBuilder::New("Date").setId(Type::QDate).setFinal());

  binding::Class<QDate> binder{ date };

  // ~QDate();
  binder.add_dtor();

  
  /* Public member functions */

  // QDate addDays(qint64 ndays) const
  binder.add_fun<QDate, qint64, &QDate::addDays>("addDays");
  // QDate addMonths(int nmonths) const
  binder.add_fun<QDate, int, &QDate::addMonths>("addMonths");
  // QDate addYears(int nyears) const
  binder.add_fun<QDate, int, &QDate::addYears>("addYears");
  // int day() const
  binder.add_fun<int, &QDate::day>("day");
  // int dayOfWeek() const
  binder.add_fun<int, &QDate::dayOfWeek>("dayOfWeek");
  // int dayOfYear() const
  binder.add_fun<int, &QDate::dayOfYear>("dayOfYear");
  // int daysInMonth() const
  binder.add_fun<int, &QDate::daysInMonth>("daysInMonth");
  // int daysInYear() const
  binder.add_fun<int, &QDate::daysInYear>("daysInYear");
  // qint64 daysTo(const QDate &d) const
  binder.add_fun<qint64, const QDate &, &QDate::daysTo>("daysTo");
  // void getDate(int *year, int *month, int *day) const
  /// TODO !!!
  // bool isNull() const
  binder.add_fun<bool, &QDate::isNull>("isNull");
  // bool isValid() const
  binder.add_fun<bool, &QDate::isValid>("isValid");
  // int month() const
  binder.add_fun<int, &QDate::month>("month");
  // bool setDate(int year, int month, int day)
  binder.add_fun<bool, int, int, int, &QDate::setDate>("setDate");
  // qint64 toJulianDay() const
  binder.add_fun<qint64, &QDate::toJulianDay>("toJulianDay");
  // QString toString(const QString &format) const
  binder.add_fun<QString, const QString &, &QDate::toString>("toString");
  // QString toString(Qt::DateFormat format = Qt::TextDate) const
  binder.add_fun<QString, Qt::DateFormat, &QDate::toString>("toString");
  // QString toString(QStringView format) const
  /// binder.add_fun<QString, QStringView, &QDate::toString>("toString");
  // int weekNumber(int *yearNumber = nullptr) const
  /// TODO !!!
  // int year() const
  binder.add_fun<int, &QDate::year>("year");
  // bool operator!=(const QDate &d) const
  /// TODO !!!
  // bool operator<(const QDate &d) const
  /// TODO !!!
  // bool operator<=(const QDate &d) const
  /// TODO !!!
  // bool operator==(const QDate &d) const
  /// TODO !!!
  // bool operator>(const QDate &d) const
  /// TODO !!!
  // bool operator>=(const QDate &d) const
  /// TODO !!!


  /* Static public members */

  auto _ = binding::function_wrapper_t<decltype(&QDate::currentDate), &QDate::currentDate>::wrap;

  // static QDate currentDate()
  binder.add_static<QDate, &QDate::currentDate>("currentDate");
  // static QDate fromJulianDay(qint64 jd)
  binder.add_static<QDate, qint64, &QDate::fromJulianDay>("fromJulianDay");
  // static QDate fromString(const QString &string, Qt::DateFormat format = Qt::TextDate)
  binder.add_static<QDate, const QString &, Qt::DateFormat, &QDate::fromString>("fromString");
  // static QDate fromString(const QString &string, const QString &format)
  binder.add_static<QDate, const QString &, const QString &, &QDate::fromString>("fromString");
  // static bool isLeapYear(int year)
  binder.add_static<bool, int, &QDate::isLeapYear>("isLeapYear");
  // static bool isValid(int year, int month, int day)
  binder.add_static<bool, int, int, int, &QDate::isValid>("isValid");


  /* Related non-members */
  binding::Namespace related{ ns };
  // QDataStream & operator<<(QDataStream &out, const QDate &date)
  /// TODO !!!
  // QDataStream & operator>>(QDataStream &in, QDate &date)
  /// TODO !!!

}
