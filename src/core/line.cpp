// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/line.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/point.h"

#include <QDataStream>
#include <QDebug>

static void register_line_class(script::Namespace ns)
{
  using namespace script;

  Class line = ns.newClass(ClassBuilder::New("Line").setId(script::Type::QLine));

  binding::Class<QLine> binder{ line };

  // QLine();
  binder.ctors().add_default();
  // QLine(const QPoint &, const QPoint &);
  binder.ctors().add<const QPoint &, const QPoint &>();
  // QLine(int, int, int, int);
  binder.ctors().add<int, int, int, int>();
  // bool isNull() const;
  binder.add_fun<bool, &QLine::isNull>("isNull");
  // QPoint p1() const;
  binder.add_fun<QPoint, &QLine::p1>("p1");
  // QPoint p2() const;
  binder.add_fun<QPoint, &QLine::p2>("p2");
  // int x1() const;
  binder.add_fun<int, &QLine::x1>("x1");
  // int y1() const;
  binder.add_fun<int, &QLine::y1>("y1");
  // int x2() const;
  binder.add_fun<int, &QLine::x2>("x2");
  // int y2() const;
  binder.add_fun<int, &QLine::y2>("y2");
  // int dx() const;
  binder.add_fun<int, &QLine::dx>("dx");
  // int dy() const;
  binder.add_fun<int, &QLine::dy>("dy");
  // void translate(const QPoint &);
  binder.add_void_fun<const QPoint &, &QLine::translate>("translate");
  // void translate(int, int);
  binder.add_void_fun<int, int, &QLine::translate>("translate");
  // QLine translated(const QPoint &) const;
  binder.add_fun<QLine, const QPoint &, &QLine::translated>("translated");
  // QLine translated(int, int) const;
  binder.add_fun<QLine, int, int, &QLine::translated>("translated");
  // QPoint center() const;
  binder.add_fun<QPoint, &QLine::center>("center");
  // void setP1(const QPoint &);
  binder.add_void_fun<const QPoint &, &QLine::setP1>("setP1");
  // void setP2(const QPoint &);
  binder.add_void_fun<const QPoint &, &QLine::setP2>("setP2");
  // void setPoints(const QPoint &, const QPoint &);
  binder.add_void_fun<const QPoint &, const QPoint &, &QLine::setPoints>("setPoints");
  // void setLine(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QLine::setLine>("setLine");
  // bool operator==(const QLine &) const;
  binder.operators().eq<const QLine &>();
  // bool operator!=(const QLine &) const;
  binder.operators().neq<const QLine &>();
}

static void register_line_f_intersect_type_enum(script::Class line_f)
{
  using namespace script;

  Enum intersect_type = line_f.newEnum("IntersectType", script::Type::QLineFIntersectType);

  intersect_type.addValue("BoundedIntersection", QLineF::BoundedIntersection);
  intersect_type.addValue("NoIntersection", QLineF::NoIntersection);
  intersect_type.addValue("UnboundedIntersection", QLineF::UnboundedIntersection);
}

static void register_line_f_class(script::Namespace ns)
{
  using namespace script;

  Class line_f = ns.newClass(ClassBuilder::New("LineF").setId(script::Type::QLineF));

  register_line_f_intersect_type_enum(line_f);
  binding::Class<QLineF> binder{ line_f };

  // QLineF();
  binder.ctors().add_default();
  // QLineF(const QPointF &, const QPointF &);
  binder.ctors().add<const QPointF &, const QPointF &>();
  // QLineF(qreal, qreal, qreal, qreal);
  binder.ctors().add<qreal, qreal, qreal, qreal>();
  // QLineF(const QLine &);
  binder.ctors().add<const QLine &>();
  // static QLineF fromPolar(qreal, qreal);
  binder.add_static<QLineF, qreal, qreal, &QLineF::fromPolar>("fromPolar");
  // bool isNull() const;
  binder.add_fun<bool, &QLineF::isNull>("isNull");
  // QPointF p1() const;
  binder.add_fun<QPointF, &QLineF::p1>("p1");
  // QPointF p2() const;
  binder.add_fun<QPointF, &QLineF::p2>("p2");
  // qreal x1() const;
  binder.add_fun<qreal, &QLineF::x1>("x1");
  // qreal y1() const;
  binder.add_fun<qreal, &QLineF::y1>("y1");
  // qreal x2() const;
  binder.add_fun<qreal, &QLineF::x2>("x2");
  // qreal y2() const;
  binder.add_fun<qreal, &QLineF::y2>("y2");
  // qreal dx() const;
  binder.add_fun<qreal, &QLineF::dx>("dx");
  // qreal dy() const;
  binder.add_fun<qreal, &QLineF::dy>("dy");
  // qreal length() const;
  binder.add_fun<qreal, &QLineF::length>("length");
  // void setLength(qreal);
  binder.add_void_fun<qreal, &QLineF::setLength>("setLength");
  // qreal angle() const;
  binder.add_fun<qreal, &QLineF::angle>("angle");
  // void setAngle(qreal);
  binder.add_void_fun<qreal, &QLineF::setAngle>("setAngle");
  // qreal angleTo(const QLineF &) const;
  binder.add_fun<qreal, const QLineF &, &QLineF::angleTo>("angleTo");
  // QLineF unitVector() const;
  binder.add_fun<QLineF, &QLineF::unitVector>("unitVector");
  // QLineF normalVector() const;
  binder.add_fun<QLineF, &QLineF::normalVector>("normalVector");
  // QLineF::IntersectType intersect(const QLineF &, QPointF *) const;
  binder.add_fun<QLineF::IntersectType, const QLineF &, QPointF *, &QLineF::intersect>("intersect");
  // qreal angle(const QLineF &) const;
  binder.add_fun<qreal, const QLineF &, &QLineF::angle>("angle");
  // QPointF pointAt(qreal) const;
  binder.add_fun<QPointF, qreal, &QLineF::pointAt>("pointAt");
  // void translate(const QPointF &);
  binder.add_void_fun<const QPointF &, &QLineF::translate>("translate");
  // void translate(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QLineF::translate>("translate");
  // QLineF translated(const QPointF &) const;
  binder.add_fun<QLineF, const QPointF &, &QLineF::translated>("translated");
  // QLineF translated(qreal, qreal) const;
  binder.add_fun<QLineF, qreal, qreal, &QLineF::translated>("translated");
  // QPointF center() const;
  binder.add_fun<QPointF, &QLineF::center>("center");
  // void setP1(const QPointF &);
  binder.add_void_fun<const QPointF &, &QLineF::setP1>("setP1");
  // void setP2(const QPointF &);
  binder.add_void_fun<const QPointF &, &QLineF::setP2>("setP2");
  // void setPoints(const QPointF &, const QPointF &);
  binder.add_void_fun<const QPointF &, const QPointF &, &QLineF::setPoints>("setPoints");
  // void setLine(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QLineF::setLine>("setLine");
  // bool operator==(const QLineF &) const;
  binder.operators().eq<const QLineF &>();
  // bool operator!=(const QLineF &) const;
  binder.operators().neq<const QLineF &>();
  // QLine toLine() const;
  binder.add_fun<QLine, &QLineF::toLine>("toLine");
}

void register_line_file(script::Namespace root)
{
  using namespace script;

  register_line_class(root);
  register_line_f_class(root);
  binding::Namespace binder{ root };

  // QDebug operator<<(QDebug, const QLine &);
  binder.operators().left_shift<QDebug, QDebug, const QLine &>();
  // QDataStream & operator<<(QDataStream &, const QLine &);
  binder.operators().put_to<QDataStream &, const QLine &>();
  // QDataStream & operator>>(QDataStream &, QLine &);
  binder.operators().read_from<QDataStream &, QLine &>();
  // QDebug operator<<(QDebug, const QLineF &);
  binder.operators().left_shift<QDebug, QDebug, const QLineF &>();
  // QDataStream & operator<<(QDataStream &, const QLineF &);
  binder.operators().put_to<QDataStream &, const QLineF &>();
  // QDataStream & operator>>(QDataStream &, QLineF &);
  binder.operators().read_from<QDataStream &, QLineF &>();
}

