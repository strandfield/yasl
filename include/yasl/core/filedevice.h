// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILEDEVICE_H
#define YASL_CORE_FILEDEVICE_H

#include "yasl/binding2/qobject-binding.h"
#include "yasl/binding2/types.h"

#include <QFileDevice>
#include "yasl/core/iodevice.h"

namespace script { namespace bind {
template<> struct make_type_t<QFileDevice> { inline static script::Type get() { return script::Type::QFileDevice; } };
template<> struct tag_resolver<QFileDevice> { typedef qobject_tag tag_type; };
template<> struct make_type_t<QFileDevice::FileError> { inline static script::Type get() { return script::Type::QFileDeviceFileError; } };
template<> struct make_type_t<QFileDevice::FileHandleFlag> { inline static script::Type get() { return script::Type::QFileDeviceFileHandleFlag; } };
template<> struct make_type_t<QFileDevice::FileHandleFlags> { inline static script::Type get() { return script::Type::QFileDeviceFileHandleFlags; } };
template<> struct make_type_t<QFileDevice::FileTime> { inline static script::Type get() { return script::Type::QFileDeviceFileTime; } };
template<> struct make_type_t<QFileDevice::MemoryMapFlags> { inline static script::Type get() { return script::Type::QFileDeviceMemoryMapFlags; } };
template<> struct make_type_t<QFileDevice::Permission> { inline static script::Type get() { return script::Type::QFileDevicePermission; } };
template<> struct make_type_t<QFileDevice::Permissions> { inline static script::Type get() { return script::Type::QFileDevicePermissions; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_FILEDEVICE_H
