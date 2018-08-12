// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_SIGNALS_H
#define YASL_CORE_SIGNALS_H

#include <script/class.h>
#include <script/function.h>

struct QMetaObject;

void register_signal(script::Class & cla, const QMetaObject *meta, const script::Function & f, const std::string & signature);

namespace callbacks
{
script::Value signal_callback(script::FunctionCall *c);
} // namespace callbacks

#endif // YASL_CORE_SIGNALS_H
