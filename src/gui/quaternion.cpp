// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/quaternion.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/gui/quaternion.h"
#include "yasl/gui/vector3d.h"
#include "yasl/gui/vector4d.h"

#include <script/classbuilder.h>

static void register_quaternion_class(script::Namespace ns)
{
  using namespace script;

  Class quaternion = ns.Class("Quaternion").setId(script::Type::QQuaternion).get();

  binding::ClassBinder<QQuaternion> binder{ quaternion };

  // QQuaternion();
  binder.default_ctor().create();
  // QQuaternion(const QQuaternion &);
  binder.ctor<const QQuaternion &>().create();
  // ~QQuaternion();
  binder.dtor().create();
  // QQuaternion & operator=(const QQuaternion &);
  binder.operators().assign<const QQuaternion &>();
  // QQuaternion(Qt::Initialization);
  binder.ctor<Qt::Initialization>().create();
  // QQuaternion(float, float, float, float);
  binder.ctor<float, float, float, float>().create();
  // QQuaternion(float, const QVector3D &);
  binder.ctor<float, const QVector3D &>().create();
  // QQuaternion(const QVector4D &);
  binder.ctor<const QVector4D &>().create();
  // bool isNull() const;
  binder.fun<bool, &QQuaternion::isNull>("isNull").create();
  // bool isIdentity() const;
  binder.fun<bool, &QQuaternion::isIdentity>("isIdentity").create();
  // QVector3D vector() const;
  binder.fun<QVector3D, &QQuaternion::vector>("vector").create();
  // void setVector(const QVector3D &);
  binder.void_fun<const QVector3D &, &QQuaternion::setVector>("setVector").create();
  // void setVector(float, float, float);
  binder.void_fun<float, float, float, &QQuaternion::setVector>("setVector").create();
  // float x() const;
  binder.fun<float, &QQuaternion::x>("x").create();
  // float y() const;
  binder.fun<float, &QQuaternion::y>("y").create();
  // float z() const;
  binder.fun<float, &QQuaternion::z>("z").create();
  // float scalar() const;
  binder.fun<float, &QQuaternion::scalar>("scalar").create();
  // void setX(float);
  binder.void_fun<float, &QQuaternion::setX>("setX").create();
  // void setY(float);
  binder.void_fun<float, &QQuaternion::setY>("setY").create();
  // void setZ(float);
  binder.void_fun<float, &QQuaternion::setZ>("setZ").create();
  // void setScalar(float);
  binder.void_fun<float, &QQuaternion::setScalar>("setScalar").create();
  // static float dotProduct(const QQuaternion &, const QQuaternion &);
  binder.static_fun<float, const QQuaternion &, const QQuaternion &, &QQuaternion::dotProduct>("dotProduct").create();
  // float length() const;
  binder.fun<float, &QQuaternion::length>("length").create();
  // float lengthSquared() const;
  binder.fun<float, &QQuaternion::lengthSquared>("lengthSquared").create();
  // QQuaternion normalized() const;
  binder.fun<QQuaternion, &QQuaternion::normalized>("normalized").create();
  // void normalize();
  binder.void_fun<&QQuaternion::normalize>("normalize").create();
  // QQuaternion inverted() const;
  binder.fun<QQuaternion, &QQuaternion::inverted>("inverted").create();
  // QQuaternion conjugated() const;
  binder.fun<QQuaternion, &QQuaternion::conjugated>("conjugated").create();
  // QQuaternion conjugate() const;
  binder.fun<QQuaternion, &QQuaternion::conjugate>("conjugate").create();
  // QVector3D rotatedVector(const QVector3D &) const;
  binder.fun<QVector3D, const QVector3D &, &QQuaternion::rotatedVector>("rotatedVector").create();
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
  binder.fun<QVector4D, &QQuaternion::toVector4D>("toVector4D").create();
  // void getAxisAndAngle(QVector3D *, float *) const;
  /// TODO: void getAxisAndAngle(QVector3D *, float *) const;
  // static QQuaternion fromAxisAndAngle(const QVector3D &, float);
  binder.static_fun<QQuaternion, const QVector3D &, float, &QQuaternion::fromAxisAndAngle>("fromAxisAndAngle").create();
  // void getAxisAndAngle(float *, float *, float *, float *) const;
  /// TODO: void getAxisAndAngle(float *, float *, float *, float *) const;
  // static QQuaternion fromAxisAndAngle(float, float, float, float);
  binder.static_fun<QQuaternion, float, float, float, float, &QQuaternion::fromAxisAndAngle>("fromAxisAndAngle").create();
  // QVector3D toEulerAngles() const;
  binder.fun<QVector3D, &QQuaternion::toEulerAngles>("toEulerAngles").create();
  // static QQuaternion fromEulerAngles(const QVector3D &);
  binder.static_fun<QQuaternion, const QVector3D &, &QQuaternion::fromEulerAngles>("fromEulerAngles").create();
  // void getEulerAngles(float *, float *, float *) const;
  /// TODO: void getEulerAngles(float *, float *, float *) const;
  // static QQuaternion fromEulerAngles(float, float, float);
  binder.static_fun<QQuaternion, float, float, float, &QQuaternion::fromEulerAngles>("fromEulerAngles").create();
  // QMatrix3x3 toRotationMatrix() const;
  /// TODO: QMatrix3x3 toRotationMatrix() const;
  // static QQuaternion fromRotationMatrix(const QMatrix3x3 &);
  /// TODO: static QQuaternion fromRotationMatrix(const QMatrix3x3 &);
  // void getAxes(QVector3D *, QVector3D *, QVector3D *) const;
  /// TODO: void getAxes(QVector3D *, QVector3D *, QVector3D *) const;
  // static QQuaternion fromAxes(const QVector3D &, const QVector3D &, const QVector3D &);
  binder.static_fun<QQuaternion, const QVector3D &, const QVector3D &, const QVector3D &, &QQuaternion::fromAxes>("fromAxes").create();
  // static QQuaternion fromDirection(const QVector3D &, const QVector3D &);
  binder.static_fun<QQuaternion, const QVector3D &, const QVector3D &, &QQuaternion::fromDirection>("fromDirection").create();
  // static QQuaternion rotationTo(const QVector3D &, const QVector3D &);
  binder.static_fun<QQuaternion, const QVector3D &, const QVector3D &, &QQuaternion::rotationTo>("rotationTo").create();
  // static QQuaternion slerp(const QQuaternion &, const QQuaternion &, float);
  binder.static_fun<QQuaternion, const QQuaternion &, const QQuaternion &, float, &QQuaternion::slerp>("slerp").create();
  // static QQuaternion nlerp(const QQuaternion &, const QQuaternion &, float);
  binder.static_fun<QQuaternion, const QQuaternion &, const QQuaternion &, float, &QQuaternion::nlerp>("nlerp").create();
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
  binder.fun<bool, const QQuaternion &, const QQuaternion &, &qFuzzyCompare>("qFuzzyCompare").create();
  // QVector3D operator*(const QQuaternion &, const QVector3D &);
  binder.operators().mul<QVector3D, const QQuaternion &, const QVector3D &>();
  // QDebug operator<<(QDebug, const QQuaternion &);
  /// TODO: QDebug operator<<(QDebug, const QQuaternion &);
  // QDataStream & operator<<(QDataStream &, const QQuaternion &);
  binder.operators().put_to<QDataStream &, const QQuaternion &>();
  // QDataStream & operator>>(QDataStream &, QQuaternion &);
  binder.operators().read_from<QDataStream &, QQuaternion &>();
}

