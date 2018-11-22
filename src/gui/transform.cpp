// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/transform.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"

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

  Enum transformation_type = transform.newEnum("TransformationType").setId(script::Type::QTransformTransformationType).get();

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

  Class transform = ns.newClass("Transform").setId(script::Type::QTransform).get();

  register_transform_transformation_type_enum(transform);

  // QTransform(Qt::Initialization);
  bind::constructor<QTransform, Qt::Initialization>(transform).create();
  // QTransform();
  bind::default_constructor<QTransform>(transform).create();
  // QTransform(qreal, qreal, qreal, qreal, qreal, qreal);
  bind::constructor<QTransform, qreal, qreal, qreal, qreal, qreal, qreal>(transform).create();
  // QTransform(const QMatrix &);
  /// TODO: QTransform(const QMatrix &);
  // QTransform & operator=(QTransform &&);
  bind::memop_assign<QTransform, QTransform &&>(transform);
  // QTransform & operator=(const QTransform &);
  bind::memop_assign<QTransform, const QTransform &>(transform);
  // QTransform(QTransform &&);
  bind::constructor<QTransform, QTransform &&>(transform).create();
  // QTransform(const QTransform &);
  bind::constructor<QTransform, const QTransform &>(transform).create();
  // bool isAffine() const;
  bind::member_function<QTransform, bool, &QTransform::isAffine>(transform, "isAffine").create();
  // bool isIdentity() const;
  bind::member_function<QTransform, bool, &QTransform::isIdentity>(transform, "isIdentity").create();
  // bool isInvertible() const;
  bind::member_function<QTransform, bool, &QTransform::isInvertible>(transform, "isInvertible").create();
  // bool isScaling() const;
  bind::member_function<QTransform, bool, &QTransform::isScaling>(transform, "isScaling").create();
  // bool isRotating() const;
  bind::member_function<QTransform, bool, &QTransform::isRotating>(transform, "isRotating").create();
  // bool isTranslating() const;
  bind::member_function<QTransform, bool, &QTransform::isTranslating>(transform, "isTranslating").create();
  // QTransform::TransformationType type() const;
  bind::member_function<QTransform, QTransform::TransformationType, &QTransform::type>(transform, "type").create();
  // qreal determinant() const;
  bind::member_function<QTransform, qreal, &QTransform::determinant>(transform, "determinant").create();
  // qreal det() const;
  bind::member_function<QTransform, qreal, &QTransform::det>(transform, "det").create();
  // qreal m11() const;
  bind::member_function<QTransform, qreal, &QTransform::m11>(transform, "m11").create();
  // qreal m12() const;
  bind::member_function<QTransform, qreal, &QTransform::m12>(transform, "m12").create();
  // qreal m13() const;
  bind::member_function<QTransform, qreal, &QTransform::m13>(transform, "m13").create();
  // qreal m21() const;
  bind::member_function<QTransform, qreal, &QTransform::m21>(transform, "m21").create();
  // qreal m22() const;
  bind::member_function<QTransform, qreal, &QTransform::m22>(transform, "m22").create();
  // qreal m23() const;
  bind::member_function<QTransform, qreal, &QTransform::m23>(transform, "m23").create();
  // qreal m31() const;
  bind::member_function<QTransform, qreal, &QTransform::m31>(transform, "m31").create();
  // qreal m32() const;
  bind::member_function<QTransform, qreal, &QTransform::m32>(transform, "m32").create();
  // qreal m33() const;
  bind::member_function<QTransform, qreal, &QTransform::m33>(transform, "m33").create();
  // qreal dx() const;
  bind::member_function<QTransform, qreal, &QTransform::dx>(transform, "dx").create();
  // qreal dy() const;
  bind::member_function<QTransform, qreal, &QTransform::dy>(transform, "dy").create();
  // QTransform inverted(bool *) const;
  /// TODO: QTransform inverted(bool *) const;
  // QTransform adjoint() const;
  bind::member_function<QTransform, QTransform, &QTransform::adjoint>(transform, "adjoint").create();
  // QTransform transposed() const;
  bind::member_function<QTransform, QTransform, &QTransform::transposed>(transform, "transposed").create();
  // QTransform & translate(qreal, qreal);
  bind::chainable_memfn<QTransform, qreal, qreal, &QTransform::translate>(transform, "translate").create();
  // QTransform & scale(qreal, qreal);
  bind::chainable_memfn<QTransform, qreal, qreal, &QTransform::scale>(transform, "scale").create();
  // QTransform & shear(qreal, qreal);
  bind::chainable_memfn<QTransform, qreal, qreal, &QTransform::shear>(transform, "shear").create();
  // QTransform & rotate(qreal, Qt::Axis);
  bind::chainable_memfn<QTransform, qreal, Qt::Axis, &QTransform::rotate>(transform, "rotate")
    .apply(bind::default_arguments(Qt::ZAxis)).create();
  // QTransform & rotateRadians(qreal, Qt::Axis);
  bind::chainable_memfn<QTransform, qreal, Qt::Axis, &QTransform::rotateRadians>(transform, "rotateRadians")
    .apply(bind::default_arguments(Qt::ZAxis)).create();
  // static bool squareToQuad(const QPolygonF &, QTransform &);
  /// TODO: static bool squareToQuad(const QPolygonF &, QTransform &);
  // static bool quadToSquare(const QPolygonF &, QTransform &);
  /// TODO: static bool quadToSquare(const QPolygonF &, QTransform &);
  // static bool quadToQuad(const QPolygonF &, const QPolygonF &, QTransform &);
  /// TODO: static bool quadToQuad(const QPolygonF &, const QPolygonF &, QTransform &);
  // bool operator==(const QTransform &) const;
  bind::memop_eq<QTransform, const QTransform &>(transform);
  // bool operator!=(const QTransform &) const;
  bind::memop_neq<QTransform, const QTransform &>(transform);
  // QTransform & operator*=(const QTransform &);
  bind::memop_mul_assign<QTransform, const QTransform &>(transform);
  // QTransform operator*(const QTransform &) const;
  bind::memop_mul<QTransform, QTransform, const QTransform &>(transform);
  // void reset();
  bind::void_member_function<QTransform, &QTransform::reset>(transform, "reset").create();
  // QPoint map(const QPoint &) const;
  bind::member_function<QTransform, QPoint, const QPoint &, &QTransform::map>(transform, "map").create();
  // QPointF map(const QPointF &) const;
  bind::member_function<QTransform, QPointF, const QPointF &, &QTransform::map>(transform, "map").create();
  // QLine map(const QLine &) const;
  bind::member_function<QTransform, QLine, const QLine &, &QTransform::map>(transform, "map").create();
  // QLineF map(const QLineF &) const;
  bind::member_function<QTransform, QLineF, const QLineF &, &QTransform::map>(transform, "map").create();
  // QPolygonF map(const QPolygonF &) const;
  /// TODO: QPolygonF map(const QPolygonF &) const;
  // QPolygon map(const QPolygon &) const;
  /// TODO: QPolygon map(const QPolygon &) const;
  // QRegion map(const QRegion &) const;
  bind::member_function<QTransform, QRegion, const QRegion &, &QTransform::map>(transform, "map").create();
  // QPainterPath map(const QPainterPath &) const;
  bind::member_function<QTransform, QPainterPath, const QPainterPath &, &QTransform::map>(transform, "map").create();
  // QPolygon mapToPolygon(const QRect &) const;
  /// TODO: QPolygon mapToPolygon(const QRect &) const;
  // QRect mapRect(const QRect &) const;
  bind::member_function<QTransform, QRect, const QRect &, &QTransform::mapRect>(transform, "mapRect").create();
  // QRectF mapRect(const QRectF &) const;
  bind::member_function<QTransform, QRectF, const QRectF &, &QTransform::mapRect>(transform, "mapRect").create();
  // void map(int, int, int *, int *) const;
  /// TODO: void map(int, int, int *, int *) const;
  // void map(qreal, qreal, qreal *, qreal *) const;
  /// TODO: void map(qreal, qreal, qreal *, qreal *) const;
  // const QMatrix & toAffine() const;
  /// TODO: const QMatrix & toAffine() const;
  // QTransform & operator*=(qreal);
  bind::memop_mul_assign<QTransform, qreal>(transform);
  // QTransform & operator/=(qreal);
  bind::memop_div_assign<QTransform, qreal>(transform);
  // QTransform & operator+=(qreal);
  bind::memop_add_assign<QTransform, qreal>(transform);
  // QTransform & operator-=(qreal);
  bind::memop_sub_assign<QTransform, qreal>(transform);
  // static QTransform fromTranslate(qreal, qreal);
  bind::static_member_function<QTransform, QTransform, qreal, qreal, &QTransform::fromTranslate>(transform, "fromTranslate").create();
  // static QTransform fromScale(qreal, qreal);
  bind::static_member_function<QTransform, QTransform, qreal, qreal, &QTransform::fromScale>(transform, "fromScale").create();
}


void register_transform_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_transform_class(ns);

  // uint qHash(const QTransform &, uint);
  bind::function<uint, const QTransform &, uint, &qHash>(ns, "qHash").create();
  // bool qFuzzyCompare(const QTransform &, const QTransform &);
  bind::function<bool, const QTransform &, const QTransform &, &qFuzzyCompare>(ns, "qFuzzyCompare").create();
  // QDataStream & operator<<(QDataStream &, const QTransform &);
  bind::op_put_to<QDataStream &, const QTransform &>(ns);
  // QDataStream & operator>>(QDataStream &, QTransform &);
  bind::op_read_from<QDataStream &, QTransform &>(ns);
  // QDebug operator<<(QDebug, const QTransform &);
  /// TODO: QDebug operator<<(QDebug, const QTransform &);
  // QPoint operator*(const QPoint &, const QTransform &);
  bind::op_mul<QPoint, const QPoint &, const QTransform &>(ns);
  // QPointF operator*(const QPointF &, const QTransform &);
  bind::op_mul<QPointF, const QPointF &, const QTransform &>(ns);
  // QLineF operator*(const QLineF &, const QTransform &);
  bind::op_mul<QLineF, const QLineF &, const QTransform &>(ns);
  // QLine operator*(const QLine &, const QTransform &);
  bind::op_mul<QLine, const QLine &, const QTransform &>(ns);
  // QPolygon operator*(const QPolygon &, const QTransform &);
  /// TODO: QPolygon operator*(const QPolygon &, const QTransform &);
  // QPolygonF operator*(const QPolygonF &, const QTransform &);
  /// TODO: QPolygonF operator*(const QPolygonF &, const QTransform &);
  // QRegion operator*(const QRegion &, const QTransform &);
  bind::op_mul<QRegion, const QRegion &, const QTransform &>(ns);
  // QPainterPath operator*(const QPainterPath &, const QTransform &);
  bind::op_mul<QPainterPath, const QPainterPath &, const QTransform &>(ns);
  // QTransform operator*(const QTransform &, qreal);
  bind::op_mul<QTransform, const QTransform &, qreal>(ns);
  // QTransform operator/(const QTransform &, qreal);
  bind::op_div<QTransform, const QTransform &, qreal>(ns);
  // QTransform operator+(const QTransform &, qreal);
  bind::op_add<QTransform, const QTransform &, qreal>(ns);
  // QTransform operator-(const QTransform &, qreal);
  bind::op_sub<QTransform, const QTransform &, qreal>(ns);
}

