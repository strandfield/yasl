// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_SIZE_H
#define YASL_CORE_SIZE_H

#include "yasl/common/types.h"

#include <QSize>

namespace script {
template<> struct make_type_helper<QSize> { inline static script::Type get() { return script::Type::QSize; } };
template<> struct make_type_helper<QSizeF> { inline static script::Type get() { return script::Type::QSizeF; } };
} // namespace script

#endif // YASL_CORE_SIZE_H
