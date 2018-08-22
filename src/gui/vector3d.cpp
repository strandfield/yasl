// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/vector3d.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

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
  binder.ctors().add<const QVector3D &>();
  // ~QVector3D();
  binder.add_dtor();
  // QVector3D & operator=(const QVector3D &);
  binder.operators().assign<const QVector3D &>();
  // QVector3D(Qt::Initialization);
  binder.ctors().add<Qt::Initialization>();
  // QVector3D(float, float, float);
  binder.ctors().add<float, float, float>();
  // QVector3D(const QPoint &);
  binder.ctors().add<const QPoint &>();
  // QVector3D(const QPointF &);
  binder.ctors().add<const QPointF &>();
  // QVector3D(const QVector2D &);
  binder.ctors().add<const QVector2D &>();
  // QVector3D(const QVector2D &, float);
  binder.ctors().add<const QVector2D &, float>();
  // QVector3D(const QVector4D &);
  binder.ctors().add<const QVector4D &>();
  // bool isNull() const;
  binder.add_fun<bool, &QVector3D::isNull>("isNull");
  // float x() const;
  binder.add_fun<float, &QVector3D::x>("x");
  // float y() const;
  binder.add_fun<float, &QVector3D::y>("y");
  // float z() const;
  binder.add_fun<float, &QVector3D::z>("z");
  // void setX(float);
  binder.add_void_fun<float, &QVector3D::setX>("setX");
  // void setY(float);
  binder.add_void_fun<float, &QVector3D::setY>("setY");
  // void setZ(float);
  binder.add_void_fun<float, &QVector3D::setZ>("setZ");
  // float operator[](int) const;
  binder.operators().const_subscript<float, int>();
  // float length() const;
  binder.add_fun<float, &QVector3D::length>("length");
  // float lengthSquared() const;
  binder.add_fun<float, &QVector3D::lengthSquared>("lengthSquared");
  // QVector3D normalized() const;
  binder.add_fun<QVector3D, &QVector3D::normalized>("normalized");
  // void normalize();
  binder.add_void_fun<&QVector3D::normalize>("normalize");
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
  binder.add_static<float, const QVector3D &, const QVector3D &, &QVector3D::dotProduct>("dotProduct");
  // static QVector3D crossProduct(const QVector3D &, const QVector3D &);
  binder.add_static<QVector3D, const QVector3D &, const QVector3D &, &QVector3D::crossProduct>("crossProduct");
  // static QVector3D normal(const QVector3D &, const QVector3D &);
  binder.add_static<QVector3D, const QVector3D &, const QVector3D &, &QVector3D::normal>("normal");
  // static QVector3D normal(const QVector3D &, const QVector3D &, const QVector3D &);
  binder.add_static<QVector3D, const QVector3D &, const QVector3D &, const QVector3D &, &QVector3D::normal>("normal");
  // QVector3D project(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  /// TODO: QVector3D project(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  // QVector3D unproject(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  /// TODO: QVector3D unproject(const QMatrix4x4 &, const QMatrix4x4 &, const QRect &) const;
  // float distanceToPoint(const QVector3D &) const;
  binder.add_fun<float, const QVector3D &, &QVector3D::distanceToPoint>("distanceToPoint");
  // float distanceToPlane(const QVector3D &, const QVector3D &) const;
  binder.add_fun<float, const QVector3D &, const QVector3D &, &QVector3D::distanceToPlane>("distanceToPlane");
  // float distanceToPlane(const QVector3D &, const QVector3D &, const QVector3D &) const;
  binder.add_fun<float, const QVector3D &, const QVector3D &, const QVector3D &, &QVector3D::distanceToPlane>("distanceToPlane");
  // float distanceToLine(const QVector3D &, const QVector3D &) const;
  binder.add_fun<float, const QVector3D &, const QVector3D &, &QVector3D::distanceToLine>("distanceToLine");
  // QVector2D toVector2D() const;
  binder.add_fun<QVector2D, &QVector3D::toVector2D>("toVector2D");
  // QVector4D toVector4D() const;
  binder.add_fun<QVector4D, &QVector3D::toVector4D>("toVector4D");
  // QPoint toPoint() const;
  binder.add_fun<QPoint, &QVector3D::toPoint>("toPoint");
  // QPointF toPointF() const;
  binder.add_fun<QPointF, &QVector3D::toPointF>("toPointF");
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
  binder.add_fun<bool, const QVector3D &, const QVector3D &, &qFuzzyCompare>("qFuzzyCompare");
  // QDebug operator<<(QDebug, const QVector3D &);
  /// TODO: QDebug operator<<(QDebug, const QVector3D &);
  // QDataStream & operator<<(QDataStream &, const QVector3D &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QVector3D &);
  // QDataStream & operator>>(QDataStream &, QVector3D &);
  /// TODO: QDataStream & operator>>(QDataStream &, QVector3D &);
}

