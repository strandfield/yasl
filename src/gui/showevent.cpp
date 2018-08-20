// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/showevent.h"

#include "yasl/core/qevent-binder.h"

#include <script/classbuilder.h>
#include <script/namespace.h>
#include <script/interpreter/executioncontext.h>


void register_qshowevent(script::Namespace root)
{
  using namespace script;

  Class showevent = root.Class("ShowEvent").setId(Type::QShowEvent).setBase(Type::QEvent).setFinal().get();
  
  binding::Event<QShowEvent> binder{ showevent };

  // QShowEvent();
  binder.ctors().add_default();
  // ~QShowEvent();
  binder.add_dtor();
}
