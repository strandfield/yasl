// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_BOXLAYOUT_H
#define YASL_WIDGETS_BOXLAYOUT_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QBoxLayout>

namespace script {
template<> struct make_type_helper<QBoxLayout> { inline static script::Type get() { return script::Type::QBoxLayout; } };
template<> struct details::tag_resolver<QBoxLayout> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QBoxLayout::Direction> { inline static script::Type get() { return script::Type::QBoxLayoutDirection; } };
template<> struct make_type_helper<QHBoxLayout> { inline static script::Type get() { return script::Type::QHBoxLayout; } };
template<> struct details::tag_resolver<QHBoxLayout> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QVBoxLayout> { inline static script::Type get() { return script::Type::QVBoxLayout; } };
template<> struct details::tag_resolver<QVBoxLayout> { typedef qobject_tag tag_type; };
} // namespace script

#endif // YASL_WIDGETS_BOXLAYOUT_H
