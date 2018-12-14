// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/value.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/initialization.h>
#include <script/namelookup.h>
#include <script/namespace.h>
#include <script/overloadresolution.h>

namespace yasl
{

static std::map<int, std::shared_ptr<TypeInfo>> & get_typeinfo_map()
{
  static std::map<int, std::shared_ptr<TypeInfo>> map = {};
  return map;
}

static bool check_op_eq(const script::Type & t, const script::Function & op)
{
  if (op.returnType().baseType() != script::Type::Boolean)
    return false;

  if (op.parameter(0) != script::Type::cref(t) || op.parameter(1) != script::Type::cref(t))
    return false;

  return true;
}

static bool check_op_assign(const script::Type & t, const script::Function & op)
{
  if (op.returnType() != script::Type::ref(t))
    return false;

  if (op.parameter(0) != script::Type::ref(t) || op.parameter(1) != script::Type::cref(t))
    return false;

  return true;
}

static bool check_op_less(const script::Type & t, const script::Function & op)
{
  if (op.returnType() != script::Type::Boolean)
    return false;

  if (op.parameter(0) != script::Type::cref(t) || op.parameter(1) != script::Type::cref(t))
    return false;

  return true;
}


std::shared_ptr<TypeInfo> TypeInfo::get(script::Engine *e, const script::Type & t)
{
  auto & typeinfomap = get_typeinfo_map();

  auto it = typeinfomap.find(t.baseType().data());
  if (it != typeinfomap.end())
    return it->second;

  std::shared_ptr<TypeInfo> ret = std::make_shared<TypeInfo>();
  ret->element_type = t.baseType();
  ret->engine = e;

  if (t.isObjectType() || t.isFundamentalType())
  {
    auto creftype = script::Type::cref(t);
    auto reftype = script::Type::ref(t);

    {
      std::vector<script::Function> ops = script::NameLookup::resolve(script::EqualOperator, creftype, creftype, script::Scope{ e->rootNamespace() }, script::OperatorLookup::ConsiderCurrentScope);
      auto resol = script::OverloadResolution::New(e);
      if (!resol.process(ops, { creftype, creftype }))
        throw std::runtime_error{ "TypeInfo::get(): type must be equality-comparable" };

      ret->eq = resol.selectedOverload();
      if (!check_op_eq(t.baseType(), ret->eq))
        throw std::runtime_error{ "TypeInfo::get(): invalid operator==" };
    }

    {
      std::vector<script::Function> ops = script::NameLookup::resolve(script::AssignmentOperator, reftype, creftype, script::Scope{ e->rootNamespace() }, script::OperatorLookup::ConsiderCurrentScope);
      auto resol = script::OverloadResolution::New(e);
      if (!resol.process(ops, { reftype, creftype }))
        throw std::runtime_error{ "TypeInfo::get(): type must be assignable" };

      ret->assign = resol.selectedOverload();
      if (!check_op_assign(t.baseType(), ret->assign))
        throw std::runtime_error{ "TypeInfo::get(): invalid operator=" };
    }

    {
      std::vector<script::Function> ops = script::NameLookup::resolve(script::LessOperator, creftype, creftype, script::Scope{ e->rootNamespace() }, script::OperatorLookup::ConsiderCurrentScope);
      auto resol = script::OverloadResolution::New(e);
      if (!resol.process(ops, { creftype, creftype }))
        throw std::runtime_error{ "TypeInfo::get(): type must have operator<" };

      ret->less = resol.selectedOverload();
      if (!check_op_less(t.baseType(), ret->less))
        throw std::runtime_error{ "TypeInfo::get(): invalid operator<" };
    }
  }
  else
  {
    throw std::runtime_error{ "Not implemented" };
  }

  typeinfomap[t.baseType().data()] = ret;
  return ret;
}

std::shared_ptr<TypeInfo> TypeInfo::get(const script::Class & cla)
{
  return std::static_pointer_cast<TypeInfo>(cla.data());
}

Value::Value()
  : typeinfo_(nullptr)
{

}

Value::Value(const Value & other)
  : typeinfo_(other.typeinfo_)
{
  if (other.isValid())
    value_ = engine()->copy(other.value_);
}

Value::Value(Value && other)
  : typeinfo_(other.typeinfo_)
  , value_(other.value_)
{
  other.typeinfo_ = nullptr;
  other.value_ = script::Value{};
}

Value::Value(const std::shared_ptr<TypeInfo> & ti, const script::Value & val)
  : typeinfo_(ti)
{
  value_ = engine()->copy(val);
}

Value::Value(const std::shared_ptr<TypeInfo> & ti, script::Value && val)
  : typeinfo_(ti)
  , value_(val)
{

}

Value::Value(const script::Value & val)
{
  typeinfo_ = TypeInfo::get(val.engine(), val.type());
  value_ = engine()->copy(val);
}

Value::Value(script::Value && val)
  : value_(val)
{
  typeinfo_ = TypeInfo::get(val.engine(), val.type());
}

Value::~Value()
{
  if (isValid())
    engine()->destroy(value_);
  value_ = script::Value{};
}

script::Value Value::release()
{
  typeinfo_ = nullptr;
  script::Value ret = value_;
  value_ = script::Value{};
  return ret;
}

void Value::assign(const script::Value & v)
{
  assert(isValid());
  assert(typeinfo_->element_type == v.type());

  typeinfo_->engine->invoke(typeinfo_->assign, { value_, v });
}

Value & Value::operator=(const Value & other)
{
  if (value_ == other.value_)
    return *(this);

  if (isValid())
    engine()->destroy(value_);

  typeinfo_ = other.typeinfo_;
  if(isValid())
    value_ = engine()->copy(other.value_);

  return *(this);
}

Value & Value::operator=(Value && other)
{
  typeinfo_ = other.typeinfo_;
  value_ = other.value_;

  other.typeinfo_ = nullptr;
  other.value_ = script::Value{};

  return *this;
}

bool Value::operator==(const Value & other) const
{
  if (other.isNull() && isNull())
    return true;

  if (other.isNull() != isNull())
    return false;

  auto ret = engine()->invoke(typeinfo_->eq, { value_, other.value_ });
  bool result = ret.toBool();
  engine()->destroy(ret);
  return result;
}

bool Value::operator!=(const Value & other) const
{
  return !(*this == other);
}

bool Value::operator<(const Value & other) const
{
  assert(!typeinfo_->less.isNull());

  script::Engine *e = typeinfo_->engine;
  script::Value ret = e->invoke(typeinfo_->less, { value_, other.value_ });
  bool result = ret.toBool();
  e->destroy(ret);
  return result;
}

ObserverValue::ObserverValue(const std::shared_ptr<TypeInfo> & ti, const script::Value & val)
  : Value()
{
  typeinfo_ = ti;
  value_ = val;
}

ObserverValue::~ObserverValue()
{
  release();
}

} // namespace yasl
