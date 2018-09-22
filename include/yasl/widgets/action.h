// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_ACTION_H
#define YASL_WIDGETS_ACTION_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"
#include "yasl/utils/ptr.h"

#include <QAction>

namespace binding {
template<> struct make_type_t<Ptr<QAction*>> { inline static script::Type get() { return script::Type::PtrQAction; } };
template<> struct make_type_t<QAction> { inline static script::Type get() { return script::Type::QAction; } };
template<> struct tag_resolver<QAction> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QAction*> { inline static script::Type get() { return script::Type::QActionStar; } };
template<> struct make_type_t<QAction::ActionEvent> { inline static script::Type get() { return script::Type::QActionActionEvent; } };
template<> struct make_type_t<QAction::MenuRole> { inline static script::Type get() { return script::Type::QActionMenuRole; } };
template<> struct make_type_t<QAction::Priority> { inline static script::Type get() { return script::Type::QActionPriority; } };
template<> struct make_type_t<QList<QAction*>> { inline static script::Type get() { return script::Type::QListQAction; } };
} // namespace binding

#endif // YASL_WIDGETS_ACTION_H
