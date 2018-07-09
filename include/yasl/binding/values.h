// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_VALUES_H
#define YASL_BINDING_VALUES_H

#include "yasl/binding/enum.h"
#include "yasl/binding/types.h"

#include <script/engine.h>
#include <script/value.h>
#include <script/private/value_p.h>

#include <string>

namespace binding
{

struct large_object_tag {};
struct small_object_tag {};
struct enum_tag {};

template<bool isSmall, bool isEnum>
struct tag_resolver_impl;

template<bool isSmall>
struct tag_resolver_impl<isSmall, true>
{
  typedef enum_tag type;
};

template<>
struct tag_resolver_impl<true, false>
{
  typedef small_object_tag type;
};

template<>
struct tag_resolver_impl<false, false>
{
  typedef large_object_tag type;
};

template<typename T>
struct tag_resolver
{
  typedef typename tag_resolver_impl<(sizeof(T) <= sizeof(script::ValueImpl::BuiltIn)), std::is_enum<T>::value>::type tag_type;
};

} // namespace binding


namespace binding
{

#if defined(YASL_BINDING_COMPILE_TIME_CHECK)
template<typename T, typename Tag = typename tag_resolver<T>::tag_type>
struct make_value_t;
#else
template<typename T, typename Tag = typename tag_resolver<T>::tag_type>
struct make_value_t
{
  static script::Value make(const T & input, script::Engine *e)
  {
    throw std::runtime_error{ "Cannot create value of an unknown type..." };
  }
};
#endif // defined(YASL_BINDING_COMPILE_TIME_CHECK)

template<typename T>
struct make_value_t<T, small_object_tag>
{
  static script::Value make(const T & input, script::Engine *e)
  {
    script::Value ret = e->uninitialized(make_type<T>());
    new (&ret.impl()->data.memory) T(input);
    ret.impl()->type = ret.impl()->type.withoutFlag(script::Type::UninitializedFlag);
    return ret;
  }
};

template<typename T>
struct make_value_t<T, large_object_tag>
{
  static script::Value make(const T & input, script::Engine *e)
  {
    script::Value ret = e->uninitialized(make_type<T>());
    ret.impl()->data.ptr = new T(input);
    ret.impl()->type = ret.impl()->type.withoutFlag(script::Type::UninitializedFlag);
    return ret;
  }
};

template<typename T>
struct make_value_t<T, enum_tag>
{
  static script::Value make(const T & input, script::Engine *e)
  {
    return make_enum(e, make_type<T>(), input);
  }
};


template<typename T>
script::Value make_value(const T & val, script::Engine *e)
{
  return make_value_t<T>::make(val, e);
}

template<typename T>
script::Value make_value(T *val, script::Engine *e)
{
  return make_value_t<T>::make(val, e);
}

template<> inline script::Value make_value<bool>(const bool & x, script::Engine *e) { return e->newBool(x); }
template<> inline script::Value make_value<char>(const char & x, script::Engine *e) { return e->newChar(x); }
template<> inline script::Value make_value<int>(const int & x, script::Engine *e) { return e->newInt(x); }
template<> inline script::Value make_value<float>(const float & x, script::Engine *e) { return e->newFloat(x); }
template<> inline script::Value make_value<double>(const double & x, script::Engine *e) { return e->newDouble(x); }
template<> inline script::Value make_value<script::String>(const script::String & x, script::Engine *e) { return e->newString(x); }

/// TODO !!!
template<> inline script::Value make_value<qint64>(const qint64 & x, script::Engine *e) { return e->newInt(x); }

} // namespace binding



namespace binding
{

static const int small_type_tag = 1;
static const int small_reference_tag = 2;
static const int small_pointer_tag = 3;
static const int small_enum_tag = 4;
static const int large_type_tag = 5;

template<typename T>
struct is_small_type
{
  constexpr static const bool value = (sizeof(T) <= sizeof(script::ValueImpl::BuiltIn))
    && std::is_same<std::remove_reference_t<T>, T>::value
    && std::is_same<std::remove_pointer_t<T>, T>::value
    && !std::is_enum<T>::value;
};

template<typename T>
struct is_small_reference
{
  constexpr static const bool value = (sizeof(T) <= sizeof(script::ValueImpl::BuiltIn))
    && std::is_reference<T>::value
    && !std::is_enum<T>::value;
};

template<typename T>
struct is_small_pointer
{
  constexpr static const bool value = (sizeof(T) <= sizeof(script::ValueImpl::BuiltIn))
    && std::is_pointer<T>::value;
};

template<typename T>
struct is_large_type
{
  constexpr static const bool value = (sizeof(script::ValueImpl::BuiltIn) < sizeof(T));
};


template<typename T>
struct value_cast_tag_resolver
{
  constexpr static const int value = 
    is_small_type<T>::value * small_type_tag
    + is_small_reference<T>::value * small_reference_tag
    + is_small_pointer<T>::value * small_pointer_tag
    + std::is_enum<T>::value * small_enum_tag
    + is_large_type<T>::value * small_pointer_tag;
};

template<typename T, int Tag = value_cast_tag_resolver<T>::value>
struct value_cast_helper;

template<typename T>
struct value_cast_helper<T, small_type_tag>
{
  static T impl(const script::Value & val)
  {
    return *reinterpret_cast<T*>(&val.impl()->data.memory);
  }
};

template<typename T>
struct value_cast_helper<T, small_reference_tag>
{
  static T impl(const script::Value & val)
  {
    using U = std::remove_reference_t<T>;
    return *reinterpret_cast<U*>(&val.impl()->data.memory);
  }
};

template<typename T>
struct value_cast_helper<T, small_pointer_tag>
{
  static T impl(const script::Value & val)
  {
    return reinterpret_cast<T>(&val.impl()->data.memory);
  }
};

template<typename T>
struct value_cast_helper<T, small_enum_tag>
{
  static T impl(const script::Value & val)
  {
    return static_cast<T>(val.impl()->get_enum_value().value());
  }
};


template<typename T>
struct value_cast_helper<T, large_type_tag>
{
  static T impl(const script::Value & val)
  {
    return *reinterpret_cast<T*>(val.impl()->data.ptr);
  }
};


template<typename T>
T value_cast(const script::Value & val)
{
  return value_cast_helper<T>::impl(val);
}

template<> inline bool value_cast<bool>(const script::Value & v) { return v.impl()->data.boolean; }
template<> inline bool& value_cast<bool&>(const script::Value & v) { return v.impl()->data.boolean; }
template<> inline const bool& value_cast<const bool&>(const script::Value & v) { return v.impl()->data.boolean; }

template<> inline char value_cast<char>(const script::Value & v) { return v.impl()->data.character; }
template<> inline char& value_cast<char&>(const script::Value & v) { return v.impl()->data.character; }
template<> inline const char& value_cast<const char&>(const script::Value & v) { return v.impl()->data.character; }

template<> inline int value_cast<int>(const script::Value & v) { return v.impl()->data.integer; }
template<> inline int& value_cast<int&>(const script::Value & v) { return v.impl()->data.integer; }
template<> inline const int& value_cast<const int&>(const script::Value & v) { return v.impl()->data.integer; }

template<> inline float value_cast<float>(const script::Value & v) { return v.impl()->data.realf; }
template<> inline float& value_cast<float&>(const script::Value & v) { return v.impl()->data.realf; }
template<> inline const float& value_cast<const float&>(const script::Value & v) { return v.impl()->data.realf; }

template<> inline double value_cast<double>(const script::Value & v) { return v.impl()->data.reald; }
template<> inline double& value_cast<double&>(const script::Value & v) { return v.impl()->data.reald; }
template<> inline const double& value_cast<const double&>(const script::Value & v) { return v.impl()->data.reald; }

template<> inline script::String value_cast<script::String>(const script::Value & v) { return v.impl()->data.builtin.string; }
template<> inline script::String& value_cast<script::String&>(const script::Value & v) { return v.impl()->data.builtin.string; }
template<> inline const script::String& value_cast<const script::String&>(const script::Value & v) { return v.impl()->data.builtin.string; }

/// TODO !!!
template<> inline qint64 value_cast<qint64>(const script::Value & v) { return v.impl()->data.integer; }
template<> inline qulonglong value_cast<qulonglong>(const script::Value & v) { return v.impl()->data.integer; }
template<> inline short value_cast<short>(const script::Value & v) { return v.impl()->data.integer; }
template<> inline uint value_cast<uint>(const script::Value & v) { return v.impl()->data.integer; }
template<> inline ushort value_cast<ushort>(const script::Value & v) { return v.impl()->data.integer; }

} // namespace binding

#endif // YASL_BINDING_VALUES_H
