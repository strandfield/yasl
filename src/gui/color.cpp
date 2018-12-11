// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/color.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/gui/color.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_color_spec_enum(script::Class color)
{
  using namespace script;

  Enum spec = color.newEnum("Spec").setId(script::Type::QColorSpec).get();

  spec.addValue("Invalid", QColor::Invalid);
  spec.addValue("Rgb", QColor::Rgb);
  spec.addValue("Hsv", QColor::Hsv);
  spec.addValue("Cmyk", QColor::Cmyk);
  spec.addValue("Hsl", QColor::Hsl);
}


#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
static void register_color_name_format_enum(script::Class color)
{
  using namespace script;

  Enum name_format = color.newEnum("NameFormat").setId(script::Type::QColorNameFormat).get();

  name_format.addValue("HexRgb", QColor::HexRgb);
  name_format.addValue("HexArgb", QColor::HexArgb);
}
#endif


static void register_color_class(script::Namespace ns)
{
  using namespace script;

  Class color = ns.newClass("Color").setId(script::Type::QColor).get();

  register_color_spec_enum(color);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  register_color_name_format_enum(color);
#endif

  // QColor();
  bind::default_constructor<QColor>(color).create();
  // ~QColor();
  bind::destructor<QColor>(color).create();
  // QColor(Qt::GlobalColor);
  bind::constructor<QColor, Qt::GlobalColor>(color).create();
  // QColor(int, int, int, int = 255);
  bind::constructor<QColor, int, int, int, int>(color)
    .apply(bind::default_arguments(255)).create();
  // QColor(QRgb);
  /// TODO: QColor(QRgb);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // QColor(QRgba64);
  /// TODO: QColor(QRgba64);
#endif
  // QColor(const QString &);
  bind::constructor<QColor, const QString &>(color).create();
  // QColor(QStringView);
  /// TODO: QColor(QStringView);
  // QColor(const char *);
  /// TODO: QColor(const char *);
  // QColor(QLatin1String);
  /// TODO: QColor(QLatin1String);
  // QColor(QColor::Spec);
  bind::constructor<QColor, QColor::Spec>(color).create();
  // QColor(const QColor &);
  bind::constructor<QColor, const QColor &>(color).create();
  // QColor(QColor &&);
  bind::constructor<QColor, QColor &&>(color).create();
  // QColor & operator=(QColor &&);
  bind::memop_assign<QColor, QColor &&>(color);
  // QColor & operator=(const QColor &);
  bind::memop_assign<QColor, const QColor &>(color);
  // QColor & operator=(Qt::GlobalColor);
  bind::memop_assign<QColor, Qt::GlobalColor>(color);
  // bool isValid() const;
  bind::member_function<QColor, bool, &QColor::isValid>(color, "isValid").create();
  // QString name() const;
  bind::member_function<QColor, QString, &QColor::name>(color, "name").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // QString name(QColor::NameFormat) const;
  bind::member_function<QColor, QString, QColor::NameFormat, &QColor::name>(color, "name").create();
#endif
  // void setNamedColor(const QString &);
  bind::void_member_function<QColor, const QString &, &QColor::setNamedColor>(color, "setNamedColor").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // void setNamedColor(QStringView);
  /// TODO: void setNamedColor(QStringView);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 8, 0))
  // void setNamedColor(QLatin1String);
  /// TODO: void setNamedColor(QLatin1String);
#endif
  // static QStringList colorNames();
  /// TODO: static QStringList colorNames();
  // QColor::Spec spec() const;
  bind::member_function<QColor, QColor::Spec, &QColor::spec>(color, "spec").create();
  // int alpha() const;
  bind::member_function<QColor, int, &QColor::alpha>(color, "alpha").create();
  // void setAlpha(int);
  bind::void_member_function<QColor, int, &QColor::setAlpha>(color, "setAlpha").create();
  // qreal alphaF() const;
  bind::member_function<QColor, qreal, &QColor::alphaF>(color, "alphaF").create();
  // void setAlphaF(qreal);
  bind::void_member_function<QColor, qreal, &QColor::setAlphaF>(color, "setAlphaF").create();
  // int red() const;
  bind::member_function<QColor, int, &QColor::red>(color, "red").create();
  // int green() const;
  bind::member_function<QColor, int, &QColor::green>(color, "green").create();
  // int blue() const;
  bind::member_function<QColor, int, &QColor::blue>(color, "blue").create();
  // void setRed(int);
  bind::void_member_function<QColor, int, &QColor::setRed>(color, "setRed").create();
  // void setGreen(int);
  bind::void_member_function<QColor, int, &QColor::setGreen>(color, "setGreen").create();
  // void setBlue(int);
  bind::void_member_function<QColor, int, &QColor::setBlue>(color, "setBlue").create();
  // qreal redF() const;
  bind::member_function<QColor, qreal, &QColor::redF>(color, "redF").create();
  // qreal greenF() const;
  bind::member_function<QColor, qreal, &QColor::greenF>(color, "greenF").create();
  // qreal blueF() const;
  bind::member_function<QColor, qreal, &QColor::blueF>(color, "blueF").create();
  // void setRedF(qreal);
  bind::void_member_function<QColor, qreal, &QColor::setRedF>(color, "setRedF").create();
  // void setGreenF(qreal);
  bind::void_member_function<QColor, qreal, &QColor::setGreenF>(color, "setGreenF").create();
  // void setBlueF(qreal);
  bind::void_member_function<QColor, qreal, &QColor::setBlueF>(color, "setBlueF").create();
  // void getRgb(int *, int *, int *, int *) const;
  /// TODO: void getRgb(int *, int *, int *, int *) const;
  // void setRgb(int, int, int, int = 255);
  bind::void_member_function<QColor, int, int, int, int, &QColor::setRgb>(color, "setRgb")
    .apply(bind::default_arguments(255)).create();
  // void getRgbF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getRgbF(qreal *, qreal *, qreal *, qreal *) const;
  // void setRgbF(qreal, qreal, qreal, qreal = qreal(1.0));
  bind::void_member_function<QColor, qreal, qreal, qreal, qreal, &QColor::setRgbF>(color, "setRgbF")
    .apply(bind::default_arguments(qreal(1.0))).create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // QRgba64 rgba64() const;
  /// TODO: QRgba64 rgba64() const;
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // void setRgba64(QRgba64);
  /// TODO: void setRgba64(QRgba64);
#endif
  // QRgb rgba() const;
  /// TODO: QRgb rgba() const;
  // void setRgba(QRgb);
  /// TODO: void setRgba(QRgb);
  // QRgb rgb() const;
  /// TODO: QRgb rgb() const;
  // void setRgb(QRgb);
  /// TODO: void setRgb(QRgb);
  // int hue() const;
  bind::member_function<QColor, int, &QColor::hue>(color, "hue").create();
  // int saturation() const;
  bind::member_function<QColor, int, &QColor::saturation>(color, "saturation").create();
  // int hsvHue() const;
  bind::member_function<QColor, int, &QColor::hsvHue>(color, "hsvHue").create();
  // int hsvSaturation() const;
  bind::member_function<QColor, int, &QColor::hsvSaturation>(color, "hsvSaturation").create();
  // int value() const;
  bind::member_function<QColor, int, &QColor::value>(color, "value").create();
  // qreal hueF() const;
  bind::member_function<QColor, qreal, &QColor::hueF>(color, "hueF").create();
  // qreal saturationF() const;
  bind::member_function<QColor, qreal, &QColor::saturationF>(color, "saturationF").create();
  // qreal hsvHueF() const;
  bind::member_function<QColor, qreal, &QColor::hsvHueF>(color, "hsvHueF").create();
  // qreal hsvSaturationF() const;
  bind::member_function<QColor, qreal, &QColor::hsvSaturationF>(color, "hsvSaturationF").create();
  // qreal valueF() const;
  bind::member_function<QColor, qreal, &QColor::valueF>(color, "valueF").create();
  // void getHsv(int *, int *, int *, int *) const;
  /// TODO: void getHsv(int *, int *, int *, int *) const;
  // void setHsv(int, int, int, int = 255);
  bind::void_member_function<QColor, int, int, int, int, &QColor::setHsv>(color, "setHsv")
    .apply(bind::default_arguments(255)).create();
  // void getHsvF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getHsvF(qreal *, qreal *, qreal *, qreal *) const;
  // void setHsvF(qreal, qreal, qreal, qreal = qreal(1.0));
  bind::void_member_function<QColor, qreal, qreal, qreal, qreal, &QColor::setHsvF>(color, "setHsvF")
    .apply(bind::default_arguments(qreal(1.0))).create();
  // int cyan() const;
  bind::member_function<QColor, int, &QColor::cyan>(color, "cyan").create();
  // int magenta() const;
  bind::member_function<QColor, int, &QColor::magenta>(color, "magenta").create();
  // int yellow() const;
  bind::member_function<QColor, int, &QColor::yellow>(color, "yellow").create();
  // int black() const;
  bind::member_function<QColor, int, &QColor::black>(color, "black").create();
  // qreal cyanF() const;
  bind::member_function<QColor, qreal, &QColor::cyanF>(color, "cyanF").create();
  // qreal magentaF() const;
  bind::member_function<QColor, qreal, &QColor::magentaF>(color, "magentaF").create();
  // qreal yellowF() const;
  bind::member_function<QColor, qreal, &QColor::yellowF>(color, "yellowF").create();
  // qreal blackF() const;
  bind::member_function<QColor, qreal, &QColor::blackF>(color, "blackF").create();
  // void getCmyk(int *, int *, int *, int *, int *);
  /// TODO: void getCmyk(int *, int *, int *, int *, int *);
  // void setCmyk(int, int, int, int, int = 255);
  bind::void_member_function<QColor, int, int, int, int, int, &QColor::setCmyk>(color, "setCmyk")
    .apply(bind::default_arguments(255)).create();
  // void getCmykF(qreal *, qreal *, qreal *, qreal *, qreal *);
  /// TODO: void getCmykF(qreal *, qreal *, qreal *, qreal *, qreal *);
  // void setCmykF(qreal, qreal, qreal, qreal, qreal = qreal(1.0));
  bind::void_member_function<QColor, qreal, qreal, qreal, qreal, qreal, &QColor::setCmykF>(color, "setCmykF")
    .apply(bind::default_arguments(qreal(1.0))).create();
  // int hslHue() const;
  bind::member_function<QColor, int, &QColor::hslHue>(color, "hslHue").create();
  // int hslSaturation() const;
  bind::member_function<QColor, int, &QColor::hslSaturation>(color, "hslSaturation").create();
  // int lightness() const;
  bind::member_function<QColor, int, &QColor::lightness>(color, "lightness").create();
  // qreal hslHueF() const;
  bind::member_function<QColor, qreal, &QColor::hslHueF>(color, "hslHueF").create();
  // qreal hslSaturationF() const;
  bind::member_function<QColor, qreal, &QColor::hslSaturationF>(color, "hslSaturationF").create();
  // qreal lightnessF() const;
  bind::member_function<QColor, qreal, &QColor::lightnessF>(color, "lightnessF").create();
  // void getHsl(int *, int *, int *, int *) const;
  /// TODO: void getHsl(int *, int *, int *, int *) const;
  // void setHsl(int, int, int, int = 255);
  bind::void_member_function<QColor, int, int, int, int, &QColor::setHsl>(color, "setHsl")
    .apply(bind::default_arguments(255)).create();
  // void getHslF(qreal *, qreal *, qreal *, qreal *) const;
  /// TODO: void getHslF(qreal *, qreal *, qreal *, qreal *) const;
  // void setHslF(qreal, qreal, qreal, qreal = qreal(1.0));
  bind::void_member_function<QColor, qreal, qreal, qreal, qreal, &QColor::setHslF>(color, "setHslF")
    .apply(bind::default_arguments(qreal(1.0))).create();
  // QColor toRgb() const;
  bind::member_function<QColor, QColor, &QColor::toRgb>(color, "toRgb").create();
  // QColor toHsv() const;
  bind::member_function<QColor, QColor, &QColor::toHsv>(color, "toHsv").create();
  // QColor toCmyk() const;
  bind::member_function<QColor, QColor, &QColor::toCmyk>(color, "toCmyk").create();
  // QColor toHsl() const;
  bind::member_function<QColor, QColor, &QColor::toHsl>(color, "toHsl").create();
  // QColor convertTo(QColor::Spec) const;
  bind::member_function<QColor, QColor, QColor::Spec, &QColor::convertTo>(color, "convertTo").create();
  // static QColor fromRgb(QRgb);
  /// TODO: static QColor fromRgb(QRgb);
  // static QColor fromRgba(QRgb);
  /// TODO: static QColor fromRgba(QRgb);
  // static QColor fromRgb(int, int, int, int = 255);
  bind::static_member_function<QColor, QColor, int, int, int, int, &QColor::fromRgb>(color, "fromRgb")
    .apply(bind::default_arguments(255)).create();
  // static QColor fromRgbF(qreal, qreal, qreal, qreal = qreal(1.0));
  bind::static_member_function<QColor, QColor, qreal, qreal, qreal, qreal, &QColor::fromRgbF>(color, "fromRgbF")
    .apply(bind::default_arguments(qreal(1.0))).create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // static QColor fromRgba64(ushort, ushort, ushort, ushort);
  /// TODO: static QColor fromRgba64(ushort, ushort, ushort, ushort);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
  // static QColor fromRgba64(QRgba64);
  /// TODO: static QColor fromRgba64(QRgba64);
#endif
  // static QColor fromHsv(int, int, int, int = 255);
  bind::static_member_function<QColor, QColor, int, int, int, int, &QColor::fromHsv>(color, "fromHsv")
    .apply(bind::default_arguments(255)).create();
  // static QColor fromHsvF(qreal, qreal, qreal, qreal = qreal(1.0));
  bind::static_member_function<QColor, QColor, qreal, qreal, qreal, qreal, &QColor::fromHsvF>(color, "fromHsvF")
    .apply(bind::default_arguments(qreal(1.0))).create();
  // static QColor fromCmyk(int, int, int, int, int = 255);
  bind::static_member_function<QColor, QColor, int, int, int, int, int, &QColor::fromCmyk>(color, "fromCmyk")
    .apply(bind::default_arguments(255)).create();
  // static QColor fromCmykF(qreal, qreal, qreal, qreal, qreal = qreal(1.0));
  bind::static_member_function<QColor, QColor, qreal, qreal, qreal, qreal, qreal, &QColor::fromCmykF>(color, "fromCmykF")
    .apply(bind::default_arguments(qreal(1.0))).create();
  // static QColor fromHsl(int, int, int, int = 255);
  bind::static_member_function<QColor, QColor, int, int, int, int, &QColor::fromHsl>(color, "fromHsl")
    .apply(bind::default_arguments(255)).create();
  // static QColor fromHslF(qreal, qreal, qreal, qreal = qreal(1.0));
  bind::static_member_function<QColor, QColor, qreal, qreal, qreal, qreal, &QColor::fromHslF>(color, "fromHslF")
    .apply(bind::default_arguments(qreal(1.0))).create();
  // QColor light(int) const;
  bind::member_function<QColor, QColor, int, &QColor::light>(color, "light").create();
  // QColor lighter(int = 150) const;
  bind::member_function<QColor, QColor, int, &QColor::lighter>(color, "lighter")
    .apply(bind::default_arguments(150)).create();
  // QColor dark(int) const;
  bind::member_function<QColor, QColor, int, &QColor::dark>(color, "dark").create();
  // QColor darker(int) const;
  bind::member_function<QColor, QColor, int, &QColor::darker>(color, "darker").create();
  // bool operator==(const QColor &) const;
  bind::memop_eq<QColor, const QColor &>(color);
  // bool operator!=(const QColor &) const;
  bind::memop_neq<QColor, const QColor &>(color);
  // static bool isValidColor(const QString &);
  bind::static_member_function<QColor, bool, const QString &, &QColor::isValidColor>(color, "isValidColor").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 10, 0))
  // static bool isValidColor(QStringView);
  /// TODO: static bool isValidColor(QStringView);
#endif
  // static bool isValidColor(QLatin1String);
  /// TODO: static bool isValidColor(QLatin1String);

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QColor, QMetaType::QColor>>();
}


void register_color_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_color_class(ns);

  // QDebug operator<<(QDebug, const QColor &);
  /// TODO: QDebug operator<<(QDebug, const QColor &);
  // QDataStream & operator<<(QDataStream &, const QColor &);
  bind::op_put_to<QDataStream &, const QColor &>(ns);
  // QDataStream & operator>>(QDataStream &, QColor &);
  bind::op_read_from<QDataStream &, QColor &>(ns);
}
