// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/vector3d.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/gui/vector2d.h"
#include "yasl/gui/vector3d.h"
#include "yasl/gui/vector4d.h"

#include <script/classbuilder.h>

static void register_vector3_d_class(script::Namespace ns)
{
  using namespace script;

  Class vector3_d = ns.Class("Vector3D").setId(script::Type::QVector3D).get();

  binding::Class<QVector3D> binder{ vector3_d };

  // QVector3D();
  binder.ctors().add_default();
  // QVector3D(const QVector3D &);
  binder.ctors().ctor<const QVector3D &>().create();
  // ~QVector3D();
  binder.add_dtor();
  // QVector3D & operator=(const QVector3D &);
  binder.operators().assign<const QVector3D &>();
  // QVector3D(Qt::Initialization);
  binder.ctors().ctor<Qt::Initialization>().create();
  // QVector3D(float, float, float);
  binder.ctors().ctor<float, float, float>().create();
  // QVector3D(const QPoint &);
  binder.ctors().ctor<const QPoint &>().create();
  // QVector3D(const QPointF &);
  binder.ctors().ctor<const QPointF &>().create();
  // QVector3D(const QVector2D &);
  binder.ctors().ctor<const QVector2D &>().create();
  // QVector3D(const QVector2D &, float);
  binder.ctors().ctor<const QVector2D &, float>().create();
  // QVector3D(const QVector4D &);
  binder.ctors().ctor<const QVector4D &>().create();
  // bool isNull() const;
  binder.fun<bool, &QVector3D::isNull>("isNull").create();
  // float x() const;
  binder.fun<float, &QVector3D::x>("x").create();
  // float y() const;
  binder.fun<float, &QVector3D::y>("y").create();
  // float z() const;
  binder.fun<float, &QVector3D::z>("z").create();
  // void setX(float);
  binder.void_fun<float, &QVector3D::setX>("setX").create();
  // void setY(float);
  binder.void_fun<float, &QVector3D::setY>("setY").create();
  // void setZ(float);
  binder.void_fun<float, &QVector3D::setZ>("setZ").create();
  // float operator[](int) const;
  binder.operators().const_subscript<float, int>();
  // float length() const;
  binder.fun<float, &QVector3D::length>("length").create();
  // float lengthSquared() const;
  binder.fun<float, &QVector3D::lengthSquared>("lengthSquared").create();
  // QVector3D normalized() const;
  binder.fun<QVector3D, &QVector3D::normalized>("normalized").create();
  // void normalize();
  binder.void_fun<&QVector3D::normalize>("normalize").create();
  // QVector3D & operator+=(const QVector3D &);
  binder.operators().add_assign<const QVector3D &>();
  // QVector3D & operator-=(const QVector3D &);
  binder.operators().sub_assign<const QVector3D &>();
  // QVector3D & operator*=(float);
  binder.operators().mul_assign<float>();
  // QVector3D & operator*=(const QVector3D &);
  binder.operators().mul_assign<const QVector3D &>();
  // QVector3D & operator/=(float);
  binder.operators().div_assign<float>();
  // QVector3D & operator/=(const QVector3D &);
  binder.operators().div_assign<const QVector3D &>();
  // static float dotProduct(const QVector3D &, const QVector3D &);
  binder.static_fun<float, const QVector3D &, const QVector3D &, &QVector3D::dotProduct>("dotProduct").create();
  // static QVector3D crossProduct(const QVector3D &, const QVector3D &);
  binder.static_fun<QVector3D, const QVector3D &, const QVector3D &, &QVector3D::crossProduct>("crossProduct").create();
  // static QVector3D normal(const QVector3D &, const QVector3D &);
  binder.static_fun<QVector3D, const QVector3D &, const QVector3D &, &QVector3D::normal>("normal").create();
  // static QVector3D normal(const QVector3D &, const QVector3D &, const QVector3D &);
  binder.static_fun<QVector3D, const QVector3D &, const QVector3D &, const QVector3D &, &QVector3D::normal>("normal").create();
  // QVector3D project(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  /// TODO: QVector3D project(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  // QVector3D unproject(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  /// TODO: QVector3D unproject(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  // float distanceToPoint(const QVector3D &) const;
  binder.fun<float, const QVector3D &, &QVector3D::distanceToPoint>("distanceToPoint").create();
  // float distanceToPlane(const QVector3D &, const QVector3D &) const;
  binder.fun<float, const QVector3D &, const QVector3D &, &QVector3D::distanceToPlane>("distanceToPlane").create();
  // float distanceToPlane(const QVector3D &, const QVector3D &, const QVector3D &) const;
  binder.fun<float, const QVector3D &, const QVector3D &, const QVector3D &, &QVector3D::distanceToPlane>("distanceToPlane").create();
  // float distanceToLine(const QVector3D &, const QVector3D &) const;
  binder.fun<float, const QVector3D &, const QVector3D &, &QVector3D::distanceToLine>("distanceToLine").create();
  // QVector2D toVector2D() const;
  binder.fun<QVector2D, &QVector3D::toVector2D>("toVector2D").create();
  // QVector4D toVector4D() const;
  binder.fun<QVector4D, &QVector3D::toVector4D>("toVector4D").create();
  // QPoint toPoint() const;
  binder.fun<QPoint, &QVector3D::toPoint>("toPoint").create();
  // QPointF toPointF() const;
  binder.fun<QPointF, &QVector3D::toPointF>("toPointF").create();
}


void register_vector3d_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_vector3_d_class(ns);
  binding::Namespace binder{ ns };

  // bool operator==(const QVector3D &, const QVector3D &);
  binder.operators().eq<const QVector3D &, const QVector3D &>();
  // bool operator!=(const QVector3D &, const QVector3D &);
  binder.operators().neq<const QVector3D &, const QVector3D &>();
  // const QVector3D operator+(const QVector3D &, const QVector3D &);
  binder.operators().add<const QVector3D, const QVector3D &, const QVector3D &>();
  // const QVector3D operator-(const QVector3D &, const QVector3D &);
  binder.operators().sub<const QVector3D, const QVector3D &, const QVector3D &>();
  // const QVector3D operator*(float, const QVector3D &);
  binder.operators().mul<const QVector3D, float, const QVector3D &>();
  // const QVector3D operator*(const QVector3D &, float);
  binder.operators().mul<const QVector3D, const QVector3D &, float>();
  // const QVector3D operator*(const QVector3D &, const QVector3D &);
  binder.operators().mul<const QVector3D, const QVector3D &, const QVector3D &>();
  // const QVector3D operator-(const QVector3D &);
  binder.operators().unary_minus<const QVector3D, const QVector3D &>();
  // const QVector3D operator/(const QVector3D &, float);
  binder.operators().div<const QVector3D, const QVector3D &, float>();
  // const QVector3D operator/(const QVector3D &, const QVector3D &);
  binder.operators().div<const QVector3D, const QVector3D &, const QVector3D &>();
  // bool qFuzzyCompare(const QVector3D &, const QVector3D &);
  binder.fun<bool, const QVector3D &, const QVector3D &, &qFuzzyCompare>("qFuzzyCompare").create();
  // QDebug operator<<(QDebug, const QVector3D &);
  /// TODO: QDebug operator<<(QDebug, const QVector3D &);
  // QDataStream & operator<<(QDataStream &, const QVector3D &);
  binder.operators().put_to<QDataStream &, const QVector3D &>();
  // QDataStream & operator>>(QDataStream &, QVector3D &);
  binder.operators().read_from<QDataStream &, QVector3D &>();
}

