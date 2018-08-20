// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/closeevent.h"

#include "yasl/core/qevent-binder.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>

void register_qcloseevent(script::Namespace root)
{
  using namespace script;

  Class closeevent = root.Class("CloseEvent").setId(Type::QCloseEvent).setBase(Type::QEvent).setFinal().get();

  binding::Event<QCloseEvent> binder{ closeevent };

  // QCloseEvent();
  binder.ctors().add_default();
  // ~QCloseEvent();
  binder.add_dtor();
}
