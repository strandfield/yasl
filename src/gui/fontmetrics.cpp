// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/fontmetrics.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/char.h"
#include "yasl/core/enums.h"
#include "yasl/core/rect.h"
#include "yasl/gui/font.h"
#include "yasl/gui/fontmetrics.h"

#include <script/classbuilder.h>

static void register_font_metrics_class(script::Namespace ns)
{
  using namespace script;

  Class font_metrics = ns.Class("FontMetrics").setId(script::Type::QFontMetrics).get();

  binding::Class<QFontMetrics> binder{ font_metrics };

  // QFontMetrics(const QFont &);
  binder.ctors().ctor<const QFont &>().create();
  // QFontMetrics(const QFont &, QPaintDevice *);
  /// TODO: QFontMetrics(const QFont &, QPaintDevice *);
  // QFontMetrics(const QFontMetrics &);
  binder.ctors().ctor<const QFontMetrics &>().create();
  // ~QFontMetrics();
  binder.add_dtor();
  // QFontMetrics & operator=(const QFontMetrics &);
  binder.operators().assign<const QFontMetrics &>();
  // QFontMetrics & operator=(QFontMetrics &&);
  binder.operators().assign<QFontMetrics &&>();
  // void swap(QFontMetrics &);
  binder.void_fun<QFontMetrics &, &QFontMetrics::swap>("swap").create();
  // int ascent() const;
  binder.fun<int, &QFontMetrics::ascent>("ascent").create();
  // int capHeight() const;
  binder.fun<int, &QFontMetrics::capHeight>("capHeight").create();
  // int descent() const;
  binder.fun<int, &QFontMetrics::descent>("descent").create();
  // int height() const;
  binder.fun<int, &QFontMetrics::height>("height").create();
  // int leading() const;
  binder.fun<int, &QFontMetrics::leading>("leading").create();
  // int lineSpacing() const;
  binder.fun<int, &QFontMetrics::lineSpacing>("lineSpacing").create();
  // int minLeftBearing() const;
  binder.fun<int, &QFontMetrics::minLeftBearing>("minLeftBearing").create();
  // int minRightBearing() const;
  binder.fun<int, &QFontMetrics::minRightBearing>("minRightBearing").create();
  // int maxWidth() const;
  binder.fun<int, &QFontMetrics::maxWidth>("maxWidth").create();
  // int xHeight() const;
  binder.fun<int, &QFontMetrics::xHeight>("xHeight").create();
  // int averageCharWidth() const;
  binder.fun<int, &QFontMetrics::averageCharWidth>("averageCharWidth").create();
  // bool inFont(QChar) const;
  binder.fun<bool, QChar, &QFontMetrics::inFont>("inFont").create();
  // bool inFontUcs4(uint) const;
  binder.fun<bool, uint, &QFontMetrics::inFontUcs4>("inFontUcs4").create();
  // int leftBearing(QChar) const;
  binder.fun<int, QChar, &QFontMetrics::leftBearing>("leftBearing").create();
  // int rightBearing(QChar) const;
  binder.fun<int, QChar, &QFontMetrics::rightBearing>("rightBearing").create();
  // int width(const QString &, int) const;
  binder.fun<int, const QString &, int, &QFontMetrics::width>("width").create();
  // int width(const QString &, int, int) const;
  binder.fun<int, const QString &, int, int, &QFontMetrics::width>("width").create();
  // int width(QChar) const;
  binder.fun<int, QChar, &QFontMetrics::width>("width").create();
  // int charWidth(const QString &, int) const;
  binder.fun<int, const QString &, int, &QFontMetrics::charWidth>("charWidth").create();
  // QRect boundingRect(QChar) const;
  binder.fun<QRect, QChar, &QFontMetrics::boundingRect>("boundingRect").create();
  // QRect boundingRect(const QString &) const;
  binder.fun<QRect, const QString &, &QFontMetrics::boundingRect>("boundingRect").create();
  // QRect boundingRect(const QRect &, int, const QString &, int, int *) const;
  /// TODO: QRect boundingRect(const QRect &, int, const QString &, int, int *) const;
  // QRect boundingRect(int, int, int, int, int, const QString &, int, int *) const;
  /// TODO: QRect boundingRect(int, int, int, int, int, const QString &, int, int *) const;
  // QSize size(int, const QString &, int, int *) const;
  /// TODO: QSize size(int, const QString &, int, int *) const;
  // QRect tightBoundingRect(const QString &) const;
  binder.fun<QRect, const QString &, &QFontMetrics::tightBoundingRect>("tightBoundingRect").create();
  // QString elidedText(const QString &, Qt::TextElideMode, int, int) const;
  binder.fun<QString, const QString &, Qt::TextElideMode, int, int, &QFontMetrics::elidedText>("elidedText").create();
  // int underlinePos() const;
  binder.fun<int, &QFontMetrics::underlinePos>("underlinePos").create();
  // int overlinePos() const;
  binder.fun<int, &QFontMetrics::overlinePos>("overlinePos").create();
  // int strikeOutPos() const;
  binder.fun<int, &QFontMetrics::strikeOutPos>("strikeOutPos").create();
  // int lineWidth() const;
  binder.fun<int, &QFontMetrics::lineWidth>("lineWidth").create();
  // bool operator==(const QFontMetrics &) const;
  binder.operators().eq<const QFontMetrics &>();
  // bool operator!=(const QFontMetrics &) const;
  binder.operators().neq<const QFontMetrics &>();
}


static void register_font_metrics_f_class(script::Namespace ns)
{
  using namespace script;

  Class font_metrics_f = ns.Class("FontMetricsF").setId(script::Type::QFontMetricsF).get();

  binding::Class<QFontMetricsF> binder{ font_metrics_f };

  // QFontMetricsF(const QFont &);
  binder.ctors().ctor<const QFont &>().create();
  // QFontMetricsF(const QFont &, QPaintDevice *);
  /// TODO: QFontMetricsF(const QFont &, QPaintDevice *);
  // QFontMetricsF(const QFontMetrics &);
  binder.ctors().ctor<const QFontMetrics &>().create();
  // QFontMetricsF(const QFontMetricsF &);
  binder.ctors().ctor<const QFontMetricsF &>().create();
  // ~QFontMetricsF();
  binder.add_dtor();
  // QFontMetricsF & operator=(const QFontMetricsF &);
  binder.operators().assign<const QFontMetricsF &>();
  // QFontMetricsF & operator=(const QFontMetrics &);
  binder.operators().assign<const QFontMetrics &>();
  // QFontMetricsF & operator=(QFontMetricsF &&);
  binder.operators().assign<QFontMetricsF &&>();
  // void swap(QFontMetricsF &);
  binder.void_fun<QFontMetricsF &, &QFontMetricsF::swap>("swap").create();
  // qreal ascent() const;
  binder.fun<qreal, &QFontMetricsF::ascent>("ascent").create();
  // qreal capHeight() const;
  binder.fun<qreal, &QFontMetricsF::capHeight>("capHeight").create();
  // qreal descent() const;
  binder.fun<qreal, &QFontMetricsF::descent>("descent").create();
  // qreal height() const;
  binder.fun<qreal, &QFontMetricsF::height>("height").create();
  // qreal leading() const;
  binder.fun<qreal, &QFontMetricsF::leading>("leading").create();
  // qreal lineSpacing() const;
  binder.fun<qreal, &QFontMetricsF::lineSpacing>("lineSpacing").create();
  // qreal minLeftBearing() const;
  binder.fun<qreal, &QFontMetricsF::minLeftBearing>("minLeftBearing").create();
  // qreal minRightBearing() const;
  binder.fun<qreal, &QFontMetricsF::minRightBearing>("minRightBearing").create();
  // qreal maxWidth() const;
  binder.fun<qreal, &QFontMetricsF::maxWidth>("maxWidth").create();
  // qreal xHeight() const;
  binder.fun<qreal, &QFontMetricsF::xHeight>("xHeight").create();
  // qreal averageCharWidth() const;
  binder.fun<qreal, &QFontMetricsF::averageCharWidth>("averageCharWidth").create();
  // bool inFont(QChar) const;
  binder.fun<bool, QChar, &QFontMetricsF::inFont>("inFont").create();
  // bool inFontUcs4(uint) const;
  binder.fun<bool, uint, &QFontMetricsF::inFontUcs4>("inFontUcs4").create();
  // qreal leftBearing(QChar) const;
  binder.fun<qreal, QChar, &QFontMetricsF::leftBearing>("leftBearing").create();
  // qreal rightBearing(QChar) const;
  binder.fun<qreal, QChar, &QFontMetricsF::rightBearing>("rightBearing").create();
  // qreal width(const QString &) const;
  binder.fun<qreal, const QString &, &QFontMetricsF::width>("width").create();
  // qreal width(QChar) const;
  binder.fun<qreal, QChar, &QFontMetricsF::width>("width").create();
  // QRectF boundingRect(const QString &) const;
  binder.fun<QRectF, const QString &, &QFontMetricsF::boundingRect>("boundingRect").create();
  // QRectF boundingRect(QChar) const;
  binder.fun<QRectF, QChar, &QFontMetricsF::boundingRect>("boundingRect").create();
  // QRectF boundingRect(const QRectF &, int, const QString &, int, int *) const;
  /// TODO: QRectF boundingRect(const QRectF &, int, const QString &, int, int *) const;
  // QSizeF size(int, const QString &, int, int *) const;
  /// TODO: QSizeF size(int, const QString &, int, int *) const;
  // QRectF tightBoundingRect(const QString &) const;
  binder.fun<QRectF, const QString &, &QFontMetricsF::tightBoundingRect>("tightBoundingRect").create();
  // QString elidedText(const QString &, Qt::TextElideMode, qreal, int) const;
  binder.fun<QString, const QString &, Qt::TextElideMode, qreal, int, &QFontMetricsF::elidedText>("elidedText").create();
  // qreal underlinePos() const;
  binder.fun<qreal, &QFontMetricsF::underlinePos>("underlinePos").create();
  // qreal overlinePos() const;
  binder.fun<qreal, &QFontMetricsF::overlinePos>("overlinePos").create();
  // qreal strikeOutPos() const;
  binder.fun<qreal, &QFontMetricsF::strikeOutPos>("strikeOutPos").create();
  // qreal lineWidth() const;
  binder.fun<qreal, &QFontMetricsF::lineWidth>("lineWidth").create();
  // bool operator==(const QFontMetricsF &) const;
  binder.operators().eq<const QFontMetricsF &>();
  // bool operator!=(const QFontMetricsF &) const;
  binder.operators().neq<const QFontMetricsF &>();
}


void register_fontmetrics_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_metrics_class(ns);
  register_font_metrics_f_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QFontMetrics &, QFontMetrics &);
  binder.void_fun<QFontMetrics &, QFontMetrics &, &swap>("swap").create();
  // void swap(QFontMetricsF &, QFontMetricsF &);
  binder.void_fun<QFontMetricsF &, QFontMetricsF &, &swap>("swap").create();
}

