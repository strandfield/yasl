// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/point.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/point.h"

#include <script/classbuilder.h>

static void register_point_class(script::Namespace ns)
{
  using namespace script;

  Class point = ns.Class("Point").setId(script::Type::QPoint).get();

  binding::Class<QPoint> binder{ point };

  // QPoint();
  binder.ctors().add_default();
  // QPoint(int, int);
  binder.ctors().add<int, int>();
  // ~QPoint();
  binder.add_dtor();
  // bool isNull() const;
  binder.add_fun<bool, &QPoint::isNull>("isNull");
  // int x() const;
  binder.add_fun<int, &QPoint::x>("x");
  // int y() const;
  binder.add_fun<int, &QPoint::y>("y");
  // void setX(int);
  binder.add_void_fun<int, &QPoint::setX>("setX");
  // void setY(int);
  binder.add_void_fun<int, &QPoint::setY>("setY");
  // int manhattanLength() const;
  binder.add_fun<int, &QPoint::manhattanLength>("manhattanLength");
  // int & rx();
  binder.add_ref_mem<int &, &QPoint::rx>("rx");
  // int & ry();
  binder.add_ref_mem<int &, &QPoint::ry>("ry");
  // QPoint & operator+=(const QPoint &);
  binder.operators().add_assign<const QPoint &>();
  // QPoint & operator-=(const QPoint &);
  binder.operators().sub_assign<const QPoint &>();
  // QPoint & operator*=(float);
  binder.operators().mul_assign<float>();
  // QPoint & operator*=(double);
  binder.operators().mul_assign<double>();
  // QPoint & operator*=(int);
  binder.operators().mul_assign<int>();
  // QPoint & operator/=(qreal);
  binder.operators().div_assign<qreal>();
  // static int dotProduct(const QPoint &, const QPoint &);
  binder.add_static<int, const QPoint &, const QPoint &, &QPoint::dotProduct>("dotProduct");
}


static void register_point_f_class(script::Namespace ns)
{
  using namespace script;

  Class point_f = ns.Class("PointF").setId(script::Type::QPointF).get();

  binding::Class<QPointF> binder{ point_f };

  // QPointF();
  binder.ctors().add_default();
  // QPointF(const QPoint &);
  binder.ctors().add<const QPoint &>();
  // QPointF(qreal, qreal);
  binder.ctors().add<qreal, qreal>();
  // ~QPointF();
  binder.add_dtor();
  // qreal manhattanLength() const;
  binder.add_fun<qreal, &QPointF::manhattanLength>("manhattanLength");
  // bool isNull() const;
  binder.add_fun<bool, &QPointF::isNull>("isNull");
  // qreal x() const;
  binder.add_fun<qreal, &QPointF::x>("x");
  // qreal y() const;
  binder.add_fun<qreal, &QPointF::y>("y");
  // void setX(qreal);
  binder.add_void_fun<qreal, &QPointF::setX>("setX");
  // void setY(qreal);
  binder.add_void_fun<qreal, &QPointF::setY>("setY");
  // qreal & rx();
  binder.add_ref_mem<qreal &, &QPointF::rx>("rx");
  // qreal & ry();
  binder.add_ref_mem<qreal &, &QPointF::ry>("ry");
  // QPointF & operator+=(const QPointF &);
  binder.operators().add_assign<const QPointF &>();
  // QPointF & operator-=(const QPointF &);
  binder.operators().sub_assign<const QPointF &>();
  // QPointF & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QPointF & operator/=(qreal);
  binder.operators().div_assign<qreal>();
  // static qreal dotProduct(const QPointF &, const QPointF &);
  binder.add_static<qreal, const QPointF &, const QPointF &, &QPointF::dotProduct>("dotProduct");
  // QPoint toPoint() const;
  binder.add_fun<QPoint, &QPointF::toPoint>("toPoint");
}


void register_point_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_point_class(ns);
  register_point_f_class(ns);
  binding::Namespace binder{ ns };

  // QDataStream & operator<<(QDataStream &, const QPoint &);
  binder.operators().put_to<QDataStream &, const QPoint &>();
  // QDataStream & operator>>(QDataStream &, QPoint &);
  binder.operators().read_from<QDataStream &, QPoint &>();
  // bool operator==(const QPoint &, const QPoint &);
  binder.operators().eq<const QPoint &, const QPoint &>();
  // bool operator!=(const QPoint &, const QPoint &);
  binder.operators().neq<const QPoint &, const QPoint &>();
  // const QPoint operator+(const QPoint &, const QPoint &);
  binder.operators().add<const QPoint, const QPoint &, const QPoint &>();
  // const QPoint operator-(const QPoint &, const QPoint &);
  binder.operators().sub<const QPoint, const QPoint &, const QPoint &>();
  // const QPoint operator*(const QPoint &, float);
  binder.operators().mul<const QPoint, const QPoint &, float>();
  // const QPoint operator*(const QPoint &, double);
  binder.operators().mul<const QPoint, const QPoint &, double>();
  // const QPoint operator*(const QPoint &, int);
  binder.operators().mul<const QPoint, const QPoint &, int>();
  // const QPoint operator*(float, const QPoint &);
  binder.operators().mul<const QPoint, float, const QPoint &>();
  // const QPoint operator*(double, const QPoint &);
  binder.operators().mul<const QPoint, double, const QPoint &>();
  // const QPoint operator*(int, const QPoint &);
  binder.operators().mul<const QPoint, int, const QPoint &>();
  // const QPoint operator+(const QPoint &);
  binder.operators().unary_plus<const QPoint, const QPoint &>();
  // const QPoint operator-(const QPoint &);
  binder.operators().unary_minus<const QPoint, const QPoint &>();
  // const QPoint operator/(const QPoint &, qreal);
  binder.operators().div<const QPoint, const QPoint &, qreal>();
  // QDebug operator<<(QDebug, const QPoint &);
  /// TODO: QDebug operator<<(QDebug, const QPoint &);
  // QDataStream & operator<<(QDataStream &, const QPointF &);
  binder.operators().put_to<QDataStream &, const QPointF &>();
  // QDataStream & operator>>(QDataStream &, QPointF &);
  binder.operators().read_from<QDataStream &, QPointF &>();
  // bool operator==(const QPointF &, const QPointF &);
  binder.operators().eq<const QPointF &, const QPointF &>();
  // bool operator!=(const QPointF &, const QPointF &);
  binder.operators().neq<const QPointF &, const QPointF &>();
  // const QPointF operator+(const QPointF &, const QPointF &);
  binder.operators().add<const QPointF, const QPointF &, const QPointF &>();
  // const QPointF operator-(const QPointF &, const QPointF &);
  binder.operators().sub<const QPointF, const QPointF &, const QPointF &>();
  // const QPointF operator*(const QPointF &, qreal);
  binder.operators().mul<const QPointF, const QPointF &, qreal>();
  // const QPointF operator*(qreal, const QPointF &);
  binder.operators().mul<const QPointF, qreal, const QPointF &>();
  // const QPointF operator+(const QPointF &);
  binder.operators().unary_plus<const QPointF, const QPointF &>();
  // const QPointF operator-(const QPointF &);
  binder.operators().unary_minus<const QPointF, const QPointF &>();
  // const QPointF operator/(const QPointF &, qreal);
  binder.operators().div<const QPointF, const QPointF &, qreal>();
  // QDebug operator<<(QDebug, const QPointF &);
  /// TODO: QDebug operator<<(QDebug, const QPointF &);
}

