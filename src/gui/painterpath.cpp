// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/painterpath.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

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

  Enum element_type = painter_path.Enum("ElementType").setId(script::Type::QPainterPathElementType).get();

  element_type.addValue("MoveToElement", QPainterPath::MoveToElement);
  element_type.addValue("LineToElement", QPainterPath::LineToElement);
  element_type.addValue("CurveToElement", QPainterPath::CurveToElement);
  element_type.addValue("CurveToDataElement", QPainterPath::CurveToDataElement);
}


static void register_painter_path_class(script::Namespace ns)
{
  using namespace script;

  Class painter_path = ns.Class("PainterPath").setId(script::Type::QPainterPath).get();

  register_painter_path_element_type_enum(painter_path);
  binding::Class<QPainterPath> binder{ painter_path };

  // QPainterPath();
  binder.ctors().add_default();
  // QPainterPath(const QPointF &);
  binder.ctors().ctor<const QPointF &>().create();
  // QPainterPath(const QPainterPath &);
  binder.ctors().ctor<const QPainterPath &>().create();
  // QPainterPath & operator=(const QPainterPath &);
  binder.operators().assign<const QPainterPath &>();
  // QPainterPath & operator=(QPainterPath &&);
  binder.operators().assign<QPainterPath &&>();
  // ~QPainterPath();
  binder.add_dtor();
  // void swap(QPainterPath &);
  binder.void_fun<QPainterPath &, &QPainterPath::swap>("swap").create();
  // void closeSubpath();
  binder.void_fun<&QPainterPath::closeSubpath>("closeSubpath").create();
  // void moveTo(const QPointF &);
  binder.void_fun<const QPointF &, &QPainterPath::moveTo>("moveTo").create();
  // void moveTo(qreal, qreal);
  binder.void_fun<qreal, qreal, &QPainterPath::moveTo>("moveTo").create();
  // void lineTo(const QPointF &);
  binder.void_fun<const QPointF &, &QPainterPath::lineTo>("lineTo").create();
  // void lineTo(qreal, qreal);
  binder.void_fun<qreal, qreal, &QPainterPath::lineTo>("lineTo").create();
  // void arcMoveTo(const QRectF &, qreal);
  binder.void_fun<const QRectF &, qreal, &QPainterPath::arcMoveTo>("arcMoveTo").create();
  // void arcMoveTo(qreal, qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, qreal, &QPainterPath::arcMoveTo>("arcMoveTo").create();
  // void arcTo(const QRectF &, qreal, qreal);
  binder.void_fun<const QRectF &, qreal, qreal, &QPainterPath::arcTo>("arcTo").create();
  // void arcTo(qreal, qreal, qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, qreal, qreal, &QPainterPath::arcTo>("arcTo").create();
  // void cubicTo(const QPointF &, const QPointF &, const QPointF &);
  binder.void_fun<const QPointF &, const QPointF &, const QPointF &, &QPainterPath::cubicTo>("cubicTo").create();
  // void cubicTo(qreal, qreal, qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, qreal, qreal, &QPainterPath::cubicTo>("cubicTo").create();
  // void quadTo(const QPointF &, const QPointF &);
  binder.void_fun<const QPointF &, const QPointF &, &QPainterPath::quadTo>("quadTo").create();
  // void quadTo(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QPainterPath::quadTo>("quadTo").create();
  // QPointF currentPosition() const;
  binder.fun<QPointF, &QPainterPath::currentPosition>("currentPosition").create();
  // void addRect(const QRectF &);
  binder.void_fun<const QRectF &, &QPainterPath::addRect>("addRect").create();
  // void addRect(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QPainterPath::addRect>("addRect").create();
  // void addEllipse(const QRectF &);
  binder.void_fun<const QRectF &, &QPainterPath::addEllipse>("addEllipse").create();
  // void addEllipse(qreal, qreal, qreal, qreal);
  binder.void_fun<qreal, qreal, qreal, qreal, &QPainterPath::addEllipse>("addEllipse").create();
  // void addEllipse(const QPointF &, qreal, qreal);
  binder.void_fun<const QPointF &, qreal, qreal, &QPainterPath::addEllipse>("addEllipse").create();
  // void addPolygon(const QPolygonF &);
  /// TODO: void addPolygon(const QPolygonF &);
  // void addText(const QPointF &, const QFont &, const QString &);
  binder.void_fun<const QPointF &, const QFont &, const QString &, &QPainterPath::addText>("addText").create();
  // void addText(qreal, qreal, const QFont &, const QString &);
  binder.void_fun<qreal, qreal, const QFont &, const QString &, &QPainterPath::addText>("addText").create();
  // void addPath(const QPainterPath &);
  binder.void_fun<const QPainterPath &, &QPainterPath::addPath>("addPath").create();
  // void addRegion(const QRegion &);
  binder.void_fun<const QRegion &, &QPainterPath::addRegion>("addRegion").create();
  // void addRoundedRect(const QRectF &, qreal, qreal, Qt::SizeMode);
  binder.void_fun<const QRectF &, qreal, qreal, Qt::SizeMode, &QPainterPath::addRoundedRect>("addRoundedRect").create();
  // void addRoundRect(const QRectF &, int, int);
  binder.void_fun<const QRectF &, int, int, &QPainterPath::addRoundRect>("addRoundRect").create();
  // void addRoundRect(qreal, qreal, qreal, qreal, int, int);
  binder.void_fun<qreal, qreal, qreal, qreal, int, int, &QPainterPath::addRoundRect>("addRoundRect").create();
  // void addRoundRect(const QRectF &, int);
  binder.void_fun<const QRectF &, int, &QPainterPath::addRoundRect>("addRoundRect").create();
  // void addRoundRect(qreal, qreal, qreal, qreal, int);
  binder.void_fun<qreal, qreal, qreal, qreal, int, &QPainterPath::addRoundRect>("addRoundRect").create();
  // void connectPath(const QPainterPath &);
  binder.void_fun<const QPainterPath &, &QPainterPath::connectPath>("connectPath").create();
  // bool contains(const QPointF &) const;
  binder.fun<bool, const QPointF &, &QPainterPath::contains>("contains").create();
  // bool contains(const QRectF &) const;
  binder.fun<bool, const QRectF &, &QPainterPath::contains>("contains").create();
  // bool intersects(const QRectF &) const;
  binder.fun<bool, const QRectF &, &QPainterPath::intersects>("intersects").create();
  // void translate(qreal, qreal);
  binder.void_fun<qreal, qreal, &QPainterPath::translate>("translate").create();
  // void translate(const QPointF &);
  binder.void_fun<const QPointF &, &QPainterPath::translate>("translate").create();
  // QPainterPath translated(qreal, qreal) const;
  binder.fun<QPainterPath, qreal, qreal, &QPainterPath::translated>("translated").create();
  // QPainterPath translated(const QPointF &) const;
  binder.fun<QPainterPath, const QPointF &, &QPainterPath::translated>("translated").create();
  // QRectF boundingRect() const;
  binder.fun<QRectF, &QPainterPath::boundingRect>("boundingRect").create();
  // QRectF controlPointRect() const;
  binder.fun<QRectF, &QPainterPath::controlPointRect>("controlPointRect").create();
  // Qt::FillRule fillRule() const;
  binder.fun<Qt::FillRule, &QPainterPath::fillRule>("fillRule").create();
  // void setFillRule(Qt::FillRule);
  binder.void_fun<Qt::FillRule, &QPainterPath::setFillRule>("setFillRule").create();
  // bool isEmpty() const;
  binder.fun<bool, &QPainterPath::isEmpty>("isEmpty").create();
  // QPainterPath toReversed() const;
  binder.fun<QPainterPath, &QPainterPath::toReversed>("toReversed").create();
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
  binder.fun<int, &QPainterPath::elementCount>("elementCount").create();
  // QPainterPath::Element elementAt(int) const;
  /// TODO: QPainterPath::Element elementAt(int) const;
  // void setElementPositionAt(int, qreal, qreal);
  binder.void_fun<int, qreal, qreal, &QPainterPath::setElementPositionAt>("setElementPositionAt").create();
  // qreal length() const;
  binder.fun<qreal, &QPainterPath::length>("length").create();
  // qreal percentAtLength(qreal) const;
  binder.fun<qreal, qreal, &QPainterPath::percentAtLength>("percentAtLength").create();
  // QPointF pointAtPercent(qreal) const;
  binder.fun<QPointF, qreal, &QPainterPath::pointAtPercent>("pointAtPercent").create();
  // qreal angleAtPercent(qreal) const;
  binder.fun<qreal, qreal, &QPainterPath::angleAtPercent>("angleAtPercent").create();
  // qreal slopeAtPercent(qreal) const;
  binder.fun<qreal, qreal, &QPainterPath::slopeAtPercent>("slopeAtPercent").create();
  // bool intersects(const QPainterPath &) const;
  binder.fun<bool, const QPainterPath &, &QPainterPath::intersects>("intersects").create();
  // bool contains(const QPainterPath &) const;
  binder.fun<bool, const QPainterPath &, &QPainterPath::contains>("contains").create();
  // QPainterPath united(const QPainterPath &) const;
  binder.fun<QPainterPath, const QPainterPath &, &QPainterPath::united>("united").create();
  // QPainterPath intersected(const QPainterPath &) const;
  binder.fun<QPainterPath, const QPainterPath &, &QPainterPath::intersected>("intersected").create();
  // QPainterPath subtracted(const QPainterPath &) const;
  binder.fun<QPainterPath, const QPainterPath &, &QPainterPath::subtracted>("subtracted").create();
  // QPainterPath subtractedInverted(const QPainterPath &) const;
  binder.fun<QPainterPath, const QPainterPath &, &QPainterPath::subtractedInverted>("subtractedInverted").create();
  // QPainterPath simplified() const;
  binder.fun<QPainterPath, &QPainterPath::simplified>("simplified").create();
  // bool operator==(const QPainterPath &) const;
  binder.operators().eq<const QPainterPath &>();
  // bool operator!=(const QPainterPath &) const;
  binder.operators().neq<const QPainterPath &>();
  // QPainterPath operator&(const QPainterPath &) const;
  binder.operators().and<QPainterPath, const QPainterPath &>();
  // QPainterPath operator|(const QPainterPath &) const;
  binder.operators().or<QPainterPath, const QPainterPath &>();
  // QPainterPath operator+(const QPainterPath &) const;
  binder.operators().add<QPainterPath, const QPainterPath &>();
  // QPainterPath operator-(const QPainterPath &) const;
  binder.operators().sub<QPainterPath, const QPainterPath &>();
  // QPainterPath & operator&=(const QPainterPath &);
  binder.operators().and_assign<const QPainterPath &>();
  // QPainterPath & operator|=(const QPainterPath &);
  binder.operators().or_assign<const QPainterPath &>();
  // QPainterPath & operator+=(const QPainterPath &);
  binder.operators().add_assign<const QPainterPath &>();
  // QPainterPath & operator-=(const QPainterPath &);
  binder.operators().sub_assign<const QPainterPath &>();
}


static void register_painter_path_stroker_class(script::Namespace ns)
{
  using namespace script;

  Class painter_path_stroker = ns.Class("PainterPathStroker").setId(script::Type::QPainterPathStroker).get();

  binding::Class<QPainterPathStroker> binder{ painter_path_stroker };

  // QPainterPathStroker();
  binder.ctors().add_default();
  // QPainterPathStroker(const QPen &);
  binder.ctors().ctor<const QPen &>().create();
  // ~QPainterPathStroker();
  binder.add_dtor();
  // void setWidth(qreal);
  binder.void_fun<qreal, &QPainterPathStroker::setWidth>("setWidth").create();
  // qreal width() const;
  binder.fun<qreal, &QPainterPathStroker::width>("width").create();
  // void setCapStyle(Qt::PenCapStyle);
  binder.void_fun<Qt::PenCapStyle, &QPainterPathStroker::setCapStyle>("setCapStyle").create();
  // Qt::PenCapStyle capStyle() const;
  binder.fun<Qt::PenCapStyle, &QPainterPathStroker::capStyle>("capStyle").create();
  // void setJoinStyle(Qt::PenJoinStyle);
  binder.void_fun<Qt::PenJoinStyle, &QPainterPathStroker::setJoinStyle>("setJoinStyle").create();
  // Qt::PenJoinStyle joinStyle() const;
  binder.fun<Qt::PenJoinStyle, &QPainterPathStroker::joinStyle>("joinStyle").create();
  // void setMiterLimit(qreal);
  binder.void_fun<qreal, &QPainterPathStroker::setMiterLimit>("setMiterLimit").create();
  // qreal miterLimit() const;
  binder.fun<qreal, &QPainterPathStroker::miterLimit>("miterLimit").create();
  // void setCurveThreshold(qreal);
  binder.void_fun<qreal, &QPainterPathStroker::setCurveThreshold>("setCurveThreshold").create();
  // qreal curveThreshold() const;
  binder.fun<qreal, &QPainterPathStroker::curveThreshold>("curveThreshold").create();
  // void setDashPattern(Qt::PenStyle);
  binder.void_fun<Qt::PenStyle, &QPainterPathStroker::setDashPattern>("setDashPattern").create();
  // void setDashPattern(const QVector<qreal> &);
  /// TODO: void setDashPattern(const QVector<qreal> &);
  // QVector<qreal> dashPattern() const;
  /// TODO: QVector<qreal> dashPattern() const;
  // void setDashOffset(qreal);
  binder.void_fun<qreal, &QPainterPathStroker::setDashOffset>("setDashOffset").create();
  // qreal dashOffset() const;
  binder.fun<qreal, &QPainterPathStroker::dashOffset>("dashOffset").create();
  // QPainterPath createStroke(const QPainterPath &) const;
  binder.fun<QPainterPath, const QPainterPath &, &QPainterPathStroker::createStroke>("createStroke").create();
}


void register_painterpath_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_painter_path_class(ns);
  register_painter_path_stroker_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QPainterPath &, QPainterPath &);
  binder.void_fun<QPainterPath &, QPainterPath &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QPainterPath &);
  binder.operators().put_to<QDataStream &, const QPainterPath &>();
  // QDataStream & operator>>(QDataStream &, QPainterPath &);
  binder.operators().read_from<QDataStream &, QPainterPath &>();
  // QDebug operator<<(QDebug, const QPainterPath &);
  /// TODO: QDebug operator<<(QDebug, const QPainterPath &);
}

