// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/line.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/enums.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/line.h"
#include "yasl/core/point.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_line_class(script::Namespace ns)
{
  using namespace script;

  Class line = ns.newClass("Line").setId(script::Type::QLine).get();


  // QLine();
  bind::default_constructor<QLine>(line).create();
  // QLine(const QLine &);
  bind::constructor<QLine, const QLine &>(line).create();
  // ~QLine();
  bind::destructor<QLine>(line).create();
  // QLine(const QPoint &, const QPoint &);
  bind::constructor<QLine, const QPoint &, const QPoint &>(line).create();
  // QLine(int, int, int, int);
  bind::constructor<QLine, int, int, int, int>(line).create();
  // bool isNull() const;
  bind::member_function<QLine, bool, &QLine::isNull>(line, "isNull").create();
  // QPoint p1() const;
  bind::member_function<QLine, QPoint, &QLine::p1>(line, "p1").create();
  // QPoint p2() const;
  bind::member_function<QLine, QPoint, &QLine::p2>(line, "p2").create();
  // int x1() const;
  bind::member_function<QLine, int, &QLine::x1>(line, "x1").create();
  // int y1() const;
  bind::member_function<QLine, int, &QLine::y1>(line, "y1").create();
  // int x2() const;
  bind::member_function<QLine, int, &QLine::x2>(line, "x2").create();
  // int y2() const;
  bind::member_function<QLine, int, &QLine::y2>(line, "y2").create();
  // int dx() const;
  bind::member_function<QLine, int, &QLine::dx>(line, "dx").create();
  // int dy() const;
  bind::member_function<QLine, int, &QLine::dy>(line, "dy").create();
  // void translate(const QPoint &);
  bind::void_member_function<QLine, const QPoint &, &QLine::translate>(line, "translate").create();
  // void translate(int, int);
  bind::void_member_function<QLine, int, int, &QLine::translate>(line, "translate").create();
  // QLine translated(const QPoint &) const;
  bind::member_function<QLine, QLine, const QPoint &, &QLine::translated>(line, "translated").create();
  // QLine translated(int, int) const;
  bind::member_function<QLine, QLine, int, int, &QLine::translated>(line, "translated").create();
  // QPoint center() const;
  bind::member_function<QLine, QPoint, &QLine::center>(line, "center").create();
  // void setP1(const QPoint &);
  bind::void_member_function<QLine, const QPoint &, &QLine::setP1>(line, "setP1").create();
  // void setP2(const QPoint &);
  bind::void_member_function<QLine, const QPoint &, &QLine::setP2>(line, "setP2").create();
  // void setPoints(const QPoint &, const QPoint &);
  bind::void_member_function<QLine, const QPoint &, const QPoint &, &QLine::setPoints>(line, "setPoints").create();
  // void setLine(int, int, int, int);
  bind::void_member_function<QLine, int, int, int, int, &QLine::setLine>(line, "setLine").create();
  // QLine & operator=(const QLine &);
  bind::memop_assign<QLine, const QLine &>(line);
  // bool operator==(const QLine &) const;
  bind::memop_eq<QLine, const QLine &>(line);
  // bool operator!=(const QLine &) const;
  bind::memop_neq<QLine, const QLine &>(line);
}


static void register_line_f_intersect_type_enum(script::Class line_f)
{
  using namespace script;

  Enum intersect_type = line_f.newEnum("IntersectType").setId(script::Type::QLineFIntersectType).get();

  intersect_type.addValue("NoIntersection", QLineF::NoIntersection);
  intersect_type.addValue("BoundedIntersection", QLineF::BoundedIntersection);
  intersect_type.addValue("UnboundedIntersection", QLineF::UnboundedIntersection);
}


static void register_line_f_class(script::Namespace ns)
{
  using namespace script;

  Class line_f = ns.newClass("LineF").setId(script::Type::QLineF).get();

  register_line_f_intersect_type_enum(line_f);

  // QLineF();
  bind::default_constructor<QLineF>(line_f).create();
  // QLineF(const QLineF &);
  bind::constructor<QLineF, const QLineF &>(line_f).create();
  // ~QLineF();
  bind::destructor<QLineF>(line_f).create();
  // QLineF(const QPointF &, const QPointF &);
  bind::constructor<QLineF, const QPointF &, const QPointF &>(line_f).create();
  // QLineF(qreal, qreal, qreal, qreal);
  bind::constructor<QLineF, qreal, qreal, qreal, qreal>(line_f).create();
  // QLineF(const QLine &);
  bind::constructor<QLineF, const QLine &>(line_f).create();
  // static QLineF fromPolar(qreal, qreal);
  bind::static_member_function<QLineF, QLineF, qreal, qreal, &QLineF::fromPolar>(line_f, "fromPolar").create();
  // bool isNull() const;
  bind::member_function<QLineF, bool, &QLineF::isNull>(line_f, "isNull").create();
  // QPointF p1() const;
  bind::member_function<QLineF, QPointF, &QLineF::p1>(line_f, "p1").create();
  // QPointF p2() const;
  bind::member_function<QLineF, QPointF, &QLineF::p2>(line_f, "p2").create();
  // qreal x1() const;
  bind::member_function<QLineF, qreal, &QLineF::x1>(line_f, "x1").create();
  // qreal y1() const;
  bind::member_function<QLineF, qreal, &QLineF::y1>(line_f, "y1").create();
  // qreal x2() const;
  bind::member_function<QLineF, qreal, &QLineF::x2>(line_f, "x2").create();
  // qreal y2() const;
  bind::member_function<QLineF, qreal, &QLineF::y2>(line_f, "y2").create();
  // qreal dx() const;
  bind::member_function<QLineF, qreal, &QLineF::dx>(line_f, "dx").create();
  // qreal dy() const;
  bind::member_function<QLineF, qreal, &QLineF::dy>(line_f, "dy").create();
  // qreal length() const;
  bind::member_function<QLineF, qreal, &QLineF::length>(line_f, "length").create();
  // void setLength(qreal);
  bind::void_member_function<QLineF, qreal, &QLineF::setLength>(line_f, "setLength").create();
  // qreal angle() const;
  bind::member_function<QLineF, qreal, &QLineF::angle>(line_f, "angle").create();
  // void setAngle(qreal);
  bind::void_member_function<QLineF, qreal, &QLineF::setAngle>(line_f, "setAngle").create();
  // qreal angleTo(const QLineF &) const;
  bind::member_function<QLineF, qreal, const QLineF &, &QLineF::angleTo>(line_f, "angleTo").create();
  // QLineF unitVector() const;
  bind::member_function<QLineF, QLineF, &QLineF::unitVector>(line_f, "unitVector").create();
  // QLineF normalVector() const;
  bind::member_function<QLineF, QLineF, &QLineF::normalVector>(line_f, "normalVector").create();
  // QLineF::IntersectType intersect(const QLineF &, QPointF *) const;
  /// TODO: QLineF::IntersectType intersect(const QLineF &, QPointF *) const;
  // qreal angle(const QLineF &) const;
  bind::member_function<QLineF, qreal, const QLineF &, &QLineF::angle>(line_f, "angle").create();
  // QPointF pointAt(qreal) const;
  bind::member_function<QLineF, QPointF, qreal, &QLineF::pointAt>(line_f, "pointAt").create();
  // void translate(const QPointF &);
  bind::void_member_function<QLineF, const QPointF &, &QLineF::translate>(line_f, "translate").create();
  // void translate(qreal, qreal);
  bind::void_member_function<QLineF, qreal, qreal, &QLineF::translate>(line_f, "translate").create();
  // QLineF translated(const QPointF &) const;
  bind::member_function<QLineF, QLineF, const QPointF &, &QLineF::translated>(line_f, "translated").create();
  // QLineF translated(qreal, qreal) const;
  bind::member_function<QLineF, QLineF, qreal, qreal, &QLineF::translated>(line_f, "translated").create();
  // QPointF center() const;
  bind::member_function<QLineF, QPointF, &QLineF::center>(line_f, "center").create();
  // void setP1(const QPointF &);
  bind::void_member_function<QLineF, const QPointF &, &QLineF::setP1>(line_f, "setP1").create();
  // void setP2(const QPointF &);
  bind::void_member_function<QLineF, const QPointF &, &QLineF::setP2>(line_f, "setP2").create();
  // void setPoints(const QPointF &, const QPointF &);
  bind::void_member_function<QLineF, const QPointF &, const QPointF &, &QLineF::setPoints>(line_f, "setPoints").create();
  // void setLine(qreal, qreal, qreal, qreal);
  bind::void_member_function<QLineF, qreal, qreal, qreal, qreal, &QLineF::setLine>(line_f, "setLine").create();
  // QLineF & operator=(const QLineF &);
  bind::memop_assign<QLineF, const QLineF &>(line_f);
  // bool operator==(const QLineF &) const;
  bind::memop_eq<QLineF, const QLineF &>(line_f);
  // bool operator!=(const QLineF &) const;
  bind::memop_neq<QLineF, const QLineF &>(line_f);
  // QLine toLine() const;
  bind::member_function<QLineF, QLine, &QLineF::toLine>(line_f, "toLine").create();
}


void register_line_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_line_class(ns);
  register_line_f_class(ns);

  // QDebug operator<<(QDebug, const QLine &);
  /// TODO: QDebug operator<<(QDebug, const QLine &);
  // QDataStream & operator<<(QDataStream &, const QLine &);
  bind::op_put_to<QDataStream &, const QLine &>(ns);
  // QDataStream & operator>>(QDataStream &, QLine &);
  bind::op_read_from<QDataStream &, QLine &>(ns);
  // QDebug operator<<(QDebug, const QLineF &);
  /// TODO: QDebug operator<<(QDebug, const QLineF &);
  // QDataStream & operator<<(QDataStream &, const QLineF &);
  bind::op_put_to<QDataStream &, const QLineF &>(ns);
  // QDataStream & operator>>(QDataStream &, QLineF &);
  bind::op_read_from<QDataStream &, QLineF &>(ns);
}

