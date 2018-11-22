// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_STRING_H
#define YASL_CORE_STRING_H

#include "yasl/binding2/types.h"
#include "yasl/binding2/proxy.h"

#include <QStringList>

namespace script 
{
namespace bind 
{
template<> struct make_type_t<Proxy<QString>> { inline static script::Type get() { return script::Type::ProxyQString; } };
template<> struct make_type_t<QList<QString>> { inline static script::Type get() { return script::Type::QListQString; } };
template<> struct make_type_t<QStringList> { inline static script::Type get() { return script::Type::QStringList; } };
}
}

#endif // YASL_CORE_STRING_H
