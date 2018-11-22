// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILE_H
#define YASL_CORE_FILE_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QFile>

namespace script { namespace bind {
template<> struct make_type_t<QFile> { inline static script::Type get() { return script::Type::QFile; } };
template<> struct tag_resolver<QFile> { typedef qobject_tag tag_type; };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_FILE_H
