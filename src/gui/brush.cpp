// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/brush.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

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

  Class brush = ns.Class("Brush").setId(script::Type::QBrush).get();

  binding::Class<QBrush> binder{ brush };

  // QBrush();
  binder.ctors().add_default();
  // QBrush(Qt::BrushStyle);
  binder.ctors().add<Qt::BrushStyle>();
  // QBrush(const QColor &, Qt::BrushStyle);
  binder.ctors().add<const QColor &, Qt::BrushStyle>();
  // QBrush(Qt::GlobalColor, Qt::BrushStyle);
  binder.ctors().add<Qt::GlobalColor, Qt::BrushStyle>();
  // QBrush(const QColor &, const QPixmap &);
  binder.ctors().add<const QColor &, const QPixmap &>();
  // QBrush(Qt::GlobalColor, const QPixmap &);
  binder.ctors().add<Qt::GlobalColor, const QPixmap &>();
  // QBrush(const QPixmap &);
  binder.ctors().add<const QPixmap &>();
  // QBrush(const QImage &);
  binder.ctors().add<const QImage &>();
  // QBrush(const QBrush &);
  binder.ctors().add<const QBrush &>();
  // QBrush(const QGradient &);
  binder.ctors().add<const QGradient &>();
  // ~QBrush();
  binder.add_dtor();
  // QBrush & operator=(const QBrush &);
  binder.operators().assign<const QBrush &>();
  // QBrush & operator=(QBrush &&);
  binder.operators().assign<QBrush &&>();
  // void swap(QBrush &);
  binder.add_void_fun<QBrush &, &QBrush::swap>("swap");
  // Qt::BrushStyle style() const;
  binder.add_fun<Qt::BrushStyle, &QBrush::style>("style");
  // void setStyle(Qt::BrushStyle);
  binder.add_void_fun<Qt::BrushStyle, &QBrush::setStyle>("setStyle");
  // const QMatrix & matrix() const;
  /// TODO: const QMatrix & matrix() const;
  // void setMatrix(const QMatrix &);
  /// TODO: void setMatrix(const QMatrix &);
  // QTransform transform() const;
  binder.add_fun<QTransform, &QBrush::transform>("transform");
  // void setTransform(const QTransform &);
  binder.add_void_fun<const QTransform &, &QBrush::setTransform>("setTransform");
  // QPixmap texture() const;
  binder.add_fun<QPixmap, &QBrush::texture>("texture");
  // void setTexture(const QPixmap &);
  binder.add_void_fun<const QPixmap &, &QBrush::setTexture>("setTexture");
  // QImage textureImage() const;
  binder.add_fun<QImage, &QBrush::textureImage>("textureImage");
  // void setTextureImage(const QImage &);
  binder.add_void_fun<const QImage &, &QBrush::setTextureImage>("setTextureImage");
  // const QColor & color() const;
  binder.add_fun<const QColor &, &QBrush::color>("color");
  // void setColor(const QColor &);
  binder.add_void_fun<const QColor &, &QBrush::setColor>("setColor");
  // void setColor(Qt::GlobalColor);
  binder.add_void_fun<Qt::GlobalColor, &QBrush::setColor>("setColor");
  // const QGradient * gradient() const;
  /// TODO: const QGradient * gradient() const;
  // bool isOpaque() const;
  binder.add_fun<bool, &QBrush::isOpaque>("isOpaque");
  // bool operator==(const QBrush &) const;
  binder.operators().eq<const QBrush &>();
  // bool operator!=(const QBrush &) const;
  binder.operators().neq<const QBrush &>();
  // bool isDetached() const;
  binder.add_fun<bool, &QBrush::isDetached>("isDetached");
  // QBrush::DataPtr & data_ptr();
  /// TODO: QBrush::DataPtr & data_ptr();
}


static void register_gradient_type_enum(script::Class gradient)
{
  using namespace script;

  Enum type = gradient.Enum("Type").setId(script::Type::QGradientType).get();

  type.addValue("LinearGradient", QGradient::LinearGradient);
  type.addValue("RadialGradient", QGradient::RadialGradient);
  type.addValue("ConicalGradient", QGradient::ConicalGradient);
  type.addValue("NoGradient", QGradient::NoGradient);
}


static void register_gradient_spread_enum(script::Class gradient)
{
  using namespace script;

  Enum spread = gradient.Enum("Spread").setId(script::Type::QGradientSpread).get();

  spread.addValue("PadSpread", QGradient::PadSpread);
  spread.addValue("ReflectSpread", QGradient::ReflectSpread);
  spread.addValue("RepeatSpread", QGradient::RepeatSpread);
}


static void register_gradient_coordinate_mode_enum(script::Class gradient)
{
  using namespace script;

  Enum coordinate_mode = gradient.Enum("CoordinateMode").setId(script::Type::QGradientCoordinateMode).get();

  coordinate_mode.addValue("LogicalMode", QGradient::LogicalMode);
  coordinate_mode.addValue("StretchToDeviceMode", QGradient::StretchToDeviceMode);
  coordinate_mode.addValue("ObjectBoundingMode", QGradient::ObjectBoundingMode);
}


static void register_gradient_interpolation_mode_enum(script::Class gradient)
{
  using namespace script;

  Enum interpolation_mode = gradient.Enum("InterpolationMode").setId(script::Type::QGradientInterpolationMode).get();

  interpolation_mode.addValue("ColorInterpolation", QGradient::ColorInterpolation);
  interpolation_mode.addValue("ComponentInterpolation", QGradient::ComponentInterpolation);
}


static void register_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class gradient = ns.Class("Gradient").setId(script::Type::QGradient).get();

  register_gradient_type_enum(gradient);
  register_gradient_spread_enum(gradient);
  register_gradient_coordinate_mode_enum(gradient);
  register_gradient_interpolation_mode_enum(gradient);
  binding::Class<QGradient> binder{ gradient };

  // QGradient();
  binder.ctors().add_default();
  // QGradient::Type type() const;
  binder.add_fun<QGradient::Type, &QGradient::type>("type");
  // void setSpread(QGradient::Spread);
  binder.add_void_fun<QGradient::Spread, &QGradient::setSpread>("setSpread");
  // QGradient::Spread spread() const;
  binder.add_fun<QGradient::Spread, &QGradient::spread>("spread");
  // void setColorAt(qreal, const QColor &);
  binder.add_void_fun<qreal, const QColor &, &QGradient::setColorAt>("setColorAt");
  // void setStops(const QGradientStops &);
  /// TODO: void setStops(const QGradientStops &);
  // QGradientStops stops() const;
  /// TODO: QGradientStops stops() const;
  // QGradient::CoordinateMode coordinateMode() const;
  binder.add_fun<QGradient::CoordinateMode, &QGradient::coordinateMode>("coordinateMode");
  // void setCoordinateMode(QGradient::CoordinateMode);
  binder.add_void_fun<QGradient::CoordinateMode, &QGradient::setCoordinateMode>("setCoordinateMode");
  // QGradient::InterpolationMode interpolationMode() const;
  binder.add_fun<QGradient::InterpolationMode, &QGradient::interpolationMode>("interpolationMode");
  // void setInterpolationMode(QGradient::InterpolationMode);
  binder.add_void_fun<QGradient::InterpolationMode, &QGradient::setInterpolationMode>("setInterpolationMode");
  // bool operator==(const QGradient &) const;
  binder.operators().eq<const QGradient &>();
  // bool operator!=(const QGradient &) const;
  binder.operators().neq<const QGradient &>();
}


static void register_linear_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class linear_gradient = ns.Class("LinearGradient").setId(script::Type::QLinearGradient)
    .setBase(script::Type::QGradient).get();

  binding::Class<QLinearGradient> binder{ linear_gradient };

  // QLinearGradient();
  binder.ctors().add_default();
  // QLinearGradient(const QLinearGradient &);
  binder.ctors().add<const QLinearGradient &>();
  // ~QLinearGradient();
  binder.add_dtor();
  // QLinearGradient & operator=(const QLinearGradient &);
  binder.operators().assign<const QLinearGradient &>();
  // QLinearGradient(const QPointF &, const QPointF &);
  binder.ctors().add<const QPointF &, const QPointF &>();
  // QLinearGradient(qreal, qreal, qreal, qreal);
  binder.ctors().add<qreal, qreal, qreal, qreal>();
  // QPointF start() const;
  binder.add_fun<QPointF, &QLinearGradient::start>("start");
  // void setStart(const QPointF &);
  binder.add_void_fun<const QPointF &, &QLinearGradient::setStart>("setStart");
  // void setStart(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QLinearGradient::setStart>("setStart");
  // QPointF finalStop() const;
  binder.add_fun<QPointF, &QLinearGradient::finalStop>("finalStop");
  // void setFinalStop(const QPointF &);
  binder.add_void_fun<const QPointF &, &QLinearGradient::setFinalStop>("setFinalStop");
  // void setFinalStop(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QLinearGradient::setFinalStop>("setFinalStop");
}


static void register_radial_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class radial_gradient = ns.Class("RadialGradient").setId(script::Type::QRadialGradient)
    .setBase(script::Type::QGradient).get();

  binding::Class<QRadialGradient> binder{ radial_gradient };

  // QRadialGradient();
  binder.ctors().add_default();
  // QRadialGradient(const QRadialGradient &);
  binder.ctors().add<const QRadialGradient &>();
  // QRadialGradient & operator=(const QRadialGradient &);
  binder.operators().assign<const QRadialGradient &>();
  // ~QRadialGradient();
  binder.add_dtor();
  // QRadialGradient(const QPointF &, qreal, const QPointF &);
  binder.ctors().add<const QPointF &, qreal, const QPointF &>();
  // QRadialGradient(qreal, qreal, qreal, qreal, qreal);
  binder.ctors().add<qreal, qreal, qreal, qreal, qreal>();
  // QRadialGradient(const QPointF &, qreal);
  binder.ctors().add<const QPointF &, qreal>();
  // QRadialGradient(qreal, qreal, qreal);
  binder.ctors().add<qreal, qreal, qreal>();
  // QRadialGradient(const QPointF &, qreal, const QPointF &, qreal);
  binder.ctors().add<const QPointF &, qreal, const QPointF &, qreal>();
  // QRadialGradient(qreal, qreal, qreal, qreal, qreal, qreal);
  binder.ctors().add<qreal, qreal, qreal, qreal, qreal, qreal>();
  // QPointF center() const;
  binder.add_fun<QPointF, &QRadialGradient::center>("center");
  // void setCenter(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRadialGradient::setCenter>("setCenter");
  // void setCenter(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QRadialGradient::setCenter>("setCenter");
  // QPointF focalPoint() const;
  binder.add_fun<QPointF, &QRadialGradient::focalPoint>("focalPoint");
  // void setFocalPoint(const QPointF &);
  binder.add_void_fun<const QPointF &, &QRadialGradient::setFocalPoint>("setFocalPoint");
  // void setFocalPoint(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QRadialGradient::setFocalPoint>("setFocalPoint");
  // qreal radius() const;
  binder.add_fun<qreal, &QRadialGradient::radius>("radius");
  // void setRadius(qreal);
  binder.add_void_fun<qreal, &QRadialGradient::setRadius>("setRadius");
  // qreal centerRadius() const;
  binder.add_fun<qreal, &QRadialGradient::centerRadius>("centerRadius");
  // void setCenterRadius(qreal);
  binder.add_void_fun<qreal, &QRadialGradient::setCenterRadius>("setCenterRadius");
  // qreal focalRadius() const;
  binder.add_fun<qreal, &QRadialGradient::focalRadius>("focalRadius");
  // void setFocalRadius(qreal);
  binder.add_void_fun<qreal, &QRadialGradient::setFocalRadius>("setFocalRadius");
}


static void register_conical_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class conical_gradient = ns.Class("ConicalGradient").setId(script::Type::QConicalGradient)
    .setBase(script::Type::QGradient).get();

  binding::Class<QConicalGradient> binder{ conical_gradient };

  // QConicalGradient();
  binder.ctors().add_default();
  // QConicalGradient(const QConicalGradient &);
  binder.ctors().add<const QConicalGradient &>();
  // QConicalGradient & operator=(const QConicalGradient &);
  binder.operators().assign<const QConicalGradient &>();
  // ~QConicalGradient();
  binder.add_dtor();
  // QConicalGradient(const QPointF &, qreal);
  binder.ctors().add<const QPointF &, qreal>();
  // QConicalGradient(qreal, qreal, qreal);
  binder.ctors().add<qreal, qreal, qreal>();
  // QPointF center() const;
  binder.add_fun<QPointF, &QConicalGradient::center>("center");
  // void setCenter(const QPointF &);
  binder.add_void_fun<const QPointF &, &QConicalGradient::setCenter>("setCenter");
  // void setCenter(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QConicalGradient::setCenter>("setCenter");
  // qreal angle() const;
  binder.add_fun<qreal, &QConicalGradient::angle>("angle");
  // void setAngle(qreal);
  binder.add_void_fun<qreal, &QConicalGradient::setAngle>("setAngle");
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
  binding::Namespace binder{ ns };

  // void swap(QBrush &, QBrush &);
  binder.add_void_fun<QBrush &, QBrush &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QBrush &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QBrush &);
  // QDataStream & operator>>(QDataStream &, QBrush &);
  /// TODO: QDataStream & operator>>(QDataStream &, QBrush &);
  // QDebug operator<<(QDebug, const QBrush &);
  /// TODO: QDebug operator<<(QDebug, const QBrush &);
}

