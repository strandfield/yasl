// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/picture.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
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
  binder.ctors().ctor<int>()
    .apply(binding::default_arguments(-1)).create();
  // QPicture(const QPicture &);
  binder.ctors().ctor<const QPicture &>().create();
  // ~QPicture();
  binder.add_dtor();
  // bool isNull() const;
  binder.fun<bool, &QPicture::isNull>("isNull").create();
  // int devType() const;
  binder.fun<int, &QPicture::devType>("devType").create();
  // uint size() const;
  binder.fun<uint, &QPicture::size>("size").create();
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
  binder.fun<QRect, &QPicture::boundingRect>("boundingRect").create();
  // void setBoundingRect(const QRect &);
  binder.void_fun<const QRect &, &QPicture::setBoundingRect>("setBoundingRect").create();
  // QPicture & operator=(const QPicture &);
  binder.operators().assign<const QPicture &>();
  // QPicture & operator=(QPicture &&);
  binder.operators().assign<QPicture &&>();
  // void swap(QPicture &);
  binder.void_fun<QPicture &, &QPicture::swap>("swap").create();
  // void detach();
  binder.void_fun<&QPicture::detach>("detach").create();
  // bool isDetached() const;
  binder.fun<bool, &QPicture::isDetached>("isDetached").create();
  // static const char * pictureFormat(const QString &);
  /// TODO: static const char * pictureFormat(const QString &);
  // static QList<QByteArray> inputFormats();
  binder.static_fun<QList<QByteArray>, &QPicture::inputFormats>("inputFormats").create();
  // static QList<QByteArray> outputFormats();
  binder.static_fun<QList<QByteArray>, &QPicture::outputFormats>("outputFormats").create();
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
  binder.ctors().default_ctor().create();
  // QPictureIO(QIODevice *, const char *);
  /// TODO: QPictureIO(QIODevice *, const char *);
  // QPictureIO(const QString &, const char *);
  /// TODO: QPictureIO(const QString &, const char *);
  // ~QPictureIO();
  binder.add_dtor();
  // const QPicture & picture() const;
  binder.fun<const QPicture &, &QPictureIO::picture>("picture").create();
  // int status() const;
  binder.fun<int, &QPictureIO::status>("status").create();
  // const char * format() const;
  /// TODO: const char * format() const;
  // QIODevice * ioDevice() const;
  /// TODO: QIODevice * ioDevice() const;
  // QString fileName() const;
  binder.fun<QString, &QPictureIO::fileName>("fileName").create();
  // int quality() const;
  binder.fun<int, &QPictureIO::quality>("quality").create();
  // QString description() const;
  binder.fun<QString, &QPictureIO::description>("description").create();
  // const char * parameters() const;
  /// TODO: const char * parameters() const;
  // float gamma() const;
  binder.fun<float, &QPictureIO::gamma>("gamma").create();
  // void setPicture(const QPicture &);
  binder.void_fun<const QPicture &, &QPictureIO::setPicture>("setPicture").create();
  // void setStatus(int);
  binder.void_fun<int, &QPictureIO::setStatus>("setStatus").create();
  // void setFormat(const char *);
  /// TODO: void setFormat(const char *);
  // void setIODevice(QIODevice *);
  /// TODO: void setIODevice(QIODevice *);
  // void setFileName(const QString &);
  binder.void_fun<const QString &, &QPictureIO::setFileName>("setFileName").create();
  // void setQuality(int);
  binder.void_fun<int, &QPictureIO::setQuality>("setQuality").create();
  // void setDescription(const QString &);
  binder.void_fun<const QString &, &QPictureIO::setDescription>("setDescription").create();
  // void setParameters(const char *);
  /// TODO: void setParameters(const char *);
  // void setGamma(float);
  binder.void_fun<float, &QPictureIO::setGamma>("setGamma").create();
  // bool read();
  binder.fun<bool, &QPictureIO::read>("read").create();
  // bool write();
  binder.fun<bool, &QPictureIO::write>("write").create();
  // static QByteArray pictureFormat(const QString &);
  binder.static_fun<QByteArray, const QString &, &QPictureIO::pictureFormat>("pictureFormat").create();
  // static QByteArray pictureFormat(QIODevice *);
  /// TODO: static QByteArray pictureFormat(QIODevice *);
  // static QList<QByteArray> inputFormats();
  binder.static_fun<QList<QByteArray>, &QPictureIO::inputFormats>("inputFormats").create();
  // static QList<QByteArray> outputFormats();
  binder.static_fun<QList<QByteArray>, &QPictureIO::outputFormats>("outputFormats").create();
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
  binder.void_fun<QPicture &, QPicture &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QPicture &);
  binder.operators().put_to<QDataStream &, const QPicture &>();
  // QDataStream & operator>>(QDataStream &, QPicture &);
  binder.operators().read_from<QDataStream &, QPicture &>();
}

