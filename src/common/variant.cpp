// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/common/variant.h"

#include "yasl/common/value.h"

#include <script/engine.h>

#include <map>
#include <memory>

namespace script
{

bool operator<(const script::Type & lhs, const script::Type & rhs)
{
  return lhs.data() < rhs.data();
}

} // namespace script

namespace yasl
{

struct VariantEngine
{
  std::map<script::Type, std::unique_ptr<VariantHandler>> handlers;
  std::map<QVariant::Type, script::Type> typemap;
};

VariantEngine* get_variant_engine()
{
  static VariantEngine vaeng = {};
  return &vaeng;
}

void register_variant_handler(VariantHandler *handler)
{
  auto *vaeng = get_variant_engine();
  vaeng->handlers[handler->script_type()] = std::unique_ptr<VariantHandler>(handler);
  vaeng->typemap[handler->qt_type()] = handler->script_type();
}

QVariant make_qvariant(const script::Value & v)
{
  switch (v.type().baseType().data())
  {
  case script::Type::Boolean:
    return QVariant(v.toBool());
  case script::Type::Char:
    return QVariant(v.toChar());
  case script::Type::Int:
    return QVariant(v.toInt());
  case script::Type::Float:
    return QVariant(v.toFloat());
  case script::Type::Double:
    return QVariant(v.toDouble());
  case script::Type::String:
    return QVariant(v.toString());
  default:
    break;
  }

  auto *vaeng = get_variant_engine();
  auto it = vaeng->handlers.find(v.type().baseType());
  if (it != vaeng->handlers.end())
  {
    return it->second->to_qvariant(v);
  }
  else
  {
    auto typeinfo = TypeInfo::get(v.engine(), v.type());
    return QVariant::fromValue(yasl::Value{ typeinfo, v });
  }
}

script::Value get_variant_value(script::Engine *e, const QVariant & v)
{
  if (v.type() == qMetaTypeId<yasl::Value>())
    return v.value<yasl::Value>().release();

  switch (v.type())
  {
  case QMetaType::Bool:
    return e->newBool(v.toBool());
  case QMetaType::Char:
    return e->newChar(v.value<char>());
  case QMetaType::Int:
    return e->newInt(v.toInt());
  case QMetaType::Float:
    return e->newFloat(v.toFloat());
  case QMetaType::Double:
    return e->newDouble(v.toDouble());
  case QMetaType::QString:
    return e->newString(v.toString());
  default:
    break;
  }

  auto *vaeng = get_variant_engine();
  script::Type t = vaeng->typemap.at(v.type());
  return vaeng->handlers[t]->from_qvariant(e, v);
}

script::Type get_variant_value_type(const QVariant & v)
{
  if (v.type() == qMetaTypeId<yasl::Value>())
    return v.value<yasl::Value>().get().type();

  switch (v.type())
  {
  case QMetaType::Bool:
    return script::Type::Boolean;
  case QMetaType::Char:
    return script::Type::Char;
  case QMetaType::Int:
    return script::Type::Int;
  case QMetaType::Float:
    return script::Type::Float;
  case QMetaType::Double:
    return script::Type::Double;
  case QMetaType::QString:
    return script::Type::String;
  default:
    break;
  }

  auto *vaeng = get_variant_engine();
  return vaeng->typemap.at(v.type());
}

} // namespace yasl
