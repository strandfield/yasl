// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/hideevent.h"

#include "yasl/core/qevent-binder.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>


void register_qhideevent(script::Namespace root)
{
  using namespace script;

  Class hideevent = root.Class("HideEvent").setId(Type::QHideEvent).setBase(script::Type::QEvent).setFinal().get();
  
  binding::Event<QHideEvent> binder{ hideevent };

  // QHideEvent();
  binder.ctors().add_default();
  // ~QHideEvent();
  binder.add_dtor();
}
