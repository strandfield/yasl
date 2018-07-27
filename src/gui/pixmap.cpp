// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pixmap.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/enums.h"
#include "yasl/core/iodevice.h"
#include "yasl/core/object.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"

#include "yasl/gui/bitmap.h"
#include "yasl/gui/color.h"
#include "yasl/gui/image.h"
#include "yasl/gui/imagereader.h"
#include "yasl/gui/paintdevice.h"
#include "yasl/gui/region.h"
#include "yasl/gui/transform.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_pixmap_class(script::Namespace ns)
{
  using namespace script;

  Class pixmap = ns.Class("Pixmap").setId(script::Type::QPixmap).get();

  binding::Class<QPixmap> binder{ pixmap };

  // ~QPixmap();
  binder.add_dtor();
  // QPixmap();
  binder.ctors().add_default();
  // QPixmap(QPlatformPixmap *);
  /// ignore: binder.ctors().add<QPlatformPixmap *>();
  // QPixmap(int, int);
  binder.ctors().add<int, int>();
  // QPixmap(const QSize &);
  binder.ctors().add<const QSize &>();
  // QPixmap(const QString &, const char *, Qt::ImageConversionFlags);
  binder.ctors().add<const QString &, const char *, Qt::ImageConversionFlags>();
  // QPixmap(const char *const []);
  /// ignore: binder.ctors().add<const char *const []>();
  // QPixmap(const QPixmap &);
  binder.ctors().add<const QPixmap &>();
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
  binder.add_void_fun<const QPaintDevice *, const QPoint &, &QPixmap::fill>("fill");
  // void fill(const QPaintDevice *, int, int);
  binder.add_void_fun<const QPaintDevice *, int, int, &QPixmap::fill>("fill");
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
  binder.add_static<QPixmap, WId, int, int, int, int, &QPixmap::grabWindow>("grabWindow");
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
  binder.add_fun<QPixmap, const QMatrix &, Qt::TransformationMode, &QPixmap::transformed>("transformed");
  // static QMatrix trueMatrix(const QMatrix &, int, int);
  /// ignore: binder.add_static<QMatrix, const QMatrix &, int, int, &QPixmap::trueMatrix>("trueMatrix");
  // QPixmap transformed(const QTransform &, Qt::TransformationMode) const;
  binder.add_fun<QPixmap, const QTransform &, Qt::TransformationMode, &QPixmap::transformed>("transformed");
  // static QTransform trueMatrix(const QTransform &, int, int);
  binder.add_static<QTransform, const QTransform &, int, int, &QPixmap::trueMatrix>("trueMatrix");
  // QImage toImage() const;
  binder.add_fun<QImage, &QPixmap::toImage>("toImage");
  // static QPixmap fromImage(const QImage &, Qt::ImageConversionFlags);
  binder.add_static<QPixmap, const QImage &, Qt::ImageConversionFlags, &QPixmap::fromImage>("fromImage");
  // static QPixmap fromImageReader(QImageReader *, Qt::ImageConversionFlags);
  binder.add_static<QPixmap, QImageReader *, Qt::ImageConversionFlags, &QPixmap::fromImageReader>("fromImageReader");
  // static QPixmap fromImage(QImage &&, Qt::ImageConversionFlags);
  binder.add_static<QPixmap, QImage &&, Qt::ImageConversionFlags, &QPixmap::fromImage>("fromImage");
  // bool load(const QString &, const char *, Qt::ImageConversionFlags);
  binder.add_fun<bool, const QString &, const char *, Qt::ImageConversionFlags, &QPixmap::load>("load");
  // bool loadFromData(const uchar *, uint, const char *, Qt::ImageConversionFlags);
  /// ignore: binder.add_fun<bool, const uchar *, uint, const char *, Qt::ImageConversionFlags, &QPixmap::loadFromData>("loadFromData");
  // bool loadFromData(const QByteArray &, const char *, Qt::ImageConversionFlags);
  binder.add_fun<bool, const QByteArray &, const char *, Qt::ImageConversionFlags, &QPixmap::loadFromData>("loadFromData");
  // bool save(const QString &, const char *, int) const;
  binder.add_fun<bool, const QString &, const char *, int, &QPixmap::save>("save");
  // bool save(QIODevice *, const char *, int) const;
  binder.add_fun<bool, QIODevice *, const char *, int, &QPixmap::save>("save");
  // bool convertFromImage(const QImage &, Qt::ImageConversionFlags);
  binder.add_fun<bool, const QImage &, Qt::ImageConversionFlags, &QPixmap::convertFromImage>("convertFromImage");
  // QPixmap copy(int, int, int, int) const;
  binder.add_fun<QPixmap, int, int, int, int, &QPixmap::copy>("copy");
  // QPixmap copy(const QRect &) const;
  binder.add_fun<QPixmap, const QRect &, &QPixmap::copy>("copy");
  // void scroll(int, int, int, int, int, int, QRegion *);
  /// TODO: binder.add_void_fun<int, int, int, int, int, int, QRegion *, &QPixmap::scroll>("scroll");
  // void scroll(int, int, const QRect &, QRegion *);
  binder.add_void_fun<int, int, const QRect &, QRegion *, &QPixmap::scroll>("scroll");
  // qint64 cacheKey() const;
  binder.add_fun<qint64, &QPixmap::cacheKey>("cacheKey");
  // bool isDetached() const;
  binder.add_fun<bool, &QPixmap::isDetached>("isDetached");
  // void detach();
  binder.add_void_fun<&QPixmap::detach>("detach");
  // bool isQBitmap() const;
  binder.add_fun<bool, &QPixmap::isQBitmap>("isQBitmap");
  // QPaintEngine * paintEngine() const;
  binder.add_fun<QPaintEngine *, &QPixmap::paintEngine>("paintEngine");
  // bool operator!() const;
  binder.operators().logical_not<bool>();
}

void register_pixmap_file(script::Namespace root)
{
  using namespace script;

  register_pixmap_class(root);
  binding::Namespace binder{ root };

  // void swap(QPixmap &, QPixmap &);
  binder.add_void_fun<QPixmap &, QPixmap &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QPixmap &);
  binder.operators().put_to<QDataStream &, const QPixmap &>();
  // QDataStream & operator>>(QDataStream &, QPixmap &);
  binder.operators().read_from<QDataStream &, QPixmap &>();
  // QDebug operator<<(QDebug, const QPixmap &);
  binder.operators().left_shift<QDebug, QDebug, const QPixmap &>();
}

