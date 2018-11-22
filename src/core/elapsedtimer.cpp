// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/elapsedtimer.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"

#include "yasl/core/elapsedtimer.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_elapsed_timer_clock_type_enum(script::Class elapsed_timer)
{
  using namespace script;

  Enum clock_type = elapsed_timer.newEnum("ClockType").setId(script::Type::QElapsedTimerClockType).get();

  clock_type.addValue("SystemTime", QElapsedTimer::SystemTime);
  clock_type.addValue("MonotonicClock", QElapsedTimer::MonotonicClock);
  clock_type.addValue("TickCounter", QElapsedTimer::TickCounter);
  clock_type.addValue("MachAbsoluteTime", QElapsedTimer::MachAbsoluteTime);
  clock_type.addValue("PerformanceCounter", QElapsedTimer::PerformanceCounter);
}


static void register_elapsed_timer_class(script::Namespace ns)
{
  using namespace script;

  Class elapsed_timer = ns.newClass("ElapsedTimer").setId(script::Type::QElapsedTimer).get();

  register_elapsed_timer_clock_type_enum(elapsed_timer);

  // QElapsedTimer();
  bind::default_constructor<QElapsedTimer>(elapsed_timer).create();
  // ~QElapsedTimer();
  bind::destructor<QElapsedTimer>(elapsed_timer).create();
  // static QElapsedTimer::ClockType clockType();
  bind::static_member_function<QElapsedTimer, QElapsedTimer::ClockType, &QElapsedTimer::clockType>(elapsed_timer, "clockType").create();
  // static bool isMonotonic();
  bind::static_member_function<QElapsedTimer, bool, &QElapsedTimer::isMonotonic>(elapsed_timer, "isMonotonic").create();
  // void start();
  bind::void_member_function<QElapsedTimer, &QElapsedTimer::start>(elapsed_timer, "start").create();
  // qint64 restart();
  /// TODO: qint64 restart();
  // void invalidate();
  bind::void_member_function<QElapsedTimer, &QElapsedTimer::invalidate>(elapsed_timer, "invalidate").create();
  // bool isValid() const;
  bind::member_function<QElapsedTimer, bool, &QElapsedTimer::isValid>(elapsed_timer, "isValid").create();
  // qint64 nsecsElapsed() const;
  /// TODO: qint64 nsecsElapsed() const;
  // qint64 elapsed() const;
  /// TODO: qint64 elapsed() const;
  // bool hasExpired(qint64) const;
  /// TODO: bool hasExpired(qint64) const;
  // qint64 msecsSinceReference() const;
  /// TODO: qint64 msecsSinceReference() const;
  // qint64 msecsTo(const QElapsedTimer &) const;
  /// TODO: qint64 msecsTo(const QElapsedTimer &) const;
  // qint64 secsTo(const QElapsedTimer &) const;
  /// TODO: qint64 secsTo(const QElapsedTimer &) const;
  // bool operator==(const QElapsedTimer &) const;
  bind::memop_eq<QElapsedTimer, const QElapsedTimer &>(elapsed_timer);
  // bool operator!=(const QElapsedTimer &) const;
  bind::memop_neq<QElapsedTimer, const QElapsedTimer &>(elapsed_timer);
}


void register_elapsedtimer_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_elapsed_timer_class(ns);

}

