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
#include <script/private/function_p.h>
#include <script/private/value_p.h>

static int ptr_bool_type_id = 0;
static int ptr_char_type_id = 0;
static int ptr_int_type_id = 0;
static int ptr_float_type_id = 0;
static int ptr_double_type_id = 0;


namespace callbacks
{

namespace ptr
{

script::Value copy_ctor(script::FunctionCall *c)
{
  script::Value other = c->arg(0);
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



script::Class ptr_template_instantiate(script::ClassTemplate, const std::vector<script::TemplateArgument> &)
{
  throw script::TemplateInstantiationError{ "Ptr template cannot be instantiated" };
}


void register_ptr_template(script::Namespace ns)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{TemplateParameter::TypeParameter{}, "T"}
  };

  ClassTemplate ptr = ns.engine()->newClassTemplate("Ptr", std::move(params), Scope{ ns }, ptr_template_instantiate);

  register_ptr_specialization<bool>(ptr, &ptr_bool_type_id);
  register_ptr_specialization<char>(ptr, &ptr_char_type_id);
  register_ptr_specialization<int>(ptr, &ptr_int_type_id);
  register_ptr_specialization<float>(ptr, &ptr_float_type_id);
  register_ptr_specialization<double>(ptr, &ptr_double_type_id);
  
  qApp->setPtrTemplate(ptr);
}

script::ClassTemplate get_ptr_template()
{
  return qApp->getPtrTemplate();
}

void* get_ptr(const script::Value & val)
{
  return val.impl()->data.ptr;
}

script::Value make_ptr(script::Engine *e, const script::Type & ptr_type, void *value)
{
  script::Value ret = e->uninitialized(ptr_type);
  ret.impl()->data.ptr = value;
  ret.impl()->type = ret.impl()->type.withoutFlag(script::Type::UninitializedFlag);
  return ret;
}

script::Type get_ptr_bool_type()
{
  return ptr_bool_type_id;
}

script::Type get_ptr_char_type()
{
  return ptr_char_type_id;
}

script::Type get_ptr_int_type()
{
  return ptr_int_type_id;
}

script::Type get_ptr_float_type()
{
  return ptr_float_type_id;
}

script::Type get_ptr_double_type()
{
  return ptr_double_type_id;
}
