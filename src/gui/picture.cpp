// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/picture.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/rect.h"
#include "yasl/gui/picture.h"

#include <script/classbuilder.h>

static void register_picture_class(script::Namespace ns)
{
  using namespace script;

  Class picture = ns.Class("Picture").setId(script::Type::QPicture).get();

  binding::Class<QPicture> binder{ picture };

  // QPicture(int);
  binder.ctors().add<int>();
  // QPicture(const QPicture &);
  binder.ctors().add<const QPicture &>();
  // ~QPicture();
  binder.add_dtor();
  // bool isNull() const;
  binder.add_fun<bool, &QPicture::isNull>("isNull");
  // int devType() const;
  binder.add_fun<int, &QPicture::devType>("devType");
  // uint size() const;
  binder.add_fun<uint, &QPicture::size>("size");
  // const char * data() const;
  /// TODO: const char * data() const;
  // void setData(const char *, uint);
  /// TODO: void setData(const char *, uint);
  // bool play(QPainter *);
  /// TODO: bool play(QPainter *);
  // bool load(QIODevice *, const char *);
  /// TODO: bool load(QIODevice *, const char *);
  // bool load(const QString &, const char *);
  /// TODO: bool load(const QString &, const char *);
  // bool save(QIODevice *, const char *);
  /// TODO: bool save(QIODevice *, const char *);
  // bool save(const QString &, const char *);
  /// TODO: bool save(const QString &, const char *);
  // QRect boundingRect() const;
  binder.add_fun<QRect, &QPicture::boundingRect>("boundingRect");
  // void setBoundingRect(const QRect &);
  binder.add_void_fun<const QRect &, &QPicture::setBoundingRect>("setBoundingRect");
  // QPicture & operator=(const QPicture &);
  binder.operators().assign<const QPicture &>();
  // QPicture & operator=(QPicture &&);
  binder.operators().assign<QPicture &&>();
  // void swap(QPicture &);
  binder.add_void_fun<QPicture &, &QPicture::swap>("swap");
  // void detach();
  binder.add_void_fun<&QPicture::detach>("detach");
  // bool isDetached() const;
  binder.add_fun<bool, &QPicture::isDetached>("isDetached");
  // static const char * pictureFormat(const QString &);
  /// TODO: static const char * pictureFormat(const QString &);
  // static QList<QByteArray> inputFormats();
  binder.add_static<QList<QByteArray>, &QPicture::inputFormats>("inputFormats");
  // static QList<QByteArray> outputFormats();
  binder.add_static<QList<QByteArray>, &QPicture::outputFormats>("outputFormats");
  // static QStringList inputFormatList();
  /// TODO: static QStringList inputFormatList();
  // static QStringList outputFormatList();
  /// TODO: static QStringList outputFormatList();
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // QPicture::DataPtr & data_ptr();
  /// TODO: QPicture::DataPtr & data_ptr();
}


static void register_picture_i_o_class(script::Namespace ns)
{
  using namespace script;

  Class picture_i_o = ns.Class("PictureIO").setId(script::Type::QPictureIO).get();

  binding::Class<QPictureIO> binder{ picture_i_o };

  // QPictureIO();
  binder.ctors().add_default();
  // QPictureIO(QIODevice *, const char *);
  /// TODO: QPictureIO(QIODevice *, const char *);
  // QPictureIO(const QString &, const char *);
  /// TODO: QPictureIO(const QString &, const char *);
  // ~QPictureIO();
  binder.add_dtor();
  // const QPicture & picture() const;
  binder.add_fun<const QPicture &, &QPictureIO::picture>("picture");
  // int status() const;
  binder.add_fun<int, &QPictureIO::status>("status");
  // const char * format() const;
  /// TODO: const char * format() const;
  // QIODevice * ioDevice() const;
  /// TODO: QIODevice * ioDevice() const;
  // QString fileName() const;
  binder.add_fun<QString, &QPictureIO::fileName>("fileName");
  // int quality() const;
  binder.add_fun<int, &QPictureIO::quality>("quality");
  // QString description() const;
  binder.add_fun<QString, &QPictureIO::description>("description");
  // const char * parameters() const;
  /// TODO: const char * parameters() const;
  // float gamma() const;
  binder.add_fun<float, &QPictureIO::gamma>("gamma");
  // void setPicture(const QPicture &);
  binder.add_void_fun<const QPicture &, &QPictureIO::setPicture>("setPicture");
  // void setStatus(int);
  binder.add_void_fun<int, &QPictureIO::setStatus>("setStatus");
  // void setFormat(const char *);
  /// TODO: void setFormat(const char *);
  // void setIODevice(QIODevice *);
  /// TODO: void setIODevice(QIODevice *);
  // void setFileName(const QString &);
  binder.add_void_fun<const QString &, &QPictureIO::setFileName>("setFileName");
  // void setQuality(int);
  binder.add_void_fun<int, &QPictureIO::setQuality>("setQuality");
  // void setDescription(const QString &);
  binder.add_void_fun<const QString &, &QPictureIO::setDescription>("setDescription");
  // void setParameters(const char *);
  /// TODO: void setParameters(const char *);
  // void setGamma(float);
  binder.add_void_fun<float, &QPictureIO::setGamma>("setGamma");
  // bool read();
  binder.add_fun<bool, &QPictureIO::read>("read");
  // bool write();
  binder.add_fun<bool, &QPictureIO::write>("write");
  // static QByteArray pictureFormat(const QString &);
  binder.add_static<QByteArray, const QString &, &QPictureIO::pictureFormat>("pictureFormat");
  // static QByteArray pictureFormat(QIODevice *);
  /// TODO: static QByteArray pictureFormat(QIODevice *);
  // static QList<QByteArray> inputFormats();
  binder.add_static<QList<QByteArray>, &QPictureIO::inputFormats>("inputFormats");
  // static QList<QByteArray> outputFormats();
  binder.add_static<QList<QByteArray>, &QPictureIO::outputFormats>("outputFormats");
  // static void defineIOHandler(const char *, const char *, const char *, picture_io_handler, picture_io_handler);
  /// TODO: static void defineIOHandler(const char *, const char *, const char *, picture_io_handler, picture_io_handler);
}


void register_picture_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_picture_class(ns);
  register_picture_i_o_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QPicture &, QPicture &);
  binder.add_void_fun<QPicture &, QPicture &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QPicture &);
  binder.operators().put_to<QDataStream &, const QPicture &>();
  // QDataStream & operator>>(QDataStream &, QPicture &);
  binder.operators().read_from<QDataStream &, QPicture &>();
}

