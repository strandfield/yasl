// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_DEFAULT_ARGUMENTS_H
#define YASL_BINDING_DEFAULT_ARGUMENTS_H

#include "yasl/common/values.h"

namespace script
{

namespace bind
{

std::shared_ptr<script::program::Expression> make_default_argument(script::Value val);

template<typename Builder>
void add_default_args(Builder &)
{

}

template<typename Builder>
void add_default_args(Builder &b, bool val)
{
  b.addDefaultArgument(make_default_argument(b.engine->newBool(val)));
}

template<typename Builder>
void add_default_args(Builder &b, char val)
{
  b.addDefaultArgument(make_default_argument(b.engine->newChar(val)));
}

template<typename Builder>
void add_default_args(Builder &b, int val)
{
  b.addDefaultArgument(make_default_argument(b.engine->newInt(val)));
}

template<typename Builder>
void add_default_args(Builder &b, float val)
{
  b.addDefaultArgument(make_default_argument(b.engine->newFloat(val)));
}

template<typename Builder>
void add_default_args(Builder &b, double val)
{
  b.addDefaultArgument(make_default_argument(b.engine->newDouble(val)));
}

template<typename Builder, typename T>
void add_default_args(Builder &b, const T & n)
{
  b.addDefaultArgument(make_default_argument(make_value(n, b.engine)));
}

template<typename Builder, typename T, typename...Args>
void add_default_args(Builder &b, const T& arg, const Args &...args)
{
  add_default_args(b, arg);
  add_default_args(b, args...);
}

template<typename Builder, typename Tuple, size_t... I>
auto set_default_args(Builder &b, Tuple t, std::index_sequence<I...>)
{
  return add_default_args(b, std::get<I>(t) ...);
}

template<typename...Args>
struct default_arguments_t
{
  using Tuple = std::tuple<Args...>;
  Tuple values;

  template<typename Builder>
  void operator()(Builder & b) const
  {
    static constexpr auto size = std::tuple_size<Tuple>::value;
    return set_default_args(b, values, std::make_index_sequence<size>{});
  }
};

template<typename...Args>
default_arguments_t<Args...> default_arguments(const Args &... args)
{
  return default_arguments_t<Args...>{std::make_tuple(args...)};
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING_DEFAULT_ARGUMENTS_H
