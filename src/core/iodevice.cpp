// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/iodevice.h"

#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"
#include "yasl/core/flags.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/iodevice.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_i_o_device_open_mode_flag_enum(script::Class i_o_device)
{
  using namespace script;

  Enum open_mode_flag = i_o_device.newEnum("OpenModeFlag").setId(script::Type::QIODeviceOpenModeFlag).get();

  register_qflags_type<QIODevice::OpenModeFlag>(i_o_device, "OpenMode", script::Type::QIODeviceOpenMode);
  open_mode_flag.addValue("NotOpen", QIODevice::NotOpen);
  open_mode_flag.addValue("ReadOnly", QIODevice::ReadOnly);
  open_mode_flag.addValue("WriteOnly", QIODevice::WriteOnly);
  open_mode_flag.addValue("ReadWrite", QIODevice::ReadWrite);
  open_mode_flag.addValue("Append", QIODevice::Append);
  open_mode_flag.addValue("Truncate", QIODevice::Truncate);
  open_mode_flag.addValue("Text", QIODevice::Text);
  open_mode_flag.addValue("Unbuffered", QIODevice::Unbuffered);
}


static void register_i_o_device_class(script::Namespace ns)
{
  using namespace script;

  Class i_o_device = ns.newClass("IODevice").setId(script::Type::QIODevice)
    .setBase(script::Type::QObject).get();

  register_i_o_device_open_mode_flag_enum(i_o_device);

  // ~QIODevice();
  bind::destructor<QIODevice>(i_o_device).create();
  // QIODevice::OpenMode openMode() const;
  bind::member_function<QIODevice, QIODevice::OpenMode, &QIODevice::openMode>(i_o_device, "openMode").create();
  // void setTextModeEnabled(bool);
  bind::void_member_function<QIODevice, bool, &QIODevice::setTextModeEnabled>(i_o_device, "setTextModeEnabled").create();
  // bool isTextModeEnabled() const;
  bind::member_function<QIODevice, bool, &QIODevice::isTextModeEnabled>(i_o_device, "isTextModeEnabled").create();
  // bool isOpen() const;
  bind::member_function<QIODevice, bool, &QIODevice::isOpen>(i_o_device, "isOpen").create();
  // bool isReadable() const;
  bind::member_function<QIODevice, bool, &QIODevice::isReadable>(i_o_device, "isReadable").create();
  // bool isWritable() const;
  bind::member_function<QIODevice, bool, &QIODevice::isWritable>(i_o_device, "isWritable").create();
  // bool isSequential() const;
  bind::member_function<QIODevice, bool, &QIODevice::isSequential>(i_o_device, "isSequential").create();
  // int readChannelCount() const;
  bind::member_function<QIODevice, int, &QIODevice::readChannelCount>(i_o_device, "readChannelCount").create();
  // int writeChannelCount() const;
  bind::member_function<QIODevice, int, &QIODevice::writeChannelCount>(i_o_device, "writeChannelCount").create();
  // int currentReadChannel() const;
  bind::member_function<QIODevice, int, &QIODevice::currentReadChannel>(i_o_device, "currentReadChannel").create();
  // void setCurrentReadChannel(int);
  bind::void_member_function<QIODevice, int, &QIODevice::setCurrentReadChannel>(i_o_device, "setCurrentReadChannel").create();
  // int currentWriteChannel() const;
  bind::member_function<QIODevice, int, &QIODevice::currentWriteChannel>(i_o_device, "currentWriteChannel").create();
  // void setCurrentWriteChannel(int);
  bind::void_member_function<QIODevice, int, &QIODevice::setCurrentWriteChannel>(i_o_device, "setCurrentWriteChannel").create();
  // bool open(QIODevice::OpenMode);
  bind::member_function<QIODevice, bool, QIODevice::OpenMode, &QIODevice::open>(i_o_device, "open").create();
  // void close();
  bind::void_member_function<QIODevice, &QIODevice::close>(i_o_device, "close").create();
  // qint64 pos() const;
  /// TODO: qint64 pos() const;
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // bool seek(qint64);
  /// TODO: bool seek(qint64);
  // bool atEnd() const;
  bind::member_function<QIODevice, bool, &QIODevice::atEnd>(i_o_device, "atEnd").create();
  // bool reset();
  bind::member_function<QIODevice, bool, &QIODevice::reset>(i_o_device, "reset").create();
  // qint64 bytesAvailable() const;
  /// TODO: qint64 bytesAvailable() const;
  // qint64 bytesToWrite() const;
  /// TODO: qint64 bytesToWrite() const;
  // qint64 read(char *, qint64);
  /// TODO: qint64 read(char *, qint64);
  // QByteArray read(qint64);
  /// TODO: QByteArray read(qint64);
  // QByteArray readAll();
  bind::member_function<QIODevice, QByteArray, &QIODevice::readAll>(i_o_device, "readAll").create();
  // qint64 readLine(char *, qint64);
  /// TODO: qint64 readLine(char *, qint64);
  // QByteArray readLine(qint64);
  /// TODO: QByteArray readLine(qint64);
  // bool canReadLine() const;
  bind::member_function<QIODevice, bool, &QIODevice::canReadLine>(i_o_device, "canReadLine").create();
  // void startTransaction();
  bind::void_member_function<QIODevice, &QIODevice::startTransaction>(i_o_device, "startTransaction").create();
  // void commitTransaction();
  bind::void_member_function<QIODevice, &QIODevice::commitTransaction>(i_o_device, "commitTransaction").create();
  // void rollbackTransaction();
  bind::void_member_function<QIODevice, &QIODevice::rollbackTransaction>(i_o_device, "rollbackTransaction").create();
  // bool isTransactionStarted() const;
  bind::member_function<QIODevice, bool, &QIODevice::isTransactionStarted>(i_o_device, "isTransactionStarted").create();
  // qint64 write(const char *, qint64);
  /// TODO: qint64 write(const char *, qint64);
  // qint64 write(const char *);
  /// TODO: qint64 write(const char *);
  // qint64 write(const QByteArray &);
  /// TODO: qint64 write(const QByteArray &);
  // qint64 peek(char *, qint64);
  /// TODO: qint64 peek(char *, qint64);
  // QByteArray peek(qint64);
  /// TODO: QByteArray peek(qint64);
  // qint64 skip(qint64);
  /// TODO: qint64 skip(qint64);
  // bool waitForReadyRead(int);
  bind::member_function<QIODevice, bool, int, &QIODevice::waitForReadyRead>(i_o_device, "waitForReadyRead").create();
  // bool waitForBytesWritten(int);
  bind::member_function<QIODevice, bool, int, &QIODevice::waitForBytesWritten>(i_o_device, "waitForBytesWritten").create();
  // void ungetChar(char);
  bind::void_member_function<QIODevice, char, &QIODevice::ungetChar>(i_o_device, "ungetChar").create();
  // bool putChar(char);
  bind::member_function<QIODevice, bool, char, &QIODevice::putChar>(i_o_device, "putChar").create();
  // bool getChar(char *);
  /// TODO: bool getChar(char *);
  // QString errorString() const;
  bind::member_function<QIODevice, QString, &QIODevice::errorString>(i_o_device, "errorString").create();
  // void readyRead();
  bind::signal<QIODevice>(i_o_device, "readyRead", "readyRead()");
  // void channelReadyRead(int);
  bind::signal<QIODevice, int>(i_o_device, "channelReadyRead", "channelReadyRead(int)");
  // void bytesWritten(qint64);
  /// TODO: void bytesWritten(qint64);
  // void channelBytesWritten(int, qint64);
  /// TODO: void channelBytesWritten(int, qint64);
  // void aboutToClose();
  bind::signal<QIODevice>(i_o_device, "aboutToClose", "aboutToClose()");
  // void readChannelFinished();
  bind::signal<QIODevice>(i_o_device, "readChannelFinished", "readChannelFinished()");

  bind::link(i_o_device, &QIODevice::staticMetaObject);
}


void register_iodevice_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_i_o_device_class(ns);

  // QIODevice::OpenMode operator|(QIODevice::OpenModeFlag, QIODevice::OpenModeFlag);
  bind::op_bitor<QIODevice::OpenMode, QIODevice::OpenModeFlag, QIODevice::OpenModeFlag>(ns);
  // QIODevice::OpenMode operator|(QIODevice::OpenModeFlag, QIODevice::OpenMode);
  bind::op_bitor<QIODevice::OpenMode, QIODevice::OpenModeFlag, QIODevice::OpenMode>(ns);
  // QIncompatibleFlag operator|(QIODevice::OpenMode::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QIODevice::OpenMode::enum_type, int);
  // QDebug operator<<(QDebug, QIODevice::OpenMode);
  /// TODO: QDebug operator<<(QDebug, QIODevice::OpenMode);
}

