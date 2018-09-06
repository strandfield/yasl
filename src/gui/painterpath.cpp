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
  binder.ctors().add<const QPointF &>();
  // QPainterPath(const QPainterPath &);
  binder.ctors().add<const QPainterPath &>();
  // QPainterPath & operator=(const QPainterPath &);
  binder.operators().assign<const QPainterPath &>();
  // QPainterPath & operator=(QPainterPath &&);
  binder.operators().assign<QPainterPath &&>();
  // ~QPainterPath();
  binder.add_dtor();
  // void swap(QPainterPath &);
  binder.add_void_fun<QPainterPath &, &QPainterPath::swap>("swap");
  // void closeSubpath();
  binder.add_void_fun<&QPainterPath::closeSubpath>("closeSubpath");
  // void moveTo(const QPointF &);
  binder.add_void_fun<const QPointF &, &QPainterPath::moveTo>("moveTo");
  // void moveTo(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QPainterPath::moveTo>("moveTo");
  // void lineTo(const QPointF &);
  binder.add_void_fun<const QPointF &, &QPainterPath::lineTo>("lineTo");
  // void lineTo(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QPainterPath::lineTo>("lineTo");
  // void arcMoveTo(const QRectF &, qreal);
  binder.add_void_fun<const QRectF &, qreal, &QPainterPath::arcMoveTo>("arcMoveTo");
  // void arcMoveTo(qreal, qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, qreal, &QPainterPath::arcMoveTo>("arcMoveTo");
  // void arcTo(const QRectF &, qreal, qreal);
  binder.add_void_fun<const QRectF &, qreal, qreal, &QPainterPath::arcTo>("arcTo");
  // void arcTo(qreal, qreal, qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, qreal, qreal, &QPainterPath::arcTo>("arcTo");
  // void cubicTo(const QPointF &, const QPointF &, const QPointF &);
  binder.add_void_fun<const QPointF &, const QPointF &, const QPointF &, &QPainterPath::cubicTo>("cubicTo");
  // void cubicTo(qreal, qreal, qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, qreal, qreal, &QPainterPath::cubicTo>("cubicTo");
  // void quadTo(const QPointF &, const QPointF &);
  binder.add_void_fun<const QPointF &, const QPointF &, &QPainterPath::quadTo>("quadTo");
  // void quadTo(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QPainterPath::quadTo>("quadTo");
  // QPointF currentPosition() const;
  binder.add_fun<QPointF, &QPainterPath::currentPosition>("currentPosition");
  // void addRect(const QRectF &);
  binder.add_void_fun<const QRectF &, &QPainterPath::addRect>("addRect");
  // void addRect(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QPainterPath::addRect>("addRect");
  // void addEllipse(const QRectF &);
  binder.add_void_fun<const QRectF &, &QPainterPath::addEllipse>("addEllipse");
  // void addEllipse(qreal, qreal, qreal, qreal);
  binder.add_void_fun<qreal, qreal, qreal, qreal, &QPainterPath::addEllipse>("addEllipse");
  // void addEllipse(const QPointF &, qreal, qreal);
  binder.add_void_fun<const QPointF &, qreal, qreal, &QPainterPath::addEllipse>("addEllipse");
  // void addPolygon(const QPolygonF &);
  /// TODO: void addPolygon(const QPolygonF &);
  // void addText(const QPointF &, const QFont &, const QString &);
  binder.add_void_fun<const QPointF &, const QFont &, const QString &, &QPainterPath::addText>("addText");
  // void addText(qreal, qreal, const QFont &, const QString &);
  binder.add_void_fun<qreal, qreal, const QFont &, const QString &, &QPainterPath::addText>("addText");
  // void addPath(const QPainterPath &);
  binder.add_void_fun<const QPainterPath &, &QPainterPath::addPath>("addPath");
  // void addRegion(const QRegion &);
  binder.add_void_fun<const QRegion &, &QPainterPath::addRegion>("addRegion");
  // void addRoundedRect(const QRectF &, qreal, qreal, Qt::SizeMode);
  binder.add_void_fun<const QRectF &, qreal, qreal, Qt::SizeMode, &QPainterPath::addRoundedRect>("addRoundedRect");
  // void addRoundRect(const QRectF &, int, int);
  binder.add_void_fun<const QRectF &, int, int, &QPainterPath::addRoundRect>("addRoundRect");
  // void addRoundRect(qreal, qreal, qreal, qreal, int, int);
  binder.add_void_fun<qreal, qreal, qreal, qreal, int, int, &QPainterPath::addRoundRect>("addRoundRect");
  // void addRoundRect(const QRectF &, int);
  binder.add_void_fun<const QRectF &, int, &QPainterPath::addRoundRect>("addRoundRect");
  // void addRoundRect(qreal, qreal, qreal, qreal, int);
  binder.add_void_fun<qreal, qreal, qreal, qreal, int, &QPainterPath::addRoundRect>("addRoundRect");
  // void connectPath(const QPainterPath &);
  binder.add_void_fun<const QPainterPath &, &QPainterPath::connectPath>("connectPath");
  // bool contains(const QPointF &) const;
  binder.add_fun<bool, const QPointF &, &QPainterPath::contains>("contains");
  // bool contains(const QRectF &) const;
  binder.add_fun<bool, const QRectF &, &QPainterPath::contains>("contains");
  // bool intersects(const QRectF &) const;
  binder.add_fun<bool, const QRectF &, &QPainterPath::intersects>("intersects");
  // void translate(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QPainterPath::translate>("translate");
  // void translate(const QPointF &);
  binder.add_void_fun<const QPointF &, &QPainterPath::translate>("translate");
  // QPainterPath translated(qreal, qreal) const;
  binder.add_fun<QPainterPath, qreal, qreal, &QPainterPath::translated>("translated");
  // QPainterPath translated(const QPointF &) const;
  binder.add_fun<QPainterPath, const QPointF &, &QPainterPath::translated>("translated");
  // QRectF boundingRect() const;
  binder.add_fun<QRectF, &QPainterPath::boundingRect>("boundingRect");
  // QRectF controlPointRect() const;
  binder.add_fun<QRectF, &QPainterPath::controlPointRect>("controlPointRect");
  // Qt::FillRule fillRule() const;
  binder.add_fun<Qt::FillRule, &QPainterPath::fillRule>("fillRule");
  // void setFillRule(Qt::FillRule);
  binder.add_void_fun<Qt::FillRule, &QPainterPath::setFillRule>("setFillRule");
  // bool isEmpty() const;
  binder.add_fun<bool, &QPainterPath::isEmpty>("isEmpty");
  // QPainterPath toReversed() const;
  binder.add_fun<QPainterPath, &QPainterPath::toReversed>("toReversed");
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
  binder.add_fun<int, &QPainterPath::elementCount>("elementCount");
  // QPainterPath::Element elementAt(int) const;
  /// TODO: QPainterPath::Element elementAt(int) const;
  // void setElementPositionAt(int, qreal, qreal);
  binder.add_void_fun<int, qreal, qreal, &QPainterPath::setElementPositionAt>("setElementPositionAt");
  // qreal length() const;
  binder.add_fun<qreal, &QPainterPath::length>("length");
  // qreal percentAtLength(qreal) const;
  binder.add_fun<qreal, qreal, &QPainterPath::percentAtLength>("percentAtLength");
  // QPointF pointAtPercent(qreal) const;
  binder.add_fun<QPointF, qreal, &QPainterPath::pointAtPercent>("pointAtPercent");
  // qreal angleAtPercent(qreal) const;
  binder.add_fun<qreal, qreal, &QPainterPath::angleAtPercent>("angleAtPercent");
  // qreal slopeAtPercent(qreal) const;
  binder.add_fun<qreal, qreal, &QPainterPath::slopeAtPercent>("slopeAtPercent");
  // bool intersects(const QPainterPath &) const;
  binder.add_fun<bool, const QPainterPath &, &QPainterPath::intersects>("intersects");
  // bool contains(const QPainterPath &) const;
  binder.add_fun<bool, const QPainterPath &, &QPainterPath::contains>("contains");
  // QPainterPath united(const QPainterPath &) const;
  binder.add_fun<QPainterPath, const QPainterPath &, &QPainterPath::united>("united");
  // QPainterPath intersected(const QPainterPath &) const;
  binder.add_fun<QPainterPath, const QPainterPath &, &QPainterPath::intersected>("intersected");
  // QPainterPath subtracted(const QPainterPath &) const;
  binder.add_fun<QPainterPath, const QPainterPath &, &QPainterPath::subtracted>("subtracted");
  // QPainterPath subtractedInverted(const QPainterPath &) const;
  binder.add_fun<QPainterPath, const QPainterPath &, &QPainterPath::subtractedInverted>("subtractedInverted");
  // QPainterPath simplified() const;
  binder.add_fun<QPainterPath, &QPainterPath::simplified>("simplified");
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
  binder.ctors().add<const QPen &>();
  // ~QPainterPathStroker();
  binder.add_dtor();
  // void setWidth(qreal);
  binder.add_void_fun<qreal, &QPainterPathStroker::setWidth>("setWidth");
  // qreal width() const;
  binder.add_fun<qreal, &QPainterPathStroker::width>("width");
  // void setCapStyle(Qt::PenCapStyle);
  binder.add_void_fun<Qt::PenCapStyle, &QPainterPathStroker::setCapStyle>("setCapStyle");
  // Qt::PenCapStyle capStyle() const;
  binder.add_fun<Qt::PenCapStyle, &QPainterPathStroker::capStyle>("capStyle");
  // void setJoinStyle(Qt::PenJoinStyle);
  binder.add_void_fun<Qt::PenJoinStyle, &QPainterPathStroker::setJoinStyle>("setJoinStyle");
  // Qt::PenJoinStyle joinStyle() const;
  binder.add_fun<Qt::PenJoinStyle, &QPainterPathStroker::joinStyle>("joinStyle");
  // void setMiterLimit(qreal);
  binder.add_void_fun<qreal, &QPainterPathStroker::setMiterLimit>("setMiterLimit");
  // qreal miterLimit() const;
  binder.add_fun<qreal, &QPainterPathStroker::miterLimit>("miterLimit");
  // void setCurveThreshold(qreal);
  binder.add_void_fun<qreal, &QPainterPathStroker::setCurveThreshold>("setCurveThreshold");
  // qreal curveThreshold() const;
  binder.add_fun<qreal, &QPainterPathStroker::curveThreshold>("curveThreshold");
  // void setDashPattern(Qt::PenStyle);
  binder.add_void_fun<Qt::PenStyle, &QPainterPathStroker::setDashPattern>("setDashPattern");
  // void setDashPattern(const QVector<qreal> &);
  /// TODO: void setDashPattern(const QVector<qreal> &);
  // QVector<qreal> dashPattern() const;
  /// TODO: QVector<qreal> dashPattern() const;
  // void setDashOffset(qreal);
  binder.add_void_fun<qreal, &QPainterPathStroker::setDashOffset>("setDashOffset");
  // qreal dashOffset() const;
  binder.add_fun<qreal, &QPainterPathStroker::dashOffset>("dashOffset");
  // QPainterPath createStroke(const QPainterPath &) const;
  binder.add_fun<QPainterPath, const QPainterPath &, &QPainterPathStroker::createStroke>("createStroke");
}


void register_painterpath_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_painter_path_class(ns);
  register_painter_path_stroker_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QPainterPath &, QPainterPath &);
  binder.add_void_fun<QPainterPath &, QPainterPath &, &swap>("swap");
  // QDataStream & operator<<(QDataStream &, const QPainterPath &);
  binder.operators().put_to<QDataStream &, const QPainterPath &>();
  // QDataStream & operator>>(QDataStream &, QPainterPath &);
  binder.operators().read_from<QDataStream &, QPainterPath &>();
  // QDebug operator<<(QDebug, const QPainterPath &);
  /// TODO: QDebug operator<<(QDebug, const QPainterPath &);
}

