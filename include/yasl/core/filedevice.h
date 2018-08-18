// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILEDEVICE_H
#define YASL_CORE_FILEDEVICE_H

#include "yasl/core/iodevice.h"

#include <QFileDevice>

namespace binding
{

template<> struct make_type_t<QFileDevice> { inline static script::Type get() { return script::Type::QFile; } };
template<> struct make_type_t<QFileDevice::FileError> { inline static script::Type get() { return script::Type::QFileDeviceFileError; } };
template<> struct make_type_t<QFileDevice::FileHandleFlag> { inline static script::Type get() { return script::Type::QFileDeviceFileHandleFlag; } };
template<> struct make_type_t<QFileDevice::FileHandleFlags> { inline static script::Type get() { return script::Type::QFileDeviceFileHandleFlags; } };
template<> struct make_type_t<QFileDevice::FileTime> { inline static script::Type get() { return script::Type::QFileDeviceFileTime; } };
template<> struct make_type_t<QFileDevice::MemoryMapFlags> { inline static script::Type get() { return script::Type::QFileDeviceMemoryMapFlags; } };
template<> struct make_type_t<QFileDevice::Permission> { inline static script::Type get() { return script::Type::QFileDevicePermission; } };
template<> struct make_type_t<QFileDevice::Permissions> { inline static script::Type get() { return script::Type::QFileDevicePermissions; } };

//template<> struct storage_type<QFileDevice> { typedef QFileDevice* type; };
//template<> inline QFileDevice* get<QFileDevice>(const script::Value & val) { return qobject_cast<QFileDevice*>(val.toQObject()); }

template<> inline script::Value make_value(QFileDevice *f, script::Engine *e) = delete;

} // namespace binding

#endif // YASL_CORE_FILEDEVICE_H
