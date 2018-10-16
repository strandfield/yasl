// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/object.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/listspecializations.h"
#include "yasl/utils/ref.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/enums.h"
#include "yasl/core/object.h"

#include <script/classbuilder.h>

static void register_object_class(script::Namespace ns)
{
  using namespace script;

  Class object = ns.Class("Object").setId(script::Type::QObject).get();

  register_ref_specialization(object.engine(), script::Type::QObject, script::Type::QObjectStar);
  register_ptr_specialization<QObject*>(object.engine()->getTemplate(Engine::PtrTemplate), script::Type::PtrQObject);
  register_list_specialization<QObject*>(object.engine(), script::Type::QListQObject);
  binding::QClass<QObject> binder{ object, &QObject::staticMetaObject };

  // const QMetaObject * metaObject() const;
  /// TODO: const QMetaObject * metaObject() const;
  // static QString tr(const char *, const char *, int);
  /// TODO: static QString tr(const char *, const char *, int);
  // static QString trUtf8(const char *, const char *, int);
  /// TODO: static QString trUtf8(const char *, const char *, int);
  // QObject(QObject *);
  binder.ctors().ctor<QObject *>().create();
  // ~QObject();
  binder.add_dtor();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // bool eventFilter(QObject *, QEvent *);
  /// TODO: bool eventFilter(QObject *, QEvent *);
  // QString objectName() const;
  binder.fun<QString, &QObject::objectName>("objectName").create();
  // void setObjectName(const QString &);
  binder.void_fun<const QString &, &QObject::setObjectName>("setObjectName").create();
  // bool isWidgetType() const;
  binder.fun<bool, &QObject::isWidgetType>("isWidgetType").create();
  // bool isWindowType() const;
  binder.fun<bool, &QObject::isWindowType>("isWindowType").create();
  // bool signalsBlocked() const;
  binder.fun<bool, &QObject::signalsBlocked>("signalsBlocked").create();
  // bool blockSignals(bool);
  binder.fun<bool, bool, &QObject::blockSignals>("blockSignals").create();
  // QThread * thread() const;
  /// TODO: QThread * thread() const;
  // void moveToThread(QThread *);
  /// TODO: void moveToThread(QThread *);
  // int startTimer(int, Qt::TimerType);
  binder.fun<int, int, Qt::TimerType, &QObject::startTimer>("startTimer").create();
  // int startTimer(std::chrono::milliseconds, Qt::TimerType);
  /// TODO: int startTimer(std::chrono::milliseconds, Qt::TimerType);
  // void killTimer(int);
  binder.void_fun<int, &QObject::killTimer>("killTimer").create();
  // const QObjectList & children() const;
  binder.fun<const QObjectList &, &QObject::children>("children").create();
  // void setParent(QObject *);
  binder.void_fun<QObject *, &QObject::setParent>("setParent").create();
  // void installEventFilter(QObject *);
  binder.void_fun<QObject *, &QObject::installEventFilter>("installEventFilter").create();
  // void removeEventFilter(QObject *);
  binder.void_fun<QObject *, &QObject::removeEventFilter>("removeEventFilter").create();
  // static QMetaObject::Connection connect(const QObject *, const char *, const QObject *, const char *, Qt::ConnectionType);
  /// TODO: static QMetaObject::Connection connect(const QObject *, const char *, const QObject *, const char *, Qt::ConnectionType);
  // static QMetaObject::Connection connect(const QObject *, const QMetaMethod &, const QObject *, const QMetaMethod &, Qt::ConnectionType);
  /// TODO: static QMetaObject::Connection connect(const QObject *, const QMetaMethod &, const QObject *, const QMetaMethod &, Qt::ConnectionType);
  // QMetaObject::Connection connect(const QObject *, const char *, const char *, Qt::ConnectionType) const;
  /// TODO: QMetaObject::Connection connect(const QObject *, const char *, const char *, Qt::ConnectionType) const;
  // static bool disconnect(const QObject *, const char *, const QObject *, const char *);
  /// TODO: static bool disconnect(const QObject *, const char *, const QObject *, const char *);
  // static bool disconnect(const QObject *, const QMetaMethod &, const QObject *, const QMetaMethod &);
  /// TODO: static bool disconnect(const QObject *, const QMetaMethod &, const QObject *, const QMetaMethod &);
  // bool disconnect(const char *, const QObject *, const char *) const;
  /// TODO: bool disconnect(const char *, const QObject *, const char *) const;
  // bool disconnect(const QObject *, const char *) const;
  /// TODO: bool disconnect(const QObject *, const char *) const;
  // static bool disconnect(const QMetaObject::Connection &);
  /// TODO: static bool disconnect(const QMetaObject::Connection &);
  // void dumpObjectTree() const;
  binder.const_void_fun<&QObject::dumpObjectTree>("dumpObjectTree").create();
  // void dumpObjectInfo() const;
  binder.const_void_fun<&QObject::dumpObjectInfo>("dumpObjectInfo").create();
  // bool setProperty(const char *, const QVariant &);
  /// TODO: bool setProperty(const char *, const QVariant &);
  // QVariant property(const char *) const;
  /// TODO: QVariant property(const char *) const;
  // QList<QByteArray> dynamicPropertyNames() const;
  binder.fun<QList<QByteArray>, &QObject::dynamicPropertyNames>("dynamicPropertyNames").create();
  // void destroyed(QObject *);
  binder.sigs().add<QObject *>("destroyed", "destroyed(QObject *)");
  // QObject * parent() const;
  binder.fun<QObject *, &QObject::parent>("parent").create();
  // bool inherits(const char *) const;
  /// TODO: bool inherits(const char *) const;
  // void deleteLater();
  binder.void_fun<&QObject::deleteLater>("deleteLater").create();

  object.engine()->registerQtType(&QObject::staticMetaObject, object.id());
}


static void register_signal_blocker_class(script::Namespace ns)
{
  using namespace script;

  Class signal_blocker = ns.Class("SignalBlocker").setId(script::Type::QSignalBlocker).get();

  binding::Class<QSignalBlocker> binder{ signal_blocker };

  // QSignalBlocker(QObject *);
  binder.ctors().ctor<QObject *>().create();
  // QSignalBlocker(QObject &);
  binder.ctors().ctor<QObject &>().create();
  // ~QSignalBlocker();
  binder.add_dtor();
  // QSignalBlocker(QSignalBlocker &&);
  binder.ctors().ctor<QSignalBlocker &&>().create();
  // QSignalBlocker & operator=(QSignalBlocker &&);
  binder.operators().assign<QSignalBlocker &&>();
  // void reblock();
  binder.void_fun<&QSignalBlocker::reblock>("reblock").create();
  // void unblock();
  binder.void_fun<&QSignalBlocker::unblock>("unblock").create();
}


void register_object_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_object_class(ns);
  register_signal_blocker_class(ns);
  binding::Namespace binder{ ns };

  // QDebug operator<<(QDebug, const QObject *);
  /// TODO: QDebug operator<<(QDebug, const QObject *);
}

