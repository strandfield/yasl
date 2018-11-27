// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/painterpath.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/gui/font.h"
#include "yasl/gui/painterpath.h"
#include "yasl/gui/pen.h"
#include "yasl/gui/region.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_painter_path_element_type_enum(script::Class painter_path)
{
  using namespace script;

  Enum element_type = painter_path.newEnum("ElementType").setId(script::Type::QPainterPathElementType).get();

  element_type.addValue("MoveToElement", QPainterPath::MoveToElement);
  element_type.addValue("LineToElement", QPainterPath::LineToElement);
  element_type.addValue("CurveToElement", QPainterPath::CurveToElement);
  element_type.addValue("CurveToDataElement", QPainterPath::CurveToDataElement);
}


static void register_painter_path_class(script::Namespace ns)
{
  using namespace script;

  Class painter_path = ns.newClass("PainterPath").setId(script::Type::QPainterPath).get();

  register_painter_path_element_type_enum(painter_path);

  // QPainterPath();
  bind::default_constructor<QPainterPath>(painter_path).create();
  // QPainterPath(const QPointF &);
  bind::constructor<QPainterPath, const QPointF &>(painter_path).create();
  // QPainterPath(const QPainterPath &);
  bind::constructor<QPainterPath, const QPainterPath &>(painter_path).create();
  // QPainterPath & operator=(const QPainterPath &);
  bind::memop_assign<QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath & operator=(QPainterPath &&);
  bind::memop_assign<QPainterPath, QPainterPath &&>(painter_path);
  // ~QPainterPath();
  bind::destructor<QPainterPath>(painter_path).create();
  // void swap(QPainterPath &);
  bind::void_member_function<QPainterPath, QPainterPath &, &QPainterPath::swap>(painter_path, "swap").create();
  // void closeSubpath();
  bind::void_member_function<QPainterPath, &QPainterPath::closeSubpath>(painter_path, "closeSubpath").create();
  // void moveTo(const QPointF &);
  bind::void_member_function<QPainterPath, const QPointF &, &QPainterPath::moveTo>(painter_path, "moveTo").create();
  // void moveTo(qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, &QPainterPath::moveTo>(painter_path, "moveTo").create();
  // void lineTo(const QPointF &);
  bind::void_member_function<QPainterPath, const QPointF &, &QPainterPath::lineTo>(painter_path, "lineTo").create();
  // void lineTo(qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, &QPainterPath::lineTo>(painter_path, "lineTo").create();
  // void arcMoveTo(const QRectF &, qreal);
  bind::void_member_function<QPainterPath, const QRectF &, qreal, &QPainterPath::arcMoveTo>(painter_path, "arcMoveTo").create();
  // void arcMoveTo(qreal, qreal, qreal, qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, qreal, qreal, qreal, &QPainterPath::arcMoveTo>(painter_path, "arcMoveTo").create();
  // void arcTo(const QRectF &, qreal, qreal);
  bind::void_member_function<QPainterPath, const QRectF &, qreal, qreal, &QPainterPath::arcTo>(painter_path, "arcTo").create();
  // void arcTo(qreal, qreal, qreal, qreal, qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, qreal, qreal, qreal, qreal, &QPainterPath::arcTo>(painter_path, "arcTo").create();
  // void cubicTo(const QPointF &, const QPointF &, const QPointF &);
  bind::void_member_function<QPainterPath, const QPointF &, const QPointF &, const QPointF &, &QPainterPath::cubicTo>(painter_path, "cubicTo").create();
  // void cubicTo(qreal, qreal, qreal, qreal, qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, qreal, qreal, qreal, qreal, &QPainterPath::cubicTo>(painter_path, "cubicTo").create();
  // void quadTo(const QPointF &, const QPointF &);
  bind::void_member_function<QPainterPath, const QPointF &, const QPointF &, &QPainterPath::quadTo>(painter_path, "quadTo").create();
  // void quadTo(qreal, qreal, qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, qreal, qreal, &QPainterPath::quadTo>(painter_path, "quadTo").create();
  // QPointF currentPosition() const;
  bind::member_function<QPainterPath, QPointF, &QPainterPath::currentPosition>(painter_path, "currentPosition").create();
  // void addRect(const QRectF &);
  bind::void_member_function<QPainterPath, const QRectF &, &QPainterPath::addRect>(painter_path, "addRect").create();
  // void addRect(qreal, qreal, qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, qreal, qreal, &QPainterPath::addRect>(painter_path, "addRect").create();
  // void addEllipse(const QRectF &);
  bind::void_member_function<QPainterPath, const QRectF &, &QPainterPath::addEllipse>(painter_path, "addEllipse").create();
  // void addEllipse(qreal, qreal, qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, qreal, qreal, &QPainterPath::addEllipse>(painter_path, "addEllipse").create();
  // void addEllipse(const QPointF &, qreal, qreal);
  bind::void_member_function<QPainterPath, const QPointF &, qreal, qreal, &QPainterPath::addEllipse>(painter_path, "addEllipse").create();
  // void addPolygon(const QPolygonF &);
  /// TODO: void addPolygon(const QPolygonF &);
  // void addText(const QPointF &, const QFont &, const QString &);
  bind::void_member_function<QPainterPath, const QPointF &, const QFont &, const QString &, &QPainterPath::addText>(painter_path, "addText").create();
  // void addText(qreal, qreal, const QFont &, const QString &);
  bind::void_member_function<QPainterPath, qreal, qreal, const QFont &, const QString &, &QPainterPath::addText>(painter_path, "addText").create();
  // void addPath(const QPainterPath &);
  bind::void_member_function<QPainterPath, const QPainterPath &, &QPainterPath::addPath>(painter_path, "addPath").create();
  // void addRegion(const QRegion &);
  bind::void_member_function<QPainterPath, const QRegion &, &QPainterPath::addRegion>(painter_path, "addRegion").create();
  // void addRoundedRect(const QRectF &, qreal, qreal, Qt::SizeMode = Qt::AbsoluteSize);
  bind::void_member_function<QPainterPath, const QRectF &, qreal, qreal, Qt::SizeMode, &QPainterPath::addRoundedRect>(painter_path, "addRoundedRect")
    .apply(bind::default_arguments(Qt::AbsoluteSize)).create();
  // void addRoundRect(const QRectF &, int, int);
  bind::void_member_function<QPainterPath, const QRectF &, int, int, &QPainterPath::addRoundRect>(painter_path, "addRoundRect").create();
  // void addRoundRect(qreal, qreal, qreal, qreal, int, int);
  bind::void_member_function<QPainterPath, qreal, qreal, qreal, qreal, int, int, &QPainterPath::addRoundRect>(painter_path, "addRoundRect").create();
  // void addRoundRect(const QRectF &, int);
  bind::void_member_function<QPainterPath, const QRectF &, int, &QPainterPath::addRoundRect>(painter_path, "addRoundRect").create();
  // void addRoundRect(qreal, qreal, qreal, qreal, int);
  bind::void_member_function<QPainterPath, qreal, qreal, qreal, qreal, int, &QPainterPath::addRoundRect>(painter_path, "addRoundRect").create();
  // void connectPath(const QPainterPath &);
  bind::void_member_function<QPainterPath, const QPainterPath &, &QPainterPath::connectPath>(painter_path, "connectPath").create();
  // bool contains(const QPointF &) const;
  bind::member_function<QPainterPath, bool, const QPointF &, &QPainterPath::contains>(painter_path, "contains").create();
  // bool contains(const QRectF &) const;
  bind::member_function<QPainterPath, bool, const QRectF &, &QPainterPath::contains>(painter_path, "contains").create();
  // bool intersects(const QRectF &) const;
  bind::member_function<QPainterPath, bool, const QRectF &, &QPainterPath::intersects>(painter_path, "intersects").create();
  // void translate(qreal, qreal);
  bind::void_member_function<QPainterPath, qreal, qreal, &QPainterPath::translate>(painter_path, "translate").create();
  // void translate(const QPointF &);
  bind::void_member_function<QPainterPath, const QPointF &, &QPainterPath::translate>(painter_path, "translate").create();
  // QPainterPath translated(qreal, qreal) const;
  bind::member_function<QPainterPath, QPainterPath, qreal, qreal, &QPainterPath::translated>(painter_path, "translated").create();
  // QPainterPath translated(const QPointF &) const;
  bind::member_function<QPainterPath, QPainterPath, const QPointF &, &QPainterPath::translated>(painter_path, "translated").create();
  // QRectF boundingRect() const;
  bind::member_function<QPainterPath, QRectF, &QPainterPath::boundingRect>(painter_path, "boundingRect").create();
  // QRectF controlPointRect() const;
  bind::member_function<QPainterPath, QRectF, &QPainterPath::controlPointRect>(painter_path, "controlPointRect").create();
  // Qt::FillRule fillRule() const;
  bind::member_function<QPainterPath, Qt::FillRule, &QPainterPath::fillRule>(painter_path, "fillRule").create();
  // void setFillRule(Qt::FillRule);
  bind::void_member_function<QPainterPath, Qt::FillRule, &QPainterPath::setFillRule>(painter_path, "setFillRule").create();
  // bool isEmpty() const;
  bind::member_function<QPainterPath, bool, &QPainterPath::isEmpty>(painter_path, "isEmpty").create();
  // QPainterPath toReversed() const;
  bind::member_function<QPainterPath, QPainterPath, &QPainterPath::toReversed>(painter_path, "toReversed").create();
  // QList<QPolygonF> toSubpathPolygons(const QMatrix &) const;
  /// TODO: QList<QPolygonF> toSubpathPolygons(const QMatrix &) const;
  // QList<QPolygonF> toFillPolygons(const QMatrix &) const;
  /// TODO: QList<QPolygonF> toFillPolygons(const QMatrix &) const;
  // QPolygonF toFillPolygon(const QMatrix &) const;
  /// TODO: QPolygonF toFillPolygon(const QMatrix &) const;
  // QList<QPolygonF> toSubpathPolygons(const QTransform &) const;
  /// TODO: QList<QPolygonF> toSubpathPolygons(const QTransform &) const;
  // QList<QPolygonF> toFillPolygons(const QTransform &) const;
  /// TODO: QList<QPolygonF> toFillPolygons(const QTransform &) const;
  // QPolygonF toFillPolygon(const QTransform &) const;
  /// TODO: QPolygonF toFillPolygon(const QTransform &) const;
  // int elementCount() const;
  bind::member_function<QPainterPath, int, &QPainterPath::elementCount>(painter_path, "elementCount").create();
  // QPainterPath::Element elementAt(int) const;
  /// TODO: QPainterPath::Element elementAt(int) const;
  // void setElementPositionAt(int, qreal, qreal);
  bind::void_member_function<QPainterPath, int, qreal, qreal, &QPainterPath::setElementPositionAt>(painter_path, "setElementPositionAt").create();
  // qreal length() const;
  bind::member_function<QPainterPath, qreal, &QPainterPath::length>(painter_path, "length").create();
  // qreal percentAtLength(qreal) const;
  bind::member_function<QPainterPath, qreal, qreal, &QPainterPath::percentAtLength>(painter_path, "percentAtLength").create();
  // QPointF pointAtPercent(qreal) const;
  bind::member_function<QPainterPath, QPointF, qreal, &QPainterPath::pointAtPercent>(painter_path, "pointAtPercent").create();
  // qreal angleAtPercent(qreal) const;
  bind::member_function<QPainterPath, qreal, qreal, &QPainterPath::angleAtPercent>(painter_path, "angleAtPercent").create();
  // qreal slopeAtPercent(qreal) const;
  bind::member_function<QPainterPath, qreal, qreal, &QPainterPath::slopeAtPercent>(painter_path, "slopeAtPercent").create();
  // bool intersects(const QPainterPath &) const;
  bind::member_function<QPainterPath, bool, const QPainterPath &, &QPainterPath::intersects>(painter_path, "intersects").create();
  // bool contains(const QPainterPath &) const;
  bind::member_function<QPainterPath, bool, const QPainterPath &, &QPainterPath::contains>(painter_path, "contains").create();
  // QPainterPath united(const QPainterPath &) const;
  bind::member_function<QPainterPath, QPainterPath, const QPainterPath &, &QPainterPath::united>(painter_path, "united").create();
  // QPainterPath intersected(const QPainterPath &) const;
  bind::member_function<QPainterPath, QPainterPath, const QPainterPath &, &QPainterPath::intersected>(painter_path, "intersected").create();
  // QPainterPath subtracted(const QPainterPath &) const;
  bind::member_function<QPainterPath, QPainterPath, const QPainterPath &, &QPainterPath::subtracted>(painter_path, "subtracted").create();
  // QPainterPath subtractedInverted(const QPainterPath &) const;
  bind::member_function<QPainterPath, QPainterPath, const QPainterPath &, &QPainterPath::subtractedInverted>(painter_path, "subtractedInverted").create();
  // QPainterPath simplified() const;
  bind::member_function<QPainterPath, QPainterPath, &QPainterPath::simplified>(painter_path, "simplified").create();
  // bool operator==(const QPainterPath &) const;
  bind::memop_eq<QPainterPath, const QPainterPath &>(painter_path);
  // bool operator!=(const QPainterPath &) const;
  bind::memop_neq<QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath operator&(const QPainterPath &) const;
  bind::memop_bitand<QPainterPath, QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath operator|(const QPainterPath &) const;
  bind::memop_bitor<QPainterPath, QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath operator+(const QPainterPath &) const;
  bind::memop_add<QPainterPath, QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath operator-(const QPainterPath &) const;
  bind::memop_sub<QPainterPath, QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath & operator&=(const QPainterPath &);
  bind::memop_and_assign<QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath & operator|=(const QPainterPath &);
  bind::memop_or_assign<QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath & operator+=(const QPainterPath &);
  bind::memop_add_assign<QPainterPath, const QPainterPath &>(painter_path);
  // QPainterPath & operator-=(const QPainterPath &);
  bind::memop_sub_assign<QPainterPath, const QPainterPath &>(painter_path);
}


static void register_painter_path_stroker_class(script::Namespace ns)
{
  using namespace script;

  Class painter_path_stroker = ns.newClass("PainterPathStroker").setId(script::Type::QPainterPathStroker).get();


  // QPainterPathStroker();
  bind::default_constructor<QPainterPathStroker>(painter_path_stroker).create();
  // QPainterPathStroker(const QPen &);
  bind::constructor<QPainterPathStroker, const QPen &>(painter_path_stroker).create();
  // ~QPainterPathStroker();
  bind::destructor<QPainterPathStroker>(painter_path_stroker).create();
  // void setWidth(qreal);
  bind::void_member_function<QPainterPathStroker, qreal, &QPainterPathStroker::setWidth>(painter_path_stroker, "setWidth").create();
  // qreal width() const;
  bind::member_function<QPainterPathStroker, qreal, &QPainterPathStroker::width>(painter_path_stroker, "width").create();
  // void setCapStyle(Qt::PenCapStyle);
  bind::void_member_function<QPainterPathStroker, Qt::PenCapStyle, &QPainterPathStroker::setCapStyle>(painter_path_stroker, "setCapStyle").create();
  // Qt::PenCapStyle capStyle() const;
  bind::member_function<QPainterPathStroker, Qt::PenCapStyle, &QPainterPathStroker::capStyle>(painter_path_stroker, "capStyle").create();
  // void setJoinStyle(Qt::PenJoinStyle);
  bind::void_member_function<QPainterPathStroker, Qt::PenJoinStyle, &QPainterPathStroker::setJoinStyle>(painter_path_stroker, "setJoinStyle").create();
  // Qt::PenJoinStyle joinStyle() const;
  bind::member_function<QPainterPathStroker, Qt::PenJoinStyle, &QPainterPathStroker::joinStyle>(painter_path_stroker, "joinStyle").create();
  // void setMiterLimit(qreal);
  bind::void_member_function<QPainterPathStroker, qreal, &QPainterPathStroker::setMiterLimit>(painter_path_stroker, "setMiterLimit").create();
  // qreal miterLimit() const;
  bind::member_function<QPainterPathStroker, qreal, &QPainterPathStroker::miterLimit>(painter_path_stroker, "miterLimit").create();
  // void setCurveThreshold(qreal);
  bind::void_member_function<QPainterPathStroker, qreal, &QPainterPathStroker::setCurveThreshold>(painter_path_stroker, "setCurveThreshold").create();
  // qreal curveThreshold() const;
  bind::member_function<QPainterPathStroker, qreal, &QPainterPathStroker::curveThreshold>(painter_path_stroker, "curveThreshold").create();
  // void setDashPattern(Qt::PenStyle);
  bind::void_member_function<QPainterPathStroker, Qt::PenStyle, &QPainterPathStroker::setDashPattern>(painter_path_stroker, "setDashPattern").create();
  // void setDashPattern(const QVector<qreal> &);
  /// TODO: void setDashPattern(const QVector<qreal> &);
  // QVector<qreal> dashPattern() const;
  /// TODO: QVector<qreal> dashPattern() const;
  // void setDashOffset(qreal);
  bind::void_member_function<QPainterPathStroker, qreal, &QPainterPathStroker::setDashOffset>(painter_path_stroker, "setDashOffset").create();
  // qreal dashOffset() const;
  bind::member_function<QPainterPathStroker, qreal, &QPainterPathStroker::dashOffset>(painter_path_stroker, "dashOffset").create();
  // QPainterPath createStroke(const QPainterPath &) const;
  bind::member_function<QPainterPathStroker, QPainterPath, const QPainterPath &, &QPainterPathStroker::createStroke>(painter_path_stroker, "createStroke").create();
}


void register_painterpath_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_painter_path_class(ns);
  register_painter_path_stroker_class(ns);

  // void swap(QPainterPath &, QPainterPath &);
  bind::void_function<QPainterPath &, QPainterPath &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QPainterPath &);
  bind::op_put_to<QDataStream &, const QPainterPath &>(ns);
  // QDataStream & operator>>(QDataStream &, QPainterPath &);
  bind::op_read_from<QDataStream &, QPainterPath &>(ns);
  // QDebug operator<<(QDebug, const QPainterPath &);
  /// TODO: QDebug operator<<(QDebug, const QPainterPath &);
}

