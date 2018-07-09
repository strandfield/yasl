// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/string.h"

#include "yasl/core/list.h"

#include <script/classtemplate.h>
#include <script/engine.h>

void register_stringlist_class(script::Namespace n)
{
  using namespace script;

  register_ptr_specialization<QString>(n.engine()->getTemplate(Engine::PtrTemplate), Type::PtrQString);
  register_list_specialization<QString>(n.engine()->getTemplate(Engine::ListTemplate), Type::QStringList);
}
