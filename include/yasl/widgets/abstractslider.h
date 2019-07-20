// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_ABSTRACTSLIDER_H
#define YASL_WIDGETS_ABSTRACTSLIDER_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QAbstractSlider>

namespace script {
template<> struct make_type_helper<QAbstractSlider> { inline static script::Type get() { return script::Type::QAbstractSlider; } };
namespace details { template<> struct tag_resolver<QAbstractSlider> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QAbstractSlider::SliderAction> { inline static script::Type get() { return script::Type::QAbstractSliderSliderAction; } };
} // namespace script

#endif // YASL_WIDGETS_ABSTRACTSLIDER_H
