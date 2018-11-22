// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_IODEVICE_H
#define YASL_CORE_IODEVICE_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QIODevice>

namespace script { namespace bind {
template<> struct make_type_t<QIODevice> { inline static script::Type get() { return script::Type::QIODevice; } };
template<> struct tag_resolver<QIODevice> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QIODevice::OpenMode> { inline static script::Type get() { return script::Type::QIODeviceOpenMode; } };
template<> struct make_type_t<QIODevice::OpenModeFlag> { inline static script::Type get() { return script::Type::QIODeviceOpenModeFlag; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_IODEVICE_H
