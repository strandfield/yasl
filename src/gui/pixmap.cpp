// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pixmap.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/genericvarianthandler.h"

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

  Class pixmap = ns.newClass("Pixmap").setId(script::Type::QPixmap).get();


  // QPixmap();
  bind::default_constructor<QPixmap>(pixmap).create();
  // QPixmap(QPlatformPixmap *);
  /// TODO: QPixmap(QPlatformPixmap *);
  // QPixmap(int, int);
  bind::constructor<QPixmap, int, int>(pixmap).create();
  // QPixmap(const QSize &);
  bind::constructor<QPixmap, const QSize &>(pixmap).create();
  // QPixmap(const QString &, const char *, Qt::ImageConversionFlags);
  /// TODO: QPixmap(const QString &, const char *, Qt::ImageConversionFlags);
  // QPixmap(const QPixmap &);
  bind::constructor<QPixmap, const QPixmap &>(pixmap).create();
  // ~QPixmap();
  bind::destructor<QPixmap>(pixmap).create();
  // QPixmap & operator=(const QPixmap &);
  bind::memop_assign<QPixmap, const QPixmap &>(pixmap);
  // QPixmap & operator=(QPixmap &&);
  bind::memop_assign<QPixmap, QPixmap &&>(pixmap);
  // void swap(QPixmap &);
  bind::void_member_function<QPixmap, QPixmap &, &QPixmap::swap>(pixmap, "swap").create();
  // bool isNull() const;
  bind::member_function<QPixmap, bool, &QPixmap::isNull>(pixmap, "isNull").create();
  // int devType() const;
  bind::member_function<QPixmap, int, &QPixmap::devType>(pixmap, "devType").create();
  // int width() const;
  bind::member_function<QPixmap, int, &QPixmap::width>(pixmap, "width").create();
  // int height() const;
  bind::member_function<QPixmap, int, &QPixmap::height>(pixmap, "height").create();
  // QSize size() const;
  bind::member_function<QPixmap, QSize, &QPixmap::size>(pixmap, "size").create();
  // QRect rect() const;
  bind::member_function<QPixmap, QRect, &QPixmap::rect>(pixmap, "rect").create();
  // int depth() const;
  bind::member_function<QPixmap, int, &QPixmap::depth>(pixmap, "depth").create();
  // static int defaultDepth();
  bind::static_member_function<QPixmap, int, &QPixmap::defaultDepth>(pixmap, "defaultDepth").create();
  // void fill(const QColor & = QColor(Qt::white));
  bind::void_member_function<QPixmap, const QColor &, &QPixmap::fill>(pixmap, "fill")
    .apply(bind::default_arguments(QColor(Qt::white))).create();
  // void fill(const QPaintDevice *, const QPoint &);
  /// TODO: void fill(const QPaintDevice *, const QPoint &);
  // void fill(const QPaintDevice *, int, int);
  /// TODO: void fill(const QPaintDevice *, int, int);
  // QBitmap mask() const;
  bind::member_function<QPixmap, QBitmap, &QPixmap::mask>(pixmap, "mask").create();
  // void setMask(const QBitmap &);
  bind::void_member_function<QPixmap, const QBitmap &, &QPixmap::setMask>(pixmap, "setMask").create();
  // qreal devicePixelRatio() const;
  bind::member_function<QPixmap, qreal, &QPixmap::devicePixelRatio>(pixmap, "devicePixelRatio").create();
  // void setDevicePixelRatio(qreal);
  bind::void_member_function<QPixmap, qreal, &QPixmap::setDevicePixelRatio>(pixmap, "setDevicePixelRatio").create();
  // bool hasAlpha() const;
  bind::member_function<QPixmap, bool, &QPixmap::hasAlpha>(pixmap, "hasAlpha").create();
  // bool hasAlphaChannel() const;
  bind::member_function<QPixmap, bool, &QPixmap::hasAlphaChannel>(pixmap, "hasAlphaChannel").create();
  // QBitmap createHeuristicMask(bool = true) const;
  bind::member_function<QPixmap, QBitmap, bool, &QPixmap::createHeuristicMask>(pixmap, "createHeuristicMask")
    .apply(bind::default_arguments(true)).create();
  // QBitmap createMaskFromColor(const QColor &, Qt::MaskMode = Qt::MaskInColor) const;
  bind::member_function<QPixmap, QBitmap, const QColor &, Qt::MaskMode, &QPixmap::createMaskFromColor>(pixmap, "createMaskFromColor")
    .apply(bind::default_arguments(Qt::MaskInColor)).create();
  // static QPixmap grabWindow(WId, int, int, int, int);
  /// TODO: static QPixmap grabWindow(WId, int, int, int, int);
  // static QPixmap grabWidget(QObject *, const QRect &);
  bind::static_member_function<QPixmap, QPixmap, QObject *, const QRect &, &QPixmap::grabWidget>(pixmap, "grabWidget").create();
  // static QPixmap grabWidget(QObject *, int, int, int, int);
  bind::static_member_function<QPixmap, QPixmap, QObject *, int, int, int, int, &QPixmap::grabWidget>(pixmap, "grabWidget").create();
  // QPixmap scaled(int, int, Qt::AspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QPixmap, QPixmap, int, int, Qt::AspectRatioMode, Qt::TransformationMode, &QPixmap::scaled>(pixmap, "scaled")
    .apply(bind::default_arguments(Qt::FastTransformation, Qt::IgnoreAspectRatio)).create();
  // QPixmap scaled(const QSize &, Qt::AspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QPixmap, QPixmap, const QSize &, Qt::AspectRatioMode, Qt::TransformationMode, &QPixmap::scaled>(pixmap, "scaled")
    .apply(bind::default_arguments(Qt::FastTransformation, Qt::IgnoreAspectRatio)).create();
  // QPixmap scaledToWidth(int, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QPixmap, QPixmap, int, Qt::TransformationMode, &QPixmap::scaledToWidth>(pixmap, "scaledToWidth")
    .apply(bind::default_arguments(Qt::FastTransformation)).create();
  // QPixmap scaledToHeight(int, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QPixmap, QPixmap, int, Qt::TransformationMode, &QPixmap::scaledToHeight>(pixmap, "scaledToHeight")
    .apply(bind::default_arguments(Qt::FastTransformation)).create();
  // QPixmap transformed(const QMatrix &, Qt::TransformationMode = Qt::FastTransformation) const;
  /// TODO: QPixmap transformed(const QMatrix &, Qt::TransformationMode = Qt::FastTransformation) const;
  // static QMatrix trueMatrix(const QMatrix &, int, int);
  /// TODO: static QMatrix trueMatrix(const QMatrix &, int, int);
  // QPixmap transformed(const QTransform &, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QPixmap, QPixmap, const QTransform &, Qt::TransformationMode, &QPixmap::transformed>(pixmap, "transformed")
    .apply(bind::default_arguments(Qt::FastTransformation)).create();
  // static QTransform trueMatrix(const QTransform &, int, int);
  bind::static_member_function<QPixmap, QTransform, const QTransform &, int, int, &QPixmap::trueMatrix>(pixmap, "trueMatrix").create();
  // QImage toImage() const;
  bind::member_function<QPixmap, QImage, &QPixmap::toImage>(pixmap, "toImage").create();
  // static QPixmap fromImage(const QImage &, Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor));
  bind::static_member_function<QPixmap, QPixmap, const QImage &, Qt::ImageConversionFlags, &QPixmap::fromImage>(pixmap, "fromImage")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // static QPixmap fromImageReader(QImageReader *, Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor));
  /// TODO: static QPixmap fromImageReader(QImageReader *, Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor));
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
  // static QPixmap fromImage(QImage &&, Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor));
  bind::static_member_function<QPixmap, QPixmap, QImage &&, Qt::ImageConversionFlags, &QPixmap::fromImage>(pixmap, "fromImage")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
#endif
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
  // bool convertFromImage(const QImage &, Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor));
  bind::member_function<QPixmap, bool, const QImage &, Qt::ImageConversionFlags, &QPixmap::convertFromImage>(pixmap, "convertFromImage")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // QPixmap copy(int, int, int, int) const;
  bind::member_function<QPixmap, QPixmap, int, int, int, int, &QPixmap::copy>(pixmap, "copy").create();
  // QPixmap copy(const QRect & = QRect()) const;
  bind::member_function<QPixmap, QPixmap, const QRect &, &QPixmap::copy>(pixmap, "copy")
    .apply(bind::default_arguments(QRect())).create();
  // void scroll(int, int, int, int, int, int, QRegion *);
  /// TODO: void scroll(int, int, int, int, int, int, QRegion *);
  // void scroll(int, int, const QRect &, QRegion *);
  /// TODO: void scroll(int, int, const QRect &, QRegion *);
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // bool isDetached() const;
  bind::member_function<QPixmap, bool, &QPixmap::isDetached>(pixmap, "isDetached").create();
  // void detach();
  bind::void_member_function<QPixmap, &QPixmap::detach>(pixmap, "detach").create();
  // bool isQBitmap() const;
  bind::member_function<QPixmap, bool, &QPixmap::isQBitmap>(pixmap, "isQBitmap").create();
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // bool operator!() const;
  bind::member_function<QPixmap, bool, &QPixmap::operator!>(pixmap, "operator!").create();
  // QPlatformPixmap * handle() const;
  /// TODO: QPlatformPixmap * handle() const;
  // QPixmap::DataPtr & data_ptr();
  /// TODO: QPixmap::DataPtr & data_ptr();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QPixmap, QMetaType::QPixmap>>();
}


void register_pixmap_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_pixmap_class(ns);

  // QDataStream & operator<<(QDataStream &, const QPixmap &);
  bind::op_put_to<QDataStream &, const QPixmap &>(ns);
  // QDataStream & operator>>(QDataStream &, QPixmap &);
  bind::op_read_from<QDataStream &, QPixmap &>(ns);
  // QDebug operator<<(QDebug, const QPixmap &);
  /// TODO: QDebug operator<<(QDebug, const QPixmap &);
}
