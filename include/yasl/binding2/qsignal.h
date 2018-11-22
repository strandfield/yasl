// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_QSIGNAL_H
#define YASL_BINDING_QSIGNAL_H

#include "yasl/core/signals.h"

#include <script/class.h>
#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/value.h>

namespace binding
{

struct QSignal
{
  script::Class class_;
  const QMetaObject *meta_;

  void register_qsignal(const script::Function & f, const std::string & signature)
  {
    register_signal(class_, meta_, f, signature);
  }

  
  script::Function add(const std::string & name, const std::string & signature)
  {
    auto ret = class_.newMethod(name, callbacks::signal_callback)
      .get();
    register_qsignal(ret, signature);
    return ret;
  }
  
  template<typename A1>
  script::Function add(const std::string & name, const std::string & signature)
  {
    auto ret = class_.newMethod(name, callbacks::signal_callback)
      .params(make_type<A1>())
      .get();
    register_qsignal(ret, signature);
    return ret;
  }

  template<typename A1, typename A2>
  script::Function add(const std::string & name, const std::string & signature)
  {
    auto ret = class_.newMethod(name, callbacks::signal_callback)
      .params(make_type<A1>(), make_type<A2>())
      .get();
    register_qsignal(ret, signature);
    return ret;
  }

  template<typename A1, typename A2, typename A3>
  script::Function add(const std::string & name, const std::string & signature)
  {
    auto ret = class_.newMethod(name, callbacks::signal_callback)
      .params(make_type<A1>(), make_type<A2>(), make_type<A3>())
      .get();
    register_qsignal(ret, signature);
    return ret;
  }
};

} // namespace binding


#endif // YASL_BINDING_QSIGNAL_H
