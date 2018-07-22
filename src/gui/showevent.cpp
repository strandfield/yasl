// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/showevent.h"

#include "yasl/binding/class.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

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

  const Class event = root.engine()->getClass(Type::QEvent);
  Class showevent = root.Class("ShowEvent").setId(Type::QShowEvent).setBase(event).setFinal().get();
  
  // QShowEvent();
  showevent.Constructor(callbacks::showevent::ctor).create();
  // ~QShowEvent();
  showevent.newDestructor(event.destructor().native_callback());
}
