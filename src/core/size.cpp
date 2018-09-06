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
  binder.ctors().add_default();
  // QSize(const QSize &);
  binder.ctors().add<const QSize &>();
  // ~QSize();
  binder.add_dtor();
  // QSize(int, int);
  binder.ctors().add<int, int>();
  // bool isNull() const;
  binder.add_fun<bool, &QSize::isNull>("isNull");
  // bool isEmpty() const;
  binder.add_fun<bool, &QSize::isEmpty>("isEmpty");
  // bool isValid() const;
  binder.add_fun<bool, &QSize::isValid>("isValid");
  // int width() const;
  binder.add_fun<int, &QSize::width>("width");
  // int height() const;
  binder.add_fun<int, &QSize::height>("height");
  // void setWidth(int);
  binder.add_void_fun<int, &QSize::setWidth>("setWidth");
  // void setHeight(int);
  binder.add_void_fun<int, &QSize::setHeight>("setHeight");
  // void transpose();
  binder.add_void_fun<&QSize::transpose>("transpose");
  // QSize transposed() const;
  binder.add_fun<QSize, &QSize::transposed>("transposed");
  // void scale(int, int, Qt::AspectRatioMode);
  binder.add_void_fun<int, int, Qt::AspectRatioMode, &QSize::scale>("scale");
  // void scale(const QSize &, Qt::AspectRatioMode);
  binder.add_void_fun<const QSize &, Qt::AspectRatioMode, &QSize::scale>("scale");
  // QSize scaled(int, int, Qt::AspectRatioMode) const;
  binder.add_fun<QSize, int, int, Qt::AspectRatioMode, &QSize::scaled>("scaled");
  // QSize scaled(const QSize &, Qt::AspectRatioMode) const;
  binder.add_fun<QSize, const QSize &, Qt::AspectRatioMode, &QSize::scaled>("scaled");
  // QSize expandedTo(const QSize &) const;
  binder.add_fun<QSize, const QSize &, &QSize::expandedTo>("expandedTo");
  // QSize boundedTo(const QSize &) const;
  binder.add_fun<QSize, const QSize &, &QSize::boundedTo>("boundedTo");
  // int & rwidth();
  binder.add_ref_mem<int &, &QSize::rwidth>("rwidth");
  // int & rheight();
  binder.add_ref_mem<int &, &QSize::rheight>("rheight");
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
  binder.ctors().add_default();
  // QSizeF(const QSizeF &);
  binder.ctors().add<const QSizeF &>();
  // QSizeF(const QSize &);
  binder.ctors().add<const QSize &>();
  // QSizeF(qreal, qreal);
  binder.ctors().add<qreal, qreal>();
  // ~QSizeF();
  binder.add_dtor();
  // bool isNull() const;
  binder.add_fun<bool, &QSizeF::isNull>("isNull");
  // bool isEmpty() const;
  binder.add_fun<bool, &QSizeF::isEmpty>("isEmpty");
  // bool isValid() const;
  binder.add_fun<bool, &QSizeF::isValid>("isValid");
  // qreal width() const;
  binder.add_fun<qreal, &QSizeF::width>("width");
  // qreal height() const;
  binder.add_fun<qreal, &QSizeF::height>("height");
  // void setWidth(qreal);
  binder.add_void_fun<qreal, &QSizeF::setWidth>("setWidth");
  // void setHeight(qreal);
  binder.add_void_fun<qreal, &QSizeF::setHeight>("setHeight");
  // void transpose();
  binder.add_void_fun<&QSizeF::transpose>("transpose");
  // QSizeF transposed() const;
  binder.add_fun<QSizeF, &QSizeF::transposed>("transposed");
  // void scale(qreal, qreal, Qt::AspectRatioMode);
  binder.add_void_fun<qreal, qreal, Qt::AspectRatioMode, &QSizeF::scale>("scale");
  // void scale(const QSizeF &, Qt::AspectRatioMode);
  binder.add_void_fun<const QSizeF &, Qt::AspectRatioMode, &QSizeF::scale>("scale");
  // QSizeF scaled(qreal, qreal, Qt::AspectRatioMode) const;
  binder.add_fun<QSizeF, qreal, qreal, Qt::AspectRatioMode, &QSizeF::scaled>("scaled");
  // QSizeF scaled(const QSizeF &, Qt::AspectRatioMode) const;
  binder.add_fun<QSizeF, const QSizeF &, Qt::AspectRatioMode, &QSizeF::scaled>("scaled");
  // QSizeF expandedTo(const QSizeF &) const;
  binder.add_fun<QSizeF, const QSizeF &, &QSizeF::expandedTo>("expandedTo");
  // QSizeF boundedTo(const QSizeF &) const;
  binder.add_fun<QSizeF, const QSizeF &, &QSizeF::boundedTo>("boundedTo");
  // qreal & rwidth();
  binder.add_ref_mem<qreal &, &QSizeF::rwidth>("rwidth");
  // qreal & rheight();
  binder.add_ref_mem<qreal &, &QSizeF::rheight>("rheight");
  // QSizeF & operator+=(const QSizeF &);
  binder.operators().add_assign<const QSizeF &>();
  // QSizeF & operator-=(const QSizeF &);
  binder.operators().sub_assign<const QSizeF &>();
  // QSizeF & operator*=(qreal);
  binder.operators().mul_assign<qreal>();
  // QSizeF & operator/=(qreal);
  binder.operators().div_assign<qreal>();
  // QSize toSize() const;
  binder.add_fun<QSize, &QSizeF::toSize>("toSize");
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

