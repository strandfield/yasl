// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/null.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/constructorbuilder.h>
#include <script/destructorbuilder.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/operatorbuilder.h>

#include <script/interpreter/executioncontext.h>

namespace script
{

namespace callbacks
{

script::Value null_dummy_callback(script::FunctionCall *c)
{
  return c->thisObject();
}

} // namespace callbacks

void register_null_type(script::Namespace ns)
{
  Class null = ns.newClass("NullType").setId(Type::NullType).setFinal(true).get();

  // NullType();
  null.newConstructor(callbacks::null_dummy_callback).create();
  // NullType(const NullType &)
  null.newConstructor(callbacks::null_dummy_callback)
    .params(Type::cref(Type::NullType)).create();
  // ~NullType()
  null.newDestructor(callbacks::null_dummy_callback).create();

  // NullType & operator=(const NullType &)
  null.newOperator(AssignmentOperator, callbacks::null_dummy_callback)
    .returns(Type::ref(Type::NullType))
    .params(Type::cref(Type::NullType)).create();

  Value nullinstance = ns.engine()->construct(Type::NullType, [](Value &) {});
  ns.engine()->manage(nullinstance);
  ns.addValue("null", nullinstance);
}

} // namespace script
