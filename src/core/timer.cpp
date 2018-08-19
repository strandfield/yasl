// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/timer.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/object.h"

#include <script/classbuilder.h>

static void register_timer_class(script::Namespace ns)
{
  using namespace script;

  Class timer = ns.Class("Timer").setId(script::Type::QTimer)
    .setBase(script::Type::QObject).get();

  binding::QClass<QTimer> binder{ timer, &QTimer::staticMetaObject };

  // QTimer(QObject *);
  binder.ctors().add<QObject *>();
  // ~QTimer();
  binder.add_dtor();
  // bool isActive() const;
  binder.add_fun<bool, &QTimer::isActive>("isActive");
  // int timerId() const;
  binder.add_fun<int, &QTimer::timerId>("timerId");
  // void setInterval(int);
  binder.add_void_fun<int, &QTimer::setInterval>("setInterval");
  // int interval() const;
  binder.add_fun<int, &QTimer::interval>("interval");
  // int remainingTime() const;
  binder.add_fun<int, &QTimer::remainingTime>("remainingTime");
  // void setTimerType(Qt::TimerType);
  binder.add_void_fun<Qt::TimerType, &QTimer::setTimerType>("setTimerType");
  // Qt::TimerType timerType() const;
  binder.add_fun<Qt::TimerType, &QTimer::timerType>("timerType");
  // void setSingleShot(bool);
  binder.add_void_fun<bool, &QTimer::setSingleShot>("setSingleShot");
  // bool isSingleShot() const;
  binder.add_fun<bool, &QTimer::isSingleShot>("isSingleShot");
  // static void singleShot(int, const QObject *, const char *);
  /// TODO: static void singleShot(int, const QObject *, const char *);
  // static void singleShot(int, Qt::TimerType, const QObject *, const char *);
  /// TODO: static void singleShot(int, Qt::TimerType, const QObject *, const char *);
  // void start(int);
  binder.add_void_fun<int, &QTimer::start>("start");
  // void start();
  binder.add_void_fun<&QTimer::start>("start");
  // void stop();
  binder.add_void_fun<&QTimer::stop>("stop");
  // void timeout();
  binder.sigs().add("timeout", "timeout()");
  // void setInterval(std::chrono::milliseconds);
  /// TODO: void setInterval(std::chrono::milliseconds);
  // std::chrono::milliseconds intervalAsDuration() const;
  /// TODO: std::chrono::milliseconds intervalAsDuration() const;
  // std::chrono::milliseconds remainingTimeAsDuration() const;
  /// TODO: std::chrono::milliseconds remainingTimeAsDuration() const;
  // static void singleShot(std::chrono::milliseconds, const QObject *, const char *);
  /// TODO: static void singleShot(std::chrono::milliseconds, const QObject *, const char *);
  // static void singleShot(std::chrono::milliseconds, Qt::TimerType, const QObject *, const char *);
  /// TODO: static void singleShot(std::chrono::milliseconds, Qt::TimerType, const QObject *, const char *);
  // void start(std::chrono::milliseconds);
  /// TODO: void start(std::chrono::milliseconds);

  timer.engine()->registerQtType(&QTimer::staticMetaObject, timer.id());
}


void register_timer_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_timer_class(ns);
  binding::Namespace binder{ ns };

}

