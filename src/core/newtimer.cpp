// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/newtimer.h"

#include "yasl/core/object.h"

#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/value.h>

namespace callbacks
{

static script::Value new_timer(script::FunctionCall *c)
{
  using namespace script;
  QTimer *timer = new QTimer(binding::value_cast<QObject*>(c->arg(0)));
  return c->engine()->expose(timer, Type::QTimer);
}

} // namespace callbacks


void register_newtimer_file(script::Namespace core)
{
  using namespace script;

  core.Function("newTimer", callbacks::new_timer)
    .returns(Type::ref(Type::QTimer))
    .params(binding::make_type<QObject*>())
    .create();
}