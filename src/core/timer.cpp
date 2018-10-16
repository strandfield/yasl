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
  binder.ctors().ctor<QObject *>().create();
  // ~QTimer();
  binder.add_dtor();
  // bool isActive() const;
  binder.fun<bool, &QTimer::isActive>("isActive").create();
  // int timerId() const;
  binder.fun<int, &QTimer::timerId>("timerId").create();
  // void setInterval(int);
  binder.void_fun<int, &QTimer::setInterval>("setInterval").create();
  // int interval() const;
  binder.fun<int, &QTimer::interval>("interval").create();
  // int remainingTime() const;
  binder.fun<int, &QTimer::remainingTime>("remainingTime").create();
  // void setTimerType(Qt::TimerType);
  binder.void_fun<Qt::TimerType, &QTimer::setTimerType>("setTimerType").create();
  // Qt::TimerType timerType() const;
  binder.fun<Qt::TimerType, &QTimer::timerType>("timerType").create();
  // void setSingleShot(bool);
  binder.void_fun<bool, &QTimer::setSingleShot>("setSingleShot").create();
  // bool isSingleShot() const;
  binder.fun<bool, &QTimer::isSingleShot>("isSingleShot").create();
  // static void singleShot(int, const QObject *, const char *);
  /// TODO: static void singleShot(int, const QObject *, const char *);
  // static void singleShot(int, Qt::TimerType, const QObject *, const char *);
  /// TODO: static void singleShot(int, Qt::TimerType, const QObject *, const char *);
  // void start(int);
  binder.void_fun<int, &QTimer::start>("start").create();
  // void start();
  binder.void_fun<&QTimer::start>("start").create();
  // void stop();
  binder.void_fun<&QTimer::stop>("stop").create();
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

