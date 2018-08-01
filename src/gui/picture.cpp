// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/picture.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/iodevice.h"
#include "yasl/core/rect.h"
#include "yasl/core/string.h"

#include "yasl/gui/painter.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/namespace.h>

static void register_picture_class(script::Namespace ns)
{
  using namespace script;

  Class picture = ns.Class("Picture").setId(script::Type::QPicture).get();

  binding::Class<QPicture> binder{ picture };

  // QPicture(int);
  binder.ctors().add<int>();
  // QPicture(const QPicture &);
  binder.ctors().add<const QPicture &>();
  // bool isNull() const;
  binder.add_fun<bool, &QPicture::isNull>("isNull");
  // int devType() const;
  binder.add_fun<int, &QPicture::devType>("devType");
  // uint size() const;
  binder.add_fun<uint, &QPicture::size>("size");
  // const char * data() const;
  binder.add_fun<const char *, &QPicture::data>("data");
  // void setData(const char *, uint);
  binder.add_void_fun<const char *, uint, &QPicture::setData>("setData");
  // bool play(QPainter *);
  binder.add_fun<bool, QPainter *, &QPicture::play>("play");
  // bool load(QIODevice *, const char *);
  binder.add_fun<bool, QIODevice *, const char *, &QPicture::load>("load");
  // bool load(const QString &, const char *);
  binder.add_fun<bool, const QString &, const char *, &QPicture::load>("load");
  // bool save(QIODevice *, const char *);
  binder.add_fun<bool, QIODevice *, const char *, &QPicture::save>("save");
  // bool save(const QString &, const char *);
  binder.add_fun<bool, const QString &, const char *, &QPicture::save>("save");
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
  binder.add_static<const char *, const QString &, &QPicture::pictureFormat>("pictureFormat");
  // static QList<QByteArray> inputFormats();
  binder.add_static<QList<QByteArray>, &QPicture::inputFormats>("inputFormats");
  // static QList<QByteArray> outputFormats();
  binder.add_static<QList<QByteArray>, &QPicture::outputFormats>("outputFormats");
  // static QStringList inputFormatList();
  binder.add_static<QStringList, &QPicture::inputFormatList>("inputFormatList");
  // static QStringList outputFormatList();
  binder.add_static<QStringList, &QPicture::outputFormatList>("outputFormatList");
  // QPaintEngine * paintEngine() const;
  /// ignore: binder.add_fun<QPaintEngine *, &QPicture::paintEngine>("paintEngine");
  // QPicture::DataPtr & data_ptr();
  /// ignore: binder.add_fun<QPicture::DataPtr &, &QPicture::data_ptr>("data_ptr");
}

static void register_picture_i_o_class(script::Namespace ns)
{
  using namespace script;

  Class picture_i_o = ns.Class("PictureIO").setId(script::Type::QPictureIO).get();

  binding::Class<QPictureIO> binder{ picture_i_o };

  // QPictureIO();
  binder.ctors().add_default();
  // QPictureIO(QIODevice *, const char *);
  binder.ctors().add<QIODevice *, const char *>();
  // QPictureIO(const QString &, const char *);
  binder.ctors().add<const QString &, const char *>();
  // const QPicture & picture() const;
  binder.add_fun<const QPicture &, &QPictureIO::picture>("picture");
  // int status() const;
  binder.add_fun<int, &QPictureIO::status>("status");
  // const char * format() const;
  binder.add_fun<const char *, &QPictureIO::format>("format");
  // QIODevice * ioDevice() const;
  binder.add_fun<QIODevice *, &QPictureIO::ioDevice>("ioDevice");
  // QString fileName() const;
  binder.add_fun<QString, &QPictureIO::fileName>("fileName");
  // int quality() const;
  binder.add_fun<int, &QPictureIO::quality>("quality");
  // QString description() const;
  binder.add_fun<QString, &QPictureIO::description>("description");
  // const char * parameters() const;
  binder.add_fun<const char *, &QPictureIO::parameters>("parameters");
  // float gamma() const;
  binder.add_fun<float, &QPictureIO::gamma>("gamma");
  // void setPicture(const QPicture &);
  binder.add_void_fun<const QPicture &, &QPictureIO::setPicture>("setPicture");
  // void setStatus(int);
  binder.add_void_fun<int, &QPictureIO::setStatus>("setStatus");
  // void setFormat(const char *);
  binder.add_void_fun<const char *, &QPictureIO::setFormat>("setFormat");
  // void setIODevice(QIODevice *);
  binder.add_void_fun<QIODevice *, &QPictureIO::setIODevice>("setIODevice");
  // void setFileName(const QString &);
  binder.add_void_fun<const QString &, &QPictureIO::setFileName>("setFileName");
  // void setQuality(int);
  binder.add_void_fun<int, &QPictureIO::setQuality>("setQuality");
  // void setDescription(const QString &);
  binder.add_void_fun<const QString &, &QPictureIO::setDescription>("setDescription");
  // void setParameters(const char *);
  binder.add_void_fun<const char *, &QPictureIO::setParameters>("setParameters");
  // void setGamma(float);
  binder.add_void_fun<float, &QPictureIO::setGamma>("setGamma");
  // bool read();
  binder.add_fun<bool, &QPictureIO::read>("read");
  // bool write();
  binder.add_fun<bool, &QPictureIO::write>("write");
  // static QByteArray pictureFormat(const QString &);
  binder.add_static<QByteArray, const QString &, &QPictureIO::pictureFormat>("pictureFormat");
  // static QByteArray pictureFormat(QIODevice *);
  binder.add_static<QByteArray, QIODevice *, &QPictureIO::pictureFormat>("pictureFormat");
  // static QList<QByteArray> inputFormats();
  binder.add_static<QList<QByteArray>, &QPictureIO::inputFormats>("inputFormats");
  // static QList<QByteArray> outputFormats();
  binder.add_static<QList<QByteArray>, &QPictureIO::outputFormats>("outputFormats");
  // static void defineIOHandler(const char *, const char *, const char *, picture_io_handler, picture_io_handler);
  binder.add_static_void_fun<const char *, const char *, const char *, picture_io_handler, picture_io_handler, &QPictureIO::defineIOHandler>("defineIOHandler");
}

void register_picture_file(script::Namespace root)
{
  using namespace script;

  register_picture_class(root);
  register_picture_i_o_class(root);
  binding::Namespace binder{ root };

  // void swap(QPicture &, QPicture &);
  binder.add_void_fun<QPicture &, QPicture &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QPicture &);
  binder.operators().put_to<QDataStream &, const QPicture &>();
  // QDataStream & operator>>(QDataStream &, QPicture &);
  binder.operators().read_from<QDataStream &, QPicture &>();
}

