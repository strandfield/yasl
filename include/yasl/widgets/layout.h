// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_LAYOUT_H
#define YASL_WIDGETS_LAYOUT_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QLayout>

namespace script {
template<> struct make_type_helper<QLayout> { inline static script::Type get() { return script::Type::QLayout; } };
namespace details { template<> struct tag_resolver<QLayout> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QLayout*> { inline static script::Type get() { return script::Type::QLayoutStar; } };
template<> struct make_type_helper<QLayout::SizeConstraint> { inline static script::Type get() { return script::Type::QLayoutSizeConstraint; } };
} // namespace script

#endif // YASL_WIDGETS_LAYOUT_H
