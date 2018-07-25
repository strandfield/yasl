// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/transform.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/line.h"
#include "yasl/core/point.h"

#include "yasl/gui/painterpath.h"
#include "yasl/gui/polygon.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_transform_transformation_type_enum(script::Class transform)
{
  using namespace script;

  Enum transformation_type = transform.Enum("TransformationType").setId(script::Type::QTransformTransformationType).get();

  transformation_type.addValue("TxNone", QTransform::TxNone);
  transformation_type.addValue("TxProject", QTransform::TxProject);
  transformation_type.addValue("TxRotate", QTransform::TxRotate);
  transformation_type.addValue("TxScale", QTransform::TxScale);
  transformation_type.addValue("TxShear", QTransform::TxShear);
  transformation_type.addValue("TxTranslate", QTransform::TxTranslate);
}

static void register_transform_class(script::Namespace ns)
{
  using namespace script;

  Class transform = ns.Class("Transform").setId(script::Type::QTransform).get();

  register_transform_transformation_type_enum(transform);
  binding::Class<QTransform> binder{ transform };

  // ~QTransform();
  binder.add_dtor();
  // QTransform(Qt::Initialization);
  binder.ctors().add<Qt::Initialization>();
  // QTransform();
  binder.ctors().add_default();
  // QTransform(qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal);
  /// TODO: binder.ctors().add<qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal>();
  // QTransform(qreal, qreal, qreal, qreal, qreal, qreal);
  /// TODO: binder.ctors().add<qreal, qreal, qreal, qreal, qreal, qreal>();
  // QTransform(const QMatrix &);
  /// ignore: binder.ctors().add<const QMatrix &>();
  // QTransform & operator=(QTransform &&);
  binder.operators().assign<QTransform &&>();
  // QTransform & operator=(const QTransform &);
  binder.operators().assign<const QTransform &>();
  // QTransform(QTransform &&);
  binder.ctors().add<QTransform &&>();
  // QTransform(const QTransform &);
  binder.ctors().add<const QTransform &>();
  // bool isAffine() const;
  binder.add_fun<bool, &QTransform::isAffine>("isAffine");
  // bool isIdentity() const;
  binder.add_fun<bool, &QTransform::isIdentity>("isIdentity");
  // bool isInvertible() const;
  binder.add_fun<bool, &QTransform::isInvertible>("isInvertible");
  // bool isScaling() const;
  binder.add_fun<bool, &QTransform::isScaling>("isScaling");
  // bool isRotating() const;
  binder.add_fun<bool, &QTransform::isRotating>("isRotating");
  // bool isTranslating() const;
  binder.add_fun<bool, &QTransform::isTranslating>("isTranslating");
  // QTransform::TransformationType type() const;
  binder.add_fun<QTransform::TransformationType, &QTransform::type>("type");
  // qreal determinant() const;
  binder.add_fun<qreal, &QTransform::determinant>("determinant");
  // qreal det() const;
  binder.add_fun<qreal, &QTransform::det>("det");
  // qreal m11() const;
  binder.add_fun<qreal, &QTransform::m11>("m11");
  // qreal m12() const;
  binder.add_fun<qreal, &QTransform::m12>("m12");
  // qreal m13() const;
  binder.add_fun<qreal, &QTransform::m13>("m13");
  // qreal m21() const;
  binder.add_fun<qreal, &QTransform::m21>("m21");
  // qreal m22() const;
  binder.add_fun<qreal, &QTransform::m22>("m22");
  // qreal m23() const;
  binder.add_fun<qreal, &QTransform::m23>("m23");
  // qreal m31() const;
  binder.add_fun<qreal, &QTransform::m31>("m31");
  // qreal m32() const;
  binder.add_fun<qreal, &QTransform::m32>("m32");
  // qreal m33() const;
  binder.add_fun<qreal, &QTransform::m33>("m33");
  // qreal dx() const;
  binder.add_fun<qreal, &QTransform::dx>("dx");
  // qreal dy() const;
  binder.add_fun<qreal, &QTransform::dy>("dy");
  // void setMatrix(qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal);
  /// TODO: binder.add_void_fun<qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal, qreal, &QTransform::setMatrix>("setMatrix");
  // QTransform inverted(bool *) const;
  binder.add_fun<QTransform, bool *, &QTransform::inverted>("inverted");
  // QTransform adjoint() const;
  binder.add_fun<QTransform, &QTransform::adjoint>("adjoint");
  // QTransform transposed() const;
  binder.add_fun<QTransform, &QTransform::transposed>("transposed");
  // QTransform & translate(qreal, qreal);
  binder.add_chainable<qreal, qreal, &QTransform::translate>("translate");
  // QTransform & scale(qreal, qreal);
  binder.add_chainable<qreal, qreal, &QTransform::scale>("scale");
  // QTransform & shear(qreal, qreal);
  binder.add_chainable<qreal, qreal, &QTransform::shear>("shear");
  // QTransform & rotate(qreal, Qt::Axis);
  binder.add_chainable<qreal, Qt::Axis, &QTransform::rotate>("rotate");
  // QTransform & rotateRadians(qreal, Qt::Axis);
  binder.add_chainable<qreal, Qt::Axis, &QTransform::rotateRadians>("rotateRadians");
  // static bool squareToQuad(const QPolygonF &, QTransform &);
  binder.add_static<bool, const QPolygonF &, QTransform &, &QTransform::squareToQuad>("squareToQuad");
  // static bool quadToSquare(const QPolygonF &, QTransform &);
  binder.add_static<bool, const QPolygonF &, QTransform &, &QTransform::quadToSquare>("quadToSquare");
  // static bool quadToQuad(const QPolygonF &, const QPolygonF &, QTransform &);
  binder.add_static<bool, const QPolygonF &, const QPolygonF &, QTransform &, &QTransform::quadToQuad>("quadToQuad");
  // bool operator==(const QTransform &) const;
  binder.operators().eq<const QTransform &>();
  // bool operator!=(const QTransform &) const;
  binder.operators().neq<const QTransform &>();
  // QTransform & operator*=(const QTransform &);
  binder.operators().mul_assign<const QTransform &>();
  // QTransform operator*(const QTransform &) const;
  binder.operators().mul<QTransform, const QTransform &>();
  // void reset();
  binder.add_void_fun<&QTransform::reset>("reset");
  // QPoint map(const QPoint &) const;
  binder.add_fun<QPoint, const QPoint &, &QTransform::map>("map");
  // QPointF map(const QPointF &) const;
  binder.add_fun<QPointF, const QPointF &, &QTransform::map>("map");
  // QLine map(const QLine &) const;
  binder.add_fun<QLine, const QLine &, &QTransform::map>("map");
  // QLineF map(const QLineF &) const;
  binder.add_fun<QLineF, const QLineF &, &QTransform::map>("map");
  // QPolygonF map(const QPolygonF &) const;
  binder.add_fun<QPolygonF, const QPolygonF &, &QTransform::map>("map");
  // QPolygon map(const QPolygon &) const;
  binder.add_fun<QPolygon, const QPolygon &, &QTransform::map>("map");
  // QRegion map(const QRegion &) const;
  binder.add_fun<QRegion, const QRegion &, &QTransform::map>("map");
  // QPainterPath map(const QPainterPath &) const;
  binder.add_fun<QPainterPath, const QPainterPath &, &QTransform::map>("map");
  // QPolygon mapToPolygon(const QRect &) const;
  binder.add_fun<QPolygon, const QRect &, &QTransform::mapToPolygon>("mapToPolygon");
  // QRect mapRect(const QRect &) const;
  binder.add_fun<QRect, const QRect &, &QTransform::mapRect>("mapRect");
  // QRectF mapRect(const QRectF &) const;
  binder.add_fun<QRectF, const QRectF &, &QTransform::mapRect>("mapRect");
  // void map(int, int, int *, int *) const;
  /// TODO: binder.add_const_void_fun<int, int, int *, int *, &QTransform::map>("map");
  // void map(qreal, qreal, qreal *, qreal *) const;
  /// TODO: binder.add_const_void_fun<qreal, qreal, qreal *, qreal *, &QTransform::map>("map");
  // const QMatrix & toAffine() const;
  /// ignore: binder.add_fun<const QMatrix &, &QTransform::toAffine>("toAffine");
  // QTransform & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QTransform & operator/=(qreal);
  binder.operators().div_assign<qreal>();
  // QTransform & operator+=(qreal);
  binder.operators().add_assign<qreal>();
  // QTransform & operator-=(qreal);
  binder.operators().sub_assign<qreal>();
  // static QTransform fromTranslate(qreal, qreal);
  binder.add_static<QTransform, qreal, qreal, &QTransform::fromTranslate>("fromTranslate");
  // static QTransform fromScale(qreal, qreal);
  binder.add_static<QTransform, qreal, qreal, &QTransform::fromScale>("fromScale");
}

void register_transform_file(script::Namespace root)
{
  using namespace script;

  register_transform_class(root);
  binding::Namespace binder{ root };

  // uint qHash(const QTransform &, uint);
  binder.add_fun<uint, const QTransform &, uint, &qHash>("qHash");
  // bool qFuzzyCompare(const QTransform &, const QTransform &);
  binder.add_fun<bool, const QTransform &, const QTransform &, &qFuzzyCompare>("qFuzzyCompare");
  // QDataStream & operator<<(QDataStream &, const QTransform &);
  binder.operators().put_to<QDataStream &, const QTransform &>();
  // QDataStream & operator>>(QDataStream &, QTransform &);
  binder.operators().read_from<QDataStream &, QTransform &>();
  // QDebug operator<<(QDebug, const QTransform &);
  binder.operators().put_to<QDebug, const QTransform &>();
  // QPoint operator*(const QPoint &, const QTransform &);
  binder.operators().mul<QPoint, const QPoint &, const QTransform &>();
  // QPointF operator*(const QPointF &, const QTransform &);
  binder.operators().mul<QPointF, const QPointF &, const QTransform &>();
  // QLineF operator*(const QLineF &, const QTransform &);
  binder.operators().mul<QLineF, const QLineF &, const QTransform &>();
  // QLine operator*(const QLine &, const QTransform &);
  binder.operators().mul<QLine, const QLine &, const QTransform &>();
  // QPolygon operator*(const QPolygon &, const QTransform &);
  binder.operators().mul<QPolygon, const QPolygon &, const QTransform &>();
  // QPolygonF operator*(const QPolygonF &, const QTransform &);
  binder.operators().mul<QPolygonF, const QPolygonF &, const QTransform &>();
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

