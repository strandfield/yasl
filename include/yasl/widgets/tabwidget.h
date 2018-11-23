// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_TABWIDGET_H
#define YASL_WIDGETS_TABWIDGET_H

#include "yasl/binding/qobject-binding.h"
#include "yasl/binding/types.h"

#include <QTabWidget>

namespace script { namespace bind {
template<> struct make_type_t<QTabWidget> { inline static script::Type get() { return script::Type::QTabWidget; } };
template<> struct tag_resolver<QTabWidget> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QTabWidget::TabPosition> { inline static script::Type get() { return script::Type::QTabWidgetTabPosition; } };
template<> struct make_type_t<QTabWidget::TabShape> { inline static script::Type get() { return script::Type::QTabWidgetTabShape; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_TABWIDGET_H
