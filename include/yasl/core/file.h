// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILE_H
#define YASL_CORE_FILE_H

#include "yasl/binding/types.h"
#include "yasl/core/qobject-binding.h"

#include <QFile>

namespace binding {
template<> struct make_type_t<QFile> { inline static script::Type get() { return script::Type::QFile; } };
template<> struct tag_resolver<QFile> { typedef qobject_tag tag_type; };
} // namespace binding

#endif // YASL_CORE_FILE_H
