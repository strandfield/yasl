// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/vector4d.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/gui/vector2d.h"
#include "yasl/gui/vector3d.h"
#include "yasl/gui/vector4d.h"

#include <script/classbuilder.h>

static void register_vector4_d_class(script::Namespace ns)
{
  using namespace script;

  Class vector4_d = ns.Class("Vector4D").setId(script::Type::QVector4D).get();

  binding::Class<QVector4D> binder{ vector4_d };

  // QVector4D();
  binder.ctors().add_default();
  // QVector4D(const QVector4D &);
  binder.ctors().add<const QVector4D &>();
  // ~QVector4D();
  binder.add_dtor();
  // QVector4D & operator=(const QVector4D &);
  binder.operators().assign<const QVector4D &>();
  // QVector4D(Qt::Initialization);
  binder.ctors().add<Qt::Initialization>();
  // QVector4D(float, float, float, float);
  binder.ctors().add<float, float, float, float>();
  // QVector4D(const QPoint &);
  binder.ctors().add<const QPoint &>();
  // QVector4D(const QPointF &);
  binder.ctors().add<const QPointF &>();
  // QVector4D(const QVector2D &);
  binder.ctors().add<const QVector2D &>();
  // QVector4D(const QVector2D &, float, float);
  binder.ctors().add<const QVector2D &, float, float>();
  // QVector4D(const QVector3D &);
  binder.ctors().add<const QVector3D &>();
  // QVector4D(const QVector3D &, float);
  binder.ctors().add<const QVector3D &, float>();
  // bool isNull() const;
  binder.add_fun<bool, &QVector4D::isNull>("isNull");
  // float x() const;
  binder.add_fun<float, &QVector4D::x>("x");
  // float y() const;
  binder.add_fun<float, &QVector4D::y>("y");
  // float z() const;
  binder.add_fun<float, &QVector4D::z>("z");
  // float w() const;
  binder.add_fun<float, &QVector4D::w>("w");
  // void setX(float);
  binder.add_void_fun<float, &QVector4D::setX>("setX");
  // void setY(float);
  binder.add_void_fun<float, &QVector4D::setY>("setY");
  // void setZ(float);
  binder.add_void_fun<float, &QVector4D::setZ>("setZ");
  // void setW(float);
  binder.add_void_fun<float, &QVector4D::setW>("setW");
  // float operator[](int) const;
  binder.operators().const_subscript<float, int>();
  // float length() const;
  binder.add_fun<float, &QVector4D::length>("length");
  // float lengthSquared() const;
  binder.add_fun<float, &QVector4D::lengthSquared>("lengthSquared");
  // QVector4D normalized() const;
  binder.add_fun<QVector4D, &QVector4D::normalized>("normalized");
  // void normalize();
  binder.add_void_fun<&QVector4D::normalize>("normalize");
  // QVector4D & operator+=(const QVector4D &);
  binder.operators().add_assign<const QVector4D &>();
  // QVector4D & operator-=(const QVector4D &);
  binder.operators().sub_assign<const QVector4D &>();
  // QVector4D & operator*=(float);
  binder.operators().mul_assign<float>();
  // QVector4D & operator*=(const QVector4D &);
  binder.operators().mul_assign<const QVector4D &>();
  // QVector4D & operator/=(float);
  binder.operators().div_assign<float>();
  // QVector4D & operator/=(const QVector4D &);
  binder.operators().div_assign<const QVector4D &>();
  // static float dotProduct(const QVector4D &, const QVector4D &);
  binder.add_static<float, const QVector4D &, const QVector4D &, &QVector4D::dotProduct>("dotProduct");
  // QVector2D toVector2D() const;
  binder.add_fun<QVector2D, &QVector4D::toVector2D>("toVector2D");
  // QVector2D toVector2DAffine() const;
  binder.add_fun<QVector2D, &QVector4D::toVector2DAffine>("toVector2DAffine");
  // QVector3D toVector3D() const;
  binder.add_fun<QVector3D, &QVector4D::toVector3D>("toVector3D");
  // QVector3D toVector3DAffine() const;
  binder.add_fun<QVector3D, &QVector4D::toVector3DAffine>("toVector3DAffine");
  // QPoint toPoint() const;
  binder.add_fun<QPoint, &QVector4D::toPoint>("toPoint");
  // QPointF toPointF() const;
  binder.add_fun<QPointF, &QVector4D::toPointF>("toPointF");
}


void register_vector4d_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_vector4_d_class(ns);
  binding::Namespace binder{ ns };

  // bool operator==(const QVector4D &, const QVector4D &);
  binder.operators().eq<const QVector4D &, const QVector4D &>();
  // bool operator!=(const QVector4D &, const QVector4D &);
  binder.operators().neq<const QVector4D &, const QVector4D &>();
  // const QVector4D operator+(const QVector4D &, const QVector4D &);
  binder.operators().add<const QVector4D, const QVector4D &, const QVector4D &>();
  // const QVector4D operator-(const QVector4D &, const QVector4D &);
  binder.operators().sub<const QVector4D, const QVector4D &, const QVector4D &>();
  // const QVector4D operator*(float, const QVector4D &);
  binder.operators().mul<const QVector4D, float, const QVector4D &>();
  // const QVector4D operator*(const QVector4D &, float);
  binder.operators().mul<const QVector4D, const QVector4D &, float>();
  // const QVector4D operator*(const QVector4D &, const QVector4D &);
  binder.operators().mul<const QVector4D, const QVector4D &, const QVector4D &>();
  // const QVector4D operator-(const QVector4D &);
  binder.operators().unary_minus<const QVector4D, const QVector4D &>();
  // const QVector4D operator/(const QVector4D &, float);
  binder.operators().div<const QVector4D, const QVector4D &, float>();
  // const QVector4D operator/(const QVector4D &, const QVector4D &);
  binder.operators().div<const QVector4D, const QVector4D &, const QVector4D &>();
  // bool qFuzzyCompare(const QVector4D &, const QVector4D &);
  binder.add_fun<bool, const QVector4D &, const QVector4D &, &qFuzzyCompare>("qFuzzyCompare");
  // QDebug operator<<(QDebug, const QVector4D &);
  /// TODO: QDebug operator<<(QDebug, const QVector4D &);
  // QDataStream & operator<<(QDataStream &, const QVector4D &);
  binder.operators().put_to<QDataStream &, const QVector4D &>();
  // QDataStream & operator>>(QDataStream &, QVector4D &);
  binder.operators().read_from<QDataStream &, QVector4D &>();
}

