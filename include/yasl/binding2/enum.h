// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING2_ENUM_H
#define YASL_BINDING2_ENUM_H

#include <script/engine.h>
#include <script/value.h>
#include <script/enumerator.h>

namespace script
{

namespace bind
{

inline script::Value make_enum(script::Engine *e, const script::Type &enum_type, int val)
{
  return script::Value::fromEnumerator(script::Enumerator{ e->getEnum(enum_type), val });
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_ENUM_H
