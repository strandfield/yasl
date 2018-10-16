// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/color.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/gui/color.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_color_spec_enum(script::Class color)
{
  using namespace script;

  Enum spec = color.Enum("Spec").setId(script::Type::QColorSpec).get();

  spec.addValue("Invalid", QColor::Invalid);
  spec.addValue("Rgb", QColor::Rgb);
  spec.addValue("Hsv", QColor::Hsv);
  spec.addValue("Cmyk", QColor::Cmyk);
  spec.addValue("Hsl", QColor::Hsl);
}


static void register_color_name_format_enum(script::Class color)
{
  using namespace script;

  Enum name_format = color.Enum("NameFormat").setId(script::Type::QColorNameFormat).get();

  name_format.addValue("HexRgb", QColor::HexRgb);
  name_format.addValue("HexArgb", QColor::HexArgb);
}


static void register_color_class(script::Namespace ns)
{
  using namespace script;

  Class color = ns.Class("Color").setId(script::Type::QColor).get();

  register_color_spec_enum(color);
  register_color_name_format_enum(color);
  binding::Class<QColor> binder{ color };

  // QColor();
  binder.ctors().add_default();
  // ~QColor();
  binder.add_dtor();
  // QColor(Qt::GlobalColor);
  binder.ctors().ctor<Qt::GlobalColor>().create();
  // QColor(int, int, int, int);
  binder.ctors().ctor<int, int, int, int>().create();
  // QColor(QRgb);
  /// TODO: QColor(QRgb);
  // QColor(QRgba64);
  /// TODO: QColor(QRgba64);
  // QColor(const QString &);
  binder.ctors().ctor<const QString &>().create();
  // QColor(QStringView);
  /// TODO: QColor(QStringView);
  // QColor(const char *);
  /// TODO: QColor(const char *);
  // QColor(QLatin1String);
  /// TODO: QColor(QLatin1String);
  // QColor(QColor::Spec);
  binder.ctors().ctor<QColor::Spec>().create();
  // QColor(const QColor &);
  binder.ctors().ctor<const QColor &>().create();
  // QColor(QColor &&);
  binder.ctors().ctor<QColor &&>().create();
  // QColor & operator=(QColor &&);
  binder.operators().assign<QColor &&>();
  // QColor & operator=(const QColor &);
  binder.operators().assign<const QColor &>();
  // QColor & operator=(Qt::GlobalColor);
  binder.operators().assign<Qt::GlobalColor>();
  // bool isValid() const;
  binder.fun<bool, &QColor::isValid>("isValid").create();
  // QString name() const;
  binder.fun<QString, &QColor::name>("name").create();
  // QString name(QColor::NameFormat) const;
  binder.fun<QString, QColor::NameFormat, &QColor::name>("name").create();
  // void setNamedColor(const QString &);
  binder.void_fun<const QString &, &QColor::setNamedColor>("setNamedColor").create();
  // void setNamedColor(QStringView);
  /// TODO: void setNamedColor(QStringView);
  // void setNamedColor(QLatin1String);
  /// TODO: void setNamedColor(QLatin1String);
  // static QStringList colorNames();
  /// TODO: static QStringList colorNames();
  // QColor::Spec spec() const;
  binder.fun<QColor::Spec, &QColor::spec>("spec").create();
  // int alpha() const;
  binder.fun<int, &QColor::alpha>("alpha").create();
  // void setAlpha(int);
  binder.void_fun<int, &QColor::setAlpha>("setAlpha").create();
  // qreal alphaF() const;
  binder.fun<qreal, &QColor::alphaF>("alphaF").create();
  // void setAlphaF(qreal);
  binder.void_fun<qreal, &QColor::setAlphaF>("setAlphaF").create();
  // int red() const;
  binder.fun<int, &QColor::red>("red").create();
  // int green() const;
  binder.fun<int, &QColor::green>("green").create();
  // int blue() const;
  binder.fun<int, &QColor::blue>("blue").create();
  // void setRed(int);
  binder.void_fun<int, &QColor::setRed>("setRed").create();
  // void setGreen(int);
  binder.void_fun<int, &QColor::setGreen>("setGreen").create();
  // void setBlue(int);
  binder.void_fun<int, &QColor::setBlue>("setBlue").create();
  // qreal redF() const;
  binder.fun<qreal, &QColor::redF>("redF").create();
  // qreal greenF() const;
  binder.fun<qreal, &QColor::greenF>("greenF").create();
  // qreal blueF() const;
  binder.fun<qreal, &QColor::blueF>("blueF").create();
  // void setRedF(qreal);
  binder.void_fun<qreal, &QColor::setRedF>("setRedF").create();
  // void setGreenF(qreal);
  binder.void_fun<qreal, &QColor::setGreenF>("setGreenF").create();
  // void setBlueF(qreal);
  binder.void_fun<qreal, &QColor::setBlueF>("setBlueF").create();
  // void getRgb(int *, int *, int *, int *) const;
  /// TODO: void getRgb(int *, int *, int *, int *) const;
  // void setRgb(int, int, int, int);
  binder.void_fun<int, int, int, int, &QColor::setRgb>("setRgb").create();
  // void getRgbF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getRgbF(qreal *, qreal *, qreal *, qreal *) const;
  // void setRgbF(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QColor::setRgbF>("setRgbF").create();
  // QRgba64 rgba64() const;
  /// TODO: QRgba64 rgba64() const;
  // void setRgba64(QRgba64);
  /// TODO: void setRgba64(QRgba64);
  // QRgb rgba() const;
  /// TODO: QRgb rgba() const;
  // void setRgba(QRgb);
  /// TODO: void setRgba(QRgb);
  // QRgb rgb() const;
  /// TODO: QRgb rgb() const;
  // void setRgb(QRgb);
  /// TODO: void setRgb(QRgb);
  // int hue() const;
  binder.fun<int, &QColor::hue>("hue").create();
  // int saturation() const;
  binder.fun<int, &QColor::saturation>("saturation").create();
  // int hsvHue() const;
  binder.fun<int, &QColor::hsvHue>("hsvHue").create();
  // int hsvSaturation() const;
  binder.fun<int, &QColor::hsvSaturation>("hsvSaturation").create();
  // int value() const;
  binder.fun<int, &QColor::value>("value").create();
  // qreal hueF() const;
  binder.fun<qreal, &QColor::hueF>("hueF").create();
  // qreal saturationF() const;
  binder.fun<qreal, &QColor::saturationF>("saturationF").create();
  // qreal hsvHueF() const;
  binder.fun<qreal, &QColor::hsvHueF>("hsvHueF").create();
  // qreal hsvSaturationF() const;
  binder.fun<qreal, &QColor::hsvSaturationF>("hsvSaturationF").create();
  // qreal valueF() const;
  binder.fun<qreal, &QColor::valueF>("valueF").create();
  // void getHsv(int *, int *, int *, int *) const;
  /// TODO: void getHsv(int *, int *, int *, int *) const;
  // void setHsv(int, int, int, int);
  binder.void_fun<int, int, int, int, &QColor::setHsv>("setHsv").create();
  // void getHsvF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getHsvF(qreal *, qreal *, qreal *, qreal *) const;
  // void setHsvF(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QColor::setHsvF>("setHsvF").create();
  // int cyan() const;
  binder.fun<int, &QColor::cyan>("cyan").create();
  // int magenta() const;
  binder.fun<int, &QColor::magenta>("magenta").create();
  // int yellow() const;
  binder.fun<int, &QColor::yellow>("yellow").create();
  // int black() const;
  binder.fun<int, &QColor::black>("black").create();
  // qreal cyanF() const;
  binder.fun<qreal, &QColor::cyanF>("cyanF").create();
  // qreal magentaF() const;
  binder.fun<qreal, &QColor::magentaF>("magentaF").create();
  // qreal yellowF() const;
  binder.fun<qreal, &QColor::yellowF>("yellowF").create();
  // qreal blackF() const;
  binder.fun<qreal, &QColor::blackF>("blackF").create();
  // void getCmyk(int *, int *, int *, int *, int *);
  /// TODO: void getCmyk(int *, int *, int *, int *, int *);
  // void setCmyk(int, int, int, int, int);
  binder.void_fun<int, int, int, int, int, &QColor::setCmyk>("setCmyk").create();
  // void getCmykF(qreal *, qreal *, qreal *, qreal *, qreal *);
  /// TODO: void getCmykF(qreal *, qreal *, qreal *, qreal *, qreal *);
  // void setCmykF(qreal, qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, qreal, &QColor::setCmykF>("setCmykF").create();
  // int hslHue() const;
  binder.fun<int, &QColor::hslHue>("hslHue").create();
  // int hslSaturation() const;
  binder.fun<int, &QColor::hslSaturation>("hslSaturation").create();
  // int lightness() const;
  binder.fun<int, &QColor::lightness>("lightness").create();
  // qreal hslHueF() const;
  binder.fun<qreal, &QColor::hslHueF>("hslHueF").create();
  // qreal hslSaturationF() const;
  binder.fun<qreal, &QColor::hslSaturationF>("hslSaturationF").create();
  // qreal lightnessF() const;
  binder.fun<qreal, &QColor::lightnessF>("lightnessF").create();
  // void getHsl(int *, int *, int *, int *) const;
  /// TODO: void getHsl(int *, int *, int *, int *) const;
  // void setHsl(int, int, int, int);
  binder.void_fun<int, int, int, int, &QColor::setHsl>("setHsl").create();
  // void getHslF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getHslF(qreal *, qreal *, qreal *, qreal *) const;
  // void setHslF(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QColor::setHslF>("setHslF").create();
  // QColor toRgb() const;
  binder.fun<QColor, &QColor::toRgb>("toRgb").create();
  // QColor toHsv() const;
  binder.fun<QColor, &QColor::toHsv>("toHsv").create();
  // QColor toCmyk() const;
  binder.fun<QColor, &QColor::toCmyk>("toCmyk").create();
  // QColor toHsl() const;
  binder.fun<QColor, &QColor::toHsl>("toHsl").create();
  // QColor convertTo(QColor::Spec) const;
  binder.fun<QColor, QColor::Spec, &QColor::convertTo>("convertTo").create();
  // static QColor fromRgb(QRgb);
  /// TODO: static QColor fromRgb(QRgb);
  // static QColor fromRgba(QRgb);
  /// TODO: static QColor fromRgba(QRgb);
  // static QColor fromRgb(int, int, int, int);
  binder.static_fun<QColor, int, int, int, int, &QColor::fromRgb>("fromRgb").create();
  // static QColor fromRgbF(qreal, qreal, qreal, qreal);
  binder.static_fun<QColor, qreal, qreal, qreal, qreal, &QColor::fromRgbF>("fromRgbF").create();
  // static QColor fromRgba64(ushort, ushort, ushort, ushort);
  /// TODO: static QColor fromRgba64(ushort, ushort, ushort, ushort);
  // static QColor fromRgba64(QRgba64);
  /// TODO: static QColor fromRgba64(QRgba64);
  // static QColor fromHsv(int, int, int, int);
  binder.static_fun<QColor, int, int, int, int, &QColor::fromHsv>("fromHsv").create();
  // static QColor fromHsvF(qreal, qreal, qreal, qreal);
  binder.static_fun<QColor, qreal, qreal, qreal, qreal, &QColor::fromHsvF>("fromHsvF").create();
  // static QColor fromCmyk(int, int, int, int, int);
  binder.static_fun<QColor, int, int, int, int, int, &QColor::fromCmyk>("fromCmyk").create();
  // static QColor fromCmykF(qreal, qreal, qreal, qreal, qreal);
  binder.static_fun<QColor, qreal, qreal, qreal, qreal, qreal, &QColor::fromCmykF>("fromCmykF").create();
  // static QColor fromHsl(int, int, int, int);
  binder.static_fun<QColor, int, int, int, int, &QColor::fromHsl>("fromHsl").create();
  // static QColor fromHslF(qreal, qreal, qreal, qreal);
  binder.static_fun<QColor, qreal, qreal, qreal, qreal, &QColor::fromHslF>("fromHslF").create();
  // QColor light(int) const;
  binder.fun<QColor, int, &QColor::light>("light").create();
  // QColor lighter(int) const;
  binder.fun<QColor, int, &QColor::lighter>("lighter").create();
  // QColor dark(int) const;
  binder.fun<QColor, int, &QColor::dark>("dark").create();
  // QColor darker(int) const;
  binder.fun<QColor, int, &QColor::darker>("darker").create();
  // bool operator==(const QColor &) const;
  binder.operators().eq<const QColor &>();
  // bool operator!=(const QColor &) const;
  binder.operators().neq<const QColor &>();
  // static bool isValidColor(const QString &);
  binder.static_fun<bool, const QString &, &QColor::isValidColor>("isValidColor").create();
  // static bool isValidColor(QStringView);
  /// TODO: static bool isValidColor(QStringView);
  // static bool isValidColor(QLatin1String);
  /// TODO: static bool isValidColor(QLatin1String);
}


void register_color_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_color_class(ns);
  binding::Namespace binder{ ns };

  // QDebug operator<<(QDebug, const QColor &);
  /// TODO: QDebug operator<<(QDebug, const QColor &);
  // QDataStream & operator<<(QDataStream &, const QColor &);
  binder.operators().put_to<QDataStream &, const QColor &>();
  // QDataStream & operator>>(QDataStream &, QColor &);
  binder.operators().read_from<QDataStream &, QColor &>();
}

