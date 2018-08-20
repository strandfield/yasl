// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/resizeevent.h"

#include "yasl/core/qevent-binder.h"
#include "yasl/core/size.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>


void register_qresizeevent(script::Namespace root)
{
  using namespace script;

  const Class event = root.engine()->getClass(script::Type::QEvent);
  Class resizeevent = root.Class("ResizeEvent").setId(Type::QResizeEvent).setBase(event).setFinal().get();
  
  binding::Event<QResizeEvent> qresizeevent{ resizeevent };
  // QResizeEvent(const QSize & size, const QSize & oldSize);
  qresizeevent.ctors().add<const QSize &, const QSize &>();
  // ~QResizeEvent();
  qresizeevent.add_dtor();
  // const QSize & oldSize() const;
  qresizeevent.add_fun<const QSize &, &QResizeEvent::oldSize>("oldSize");
  // const QSize & size() const;
  qresizeevent.add_fun<const QSize &, &QResizeEvent::size>("size");
}
