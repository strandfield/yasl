// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/utils/ref.h"

#include "yasl/core/object.h"
#include "yasl/utils/expose.h"

#include <script/classtemplate.h>
#include <script/engine.h>
#include <script/interpreter/executioncontext.h>
#include <script/functionbuilder.h>
#include <script/functiontemplate.h>
#include <script/namespace.h>
#include <script/private/function_p.h>
#include <script/private/value_p.h>

#include <QObject>


namespace callbacks
{

script::Value default_ctor(script::FunctionCall *c)
{
  c->thisObject().impl()->set_qobject(nullptr);
  return c->thisObject();
}

script::Value copy_ctor(script::FunctionCall *c)
{
  script::Value other = c->arg(0);
  c->thisObject().impl()->set_qobject(other.impl()->data.builtin.qobject);
  return c->thisObject();
}

script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().impl()->set_qobject(nullptr);
  c->thisObject().impl()->clear();
  return c->thisObject();
}

script::Value get(script::FunctionCall *c)
{
  /// TODO : throw on error ?
  auto self = c->thisObject();
  QObject *ptr = self.impl()->data.builtin.qobject;
  return ptr->property("_yasl_data_").value<binding::BindingData>().value;
}

script::Value is_null(script::FunctionCall *c)
{
  return c->engine()->newBool(c->thisObject().impl()->data.builtin.qobject == nullptr);
}

script::Value is_valid(script::FunctionCall *c)
{
  return c->engine()->newBool(c->thisObject().impl()->data.builtin.qobject != nullptr);
}

script::Value assign(script::FunctionCall *c)
{
  script::Value other = c->arg(1);
  c->thisObject().impl()->set_qobject(other.impl()->data.builtin.qobject);
  return c->thisObject();
}

script::Value cast(script::FunctionCall *c)
{
  QObject *ptr = c->thisObject().impl()->data.builtin.qobject;
  script::Value ret = c->engine()->construct(c->callee().returnType(), {});
  ret.impl()->set_qobject(ptr);
  return ret;
}

}

static script::Class get_qobject_class(script::Engine *e)
{
  return e->getClass(get_qobject_type());
}

static script::ClassTemplate get_ref_template(script::Engine *e)
{
  const std::string Ref = "Ref";
  const auto & tmplts = e->rootNamespace().templates();
  for (const auto & t : tmplts)
  {
    if (t.name() == Ref)
      return t.asClassTemplate();
  }

  throw std::runtime_error{ "Could not find Ref class template" };
}

static script::Class get_ref_instance(const script::Class & c)
{
  using namespace script;
  ClassTemplate ct = get_ref_template(c.engine());
  std::vector<TemplateArgument> args;
  args.push_back(TemplateArgument{ Type{c.id()} });
  return ct.getInstance(args);
}


static void inject_conversions(script::Class & ref, const script::Class & src)
{
  using namespace script;

  if (src.id() == ref.arguments().front().type.baseType().data())
    return;

  // we add a conversion from Ref<T> to Ref<Base>
  ref.Conversion(get_ref_instance(src).id(), callbacks::cast).create();
}

static void inject_conversions_recursively(script::Class & ref, const script::Class & src, const script::Class & qobject)
{
  inject_conversions(ref, src);

  if (src == qobject)
    return;

  inject_conversions_recursively(ref, src.parent(), qobject);
}

script::Class ref_template(script::ClassTemplate ref, const std::vector<script::TemplateArgument> & targs)
{
  /// TODO: should we throw on failure

  using namespace script;

  if (targs.size() != 1 || targs.at(0).kind != TemplateArgument::TypeArgument)
    return Class{}; 

  Type T = targs.front().type;
  if (!T.isObjectType() || T.isReference() || T.isRefRef())
    return Class{};

  Engine *e = ref.engine();

  Class qobject_class = get_qobject_class(e);
  Class qclass = e->getClass(T);
  if (!qclass.inherits(qobject_class))
    return Class{};

  ClassBuilder builder{ std::string{} };

  Class result = ref.build(builder, targs);

  result.Constructor(callbacks::default_ctor).create();
  result.Constructor(callbacks::copy_ctor).params(Type::cref(result.id())).create();
  result.Constructor(callbacks::copy_ctor).params(Type::cref(qclass.id())).create();

  result.newDestructor(callbacks::dtor);

  result.Method("get", callbacks::get)
    .setConst()
    .returns(Type::ref(qclass.id()))
    .create();
  
  result.Method("isNull", callbacks::is_null)
    .setConst()
    .returns(Type::Boolean)
    .create();

  result.Method("isValid", callbacks::is_valid)
    .setConst()
    .returns(Type::Boolean)
    .create();

  result.Operation(AssignmentOperator, callbacks::assign)
    .returns(Type::ref(result.id()))
    .params(Type::cref(result.id())).create();

  result.Conversion(Type::ref(qclass.id()), callbacks::get)
    .setConst()
    .create();

  inject_conversions_recursively(result, qclass, qobject_class);

  return result;
}


void register_ref_template(script::Namespace ns)
{
  using namespace script;

  std::vector<TemplateParameter> params;
  params.push_back(TemplateParameter{ TemplateParameter::TypeParameter{}, "T" });
  ns.addTemplate(ns.engine()->newClassTemplate("Ref", std::move(params), Scope{ ns }, ref_template));

}

script::Value make_ref(script::Engine *e, const script::Type & ref_type, QObject *value)
{
  using namespace script;
  Value v = e->uninitialized(ref_type);
  v.impl()->set_qobject(value);
  v.impl()->type = v.impl()->type.withoutFlag(Type::UninitializedFlag);
  return v;
}

script::Class get_ref_type(script::Engine *e, const script::Type & object_type)
{
  return get_ref_instance(e->getClass(object_type));
}
