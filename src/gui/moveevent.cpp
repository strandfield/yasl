// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/moveevent.h"

#include "yasl/core/qevent-binder.h"
#include "yasl/core/point.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>


void register_qmoveevent(script::Namespace root)
{
  using namespace script;

  Class moveevent = root.Class("MoveEvent").setId(Type::QMoveEvent).setBase(Type::QEvent).setFinal().get();
  
  binding::Event<QMoveEvent> qmoveevent{ moveevent };
  // QMoveEvent(const QPoint & pos, const QPoint & oldPos);
  qmoveevent.ctors().add<const QPoint &, const QPoint &>();
  // ~QMoveEvent();
  qmoveevent.add_dtor();
  // const QPoint & oldPos() const;
  qmoveevent.add_fun<const QPoint &, &QMoveEvent::oldPos>("oldPos");
  // const QPoint & pos() const;
  qmoveevent.add_fun<const QPoint &, &QMoveEvent::pos>("pos");
}

