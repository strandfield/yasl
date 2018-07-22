// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/hideevent.h"

#include "yasl/binding/class.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

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

  const Class event = root.engine()->getClass(script::Type::QEvent);
  Class hideevent = root.Class("HideEvent").setId(Type::QHideEvent).setBase(event).setFinal().get();
  
  // QHideEvent();
  hideevent.Constructor(callbacks::hideevent::ctor).create();
  // ~QHideEvent();
  hideevent.newDestructor(event.destructor().native_callback());
}
