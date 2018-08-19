// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_OBJECT_H
#define YASL_CORE_OBJECT_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"
#include "yasl/utils/ptr.h"

#include <QObject>

namespace binding {
template<> struct make_type_t<Ptr<QObject*>> { inline static script::Type get() { return script::Type::PtrQObject; } };
template<> struct make_type_t<QList<QObject*>> { inline static script::Type get() { return script::Type::QListQObject; } };
template<> struct make_type_t<QObject> { inline static script::Type get() { return script::Type::QObject; } };
template<> struct tag_resolver<QObject> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QObject*> { inline static script::Type get() { return script::Type::QObjectStar; } };
template<> struct make_type_t<QSignalBlocker> { inline static script::Type get() { return script::Type::QSignalBlocker; } };
} // namespace binding

#endif // YASL_CORE_OBJECT_H
