// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/datastream.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_data_stream_version_enum(script::Class data_stream)
{
  using namespace script;

  Enum version = data_stream.newEnum("Version").setId(script::Type::QDataStreamVersion).get();

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
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
  version.addValue("Qt_5_1", QDataStream::Qt_5_1);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  version.addValue("Qt_5_2", QDataStream::Qt_5_2);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  version.addValue("Qt_5_3", QDataStream::Qt_5_3);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  version.addValue("Qt_5_4", QDataStream::Qt_5_4);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  version.addValue("Qt_5_5", QDataStream::Qt_5_5);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  version.addValue("Qt_5_6", QDataStream::Qt_5_6);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  version.addValue("Qt_5_7", QDataStream::Qt_5_7);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  version.addValue("Qt_5_8", QDataStream::Qt_5_8);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
  version.addValue("Qt_5_9", QDataStream::Qt_5_9);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  version.addValue("Qt_5_10", QDataStream::Qt_5_10);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  version.addValue("Qt_DefaultCompiledVersion", QDataStream::Qt_DefaultCompiledVersion);
#endif
}


static void register_data_stream_byte_order_enum(script::Class data_stream)
{
  using namespace script;

  Enum byte_order = data_stream.newEnum("ByteOrder").setId(script::Type::QDataStreamByteOrder).get();

  byte_order.addValue("BigEndian", QDataStream::BigEndian);
  byte_order.addValue("LittleEndian", QDataStream::LittleEndian);
}


static void register_data_stream_status_enum(script::Class data_stream)
{
  using namespace script;

  Enum status = data_stream.newEnum("Status").setId(script::Type::QDataStreamStatus).get();

  status.addValue("Ok", QDataStream::Ok);
  status.addValue("ReadPastEnd", QDataStream::ReadPastEnd);
  status.addValue("ReadCorruptData", QDataStream::ReadCorruptData);
  status.addValue("WriteFailed", QDataStream::WriteFailed);
}


static void register_data_stream_floating_point_precision_enum(script::Class data_stream)
{
  using namespace script;

  Enum floating_point_precision = data_stream.newEnum("FloatingPointPrecision").setId(script::Type::QDataStreamFloatingPointPrecision).get();

  floating_point_precision.addValue("SinglePrecision", QDataStream::SinglePrecision);
  floating_point_precision.addValue("DoublePrecision", QDataStream::DoublePrecision);
}


static void register_data_stream_class(script::Namespace ns)
{
  using namespace script;

  Class data_stream = ns.newClass("DataStream").setId(script::Type::QDataStream).get();

  register_data_stream_version_enum(data_stream);
  register_data_stream_byte_order_enum(data_stream);
  register_data_stream_status_enum(data_stream);
  register_data_stream_floating_point_precision_enum(data_stream);

  // QDataStream();
  bind::default_constructor<QDataStream>(data_stream).create();
  // QDataStream(QIODevice *);
  /// TODO: QDataStream(QIODevice *);
  // QDataStream(QByteArray *, QIODevice::OpenMode);
  /// TODO: QDataStream(QByteArray *, QIODevice::OpenMode);
  // QDataStream(const QByteArray &);
  bind::constructor<QDataStream, const QByteArray &>(data_stream).create();
  // ~QDataStream();
  bind::destructor<QDataStream>(data_stream).create();
  // QIODevice * device() const;
  /// TODO: QIODevice * device() const;
  // void setDevice(QIODevice *);
  /// TODO: void setDevice(QIODevice *);
  // void unsetDevice();
  bind::void_member_function<QDataStream, &QDataStream::unsetDevice>(data_stream, "unsetDevice").create();
  // bool atEnd() const;
  bind::member_function<QDataStream, bool, &QDataStream::atEnd>(data_stream, "atEnd").create();
  // QDataStream::Status status() const;
  bind::member_function<QDataStream, QDataStream::Status, &QDataStream::status>(data_stream, "status").create();
  // void setStatus(QDataStream::Status);
  bind::void_member_function<QDataStream, QDataStream::Status, &QDataStream::setStatus>(data_stream, "setStatus").create();
  // void resetStatus();
  bind::void_member_function<QDataStream, &QDataStream::resetStatus>(data_stream, "resetStatus").create();
  // QDataStream::FloatingPointPrecision floatingPointPrecision() const;
  bind::member_function<QDataStream, QDataStream::FloatingPointPrecision, &QDataStream::floatingPointPrecision>(data_stream, "floatingPointPrecision").create();
  // void setFloatingPointPrecision(QDataStream::FloatingPointPrecision);
  bind::void_member_function<QDataStream, QDataStream::FloatingPointPrecision, &QDataStream::setFloatingPointPrecision>(data_stream, "setFloatingPointPrecision").create();
  // QDataStream::ByteOrder byteOrder() const;
  bind::member_function<QDataStream, QDataStream::ByteOrder, &QDataStream::byteOrder>(data_stream, "byteOrder").create();
  // void setByteOrder(QDataStream::ByteOrder);
  bind::void_member_function<QDataStream, QDataStream::ByteOrder, &QDataStream::setByteOrder>(data_stream, "setByteOrder").create();
  // int version() const;
  bind::member_function<QDataStream, int, &QDataStream::version>(data_stream, "version").create();
  // void setVersion(int);
  bind::void_member_function<QDataStream, int, &QDataStream::setVersion>(data_stream, "setVersion").create();
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
  bind::memop_read_from<QDataStream, bool &>(data_stream);
  // QDataStream & operator>>(qfloat16 &);
  /// TODO: QDataStream & operator>>(qfloat16 &);
  // QDataStream & operator>>(float &);
  bind::memop_read_from<QDataStream, float &>(data_stream);
  // QDataStream & operator>>(double &);
  bind::memop_read_from<QDataStream, double &>(data_stream);
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
  bind::memop_put_to<QDataStream, bool>(data_stream);
  // QDataStream & operator<<(qfloat16);
  /// TODO: QDataStream & operator<<(qfloat16);
  // QDataStream & operator<<(float);
  bind::memop_put_to<QDataStream, float>(data_stream);
  // QDataStream & operator<<(double);
  bind::memop_put_to<QDataStream, double>(data_stream);
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
  bind::member_function<QDataStream, int, int, &QDataStream::skipRawData>(data_stream, "skipRawData").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // void startTransaction();
  bind::void_member_function<QDataStream, &QDataStream::startTransaction>(data_stream, "startTransaction").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // bool commitTransaction();
  bind::member_function<QDataStream, bool, &QDataStream::commitTransaction>(data_stream, "commitTransaction").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // void rollbackTransaction();
  bind::void_member_function<QDataStream, &QDataStream::rollbackTransaction>(data_stream, "rollbackTransaction").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 7, 0))
  // void abortTransaction();
  bind::void_member_function<QDataStream, &QDataStream::abortTransaction>(data_stream, "abortTransaction").create();
#endif
}


void register_datastream_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_data_stream_class(ns);

}

