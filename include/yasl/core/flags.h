// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FLAGS_H
#define YASL_CORE_FLAGS_H

#include "yasl/common/binding/class.h"

#include <script/classbuilder.h>
#include <script/namespace.h>

#include <QFlags>

template<typename T>
script::Class register_qflags_type_impl(script::Class flags)
{
  using namespace script;

  using FlagType = QFlags<T>;

  // QFlags(const QFlags<T> & other);
  bind::copy_constructor<FlagType>(flags).create();
  // QFlags(T flags);
  bind::constructor<FlagType, T>(flags).create();
  // QFlag(Flag flag); // almost equivalent to QFlag(int);
  bind::constructor<FlagType, int>(flags).create();
  // QFlags(std::initializer_list<T> flags)
  /// TODO !!
  // ~QFlags();
  bind::destructor<FlagType>(flags).create();

#if QT_VERSION >= QT_VERSION_CHECK(5, 7, 0)
  // QFlags<T> & setFlag(T flag, bool on = true);
  bind::chainable_memfn<FlagType, T, bool, &FlagType::setFlag>(flags, "setFlag").create();
#endif
  // bool testFlag(T flag) const;
  bind::member_function<FlagType, bool, T, &FlagType::testFlag>(flags, "testFlag").create();

  // operator QFlags::Int() const
  /// TODO !!
  // bool operator!() const;
  /// TODO !!
  // QFlags<T> operator&(int mask) const
  bind::memop_bitand<FlagType, FlagType, int>(flags);
  // QFlags<T> operator&(uint mask) const
  // QFlags<T> operator&(Enum other) const
  bind::memop_bitand<FlagType, FlagType, T>(flags);
  // QFlags<T> & operator&=(int mask)
  bind::memop_and_assign<FlagType, int>(flags);
  // QFlags<T> & operator&=(uint mask)
  // QFlags<T> & operator&=(Enum mask)
  bind::memop_and_assign<FlagType, T>(flags);
  // QFlags<T> & operator=(const QFlags<T> &other)
  bind::memop_assign<FlagType, const FlagType&>(flags);
  // QFlags<T> operator^(QFlags<T> other) const
  /// TODO !!
  // QFlags<T> operator^(Enum other) const
  /// TODO !!
  // QFlags<T> & operator^=(QFlags<T> other)
  /// TODO !!
  // QFlags<T> & operator^=(Enum other)
  /// TODO !!
  // QFlags<T> operator|(QFlags<T> other) const
  bind::memop_bitor<FlagType, FlagType, const FlagType &>(flags);
  // QFlags<T> operator|(Enum other) const
  bind::memop_bitor<FlagType, FlagType, T>(flags);
  // QFlags<T> & operator|=(QFlags<T> other)
  bind::memop_or_assign<FlagType, const FlagType &>(flags);
  // QFlags<T> & operator|=(Enum other)
  bind::memop_or_assign<FlagType, T>(flags);
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
