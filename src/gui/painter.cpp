// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/painter.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/enums.h"
#include "yasl/core/flags.h"

#include "yasl/core/enums.h"
#include "yasl/core/line.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/gui/brush.h"
#include "yasl/gui/color.h"
#include "yasl/gui/font.h"
#include "yasl/gui/fontinfo.h"
#include "yasl/gui/fontmetrics.h"
#include "yasl/gui/glyphrun.h"
#include "yasl/gui/image.h"
#include "yasl/gui/painter.h"
#include "yasl/gui/painterpath.h"
#include "yasl/gui/pen.h"
#include "yasl/gui/picture.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/region.h"
#include "yasl/gui/statictext.h"
#include "yasl/gui/textoption.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_painter_render_hint_enum(script::Class painter)
{
  using namespace script;

  Enum render_hint = painter.newEnum("RenderHint").setId(script::Type::QPainterRenderHint).get();

  register_qflags_type<QPainter::RenderHint>(painter, "RenderHints", script::Type::QPainterRenderHints);
  render_hint.addValue("Antialiasing", QPainter::Antialiasing);
  render_hint.addValue("TextAntialiasing", QPainter::TextAntialiasing);
  render_hint.addValue("SmoothPixmapTransform", QPainter::SmoothPixmapTransform);
  render_hint.addValue("HighQualityAntialiasing", QPainter::HighQualityAntialiasing);
  render_hint.addValue("NonCosmeticDefaultPen", QPainter::NonCosmeticDefaultPen);
  render_hint.addValue("Qt4CompatiblePainting", QPainter::Qt4CompatiblePainting);
}


static void register_painter_pixmap_fragment_hint_enum(script::Class painter)
{
  using namespace script;

  Enum pixmap_fragment_hint = painter.newEnum("PixmapFragmentHint").setId(script::Type::QPainterPixmapFragmentHint).get();

  register_qflags_type<QPainter::PixmapFragmentHint>(painter, "PixmapFragmentHints", script::Type::QPainterPixmapFragmentHints);
  pixmap_fragment_hint.addValue("OpaqueHint", QPainter::OpaqueHint);
}


static void register_painter_composition_mode_enum(script::Class painter)
{
  using namespace script;

  Enum composition_mode = painter.newEnum("CompositionMode").setId(script::Type::QPainterCompositionMode).get();

  composition_mode.addValue("CompositionMode_SourceOver", QPainter::CompositionMode_SourceOver);
  composition_mode.addValue("CompositionMode_DestinationOver", QPainter::CompositionMode_DestinationOver);
  composition_mode.addValue("CompositionMode_Clear", QPainter::CompositionMode_Clear);
  composition_mode.addValue("CompositionMode_Source", QPainter::CompositionMode_Source);
  composition_mode.addValue("CompositionMode_Destination", QPainter::CompositionMode_Destination);
  composition_mode.addValue("CompositionMode_SourceIn", QPainter::CompositionMode_SourceIn);
  composition_mode.addValue("CompositionMode_DestinationIn", QPainter::CompositionMode_DestinationIn);
  composition_mode.addValue("CompositionMode_SourceOut", QPainter::CompositionMode_SourceOut);
  composition_mode.addValue("CompositionMode_DestinationOut", QPainter::CompositionMode_DestinationOut);
  composition_mode.addValue("CompositionMode_SourceAtop", QPainter::CompositionMode_SourceAtop);
  composition_mode.addValue("CompositionMode_DestinationAtop", QPainter::CompositionMode_DestinationAtop);
  composition_mode.addValue("CompositionMode_Xor", QPainter::CompositionMode_Xor);
  composition_mode.addValue("CompositionMode_Plus", QPainter::CompositionMode_Plus);
  composition_mode.addValue("CompositionMode_Multiply", QPainter::CompositionMode_Multiply);
  composition_mode.addValue("CompositionMode_Screen", QPainter::CompositionMode_Screen);
  composition_mode.addValue("CompositionMode_Overlay", QPainter::CompositionMode_Overlay);
  composition_mode.addValue("CompositionMode_Darken", QPainter::CompositionMode_Darken);
  composition_mode.addValue("CompositionMode_Lighten", QPainter::CompositionMode_Lighten);
  composition_mode.addValue("CompositionMode_ColorDodge", QPainter::CompositionMode_ColorDodge);
  composition_mode.addValue("CompositionMode_ColorBurn", QPainter::CompositionMode_ColorBurn);
  composition_mode.addValue("CompositionMode_HardLight", QPainter::CompositionMode_HardLight);
  composition_mode.addValue("CompositionMode_SoftLight", QPainter::CompositionMode_SoftLight);
  composition_mode.addValue("CompositionMode_Difference", QPainter::CompositionMode_Difference);
  composition_mode.addValue("CompositionMode_Exclusion", QPainter::CompositionMode_Exclusion);
  composition_mode.addValue("RasterOp_SourceOrDestination", QPainter::RasterOp_SourceOrDestination);
  composition_mode.addValue("RasterOp_SourceAndDestination", QPainter::RasterOp_SourceAndDestination);
  composition_mode.addValue("RasterOp_SourceXorDestination", QPainter::RasterOp_SourceXorDestination);
  composition_mode.addValue("RasterOp_NotSourceAndNotDestination", QPainter::RasterOp_NotSourceAndNotDestination);
  composition_mode.addValue("RasterOp_NotSourceOrNotDestination", QPainter::RasterOp_NotSourceOrNotDestination);
  composition_mode.addValue("RasterOp_NotSourceXorDestination", QPainter::RasterOp_NotSourceXorDestination);
  composition_mode.addValue("RasterOp_NotSource", QPainter::RasterOp_NotSource);
  composition_mode.addValue("RasterOp_NotSourceAndDestination", QPainter::RasterOp_NotSourceAndDestination);
  composition_mode.addValue("RasterOp_SourceAndNotDestination", QPainter::RasterOp_SourceAndNotDestination);
  composition_mode.addValue("RasterOp_NotSourceOrDestination", QPainter::RasterOp_NotSourceOrDestination);
  composition_mode.addValue("RasterOp_SourceOrNotDestination", QPainter::RasterOp_SourceOrNotDestination);
  composition_mode.addValue("RasterOp_ClearDestination", QPainter::RasterOp_ClearDestination);
  composition_mode.addValue("RasterOp_SetDestination", QPainter::RasterOp_SetDestination);
  composition_mode.addValue("RasterOp_NotDestination", QPainter::RasterOp_NotDestination);
}


static void register_painter_class(script::Namespace ns)
{
  using namespace script;

  Class painter = ns.newClass("Painter").setId(script::Type::QPainter).get();

  register_painter_render_hint_enum(painter);
  register_painter_pixmap_fragment_hint_enum(painter);
  register_painter_composition_mode_enum(painter);

  // QPainter();
  bind::default_constructor<QPainter>(painter).create();
  // QPainter(QPaintDevice *);
  /// TODO: QPainter(QPaintDevice *);
  // ~QPainter();
  bind::destructor<QPainter>(painter).create();
  // QPaintDevice * device() const;
  /// TODO: QPaintDevice * device() const;
  // bool begin(QPaintDevice *);
  /// TODO: bool begin(QPaintDevice *);
  // bool end();
  bind::member_function<QPainter, bool, &QPainter::end>(painter, "end").create();
  // bool isActive() const;
  bind::member_function<QPainter, bool, &QPainter::isActive>(painter, "isActive").create();
  // void initFrom(const QPaintDevice *);
  /// TODO: void initFrom(const QPaintDevice *);
  // void setCompositionMode(QPainter::CompositionMode);
  bind::void_member_function<QPainter, QPainter::CompositionMode, &QPainter::setCompositionMode>(painter, "setCompositionMode").create();
  // QPainter::CompositionMode compositionMode() const;
  bind::member_function<QPainter, QPainter::CompositionMode, &QPainter::compositionMode>(painter, "compositionMode").create();
  // const QFont & font() const;
  bind::member_function<QPainter, const QFont &, &QPainter::font>(painter, "font").create();
  // void setFont(const QFont &);
  bind::void_member_function<QPainter, const QFont &, &QPainter::setFont>(painter, "setFont").create();
  // QFontMetrics fontMetrics() const;
  bind::member_function<QPainter, QFontMetrics, &QPainter::fontMetrics>(painter, "fontMetrics").create();
  // QFontInfo fontInfo() const;
  bind::member_function<QPainter, QFontInfo, &QPainter::fontInfo>(painter, "fontInfo").create();
  // void setPen(const QColor &);
  bind::void_member_function<QPainter, const QColor &, &QPainter::setPen>(painter, "setPen").create();
  // void setPen(const QPen &);
  bind::void_member_function<QPainter, const QPen &, &QPainter::setPen>(painter, "setPen").create();
  // void setPen(Qt::PenStyle);
  bind::void_member_function<QPainter, Qt::PenStyle, &QPainter::setPen>(painter, "setPen").create();
  // const QPen & pen() const;
  bind::member_function<QPainter, const QPen &, &QPainter::pen>(painter, "pen").create();
  // void setBrush(const QBrush &);
  bind::void_member_function<QPainter, const QBrush &, &QPainter::setBrush>(painter, "setBrush").create();
  // void setBrush(Qt::BrushStyle);
  bind::void_member_function<QPainter, Qt::BrushStyle, &QPainter::setBrush>(painter, "setBrush").create();
  // const QBrush & brush() const;
  bind::member_function<QPainter, const QBrush &, &QPainter::brush>(painter, "brush").create();
  // void setBackgroundMode(Qt::BGMode);
  bind::void_member_function<QPainter, Qt::BGMode, &QPainter::setBackgroundMode>(painter, "setBackgroundMode").create();
  // Qt::BGMode backgroundMode() const;
  bind::member_function<QPainter, Qt::BGMode, &QPainter::backgroundMode>(painter, "backgroundMode").create();
  // QPoint brushOrigin() const;
  bind::member_function<QPainter, QPoint, &QPainter::brushOrigin>(painter, "brushOrigin").create();
  // void setBrushOrigin(int, int);
  bind::void_member_function<QPainter, int, int, &QPainter::setBrushOrigin>(painter, "setBrushOrigin").create();
  // void setBrushOrigin(const QPoint &);
  bind::void_member_function<QPainter, const QPoint &, &QPainter::setBrushOrigin>(painter, "setBrushOrigin").create();
  // void setBrushOrigin(const QPointF &);
  bind::void_member_function<QPainter, const QPointF &, &QPainter::setBrushOrigin>(painter, "setBrushOrigin").create();
  // void setBackground(const QBrush &);
  bind::void_member_function<QPainter, const QBrush &, &QPainter::setBackground>(painter, "setBackground").create();
  // const QBrush & background() const;
  bind::member_function<QPainter, const QBrush &, &QPainter::background>(painter, "background").create();
  // qreal opacity() const;
  bind::member_function<QPainter, qreal, &QPainter::opacity>(painter, "opacity").create();
  // void setOpacity(qreal);
  bind::void_member_function<QPainter, qreal, &QPainter::setOpacity>(painter, "setOpacity").create();
  // QRegion clipRegion() const;
  bind::member_function<QPainter, QRegion, &QPainter::clipRegion>(painter, "clipRegion").create();
  // QPainterPath clipPath() const;
  bind::member_function<QPainter, QPainterPath, &QPainter::clipPath>(painter, "clipPath").create();
  // void setClipRect(const QRectF &, Qt::ClipOperation);
  bind::void_member_function<QPainter, const QRectF &, Qt::ClipOperation, &QPainter::setClipRect>(painter, "setClipRect")
    .apply(bind::default_arguments(Qt::ReplaceClip)).create();
  // void setClipRect(const QRect &, Qt::ClipOperation);
  bind::void_member_function<QPainter, const QRect &, Qt::ClipOperation, &QPainter::setClipRect>(painter, "setClipRect")
    .apply(bind::default_arguments(Qt::ReplaceClip)).create();
  // void setClipRect(int, int, int, int, Qt::ClipOperation);
  bind::void_member_function<QPainter, int, int, int, int, Qt::ClipOperation, &QPainter::setClipRect>(painter, "setClipRect")
    .apply(bind::default_arguments(Qt::ReplaceClip)).create();
  // void setClipRegion(const QRegion &, Qt::ClipOperation);
  bind::void_member_function<QPainter, const QRegion &, Qt::ClipOperation, &QPainter::setClipRegion>(painter, "setClipRegion")
    .apply(bind::default_arguments(Qt::ReplaceClip)).create();
  // void setClipPath(const QPainterPath &, Qt::ClipOperation);
  bind::void_member_function<QPainter, const QPainterPath &, Qt::ClipOperation, &QPainter::setClipPath>(painter, "setClipPath")
    .apply(bind::default_arguments(Qt::ReplaceClip)).create();
  // void setClipping(bool);
  bind::void_member_function<QPainter, bool, &QPainter::setClipping>(painter, "setClipping").create();
  // bool hasClipping() const;
  bind::member_function<QPainter, bool, &QPainter::hasClipping>(painter, "hasClipping").create();
  // QRectF clipBoundingRect() const;
  bind::member_function<QPainter, QRectF, &QPainter::clipBoundingRect>(painter, "clipBoundingRect").create();
  // void save();
  bind::void_member_function<QPainter, &QPainter::save>(painter, "save").create();
  // void restore();
  bind::void_member_function<QPainter, &QPainter::restore>(painter, "restore").create();
  // void setMatrix(const QMatrix &, bool);
  /// TODO: void setMatrix(const QMatrix &, bool);
  // const QMatrix & matrix() const;
  /// TODO: const QMatrix & matrix() const;
  // const QMatrix & deviceMatrix() const;
  /// TODO: const QMatrix & deviceMatrix() const;
  // void resetMatrix();
  bind::void_member_function<QPainter, &QPainter::resetMatrix>(painter, "resetMatrix").create();
  // void setTransform(const QTransform &, bool);
  bind::void_member_function<QPainter, const QTransform &, bool, &QPainter::setTransform>(painter, "setTransform")
    .apply(bind::default_arguments(false)).create();
  // const QTransform & transform() const;
  bind::member_function<QPainter, const QTransform &, &QPainter::transform>(painter, "transform").create();
  // const QTransform & deviceTransform() const;
  bind::member_function<QPainter, const QTransform &, &QPainter::deviceTransform>(painter, "deviceTransform").create();
  // void resetTransform();
  bind::void_member_function<QPainter, &QPainter::resetTransform>(painter, "resetTransform").create();
  // void setWorldMatrix(const QMatrix &, bool);
  /// TODO: void setWorldMatrix(const QMatrix &, bool);
  // const QMatrix & worldMatrix() const;
  /// TODO: const QMatrix & worldMatrix() const;
  // void setWorldTransform(const QTransform &, bool);
  bind::void_member_function<QPainter, const QTransform &, bool, &QPainter::setWorldTransform>(painter, "setWorldTransform")
    .apply(bind::default_arguments(false)).create();
  // const QTransform & worldTransform() const;
  bind::member_function<QPainter, const QTransform &, &QPainter::worldTransform>(painter, "worldTransform").create();
  // QMatrix combinedMatrix() const;
  /// TODO: QMatrix combinedMatrix() const;
  // QTransform combinedTransform() const;
  bind::member_function<QPainter, QTransform, &QPainter::combinedTransform>(painter, "combinedTransform").create();
  // void setMatrixEnabled(bool);
  bind::void_member_function<QPainter, bool, &QPainter::setMatrixEnabled>(painter, "setMatrixEnabled").create();
  // bool matrixEnabled() const;
  bind::member_function<QPainter, bool, &QPainter::matrixEnabled>(painter, "matrixEnabled").create();
  // void setWorldMatrixEnabled(bool);
  bind::void_member_function<QPainter, bool, &QPainter::setWorldMatrixEnabled>(painter, "setWorldMatrixEnabled").create();
  // bool worldMatrixEnabled() const;
  bind::member_function<QPainter, bool, &QPainter::worldMatrixEnabled>(painter, "worldMatrixEnabled").create();
  // void scale(qreal, qreal);
  bind::void_member_function<QPainter, qreal, qreal, &QPainter::scale>(painter, "scale").create();
  // void shear(qreal, qreal);
  bind::void_member_function<QPainter, qreal, qreal, &QPainter::shear>(painter, "shear").create();
  // void rotate(qreal);
  bind::void_member_function<QPainter, qreal, &QPainter::rotate>(painter, "rotate").create();
  // void translate(const QPointF &);
  bind::void_member_function<QPainter, const QPointF &, &QPainter::translate>(painter, "translate").create();
  // void translate(const QPoint &);
  bind::void_member_function<QPainter, const QPoint &, &QPainter::translate>(painter, "translate").create();
  // void translate(qreal, qreal);
  bind::void_member_function<QPainter, qreal, qreal, &QPainter::translate>(painter, "translate").create();
  // QRect window() const;
  bind::member_function<QPainter, QRect, &QPainter::window>(painter, "window").create();
  // void setWindow(const QRect &);
  bind::void_member_function<QPainter, const QRect &, &QPainter::setWindow>(painter, "setWindow").create();
  // void setWindow(int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, &QPainter::setWindow>(painter, "setWindow").create();
  // QRect viewport() const;
  bind::member_function<QPainter, QRect, &QPainter::viewport>(painter, "viewport").create();
  // void setViewport(const QRect &);
  bind::void_member_function<QPainter, const QRect &, &QPainter::setViewport>(painter, "setViewport").create();
  // void setViewport(int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, &QPainter::setViewport>(painter, "setViewport").create();
  // void setViewTransformEnabled(bool);
  bind::void_member_function<QPainter, bool, &QPainter::setViewTransformEnabled>(painter, "setViewTransformEnabled").create();
  // bool viewTransformEnabled() const;
  bind::member_function<QPainter, bool, &QPainter::viewTransformEnabled>(painter, "viewTransformEnabled").create();
  // void strokePath(const QPainterPath &, const QPen &);
  bind::void_member_function<QPainter, const QPainterPath &, const QPen &, &QPainter::strokePath>(painter, "strokePath").create();
  // void fillPath(const QPainterPath &, const QBrush &);
  bind::void_member_function<QPainter, const QPainterPath &, const QBrush &, &QPainter::fillPath>(painter, "fillPath").create();
  // void drawPath(const QPainterPath &);
  bind::void_member_function<QPainter, const QPainterPath &, &QPainter::drawPath>(painter, "drawPath").create();
  // void drawPoint(const QPointF &);
  bind::void_member_function<QPainter, const QPointF &, &QPainter::drawPoint>(painter, "drawPoint").create();
  // void drawPoint(const QPoint &);
  bind::void_member_function<QPainter, const QPoint &, &QPainter::drawPoint>(painter, "drawPoint").create();
  // void drawPoint(int, int);
  bind::void_member_function<QPainter, int, int, &QPainter::drawPoint>(painter, "drawPoint").create();
  // void drawPoints(const QPointF *, int);
  /// TODO: void drawPoints(const QPointF *, int);
  // void drawPoints(const QPolygonF &);
  /// TODO: void drawPoints(const QPolygonF &);
  // void drawPoints(const QPoint *, int);
  /// TODO: void drawPoints(const QPoint *, int);
  // void drawPoints(const QPolygon &);
  /// TODO: void drawPoints(const QPolygon &);
  // void drawLine(const QLineF &);
  bind::void_member_function<QPainter, const QLineF &, &QPainter::drawLine>(painter, "drawLine").create();
  // void drawLine(const QLine &);
  bind::void_member_function<QPainter, const QLine &, &QPainter::drawLine>(painter, "drawLine").create();
  // void drawLine(int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, &QPainter::drawLine>(painter, "drawLine").create();
  // void drawLine(const QPoint &, const QPoint &);
  bind::void_member_function<QPainter, const QPoint &, const QPoint &, &QPainter::drawLine>(painter, "drawLine").create();
  // void drawLine(const QPointF &, const QPointF &);
  bind::void_member_function<QPainter, const QPointF &, const QPointF &, &QPainter::drawLine>(painter, "drawLine").create();
  // void drawLines(const QLineF *, int);
  /// TODO: void drawLines(const QLineF *, int);
  // void drawLines(const QVector<QLineF> &);
  /// TODO: void drawLines(const QVector<QLineF> &);
  // void drawLines(const QPointF *, int);
  /// TODO: void drawLines(const QPointF *, int);
  // void drawLines(const QVector<QPointF> &);
  /// TODO: void drawLines(const QVector<QPointF> &);
  // void drawLines(const QLine *, int);
  /// TODO: void drawLines(const QLine *, int);
  // void drawLines(const QVector<QLine> &);
  /// TODO: void drawLines(const QVector<QLine> &);
  // void drawLines(const QPoint *, int);
  /// TODO: void drawLines(const QPoint *, int);
  // void drawLines(const QVector<QPoint> &);
  /// TODO: void drawLines(const QVector<QPoint> &);
  // void drawRect(const QRectF &);
  bind::void_member_function<QPainter, const QRectF &, &QPainter::drawRect>(painter, "drawRect").create();
  // void drawRect(int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, &QPainter::drawRect>(painter, "drawRect").create();
  // void drawRect(const QRect &);
  bind::void_member_function<QPainter, const QRect &, &QPainter::drawRect>(painter, "drawRect").create();
  // void drawRects(const QRectF *, int);
  /// TODO: void drawRects(const QRectF *, int);
  // void drawRects(const QVector<QRectF> &);
  /// TODO: void drawRects(const QVector<QRectF> &);
  // void drawRects(const QRect *, int);
  /// TODO: void drawRects(const QRect *, int);
  // void drawRects(const QVector<QRect> &);
  /// TODO: void drawRects(const QVector<QRect> &);
  // void drawEllipse(const QRectF &);
  bind::void_member_function<QPainter, const QRectF &, &QPainter::drawEllipse>(painter, "drawEllipse").create();
  // void drawEllipse(const QRect &);
  bind::void_member_function<QPainter, const QRect &, &QPainter::drawEllipse>(painter, "drawEllipse").create();
  // void drawEllipse(int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, &QPainter::drawEllipse>(painter, "drawEllipse").create();
  // void drawEllipse(const QPointF &, qreal, qreal);
  bind::void_member_function<QPainter, const QPointF &, qreal, qreal, &QPainter::drawEllipse>(painter, "drawEllipse").create();
  // void drawEllipse(const QPoint &, int, int);
  bind::void_member_function<QPainter, const QPoint &, int, int, &QPainter::drawEllipse>(painter, "drawEllipse").create();
  // void drawPolyline(const QPointF *, int);
  /// TODO: void drawPolyline(const QPointF *, int);
  // void drawPolyline(const QPolygonF &);
  /// TODO: void drawPolyline(const QPolygonF &);
  // void drawPolyline(const QPoint *, int);
  /// TODO: void drawPolyline(const QPoint *, int);
  // void drawPolyline(const QPolygon &);
  /// TODO: void drawPolyline(const QPolygon &);
  // void drawPolygon(const QPointF *, int, Qt::FillRule);
  /// TODO: void drawPolygon(const QPointF *, int, Qt::FillRule);
  // void drawPolygon(const QPolygonF &, Qt::FillRule);
  /// TODO: void drawPolygon(const QPolygonF &, Qt::FillRule);
  // void drawPolygon(const QPoint *, int, Qt::FillRule);
  /// TODO: void drawPolygon(const QPoint *, int, Qt::FillRule);
  // void drawPolygon(const QPolygon &, Qt::FillRule);
  /// TODO: void drawPolygon(const QPolygon &, Qt::FillRule);
  // void drawConvexPolygon(const QPointF *, int);
  /// TODO: void drawConvexPolygon(const QPointF *, int);
  // void drawConvexPolygon(const QPolygonF &);
  /// TODO: void drawConvexPolygon(const QPolygonF &);
  // void drawConvexPolygon(const QPoint *, int);
  /// TODO: void drawConvexPolygon(const QPoint *, int);
  // void drawConvexPolygon(const QPolygon &);
  /// TODO: void drawConvexPolygon(const QPolygon &);
  // void drawArc(const QRectF &, int, int);
  bind::void_member_function<QPainter, const QRectF &, int, int, &QPainter::drawArc>(painter, "drawArc").create();
  // void drawArc(const QRect &, int, int);
  bind::void_member_function<QPainter, const QRect &, int, int, &QPainter::drawArc>(painter, "drawArc").create();
  // void drawArc(int, int, int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, int, int, &QPainter::drawArc>(painter, "drawArc").create();
  // void drawPie(const QRectF &, int, int);
  bind::void_member_function<QPainter, const QRectF &, int, int, &QPainter::drawPie>(painter, "drawPie").create();
  // void drawPie(int, int, int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, int, int, &QPainter::drawPie>(painter, "drawPie").create();
  // void drawPie(const QRect &, int, int);
  bind::void_member_function<QPainter, const QRect &, int, int, &QPainter::drawPie>(painter, "drawPie").create();
  // void drawChord(const QRectF &, int, int);
  bind::void_member_function<QPainter, const QRectF &, int, int, &QPainter::drawChord>(painter, "drawChord").create();
  // void drawChord(int, int, int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, int, int, &QPainter::drawChord>(painter, "drawChord").create();
  // void drawChord(const QRect &, int, int);
  bind::void_member_function<QPainter, const QRect &, int, int, &QPainter::drawChord>(painter, "drawChord").create();
  // void drawRoundedRect(const QRectF &, qreal, qreal, Qt::SizeMode);
  bind::void_member_function<QPainter, const QRectF &, qreal, qreal, Qt::SizeMode, &QPainter::drawRoundedRect>(painter, "drawRoundedRect")
    .apply(bind::default_arguments(Qt::AbsoluteSize)).create();
  // void drawRoundedRect(const QRect &, qreal, qreal, Qt::SizeMode);
  bind::void_member_function<QPainter, const QRect &, qreal, qreal, Qt::SizeMode, &QPainter::drawRoundedRect>(painter, "drawRoundedRect")
    .apply(bind::default_arguments(Qt::AbsoluteSize)).create();
  // void drawRoundRect(const QRectF &, int, int);
  bind::void_member_function<QPainter, const QRectF &, int, int, &QPainter::drawRoundRect>(painter, "drawRoundRect").create();
  // void drawRoundRect(int, int, int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, int, int, &QPainter::drawRoundRect>(painter, "drawRoundRect").create();
  // void drawRoundRect(const QRect &, int, int);
  bind::void_member_function<QPainter, const QRect &, int, int, &QPainter::drawRoundRect>(painter, "drawRoundRect").create();
  // void drawTiledPixmap(const QRectF &, const QPixmap &, const QPointF &);
  bind::void_member_function<QPainter, const QRectF &, const QPixmap &, const QPointF &, &QPainter::drawTiledPixmap>(painter, "drawTiledPixmap")
    .apply(bind::default_arguments(QPointF())).create();
  // void drawTiledPixmap(const QRect &, const QPixmap &, const QPoint &);
  bind::void_member_function<QPainter, const QRect &, const QPixmap &, const QPoint &, &QPainter::drawTiledPixmap>(painter, "drawTiledPixmap")
    .apply(bind::default_arguments(QPoint())).create();
  // void drawPicture(const QPointF &, const QPicture &);
  bind::void_member_function<QPainter, const QPointF &, const QPicture &, &QPainter::drawPicture>(painter, "drawPicture").create();
  // void drawPicture(int, int, const QPicture &);
  bind::void_member_function<QPainter, int, int, const QPicture &, &QPainter::drawPicture>(painter, "drawPicture").create();
  // void drawPicture(const QPoint &, const QPicture &);
  bind::void_member_function<QPainter, const QPoint &, const QPicture &, &QPainter::drawPicture>(painter, "drawPicture").create();
  // void drawPixmap(const QRectF &, const QPixmap &, const QRectF &);
  bind::void_member_function<QPainter, const QRectF &, const QPixmap &, const QRectF &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmap(const QRect &, const QPixmap &, const QRect &);
  bind::void_member_function<QPainter, const QRect &, const QPixmap &, const QRect &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmap(const QPointF &, const QPixmap &, const QRectF &);
  bind::void_member_function<QPainter, const QPointF &, const QPixmap &, const QRectF &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmap(const QPoint &, const QPixmap &, const QRect &);
  bind::void_member_function<QPainter, const QPoint &, const QPixmap &, const QRect &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmap(const QPointF &, const QPixmap &);
  bind::void_member_function<QPainter, const QPointF &, const QPixmap &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmap(const QPoint &, const QPixmap &);
  bind::void_member_function<QPainter, const QPoint &, const QPixmap &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmap(int, int, const QPixmap &);
  bind::void_member_function<QPainter, int, int, const QPixmap &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmap(const QRect &, const QPixmap &);
  bind::void_member_function<QPainter, const QRect &, const QPixmap &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmap(int, int, int, int, const QPixmap &);
  bind::void_member_function<QPainter, int, int, int, int, const QPixmap &, &QPainter::drawPixmap>(painter, "drawPixmap").create();
  // void drawPixmapFragments(const QPainter::PixmapFragment *, int, const QPixmap &, QPainter::PixmapFragmentHints);
  /// TODO: void drawPixmapFragments(const QPainter::PixmapFragment *, int, const QPixmap &, QPainter::PixmapFragmentHints);
  // void drawImage(const QRectF &, const QImage &, const QRectF &, Qt::ImageConversionFlags);
  bind::void_member_function<QPainter, const QRectF &, const QImage &, const QRectF &, Qt::ImageConversionFlags, &QPainter::drawImage>(painter, "drawImage")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // void drawImage(const QRect &, const QImage &, const QRect &, Qt::ImageConversionFlags);
  bind::void_member_function<QPainter, const QRect &, const QImage &, const QRect &, Qt::ImageConversionFlags, &QPainter::drawImage>(painter, "drawImage")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // void drawImage(const QPointF &, const QImage &, const QRectF &, Qt::ImageConversionFlags);
  bind::void_member_function<QPainter, const QPointF &, const QImage &, const QRectF &, Qt::ImageConversionFlags, &QPainter::drawImage>(painter, "drawImage")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // void drawImage(const QPoint &, const QImage &, const QRect &, Qt::ImageConversionFlags);
  bind::void_member_function<QPainter, const QPoint &, const QImage &, const QRect &, Qt::ImageConversionFlags, &QPainter::drawImage>(painter, "drawImage")
    .apply(bind::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // void drawImage(const QRectF &, const QImage &);
  bind::void_member_function<QPainter, const QRectF &, const QImage &, &QPainter::drawImage>(painter, "drawImage").create();
  // void drawImage(const QRect &, const QImage &);
  bind::void_member_function<QPainter, const QRect &, const QImage &, &QPainter::drawImage>(painter, "drawImage").create();
  // void drawImage(const QPointF &, const QImage &);
  bind::void_member_function<QPainter, const QPointF &, const QImage &, &QPainter::drawImage>(painter, "drawImage").create();
  // void drawImage(const QPoint &, const QImage &);
  bind::void_member_function<QPainter, const QPoint &, const QImage &, &QPainter::drawImage>(painter, "drawImage").create();
  // void setLayoutDirection(Qt::LayoutDirection);
  bind::void_member_function<QPainter, Qt::LayoutDirection, &QPainter::setLayoutDirection>(painter, "setLayoutDirection").create();
  // Qt::LayoutDirection layoutDirection() const;
  bind::member_function<QPainter, Qt::LayoutDirection, &QPainter::layoutDirection>(painter, "layoutDirection").create();
  // void drawGlyphRun(const QPointF &, const QGlyphRun &);
  bind::void_member_function<QPainter, const QPointF &, const QGlyphRun &, &QPainter::drawGlyphRun>(painter, "drawGlyphRun").create();
  // void drawStaticText(const QPointF &, const QStaticText &);
  bind::void_member_function<QPainter, const QPointF &, const QStaticText &, &QPainter::drawStaticText>(painter, "drawStaticText").create();
  // void drawStaticText(const QPoint &, const QStaticText &);
  bind::void_member_function<QPainter, const QPoint &, const QStaticText &, &QPainter::drawStaticText>(painter, "drawStaticText").create();
  // void drawStaticText(int, int, const QStaticText &);
  bind::void_member_function<QPainter, int, int, const QStaticText &, &QPainter::drawStaticText>(painter, "drawStaticText").create();
  // void drawText(const QPointF &, const QString &);
  bind::void_member_function<QPainter, const QPointF &, const QString &, &QPainter::drawText>(painter, "drawText").create();
  // void drawText(const QPoint &, const QString &);
  bind::void_member_function<QPainter, const QPoint &, const QString &, &QPainter::drawText>(painter, "drawText").create();
  // void drawText(int, int, const QString &);
  bind::void_member_function<QPainter, int, int, const QString &, &QPainter::drawText>(painter, "drawText").create();
  // void drawText(const QPointF &, const QString &, int, int);
  bind::void_member_function<QPainter, const QPointF &, const QString &, int, int, &QPainter::drawText>(painter, "drawText").create();
  // void drawText(const QRectF &, int, const QString &, QRectF *);
  /// TODO: void drawText(const QRectF &, int, const QString &, QRectF *);
  // void drawText(const QRect &, int, const QString &, QRect *);
  /// TODO: void drawText(const QRect &, int, const QString &, QRect *);
  // void drawText(int, int, int, int, int, const QString &, QRect *);
  /// TODO: void drawText(int, int, int, int, int, const QString &, QRect *);
  // void drawText(const QRectF &, const QString &, const QTextOption &);
  bind::void_member_function<QPainter, const QRectF &, const QString &, const QTextOption &, &QPainter::drawText>(painter, "drawText")
    .apply(bind::default_arguments(QTextOption())).create();
  // QRectF boundingRect(const QRectF &, int, const QString &);
  bind::member_function<QPainter, QRectF, const QRectF &, int, const QString &, &QPainter::boundingRect>(painter, "boundingRect").create();
  // QRect boundingRect(const QRect &, int, const QString &);
  bind::member_function<QPainter, QRect, const QRect &, int, const QString &, &QPainter::boundingRect>(painter, "boundingRect").create();
  // QRect boundingRect(int, int, int, int, int, const QString &);
  bind::member_function<QPainter, QRect, int, int, int, int, int, const QString &, &QPainter::boundingRect>(painter, "boundingRect").create();
  // QRectF boundingRect(const QRectF &, const QString &, const QTextOption &);
  bind::member_function<QPainter, QRectF, const QRectF &, const QString &, const QTextOption &, &QPainter::boundingRect>(painter, "boundingRect")
    .apply(bind::default_arguments(QTextOption())).create();
  // void drawTextItem(const QPointF &, const QTextItem &);
  /// TODO: void drawTextItem(const QPointF &, const QTextItem &);
  // void drawTextItem(int, int, const QTextItem &);
  /// TODO: void drawTextItem(int, int, const QTextItem &);
  // void drawTextItem(const QPoint &, const QTextItem &);
  /// TODO: void drawTextItem(const QPoint &, const QTextItem &);
  // void fillRect(const QRectF &, const QBrush &);
  bind::void_member_function<QPainter, const QRectF &, const QBrush &, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(int, int, int, int, const QBrush &);
  bind::void_member_function<QPainter, int, int, int, int, const QBrush &, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(const QRect &, const QBrush &);
  bind::void_member_function<QPainter, const QRect &, const QBrush &, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(const QRectF &, const QColor &);
  bind::void_member_function<QPainter, const QRectF &, const QColor &, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(int, int, int, int, const QColor &);
  bind::void_member_function<QPainter, int, int, int, int, const QColor &, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(const QRect &, const QColor &);
  bind::void_member_function<QPainter, const QRect &, const QColor &, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(int, int, int, int, Qt::GlobalColor);
  bind::void_member_function<QPainter, int, int, int, int, Qt::GlobalColor, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(const QRect &, Qt::GlobalColor);
  bind::void_member_function<QPainter, const QRect &, Qt::GlobalColor, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(const QRectF &, Qt::GlobalColor);
  bind::void_member_function<QPainter, const QRectF &, Qt::GlobalColor, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(int, int, int, int, Qt::BrushStyle);
  bind::void_member_function<QPainter, int, int, int, int, Qt::BrushStyle, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(const QRect &, Qt::BrushStyle);
  bind::void_member_function<QPainter, const QRect &, Qt::BrushStyle, &QPainter::fillRect>(painter, "fillRect").create();
  // void fillRect(const QRectF &, Qt::BrushStyle);
  bind::void_member_function<QPainter, const QRectF &, Qt::BrushStyle, &QPainter::fillRect>(painter, "fillRect").create();
  // void eraseRect(const QRectF &);
  bind::void_member_function<QPainter, const QRectF &, &QPainter::eraseRect>(painter, "eraseRect").create();
  // void eraseRect(int, int, int, int);
  bind::void_member_function<QPainter, int, int, int, int, &QPainter::eraseRect>(painter, "eraseRect").create();
  // void eraseRect(const QRect &);
  bind::void_member_function<QPainter, const QRect &, &QPainter::eraseRect>(painter, "eraseRect").create();
  // void setRenderHint(QPainter::RenderHint, bool);
  bind::void_member_function<QPainter, QPainter::RenderHint, bool, &QPainter::setRenderHint>(painter, "setRenderHint").create();
  // void setRenderHints(QPainter::RenderHints, bool);
  bind::void_member_function<QPainter, QPainter::RenderHints, bool, &QPainter::setRenderHints>(painter, "setRenderHints").create();
  // QPainter::RenderHints renderHints() const;
  bind::member_function<QPainter, QPainter::RenderHints, &QPainter::renderHints>(painter, "renderHints").create();
  // bool testRenderHint(QPainter::RenderHint) const;
  bind::member_function<QPainter, bool, QPainter::RenderHint, &QPainter::testRenderHint>(painter, "testRenderHint").create();
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // static void setRedirected(const QPaintDevice *, QPaintDevice *, const QPoint &);
  /// TODO: static void setRedirected(const QPaintDevice *, QPaintDevice *, const QPoint &);
  // static QPaintDevice * redirected(const QPaintDevice *, QPoint *);
  /// TODO: static QPaintDevice * redirected(const QPaintDevice *, QPoint *);
  // static void restoreRedirected(const QPaintDevice *);
  /// TODO: static void restoreRedirected(const QPaintDevice *);
  // void beginNativePainting();
  bind::void_member_function<QPainter, &QPainter::beginNativePainting>(painter, "beginNativePainting").create();
  // void endNativePainting();
  bind::void_member_function<QPainter, &QPainter::endNativePainting>(painter, "endNativePainting").create();
}


void register_painter_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_painter_class(ns);

  // QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QPainter::RenderHints::enum_type);
  /// TODO: QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QPainter::RenderHints::enum_type);
  // QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QFlags<QPainter::RenderHints::enum_type>);
  /// TODO: QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QFlags<QPainter::RenderHints::enum_type>);
  // QIncompatibleFlag operator|(QPainter::RenderHints::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QPainter::RenderHints::enum_type, int);
}

