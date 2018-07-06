// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_FILEDEVICE_H
#define YASL_CORE_FILEDEVICE_H

#include "yasl/core/iodevice.h"

#include <QFileDevice>

void register_filedevice_class(script::Namespace n);
script::Type get_filedevice_type();
script::Type get_filedevice_fileerror_type();
script::Type get_filedevice_filehandleflag_type();
script::Type get_filedevice_filehandleflags_type();
script::Type get_filedevice_filetime_type();
script::Type get_filedevice_memorymapflags_type();
script::Type get_filedevice_permission_type();
script::Type get_filedevice_permissions_type();

namespace binding
{

template<> struct make_type_t<QFileDevice> { inline static script::Type get() { return get_filedevice_type(); } };
template<> struct make_type_t<QFileDevice::FileError> { inline static script::Type get() { return get_filedevice_fileerror_type(); } };
template<> struct make_type_t<QFileDevice::FileHandleFlag> { inline static script::Type get() { return get_filedevice_filehandleflag_type(); } };
template<> struct make_type_t<QFileDevice::FileHandleFlags> { inline static script::Type get() { return get_filedevice_filehandleflags_type(); } };
template<> struct make_type_t<QFileDevice::FileTime> { inline static script::Type get() { return get_filedevice_filetime_type(); } };
template<> struct make_type_t<QFileDevice::MemoryMapFlags> { inline static script::Type get() { return get_filedevice_memorymapflags_type(); } };
template<> struct make_type_t<QFileDevice::Permission> { inline static script::Type get() { return get_filedevice_permission_type(); } };
template<> struct make_type_t<QFileDevice::Permissions> { inline static script::Type get() { return get_filedevice_permissions_type(); } };


template<> inline QFileDevice* value_cast<QFileDevice*>(const script::Value & val)
{
  return qobject_cast<QFileDevice*>(value_cast<QObject*>(val));
}

template<> inline script::Value make_value(QFileDevice *f, script::Engine *e) = delete;

} // namespace binding

#endif // YASL_CORE_FILEDEVICE_H
