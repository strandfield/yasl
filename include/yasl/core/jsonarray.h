// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_JSONARRAY_H
#define YASL_CORE_JSONARRAY_H

#include "yasl/binding2/types.h"

#include <QJsonArray>

namespace script { namespace bind {
template<> struct make_type_t<QJsonArray> { inline static script::Type get() { return script::Type::QJsonArray; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_JSONARRAY_H
