// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/image.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/gui/color.h"
#include "yasl/gui/image-functions.h"
#include "yasl/gui/image.h"
#include "yasl/gui/pixelformat.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_image_invert_mode_enum(script::Class image)
{
  using namespace script;

  Enum invert_mode = image.Enum("InvertMode").setId(script::Type::QImageInvertMode).get();

  invert_mode.addValue("InvertRgb", QImage::InvertRgb);
  invert_mode.addValue("InvertRgba", QImage::InvertRgba);
}


static void register_image_format_enum(script::Class image)
{
  using namespace script;

  Enum format = image.Enum("Format").setId(script::Type::QImageFormat).get();

  format.addValue("Format_Invalid", QImage::Format_Invalid);
  format.addValue("Format_Mono", QImage::Format_Mono);
  format.addValue("Format_MonoLSB", QImage::Format_MonoLSB);
  format.addValue("Format_Indexed8", QImage::Format_Indexed8);
  format.addValue("Format_RGB32", QImage::Format_RGB32);
  format.addValue("Format_ARGB32", QImage::Format_ARGB32);
  format.addValue("Format_ARGB32_Premultiplied", QImage::Format_ARGB32_Premultiplied);
  format.addValue("Format_RGB16", QImage::Format_RGB16);
  format.addValue("Format_ARGB8565_Premultiplied", QImage::Format_ARGB8565_Premultiplied);
  format.addValue("Format_RGB666", QImage::Format_RGB666);
  format.addValue("Format_ARGB6666_Premultiplied", QImage::Format_ARGB6666_Premultiplied);
  format.addValue("Format_RGB555", QImage::Format_RGB555);
  format.addValue("Format_ARGB8555_Premultiplied", QImage::Format_ARGB8555_Premultiplied);
  format.addValue("Format_RGB888", QImage::Format_RGB888);
  format.addValue("Format_RGB444", QImage::Format_RGB444);
  format.addValue("Format_ARGB4444_Premultiplied", QImage::Format_ARGB4444_Premultiplied);
  format.addValue("Format_RGBX8888", QImage::Format_RGBX8888);
  format.addValue("Format_RGBA8888", QImage::Format_RGBA8888);
  format.addValue("Format_RGBA8888_Premultiplied", QImage::Format_RGBA8888_Premultiplied);
  format.addValue("Format_BGR30", QImage::Format_BGR30);
  format.addValue("Format_A2BGR30_Premultiplied", QImage::Format_A2BGR30_Premultiplied);
  format.addValue("Format_RGB30", QImage::Format_RGB30);
  format.addValue("Format_A2RGB30_Premultiplied", QImage::Format_A2RGB30_Premultiplied);
  format.addValue("Format_Alpha8", QImage::Format_Alpha8);
  format.addValue("Format_Grayscale8", QImage::Format_Grayscale8);
  format.addValue("NImageFormats", QImage::NImageFormats);
}


static void register_image_class(script::Namespace ns)
{
  using namespace script;

  Class image = ns.Class("Image").setId(script::Type::QImage).get();

  register_image_invert_mode_enum(image);
  register_image_format_enum(image);
  binding::Class<QImage> binder{ image };

  // QImage();
  binder.ctors().default_ctor().create();
  // QImage(const QSize &, QImage::Format);
  binder.ctors().ctor<const QSize &, QImage::Format>().create();
  // QImage(int, int, QImage::Format);
  binder.ctors().ctor<int, int, QImage::Format>().create();
  // QImage(uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// TODO: QImage(uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  // QImage(const uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// TODO: QImage(const uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  // QImage(uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// TODO: QImage(uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  // QImage(const uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// TODO: QImage(const uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  // QImage(const char *const []);
  /// TODO: QImage(const char *const []);
  // QImage(const QString &, const char *);
  /// TODO: QImage(const QString &, const char *);
  // QImage(const QImage &);
  binder.ctors().ctor<const QImage &>().create();
  // QImage(QImage &&);
  binder.ctors().ctor<QImage &&>().create();
  // ~QImage();
  binder.add_dtor();
  // QImage & operator=(const QImage &);
  binder.operators().assign<const QImage &>();
  // QImage & operator=(QImage &&);
  binder.operators().assign<QImage &&>();
  // void swap(QImage &);
  binder.void_fun<QImage &, &QImage::swap>("swap").create();
  // bool isNull() const;
  binder.fun<bool, &QImage::isNull>("isNull").create();
  // int devType() const;
  binder.fun<int, &QImage::devType>("devType").create();
  // bool operator==(const QImage &) const;
  binder.operators().eq<const QImage &>();
  // bool operator!=(const QImage &) const;
  binder.operators().neq<const QImage &>();
  // void detach();
  binder.void_fun<&QImage::detach>("detach").create();
  // bool isDetached() const;
  binder.fun<bool, &QImage::isDetached>("isDetached").create();
  // QImage copy(const QRect &) const;
  binder.fun<QImage, const QRect &, &QImage::copy>("copy")
    .apply(binding::default_arguments(QRect())).create();
  // QImage copy(int, int, int, int) const;
  binder.fun<QImage, int, int, int, int, &QImage::copy>("copy").create();
  // QImage::Format format() const;
  binder.fun<QImage::Format, &QImage::format>("format").create();
  // QImage img_convertToFormat(QImage::Format, Qt::ImageConversionFlags);
  binder.fun<QImage, QImage::Format, Qt::ImageConversionFlags, &img_convertToFormat>("convertToFormat")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // QImage convertToFormat(QImage::Format, const QVector<QRgb> &, Qt::ImageConversionFlags) const;
  /// TODO: QImage convertToFormat(QImage::Format, const QVector<QRgb> &, Qt::ImageConversionFlags) const;
  // bool reinterpretAsFormat(QImage::Format);
  binder.fun<bool, QImage::Format, &QImage::reinterpretAsFormat>("reinterpretAsFormat").create();
  // int width() const;
  binder.fun<int, &QImage::width>("width").create();
  // int height() const;
  binder.fun<int, &QImage::height>("height").create();
  // QSize size() const;
  binder.fun<QSize, &QImage::size>("size").create();
  // QRect rect() const;
  binder.fun<QRect, &QImage::rect>("rect").create();
  // int depth() const;
  binder.fun<int, &QImage::depth>("depth").create();
  // int colorCount() const;
  binder.fun<int, &QImage::colorCount>("colorCount").create();
  // int bitPlaneCount() const;
  binder.fun<int, &QImage::bitPlaneCount>("bitPlaneCount").create();
  // QRgb color(int) const;
  /// TODO: QRgb color(int) const;
  // void setColor(int, QRgb);
  /// TODO: void setColor(int, QRgb);
  // void setColorCount(int);
  binder.void_fun<int, &QImage::setColorCount>("setColorCount").create();
  // bool allGray() const;
  binder.fun<bool, &QImage::allGray>("allGray").create();
  // bool isGrayscale() const;
  binder.fun<bool, &QImage::isGrayscale>("isGrayscale").create();
  // uchar * bits();
  /// TODO: uchar * bits();
  // const uchar * bits() const;
  /// TODO: const uchar * bits() const;
  // const uchar * constBits() const;
  /// TODO: const uchar * constBits() const;
  // int byteCount() const;
  binder.fun<int, &QImage::byteCount>("byteCount").create();
  // qsizetype sizeInBytes() const;
  /// TODO: qsizetype sizeInBytes() const;
  // uchar * scanLine(int);
  /// TODO: uchar * scanLine(int);
  // const uchar * scanLine(int) const;
  /// TODO: const uchar * scanLine(int) const;
  // const uchar * constScanLine(int) const;
  /// TODO: const uchar * constScanLine(int) const;
  // int bytesPerLine() const;
  binder.fun<int, &QImage::bytesPerLine>("bytesPerLine").create();
  // bool valid(int, int) const;
  binder.fun<bool, int, int, &QImage::valid>("valid").create();
  // bool valid(const QPoint &) const;
  binder.fun<bool, const QPoint &, &QImage::valid>("valid").create();
  // int pixelIndex(int, int) const;
  binder.fun<int, int, int, &QImage::pixelIndex>("pixelIndex").create();
  // int pixelIndex(const QPoint &) const;
  binder.fun<int, const QPoint &, &QImage::pixelIndex>("pixelIndex").create();
  // QRgb pixel(int, int) const;
  /// TODO: QRgb pixel(int, int) const;
  // QRgb pixel(const QPoint &) const;
  /// TODO: QRgb pixel(const QPoint &) const;
  // void setPixel(int, int, uint);
  binder.void_fun<int, int, uint, &QImage::setPixel>("setPixel").create();
  // void setPixel(const QPoint &, uint);
  binder.void_fun<const QPoint &, uint, &QImage::setPixel>("setPixel").create();
  // QColor pixelColor(int, int) const;
  binder.fun<QColor, int, int, &QImage::pixelColor>("pixelColor").create();
  // QColor pixelColor(const QPoint &) const;
  binder.fun<QColor, const QPoint &, &QImage::pixelColor>("pixelColor").create();
  // void setPixelColor(int, int, const QColor &);
  binder.void_fun<int, int, const QColor &, &QImage::setPixelColor>("setPixelColor").create();
  // void setPixelColor(const QPoint &, const QColor &);
  binder.void_fun<const QPoint &, const QColor &, &QImage::setPixelColor>("setPixelColor").create();
  // QVector<QRgb> colorTable() const;
  /// TODO: QVector<QRgb> colorTable() const;
  // void setColorTable(const QVector<QRgb>);
  /// TODO: void setColorTable(const QVector<QRgb>);
  // qreal devicePixelRatio() const;
  binder.fun<qreal, &QImage::devicePixelRatio>("devicePixelRatio").create();
  // void setDevicePixelRatio(qreal);
  binder.void_fun<qreal, &QImage::setDevicePixelRatio>("setDevicePixelRatio").create();
  // void fill(uint);
  binder.void_fun<uint, &QImage::fill>("fill").create();
  // void fill(const QColor &);
  binder.void_fun<const QColor &, &QImage::fill>("fill").create();
  // void fill(Qt::GlobalColor);
  binder.void_fun<Qt::GlobalColor, &QImage::fill>("fill").create();
  // bool hasAlphaChannel() const;
  binder.fun<bool, &QImage::hasAlphaChannel>("hasAlphaChannel").create();
  // void setAlphaChannel(const QImage &);
  binder.void_fun<const QImage &, &QImage::setAlphaChannel>("setAlphaChannel").create();
  // QImage alphaChannel() const;
  binder.fun<QImage, &QImage::alphaChannel>("alphaChannel").create();
  // QImage createAlphaMask(Qt::ImageConversionFlags) const;
  binder.fun<QImage, Qt::ImageConversionFlags, &QImage::createAlphaMask>("createAlphaMask")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // QImage createHeuristicMask(bool) const;
  binder.fun<QImage, bool, &QImage::createHeuristicMask>("createHeuristicMask")
    .apply(binding::default_arguments(true)).create();
  // QImage createMaskFromColor(QRgb, Qt::MaskMode) const;
  /// TODO: QImage createMaskFromColor(QRgb, Qt::MaskMode) const;
  // QImage scaled(int, int, Qt::AspectRatioMode, Qt::TransformationMode) const;
  binder.fun<QImage, int, int, Qt::AspectRatioMode, Qt::TransformationMode, &QImage::scaled>("scaled")
    .apply(binding::default_arguments(Qt::FastTransformation, Qt::IgnoreAspectRatio)).create();
  // QImage scaled(const QSize &, Qt::AspectRatioMode, Qt::TransformationMode) const;
  binder.fun<QImage, const QSize &, Qt::AspectRatioMode, Qt::TransformationMode, &QImage::scaled>("scaled")
    .apply(binding::default_arguments(Qt::FastTransformation, Qt::IgnoreAspectRatio)).create();
  // QImage scaledToWidth(int, Qt::TransformationMode) const;
  binder.fun<QImage, int, Qt::TransformationMode, &QImage::scaledToWidth>("scaledToWidth")
    .apply(binding::default_arguments(Qt::FastTransformation)).create();
  // QImage scaledToHeight(int, Qt::TransformationMode) const;
  binder.fun<QImage, int, Qt::TransformationMode, &QImage::scaledToHeight>("scaledToHeight")
    .apply(binding::default_arguments(Qt::FastTransformation)).create();
  // QImage transformed(const QMatrix &, Qt::TransformationMode) const;
  /// TODO: QImage transformed(const QMatrix &, Qt::TransformationMode) const;
  // static QMatrix trueMatrix(const QMatrix &, int, int);
  /// TODO: static QMatrix trueMatrix(const QMatrix &, int, int);
  // QImage transformed(const QTransform &, Qt::TransformationMode) const;
  binder.fun<QImage, const QTransform &, Qt::TransformationMode, &QImage::transformed>("transformed")
    .apply(binding::default_arguments(Qt::FastTransformation)).create();
  // static QTransform trueMatrix(const QTransform &, int, int);
  binder.static_fun<QTransform, const QTransform &, int, int, &QImage::trueMatrix>("trueMatrix").create();
  // QImage img_mirrored(bool, bool);
  binder.fun<QImage, bool, bool, &img_mirrored>("mirrored")
    .apply(binding::default_arguments(true, false)).create();
  // QImage img_rgbSwapped();
  binder.fun<QImage, &img_rgbSwapped>("rgbSwapped").create();
  // void invertPixels(QImage::InvertMode);
  binder.void_fun<QImage::InvertMode, &QImage::invertPixels>("invertPixels")
    .apply(binding::default_arguments(QImage::InvertRgb)).create();
  // bool load(QIODevice *, const char *);
  /// TODO: bool load(QIODevice *, const char *);
  // bool load(const QString &, const char *);
  /// TODO: bool load(const QString &, const char *);
  // bool loadFromData(const uchar *, int, const char *);
  /// TODO: bool loadFromData(const uchar *, int, const char *);
  // bool loadFromData(const QByteArray &, const char *);
  /// TODO: bool loadFromData(const QByteArray &, const char *);
  // bool save(const QString &, const char *, int) const;
  /// TODO: bool save(const QString &, const char *, int) const;
  // bool save(QIODevice *, const char *, int) const;
  /// TODO: bool save(QIODevice *, const char *, int) const;
  // static QImage fromData(const uchar *, int, const char *);
  /// TODO: static QImage fromData(const uchar *, int, const char *);
  // static QImage fromData(const QByteArray &, const char *);
  /// TODO: static QImage fromData(const QByteArray &, const char *);
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // int dotsPerMeterX() const;
  binder.fun<int, &QImage::dotsPerMeterX>("dotsPerMeterX").create();
  // int dotsPerMeterY() const;
  binder.fun<int, &QImage::dotsPerMeterY>("dotsPerMeterY").create();
  // void setDotsPerMeterX(int);
  binder.void_fun<int, &QImage::setDotsPerMeterX>("setDotsPerMeterX").create();
  // void setDotsPerMeterY(int);
  binder.void_fun<int, &QImage::setDotsPerMeterY>("setDotsPerMeterY").create();
  // QPoint offset() const;
  binder.fun<QPoint, &QImage::offset>("offset").create();
  // void setOffset(const QPoint &);
  binder.void_fun<const QPoint &, &QImage::setOffset>("setOffset").create();
  // QStringList textKeys() const;
  /// TODO: QStringList textKeys() const;
  // QString text(const QString &) const;
  binder.fun<QString, const QString &, &QImage::text>("text").create();
  // void setText(const QString &, const QString &);
  binder.void_fun<const QString &, const QString &, &QImage::setText>("setText").create();
  // QPixelFormat pixelFormat() const;
  binder.fun<QPixelFormat, &QImage::pixelFormat>("pixelFormat").create();
  // static QPixelFormat toPixelFormat(QImage::Format);
  binder.static_fun<QPixelFormat, QImage::Format, &QImage::toPixelFormat>("toPixelFormat").create();
  // static QImage::Format toImageFormat(QPixelFormat);
  binder.static_fun<QImage::Format, QPixelFormat, &QImage::toImageFormat>("toImageFormat").create();
  // QImage::DataPtr & data_ptr();
  /// TODO: QImage::DataPtr & data_ptr();
}


void register_image_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_image_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QImage &, QImage &);
  binder.void_fun<QImage &, QImage &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QImage &);
  binder.operators().put_to<QDataStream &, const QImage &>();
  // QDataStream & operator>>(QDataStream &, QImage &);
  binder.operators().read_from<QDataStream &, QImage &>();
  // QDebug operator<<(QDebug, const QImage &);
  /// TODO: QDebug operator<<(QDebug, const QImage &);
}

