// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_MENU_H
#define YASL_WIDGETS_MENU_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QMenu>

namespace script {
template<> struct make_type_t<QMenu> { inline static script::Type get() { return script::Type::QMenu; } };
template<> struct tag_resolver<QMenu> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QMenu*> { inline static script::Type get() { return script::Type::QMenuStar; } };
} // namespace script

#endif // YASL_WIDGETS_MENU_H
