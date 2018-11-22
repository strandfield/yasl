// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING2_QSIGNAL_H
#define YASL_BINDING2_QSIGNAL_H

#include "yasl/binding2/types.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/value.h>

namespace script
{

namespace bind
{

void register_signal(script::Class & cla, const QMetaObject *meta, const script::Function & f, const std::string & signature);
script::Value signal_callback(script::FunctionCall *c);

template<typename T, typename A1, typename A2, typename A3, typename A4>
script::Function signal(script::Class & cla, std::string &&name, const std::string & signature)
{
  script::Function ret = cla.newMethod(std::move(name), signal_callback)
    .params(make_type<A1>(), make_type<A2>(), make_type<A3>(), make_type<A4>())
    .get();

  register_signal(cla, &T::staticMetaObject, ret, signature);

  return ret;
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_QSIGNAL_H
