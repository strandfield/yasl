// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_PAIR_SPECIALIZATIONS_H
#define YASL_COMMONS_PAIR_SPECIALIZATIONS_H

#include "yasl/common/pair.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"

#include <script/classtemplatespecializationbuilder.h>
#include <script/namespace.h>
#include <script/userdata.h>
#include <script/interpreter/executioncontext.h>

namespace script
{
namespace callbacks
{

namespace pair
{

template<typename T1, typename T2>
script::Value first(script::FunctionCall *c)
{
  QPair<T1, T2> & self = script::value_cast<QPair<T1, T2> &>(c->thisObject());
  return script::make_value(self.first, c->engine());
}

template<typename T1, typename T2>
script::Value second(script::FunctionCall *c)
{
  QPair<T1, T2> & self = script::value_cast<QPair<T1, T2> &>(c->thisObject());
  return script::make_value(self.second, c->engine());
}

template<typename T1, typename T2>
script::Value set_first(script::FunctionCall *c)
{
  QPair<T1, T2> & self = script::value_cast<QPair<T1, T2> &>(c->thisObject());
  self.first = script::value_cast<const T1 &>(c->arg(1));
  return script::Value::Void;
}

template<typename T1, typename T2>
script::Value set_second(script::FunctionCall *c)
{
  QPair<T1, T2> & self = script::value_cast<QPair<T1, T2> &>(c->thisObject());
  self.second = script::value_cast<const T2 &>(c->arg(1));
  return script::Value::Void;
}

} // namespace pair

} // namespace callbacks
} // namespace script


template<typename T1, typename T2>
void register_pair_specialization(script::ClassTemplate pair_template, script::Type::BuiltInType type_id)
{
  using namespace script;

  using Pair = QPair<T1, T2>;

  std::vector<TemplateArgument> targs{
    TemplateArgument{ script::make_type<T1>() },
    TemplateArgument{ script::make_type<T2>() }
  };

  Class pair = pair_template.Specialization(std::move(targs))
    .setId(type_id)
    .setFinal()
    .get();

  // QPair();
  bind::default_constructor<Pair>(pair).create();
  // QPair(const QPair &);
  bind::copy_constructor<Pair>(pair).create();
  // QPair(const T1 & value1, const T2 & value2);
  bind::constructor<Pair, const T1 &, const T2 &>(pair).create();
  // ~QPair();
  bind::destructor<Pair>(pair).create();

  // T1 first() const;
  pair.newMethod("first", callbacks::pair::first<T1, T2>)
    .setConst()
    .returns(make_type<T1>())
    .create();
  // T2 second() const;
  pair.newMethod("second", callbacks::pair::second<T1, T2>)
    .setConst()
    .returns(make_type<T2>())
    .create();
  // void setFirst(const T1 &);
  pair.newMethod("setFirst", callbacks::pair::set_first<T1, T2>)
    .params(make_type<const T1 &>())
    .create();
  // void setSecond(const T2 &);
  pair.newMethod("setSecond", callbacks::pair::set_second<T1, T2>)
    .params(make_type<const T2 &>())
    .create();

  // QPair & operator=(const QPair &);
  bind::memop_assign<Pair, const Pair &>(pair);

  // bool operator!=(const QPair &) const;
  bind::memop_neq<Pair, const Pair &>(pair);
  // bool operator==(const QPair &) const;
  bind::memop_eq<Pair, const Pair &>(pair);
}

#endif // YASL_COMMONS_PAIR_SPECIALIZATIONS_H
