// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_IODEVICE_H
#define YASL_CORE_IODEVICE_H

#include "yasl/core/object.h"

#include <QIODevice>

namespace binding
{

template<> struct tag_resolver<QIODevice> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QIODevice> { inline static script::Type get() { return script::Type::QIODevice; } };
template<> struct make_type_t<QIODevice::OpenModeFlag> { inline static script::Type get() { return script::Type::QIODeviceOpenModeFlag; } };
template<> struct make_type_t<QIODevice::OpenMode> { inline static script::Type get() { return script::Type::QIODeviceOpenMode; } };

template<> inline script::Value make_value(QIODevice *dev, script::Engine *e) = delete;

} // namespace binding

#endif // YASL_CORE_IODEVICE_H
