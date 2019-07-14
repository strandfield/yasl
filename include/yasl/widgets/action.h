// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_ACTION_H
#define YASL_WIDGETS_ACTION_H

#include "yasl/common/proxy.h"
#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QAction>

namespace script {
template<> struct make_type_helper<Proxy<QAction*>> { inline static script::Type get() { return script::Type::ProxyQAction; } };
template<> struct make_type_helper<QAction> { inline static script::Type get() { return script::Type::QAction; } };
template<> struct details::tag_resolver<QAction> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QAction*> { inline static script::Type get() { return script::Type::QActionStar; } };
template<> struct make_type_helper<QAction::ActionEvent> { inline static script::Type get() { return script::Type::QActionActionEvent; } };
template<> struct make_type_helper<QAction::MenuRole> { inline static script::Type get() { return script::Type::QActionMenuRole; } };
template<> struct make_type_helper<QAction::Priority> { inline static script::Type get() { return script::Type::QActionPriority; } };
template<> struct make_type_helper<QList<QAction*>> { inline static script::Type get() { return script::Type::QListQAction; } };
template<> struct make_type_helper<QList<QAction*>::const_iterator> { inline static script::Type get() { return script::Type::QListQActionConstIterator; } };
template<> struct make_type_helper<QList<QAction*>::iterator> { inline static script::Type get() { return script::Type::QListQActionIterator; } };
} // namespace script

#endif // YASL_WIDGETS_ACTION_H
