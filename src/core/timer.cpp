// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/timer.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/binding/qsignal.h"

#include "yasl/core/enums.h"
#include "yasl/core/object.h"

// Cannot bind if 'static'
void single_shot(int time, const QObject *obj, const QString & name)
{
  QTimer::singleShot(time, obj, name.toUtf8().data());
}

// Cannot bind if 'static'
void single_shot(int time, Qt::TimerType tt, const QObject *obj, const QString & name)
{
  QTimer::singleShot(time, tt, obj, name.toUtf8().data());
}

namespace callbacks
{

static script::Value new_timer(script::FunctionCall *c)
{
  using namespace script;
  Value v = c->engine()->uninitialized(Type::QTimer);
  QTimer *timer = new QTimer(binding::value_cast<QObject*>(c->arg(0)));
  v.impl()->set_qobject(timer);
  c->engine()->bind(v, timer);
  v.impl()->type = v.impl()->type.withoutFlag(Type::UninitializedFlag);
  return v;
}

} // namespace callbacks

static void register_timer_class(script::Namespace ns)
{
  using namespace script;

  Class timer = ns.newClass(ClassBuilder::New("Timer").setId(script::Type::QTimer)
  .setParent(ns.engine()->getClass(script::Type::QObject)));

  binding::QClass<QTimer> binder{ timer };
  binding::Class<QTimer> static_binder{ timer };

  // ~QTimer();
  binder.add_dtor();
  // QTimer(QObject *);
  binder.ctors().add<QObject *>();
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
  /// ignore: static_binder.add_static_void_fun<int, const QObject *, const char *, &QTimer::singleShot>("singleShot");
  static_binder.add_static_void_fun<int, const QObject *, const QString &, &single_shot>("singleShot");
  // static void singleShot(int, Qt::TimerType, const QObject *, const char *);
  /// ignore: static_binder.add_static_void_fun<int, Qt::TimerType, const QObject *, const char *, &QTimer::singleShot>("singleShot");
  static_binder.add_static_void_fun<int, Qt::TimerType, const QObject *, const QString &, &single_shot>("singleShot");
  // void start(int);
  binder.add_void_fun<int, &QTimer::start>("start");
  // void start();
  binder.add_void_fun<&QTimer::start>("start");
  // void stop();
  binder.add_void_fun<&QTimer::stop>("stop");
  // void timeout(QTimer::QPrivateSignal);
  /// ignore: binder.add_void_fun<QTimer::QPrivateSignal, &QTimer::timeout>("timeout");
  // void setInterval(std::chrono::milliseconds);
  /// ignore: binder.add_void_fun<std::chrono::milliseconds, &QTimer::setInterval>("setInterval");
  // std::chrono::milliseconds intervalAsDuration() const;
  /// ignore: binder.add_fun<std::chrono::milliseconds, &QTimer::intervalAsDuration>("intervalAsDuration");
  // std::chrono::milliseconds remainingTimeAsDuration() const;
  /// ignore: binder.add_fun<std::chrono::milliseconds, &QTimer::remainingTimeAsDuration>("remainingTimeAsDuration");
  // static void singleShot(std::chrono::milliseconds, const QObject *, const char *);
  /// ignore: binder.add_void_fun<std::chrono::milliseconds, const QObject *, const char *, &QTimer::singleShot>("singleShot");
  // static void singleShot(std::chrono::milliseconds, Qt::TimerType, const QObject *, const char *);
  /// ignore: binder.add_void_fun<std::chrono::milliseconds, Qt::TimerType, const QObject *, const char *, &QTimer::singleShot>("singleShot");
  // void start(std::chrono::milliseconds);
  /// ignore: binder.add_void_fun<std::chrono::milliseconds, &QTimer::start>("start");

  /* Signals */
  binding::QSignal sigs{ timer, &QTimer::staticMetaObject };
  // void timeout();
  sigs.add("timeout", "timeout()");

  auto new_timer = ns.Function("newTimer", callbacks::new_timer)
    .returns(Type::ref(Type::QTimer))
    .params(binding::make_type<QObject*>())
    .create();

  ns.engine()->registerQtType(&QTimer::staticMetaObject, timer.id());
}

void register_timer_file(script::Namespace root)
{
  using namespace script;

  register_timer_class(root);
  binding::Namespace binder{ root };

}

