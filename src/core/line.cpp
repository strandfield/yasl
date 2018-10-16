// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/line.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/line.h"
#include "yasl/core/point.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_line_class(script::Namespace ns)
{
  using namespace script;

  Class line = ns.Class("Line").setId(script::Type::QLine).get();

  binding::Class<QLine> binder{ line };

  // QLine();
  binder.ctors().add_default();
  // QLine(const QLine &);
  binder.ctors().ctor<const QLine &>().create();
  // ~QLine();
  binder.add_dtor();
  // QLine(const QPoint &, const QPoint &);
  binder.ctors().ctor<const QPoint &, const QPoint &>().create();
  // QLine(int, int, int, int);
  binder.ctors().ctor<int, int, int, int>().create();
  // bool isNull() const;
  binder.fun<bool, &QLine::isNull>("isNull").create();
  // QPoint p1() const;
  binder.fun<QPoint, &QLine::p1>("p1").create();
  // QPoint p2() const;
  binder.fun<QPoint, &QLine::p2>("p2").create();
  // int x1() const;
  binder.fun<int, &QLine::x1>("x1").create();
  // int y1() const;
  binder.fun<int, &QLine::y1>("y1").create();
  // int x2() const;
  binder.fun<int, &QLine::x2>("x2").create();
  // int y2() const;
  binder.fun<int, &QLine::y2>("y2").create();
  // int dx() const;
  binder.fun<int, &QLine::dx>("dx").create();
  // int dy() const;
  binder.fun<int, &QLine::dy>("dy").create();
  // void translate(const QPoint &);
  binder.void_fun<const QPoint &, &QLine::translate>("translate").create();
  // void translate(int, int);
  binder.void_fun<int, int, &QLine::translate>("translate").create();
  // QLine translated(const QPoint &) const;
  binder.fun<QLine, const QPoint &, &QLine::translated>("translated").create();
  // QLine translated(int, int) const;
  binder.fun<QLine, int, int, &QLine::translated>("translated").create();
  // QPoint center() const;
  binder.fun<QPoint, &QLine::center>("center").create();
  // void setP1(const QPoint &);
  binder.void_fun<const QPoint &, &QLine::setP1>("setP1").create();
  // void setP2(const QPoint &);
  binder.void_fun<const QPoint &, &QLine::setP2>("setP2").create();
  // void setPoints(const QPoint &, const QPoint &);
  binder.void_fun<const QPoint &, const QPoint &, &QLine::setPoints>("setPoints").create();
  // void setLine(int, int, int, int);
  binder.void_fun<int, int, int, int, &QLine::setLine>("setLine").create();
  // QLine & operator=(const QLine &);
  binder.operators().assign<const QLine &>();
  // bool operator==(const QLine &) const;
  binder.operators().eq<const QLine &>();
  // bool operator!=(const QLine &) const;
  binder.operators().neq<const QLine &>();
}


static void register_line_f_intersect_type_enum(script::Class line_f)
{
  using namespace script;

  Enum intersect_type = line_f.Enum("IntersectType").setId(script::Type::QLineFIntersectType).get();

  intersect_type.addValue("NoIntersection", QLineF::NoIntersection);
  intersect_type.addValue("BoundedIntersection", QLineF::BoundedIntersection);
  intersect_type.addValue("UnboundedIntersection", QLineF::UnboundedIntersection);
}


static void register_line_f_class(script::Namespace ns)
{
  using namespace script;

  Class line_f = ns.Class("LineF").setId(script::Type::QLineF).get();

  register_line_f_intersect_type_enum(line_f);
  binding::Class<QLineF> binder{ line_f };

  // QLineF();
  binder.ctors().add_default();
  // QLineF(const QLineF &);
  binder.ctors().ctor<const QLineF &>().create();
  // ~QLineF();
  binder.add_dtor();
  // QLineF(const QPointF &, const QPointF &);
  binder.ctors().ctor<const QPointF &, const QPointF &>().create();
  // QLineF(qreal, qreal, qreal, qreal);
  binder.ctors().ctor<qreal, qreal, qreal, qreal>().create();
  // QLineF(const QLine &);
  binder.ctors().ctor<const QLine &>().create();
  // static QLineF fromPolar(qreal, qreal);
  binder.static_fun<QLineF, qreal, qreal, &QLineF::fromPolar>("fromPolar").create();
  // bool isNull() const;
  binder.fun<bool, &QLineF::isNull>("isNull").create();
  // QPointF p1() const;
  binder.fun<QPointF, &QLineF::p1>("p1").create();
  // QPointF p2() const;
  binder.fun<QPointF, &QLineF::p2>("p2").create();
  // qreal x1() const;
  binder.fun<qreal, &QLineF::x1>("x1").create();
  // qreal y1() const;
  binder.fun<qreal, &QLineF::y1>("y1").create();
  // qreal x2() const;
  binder.fun<qreal, &QLineF::x2>("x2").create();
  // qreal y2() const;
  binder.fun<qreal, &QLineF::y2>("y2").create();
  // qreal dx() const;
  binder.fun<qreal, &QLineF::dx>("dx").create();
  // qreal dy() const;
  binder.fun<qreal, &QLineF::dy>("dy").create();
  // qreal length() const;
  binder.fun<qreal, &QLineF::length>("length").create();
  // void setLength(qreal);
  binder.void_fun<qreal, &QLineF::setLength>("setLength").create();
  // qreal angle() const;
  binder.fun<qreal, &QLineF::angle>("angle").create();
  // void setAngle(qreal);
  binder.void_fun<qreal, &QLineF::setAngle>("setAngle").create();
  // qreal angleTo(const QLineF &) const;
  binder.fun<qreal, const QLineF &, &QLineF::angleTo>("angleTo").create();
  // QLineF unitVector() const;
  binder.fun<QLineF, &QLineF::unitVector>("unitVector").create();
  // QLineF normalVector() const;
  binder.fun<QLineF, &QLineF::normalVector>("normalVector").create();
  // QLineF::IntersectType intersect(const QLineF &, QPointF *) const;
  /// TODO: QLineF::IntersectType intersect(const QLineF &, QPointF *) const;
  // qreal angle(const QLineF &) const;
  binder.fun<qreal, const QLineF &, &QLineF::angle>("angle").create();
  // QPointF pointAt(qreal) const;
  binder.fun<QPointF, qreal, &QLineF::pointAt>("pointAt").create();
  // void translate(const QPointF &);
  binder.void_fun<const QPointF &, &QLineF::translate>("translate").create();
  // void translate(qreal, qreal);
  binder.void_fun<qreal, qreal, &QLineF::translate>("translate").create();
  // QLineF translated(const QPointF &) const;
  binder.fun<QLineF, const QPointF &, &QLineF::translated>("translated").create();
  // QLineF translated(qreal, qreal) const;
  binder.fun<QLineF, qreal, qreal, &QLineF::translated>("translated").create();
  // QPointF center() const;
  binder.fun<QPointF, &QLineF::center>("center").create();
  // void setP1(const QPointF &);
  binder.void_fun<const QPointF &, &QLineF::setP1>("setP1").create();
  // void setP2(const QPointF &);
  binder.void_fun<const QPointF &, &QLineF::setP2>("setP2").create();
  // void setPoints(const QPointF &, const QPointF &);
  binder.void_fun<const QPointF &, const QPointF &, &QLineF::setPoints>("setPoints").create();
  // void setLine(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QLineF::setLine>("setLine").create();
  // QLineF & operator=(const QLineF &);
  binder.operators().assign<const QLineF &>();
  // bool operator==(const QLineF &) const;
  binder.operators().eq<const QLineF &>();
  // bool operator!=(const QLineF &) const;
  binder.operators().neq<const QLineF &>();
  // QLine toLine() const;
  binder.fun<QLine, &QLineF::toLine>("toLine").create();
}


void register_line_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_line_class(ns);
  register_line_f_class(ns);
  binding::Namespace binder{ ns };

  // QDebug operator<<(QDebug, const QLine &);
  /// TODO: QDebug operator<<(QDebug, const QLine &);
  // QDataStream & operator<<(QDataStream &, const QLine &);
  binder.operators().put_to<QDataStream &, const QLine &>();
  // QDataStream & operator>>(QDataStream &, QLine &);
  binder.operators().read_from<QDataStream &, QLine &>();
  // QDebug operator<<(QDebug, const QLineF &);
  /// TODO: QDebug operator<<(QDebug, const QLineF &);
  // QDataStream & operator<<(QDataStream &, const QLineF &);
  binder.operators().put_to<QDataStream &, const QLineF &>();
  // QDataStream & operator>>(QDataStream &, QLineF &);
  binder.operators().read_from<QDataStream &, QLineF &>();
}

