// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_PROXY_SPECIALIZATION_H
#define YASL_COMMONS_PROXY_SPECIALIZATION_H

#include "yasl/common/proxy.h"
#include "yasl/common/values.h"

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
  return script::make_value(*ptr, c->engine());
}

template<typename T>
script::Value assign(script::FunctionCall *c)
{
  T* ptr = static_cast<T*>(c->thisObject().getPtr());
  *ptr = script::value_cast<const T &>(c->arg(1));
  return script::Value::Void;
}

} // namespace proxy

} // namespace callbacks


template<typename T>
script::Type register_proxy_specialization(script::Engine *e)
{
  using namespace script;

  const script::Type type_id = make_type<Proxy<T>>();
  
  ClassTemplate proxy_template = e->getTemplate(Engine::ProxyTemplate);
  Class proxy_type = proxy_template.engine()->getClass(type_id);
  if (!proxy_type.isNull() && type_id == proxy_type.id())
    return type_id;

  const script::Type element_type = script::make_type<T>();

  std::vector<TemplateArgument> targs{
    TemplateArgument{ element_type },
  };

  proxy_type = proxy_template.Specialization(std::move(targs))
    .setId(type_id.data())
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

  return proxy_type.id();
}

} // namespace script

#endif // YASL_COMMONS_PROXY_SPECIALIZATION_H
