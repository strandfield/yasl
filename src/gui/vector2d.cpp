// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/vector2d.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/gui/vector2d.h"
#include "yasl/gui/vector3d.h"
#include "yasl/gui/vector4d.h"

#include <script/classbuilder.h>

static void register_vector2_d_class(script::Namespace ns)
{
  using namespace script;

  Class vector2_d = ns.newClass("Vector2D").setId(script::Type::QVector2D).get();


  // QVector2D();
  bind::default_constructor<QVector2D>(vector2_d).create();
  // QVector2D(Qt::Initialization);
  bind::constructor<QVector2D, Qt::Initialization>(vector2_d).create();
  // QVector2D(const QVector2D &);
  bind::constructor<QVector2D, const QVector2D &>(vector2_d).create();
  // ~QVector2D();
  bind::destructor<QVector2D>(vector2_d).create();
  // QVector2D & operator=(const QVector2D &);
  bind::memop_assign<QVector2D, const QVector2D &>(vector2_d);
  // QVector2D(float, float);
  bind::constructor<QVector2D, float, float>(vector2_d).create();
  // QVector2D(const QPoint &);
  bind::constructor<QVector2D, const QPoint &>(vector2_d).create();
  // QVector2D(const QPointF &);
  bind::constructor<QVector2D, const QPointF &>(vector2_d).create();
  // QVector2D(const QVector3D &);
  bind::constructor<QVector2D, const QVector3D &>(vector2_d).create();
  // QVector2D(const QVector4D &);
  bind::constructor<QVector2D, const QVector4D &>(vector2_d).create();
  // bool isNull() const;
  bind::member_function<QVector2D, bool, &QVector2D::isNull>(vector2_d, "isNull").create();
  // float x() const;
  bind::member_function<QVector2D, float, &QVector2D::x>(vector2_d, "x").create();
  // float y() const;
  bind::member_function<QVector2D, float, &QVector2D::y>(vector2_d, "y").create();
  // void setX(float);
  bind::void_member_function<QVector2D, float, &QVector2D::setX>(vector2_d, "setX").create();
  // void setY(float);
  bind::void_member_function<QVector2D, float, &QVector2D::setY>(vector2_d, "setY").create();
  // float operator[](int) const;
  bind::memop_const_subscript<QVector2D, float, int>(vector2_d);
  // float length() const;
  bind::member_function<QVector2D, float, &QVector2D::length>(vector2_d, "length").create();
  // float lengthSquared() const;
  bind::member_function<QVector2D, float, &QVector2D::lengthSquared>(vector2_d, "lengthSquared").create();
  // QVector2D normalized() const;
  bind::member_function<QVector2D, QVector2D, &QVector2D::normalized>(vector2_d, "normalized").create();
  // void normalize();
  bind::void_member_function<QVector2D, &QVector2D::normalize>(vector2_d, "normalize").create();
  // float distanceToPoint(const QVector2D &) const;
  bind::member_function<QVector2D, float, const QVector2D &, &QVector2D::distanceToPoint>(vector2_d, "distanceToPoint").create();
  // float distanceToLine(const QVector2D &, const QVector2D &) const;
  bind::member_function<QVector2D, float, const QVector2D &, const QVector2D &, &QVector2D::distanceToLine>(vector2_d, "distanceToLine").create();
  // QVector2D & operator+=(const QVector2D &);
  bind::memop_add_assign<QVector2D, const QVector2D &>(vector2_d);
  // QVector2D & operator-=(const QVector2D &);
  bind::memop_sub_assign<QVector2D, const QVector2D &>(vector2_d);
  // QVector2D & operator*=(float);
  bind::memop_mul_assign<QVector2D, float>(vector2_d);
  // QVector2D & operator*=(const QVector2D &);
  bind::memop_mul_assign<QVector2D, const QVector2D &>(vector2_d);
  // QVector2D & operator/=(float);
  bind::memop_div_assign<QVector2D, float>(vector2_d);
  // QVector2D & operator/=(const QVector2D &);
  bind::memop_div_assign<QVector2D, const QVector2D &>(vector2_d);
  // static float dotProduct(const QVector2D &, const QVector2D &);
  bind::static_member_function<QVector2D, float, const QVector2D &, const QVector2D &, &QVector2D::dotProduct>(vector2_d, "dotProduct").create();
  // QVector3D toVector3D() const;
  bind::member_function<QVector2D, QVector3D, &QVector2D::toVector3D>(vector2_d, "toVector3D").create();
  // QVector4D toVector4D() const;
  bind::member_function<QVector2D, QVector4D, &QVector2D::toVector4D>(vector2_d, "toVector4D").create();
  // QPoint toPoint() const;
  bind::member_function<QVector2D, QPoint, &QVector2D::toPoint>(vector2_d, "toPoint").create();
  // QPointF toPointF() const;
  bind::member_function<QVector2D, QPointF, &QVector2D::toPointF>(vector2_d, "toPointF").create();
}


void register_vector2d_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_vector2_d_class(ns);

  // bool operator==(const QVector2D &, const QVector2D &);
  bind::op_eq<const QVector2D &, const QVector2D &>(ns);
  // bool operator!=(const QVector2D &, const QVector2D &);
  bind::op_neq<const QVector2D &, const QVector2D &>(ns);
  // const QVector2D operator+(const QVector2D &, const QVector2D &);
  bind::op_add<const QVector2D, const QVector2D &, const QVector2D &>(ns);
  // const QVector2D operator-(const QVector2D &, const QVector2D &);
  bind::op_sub<const QVector2D, const QVector2D &, const QVector2D &>(ns);
  // const QVector2D operator*(float, const QVector2D &);
  bind::op_mul<const QVector2D, float, const QVector2D &>(ns);
  // const QVector2D operator*(const QVector2D &, float);
  bind::op_mul<const QVector2D, const QVector2D &, float>(ns);
  // const QVector2D operator*(const QVector2D &, const QVector2D &);
  bind::op_mul<const QVector2D, const QVector2D &, const QVector2D &>(ns);
  // const QVector2D operator-(const QVector2D &);
  bind::op_unary_minus<const QVector2D, const QVector2D &>(ns);
  // const QVector2D operator/(const QVector2D &, float);
  bind::op_div<const QVector2D, const QVector2D &, float>(ns);
  // const QVector2D operator/(const QVector2D &, const QVector2D &);
  bind::op_div<const QVector2D, const QVector2D &, const QVector2D &>(ns);
  // bool qFuzzyCompare(const QVector2D &, const QVector2D &);
  bind::function<bool, const QVector2D &, const QVector2D &, &qFuzzyCompare>(ns, "qFuzzyCompare").create();
  // QDebug operator<<(QDebug, const QVector2D &);
  /// TODO: QDebug operator<<(QDebug, const QVector2D &);
  // QDataStream & operator<<(QDataStream &, const QVector2D &);
  bind::op_put_to<QDataStream &, const QVector2D &>(ns);
  // QDataStream & operator>>(QDataStream &, QVector2D &);
  bind::op_read_from<QDataStream &, QVector2D &>(ns);
}

