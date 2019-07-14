// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/proxyspecialization.h"

#include <script/classtemplate.h>
#include <script/engine.h>
#include <script/interpreter/executioncontext.h>
#include <script/functionbuilder.h>
#include <script/namespace.h>
#include <script/private/engine_p.h>
#include <script/private/function_p.h>
#include <script/templatebuilder.h>

namespace script
{

namespace callbacks
{

namespace proxy
{

script::Value copy_ctor(script::FunctionCall *c)
{
  script::Value other = c->arg(1);
  c->thisObject().init<details::PtrWrapper>(script::get<details::PtrWrapper>(other));
  return c->thisObject();
}

script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().destroy<details::PtrWrapper>();
  return c->thisObject();
}

} // namespace proxy

} // namespace callbacks



Class ProxyTemplate::instantiate(ClassTemplateInstanceBuilder& builder)
{
  throw script::TemplateInstantiationError{ "Proxy template cannot be instantiated" };

}

void register_proxy_template(script::Namespace ns)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{TemplateParameter::TypeParameter{}, "T"}
  };

  ClassTemplate proxy = Symbol{ ns }.newClassTemplate("Proxy")
    .setParams(std::move(params))
    .setScope(Scope{ ns })
    .withBackend<ProxyTemplate>()
    .get();

  register_proxy_specialization<bool>(ns.engine());
  register_proxy_specialization<char>(ns.engine());
  register_proxy_specialization<int>(ns.engine());
  register_proxy_specialization<float>(ns.engine());
  register_proxy_specialization<double>(ns.engine());
}

} // namespace script
