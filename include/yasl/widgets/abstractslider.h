// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_ABSTRACTSLIDER_H
#define YASL_WIDGETS_ABSTRACTSLIDER_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QAbstractSlider>

namespace binding {
template<> struct make_type_t<QAbstractSlider> { inline static script::Type get() { return script::Type::QAbstractSlider; } };
template<> struct tag_resolver<QAbstractSlider> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QAbstractSlider::SliderAction> { inline static script::Type get() { return script::Type::QAbstractSliderSliderAction; } };
} // namespace binding

#endif // YASL_WIDGETS_ABSTRACTSLIDER_H
