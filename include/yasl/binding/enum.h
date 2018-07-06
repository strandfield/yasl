// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_ENUM_H
#define YASL_BINDING_ENUM_H

#include <script/engine.h>
#include <script/value.h>
#include <script/enumvalue.h>

namespace binding
{

inline script::Value make_enum(script::Engine *e, const script::Type &enum_type, int val)
{
  return script::Value::fromEnumValue(script::EnumValue{ e->getEnum(enum_type), val });
}

} // namespace binding

#endif // YASL_BINDING_ENUM_H
