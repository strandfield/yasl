// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/vector4d.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/genericvarianthandler.h"

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


  // QVector4D();
  bind::default_constructor<QVector4D>(vector4_d).create();
  // QVector4D(const QVector4D &);
  bind::constructor<QVector4D, const QVector4D &>(vector4_d).create();
  // ~QVector4D();
  bind::destructor<QVector4D>(vector4_d).create();
  // QVector4D & operator=(const QVector4D &);
  bind::memop_assign<QVector4D, const QVector4D &>(vector4_d);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QVector4D(Qt::Initialization);
  bind::constructor<QVector4D, Qt::Initialization>(vector4_d).create();
#endif
  // QVector4D(float, float, float, float);
  bind::constructor<QVector4D, float, float, float, float>(vector4_d).create();
  // QVector4D(const QPoint &);
  bind::constructor<QVector4D, const QPoint &>(vector4_d).create();
  // QVector4D(const QPointF &);
  bind::constructor<QVector4D, const QPointF &>(vector4_d).create();
  // QVector4D(const QVector2D &);
  bind::constructor<QVector4D, const QVector2D &>(vector4_d).create();
  // QVector4D(const QVector2D &, float, float);
  bind::constructor<QVector4D, const QVector2D &, float, float>(vector4_d).create();
  // QVector4D(const QVector3D &);
  bind::constructor<QVector4D, const QVector3D &>(vector4_d).create();
  // QVector4D(const QVector3D &, float);
  bind::constructor<QVector4D, const QVector3D &, float>(vector4_d).create();
  // bool isNull() const;
  bind::member_function<QVector4D, bool, &QVector4D::isNull>(vector4_d, "isNull").create();
  // float x() const;
  bind::member_function<QVector4D, float, &QVector4D::x>(vector4_d, "x").create();
  // float y() const;
  bind::member_function<QVector4D, float, &QVector4D::y>(vector4_d, "y").create();
  // float z() const;
  bind::member_function<QVector4D, float, &QVector4D::z>(vector4_d, "z").create();
  // float w() const;
  bind::member_function<QVector4D, float, &QVector4D::w>(vector4_d, "w").create();
  // void setX(float);
  bind::void_member_function<QVector4D, float, &QVector4D::setX>(vector4_d, "setX").create();
  // void setY(float);
  bind::void_member_function<QVector4D, float, &QVector4D::setY>(vector4_d, "setY").create();
  // void setZ(float);
  bind::void_member_function<QVector4D, float, &QVector4D::setZ>(vector4_d, "setZ").create();
  // void setW(float);
  bind::void_member_function<QVector4D, float, &QVector4D::setW>(vector4_d, "setW").create();
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
  // float operator[](int) const;
  bind::memop_const_subscript<QVector4D, float, int>(vector4_d);
#endif
  // float length() const;
  bind::member_function<QVector4D, float, &QVector4D::length>(vector4_d, "length").create();
  // float lengthSquared() const;
  bind::member_function<QVector4D, float, &QVector4D::lengthSquared>(vector4_d, "lengthSquared").create();
  // QVector4D normalized() const;
  bind::member_function<QVector4D, QVector4D, &QVector4D::normalized>(vector4_d, "normalized").create();
  // void normalize();
  bind::void_member_function<QVector4D, &QVector4D::normalize>(vector4_d, "normalize").create();
  // QVector4D & operator+=(const QVector4D &);
  bind::memop_add_assign<QVector4D, const QVector4D &>(vector4_d);
  // QVector4D & operator-=(const QVector4D &);
  bind::memop_sub_assign<QVector4D, const QVector4D &>(vector4_d);
  // QVector4D & operator*=(float);
  bind::memop_mul_assign<QVector4D, float>(vector4_d);
  // QVector4D & operator*=(const QVector4D &);
  bind::memop_mul_assign<QVector4D, const QVector4D &>(vector4_d);
  // QVector4D & operator/=(float);
  bind::memop_div_assign<QVector4D, float>(vector4_d);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // QVector4D & operator/=(const QVector4D &);
  bind::memop_div_assign<QVector4D, const QVector4D &>(vector4_d);
#endif
  // static float dotProduct(const QVector4D &, const QVector4D &);
  bind::static_member_function<QVector4D, float, const QVector4D &, const QVector4D &, &QVector4D::dotProduct>(vector4_d, "dotProduct").create();
  // QVector2D toVector2D() const;
  bind::member_function<QVector4D, QVector2D, &QVector4D::toVector2D>(vector4_d, "toVector2D").create();
  // QVector2D toVector2DAffine() const;
  bind::member_function<QVector4D, QVector2D, &QVector4D::toVector2DAffine>(vector4_d, "toVector2DAffine").create();
  // QVector3D toVector3D() const;
  bind::member_function<QVector4D, QVector3D, &QVector4D::toVector3D>(vector4_d, "toVector3D").create();
  // QVector3D toVector3DAffine() const;
  bind::member_function<QVector4D, QVector3D, &QVector4D::toVector3DAffine>(vector4_d, "toVector3DAffine").create();
  // QPoint toPoint() const;
  bind::member_function<QVector4D, QPoint, &QVector4D::toPoint>(vector4_d, "toPoint").create();
  // QPointF toPointF() const;
  bind::member_function<QVector4D, QPointF, &QVector4D::toPointF>(vector4_d, "toPointF").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QVector4D, QMetaType::QVector4D>>();
}


void register_vector4d_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_vector4_d_class(ns);

  // bool operator==(const QVector4D &, const QVector4D &);
  bind::op_eq<const QVector4D &, const QVector4D &>(ns);
  // bool operator!=(const QVector4D &, const QVector4D &);
  bind::op_neq<const QVector4D &, const QVector4D &>(ns);
  // const QVector4D operator+(const QVector4D &, const QVector4D &);
  bind::op_add<const QVector4D, const QVector4D &, const QVector4D &>(ns);
  // const QVector4D operator-(const QVector4D &, const QVector4D &);
  bind::op_sub<const QVector4D, const QVector4D &, const QVector4D &>(ns);
  // const QVector4D operator*(float, const QVector4D &);
  bind::op_mul<const QVector4D, float, const QVector4D &>(ns);
  // const QVector4D operator*(const QVector4D &, float);
  bind::op_mul<const QVector4D, const QVector4D &, float>(ns);
  // const QVector4D operator*(const QVector4D &, const QVector4D &);
  bind::op_mul<const QVector4D, const QVector4D &, const QVector4D &>(ns);
  // const QVector4D operator-(const QVector4D &);
  bind::op_unary_minus<const QVector4D, const QVector4D &>(ns);
  // const QVector4D operator/(const QVector4D &, float);
  bind::op_div<const QVector4D, const QVector4D &, float>(ns);
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
  // const QVector4D operator/(const QVector4D &, const QVector4D &);
  bind::op_div<const QVector4D, const QVector4D &, const QVector4D &>(ns);
#endif
  // bool qFuzzyCompare(const QVector4D &, const QVector4D &);
  bind::function<bool, const QVector4D &, const QVector4D &, &qFuzzyCompare>(ns, "qFuzzyCompare").create();
  // QDebug operator<<(QDebug, const QVector4D &);
  /// TODO: QDebug operator<<(QDebug, const QVector4D &);
  // QDataStream & operator<<(QDataStream &, const QVector4D &);
  bind::op_put_to<QDataStream &, const QVector4D &>(ns);
  // QDataStream & operator>>(QDataStream &, QVector4D &);
  bind::op_read_from<QDataStream &, QVector4D &>(ns);
}
