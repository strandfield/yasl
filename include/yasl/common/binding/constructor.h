// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_CONSTRUCTOR_H
#define YASL_BINDING_CONSTRUCTOR_H

#include "yasl/common/values.h"

#include "yasl/common/binding/constructor_binder.h"

#include <script/class.h>
#include <script/constructorbuilder.h>

namespace script
{

namespace bind
{

template<typename T>
script::ConstructorBuilder default_constructor(Class & c)
{
  return c.newConstructor(constructor_binder<T, typename tag_resolver<T>::tag_type>::default_ctor);
}

template<typename T>
script::ConstructorBuilder copy_constructor(Class & c)
{
  return c.newConstructor(constructor_binder<T, typename tag_resolver<T>::tag_type>::copy_ctor)
    .params(script::Type::cref(make_type<T>()));
}

template<typename T, typename... Args>
script::ConstructorBuilder constructor(Class & c)
{
  return c.newConstructor(constructor_binder<T, typename tag_resolver<T>::tag_type>::template generic_ctor<Args...>)
    .params(make_type<Args>()...);
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING_CONSTRUCTOR_H
