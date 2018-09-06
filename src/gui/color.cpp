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
  binder.ctors().add<Qt::GlobalColor>();
  // QColor(int, int, int, int);
  binder.ctors().add<int, int, int, int>();
  // QColor(QRgb);
  /// TODO: QColor(QRgb);
  // QColor(QRgba64);
  /// TODO: QColor(QRgba64);
  // QColor(const QString &);
  binder.ctors().add<const QString &>();
  // QColor(QStringView);
  /// TODO: QColor(QStringView);
  // QColor(const char *);
  /// TODO: QColor(const char *);
  // QColor(QLatin1String);
  /// TODO: QColor(QLatin1String);
  // QColor(QColor::Spec);
  binder.ctors().add<QColor::Spec>();
  // QColor(const QColor &);
  binder.ctors().add<const QColor &>();
  // QColor(QColor &&);
  binder.ctors().add<QColor &&>();
  // QColor & operator=(QColor &&);
  binder.operators().assign<QColor &&>();
  // QColor & operator=(const QColor &);
  binder.operators().assign<const QColor &>();
  // QColor & operator=(Qt::GlobalColor);
  binder.operators().assign<Qt::GlobalColor>();
  // bool isValid() const;
  binder.add_fun<bool, &QColor::isValid>("isValid");
  // QString name() const;
  binder.add_fun<QString, &QColor::name>("name");
  // QString name(QColor::NameFormat) const;
  binder.add_fun<QString, QColor::NameFormat, &QColor::name>("name");
  // void setNamedColor(const QString &);
  binder.add_void_fun<const QString &, &QColor::setNamedColor>("setNamedColor");
  // void setNamedColor(QStringView);
  /// TODO: void setNamedColor(QStringView);
  // void setNamedColor(QLatin1String);
  /// TODO: void setNamedColor(QLatin1String);
  // static QStringList colorNames();
  /// TODO: static QStringList colorNames();
  // QColor::Spec spec() const;
  binder.add_fun<QColor::Spec, &QColor::spec>("spec");
  // int alpha() const;
  binder.add_fun<int, &QColor::alpha>("alpha");
  // void setAlpha(int);
  binder.add_void_fun<int, &QColor::setAlpha>("setAlpha");
  // qreal alphaF() const;
  binder.add_fun<qreal, &QColor::alphaF>("alphaF");
  // void setAlphaF(qreal);
  binder.add_void_fun<qreal, &QColor::setAlphaF>("setAlphaF");
  // int red() const;
  binder.add_fun<int, &QColor::red>("red");
  // int green() const;
  binder.add_fun<int, &QColor::green>("green");
  // int blue() const;
  binder.add_fun<int, &QColor::blue>("blue");
  // void setRed(int);
  binder.add_void_fun<int, &QColor::setRed>("setRed");
  // void setGreen(int);
  binder.add_void_fun<int, &QColor::setGreen>("setGreen");
  // void setBlue(int);
  binder.add_void_fun<int, &QColor::setBlue>("setBlue");
  // qreal redF() const;
  binder.add_fun<qreal, &QColor::redF>("redF");
  // qreal greenF() const;
  binder.add_fun<qreal, &QColor::greenF>("greenF");
  // qreal blueF() const;
  binder.add_fun<qreal, &QColor::blueF>("blueF");
  // void setRedF(qreal);
  binder.add_void_fun<qreal, &QColor::setRedF>("setRedF");
  // void setGreenF(qreal);
  binder.add_void_fun<qreal, &QColor::setGreenF>("setGreenF");
  // void setBlueF(qreal);
  binder.add_void_fun<qreal, &QColor::setBlueF>("setBlueF");
  // void getRgb(int *, int *, int *, int *) const;
  /// TODO: void getRgb(int *, int *, int *, int *) const;
  // void setRgb(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QColor::setRgb>("setRgb");
  // void getRgbF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getRgbF(qreal *, qreal *, qreal *, qreal *) const;
  // void setRgbF(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QColor::setRgbF>("setRgbF");
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
  binder.add_fun<int, &QColor::hue>("hue");
  // int saturation() const;
  binder.add_fun<int, &QColor::saturation>("saturation");
  // int hsvHue() const;
  binder.add_fun<int, &QColor::hsvHue>("hsvHue");
  // int hsvSaturation() const;
  binder.add_fun<int, &QColor::hsvSaturation>("hsvSaturation");
  // int value() const;
  binder.add_fun<int, &QColor::value>("value");
  // qreal hueF() const;
  binder.add_fun<qreal, &QColor::hueF>("hueF");
  // qreal saturationF() const;
  binder.add_fun<qreal, &QColor::saturationF>("saturationF");
  // qreal hsvHueF() const;
  binder.add_fun<qreal, &QColor::hsvHueF>("hsvHueF");
  // qreal hsvSaturationF() const;
  binder.add_fun<qreal, &QColor::hsvSaturationF>("hsvSaturationF");
  // qreal valueF() const;
  binder.add_fun<qreal, &QColor::valueF>("valueF");
  // void getHsv(int *, int *, int *, int *) const;
  /// TODO: void getHsv(int *, int *, int *, int *) const;
  // void setHsv(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QColor::setHsv>("setHsv");
  // void getHsvF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getHsvF(qreal *, qreal *, qreal *, qreal *) const;
  // void setHsvF(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QColor::setHsvF>("setHsvF");
  // int cyan() const;
  binder.add_fun<int, &QColor::cyan>("cyan");
  // int magenta() const;
  binder.add_fun<int, &QColor::magenta>("magenta");
  // int yellow() const;
  binder.add_fun<int, &QColor::yellow>("yellow");
  // int black() const;
  binder.add_fun<int, &QColor::black>("black");
  // qreal cyanF() const;
  binder.add_fun<qreal, &QColor::cyanF>("cyanF");
  // qreal magentaF() const;
  binder.add_fun<qreal, &QColor::magentaF>("magentaF");
  // qreal yellowF() const;
  binder.add_fun<qreal, &QColor::yellowF>("yellowF");
  // qreal blackF() const;
  binder.add_fun<qreal, &QColor::blackF>("blackF");
  // void getCmyk(int *, int *, int *, int *, int *);
  /// TODO: void getCmyk(int *, int *, int *, int *, int *);
  // void setCmyk(int, int, int, int, int);
  binder.add_void_fun<int, int, int, int, int, &QColor::setCmyk>("setCmyk");
  // void getCmykF(qreal *, qreal *, qreal *, qreal *, qreal *);
  /// TODO: void getCmykF(qreal *, qreal *, qreal *, qreal *, qreal *);
  // void setCmykF(qreal, qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, qreal, &QColor::setCmykF>("setCmykF");
  // int hslHue() const;
  binder.add_fun<int, &QColor::hslHue>("hslHue");
  // int hslSaturation() const;
  binder.add_fun<int, &QColor::hslSaturation>("hslSaturation");
  // int lightness() const;
  binder.add_fun<int, &QColor::lightness>("lightness");
  // qreal hslHueF() const;
  binder.add_fun<qreal, &QColor::hslHueF>("hslHueF");
  // qreal hslSaturationF() const;
  binder.add_fun<qreal, &QColor::hslSaturationF>("hslSaturationF");
  // qreal lightnessF() const;
  binder.add_fun<qreal, &QColor::lightnessF>("lightnessF");
  // void getHsl(int *, int *, int *, int *) const;
  /// TODO: void getHsl(int *, int *, int *, int *) const;
  // void setHsl(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QColor::setHsl>("setHsl");
  // void getHslF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getHslF(qreal *, qreal *, qreal *, qreal *) const;
  // void setHslF(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QColor::setHslF>("setHslF");
  // QColor toRgb() const;
  binder.add_fun<QColor, &QColor::toRgb>("toRgb");
  // QColor toHsv() const;
  binder.add_fun<QColor, &QColor::toHsv>("toHsv");
  // QColor toCmyk() const;
  binder.add_fun<QColor, &QColor::toCmyk>("toCmyk");
  // QColor toHsl() const;
  binder.add_fun<QColor, &QColor::toHsl>("toHsl");
  // QColor convertTo(QColor::Spec) const;
  binder.add_fun<QColor, QColor::Spec, &QColor::convertTo>("convertTo");
  // static QColor fromRgb(QRgb);
  /// TODO: static QColor fromRgb(QRgb);
  // static QColor fromRgba(QRgb);
  /// TODO: static QColor fromRgba(QRgb);
  // static QColor fromRgb(int, int, int, int);
  binder.add_static<QColor, int, int, int, int, &QColor::fromRgb>("fromRgb");
  // static QColor fromRgbF(qreal, qreal, qreal, qreal);
  binder.add_static<QColor, qreal, qreal, qreal, qreal, &QColor::fromRgbF>("fromRgbF");
  // static QColor fromRgba64(ushort, ushort, ushort, ushort);
  /// TODO: static QColor fromRgba64(ushort, ushort, ushort, ushort);
  // static QColor fromRgba64(QRgba64);
  /// TODO: static QColor fromRgba64(QRgba64);
  // static QColor fromHsv(int, int, int, int);
  binder.add_static<QColor, int, int, int, int, &QColor::fromHsv>("fromHsv");
  // static QColor fromHsvF(qreal, qreal, qreal, qreal);
  binder.add_static<QColor, qreal, qreal, qreal, qreal, &QColor::fromHsvF>("fromHsvF");
  // static QColor fromCmyk(int, int, int, int, int);
  binder.add_static<QColor, int, int, int, int, int, &QColor::fromCmyk>("fromCmyk");
  // static QColor fromCmykF(qreal, qreal, qreal, qreal, qreal);
  binder.add_static<QColor, qreal, qreal, qreal, qreal, qreal, &QColor::fromCmykF>("fromCmykF");
  // static QColor fromHsl(int, int, int, int);
  binder.add_static<QColor, int, int, int, int, &QColor::fromHsl>("fromHsl");
  // static QColor fromHslF(qreal, qreal, qreal, qreal);
  binder.add_static<QColor, qreal, qreal, qreal, qreal, &QColor::fromHslF>("fromHslF");
  // QColor light(int) const;
  binder.add_fun<QColor, int, &QColor::light>("light");
  // QColor lighter(int) const;
  binder.add_fun<QColor, int, &QColor::lighter>("lighter");
  // QColor dark(int) const;
  binder.add_fun<QColor, int, &QColor::dark>("dark");
  // QColor darker(int) const;
  binder.add_fun<QColor, int, &QColor::darker>("darker");
  // bool operator==(const QColor &) const;
  binder.operators().eq<const QColor &>();
  // bool operator!=(const QColor &) const;
  binder.operators().neq<const QColor &>();
  // static bool isValidColor(const QString &);
  binder.add_static<bool, const QString &, &QColor::isValidColor>("isValidColor");
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

