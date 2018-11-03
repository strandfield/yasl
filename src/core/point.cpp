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
  binder.ctors().default_ctor().create();
  // QPoint(int, int);
  binder.ctors().ctor<int, int>().create();
  // ~QPoint();
  binder.add_dtor();
  // bool isNull() const;
  binder.fun<bool, &QPoint::isNull>("isNull").create();
  // int x() const;
  binder.fun<int, &QPoint::x>("x").create();
  // int y() const;
  binder.fun<int, &QPoint::y>("y").create();
  // void setX(int);
  binder.void_fun<int, &QPoint::setX>("setX").create();
  // void setY(int);
  binder.void_fun<int, &QPoint::setY>("setY").create();
  // int manhattanLength() const;
  binder.fun<int, &QPoint::manhattanLength>("manhattanLength").create();
  // int & rx();
  binder.ref_mem_getter<int &, &QPoint::rx>("rx").create();
  // int & ry();
  binder.ref_mem_getter<int &, &QPoint::ry>("ry").create();
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
  binder.static_fun<int, const QPoint &, const QPoint &, &QPoint::dotProduct>("dotProduct").create();
}


static void register_point_f_class(script::Namespace ns)
{
  using namespace script;

  Class point_f = ns.Class("PointF").setId(script::Type::QPointF).get();

  binding::Class<QPointF> binder{ point_f };

  // QPointF();
  binder.ctors().default_ctor().create();
  // QPointF(const QPoint &);
  binder.ctors().ctor<const QPoint &>().create();
  // QPointF(qreal, qreal);
  binder.ctors().ctor<qreal, qreal>().create();
  // ~QPointF();
  binder.add_dtor();
  // qreal manhattanLength() const;
  binder.fun<qreal, &QPointF::manhattanLength>("manhattanLength").create();
  // bool isNull() const;
  binder.fun<bool, &QPointF::isNull>("isNull").create();
  // qreal x() const;
  binder.fun<qreal, &QPointF::x>("x").create();
  // qreal y() const;
  binder.fun<qreal, &QPointF::y>("y").create();
  // void setX(qreal);
  binder.void_fun<qreal, &QPointF::setX>("setX").create();
  // void setY(qreal);
  binder.void_fun<qreal, &QPointF::setY>("setY").create();
  // qreal & rx();
  binder.ref_mem_getter<qreal &, &QPointF::rx>("rx").create();
  // qreal & ry();
  binder.ref_mem_getter<qreal &, &QPointF::ry>("ry").create();
  // QPointF & operator+=(const QPointF &);
  binder.operators().add_assign<const QPointF &>();
  // QPointF & operator-=(const QPointF &);
  binder.operators().sub_assign<const QPointF &>();
  // QPointF & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QPointF & operator/=(qreal);
  binder.operators().div_assign<qreal>();
  // static qreal dotProduct(const QPointF &, const QPointF &);
  binder.static_fun<qreal, const QPointF &, const QPointF &, &QPointF::dotProduct>("dotProduct").create();
  // QPoint toPoint() const;
  binder.fun<QPoint, &QPointF::toPoint>("toPoint").create();
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

