// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING2_DESTRUCTOR_H
#define YASL_BINDING2_DESTRUCTOR_H

#include "yasl/binding2/values.h"

#include "yasl/binding2/destructor_binder.h"

#include <script/class.h>
#include <script/destructorbuilder.h>

namespace script
{

namespace bind
{

template<typename T>
script::DestructorBuilder destructor(Class & c)
{
  return c.newDestructor(destructor_binder<T, typename tag_resolver<T>::tag_type>::destructor);
}

} // namespace bind

} // namespace script

#endif // YASL_BINDING2_DESTRUCTOR_H
