// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/paintevent.h"

#include "yasl/core/qevent-binder.h"
#include "yasl/core/rect.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>


void register_qpaintevent(script::Namespace root)
{
  using namespace script;

  Class paintevent = root.Class("PaintEvent").setId(Type::QPaintEvent).setBase(Type::QEvent).setFinal().get();
  
  binding::Event<QPaintEvent> qpaintevent{ paintevent };
  // QPaintEvent(const QRect & rect);
  qpaintevent.ctors().add<const QRect &>();
  // ~QPaintEvent();
  qpaintevent.add_dtor();
  // const QRect & rect() const;
  qpaintevent.add_fun<const QRect &, &QPaintEvent::rect>("rect");
}

