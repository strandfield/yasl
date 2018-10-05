// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/iodevice.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/iodevice.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_i_o_device_open_mode_flag_enum(script::Class i_o_device)
{
  using namespace script;

  Enum open_mode_flag = i_o_device.Enum("OpenModeFlag").setId(script::Type::QIODeviceOpenModeFlag).get();

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

  Class i_o_device = ns.Class("IODevice").setId(script::Type::QIODevice)
    .setBase(script::Type::QObject).get();

  register_i_o_device_open_mode_flag_enum(i_o_device);
  binding::QClass<QIODevice> binder{ i_o_device, &QIODevice::staticMetaObject };

  // ~QIODevice();
  binder.add_dtor();
  // QIODevice::OpenMode openMode() const;
  binder.add_fun<QIODevice::OpenMode, &QIODevice::openMode>("openMode");
  // void setTextModeEnabled(bool);
  binder.add_void_fun<bool, &QIODevice::setTextModeEnabled>("setTextModeEnabled");
  // bool isTextModeEnabled() const;
  binder.add_fun<bool, &QIODevice::isTextModeEnabled>("isTextModeEnabled");
  // bool isOpen() const;
  binder.add_fun<bool, &QIODevice::isOpen>("isOpen");
  // bool isReadable() const;
  binder.add_fun<bool, &QIODevice::isReadable>("isReadable");
  // bool isWritable() const;
  binder.add_fun<bool, &QIODevice::isWritable>("isWritable");
  // bool isSequential() const;
  binder.add_fun<bool, &QIODevice::isSequential>("isSequential");
  // int readChannelCount() const;
  binder.add_fun<int, &QIODevice::readChannelCount>("readChannelCount");
  // int writeChannelCount() const;
  binder.add_fun<int, &QIODevice::writeChannelCount>("writeChannelCount");
  // int currentReadChannel() const;
  binder.add_fun<int, &QIODevice::currentReadChannel>("currentReadChannel");
  // void setCurrentReadChannel(int);
  binder.add_void_fun<int, &QIODevice::setCurrentReadChannel>("setCurrentReadChannel");
  // int currentWriteChannel() const;
  binder.add_fun<int, &QIODevice::currentWriteChannel>("currentWriteChannel");
  // void setCurrentWriteChannel(int);
  binder.add_void_fun<int, &QIODevice::setCurrentWriteChannel>("setCurrentWriteChannel");
  // bool open(QIODevice::OpenMode);
  binder.add_fun<bool, QIODevice::OpenMode, &QIODevice::open>("open");
  // void close();
  binder.add_void_fun<&QIODevice::close>("close");
  // qint64 pos() const;
  /// TODO: qint64 pos() const;
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // bool seek(qint64);
  /// TODO: bool seek(qint64);
  // bool atEnd() const;
  binder.add_fun<bool, &QIODevice::atEnd>("atEnd");
  // bool reset();
  binder.add_fun<bool, &QIODevice::reset>("reset");
  // qint64 bytesAvailable() const;
  /// TODO: qint64 bytesAvailable() const;
  // qint64 bytesToWrite() const;
  /// TODO: qint64 bytesToWrite() const;
  // qint64 read(char *, qint64);
  /// TODO: qint64 read(char *, qint64);
  // QByteArray read(qint64);
  /// TODO: QByteArray read(qint64);
  // QByteArray readAll();
  binder.add_fun<QByteArray, &QIODevice::readAll>("readAll");
  // qint64 readLine(char *, qint64);
  /// TODO: qint64 readLine(char *, qint64);
  // QByteArray readLine(qint64);
  /// TODO: QByteArray readLine(qint64);
  // bool canReadLine() const;
  binder.add_fun<bool, &QIODevice::canReadLine>("canReadLine");
  // void startTransaction();
  binder.add_void_fun<&QIODevice::startTransaction>("startTransaction");
  // void commitTransaction();
  binder.add_void_fun<&QIODevice::commitTransaction>("commitTransaction");
  // void rollbackTransaction();
  binder.add_void_fun<&QIODevice::rollbackTransaction>("rollbackTransaction");
  // bool isTransactionStarted() const;
  binder.add_fun<bool, &QIODevice::isTransactionStarted>("isTransactionStarted");
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
  binder.add_fun<bool, int, &QIODevice::waitForReadyRead>("waitForReadyRead");
  // bool waitForBytesWritten(int);
  binder.add_fun<bool, int, &QIODevice::waitForBytesWritten>("waitForBytesWritten");
  // void ungetChar(char);
  binder.add_void_fun<char, &QIODevice::ungetChar>("ungetChar");
  // bool putChar(char);
  binder.add_fun<bool, char, &QIODevice::putChar>("putChar");
  // bool getChar(char *);
  /// TODO: bool getChar(char *);
  // QString errorString() const;
  binder.add_fun<QString, &QIODevice::errorString>("errorString");
  // void readyRead();
  binder.sigs().add("readyRead", "readyRead()");
  // void channelReadyRead(int);
  binder.sigs().add<int>("channelReadyRead", "channelReadyRead(int)");
  // void bytesWritten(qint64);
  binder.sigs().add<qint64>("bytesWritten", "bytesWritten(qint64)");
  // void channelBytesWritten(int, qint64);
  binder.sigs().add<int, qint64>("channelBytesWritten", "channelBytesWritten(int,qint64)");
  // void aboutToClose();
  binder.sigs().add("aboutToClose", "aboutToClose()");
  // void readChannelFinished();
  binder.sigs().add("readChannelFinished", "readChannelFinished()");

  i_o_device.engine()->registerQtType(&QIODevice::staticMetaObject, i_o_device.id());
}


void register_iodevice_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_i_o_device_class(ns);
  binding::Namespace binder{ ns };

  // QIODevice::OpenMode operator|(QIODevice::OpenModeFlag, QIODevice::OpenModeFlag);
  binder.operators().or<QIODevice::OpenMode, QIODevice::OpenModeFlag, QIODevice::OpenModeFlag>();
  // QIODevice::OpenMode operator|(QIODevice::OpenModeFlag, QIODevice::OpenMode);
  binder.operators().or<QIODevice::OpenMode, QIODevice::OpenModeFlag, QIODevice::OpenMode>();
  // QIncompatibleFlag operator|(QIODevice::OpenMode::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QIODevice::OpenMode::enum_type, int);
  // QDebug operator<<(QDebug, QIODevice::OpenMode);
  /// TODO: QDebug operator<<(QDebug, QIODevice::OpenMode);
}

