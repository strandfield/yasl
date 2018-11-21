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

  Class vector4_d = ns.newClass("Vector4D").setId(script::Type::QVector4D).get();

  binding::ClassBinder<QVector4D> binder{ vector4_d };

  // QVector4D();
  binder.default_ctor().create();
  // QVector4D(const QVector4D &);
  binder.ctor<const QVector4D &>().create();
  // ~QVector4D();
  binder.dtor().create();
  // QVector4D & operator=(const QVector4D &);
  binder.operators().assign<const QVector4D &>();
  // QVector4D(Qt::Initialization);
  binder.ctor<Qt::Initialization>().create();
  // QVector4D(float, float, float, float);
  binder.ctor<float, float, float, float>().create();
  // QVector4D(const QPoint &);
  binder.ctor<const QPoint &>().create();
  // QVector4D(const QPointF &);
  binder.ctor<const QPointF &>().create();
  // QVector4D(const QVector2D &);
  binder.ctor<const QVector2D &>().create();
  // QVector4D(const QVector2D &, float, float);
  binder.ctor<const QVector2D &, float, float>().create();
  // QVector4D(const QVector3D &);
  binder.ctor<const QVector3D &>().create();
  // QVector4D(const QVector3D &, float);
  binder.ctor<const QVector3D &, float>().create();
  // bool isNull() const;
  binder.fun<bool, &QVector4D::isNull>("isNull").create();
  // float x() const;
  binder.fun<float, &QVector4D::x>("x").create();
  // float y() const;
  binder.fun<float, &QVector4D::y>("y").create();
  // float z() const;
  binder.fun<float, &QVector4D::z>("z").create();
  // float w() const;
  binder.fun<float, &QVector4D::w>("w").create();
  // void setX(float);
  binder.void_fun<float, &QVector4D::setX>("setX").create();
  // void setY(float);
  binder.void_fun<float, &QVector4D::setY>("setY").create();
  // void setZ(float);
  binder.void_fun<float, &QVector4D::setZ>("setZ").create();
  // void setW(float);
  binder.void_fun<float, &QVector4D::setW>("setW").create();
  // float operator[](int) const;
  binder.operators().const_subscript<float, int>();
  // float length() const;
  binder.fun<float, &QVector4D::length>("length").create();
  // float lengthSquared() const;
  binder.fun<float, &QVector4D::lengthSquared>("lengthSquared").create();
  // QVector4D normalized() const;
  binder.fun<QVector4D, &QVector4D::normalized>("normalized").create();
  // void normalize();
  binder.void_fun<&QVector4D::normalize>("normalize").create();
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
  binder.static_fun<float, const QVector4D &, const QVector4D &, &QVector4D::dotProduct>("dotProduct").create();
  // QVector2D toVector2D() const;
  binder.fun<QVector2D, &QVector4D::toVector2D>("toVector2D").create();
  // QVector2D toVector2DAffine() const;
  binder.fun<QVector2D, &QVector4D::toVector2DAffine>("toVector2DAffine").create();
  // QVector3D toVector3D() const;
  binder.fun<QVector3D, &QVector4D::toVector3D>("toVector3D").create();
  // QVector3D toVector3DAffine() const;
  binder.fun<QVector3D, &QVector4D::toVector3DAffine>("toVector3DAffine").create();
  // QPoint toPoint() const;
  binder.fun<QPoint, &QVector4D::toPoint>("toPoint").create();
  // QPointF toPointF() const;
  binder.fun<QPointF, &QVector4D::toPointF>("toPointF").create();
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
  binder.fun<bool, const QVector4D &, const QVector4D &, &qFuzzyCompare>("qFuzzyCompare").create();
  // QDebug operator<<(QDebug, const QVector4D &);
  /// TODO: QDebug operator<<(QDebug, const QVector4D &);
  // QDataStream & operator<<(QDataStream &, const QVector4D &);
  binder.operators().put_to<QDataStream &, const QVector4D &>();
  // QDataStream & operator>>(QDataStream &, QVector4D &);
  binder.operators().read_from<QDataStream &, QVector4D &>();
}

