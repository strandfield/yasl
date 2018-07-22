// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/utils/containervalue.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/function.h>

std::shared_ptr<ContainerData> ContainerData::get(const script::Function & f)
{
  return std::static_pointer_cast<ContainerData>(f.memberOf().data());
}

ContainerValue::ContainerValue()
  : container(nullptr)
{

}

ContainerValue::ContainerValue(const ContainerValue & other)
  : container(other.container)
{
  if (isValid())
    value = engine()->copy(other.value);
}

ContainerValue::ContainerValue(ContainerValue && other)
  : container(other.container)
  , value(other.value)
{
  other.container = nullptr;
  other.value = script::Value{};
}

ContainerValue::ContainerValue(const std::shared_ptr<ContainerData> & c, const script::Value & val)
  : container(c)
{
  value = engine()->copy(val);
}

ContainerValue::~ContainerValue()
{
  if (isValid())
    engine()->destroy(value);
  value = script::Value{};
}

script::Engine * ContainerValue::engine() const
{
  return container->engine;
}

script::Value ContainerValue::release()
{
  container = nullptr;
  script::Value ret = value;
  value = script::Value{};
  return ret;
}

ContainerValue & ContainerValue::operator=(const ContainerValue & other)
{
  if (value == other.value)
    return *(this);

  if (isValid())
    engine()->destroy(value);

  container = other.container;
  if(isValid())
    value = engine()->copy(other.value);

  return *(this);
}

bool ContainerValue::operator==(const ContainerValue & other) const
{
  if (other.isNull() && isNull())
    return true;

  if (other.isNull() != isNull())
    return false;

  auto ret = engine()->invoke(container->compare, { value, other.value });
  bool result = ret.toBool();
  engine()->destroy(ret);
  return result;
}

TemporaryContainerValueWrap::TemporaryContainerValueWrap(const std::shared_ptr<ContainerData> & c, const script::Value & val)
  : ContainerValue()
{
  container = c;
  value = val;
}

TemporaryContainerValueWrap::~TemporaryContainerValueWrap()
{
  container = nullptr;
  value = script::Value{};
}
