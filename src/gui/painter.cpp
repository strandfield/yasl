// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/painter.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
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

  Enum render_hint = painter.Enum("RenderHint").setId(script::Type::QPainterRenderHint).get();

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

  Enum pixmap_fragment_hint = painter.Enum("PixmapFragmentHint").setId(script::Type::QPainterPixmapFragmentHint).get();

  register_qflags_type<QPainter::PixmapFragmentHint>(painter, "PixmapFragmentHints", script::Type::QPainterPixmapFragmentHints);
  pixmap_fragment_hint.addValue("OpaqueHint", QPainter::OpaqueHint);
}


static void register_painter_composition_mode_enum(script::Class painter)
{
  using namespace script;

  Enum composition_mode = painter.Enum("CompositionMode").setId(script::Type::QPainterCompositionMode).get();

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

  Class painter = ns.Class("Painter").setId(script::Type::QPainter).get();

  register_painter_render_hint_enum(painter);
  register_painter_pixmap_fragment_hint_enum(painter);
  register_painter_composition_mode_enum(painter);
  binding::ClassBinder<QPainter> binder{ painter };

  // QPainter();
  binder.default_ctor().create();
  // QPainter(QPaintDevice *);
  /// TODO: QPainter(QPaintDevice *);
  // ~QPainter();
  binder.dtor().create();
  // QPaintDevice * device() const;
  /// TODO: QPaintDevice * device() const;
  // bool begin(QPaintDevice *);
  /// TODO: bool begin(QPaintDevice *);
  // bool end();
  binder.fun<bool, &QPainter::end>("end").create();
  // bool isActive() const;
  binder.fun<bool, &QPainter::isActive>("isActive").create();
  // void initFrom(const QPaintDevice *);
  /// TODO: void initFrom(const QPaintDevice *);
  // void setCompositionMode(QPainter::CompositionMode);
  binder.void_fun<QPainter::CompositionMode, &QPainter::setCompositionMode>("setCompositionMode").create();
  // QPainter::CompositionMode compositionMode() const;
  binder.fun<QPainter::CompositionMode, &QPainter::compositionMode>("compositionMode").create();
  // const QFont & font() const;
  binder.fun<const QFont &, &QPainter::font>("font").create();
  // void setFont(const QFont &);
  binder.void_fun<const QFont &, &QPainter::setFont>("setFont").create();
  // QFontMetrics fontMetrics() const;
  binder.fun<QFontMetrics, &QPainter::fontMetrics>("fontMetrics").create();
  // QFontInfo fontInfo() const;
  binder.fun<QFontInfo, &QPainter::fontInfo>("fontInfo").create();
  // void setPen(const QColor &);
  binder.void_fun<const QColor &, &QPainter::setPen>("setPen").create();
  // void setPen(const QPen &);
  binder.void_fun<const QPen &, &QPainter::setPen>("setPen").create();
  // void setPen(Qt::PenStyle);
  binder.void_fun<Qt::PenStyle, &QPainter::setPen>("setPen").create();
  // const QPen & pen() const;
  binder.fun<const QPen &, &QPainter::pen>("pen").create();
  // void setBrush(const QBrush &);
  binder.void_fun<const QBrush &, &QPainter::setBrush>("setBrush").create();
  // void setBrush(Qt::BrushStyle);
  binder.void_fun<Qt::BrushStyle, &QPainter::setBrush>("setBrush").create();
  // const QBrush & brush() const;
  binder.fun<const QBrush &, &QPainter::brush>("brush").create();
  // void setBackgroundMode(Qt::BGMode);
  binder.void_fun<Qt::BGMode, &QPainter::setBackgroundMode>("setBackgroundMode").create();
  // Qt::BGMode backgroundMode() const;
  binder.fun<Qt::BGMode, &QPainter::backgroundMode>("backgroundMode").create();
  // QPoint brushOrigin() const;
  binder.fun<QPoint, &QPainter::brushOrigin>("brushOrigin").create();
  // void setBrushOrigin(int, int);
  binder.void_fun<int, int, &QPainter::setBrushOrigin>("setBrushOrigin").create();
  // void setBrushOrigin(const QPoint &);
  binder.void_fun<const QPoint &, &QPainter::setBrushOrigin>("setBrushOrigin").create();
  // void setBrushOrigin(const QPointF &);
  binder.void_fun<const QPointF &, &QPainter::setBrushOrigin>("setBrushOrigin").create();
  // void setBackground(const QBrush &);
  binder.void_fun<const QBrush &, &QPainter::setBackground>("setBackground").create();
  // const QBrush & background() const;
  binder.fun<const QBrush &, &QPainter::background>("background").create();
  // qreal opacity() const;
  binder.fun<qreal, &QPainter::opacity>("opacity").create();
  // void setOpacity(qreal);
  binder.void_fun<qreal, &QPainter::setOpacity>("setOpacity").create();
  // QRegion clipRegion() const;
  binder.fun<QRegion, &QPainter::clipRegion>("clipRegion").create();
  // QPainterPath clipPath() const;
  binder.fun<QPainterPath, &QPainter::clipPath>("clipPath").create();
  // void setClipRect(const QRectF &, Qt::ClipOperation);
  binder.void_fun<const QRectF &, Qt::ClipOperation, &QPainter::setClipRect>("setClipRect")
    .apply(binding::default_arguments(Qt::ReplaceClip)).create();
  // void setClipRect(const QRect &, Qt::ClipOperation);
  binder.void_fun<const QRect &, Qt::ClipOperation, &QPainter::setClipRect>("setClipRect")
    .apply(binding::default_arguments(Qt::ReplaceClip)).create();
  // void setClipRect(int, int, int, int, Qt::ClipOperation);
  binder.void_fun<int, int, int, int, Qt::ClipOperation, &QPainter::setClipRect>("setClipRect")
    .apply(binding::default_arguments(Qt::ReplaceClip)).create();
  // void setClipRegion(const QRegion &, Qt::ClipOperation);
  binder.void_fun<const QRegion &, Qt::ClipOperation, &QPainter::setClipRegion>("setClipRegion")
    .apply(binding::default_arguments(Qt::ReplaceClip)).create();
  // void setClipPath(const QPainterPath &, Qt::ClipOperation);
  binder.void_fun<const QPainterPath &, Qt::ClipOperation, &QPainter::setClipPath>("setClipPath")
    .apply(binding::default_arguments(Qt::ReplaceClip)).create();
  // void setClipping(bool);
  binder.void_fun<bool, &QPainter::setClipping>("setClipping").create();
  // bool hasClipping() const;
  binder.fun<bool, &QPainter::hasClipping>("hasClipping").create();
  // QRectF clipBoundingRect() const;
  binder.fun<QRectF, &QPainter::clipBoundingRect>("clipBoundingRect").create();
  // void save();
  binder.void_fun<&QPainter::save>("save").create();
  // void restore();
  binder.void_fun<&QPainter::restore>("restore").create();
  // void setMatrix(const QMatrix &, bool);
  /// TODO: void setMatrix(const QMatrix &, bool);
  // const QMatrix & matrix() const;
  /// TODO: const QMatrix & matrix() const;
  // const QMatrix & deviceMatrix() const;
  /// TODO: const QMatrix & deviceMatrix() const;
  // void resetMatrix();
  binder.void_fun<&QPainter::resetMatrix>("resetMatrix").create();
  // void setTransform(const QTransform &, bool);
  binder.void_fun<const QTransform &, bool, &QPainter::setTransform>("setTransform")
    .apply(binding::default_arguments(false)).create();
  // const QTransform & transform() const;
  binder.fun<const QTransform &, &QPainter::transform>("transform").create();
  // const QTransform & deviceTransform() const;
  binder.fun<const QTransform &, &QPainter::deviceTransform>("deviceTransform").create();
  // void resetTransform();
  binder.void_fun<&QPainter::resetTransform>("resetTransform").create();
  // void setWorldMatrix(const QMatrix &, bool);
  /// TODO: void setWorldMatrix(const QMatrix &, bool);
  // const QMatrix & worldMatrix() const;
  /// TODO: const QMatrix & worldMatrix() const;
  // void setWorldTransform(const QTransform &, bool);
  binder.void_fun<const QTransform &, bool, &QPainter::setWorldTransform>("setWorldTransform")
    .apply(binding::default_arguments(false)).create();
  // const QTransform & worldTransform() const;
  binder.fun<const QTransform &, &QPainter::worldTransform>("worldTransform").create();
  // QMatrix combinedMatrix() const;
  /// TODO: QMatrix combinedMatrix() const;
  // QTransform combinedTransform() const;
  binder.fun<QTransform, &QPainter::combinedTransform>("combinedTransform").create();
  // void setMatrixEnabled(bool);
  binder.void_fun<bool, &QPainter::setMatrixEnabled>("setMatrixEnabled").create();
  // bool matrixEnabled() const;
  binder.fun<bool, &QPainter::matrixEnabled>("matrixEnabled").create();
  // void setWorldMatrixEnabled(bool);
  binder.void_fun<bool, &QPainter::setWorldMatrixEnabled>("setWorldMatrixEnabled").create();
  // bool worldMatrixEnabled() const;
  binder.fun<bool, &QPainter::worldMatrixEnabled>("worldMatrixEnabled").create();
  // void scale(qreal, qreal);
  binder.void_fun<qreal, qreal, &QPainter::scale>("scale").create();
  // void shear(qreal, qreal);
  binder.void_fun<qreal, qreal, &QPainter::shear>("shear").create();
  // void rotate(qreal);
  binder.void_fun<qreal, &QPainter::rotate>("rotate").create();
  // void translate(const QPointF &);
  binder.void_fun<const QPointF &, &QPainter::translate>("translate").create();
  // void translate(const QPoint &);
  binder.void_fun<const QPoint &, &QPainter::translate>("translate").create();
  // void translate(qreal, qreal);
  binder.void_fun<qreal, qreal, &QPainter::translate>("translate").create();
  // QRect window() const;
  binder.fun<QRect, &QPainter::window>("window").create();
  // void setWindow(const QRect &);
  binder.void_fun<const QRect &, &QPainter::setWindow>("setWindow").create();
  // void setWindow(int, int, int, int);
  binder.void_fun<int, int, int, int, &QPainter::setWindow>("setWindow").create();
  // QRect viewport() const;
  binder.fun<QRect, &QPainter::viewport>("viewport").create();
  // void setViewport(const QRect &);
  binder.void_fun<const QRect &, &QPainter::setViewport>("setViewport").create();
  // void setViewport(int, int, int, int);
  binder.void_fun<int, int, int, int, &QPainter::setViewport>("setViewport").create();
  // void setViewTransformEnabled(bool);
  binder.void_fun<bool, &QPainter::setViewTransformEnabled>("setViewTransformEnabled").create();
  // bool viewTransformEnabled() const;
  binder.fun<bool, &QPainter::viewTransformEnabled>("viewTransformEnabled").create();
  // void strokePath(const QPainterPath &, const QPen &);
  binder.void_fun<const QPainterPath &, const QPen &, &QPainter::strokePath>("strokePath").create();
  // void fillPath(const QPainterPath &, const QBrush &);
  binder.void_fun<const QPainterPath &, const QBrush &, &QPainter::fillPath>("fillPath").create();
  // void drawPath(const QPainterPath &);
  binder.void_fun<const QPainterPath &, &QPainter::drawPath>("drawPath").create();
  // void drawPoint(const QPointF &);
  binder.void_fun<const QPointF &, &QPainter::drawPoint>("drawPoint").create();
  // void drawPoint(const QPoint &);
  binder.void_fun<const QPoint &, &QPainter::drawPoint>("drawPoint").create();
  // void drawPoint(int, int);
  binder.void_fun<int, int, &QPainter::drawPoint>("drawPoint").create();
  // void drawPoints(const QPointF *, int);
  /// TODO: void drawPoints(const QPointF *, int);
  // void drawPoints(const QPolygonF &);
  /// TODO: void drawPoints(const QPolygonF &);
  // void drawPoints(const QPoint *, int);
  /// TODO: void drawPoints(const QPoint *, int);
  // void drawPoints(const QPolygon &);
  /// TODO: void drawPoints(const QPolygon &);
  // void drawLine(const QLineF &);
  binder.void_fun<const QLineF &, &QPainter::drawLine>("drawLine").create();
  // void drawLine(const QLine &);
  binder.void_fun<const QLine &, &QPainter::drawLine>("drawLine").create();
  // void drawLine(int, int, int, int);
  binder.void_fun<int, int, int, int, &QPainter::drawLine>("drawLine").create();
  // void drawLine(const QPoint &, const QPoint &);
  binder.void_fun<const QPoint &, const QPoint &, &QPainter::drawLine>("drawLine").create();
  // void drawLine(const QPointF &, const QPointF &);
  binder.void_fun<const QPointF &, const QPointF &, &QPainter::drawLine>("drawLine").create();
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
  binder.void_fun<const QRectF &, &QPainter::drawRect>("drawRect").create();
  // void drawRect(int, int, int, int);
  binder.void_fun<int, int, int, int, &QPainter::drawRect>("drawRect").create();
  // void drawRect(const QRect &);
  binder.void_fun<const QRect &, &QPainter::drawRect>("drawRect").create();
  // void drawRects(const QRectF *, int);
  /// TODO: void drawRects(const QRectF *, int);
  // void drawRects(const QVector<QRectF> &);
  /// TODO: void drawRects(const QVector<QRectF> &);
  // void drawRects(const QRect *, int);
  /// TODO: void drawRects(const QRect *, int);
  // void drawRects(const QVector<QRect> &);
  /// TODO: void drawRects(const QVector<QRect> &);
  // void drawEllipse(const QRectF &);
  binder.void_fun<const QRectF &, &QPainter::drawEllipse>("drawEllipse").create();
  // void drawEllipse(const QRect &);
  binder.void_fun<const QRect &, &QPainter::drawEllipse>("drawEllipse").create();
  // void drawEllipse(int, int, int, int);
  binder.void_fun<int, int, int, int, &QPainter::drawEllipse>("drawEllipse").create();
  // void drawEllipse(const QPointF &, qreal, qreal);
  binder.void_fun<const QPointF &, qreal, qreal, &QPainter::drawEllipse>("drawEllipse").create();
  // void drawEllipse(const QPoint &, int, int);
  binder.void_fun<const QPoint &, int, int, &QPainter::drawEllipse>("drawEllipse").create();
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
  binder.void_fun<const QRectF &, int, int, &QPainter::drawArc>("drawArc").create();
  // void drawArc(const QRect &, int, int);
  binder.void_fun<const QRect &, int, int, &QPainter::drawArc>("drawArc").create();
  // void drawArc(int, int, int, int, int, int);
  binder.void_fun<int, int, int, int, int, int, &QPainter::drawArc>("drawArc").create();
  // void drawPie(const QRectF &, int, int);
  binder.void_fun<const QRectF &, int, int, &QPainter::drawPie>("drawPie").create();
  // void drawPie(int, int, int, int, int, int);
  binder.void_fun<int, int, int, int, int, int, &QPainter::drawPie>("drawPie").create();
  // void drawPie(const QRect &, int, int);
  binder.void_fun<const QRect &, int, int, &QPainter::drawPie>("drawPie").create();
  // void drawChord(const QRectF &, int, int);
  binder.void_fun<const QRectF &, int, int, &QPainter::drawChord>("drawChord").create();
  // void drawChord(int, int, int, int, int, int);
  binder.void_fun<int, int, int, int, int, int, &QPainter::drawChord>("drawChord").create();
  // void drawChord(const QRect &, int, int);
  binder.void_fun<const QRect &, int, int, &QPainter::drawChord>("drawChord").create();
  // void drawRoundedRect(const QRectF &, qreal, qreal, Qt::SizeMode);
  binder.void_fun<const QRectF &, qreal, qreal, Qt::SizeMode, &QPainter::drawRoundedRect>("drawRoundedRect")
    .apply(binding::default_arguments(Qt::AbsoluteSize)).create();
  // void drawRoundedRect(const QRect &, qreal, qreal, Qt::SizeMode);
  binder.void_fun<const QRect &, qreal, qreal, Qt::SizeMode, &QPainter::drawRoundedRect>("drawRoundedRect")
    .apply(binding::default_arguments(Qt::AbsoluteSize)).create();
  // void drawRoundRect(const QRectF &, int, int);
  binder.void_fun<const QRectF &, int, int, &QPainter::drawRoundRect>("drawRoundRect").create();
  // void drawRoundRect(int, int, int, int, int, int);
  binder.void_fun<int, int, int, int, int, int, &QPainter::drawRoundRect>("drawRoundRect").create();
  // void drawRoundRect(const QRect &, int, int);
  binder.void_fun<const QRect &, int, int, &QPainter::drawRoundRect>("drawRoundRect").create();
  // void drawTiledPixmap(const QRectF &, const QPixmap &, const QPointF &);
  binder.void_fun<const QRectF &, const QPixmap &, const QPointF &, &QPainter::drawTiledPixmap>("drawTiledPixmap")
    .apply(binding::default_arguments(QPointF())).create();
  // void drawTiledPixmap(const QRect &, const QPixmap &, const QPoint &);
  binder.void_fun<const QRect &, const QPixmap &, const QPoint &, &QPainter::drawTiledPixmap>("drawTiledPixmap")
    .apply(binding::default_arguments(QPoint())).create();
  // void drawPicture(const QPointF &, const QPicture &);
  binder.void_fun<const QPointF &, const QPicture &, &QPainter::drawPicture>("drawPicture").create();
  // void drawPicture(int, int, const QPicture &);
  binder.void_fun<int, int, const QPicture &, &QPainter::drawPicture>("drawPicture").create();
  // void drawPicture(const QPoint &, const QPicture &);
  binder.void_fun<const QPoint &, const QPicture &, &QPainter::drawPicture>("drawPicture").create();
  // void drawPixmap(const QRectF &, const QPixmap &, const QRectF &);
  binder.void_fun<const QRectF &, const QPixmap &, const QRectF &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmap(const QRect &, const QPixmap &, const QRect &);
  binder.void_fun<const QRect &, const QPixmap &, const QRect &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmap(const QPointF &, const QPixmap &, const QRectF &);
  binder.void_fun<const QPointF &, const QPixmap &, const QRectF &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmap(const QPoint &, const QPixmap &, const QRect &);
  binder.void_fun<const QPoint &, const QPixmap &, const QRect &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmap(const QPointF &, const QPixmap &);
  binder.void_fun<const QPointF &, const QPixmap &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmap(const QPoint &, const QPixmap &);
  binder.void_fun<const QPoint &, const QPixmap &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmap(int, int, const QPixmap &);
  binder.void_fun<int, int, const QPixmap &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmap(const QRect &, const QPixmap &);
  binder.void_fun<const QRect &, const QPixmap &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmap(int, int, int, int, const QPixmap &);
  binder.void_fun<int, int, int, int, const QPixmap &, &QPainter::drawPixmap>("drawPixmap").create();
  // void drawPixmapFragments(const QPainter::PixmapFragment *, int, const QPixmap &, QPainter::PixmapFragmentHints);
  /// TODO: void drawPixmapFragments(const QPainter::PixmapFragment *, int, const QPixmap &, QPainter::PixmapFragmentHints);
  // void drawImage(const QRectF &, const QImage &, const QRectF &, Qt::ImageConversionFlags);
  binder.void_fun<const QRectF &, const QImage &, const QRectF &, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // void drawImage(const QRect &, const QImage &, const QRect &, Qt::ImageConversionFlags);
  binder.void_fun<const QRect &, const QImage &, const QRect &, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // void drawImage(const QPointF &, const QImage &, const QRectF &, Qt::ImageConversionFlags);
  binder.void_fun<const QPointF &, const QImage &, const QRectF &, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // void drawImage(const QPoint &, const QImage &, const QRect &, Qt::ImageConversionFlags);
  binder.void_fun<const QPoint &, const QImage &, const QRect &, Qt::ImageConversionFlags, &QPainter::drawImage>("drawImage")
    .apply(binding::default_arguments(Qt::ImageConversionFlags(Qt::AutoColor))).create();
  // void drawImage(const QRectF &, const QImage &);
  binder.void_fun<const QRectF &, const QImage &, &QPainter::drawImage>("drawImage").create();
  // void drawImage(const QRect &, const QImage &);
  binder.void_fun<const QRect &, const QImage &, &QPainter::drawImage>("drawImage").create();
  // void drawImage(const QPointF &, const QImage &);
  binder.void_fun<const QPointF &, const QImage &, &QPainter::drawImage>("drawImage").create();
  // void drawImage(const QPoint &, const QImage &);
  binder.void_fun<const QPoint &, const QImage &, &QPainter::drawImage>("drawImage").create();
  // void setLayoutDirection(Qt::LayoutDirection);
  binder.void_fun<Qt::LayoutDirection, &QPainter::setLayoutDirection>("setLayoutDirection").create();
  // Qt::LayoutDirection layoutDirection() const;
  binder.fun<Qt::LayoutDirection, &QPainter::layoutDirection>("layoutDirection").create();
  // void drawGlyphRun(const QPointF &, const QGlyphRun &);
  binder.void_fun<const QPointF &, const QGlyphRun &, &QPainter::drawGlyphRun>("drawGlyphRun").create();
  // void drawStaticText(const QPointF &, const QStaticText &);
  binder.void_fun<const QPointF &, const QStaticText &, &QPainter::drawStaticText>("drawStaticText").create();
  // void drawStaticText(const QPoint &, const QStaticText &);
  binder.void_fun<const QPoint &, const QStaticText &, &QPainter::drawStaticText>("drawStaticText").create();
  // void drawStaticText(int, int, const QStaticText &);
  binder.void_fun<int, int, const QStaticText &, &QPainter::drawStaticText>("drawStaticText").create();
  // void drawText(const QPointF &, const QString &);
  binder.void_fun<const QPointF &, const QString &, &QPainter::drawText>("drawText").create();
  // void drawText(const QPoint &, const QString &);
  binder.void_fun<const QPoint &, const QString &, &QPainter::drawText>("drawText").create();
  // void drawText(int, int, const QString &);
  binder.void_fun<int, int, const QString &, &QPainter::drawText>("drawText").create();
  // void drawText(const QPointF &, const QString &, int, int);
  binder.void_fun<const QPointF &, const QString &, int, int, &QPainter::drawText>("drawText").create();
  // void drawText(const QRectF &, int, const QString &, QRectF *);
  /// TODO: void drawText(const QRectF &, int, const QString &, QRectF *);
  // void drawText(const QRect &, int, const QString &, QRect *);
  /// TODO: void drawText(const QRect &, int, const QString &, QRect *);
  // void drawText(int, int, int, int, int, const QString &, QRect *);
  /// TODO: void drawText(int, int, int, int, int, const QString &, QRect *);
  // void drawText(const QRectF &, const QString &, const QTextOption &);
  binder.void_fun<const QRectF &, const QString &, const QTextOption &, &QPainter::drawText>("drawText")
    .apply(binding::default_arguments(QTextOption())).create();
  // QRectF boundingRect(const QRectF &, int, const QString &);
  binder.fun<QRectF, const QRectF &, int, const QString &, &QPainter::boundingRect>("boundingRect").create();
  // QRect boundingRect(const QRect &, int, const QString &);
  binder.fun<QRect, const QRect &, int, const QString &, &QPainter::boundingRect>("boundingRect").create();
  // QRect boundingRect(int, int, int, int, int, const QString &);
  binder.fun<QRect, int, int, int, int, int, const QString &, &QPainter::boundingRect>("boundingRect").create();
  // QRectF boundingRect(const QRectF &, const QString &, const QTextOption &);
  binder.fun<QRectF, const QRectF &, const QString &, const QTextOption &, &QPainter::boundingRect>("boundingRect")
    .apply(binding::default_arguments(QTextOption())).create();
  // void drawTextItem(const QPointF &, const QTextItem &);
  /// TODO: void drawTextItem(const QPointF &, const QTextItem &);
  // void drawTextItem(int, int, const QTextItem &);
  /// TODO: void drawTextItem(int, int, const QTextItem &);
  // void drawTextItem(const QPoint &, const QTextItem &);
  /// TODO: void drawTextItem(const QPoint &, const QTextItem &);
  // void fillRect(const QRectF &, const QBrush &);
  binder.void_fun<const QRectF &, const QBrush &, &QPainter::fillRect>("fillRect").create();
  // void fillRect(int, int, int, int, const QBrush &);
  binder.void_fun<int, int, int, int, const QBrush &, &QPainter::fillRect>("fillRect").create();
  // void fillRect(const QRect &, const QBrush &);
  binder.void_fun<const QRect &, const QBrush &, &QPainter::fillRect>("fillRect").create();
  // void fillRect(const QRectF &, const QColor &);
  binder.void_fun<const QRectF &, const QColor &, &QPainter::fillRect>("fillRect").create();
  // void fillRect(int, int, int, int, const QColor &);
  binder.void_fun<int, int, int, int, const QColor &, &QPainter::fillRect>("fillRect").create();
  // void fillRect(const QRect &, const QColor &);
  binder.void_fun<const QRect &, const QColor &, &QPainter::fillRect>("fillRect").create();
  // void fillRect(int, int, int, int, Qt::GlobalColor);
  binder.void_fun<int, int, int, int, Qt::GlobalColor, &QPainter::fillRect>("fillRect").create();
  // void fillRect(const QRect &, Qt::GlobalColor);
  binder.void_fun<const QRect &, Qt::GlobalColor, &QPainter::fillRect>("fillRect").create();
  // void fillRect(const QRectF &, Qt::GlobalColor);
  binder.void_fun<const QRectF &, Qt::GlobalColor, &QPainter::fillRect>("fillRect").create();
  // void fillRect(int, int, int, int, Qt::BrushStyle);
  binder.void_fun<int, int, int, int, Qt::BrushStyle, &QPainter::fillRect>("fillRect").create();
  // void fillRect(const QRect &, Qt::BrushStyle);
  binder.void_fun<const QRect &, Qt::BrushStyle, &QPainter::fillRect>("fillRect").create();
  // void fillRect(const QRectF &, Qt::BrushStyle);
  binder.void_fun<const QRectF &, Qt::BrushStyle, &QPainter::fillRect>("fillRect").create();
  // void eraseRect(const QRectF &);
  binder.void_fun<const QRectF &, &QPainter::eraseRect>("eraseRect").create();
  // void eraseRect(int, int, int, int);
  binder.void_fun<int, int, int, int, &QPainter::eraseRect>("eraseRect").create();
  // void eraseRect(const QRect &);
  binder.void_fun<const QRect &, &QPainter::eraseRect>("eraseRect").create();
  // void setRenderHint(QPainter::RenderHint, bool);
  binder.void_fun<QPainter::RenderHint, bool, &QPainter::setRenderHint>("setRenderHint").create();
  // void setRenderHints(QPainter::RenderHints, bool);
  binder.void_fun<QPainter::RenderHints, bool, &QPainter::setRenderHints>("setRenderHints").create();
  // QPainter::RenderHints renderHints() const;
  binder.fun<QPainter::RenderHints, &QPainter::renderHints>("renderHints").create();
  // bool testRenderHint(QPainter::RenderHint) const;
  binder.fun<bool, QPainter::RenderHint, &QPainter::testRenderHint>("testRenderHint").create();
  // QPaintEngine * paintEngine() const;
  /// TODO: QPaintEngine * paintEngine() const;
  // static void setRedirected(const QPaintDevice *, QPaintDevice *, const QPoint &);
  /// TODO: static void setRedirected(const QPaintDevice *, QPaintDevice *, const QPoint &);
  // static QPaintDevice * redirected(const QPaintDevice *, QPoint *);
  /// TODO: static QPaintDevice * redirected(const QPaintDevice *, QPoint *);
  // static void restoreRedirected(const QPaintDevice *);
  /// TODO: static void restoreRedirected(const QPaintDevice *);
  // void beginNativePainting();
  binder.void_fun<&QPainter::beginNativePainting>("beginNativePainting").create();
  // void endNativePainting();
  binder.void_fun<&QPainter::endNativePainting>("endNativePainting").create();
}


void register_painter_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_painter_class(ns);
  binding::Namespace binder{ ns };

  // QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QPainter::RenderHints::enum_type);
  /// TODO: QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QPainter::RenderHints::enum_type);
  // QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QFlags<QPainter::RenderHints::enum_type>);
  /// TODO: QFlags<QPainter::RenderHints::enum_type> operator|(QPainter::RenderHints::enum_type, QFlags<QPainter::RenderHints::enum_type>);
  // QIncompatibleFlag operator|(QPainter::RenderHints::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QPainter::RenderHints::enum_type, int);
}

