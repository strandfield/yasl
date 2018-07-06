// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/showevent.h"

#include "yasl/binding/class.h"

#include <script/interpreter/executioncontext.h>

static int qshowevent_type_id = 0;

namespace callbacks
{

namespace showevent
{

static script::Value ctor(script::FunctionCall *c)
{
  auto self = c->thisObject();
  self.impl()->data.ptr = new QShowEvent();
  return self;
}

} // namespace showevent

} // namespace callbacks


void register_qshowevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(get_qevent_type());
  Class showevent = root.newClass(ClassBuilder::New("ShowEvent").setParent(event).setFinal());
  qshowevent_type_id = showevent.id();
  
  // QShowEvent();
  showevent.Constructor(callbacks::showevent::ctor).create();
  // ~QShowEvent();
  showevent.newDestructor(event.destructor().native_callback());
}

script::Type get_qshowevent_type()
{
  return script::Type{ qshowevent_type_id };
}

