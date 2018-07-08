// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FLAGS_H
#define YASL_CORE_FLAGS_H

#include "yasl/binding/class.h"
#include "yasl/binding/utils.h"
#include "yasl/binding/wraputils.h"

#include <script/namespace.h>

#include <Qt>

template<typename T>
script::Class register_qflags_type_impl(script::Class flags)
{
  using namespace script;

  binding::Class<QFlags<T>> f{ flags };

  // QFlags(const QFlags<T> & other);
  f.ctors().add<const QFlags<T> &>();
  // QFlags(T flags);
  f.ctors().add<T>();
  // QFlag(Flag flag); // almost equivalent to QFlag(int);
  f.ctors().add<int>();
  // QFlags(std::initializer_list<T> flags)
  /// TODO !!

  // QFlags<T> & setFlag(T flag, bool on = true);
  //f.add_chainable<T, bool, &QFlags<T>::setFlag>("setFlag");
  YASL_CHAINABLE_METHOD_2(flags, "setFlag", QFlags<T>, setFlag, T, bool).create();
  // bool testFlag(T flag) const;
  //f.add_fun<bool, T, &QFlags<T>::testFlag>("testFlag");
  YASL_METHOD_1(flags, "testFlag", bool, QFlags<T>, testFlag, T).setConst().create();

  // operator QFlags::Int() const
  /// TODO !!
  // bool operator!() const;
  /// TODO !!
  // QFlags<T> operator&(int mask) const
  f.operators().and<QFlags<T>, int>();
  // QFlags<T> operator&(uint mask) const
  // QFlags<T> operator&(Enum other) const
  f.operators().and<QFlags<T>, T>();
  // QFlags<T> & operator&=(int mask)
  f.operators().and_assign<int>();
  // QFlags<T> & operator&=(uint mask)
  // QFlags<T> & operator&=(Enum mask)
  f.operators().and_assign<T>();
  // QFlags<T> & operator=(const QFlags<T> &other)
  f.operators().assign<const QFlags<T> &>();
  // QFlags<T> operator^(QFlags<T> other) const
  /// TODO !!
  // QFlags<T> operator^(Enum other) const
  /// TODO !!
  // QFlags<T> & operator^=(QFlags<T> other)
  /// TODO !!
  // QFlags<T> & operator^=(Enum other)
  /// TODO !!
  // QFlags<T> operator|(QFlags<T> other) const
  f.operators().or<QFlags<T>, QFlags<T>>();
  // QFlags<T> operator|(Enum other) const
  f.operators().or<QFlags<T>, T>();
  // QFlags<T> & operator|=(QFlags<T> other)
  f.operators().or_assign<QFlags<T>>();
  // QFlags<T> & operator|=(Enum other)
  f.operators().or_assign<T>();
  // QFlags<T> operator~() const
  /// TODO !!

  return flags;
}

template<typename T>
script::Class register_qflags_type(script::Namespace root, const std::string & name, int type_id)
{
  using namespace script;

  Class flags = root.newClass(ClassBuilder::New(name).setFinal().setId(type_id));
  register_qflags_type_impl<T>(flags);
  return flags;
}

template<typename T>
script::Class register_qflags_type(script::Class c, const std::string & name, int type_id)
{
  using namespace script;

  Class flags = c.newClass(ClassBuilder::New(name).setFinal().setId(type_id));
  register_qflags_type_impl<T>(flags);
  return flags;
}

#endif // YASL_CORE_FLAGS_H
