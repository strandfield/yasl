// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/resizeevent.h"

#include "yasl/binding/class.h"
#include "yasl/core/size.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

namespace callbacks
{

static script::Value ctor(script::FunctionCall *c)
{
  auto self = c->thisObject();
  self.impl()->data.ptr = new QResizeEvent(binding::value_cast<const QSize &>(c->arg(0)), binding::value_cast<const QSize &>(c->arg(1)));
  return self;
}

} // namespace callbacks


void register_qresizeevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(script::Type::QEvent);
  Class resizeevent = root.Class("ResizeEvent").setId(Type::QResizeEvent).setBase(event).setFinal().get();
  
  binding::Class<QResizeEvent> qresizeevent{ resizeevent };
  // QResizeEvent(const QSize & size, const QSize & oldSize);
  resizeevent.Constructor(callbacks::ctor)
    .params(binding::make_type<const QSize &>(), binding::make_type<const QSize &>())
    .create();
  // ~QResizeEvent();
  resizeevent.newDestructor(event.destructor().native_callback());
  // const QSize & oldSize() const;
  qresizeevent.add_fun<const QSize &, &QResizeEvent::oldSize>("oldSize");
  // const QSize & size() const;
  qresizeevent.add_fun<const QSize &, &QResizeEvent::size>("size");
}
