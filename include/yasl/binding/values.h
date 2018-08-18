// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_VALUES_H
#define YASL_BINDING_VALUES_H

#include "yasl/binding/enum.h"
#include "yasl/binding/types.h"
#include "yasl/utils/ref.h"

#include <script/engine.h>
#include <script/value.h>
#include <script/private/value_p.h>

#include <QObject>

#include <string>

namespace binding
{

struct large_object_tag {};
struct small_object_tag {};
struct qobject_tag {};
struct enum_tag {};

template<bool isSmall, bool isEnum, bool isQObject>
struct tag_resolver_impl;

template<bool isSmall>
struct tag_resolver_impl<isSmall, true, false>
{
  typedef enum_tag type;
};

template<>
struct tag_resolver_impl<true, false, false>
{
  typedef small_object_tag type;
};

template<>
struct tag_resolver_impl<false, false, false>
{
  typedef large_object_tag type;
};

template<bool isSmall>
struct tag_resolver_impl<isSmall, false, true>
{
  typedef qobject_tag type;
};

template<typename T>
struct tag_resolver
{
  typedef typename tag_resolver_impl<(sizeof(T) <= sizeof(script::ValueImpl::BuiltIn)), std::is_enum<T>::value, std::is_convertible<T*, QObject*>::value>::type tag_type;
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
struct make_value_t<T, qobject_tag>
{
  static script::Value make(T *input, script::Engine *e)
  {
    return make_ref(e, make_type<T*>(), input);
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

template<typename T>
struct buffer_storage
{
  typedef T& type;
};

template<typename T>
struct heap_storage
{
  typedef T* type;
};

template<typename T>
struct qobject_storage : heap_storage<T> { };

template<typename T, typename Tag = typename tag_resolver<T>::tag_type>
struct storage_type_default_impl;

template<typename T>
struct storage_type_default_impl<T, small_object_tag> : buffer_storage<T> { };

template<typename T>
struct storage_type_default_impl<T, large_object_tag> : heap_storage<T> { };

template<typename T>
struct storage_type_default_impl<T, enum_tag> 
{
  typedef T type;
};

template<typename T>
struct storage_type_default_impl<T, qobject_tag> : qobject_storage<T> { };


template<typename T>
struct storage_type
{
  typedef typename storage_type_default_impl<T>::type type;
};


template<typename T, typename Tag = typename tag_resolver<T>::tag_type>
struct get_helper;

template<typename T>
struct get_helper<T, small_object_tag>
{
  static T& get(const script::Value & val)
  {
    return *reinterpret_cast<T*>(&val.impl()->data.memory);
  }
};

template<typename T>
struct get_helper<T, large_object_tag>
{
  static T* get(const script::Value & val)
  {
    return static_cast<T*>(val.impl()->data.ptr);
  }
};

template<typename T>
struct get_helper<T, enum_tag>
{
  static T get(const script::Value & val)
  {
    return static_cast<T>(val.toEnumerator().value());
  }
};

template<typename T>
struct get_helper<T, qobject_tag>
{
  static T* get(const script::Value & val)
  {
    return qobject_cast<T*>(val.toQObject());
  }
};

template<typename T>
typename storage_type<T>::type get(const script::Value & val)
{
  return get_helper<T>::get(val);
}

template<> inline bool& get<bool>(const script::Value & val) { return val.impl()->data.boolean; }
template<> inline char& get<char>(const script::Value & val) { return val.impl()->data.character; }
template<> inline int& get<int>(const script::Value & val) { return val.impl()->data.integer; }
template<> inline float& get<float>(const script::Value & val) { return val.impl()->data.realf; }
template<> inline double& get<double>(const script::Value & val) { return val.impl()->data.reald; }
template<> inline script::String& get<script::String>(const script::Value & v) { return v.impl()->data.builtin.string; }

template<> struct storage_type<qint64> { typedef qint64 type; };
template<> inline qint64 get<qint64>(const script::Value & v) { return v.impl()->data.integer; }

template<> struct storage_type<qulonglong> { typedef qulonglong type; };
template<> inline qulonglong get<qulonglong>(const script::Value & v) { return v.impl()->data.integer; }

template<> struct storage_type<short> { typedef short type; };
template<> inline short get<short>(const script::Value & v) { return v.impl()->data.integer; }

template<> struct storage_type<uint> { typedef uint type; };
template<> inline uint get<uint>(const script::Value & v) { return v.impl()->data.integer; }

template<> struct storage_type<ushort> { typedef ushort type; };
template<> inline ushort get<ushort>(const script::Value & v) { return v.impl()->data.integer; }

template<typename T>
struct decay
{
  typedef typename std::decay<typename std::remove_pointer<T>::type>::type type;
};


#if defined(YASL_BINDING_COMPILE_TIME_CHECK)
template<typename T, typename StorageType = typename storage_type<decay<T>::type>::type>
struct value_cast_helper;
#else
template<typename T, typename StorageType = typename storage_type<decay<T>::type>::type>
struct value_cast_helper
{
  static T impl(const script::Value & val)
  {
    throw std::runtime_error{ "Could not convert from actual type to desired type" };
  }
};
#endif // defined(YASL_BINDING_COMPILE_TIME_CHECK)

template<typename T>
struct value_cast_helper<T, T>
{
  static T impl(const script::Value & val)
  {
    return get<typename decay<T>::type>(val);
  }
};

template<typename T>
struct value_cast_helper<T, T&>
{
  static T impl(const script::Value & val)
  {
    return get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<T*, T&>
{
  static T* impl(const script::Value & val)
  {
    return std::addressof(get<T>(val));
  }
};

template<typename T>
struct value_cast_helper<const T*, T&>
{
  static const T* impl(const script::Value & val)
  {
    return std::addressof(get<T>(val));
  }
};


template<typename T>
struct value_cast_helper<const T, T>
{
  static const T impl(const script::Value & val)
  {
    return get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<T&&, T&>
{
  static T&& impl(const script::Value & val)
  {
    return std::move(get<T>(val));
  }
};

template<typename T>
struct value_cast_helper<const T&, T&>
{
  static const T& impl(const script::Value & val)
  {
    return get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<T&, T*>
{
  static T& impl(const script::Value & val)
  {
    return *get<T>(val);
  }
};

template<typename T>
struct value_cast_helper<const T*, T*>
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

} // namespace binding

#endif // YASL_BINDING_VALUES_H
