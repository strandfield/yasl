// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/iodevice.h"

#include "yasl/binding/qclass.h"
#include "yasl/binding/qsignal.h"
#include "yasl/core/bytearray.h"
#include "yasl/core/flags.h"
#include "yasl/utils/typeregistration.h"

#include <script/engine.h>
#include <script/functionbuilder.h>
#include <script/interpreter/executioncontext.h>
#include <script/value.h>

static int iodevice_type_id = 0;
static int iodevice_open_mode_flag_type_id = 0;
static int iodevice_open_mode_type_id = 0;

void register_iodevice_open_mode(script::Class iodevice)
{
  using namespace script;

  Enum open_mode_flag = iodevice.newEnum("OpenModeFlag");
  iodevice_open_mode_flag_type_id = open_mode_flag.id();

  open_mode_flag.addValue("NotOpen", QIODevice::NotOpen);
  open_mode_flag.addValue("ReadOnly", QIODevice::ReadOnly);
  open_mode_flag.addValue("WriteOnly", QIODevice::WriteOnly);
  open_mode_flag.addValue("ReadWrite", QIODevice::ReadWrite);
  open_mode_flag.addValue("Append", QIODevice::Append);
  open_mode_flag.addValue("Truncate", QIODevice::Truncate);
  open_mode_flag.addValue("Text", QIODevice::Text);
  open_mode_flag.addValue("Unbuffered", QIODevice::Unbuffered);
  //open_mode_flag.addValue("NewOnly", QIODevice::NewOnly);
  //open_mode_flag.addValue("ExistingOnly", QIODevice::ExistingOnly);

  Class open_mode = register_qflags_type<QIODevice::OpenModeFlag>(iodevice, "OpenMode");
  iodevice_open_mode_type_id = open_mode.id();
}

script::Type get_iodevice_open_mode_flag_type()
{
  return script::Type{ iodevice_open_mode_flag_type_id };
}

script::Type get_iodevice_open_mode_type()
{
  return script::Type{ iodevice_open_mode_type_id };
}

script::Type get_iodevice_type()
{
  return script::Type{ iodevice_type_id };
}

void register_iodevice_class(script::Namespace n)
{
  using namespace script;

  Class object = n.engine()->getClass(get_qobject_type());

  Class iodevice = n.newClass(ClassBuilder::New("IODevice").setParent(object));
  iodevice_type_id = iodevice.id();

  register_iodevice_open_mode(iodevice);

  binding::QClass<QIODevice> binder{ iodevice };


  /* Public functions */

  // virtual bool atEnd() const
  binder.add_fun<bool, &QIODevice::atEnd>("atEnd");
  // virtual qint64 bytesAvailable() const
  binder.add_fun<qint64, &QIODevice::bytesAvailable>("bytesAvailable");
  // virtual qint64 bytesToWrite() const
  binder.add_fun<qint64, &QIODevice::bytesToWrite>("bytesToWrite");
  // virtual bool canReadLine() const
  binder.add_fun<bool, &QIODevice::canReadLine>("canReadLine");
  // virtual void close()
  binder.add_void_fun<&QIODevice::close>("close");
  // void commitTransaction()
  binder.add_void_fun<&QIODevice::commitTransaction>("commitTransaction");
  // int currentReadChannel() const
  binder.add_fun<int, &QIODevice::currentReadChannel>("currentReadChannel");
  // int currentWriteChannel() const
  binder.add_fun<int, &QIODevice::currentWriteChannel>("currentWriteChannel");
  // QString errorString() const
  binder.add_fun<QString, &QIODevice::errorString>("errorString");
  // bool getChar(char *c)
  /// TODO !!!
  // bool isOpen() const
  binder.add_fun<bool, &QIODevice::isOpen>("isOpen");
  // bool isReadable() const
  binder.add_fun<bool, &QIODevice::isReadable>("isReadable");
  // virtual bool isSequential() const
  binder.add_fun<bool, &QIODevice::isSequential>("isSequential");
  // bool isTextModeEnabled() const
  binder.add_fun<bool, &QIODevice::isTextModeEnabled>("isTextModeEnabled");
  // bool isTransactionStarted() const
  binder.add_fun<bool, &QIODevice::isTransactionStarted>("isTransactionStarted");
  // bool isWritable() const
  binder.add_fun<bool, &QIODevice::isWritable>("isWritable");
  // virtual bool open(QIODevice::OpenMode mode)
  binder.add_fun<bool, QIODevice::OpenMode, &QIODevice::open>("open");
  // QIODevice::OpenMode openMode() const
  binder.add_fun<QIODevice::OpenMode, &QIODevice::openMode>("openMode");
  // qint64 peek(char *data, qint64 maxSize)
  /// TODO !!!
  // QByteArray peek(qint64 maxSize)
  binder.add_fun<QByteArray, qint64, &QIODevice::peek>("peek");
  // virtual qint64 pos() const
  binder.add_fun<qint64, &QIODevice::pos>("pos");
  // bool putChar(char c)
  binder.add_fun<bool, char, &QIODevice::putChar>("putChar");
  // qint64 read(char *data, qint64 maxSize)
  /// TODO !!!
  // QByteArray read(qint64 maxSize)
  binder.add_fun<QByteArray, qint64, &QIODevice::read>("read");
  // QByteArray readAll()
  binder.add_fun<QByteArray, &QIODevice::readAll>("readAll");
  // int readChannelCount() const
  binder.add_fun<int, &QIODevice::readChannelCount>("readChannelCount");
  // qint64 readLine(char *data, qint64 maxSize)
  /// TODO !!!
  // QByteArray readLine(qint64 maxSize = 0)
  binder.add_fun<QByteArray, qint64, &QIODevice::readLine>("readLine");
  // virtual bool reset()
  binder.add_fun<bool, &QIODevice::reset>("reset");
  // void rollbackTransaction()
  binder.add_void_fun<&QIODevice::rollbackTransaction>("rollbackTransaction");
  // virtual bool seek(qint64 pos)
  binder.add_fun<bool, qint64, &QIODevice::seek>("seek");
  // void setCurrentReadChannel(int channel)
  binder.add_void_fun<int, &QIODevice::setCurrentReadChannel>("setCurrentReadChannel");
  // void setCurrentWriteChannel(int channel)
  binder.add_void_fun<int, &QIODevice::setCurrentWriteChannel>("setCurrentWriteChannel");
  // void setTextModeEnabled(bool enabled)
  binder.add_void_fun<bool, &QIODevice::setTextModeEnabled>("setTextModeEnabled");
  // virtual qint64 size() const
  binder.add_fun<qint64, &QIODevice::size>("size");
  // qint64 skip(qint64 maxSize)
  binder.add_fun<qint64, qint64, &QIODevice::skip>("skip");
  // void startTransaction()
  binder.add_void_fun<&QIODevice::startTransaction>("startTransaction");
  // void ungetChar(char c)
  binder.add_void_fun<char, &QIODevice::ungetChar>("ungetChar");
  // virtual bool waitForBytesWritten(int msecs)
  binder.add_fun<bool, int, &QIODevice::waitForBytesWritten>("waitForBytesWritten");
  // virtual bool waitForReadyRead(int msecs)
  binder.add_fun<bool, int, &QIODevice::waitForReadyRead>("waitForReadyRead");
  // qint64 write(const char *data, qint64 maxSize)
  /// TODO !!!
  // qint64 write(const char *data)
  /// TODO !!!
  // qint64 write(const QByteArray &byteArray)
  binder.add_fun<qint64, const QByteArray &, &QIODevice::write>("write");
  // int writeChannelCount() const
  binder.add_fun<int, &QIODevice::writeChannelCount>("writeChannelCount");


  /* Signals */

  binding::QSignal sigs{ iodevice, &QIODevice::staticMetaObject };
  sigs.add("aboutToClose", "aboutToClose()");
  sigs.add("bytesWritten", "bytesWritten(qint64)");
  sigs.add("channelBytesWritten", "channelBytesWritten(int, qint64)");
  sigs.add("channelReadyRead", "channelReadyRead(int)");
  sigs.add("readChannelFinished", "readChannelFinished()");
  sigs.add("readyRead", "readyRead()");


  /* MetaObject resgistration */

  register_object_type(&QIODevice::staticMetaObject, Type{ iodevice.id() });
}
