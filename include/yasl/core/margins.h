// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_MARGINS_H
#define YASL_CORE_MARGINS_H

#include "yasl/common/types.h"

#include <QMargins>

namespace script {
template<> struct make_type_helper<QMargins> { inline static script::Type get() { return script::Type::QMargins; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
template<> struct make_type_helper<QMarginsF> { inline static script::Type get() { return script::Type::QMarginsF; } };
#endif
} // namespace script

#endif // YASL_CORE_MARGINS_H
