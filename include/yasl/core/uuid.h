// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_UUID_H
#define YASL_CORE_UUID_H

#include "yasl/binding/types.h"

#include <QUuid>

namespace script { namespace bind {
template<> struct make_type_t<QUuid> { inline static script::Type get() { return script::Type::QUuid; } };
template<> struct make_type_t<QUuid::Variant> { inline static script::Type get() { return script::Type::QUuidVariant; } };
template<> struct make_type_t<QUuid::Version> { inline static script::Type get() { return script::Type::QUuidVersion; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_UUID_H
