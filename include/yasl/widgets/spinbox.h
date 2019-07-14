// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_SPINBOX_H
#define YASL_WIDGETS_SPINBOX_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QSpinBox>

namespace script {
template<> struct make_type_helper<QDoubleSpinBox> { inline static script::Type get() { return script::Type::QDoubleSpinBox; } };
template<> struct details::tag_resolver<QDoubleSpinBox> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QSpinBox> { inline static script::Type get() { return script::Type::QSpinBox; } };
template<> struct details::tag_resolver<QSpinBox> { typedef qobject_tag tag_type; };
} // namespace script

#endif // YASL_WIDGETS_SPINBOX_H
