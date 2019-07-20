// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_IODEVICE_H
#define YASL_CORE_IODEVICE_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QIODevice>

namespace script {
template<> struct make_type_helper<QIODevice> { inline static script::Type get() { return script::Type::QIODevice; } };
namespace details { template<> struct tag_resolver<QIODevice> { typedef qobject_tag tag_type; }; }
template<> struct make_type_helper<QIODevice::OpenMode> { inline static script::Type get() { return script::Type::QIODeviceOpenMode; } };
template<> struct make_type_helper<QIODevice::OpenModeFlag> { inline static script::Type get() { return script::Type::QIODeviceOpenModeFlag; } };
} // namespace script

#endif // YASL_CORE_IODEVICE_H
