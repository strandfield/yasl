// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_WINDOW_H
#define YASL_GUI_WINDOW_H

#include "yasl/binding/types.h"
#include "yasl/binding/values.h"
#include "yasl/utils/ref.h"

#include <QWindow>

namespace binding {
template<> struct make_type_t<QWindow> { inline static script::Type get() { return script::Type::QWindow; } };
template<> struct make_type_t<QWindow*> { inline static script::Type get() { return script::Type::QWindowStar; } };
template<> struct make_type_t<QWindow::AncestorMode> { inline static script::Type get() { return script::Type::QWindowAncestorMode; } };
template<> struct make_type_t<QWindow::Visibility> { inline static script::Type get() { return script::Type::QWindowVisibility; } };

template<> inline script::Value make_value(QWindow *obj, script::Engine *e)
{
  return make_ref(e, script::Type::QWindowStar, obj);
}

template<> struct storage_type<QWindow> { typedef QWindow* type; };
template<> inline QWindow* get<QWindow>(const script::Value & val) { return qobject_cast<QWindow*>(val.toQObject()); }
} // namespace binding

#endif // YASL_GUI_WINDOW_H
