// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/brush.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

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

  binding::ClassBinder<QBrush> binder{ brush };

  // QBrush();
  binder.default_ctor().create();
  // QBrush(Qt::BrushStyle);
  binder.ctor<Qt::BrushStyle>().create();
  // QBrush(const QColor &, Qt::BrushStyle);
  binder.ctor<const QColor &, Qt::BrushStyle>()
    .apply(binding::default_arguments(Qt::SolidPattern)).create();
  // QBrush(Qt::GlobalColor, Qt::BrushStyle);
  binder.ctor<Qt::GlobalColor, Qt::BrushStyle>()
    .apply(binding::default_arguments(Qt::SolidPattern)).create();
  // QBrush(const QColor &, const QPixmap &);
  binder.ctor<const QColor &, const QPixmap &>().create();
  // QBrush(Qt::GlobalColor, const QPixmap &);
  binder.ctor<Qt::GlobalColor, const QPixmap &>().create();
  // QBrush(const QPixmap &);
  binder.ctor<const QPixmap &>().create();
  // QBrush(const QImage &);
  binder.ctor<const QImage &>().create();
  // QBrush(const QBrush &);
  binder.ctor<const QBrush &>().create();
  // QBrush(const QGradient &);
  binder.ctor<const QGradient &>().create();
  // ~QBrush();
  binder.dtor().create();
  // QBrush & operator=(const QBrush &);
  binder.operators().assign<const QBrush &>();
  // QBrush & operator=(QBrush &&);
  binder.operators().assign<QBrush &&>();
  // void swap(QBrush &);
  binder.void_fun<QBrush &, &QBrush::swap>("swap").create();
  // Qt::BrushStyle style() const;
  binder.fun<Qt::BrushStyle, &QBrush::style>("style").create();
  // void setStyle(Qt::BrushStyle);
  binder.void_fun<Qt::BrushStyle, &QBrush::setStyle>("setStyle").create();
  // const QMatrix & matrix() const;
  /// TODO: const QMatrix & matrix() const;
  // void setMatrix(const QMatrix &);
  /// TODO: void setMatrix(const QMatrix &);
  // QTransform transform() const;
  binder.fun<QTransform, &QBrush::transform>("transform").create();
  // void setTransform(const QTransform &);
  binder.void_fun<const QTransform &, &QBrush::setTransform>("setTransform").create();
  // QPixmap texture() const;
  binder.fun<QPixmap, &QBrush::texture>("texture").create();
  // void setTexture(const QPixmap &);
  binder.void_fun<const QPixmap &, &QBrush::setTexture>("setTexture").create();
  // QImage textureImage() const;
  binder.fun<QImage, &QBrush::textureImage>("textureImage").create();
  // void setTextureImage(const QImage &);
  binder.void_fun<const QImage &, &QBrush::setTextureImage>("setTextureImage").create();
  // const QColor & color() const;
  binder.fun<const QColor &, &QBrush::color>("color").create();
  // void setColor(const QColor &);
  binder.void_fun<const QColor &, &QBrush::setColor>("setColor").create();
  // void setColor(Qt::GlobalColor);
  binder.void_fun<Qt::GlobalColor, &QBrush::setColor>("setColor").create();
  // const QGradient * gradient() const;
  /// TODO: const QGradient * gradient() const;
  // bool isOpaque() const;
  binder.fun<bool, &QBrush::isOpaque>("isOpaque").create();
  // bool operator==(const QBrush &) const;
  binder.operators().eq<const QBrush &>();
  // bool operator!=(const QBrush &) const;
  binder.operators().neq<const QBrush &>();
  // bool isDetached() const;
  binder.fun<bool, &QBrush::isDetached>("isDetached").create();
  // QBrush::DataPtr & data_ptr();
  /// TODO: QBrush::DataPtr & data_ptr();
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
  binding::ClassBinder<QGradient> binder{ gradient };

  // QGradient();
  binder.default_ctor().create();
  // QGradient::Type type() const;
  binder.fun<QGradient::Type, &QGradient::type>("type").create();
  // void setSpread(QGradient::Spread);
  binder.void_fun<QGradient::Spread, &QGradient::setSpread>("setSpread").create();
  // QGradient::Spread spread() const;
  binder.fun<QGradient::Spread, &QGradient::spread>("spread").create();
  // void setColorAt(qreal, const QColor &);
  binder.void_fun<qreal, const QColor &, &QGradient::setColorAt>("setColorAt").create();
  // void setStops(const QGradientStops &);
  /// TODO: void setStops(const QGradientStops &);
  // QGradientStops stops() const;
  /// TODO: QGradientStops stops() const;
  // QGradient::CoordinateMode coordinateMode() const;
  binder.fun<QGradient::CoordinateMode, &QGradient::coordinateMode>("coordinateMode").create();
  // void setCoordinateMode(QGradient::CoordinateMode);
  binder.void_fun<QGradient::CoordinateMode, &QGradient::setCoordinateMode>("setCoordinateMode").create();
  // QGradient::InterpolationMode interpolationMode() const;
  binder.fun<QGradient::InterpolationMode, &QGradient::interpolationMode>("interpolationMode").create();
  // void setInterpolationMode(QGradient::InterpolationMode);
  binder.void_fun<QGradient::InterpolationMode, &QGradient::setInterpolationMode>("setInterpolationMode").create();
  // bool operator==(const QGradient &) const;
  binder.operators().eq<const QGradient &>();
  // bool operator!=(const QGradient &) const;
  binder.operators().neq<const QGradient &>();
}


static void register_linear_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class linear_gradient = ns.newClass("LinearGradient").setId(script::Type::QLinearGradient)
    .setBase(script::Type::QGradient).get();

  binding::ClassBinder<QLinearGradient> binder{ linear_gradient };

  // QLinearGradient();
  binder.default_ctor().create();
  // QLinearGradient(const QLinearGradient &);
  binder.ctor<const QLinearGradient &>().create();
  // ~QLinearGradient();
  binder.dtor().create();
  // QLinearGradient & operator=(const QLinearGradient &);
  binder.operators().assign<const QLinearGradient &>();
  // QLinearGradient(const QPointF &, const QPointF &);
  binder.ctor<const QPointF &, const QPointF &>().create();
  // QLinearGradient(qreal, qreal, qreal, qreal);
  binder.ctor<qreal, qreal, qreal, qreal>().create();
  // QPointF start() const;
  binder.fun<QPointF, &QLinearGradient::start>("start").create();
  // void setStart(const QPointF &);
  binder.void_fun<const QPointF &, &QLinearGradient::setStart>("setStart").create();
  // void setStart(qreal, qreal);
  binder.void_fun<qreal, qreal, &QLinearGradient::setStart>("setStart").create();
  // QPointF finalStop() const;
  binder.fun<QPointF, &QLinearGradient::finalStop>("finalStop").create();
  // void setFinalStop(const QPointF &);
  binder.void_fun<const QPointF &, &QLinearGradient::setFinalStop>("setFinalStop").create();
  // void setFinalStop(qreal, qreal);
  binder.void_fun<qreal, qreal, &QLinearGradient::setFinalStop>("setFinalStop").create();
}


static void register_radial_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class radial_gradient = ns.newClass("RadialGradient").setId(script::Type::QRadialGradient)
    .setBase(script::Type::QGradient).get();

  binding::ClassBinder<QRadialGradient> binder{ radial_gradient };

  // QRadialGradient();
  binder.default_ctor().create();
  // QRadialGradient(const QRadialGradient &);
  binder.ctor<const QRadialGradient &>().create();
  // QRadialGradient & operator=(const QRadialGradient &);
  binder.operators().assign<const QRadialGradient &>();
  // ~QRadialGradient();
  binder.dtor().create();
  // QRadialGradient(const QPointF &, qreal, const QPointF &);
  binder.ctor<const QPointF &, qreal, const QPointF &>().create();
  // QRadialGradient(qreal, qreal, qreal, qreal, qreal);
  binder.ctor<qreal, qreal, qreal, qreal, qreal>().create();
  // QRadialGradient(const QPointF &, qreal);
  binder.ctor<const QPointF &, qreal>().create();
  // QRadialGradient(qreal, qreal, qreal);
  binder.ctor<qreal, qreal, qreal>().create();
  // QRadialGradient(const QPointF &, qreal, const QPointF &, qreal);
  binder.ctor<const QPointF &, qreal, const QPointF &, qreal>().create();
  // QRadialGradient(qreal, qreal, qreal, qreal, qreal, qreal);
  binder.ctor<qreal, qreal, qreal, qreal, qreal, qreal>().create();
  // QPointF center() const;
  binder.fun<QPointF, &QRadialGradient::center>("center").create();
  // void setCenter(const QPointF &);
  binder.void_fun<const QPointF &, &QRadialGradient::setCenter>("setCenter").create();
  // void setCenter(qreal, qreal);
  binder.void_fun<qreal, qreal, &QRadialGradient::setCenter>("setCenter").create();
  // QPointF focalPoint() const;
  binder.fun<QPointF, &QRadialGradient::focalPoint>("focalPoint").create();
  // void setFocalPoint(const QPointF &);
  binder.void_fun<const QPointF &, &QRadialGradient::setFocalPoint>("setFocalPoint").create();
  // void setFocalPoint(qreal, qreal);
  binder.void_fun<qreal, qreal, &QRadialGradient::setFocalPoint>("setFocalPoint").create();
  // qreal radius() const;
  binder.fun<qreal, &QRadialGradient::radius>("radius").create();
  // void setRadius(qreal);
  binder.void_fun<qreal, &QRadialGradient::setRadius>("setRadius").create();
  // qreal centerRadius() const;
  binder.fun<qreal, &QRadialGradient::centerRadius>("centerRadius").create();
  // void setCenterRadius(qreal);
  binder.void_fun<qreal, &QRadialGradient::setCenterRadius>("setCenterRadius").create();
  // qreal focalRadius() const;
  binder.fun<qreal, &QRadialGradient::focalRadius>("focalRadius").create();
  // void setFocalRadius(qreal);
  binder.void_fun<qreal, &QRadialGradient::setFocalRadius>("setFocalRadius").create();
}


static void register_conical_gradient_class(script::Namespace ns)
{
  using namespace script;

  Class conical_gradient = ns.newClass("ConicalGradient").setId(script::Type::QConicalGradient)
    .setBase(script::Type::QGradient).get();

  binding::ClassBinder<QConicalGradient> binder{ conical_gradient };

  // QConicalGradient();
  binder.default_ctor().create();
  // QConicalGradient(const QConicalGradient &);
  binder.ctor<const QConicalGradient &>().create();
  // QConicalGradient & operator=(const QConicalGradient &);
  binder.operators().assign<const QConicalGradient &>();
  // ~QConicalGradient();
  binder.dtor().create();
  // QConicalGradient(const QPointF &, qreal);
  binder.ctor<const QPointF &, qreal>().create();
  // QConicalGradient(qreal, qreal, qreal);
  binder.ctor<qreal, qreal, qreal>().create();
  // QPointF center() const;
  binder.fun<QPointF, &QConicalGradient::center>("center").create();
  // void setCenter(const QPointF &);
  binder.void_fun<const QPointF &, &QConicalGradient::setCenter>("setCenter").create();
  // void setCenter(qreal, qreal);
  binder.void_fun<qreal, qreal, &QConicalGradient::setCenter>("setCenter").create();
  // qreal angle() const;
  binder.fun<qreal, &QConicalGradient::angle>("angle").create();
  // void setAngle(qreal);
  binder.void_fun<qreal, &QConicalGradient::setAngle>("setAngle").create();
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
  binder.void_fun<QBrush &, QBrush &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QBrush &);
  binder.operators().put_to<QDataStream &, const QBrush &>();
  // QDataStream & operator>>(QDataStream &, QBrush &);
  binder.operators().read_from<QDataStream &, QBrush &>();
  // QDebug operator<<(QDebug, const QBrush &);
  /// TODO: QDebug operator<<(QDebug, const QBrush &);
}

