// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/object.h"

#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/interpreter/executioncontext.h>
#include <script/namespace.h>
#include <script/value.h>

namespace callbacks
{

script::Value new_object(script::FunctionCall *c)
{
  using namespace script;
  Value v = c->engine()->construct(Type::QObject, {});
  return v;
}

} // namespace callbacks


static void register_newobject_template(script::Engine *e)
{
  /// TODO
}

void register_newobject_file(script::Namespace core)
{
  using namespace script;

  core.newFunction("newObject", callbacks::new_object)
    .returns(Type::ref(Type::QObject))
    .create();

  register_newobject_template(core.engine());
}