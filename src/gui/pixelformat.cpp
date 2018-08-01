// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/pixelformat.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

static void register_pixel_format_alpha_position_enum(script::Class pixel_format)
{
  using namespace script;

  Enum alpha_position = pixel_format.Enum("AlphaPosition").setId(script::Type::QPixelFormatAlphaPosition).get();

  alpha_position.addValue("AtBeginning", QPixelFormat::AtBeginning);
  alpha_position.addValue("AtEnd", QPixelFormat::AtEnd);
}

static void register_pixel_format_alpha_premultiplied_enum(script::Class pixel_format)
{
  using namespace script;

  Enum alpha_premultiplied = pixel_format.Enum("AlphaPremultiplied").setId(script::Type::QPixelFormatAlphaPremultiplied).get();

  alpha_premultiplied.addValue("NotPremultiplied", QPixelFormat::NotPremultiplied);
  alpha_premultiplied.addValue("Premultiplied", QPixelFormat::Premultiplied);
}

static void register_pixel_format_alpha_usage_enum(script::Class pixel_format)
{
  using namespace script;

  Enum alpha_usage = pixel_format.Enum("AlphaUsage").setId(script::Type::QPixelFormatAlphaUsage).get();

  alpha_usage.addValue("IgnoresAlpha", QPixelFormat::IgnoresAlpha);
  alpha_usage.addValue("UsesAlpha", QPixelFormat::UsesAlpha);
}

static void register_pixel_format_byte_order_enum(script::Class pixel_format)
{
  using namespace script;

  Enum byte_order = pixel_format.Enum("ByteOrder").setId(script::Type::QPixelFormatByteOrder).get();

  byte_order.addValue("BigEndian", QPixelFormat::BigEndian);
  byte_order.addValue("CurrentSystemEndian", QPixelFormat::CurrentSystemEndian);
  byte_order.addValue("LittleEndian", QPixelFormat::LittleEndian);
}

static void register_pixel_format_color_model_enum(script::Class pixel_format)
{
  using namespace script;

  Enum color_model = pixel_format.Enum("ColorModel").setId(script::Type::QPixelFormatColorModel).get();

  color_model.addValue("Alpha", QPixelFormat::Alpha);
  color_model.addValue("BGR", QPixelFormat::BGR);
  color_model.addValue("CMYK", QPixelFormat::CMYK);
  color_model.addValue("Grayscale", QPixelFormat::Grayscale);
  color_model.addValue("HSL", QPixelFormat::HSL);
  color_model.addValue("HSV", QPixelFormat::HSV);
  color_model.addValue("Indexed", QPixelFormat::Indexed);
  color_model.addValue("RGB", QPixelFormat::RGB);
  color_model.addValue("YUV", QPixelFormat::YUV);
}

static void register_pixel_format_type_interpretation_enum(script::Class pixel_format)
{
  using namespace script;

  Enum type_interpretation = pixel_format.Enum("TypeInterpretation").setId(script::Type::QPixelFormatTypeInterpretation).get();

  type_interpretation.addValue("FloatingPoint", QPixelFormat::FloatingPoint);
  type_interpretation.addValue("UnsignedByte", QPixelFormat::UnsignedByte);
  type_interpretation.addValue("UnsignedInteger", QPixelFormat::UnsignedInteger);
  type_interpretation.addValue("UnsignedShort", QPixelFormat::UnsignedShort);
}

static void register_pixel_format_y_u_v_layout_enum(script::Class pixel_format)
{
  using namespace script;

  Enum y_u_v_layout = pixel_format.Enum("YUVLayout").setId(script::Type::QPixelFormatYUVLayout).get();

  y_u_v_layout.addValue("IMC1", QPixelFormat::IMC1);
  y_u_v_layout.addValue("IMC2", QPixelFormat::IMC2);
  y_u_v_layout.addValue("IMC3", QPixelFormat::IMC3);
  y_u_v_layout.addValue("IMC4", QPixelFormat::IMC4);
  y_u_v_layout.addValue("NV12", QPixelFormat::NV12);
  y_u_v_layout.addValue("NV21", QPixelFormat::NV21);
  y_u_v_layout.addValue("UYVY", QPixelFormat::UYVY);
  y_u_v_layout.addValue("Y16", QPixelFormat::Y16);
  y_u_v_layout.addValue("Y8", QPixelFormat::Y8);
  y_u_v_layout.addValue("YUV411", QPixelFormat::YUV411);
  y_u_v_layout.addValue("YUV420P", QPixelFormat::YUV420P);
  y_u_v_layout.addValue("YUV420SP", QPixelFormat::YUV420SP);
  y_u_v_layout.addValue("YUV422", QPixelFormat::YUV422);
  y_u_v_layout.addValue("YUV444", QPixelFormat::YUV444);
  y_u_v_layout.addValue("YUYV", QPixelFormat::YUYV);
  y_u_v_layout.addValue("YV12", QPixelFormat::YV12);
}

static void register_pixel_format_class(script::Namespace ns)
{
  using namespace script;

  Class pixel_format = ns.Class("PixelFormat").setId(script::Type::QPixelFormat).get();

  register_pixel_format_alpha_position_enum(pixel_format);
  register_pixel_format_alpha_premultiplied_enum(pixel_format);
  register_pixel_format_alpha_usage_enum(pixel_format);
  register_pixel_format_byte_order_enum(pixel_format);
  register_pixel_format_color_model_enum(pixel_format);
  register_pixel_format_type_interpretation_enum(pixel_format);
  register_pixel_format_y_u_v_layout_enum(pixel_format);
  binding::Class<QPixelFormat> binder{ pixel_format };

  // ~QPixelFormat();
  binder.add_dtor();
  // QPixelFormat();
  binder.ctors().add_default();
  // QPixelFormat(QPixelFormat::ColorModel, uchar, uchar, uchar, uchar, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, QPixelFormat::ByteOrder, uchar);
  /// TODO: binder.ctors().add<QPixelFormat::ColorModel, uchar, uchar, uchar, uchar, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, QPixelFormat::ByteOrder, uchar>();
  // QPixelFormat::ColorModel colorModel() const;
  binder.add_fun<QPixelFormat::ColorModel, &QPixelFormat::colorModel>("colorModel");
  // uchar channelCount() const;
  binder.add_fun<uchar, &QPixelFormat::channelCount>("channelCount");
  // uchar redSize() const;
  binder.add_fun<uchar, &QPixelFormat::redSize>("redSize");
  // uchar greenSize() const;
  binder.add_fun<uchar, &QPixelFormat::greenSize>("greenSize");
  // uchar blueSize() const;
  binder.add_fun<uchar, &QPixelFormat::blueSize>("blueSize");
  // uchar cyanSize() const;
  binder.add_fun<uchar, &QPixelFormat::cyanSize>("cyanSize");
  // uchar magentaSize() const;
  binder.add_fun<uchar, &QPixelFormat::magentaSize>("magentaSize");
  // uchar yellowSize() const;
  binder.add_fun<uchar, &QPixelFormat::yellowSize>("yellowSize");
  // uchar blackSize() const;
  binder.add_fun<uchar, &QPixelFormat::blackSize>("blackSize");
  // uchar hueSize() const;
  binder.add_fun<uchar, &QPixelFormat::hueSize>("hueSize");
  // uchar saturationSize() const;
  binder.add_fun<uchar, &QPixelFormat::saturationSize>("saturationSize");
  // uchar lightnessSize() const;
  binder.add_fun<uchar, &QPixelFormat::lightnessSize>("lightnessSize");
  // uchar brightnessSize() const;
  binder.add_fun<uchar, &QPixelFormat::brightnessSize>("brightnessSize");
  // uchar alphaSize() const;
  binder.add_fun<uchar, &QPixelFormat::alphaSize>("alphaSize");
  // uchar bitsPerPixel() const;
  binder.add_fun<uchar, &QPixelFormat::bitsPerPixel>("bitsPerPixel");
  // QPixelFormat::AlphaUsage alphaUsage() const;
  binder.add_fun<QPixelFormat::AlphaUsage, &QPixelFormat::alphaUsage>("alphaUsage");
  // QPixelFormat::AlphaPosition alphaPosition() const;
  binder.add_fun<QPixelFormat::AlphaPosition, &QPixelFormat::alphaPosition>("alphaPosition");
  // QPixelFormat::AlphaPremultiplied premultiplied() const;
  binder.add_fun<QPixelFormat::AlphaPremultiplied, &QPixelFormat::premultiplied>("premultiplied");
  // QPixelFormat::TypeInterpretation typeInterpretation() const;
  binder.add_fun<QPixelFormat::TypeInterpretation, &QPixelFormat::typeInterpretation>("typeInterpretation");
  // QPixelFormat::ByteOrder byteOrder() const;
  binder.add_fun<QPixelFormat::ByteOrder, &QPixelFormat::byteOrder>("byteOrder");
  // QPixelFormat::YUVLayout yuvLayout() const;
  binder.add_fun<QPixelFormat::YUVLayout, &QPixelFormat::yuvLayout>("yuvLayout");
  // uchar subEnum() const;
  binder.add_fun<uchar, &QPixelFormat::subEnum>("subEnum");
}

void register_pixelformat_file(script::Namespace root)
{
  using namespace script;

  register_pixel_format_class(root);
  binding::Namespace binder{ root };

  // QPixelFormat qPixelFormatRgba(uchar, uchar, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation);
  /// TODO: binder.add_fun<QPixelFormat, uchar, uchar, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, &qPixelFormatRgba>("qPixelFormatRgba");
  // QPixelFormat qPixelFormatGrayscale(uchar, QPixelFormat::TypeInterpretation);
  binder.add_fun<QPixelFormat, uchar, QPixelFormat::TypeInterpretation, &qPixelFormatGrayscale>("qPixelFormatGrayscale");
  // QPixelFormat qPixelFormatAlpha(uchar, QPixelFormat::TypeInterpretation);
  binder.add_fun<QPixelFormat, uchar, QPixelFormat::TypeInterpretation, &qPixelFormatAlpha>("qPixelFormatAlpha");
  // QPixelFormat qPixelFormatCmyk(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  /// TODO: binder.add_fun<QPixelFormat, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation, &qPixelFormatCmyk>("qPixelFormatCmyk");
  // QPixelFormat qPixelFormatHsl(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  /// TODO: binder.add_fun<QPixelFormat, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation, &qPixelFormatHsl>("qPixelFormatHsl");
  // QPixelFormat qPixelFormatHsv(uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation);
  /// TODO: binder.add_fun<QPixelFormat, uchar, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::TypeInterpretation, &qPixelFormatHsv>("qPixelFormatHsv");
  // QPixelFormat qPixelFormatYuv(QPixelFormat::YUVLayout, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, QPixelFormat::ByteOrder);
  /// TODO: binder.add_fun<QPixelFormat, QPixelFormat::YUVLayout, uchar, QPixelFormat::AlphaUsage, QPixelFormat::AlphaPosition, QPixelFormat::AlphaPremultiplied, QPixelFormat::TypeInterpretation, QPixelFormat::ByteOrder, &qPixelFormatYuv>("qPixelFormatYuv");
}

