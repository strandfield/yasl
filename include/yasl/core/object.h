// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_OBJECT_H
#define YASL_CORE_OBJECT_H

#include "yasl/common/proxy.h"
#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QObject>

namespace script {
template<> struct make_type_t<Proxy<QObject*>> { inline static script::Type get() { return script::Type::ProxyQObject; } };
template<> struct make_type_t<QList<QObject*>> { inline static script::Type get() { return script::Type::QListQObject; } };
template<> struct make_type_t<QObject> { inline static script::Type get() { return script::Type::QObject; } };
template<> struct tag_resolver<QObject> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QObject*> { inline static script::Type get() { return script::Type::QObjectStar; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
template<> struct make_type_t<QSignalBlocker> { inline static script::Type get() { return script::Type::QSignalBlocker; } };
#endif
} // namespace script

#endif // YASL_CORE_OBJECT_H
