// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/hideevent.h"

#include "yasl/binding/class.h"

#include <script/interpreter/executioncontext.h>

static int qhideevent_type_id = 0;

namespace callbacks
{

namespace hideevent
{

static script::Value ctor(script::FunctionCall *c)
{
  auto self = c->thisObject();
  self.impl()->data.ptr = new QHideEvent();
  return self;
}

} // namespace hideevent

} // namespace callbacks


void register_qhideevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(get_qevent_type());
  Class hideevent = root.newClass(ClassBuilder::New("HideEvent").setParent(event).setFinal());
  qhideevent_type_id = hideevent.id();
  
  // QHideEvent();
  hideevent.Constructor(callbacks::hideevent::ctor).create();
  // ~QHideEvent();
  hideevent.newDestructor(event.destructor().native_callback());
}

script::Type get_qhideevent_type()
{
  return script::Type{ qhideevent_type_id };
}

