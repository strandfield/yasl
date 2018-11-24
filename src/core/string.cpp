// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/string.h"

#include "yasl/core/listspecializations.h"

#include <script/namespace.h>

void register_stringlist_class(script::Namespace n)
{
  using namespace script;

  register_proxy_specialization<QString>(n.engine()->getTemplate(Engine::ProxyTemplate), Type::ProxyQString);
  register_list_specialization<QString>(n.engine(), Type::QStringList);
}
