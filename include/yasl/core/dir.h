// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_DIR_H
#define YASL_CORE_DIR_H

#include "yasl/common/types.h"

#include <QDir>

namespace script {
template<> struct make_type_helper<QDir> { inline static script::Type get() { return script::Type::QDir; } };
template<> struct make_type_helper<QDir::Filter> { inline static script::Type get() { return script::Type::QDirFilter; } };
template<> struct make_type_helper<QDir::Filters> { inline static script::Type get() { return script::Type::QDirFilters; } };
template<> struct make_type_helper<QDir::SortFlag> { inline static script::Type get() { return script::Type::QDirSortFlag; } };
template<> struct make_type_helper<QDir::SortFlags> { inline static script::Type get() { return script::Type::QDirSortFlags; } };
} // namespace script

#endif // YASL_CORE_DIR_H
