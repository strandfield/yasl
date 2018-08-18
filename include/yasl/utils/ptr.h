// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_UTILS_PTR_H
#define YASL_UTILS_PTR_H

#include "yasl/binding/values.h"

#include <script/classtemplatespecializationbuilder.h>

namespace script
{
class Class;
class Engine;
class Namespace;
class Type;
class Value;
} // namespace script

void register_ptr_template(script::Namespace ns);
void* get_ptr(const script::Value & val);
script::Value make_ptr(script::Engine *e, const script::Type & ptr_type, void *value);

template<typename T>
struct Ptr
{
  T *value;

  Ptr(T *val) : value(val) { }


  T & get() { return *value; }
  operator T &() { return get(); }
  
  void operator=(const T & val) { *value = val; }
};


namespace callbacks
{

namespace ptr
{

script::Value copy_ctor(script::FunctionCall *c);
script::Value dtor(script::FunctionCall *c);

template<typename T>
script::Value get(script::FunctionCall *c)
{
  Ptr<T> ptr = binding::value_cast<Ptr<T>>(c->thisObject());
  return binding::make_value(ptr.get(), c->engine());
}

template<typename T>
script::Value assign(script::FunctionCall *c)
{
  Ptr<T> ptr = binding::value_cast<Ptr<T>>(c->thisObject());
  ptr.get() = binding::value_cast<const T &>(c->arg(1));
  return script::Value::Void;
}

} // namespace ptr

} // namespace callbacks


template<typename T>
void register_ptr_specialization(script::ClassTemplate ptr_template, script::Type::BuiltInType type_id)
{
  using namespace script;

  const script::Type element_type = binding::make_type<T>();

  std::vector<TemplateArgument> targs{
    TemplateArgument{ element_type },
  };

  Class ptr_type = ptr_template.Specialization(std::move(targs))
    .setId(type_id)
    .setFinal()
    .get();

  // Ptr(const Ptr<T> & other);
  ptr_type.Constructor(callbacks::ptr::copy_ctor).params(Type::cref(ptr_type.id())).create();
  // ~Ptr();
  ptr_type.Destructor(callbacks::ptr::dtor).create();

  // void operator=(const T & value);
  ptr_type.Operation(AssignmentOperator, callbacks::ptr::assign<T>)
    .params(Type::cref(element_type)).create();

  // operator T() const;
  ptr_type.Conversion(element_type, callbacks::ptr::get<T>).setConst().create();
}


namespace binding
{
template<> struct make_type_t<Ptr<bool>> { inline static script::Type get() { return script::Type::Ptrbool; } };
template<> struct make_type_t<Ptr<char>> { inline static script::Type get() { return script::Type::Ptrchar; } };
template<> struct make_type_t<Ptr<int>> { inline static script::Type get() { return script::Type::Ptrint; } };
template<> struct make_type_t<Ptr<float>> { inline static script::Type get() { return script::Type::Ptrfloat; } };
template<> struct make_type_t<Ptr<double>> { inline static script::Type get() { return script::Type::Ptrdouble; } };

template<> inline Ptr<bool> value_cast<Ptr<bool>>(const script::Value & v) { return static_cast<bool*>(get_ptr(v)); }
template<> inline Ptr<char> value_cast<Ptr<char>>(const script::Value & v) { return static_cast<char*>(get_ptr(v)); }
template<> inline Ptr<int> value_cast<Ptr<int>>(const script::Value & v) { return static_cast<int*>(get_ptr(v)); }
template<> inline Ptr<float> value_cast<Ptr<float>>(const script::Value & v) { return static_cast<float*>(get_ptr(v)); }
template<> inline Ptr<double> value_cast<Ptr<double>>(const script::Value & v) { return static_cast<double*>(get_ptr(v)); }

} // namespace binding

#endif // YASL_UTILS_PTR_H
