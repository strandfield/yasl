// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/image.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/bytearray.h"
#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/iodevice.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/core/string.h"

#include "yasl/gui/color.h"
#include "yasl/gui/paintdevice.h"
#include "yasl/gui/pixelformat.h"
#include "yasl/gui/rgb.h"
#include "yasl/gui/transform.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_image_format_enum(script::Class image)
{
  using namespace script;

  Enum format = image.Enum("Format").setId(script::Type::QImageFormat).get();

  format.addValue("Format_A2BGR30_Premultiplied", QImage::Format_A2BGR30_Premultiplied);
  format.addValue("Format_A2RGB30_Premultiplied", QImage::Format_A2RGB30_Premultiplied);
  format.addValue("Format_ARGB32", QImage::Format_ARGB32);
  format.addValue("Format_ARGB32_Premultiplied", QImage::Format_ARGB32_Premultiplied);
  format.addValue("Format_ARGB4444_Premultiplied", QImage::Format_ARGB4444_Premultiplied);
  format.addValue("Format_ARGB6666_Premultiplied", QImage::Format_ARGB6666_Premultiplied);
  format.addValue("Format_ARGB8555_Premultiplied", QImage::Format_ARGB8555_Premultiplied);
  format.addValue("Format_ARGB8565_Premultiplied", QImage::Format_ARGB8565_Premultiplied);
  format.addValue("Format_Alpha8", QImage::Format_Alpha8);
  format.addValue("Format_BGR30", QImage::Format_BGR30);
  format.addValue("Format_Grayscale8", QImage::Format_Grayscale8);
  format.addValue("Format_Indexed8", QImage::Format_Indexed8);
  format.addValue("Format_Invalid", QImage::Format_Invalid);
  format.addValue("Format_Mono", QImage::Format_Mono);
  format.addValue("Format_MonoLSB", QImage::Format_MonoLSB);
  format.addValue("Format_RGB16", QImage::Format_RGB16);
  format.addValue("Format_RGB30", QImage::Format_RGB30);
  format.addValue("Format_RGB32", QImage::Format_RGB32);
  format.addValue("Format_RGB444", QImage::Format_RGB444);
  format.addValue("Format_RGB555", QImage::Format_RGB555);
  format.addValue("Format_RGB666", QImage::Format_RGB666);
  format.addValue("Format_RGB888", QImage::Format_RGB888);
  format.addValue("Format_RGBA8888", QImage::Format_RGBA8888);
  format.addValue("Format_RGBA8888_Premultiplied", QImage::Format_RGBA8888_Premultiplied);
  format.addValue("Format_RGBX8888", QImage::Format_RGBX8888);
  format.addValue("NImageFormats", QImage::NImageFormats);
}

static void register_image_invert_mode_enum(script::Class image)
{
  using namespace script;

  Enum invert_mode = image.Enum("InvertMode").setId(script::Type::QImageInvertMode).get();

  invert_mode.addValue("InvertRgb", QImage::InvertRgb);
  invert_mode.addValue("InvertRgba", QImage::InvertRgba);
}

static void register_image_class(script::Namespace ns)
{
  using namespace script;

  Class image = ns.Class("Image").setId(script::Type::QImage).get();

  register_image_format_enum(image);
  register_image_invert_mode_enum(image);
  binding::Class<QImage> binder{ image };

  // ~QImage();
  binder.add_dtor();
  // QImage();
  binder.ctors().add_default();
  // QImage(const QSize &, QImage::Format);
  binder.ctors().add<const QSize &, QImage::Format>();
  // QImage(int, int, QImage::Format);
  binder.ctors().add<int, int, QImage::Format>();
  // QImage(uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// ignore: binder.ctors().add<uchar *, int, int, QImage::Format, QImageCleanupFunction, void *>();
  // QImage(const uchar *, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// ignore: binder.ctors().add<const uchar *, int, int, QImage::Format, QImageCleanupFunction, void *>();
  // QImage(uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// ignore: binder.ctors().add<uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *>();
  // QImage(const uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *);
  /// ignore: binder.ctors().add<const uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *>();
  // QImage(const char *const []);
  /// ignore: binder.ctors().add<const char *const []>();
  // QImage(const QString &, const char *);
  binder.ctors().add<const QString &>(); // the const char* is default to nullptr
  // QImage(const QImage &);
  binder.ctors().add<const QImage &>();
  // QImage(QImage &&);
  binder.ctors().add<QImage &&>();
  // QImage & operator=(const QImage &);
  binder.operators().assign<const QImage &>();
  // QImage & operator=(QImage &&);
  binder.operators().assign<QImage &&>();
  // void swap(QImage &);
  binder.add_void_fun<QImage &, &QImage::swap>("swap");
  // bool isNull() const;
  binder.add_fun<bool, &QImage::isNull>("isNull");
  // int devType() const;
  binder.add_fun<int, &QImage::devType>("devType");
  // bool operator==(const QImage &) const;
  binder.operators().eq<const QImage &>();
  // bool operator!=(const QImage &) const;
  binder.operators().neq<const QImage &>();
  // void detach();
  binder.add_void_fun<&QImage::detach>("detach");
  // bool isDetached() const;
  binder.add_fun<bool, &QImage::isDetached>("isDetached");
  // QImage copy(const QRect &) const;
  binder.add_fun<QImage, const QRect &, &QImage::copy>("copy");
  // QImage copy(int, int, int, int) const;
  binder.add_fun<QImage, int, int, int, int, &QImage::copy>("copy");
  // QImage::Format format() const;
  binder.add_fun<QImage::Format, &QImage::format>("format");
  // QImage convertToFormat(QImage::Format, Qt::ImageConversionFlags) const;
  ///binder.add_fun<QImage, QImage::Format, Qt::ImageConversionFlags, &QImage::convertToFormat>("convertToFormat");
  YASL_METHOD_2(image, "convertToFormat", QImage, QImage, convertToFormat, QImage::Format, Qt::ImageConversionFlags).setConst().create();
  // QImage convertToFormat(QImage::Format, Qt::ImageConversionFlags);
  /// ignore: binder.add_fun<QImage, QImage::Format, Qt::ImageConversionFlags, &QImage::convertToFormat>("convertToFormat");
  // QImage convertToFormat(QImage::Format, const QVector<QRgb> &, Qt::ImageConversionFlags) const;
  binder.add_fun<QImage, QImage::Format, const QVector<QRgb> &, Qt::ImageConversionFlags, &QImage::convertToFormat>("convertToFormat");
  // bool reinterpretAsFormat(QImage::Format);
  binder.add_fun<bool, QImage::Format, &QImage::reinterpretAsFormat>("reinterpretAsFormat");
  // int width() const;
  binder.add_fun<int, &QImage::width>("width");
  // int height() const;
  binder.add_fun<int, &QImage::height>("height");
  // QSize size() const;
  binder.add_fun<QSize, &QImage::size>("size");
  // QRect rect() const;
  binder.add_fun<QRect, &QImage::rect>("rect");
  // int depth() const;
  binder.add_fun<int, &QImage::depth>("depth");
  // int colorCount() const;
  binder.add_fun<int, &QImage::colorCount>("colorCount");
  // int bitPlaneCount() const;
  binder.add_fun<int, &QImage::bitPlaneCount>("bitPlaneCount");
  // QRgb color(int) const;
  binder.add_fun<QRgb, int, &QImage::color>("color");
  // void setColor(int, QRgb);
  binder.add_void_fun<int, QRgb, &QImage::setColor>("setColor");
  // void setColorCount(int);
  binder.add_void_fun<int, &QImage::setColorCount>("setColorCount");
  // bool allGray() const;
  binder.add_fun<bool, &QImage::allGray>("allGray");
  // bool isGrayscale() const;
  binder.add_fun<bool, &QImage::isGrayscale>("isGrayscale");
  // uchar * bits();
  binder.add_fun<uchar *, &QImage::bits>("bits");
  // const uchar * bits() const;
  binder.add_fun<const uchar *, &QImage::bits>("bits");
  // const uchar * constBits() const;
  binder.add_fun<const uchar *, &QImage::constBits>("constBits");
  // int byteCount() const;
  binder.add_fun<int, &QImage::byteCount>("byteCount");
  // qsizetype sizeInBytes() const;
  binder.add_fun<qsizetype, &QImage::sizeInBytes>("sizeInBytes");
  // uchar * scanLine(int);
  binder.add_fun<uchar *, int, &QImage::scanLine>("scanLine");
  // const uchar * scanLine(int) const;
  binder.add_fun<const uchar *, int, &QImage::scanLine>("scanLine");
  // const uchar * constScanLine(int) const;
  binder.add_fun<const uchar *, int, &QImage::constScanLine>("constScanLine");
  // int bytesPerLine() const;
  binder.add_fun<int, &QImage::bytesPerLine>("bytesPerLine");
  // bool valid(int, int) const;
  binder.add_fun<bool, int, int, &QImage::valid>("valid");
  // bool valid(const QPoint &) const;
  binder.add_fun<bool, const QPoint &, &QImage::valid>("valid");
  // int pixelIndex(int, int) const;
  binder.add_fun<int, int, int, &QImage::pixelIndex>("pixelIndex");
  // int pixelIndex(const QPoint &) const;
  binder.add_fun<int, const QPoint &, &QImage::pixelIndex>("pixelIndex");
  // QRgb pixel(int, int) const;
  binder.add_fun<QRgb, int, int, &QImage::pixel>("pixel");
  // QRgb pixel(const QPoint &) const;
  binder.add_fun<QRgb, const QPoint &, &QImage::pixel>("pixel");
  // void setPixel(int, int, uint);
  binder.add_void_fun<int, int, uint, &QImage::setPixel>("setPixel");
  // void setPixel(const QPoint &, uint);
  binder.add_void_fun<const QPoint &, uint, &QImage::setPixel>("setPixel");
  // QColor pixelColor(int, int) const;
  binder.add_fun<QColor, int, int, &QImage::pixelColor>("pixelColor");
  // QColor pixelColor(const QPoint &) const;
  binder.add_fun<QColor, const QPoint &, &QImage::pixelColor>("pixelColor");
  // void setPixelColor(int, int, const QColor &);
  binder.add_void_fun<int, int, const QColor &, &QImage::setPixelColor>("setPixelColor");
  // void setPixelColor(const QPoint &, const QColor &);
  binder.add_void_fun<const QPoint &, const QColor &, &QImage::setPixelColor>("setPixelColor");
  // QVector<QRgb> colorTable() const;
  binder.add_fun<QVector<QRgb>, &QImage::colorTable>("colorTable");
  // void setColorTable(const QVector<QRgb>);
  binder.add_void_fun<const QVector<QRgb>, &QImage::setColorTable>("setColorTable");
  // qreal devicePixelRatio() const;
  binder.add_fun<qreal, &QImage::devicePixelRatio>("devicePixelRatio");
  // void setDevicePixelRatio(qreal);
  binder.add_void_fun<qreal, &QImage::setDevicePixelRatio>("setDevicePixelRatio");
  // void fill(uint);
  binder.add_void_fun<uint, &QImage::fill>("fill");
  // void fill(const QColor &);
  binder.add_void_fun<const QColor &, &QImage::fill>("fill");
  // void fill(Qt::GlobalColor);
  binder.add_void_fun<Qt::GlobalColor, &QImage::fill>("fill");
  // bool hasAlphaChannel() const;
  binder.add_fun<bool, &QImage::hasAlphaChannel>("hasAlphaChannel");
  // void setAlphaChannel(const QImage &);
  binder.add_void_fun<const QImage &, &QImage::setAlphaChannel>("setAlphaChannel");
  // QImage alphaChannel() const;
  binder.add_fun<QImage, &QImage::alphaChannel>("alphaChannel");
  // QImage createAlphaMask(Qt::ImageConversionFlags) const;
  binder.add_fun<QImage, Qt::ImageConversionFlags, &QImage::createAlphaMask>("createAlphaMask");
  // QImage createHeuristicMask(bool) const;
  binder.add_fun<QImage, bool, &QImage::createHeuristicMask>("createHeuristicMask");
  // QImage createMaskFromColor(QRgb, Qt::MaskMode) const;
  binder.add_fun<QImage, QRgb, Qt::MaskMode, &QImage::createMaskFromColor>("createMaskFromColor");
  // QImage scaled(int, int, Qt::AspectRatioMode, Qt::TransformationMode) const;
  binder.add_fun<QImage, int, int, Qt::AspectRatioMode, Qt::TransformationMode, &QImage::scaled>("scaled");
  // QImage scaled(const QSize &, Qt::AspectRatioMode, Qt::TransformationMode) const;
  binder.add_fun<QImage, const QSize &, Qt::AspectRatioMode, Qt::TransformationMode, &QImage::scaled>("scaled");
  // QImage scaledToWidth(int, Qt::TransformationMode) const;
  binder.add_fun<QImage, int, Qt::TransformationMode, &QImage::scaledToWidth>("scaledToWidth");
  // QImage scaledToHeight(int, Qt::TransformationMode) const;
  binder.add_fun<QImage, int, Qt::TransformationMode, &QImage::scaledToHeight>("scaledToHeight");
  // QImage transformed(const QMatrix &, Qt::TransformationMode) const;
  /// ignore: binder.add_fun<QImage, const QMatrix &, Qt::TransformationMode, &QImage::transformed>("transformed");
  // static QMatrix trueMatrix(const QMatrix &, int, int);
  /// ignore: binder.add_static<QMatrix, const QMatrix &, int, int, &QImage::trueMatrix>("trueMatrix");
  // QImage transformed(const QTransform &, Qt::TransformationMode) const;
  binder.add_fun<QImage, const QTransform &, Qt::TransformationMode, &QImage::transformed>("transformed");
  // static QTransform trueMatrix(const QTransform &, int, int);
  binder.add_static<QTransform, const QTransform &, int, int, &QImage::trueMatrix>("trueMatrix");
  // QImage mirrored(bool, bool) const;
  /// binder.add_fun<QImage, bool, bool, &QImage::mirrored>("mirrored");
  YASL_METHOD_2(image, "mirrored", QImage, QImage, mirrored, bool, bool).setConst().create();
  // QImage && mirrored(bool, bool);
  /// ignore: binder.add_fun<QImage &&, bool, bool, &QImage::mirrored>("mirrored");
  // QImage rgbSwapped() const;
  ///binder.add_fun<QImage, &QImage::rgbSwapped>("rgbSwapped");
  YASL_METHOD_0(image, "rgbSwapped", QImage, QImage, rgbSwapped).setConst().create();
  // QImage && rgbSwapped();
  /// ignore: binder.add_fun<QImage &&, &QImage::rgbSwapped>("rgbSwapped");
  // void invertPixels(QImage::InvertMode);
  binder.add_void_fun<QImage::InvertMode, &QImage::invertPixels>("invertPixels");
  // bool load(QIODevice *, const char *);
  binder.add_fun<bool, QIODevice *, const char *, &QImage::load>("load");
  // bool load(const QString &, const char *);
  binder.add_fun<bool, const QString &, const char *, &QImage::load>("load");
  // bool loadFromData(const uchar *, int, const char *);
  binder.add_fun<bool, const uchar *, int, const char *, &QImage::loadFromData>("loadFromData");
  // bool loadFromData(const QByteArray &, const char *);
  binder.add_fun<bool, const QByteArray &, const char *, &QImage::loadFromData>("loadFromData");
  // bool save(const QString &, const char *, int) const;
  binder.add_fun<bool, const QString &, const char *, int, &QImage::save>("save");
  // bool save(QIODevice *, const char *, int) const;
  binder.add_fun<bool, QIODevice *, const char *, int, &QImage::save>("save");
  // static QImage fromData(const uchar *, int, const char *);
  binder.add_static<QImage, const uchar *, int, const char *, &QImage::fromData>("fromData");
  // static QImage fromData(const QByteArray &, const char *);
  binder.add_static<QImage, const QByteArray &, const char *, &QImage::fromData>("fromData");
  // qint64 cacheKey() const;
  binder.add_fun<qint64, &QImage::cacheKey>("cacheKey");
  // QPaintEngine * paintEngine() const;
  binder.add_fun<QPaintEngine *, &QImage::paintEngine>("paintEngine");
  // int dotsPerMeterX() const;
  binder.add_fun<int, &QImage::dotsPerMeterX>("dotsPerMeterX");
  // int dotsPerMeterY() const;
  binder.add_fun<int, &QImage::dotsPerMeterY>("dotsPerMeterY");
  // void setDotsPerMeterX(int);
  binder.add_void_fun<int, &QImage::setDotsPerMeterX>("setDotsPerMeterX");
  // void setDotsPerMeterY(int);
  binder.add_void_fun<int, &QImage::setDotsPerMeterY>("setDotsPerMeterY");
  // QPoint offset() const;
  binder.add_fun<QPoint, &QImage::offset>("offset");
  // void setOffset(const QPoint &);
  binder.add_void_fun<const QPoint &, &QImage::setOffset>("setOffset");
  // QStringList textKeys() const;
  binder.add_fun<QStringList, &QImage::textKeys>("textKeys");
  // QString text(const QString &) const;
  binder.add_fun<QString, const QString &, &QImage::text>("text");
  // void setText(const QString &, const QString &);
  binder.add_void_fun<const QString &, const QString &, &QImage::setText>("setText");
  // QPixelFormat pixelFormat() const;
  binder.add_fun<QPixelFormat, &QImage::pixelFormat>("pixelFormat");
  // static QPixelFormat toPixelFormat(QImage::Format);
  binder.add_static<QPixelFormat, QImage::Format, &QImage::toPixelFormat>("toPixelFormat");
  // static QImage::Format toImageFormat(QPixelFormat);
  binder.add_static<QImage::Format, QPixelFormat, &QImage::toImageFormat>("toImageFormat");
}

void register_image_file(script::Namespace root)
{
  using namespace script;

  register_image_class(root);
  binding::Namespace binder{ root };

  // void swap(QImage &, QImage &);
  binder.add_void_fun<QImage &, QImage &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QImage &);
  binder.operators().put_to<QDataStream &, const QImage &>();
  // QDataStream & operator>>(QDataStream &, QImage &);
  binder.operators().read_from<QDataStream &, QImage &>();
  // QDebug operator<<(QDebug, const QImage &);
  binder.operators().left_shift<QDebug, QDebug, const QImage &>();
}

