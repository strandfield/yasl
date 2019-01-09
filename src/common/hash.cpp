// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/hash.h"

#include <script/engine.h>
#include <script/functionbuilder.h>

#include <script/interpreter/executioncontext.h>

#include <QHash>

namespace script
{

namespace callbacks
{

script::Value hash_bool(script::FunctionCall *c)
{
  return c->engine()->newInt(c->arg(0).toBool() ? 0 : 1);
}

script::Value hash_char(script::FunctionCall *c)
{
  return c->engine()->newInt(c->arg(0).toChar());
}

script::Value hash_int(script::FunctionCall *c)
{
  return c->engine()->newInt(c->arg(0).toInt());
}

script::Value hash_float(script::FunctionCall *c)
{
  return c->engine()->newInt(qHash(c->arg(0).toFloat()));
}

script::Value hash_double(script::FunctionCall *c)
{
  return c->engine()->newInt(qHash(c->arg(0).toDouble()));
}

} // namespace callbacks

void register_hash_functions(script::Engine *e)
{
  script::Namespace ns = e->rootNamespace();

  ns.newFunction("hash", callbacks::hash_bool)
    .returns(Type::Int)
    .params(Type::cref(Type::Boolean)).create();

  ns.newFunction("hash", callbacks::hash_char)
    .returns(Type::Int)
    .params(Type::cref(Type::Char)).create();

  ns.newFunction("hash", callbacks::hash_int)
    .returns(Type::Int)
    .params(Type::cref(Type::Int)).create();

  ns.newFunction("hash", callbacks::hash_float)
    .returns(Type::Int)
    .params(Type::cref(Type::Float)).create();

  ns.newFunction("hash", callbacks::hash_double)
    .returns(Type::Int)
    .params(Type::cref(Type::Double)).create();
}

} // namespace script
