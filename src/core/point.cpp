// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/point.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/genericvarianthandler.h"

#include "yasl/core/datastream.h"
#include "yasl/core/point.h"

#include <script/classbuilder.h>

static void register_point_class(script::Namespace ns)
{
  using namespace script;

  Class point = ns.newClass("Point").setId(script::Type::QPoint).get();


  // QPoint();
  bind::default_constructor<QPoint>(point).create();
  // QPoint(int, int);
  bind::constructor<QPoint, int, int>(point).create();
  // ~QPoint();
  bind::destructor<QPoint>(point).create();
  // bool isNull() const;
  bind::member_function<QPoint, bool, &QPoint::isNull>(point, "isNull").create();
  // int x() const;
  bind::member_function<QPoint, int, &QPoint::x>(point, "x").create();
  // int y() const;
  bind::member_function<QPoint, int, &QPoint::y>(point, "y").create();
  // void setX(int);
  bind::void_member_function<QPoint, int, &QPoint::setX>(point, "setX").create();
  // void setY(int);
  bind::void_member_function<QPoint, int, &QPoint::setY>(point, "setY").create();
  // int manhattanLength() const;
  bind::member_function<QPoint, int, &QPoint::manhattanLength>(point, "manhattanLength").create();
  // int & rx();
  bind::non_const_getter<QPoint, int &, &QPoint::rx>(point, "rx").create();
  // int & ry();
  bind::non_const_getter<QPoint, int &, &QPoint::ry>(point, "ry").create();
  // QPoint & operator+=(const QPoint &);
  bind::memop_add_assign<QPoint, const QPoint &>(point);
  // QPoint & operator-=(const QPoint &);
  bind::memop_sub_assign<QPoint, const QPoint &>(point);
  // QPoint & operator*=(float);
  bind::memop_mul_assign<QPoint, float>(point);
  // QPoint & operator*=(double);
  bind::memop_mul_assign<QPoint, double>(point);
  // QPoint & operator*=(int);
  bind::memop_mul_assign<QPoint, int>(point);
  // QPoint & operator/=(qreal);
  bind::memop_div_assign<QPoint, qreal>(point);
  // static int dotProduct(const QPoint &, const QPoint &);
  bind::static_member_function<QPoint, int, const QPoint &, const QPoint &, &QPoint::dotProduct>(point, "dotProduct").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QPoint, QMetaType::QPoint>>();
}


static void register_point_f_class(script::Namespace ns)
{
  using namespace script;

  Class point_f = ns.newClass("PointF").setId(script::Type::QPointF).get();


  // QPointF();
  bind::default_constructor<QPointF>(point_f).create();
  // QPointF(const QPoint &);
  bind::constructor<QPointF, const QPoint &>(point_f).create();
  // QPointF(qreal, qreal);
  bind::constructor<QPointF, qreal, qreal>(point_f).create();
  // ~QPointF();
  bind::destructor<QPointF>(point_f).create();
  // qreal manhattanLength() const;
  bind::member_function<QPointF, qreal, &QPointF::manhattanLength>(point_f, "manhattanLength").create();
  // bool isNull() const;
  bind::member_function<QPointF, bool, &QPointF::isNull>(point_f, "isNull").create();
  // qreal x() const;
  bind::member_function<QPointF, qreal, &QPointF::x>(point_f, "x").create();
  // qreal y() const;
  bind::member_function<QPointF, qreal, &QPointF::y>(point_f, "y").create();
  // void setX(qreal);
  bind::void_member_function<QPointF, qreal, &QPointF::setX>(point_f, "setX").create();
  // void setY(qreal);
  bind::void_member_function<QPointF, qreal, &QPointF::setY>(point_f, "setY").create();
  // qreal & rx();
  bind::non_const_getter<QPointF, qreal &, &QPointF::rx>(point_f, "rx").create();
  // qreal & ry();
  bind::non_const_getter<QPointF, qreal &, &QPointF::ry>(point_f, "ry").create();
  // QPointF & operator+=(const QPointF &);
  bind::memop_add_assign<QPointF, const QPointF &>(point_f);
  // QPointF & operator-=(const QPointF &);
  bind::memop_sub_assign<QPointF, const QPointF &>(point_f);
  // QPointF & operator*=(qreal);
  bind::memop_mul_assign<QPointF, qreal>(point_f);
  // QPointF & operator/=(qreal);
  bind::memop_div_assign<QPointF, qreal>(point_f);
  // static qreal dotProduct(const QPointF &, const QPointF &);
  bind::static_member_function<QPointF, qreal, const QPointF &, const QPointF &, &QPointF::dotProduct>(point_f, "dotProduct").create();
  // QPoint toPoint() const;
  bind::member_function<QPointF, QPoint, &QPointF::toPoint>(point_f, "toPoint").create();

  yasl::registerVariantHandler<yasl::GenericVariantHandler<QPointF, QMetaType::QPointF>>();
}


void register_point_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_point_class(ns);
  register_point_f_class(ns);

  // QDataStream & operator<<(QDataStream &, const QPoint &);
  bind::op_put_to<QDataStream &, const QPoint &>(ns);
  // QDataStream & operator>>(QDataStream &, QPoint &);
  bind::op_read_from<QDataStream &, QPoint &>(ns);
  // bool operator==(const QPoint &, const QPoint &);
  bind::op_eq<const QPoint &, const QPoint &>(ns);
  // bool operator!=(const QPoint &, const QPoint &);
  bind::op_neq<const QPoint &, const QPoint &>(ns);
  // const QPoint operator+(const QPoint &, const QPoint &);
  bind::op_add<const QPoint, const QPoint &, const QPoint &>(ns);
  // const QPoint operator-(const QPoint &, const QPoint &);
  bind::op_sub<const QPoint, const QPoint &, const QPoint &>(ns);
  // const QPoint operator*(const QPoint &, float);
  bind::op_mul<const QPoint, const QPoint &, float>(ns);
  // const QPoint operator*(const QPoint &, double);
  bind::op_mul<const QPoint, const QPoint &, double>(ns);
  // const QPoint operator*(const QPoint &, int);
  bind::op_mul<const QPoint, const QPoint &, int>(ns);
  // const QPoint operator*(float, const QPoint &);
  bind::op_mul<const QPoint, float, const QPoint &>(ns);
  // const QPoint operator*(double, const QPoint &);
  bind::op_mul<const QPoint, double, const QPoint &>(ns);
  // const QPoint operator*(int, const QPoint &);
  bind::op_mul<const QPoint, int, const QPoint &>(ns);
  // const QPoint operator+(const QPoint &);
  bind::op_unary_plus<const QPoint, const QPoint &>(ns);
  // const QPoint operator-(const QPoint &);
  bind::op_unary_minus<const QPoint, const QPoint &>(ns);
  // const QPoint operator/(const QPoint &, qreal);
  bind::op_div<const QPoint, const QPoint &, qreal>(ns);
  // QDebug operator<<(QDebug, const QPoint &);
  /// TODO: QDebug operator<<(QDebug, const QPoint &);
  // QDataStream & operator<<(QDataStream &, const QPointF &);
  bind::op_put_to<QDataStream &, const QPointF &>(ns);
  // QDataStream & operator>>(QDataStream &, QPointF &);
  bind::op_read_from<QDataStream &, QPointF &>(ns);
  // bool operator==(const QPointF &, const QPointF &);
  bind::op_eq<const QPointF &, const QPointF &>(ns);
  // bool operator!=(const QPointF &, const QPointF &);
  bind::op_neq<const QPointF &, const QPointF &>(ns);
  // const QPointF operator+(const QPointF &, const QPointF &);
  bind::op_add<const QPointF, const QPointF &, const QPointF &>(ns);
  // const QPointF operator-(const QPointF &, const QPointF &);
  bind::op_sub<const QPointF, const QPointF &, const QPointF &>(ns);
  // const QPointF operator*(const QPointF &, qreal);
  bind::op_mul<const QPointF, const QPointF &, qreal>(ns);
  // const QPointF operator*(qreal, const QPointF &);
  bind::op_mul<const QPointF, qreal, const QPointF &>(ns);
  // const QPointF operator+(const QPointF &);
  bind::op_unary_plus<const QPointF, const QPointF &>(ns);
  // const QPointF operator-(const QPointF &);
  bind::op_unary_minus<const QPointF, const QPointF &>(ns);
  // const QPointF operator/(const QPointF &, qreal);
  bind::op_div<const QPointF, const QPointF &, qreal>(ns);
  // QDebug operator<<(QDebug, const QPointF &);
  /// TODO: QDebug operator<<(QDebug, const QPointF &);
}

