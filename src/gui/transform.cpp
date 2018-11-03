// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/transform.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/line.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/gui/painterpath.h"
#include "yasl/gui/region.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_transform_transformation_type_enum(script::Class transform)
{
  using namespace script;

  Enum transformation_type = transform.Enum("TransformationType").setId(script::Type::QTransformTransformationType).get();

  transformation_type.addValue("TxNone", QTransform::TxNone);
  transformation_type.addValue("TxTranslate", QTransform::TxTranslate);
  transformation_type.addValue("TxScale", QTransform::TxScale);
  transformation_type.addValue("TxRotate", QTransform::TxRotate);
  transformation_type.addValue("TxShear", QTransform::TxShear);
  transformation_type.addValue("TxProject", QTransform::TxProject);
}


static void register_transform_class(script::Namespace ns)
{
  using namespace script;

  Class transform = ns.Class("Transform").setId(script::Type::QTransform).get();

  register_transform_transformation_type_enum(transform);
  binding::ClassBinder<QTransform> binder{ transform };

  // QTransform(Qt::Initialization);
  binder.ctor<Qt::Initialization>().create();
  // QTransform();
  binder.default_ctor().create();
  // QTransform(qreal, qreal, qreal, qreal, qreal, qreal);
  binder.ctor<qreal, qreal, qreal, qreal, qreal, qreal>().create();
  // QTransform(const QMatrix &);
  /// TODO: QTransform(const QMatrix &);
  // QTransform & operator=(QTransform &&);
  binder.operators().assign<QTransform &&>();
  // QTransform & operator=(const QTransform &);
  binder.operators().assign<const QTransform &>();
  // QTransform(QTransform &&);
  binder.ctor<QTransform &&>().create();
  // QTransform(const QTransform &);
  binder.ctor<const QTransform &>().create();
  // bool isAffine() const;
  binder.fun<bool, &QTransform::isAffine>("isAffine").create();
  // bool isIdentity() const;
  binder.fun<bool, &QTransform::isIdentity>("isIdentity").create();
  // bool isInvertible() const;
  binder.fun<bool, &QTransform::isInvertible>("isInvertible").create();
  // bool isScaling() const;
  binder.fun<bool, &QTransform::isScaling>("isScaling").create();
  // bool isRotating() const;
  binder.fun<bool, &QTransform::isRotating>("isRotating").create();
  // bool isTranslating() const;
  binder.fun<bool, &QTransform::isTranslating>("isTranslating").create();
  // QTransform::TransformationType type() const;
  binder.fun<QTransform::TransformationType, &QTransform::type>("type").create();
  // qreal determinant() const;
  binder.fun<qreal, &QTransform::determinant>("determinant").create();
  // qreal det() const;
  binder.fun<qreal, &QTransform::det>("det").create();
  // qreal m11() const;
  binder.fun<qreal, &QTransform::m11>("m11").create();
  // qreal m12() const;
  binder.fun<qreal, &QTransform::m12>("m12").create();
  // qreal m13() const;
  binder.fun<qreal, &QTransform::m13>("m13").create();
  // qreal m21() const;
  binder.fun<qreal, &QTransform::m21>("m21").create();
  // qreal m22() const;
  binder.fun<qreal, &QTransform::m22>("m22").create();
  // qreal m23() const;
  binder.fun<qreal, &QTransform::m23>("m23").create();
  // qreal m31() const;
  binder.fun<qreal, &QTransform::m31>("m31").create();
  // qreal m32() const;
  binder.fun<qreal, &QTransform::m32>("m32").create();
  // qreal m33() const;
  binder.fun<qreal, &QTransform::m33>("m33").create();
  // qreal dx() const;
  binder.fun<qreal, &QTransform::dx>("dx").create();
  // qreal dy() const;
  binder.fun<qreal, &QTransform::dy>("dy").create();
  // QTransform inverted(bool *) const;
  /// TODO: QTransform inverted(bool *) const;
  // QTransform adjoint() const;
  binder.fun<QTransform, &QTransform::adjoint>("adjoint").create();
  // QTransform transposed() const;
  binder.fun<QTransform, &QTransform::transposed>("transposed").create();
  // QTransform & translate(qreal, qreal);
  binder.chainable<qreal, qreal, &QTransform::translate>("translate").create();
  // QTransform & scale(qreal, qreal);
  binder.chainable<qreal, qreal, &QTransform::scale>("scale").create();
  // QTransform & shear(qreal, qreal);
  binder.chainable<qreal, qreal, &QTransform::shear>("shear").create();
  // QTransform & rotate(qreal, Qt::Axis);
  binder.chainable<qreal, Qt::Axis, &QTransform::rotate>("rotate")
    .apply(binding::default_arguments(Qt::ZAxis)).create();
  // QTransform & rotateRadians(qreal, Qt::Axis);
  binder.chainable<qreal, Qt::Axis, &QTransform::rotateRadians>("rotateRadians")
    .apply(binding::default_arguments(Qt::ZAxis)).create();
  // static bool squareToQuad(const QPolygonF &, QTransform &);
  /// TODO: static bool squareToQuad(const QPolygonF &, QTransform &);
  // static bool quadToSquare(const QPolygonF &, QTransform &);
  /// TODO: static bool quadToSquare(const QPolygonF &, QTransform &);
  // static bool quadToQuad(const QPolygonF &, const QPolygonF &, QTransform &);
  /// TODO: static bool quadToQuad(const QPolygonF &, const QPolygonF &, QTransform &);
  // bool operator==(const QTransform &) const;
  binder.operators().eq<const QTransform &>();
  // bool operator!=(const QTransform &) const;
  binder.operators().neq<const QTransform &>();
  // QTransform & operator*=(const QTransform &);
  binder.operators().mul_assign<const QTransform &>();
  // QTransform operator*(const QTransform &) const;
  binder.operators().mul<QTransform, const QTransform &>();
  // void reset();
  binder.void_fun<&QTransform::reset>("reset").create();
  // QPoint map(const QPoint &) const;
  binder.fun<QPoint, const QPoint &, &QTransform::map>("map").create();
  // QPointF map(const QPointF &) const;
  binder.fun<QPointF, const QPointF &, &QTransform::map>("map").create();
  // QLine map(const QLine &) const;
  binder.fun<QLine, const QLine &, &QTransform::map>("map").create();
  // QLineF map(const QLineF &) const;
  binder.fun<QLineF, const QLineF &, &QTransform::map>("map").create();
  // QPolygonF map(const QPolygonF &) const;
  /// TODO: QPolygonF map(const QPolygonF &) const;
  // QPolygon map(const QPolygon &) const;
  /// TODO: QPolygon map(const QPolygon &) const;
  // QRegion map(const QRegion &) const;
  binder.fun<QRegion, const QRegion &, &QTransform::map>("map").create();
  // QPainterPath map(const QPainterPath &) const;
  binder.fun<QPainterPath, const QPainterPath &, &QTransform::map>("map").create();
  // QPolygon mapToPolygon(const QRect &) const;
  /// TODO: QPolygon mapToPolygon(const QRect &) const;
  // QRect mapRect(const QRect &) const;
  binder.fun<QRect, const QRect &, &QTransform::mapRect>("mapRect").create();
  // QRectF mapRect(const QRectF &) const;
  binder.fun<QRectF, const QRectF &, &QTransform::mapRect>("mapRect").create();
  // void map(int, int, int *, int *) const;
  /// TODO: void map(int, int, int *, int *) const;
  // void map(qreal, qreal, qreal *, qreal *) const;
  /// TODO: void map(qreal, qreal, qreal *, qreal *) const;
  // const QMatrix & toAffine() const;
  /// TODO: const QMatrix & toAffine() const;
  // QTransform & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QTransform & operator/=(qreal);
  binder.operators().div_assign<qreal>();
  // QTransform & operator+=(qreal);
  binder.operators().add_assign<qreal>();
  // QTransform & operator-=(qreal);
  binder.operators().sub_assign<qreal>();
  // static QTransform fromTranslate(qreal, qreal);
  binder.static_fun<QTransform, qreal, qreal, &QTransform::fromTranslate>("fromTranslate").create();
  // static QTransform fromScale(qreal, qreal);
  binder.static_fun<QTransform, qreal, qreal, &QTransform::fromScale>("fromScale").create();
}


void register_transform_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_transform_class(ns);
  binding::Namespace binder{ ns };

  // uint qHash(const QTransform &, uint);
  binder.fun<uint, const QTransform &, uint, &qHash>("qHash").create();
  // bool qFuzzyCompare(const QTransform &, const QTransform &);
  binder.fun<bool, const QTransform &, const QTransform &, &qFuzzyCompare>("qFuzzyCompare").create();
  // QDataStream & operator<<(QDataStream &, const QTransform &);
  binder.operators().put_to<QDataStream &, const QTransform &>();
  // QDataStream & operator>>(QDataStream &, QTransform &);
  binder.operators().read_from<QDataStream &, QTransform &>();
  // QDebug operator<<(QDebug, const QTransform &);
  /// TODO: QDebug operator<<(QDebug, const QTransform &);
  // QPoint operator*(const QPoint &, const QTransform &);
  binder.operators().mul<QPoint, const QPoint &, const QTransform &>();
  // QPointF operator*(const QPointF &, const QTransform &);
  binder.operators().mul<QPointF, const QPointF &, const QTransform &>();
  // QLineF operator*(const QLineF &, const QTransform &);
  binder.operators().mul<QLineF, const QLineF &, const QTransform &>();
  // QLine operator*(const QLine &, const QTransform &);
  binder.operators().mul<QLine, const QLine &, const QTransform &>();
  // QPolygon operator*(const QPolygon &, const QTransform &);
  /// TODO: QPolygon operator*(const QPolygon &, const QTransform &);
  // QPolygonF operator*(const QPolygonF &, const QTransform &);
  /// TODO: QPolygonF operator*(const QPolygonF &, const QTransform &);
  // QRegion operator*(const QRegion &, const QTransform &);
  binder.operators().mul<QRegion, const QRegion &, const QTransform &>();
  // QPainterPath operator*(const QPainterPath &, const QTransform &);
  binder.operators().mul<QPainterPath, const QPainterPath &, const QTransform &>();
  // QTransform operator*(const QTransform &, qreal);
  binder.operators().mul<QTransform, const QTransform &, qreal>();
  // QTransform operator/(const QTransform &, qreal);
  binder.operators().div<QTransform, const QTransform &, qreal>();
  // QTransform operator+(const QTransform &, qreal);
  binder.operators().add<QTransform, const QTransform &, qreal>();
  // QTransform operator-(const QTransform &, qreal);
  binder.operators().sub<QTransform, const QTransform &, qreal>();
}

