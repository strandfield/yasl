// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/quaternion.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/enums.h"
#include "yasl/gui/quaternion.h"
#include "yasl/gui/vector3d.h"
#include "yasl/gui/vector4d.h"

#include <script/classbuilder.h>

static void register_quaternion_class(script::Namespace ns)
{
  using namespace script;

  Class quaternion = ns.Class("Quaternion").setId(script::Type::QQuaternion).get();

  binding::Class<QQuaternion> binder{ quaternion };

  // QQuaternion();
  binder.ctors().add_default();
  // QQuaternion(const QQuaternion &);
  binder.ctors().add<const QQuaternion &>();
  // ~QQuaternion();
  binder.add_dtor();
  // QQuaternion & operator=(const QQuaternion &);
  binder.operators().assign<const QQuaternion &>();
  // QQuaternion(Qt::Initialization);
  binder.ctors().add<Qt::Initialization>();
  // QQuaternion(float, float, float, float);
  binder.ctors().add<float, float, float, float>();
  // QQuaternion(float, const QVector3D &);
  binder.ctors().add<float, const QVector3D &>();
  // QQuaternion(const QVector4D &);
  binder.ctors().add<const QVector4D &>();
  // bool isNull() const;
  binder.add_fun<bool, &QQuaternion::isNull>("isNull");
  // bool isIdentity() const;
  binder.add_fun<bool, &QQuaternion::isIdentity>("isIdentity");
  // QVector3D vector() const;
  binder.add_fun<QVector3D, &QQuaternion::vector>("vector");
  // void setVector(const QVector3D &);
  binder.add_void_fun<const QVector3D &, &QQuaternion::setVector>("setVector");
  // void setVector(float, float, float);
  binder.add_void_fun<float, float, float, &QQuaternion::setVector>("setVector");
  // float x() const;
  binder.add_fun<float, &QQuaternion::x>("x");
  // float y() const;
  binder.add_fun<float, &QQuaternion::y>("y");
  // float z() const;
  binder.add_fun<float, &QQuaternion::z>("z");
  // float scalar() const;
  binder.add_fun<float, &QQuaternion::scalar>("scalar");
  // void setX(float);
  binder.add_void_fun<float, &QQuaternion::setX>("setX");
  // void setY(float);
  binder.add_void_fun<float, &QQuaternion::setY>("setY");
  // void setZ(float);
  binder.add_void_fun<float, &QQuaternion::setZ>("setZ");
  // void setScalar(float);
  binder.add_void_fun<float, &QQuaternion::setScalar>("setScalar");
  // static float dotProduct(const QQuaternion &, const QQuaternion &);
  binder.add_static<float, const QQuaternion &, const QQuaternion &, &QQuaternion::dotProduct>("dotProduct");
  // float length() const;
  binder.add_fun<float, &QQuaternion::length>("length");
  // float lengthSquared() const;
  binder.add_fun<float, &QQuaternion::lengthSquared>("lengthSquared");
  // QQuaternion normalized() const;
  binder.add_fun<QQuaternion, &QQuaternion::normalized>("normalized");
  // void normalize();
  binder.add_void_fun<&QQuaternion::normalize>("normalize");
  // QQuaternion inverted() const;
  binder.add_fun<QQuaternion, &QQuaternion::inverted>("inverted");
  // QQuaternion conjugated() const;
  binder.add_fun<QQuaternion, &QQuaternion::conjugated>("conjugated");
  // QQuaternion conjugate() const;
  binder.add_fun<QQuaternion, &QQuaternion::conjugate>("conjugate");
  // QVector3D rotatedVector(const QVector3D &) const;
  binder.add_fun<QVector3D, const QVector3D &, &QQuaternion::rotatedVector>("rotatedVector");
  // QQuaternion & operator+=(const QQuaternion &);
  binder.operators().add_assign<const QQuaternion &>();
  // QQuaternion & operator-=(const QQuaternion &);
  binder.operators().sub_assign<const QQuaternion &>();
  // QQuaternion & operator*=(float);
  binder.operators().mul_assign<float>();
  // QQuaternion & operator*=(const QQuaternion &);
  binder.operators().mul_assign<const QQuaternion &>();
  // QQuaternion & operator/=(float);
  binder.operators().div_assign<float>();
  // QVector4D toVector4D() const;
  binder.add_fun<QVector4D, &QQuaternion::toVector4D>("toVector4D");
  // void getAxisAndAngle(QVector3D *, float *) const;
  /// TODO: void getAxisAndAngle(QVector3D *, float *) const;
  // static QQuaternion fromAxisAndAngle(const QVector3D &, float);
  binder.add_static<QQuaternion, const QVector3D &, float, &QQuaternion::fromAxisAndAngle>("fromAxisAndAngle");
  // void getAxisAndAngle(float *, float *, float *, float *) const;
  /// TODO: void getAxisAndAngle(float *, float *, float *, float *) const;
  // static QQuaternion fromAxisAndAngle(float, float, float, float);
  binder.add_static<QQuaternion, float, float, float, float, &QQuaternion::fromAxisAndAngle>("fromAxisAndAngle");
  // QVector3D toEulerAngles() const;
  binder.add_fun<QVector3D, &QQuaternion::toEulerAngles>("toEulerAngles");
  // static QQuaternion fromEulerAngles(const QVector3D &);
  binder.add_static<QQuaternion, const QVector3D &, &QQuaternion::fromEulerAngles>("fromEulerAngles");
  // void getEulerAngles(float *, float *, float *) const;
  /// TODO: void getEulerAngles(float *, float *, float *) const;
  // static QQuaternion fromEulerAngles(float, float, float);
  binder.add_static<QQuaternion, float, float, float, &QQuaternion::fromEulerAngles>("fromEulerAngles");
  // QMatrix3x3 toRotationMatrix() const;
  /// TODO: QMatrix3x3 toRotationMatrix() const;
  // static QQuaternion fromRotationMatrix(const QMatrix3x3 &);
  /// TODO: static QQuaternion fromRotationMatrix(const QMatrix3x3 &);
  // void getAxes(QVector3D *, QVector3D *, QVector3D *) const;
  /// TODO: void getAxes(QVector3D *, QVector3D *, QVector3D *) const;
  // static QQuaternion fromAxes(const QVector3D &, const QVector3D &, const QVector3D &);
  binder.add_static<QQuaternion, const QVector3D &, const QVector3D &, const QVector3D &, &QQuaternion::fromAxes>("fromAxes");
  // static QQuaternion fromDirection(const QVector3D &, const QVector3D &);
  binder.add_static<QQuaternion, const QVector3D &, const QVector3D &, &QQuaternion::fromDirection>("fromDirection");
  // static QQuaternion rotationTo(const QVector3D &, const QVector3D &);
  binder.add_static<QQuaternion, const QVector3D &, const QVector3D &, &QQuaternion::rotationTo>("rotationTo");
  // static QQuaternion slerp(const QQuaternion &, const QQuaternion &, float);
  binder.add_static<QQuaternion, const QQuaternion &, const QQuaternion &, float, &QQuaternion::slerp>("slerp");
  // static QQuaternion nlerp(const QQuaternion &, const QQuaternion &, float);
  binder.add_static<QQuaternion, const QQuaternion &, const QQuaternion &, float, &QQuaternion::nlerp>("nlerp");
}


void register_quaternion_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_quaternion_class(ns);
  binding::Namespace binder{ ns };

  // bool operator==(const QQuaternion &, const QQuaternion &);
  binder.operators().eq<const QQuaternion &, const QQuaternion &>();
  // const QQuaternion operator*(const QQuaternion &, const QQuaternion &);
  binder.operators().mul<const QQuaternion, const QQuaternion &, const QQuaternion &>();
  // bool operator!=(const QQuaternion &, const QQuaternion &);
  binder.operators().neq<const QQuaternion &, const QQuaternion &>();
  // const QQuaternion operator+(const QQuaternion &, const QQuaternion &);
  binder.operators().add<const QQuaternion, const QQuaternion &, const QQuaternion &>();
  // const QQuaternion operator-(const QQuaternion &, const QQuaternion &);
  binder.operators().sub<const QQuaternion, const QQuaternion &, const QQuaternion &>();
  // const QQuaternion operator*(float, const QQuaternion &);
  binder.operators().mul<const QQuaternion, float, const QQuaternion &>();
  // const QQuaternion operator*(const QQuaternion &, float);
  binder.operators().mul<const QQuaternion, const QQuaternion &, float>();
  // const QQuaternion operator-(const QQuaternion &);
  binder.operators().unary_minus<const QQuaternion, const QQuaternion &>();
  // const QQuaternion operator/(const QQuaternion &, float);
  binder.operators().div<const QQuaternion, const QQuaternion &, float>();
  // bool qFuzzyCompare(const QQuaternion &, const QQuaternion &);
  binder.add_fun<bool, const QQuaternion &, const QQuaternion &, &qFuzzyCompare>("qFuzzyCompare");
  // QVector3D operator*(const QQuaternion &, const QVector3D &);
  binder.operators().mul<QVector3D, const QQuaternion &, const QVector3D &>();
  // QDebug operator<<(QDebug, const QQuaternion &);
  /// TODO: QDebug operator<<(QDebug, const QQuaternion &);
  // QDataStream & operator<<(QDataStream &, const QQuaternion &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QQuaternion &);
  // QDataStream & operator>>(QDataStream &, QQuaternion &);
  /// TODO: QDataStream & operator>>(QDataStream &, QQuaternion &);
}

