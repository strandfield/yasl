// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_UTILS_PROXY_H
#define YASL_UTILS_PROXY_H

#include "yasl/binding/values.h"

#include <script/castbuilder.h>
#include <script/constructorbuilder.h>
#include <script/destructorbuilder.h>
#include <script/operatorbuilder.h>
#include <script/classtemplatespecializationbuilder.h>

namespace script
{
class Class;
class Engine;
class Namespace;
class Type;
class Value;
} // namespace script

void register_proxy_template(script::Namespace ns);

template<typename T>
struct Proxy
{
  T *value;

  Proxy(T *val) : value(val) { }


  T & get() { return *value; }
  operator T &() { return get(); }
  
  void operator=(const T & val) { *value = val; }
};


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
  return binding::make_value(*ptr, c->engine());
}

template<typename T>
script::Value assign(script::FunctionCall *c)
{
  T* ptr = static_cast<T*>(c->thisObject().getPtr());
  *ptr = binding::value_cast<const T &>(c->arg(1));
  return script::Value::Void;
}

} // namespace proxy

} // namespace callbacks


template<typename T>
void register_proxy_specialization(script::ClassTemplate proxy_template, script::Type::BuiltInType type_id)
{
  using namespace script;

  const script::Type element_type = binding::make_type<T>();

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


namespace binding
{
template<> struct make_type_t<Proxy<bool>> { inline static script::Type get() { return script::Type::Proxybool; } };
template<> struct make_type_t<Proxy<char>> { inline static script::Type get() { return script::Type::Proxychar; } };
template<> struct make_type_t<Proxy<int>> { inline static script::Type get() { return script::Type::Proxyint; } };
template<> struct make_type_t<Proxy<float>> { inline static script::Type get() { return script::Type::Proxyfloat; } };
template<> struct make_type_t<Proxy<double>> { inline static script::Type get() { return script::Type::Proxydouble; } };

} // namespace binding

#endif // YASL_UTILS_PROXY_H
