// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/time.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/enums.h"

#include <script/engine.h>

void register_time_class(script::Namespace ns)
{
  using namespace script;

  Class time = ns.newClass(ClassBuilder::New("Time").setId(Type::QTime).setFinal());

  binding::Class<QTime> binder{ time };

  // ~QTime();
  binder.add_dtor();


  /* Public member functions */

  // QTime addMSecs(int ms) const
  binder.add_fun<QTime, int, &QTime::addMSecs>("addMSecs");
  // QTime addSecs(int s) const
  binder.add_fun<QTime, int, &QTime::addSecs>("addSecs");
  // int elapsed() const
  binder.add_fun<int, &QTime::elapsed>("elapsed");
  // int hour() const
  binder.add_fun<int, &QTime::hour>("hour");
  // bool isNull() const
  binder.add_fun<bool, &QTime::isNull>("isNull");
  // bool isValid() const
  binder.add_fun<bool, &QTime::isValid>("isValid");
  // int minute() const
  binder.add_fun<int, &QTime::minute>("minute");
  // int msec() const
  binder.add_fun<int, &QTime::msec>("msec");
  // int msecsSinceStartOfDay() const
  binder.add_fun<int, &QTime::msecsSinceStartOfDay>("msecsSinceStartOfDay");
  // int msecsTo(const QTime &t) const
  binder.add_fun<int, const QTime &, &QTime::msecsTo>("msecsTo");
  // int restart()
  binder.add_fun<int, &QTime::restart>("restart");
  // int second() const
  binder.add_fun<int, &QTime::second>("second");
  // int secsTo(const QTime &t) const
  binder.add_fun<int, const QTime &, &QTime::secsTo>("secsTo");
  // bool setHMS(int h, int m, int s, int ms = 0)
  binder.add_fun<bool, int, int, int, int, &QTime::setHMS>("setHMS");
  // void start()
  binder.add_void_fun<&QTime::start>("start");
  // QString toString(const QString &format) const
  binder.add_fun<QString, const QString &, &QTime::toString>("toString");
  // QString toString(Qt::DateFormat format = Qt::TextDate) const
  binder.add_fun<QString, Qt::DateFormat, &QTime::toString>("toString");
  // QString toString(QStringView format) const
  /// binder.add_fun<QString, QStringView, &QTime::toString>("toString");
  // bool operator!=(const QTime &t) const
  /// TODO !!!
  // bool operator<(const QTime &t) const
  /// TODO !!!
  // bool operator<=(const QTime &t) const
  /// TODO !!!
  // bool operator==(const QTime &t) const
  /// TODO !!!
  // bool operator>(const QTime &t) const
  /// TODO !!!
  // bool operator>=(const QTime &t) const
  /// TODO !!!


  /* Static public members */

  // static QTime currentTime()
  binder.add_static<QTime, &QTime::currentTime>("currentTime");
  // static QTime fromMSecsSinceStartOfDay(int msecs)
  binder.add_static<QTime, int, &QTime::fromMSecsSinceStartOfDay>("fromMSecsSinceStartOfDay");
  // static QTime fromString(const QString &string, Qt::DateFormat format = Qt::TextDate)
  binder.add_static<QTime, const QString &, Qt::DateFormat, &QTime::fromString>("fromString");
  // static QTime fromString(const QString &string, const QString &format)
  binder.add_static<QTime, const QString &, const QString &, &QTime::fromString>("fromString");
  // static bool isValid(int h, int m, int s, int ms = 0)
  binder.add_static<bool, int, int, int, int, &QTime::isValid>("isValid");


  /* Related non-members */
  binding::Namespace related{ ns };
  // QDataStream & operator<<(QDataStream &out, const QTime &time)
  /// TODO !!!
  // QDataStream & operator>>(QDataStream &in, QTime &time)
  /// TODO !!!

}
