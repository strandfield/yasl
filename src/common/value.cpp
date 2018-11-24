// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/value.h"

#include <script/class.h>
#include <script/engine.h>

namespace yasl
{

Value::Value()
  : typeinfo_(nullptr)
{

}

Value::Value(const Value & other)
  : typeinfo_(other.typeinfo_)
{
  if (isValid())
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

  auto ret = engine()->invoke(typeinfo_->compare, { value_, other.value_ });
  bool result = ret.toBool();
  engine()->destroy(ret);
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
