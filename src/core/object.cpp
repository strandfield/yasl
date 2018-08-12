// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/object.h"

#include "yasl/binding/qclass.h"
#include "yasl/core/listspecializations.h"
#include "yasl/utils/ref.h"

#include <script/classbuilder.h>
#include <script/engine.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/value.h>
#include <script/private/value_p.h>


void register_qobject(script::Namespace n)
{
  using namespace script;

  Class qobject_class = n.Class("Object").setId(Type::QObject).get();
  Type object_type = qobject_class.id();

  register_ref_specialization(n.engine(), Type::QObject, Type::QObjectStar);
  register_ptr_specialization<QObject*>(n.engine()->getTemplate(Engine::PtrTemplate), Type::PtrQObject);
  register_list_specialization<QObject*>(n.engine(), Type::QListQObject);

  auto qobject = binding::QClass<QObject>{ qobject_class, &QObject::staticMetaObject };
  qobject.ctors().add_default();
  qobject.add_dtor();
  qobject.add_fun<bool, bool, &QObject::blockSignals>("blockSignals");
  // const QObjectList & children() const;
  qobject.add_fun<const QObjectList &, &QObject::children>("children");
  // QMetaObject::Connection 	connect(const QObject *sender, const char *signal, const char *method, Qt::ConnectionType type = Qt::AutoConnection) const
  // bool 	disconnect(const char *signal = nullptr, const QObject *receiver = nullptr, const char *method = nullptr) const
  // bool 	disconnect(const QObject *receiver, const char *method = nullptr) const
  qobject.add_void_fun<&QObject::dumpObjectInfo>("dumpObjectInfo");
  qobject.add_void_fun<&QObject::dumpObjectTree>("dumpObjectTree");
  //qobject.add_fun<QList<QByteArray>, &QObject::dynamicPropertyNames>("dynamicPropertyNames");
  //virtual bool 	event(QEvent *e)
  // virtual bool 	eventFilter(QObject *watched, QEvent *event)
//  QList<T> 	findChildren(const QString &name = QString(), Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
//QList<T> 	findChildren(const QRegExp &regExp, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
//QList<T> 	findChildren(const QRegularExpression &re, Qt::FindChildOptions options = Qt::FindChildrenRecursively) const
//bool 	inherits(const char *className) const
//void 	installEventFilter(QObject *filterObj)
  qobject.add_fun<bool, &QObject::isWidgetType>("isWidgetType");
  qobject.add_fun<bool, &QObject::isWindowType>("isWindowType");
  qobject.add_void_fun<int, &QObject::killTimer>("killTimer");
//virtual const QMetaObject *	metaObject() const
//void 	moveToThread(QThread *targetThread)
  qobject.add_fun<QString, &QObject::objectName>("objectName");
// QObject* parent() const
  qobject.add_fun<QObject*, &QObject::parent>("parent");
  //QVariant 	property(const char *name) const
//void 	removeEventFilter(QObject *obj)
// void setObjectName(const QString &);
  qobject.add_void_fun<const QString &, &QObject::setObjectName>("setObjectName");
//void 	setParent(QObject *parent)
  qobject.add_void_fun<QObject*, &QObject::setParent>("setParent");
//bool 	setProperty(const char *name, const QVariant &value)
  qobject.add_fun<bool, &QObject::signalsBlocked>("signalsBlocked");
//int 	startTimer(int interval, Qt::TimerType timerType = Qt::CoarseTimer)
//int 	startTimer(std::chrono::milliseconds time, Qt::TimerType timerType = Qt::CoarseTimer)
//QThread *	thread() const

  n.engine()->registerQtType(&QObject::staticMetaObject, object_type);
}

script::Value make_object(script::Engine *e, script::Type object_type, QObject *value)
{
  script::Value v = e->uninitialized(object_type);
  e->bind(v, value);
  v.impl()->type = v.impl()->type.withoutFlag(script::Type::UninitializedFlag);
  return v;
}

