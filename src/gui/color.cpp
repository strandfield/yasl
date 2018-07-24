// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/color.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"

#include "yasl/gui/rgb.h"
#include "yasl/gui/rgba64.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_color_name_format_enum(script::Class color)
{
  using namespace script;

  Enum name_format = color.Enum("NameFormat").setId(script::Type::QColorNameFormat).get();

  name_format.addValue("HexArgb", QColor::HexArgb);
  name_format.addValue("HexRgb", QColor::HexRgb);
}

static void register_color_spec_enum(script::Class color)
{
  using namespace script;

  Enum spec = color.Enum("Spec").setId(script::Type::QColorSpec).get();

  spec.addValue("Cmyk", QColor::Cmyk);
  spec.addValue("Hsl", QColor::Hsl);
  spec.addValue("Hsv", QColor::Hsv);
  spec.addValue("Invalid", QColor::Invalid);
  spec.addValue("Rgb", QColor::Rgb);
}

static void register_color_class(script::Namespace ns)
{
  using namespace script;

  Class color = ns.Class("Color").setId(script::Type::QColor).get();

  register_color_name_format_enum(color);
  register_color_spec_enum(color);
  binding::Class<QColor> binder{ color };

  // ~QColor();
  binder.add_dtor();
  // QColor();
  binder.ctors().add_default();
  // QColor(Qt::GlobalColor);
  binder.ctors().add<Qt::GlobalColor>();
  // QColor(int, int, int, int);
  binder.ctors().add<int, int, int, int>();
  // QColor(QRgb);
  binder.ctors().add<QRgb>();
  // QColor(QRgba64);
  binder.ctors().add<QRgba64>();
  // QColor(const QString &);
  binder.ctors().add<const QString &>();
  // QColor(QStringView);
  binder.ctors().add<QStringView>();
  // QColor(const char *);
  binder.ctors().add<const char *>();
  // QColor(QLatin1String);
  binder.ctors().add<QLatin1String>();
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
  binder.add_void_fun<QStringView, &QColor::setNamedColor>("setNamedColor");
  // void setNamedColor(QLatin1String);
  binder.add_void_fun<QLatin1String, &QColor::setNamedColor>("setNamedColor");
  // static QStringList colorNames();
  binder.add_static<QStringList, &QColor::colorNames>("colorNames");
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
  /// TODO: binder.add_const_void_fun<int *, int *, int *, int *, &QColor::getRgb>("getRgb");
  // void setRgb(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QColor::setRgb>("setRgb");
  // void getRgbF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: binder.add_const_void_fun<qreal *, qreal *, qreal *, qreal *, &QColor::getRgbF>("getRgbF");
  // void setRgbF(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QColor::setRgbF>("setRgbF");
  // QRgba64 rgba64() const;
  binder.add_fun<QRgba64, &QColor::rgba64>("rgba64");
  // void setRgba64(QRgba64);
  binder.add_void_fun<QRgba64, &QColor::setRgba64>("setRgba64");
  // QRgb rgba() const;
  binder.add_fun<QRgb, &QColor::rgba>("rgba");
  // void setRgba(QRgb);
  binder.add_void_fun<QRgb, &QColor::setRgba>("setRgba");
  // QRgb rgb() const;
  binder.add_fun<QRgb, &QColor::rgb>("rgb");
  // void setRgb(QRgb);
  binder.add_void_fun<QRgb, &QColor::setRgb>("setRgb");
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
  /// TODO: binder.add_const_void_fun<int *, int *, int *, int *, &QColor::getHsv>("getHsv");
  // void setHsv(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QColor::setHsv>("setHsv");
  // void getHsvF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: binder.add_const_void_fun<qreal *, qreal *, qreal *, qreal *, &QColor::getHsvF>("getHsvF");
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
  /// TODO: binder.add_void_fun<int *, int *, int *, int *, int *, &QColor::getCmyk>("getCmyk");
  // void setCmyk(int, int, int, int, int);
  binder.add_void_fun<int, int, int, int, int, &QColor::setCmyk>("setCmyk");
  // void getCmykF(qreal *, qreal *, qreal *, qreal *, qreal *);
  binder.add_void_fun<qreal *, qreal *, qreal *, qreal *, qreal *, &QColor::getCmykF>("getCmykF");
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
  /// TODO: binder.add_const_void_fun<int *, int *, int *, int *, &QColor::getHsl>("getHsl");
  // void setHsl(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QColor::setHsl>("setHsl");
  // void getHslF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: binder.add_const_void_fun<qreal *, qreal *, qreal *, qreal *, &QColor::getHslF>("getHslF");
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
  binder.add_static<QColor, QRgb, &QColor::fromRgb>("fromRgb");
  // static QColor fromRgba(QRgb);
  binder.add_static<QColor, QRgb, &QColor::fromRgba>("fromRgba");
  // static QColor fromRgb(int, int, int, int);
  binder.add_static<QColor, int, int, int, int, &QColor::fromRgb>("fromRgb");
  // static QColor fromRgbF(qreal, qreal, qreal, qreal);
  binder.add_static<QColor, qreal, qreal, qreal, qreal, &QColor::fromRgbF>("fromRgbF");
  // static QColor fromRgba64(ushort, ushort, ushort, ushort);
  binder.add_static<QColor, ushort, ushort, ushort, ushort, &QColor::fromRgba64>("fromRgba64");
  // static QColor fromRgba64(QRgba64);
  binder.add_static<QColor, QRgba64, &QColor::fromRgba64>("fromRgba64");
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
  binder.add_static<bool, QStringView, &QColor::isValidColor>("isValidColor");
  // static bool isValidColor(QLatin1String);
  binder.add_static<bool, QLatin1String, &QColor::isValidColor>("isValidColor");
}

void register_color_file(script::Namespace root)
{
  using namespace script;

  register_color_class(root);
  binding::Namespace binder{ root };

  // QDebug operator<<(QDebug, const QColor &);
  binder.operators().left_shift<QDebug, QDebug, const QColor &>();
  // QDataStream & operator<<(QDataStream &, const QColor &);
  binder.operators().put_to<QDataStream &, const QColor &>();
  // QDataStream & operator>>(QDataStream &, QColor &);
  binder.operators().read_from<QDataStream &, QColor &>();
}

