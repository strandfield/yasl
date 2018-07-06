// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/string.h"

#include "yasl/core/list.h"

#include <script/classtemplate.h>
#include <script/engine.h>

static int ptr_string_type_id = 0;
static int stringlist_type_id = 0;

script::Type get_ptr_string_type()
{
  return script::Type{ ptr_string_type_id };
}

script::Type get_stringlist_type()
{
  return script::Type{ stringlist_type_id };
}

void register_stringlist_class(script::Namespace n)
{
  using namespace script;

  register_ptr_specialization<QString>(get_ptr_template(), &ptr_string_type_id);
  register_list_specialization<QString>(get_qlist_template(), &stringlist_type_id);
}
