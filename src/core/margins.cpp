// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/margins.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/margins.h"

#include <script/classbuilder.h>

static void register_margins_class(script::Namespace ns)
{
  using namespace script;

  Class margins = ns.Class("Margins").setId(script::Type::QMargins).get();

  binding::Class<QMargins> binder{ margins };

  // QMargins();
  binder.ctors().add_default();
  // QMargins(const QMargins &);
  binder.ctors().add<const QMargins &>();
  // ~QMargins();
  binder.add_dtor();
  // QMargins(int, int, int, int);
  binder.ctors().add<int, int, int, int>();
  // bool isNull() const;
  binder.add_fun<bool, &QMargins::isNull>("isNull");
  // int left() const;
  binder.add_fun<int, &QMargins::left>("left");
  // int top() const;
  binder.add_fun<int, &QMargins::top>("top");
  // int right() const;
  binder.add_fun<int, &QMargins::right>("right");
  // int bottom() const;
  binder.add_fun<int, &QMargins::bottom>("bottom");
  // void setLeft(int);
  binder.add_void_fun<int, &QMargins::setLeft>("setLeft");
  // void setTop(int);
  binder.add_void_fun<int, &QMargins::setTop>("setTop");
  // void setRight(int);
  binder.add_void_fun<int, &QMargins::setRight>("setRight");
  // void setBottom(int);
  binder.add_void_fun<int, &QMargins::setBottom>("setBottom");
  // QMargins & operator+=(const QMargins &);
  binder.operators().add_assign<const QMargins &>();
  // QMargins & operator-=(const QMargins &);
  binder.operators().sub_assign<const QMargins &>();
  // QMargins & operator+=(int);
  binder.operators().add_assign<int>();
  // QMargins & operator-=(int);
  binder.operators().sub_assign<int>();
  // QMargins & operator*=(int);
  binder.operators().mul_assign<int>();
  // QMargins & operator/=(int);
  binder.operators().div_assign<int>();
  // QMargins & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QMargins & operator/=(qreal);
  binder.operators().div_assign<qreal>();
}


static void register_margins_f_class(script::Namespace ns)
{
  using namespace script;

  Class margins_f = ns.Class("MarginsF").setId(script::Type::QMarginsF).get();

  binding::Class<QMarginsF> binder{ margins_f };

  // QMarginsF();
  binder.ctors().add_default();
  // QMargins(const QMargins &);
  binder.ctors().add<const QMargins &>();
  // ~QMarginsF();
  binder.add_dtor();
  // QMarginsF(qreal, qreal, qreal, qreal);
  binder.ctors().add<qreal, qreal, qreal, qreal>();
  // QMarginsF(const QMargins &);
  binder.ctors().add<const QMargins &>();
  // bool isNull() const;
  binder.add_fun<bool, &QMarginsF::isNull>("isNull");
  // qreal left() const;
  binder.add_fun<qreal, &QMarginsF::left>("left");
  // qreal top() const;
  binder.add_fun<qreal, &QMarginsF::top>("top");
  // qreal right() const;
  binder.add_fun<qreal, &QMarginsF::right>("right");
  // qreal bottom() const;
  binder.add_fun<qreal, &QMarginsF::bottom>("bottom");
  // void setLeft(qreal);
  binder.add_void_fun<qreal, &QMarginsF::setLeft>("setLeft");
  // void setTop(qreal);
  binder.add_void_fun<qreal, &QMarginsF::setTop>("setTop");
  // void setRight(qreal);
  binder.add_void_fun<qreal, &QMarginsF::setRight>("setRight");
  // void setBottom(qreal);
  binder.add_void_fun<qreal, &QMarginsF::setBottom>("setBottom");
  // QMarginsF & operator+=(const QMarginsF &);
  binder.operators().add_assign<const QMarginsF &>();
  // QMarginsF & operator-=(const QMarginsF &);
  binder.operators().sub_assign<const QMarginsF &>();
  // QMarginsF & operator+=(qreal);
  binder.operators().add_assign<qreal>();
  // QMarginsF & operator-=(qreal);
  binder.operators().sub_assign<qreal>();
  // QMarginsF & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QMarginsF & operator/=(qreal);
  binder.operators().div_assign<qreal>();
  // QMargins toMargins() const;
  binder.add_fun<QMargins, &QMarginsF::toMargins>("toMargins");
}


void register_margins_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_margins_class(ns);
  register_margins_f_class(ns);
  binding::Namespace binder{ ns };

  // QDataStream & operator<<(QDataStream &, const QMargins &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QMargins &);
  // QDataStream & operator>>(QDataStream &, QMargins &);
  /// TODO: QDataStream & operator>>(QDataStream &, QMargins &);
  // bool operator==(const QMargins &, const QMargins &);
  binder.operators().eq<const QMargins &, const QMargins &>();
  // bool operator!=(const QMargins &, const QMargins &);
  binder.operators().neq<const QMargins &, const QMargins &>();
  // QMargins operator+(const QMargins &, const QMargins &);
  binder.operators().add<QMargins, const QMargins &, const QMargins &>();
  // QMargins operator-(const QMargins &, const QMargins &);
  binder.operators().sub<QMargins, const QMargins &, const QMargins &>();
  // QMargins operator+(const QMargins &, int);
  binder.operators().add<QMargins, const QMargins &, int>();
  // QMargins operator+(int, const QMargins &);
  binder.operators().add<QMargins, int, const QMargins &>();
  // QMargins operator-(const QMargins &, int);
  binder.operators().sub<QMargins, const QMargins &, int>();
  // QMargins operator*(const QMargins &, int);
  binder.operators().mul<QMargins, const QMargins &, int>();
  // QMargins operator*(int, const QMargins &);
  binder.operators().mul<QMargins, int, const QMargins &>();
  // QMargins operator*(const QMargins &, qreal);
  binder.operators().mul<QMargins, const QMargins &, qreal>();
  // QMargins operator*(qreal, const QMargins &);
  binder.operators().mul<QMargins, qreal, const QMargins &>();
  // QMargins operator/(const QMargins &, int);
  binder.operators().div<QMargins, const QMargins &, int>();
  // QMargins operator/(const QMargins &, qreal);
  binder.operators().div<QMargins, const QMargins &, qreal>();
  // QMargins operator+(const QMargins &);
  binder.operators().unary_plus<QMargins, const QMargins &>();
  // QMargins operator-(const QMargins &);
  binder.operators().unary_minus<QMargins, const QMargins &>();
  // QDebug operator<<(QDebug, const QMargins &);
  /// TODO: QDebug operator<<(QDebug, const QMargins &);
  // QDataStream & operator<<(QDataStream &, const QMarginsF &);
  /// TODO: QDataStream & operator<<(QDataStream &, const QMarginsF &);
  // QDataStream & operator>>(QDataStream &, QMarginsF &);
  /// TODO: QDataStream & operator>>(QDataStream &, QMarginsF &);
  // bool operator==(const QMarginsF &, const QMarginsF &);
  binder.operators().eq<const QMarginsF &, const QMarginsF &>();
  // bool operator!=(const QMarginsF &, const QMarginsF &);
  binder.operators().neq<const QMarginsF &, const QMarginsF &>();
  // QMarginsF operator+(const QMarginsF &, const QMarginsF &);
  binder.operators().add<QMarginsF, const QMarginsF &, const QMarginsF &>();
  // QMarginsF operator-(const QMarginsF &, const QMarginsF &);
  binder.operators().sub<QMarginsF, const QMarginsF &, const QMarginsF &>();
  // QMarginsF operator+(const QMarginsF &, qreal);
  binder.operators().add<QMarginsF, const QMarginsF &, qreal>();
  // QMarginsF operator+(qreal, const QMarginsF &);
  binder.operators().add<QMarginsF, qreal, const QMarginsF &>();
  // QMarginsF operator-(const QMarginsF &, qreal);
  binder.operators().sub<QMarginsF, const QMarginsF &, qreal>();
  // QMarginsF operator*(const QMarginsF &, qreal);
  binder.operators().mul<QMarginsF, const QMarginsF &, qreal>();
  // QMarginsF operator*(qreal, const QMarginsF &);
  binder.operators().mul<QMarginsF, qreal, const QMarginsF &>();
  // QMarginsF operator/(const QMarginsF &, qreal);
  binder.operators().div<QMarginsF, const QMarginsF &, qreal>();
  // QMarginsF operator+(const QMarginsF &);
  binder.operators().unary_plus<QMarginsF, const QMarginsF &>();
  // QMarginsF operator-(const QMarginsF &);
  binder.operators().unary_minus<QMarginsF, const QMarginsF &>();
  // QDebug operator<<(QDebug, const QMarginsF &);
  /// TODO: QDebug operator<<(QDebug, const QMarginsF &);
}

