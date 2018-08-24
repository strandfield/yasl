// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/statictext.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/gui/font.h"
#include "yasl/gui/statictext.h"
#include "yasl/gui/transform.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_static_text_performance_hint_enum(script::Class static_text)
{
  using namespace script;

  Enum performance_hint = static_text.Enum("PerformanceHint").setId(script::Type::QStaticTextPerformanceHint).get();

  performance_hint.addValue("ModerateCaching", QStaticText::ModerateCaching);
  performance_hint.addValue("AggressiveCaching", QStaticText::AggressiveCaching);
}


static void register_static_text_class(script::Namespace ns)
{
  using namespace script;

  Class static_text = ns.Class("StaticText").setId(script::Type::QStaticText).get();

  register_static_text_performance_hint_enum(static_text);
  binding::Class<QStaticText> binder{ static_text };

  // QStaticText();
  binder.ctors().add_default();
  // QStaticText(const QString &);
  binder.ctors().add<const QString &>();
  // QStaticText(const QStaticText &);
  binder.ctors().add<const QStaticText &>();
  // QStaticText & operator=(QStaticText &&);
  binder.operators().assign<QStaticText &&>();
  // QStaticText & operator=(const QStaticText &);
  binder.operators().assign<const QStaticText &>();
  // ~QStaticText();
  binder.add_dtor();
  // void swap(QStaticText &);
  binder.add_void_fun<QStaticText &, &QStaticText::swap>("swap");
  // void setText(const QString &);
  binder.add_void_fun<const QString &, &QStaticText::setText>("setText");
  // QString text() const;
  binder.add_fun<QString, &QStaticText::text>("text");
  // void setTextFormat(Qt::TextFormat);
  binder.add_void_fun<Qt::TextFormat, &QStaticText::setTextFormat>("setTextFormat");
  // Qt::TextFormat textFormat() const;
  binder.add_fun<Qt::TextFormat, &QStaticText::textFormat>("textFormat");
  // void setTextWidth(qreal);
  binder.add_void_fun<qreal, &QStaticText::setTextWidth>("setTextWidth");
  // qreal textWidth() const;
  binder.add_fun<qreal, &QStaticText::textWidth>("textWidth");
  // void setTextOption(const QTextOption &);
  /// TODO: void setTextOption(const QTextOption &);
  // QTextOption textOption() const;
  /// TODO: QTextOption textOption() const;
  // QSizeF size() const;
  binder.add_fun<QSizeF, &QStaticText::size>("size");
  // void prepare(const QTransform &, const QFont &);
  binder.add_void_fun<const QTransform &, const QFont &, &QStaticText::prepare>("prepare");
  // void setPerformanceHint(QStaticText::PerformanceHint);
  binder.add_void_fun<QStaticText::PerformanceHint, &QStaticText::setPerformanceHint>("setPerformanceHint");
  // QStaticText::PerformanceHint performanceHint() const;
  binder.add_fun<QStaticText::PerformanceHint, &QStaticText::performanceHint>("performanceHint");
  // bool operator==(const QStaticText &) const;
  binder.operators().eq<const QStaticText &>();
  // bool operator!=(const QStaticText &) const;
  binder.operators().neq<const QStaticText &>();
}


void register_statictext_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_static_text_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QStaticText &, QStaticText &);
  binder.add_void_fun<QStaticText &, QStaticText &, &swap>("swap");
}

