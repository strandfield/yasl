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

  Enum glyph_run_flag = glyph_run.newEnum("GlyphRunFlag").setId(script::Type::QGlyphRunGlyphRunFlag).get();

  glyph_run_flag.addValue("Overline", QGlyphRun::Overline);
  glyph_run_flag.addValue("Underline", QGlyphRun::Underline);
  glyph_run_flag.addValue("StrikeOut", QGlyphRun::StrikeOut);
  glyph_run_flag.addValue("RightToLeft", QGlyphRun::RightToLeft);
  glyph_run_flag.addValue("SplitLigature", QGlyphRun::SplitLigature);
}


static void register_glyph_run_class(script::Namespace ns)
{
  using namespace script;

  Class glyph_run = ns.newClass("GlyphRun").setId(script::Type::QGlyphRun).get();

  register_glyph_run_glyph_run_flag_enum(glyph_run);

  // QGlyphRun();
  bind::default_constructor<QGlyphRun>(glyph_run).create();
  // QGlyphRun(const QGlyphRun &);
  bind::constructor<QGlyphRun, const QGlyphRun &>(glyph_run).create();
  // QGlyphRun & operator=(QGlyphRun &&);
  bind::memop_assign<QGlyphRun, QGlyphRun &&>(glyph_run);
  // QGlyphRun & operator=(const QGlyphRun &);
  bind::memop_assign<QGlyphRun, const QGlyphRun &>(glyph_run);
  // ~QGlyphRun();
  bind::destructor<QGlyphRun>(glyph_run).create();
  // void swap(QGlyphRun &);
  bind::void_member_function<QGlyphRun, QGlyphRun &, &QGlyphRun::swap>(glyph_run, "swap").create();
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
  bind::void_member_function<QGlyphRun, &QGlyphRun::clear>(glyph_run, "clear").create();
  // bool operator==(const QGlyphRun &) const;
  bind::memop_eq<QGlyphRun, const QGlyphRun &>(glyph_run);
  // bool operator!=(const QGlyphRun &) const;
  bind::memop_neq<QGlyphRun, const QGlyphRun &>(glyph_run);
  // void setOverline(bool);
  bind::void_member_function<QGlyphRun, bool, &QGlyphRun::setOverline>(glyph_run, "setOverline").create();
  // bool overline() const;
  bind::member_function<QGlyphRun, bool, &QGlyphRun::overline>(glyph_run, "overline").create();
  // void setUnderline(bool);
  bind::void_member_function<QGlyphRun, bool, &QGlyphRun::setUnderline>(glyph_run, "setUnderline").create();
  // bool underline() const;
  bind::member_function<QGlyphRun, bool, &QGlyphRun::underline>(glyph_run, "underline").create();
  // void setStrikeOut(bool);
  bind::void_member_function<QGlyphRun, bool, &QGlyphRun::setStrikeOut>(glyph_run, "setStrikeOut").create();
  // bool strikeOut() const;
  bind::member_function<QGlyphRun, bool, &QGlyphRun::strikeOut>(glyph_run, "strikeOut").create();
  // void setRightToLeft(bool);
  bind::void_member_function<QGlyphRun, bool, &QGlyphRun::setRightToLeft>(glyph_run, "setRightToLeft").create();
  // bool isRightToLeft() const;
  bind::member_function<QGlyphRun, bool, &QGlyphRun::isRightToLeft>(glyph_run, "isRightToLeft").create();
  // void setFlag(QGlyphRun::GlyphRunFlag, bool);
  bind::void_member_function<QGlyphRun, QGlyphRun::GlyphRunFlag, bool, &QGlyphRun::setFlag>(glyph_run, "setFlag")
    .apply(bind::default_arguments(true)).create();
  // void setFlags(QGlyphRun::GlyphRunFlags);
  /// TODO: void setFlags(QGlyphRun::GlyphRunFlags);
  // QGlyphRun::GlyphRunFlags flags() const;
  /// TODO: QGlyphRun::GlyphRunFlags flags() const;
  // void setBoundingRect(const QRectF &);
  bind::void_member_function<QGlyphRun, const QRectF &, &QGlyphRun::setBoundingRect>(glyph_run, "setBoundingRect").create();
  // QRectF boundingRect() const;
  bind::member_function<QGlyphRun, QRectF, &QGlyphRun::boundingRect>(glyph_run, "boundingRect").create();
  // bool isEmpty() const;
  bind::member_function<QGlyphRun, bool, &QGlyphRun::isEmpty>(glyph_run, "isEmpty").create();
}


void register_glyphrun_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_glyph_run_class(ns);

  // void swap(QGlyphRun &, QGlyphRun &);
  bind::void_function<QGlyphRun &, QGlyphRun &, &swap>(ns, "swap").create();
}

