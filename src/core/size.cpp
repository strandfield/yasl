// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/size.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/size.h"

#include <script/classbuilder.h>

static void register_size_class(script::Namespace ns)
{
  using namespace script;

  Class size = ns.newClass("Size").setId(script::Type::QSize).get();


  // QSize();
  bind::default_constructor<QSize>(size).create();
  // QSize(const QSize &);
  bind::constructor<QSize, const QSize &>(size).create();
  // ~QSize();
  bind::destructor<QSize>(size).create();
  // QSize(int, int);
  bind::constructor<QSize, int, int>(size).create();
  // bool isNull() const;
  bind::member_function<QSize, bool, &QSize::isNull>(size, "isNull").create();
  // bool isEmpty() const;
  bind::member_function<QSize, bool, &QSize::isEmpty>(size, "isEmpty").create();
  // bool isValid() const;
  bind::member_function<QSize, bool, &QSize::isValid>(size, "isValid").create();
  // int width() const;
  bind::member_function<QSize, int, &QSize::width>(size, "width").create();
  // int height() const;
  bind::member_function<QSize, int, &QSize::height>(size, "height").create();
  // void setWidth(int);
  bind::void_member_function<QSize, int, &QSize::setWidth>(size, "setWidth").create();
  // void setHeight(int);
  bind::void_member_function<QSize, int, &QSize::setHeight>(size, "setHeight").create();
  // void transpose();
  bind::void_member_function<QSize, &QSize::transpose>(size, "transpose").create();
  // QSize transposed() const;
  bind::member_function<QSize, QSize, &QSize::transposed>(size, "transposed").create();
  // void scale(int, int, Qt::AspectRatioMode);
  bind::void_member_function<QSize, int, int, Qt::AspectRatioMode, &QSize::scale>(size, "scale").create();
  // void scale(const QSize &, Qt::AspectRatioMode);
  bind::void_member_function<QSize, const QSize &, Qt::AspectRatioMode, &QSize::scale>(size, "scale").create();
  // QSize scaled(int, int, Qt::AspectRatioMode) const;
  bind::member_function<QSize, QSize, int, int, Qt::AspectRatioMode, &QSize::scaled>(size, "scaled").create();
  // QSize scaled(const QSize &, Qt::AspectRatioMode) const;
  bind::member_function<QSize, QSize, const QSize &, Qt::AspectRatioMode, &QSize::scaled>(size, "scaled").create();
  // QSize expandedTo(const QSize &) const;
  bind::member_function<QSize, QSize, const QSize &, &QSize::expandedTo>(size, "expandedTo").create();
  // QSize boundedTo(const QSize &) const;
  bind::member_function<QSize, QSize, const QSize &, &QSize::boundedTo>(size, "boundedTo").create();
  // int & rwidth();
  bind::non_const_getter<QSize, int &, &QSize::rwidth>(size, "rwidth").create();
  // int & rheight();
  bind::non_const_getter<QSize, int &, &QSize::rheight>(size, "rheight").create();
  // QSize & operator+=(const QSize &);
  bind::memop_add_assign<QSize, const QSize &>(size);
  // QSize & operator-=(const QSize &);
  bind::memop_sub_assign<QSize, const QSize &>(size);
  // QSize & operator*=(qreal);
  bind::memop_mul_assign<QSize, qreal>(size);
  // QSize & operator/=(qreal);
  bind::memop_div_assign<QSize, qreal>(size);
}


static void register_size_f_class(script::Namespace ns)
{
  using namespace script;

  Class size_f = ns.newClass("SizeF").setId(script::Type::QSizeF).get();


  // QSizeF();
  bind::default_constructor<QSizeF>(size_f).create();
  // QSizeF(const QSizeF &);
  bind::constructor<QSizeF, const QSizeF &>(size_f).create();
  // QSizeF(const QSize &);
  bind::constructor<QSizeF, const QSize &>(size_f).create();
  // QSizeF(qreal, qreal);
  bind::constructor<QSizeF, qreal, qreal>(size_f).create();
  // ~QSizeF();
  bind::destructor<QSizeF>(size_f).create();
  // bool isNull() const;
  bind::member_function<QSizeF, bool, &QSizeF::isNull>(size_f, "isNull").create();
  // bool isEmpty() const;
  bind::member_function<QSizeF, bool, &QSizeF::isEmpty>(size_f, "isEmpty").create();
  // bool isValid() const;
  bind::member_function<QSizeF, bool, &QSizeF::isValid>(size_f, "isValid").create();
  // qreal width() const;
  bind::member_function<QSizeF, qreal, &QSizeF::width>(size_f, "width").create();
  // qreal height() const;
  bind::member_function<QSizeF, qreal, &QSizeF::height>(size_f, "height").create();
  // void setWidth(qreal);
  bind::void_member_function<QSizeF, qreal, &QSizeF::setWidth>(size_f, "setWidth").create();
  // void setHeight(qreal);
  bind::void_member_function<QSizeF, qreal, &QSizeF::setHeight>(size_f, "setHeight").create();
  // void transpose();
  bind::void_member_function<QSizeF, &QSizeF::transpose>(size_f, "transpose").create();
  // QSizeF transposed() const;
  bind::member_function<QSizeF, QSizeF, &QSizeF::transposed>(size_f, "transposed").create();
  // void scale(qreal, qreal, Qt::AspectRatioMode);
  bind::void_member_function<QSizeF, qreal, qreal, Qt::AspectRatioMode, &QSizeF::scale>(size_f, "scale").create();
  // void scale(const QSizeF &, Qt::AspectRatioMode);
  bind::void_member_function<QSizeF, const QSizeF &, Qt::AspectRatioMode, &QSizeF::scale>(size_f, "scale").create();
  // QSizeF scaled(qreal, qreal, Qt::AspectRatioMode) const;
  bind::member_function<QSizeF, QSizeF, qreal, qreal, Qt::AspectRatioMode, &QSizeF::scaled>(size_f, "scaled").create();
  // QSizeF scaled(const QSizeF &, Qt::AspectRatioMode) const;
  bind::member_function<QSizeF, QSizeF, const QSizeF &, Qt::AspectRatioMode, &QSizeF::scaled>(size_f, "scaled").create();
  // QSizeF expandedTo(const QSizeF &) const;
  bind::member_function<QSizeF, QSizeF, const QSizeF &, &QSizeF::expandedTo>(size_f, "expandedTo").create();
  // QSizeF boundedTo(const QSizeF &) const;
  bind::member_function<QSizeF, QSizeF, const QSizeF &, &QSizeF::boundedTo>(size_f, "boundedTo").create();
  // qreal & rwidth();
  bind::non_const_getter<QSizeF, qreal &, &QSizeF::rwidth>(size_f, "rwidth").create();
  // qreal & rheight();
  bind::non_const_getter<QSizeF, qreal &, &QSizeF::rheight>(size_f, "rheight").create();
  // QSizeF & operator+=(const QSizeF &);
  bind::memop_add_assign<QSizeF, const QSizeF &>(size_f);
  // QSizeF & operator-=(const QSizeF &);
  bind::memop_sub_assign<QSizeF, const QSizeF &>(size_f);
  // QSizeF & operator*=(qreal);
  bind::memop_mul_assign<QSizeF, qreal>(size_f);
  // QSizeF & operator/=(qreal);
  bind::memop_div_assign<QSizeF, qreal>(size_f);
  // QSize toSize() const;
  bind::member_function<QSizeF, QSize, &QSizeF::toSize>(size_f, "toSize").create();
}


void register_size_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_size_class(ns);
  register_size_f_class(ns);

  // QDataStream & operator<<(QDataStream &, const QSize &);
  bind::op_put_to<QDataStream &, const QSize &>(ns);
  // QDataStream & operator>>(QDataStream &, QSize &);
  bind::op_read_from<QDataStream &, QSize &>(ns);
  // bool operator==(const QSize &, const QSize &);
  bind::op_eq<const QSize &, const QSize &>(ns);
  // bool operator!=(const QSize &, const QSize &);
  bind::op_neq<const QSize &, const QSize &>(ns);
  // const QSize operator+(const QSize &, const QSize &);
  bind::op_add<const QSize, const QSize &, const QSize &>(ns);
  // const QSize operator-(const QSize &, const QSize &);
  bind::op_sub<const QSize, const QSize &, const QSize &>(ns);
  // const QSize operator*(const QSize &, qreal);
  bind::op_mul<const QSize, const QSize &, qreal>(ns);
  // const QSize operator*(qreal, const QSize &);
  bind::op_mul<const QSize, qreal, const QSize &>(ns);
  // const QSize operator/(const QSize &, qreal);
  bind::op_div<const QSize, const QSize &, qreal>(ns);
  // QDebug operator<<(QDebug, const QSize &);
  /// TODO: QDebug operator<<(QDebug, const QSize &);
  // QDataStream & operator<<(QDataStream &, const QSizeF &);
  bind::op_put_to<QDataStream &, const QSizeF &>(ns);
  // QDataStream & operator>>(QDataStream &, QSizeF &);
  bind::op_read_from<QDataStream &, QSizeF &>(ns);
  // bool operator==(const QSizeF &, const QSizeF &);
  bind::op_eq<const QSizeF &, const QSizeF &>(ns);
  // bool operator!=(const QSizeF &, const QSizeF &);
  bind::op_neq<const QSizeF &, const QSizeF &>(ns);
  // const QSizeF operator+(const QSizeF &, const QSizeF &);
  bind::op_add<const QSizeF, const QSizeF &, const QSizeF &>(ns);
  // const QSizeF operator-(const QSizeF &, const QSizeF &);
  bind::op_sub<const QSizeF, const QSizeF &, const QSizeF &>(ns);
  // const QSizeF operator*(const QSizeF &, qreal);
  bind::op_mul<const QSizeF, const QSizeF &, qreal>(ns);
  // const QSizeF operator*(qreal, const QSizeF &);
  bind::op_mul<const QSizeF, qreal, const QSizeF &>(ns);
  // const QSizeF operator/(const QSizeF &, qreal);
  bind::op_div<const QSizeF, const QSizeF &, qreal>(ns);
  // QDebug operator<<(QDebug, const QSizeF &);
  /// TODO: QDebug operator<<(QDebug, const QSizeF &);
}

