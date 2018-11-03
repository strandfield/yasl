// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/vector2d.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

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

  Class vector2_d = ns.Class("Vector2D").setId(script::Type::QVector2D).get();

  binding::ClassBinder<QVector2D> binder{ vector2_d };

  // QVector2D();
  binder.default_ctor().create();
  // QVector2D(Qt::Initialization);
  binder.ctor<Qt::Initialization>().create();
  // QVector2D(const QVector2D &);
  binder.ctor<const QVector2D &>().create();
  // ~QVector2D();
  binder.dtor().create();
  // QVector2D & operator=(const QVector2D &);
  binder.operators().assign<const QVector2D &>();
  // QVector2D(float, float);
  binder.ctor<float, float>().create();
  // QVector2D(const QPoint &);
  binder.ctor<const QPoint &>().create();
  // QVector2D(const QPointF &);
  binder.ctor<const QPointF &>().create();
  // QVector2D(const QVector3D &);
  binder.ctor<const QVector3D &>().create();
  // QVector2D(const QVector4D &);
  binder.ctor<const QVector4D &>().create();
  // bool isNull() const;
  binder.fun<bool, &QVector2D::isNull>("isNull").create();
  // float x() const;
  binder.fun<float, &QVector2D::x>("x").create();
  // float y() const;
  binder.fun<float, &QVector2D::y>("y").create();
  // void setX(float);
  binder.void_fun<float, &QVector2D::setX>("setX").create();
  // void setY(float);
  binder.void_fun<float, &QVector2D::setY>("setY").create();
  // float operator[](int) const;
  binder.operators().const_subscript<float, int>();
  // float length() const;
  binder.fun<float, &QVector2D::length>("length").create();
  // float lengthSquared() const;
  binder.fun<float, &QVector2D::lengthSquared>("lengthSquared").create();
  // QVector2D normalized() const;
  binder.fun<QVector2D, &QVector2D::normalized>("normalized").create();
  // void normalize();
  binder.void_fun<&QVector2D::normalize>("normalize").create();
  // float distanceToPoint(const QVector2D &) const;
  binder.fun<float, const QVector2D &, &QVector2D::distanceToPoint>("distanceToPoint").create();
  // float distanceToLine(const QVector2D &, const QVector2D &) const;
  binder.fun<float, const QVector2D &, const QVector2D &, &QVector2D::distanceToLine>("distanceToLine").create();
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
  binder.static_fun<float, const QVector2D &, const QVector2D &, &QVector2D::dotProduct>("dotProduct").create();
  // QVector3D toVector3D() const;
  binder.fun<QVector3D, &QVector2D::toVector3D>("toVector3D").create();
  // QVector4D toVector4D() const;
  binder.fun<QVector4D, &QVector2D::toVector4D>("toVector4D").create();
  // QPoint toPoint() const;
  binder.fun<QPoint, &QVector2D::toPoint>("toPoint").create();
  // QPointF toPointF() const;
  binder.fun<QPointF, &QVector2D::toPointF>("toPointF").create();
}


void register_vector2d_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_vector2_d_class(ns);
  binding::Namespace binder{ ns };

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
  binder.fun<bool, const QVector2D &, const QVector2D &, &qFuzzyCompare>("qFuzzyCompare").create();
  // QDebug operator<<(QDebug, const QVector2D &);
  /// TODO: QDebug operator<<(QDebug, const QVector2D &);
  // QDataStream & operator<<(QDataStream &, const QVector2D &);
  binder.operators().put_to<QDataStream &, const QVector2D &>();
  // QDataStream & operator>>(QDataStream &, QVector2D &);
  binder.operators().read_from<QDataStream &, QVector2D &>();
}

