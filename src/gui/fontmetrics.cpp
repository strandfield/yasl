// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/fontmetrics.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/core/char.h"
#include "yasl/core/enums.h"
#include "yasl/core/rect.h"
#include "yasl/gui/font.h"
#include "yasl/gui/fontmetrics.h"

#include <script/classbuilder.h>

static void register_font_metrics_class(script::Namespace ns)
{
  using namespace script;

  Class font_metrics = ns.newClass("FontMetrics").setId(script::Type::QFontMetrics).get();


  // QFontMetrics(const QFont &);
  bind::constructor<QFontMetrics, const QFont &>(font_metrics).create();
  // QFontMetrics(const QFont &, QPaintDevice *);
  /// TODO: QFontMetrics(const QFont &, QPaintDevice *);
  // QFontMetrics(const QFontMetrics &);
  bind::constructor<QFontMetrics, const QFontMetrics &>(font_metrics).create();
  // ~QFontMetrics();
  bind::destructor<QFontMetrics>(font_metrics).create();
  // QFontMetrics & operator=(const QFontMetrics &);
  bind::memop_assign<QFontMetrics, const QFontMetrics &>(font_metrics);
  // QFontMetrics & operator=(QFontMetrics &&);
  bind::memop_assign<QFontMetrics, QFontMetrics &&>(font_metrics);
  // void swap(QFontMetrics &);
  bind::void_member_function<QFontMetrics, QFontMetrics &, &QFontMetrics::swap>(font_metrics, "swap").create();
  // int ascent() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::ascent>(font_metrics, "ascent").create();
  // int capHeight() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::capHeight>(font_metrics, "capHeight").create();
  // int descent() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::descent>(font_metrics, "descent").create();
  // int height() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::height>(font_metrics, "height").create();
  // int leading() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::leading>(font_metrics, "leading").create();
  // int lineSpacing() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::lineSpacing>(font_metrics, "lineSpacing").create();
  // int minLeftBearing() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::minLeftBearing>(font_metrics, "minLeftBearing").create();
  // int minRightBearing() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::minRightBearing>(font_metrics, "minRightBearing").create();
  // int maxWidth() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::maxWidth>(font_metrics, "maxWidth").create();
  // int xHeight() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::xHeight>(font_metrics, "xHeight").create();
  // int averageCharWidth() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::averageCharWidth>(font_metrics, "averageCharWidth").create();
  // bool inFont(QChar) const;
  bind::member_function<QFontMetrics, bool, QChar, &QFontMetrics::inFont>(font_metrics, "inFont").create();
  // bool inFontUcs4(uint) const;
  bind::member_function<QFontMetrics, bool, uint, &QFontMetrics::inFontUcs4>(font_metrics, "inFontUcs4").create();
  // int leftBearing(QChar) const;
  bind::member_function<QFontMetrics, int, QChar, &QFontMetrics::leftBearing>(font_metrics, "leftBearing").create();
  // int rightBearing(QChar) const;
  bind::member_function<QFontMetrics, int, QChar, &QFontMetrics::rightBearing>(font_metrics, "rightBearing").create();
  // int width(const QString &, int) const;
  bind::member_function<QFontMetrics, int, const QString &, int, &QFontMetrics::width>(font_metrics, "width")
    .apply(bind::default_arguments(-1)).create();
  // int width(const QString &, int, int) const;
  bind::member_function<QFontMetrics, int, const QString &, int, int, &QFontMetrics::width>(font_metrics, "width").create();
  // int width(QChar) const;
  bind::member_function<QFontMetrics, int, QChar, &QFontMetrics::width>(font_metrics, "width").create();
  // int charWidth(const QString &, int) const;
  bind::member_function<QFontMetrics, int, const QString &, int, &QFontMetrics::charWidth>(font_metrics, "charWidth").create();
  // QRect boundingRect(QChar) const;
  bind::member_function<QFontMetrics, QRect, QChar, &QFontMetrics::boundingRect>(font_metrics, "boundingRect").create();
  // QRect boundingRect(const QString &) const;
  bind::member_function<QFontMetrics, QRect, const QString &, &QFontMetrics::boundingRect>(font_metrics, "boundingRect").create();
  // QRect boundingRect(const QRect &, int, const QString &, int, int *) const;
  /// TODO: QRect boundingRect(const QRect &, int, const QString &, int, int *) const;
  // QRect boundingRect(int, int, int, int, int, const QString &, int, int *) const;
  /// TODO: QRect boundingRect(int, int, int, int, int, const QString &, int, int *) const;
  // QSize size(int, const QString &, int, int *) const;
  /// TODO: QSize size(int, const QString &, int, int *) const;
  // QRect tightBoundingRect(const QString &) const;
  bind::member_function<QFontMetrics, QRect, const QString &, &QFontMetrics::tightBoundingRect>(font_metrics, "tightBoundingRect").create();
  // QString elidedText(const QString &, Qt::TextElideMode, int, int) const;
  bind::member_function<QFontMetrics, QString, const QString &, Qt::TextElideMode, int, int, &QFontMetrics::elidedText>(font_metrics, "elidedText")
    .apply(bind::default_arguments(0)).create();
  // int underlinePos() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::underlinePos>(font_metrics, "underlinePos").create();
  // int overlinePos() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::overlinePos>(font_metrics, "overlinePos").create();
  // int strikeOutPos() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::strikeOutPos>(font_metrics, "strikeOutPos").create();
  // int lineWidth() const;
  bind::member_function<QFontMetrics, int, &QFontMetrics::lineWidth>(font_metrics, "lineWidth").create();
  // bool operator==(const QFontMetrics &) const;
  bind::memop_eq<QFontMetrics, const QFontMetrics &>(font_metrics);
  // bool operator!=(const QFontMetrics &) const;
  bind::memop_neq<QFontMetrics, const QFontMetrics &>(font_metrics);
}


static void register_font_metrics_f_class(script::Namespace ns)
{
  using namespace script;

  Class font_metrics_f = ns.newClass("FontMetricsF").setId(script::Type::QFontMetricsF).get();


  // QFontMetricsF(const QFont &);
  bind::constructor<QFontMetricsF, const QFont &>(font_metrics_f).create();
  // QFontMetricsF(const QFont &, QPaintDevice *);
  /// TODO: QFontMetricsF(const QFont &, QPaintDevice *);
  // QFontMetricsF(const QFontMetrics &);
  bind::constructor<QFontMetricsF, const QFontMetrics &>(font_metrics_f).create();
  // QFontMetricsF(const QFontMetricsF &);
  bind::constructor<QFontMetricsF, const QFontMetricsF &>(font_metrics_f).create();
  // ~QFontMetricsF();
  bind::destructor<QFontMetricsF>(font_metrics_f).create();
  // QFontMetricsF & operator=(const QFontMetricsF &);
  bind::memop_assign<QFontMetricsF, const QFontMetricsF &>(font_metrics_f);
  // QFontMetricsF & operator=(const QFontMetrics &);
  bind::memop_assign<QFontMetricsF, const QFontMetrics &>(font_metrics_f);
  // QFontMetricsF & operator=(QFontMetricsF &&);
  bind::memop_assign<QFontMetricsF, QFontMetricsF &&>(font_metrics_f);
  // void swap(QFontMetricsF &);
  bind::void_member_function<QFontMetricsF, QFontMetricsF &, &QFontMetricsF::swap>(font_metrics_f, "swap").create();
  // qreal ascent() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::ascent>(font_metrics_f, "ascent").create();
  // qreal capHeight() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::capHeight>(font_metrics_f, "capHeight").create();
  // qreal descent() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::descent>(font_metrics_f, "descent").create();
  // qreal height() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::height>(font_metrics_f, "height").create();
  // qreal leading() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::leading>(font_metrics_f, "leading").create();
  // qreal lineSpacing() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::lineSpacing>(font_metrics_f, "lineSpacing").create();
  // qreal minLeftBearing() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::minLeftBearing>(font_metrics_f, "minLeftBearing").create();
  // qreal minRightBearing() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::minRightBearing>(font_metrics_f, "minRightBearing").create();
  // qreal maxWidth() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::maxWidth>(font_metrics_f, "maxWidth").create();
  // qreal xHeight() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::xHeight>(font_metrics_f, "xHeight").create();
  // qreal averageCharWidth() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::averageCharWidth>(font_metrics_f, "averageCharWidth").create();
  // bool inFont(QChar) const;
  bind::member_function<QFontMetricsF, bool, QChar, &QFontMetricsF::inFont>(font_metrics_f, "inFont").create();
  // bool inFontUcs4(uint) const;
  bind::member_function<QFontMetricsF, bool, uint, &QFontMetricsF::inFontUcs4>(font_metrics_f, "inFontUcs4").create();
  // qreal leftBearing(QChar) const;
  bind::member_function<QFontMetricsF, qreal, QChar, &QFontMetricsF::leftBearing>(font_metrics_f, "leftBearing").create();
  // qreal rightBearing(QChar) const;
  bind::member_function<QFontMetricsF, qreal, QChar, &QFontMetricsF::rightBearing>(font_metrics_f, "rightBearing").create();
  // qreal width(const QString &) const;
  bind::member_function<QFontMetricsF, qreal, const QString &, &QFontMetricsF::width>(font_metrics_f, "width").create();
  // qreal width(QChar) const;
  bind::member_function<QFontMetricsF, qreal, QChar, &QFontMetricsF::width>(font_metrics_f, "width").create();
  // QRectF boundingRect(const QString &) const;
  bind::member_function<QFontMetricsF, QRectF, const QString &, &QFontMetricsF::boundingRect>(font_metrics_f, "boundingRect").create();
  // QRectF boundingRect(QChar) const;
  bind::member_function<QFontMetricsF, QRectF, QChar, &QFontMetricsF::boundingRect>(font_metrics_f, "boundingRect").create();
  // QRectF boundingRect(const QRectF &, int, const QString &, int, int *) const;
  /// TODO: QRectF boundingRect(const QRectF &, int, const QString &, int, int *) const;
  // QSizeF size(int, const QString &, int, int *) const;
  /// TODO: QSizeF size(int, const QString &, int, int *) const;
  // QRectF tightBoundingRect(const QString &) const;
  bind::member_function<QFontMetricsF, QRectF, const QString &, &QFontMetricsF::tightBoundingRect>(font_metrics_f, "tightBoundingRect").create();
  // QString elidedText(const QString &, Qt::TextElideMode, qreal, int) const;
  bind::member_function<QFontMetricsF, QString, const QString &, Qt::TextElideMode, qreal, int, &QFontMetricsF::elidedText>(font_metrics_f, "elidedText")
    .apply(bind::default_arguments(0)).create();
  // qreal underlinePos() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::underlinePos>(font_metrics_f, "underlinePos").create();
  // qreal overlinePos() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::overlinePos>(font_metrics_f, "overlinePos").create();
  // qreal strikeOutPos() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::strikeOutPos>(font_metrics_f, "strikeOutPos").create();
  // qreal lineWidth() const;
  bind::member_function<QFontMetricsF, qreal, &QFontMetricsF::lineWidth>(font_metrics_f, "lineWidth").create();
  // bool operator==(const QFontMetricsF &) const;
  bind::memop_eq<QFontMetricsF, const QFontMetricsF &>(font_metrics_f);
  // bool operator!=(const QFontMetricsF &) const;
  bind::memop_neq<QFontMetricsF, const QFontMetricsF &>(font_metrics_f);
}


void register_fontmetrics_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_metrics_class(ns);
  register_font_metrics_f_class(ns);

  // void swap(QFontMetrics &, QFontMetrics &);
  bind::void_function<QFontMetrics &, QFontMetrics &, &swap>(ns, "swap").create();
  // void swap(QFontMetricsF &, QFontMetricsF &);
  bind::void_function<QFontMetricsF &, QFontMetricsF &, &swap>(ns, "swap").create();
}

