// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/paintevent.h"

#include "yasl/binding/class.h"
#include "yasl/core/rect.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

namespace callbacks
{

namespace paintevent
{

static script::Value ctor_rect(script::FunctionCall *c)
{
  auto self = c->thisObject();
  self.impl()->data.ptr = new QPaintEvent(binding::value_cast<const QRect &>(c->arg(0)));
  return self;
}

} // namespace paintevent

} // namespace callbacks


void register_qpaintevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(script::Type::QEvent);
  Class paintevent = root.Class("PaintEvent").setId(Type::QPaintEvent).setBase(event).setFinal().get();
  
  binding::Class<QPaintEvent> qpaintevent{ paintevent };
  // QPaintEvent(const QRect & rect);
  paintevent.Constructor(callbacks::paintevent::ctor_rect)
    .params(binding::make_type<const QRect &>())
    .create();
  // ~QPaintEvent();
  paintevent.newDestructor(event.destructor().native_callback());
  // const QRect & rect() const;
  qpaintevent.add_fun<const QRect &, &QPaintEvent::rect>("rect");
}

