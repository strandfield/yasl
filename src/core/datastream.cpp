// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/datastream.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_data_stream_version_enum(script::Class data_stream)
{
  using namespace script;

  Enum version = data_stream.Enum("Version").setId(script::Type::QDataStreamVersion).get();

  version.addValue("Qt_1_0", QDataStream::Qt_1_0);
  version.addValue("Qt_2_0", QDataStream::Qt_2_0);
  version.addValue("Qt_2_1", QDataStream::Qt_2_1);
  version.addValue("Qt_3_0", QDataStream::Qt_3_0);
  version.addValue("Qt_3_1", QDataStream::Qt_3_1);
  version.addValue("Qt_3_3", QDataStream::Qt_3_3);
  version.addValue("Qt_4_0", QDataStream::Qt_4_0);
  version.addValue("Qt_4_1", QDataStream::Qt_4_1);
  version.addValue("Qt_4_2", QDataStream::Qt_4_2);
  version.addValue("Qt_4_3", QDataStream::Qt_4_3);
  version.addValue("Qt_4_4", QDataStream::Qt_4_4);
  version.addValue("Qt_4_5", QDataStream::Qt_4_5);
  version.addValue("Qt_4_6", QDataStream::Qt_4_6);
  version.addValue("Qt_4_7", QDataStream::Qt_4_7);
  version.addValue("Qt_4_8", QDataStream::Qt_4_8);
  version.addValue("Qt_4_9", QDataStream::Qt_4_9);
  version.addValue("Qt_5_0", QDataStream::Qt_5_0);
  version.addValue("Qt_5_1", QDataStream::Qt_5_1);
  version.addValue("Qt_5_2", QDataStream::Qt_5_2);
  version.addValue("Qt_5_3", QDataStream::Qt_5_3);
  version.addValue("Qt_5_4", QDataStream::Qt_5_4);
  version.addValue("Qt_5_5", QDataStream::Qt_5_5);
  version.addValue("Qt_5_6", QDataStream::Qt_5_6);
  version.addValue("Qt_5_7", QDataStream::Qt_5_7);
  version.addValue("Qt_5_8", QDataStream::Qt_5_8);
  version.addValue("Qt_5_9", QDataStream::Qt_5_9);
  version.addValue("Qt_5_10", QDataStream::Qt_5_10);
  version.addValue("Qt_DefaultCompiledVersion", QDataStream::Qt_DefaultCompiledVersion);
}


static void register_data_stream_byte_order_enum(script::Class data_stream)
{
  using namespace script;

  Enum byte_order = data_stream.Enum("ByteOrder").setId(script::Type::QDataStreamByteOrder).get();

  byte_order.addValue("BigEndian", QDataStream::BigEndian);
  byte_order.addValue("LittleEndian", QDataStream::LittleEndian);
}


static void register_data_stream_status_enum(script::Class data_stream)
{
  using namespace script;

  Enum status = data_stream.Enum("Status").setId(script::Type::QDataStreamStatus).get();

  status.addValue("Ok", QDataStream::Ok);
  status.addValue("ReadPastEnd", QDataStream::ReadPastEnd);
  status.addValue("ReadCorruptData", QDataStream::ReadCorruptData);
  status.addValue("WriteFailed", QDataStream::WriteFailed);
}


static void register_data_stream_floating_point_precision_enum(script::Class data_stream)
{
  using namespace script;

  Enum floating_point_precision = data_stream.Enum("FloatingPointPrecision").setId(script::Type::QDataStreamFloatingPointPrecision).get();

  floating_point_precision.addValue("SinglePrecision", QDataStream::SinglePrecision);
  floating_point_precision.addValue("DoublePrecision", QDataStream::DoublePrecision);
}


static void register_data_stream_class(script::Namespace ns)
{
  using namespace script;

  Class data_stream = ns.Class("DataStream").setId(script::Type::QDataStream).get();

  register_data_stream_version_enum(data_stream);
  register_data_stream_byte_order_enum(data_stream);
  register_data_stream_status_enum(data_stream);
  register_data_stream_floating_point_precision_enum(data_stream);
  binding::Class<QDataStream> binder{ data_stream };

  // QDataStream();
  binder.ctors().add_default();
  // QDataStream(QIODevice *);
  /// TODO: QDataStream(QIODevice *);
  // QDataStream(QByteArray *, QIODevice::OpenMode);
  /// TODO: QDataStream(QByteArray *, QIODevice::OpenMode);
  // QDataStream(const QByteArray &);
  binder.ctors().ctor<const QByteArray &>().create();
  // ~QDataStream();
  binder.add_dtor();
  // QIODevice * device() const;
  /// TODO: QIODevice * device() const;
  // void setDevice(QIODevice *);
  /// TODO: void setDevice(QIODevice *);
  // void unsetDevice();
  binder.void_fun<&QDataStream::unsetDevice>("unsetDevice").create();
  // bool atEnd() const;
  binder.fun<bool, &QDataStream::atEnd>("atEnd").create();
  // QDataStream::Status status() const;
  binder.fun<QDataStream::Status, &QDataStream::status>("status").create();
  // void setStatus(QDataStream::Status);
  binder.void_fun<QDataStream::Status, &QDataStream::setStatus>("setStatus").create();
  // void resetStatus();
  binder.void_fun<&QDataStream::resetStatus>("resetStatus").create();
  // QDataStream::FloatingPointPrecision floatingPointPrecision() const;
  binder.fun<QDataStream::FloatingPointPrecision, &QDataStream::floatingPointPrecision>("floatingPointPrecision").create();
  // void setFloatingPointPrecision(QDataStream::FloatingPointPrecision);
  binder.void_fun<QDataStream::FloatingPointPrecision, &QDataStream::setFloatingPointPrecision>("setFloatingPointPrecision").create();
  // QDataStream::ByteOrder byteOrder() const;
  binder.fun<QDataStream::ByteOrder, &QDataStream::byteOrder>("byteOrder").create();
  // void setByteOrder(QDataStream::ByteOrder);
  binder.void_fun<QDataStream::ByteOrder, &QDataStream::setByteOrder>("setByteOrder").create();
  // int version() const;
  binder.fun<int, &QDataStream::version>("version").create();
  // void setVersion(int);
  binder.void_fun<int, &QDataStream::setVersion>("setVersion").create();
  // QDataStream & operator>>(qint8 &);
  /// TODO: QDataStream & operator>>(qint8 &);
  // QDataStream & operator>>(quint8 &);
  /// TODO: QDataStream & operator>>(quint8 &);
  // QDataStream & operator>>(qint16 &);
  /// TODO: QDataStream & operator>>(qint16 &);
  // QDataStream & operator>>(quint16 &);
  /// TODO: QDataStream & operator>>(quint16 &);
  // QDataStream & operator>>(qint32 &);
  /// TODO: QDataStream & operator>>(qint32 &);
  // QDataStream & operator>>(quint32 &);
  /// TODO: QDataStream & operator>>(quint32 &);
  // QDataStream & operator>>(qint64 &);
  /// TODO: QDataStream & operator>>(qint64 &);
  // QDataStream & operator>>(quint64 &);
  /// TODO: QDataStream & operator>>(quint64 &);
  // QDataStream & operator>>(std::nullptr_t &);
  /// TODO: QDataStream & operator>>(std::nullptr_t &);
  // QDataStream & operator>>(bool &);
  binder.operators().read_from<bool &>();
  // QDataStream & operator>>(qfloat16 &);
  /// TODO: QDataStream & operator>>(qfloat16 &);
  // QDataStream & operator>>(float &);
  binder.operators().read_from<float &>();
  // QDataStream & operator>>(double &);
  binder.operators().read_from<double &>();
  // QDataStream & operator>>(char *&);
  /// TODO: QDataStream & operator>>(char *&);
  // QDataStream & operator<<(qint8);
  /// TODO: QDataStream & operator<<(qint8);
  // QDataStream & operator<<(quint8);
  /// TODO: QDataStream & operator<<(quint8);
  // QDataStream & operator<<(qint16);
  /// TODO: QDataStream & operator<<(qint16);
  // QDataStream & operator<<(quint16);
  /// TODO: QDataStream & operator<<(quint16);
  // QDataStream & operator<<(qint32);
  /// TODO: QDataStream & operator<<(qint32);
  // QDataStream & operator<<(quint32);
  /// TODO: QDataStream & operator<<(quint32);
  // QDataStream & operator<<(qint64);
  /// TODO: QDataStream & operator<<(qint64);
  // QDataStream & operator<<(quint64);
  /// TODO: QDataStream & operator<<(quint64);
  // QDataStream & operator<<(std::nullptr_t);
  /// TODO: QDataStream & operator<<(std::nullptr_t);
  // QDataStream & operator<<(bool);
  binder.operators().put_to<bool>();
  // QDataStream & operator<<(qfloat16);
  /// TODO: QDataStream & operator<<(qfloat16);
  // QDataStream & operator<<(float);
  binder.operators().put_to<float>();
  // QDataStream & operator<<(double);
  binder.operators().put_to<double>();
  // QDataStream & operator<<(const char *);
  /// TODO: QDataStream & operator<<(const char *);
  // QDataStream & readBytes(char *&, uint &);
  /// TODO: QDataStream & readBytes(char *&, uint &);
  // int readRawData(char *, int);
  /// TODO: int readRawData(char *, int);
  // QDataStream & writeBytes(const char *, uint);
  /// TODO: QDataStream & writeBytes(const char *, uint);
  // int writeRawData(const char *, int);
  /// TODO: int writeRawData(const char *, int);
  // int skipRawData(int);
  binder.fun<int, int, &QDataStream::skipRawData>("skipRawData").create();
  // void startTransaction();
  binder.void_fun<&QDataStream::startTransaction>("startTransaction").create();
  // bool commitTransaction();
  binder.fun<bool, &QDataStream::commitTransaction>("commitTransaction").create();
  // void rollbackTransaction();
  binder.void_fun<&QDataStream::rollbackTransaction>("rollbackTransaction").create();
  // void abortTransaction();
  binder.void_fun<&QDataStream::abortTransaction>("abortTransaction").create();
}


void register_datastream_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_data_stream_class(ns);
  binding::Namespace binder{ ns };

}

