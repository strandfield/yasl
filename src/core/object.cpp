// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/object.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/listspecializations.h"
#include "yasl/common/ref.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/enums.h"
#include "yasl/core/object.h"

#include <script/classbuilder.h>

static void register_object_class(script::Namespace ns)
{
  using namespace script;

  Class object = ns.newClass("Object").setId(script::Type::QObject).get();

  register_ref_specialization(object.engine(), script::Type::QObject, script::Type::QObjectStar);
  register_proxy_specialization<QObject*>(object.engine()->getTemplate(Engine::ProxyTemplate), script::Type::ProxyQObject);
  register_list_specialization<QObject*>(object.engine(), script::Type::QListQObject);

  // const QMetaObject * metaObject() const;
  /// TODO: const QMetaObject * metaObject() const;
  // static QString tr(const char *, const char *, int);
  /// TODO: static QString tr(const char *, const char *, int);
  // static QString trUtf8(const char *, const char *, int);
  /// TODO: static QString trUtf8(const char *, const char *, int);
  // QObject(QObject * = (QObject*)nullptr);
  bind::constructor<QObject, QObject *>(object)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // ~QObject();
  bind::destructor<QObject>(object).create();
  // bool event(QEvent *);
  /// TODO: bool event(QEvent *);
  // bool eventFilter(QObject *, QEvent *);
  /// TODO: bool eventFilter(QObject *, QEvent *);
  // QString objectName() const;
  bind::member_function<QObject, QString, &QObject::objectName>(object, "objectName").create();
  // void setObjectName(const QString &);
  bind::void_member_function<QObject, const QString &, &QObject::setObjectName>(object, "setObjectName").create();
  // bool isWidgetType() const;
  bind::member_function<QObject, bool, &QObject::isWidgetType>(object, "isWidgetType").create();
  // bool isWindowType() const;
  bind::member_function<QObject, bool, &QObject::isWindowType>(object, "isWindowType").create();
  // bool signalsBlocked() const;
  bind::member_function<QObject, bool, &QObject::signalsBlocked>(object, "signalsBlocked").create();
  // bool blockSignals(bool);
  bind::member_function<QObject, bool, bool, &QObject::blockSignals>(object, "blockSignals").create();
  // QThread * thread() const;
  /// TODO: QThread * thread() const;
  // void moveToThread(QThread *);
  /// TODO: void moveToThread(QThread *);
  // int startTimer(int, Qt::TimerType = Qt::CoarseTimer);
  bind::member_function<QObject, int, int, Qt::TimerType, &QObject::startTimer>(object, "startTimer")
    .apply(bind::default_arguments(Qt::CoarseTimer)).create();
  // int startTimer(std::chrono::milliseconds, Qt::TimerType);
  /// TODO: int startTimer(std::chrono::milliseconds, Qt::TimerType);
  // void killTimer(int);
  bind::void_member_function<QObject, int, &QObject::killTimer>(object, "killTimer").create();
  // const QObjectList & children() const;
  bind::member_function<QObject, const QObjectList &, &QObject::children>(object, "children").create();
  // void setParent(QObject *);
  bind::void_member_function<QObject, QObject *, &QObject::setParent>(object, "setParent").create();
  // void installEventFilter(QObject *);
  bind::void_member_function<QObject, QObject *, &QObject::installEventFilter>(object, "installEventFilter").create();
  // void removeEventFilter(QObject *);
  bind::void_member_function<QObject, QObject *, &QObject::removeEventFilter>(object, "removeEventFilter").create();
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
  bind::const_void_member_function<QObject, &QObject::dumpObjectTree>(object, "dumpObjectTree").create();
  // void dumpObjectInfo() const;
  bind::const_void_member_function<QObject, &QObject::dumpObjectInfo>(object, "dumpObjectInfo").create();
  // bool setProperty(const char *, const QVariant &);
  /// TODO: bool setProperty(const char *, const QVariant &);
  // QVariant property(const char *) const;
  /// TODO: QVariant property(const char *) const;
  // QList<QByteArray> dynamicPropertyNames() const;
  bind::member_function<QObject, QList<QByteArray>, &QObject::dynamicPropertyNames>(object, "dynamicPropertyNames").create();
  // void destroyed(QObject *);
  bind::signal<QObject, QObject *>(object, "destroyed", "destroyed(QObject *)");
  // QObject * parent() const;
  bind::member_function<QObject, QObject *, &QObject::parent>(object, "parent").create();
  // bool inherits(const char *) const;
  /// TODO: bool inherits(const char *) const;
  // void deleteLater();
  bind::void_member_function<QObject, &QObject::deleteLater>(object, "deleteLater").create();

  bind::link(object, &QObject::staticMetaObject);
}


#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
static void register_signal_blocker_class(script::Namespace ns)
{
  using namespace script;

  Class signal_blocker = ns.newClass("SignalBlocker").setId(script::Type::QSignalBlocker).get();


  // QSignalBlocker(QObject *);
  bind::constructor<QSignalBlocker, QObject *>(signal_blocker).create();
  // QSignalBlocker(QObject &);
  bind::constructor<QSignalBlocker, QObject &>(signal_blocker).create();
  // ~QSignalBlocker();
  bind::destructor<QSignalBlocker>(signal_blocker).create();
  // QSignalBlocker(QSignalBlocker &&);
  bind::constructor<QSignalBlocker, QSignalBlocker &&>(signal_blocker).create();
  // QSignalBlocker & operator=(QSignalBlocker &&);
  bind::memop_assign<QSignalBlocker, QSignalBlocker &&>(signal_blocker);
  // void reblock();
  bind::void_member_function<QSignalBlocker, &QSignalBlocker::reblock>(signal_blocker, "reblock").create();
  // void unblock();
  bind::void_member_function<QSignalBlocker, &QSignalBlocker::unblock>(signal_blocker, "unblock").create();
}
#endif


void register_object_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_object_class(ns);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  register_signal_blocker_class(ns);
#endif

  // QDebug operator<<(QDebug, const QObject *);
  /// TODO: QDebug operator<<(QDebug, const QObject *);
}

