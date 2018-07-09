// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_TYPES_H
#define YASL_BINDING_TYPES_H

#include <script/string.h>
#include <script/types.h>

namespace binding
{

#if defined(YASL_BINDING_COMPILE_TIME_CHECK)
template<typename T>
struct make_type_t
{
  inline static script::Type get() = delete;
};
#else
struct UnknownTypeException {};
template<typename T>
struct make_type_t
{
  inline static script::Type get()
  {
    throw UnknownTypeException{};
  }
};
#endif // defined(YASL_BINDING_COMPILE_TIME_CHECK)


template<typename T>
struct make_type_t<T&>
{
  inline static script::Type get()
  {
    return script::Type::ref(make_type_t<T>::get());
  }
};

template<typename T>
struct make_type_t<const T&>
{
  inline static script::Type get()
  {
    return script::Type::cref(make_type_t<T>::get());
  }
};

template<typename T>
script::Type make_type()
{
  return make_type_t<T>::get();
}

template<typename T>
struct make_return_type_t
{
  inline static script::Type get()
  {
    return make_type_t<T>::get();
  }
};

template<typename T>
struct make_return_type_t<const T>
{
  inline static script::Type get()
  {
    return make_type_t<T>::get().withFlag(script::Type::ConstFlag);
  }
};

template<typename T>
struct make_return_type_t<T&>
{
  inline static script::Type get()
  {
    static_assert(false, "Return type cannot be a non-const ref");
    return make_return_type_t<T>::get();
  }
};

template<typename T>
struct make_return_type_t<const T&>
{
  inline static script::Type get()
  {
    return make_return_type_t<T>::get();
  }
};

template<typename T>
script::Type make_return_type()
{
  return make_return_type_t<T>::get();
}


template<> inline script::Type make_type<void>() { return script::Type::Void; }

template<> struct make_type_t<bool> { inline static script::Type get() { return script::Type::Boolean; } };
template<> struct make_type_t<char> { inline static script::Type get() { return script::Type::Char; } };
template<> struct make_type_t<int> { inline static script::Type get() { return script::Type::Int; } };
template<> struct make_type_t<float> { inline static script::Type get() { return script::Type::Float; } };
template<> struct make_type_t<double> { inline static script::Type get() { return script::Type::Double; } };
template<> struct make_type_t<script::String> { inline static script::Type get() { return script::Type::String; } };

/// TODO 

template<> struct make_type_t<qint64> { inline static script::Type get() { return script::Type::Int; } };
template<> struct make_type_t<qulonglong> { inline static script::Type get() { return script::Type::Int; } };
template<> struct make_type_t<short> { inline static script::Type get() { return script::Type::Int; } };
template<> struct make_type_t<uint> { inline static script::Type get() { return script::Type::Int; } };
template<> struct make_type_t<ushort> { inline static script::Type get() { return script::Type::Int; } };


} // namespace binding


#endif // YASL_BINDING_TYPES_H
