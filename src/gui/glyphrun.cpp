// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/glyphrun.h"

#include "yasl/binding/class.h"
#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/rect.h"
#include "yasl/gui/glyphrun.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_glyph_run_glyph_run_flag_enum(script::Class glyph_run)
{
  using namespace script;

  Enum glyph_run_flag = glyph_run.Enum("GlyphRunFlag").setId(script::Type::QGlyphRunGlyphRunFlag).get();

  glyph_run_flag.addValue("Overline", QGlyphRun::Overline);
  glyph_run_flag.addValue("Underline", QGlyphRun::Underline);
  glyph_run_flag.addValue("StrikeOut", QGlyphRun::StrikeOut);
  glyph_run_flag.addValue("RightToLeft", QGlyphRun::RightToLeft);
  glyph_run_flag.addValue("SplitLigature", QGlyphRun::SplitLigature);
}


static void register_glyph_run_class(script::Namespace ns)
{
  using namespace script;

  Class glyph_run = ns.Class("GlyphRun").setId(script::Type::QGlyphRun).get();

  register_glyph_run_glyph_run_flag_enum(glyph_run);
  binding::ClassBinder<QGlyphRun> binder{ glyph_run };

  // QGlyphRun();
  binder.default_ctor().create();
  // QGlyphRun(const QGlyphRun &);
  binder.ctor<const QGlyphRun &>().create();
  // QGlyphRun & operator=(QGlyphRun &&);
  binder.operators().assign<QGlyphRun &&>();
  // QGlyphRun & operator=(const QGlyphRun &);
  binder.operators().assign<const QGlyphRun &>();
  // ~QGlyphRun();
  binder.dtor().create();
  // void swap(QGlyphRun &);
  binder.void_fun<QGlyphRun &, &QGlyphRun::swap>("swap").create();
  // QRawFont rawFont() const;
  /// TODO: QRawFont rawFont() const;
  // void setRawFont(const QRawFont &);
  /// TODO: void setRawFont(const QRawFont &);
  // void setRawData(const quint32 *, const QPointF *, int);
  /// TODO: void setRawData(const quint32 *, const QPointF *, int);
  // QVector<quint32> glyphIndexes() const;
  /// TODO: QVector<quint32> glyphIndexes() const;
  // void setGlyphIndexes(const QVector<quint32> &);
  /// TODO: void setGlyphIndexes(const QVector<quint32> &);
  // QVector<QPointF> positions() const;
  /// TODO: QVector<QPointF> positions() const;
  // void setPositions(const QVector<QPointF> &);
  /// TODO: void setPositions(const QVector<QPointF> &);
  // void clear();
  binder.void_fun<&QGlyphRun::clear>("clear").create();
  // bool operator==(const QGlyphRun &) const;
  binder.operators().eq<const QGlyphRun &>();
  // bool operator!=(const QGlyphRun &) const;
  binder.operators().neq<const QGlyphRun &>();
  // void setOverline(bool);
  binder.void_fun<bool, &QGlyphRun::setOverline>("setOverline").create();
  // bool overline() const;
  binder.fun<bool, &QGlyphRun::overline>("overline").create();
  // void setUnderline(bool);
  binder.void_fun<bool, &QGlyphRun::setUnderline>("setUnderline").create();
  // bool underline() const;
  binder.fun<bool, &QGlyphRun::underline>("underline").create();
  // void setStrikeOut(bool);
  binder.void_fun<bool, &QGlyphRun::setStrikeOut>("setStrikeOut").create();
  // bool strikeOut() const;
  binder.fun<bool, &QGlyphRun::strikeOut>("strikeOut").create();
  // void setRightToLeft(bool);
  binder.void_fun<bool, &QGlyphRun::setRightToLeft>("setRightToLeft").create();
  // bool isRightToLeft() const;
  binder.fun<bool, &QGlyphRun::isRightToLeft>("isRightToLeft").create();
  // void setFlag(QGlyphRun::GlyphRunFlag, bool);
  binder.void_fun<QGlyphRun::GlyphRunFlag, bool, &QGlyphRun::setFlag>("setFlag")
    .apply(binding::default_arguments(true)).create();
  // void setFlags(QGlyphRun::GlyphRunFlags);
  /// TODO: void setFlags(QGlyphRun::GlyphRunFlags);
  // QGlyphRun::GlyphRunFlags flags() const;
  /// TODO: QGlyphRun::GlyphRunFlags flags() const;
  // void setBoundingRect(const QRectF &);
  binder.void_fun<const QRectF &, &QGlyphRun::setBoundingRect>("setBoundingRect").create();
  // QRectF boundingRect() const;
  binder.fun<QRectF, &QGlyphRun::boundingRect>("boundingRect").create();
  // bool isEmpty() const;
  binder.fun<bool, &QGlyphRun::isEmpty>("isEmpty").create();
}


void register_glyphrun_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_glyph_run_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QGlyphRun &, QGlyphRun &);
  binder.void_fun<QGlyphRun &, QGlyphRun &, &swap>("swap").create();
}

