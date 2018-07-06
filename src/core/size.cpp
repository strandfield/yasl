// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/size.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/enums.h"

static int qsize_type_id = 0;

void register_qsize(script::Namespace n)
{
  using namespace script;

  Class size_class = n.newClass(ClassBuilder::New("Size").setFinal());
  qsize_type_id = size_class.id();

  binding::Class<QSize> s{ size_class };

  // QSize()
  s.ctors().add_default();
  // QSize(const QSize &)
  s.ctors().add_copy();
  // QSize(int width, int height)
  s.ctors().add<int, int>();
  // ~QSize()
  s.add_dtor();
  // QSize boundedTo(const QSize &otherSize) const
  s.add_fun<QSize, const QSize &, &QSize::boundedTo>("boundedTo");
  // QSize expandedTo(const QSize &otherSize) const
  s.add_fun<QSize, const QSize &, &QSize::expandedTo>("expandedTo");
  // int height() const
  s.add_fun<int, &QSize::height>("height");
  // bool isEmpty() const
  s.add_fun<bool, &QSize::isEmpty>("isEmpty");
  // bool isNull() const
  s.add_fun<bool, &QSize::isNull>("isNull");
  // bool isValid() const
  s.add_fun<bool, &QSize::isValid>("isValid");
  // int & rheight()
  // int & rwidth()
  // void scale(int width, int height, Qt::AspectRatioMode mode)
  s.add_void_fun<int, int, Qt::AspectRatioMode, &QSize::scale>("scale");
  // void scale(const QSize &size, Qt::AspectRatioMode mode)
  s.add_void_fun<const QSize &, Qt::AspectRatioMode, &QSize::scale>("scale");
  // QSize scaled(int width, int height, Qt::AspectRatioMode mode) const
  s.add_fun<QSize, int, int, Qt::AspectRatioMode, &QSize::scaled>("scaled");
  // QSize scaled(const QSize &s, Qt::AspectRatioMode mode) const
  s.add_fun<QSize, const QSize &, Qt::AspectRatioMode, &QSize::scaled>("scaled");
  // void setHeight(int height)
  s.add_void_fun<int, &QSize::setHeight>("setHeight");
  // void setWidth(int width)
  s.add_void_fun<int, &QSize::setWidth>("setWidth");
  // CGSize toCGSize() const
  // void transpose()
  s.add_void_fun<&QSize::transpose>("transpose");
  // QSize transposed() const
  s.add_fun<QSize, &QSize::transposed>("transposed");
  // int width() const
  s.add_fun<int, &QSize::width>("width");
  // QSize & operator=(const QSize & other);
  s.operators().add_assign<const QSize &>();
  // QSize & operator*=(qreal factor)
  s.operators().mul_assign<qreal>();
  // QSize & operator+=(const QSize &size)
  s.operators().add_assign<const QSize &>();
  // QSize & operator-=(const QSize &size)
  s.operators().sub_assign<const QSize &>();
  // QSize & operator/=(qreal divisor)
  s.operators().div_assign<qreal>();

  /* Non members */
  binding::Namespace ns{ n };
  // bool operator!=(const QSize &s1, const QSize &s2)
  ns.operators().eq<const QSize &, const QSize &>();
  // const QSize operator*(const QSize &size, qreal factor)
  ns.operators().mul<const QSize, const QSize &, qreal>();
  // const QSize operator*(qreal factor, const QSize &size)
  ns.operators().mul<const QSize, qreal, const QSize &>();
  // const QSize operator+(const QSize &s1, const QSize &s2)
  ns.operators().add<const QSize, const QSize &, const QSize &>();
  // const QSize operator-(const QSize &s1, const QSize &s2)
  ns.operators().sub<const QSize, const QSize &, const QSize &>();
  // const QSize operator/(const QSize &size, qreal divisor)
  ns.operators().div<const QSize, const QSize &, qreal>();
  // QDataStream & operator<<(QDataStream &stream, const QSize &size)
  // bool operator==(const QSize &s1, const QSize &s2)
  ns.operators().neq<const QSize &, const QSize &>();
  // QDataStream & operator>>(QDataStream &stream, QSize &size)
}

script::Type get_qsize_type()
{
  return qsize_type_id;
}
