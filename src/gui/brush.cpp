// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/brush.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/gui/brush.h"
#include "yasl/gui/color.h"
#include "yasl/gui/image.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_brush_class(script::Namespace ns)
{
  using namespace script;

  Class brush = ns.newClass("Brush").setId(script::Type::QBrush).get();


  // QBrush();
  bind::default_constructor<QBrush>(brush).create();
  // QBrush(Qt::BrushStyle);
  bind::constructor<QBrush, Qt::BrushStyle>(brush).create();
  // QBrush(const QColor &, Qt::BrushStyle = Qt::SolidPattern);
  bind::constructor<QBrush, const QColor &, Qt::BrushStyle>(brush)
    .apply(bind::default_arguments(Qt::SolidPattern)).create();
  // QBrush(Qt::GlobalColor, Qt::BrushStyle = Qt::SolidPattern);
  bind::constructor<QBrush, Qt::GlobalColor, Qt::BrushStyle>(brush)
    .apply(bind::default_arguments(Qt::SolidPattern)).create();
  // QBrush(const QColor &, const QPixmap &);
  bind::constructor<QBrush, const QColor &, const QPixmap &>(brush).create();
  // QBrush(Qt::GlobalColor, const QPixmap &);
  bind::constructor<QBrush, Qt::GlobalColor, const QPixmap &>(brush).create();
  // QBrush(const QPixmap &);
  bind::constructor<QBrush, const QPixmap &>(brush).create();
  // QBrush(const QImage &);
  bind::constructor<QBrush, const QImage &>(brush).create();
  // QBrush(const QBrush &);
  bind::constructor<QBrush, const QBrush &>(brush).create();
  // QBrush(const QGradient &);
  bind::constructor<QBrush, const QGradient &>(brush).create();
  // ~QBrush();
  bind::destructor<QBrush>(brush).create();
  // QBrush & operator=(const QBrush &);
  bind::memop_assign<QBrush, const QBrush &>(brush);
  // QBrush & operator=(QBrush &&);
  bind::memop_assign<QBrush, QBrush &&>(brush);
  // void swap(QBrush &);
  bind::void_member_function<QBrush, QBrush &, &QBrush::swap>(brush, "swap").create();
  // Qt::BrushStyle style() const;
  bind::member_function<QBrush, Qt::BrushStyle, &QBrush::style>(brush, "style").create();
  // void setStyle(Qt::BrushStyle);
  bind::void_member_function<QBrush, Qt::BrushStyle, &QBrush::setStyle>(brush, "setStyle").create();
  // const QMatrix & matrix() const;
  /// TODO: const QMatrix & matrix() const;
  // void setMatrix(const QMatrix &);
  /// TODO: void setMatrix(const QMatrix &);
  // QTransform transform() const;
  bind::member_function<QBrush, QTransform, &QBrush::transform>(brush, "transform").create();
  // void setTransform(const QTransform &);
  bind::void_member_function<QBrush, const QTransform &, &QBrush::setTransform>(brush, "setTransform").create();
  // QPixmap texture() const;
  bind::member_function<QBrush, QPixmap, &QBrush::texture>(brush, "texture").create();
  // void setTexture(const QPixmap &);
  bind::void_member_function<QBrush, const QPixmap &, &QBrush::setTexture>(brush, "setTexture").create();
  // QImage textureImage() const;
  bind::member_function<QBrush, QImage, &QBrush::textureImage>(brush, "textureImage").create();
  // void setTextureImage(const QImage &);
  bind::void_member_function<QBrush, const QImage &, &QBrush::setTextureImage>(brush, "setTextureImage").create();
  // const QColor & color() const;
  bind::member_function<QBrush, const QColor &, &QBrush::color>(brush, "color").create();
  // void setColor(const QColor &);
  bind::void_member_function<QBrush, const QColor &, &QBrush::setColor>(brush, "setColor").create();
  // void setColor(Qt::GlobalColor);
  bind::void_member_function<QBrush, Qt::GlobalColor, &QBrush::setColor>(brush, "setColor").create();
  // const QGradient * gradient() const;
  /// TODO: const QGradient * gradient() const;
  // bool isOpaque() const;
  bind::member_function<QBrush, bool, &QBrush::isOpaque>(brush, "isOpaque").create();
  // bool operator==(const QBrush &) const;
  bind::memop_eq<QBrush, const QBrush &>(brush);
  // bool operator!=(const QBrush &) const;
  bind::memop_neq<QBrush, const QBrush &>(brush);
  // bool isDetached() const;
  bind::member_function<QBrush, bool, &QBrush::isDetached>(brush, "isDetached").create();
  // QBrush::DataPtr & data_ptr();
  /// TODO: QBrush::DataPtr & data_ptr();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QBrush, QMetaType::QBrush>>();
}


static void register_gradient_type_enum(script::Class gradient)
{
  using namespace script;

  Enum type = gradient.newEnum("Type").setId(script::Type::QGradientType).get();

  type.addValue("LinearGradient", QGradient::LinearGradient);
  type.addValue("RadialGradient", QGradient::RadialGradient);
  type.addValue("ConicalGradient", QGradient::ConicalGradient);
  type.addValue("NoGradient", QGradient::NoGradient);
}


static void register_gradient_spread_enum(script::Class gradient)
{
  using namespace script;

  Enum spread = gradient.newEnum("Spread").setId(script::Type::QGradientSpread).get();

  spread.addValue("PadSpread", QGradient::PadSpread);
  spread.addValue("ReflectSpread", QGradient::ReflectSpread);
  spread.addValue("RepeatSpread", QGradient::RepeatSpread);
}


static void register_gradient_coordinate_mode_enum(script::Class gradient)
{
  using namespace script;

  Enum coordinate_mode = gradient.newEnum("CoordinateMode").setId(script::Type::QGradientCoordinateMode).get();

  coordinate_mode.addValue("LogicalMode", QGradient::LogicalMode);
  coordinate_mode.addValue("StretchToDeviceMode", QGradient::StretchToDeviceMode);
  coordinate_mode.addValue("ObjectBoundingMode", QGradient::ObjectBoundingMode);
}


static void register_gradient_interpolation_mode_enum(script::Class gradient)
{
  using namespace script;

  Enum interpolation_mode = gradient.newEnum("InterpolationMode").setId(script::Type::QGradientInterpolationMode).get();

  interpolation_mode.addValue("ColorInterpolation", QGradient::ColorInterpolation);
  interpolation_mode.addValue("ComponentInterpolation", QGradient::ComponentInterpolation);
}


static void register_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class gradient = ns.newClass("Gradient").setId(script::Type::QGradient).get();

  register_gradient_type_enum(gradient);
  register_gradient_spread_enum(gradient);
  register_gradient_coordinate_mode_enum(gradient);
  register_gradient_interpolation_mode_enum(gradient);

  // QGradient();
  bind::default_constructor<QGradient>(gradient).create();
  // QGradient::Type type() const;
  bind::member_function<QGradient, QGradient::Type, &QGradient::type>(gradient, "type").create();
  // void setSpread(QGradient::Spread);
  bind::void_member_function<QGradient, QGradient::Spread, &QGradient::setSpread>(gradient, "setSpread").create();
  // QGradient::Spread spread() const;
  bind::member_function<QGradient, QGradient::Spread, &QGradient::spread>(gradient, "spread").create();
  // void setColorAt(qreal, const QColor &);
  bind::void_member_function<QGradient, qreal, const QColor &, &QGradient::setColorAt>(gradient, "setColorAt").create();
  // void setStops(const QGradientStops &);
  /// TODO: void setStops(const QGradientStops &);
  // QGradientStops stops() const;
  /// TODO: QGradientStops stops() const;
  // QGradient::CoordinateMode coordinateMode() const;
  bind::member_function<QGradient, QGradient::CoordinateMode, &QGradient::coordinateMode>(gradient, "coordinateMode").create();
  // void setCoordinateMode(QGradient::CoordinateMode);
  bind::void_member_function<QGradient, QGradient::CoordinateMode, &QGradient::setCoordinateMode>(gradient, "setCoordinateMode").create();
  // QGradient::InterpolationMode interpolationMode() const;
  bind::member_function<QGradient, QGradient::InterpolationMode, &QGradient::interpolationMode>(gradient, "interpolationMode").create();
  // void setInterpolationMode(QGradient::InterpolationMode);
  bind::void_member_function<QGradient, QGradient::InterpolationMode, &QGradient::setInterpolationMode>(gradient, "setInterpolationMode").create();
  // bool operator==(const QGradient &) const;
  bind::memop_eq<QGradient, const QGradient &>(gradient);
  // bool operator!=(const QGradient &) const;
  bind::memop_neq<QGradient, const QGradient &>(gradient);
}


static void register_linear_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class linear_gradient = ns.newClass("LinearGradient").setId(script::Type::QLinearGradient)
    .setBase(script::Type::QGradient).get();


  // QLinearGradient();
  bind::default_constructor<QLinearGradient>(linear_gradient).create();
  // QLinearGradient(const QLinearGradient &);
  bind::constructor<QLinearGradient, const QLinearGradient &>(linear_gradient).create();
  // ~QLinearGradient();
  bind::destructor<QLinearGradient>(linear_gradient).create();
  // QLinearGradient & operator=(const QLinearGradient &);
  bind::memop_assign<QLinearGradient, const QLinearGradient &>(linear_gradient);
  // QLinearGradient(const QPointF &, const QPointF &);
  bind::constructor<QLinearGradient, const QPointF &, const QPointF &>(linear_gradient).create();
  // QLinearGradient(qreal, qreal, qreal, qreal);
  bind::constructor<QLinearGradient, qreal, qreal, qreal, qreal>(linear_gradient).create();
  // QPointF start() const;
  bind::member_function<QLinearGradient, QPointF, &QLinearGradient::start>(linear_gradient, "start").create();
  // void setStart(const QPointF &);
  bind::void_member_function<QLinearGradient, const QPointF &, &QLinearGradient::setStart>(linear_gradient, "setStart").create();
  // void setStart(qreal, qreal);
  bind::void_member_function<QLinearGradient, qreal, qreal, &QLinearGradient::setStart>(linear_gradient, "setStart").create();
  // QPointF finalStop() const;
  bind::member_function<QLinearGradient, QPointF, &QLinearGradient::finalStop>(linear_gradient, "finalStop").create();
  // void setFinalStop(const QPointF &);
  bind::void_member_function<QLinearGradient, const QPointF &, &QLinearGradient::setFinalStop>(linear_gradient, "setFinalStop").create();
  // void setFinalStop(qreal, qreal);
  bind::void_member_function<QLinearGradient, qreal, qreal, &QLinearGradient::setFinalStop>(linear_gradient, "setFinalStop").create();
}


static void register_radial_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class radial_gradient = ns.newClass("RadialGradient").setId(script::Type::QRadialGradient)
    .setBase(script::Type::QGradient).get();


  // QRadialGradient();
  bind::default_constructor<QRadialGradient>(radial_gradient).create();
  // QRadialGradient(const QRadialGradient &);
  bind::constructor<QRadialGradient, const QRadialGradient &>(radial_gradient).create();
  // QRadialGradient & operator=(const QRadialGradient &);
  bind::memop_assign<QRadialGradient, const QRadialGradient &>(radial_gradient);
  // ~QRadialGradient();
  bind::destructor<QRadialGradient>(radial_gradient).create();
  // QRadialGradient(const QPointF &, qreal, const QPointF &);
  bind::constructor<QRadialGradient, const QPointF &, qreal, const QPointF &>(radial_gradient).create();
  // QRadialGradient(qreal, qreal, qreal, qreal, qreal);
  bind::constructor<QRadialGradient, qreal, qreal, qreal, qreal, qreal>(radial_gradient).create();
  // QRadialGradient(const QPointF &, qreal);
  bind::constructor<QRadialGradient, const QPointF &, qreal>(radial_gradient).create();
  // QRadialGradient(qreal, qreal, qreal);
  bind::constructor<QRadialGradient, qreal, qreal, qreal>(radial_gradient).create();
  // QRadialGradient(const QPointF &, qreal, const QPointF &, qreal);
  bind::constructor<QRadialGradient, const QPointF &, qreal, const QPointF &, qreal>(radial_gradient).create();
  // QRadialGradient(qreal, qreal, qreal, qreal, qreal, qreal);
  bind::constructor<QRadialGradient, qreal, qreal, qreal, qreal, qreal, qreal>(radial_gradient).create();
  // QPointF center() const;
  bind::member_function<QRadialGradient, QPointF, &QRadialGradient::center>(radial_gradient, "center").create();
  // void setCenter(const QPointF &);
  bind::void_member_function<QRadialGradient, const QPointF &, &QRadialGradient::setCenter>(radial_gradient, "setCenter").create();
  // void setCenter(qreal, qreal);
  bind::void_member_function<QRadialGradient, qreal, qreal, &QRadialGradient::setCenter>(radial_gradient, "setCenter").create();
  // QPointF focalPoint() const;
  bind::member_function<QRadialGradient, QPointF, &QRadialGradient::focalPoint>(radial_gradient, "focalPoint").create();
  // void setFocalPoint(const QPointF &);
  bind::void_member_function<QRadialGradient, const QPointF &, &QRadialGradient::setFocalPoint>(radial_gradient, "setFocalPoint").create();
  // void setFocalPoint(qreal, qreal);
  bind::void_member_function<QRadialGradient, qreal, qreal, &QRadialGradient::setFocalPoint>(radial_gradient, "setFocalPoint").create();
  // qreal radius() const;
  bind::member_function<QRadialGradient, qreal, &QRadialGradient::radius>(radial_gradient, "radius").create();
  // void setRadius(qreal);
  bind::void_member_function<QRadialGradient, qreal, &QRadialGradient::setRadius>(radial_gradient, "setRadius").create();
  // qreal centerRadius() const;
  bind::member_function<QRadialGradient, qreal, &QRadialGradient::centerRadius>(radial_gradient, "centerRadius").create();
  // void setCenterRadius(qreal);
  bind::void_member_function<QRadialGradient, qreal, &QRadialGradient::setCenterRadius>(radial_gradient, "setCenterRadius").create();
  // qreal focalRadius() const;
  bind::member_function<QRadialGradient, qreal, &QRadialGradient::focalRadius>(radial_gradient, "focalRadius").create();
  // void setFocalRadius(qreal);
  bind::void_member_function<QRadialGradient, qreal, &QRadialGradient::setFocalRadius>(radial_gradient, "setFocalRadius").create();
}


static void register_conical_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class conical_gradient = ns.newClass("ConicalGradient").setId(script::Type::QConicalGradient)
    .setBase(script::Type::QGradient).get();


  // QConicalGradient();
  bind::default_constructor<QConicalGradient>(conical_gradient).create();
  // QConicalGradient(const QConicalGradient &);
  bind::constructor<QConicalGradient, const QConicalGradient &>(conical_gradient).create();
  // QConicalGradient & operator=(const QConicalGradient &);
  bind::memop_assign<QConicalGradient, const QConicalGradient &>(conical_gradient);
  // ~QConicalGradient();
  bind::destructor<QConicalGradient>(conical_gradient).create();
  // QConicalGradient(const QPointF &, qreal);
  bind::constructor<QConicalGradient, const QPointF &, qreal>(conical_gradient).create();
  // QConicalGradient(qreal, qreal, qreal);
  bind::constructor<QConicalGradient, qreal, qreal, qreal>(conical_gradient).create();
  // QPointF center() const;
  bind::member_function<QConicalGradient, QPointF, &QConicalGradient::center>(conical_gradient, "center").create();
  // void setCenter(const QPointF &);
  bind::void_member_function<QConicalGradient, const QPointF &, &QConicalGradient::setCenter>(conical_gradient, "setCenter").create();
  // void setCenter(qreal, qreal);
  bind::void_member_function<QConicalGradient, qreal, qreal, &QConicalGradient::setCenter>(conical_gradient, "setCenter").create();
  // qreal angle() const;
  bind::member_function<QConicalGradient, qreal, &QConicalGradient::angle>(conical_gradient, "angle").create();
  // void setAngle(qreal);
  bind::void_member_function<QConicalGradient, qreal, &QConicalGradient::setAngle>(conical_gradient, "setAngle").create();
}


void register_brush_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_brush_class(ns);
  register_gradient_class(ns);
  register_linear_gradient_class(ns);
  register_radial_gradient_class(ns);
  register_conical_gradient_class(ns);

  // void swap(QBrush &, QBrush &);
  bind::void_function<QBrush &, QBrush &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QBrush &);
  bind::op_put_to<QDataStream &, const QBrush &>(ns);
  // QDataStream & operator>>(QDataStream &, QBrush &);
  bind::op_read_from<QDataStream &, QBrush &>(ns);
  // QDebug operator<<(QDebug, const QBrush &);
  /// TODO: QDebug operator<<(QDebug, const QBrush &);
}

