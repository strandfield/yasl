// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/image.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

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

  Enum invert_mode = image.newEnum("InvertMode").setId(script::Type::QImageInvertMode).get();

  invert_mode.addValue("InvertRgb", QImage::InvertRgb);
  invert_mode.addValue("InvertRgba", QImage::InvertRgba);
}


static void register_image_format_enum(script::Class image)
{
  using namespace script;

  Enum format = image.newEnum("Format").setId(script::Type::QImageFormat).get();

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
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  format.addValue("Format_RGBX8888", QImage::Format_RGBX8888);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  format.addValue("Format_RGBA8888", QImage::Format_RGBA8888);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  format.addValue("Format_RGBA8888_Premultiplied", QImage::Format_RGBA8888_Premultiplied);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  format.addValue("Format_BGR30", QImage::Format_BGR30);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  format.addValue("Format_A2BGR30_Premultiplied", QImage::Format_A2BGR30_Premultiplied);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  format.addValue("Format_RGB30", QImage::Format_RGB30);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  format.addValue("Format_A2RGB30_Premultiplied", QImage::Format_A2RGB30_Premultiplied);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  format.addValue("Format_Alpha8", QImage::Format_Alpha8);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  format.addValue("Format_Grayscale8", QImage::Format_Grayscale8);
#endif
  format.addValue("NImageFormats", QImage::NImageFormats);
}


static void register_image_class(script::Namespace ns)
{
  using namespace script;

  Class image = ns.newClass("Image").setId(script::Type::QImage).get();

  register_image_invert_mode_enum(image);
  register_image_format_enum(image);

  // QImage();
  bind::default_constructor<QImage>(image).create();
  // QImage(const QSize &, QImage::Format);
  bind::constructor<QImage, const QSize &, QImage::Format>(image).create();
  // QImage(int, int, QImage::Format);
  bind::constructor<QImage, int, int, QImage::Format>(image).create();
  // QImage(uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// TODO: QImage(uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  // QImage(const uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// TODO: QImage(const uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  // QImage(uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// TODO: QImage(uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  // QImage(const uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// TODO: QImage(const uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  // QImage(const QString &, const char *);
  /// TODO: QImage(const QString &, const char *);
  // QImage(const QImage &);
  bind::constructor<QImage, const QImage &>(image).create();
  // QImage(QImage &&);
  bind::constructor<QImage, QImage &&>(image).create();
  // ~QImage();
  bind::destructor<QImage>(image).create();
  // QImage & operator=(const QImage &);
  bind::memop_assign<QImage, const QImage &>(image);
  // QImage & operator=(QImage &&);
  bind::memop_assign<QImage, QImage &&>(image);
  // void swap(QImage &);
  bind::void_member_function<QImage, QImage &, &QImage::swap>(image, "swap").create();
  // bool isNull() const;
  bind::member_function<QImage, bool, &QImage::isNull>(image, "isNull").create();
  // int devType() const;
  bind::member_function<QImage, int, &QImage::devType>(image, "devType").create();
  // bool operator==(const QImage &) const;
  bind::memop_eq<QImage, const QImage &>(image);
  // bool operator!=(const QImage &) const;
  bind::memop_neq<QImage, const QImage &>(image);
  // void detach();
  bind::void_member_function<QImage, &QImage::detach>(image, "detach").create();
  // bool isDetached() const;
  bind::member_function<QImage, bool, &QImage::isDetached>(image, "isDetached").create();
  // QImage copy(const QRect & = QRect()) const;
  bind::member_function<QImage, QImage, const QRect &, &QImage::copy>(image, "copy")
    .apply(bind::default_arguments(QRect())).create();
  // QImage copy(int, int, int, int) const;
  bind::member_function<QImage, QImage, int, int, int, int, &QImage::copy>(image, "copy").create();
  // QImage::Format format() const;
  bind::member_function<QImage, QImage::Format, &QImage::format>(image, "format").create();
  // QImage img_convertToFormat(QImage::Format, Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor));
  bind::fn_as_memfn<QImage, QImage, QImage::Format, Qt::ImageConversionFlags, &img_convertToFormat>(image, "convertToFormat")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // QImage convertToFormat(QImage::Format, const QVector<QRgb> &, Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor)) const;
  /// TODO: QImage convertToFormat(QImage::Format, const QVector<QRgb> &, Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor)) const;
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
  // bool reinterpretAsFormat(QImage::Format);
  bind::member_function<QImage, bool, QImage::Format, &QImage::reinterpretAsFormat>(image, "reinterpretAsFormat").create();
#endif
  // int width() const;
  bind::member_function<QImage, int, &QImage::width>(image, "width").create();
  // int height() const;
  bind::member_function<QImage, int, &QImage::height>(image, "height").create();
  // QSize size() const;
  bind::member_function<QImage, QSize, &QImage::size>(image, "size").create();
  // QRect rect() const;
  bind::member_function<QImage, QRect, &QImage::rect>(image, "rect").create();
  // int depth() const;
  bind::member_function<QImage, int, &QImage::depth>(image, "depth").create();
  // int colorCount() const;
  bind::member_function<QImage, int, &QImage::colorCount>(image, "colorCount").create();
  // int bitPlaneCount() const;
  bind::member_function<QImage, int, &QImage::bitPlaneCount>(image, "bitPlaneCount").create();
  // QRgb color(int) const;
  /// TODO: QRgb color(int) const;
  // void setColor(int, QRgb);
  /// TODO: void setColor(int, QRgb);
  // void setColorCount(int);
  bind::void_member_function<QImage, int, &QImage::setColorCount>(image, "setColorCount").create();
  // bool allGray() const;
  bind::member_function<QImage, bool, &QImage::allGray>(image, "allGray").create();
  // bool isGrayscale() const;
  bind::member_function<QImage, bool, &QImage::isGrayscale>(image, "isGrayscale").create();
  // uchar * bits();
  /// TODO: uchar * bits();
  // const uchar * bits() const;
  /// TODO: const uchar * bits() const;
  // const uchar * constBits() const;
  /// TODO: const uchar * constBits() const;
  // int byteCount() const;
  bind::member_function<QImage, int, &QImage::byteCount>(image, "byteCount").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // qsizetype sizeInBytes() const;
  /// TODO: qsizetype sizeInBytes() const;
#endif
  // uchar * scanLine(int);
  /// TODO: uchar * scanLine(int);
  // const uchar * scanLine(int) const;
  /// TODO: const uchar * scanLine(int) const;
  // const uchar * constScanLine(int) const;
  /// TODO: const uchar * constScanLine(int) const;
  // int bytesPerLine() const;
  bind::member_function<QImage, int, &QImage::bytesPerLine>(image, "bytesPerLine").create();
  // bool valid(int, int) const;
  bind::member_function<QImage, bool, int, int, &QImage::valid>(image, "valid").create();
  // bool valid(const QPoint &) const;
  bind::member_function<QImage, bool, const QPoint &, &QImage::valid>(image, "valid").create();
  // int pixelIndex(int, int) const;
  bind::member_function<QImage, int, int, int, &QImage::pixelIndex>(image, "pixelIndex").create();
  // int pixelIndex(const QPoint &) const;
  bind::member_function<QImage, int, const QPoint &, &QImage::pixelIndex>(image, "pixelIndex").create();
  // QRgb pixel(int, int) const;
  /// TODO: QRgb pixel(int, int) const;
  // QRgb pixel(const QPoint &) const;
  /// TODO: QRgb pixel(const QPoint &) const;
  // void setPixel(int, int, uint);
  bind::void_member_function<QImage, int, int, uint, &QImage::setPixel>(image, "setPixel").create();
  // void setPixel(const QPoint &, uint);
  bind::void_member_function<QImage, const QPoint &, uint, &QImage::setPixel>(image, "setPixel").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // QColor pixelColor(int, int) const;
  bind::member_function<QImage, QColor, int, int, &QImage::pixelColor>(image, "pixelColor").create();
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // QColor pixelColor(const QPoint &) const;
  bind::member_function<QImage, QColor, const QPoint &, &QImage::pixelColor>(image, "pixelColor").create();
#endif
  // void setPixelColor(int, int, const QColor &);
  bind::void_member_function<QImage, int, int, const QColor &, &QImage::setPixelColor>(image, "setPixelColor").create();
  // void setPixelColor(const QPoint &, const QColor &);
  bind::void_member_function<QImage, const QPoint &, const QColor &, &QImage::setPixelColor>(image, "setPixelColor").create();
  // QVector<QRgb> colorTable() const;
  /// TODO: QVector<QRgb> colorTable() const;
  // void setColorTable(const QVector<QRgb>);
  /// TODO: void setColorTable(const QVector<QRgb>);
  // qreal devicePixelRatio() const;
  bind::member_function<QImage, qreal, &QImage::devicePixelRatio>(image, "devicePixelRatio").create();
  // void setDevicePixelRatio(qreal);
  bind::void_member_function<QImage, qreal, &QImage::setDevicePixelRatio>(image, "setDevicePixelRatio").create();
  // void fill(uint);
  bind::void_member_function<QImage, uint, &QImage::fill>(image, "fill").create();
  // void fill(const QColor &);
  bind::void_member_function<QImage, const QColor &, &QImage::fill>(image, "fill").create();
  // void fill(Qt::GlobalColor);
  bind::void_member_function<QImage, Qt::GlobalColor, &QImage::fill>(image, "fill").create();
  // bool hasAlphaChannel() const;
  bind::member_function<QImage, bool, &QImage::hasAlphaChannel>(image, "hasAlphaChannel").create();
  // void setAlphaChannel(const QImage &);
  bind::void_member_function<QImage, const QImage &, &QImage::setAlphaChannel>(image, "setAlphaChannel").create();
  // QImage alphaChannel() const;
  bind::member_function<QImage, QImage, &QImage::alphaChannel>(image, "alphaChannel").create();
  // QImage createAlphaMask(Qt::ImageConversionFlags = Qt::ImageConversionFlags(Qt::AutoColor)) const;
  bind::member_function<QImage, QImage, Qt::ImageConversionFlags, &QImage::createAlphaMask>(image, "createAlphaMask")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // QImage createHeuristicMask(bool = true) const;
  bind::member_function<QImage, QImage, bool, &QImage::createHeuristicMask>(image, "createHeuristicMask")
    .apply(bind::default_arguments(true)).create();
  // QImage createMaskFromColor(QRgb, Qt::MaskMode = Qt::MaskInColor) const;
  /// TODO: QImage createMaskFromColor(QRgb, Qt::MaskMode = Qt::MaskInColor) const;
  // QImage scaled(int, int, Qt::AspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QImage, QImage, int, int, Qt::AspectRatioMode, Qt::TransformationMode, &QImage::scaled>(image, "scaled")
    .apply(bind::default_arguments(Qt::FastTransformation, Qt::IgnoreAspectRatio)).create();
  // QImage scaled(const QSize &, Qt::AspectRatioMode = Qt::IgnoreAspectRatio, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QImage, QImage, const QSize &, Qt::AspectRatioMode, Qt::TransformationMode, &QImage::scaled>(image, "scaled")
    .apply(bind::default_arguments(Qt::FastTransformation, Qt::IgnoreAspectRatio)).create();
  // QImage scaledToWidth(int, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QImage, QImage, int, Qt::TransformationMode, &QImage::scaledToWidth>(image, "scaledToWidth")
    .apply(bind::default_arguments(Qt::FastTransformation)).create();
  // QImage scaledToHeight(int, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QImage, QImage, int, Qt::TransformationMode, &QImage::scaledToHeight>(image, "scaledToHeight")
    .apply(bind::default_arguments(Qt::FastTransformation)).create();
  // QImage transformed(const QMatrix &, Qt::TransformationMode = Qt::FastTransformation) const;
  /// TODO: QImage transformed(const QMatrix &, Qt::TransformationMode = Qt::FastTransformation) const;
  // static QMatrix trueMatrix(const QMatrix &, int, int);
  /// TODO: static QMatrix trueMatrix(const QMatrix &, int, int);
  // QImage transformed(const QTransform &, Qt::TransformationMode = Qt::FastTransformation) const;
  bind::member_function<QImage, QImage, const QTransform &, Qt::TransformationMode, &QImage::transformed>(image, "transformed")
    .apply(bind::default_arguments(Qt::FastTransformation)).create();
  // static QTransform trueMatrix(const QTransform &, int, int);
  bind::static_member_function<QImage, QTransform, const QTransform &, int, int, &QImage::trueMatrix>(image, "trueMatrix").create();
  // QImage img_mirrored(bool = false, bool = true);
  bind::fn_as_memfn<QImage, QImage, bool, bool, &img_mirrored>(image, "mirrored")
    .apply(bind::default_arguments(true, false)).create();
  // QImage img_rgbSwapped();
  bind::fn_as_memfn<QImage, QImage, &img_rgbSwapped>(image, "rgbSwapped").create();
  // void invertPixels(QImage::InvertMode = QImage::InvertRgb);
  bind::void_member_function<QImage, QImage::InvertMode, &QImage::invertPixels>(image, "invertPixels")
    .apply(bind::default_arguments(QImage::InvertRgb)).create();
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
  bind::member_function<QImage, int, &QImage::dotsPerMeterX>(image, "dotsPerMeterX").create();
  // int dotsPerMeterY() const;
  bind::member_function<QImage, int, &QImage::dotsPerMeterY>(image, "dotsPerMeterY").create();
  // void setDotsPerMeterX(int);
  bind::void_member_function<QImage, int, &QImage::setDotsPerMeterX>(image, "setDotsPerMeterX").create();
  // void setDotsPerMeterY(int);
  bind::void_member_function<QImage, int, &QImage::setDotsPerMeterY>(image, "setDotsPerMeterY").create();
  // QPoint offset() const;
  bind::member_function<QImage, QPoint, &QImage::offset>(image, "offset").create();
  // void setOffset(const QPoint &);
  bind::void_member_function<QImage, const QPoint &, &QImage::setOffset>(image, "setOffset").create();
  // QStringList textKeys() const;
  /// TODO: QStringList textKeys() const;
  // QString text(const QString &) const;
  bind::member_function<QImage, QString, const QString &, &QImage::text>(image, "text").create();
  // void setText(const QString &, const QString &);
  bind::void_member_function<QImage, const QString &, const QString &, &QImage::setText>(image, "setText").create();
  // QPixelFormat pixelFormat() const;
  bind::member_function<QImage, QPixelFormat, &QImage::pixelFormat>(image, "pixelFormat").create();
  // static QPixelFormat toPixelFormat(QImage::Format);
  bind::static_member_function<QImage, QPixelFormat, QImage::Format, &QImage::toPixelFormat>(image, "toPixelFormat").create();
  // static QImage::Format toImageFormat(QPixelFormat);
  bind::static_member_function<QImage, QImage::Format, QPixelFormat, &QImage::toImageFormat>(image, "toImageFormat").create();
  // QImage::DataPtr & data_ptr();
  /// TODO: QImage::DataPtr & data_ptr();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QImage, QMetaType::QImage>>();
}


void register_image_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_image_class(ns);

  // void swap(QImage &, QImage &);
  bind::void_function<QImage &, QImage &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QImage &);
  bind::op_put_to<QDataStream &, const QImage &>(ns);
  // QDataStream & operator>>(QDataStream &, QImage &);
  bind::op_read_from<QDataStream &, QImage &>(ns);
  // QDebug operator<<(QDebug, const QImage &);
  /// TODO: QDebug operator<<(QDebug, const QImage &);
}

