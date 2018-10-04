// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_PROGRESSBAR_H
#define YASL_WIDGETS_PROGRESSBAR_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QProgressBar>

namespace binding {
template<> struct make_type_t<QProgressBar> { inline static script::Type get() { return script::Type::QProgressBar; } };
template<> struct tag_resolver<QProgressBar> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QProgressBar::Direction> { inline static script::Type get() { return script::Type::QProgressBarDirection; } };
} // namespace binding

#endif // YASL_WIDGETS_PROGRESSBAR_H
