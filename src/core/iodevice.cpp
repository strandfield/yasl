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
  binding::ClassBinder<QIODevice> binder{ i_o_device, &QIODevice::staticMetaObject };

  // ~QIODevice();
  binder.dtor().create();
  // QIODevice::OpenMode openMode() const;
  binder.fun<QIODevice::OpenMode, &QIODevice::openMode>("openMode").create();
  // void setTextModeEnabled(bool);
  binder.void_fun<bool, &QIODevice::setTextModeEnabled>("setTextModeEnabled").create();
  // bool isTextModeEnabled() const;
  binder.fun<bool, &QIODevice::isTextModeEnabled>("isTextModeEnabled").create();
  // bool isOpen() const;
  binder.fun<bool, &QIODevice::isOpen>("isOpen").create();
  // bool isReadable() const;
  binder.fun<bool, &QIODevice::isReadable>("isReadable").create();
  // bool isWritable() const;
  binder.fun<bool, &QIODevice::isWritable>("isWritable").create();
  // bool isSequential() const;
  binder.fun<bool, &QIODevice::isSequential>("isSequential").create();
  // int readChannelCount() const;
  binder.fun<int, &QIODevice::readChannelCount>("readChannelCount").create();
  // int writeChannelCount() const;
  binder.fun<int, &QIODevice::writeChannelCount>("writeChannelCount").create();
  // int currentReadChannel() const;
  binder.fun<int, &QIODevice::currentReadChannel>("currentReadChannel").create();
  // void setCurrentReadChannel(int);
  binder.void_fun<int, &QIODevice::setCurrentReadChannel>("setCurrentReadChannel").create();
  // int currentWriteChannel() const;
  binder.fun<int, &QIODevice::currentWriteChannel>("currentWriteChannel").create();
  // void setCurrentWriteChannel(int);
  binder.void_fun<int, &QIODevice::setCurrentWriteChannel>("setCurrentWriteChannel").create();
  // bool open(QIODevice::OpenMode);
  binder.fun<bool, QIODevice::OpenMode, &QIODevice::open>("open").create();
  // void close();
  binder.void_fun<&QIODevice::close>("close").create();
  // qint64 pos() const;
  /// TODO: qint64 pos() const;
  // qint64 size() const;
  /// TODO: qint64 size() const;
  // bool seek(qint64);
  /// TODO: bool seek(qint64);
  // bool atEnd() const;
  binder.fun<bool, &QIODevice::atEnd>("atEnd").create();
  // bool reset();
  binder.fun<bool, &QIODevice::reset>("reset").create();
  // qint64 bytesAvailable() const;
  /// TODO: qint64 bytesAvailable() const;
  // qint64 bytesToWrite() const;
  /// TODO: qint64 bytesToWrite() const;
  // qint64 read(char *, qint64);
  /// TODO: qint64 read(char *, qint64);
  // QByteArray read(qint64);
  /// TODO: QByteArray read(qint64);
  // QByteArray readAll();
  binder.fun<QByteArray, &QIODevice::readAll>("readAll").create();
  // qint64 readLine(char *, qint64);
  /// TODO: qint64 readLine(char *, qint64);
  // QByteArray readLine(qint64);
  /// TODO: QByteArray readLine(qint64);
  // bool canReadLine() const;
  binder.fun<bool, &QIODevice::canReadLine>("canReadLine").create();
  // void startTransaction();
  binder.void_fun<&QIODevice::startTransaction>("startTransaction").create();
  // void commitTransaction();
  binder.void_fun<&QIODevice::commitTransaction>("commitTransaction").create();
  // void rollbackTransaction();
  binder.void_fun<&QIODevice::rollbackTransaction>("rollbackTransaction").create();
  // bool isTransactionStarted() const;
  binder.fun<bool, &QIODevice::isTransactionStarted>("isTransactionStarted").create();
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
  binder.fun<bool, int, &QIODevice::waitForReadyRead>("waitForReadyRead").create();
  // bool waitForBytesWritten(int);
  binder.fun<bool, int, &QIODevice::waitForBytesWritten>("waitForBytesWritten").create();
  // void ungetChar(char);
  binder.void_fun<char, &QIODevice::ungetChar>("ungetChar").create();
  // bool putChar(char);
  binder.fun<bool, char, &QIODevice::putChar>("putChar").create();
  // bool getChar(char *);
  /// TODO: bool getChar(char *);
  // QString errorString() const;
  binder.fun<QString, &QIODevice::errorString>("errorString").create();
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

