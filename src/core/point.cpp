// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/point.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

static int qpoint_type_id = 0;

void register_qpoint(script::Namespace n)
{
  using namespace script;

  Class point = n.newClass(ClassBuilder::New("Point").setFinal());
  qpoint_type_id = point.id();

  binding::Class<QPoint> p{ point };

  // QPoint();
  p.ctors().add_default();
  // QPoint(const QPoint &);
  p.ctors().add_copy();
  // QPoint(int xpos, int ypos);
  p.ctors().add<int, int>();
  // ~QPoint();
  p.add_dtor();
  // bool isNull() const;
  p.add_fun<bool, &QPoint::isNull>("isNull");
  // int manhattanLength() const;
  p.add_fun<int, &QPoint::manhattanLength>("manhattanLength");
  // int & rx();
  // int & ry();
  // void setX(int x);
  p.add_void_fun<int, &QPoint::setX>("setX");
  // void setY(int y);
  p.add_void_fun<int, &QPoint::setY>("setY");
  // CGPoint toCGPoint() const;
  // int x() const;
  p.add_fun<int, &QPoint::x>("x");
  // int y() const;
  p.add_fun<int, &QPoint::y>("y");
  // QPoint & operator=(const QPoint &);
  p.operators().assign<const QPoint &>();
  // QPoint & operator*=(float factor);
  p.operators().mul_assign<float>();
  // QPoint & operator*=(double factor);
  p.operators().mul_assign<double>();
  // QPoint & operator*=(int factor);
  p.operators().mul_assign<int>();
  // QPoint & operator+=(const QPoint &point);
  p.operators().add_assign<const QPoint &>();
  // QPoint & operator-=(const QPoint &point);
  p.operators().sub_assign<const QPoint &>();
  // QPoint & operator/=(qreal divisor);
  p.operators().div_assign<qreal>();


  /* Public static members */

  // int dotProduct(const QPoint &p1, const QPoint &p2);
  //p.add_static<int, const QPoint &, const QPoint &, &QPoint::dotProduct>("dotProduct");
  point.Method("dotProduct", binding::function_wrapper_t<decltype(&QPoint::dotProduct), &QPoint::dotProduct>::wrap)
    .setStatic()
    .returns(Type::Int)
    .params(binding::make_type<const QPoint &>(), binding::make_type<const QPoint &>())
    .create();


  /* Non members */
  binding::Namespace ns{ n };
  // bool operator!=(const QPoint &p1, const QPoint &p2);
  ns.operators().neq<const QPoint &, const QPoint &>();
  // const QPoint operator*(const QPoint &point, float factor);
  ns.operators().mul<const QPoint, const QPoint &, float>();
  // const QPoint operator*(const QPoint &point, double factor);
  ns.operators().mul<const QPoint, const QPoint &, double>();
  // const QPoint operator*(const QPoint &point, int factor);
  ns.operators().mul<const QPoint, const QPoint &, int>();
  // const QPoint operator*(float factor, const QPoint &point);
  ns.operators().mul<const QPoint, float, const QPoint &>();
  // const QPoint operator*(double factor, const QPoint &point);
  ns.operators().mul<const QPoint, double, const QPoint &>();
  // const QPoint operator*(int factor, const QPoint &point);
  ns.operators().mul<const QPoint, int, const QPoint &>();
  // const QPoint operator+(const QPoint &p1, const QPoint &p2);
  ns.operators().add<const QPoint, const QPoint &, const QPoint &>();
  // const QPoint operator+(const QPoint &point);
  /// TODO : operator unary plus
  // const QPoint operator-(const QPoint &p1, const QPoint &p2);
  ns.operators().sub<const QPoint, const QPoint &, const QPoint &>();
  // const QPoint operator-(const QPoint &point);
  /// TODO : operator unary minus
  // const QPoint operator/(const QPoint &point, qreal divisor);
  ns.operators().div<const QPoint, const QPoint &, qreal>();
  // QDataStream & operator<<(QDataStream &stream, const QPoint &point);
  /// TODO : QDataStream output
  // bool operator==(const QPoint &p1, const QPoint &p2);
  ns.operators().eq<const QPoint &, const QPoint &>();
  // QDataStream & operator>>(QDataStream &stream, QPoint &point);
  /// TODO : QDataStream output
}

script::Type get_qpoint_type()
{
  return qpoint_type_id;
}
