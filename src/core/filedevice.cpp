// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/filedevice.h"

#include "yasl/common/enums.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/datetime.h"
#include "yasl/core/filedevice.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_file_device_file_error_enum(script::Class file_device)
{
  using namespace script;

  Enum file_error = file_device.newEnum("FileError").setId(script::Type::QFileDeviceFileError).get();

  file_error.addValue("NoError", QFileDevice::NoError);
  file_error.addValue("ReadError", QFileDevice::ReadError);
  file_error.addValue("WriteError", QFileDevice::WriteError);
  file_error.addValue("FatalError", QFileDevice::FatalError);
  file_error.addValue("ResourceError", QFileDevice::ResourceError);
  file_error.addValue("OpenError", QFileDevice::OpenError);
  file_error.addValue("AbortError", QFileDevice::AbortError);
  file_error.addValue("TimeOutError", QFileDevice::TimeOutError);
  file_error.addValue("UnspecifiedError", QFileDevice::UnspecifiedError);
  file_error.addValue("RemoveError", QFileDevice::RemoveError);
  file_error.addValue("RenameError", QFileDevice::RenameError);
  file_error.addValue("PositionError", QFileDevice::PositionError);
  file_error.addValue("ResizeError", QFileDevice::ResizeError);
  file_error.addValue("PermissionsError", QFileDevice::PermissionsError);
  file_error.addValue("CopyError", QFileDevice::CopyError);
}


static void register_file_device_permission_enum(script::Class file_device)
{
  using namespace script;

  Enum permission = file_device.newEnum("Permission").setId(script::Type::QFileDevicePermission).get();

  register_qflags_type<QFileDevice::Permission>(file_device, "Permissions", script::Type::QFileDevicePermissions);
  permission.addValue("ReadOwner", QFileDevice::ReadOwner);
  permission.addValue("WriteOwner", QFileDevice::WriteOwner);
  permission.addValue("ExeOwner", QFileDevice::ExeOwner);
  permission.addValue("ReadUser", QFileDevice::ReadUser);
  permission.addValue("WriteUser", QFileDevice::WriteUser);
  permission.addValue("ExeUser", QFileDevice::ExeUser);
  permission.addValue("ReadGroup", QFileDevice::ReadGroup);
  permission.addValue("WriteGroup", QFileDevice::WriteGroup);
  permission.addValue("ExeGroup", QFileDevice::ExeGroup);
  permission.addValue("ReadOther", QFileDevice::ReadOther);
  permission.addValue("WriteOther", QFileDevice::WriteOther);
  permission.addValue("ExeOther", QFileDevice::ExeOther);
}


static void register_file_device_file_handle_flag_enum(script::Class file_device)
{
  using namespace script;

  Enum file_handle_flag = file_device.newEnum("FileHandleFlag").setId(script::Type::QFileDeviceFileHandleFlag).get();

  register_qflags_type<QFileDevice::FileHandleFlag>(file_device, "FileHandleFlags", script::Type::QFileDeviceFileHandleFlags);
  file_handle_flag.addValue("AutoCloseHandle", QFileDevice::AutoCloseHandle);
  file_handle_flag.addValue("DontCloseHandle", QFileDevice::DontCloseHandle);
}


static void register_file_device_memory_map_flags_enum(script::Class file_device)
{
  using namespace script;

  Enum memory_map_flags = file_device.newEnum("MemoryMapFlags").setId(script::Type::QFileDeviceMemoryMapFlags).get();

  memory_map_flags.addValue("NoOptions", QFileDevice::NoOptions);
  memory_map_flags.addValue("MapPrivateOption", QFileDevice::MapPrivateOption);
}


static void register_file_device_class(script::Namespace ns)
{
  using namespace script;

  Class file_device = ns.newClass("FileDevice").setId(script::Type::QFileDevice)
    .setBase(script::Type::QIODevice).get();

  register_file_device_file_error_enum(file_device);
  register_file_device_permission_enum(file_device);
  register_file_device_file_handle_flag_enum(file_device);
  register_file_device_memory_map_flags_enum(file_device);

  // ~QFileDevice();
  bind::destructor<QFileDevice>(file_device).create();
  // QFileDevice::FileError error() const;
  bind::member_function<QFileDevice, QFileDevice::FileError, &QFileDevice::error>(file_device, "error").create();
  // void unsetError();
  bind::void_member_function<QFileDevice, &QFileDevice::unsetError>(file_device, "unsetError").create();
  // void close();
  bind::void_member_function<QFileDevice, &QFileDevice::close>(file_device, "close").create();
  // bool isSequential() const;
  bind::member_function<QFileDevice, bool, &QFileDevice::isSequential>(file_device, "isSequential").create();
  // int handle() const;
  bind::member_function<QFileDevice, int, &QFileDevice::handle>(file_device, "handle").create();
  // QString fileName() const;
  bind::member_function<QFileDevice, QString, &QFileDevice::fileName>(file_device, "fileName").create();
  // qint64 pos() const;
  /// TODO: qint64 pos() const;
  // bool seek(qint64);
  /// TODO: bool seek(qint64);
  // bool atEnd() const;
  bind::member_function<QFileDevice, bool, &QFileDevice::atEnd>(file_device, "atEnd").create();
  // bool flush();
  bind::member_function<QFileDevice, bool, &QFileDevice::flush>(file_device, "flush").create();
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // bool resize(qint64);
  /// TODO: bool resize(qint64);
  // QFileDevice::Permissions permissions() const;
  bind::member_function<QFileDevice, QFileDevice::Permissions, &QFileDevice::permissions>(file_device, "permissions").create();
  // bool setPermissions(QFileDevice::Permissions);
  bind::member_function<QFileDevice, bool, QFileDevice::Permissions, &QFileDevice::setPermissions>(file_device, "setPermissions").create();
  // QDateTime fileTime(QFileDevice::FileTime) const;
  /// TODO: QDateTime fileTime(QFileDevice::FileTime) const;
  // bool setFileTime(const QDateTime &, QFileDevice::FileTime);
  /// TODO: bool setFileTime(const QDateTime &, QFileDevice::FileTime);

  bind::link(file_device, &QFileDevice::staticMetaObject);
}


void register_filedevice_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_file_device_class(ns);

  // QFileDevice::Permissions operator|(QFileDevice::Permission, QFileDevice::Permission);
  bind::op_bitor<QFileDevice::Permissions, QFileDevice::Permission, QFileDevice::Permission>(ns);
  // QFileDevice::Permissions operator|(QFileDevice::Permission, QFileDevice::Permissions);
  bind::op_bitor<QFileDevice::Permissions, QFileDevice::Permission, QFileDevice::Permissions>(ns);
  // QIncompatibleFlag operator|(QFileDevice::Permissions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QFileDevice::Permissions::enum_type, int);
}

