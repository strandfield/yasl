// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/event-utils.h"

#include "yasl/core/variant.h"

#include <script/class.h>
#include <script/constructorbuilder.h>
#include <script/destructorbuilder.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/typesystem.h>
#include <script/interpreter/executioncontext.h>

#include <QCoreApplication>

namespace script
{

namespace callbacks
{

script::Value user_event_ctor(script::FunctionCall *c)
{
  int type = c->arg(1).toInt();
  c->arg(0).setQEvent(new yasl::UserEvent{ type });
  return c->thisObject();
}

script::Value user_event_data(script::FunctionCall *c)
{
  QEvent *ev = c->arg(0).toQEvent();
  yasl::UserEvent *uev = dynamic_cast<yasl::UserEvent*>(ev);
  if (uev == nullptr)
  {
    return c->engine()->construct<QVariant>();
  }
  else
  {
    return c->engine()->construct<QVariant>(uev->data);
  }
}

script::Value user_event_set_data(script::FunctionCall *c)
{
  QEvent* ev = c->arg(0).toQEvent();
  yasl::UserEvent *uev = dynamic_cast<yasl::UserEvent*>(ev);
  if (uev != nullptr)
  {
    uev->data = script::get<QVariant>(c->arg(1));
  }
  return script::Value::Void;
}

script::Value app_sendevent(script::FunctionCall *c)
{
  QObject *obj = c->arg(0).toQObject();
  QEvent* ev = c->arg(1).toQEvent();
  QCoreApplication::sendEvent(obj, ev);
  return script::Value::Void;
}

script::Value app_postevent(script::FunctionCall *c)
{
  QObject *obj = c->arg(0).toQObject();
  QEvent *ev = c->arg(1).toQEvent();
  QCoreApplication::postEvent(obj, ev);
  c->arg(0).setQEvent(nullptr); // QCoreApplication takes ownership of the event
  return script::Value::Void;
}

} // namespace callbacks

} // namespace script

namespace yasl
{

UserEvent::UserEvent(int type)
  : QEvent(static_cast<QEvent::Type>(type))
{

}

UserEvent::~UserEvent()
{

}

void registerEventUtils(script::Namespace core)
{
  script::Class ev = core.engine()->typeSystem()->getClass(script::Type::QEvent);
  
  ev.newConstructor(script::callbacks::user_event_ctor)
    .params(script::Type::Int)
    .create();

  ev.newMethod("data", script::callbacks::user_event_data)
    .setConst()
    .returns(script::Type::QVariant).create();

  ev.newMethod("setData", script::callbacks::user_event_set_data)
    .params(script::Type::cref(script::Type::QVariant)).create();

  script::Class app = core.engine()->typeSystem()->getClass(script::Type::App);

  app.newMethod("sendEvent", script::callbacks::app_sendevent)
    .setStatic()
    .returns(script::Type::Void)
    .params(script::Type::ref(script::Type::QObject), script::Type::ref(ev.id())).create();

  app.newMethod("postEvent", script::callbacks::app_postevent)
    .setStatic()
    .returns(script::Type::Void)
    .params(script::Type::ref(script::Type::QObject), script::Type::ref(ev.id())).create();
}

} // namespace yasl