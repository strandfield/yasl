// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_UTILS_CONTAINER_VALUE_H
#define YASL_UTILS_CONTAINER_VALUE_H

#include <script/value.h>
#include <script/userdata.h>

struct ContainerData : public script::UserData
{
  script::Type element_type;
  script::Engine *engine;
  script::Function assignment;
  script::Function compare;

  static std::shared_ptr<ContainerData> get(const script::Function & f);
};

// gives value semantic to a script::Value
struct ContainerValue
{
  ContainerValue();
  ContainerValue(const ContainerValue & other);
  ContainerValue(ContainerValue && other);
  ContainerValue(const std::shared_ptr<ContainerData> & c, const script::Value & val);
  ~ContainerValue();

  inline bool isValid() const { return container != nullptr; }
  inline bool isNull() const { return container == nullptr; }
  script::Engine *engine() const;

  script::Value release();

  ContainerValue & operator=(const ContainerValue & other);
  bool operator==(const ContainerValue & other) const;

  std::shared_ptr<ContainerData> container;
  script::Value value;
};

struct TemporaryContainerValueWrap : public ContainerValue
{
  TemporaryContainerValueWrap(const std::shared_ptr<ContainerData> & c, const script::Value & val);
  ~TemporaryContainerValueWrap();
};

#endif // YASL_UTILS_CONTAINER_VALUE_H
