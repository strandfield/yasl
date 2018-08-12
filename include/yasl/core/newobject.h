// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_NEWOBJECT_H
#define YASL_CORE_NEWOBJECT_H

#include "yasl/core/object.h"

class Object : public QObject
{
  Q_OBJECT
public:

  /// TODO:
  // virtual bool event(QEvent *e);
  //virtual void childEvent(QChildEvent *event);
  //virtual void connectNotify(const QMetaMethod &signal);
  //virtual void customEvent(QEvent *event);
  //virtual void disconnectNotify(const QMetaMethod &signal);
  //virtual void timerEvent(QTimerEvent *event);
};

#endif // YASL_CORE_NEWOBJECT_H
