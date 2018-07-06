// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/closeevent.h"

#include "yasl/binding/class.h"

#include <script/interpreter/executioncontext.h>

static int qcloseevent_type_id = 0;

namespace callbacks
{

namespace closeevent
{

static script::Value ctor(script::FunctionCall *c)
{
  auto self = c->thisObject();
  self.impl()->data.ptr = new QCloseEvent();
  return self;
}

} // namespace closeevent

} // namespace callbacks


void register_qcloseevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(get_qevent_type());
  Class closeevent = root.newClass(ClassBuilder::New("CloseEvent").setParent(event).setFinal());
  qcloseevent_type_id = closeevent.id();
 
  // QCloseEvent();
  closeevent.Constructor(callbacks::closeevent::ctor).create();
  // ~QCloseEvent();
  closeevent.newDestructor(event.destructor().native_callback());
}

script::Type get_qcloseevent_type()
{
  return script::Type{ qcloseevent_type_id };
}

