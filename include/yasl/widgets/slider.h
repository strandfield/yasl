// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_SLIDER_H
#define YASL_WIDGETS_SLIDER_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QSlider>

namespace script {
template<> struct make_type_helper<QSlider> { inline static script::Type get() { return script::Type::QSlider; } };
namespace details { template<> struct tag_resolver<QSlider> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QSlider::TickPosition> { inline static script::Type get() { return script::Type::QSliderTickPosition; } };
} // namespace script

#endif // YASL_WIDGETS_SLIDER_H
