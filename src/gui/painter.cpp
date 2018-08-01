// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/painter.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/enums.h"
#include "yasl/core/flags.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"

#include "yasl/gui/brush.h"
#include "yasl/gui/color.h"
#include "yasl/gui/font.h"
#include "yasl/gui/fontinfo.h"
#include "yasl/gui/fontmetrics.h"
#include "yasl/gui/glyphrun.h"
#include "yasl/gui/image.h"
#include "yasl/gui/paintdevice.h"
#include "yasl/gui/painterpath.h"
#include "yasl/gui/pen.h"
#include "yasl/gui/picture.h"
#include "yasl/gui/pixmap.h"
#include "yasl/gui/polygon.h"
#include "yasl/gui/region.h"
#include "yasl/gui/statictext.h"
#include "yasl/gui/textitem.h"
#include "yasl/gui/textoption.h"
#include "yasl/gui/transform.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

static void register_painter_composition_mode_enum(script::Class painter)
{
  using namespace script;

  Enum composition_mode = painter.Enum("CompositionMode").setId(script::Type::QPainterCompositionMode).get();

  composition_mode.addValue("CompositionMode_Clear", QPainter::CompositionMode_Clear);
  composition_mode.addValue("CompositionMode_ColorBurn", QPainter::CompositionMode_ColorBurn);
  composition_mode.addValue("CompositionMode_ColorDodge", QPainter::CompositionMode_ColorDodge);
  composition_mode.addValue("CompositionMode_Darken", QPainter::CompositionMode_Darken);
  composition_mode.addValue("CompositionMode_Destination", QPainter::CompositionMode_Destination);
  composition_mode.addValue("CompositionMode_DestinationAtop", QPainter::CompositionMode_DestinationAtop);
  composition_mode.addValue("CompositionMode_DestinationIn", QPainter::CompositionMode_DestinationIn);
  composition_mode.addValue("CompositionMode_DestinationOut", QPainter::CompositionMode_DestinationOut);
  composition_mode.addValue("CompositionMode_DestinationOver", QPainter::CompositionMode_DestinationOver);
  composition_mode.addValue("CompositionMode_Difference", QPainter::CompositionMode_Difference);
  composition_mode.addValue("CompositionMode_Exclusion", QPainter::CompositionMode_Exclusion);
  composition_mode.addValue("CompositionMode_HardLight", QPainter::CompositionMode_HardLight);
  composition_mode.addValue("CompositionMode_Lighten", QPainter::CompositionMode_Lighten);
  composition_mode.addValue("CompositionMode_Multiply", QPainter::CompositionMode_Multiply);
  composition_mode.addValue("CompositionMode_Overlay", QPainter::CompositionMode_Overlay);
  composition_mode.addValue("CompositionMode_Plus", QPainter::CompositionMode_Plus);
  composition_mode.addValue("CompositionMode_Screen", QPainter::CompositionMode_Screen);
  composition_mode.addValue("CompositionMode_SoftLight", QPainter::CompositionMode_SoftLight);
  composition_mode.addValue("CompositionMode_Source", QPainter::CompositionMode_Source);
  composition_mode.addValue("CompositionMode_SourceAtop", QPainter::CompositionMode_SourceAtop);
  composition_mode.addValue("CompositionMode_SourceIn", QPainter::CompositionMode_SourceIn);
  composition_mode.addValue("CompositionMode_SourceOut", QPainter::CompositionMode_SourceOut);
  composition_mode.addValue("CompositionMode_SourceOver", QPainter::CompositionMode_SourceOver);
  composition_mode.addValue("CompositionMode_Xor", QPainter::CompositionMode_Xor);
  composition_mode.addValue("RasterOp_ClearDestination", QPainter::RasterOp_ClearDestination);
  composition_mode.addValue("RasterOp_NotDestination", QPainter::RasterOp_NotDestination);
  composition_mode.addValue("RasterOp_NotSource", QPainter::RasterOp_NotSource);
  composition_mode.addValue("RasterOp_NotSourceAndDestination", QPainter::RasterOp_NotSourceAndDestination);
  composition_mode.addValue("RasterOp_NotSourceAndNotDestination", QPainter::RasterOp_NotSourceAndNotDestination);
  composition_mode.addValue("RasterOp_NotSourceOrDestination", QPainter::RasterOp_NotSourceOrDestination);
  composition_mode.addValue("RasterOp_NotSourceOrNotDestination", QPainter::RasterOp_NotSourceOrNotDestination);
  composition_mode.addValue("RasterOp_NotSourceXorDestination", QPainter::RasterOp_NotSourceXorDestination);
  composition_mode.addValue("RasterOp_SetDestination", QPainter::RasterOp_SetDestination);
  composition_mode.addValue("RasterOp_SourceAndDestination", QPainter::RasterOp_SourceAndDestination);
  composition_mode.addValue("RasterOp_SourceAndNotDestination", QPainter::RasterOp_SourceAndNotDestination);
  composition_mode.addValue("RasterOp_SourceOrDestination", QPainter::RasterOp_SourceOrDestination);
  composition_mode.addValue("RasterOp_SourceOrNotDestination", QPainter::RasterOp_SourceOrNotDestination);
  composition_mode.addValue("RasterOp_SourceXorDestination", QPainter::RasterOp_SourceXorDestination);
}

static void register_painter_pixmap_fragment_hint_enum(script::Class painter)
{
  using namespace script;

  Enum pixmap_fragment_hint = painter.Enum("PixmapFragmentHint").setId(script::Type::QPainterPixmapFragmentHint).get();

  pixmap_fragment_hint.addValue("OpaqueHint", QPainter::OpaqueHint);

  register_qflags_type<QPainter::PixmapFragmentHint>(painter, "PixmapFragmentHints", Type::QPainterPixmapFragmentHints);
}

static void register_painter_render_hint_enum(script::Class painter)
{
  using namespace script;

  Enum render_hint = painter.Enum("RenderHint").setId(script::Type::QPainterRenderHint).get();

  render_hint.addValue("Antialiasing", QPainter::Antialiasing);
  render_hint.addValue("HighQualityAntialiasing", QPainter::HighQualityAntialiasing);
  render_hint.addValue("NonCosmeticDefaultPen", QPainter::NonCosmeticDefaultPen);
  render_hint.addValue("Qt4CompatiblePainting", QPainter::Qt4CompatiblePainting);
  render_hint.addValue("SmoothPixmapTransform", QPainter::SmoothPixmapTransform);
  render_hint.addValue("TextAntialiasing", QPainter::TextAntialiasing);

  register_qflags_type<QPainter::RenderHint>(painter, "RenderHint", Type::QPainterRenderHints);
}

static void register_painter_class(script::Namespace ns)
{
  using namespace script;

  Class painter = ns.Class("Painter").setId(script::Type::QPainter).get();

  register_painter_composition_mode_enum(painter);
  register_painter_pixmap_fragment_hint_enum(painter);
  register_painter_render_hint_enum(painter);
  binding::Class<QPainter> binder{ painter };

  // ~QPainter();
  binder.add_dtor();
  // QPainter();
  binder.ctors().add_default();
  // QPainter(QPaintDevice *);
  binder.ctors().add<QPaintDevice *>();
  // QPaintDevice * device() const;
  binder.add_fun<QPaintDevice *, &QPainter::device>("device");
  // bool begin(QPaintDevice *);
  binder.add_fun<bool, QPaintDevice *, &QPainter::begin>("begin");
  // bool end();
  binder.add_fun<bool, &QPainter::end>("end");
  // bool isActive() const;
  binder.add_fun<bool, &QPainter::isActive>("isActive");
  // void initFrom(const QPaintDevice *);
  binder.add_void_fun<const QPaintDevice *, &QPainter::initFrom>("initFrom");
  // void setCompositionMode(QPainter::CompositionMode);
  binder.add_void_fun<QPainter::CompositionMode, &QPainter::setCompositionMode>("setCompositionMode");
  // QPainter::CompositionMode compositionMode() const;
  binder.add_fun<QPainter::CompositionMode, &QPainter::compositionMode>("compositionMode");
  // const QFont & font() const;
  binder.add_fun<const QFont &, &QPainter::font>("font");
  // void setFont(const QFont &);
  binder.add_void_fun<const QFont &, &QPainter::setFont>("setFont");
  // QFontMetrics fontMetrics() const;
  binder.add_fun<QFontMetrics, &QPainter::fontMetrics>("fontMetrics");
  // QFontInfo fontInfo() const;
  binder.add_fun<QFontInfo, &QPainter::fontInfo>("fontInfo");
  // void setPen(const QColor &);
  binder.add_void_fun<const QColor &, &QPainter::setPen>("setPen");
  // void setPen(const QPen &);
  binder.add_void_fun<const QPen &, &QPainter::setPen>("setPen");
  // void setPen(Qt::PenStyle);
  binder.add_void_fun<Qt::PenStyle, &QPainter::setPen>("setPen");
  // const QPen & pen() const;
  binder.add_fun<const QPen &, &QPainter::pen>("pen");
  // void setBrush(const QBrush &);
  binder.add_void_fun<const QBrush &, &QPainter::setBrush>("setBrush");
  // void setBrush(Qt::BrushStyle);
  binder.add_void_fun<Qt::BrushStyle, &QPainter::setBrush>("setBrush");
  // const QBrush & brush() const;
  binder.add_fun<const QBrush &, &QPainter::brush>("brush");
  // void setBackgroundMode(Qt::BGMode);
  binder.add_void_fun<Qt::BGMode, &QPainter::setBackgroundMode>("setBackgroundMode");
  // Qt::BGMode backgroundMode() const;
  binder.add_fun<Qt::BGMode, &QPainter::backgroundMode>("backgroundMode");
  // QPoint brushOrigin() const;
  binder.add_fun<QPoint, &QPainter::brushOrigin>("brushOrigin");
  // void setBrushOrigin(int, int);
  binder.add_void_fun<int, int, &QPainter::setBrushOrigin>("setBrushOrigin");
  // void setBrushOrigin(const QPoint &);
  binder.add_void_fun<const QPoint &, &QPainter::setBrushOrigin>("setBrushOrigin");
  // void setBrushOrigin(const QPointF &);
  binder.add_void_fun<const QPointF &, &QPainter::setBrushOrigin>("setBrushOrigin");
  // void setBackground(const QBrush &);
  binder.add_void_fun<const QBrush &, &QPainter::setBackground>("setBackground");
  // const QBrush & background() const;
  binder.add_fun<const QBrush &, &QPainter::background>("background");
  // qreal opacity() const;
  binder.add_fun<qreal, &QPainter::opacity>("opacity");
  // void setOpacity(qreal);
  binder.add_void_fun<qreal, &QPainter::setOpacity>("setOpacity");
  // QRegion clipRegion() const;
  binder.add_fun<QRegion, &QPainter::clipRegion>("clipRegion");
  // QPainterPath clipPath() const;
  binder.add_fun<QPainterPath, &QPainter::clipPath>("clipPath");
  // void setClipRect(const QRectF &, Qt::ClipOperation);
  binder.add_void_fun<const QRectF &, Qt::ClipOperation, &QPainter::setClipRect>("setClipRect");
  // void setClipRect(const QRect &, Qt::ClipOperation);
  binder.add_void_fun<const QRect &, Qt::ClipOperation, &QPainter::setClipRect>("setClipRect");
  // void setClipRect(int, int, int, int, Qt::ClipOperation);
  binder.add_void_fun<int, int, int, int, Qt::ClipOperation, &QPainter::setClipRect>("setClipRect");
  // void setClipRegion(const QRegion &, Qt::ClipOperation);
  binder.add_void_fun<const QRegion &, Qt::ClipOperation, &QPainter::setClipRegion>("setClipRegion");
  // void setClipPath(const QPainterPath &, Qt::ClipOperation);
  binder.add_void_fun<const QPainterPath &, Qt::ClipOperation, &QPainter::setClipPath>("setClipPath");
  // void setClipping(bool);
  binder.add_void_fun<bool, &QPainter::setClipping>("setClipping");
  // bool hasClipping() const;
  binder.add_fun<bool, &QPainter::hasClipping>("hasClipping");
  // QRectF clipBoundingRect() const;
  binder.add_fun<QRectF, &QPainter::clipBoundingRect>("clipBoundingRect");
  // void save();
  binder.add_void_fun<&QPainter::save>("save");
  // void restore();
  binder.add_void_fun<&QPainter::restore>("restore");
  // void setMatrix(const QMatrix &, bool);
  /// ignore: binder.add_void_fun<const QMatrix &, bool, &QPainter::setMatrix>("setMatrix");
  // const QMatrix & matrix() const;
  /// ignore: binder.add_fun<const QMatrix &, &QPainter::matrix>("matrix");
  // const QMatrix & deviceMatrix() const;
  /// ignore: binder.add_fun<const QMatrix &, &QPainter::deviceMatrix>("deviceMatrix");
  // void resetMatrix();
  /// ignore: binder.add_void_fun<&QPainter::resetMatrix>("resetMatrix");
  // void setTransform(const QTransform &, bool);
  binder.add_void_fun<const QTransform &, bool, &QPainter::setTransform>("setTransform");
  // const QTransform & transform() const;
  binder.add_fun<const QTransform &, &QPainter::transform>("transform");
  // const QTransform & deviceTransform() const;
  binder.add_fun<const QTransform &, &QPainter::deviceTransform>("deviceTransform");
  // void resetTransform();
  binder.add_void_fun<&QPainter::resetTransform>("resetTransform");
  // void setWorldMatrix(const QMatrix &, bool);
  /// ignore: binder.add_void_fun<const QMatrix &, bool, &QPainter::setWorldMatrix>("setWorldMatrix");
  // const QMatrix & worldMatrix() const;
  /// ignore: binder.add_fun<const QMatrix &, &QPainter::worldMatrix>("worldMatrix");
  // void setWorldTransform(const QTransform &, bool);
  binder.add_void_fun<const QTransform &, bool, &QPainter::setWorldTransform>("setWorldTransform");
  // const QTransform & worldTransform() const;
  binder.add_fun<const QTransform &, &QPainter::worldTransform>("worldTransform");
  // QMatrix combinedMatrix() const;
  /// ignore: binder.add_fun<QMatrix, &QPainter::combinedMatrix>("combinedMatrix");
  // QTransform combinedTransform() const;
  binder.add_fun<QTransform, &QPainter::combinedTransform>("combinedTransform");
  // void setMatrixEnabled(bool);
  binder.add_void_fun<bool, &QPainter::setMatrixEnabled>("setMatrixEnabled");
  // bool matrixEnabled() const;
  binder.add_fun<bool, &QPainter::matrixEnabled>("matrixEnabled");
  // void setWorldMatrixEnabled(bool);
  binder.add_void_fun<bool, &QPainter::setWorldMatrixEnabled>("setWorldMatrixEnabled");
  // bool worldMatrixEnabled() const;
  binder.add_fun<bool, &QPainter::worldMatrixEnabled>("worldMatrixEnabled");
  // void scale(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QPainter::scale>("scale");
  // void shear(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QPainter::shear>("shear");
  // void rotate(qreal);
  binder.add_void_fun<qreal, &QPainter::rotate>("rotate");
  // void translate(const QPointF &);
  binder.add_void_fun<const QPointF &, &QPainter::translate>("translate");
  // void translate(const QPoint &);
  binder.add_void_fun<const QPoint &, &QPainter::translate>("translate");
  // void translate(qreal, qreal);
  binder.add_void_fun<qreal, qreal, &QPainter::translate>("translate");
  // QRect window() const;
  binder.add_fun<QRect, &QPainter::window>("window");
  // void setWindow(const QRect &);
  binder.add_void_fun<const QRect &, &QPainter::setWindow>("setWindow");
  // void setWindow(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QPainter::setWindow>("setWindow");
  // QRect viewport() const;
  binder.add_fun<QRect, &QPainter::viewport>("viewport");
  // void setViewport(const QRect &);
  binder.add_void_fun<const QRect &, &QPainter::setViewport>("setViewport");
  // void setViewport(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QPainter::setViewport>("setViewport");
  // void setViewTransformEnabled(bool);
  binder.add_void_fun<bool, &QPainter::setViewTransformEnabled>("setViewTransformEnabled");
  // bool viewTransformEnabled() const;
  binder.add_fun<bool, &QPainter::viewTransformEnabled>("viewTransformEnabled");
  // void strokePath(const QPainterPath &, const QPen &);
  binder.add_void_fun<const QPainterPath &, const QPen &, &QPainter::strokePath>("strokePath");
  // void fillPath(const QPainterPath &, const QBrush &);
  binder.add_void_fun<const QPainterPath &, const QBrush &, &QPainter::fillPath>("fillPath");
  // void drawPath(const QPainterPath &);
  binder.add_void_fun<const QPainterPath &, &QPainter::drawPath>("drawPath");
  // void drawPoint(const QPointF &);
  binder.add_void_fun<const QPointF &, &QPainter::drawPoint>("drawPoint");
  // void drawPoint(const QPoint &);
  binder.add_void_fun<const QPoint &, &QPainter::drawPoint>("drawPoint");
  // void drawPoint(int, int);
  binder.add_void_fun<int, int, &QPainter::drawPoint>("drawPoint");
  // void drawPoints(const QPointF *, int);
  binder.add_void_fun<const QPointF *, int, &QPainter::drawPoints>("drawPoints");
  // void drawPoints(const QPolygonF &);
  binder.add_void_fun<const QPolygonF &, &QPainter::drawPoints>("drawPoints");
  // void drawPoints(const QPoint *, int);
  binder.add_void_fun<const QPoint *, int, &QPainter::drawPoints>("drawPoints");
  // void drawPoints(const QPolygon &);
  binder.add_void_fun<const QPolygon &, &QPainter::drawPoints>("drawPoints");
  // void drawLine(const QLineF &);
  binder.add_void_fun<const QLineF &, &QPainter::drawLine>("drawLine");
  // void drawLine(const QLine &);
  binder.add_void_fun<const QLine &, &QPainter::drawLine>("drawLine");
  // void drawLine(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QPainter::drawLine>("drawLine");
  // void drawLine(const QPoint &, const QPoint &);
  binder.add_void_fun<const QPoint &, const QPoint &, &QPainter::drawLine>("drawLine");
  // void drawLine(const QPointF &, const QPointF &);
  binder.add_void_fun<const QPointF &, const QPointF &, &QPainter::drawLine>("drawLine");
  // void drawLines(const QLineF *, int);
  binder.add_void_fun<const QLineF *, int, &QPainter::drawLines>("drawLines");
  // void drawLines(const QVector<QLineF> &);
  binder.add_void_fun<const QVector<QLineF> &, &QPainter::drawLines>("drawLines");
  // void drawLines(const QPointF *, int);
  binder.add_void_fun<const QPointF *, int, &QPainter::drawLines>("drawLines");
  // void drawLines(const QVector<QPointF> &);
  binder.add_void_fun<const QVector<QPointF> &, &QPainter::drawLines>("drawLines");
  // void drawLines(const QLine *, int);
  binder.add_void_fun<const QLine *, int, &QPainter::drawLines>("drawLines");
  // void drawLines(const QVector<QLine> &);
  binder.add_void_fun<const QVector<QLine> &, &QPainter::drawLines>("drawLines");
  // void drawLines(const QPoint *, int);
  binder.add_void_fun<const QPoint *, int, &QPainter::drawLines>("drawLines");
  // void drawLines(const QVector<QPoint> &);
  binder.add_void_fun<const QVector<QPoint> &, &QPainter::drawLines>("drawLines");
  // void drawRect(const QRectF &);
  binder.add_void_fun<const QRectF &, &QPainter::drawRect>("drawRect");
  // void drawRect(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QPainter::drawRect>("drawRect");
  // void drawRect(const QRect &);
  binder.add_void_fun<const QRect &, &QPainter::drawRect>("drawRect");
  // void drawRects(const QRectF *, int);
  binder.add_void_fun<const QRectF *, int, &QPainter::drawRects>("drawRects");
  // void drawRects(const QVector<QRectF> &);
  binder.add_void_fun<const QVector<QRectF> &, &QPainter::drawRects>("drawRects");
  // void drawRects(const QRect *, int);
  binder.add_void_fun<const QRect *, int, &QPainter::drawRects>("drawRects");
  // void drawRects(const QVector<QRect> &);
  binder.add_void_fun<const QVector<QRect> &, &QPainter::drawRects>("drawRects");
  // void drawEllipse(const QRectF &);
  binder.add_void_fun<const QRectF &, &QPainter::drawEllipse>("drawEllipse");
  // void drawEllipse(const QRect &);
  binder.add_void_fun<const QRect &, &QPainter::drawEllipse>("drawEllipse");
  // void drawEllipse(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QPainter::drawEllipse>("drawEllipse");
  // void drawEllipse(const QPointF &, qreal, qreal);
  binder.add_void_fun<const QPointF &, qreal, qreal, &QPainter::drawEllipse>("drawEllipse");
  // void drawEllipse(const QPoint &, int, int);
  binder.add_void_fun<const QPoint &, int, int, &QPainter::drawEllipse>("drawEllipse");
  // void drawPolyline(const QPointF *, int);
  binder.add_void_fun<const QPointF *, int, &QPainter::drawPolyline>("drawPolyline");
  // void drawPolyline(const QPolygonF &);
  binder.add_void_fun<const QPolygonF &, &QPainter::drawPolyline>("drawPolyline");
  // void drawPolyline(const QPoint *, int);
  binder.add_void_fun<const QPoint *, int, &QPainter::drawPolyline>("drawPolyline");
  // void drawPolyline(const QPolygon &);
  binder.add_void_fun<const QPolygon &, &QPainter::drawPolyline>("drawPolyline");
  // void drawPolygon(const QPointF *, int, Qt::FillRule);
  binder.add_void_fun<const QPointF *, int, Qt::FillRule, &QPainter::drawPolygon>("drawPolygon");
  // void drawPolygon(const QPolygonF &, Qt::FillRule);
  binder.add_void_fun<const QPolygonF &, Qt::FillRule, &QPainter::drawPolygon>("drawPolygon");
  // void drawPolygon(const QPoint *, int, Qt::FillRule);
  binder.add_void_fun<const QPoint *, int, Qt::FillRule, &QPainter::drawPolygon>("drawPolygon");
  // void drawPolygon(const QPolygon &, Qt::FillRule);
  binder.add_void_fun<const QPolygon &, Qt::FillRule, &QPainter::drawPolygon>("drawPolygon");
  // void drawConvexPolygon(const QPointF *, int);
  binder.add_void_fun<const QPointF *, int, &QPainter::drawConvexPolygon>("drawConvexPolygon");
  // void drawConvexPolygon(const QPolygonF &);
  binder.add_void_fun<const QPolygonF &, &QPainter::drawConvexPolygon>("drawConvexPolygon");
  // void drawConvexPolygon(const QPoint *, int);
  binder.add_void_fun<const QPoint *, int, &QPainter::drawConvexPolygon>("drawConvexPolygon");
  // void drawConvexPolygon(const QPolygon &);
  binder.add_void_fun<const QPolygon &, &QPainter::drawConvexPolygon>("drawConvexPolygon");
  // void drawArc(const QRectF &, int, int);
  binder.add_void_fun<const QRectF &, int, int, &QPainter::drawArc>("drawArc");
  // void drawArc(const QRect &, int, int);
  binder.add_void_fun<const QRect &, int, int, &QPainter::drawArc>("drawArc");
  // void drawArc(int, int, int, int, int, int);
  binder.add_void_fun<int, int, int, int, int, int, &QPainter::drawArc>("drawArc");
  // void drawPie(const QRectF &, int, int);
  binder.add_void_fun<const QRectF &, int, int, &QPainter::drawPie>("drawPie");
  // void drawPie(int, int, int, int, int, int);
  binder.add_void_fun<int, int, int, int, int, int, &QPainter::drawPie>("drawPie");
  // void drawPie(const QRect &, int, int);
  binder.add_void_fun<const QRect &, int, int, &QPainter::drawPie>("drawPie");
  // void drawChord(const QRectF &, int, int);
  binder.add_void_fun<const QRectF &, int, int, &QPainter::drawChord>("drawChord");
  // void drawChord(int, int, int, int, int, int);
  binder.add_void_fun<int, int, int, int, int, int, &QPainter::drawChord>("drawChord");
  // void drawChord(const QRect &, int, int);
  binder.add_void_fun<const QRect &, int, int, &QPainter::drawChord>("drawChord");
  // void drawRoundedRect(const QRectF &, qreal, qreal, Qt::SizeMode);
  binder.add_void_fun<const QRectF &, qreal, qreal, Qt::SizeMode, &QPainter::drawRoundedRect>("drawRoundedRect");
  // void drawRoundedRect(int, int, int, int, qreal, qreal, Qt::SizeMode);
  /// TODO: binder.add_void_fun<int, int, int, int, qreal, qreal, Qt::SizeMode, &QPainter::drawRoundedRect>("drawRoundedRect");
  // void drawRoundedRect(const QRect &, qreal, qreal, Qt::SizeMode);
  binder.add_void_fun<const QRect &, qreal, qreal, Qt::SizeMode, &QPainter::drawRoundedRect>("drawRoundedRect");
  // void drawRoundRect(const QRectF &, int, int);
  binder.add_void_fun<const QRectF &, int, int, &QPainter::drawRoundRect>("drawRoundRect");
  // void drawRoundRect(int, int, int, int, int, int);
  binder.add_void_fun<int, int, int, int, int, int, &QPainter::drawRoundRect>("drawRoundRect");
  // void drawRoundRect(const QRect &, int, int);
  binder.add_void_fun<const QRect &, int, int, &QPainter::drawRoundRect>("drawRoundRect");
  // void drawTiledPixmap(const QRectF &, const QPixmap &, const QPointF &);
  binder.add_void_fun<const QRectF &, const QPixmap &, const QPointF &, &QPainter::drawTiledPixmap>("drawTiledPixmap");
  // void drawTiledPixmap(int, int, int, int, const QPixmap &, int, int);
  /// TODO: binder.add_void_fun<int, int, int, int, const QPixmap &, int, int, &QPainter::drawTiledPixmap>("drawTiledPixmap");
  // void drawTiledPixmap(const QRect &, const QPixmap &, const QPoint &);
  binder.add_void_fun<const QRect &, const QPixmap &, const QPoint &, &QPainter::drawTiledPixmap>("drawTiledPixmap");
  // void drawPicture(const QPointF &, const QPicture &);
  binder.add_void_fun<const QPointF &, const QPicture &, &QPainter::drawPicture>("drawPicture");
  // void drawPicture(int, int, const QPicture &);
  binder.add_void_fun<int, int, const QPicture &, &QPainter::drawPicture>("drawPicture");
  // void drawPicture(const QPoint &, const QPicture &);
  binder.add_void_fun<const QPoint &, const QPicture &, &QPainter::drawPicture>("drawPicture");
  // void drawPixmap(const QRectF &, const QPixmap &, const QRectF &);
  binder.add_void_fun<const QRectF &, const QPixmap &, const QRectF &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(const QRect &, const QPixmap &, const QRect &);
  binder.add_void_fun<const QRect &, const QPixmap &, const QRect &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(int, int, int, int, const QPixmap &, int, int, int, int);
  /// TODO: binder.add_void_fun<int, int, int, int, const QPixmap &, int, int, int, int, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(int, int, const QPixmap &, int, int, int, int);
  /// TODO: binder.add_void_fun<int, int, const QPixmap &, int, int, int, int, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(const QPointF &, const QPixmap &, const QRectF &);
  binder.add_void_fun<const QPointF &, const QPixmap &, const QRectF &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(const QPoint &, const QPixmap &, const QRect &);
  binder.add_void_fun<const QPoint &, const QPixmap &, const QRect &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(const QPointF &, const QPixmap &);
  binder.add_void_fun<const QPointF &, const QPixmap &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(const QPoint &, const QPixmap &);
  binder.add_void_fun<const QPoint &, const QPixmap &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(int, int, const QPixmap &);
  binder.add_void_fun<int, int, const QPixmap &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(const QRect &, const QPixmap &);
  binder.add_void_fun<const QRect &, const QPixmap &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmap(int, int, int, int, const QPixmap &);
  binder.add_void_fun<int, int, int, int, const QPixmap &, &QPainter::drawPixmap>("drawPixmap");
  // void drawPixmapFragments(const QPainter::PixmapFragment *, int, const QPixmap &, QPainter::PixmapFragmentHints);
  binder.add_void_fun<const QPainter::PixmapFragment *, int, const QPixmap &, QPainter::PixmapFragmentHints, &QPainter::drawPixmapFragments>("drawPixmapFragments");
  // void drawImage(const QRectF &, const QImage &, const QRectF &, Qt::ImageConversionFlags);
  binder.add_void_fun<const QRectF &, const QImage &, const QRectF &, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage");
  // void drawImage(const QRect &, const QImage &, const QRect &, Qt::ImageConversionFlags);
  binder.add_void_fun<const QRect &, const QImage &, const QRect &, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage");
  // void drawImage(const QPointF &, const QImage &, const QRectF &, Qt::ImageConversionFlags);
  binder.add_void_fun<const QPointF &, const QImage &, const QRectF &, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage");
  // void drawImage(const QPoint &, const QImage &, const QRect &, Qt::ImageConversionFlags);
  binder.add_void_fun<const QPoint &, const QImage &, const QRect &, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage");
  // void drawImage(const QRectF &, const QImage &);
  binder.add_void_fun<const QRectF &, const QImage &, &QPainter::drawImage>("drawImage");
  // void drawImage(const QRect &, const QImage &);
  binder.add_void_fun<const QRect &, const QImage &, &QPainter::drawImage>("drawImage");
  // void drawImage(const QPointF &, const QImage &);
  binder.add_void_fun<const QPointF &, const QImage &, &QPainter::drawImage>("drawImage");
  // void drawImage(const QPoint &, const QImage &);
  binder.add_void_fun<const QPoint &, const QImage &, &QPainter::drawImage>("drawImage");
  // void drawImage(int, int, const QImage &, int, int, int, int, Qt::ImageConversionFlags);
  /// TODO: binder.add_void_fun<int, int, const QImage &, int, int, int, int, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage");
  // void setLayoutDirection(Qt::LayoutDirection);
  binder.add_void_fun<Qt::LayoutDirection, &QPainter::setLayoutDirection>("setLayoutDirection");
  // Qt::LayoutDirection layoutDirection() const;
  binder.add_fun<Qt::LayoutDirection, &QPainter::layoutDirection>("layoutDirection");
  // void drawGlyphRun(const QPointF &, const QGlyphRun &);
  binder.add_void_fun<const QPointF &, const QGlyphRun &, &QPainter::drawGlyphRun>("drawGlyphRun");
  // void drawStaticText(const QPointF &, const QStaticText &);
  binder.add_void_fun<const QPointF &, const QStaticText &, &QPainter::drawStaticText>("drawStaticText");
  // void drawStaticText(const QPoint &, const QStaticText &);
  binder.add_void_fun<const QPoint &, const QStaticText &, &QPainter::drawStaticText>("drawStaticText");
  // void drawStaticText(int, int, const QStaticText &);
  binder.add_void_fun<int, int, const QStaticText &, &QPainter::drawStaticText>("drawStaticText");
  // void drawText(const QPointF &, const QString &);
  binder.add_void_fun<const QPointF &, const QString &, &QPainter::drawText>("drawText");
  // void drawText(const QPoint &, const QString &);
  binder.add_void_fun<const QPoint &, const QString &, &QPainter::drawText>("drawText");
  // void drawText(int, int, const QString &);
  binder.add_void_fun<int, int, const QString &, &QPainter::drawText>("drawText");
  // void drawText(const QPointF &, const QString &, int, int);
  binder.add_void_fun<const QPointF &, const QString &, int, int, &QPainter::drawText>("drawText");
  // void drawText(const QRectF &, int, const QString &, QRectF *);
  binder.add_void_fun<const QRectF &, int, const QString &, QRectF *, &QPainter::drawText>("drawText");
  // void drawText(const QRect &, int, const QString &, QRect *);
  binder.add_void_fun<const QRect &, int, const QString &, QRect *, &QPainter::drawText>("drawText");
  // void drawText(int, int, int, int, int, const QString &, QRect *);
  /// TODO: binder.add_void_fun<int, int, int, int, int, const QString &, QRect *, &QPainter::drawText>("drawText");
  // void drawText(const QRectF &, const QString &, const QTextOption &);
  binder.add_void_fun<const QRectF &, const QString &, const QTextOption &, &QPainter::drawText>("drawText");
  // QRectF boundingRect(const QRectF &, int, const QString &);
  binder.add_fun<QRectF, const QRectF &, int, const QString &, &QPainter::boundingRect>("boundingRect");
  // QRect boundingRect(const QRect &, int, const QString &);
  binder.add_fun<QRect, const QRect &, int, const QString &, &QPainter::boundingRect>("boundingRect");
  // QRect boundingRect(int, int, int, int, int, const QString &);
  binder.add_fun<QRect, int, int, int, int, int, const QString &, &QPainter::boundingRect>("boundingRect");
  // QRectF boundingRect(const QRectF &, const QString &, const QTextOption &);
  binder.add_fun<QRectF, const QRectF &, const QString &, const QTextOption &, &QPainter::boundingRect>("boundingRect");
  // void drawTextItem(const QPointF &, const QTextItem &);
  binder.add_void_fun<const QPointF &, const QTextItem &, &QPainter::drawTextItem>("drawTextItem");
  // void drawTextItem(int, int, const QTextItem &);
  binder.add_void_fun<int, int, const QTextItem &, &QPainter::drawTextItem>("drawTextItem");
  // void drawTextItem(const QPoint &, const QTextItem &);
  binder.add_void_fun<const QPoint &, const QTextItem &, &QPainter::drawTextItem>("drawTextItem");
  // void fillRect(const QRectF &, const QBrush &);
  binder.add_void_fun<const QRectF &, const QBrush &, &QPainter::fillRect>("fillRect");
  // void fillRect(int, int, int, int, const QBrush &);
  binder.add_void_fun<int, int, int, int, const QBrush &, &QPainter::fillRect>("fillRect");
  // void fillRect(const QRect &, const QBrush &);
  binder.add_void_fun<const QRect &, const QBrush &, &QPainter::fillRect>("fillRect");
  // void fillRect(const QRectF &, const QColor &);
  binder.add_void_fun<const QRectF &, const QColor &, &QPainter::fillRect>("fillRect");
  // void fillRect(int, int, int, int, const QColor &);
  binder.add_void_fun<int, int, int, int, const QColor &, &QPainter::fillRect>("fillRect");
  // void fillRect(const QRect &, const QColor &);
  binder.add_void_fun<const QRect &, const QColor &, &QPainter::fillRect>("fillRect");
  // void fillRect(int, int, int, int, Qt::GlobalColor);
  binder.add_void_fun<int, int, int, int, Qt::GlobalColor, &QPainter::fillRect>("fillRect");
  // void fillRect(const QRect &, Qt::GlobalColor);
  binder.add_void_fun<const QRect &, Qt::GlobalColor, &QPainter::fillRect>("fillRect");
  // void fillRect(const QRectF &, Qt::GlobalColor);
  binder.add_void_fun<const QRectF &, Qt::GlobalColor, &QPainter::fillRect>("fillRect");
  // void fillRect(int, int, int, int, Qt::BrushStyle);
  binder.add_void_fun<int, int, int, int, Qt::BrushStyle, &QPainter::fillRect>("fillRect");
  // void fillRect(const QRect &, Qt::BrushStyle);
  binder.add_void_fun<const QRect &, Qt::BrushStyle, &QPainter::fillRect>("fillRect");
  // void fillRect(const QRectF &, Qt::BrushStyle);
  binder.add_void_fun<const QRectF &, Qt::BrushStyle, &QPainter::fillRect>("fillRect");
  // void eraseRect(const QRectF &);
  binder.add_void_fun<const QRectF &, &QPainter::eraseRect>("eraseRect");
  // void eraseRect(int, int, int, int);
  binder.add_void_fun<int, int, int, int, &QPainter::eraseRect>("eraseRect");
  // void eraseRect(const QRect &);
  binder.add_void_fun<const QRect &, &QPainter::eraseRect>("eraseRect");
  // void setRenderHint(QPainter::RenderHint, bool);
  binder.add_void_fun<QPainter::RenderHint, bool, &QPainter::setRenderHint>("setRenderHint");
  // void setRenderHints(QPainter::RenderHints, bool);
  binder.add_void_fun<QPainter::RenderHints, bool, &QPainter::setRenderHints>("setRenderHints");
  // QPainter::RenderHints renderHints() const;
  binder.add_fun<QPainter::RenderHints, &QPainter::renderHints>("renderHints");
  // bool testRenderHint(QPainter::RenderHint) const;
  binder.add_fun<bool, QPainter::RenderHint, &QPainter::testRenderHint>("testRenderHint");
  // QPaintEngine * paintEngine() const;
  binder.add_fun<QPaintEngine *, &QPainter::paintEngine>("paintEngine");
  // static void setRedirected(const QPaintDevice *, QPaintDevice *, const QPoint &);
  binder.add_static_void_fun<const QPaintDevice *, QPaintDevice *, const QPoint &, &QPainter::setRedirected>("setRedirected");
  // static QPaintDevice * redirected(const QPaintDevice *, QPoint *);
  binder.add_static<QPaintDevice *, const QPaintDevice *, QPoint *, &QPainter::redirected>("redirected");
  // static void restoreRedirected(const QPaintDevice *);
  binder.add_static_void_fun<const QPaintDevice *, &QPainter::restoreRedirected>("restoreRedirected");
  // void beginNativePainting();
  binder.add_void_fun<&QPainter::beginNativePainting>("beginNativePainting");
  // void endNativePainting();
  binder.add_void_fun<&QPainter::endNativePainting>("endNativePainting");
}

void register_painter_file(script::Namespace root)
{
  using namespace script;

  register_painter_class(root);
  binding::Namespace binder{ root };

  // QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QPainter::RenderHints::enum_type);
  binder.operators().or<QFlags<QPainter::RenderHints::enum_type>, QPainter::RenderHints::enum_type, QPainter::RenderHints::enum_type>();
  // QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QFlags<QPainter::RenderHints::enum_type>);
  binder.operators().or<QFlags<QPainter::RenderHints::enum_type>, QPainter::RenderHints::enum_type, QFlags<QPainter::RenderHints::enum_type>>();
  // QIncompatibleFlag operator|(QPainter::RenderHints::enum_type, int);
  binder.operators().or<QIncompatibleFlag, QPainter::RenderHints::enum_type, int>();
}

