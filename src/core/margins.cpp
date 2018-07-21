// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/margins.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include <script/classbuilder.h>

void register_qmargins(script::Namespace n)
{
  using namespace script;

  Class margins = n.Class("Margins").setId(Type::QMargins).setFinal().get();

  binding::Class<QMargins> m{ margins };

  // QMargins()
  m.ctors().add_default();
  m.ctors().add_copy();
  // QMargins(int, int, int, int)
  m.ctors().add<int, int, int, int>();
  // ~QMargins()
  m.add_dtor();
  // int bottom() const
  m.add_fun<int, &QMargins::bottom>("bottom");
  // bool isNull() const
  m.add_fun<bool, &QMargins::isNull>("isNull");
  // int left() const
  m.add_fun<int, &QMargins::left>("left");
  // int right() const
  m.add_fun<int, &QMargins::right>("right");
  // void setBottom(int bottom)
  m.add_void_fun<int, &QMargins::setBottom>("setBottom");
  // void setLeft(int left)
  m.add_void_fun<int, &QMargins::setLeft>("setLeft");
  // void setRight(int right)
  m.add_void_fun<int, &QMargins::setRight>("setRight");
  // void setTop(int Top)
  m.add_void_fun<int, &QMargins::setTop>("setTop");
  // int top() const
  m.add_fun<int, &QMargins::top>("top");

  // QMargins & operator=(const QMargins & other);
  m.operators().assign<const QMargins &>();
  // QMargins & operator*=(int factor)
  m.operators().mul_assign<int>();
  // QMargins & operator*=(qreal factor)
  m.operators().mul_assign<qreal>();
  // QMargins & operator+=(const QMargins &margins)
  m.operators().add_assign<const QMargins &>();
  // QMargins & operator+=(int addend)
  m.operators().add_assign<int>();
  // QMargins & operator-=(const QMargins &margins)
  m.operators().sub_assign<const QMargins &>();
  // QMargins & operator-=(int subtrahend)
  m.operators().sub_assign<int>();
  // QMargins & operator/=(int divisor)
  m.operators().div_assign<int>();
  // QMargins & operator/=(qreal divisor)
  m.operators().div_assign<qreal>();


  /* Non members */
  binding::Namespace ns{ n };
  // bool operator!=(const QMargins &m1, const QMargins &m2)
  ns.operators().neq<const QMargins &, const QMargins &>();
  // QMargins operator*(const QMargins &margins, int factor)
  ns.operators().mul<QMargins, const QMargins &, int>();
  // QMargins operator*(int factor, const QMargins &margins)
  ns.operators().mul<QMargins, int, const QMargins &>();
  // QMargins operator*(const QMargins &margins, qreal factor)
  ns.operators().mul<QMargins, const QMargins &, qreal>();
  // QMargins operator*(qreal factor, const QMargins &margins)
  ns.operators().mul<QMargins, qreal, const QMargins &>();
  // QMargins operator+(const QMargins &m1, const QMargins &m2)
  ns.operators().add<QMargins, const QMargins &, const QMargins &>();
  // QMargins operator+(const QMargins &lhs, int rhs)
  ns.operators().add<QMargins, const QMargins &, int>();
  // QMargins operator+(int lhs, const QMargins &rhs)
  ns.operators().add<QMargins, int, const QMargins &>();
  // QMargins operator+(const QMargins &margins)
  /// TODO !!!
  // QMargins operator-(const QMargins &m1, const QMargins &m2)
  ns.operators().sub<QMargins, const QMargins &, const QMargins &>();
  // QMargins operator-(const QMargins &lhs, int rhs)
  ns.operators().sub<QMargins, const QMargins &, int>();
  // QMargins operator-(const QMargins &margins)
  /// TODO !!!
  // QMargins operator/(const QMargins &margins, int divisor)
  ns.operators().div<QMargins, const QMargins &, int>();
  // QMargins operator/(const QMargins &margins, qreal divisor)
  ns.operators().div<QMargins, const QMargins &, qreal>();
  // QDataStream & operator<<(QDataStream &stream, const QMargins &m)
  /// TODO !!!
  // bool operator==(const QMargins &m1, const QMargins &m2)
  ns.operators().eq<const QMargins &, const QMargins &>();
  // QDataStream & operator>>(QDataStream &stream, QMargins &m)
  /// TODO !!!
}
