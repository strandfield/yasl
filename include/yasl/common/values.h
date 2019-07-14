// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_COMMONS_VALUES_H
#define YASL_COMMONS_VALUES_H

#include "yasl/common/enums.h"
#include "yasl/common/types.h"

#include <script/engine.h>
#include <script/value.h>

#include <string>

namespace script
{

template<typename T, typename Tag = typename details::tag_resolver<T>::tag_type>
struct make_value_t;

template<typename T>
struct make_value_t<T, details::small_object_tag>
{
  static script::Value make(const T & input, script::Engine *e)
  {
    return e->construct<T>(input);
  }
};

template<typename T>
struct make_value_t<T, details::large_object_tag>
{
  static script::Value make(const T & input, script::Engine *e)
  {
    return e->construct<T>(input);
  }
};

template<typename T>
struct make_value_t<T, details::enum_tag>
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

} // namespace script

namespace script
{

struct value_storage_tag {};
struct reference_storage_tag {};
struct pointer_storage_tag {};

template<typename T>
struct value_storage
{
  typedef value_storage_tag type;
};

template<typename T>
struct reference_storage
{
  typedef reference_storage_tag type;
};

template<typename T>
struct pointer_storage
{
  typedef pointer_storage_tag type;
};

template<typename T, typename Tag = typename details::tag_resolver<T>::tag_type>
struct storage_type_default_impl;

template<typename T>
struct storage_type_default_impl<T, details::small_object_tag> : reference_storage<T> { };

template<typename T>
struct storage_type_default_impl<T, details::large_object_tag> : reference_storage<T> { };

template<typename T>
struct storage_type_default_impl<T, details::enum_tag> : value_storage<T> { };

template<typename T>
struct storage_type
{
  typedef typename storage_type_default_impl<T>::type type;
};

template<typename T>
struct decay
{
  typedef typename std::decay<typename std::remove_pointer<T>::type>::type type;
};

template<typename T, typename StorageType = typename storage_type<typename decay<T>::type>::type>
struct value_cast_helper;

template<typename T>
struct value_cast_helper<T, value_storage_tag>
{
  static T impl(const script::Value & val)
  {
    return get<typename decay<T>::type>(val);
  }
};

template<typename T>
struct value_cast_helper<T, reference_storage_tag>
{
  static T impl(const script::Value & val)
  {
    return get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<T&, reference_storage_tag>
{
  static T& impl(const script::Value& val)
  {
    return get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<T*, reference_storage_tag>
{
  static T* impl(const script::Value & val)
  {
    return std::addressof(get<T>(val));
  }
};

template<typename T>
struct value_cast_helper<const T*, reference_storage_tag>
{
  static const T* impl(const script::Value & val)
  {
    return std::addressof(get<T>(val));
  }
};

template<typename T>
struct value_cast_helper<T&&, reference_storage_tag>
{
  static T&& impl(const script::Value & val)
  {
    return std::move(get<T>(val));
  }
};

template<typename T>
struct value_cast_helper<const T&, reference_storage_tag>
{
  static const T& impl(const script::Value & val)
  {
    return get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<T&, pointer_storage_tag>
{
  static T& impl(const script::Value & val)
  {
    return *get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<const T&, pointer_storage_tag>
{
  static const T& impl(const script::Value& val)
  {
    return *get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<T*, pointer_storage_tag>
{
  static T* impl(const script::Value& val)
  {
    return get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<const T*, pointer_storage_tag>
{
  static const T* impl(const script::Value & val)
  {
    return get<T>(val);
  }
};

template<typename T>
T value_cast(const script::Value & val)
{
  return value_cast_helper<T>::impl(val);
}

} // namespace script

#endif // YASL_COMMONS_VALUES_H
