// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_PROXY_SPECIALIZATION_H
#define YASL_BINDING_PROXY_SPECIALIZATION_H

#include "yasl/binding/proxy.h"
#include "yasl/binding/values.h"

#include <script/class.h>
#include <script/classtemplate.h>
#include <script/castbuilder.h>
#include <script/constructorbuilder.h>
#include <script/destructorbuilder.h>
#include <script/engine.h>
#include <script/interpreter/executioncontext.h>
#include <script/operatorbuilder.h>
#include <script/classtemplatespecializationbuilder.h>

namespace script
{

namespace bind
{

void register_proxy_template(script::Namespace ns);

namespace callbacks
{

namespace proxy
{

script::Value copy_ctor(script::FunctionCall *c);
script::Value dtor(script::FunctionCall *c);

template<typename T>
script::Value get(script::FunctionCall *c)
{
  T* ptr = static_cast<T*>(c->thisObject().getPtr());
  return bind::make_value(*ptr, c->engine());
}

template<typename T>
script::Value assign(script::FunctionCall *c)
{
  T* ptr = static_cast<T*>(c->thisObject().getPtr());
  *ptr = bind::value_cast<const T &>(c->arg(1));
  return script::Value::Void;
}

} // namespace proxy

} // namespace callbacks


template<typename T>
void register_proxy_specialization(script::ClassTemplate proxy_template, script::Type::BuiltInType type_id)
{
  using namespace script;

  const script::Type element_type = bind::make_type<T>();

  std::vector<TemplateArgument> targs{
    TemplateArgument{ element_type },
  };

  Class proxy_type = proxy_template.Specialization(std::move(targs))
    .setId(type_id)
    .setFinal()
    .get();

  // Proxy(const Proxy<T> & other);
  proxy_type.newConstructor(callbacks::proxy::copy_ctor).params(Type::cref(proxy_type.id())).create();
  // ~Proxy();
  proxy_type.newDestructor(callbacks::proxy::dtor).create();

  // void operator=(const T & value);
  proxy_type.newOperator(AssignmentOperator, callbacks::proxy::assign<T>)
    .params(Type::cref(element_type)).create();

  // operator T() const;
  proxy_type.newConversion(element_type, callbacks::proxy::get<T>).setConst().create();
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING_PROXY_SPECIALIZATION_H
