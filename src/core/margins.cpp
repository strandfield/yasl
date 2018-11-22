// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/margins.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/margins.h"

#include <script/classbuilder.h>

static void register_margins_class(script::Namespace ns)
{
  using namespace script;

  Class margins = ns.newClass("Margins").setId(script::Type::QMargins).get();


  // QMargins();
  bind::default_constructor<QMargins>(margins).create();
  // QMargins(const QMargins &);
  bind::constructor<QMargins, const QMargins &>(margins).create();
  // ~QMargins();
  bind::destructor<QMargins>(margins).create();
  // QMargins(int, int, int, int);
  bind::constructor<QMargins, int, int, int, int>(margins).create();
  // bool isNull() const;
  bind::member_function<QMargins, bool, &QMargins::isNull>(margins, "isNull").create();
  // int left() const;
  bind::member_function<QMargins, int, &QMargins::left>(margins, "left").create();
  // int top() const;
  bind::member_function<QMargins, int, &QMargins::top>(margins, "top").create();
  // int right() const;
  bind::member_function<QMargins, int, &QMargins::right>(margins, "right").create();
  // int bottom() const;
  bind::member_function<QMargins, int, &QMargins::bottom>(margins, "bottom").create();
  // void setLeft(int);
  bind::void_member_function<QMargins, int, &QMargins::setLeft>(margins, "setLeft").create();
  // void setTop(int);
  bind::void_member_function<QMargins, int, &QMargins::setTop>(margins, "setTop").create();
  // void setRight(int);
  bind::void_member_function<QMargins, int, &QMargins::setRight>(margins, "setRight").create();
  // void setBottom(int);
  bind::void_member_function<QMargins, int, &QMargins::setBottom>(margins, "setBottom").create();
  // QMargins & operator+=(const QMargins &);
  bind::memop_add_assign<QMargins, const QMargins &>(margins);
  // QMargins & operator-=(const QMargins &);
  bind::memop_sub_assign<QMargins, const QMargins &>(margins);
  // QMargins & operator+=(int);
  bind::memop_add_assign<QMargins, int>(margins);
  // QMargins & operator-=(int);
  bind::memop_sub_assign<QMargins, int>(margins);
  // QMargins & operator*=(int);
  bind::memop_mul_assign<QMargins, int>(margins);
  // QMargins & operator/=(int);
  bind::memop_div_assign<QMargins, int>(margins);
  // QMargins & operator*=(qreal);
  bind::memop_mul_assign<QMargins, qreal>(margins);
  // QMargins & operator/=(qreal);
  bind::memop_div_assign<QMargins, qreal>(margins);
}


static void register_margins_f_class(script::Namespace ns)
{
  using namespace script;

  Class margins_f = ns.newClass("MarginsF").setId(script::Type::QMarginsF).get();


  // QMarginsF();
  bind::default_constructor<QMarginsF>(margins_f).create();
  // QMargins(const QMargins &);
  bind::constructor<QMarginsF, const QMargins &>(margins_f).create();
  // ~QMarginsF();
  bind::destructor<QMarginsF>(margins_f).create();
  // QMarginsF(qreal, qreal, qreal, qreal);
  bind::constructor<QMarginsF, qreal, qreal, qreal, qreal>(margins_f).create();
  // QMarginsF(const QMargins &);
  bind::constructor<QMarginsF, const QMargins &>(margins_f).create();
  // bool isNull() const;
  bind::member_function<QMarginsF, bool, &QMarginsF::isNull>(margins_f, "isNull").create();
  // qreal left() const;
  bind::member_function<QMarginsF, qreal, &QMarginsF::left>(margins_f, "left").create();
  // qreal top() const;
  bind::member_function<QMarginsF, qreal, &QMarginsF::top>(margins_f, "top").create();
  // qreal right() const;
  bind::member_function<QMarginsF, qreal, &QMarginsF::right>(margins_f, "right").create();
  // qreal bottom() const;
  bind::member_function<QMarginsF, qreal, &QMarginsF::bottom>(margins_f, "bottom").create();
  // void setLeft(qreal);
  bind::void_member_function<QMarginsF, qreal, &QMarginsF::setLeft>(margins_f, "setLeft").create();
  // void setTop(qreal);
  bind::void_member_function<QMarginsF, qreal, &QMarginsF::setTop>(margins_f, "setTop").create();
  // void setRight(qreal);
  bind::void_member_function<QMarginsF, qreal, &QMarginsF::setRight>(margins_f, "setRight").create();
  // void setBottom(qreal);
  bind::void_member_function<QMarginsF, qreal, &QMarginsF::setBottom>(margins_f, "setBottom").create();
  // QMarginsF & operator+=(const QMarginsF &);
  bind::memop_add_assign<QMarginsF, const QMarginsF &>(margins_f);
  // QMarginsF & operator-=(const QMarginsF &);
  bind::memop_sub_assign<QMarginsF, const QMarginsF &>(margins_f);
  // QMarginsF & operator+=(qreal);
  bind::memop_add_assign<QMarginsF, qreal>(margins_f);
  // QMarginsF & operator-=(qreal);
  bind::memop_sub_assign<QMarginsF, qreal>(margins_f);
  // QMarginsF & operator*=(qreal);
  bind::memop_mul_assign<QMarginsF, qreal>(margins_f);
  // QMarginsF & operator/=(qreal);
  bind::memop_div_assign<QMarginsF, qreal>(margins_f);
  // QMargins toMargins() const;
  bind::member_function<QMarginsF, QMargins, &QMarginsF::toMargins>(margins_f, "toMargins").create();
}


void register_margins_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_margins_class(ns);
  register_margins_f_class(ns);

  // QDataStream & operator<<(QDataStream &, const QMargins &);
  bind::op_put_to<QDataStream &, const QMargins &>(ns);
  // QDataStream & operator>>(QDataStream &, QMargins &);
  bind::op_read_from<QDataStream &, QMargins &>(ns);
  // bool operator==(const QMargins &, const QMargins &);
  bind::op_eq<const QMargins &, const QMargins &>(ns);
  // bool operator!=(const QMargins &, const QMargins &);
  bind::op_neq<const QMargins &, const QMargins &>(ns);
  // QMargins operator+(const QMargins &, const QMargins &);
  bind::op_add<QMargins, const QMargins &, const QMargins &>(ns);
  // QMargins operator-(const QMargins &, const QMargins &);
  bind::op_sub<QMargins, const QMargins &, const QMargins &>(ns);
  // QMargins operator+(const QMargins &, int);
  bind::op_add<QMargins, const QMargins &, int>(ns);
  // QMargins operator+(int, const QMargins &);
  bind::op_add<QMargins, int, const QMargins &>(ns);
  // QMargins operator-(const QMargins &, int);
  bind::op_sub<QMargins, const QMargins &, int>(ns);
  // QMargins operator*(const QMargins &, int);
  bind::op_mul<QMargins, const QMargins &, int>(ns);
  // QMargins operator*(int, const QMargins &);
  bind::op_mul<QMargins, int, const QMargins &>(ns);
  // QMargins operator*(const QMargins &, qreal);
  bind::op_mul<QMargins, const QMargins &, qreal>(ns);
  // QMargins operator*(qreal, const QMargins &);
  bind::op_mul<QMargins, qreal, const QMargins &>(ns);
  // QMargins operator/(const QMargins &, int);
  bind::op_div<QMargins, const QMargins &, int>(ns);
  // QMargins operator/(const QMargins &, qreal);
  bind::op_div<QMargins, const QMargins &, qreal>(ns);
  // QMargins operator+(const QMargins &);
  bind::op_unary_plus<QMargins, const QMargins &>(ns);
  // QMargins operator-(const QMargins &);
  bind::op_unary_minus<QMargins, const QMargins &>(ns);
  // QDebug operator<<(QDebug, const QMargins &);
  /// TODO: QDebug operator<<(QDebug, const QMargins &);
  // QDataStream & operator<<(QDataStream &, const QMarginsF &);
  bind::op_put_to<QDataStream &, const QMarginsF &>(ns);
  // QDataStream & operator>>(QDataStream &, QMarginsF &);
  bind::op_read_from<QDataStream &, QMarginsF &>(ns);
  // bool operator==(const QMarginsF &, const QMarginsF &);
  bind::op_eq<const QMarginsF &, const QMarginsF &>(ns);
  // bool operator!=(const QMarginsF &, const QMarginsF &);
  bind::op_neq<const QMarginsF &, const QMarginsF &>(ns);
  // QMarginsF operator+(const QMarginsF &, const QMarginsF &);
  bind::op_add<QMarginsF, const QMarginsF &, const QMarginsF &>(ns);
  // QMarginsF operator-(const QMarginsF &, const QMarginsF &);
  bind::op_sub<QMarginsF, const QMarginsF &, const QMarginsF &>(ns);
  // QMarginsF operator+(const QMarginsF &, qreal);
  bind::op_add<QMarginsF, const QMarginsF &, qreal>(ns);
  // QMarginsF operator+(qreal, const QMarginsF &);
  bind::op_add<QMarginsF, qreal, const QMarginsF &>(ns);
  // QMarginsF operator-(const QMarginsF &, qreal);
  bind::op_sub<QMarginsF, const QMarginsF &, qreal>(ns);
  // QMarginsF operator*(const QMarginsF &, qreal);
  bind::op_mul<QMarginsF, const QMarginsF &, qreal>(ns);
  // QMarginsF operator*(qreal, const QMarginsF &);
  bind::op_mul<QMarginsF, qreal, const QMarginsF &>(ns);
  // QMarginsF operator/(const QMarginsF &, qreal);
  bind::op_div<QMarginsF, const QMarginsF &, qreal>(ns);
  // QMarginsF operator+(const QMarginsF &);
  bind::op_unary_plus<QMarginsF, const QMarginsF &>(ns);
  // QMarginsF operator-(const QMarginsF &);
  bind::op_unary_minus<QMarginsF, const QMarginsF &>(ns);
  // QDebug operator<<(QDebug, const QMarginsF &);
  /// TODO: QDebug operator<<(QDebug, const QMarginsF &);
}

