// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/utils/ptr.h"

#include "yasl/application.h"

#include <script/classtemplate.h>
#include <script/engine.h>
#include <script/interpreter/executioncontext.h>
#include <script/functionbuilder.h>
#include <script/namespace.h>
#include <script/private/engine_p.h>
#include <script/private/function_p.h>
#include <script/private/value_p.h>
#include <script/templatebuilder.h>

namespace callbacks
{

namespace ptr
{

script::Value copy_ctor(script::FunctionCall *c)
{
  script::Value other = c->arg(1);
  c->thisObject().impl()->data.ptr = other.impl()->data.ptr;
  return c->thisObject();
}

script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().impl()->data.ptr = nullptr;
  return c->thisObject();
}

} // namespace ptr

} // namespace callbacks



script::Class ptr_template_instantiate(script::ClassTemplateInstanceBuilder &)
{
  throw script::TemplateInstantiationError{ "Ptr template cannot be instantiated" };
}


void register_ptr_template(script::Namespace ns)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{TemplateParameter::TypeParameter{}, "T"}
  };

  ClassTemplate ptr = Symbol{ ns }.ClassTemplate("Ptr")
    .setParams(std::move(params))
    .setScope(Scope{ ns })
    .setCallback(ptr_template_instantiate)
    .get();

  register_ptr_specialization<bool>(ptr, Type::Ptrbool);
  register_ptr_specialization<char>(ptr, Type::Ptrchar);
  register_ptr_specialization<int>(ptr, Type::Ptrint);
  register_ptr_specialization<float>(ptr, Type::Ptrfloat);
  register_ptr_specialization<double>(ptr, Type::Ptrdouble);
  
  ns.engine()->implementation()->ptr_template_ = ptr;
}

