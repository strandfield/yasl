// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/glyphrun.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/gui/rawfont.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

static void register_glyph_run_glyph_run_flag_enum(script::Class glyph_run)
{
  using namespace script;

  Enum glyph_run_flag = glyph_run.Enum("GlyphRunFlag").setId(script::Type::QGlyphRunGlyphRunFlag).get();

  glyph_run_flag.addValue("Overline", QGlyphRun::Overline);
  glyph_run_flag.addValue("RightToLeft", QGlyphRun::RightToLeft);
  glyph_run_flag.addValue("SplitLigature", QGlyphRun::SplitLigature);
  glyph_run_flag.addValue("StrikeOut", QGlyphRun::StrikeOut);
  glyph_run_flag.addValue("Underline", QGlyphRun::Underline);
}

static void register_glyph_run_class(script::Namespace ns)
{
  using namespace script;

  Class glyph_run = ns.Class("GlyphRun").setId(script::Type::QGlyphRun).get();

  register_glyph_run_glyph_run_flag_enum(glyph_run);
  binding::Class<QGlyphRun> binder{ glyph_run };

  // ~QGlyphRun();
  binder.add_dtor();
  // QGlyphRun();
  binder.ctors().add_default();
  // QGlyphRun(const QGlyphRun &);
  binder.ctors().add<const QGlyphRun &>();
  // QGlyphRun & operator=(QGlyphRun &&);
  binder.operators().assign<QGlyphRun &&>();
  // QGlyphRun & operator=(const QGlyphRun &);
  binder.operators().assign<const QGlyphRun &>();
  // void swap(QGlyphRun &);
  binder.add_void_fun<QGlyphRun &, &QGlyphRun::swap>("swap");
  // QRawFont rawFont() const;
  binder.add_fun<QRawFont, &QGlyphRun::rawFont>("rawFont");
  // void setRawFont(const QRawFont &);
  binder.add_void_fun<const QRawFont &, &QGlyphRun::setRawFont>("setRawFont");
  // void setRawData(const quint32 *, const QPointF *, int);
  binder.add_void_fun<const quint32 *, const QPointF *, int, &QGlyphRun::setRawData>("setRawData");
  // QVector<quint32> glyphIndexes() const;
  binder.add_fun<QVector<quint32>, &QGlyphRun::glyphIndexes>("glyphIndexes");
  // void setGlyphIndexes(const QVector<quint32> &);
  binder.add_void_fun<const QVector<quint32> &, &QGlyphRun::setGlyphIndexes>("setGlyphIndexes");
  // QVector<QPointF> positions() const;
  binder.add_fun<QVector<QPointF>, &QGlyphRun::positions>("positions");
  // void setPositions(const QVector<QPointF> &);
  binder.add_void_fun<const QVector<QPointF> &, &QGlyphRun::setPositions>("setPositions");
  // void clear();
  binder.add_void_fun<&QGlyphRun::clear>("clear");
  // bool operator==(const QGlyphRun &) const;
  binder.operators().eq<const QGlyphRun &>();
  // bool operator!=(const QGlyphRun &) const;
  binder.operators().neq<const QGlyphRun &>();
  // void setOverline(bool);
  binder.add_void_fun<bool, &QGlyphRun::setOverline>("setOverline");
  // bool overline() const;
  binder.add_fun<bool, &QGlyphRun::overline>("overline");
  // void setUnderline(bool);
  binder.add_void_fun<bool, &QGlyphRun::setUnderline>("setUnderline");
  // bool underline() const;
  binder.add_fun<bool, &QGlyphRun::underline>("underline");
  // void setStrikeOut(bool);
  binder.add_void_fun<bool, &QGlyphRun::setStrikeOut>("setStrikeOut");
  // bool strikeOut() const;
  binder.add_fun<bool, &QGlyphRun::strikeOut>("strikeOut");
  // void setRightToLeft(bool);
  binder.add_void_fun<bool, &QGlyphRun::setRightToLeft>("setRightToLeft");
  // bool isRightToLeft() const;
  binder.add_fun<bool, &QGlyphRun::isRightToLeft>("isRightToLeft");
  // void setFlag(QGlyphRun::GlyphRunFlag, bool);
  binder.add_void_fun<QGlyphRun::GlyphRunFlag, bool, &QGlyphRun::setFlag>("setFlag");
  // void setFlags(QGlyphRun::GlyphRunFlags);
  binder.add_void_fun<QGlyphRun::GlyphRunFlags, &QGlyphRun::setFlags>("setFlags");
  // QGlyphRun::GlyphRunFlags flags() const;
  binder.add_fun<QGlyphRun::GlyphRunFlags, &QGlyphRun::flags>("flags");
  // void setBoundingRect(const QRectF &);
  binder.add_void_fun<const QRectF &, &QGlyphRun::setBoundingRect>("setBoundingRect");
  // QRectF boundingRect() const;
  binder.add_fun<QRectF, &QGlyphRun::boundingRect>("boundingRect");
  // bool isEmpty() const;
  binder.add_fun<bool, &QGlyphRun::isEmpty>("isEmpty");
}

void register_glyphrun_file(script::Namespace root)
{
  using namespace script;

  register_glyph_run_class(root);
  binding::Namespace binder{ root };

  // void swap(QGlyphRun &, QGlyphRun &);
  binder.add_void_fun<QGlyphRun &, QGlyphRun &, &swap>("swap");
}

