// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/moveevent.h"

#include "yasl/binding/class.h"
#include "yasl/core/point.h"

#include <script/interpreter/executioncontext.h>

static int qmoveevent_type_id = 0;

namespace callbacks
{

static script::Value ctor(script::FunctionCall *c)
{
  auto self = c->thisObject();
  self.impl()->data.ptr = new QMoveEvent(binding::value_cast<const QPoint &>(c->arg(0)), binding::value_cast<const QPoint &>(c->arg(1)));
  return self;
}

} // namespace callbacks


void register_qmoveevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(get_qevent_type());
  Class moveevent = root.newClass(ClassBuilder::New("MoveEvent").setParent(event).setFinal());
  qmoveevent_type_id = moveevent.id();
  
  binding::Class<QMoveEvent> qmoveevent{ moveevent };
  // QMoveEvent(const QPoint & pos, const QPoint & oldPos);
  moveevent.Constructor(callbacks::ctor)
    .params(binding::make_type<const QPoint &>(), binding::make_type<const QPoint &>())
    .create();  // ~QMoveEvent();
  moveevent.newDestructor(event.destructor().native_callback());
  // const QPoint & oldPos() const;
  qmoveevent.add_fun<const QPoint &, &QMoveEvent::oldPos>("oldPos");
  // const QPoint & pos() const;
  qmoveevent.add_fun<const QPoint &, &QMoveEvent::pos>("pos");
}

script::Type get_qmoveevent_type()
{
  return script::Type{ qmoveevent_type_id };
}

