// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_GUI_FONTMETRICS_H
#define YASL_GUI_FONTMETRICS_H

#include "yasl/common/types.h"

#include <QFontMetrics>

namespace script {
template<> struct make_type_t<QFontMetrics> { inline static script::Type get() { return script::Type::QFontMetrics; } };
template<> struct make_type_t<QFontMetricsF> { inline static script::Type get() { return script::Type::QFontMetricsF; } };
} // namespace script

#endif // YASL_GUI_FONTMETRICS_H
