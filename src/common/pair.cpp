// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/pair.h"
#include "yasl/common/pairspecializations.h"

#include "yasl/common/value.h"

#include <script/classtemplate.h>
#include <script/classtemplateinstancebuilder.h>
#include <script/constructorbuilder.h>
#include <script/templatebuilder.h>

#include <cstring>

struct PairData : public script::UserData
{
  ~PairData() = default;

  std::shared_ptr<yasl::TypeInfo> T1;
  std::shared_ptr<yasl::TypeInfo> T2;

  static std::shared_ptr<PairData> get(script::Engine *e, const script::Type & T1, const script::Type & T2)
  {
    auto ret = std::make_shared<PairData>();
    ret->T1 = yasl::TypeInfo::get(e, T1);
    ret->T2 = yasl::TypeInfo::get(e, T2);
    return ret;
  }
};

static script::Value make_pair(const QPair<yasl::Value, yasl::Value> & val, const script::Type & pair_type, script::Engine *e)
{
  script::Value ret = e->allocate(pair_type);
  script::ThisObject(ret).init<QPair<yasl::Value, yasl::Value>>(val);
  return ret;
}


namespace script
{
namespace callbacks
{

namespace pair
{

// QPair()
script::Value default_ctor(script::FunctionCall *c)
{
  c->thisObject().init<QPair<yasl::Value, yasl::Value>>();
  return c->thisObject();
}

// QPair(const QPair &)
script::Value copy_ctor(script::FunctionCall *c)
{
  auto & other = script::get<QPair<yasl::Value, yasl::Value>>(c->arg(1));
  c->thisObject().init<QPair<yasl::Value, yasl::Value>>(other);
  return c->thisObject();
}

// QPair(const T1 &, const T2 &)
script::Value value_ctor(script::FunctionCall *c)
{
  auto info = std::static_pointer_cast<PairData>(c->callee().memberOf().data());
  yasl::Value v1{ info->T1, c->arg(1) };
  yasl::Value v2{ info->T2, c->arg(2) };
  c->thisObject().init<QPair<yasl::Value, yasl::Value>>(std::move(v1), std::move(v2));
  return c->thisObject();
}

// ~QPair()
script::Value dtor(script::FunctionCall *c)
{
  c->thisObject().destroy<QPair<yasl::Value, yasl::Value>>();
  return script::Value::Void;
}

// const T1 & first() const
script::Value first(script::FunctionCall *c)
{
  QPair<yasl::Value, yasl::Value> & self = script::value_cast<QPair<yasl::Value, yasl::Value> &>(c->thisObject());
  return self.first.get();
}

// const T2 & second() const
script::Value second(script::FunctionCall *c)
{
  QPair<yasl::Value, yasl::Value> & self = script::value_cast<QPair<yasl::Value, yasl::Value> &>(c->thisObject());
  return self.second.get();
}

// void setFirst(const T1 &)
script::Value set_first(script::FunctionCall *c)
{
  QPair<yasl::Value, yasl::Value> & self = script::value_cast<QPair<yasl::Value, yasl::Value> &>(c->thisObject());
  self.first.assign(c->arg(1));
  return script::Value::Void;
}

// void setSecond(const T2 &)
script::Value set_second(script::FunctionCall *c)
{
  QPair<yasl::Value, yasl::Value> & self = script::value_cast<QPair<yasl::Value, yasl::Value> &>(c->thisObject());
  self.second.assign(c->arg(1));
  return script::Value::Void;
}

// QPair & operator=(const Pair &)
script::Value op_assign(script::FunctionCall *c)
{
  auto & self = script::value_cast<QPair<yasl::Value, yasl::Value> &>(c->thisObject());
  const auto & other = script::value_cast<const QPair<yasl::Value, yasl::Value> &>(c->arg(1));
  self = other;
  return c->thisObject();
}

// bool operator==(const Pair &) const
script::Value op_eq(script::FunctionCall *c)
{
  auto & self = script::value_cast<QPair<yasl::Value, yasl::Value> &>(c->thisObject());
  const auto & other = script::value_cast<const QPair<yasl::Value, yasl::Value> &>(c->arg(1));
  return c->engine()->newBool(self == other);
}

// bool operator!=(const Pair &) const
script::Value op_neq(script::FunctionCall *c)
{
  auto & self = script::value_cast<QPair<yasl::Value, yasl::Value> &>(c->thisObject());
  const auto & other = script::value_cast<const QPair<yasl::Value, yasl::Value> &>(c->arg(1));
  return c->engine()->newBool(self != other);
}

} // namespace pair

} // namespace callbacks

Class PairTemplate::instantiate(ClassTemplateInstanceBuilder& builder)
{
  builder.setFinal();
  const Type T1 = builder.arguments().front().type;
  const Type T2 = builder.arguments().back().type;

  builder.setData(PairData::get(builder.getTemplate().engine(), T1, T2));

  Class pair = builder.get();

  // QPair();
  pair.newConstructor(callbacks::pair::default_ctor).create();
  // QPair(const QPair &)
  pair.newConstructor(callbacks::pair::copy_ctor)
    .params(Type::cref(pair.id())).create();
  // QPair(const T1 &, const T2 &)
  pair.newConstructor(callbacks::pair::value_ctor)
    .params(Type::cref(T1), Type::cref(T2)).create();
  // ~QPair();
  pair.newDestructor(callbacks::pair::dtor).create();


  // const T1 & first() const;
  pair.newMethod("first", callbacks::pair::first)
    .setConst()
    .returns(Type::cref(T1))
    .create();
  // const T2 & second() const;
  pair.newMethod("second", callbacks::pair::second)
    .setConst()
    .returns(Type::cref(T2))
    .create();
  // void setFirst(const T1 &)
  pair.newMethod("setFirst", callbacks::pair::set_first)
    .params(Type::cref(T1))
    .create();
  // void setFirst(const T2 &)
  pair.newMethod("setSecond", callbacks::pair::set_second)
    .params(Type::cref(T2))
    .create();


  // QPair & operator=(const QPair &other);
  pair.newOperator(AssignmentOperator, callbacks::pair::op_assign)
    .returns(Type::ref(pair.id()))
    .params(Type::cref(pair.id())).create();
  // bool operator!=(const QPair &other) const;
  pair.newOperator(InequalOperator, callbacks::pair::op_neq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(pair.id())).create();
  // bool operator==(const QPair &other) const;
  pair.newOperator(EqualOperator, callbacks::pair::op_eq)
    .setConst()
    .returns(Type::Boolean)
    .params(Type::cref(pair.id())).create();

  return pair;
}

} // namespace script

void register_pair_template(script::Namespace n)
{
  using namespace script;

  std::vector<TemplateParameter> params{
    TemplateParameter{ TemplateParameter::TypeParameter{}, "T1" },
    TemplateParameter{ TemplateParameter::TypeParameter{}, "T2" },
  };

  ClassTemplate pair_template = Symbol{ n }.newClassTemplate("Pair")
    .setParams(std::move(params))
    .setScope(Scope{ n })
    .withBackend<PairTemplate>()
    .get();

  // Registering full specializations

}
