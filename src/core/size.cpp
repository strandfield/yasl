// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/size.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/size.h"

#include <script/classbuilder.h>

static void register_size_class(script::Namespace ns)
{
  using namespace script;

  Class size = ns.Class("Size").setId(script::Type::QSize).get();

  binding::Class<QSize> binder{ size };

  // QSize();
  binder.ctors().default_ctor().create();
  // QSize(const QSize &);
  binder.ctors().ctor<const QSize &>().create();
  // ~QSize();
  binder.add_dtor();
  // QSize(int, int);
  binder.ctors().ctor<int, int>().create();
  // bool isNull() const;
  binder.fun<bool, &QSize::isNull>("isNull").create();
  // bool isEmpty() const;
  binder.fun<bool, &QSize::isEmpty>("isEmpty").create();
  // bool isValid() const;
  binder.fun<bool, &QSize::isValid>("isValid").create();
  // int width() const;
  binder.fun<int, &QSize::width>("width").create();
  // int height() const;
  binder.fun<int, &QSize::height>("height").create();
  // void setWidth(int);
  binder.void_fun<int, &QSize::setWidth>("setWidth").create();
  // void setHeight(int);
  binder.void_fun<int, &QSize::setHeight>("setHeight").create();
  // void transpose();
  binder.void_fun<&QSize::transpose>("transpose").create();
  // QSize transposed() const;
  binder.fun<QSize, &QSize::transposed>("transposed").create();
  // void scale(int, int, Qt::AspectRatioMode);
  binder.void_fun<int, int, Qt::AspectRatioMode, &QSize::scale>("scale").create();
  // void scale(const QSize &, Qt::AspectRatioMode);
  binder.void_fun<const QSize &, Qt::AspectRatioMode, &QSize::scale>("scale").create();
  // QSize scaled(int, int, Qt::AspectRatioMode) const;
  binder.fun<QSize, int, int, Qt::AspectRatioMode, &QSize::scaled>("scaled").create();
  // QSize scaled(const QSize &, Qt::AspectRatioMode) const;
  binder.fun<QSize, const QSize &, Qt::AspectRatioMode, &QSize::scaled>("scaled").create();
  // QSize expandedTo(const QSize &) const;
  binder.fun<QSize, const QSize &, &QSize::expandedTo>("expandedTo").create();
  // QSize boundedTo(const QSize &) const;
  binder.fun<QSize, const QSize &, &QSize::boundedTo>("boundedTo").create();
  // int & rwidth();
  binder.ref_mem_getter<int &, &QSize::rwidth>("rwidth").create();
  // int & rheight();
  binder.ref_mem_getter<int &, &QSize::rheight>("rheight").create();
  // QSize & operator+=(const QSize &);
  binder.operators().add_assign<const QSize &>();
  // QSize & operator-=(const QSize &);
  binder.operators().sub_assign<const QSize &>();
  // QSize & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QSize & operator/=(qreal);
  binder.operators().div_assign<qreal>();
}


static void register_size_f_class(script::Namespace ns)
{
  using namespace script;

  Class size_f = ns.Class("SizeF").setId(script::Type::QSizeF).get();

  binding::Class<QSizeF> binder{ size_f };

  // QSizeF();
  binder.ctors().default_ctor().create();
  // QSizeF(const QSizeF &);
  binder.ctors().ctor<const QSizeF &>().create();
  // QSizeF(const QSize &);
  binder.ctors().ctor<const QSize &>().create();
  // QSizeF(qreal, qreal);
  binder.ctors().ctor<qreal, qreal>().create();
  // ~QSizeF();
  binder.add_dtor();
  // bool isNull() const;
  binder.fun<bool, &QSizeF::isNull>("isNull").create();
  // bool isEmpty() const;
  binder.fun<bool, &QSizeF::isEmpty>("isEmpty").create();
  // bool isValid() const;
  binder.fun<bool, &QSizeF::isValid>("isValid").create();
  // qreal width() const;
  binder.fun<qreal, &QSizeF::width>("width").create();
  // qreal height() const;
  binder.fun<qreal, &QSizeF::height>("height").create();
  // void setWidth(qreal);
  binder.void_fun<qreal, &QSizeF::setWidth>("setWidth").create();
  // void setHeight(qreal);
  binder.void_fun<qreal, &QSizeF::setHeight>("setHeight").create();
  // void transpose();
  binder.void_fun<&QSizeF::transpose>("transpose").create();
  // QSizeF transposed() const;
  binder.fun<QSizeF, &QSizeF::transposed>("transposed").create();
  // void scale(qreal, qreal, Qt::AspectRatioMode);
  binder.void_fun<qreal, qreal, Qt::AspectRatioMode, &QSizeF::scale>("scale").create();
  // void scale(const QSizeF &, Qt::AspectRatioMode);
  binder.void_fun<const QSizeF &, Qt::AspectRatioMode, &QSizeF::scale>("scale").create();
  // QSizeF scaled(qreal, qreal, Qt::AspectRatioMode) const;
  binder.fun<QSizeF, qreal, qreal, Qt::AspectRatioMode, &QSizeF::scaled>("scaled").create();
  // QSizeF scaled(const QSizeF &, Qt::AspectRatioMode) const;
  binder.fun<QSizeF, const QSizeF &, Qt::AspectRatioMode, &QSizeF::scaled>("scaled").create();
  // QSizeF expandedTo(const QSizeF &) const;
  binder.fun<QSizeF, const QSizeF &, &QSizeF::expandedTo>("expandedTo").create();
  // QSizeF boundedTo(const QSizeF &) const;
  binder.fun<QSizeF, const QSizeF &, &QSizeF::boundedTo>("boundedTo").create();
  // qreal & rwidth();
  binder.ref_mem_getter<qreal &, &QSizeF::rwidth>("rwidth").create();
  // qreal & rheight();
  binder.ref_mem_getter<qreal &, &QSizeF::rheight>("rheight").create();
  // QSizeF & operator+=(const QSizeF &);
  binder.operators().add_assign<const QSizeF &>();
  // QSizeF & operator-=(const QSizeF &);
  binder.operators().sub_assign<const QSizeF &>();
  // QSizeF & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QSizeF & operator/=(qreal);
  binder.operators().div_assign<qreal>();
  // QSize toSize() const;
  binder.fun<QSize, &QSizeF::toSize>("toSize").create();
}


void register_size_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_size_class(ns);
  register_size_f_class(ns);
  binding::Namespace binder{ ns };

  // QDataStream & operator<<(QDataStream &, const QSize &);
  binder.operators().put_to<QDataStream &, const QSize &>();
  // QDataStream & operator>>(QDataStream &, QSize &);
  binder.operators().read_from<QDataStream &, QSize &>();
  // bool operator==(const QSize &, const QSize &);
  binder.operators().eq<const QSize &, const QSize &>();
  // bool operator!=(const QSize &, const QSize &);
  binder.operators().neq<const QSize &, const QSize &>();
  // const QSize operator+(const QSize &, const QSize &);
  binder.operators().add<const QSize, const QSize &, const QSize &>();
  // const QSize operator-(const QSize &, const QSize &);
  binder.operators().sub<const QSize, const QSize &, const QSize &>();
  // const QSize operator*(const QSize &, qreal);
  binder.operators().mul<const QSize, const QSize &, qreal>();
  // const QSize operator*(qreal, const QSize &);
  binder.operators().mul<const QSize, qreal, const QSize &>();
  // const QSize operator/(const QSize &, qreal);
  binder.operators().div<const QSize, const QSize &, qreal>();
  // QDebug operator<<(QDebug, const QSize &);
  /// TODO: QDebug operator<<(QDebug, const QSize &);
  // QDataStream & operator<<(QDataStream &, const QSizeF &);
  binder.operators().put_to<QDataStream &, const QSizeF &>();
  // QDataStream & operator>>(QDataStream &, QSizeF &);
  binder.operators().read_from<QDataStream &, QSizeF &>();
  // bool operator==(const QSizeF &, const QSizeF &);
  binder.operators().eq<const QSizeF &, const QSizeF &>();
  // bool operator!=(const QSizeF &, const QSizeF &);
  binder.operators().neq<const QSizeF &, const QSizeF &>();
  // const QSizeF operator+(const QSizeF &, const QSizeF &);
  binder.operators().add<const QSizeF, const QSizeF &, const QSizeF &>();
  // const QSizeF operator-(const QSizeF &, const QSizeF &);
  binder.operators().sub<const QSizeF, const QSizeF &, const QSizeF &>();
  // const QSizeF operator*(const QSizeF &, qreal);
  binder.operators().mul<const QSizeF, const QSizeF &, qreal>();
  // const QSizeF operator*(qreal, const QSizeF &);
  binder.operators().mul<const QSizeF, qreal, const QSizeF &>();
  // const QSizeF operator/(const QSizeF &, qreal);
  binder.operators().div<const QSizeF, const QSizeF &, qreal>();
  // QDebug operator<<(QDebug, const QSizeF &);
  /// TODO: QDebug operator<<(QDebug, const QSizeF &);
}

