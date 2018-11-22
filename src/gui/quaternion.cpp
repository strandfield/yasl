// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/quaternion.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/gui/quaternion.h"
#include "yasl/gui/vector3d.h"
#include "yasl/gui/vector4d.h"

#include <script/classbuilder.h>

static void register_quaternion_class(script::Namespace ns)
{
  using namespace script;

  Class quaternion = ns.newClass("Quaternion").setId(script::Type::QQuaternion).get();


  // QQuaternion();
  bind::default_constructor<QQuaternion>(quaternion).create();
  // QQuaternion(const QQuaternion &);
  bind::constructor<QQuaternion, const QQuaternion &>(quaternion).create();
  // ~QQuaternion();
  bind::destructor<QQuaternion>(quaternion).create();
  // QQuaternion & operator=(const QQuaternion &);
  bind::memop_assign<QQuaternion, const QQuaternion &>(quaternion);
  // QQuaternion(Qt::Initialization);
  bind::constructor<QQuaternion, Qt::Initialization>(quaternion).create();
  // QQuaternion(float, float, float, float);
  bind::constructor<QQuaternion, float, float, float, float>(quaternion).create();
  // QQuaternion(float, const QVector3D &);
  bind::constructor<QQuaternion, float, const QVector3D &>(quaternion).create();
  // QQuaternion(const QVector4D &);
  bind::constructor<QQuaternion, const QVector4D &>(quaternion).create();
  // bool isNull() const;
  bind::member_function<QQuaternion, bool, &QQuaternion::isNull>(quaternion, "isNull").create();
  // bool isIdentity() const;
  bind::member_function<QQuaternion, bool, &QQuaternion::isIdentity>(quaternion, "isIdentity").create();
  // QVector3D vector() const;
  bind::member_function<QQuaternion, QVector3D, &QQuaternion::vector>(quaternion, "vector").create();
  // void setVector(const QVector3D &);
  bind::void_member_function<QQuaternion, const QVector3D &, &QQuaternion::setVector>(quaternion, "setVector").create();
  // void setVector(float, float, float);
  bind::void_member_function<QQuaternion, float, float, float, &QQuaternion::setVector>(quaternion, "setVector").create();
  // float x() const;
  bind::member_function<QQuaternion, float, &QQuaternion::x>(quaternion, "x").create();
  // float y() const;
  bind::member_function<QQuaternion, float, &QQuaternion::y>(quaternion, "y").create();
  // float z() const;
  bind::member_function<QQuaternion, float, &QQuaternion::z>(quaternion, "z").create();
  // float scalar() const;
  bind::member_function<QQuaternion, float, &QQuaternion::scalar>(quaternion, "scalar").create();
  // void setX(float);
  bind::void_member_function<QQuaternion, float, &QQuaternion::setX>(quaternion, "setX").create();
  // void setY(float);
  bind::void_member_function<QQuaternion, float, &QQuaternion::setY>(quaternion, "setY").create();
  // void setZ(float);
  bind::void_member_function<QQuaternion, float, &QQuaternion::setZ>(quaternion, "setZ").create();
  // void setScalar(float);
  bind::void_member_function<QQuaternion, float, &QQuaternion::setScalar>(quaternion, "setScalar").create();
  // static float dotProduct(const QQuaternion &, const QQuaternion &);
  bind::static_member_function<QQuaternion, float, const QQuaternion &, const QQuaternion &, &QQuaternion::dotProduct>(quaternion, "dotProduct").create();
  // float length() const;
  bind::member_function<QQuaternion, float, &QQuaternion::length>(quaternion, "length").create();
  // float lengthSquared() const;
  bind::member_function<QQuaternion, float, &QQuaternion::lengthSquared>(quaternion, "lengthSquared").create();
  // QQuaternion normalized() const;
  bind::member_function<QQuaternion, QQuaternion, &QQuaternion::normalized>(quaternion, "normalized").create();
  // void normalize();
  bind::void_member_function<QQuaternion, &QQuaternion::normalize>(quaternion, "normalize").create();
  // QQuaternion inverted() const;
  bind::member_function<QQuaternion, QQuaternion, &QQuaternion::inverted>(quaternion, "inverted").create();
  // QQuaternion conjugated() const;
  bind::member_function<QQuaternion, QQuaternion, &QQuaternion::conjugated>(quaternion, "conjugated").create();
  // QQuaternion conjugate() const;
  bind::member_function<QQuaternion, QQuaternion, &QQuaternion::conjugate>(quaternion, "conjugate").create();
  // QVector3D rotatedVector(const QVector3D &) const;
  bind::member_function<QQuaternion, QVector3D, const QVector3D &, &QQuaternion::rotatedVector>(quaternion, "rotatedVector").create();
  // QQuaternion & operator+=(const QQuaternion &);
  bind::memop_add_assign<QQuaternion, const QQuaternion &>(quaternion);
  // QQuaternion & operator-=(const QQuaternion &);
  bind::memop_sub_assign<QQuaternion, const QQuaternion &>(quaternion);
  // QQuaternion & operator*=(float);
  bind::memop_mul_assign<QQuaternion, float>(quaternion);
  // QQuaternion & operator*=(const QQuaternion &);
  bind::memop_mul_assign<QQuaternion, const QQuaternion &>(quaternion);
  // QQuaternion & operator/=(float);
  bind::memop_div_assign<QQuaternion, float>(quaternion);
  // QVector4D toVector4D() const;
  bind::member_function<QQuaternion, QVector4D, &QQuaternion::toVector4D>(quaternion, "toVector4D").create();
  // void getAxisAndAngle(QVector3D *, float *) const;
  /// TODO: void getAxisAndAngle(QVector3D *, float *) const;
  // static QQuaternion fromAxisAndAngle(const QVector3D &, float);
  bind::static_member_function<QQuaternion, QQuaternion, const QVector3D &, float, &QQuaternion::fromAxisAndAngle>(quaternion, "fromAxisAndAngle").create();
  // void getAxisAndAngle(float *, float *, float *, float *) const;
  /// TODO: void getAxisAndAngle(float *, float *, float *, float *) const;
  // static QQuaternion fromAxisAndAngle(float, float, float, float);
  bind::static_member_function<QQuaternion, QQuaternion, float, float, float, float, &QQuaternion::fromAxisAndAngle>(quaternion, "fromAxisAndAngle").create();
  // QVector3D toEulerAngles() const;
  bind::member_function<QQuaternion, QVector3D, &QQuaternion::toEulerAngles>(quaternion, "toEulerAngles").create();
  // static QQuaternion fromEulerAngles(const QVector3D &);
  bind::static_member_function<QQuaternion, QQuaternion, const QVector3D &, &QQuaternion::fromEulerAngles>(quaternion, "fromEulerAngles").create();
  // void getEulerAngles(float *, float *, float *) const;
  /// TODO: void getEulerAngles(float *, float *, float *) const;
  // static QQuaternion fromEulerAngles(float, float, float);
  bind::static_member_function<QQuaternion, QQuaternion, float, float, float, &QQuaternion::fromEulerAngles>(quaternion, "fromEulerAngles").create();
  // QMatrix3x3 toRotationMatrix() const;
  /// TODO: QMatrix3x3 toRotationMatrix() const;
  // static QQuaternion fromRotationMatrix(const QMatrix3x3 &);
  /// TODO: static QQuaternion fromRotationMatrix(const QMatrix3x3 &);
  // void getAxes(QVector3D *, QVector3D *, QVector3D *) const;
  /// TODO: void getAxes(QVector3D *, QVector3D *, QVector3D *) const;
  // static QQuaternion fromAxes(const QVector3D &, const QVector3D &, const QVector3D &);
  bind::static_member_function<QQuaternion, QQuaternion, const QVector3D &, const QVector3D &, const QVector3D &, &QQuaternion::fromAxes>(quaternion, "fromAxes").create();
  // static QQuaternion fromDirection(const QVector3D &, const QVector3D &);
  bind::static_member_function<QQuaternion, QQuaternion, const QVector3D &, const QVector3D &, &QQuaternion::fromDirection>(quaternion, "fromDirection").create();
  // static QQuaternion rotationTo(const QVector3D &, const QVector3D &);
  bind::static_member_function<QQuaternion, QQuaternion, const QVector3D &, const QVector3D &, &QQuaternion::rotationTo>(quaternion, "rotationTo").create();
  // static QQuaternion slerp(const QQuaternion &, const QQuaternion &, float);
  bind::static_member_function<QQuaternion, QQuaternion, const QQuaternion &, const QQuaternion &, float, &QQuaternion::slerp>(quaternion, "slerp").create();
  // static QQuaternion nlerp(const QQuaternion &, const QQuaternion &, float);
  bind::static_member_function<QQuaternion, QQuaternion, const QQuaternion &, const QQuaternion &, float, &QQuaternion::nlerp>(quaternion, "nlerp").create();
}


void register_quaternion_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_quaternion_class(ns);

  // bool operator==(const QQuaternion &, const QQuaternion &);
  bind::op_eq<const QQuaternion &, const QQuaternion &>(ns);
  // const QQuaternion operator*(const QQuaternion &, const QQuaternion &);
  bind::op_mul<const QQuaternion, const QQuaternion &, const QQuaternion &>(ns);
  // bool operator!=(const QQuaternion &, const QQuaternion &);
  bind::op_neq<const QQuaternion &, const QQuaternion &>(ns);
  // const QQuaternion operator+(const QQuaternion &, const QQuaternion &);
  bind::op_add<const QQuaternion, const QQuaternion &, const QQuaternion &>(ns);
  // const QQuaternion operator-(const QQuaternion &, const QQuaternion &);
  bind::op_sub<const QQuaternion, const QQuaternion &, const QQuaternion &>(ns);
  // const QQuaternion operator*(float, const QQuaternion &);
  bind::op_mul<const QQuaternion, float, const QQuaternion &>(ns);
  // const QQuaternion operator*(const QQuaternion &, float);
  bind::op_mul<const QQuaternion, const QQuaternion &, float>(ns);
  // const QQuaternion operator-(const QQuaternion &);
  bind::op_unary_minus<const QQuaternion, const QQuaternion &>(ns);
  // const QQuaternion operator/(const QQuaternion &, float);
  bind::op_div<const QQuaternion, const QQuaternion &, float>(ns);
  // bool qFuzzyCompare(const QQuaternion &, const QQuaternion &);
  bind::function<bool, const QQuaternion &, const QQuaternion &, &qFuzzyCompare>(ns, "qFuzzyCompare").create();
  // QVector3D operator*(const QQuaternion &, const QVector3D &);
  bind::op_mul<QVector3D, const QQuaternion &, const QVector3D &>(ns);
  // QDebug operator<<(QDebug, const QQuaternion &);
  /// TODO: QDebug operator<<(QDebug, const QQuaternion &);
  // QDataStream & operator<<(QDataStream &, const QQuaternion &);
  bind::op_put_to<QDataStream &, const QQuaternion &>(ns);
  // QDataStream & operator>>(QDataStream &, QQuaternion &);
  bind::op_read_from<QDataStream &, QQuaternion &>(ns);
}

