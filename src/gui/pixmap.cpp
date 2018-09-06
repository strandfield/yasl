// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pixmap.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/object.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/gui/bitmap.h"
#include "yasl/gui/color.h"
#include "yasl/gui/image.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>

static void register_pixmap_class(script::Namespace ns)
{
  using namespace script;

  Class pixmap = ns.Class("Pixmap").setId(script::Type::QPixmap).get();

  binding::Class<QPixmap> binder{ pixmap };

  // QPixmap();
  binder.ctors().add_default();
  // QPixmap(QPlatformPixmap *);
  /// TODO: QPixmap(QPlatformPixmap *);
  // QPixmap(int, int);
  binder.ctors().add<int, int>();
  // QPixmap(const QSize &);
  binder.ctors().add<const QSize &>();
  // QPixmap(const QString &, const char *, Qt::ImageConversionFlags);
  /// TODO: QPixmap(const QString &, const char *, Qt::ImageConversionFlags);
  // QPixmap(const char *const []);
  /// TODO: QPixmap(const char *const []);
  // QPixmap(const QPixmap &);
  binder.ctors().add<const QPixmap &>();
  // ~QPixmap();
  binder.add_dtor();
  // QPixmap & operator=(const QPixmap &);
  binder.operators().assign<const QPixmap &>();
  // QPixmap & operator=(QPixmap &&);
  binder.operators().assign<QPixmap &&>();
  // void swap(QPixmap &);
  binder.add_void_fun<QPixmap &, &QPixmap::swap>("swap");
  // bool isNull() const;
  binder.add_fun<bool, &QPixmap::isNull>("isNull");
  // int devType() const;
  binder.add_fun<int, &QPixmap::devType>("devType");
  // int width() const;
  binder.add_fun<int, &QPixmap::width>("width");
  // int height() const;
  binder.add_fun<int, &QPixmap::height>("height");
  // QSize size() const;
  binder.add_fun<QSize, &QPixmap::size>("size");
  // QRect rect() const;
  binder.add_fun<QRect, &QPixmap::rect>("rect");
  // int depth() const;
  binder.add_fun<int, &QPixmap::depth>("depth");
  // static int defaultDepth();
  binder.add_static<int, &QPixmap::defaultDepth>("defaultDepth");
  // void fill(const QColor &);
  binder.add_void_fun<const QColor &, &QPixmap::fill>("fill");
  // void fill(const QPaintDevice *, const QPoint &);
  /// TODO: void fill(const QPaintDevice *, const QPoint &);
  // void fill(const QPaintDevice *, int, int);
  /// TODO: void fill(const QPaintDevice *, int, int);
  // QBitmap mask() const;
  binder.add_fun<QBitmap, &QPixmap::mask>("mask");
  // void setMask(const QBitmap &);
  binder.add_void_fun<const QBitmap &, &QPixmap::setMask>("setMask");
  // qreal devicePixelRatio() const;
  binder.add_fun<qreal, &QPixmap::devicePixelRatio>("devicePixelRatio");
  // void setDevicePixelRatio(qreal);
  binder.add_void_fun<qreal, &QPixmap::setDevicePixelRatio>("setDevicePixelRatio");
  // bool hasAlpha() const;
  binder.add_fun<bool, &QPixmap::hasAlpha>("hasAlpha");
  // bool hasAlphaChannel() const;
  binder.add_fun<bool, &QPixmap::hasAlphaChannel>("hasAlphaChannel");
  // QBitmap createHeuristicMask(bool) const;
  binder.add_fun<QBitmap, bool, &QPixmap::createHeuristicMask>("createHeuristicMask");
  // QBitmap createMaskFromColor(const QColor &, Qt::MaskMode) const;
  binder.add_fun<QBitmap, const QColor &, Qt::MaskMode, &QPixmap::createMaskFromColor>("createMaskFromColor");
  // static QPixmap grabWindow(WId, int, int, int, int);
  /// TODO: static QPixmap grabWindow(WId, int, int, int, int);
  // static QPixmap grabWidget(QObject *, const QRect &);
  binder.add_static<QPixmap, QObject *, const QRect &, &QPixmap::grabWidget>("grabWidget");
  // static QPixmap grabWidget(QObject *, int, int, int, int);
  binder.add_static<QPixmap, QObject *, int, int, int, int, &QPixmap::grabWidget>("grabWidget");
  // QPixmap scaled(int, int, Qt::AspectRatioMode, Qt::TransformationMode) const;
  binder.add_fun<QPixmap, int, int, Qt::AspectRatioMode, Qt::TransformationMode, &QPixmap::scaled>("scaled");
  // QPixmap scaled(const QSize &, Qt::AspectRatioMode, Qt::TransformationMode) const;
  binder.add_fun<QPixmap, const QSize &, Qt::AspectRatioMode, Qt::TransformationMode, &QPixmap::scaled>("scaled");
  // QPixmap scaledToWidth(int, Qt::TransformationMode) const;
  binder.add_fun<QPixmap, int, Qt::TransformationMode, &QPixmap::scaledToWidth>("scaledToWidth");
  // QPixmap scaledToHeight(int, Qt::TransformationMode) const;
  binder.add_fun<QPixmap, int, Qt::TransformationMode, &QPixmap::scaledToHeight>("scaledToHeight");
  // QPixmap transformed(const QMatrix &, Qt::TransformationMode) const;
  /// TODO: QPixmap transformed(const QMatrix &, Qt::TransformationMode) const;
  // static QMatrix trueMatrix(const QMatrix &, int, int);
  /// TODO: static QMatrix trueMatrix(const QMatrix &, int, int);
  // QPixmap transformed(const QTransform &, Qt::TransformationMode) const;
  binder.add_fun<QPixmap, const QTransform &, Qt::TransformationMode, &QPixmap::transformed>("transformed");
  // static QTransform trueMatrix(const QTransform &, int, int);
  binder.add_static<QTransform, const QTransform &, int, int, &QPixmap::trueMatrix>("trueMatrix");
  // QImage toImage() const;
  binder.add_fun<QImage, &QPixmap::toImage>("toImage");
  // static QPixmap fromImage(const QImage &, Qt::ImageConversionFlags);
  binder.add_static<QPixmap, const QImage &, Qt::ImageConversionFlags, &QPixmap::fromImage>("fromImage");
  // static QPixmap fromImageReader(QImageReader *, Qt::ImageConversionFlags);
  /// TODO: static QPixmap fromImageReader(QImageReader *, Qt::ImageConversionFlags);
  // static QPixmap fromImage(QImage &&, Qt::ImageConversionFlags);
  binder.add_static<QPixmap, QImage &&, Qt::ImageConversionFlags, &QPixmap::fromImage>("fromImage");
  // bool load(const QString &, const char *, Qt::ImageConversionFlags);
  /// TODO: bool load(const QString &, const char *, Qt::ImageConversionFlags);
  // bool loadFromData(const uchar *, uint, const char *, Qt::ImageConversionFlags);
  /// TODO: bool loadFromData(const uchar *, uint, const char *, Qt::ImageConversionFlags);
  // bool loadFromData(const QByteArray &, const char *, Qt::ImageConversionFlags);
  /// TODO: bool loadFromData(const QByteArray &, const char *, Qt::ImageConversionFlags);
  // bool save(const QString &, const char *, int) const;
  /// TODO: bool save(const QString &, const char *, int) const;
  // bool save(QIODevice *, const char *, int) const;
  /// TODO: bool save(QIODevice *, const char *, int) const;
  // bool convertFromImage(const QImage &, Qt::ImageConversionFlags);
  binder.add_fun<bool, const QImage &, Qt::ImageConversionFlags, &QPixmap::convertFromImage>("convertFromImage");
  // QPixmap copy(int, int, int, int) const;
  binder.add_fun<QPixmap, int, int, int, int, &QPixmap::copy>("copy");
  // QPixmap copy(const QRect &) const;
  binder.add_fun<QPixmap, const QRect &, &QPixmap::copy>("copy");
  // void scroll(int, int, int, int, int, int, QRegion *);
  /// TODO: void scroll(int, int, int, int, int, int, QRegion *);
  // void scroll(int, int, const QRect &, QRegion *);
  /// TODO: void scroll(int, int, const QRect &, QRegion *);
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // bool isDetached() const;
  binder.add_fun<bool, &QPixmap::isDetached>("isDetached");
  // void detach();
  binder.add_void_fun<&QPixmap::detach>("detach");
  // bool isQBitmap() const;
  binder.add_fun<bool, &QPixmap::isQBitmap>("isQBitmap");
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // bool operator!() const;
  binder.add_fun<bool, &QPixmap::operator!>("operator!");
  // QPlatformPixmap * handle() const;
  /// TODO: QPlatformPixmap * handle() const;
  // QPixmap::DataPtr & data_ptr();
  /// TODO: QPixmap::DataPtr & data_ptr();
}


void register_pixmap_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_pixmap_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QPixmap &, QPixmap &);
  binder.add_void_fun<QPixmap &, QPixmap &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QPixmap &);
  binder.operators().put_to<QDataStream &, const QPixmap &>();
  // QDataStream & operator>>(QDataStream &, QPixmap &);
  binder.operators().read_from<QDataStream &, QPixmap &>();
  // QDebug operator<<(QDebug, const QPixmap &);
  /// TODO: QDebug operator<<(QDebug, const QPixmap &);
}

