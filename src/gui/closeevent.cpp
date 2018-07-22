// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/closeevent.h"

#include "yasl/binding/class.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

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

  const Class event = root.engine()->getClass(script::Type::QEvent);
  Class closeevent = root.Class("CloseEvent").setId(Type::QCloseEvent).setBase(event).setFinal().get();

  // QCloseEvent();
  closeevent.Constructor(callbacks::closeevent::ctor).create();
  // ~QCloseEvent();
  closeevent.newDestructor(event.destructor().native_callback());
}
