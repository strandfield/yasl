// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FLAGS_H
#define YASL_CORE_FLAGS_H

#include "yasl/binding/class.h"

#include <script/classbuilder.h>
#include <script/namespace.h>

#include <QFlags>

template<typename T>
script::Class register_qflags_type_impl(script::Class flags)
{
  using namespace script;

  binding::ClassBinder<QFlags<T>> f{ flags };

  // QFlags(const QFlags<T> & other);
  f.ctor<const QFlags<T> &>().create();
  // QFlags(T flags);
  f.ctor<T>().create();
  // QFlag(Flag flag); // almost equivalent to QFlag(int);
  f.ctor<int>().create();
  // QFlags(std::initializer_list<T> flags)
  /// TODO !!
  // ~QFlags();
  f.dtor().create();

  // QFlags<T> & setFlag(T flag, bool on = true);
  f.chainable<T, bool, &QFlags<T>::setFlag>("setFlag").create();
  // bool testFlag(T flag) const;
  f.fun<bool, T, &QFlags<T>::testFlag>("testFlag").create();

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

  Class flags = root.newClass(name).setFinal().setId(type_id).get();
  register_qflags_type_impl<T>(flags);
  return flags;
}

template<typename T>
script::Class register_qflags_type(script::Class c, const std::string & name, int type_id)
{
  using namespace script;

  Class flags = c.newNestedClass(name).setFinal().setId(type_id).get();
  register_qflags_type_impl<T>(flags);
  return flags;
}

#endif // YASL_CORE_FLAGS_H
