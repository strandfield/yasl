// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILEINFO_H
#define YASL_CORE_FILEINFO_H

#include "yasl/binding/types.h"

#include <QFileInfo>

namespace script { namespace bind {
template<> struct make_type_t<QFileInfo> { inline static script::Type get() { return script::Type::QFileInfo; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_FILEINFO_H
