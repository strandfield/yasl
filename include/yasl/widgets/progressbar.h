// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_WIDGETS_PROGRESSBAR_H
#define YASL_WIDGETS_PROGRESSBAR_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QProgressBar>

namespace script {
template<> struct make_type_helper<QProgressBar> { inline static script::Type get() { return script::Type::QProgressBar; } };
template<> struct details::tag_resolver<QProgressBar> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QProgressBar::Direction> { inline static script::Type get() { return script::Type::QProgressBarDirection; } };
} // namespace script

#endif // YASL_WIDGETS_PROGRESSBAR_H
