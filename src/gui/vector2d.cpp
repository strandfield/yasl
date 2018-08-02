// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/vector2d.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"

#include "yasl/gui/vector3d.h"
#include "yasl/gui/vector4d.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/namespace.h>

#include <QDebug>

static void register_vector2_d_class(script::Namespace ns)
{
  using namespace script;

  Class vector2_d = ns.Class("Vector2D").setId(script::Type::QVector2D).get();

  binding::Class<QVector2D> binder{ vector2_d };

  // ~QVector2D();
  binder.add_dtor();
  // QVector2D();
  binder.ctors().add_default();
  // QVector2D(Qt::Initialization);
  binder.ctors().add<Qt::Initialization>();
  // QVector2D(float, float);
  binder.ctors().add<float, float>();
  // QVector2D(const QPoint &);
  binder.ctors().add<const QPoint &>();
  // QVector2D(const QPointF &);
  binder.ctors().add<const QPointF &>();
  // QVector2D(const QVector3D &);
  binder.ctors().add<const QVector3D &>();
  // QVector2D(const QVector4D &);
  binder.ctors().add<const QVector4D &>();
  // bool isNull() const;
  binder.add_fun<bool, &QVector2D::isNull>("isNull");
  // float x() const;
  binder.add_fun<float, &QVector2D::x>("x");
  // float y() const;
  binder.add_fun<float, &QVector2D::y>("y");
  // void setX(float);
  binder.add_void_fun<float, &QVector2D::setX>("setX");
  // void setY(float);
  binder.add_void_fun<float, &QVector2D::setY>("setY");
  // float & operator[](int);
  /// TODO: binder.operators().subscript<float &, int>();
  // float operator[](int) const;
  binder.operators().subscript<float, int>();
  // float length() const;
  binder.add_fun<float, &QVector2D::length>("length");
  // float lengthSquared() const;
  binder.add_fun<float, &QVector2D::lengthSquared>("lengthSquared");
  // QVector2D normalized() const;
  binder.add_fun<QVector2D, &QVector2D::normalized>("normalized");
  // void normalize();
  binder.add_void_fun<&QVector2D::normalize>("normalize");
  // float distanceToPoint(const QVector2D &) const;
  binder.add_fun<float, const QVector2D &, &QVector2D::distanceToPoint>("distanceToPoint");
  // float distanceToLine(const QVector2D &, const QVector2D &) const;
  binder.add_fun<float, const QVector2D &, const QVector2D &, &QVector2D::distanceToLine>("distanceToLine");
  // QVector2D & operator+=(const QVector2D &);
  binder.operators().add_assign<const QVector2D &>();
  // QVector2D & operator-=(const QVector2D &);
  binder.operators().sub_assign<const QVector2D &>();
  // QVector2D & operator*=(float);
  binder.operators().mul_assign<float>();
  // QVector2D & operator*=(const QVector2D &);
  binder.operators().mul_assign<const QVector2D &>();
  // QVector2D & operator/=(float);
  binder.operators().div_assign<float>();
  // QVector2D & operator/=(const QVector2D &);
  binder.operators().div_assign<const QVector2D &>();
  // static float dotProduct(const QVector2D &, const QVector2D &);
  binder.add_static<float, const QVector2D &, const QVector2D &, &QVector2D::dotProduct>("dotProduct");
  // QVector3D toVector3D() const;
  binder.add_fun<QVector3D, &QVector2D::toVector3D>("toVector3D");
  // QVector4D toVector4D() const;
  binder.add_fun<QVector4D, &QVector2D::toVector4D>("toVector4D");
  // QPoint toPoint() const;
  binder.add_fun<QPoint, &QVector2D::toPoint>("toPoint");
  // QPointF toPointF() const;
  binder.add_fun<QPointF, &QVector2D::toPointF>("toPointF");
}

void register_vector2d_file(script::Namespace root)
{
  using namespace script;

  register_vector2_d_class(root);
  binding::Namespace binder{ root };

  // bool operator==(const QVector2D &, const QVector2D &);
  binder.operators().eq<const QVector2D &, const QVector2D &>();
  // bool operator!=(const QVector2D &, const QVector2D &);
  binder.operators().neq<const QVector2D &, const QVector2D &>();
  // const QVector2D operator+(const QVector2D &, const QVector2D &);
  binder.operators().add<const QVector2D, const QVector2D &, const QVector2D &>();
  // const QVector2D operator-(const QVector2D &, const QVector2D &);
  binder.operators().sub<const QVector2D, const QVector2D &, const QVector2D &>();
  // const QVector2D operator*(float, const QVector2D &);
  binder.operators().mul<const QVector2D, float, const QVector2D &>();
  // const QVector2D operator*(const QVector2D &, float);
  binder.operators().mul<const QVector2D, const QVector2D &, float>();
  // const QVector2D operator*(const QVector2D &, const QVector2D &);
  binder.operators().mul<const QVector2D, const QVector2D &, const QVector2D &>();
  // const QVector2D operator-(const QVector2D &);
  binder.operators().unary_minus<const QVector2D, const QVector2D &>();
  // const QVector2D operator/(const QVector2D &, float);
  binder.operators().div<const QVector2D, const QVector2D &, float>();
  // const QVector2D operator/(const QVector2D &, const QVector2D &);
  binder.operators().div<const QVector2D, const QVector2D &, const QVector2D &>();
  // bool qFuzzyCompare(const QVector2D &, const QVector2D &);
  binder.add_fun<bool, const QVector2D &, const QVector2D &, &qFuzzyCompare>("qFuzzyCompare");
  // QDebug operator<<(QDebug, const QVector2D &);
  binder.operators().left_shift<QDebug, QDebug, const QVector2D &>();
  // QDataStream & operator<<(QDataStream &, const QVector2D &);
  binder.operators().put_to<QDataStream &, const QVector2D &>();
  // QDataStream & operator>>(QDataStream &, QVector2D &);
  binder.operators().read_from<QDataStream &, QVector2D &>();
}

