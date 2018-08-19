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
  binder.ctors().add<QObject *>();
  // ~QObject();
  binder.add_dtor();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // bool eventFilter(QObject *, QEvent *);
  /// TODO: bool eventFilter(QObject *, QEvent *);
  // QString objectName() const;
  binder.add_fun<QString, &QObject::objectName>("objectName");
  // void setObjectName(const QString &);
  binder.add_void_fun<const QString &, &QObject::setObjectName>("setObjectName");
  // bool isWidgetType() const;
  binder.add_fun<bool, &QObject::isWidgetType>("isWidgetType");
  // bool isWindowType() const;
  binder.add_fun<bool, &QObject::isWindowType>("isWindowType");
  // bool signalsBlocked() const;
  binder.add_fun<bool, &QObject::signalsBlocked>("signalsBlocked");
  // bool blockSignals(bool);
  binder.add_fun<bool, bool, &QObject::blockSignals>("blockSignals");
  // QThread * thread() const;
  /// TODO: QThread * thread() const;
  // void moveToThread(QThread *);
  /// TODO: void moveToThread(QThread *);
  // int startTimer(int, Qt::TimerType);
  binder.add_fun<int, int, Qt::TimerType, &QObject::startTimer>("startTimer");
  // int startTimer(std::chrono::milliseconds, Qt::TimerType);
  /// TODO: int startTimer(std::chrono::milliseconds, Qt::TimerType);
  // void killTimer(int);
  binder.add_void_fun<int, &QObject::killTimer>("killTimer");
  // const QObjectList & children() const;
  binder.add_fun<const QObjectList &, &QObject::children>("children");
  // void setParent(QObject *);
  binder.add_void_fun<QObject *, &QObject::setParent>("setParent");
  // void installEventFilter(QObject *);
  binder.add_void_fun<QObject *, &QObject::installEventFilter>("installEventFilter");
  // void removeEventFilter(QObject *);
  binder.add_void_fun<QObject *, &QObject::removeEventFilter>("removeEventFilter");
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
  binder.add_const_void_fun<&QObject::dumpObjectTree>("dumpObjectTree");
  // void dumpObjectInfo() const;
  binder.add_const_void_fun<&QObject::dumpObjectInfo>("dumpObjectInfo");
  // bool setProperty(const char *, const QVariant &);
  /// TODO: bool setProperty(const char *, const QVariant &);
  // QVariant property(const char *) const;
  /// TODO: QVariant property(const char *) const;
  // QList<QByteArray> dynamicPropertyNames() const;
  binder.add_fun<QList<QByteArray>, &QObject::dynamicPropertyNames>("dynamicPropertyNames");
  // void destroyed(QObject *);
  binder.sigs().add<QObject *>("destroyed", "destroyed(QObject *)");
  // QObject * parent() const;
  binder.add_fun<QObject *, &QObject::parent>("parent");
  // bool inherits(const char *) const;
  /// TODO: bool inherits(const char *) const;
  // void deleteLater();
  binder.add_void_fun<&QObject::deleteLater>("deleteLater");

  object.engine()->registerQtType(&QObject::staticMetaObject, object.id());
}


static void register_signal_blocker_class(script::Namespace ns)
{
  using namespace script;

  Class signal_blocker = ns.Class("SignalBlocker").setId(script::Type::QSignalBlocker).get();

  binding::Class<QSignalBlocker> binder{ signal_blocker };

  // QSignalBlocker(QObject *);
  binder.ctors().add<QObject *>();
  // QSignalBlocker(QObject &);
  binder.ctors().add<QObject &>();
  // ~QSignalBlocker();
  binder.add_dtor();
  // QSignalBlocker(QSignalBlocker &&);
  binder.ctors().add<QSignalBlocker &&>();
  // QSignalBlocker & operator=(QSignalBlocker &&);
  binder.operators().assign<QSignalBlocker &&>();
  // void reblock();
  binder.add_void_fun<&QSignalBlocker::reblock>("reblock");
  // void unblock();
  binder.add_void_fun<&QSignalBlocker::unblock>("unblock");
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

