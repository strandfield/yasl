// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_WIDGET_H
#define YASL_WIDGETS_WIDGET_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"
#include "yasl/utils/proxy.h"

#include <QWidget>

namespace binding {
template<> struct make_type_t<Proxy<QWidget*>> { inline static script::Type get() { return script::Type::ProxyQWidget; } };
template<> struct make_type_t<QList<QWidget*>> { inline static script::Type get() { return script::Type::QListQWidget; } };
template<> struct make_type_t<QWidget> { inline static script::Type get() { return script::Type::QWidget; } };
template<> struct tag_resolver<QWidget> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QWidget*> { inline static script::Type get() { return script::Type::QWidgetStar; } };
template<> struct make_type_t<QWidget::RenderFlag> { inline static script::Type get() { return script::Type::QWidgetRenderFlag; } };
} // namespace binding

#endif // YASL_WIDGETS_WIDGET_H
