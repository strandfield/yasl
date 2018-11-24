// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_VALUE_H
#define YASL_COMMONS_VALUE_H

#include <script/function.h>
#include <script/value.h>
#include <script/userdata.h>

#include <QMetaType>

namespace yasl
{

struct TypeInfo : public script::UserData
{
  script::Type element_type;
  script::Engine *engine;
  script::Function eq;

  static std::shared_ptr<TypeInfo> get(script::Engine *e, const script::Type & t);
  static std::shared_ptr<TypeInfo> get(const script::Class & cla);
};

class Value
{
public:
  Value();
  Value(const Value & other);
  Value(Value && other);
  Value(const std::shared_ptr<TypeInfo> & ti, const script::Value & val);
  Value(const std::shared_ptr<TypeInfo> & ti, script::Value && val);
  explicit Value(const script::Value & val);
  explicit Value(script::Value && val);
  ~Value();

  inline script::Value & get() { return value_; }
  inline const script::Value & get() const { return value_; }
  script::Value release();

  inline bool isValid() const { return typeinfo_ != nullptr && !value_.isNull(); }
  inline bool isNull() const { return typeinfo_ == nullptr || value_.isNull(); }
  inline script::Engine *engine() const { return typeinfo_->engine; }

  Value & operator=(const Value & other);
  Value & operator=(Value && other);
  bool operator==(const Value & other) const;

protected:
  std::shared_ptr<TypeInfo> typeinfo_;
  script::Value value_;
};

class ObserverValue : public Value
{
public:
  ObserverValue(const std::shared_ptr<TypeInfo> & ti, const script::Value & val);
  ~ObserverValue();
};

} // namespace yasl

Q_DECLARE_METATYPE(yasl::Value)

#endif // YASL_COMMONS_VALUE_H
