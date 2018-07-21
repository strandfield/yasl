// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/file.h"

#include "yasl/binding/qclass.h"
#include "yasl/core/datetime.h"
#include "yasl/core/flags.h"

#include <script/classbuilder.h>
#include <script/engine.h>
#include <script/enumbuilder.h>

void register_file_error_enum(script::Class filedevice)
{
  using namespace script;

  Enum file_error = filedevice.Enum("FileError").setId(Type::QFileDeviceFileError).get();

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


void register_file_handle_flag_enum(script::Class filedevice)
{
  using namespace script;

  Enum file_handle_flag = filedevice.Enum("FileHandleFlag").setId(Type::QFileDeviceFileHandleFlag).get();

  file_handle_flag.addValue("AutoCloseHandle", QFileDevice::AutoCloseHandle);
  file_handle_flag.addValue("DontCloseHandle", QFileDevice::DontCloseHandle);

  Class file_handle_flags = register_qflags_type<QFileDevice::FileHandleFlag>(filedevice, "FileHandleFlags", script::Type::QFileDeviceFileHandleFlags);
}


void register_filetime_enum(script::Class filedevice)
{
  using namespace script;

  Enum filetime = filedevice.Enum("FileTime").setId(Type::QFileDeviceFileTime).get();

  filetime.addValue("FileAccessTime", QFileDevice::FileAccessTime);
  filetime.addValue("FileBirthTime", QFileDevice::FileBirthTime);
  filetime.addValue("FileMetadataChangeTime", QFileDevice::FileMetadataChangeTime);
  filetime.addValue("FileModificationTime", QFileDevice::FileModificationTime);
}


void register_memorymapflags_enum(script::Class filedevice)
{
  using namespace script;

  Enum memorymapflags = filedevice.Enum("MemoryMapFlags").setId(Type::QFileDeviceMemoryMapFlags).get();

  memorymapflags.addValue("NoOptions", QFileDevice::NoOptions);
  memorymapflags.addValue("MapPrivateOption", QFileDevice::MapPrivateOption);
}


void register_permission_enum(script::Class filedevice)
{
  using namespace script;

  Enum permission = filedevice.Enum("Permission").setId(Type::QFileDevicePermission).get();

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
  permission.addValue("ResizeError", QFileDevice::ResizeError);
  permission.addValue("PermissionsError", QFileDevice::PermissionsError);
  permission.addValue("CopyError", QFileDevice::CopyError);

  Class permissions = register_qflags_type<QFileDevice::Permission>(filedevice, "Permissions", Type::QFileDevicePermissions);
}


void register_filedevice_class(script::Namespace n)
{
  using namespace script;

  Class iodevice = n.engine()->getClass(Type::QIODevice);

  Class filedevice = n.Class("FileDevice").setId(Type::QFileDevice).setBase(iodevice).get();

  register_file_error_enum(filedevice);
  register_file_handle_flag_enum(filedevice);
  register_filetime_enum(filedevice);
  register_memorymapflags_enum(filedevice);
  register_permission_enum(filedevice);

  binding::QClass<QFileDevice> binder{ filedevice };

  /* Public functions */

  // QFileDevice::FileError error() const
  binder.add_fun<QFileDevice::FileError, &QFileDevice::error>("error");
  // virtual QString fileName() const
  /// TODO !!!
  // QDateTime fileTime(QFileDevice::FileTime time) const
  binder.add_fun<QDateTime, QFileDevice::FileTime, &QFileDevice::fileTime>("fileTime");
  // bool flush()
  binder.add_fun<bool, &QFileDevice::flush>("flush");
  // int handle() const
  binder.add_fun<int, &QFileDevice::handle>("handle");
  // uchar * map(qint64 offset, qint64 size, QFileDevice::MemoryMapFlags flags = NoOptions)
  /// TODO !!!
  // virtual QFileDevice::Permissions permissions() const
  /// TODO !!!
  // virtual bool resize(qint64 sz)
  /// TODO !!!
  // bool setFileTime(const QDateTime &newDate, QFileDevice::FileTime fileTime)
  binder.add_fun<bool, const QDateTime &, QFileDevice::FileTime, &QFileDevice::setFileTime>("setFileTime");
  // virtual bool setPermissions(QFileDevice::Permissions permissions)
  /// TODO !!!
  // bool unmap(uchar *address)
  /// TODO !!!
  // void unsetError()
  binder.add_void_fun<&QFileDevice::unsetError>("unsetError");


  /* MetaObject resgistration */

  n.engine()->registerQtType(&QFileDevice::staticMetaObject, Type{ filedevice.id() });
}
