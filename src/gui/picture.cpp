// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/picture.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/rect.h"
#include "yasl/gui/picture.h"

#include <script/classbuilder.h>

static void register_picture_class(script::Namespace ns)
{
  using namespace script;

  Class picture = ns.newClass("Picture").setId(script::Type::QPicture).get();


  // QPicture(int);
  bind::constructor<QPicture, int>(picture)
    .apply(bind::default_arguments(-1)).create();
  // QPicture(const QPicture &);
  bind::constructor<QPicture, const QPicture &>(picture).create();
  // ~QPicture();
  bind::destructor<QPicture>(picture).create();
  // bool isNull() const;
  bind::member_function<QPicture, bool, &QPicture::isNull>(picture, "isNull").create();
  // int devType() const;
  bind::member_function<QPicture, int, &QPicture::devType>(picture, "devType").create();
  // uint size() const;
  bind::member_function<QPicture, uint, &QPicture::size>(picture, "size").create();
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
  bind::member_function<QPicture, QRect, &QPicture::boundingRect>(picture, "boundingRect").create();
  // void setBoundingRect(const QRect &);
  bind::void_member_function<QPicture, const QRect &, &QPicture::setBoundingRect>(picture, "setBoundingRect").create();
  // QPicture & operator=(const QPicture &);
  bind::memop_assign<QPicture, const QPicture &>(picture);
  // QPicture & operator=(QPicture &&);
  bind::memop_assign<QPicture, QPicture &&>(picture);
  // void swap(QPicture &);
  bind::void_member_function<QPicture, QPicture &, &QPicture::swap>(picture, "swap").create();
  // void detach();
  bind::void_member_function<QPicture, &QPicture::detach>(picture, "detach").create();
  // bool isDetached() const;
  bind::member_function<QPicture, bool, &QPicture::isDetached>(picture, "isDetached").create();
  // static const char * pictureFormat(const QString &);
  /// TODO: static const char * pictureFormat(const QString &);
  // static QList<QByteArray> inputFormats();
  bind::static_member_function<QPicture, QList<QByteArray>, &QPicture::inputFormats>(picture, "inputFormats").create();
  // static QList<QByteArray> outputFormats();
  bind::static_member_function<QPicture, QList<QByteArray>, &QPicture::outputFormats>(picture, "outputFormats").create();
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

  Class picture_i_o = ns.newClass("PictureIO").setId(script::Type::QPictureIO).get();


  // QPictureIO();
  bind::default_constructor<QPictureIO>(picture_i_o).create();
  // QPictureIO(QIODevice *, const char *);
  /// TODO: QPictureIO(QIODevice *, const char *);
  // QPictureIO(const QString &, const char *);
  /// TODO: QPictureIO(const QString &, const char *);
  // ~QPictureIO();
  bind::destructor<QPictureIO>(picture_i_o).create();
  // const QPicture & picture() const;
  bind::member_function<QPictureIO, const QPicture &, &QPictureIO::picture>(picture_i_o, "picture").create();
  // int status() const;
  bind::member_function<QPictureIO, int, &QPictureIO::status>(picture_i_o, "status").create();
  // const char * format() const;
  /// TODO: const char * format() const;
  // QIODevice * ioDevice() const;
  /// TODO: QIODevice * ioDevice() const;
  // QString fileName() const;
  bind::member_function<QPictureIO, QString, &QPictureIO::fileName>(picture_i_o, "fileName").create();
  // int quality() const;
  bind::member_function<QPictureIO, int, &QPictureIO::quality>(picture_i_o, "quality").create();
  // QString description() const;
  bind::member_function<QPictureIO, QString, &QPictureIO::description>(picture_i_o, "description").create();
  // const char * parameters() const;
  /// TODO: const char * parameters() const;
  // float gamma() const;
  bind::member_function<QPictureIO, float, &QPictureIO::gamma>(picture_i_o, "gamma").create();
  // void setPicture(const QPicture &);
  bind::void_member_function<QPictureIO, const QPicture &, &QPictureIO::setPicture>(picture_i_o, "setPicture").create();
  // void setStatus(int);
  bind::void_member_function<QPictureIO, int, &QPictureIO::setStatus>(picture_i_o, "setStatus").create();
  // void setFormat(const char *);
  /// TODO: void setFormat(const char *);
  // void setIODevice(QIODevice *);
  /// TODO: void setIODevice(QIODevice *);
  // void setFileName(const QString &);
  bind::void_member_function<QPictureIO, const QString &, &QPictureIO::setFileName>(picture_i_o, "setFileName").create();
  // void setQuality(int);
  bind::void_member_function<QPictureIO, int, &QPictureIO::setQuality>(picture_i_o, "setQuality").create();
  // void setDescription(const QString &);
  bind::void_member_function<QPictureIO, const QString &, &QPictureIO::setDescription>(picture_i_o, "setDescription").create();
  // void setParameters(const char *);
  /// TODO: void setParameters(const char *);
  // void setGamma(float);
  bind::void_member_function<QPictureIO, float, &QPictureIO::setGamma>(picture_i_o, "setGamma").create();
  // bool read();
  bind::member_function<QPictureIO, bool, &QPictureIO::read>(picture_i_o, "read").create();
  // bool write();
  bind::member_function<QPictureIO, bool, &QPictureIO::write>(picture_i_o, "write").create();
  // static QByteArray pictureFormat(const QString &);
  bind::static_member_function<QPictureIO, QByteArray, const QString &, &QPictureIO::pictureFormat>(picture_i_o, "pictureFormat").create();
  // static QByteArray pictureFormat(QIODevice *);
  /// TODO: static QByteArray pictureFormat(QIODevice *);
  // static QList<QByteArray> inputFormats();
  bind::static_member_function<QPictureIO, QList<QByteArray>, &QPictureIO::inputFormats>(picture_i_o, "inputFormats").create();
  // static QList<QByteArray> outputFormats();
  bind::static_member_function<QPictureIO, QList<QByteArray>, &QPictureIO::outputFormats>(picture_i_o, "outputFormats").create();
  // static void defineIOHandler(const char *, const char *, const char *, picture_io_handler, picture_io_handler);
  /// TODO: static void defineIOHandler(const char *, const char *, const char *, picture_io_handler, picture_io_handler);
}


void register_picture_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_picture_class(ns);
  register_picture_i_o_class(ns);

  // void swap(QPicture &, QPicture &);
  bind::void_function<QPicture &, QPicture &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QPicture &);
  bind::op_put_to<QDataStream &, const QPicture &>(ns);
  // QDataStream & operator>>(QDataStream &, QPicture &);
  bind::op_read_from<QDataStream &, QPicture &>(ns);
}

