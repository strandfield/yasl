// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QSIGNAL_H
#define YASL_BINDING_QSIGNAL_H

#include "yasl/common/types.h"
#include "yasl/common/signal-utils.h"

#include <script/class.h>
#include <script/function.h>
#include <script/functionbuilder.h>
#include <script/value.h>

namespace script
{

namespace callbacks {
script::Value signal_callback(script::FunctionCall *c);
}

namespace bind
{

template<typename T>
script::Function signal(script::Class & cla, std::string &&name, const std::string & signature)
{
  script::Function ret = cla.newMethod(std::move(name), callbacks::signal_callback)
    .get();

  yasl::registerSignal(cla, &T::staticMetaObject, ret, signature);

  return ret;
}

template<typename T, typename A, typename... Rest>
script::Function signal(script::Class & cla, std::string &&name, const std::string & signature)
{
  script::Function ret = cla.newMethod(std::move(name), callbacks::signal_callback)
    .params(make_type<A>(), make_type<Rest>()...)
    .get();

  yasl::registerSignal(cla, &T::staticMetaObject, ret, signature);

  return ret;
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING_QSIGNAL_H
