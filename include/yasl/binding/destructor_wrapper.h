// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_DESTRUCTOR_WRAPPER_H
#define YASL_BINDING_DESTRUCTOR_WRAPPER_H

#include <script/interpreter/executioncontext.h>

namespace binding
{

/****************************************************************
Destructor
****************************************************************/

template<typename T>
struct destructor_wrapper_small_object_t {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *ptr = reinterpret_cast<T*>(&self.impl()->data.memory);
    ptr->~T();
    return script::Value::Void;
  }
};


template<typename T>
struct destructor_wrapper_large_object_t {
  static script::Value wrap(script::FunctionCall *c) {
    script::Value self = c->thisObject();
    T *ptr = static_cast<T*>(self.impl()->data.ptr);
    delete ptr;
    self.impl()->data.ptr = nullptr;
    return script::Value::Void;
  }
};

} // namespace binding

#endif // YASL_BINDING_DESTRUCTOR_WRAPPER_H
