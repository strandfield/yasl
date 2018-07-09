// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_BINDING_MACROS_H
#define YASL_BINDING_MACROS_H

#include "yasl/binding/utils.h"

#define _YASL_LAMBDA_FUNCTION_WRAPPER_0(func) [](script::FunctionCall *c) -> script::Value { \
    return binding::make_value(func(), c->engine()); \
}

#define _YASL_LAMBDA_FUNCTION_WRAPPER_1(func, A1) [](script::FunctionCall *c) -> script::Value { \
    return binding::make_value(func(binding::value_cast<A1>(c->arg(0))), c->engine()); \
}

#define _YASL_LAMBDA_FUNCTION_WRAPPER_2(func, A1, A2) [](script::FunctionCall *c) -> script::Value { \
    return binding::make_value(func(binding::value_cast<A1>(c->arg(0)), binding::value_cast<A2>(c->arg(1))), c->engine()); \
}

#define _YASL_LAMBDA_FUNCTION_WRAPPER_3(func, A1, A2, A3) [](script::FunctionCall *c) -> script::Value { \
    return binding::make_value(func(binding::value_cast<A1>(c->arg(0)), binding::value_cast<A2>(c->arg(1)), binding::value_cast<A3>(c->arg(2))), c->engine()); \
}

#define _YASL_LAMBDA_FUNCTION_WRAPPER_4(func, A1, A2, A3, A4) [](script::FunctionCall *c) -> script::Value { \
    return binding::make_value(func(binding::value_cast<A1>(c->arg(0)), binding::value_cast<A2>(c->arg(1)), binding::value_cast<A3>(c->arg(2)), binding::value_cast<A4>(c->arg(3))), c->engine()); \
}


#define YASL_FUNCTION_0(ns_, name, ReturnType, func) ns_.Function(name, _YASL_LAMBDA_FUNCTION_WRAPPER_0(func)) \
    .returns(binding::make_type<ReturnType>())

#define YASL_FUNCTION_1(ns_, name, ReturnType, func, A1) ns_.Function(name, _YASL_LAMBDA_FUNCTION_WRAPPER_1(func, A1)) \
    .params(binding::make_type<A1>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_FUNCTION_2(ns_, name, ReturnType, func, A1, A2) ns_.Function(name, _YASL_LAMBDA_FUNCTION_WRAPPER_2(func, A1, A2)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_FUNCTION_3(ns_, name, ReturnType, func, A1, A2, A3) ns_.Function(name, _YASL_LAMBDA_FUNCTION_WRAPPER_3(func, A1, A2, A3)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_FUNCTION_4(ns_, name, ReturnType, ClassType, func, A1, A2, A3, A4) ns_.Function(name, _YASL_LAMBDA_FUNCTION_WRAPPER_4(func, A1, A2, A3, A4)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>(),  binding::make_type<A4>()) \
    .returns(binding::make_type<ReturnType>())



#define _YASL_LAMBDA_VOID_FUN_WRAPPER_0(func) [](script::FunctionCall *c) -> script::Value { \
    func(); return script::Value::Void; \
}

#define _YASL_LAMBDA_VOID_FUN_WRAPPER_1(func, A1) [](script::FunctionCall *c) -> script::Value { \
    func(binding::value_cast<A1>(c->arg(0))); return script::Value::Void; \
}

#define _YASL_LAMBDA_VOID_FUN_WRAPPER_2(func, A1, A2) [](script::FunctionCall *c) -> script::Value { \
    func(binding::value_cast<A1>(c->arg(0)), binding::value_cast<A2>(c->arg(1))); return script::Value::Void; \
}

#define _YASL_LAMBDA_VOID_FUN_WRAPPER_3(func, A1, A2, A3) [](script::FunctionCall *c) -> script::Value { \
    func(binding::value_cast<A1>(c->arg(0)), binding::value_cast<A2>(c->arg(1)), binding::value_cast<A3>(c->arg(2))); return script::Value::Void; \
}

#define _YASL_LAMBDA_VOID_FUN_WRAPPER_4(func, A1, A2, A3, A4) [](script::FunctionCall *c) -> script::Value { \
    func(binding::value_cast<A1>(c->arg(0)), binding::value_cast<A2>(c->arg(1)), binding::value_cast<A3>(c->arg(2)), binding::value_cast<A4>(c->arg(3))); return script::Value::Void; \
}


#define YASL_VOID_FUN_0(ns_, name, ReturnType, func) ns_.Function(name, _YASL_LAMBDA_VOID_FUN_WRAPPER_0(func))

#define YASL_VOID_FUN_1(ns_, name, ReturnType, func, A1) ns_.Function(name, _YASL_LAMBDA_VOID_FUN_WRAPPER_1(func, A1)) \
    .params(binding::make_type<A1>())

#define YASL_VOID_FUN_2(ns_, name, ReturnType, func, A1, A2) ns_.Function(name, _YASL_LAMBDA_VOID_FUN_WRAPPER_2(func, A1, A2)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>())

#define YASL_VOID_FUN_3(ns_, name, ReturnType, func, A1, A2, A3) ns_.Function(name, _YASL_LAMBDA_VOID_FUN_WRAPPER_3(func, A1, A2, A3)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>())

#define YASL_VOID_FUN_4(ns_, name, ReturnType, ClassType, func, A1, A2, A3, A4) ns_.Function(name, _YASL_LAMBDA_VOID_FUN_WRAPPER_4(func, A1, A2, A3, A4)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>(),  binding::make_type<A4>())



#define _YASL_LAMBDA_METHOD_WRAPPER_0(ClassType, func) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    return binding::make_value(ref.func(), c->engine()); \
}

#define _YASL_LAMBDA_METHOD_WRAPPER_1(ClassType, func, A1) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    return binding::make_value(ref.func(binding::value_cast<A1>(c->arg(1))), c->engine()); \
}

#define _YASL_LAMBDA_METHOD_WRAPPER_2(ClassType, func, A1, A2) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    return binding::make_value(ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2))), c->engine()); \
}

#define _YASL_LAMBDA_METHOD_WRAPPER_3(ClassType, func, A1, A2, A3) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    return binding::make_value(ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2)), binding::value_cast<A3>(c->arg(3))), c->engine()); \
}

#define _YASL_LAMBDA_METHOD_WRAPPER_4(ClassType, func, A1, A2, A3, A4) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    return binding::make_value(ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2)), binding::value_cast<A3>(c->arg(3)), binding::value_cast<A4>(c->arg(4))), c->engine()); \
}

#define YASL_METHOD_0(class_, name, ReturnType, ClassType, func) class_.Method(name, _YASL_LAMBDA_METHOD_WRAPPER_0(ClassType, func)) \
    .returns(binding::make_type<ReturnType>())

#define YASL_METHOD_1(class_, name, ReturnType, ClassType, func, A1) class_.Method(name, _YASL_LAMBDA_METHOD_WRAPPER_1(ClassType, func, A1)) \
    .params(binding::make_type<A1>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_METHOD_2(class_, name, ReturnType, ClassType, func, A1, A2) class_.Method(name, _YASL_LAMBDA_METHOD_WRAPPER_2(ClassType, func, A1, A2)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_METHOD_3(class_, name, ReturnType, ClassType, func, A1, A2, A3) class_.Method(name, _YASL_LAMBDA_METHOD_WRAPPER_3(ClassType, func, A1, A2, A3)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_METHOD_4(class_, name, ReturnType, ClassType, func, A1, A2, A3, A4) class_.Method(name, _YASL_LAMBDA_METHOD_WRAPPER_4(ClassType, func, A1, A2, A3, A4)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>(),  binding::make_type<A4>()) \
    .returns(binding::make_type<ReturnType>())



#define _YASL_LAMBDA_VOID_METHOD_WRAPPER_0(ClassType, func) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(); return script::Value::Void; \
}

#define _YASL_LAMBDA_VOID_METHOD_WRAPPER_1(ClassType, func, A1) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(binding::value_cast<A1>(c->arg(1))); return script::Value::Void; \
}

#define _YASL_LAMBDA_VOID_METHOD_WRAPPER_2(ClassType, func, A1, A2) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2))); return script::Value::Void; \
}

#define _YASL_LAMBDA_VOID_METHOD_WRAPPER_3(ClassType, func, A1, A2, A3) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2)), binding::value_cast<A3>(c->arg(3))); return script::Value::Void; \
}

#define _YASL_LAMBDA_VOID_METHOD_WRAPPER_4(ClassType, func, A1, A2, A3, A4) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2)), binding::value_cast<A3>(c->arg(3)), binding::value_cast<A4>(c->arg(4))); return script::Value::Void; \
}

#define YASL_VOID_METHOD_0(class_, name, ReturnType, ClassType, func) class_.Method(name, _YASL_LAMBDA_VOID_METHOD_WRAPPER_0(ClassType, func)) \
    .returns(binding::make_type<ReturnType>())

#define YASL_VOID_METHOD_1(class_, name, ReturnType, ClassType, func, A1) class_.Method(name, _YASL_LAMBDA_VOID_METHOD_WRAPPER_1(ClassType, func, A1)) \
    .params(binding::make_type<A1>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_VOID_METHOD_2(class_, name, ReturnType, ClassType, func, A1, A2) class_.Method(name, _YASL_LAMBDA_VOID_METHOD_WRAPPER_2(ClassType, func, A1, A2)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_VOID_METHOD_3(class_, name, ReturnType, ClassType, func, A1, A2, A3) class_.Method(name, _YASL_LAMBDA_VOID_METHOD_WRAPPER_3(ClassType, func, A1, A2, A3)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>()) \
    .returns(binding::make_type<ReturnType>())

#define YASL_VOID_METHOD_4(class_, name, ReturnType, ClassType, func, A1, A2, A3, A4) class_.Method(name, _YASL_LAMBDA_VOID_METHOD_WRAPPER_4(ClassType, func, A1, A2, A3, A4)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>(),  binding::make_type<A4>()) \
    .returns(binding::make_type<ReturnType>())



#define _YASL_LAMBDA_WRAPPER_CHAINABLE_0(ClassType, func) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(); \
    return c->arg(0); \
}

#define _YASL_LAMBDA_WRAPPER_CHAINABLE_1(ClassType, func, A1) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(binding::value_cast<A1>(c->arg(1))); \
    return c->arg(0); \
}

#define _YASL_LAMBDA_WRAPPER_CHAINABLE_2(ClassType, func, A1, A2) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2))); \
    return c->arg(0); \
}

#define _YASL_LAMBDA_WRAPPER_CHAINABLE_3(ClassType, func, A1, A2, A3) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2)), binding::value_cast<A3>(c->arg(3))); \
    return c->arg(0); \
}

#define _YASL_LAMBDA_WRAPPER_CHAINABLE_4(ClassType, func, A1, A2, A3, A4) [](script::FunctionCall *c) -> script::Value { \
    ClassType & ref = *binding::value_cast<ClassType*>(c->arg(0)); \
    ref.func(binding::value_cast<A1>(c->arg(1)), binding::value_cast<A2>(c->arg(2)), binding::value_cast<A3>(c->arg(3)), binding::value_cast<A4>(c->arg(4))); \
    return c->arg(0); \
}


#define YASL_CHAINABLE_METHOD_0(class_, name, ClassType, func) class_.Method(name, _YASL_LAMBDA_WRAPPER_CHAINABLE_0(ClassType, func)) \
    .returns(Type::ref(binding::make_type<ClassType>()))

#define YASL_CHAINABLE_METHOD_1(class_, name, ClassType, func, A1) class_.Method(name, _YASL_LAMBDA_WRAPPER_CHAINABLE_1(ClassType, func, A1)) \
    .params(binding::make_type<A1>()) \
    .returns(Type::ref(binding::make_type<ClassType>()))

#define YASL_CHAINABLE_METHOD_2(class_, name, ClassType, func, A1, A2) class_.Method(name, _YASL_LAMBDA_WRAPPER_CHAINABLE_2(ClassType, func, A1, A2)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>()) \
    .returns(Type::ref(binding::make_type<ClassType>()))

#define YASL_CHAINABLE_METHOD_3(class_, name, ClassType, func, A1, A2, A3) class_.Method(name, _YASL_LAMBDA_WRAPPER_CHAINABLE_3(ClassType, func, A1, A2, A3)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>()) \
    .returns(Type::ref(binding::make_type<ClassType>()))

#define YASL_CHAINABLE_METHOD_4(class_, name, ClassType, func, A1, A2, A3, A4) class_.Method(name, _YASL_LAMBDA_WRAPPER_CHAINABLE_3(ClassType, func, A1, A2, A3, A4)) \
    .params(binding::make_type<A1>(), binding::make_type<A2>(), binding::make_type<A3>(), binding::make_type<A4>()) \
    .returns(Type::ref(binding::make_type<ClassType>()))


#endif // YASL_BINDING_MACROS_H
