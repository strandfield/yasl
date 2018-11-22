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

namespace callbacks {
  script::Value signal_callback(script::FunctionCall *c);
}

template<typename T>
script::Function signal(script::Class & cla, std::string &&name, const std::string & signature)
{
  script::Function ret = cla.newMethod(std::move(name), callbacks::signal_callback)
    .get();

  register_signal(cla, &T::staticMetaObject, ret, signature);

  return ret;
}

template<typename T, typename A, typename... Rest>
script::Function signal(script::Class & cla, std::string &&name, const std::string & signature)
{
  script::Function ret = cla.newMethod(std::move(name), callbacks::signal_callback)
    .params(make_type<A>(), make_type<Rest>()...)
    .get();

  register_signal(cla, &T::staticMetaObject, ret, signature);

  return ret;
}

void register_signals_file(script::Namespace core);

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_QSIGNAL_H
