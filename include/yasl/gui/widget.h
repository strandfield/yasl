// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_WIDGET_H
#define YASL_GUI_WIDGET_H

#include "yasl/core/list.h"
#include "yasl/core/object.h"
#include "yasl/utils/ptr.h"

#include <QWidget>

script::Value make_widget(QWidget *widget, script::Engine *e);

namespace binding
{

template<> struct tag_resolver<QWidget> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QWidget*> { inline static script::Type get() { return script::Type::QWidgetStar; } };
template<> struct make_type_t<QList<QWidget*>> { inline static script::Type get() { return script::Type::QListQWidget; } };
template<> struct make_type_t<Ptr<QWidget*>> { inline static script::Type get() { return script::Type::PtrQWidget; } };

//template<> struct storage_type<QWidget> { typedef QWidget* type; };
//template<> inline QWidget* get<QWidget>(const script::Value & val) { 
//  return qobject_cast<QWidget*>(val.toQObject());
//}
//
//template<> inline script::Value make_value(QWidget *widget, script::Engine *e)
//{
//  return make_widget(widget, e);
//}

static_assert(std::is_same<binding::storage_type<QWidget>::type, QWidget*>::value, "QWidget must be stored as QWidget*");

} // namespace binding

#endif // YASL_GUI_WIDGET_H
