// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/elapsedtimer.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

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
  binding::ClassBinder<QElapsedTimer> binder{ elapsed_timer };

  // QElapsedTimer();
  binder.default_ctor().create();
  // ~QElapsedTimer();
  binder.dtor().create();
  // static QElapsedTimer::ClockType clockType();
  binder.static_fun<QElapsedTimer::ClockType, &QElapsedTimer::clockType>("clockType").create();
  // static bool isMonotonic();
  binder.static_fun<bool, &QElapsedTimer::isMonotonic>("isMonotonic").create();
  // void start();
  binder.void_fun<&QElapsedTimer::start>("start").create();
  // qint64 restart();
  /// TODO: qint64 restart();
  // void invalidate();
  binder.void_fun<&QElapsedTimer::invalidate>("invalidate").create();
  // bool isValid() const;
  binder.fun<bool, &QElapsedTimer::isValid>("isValid").create();
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
  binder.operators().eq<const QElapsedTimer &>();
  // bool operator!=(const QElapsedTimer &) const;
  binder.operators().neq<const QElapsedTimer &>();
}


void register_elapsedtimer_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_elapsed_timer_class(ns);
  binding::Namespace binder{ ns };

}

