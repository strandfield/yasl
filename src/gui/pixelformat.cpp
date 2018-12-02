// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pixelformat.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"

#include "yasl/gui/pixelformat.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
static void register_pixel_format_color_model_enum(script::Class pixel_format)
{
  using namespace script;

  Enum color_model = pixel_format.newEnum("ColorModel").setId(script::Type::QPixelFormatColorModel).get();

  color_model.addValue("RGB", QPixelFormat::RGB);
  color_model.addValue("BGR", QPixelFormat::BGR);
  color_model.addValue("Indexed", QPixelFormat::Indexed);
  color_model.addValue("Grayscale", QPixelFormat::Grayscale);
  color_model.addValue("CMYK", QPixelFormat::CMYK);
  color_model.addValue("HSL", QPixelFormat::HSL);
  color_model.addValue("HSV", QPixelFormat::HSV);
  color_model.addValue("YUV", QPixelFormat::YUV);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  color_model.addValue("Alpha", QPixelFormat::Alpha);
#endif
}
#endif


#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
static void register_pixel_format_alpha_usage_enum(script::Class pixel_format)
{
  using namespace script;

  Enum alpha_usage = pixel_format.newEnum("AlphaUsage").setId(script::Type::QPixelFormatAlphaUsage).get();

  alpha_usage.addValue("UsesAlpha", QPixelFormat::UsesAlpha);
  alpha_usage.addValue("IgnoresAlpha", QPixelFormat::IgnoresAlpha);
}
#endif


#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
static void register_pixel_format_alpha_position_enum(script::Class pixel_format)
{
  using namespace script;

  Enum alpha_position = pixel_format.newEnum("AlphaPosition").setId(script::Type::QPixelFormatAlphaPosition).get();

  alpha_position.addValue("AtBeginning", QPixelFormat::AtBeginning);
  alpha_position.addValue("AtEnd", QPixelFormat::AtEnd);
}
#endif


#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
static void register_pixel_format_alpha_premultiplied_enum(script::Class pixel_format)
{
  using namespace script;

  Enum alpha_premultiplied = pixel_format.newEnum("AlphaPremultiplied").setId(script::Type::QPixelFormatAlphaPremultiplied).get();

  alpha_premultiplied.addValue("NotPremultiplied", QPixelFormat::NotPremultiplied);
  alpha_premultiplied.addValue("Premultiplied", QPixelFormat::Premultiplied);
}
#endif


#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
static void register_pixel_format_type_interpretation_enum(script::Class pixel_format)
{
  using namespace script;

  Enum type_interpretation = pixel_format.newEnum("TypeInterpretation").setId(script::Type::QPixelFormatTypeInterpretation).get();

  type_interpretation.addValue("UnsignedInteger", QPixelFormat::UnsignedInteger);
  type_interpretation.addValue("UnsignedShort", QPixelFormat::UnsignedShort);
  type_interpretation.addValue("UnsignedByte", QPixelFormat::UnsignedByte);
  type_interpretation.addValue("FloatingPoint", QPixelFormat::FloatingPoint);
}
#endif


#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
static void register_pixel_format_y_u_v_layout_enum(script::Class pixel_format)
{
  using namespace script;

  Enum y_u_v_layout = pixel_format.newEnum("YUVLayout").setId(script::Type::QPixelFormatYUVLayout).get();

  y_u_v_layout.addValue("YUV444", QPixelFormat::YUV444);
  y_u_v_layout.addValue("YUV422", QPixelFormat::YUV422);
  y_u_v_layout.addValue("YUV411", QPixelFormat::YUV411);
  y_u_v_layout.addValue("YUV420P", QPixelFormat::YUV420P);
  y_u_v_layout.addValue("YUV420SP", QPixelFormat::YUV420SP);
  y_u_v_layout.addValue("YV12", QPixelFormat::YV12);
  y_u_v_layout.addValue("UYVY", QPixelFormat::UYVY);
  y_u_v_layout.addValue("YUYV", QPixelFormat::YUYV);
  y_u_v_layout.addValue("NV12", QPixelFormat::NV12);
  y_u_v_layout.addValue("NV21", QPixelFormat::NV21);
  y_u_v_layout.addValue("IMC1", QPixelFormat::IMC1);
  y_u_v_layout.addValue("IMC2", QPixelFormat::IMC2);
  y_u_v_layout.addValue("IMC3", QPixelFormat::IMC3);
  y_u_v_layout.addValue("IMC4", QPixelFormat::IMC4);
  y_u_v_layout.addValue("Y8", QPixelFormat::Y8);
  y_u_v_layout.addValue("Y16", QPixelFormat::Y16);
}
#endif


#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
static void register_pixel_format_byte_order_enum(script::Class pixel_format)
{
  using namespace script;

  Enum byte_order = pixel_format.newEnum("ByteOrder").setId(script::Type::QPixelFormatByteOrder).get();

  byte_order.addValue("LittleEndian", QPixelFormat::LittleEndian);
  byte_order.addValue("BigEndian", QPixelFormat::BigEndian);
  byte_order.addValue("CurrentSystemEndian", QPixelFormat::CurrentSystemEndian);
}
#endif


#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
static void register_pixel_format_class(script::Namespace ns)
{
  using namespace script;

  Class pixel_format = ns.newClass("PixelFormat").setId(script::Type::QPixelFormat).get();

#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  register_pixel_format_color_model_enum(pixel_format);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  register_pixel_format_alpha_usage_enum(pixel_format);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  register_pixel_format_alpha_position_enum(pixel_format);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  register_pixel_format_alpha_premultiplied_enum(pixel_format);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  register_pixel_format_type_interpretation_enum(pixel_format);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  register_pixel_format_y_u_v_layout_enum(pixel_format);
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  register_pixel_format_byte_order_enum(pixel_format);
#endif

  // QPixelFormat();
  bind::default_constructor<QPixelFormat>(pixel_format).create();
  // QPixelFormat(const QPixelFormat &);
  bind::constructor<QPixelFormat, const QPixelFormat &>(pixel_format).create();
  // ~QPixelFormat();
  bind::destructor<QPixelFormat>(pixel_format).create();
  // QPixelFormat & operator=(const QPixelFormat &);
  bind::memop_assign<QPixelFormat, const QPixelFormat &>(pixel_format);
  // QPixelFormat(QPixelFormat::ColorModel, uchar, uchar, uchar, uchar, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, QPixelFormat::ByteOrder, uchar);
  /// TODO: QPixelFormat(QPixelFormat::ColorModel, uchar, uchar, uchar, uchar, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, QPixelFormat::ByteOrder, uchar);
  // QPixelFormat::ColorModel colorModel() const;
  bind::member_function<QPixelFormat, QPixelFormat::ColorModel, &QPixelFormat::colorModel>(pixel_format, "colorModel").create();
  // uchar channelCount() const;
  /// TODO: uchar channelCount() const;
  // uchar redSize() const;
  /// TODO: uchar redSize() const;
  // uchar greenSize() const;
  /// TODO: uchar greenSize() const;
  // uchar blueSize() const;
  /// TODO: uchar blueSize() const;
  // uchar cyanSize() const;
  /// TODO: uchar cyanSize() const;
  // uchar magentaSize() const;
  /// TODO: uchar magentaSize() const;
  // uchar yellowSize() const;
  /// TODO: uchar yellowSize() const;
  // uchar blackSize() const;
  /// TODO: uchar blackSize() const;
  // uchar hueSize() const;
  /// TODO: uchar hueSize() const;
  // uchar saturationSize() const;
  /// TODO: uchar saturationSize() const;
  // uchar lightnessSize() const;
  /// TODO: uchar lightnessSize() const;
  // uchar brightnessSize() const;
  /// TODO: uchar brightnessSize() const;
  // uchar alphaSize() const;
  /// TODO: uchar alphaSize() const;
  // uchar bitsPerPixel() const;
  /// TODO: uchar bitsPerPixel() const;
  // QPixelFormat::AlphaUsage alphaUsage() const;
  bind::member_function<QPixelFormat, QPixelFormat::AlphaUsage, &QPixelFormat::alphaUsage>(pixel_format, "alphaUsage").create();
  // QPixelFormat::AlphaPosition alphaPosition() const;
  bind::member_function<QPixelFormat, QPixelFormat::AlphaPosition, &QPixelFormat::alphaPosition>(pixel_format, "alphaPosition").create();
  // QPixelFormat::AlphaPremultiplied premultiplied() const;
  bind::member_function<QPixelFormat, QPixelFormat::AlphaPremultiplied, &QPixelFormat::premultiplied>(pixel_format, "premultiplied").create();
  // QPixelFormat::TypeInterpretation typeInterpretation() const;
  bind::member_function<QPixelFormat, QPixelFormat::TypeInterpretation, &QPixelFormat::typeInterpretation>(pixel_format, "typeInterpretation").create();
  // QPixelFormat::ByteOrder byteOrder() const;
  bind::member_function<QPixelFormat, QPixelFormat::ByteOrder, &QPixelFormat::byteOrder>(pixel_format, "byteOrder").create();
  // QPixelFormat::YUVLayout yuvLayout() const;
  bind::member_function<QPixelFormat, QPixelFormat::YUVLayout, &QPixelFormat::yuvLayout>(pixel_format, "yuvLayout").create();
  // uchar subEnum() const;
  /// TODO: uchar subEnum() const;
}
#endif


void register_pixelformat_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

#if (QT_VERSION >= QT_VERSION_CHECK(5, 4, 0))
  register_pixel_format_class(ns);
#endif

  // QPixelFormat qPixelFormatRgba(uchar, uchar, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation);
  /// TODO: QPixelFormat qPixelFormatRgba(uchar, uchar, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation);
  // QPixelFormat qPixelFormatGrayscale(uchar, QPixelFormat::TypeInterpretation);
  /// TODO: QPixelFormat qPixelFormatGrayscale(uchar, QPixelFormat::TypeInterpretation);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QPixelFormat qPixelFormatAlpha(uchar, QPixelFormat::TypeInterpretation);
  /// TODO: QPixelFormat qPixelFormatAlpha(uchar, QPixelFormat::TypeInterpretation);
#endif
  // QPixelFormat qPixelFormatCmyk(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  /// TODO: QPixelFormat qPixelFormatCmyk(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  // QPixelFormat qPixelFormatHsl(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  /// TODO: QPixelFormat qPixelFormatHsl(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  // QPixelFormat qPixelFormatHsv(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  /// TODO: QPixelFormat qPixelFormatHsv(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  // QPixelFormat qPixelFormatYuv(QPixelFormat::YUVLayout, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, QPixelFormat::ByteOrder);
  /// TODO: QPixelFormat qPixelFormatYuv(QPixelFormat::YUVLayout, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, QPixelFormat::ByteOrder);
}

