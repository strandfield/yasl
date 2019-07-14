// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILEDEVICE_H
#define YASL_CORE_FILEDEVICE_H

#include "yasl/common/qobject-values.h"
#include "yasl/common/types.h"

#include <QFileDevice>
#include "yasl/core/iodevice.h"

namespace script {
template<> struct make_type_helper<QFileDevice> { inline static script::Type get() { return script::Type::QFileDevice; } };
template<> struct details::tag_resolver<QFileDevice> { typedef qobject_tag tag_type; };
template<> struct make_type_helper<QFileDevice::FileError> { inline static script::Type get() { return script::Type::QFileDeviceFileError; } };
template<> struct make_type_helper<QFileDevice::FileHandleFlag> { inline static script::Type get() { return script::Type::QFileDeviceFileHandleFlag; } };
template<> struct make_type_helper<QFileDevice::FileHandleFlags> { inline static script::Type get() { return script::Type::QFileDeviceFileHandleFlags; } };
template<> struct make_type_helper<QFileDevice::MemoryMapFlags> { inline static script::Type get() { return script::Type::QFileDeviceMemoryMapFlags; } };
template<> struct make_type_helper<QFileDevice::Permission> { inline static script::Type get() { return script::Type::QFileDevicePermission; } };
template<> struct make_type_helper<QFileDevice::Permissions> { inline static script::Type get() { return script::Type::QFileDevicePermissions; } };
} // namespace script

#endif // YASL_CORE_FILEDEVICE_H
