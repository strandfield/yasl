// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/timer.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/object.h"

#include <script/classbuilder.h>

static void register_timer_class(script::Namespace ns)
{
  using namespace script;

  Class timer = ns.newClass("Timer").setId(script::Type::QTimer)
    .setBase(script::Type::QObject).get();


  // QTimer(QObject *);
  bind::constructor<QTimer, QObject *>(timer)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // ~QTimer();
  bind::destructor<QTimer>(timer).create();
  // bool isActive() const;
  bind::member_function<QTimer, bool, &QTimer::isActive>(timer, "isActive").create();
  // int timerId() const;
  bind::member_function<QTimer, int, &QTimer::timerId>(timer, "timerId").create();
  // void setInterval(int);
  bind::void_member_function<QTimer, int, &QTimer::setInterval>(timer, "setInterval").create();
  // int interval() const;
  bind::member_function<QTimer, int, &QTimer::interval>(timer, "interval").create();
  // int remainingTime() const;
  bind::member_function<QTimer, int, &QTimer::remainingTime>(timer, "remainingTime").create();
  // void setTimerType(Qt::TimerType);
  bind::void_member_function<QTimer, Qt::TimerType, &QTimer::setTimerType>(timer, "setTimerType").create();
  // Qt::TimerType timerType() const;
  bind::member_function<QTimer, Qt::TimerType, &QTimer::timerType>(timer, "timerType").create();
  // void setSingleShot(bool);
  bind::void_member_function<QTimer, bool, &QTimer::setSingleShot>(timer, "setSingleShot").create();
  // bool isSingleShot() const;
  bind::member_function<QTimer, bool, &QTimer::isSingleShot>(timer, "isSingleShot").create();
  // static void singleShot(int, const QObject *, const char *);
  /// TODO: static void singleShot(int, const QObject *, const char *);
  // static void singleShot(int, Qt::TimerType, const QObject *, const char *);
  /// TODO: static void singleShot(int, Qt::TimerType, const QObject *, const char *);
  // void start(int);
  bind::void_member_function<QTimer, int, &QTimer::start>(timer, "start").create();
  // void start();
  bind::void_member_function<QTimer, &QTimer::start>(timer, "start").create();
  // void stop();
  bind::void_member_function<QTimer, &QTimer::stop>(timer, "stop").create();
  // void timeout();
  bind::signal<QTimer>(timer, "timeout", "timeout()");
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

  bind::link(timer, &QTimer::staticMetaObject);
}


void register_timer_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_timer_class(ns);

}

