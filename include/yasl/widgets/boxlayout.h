// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_BOXLAYOUT_H
#define YASL_WIDGETS_BOXLAYOUT_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QBoxLayout>

namespace binding {
template<> struct make_type_t<QBoxLayout> { inline static script::Type get() { return script::Type::QBoxLayout; } };
template<> struct tag_resolver<QBoxLayout> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QBoxLayout::Direction> { inline static script::Type get() { return script::Type::QBoxLayoutDirection; } };
template<> struct make_type_t<QHBoxLayout> { inline static script::Type get() { return script::Type::QHBoxLayout; } };
template<> struct tag_resolver<QHBoxLayout> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QVBoxLayout> { inline static script::Type get() { return script::Type::QVBoxLayout; } };
template<> struct tag_resolver<QVBoxLayout> { typedef qobject_tag tag_type; };
} // namespace binding

#endif // YASL_WIDGETS_BOXLAYOUT_H
