// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/binding/default_arguments.h"

#include <script/program/expression.h>

namespace binding
{

std::shared_ptr<script::program::Expression> make_default_argument(script::Value val)
{
  val.engine()->manage(val);
  return script::program::VariableAccess::New(val);
}

std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, bool val)
{
  return make_default_argument(e->newBool(val));
}

std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, int val)
{
  return make_default_argument(e->newInt(val));
}

std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, float val)
{
  return make_default_argument(e->newFloat(val));
}

std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, double val)
{
  return make_default_argument(e->newDouble(val));
}

} // namespace binding
