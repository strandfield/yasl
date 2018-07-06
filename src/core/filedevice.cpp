// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/file.h"

#include "yasl/binding/qclass.h"
#include "yasl/core/datetime.h"
#include "yasl/core/flags.h"
#include "yasl/utils/typeregistration.h"

#include <script/engine.h>

static int filedevice_type_id = 0;
static int fileerror_type_id = 0;
static int filehandleflag_type_id = 0;
static int filehandleflags_type_id = 0;
static int filedevice_filetime_type_id = 0;
static int filedevice_memorymapflags_type_id = 0;
static int filedevice_permission_type_id = 0;
static int filedevice_permissions_type_id = 0;

void register_file_error_enum(script::Class filedevice)
{
  using namespace script;

  Enum file_error = filedevice.newEnum("FileError");
  fileerror_type_id = file_error.id();

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

script::Type get_filedevice_fileerror_type()
{
  return script::Type{ fileerror_type_id };
}


void register_file_handle_flag_enum(script::Class filedevice)
{
  using namespace script;

  Enum file_handle_flag = filedevice.newEnum("FileHandleFlag");
  filehandleflag_type_id = file_handle_flag.id();

  file_handle_flag.addValue("AutoCloseHandle", QFileDevice::AutoCloseHandle);
  file_handle_flag.addValue("DontCloseHandle", QFileDevice::DontCloseHandle);

  Class file_handle_flags = register_qflags_type<QFileDevice::FileHandleFlag>(filedevice, "FileHandleFlags");
  filehandleflags_type_id = file_handle_flags.id();
}

script::Type get_filedevice_filehandleflag_type()
{
  return script::Type{ filehandleflag_type_id };
}

script::Type get_filedevice_filehandleflags_type()
{
  return script::Type{ filehandleflags_type_id };
}


script::Type get_filedevice_filetime_type()
{
  return script::Type{ filedevice_filetime_type_id };
}

void register_filetime_enum(script::Class filedevice)
{
  using namespace script;

  Enum filetime = filedevice.newEnum("FileTime");
  filedevice_filetime_type_id = filetime.id();

  filetime.addValue("FileAccessTime", QFileDevice::FileAccessTime);
  filetime.addValue("FileBirthTime", QFileDevice::FileBirthTime);
  filetime.addValue("FileMetadataChangeTime", QFileDevice::FileMetadataChangeTime);
  filetime.addValue("FileModificationTime", QFileDevice::FileModificationTime);
}


script::Type get_filedevice_memorymapflags_type()
{
  return script::Type{ filedevice_memorymapflags_type_id };
}

void register_memorymapflags_enum(script::Class filedevice)
{
  using namespace script;

  Enum memorymapflags = filedevice.newEnum("MemoryMapFlags");
  filedevice_memorymapflags_type_id = memorymapflags.id();

  memorymapflags.addValue("NoOptions", QFileDevice::NoOptions);
  memorymapflags.addValue("MapPrivateOption", QFileDevice::MapPrivateOption);
}


script::Type get_filedevice_permission_type()
{
  return script::Type{ filedevice_permission_type_id };
}

script::Type get_filedevice_permissions_type()
{
  return script::Type{ filedevice_permissions_type_id };
}

void register_permission_enum(script::Class filedevice)
{
  using namespace script;

  Enum permission = filedevice.newEnum("Permission");
  filedevice_permission_type_id = permission.id();

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

  Class permissions = register_qflags_type<QFileDevice::Permission>(filedevice, "Permissions");
  filedevice_permissions_type_id = permissions.id();
}



script::Type get_filedevice_type()
{
  return script::Type{ filedevice_type_id };
}

void register_filedevice_class(script::Namespace n)
{
  using namespace script;

  Class iodevice = n.engine()->getClass(get_iodevice_type());

  Class filedevice = n.newClass(ClassBuilder::New("FileDevice").setParent(iodevice));
  filedevice_type_id = filedevice.id();

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

  register_object_type(&QFileDevice::staticMetaObject, Type{ filedevice.id() });
}
