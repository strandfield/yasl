// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_CHECKBOX_H
#define YASL_WIDGETS_CHECKBOX_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QCheckBox>

namespace binding {
template<> struct make_type_t<QCheckBox> { inline static script::Type get() { return script::Type::QCheckBox; } };
template<> struct tag_resolver<QCheckBox> { typedef qobject_tag tag_type; };
} // namespace binding

#endif // YASL_WIDGETS_CHECKBOX_H
