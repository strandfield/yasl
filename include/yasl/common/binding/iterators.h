// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_ITERATORS_H
#define YASL_BINDING_ITERATORS_H

#include "yasl/common/wrappers/iterator_wrapper.h"
#include "yasl/common/proxy.h"

#include <script/class.h>
#include <script/functionbuilder.h>

namespace script
{

namespace bind
{

template<typename Iter, typename T>
void const_iter_deref(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::const_iter_deref_wrapper<T, Iter>)
    .setConst()
    .returns(make_type<const T>())
    .create();
}

template<typename Iter, typename T>
void iter_deref(script::Class & cla, std::string && name)
{
  return cla.newMethod(std::move(name), wrapper::iter_deref_wrapper<T, Iter>)
    .setConst()
    .returns(make_type<Proxy<T>>())
    .create();
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING_ITERATORS_H
