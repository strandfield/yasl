// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pixmap.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
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
  binder.ctors().default_ctor().create();
  // QPixmap(QPlatformPixmap *);
  /// TODO: QPixmap(QPlatformPixmap *);
  // QPixmap(int, int);
  binder.ctors().ctor<int, int>().create();
  // QPixmap(const QSize &);
  binder.ctors().ctor<const QSize &>().create();
  // QPixmap(const QString &, const char *, Qt::ImageConversionFlags);
  /// TODO: QPixmap(const QString &, const char *, Qt::ImageConversionFlags);
  // QPixmap(const char *const []);
  /// TODO: QPixmap(const char *const []);
  // QPixmap(const QPixmap &);
  binder.ctors().ctor<const QPixmap &>().create();
  // ~QPixmap();
  binder.add_dtor();
  // QPixmap & operator=(const QPixmap &);
  binder.operators().assign<const QPixmap &>();
  // QPixmap & operator=(QPixmap &&);
  binder.operators().assign<QPixmap &&>();
  // void swap(QPixmap &);
  binder.void_fun<QPixmap &, &QPixmap::swap>("swap").create();
  // bool isNull() const;
  binder.fun<bool, &QPixmap::isNull>("isNull").create();
  // int devType() const;
  binder.fun<int, &QPixmap::devType>("devType").create();
  // int width() const;
  binder.fun<int, &QPixmap::width>("width").create();
  // int height() const;
  binder.fun<int, &QPixmap::height>("height").create();
  // QSize size() const;
  binder.fun<QSize, &QPixmap::size>("size").create();
  // QRect rect() const;
  binder.fun<QRect, &QPixmap::rect>("rect").create();
  // int depth() const;
  binder.fun<int, &QPixmap::depth>("depth").create();
  // static int defaultDepth();
  binder.static_fun<int, &QPixmap::defaultDepth>("defaultDepth").create();
  // void fill(const QColor &);
  binder.void_fun<const QColor &, &QPixmap::fill>("fill")
    .apply(binding::default_arguments(QColor(Qt::white))).create();
  // void fill(const QPaintDevice *, const QPoint &);
  /// TODO: void fill(const QPaintDevice *, const QPoint &);
  // void fill(const QPaintDevice *, int, int);
  /// TODO: void fill(const QPaintDevice *, int, int);
  // QBitmap mask() const;
  binder.fun<QBitmap, &QPixmap::mask>("mask").create();
  // void setMask(const QBitmap &);
  binder.void_fun<const QBitmap &, &QPixmap::setMask>("setMask").create();
  // qreal devicePixelRatio() const;
  binder.fun<qreal, &QPixmap::devicePixelRatio>("devicePixelRatio").create();
  // void setDevicePixelRatio(qreal);
  binder.void_fun<qreal, &QPixmap::setDevicePixelRatio>("setDevicePixelRatio").create();
  // bool hasAlpha() const;
  binder.fun<bool, &QPixmap::hasAlpha>("hasAlpha").create();
  // bool hasAlphaChannel() const;
  binder.fun<bool, &QPixmap::hasAlphaChannel>("hasAlphaChannel").create();
  // QBitmap createHeuristicMask(bool) const;
  binder.fun<QBitmap, bool, &QPixmap::createHeuristicMask>("createHeuristicMask")
    .apply(binding::default_arguments(true)).create();
  // QBitmap createMaskFromColor(const QColor &, Qt::MaskMode) const;
  binder.fun<QBitmap, const QColor &, Qt::MaskMode, &QPixmap::createMaskFromColor>("createMaskFromColor")
    .apply(binding::default_arguments(Qt::MaskInColor)).create();
  // static QPixmap grabWindow(WId, int, int, int, int);
  /// TODO: static QPixmap grabWindow(WId, int, int, int, int);
  // static QPixmap grabWidget(QObject *, const QRect &);
  binder.static_fun<QPixmap, QObject *, const QRect &, &QPixmap::grabWidget>("grabWidget").create();
  // static QPixmap grabWidget(QObject *, int, int, int, int);
  binder.static_fun<QPixmap, QObject *, int, int, int, int, &QPixmap::grabWidget>("grabWidget").create();
  // QPixmap scaled(int, int, Qt::AspectRatioMode, Qt::TransformationMode) const;
  binder.fun<QPixmap, int, int, Qt::AspectRatioMode, Qt::TransformationMode, &QPixmap::scaled>("scaled")
    .apply(binding::default_arguments(Qt::FastTransformation, Qt::IgnoreAspectRatio)).create();
  // QPixmap scaled(const QSize &, Qt::AspectRatioMode, Qt::TransformationMode) const;
  binder.fun<QPixmap, const QSize &, Qt::AspectRatioMode, Qt::TransformationMode, &QPixmap::scaled>("scaled")
    .apply(binding::default_arguments(Qt::FastTransformation, Qt::IgnoreAspectRatio)).create();
  // QPixmap scaledToWidth(int, Qt::TransformationMode) const;
  binder.fun<QPixmap, int, Qt::TransformationMode, &QPixmap::scaledToWidth>("scaledToWidth")
    .apply(binding::default_arguments(Qt::FastTransformation)).create();
  // QPixmap scaledToHeight(int, Qt::TransformationMode) const;
  binder.fun<QPixmap, int, Qt::TransformationMode, &QPixmap::scaledToHeight>("scaledToHeight")
    .apply(binding::default_arguments(Qt::FastTransformation)).create();
  // QPixmap transformed(const QMatrix &, Qt::TransformationMode) const;
  /// TODO: QPixmap transformed(const QMatrix &, Qt::TransformationMode) const;
  // static QMatrix trueMatrix(const QMatrix &, int, int);
  /// TODO: static QMatrix trueMatrix(const QMatrix &, int, int);
  // QPixmap transformed(const QTransform &, Qt::TransformationMode) const;
  binder.fun<QPixmap, const QTransform &, Qt::TransformationMode, &QPixmap::transformed>("transformed")
    .apply(binding::default_arguments(Qt::FastTransformation)).create();
  // static QTransform trueMatrix(const QTransform &, int, int);
  binder.static_fun<QTransform, const QTransform &, int, int, &QPixmap::trueMatrix>("trueMatrix").create();
  // QImage toImage() const;
  binder.fun<QImage, &QPixmap::toImage>("toImage").create();
  // static QPixmap fromImage(const QImage &, Qt::ImageConversionFlags);
  binder.static_fun<QPixmap, const QImage &, Qt::ImageConversionFlags, &QPixmap::fromImage>("fromImage")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // static QPixmap fromImageReader(QImageReader *, Qt::ImageConversionFlags);
  /// TODO: static QPixmap fromImageReader(QImageReader *, Qt::ImageConversionFlags);
  // static QPixmap fromImage(QImage &&, Qt::ImageConversionFlags);
  binder.static_fun<QPixmap, QImage &&, Qt::ImageConversionFlags, &QPixmap::fromImage>("fromImage")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
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
  binder.fun<bool, const QImage &, Qt::ImageConversionFlags, &QPixmap::convertFromImage>("convertFromImage")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // QPixmap copy(int, int, int, int) const;
  binder.fun<QPixmap, int, int, int, int, &QPixmap::copy>("copy").create();
  // QPixmap copy(const QRect &) const;
  binder.fun<QPixmap, const QRect &, &QPixmap::copy>("copy")
    .apply(binding::default_arguments(QRect())).create();
  // void scroll(int, int, int, int, int, int, QRegion *);
  /// TODO: void scroll(int, int, int, int, int, int, QRegion *);
  // void scroll(int, int, const QRect &, QRegion *);
  /// TODO: void scroll(int, int, const QRect &, QRegion *);
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // bool isDetached() const;
  binder.fun<bool, &QPixmap::isDetached>("isDetached").create();
  // void detach();
  binder.void_fun<&QPixmap::detach>("detach").create();
  // bool isQBitmap() const;
  binder.fun<bool, &QPixmap::isQBitmap>("isQBitmap").create();
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // bool operator!() const;
  binder.fun<bool, &QPixmap::operator!>("operator!").create();
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
  binder.void_fun<QPixmap &, QPixmap &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QPixmap &);
  binder.operators().put_to<QDataStream &, const QPixmap &>();
  // QDataStream & operator>>(QDataStream &, QPixmap &);
  binder.operators().read_from<QDataStream &, QPixmap &>();
  // QDebug operator<<(QDebug, const QPixmap &);
  /// TODO: QDebug operator<<(QDebug, const QPixmap &);
}

