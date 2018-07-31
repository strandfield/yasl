// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/fontmetrics.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/macros.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/char.h"
#include "yasl/core/enums.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"

#include "yasl/gui/font.h"
#include "yasl/gui/paintdevice.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

static void register_font_metrics_class(script::Namespace ns)
{
  using namespace script;

  Class font_metrics = ns.Class("FontMetrics").setId(script::Type::QFontMetrics).get();

  binding::Class<QFontMetrics> binder{ font_metrics };

  // QFontMetrics(const QFont &);
  binder.ctors().add<const QFont &>();
  // QFontMetrics(const QFont &, QPaintDevice *);
  binder.ctors().add<const QFont &, QPaintDevice *>();
  // QFontMetrics(const QFontMetrics &);
  binder.ctors().add<const QFontMetrics &>();
  // QFontMetrics & operator=(const QFontMetrics &);
  binder.operators().assign<const QFontMetrics &>();
  // QFontMetrics & operator=(QFontMetrics &&);
  binder.operators().assign<QFontMetrics &&>();
  // void swap(QFontMetrics &);
  binder.add_void_fun<QFontMetrics &, &QFontMetrics::swap>("swap");
  // int ascent() const;
  binder.add_fun<int, &QFontMetrics::ascent>("ascent");
  // int capHeight() const;
  binder.add_fun<int, &QFontMetrics::capHeight>("capHeight");
  // int descent() const;
  binder.add_fun<int, &QFontMetrics::descent>("descent");
  // int height() const;
  binder.add_fun<int, &QFontMetrics::height>("height");
  // int leading() const;
  binder.add_fun<int, &QFontMetrics::leading>("leading");
  // int lineSpacing() const;
  binder.add_fun<int, &QFontMetrics::lineSpacing>("lineSpacing");
  // int minLeftBearing() const;
  binder.add_fun<int, &QFontMetrics::minLeftBearing>("minLeftBearing");
  // int minRightBearing() const;
  binder.add_fun<int, &QFontMetrics::minRightBearing>("minRightBearing");
  // int maxWidth() const;
  binder.add_fun<int, &QFontMetrics::maxWidth>("maxWidth");
  // int xHeight() const;
  binder.add_fun<int, &QFontMetrics::xHeight>("xHeight");
  // int averageCharWidth() const;
  binder.add_fun<int, &QFontMetrics::averageCharWidth>("averageCharWidth");
  // bool inFont(QChar) const;
  binder.add_fun<bool, QChar, &QFontMetrics::inFont>("inFont");
  // bool inFontUcs4(uint) const;
  binder.add_fun<bool, uint, &QFontMetrics::inFontUcs4>("inFontUcs4");
  // int leftBearing(QChar) const;
  binder.add_fun<int, QChar, &QFontMetrics::leftBearing>("leftBearing");
  // int rightBearing(QChar) const;
  binder.add_fun<int, QChar, &QFontMetrics::rightBearing>("rightBearing");
  // int width(const QString &, int) const;
  binder.add_fun<int, const QString &, int, &QFontMetrics::width>("width");
  // int width(const QString &, int, int) const;
  binder.add_fun<int, const QString &, int, int, &QFontMetrics::width>("width");
  // int width(QChar) const;
  binder.add_fun<int, QChar, &QFontMetrics::width>("width");
  // int charWidth(const QString &, int) const;
  binder.add_fun<int, const QString &, int, &QFontMetrics::charWidth>("charWidth");
  // QRect boundingRect(QChar) const;
  binder.add_fun<QRect, QChar, &QFontMetrics::boundingRect>("boundingRect");
  // QRect boundingRect(const QString &) const;
  binder.add_fun<QRect, const QString &, &QFontMetrics::boundingRect>("boundingRect");
  // QRect boundingRect(const QRect &, int, const QString &, int, int *) const;
  binder.add_fun<QRect, const QRect &, int, const QString &, int, int *, &QFontMetrics::boundingRect>("boundingRect");
  // QRect boundingRect(int, int, int, int, int, const QString &, int, int *) const;
  /// TODO: binder.add_fun<QRect, int, int, int, int, int, const QString &, int, int *, &QFontMetrics::boundingRect>("boundingRect");
  // QSize size(int, const QString &, int, int *) const;
  binder.add_fun<QSize, int, const QString &, int, int *, &QFontMetrics::size>("size");
  // QRect tightBoundingRect(const QString &) const;
  binder.add_fun<QRect, const QString &, &QFontMetrics::tightBoundingRect>("tightBoundingRect");
  // QString elidedText(const QString &, Qt::TextElideMode, int, int) const;
  binder.add_fun<QString, const QString &, Qt::TextElideMode, int, int, &QFontMetrics::elidedText>("elidedText");
  // int underlinePos() const;
  binder.add_fun<int, &QFontMetrics::underlinePos>("underlinePos");
  // int overlinePos() const;
  binder.add_fun<int, &QFontMetrics::overlinePos>("overlinePos");
  // int strikeOutPos() const;
  binder.add_fun<int, &QFontMetrics::strikeOutPos>("strikeOutPos");
  // int lineWidth() const;
  binder.add_fun<int, &QFontMetrics::lineWidth>("lineWidth");
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
  binder.ctors().add<const QFont &>();
  // QFontMetricsF(const QFont &, QPaintDevice *);
  binder.ctors().add<const QFont &, QPaintDevice *>();
  // QFontMetricsF(const QFontMetrics &);
  binder.ctors().add<const QFontMetrics &>();
  // QFontMetricsF(const QFontMetricsF &);
  binder.ctors().add<const QFontMetricsF &>();
  // QFontMetricsF & operator=(const QFontMetricsF &);
  binder.operators().assign<const QFontMetricsF &>();
  // QFontMetricsF & operator=(const QFontMetrics &);
  binder.operators().assign<const QFontMetrics &>();
  // QFontMetricsF & operator=(QFontMetricsF &&);
  binder.operators().assign<QFontMetricsF &&>();
  // void swap(QFontMetricsF &);
  binder.add_void_fun<QFontMetricsF &, &QFontMetricsF::swap>("swap");
  // qreal ascent() const;
  binder.add_fun<qreal, &QFontMetricsF::ascent>("ascent");
  // qreal capHeight() const;
  binder.add_fun<qreal, &QFontMetricsF::capHeight>("capHeight");
  // qreal descent() const;
  binder.add_fun<qreal, &QFontMetricsF::descent>("descent");
  // qreal height() const;
  binder.add_fun<qreal, &QFontMetricsF::height>("height");
  // qreal leading() const;
  binder.add_fun<qreal, &QFontMetricsF::leading>("leading");
  // qreal lineSpacing() const;
  binder.add_fun<qreal, &QFontMetricsF::lineSpacing>("lineSpacing");
  // qreal minLeftBearing() const;
  binder.add_fun<qreal, &QFontMetricsF::minLeftBearing>("minLeftBearing");
  // qreal minRightBearing() const;
  binder.add_fun<qreal, &QFontMetricsF::minRightBearing>("minRightBearing");
  // qreal maxWidth() const;
  binder.add_fun<qreal, &QFontMetricsF::maxWidth>("maxWidth");
  // qreal xHeight() const;
  binder.add_fun<qreal, &QFontMetricsF::xHeight>("xHeight");
  // qreal averageCharWidth() const;
  binder.add_fun<qreal, &QFontMetricsF::averageCharWidth>("averageCharWidth");
  // bool inFont(QChar) const;
  binder.add_fun<bool, QChar, &QFontMetricsF::inFont>("inFont");
  // bool inFontUcs4(uint) const;
  binder.add_fun<bool, uint, &QFontMetricsF::inFontUcs4>("inFontUcs4");
  // qreal leftBearing(QChar) const;
  binder.add_fun<qreal, QChar, &QFontMetricsF::leftBearing>("leftBearing");
  // qreal rightBearing(QChar) const;
  binder.add_fun<qreal, QChar, &QFontMetricsF::rightBearing>("rightBearing");
  // qreal width(const QString &) const;
  binder.add_fun<qreal, const QString &, &QFontMetricsF::width>("width");
  // qreal width(QChar) const;
  binder.add_fun<qreal, QChar, &QFontMetricsF::width>("width");
  // QRectF boundingRect(const QString &) const;
  binder.add_fun<QRectF, const QString &, &QFontMetricsF::boundingRect>("boundingRect");
  // QRectF boundingRect(QChar) const;
  binder.add_fun<QRectF, QChar, &QFontMetricsF::boundingRect>("boundingRect");
  // QRectF boundingRect(const QRectF &, int, const QString &, int, int *) const;
  binder.add_fun<QRectF, const QRectF &, int, const QString &, int, int *, &QFontMetricsF::boundingRect>("boundingRect");
  // QSizeF size(int, const QString &, int, int *) const;
  binder.add_fun<QSizeF, int, const QString &, int, int *, &QFontMetricsF::size>("size");
  // QRectF tightBoundingRect(const QString &) const;
  binder.add_fun<QRectF, const QString &, &QFontMetricsF::tightBoundingRect>("tightBoundingRect");
  // QString elidedText(const QString &, Qt::TextElideMode, qreal, int) const;
  binder.add_fun<QString, const QString &, Qt::TextElideMode, qreal, int, &QFontMetricsF::elidedText>("elidedText");
  // qreal underlinePos() const;
  binder.add_fun<qreal, &QFontMetricsF::underlinePos>("underlinePos");
  // qreal overlinePos() const;
  binder.add_fun<qreal, &QFontMetricsF::overlinePos>("overlinePos");
  // qreal strikeOutPos() const;
  binder.add_fun<qreal, &QFontMetricsF::strikeOutPos>("strikeOutPos");
  // qreal lineWidth() const;
  binder.add_fun<qreal, &QFontMetricsF::lineWidth>("lineWidth");
  // bool operator==(const QFontMetricsF &) const;
  binder.operators().eq<const QFontMetricsF &>();
  // bool operator!=(const QFontMetricsF &) const;
  binder.operators().neq<const QFontMetricsF &>();
}

void register_fontmetrics_file(script::Namespace root)
{
  using namespace script;

  register_font_metrics_class(root);
  register_font_metrics_f_class(root);
  binding::Namespace binder{ root };

  // void swap(QFontMetrics &, QFontMetrics &);
  binder.add_void_fun<QFontMetrics &, QFontMetrics &, &swap>("swap");
  // void swap(QFontMetricsF &, QFontMetricsF &);
  binder.add_void_fun<QFontMetricsF &, QFontMetricsF &, &swap>("swap");
}

