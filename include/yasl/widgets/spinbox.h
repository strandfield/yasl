// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_SPINBOX_H
#define YASL_WIDGETS_SPINBOX_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QSpinBox>

namespace script { namespace bind {
template<> struct make_type_t<QDoubleSpinBox> { inline static script::Type get() { return script::Type::QDoubleSpinBox; } };
template<> struct tag_resolver<QDoubleSpinBox> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QSpinBox> { inline static script::Type get() { return script::Type::QSpinBox; } };
template<> struct tag_resolver<QSpinBox> { typedef qobject_tag tag_type; };
} /* namespace bind */ } /* namespace script */

#endif // YASL_WIDGETS_SPINBOX_H
