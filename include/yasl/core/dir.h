// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_DIR_H
#define YASL_CORE_DIR_H

#include "yasl/binding/types.h"

#include <QDir>

namespace script { namespace bind {
template<> struct make_type_t<QDir> { inline static script::Type get() { return script::Type::QDir; } };
template<> struct make_type_t<QDir::Filter> { inline static script::Type get() { return script::Type::QDirFilter; } };
template<> struct make_type_t<QDir::Filters> { inline static script::Type get() { return script::Type::QDirFilters; } };
template<> struct make_type_t<QDir::SortFlag> { inline static script::Type get() { return script::Type::QDirSortFlag; } };
template<> struct make_type_t<QDir::SortFlags> { inline static script::Type get() { return script::Type::QDirSortFlags; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_DIR_H
