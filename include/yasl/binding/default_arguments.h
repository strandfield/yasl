// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_DEFAULT_ARGUMENTS_H
#define YASL_BINDING_DEFAULT_ARGUMENTS_H

#include "yasl/binding/values.h"

namespace binding
{

std::shared_ptr<script::program::Expression> make_default_argument(script::Value val);

std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, bool val);
std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, char val);
std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, int val);
std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, float val);
std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, double val);

template<typename T>
std::shared_ptr<script::program::Expression> default_argument(script::Engine *e, const T & val)
{
  return make_default_argument(make_value(val, e));
}

} // namespace binding


#endif // YASL_BINDING_DEFAULT_ARGUMENTS_H
