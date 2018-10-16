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
#include "yasl/gui/textoption.h"
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
  binder.ctors().ctor<const QString &>().create();
  // QStaticText(const QStaticText &);
  binder.ctors().ctor<const QStaticText &>().create();
  // QStaticText & operator=(QStaticText &&);
  binder.operators().assign<QStaticText &&>();
  // QStaticText & operator=(const QStaticText &);
  binder.operators().assign<const QStaticText &>();
  // ~QStaticText();
  binder.add_dtor();
  // void swap(QStaticText &);
  binder.void_fun<QStaticText &, &QStaticText::swap>("swap").create();
  // void setText(const QString &);
  binder.void_fun<const QString &, &QStaticText::setText>("setText").create();
  // QString text() const;
  binder.fun<QString, &QStaticText::text>("text").create();
  // void setTextFormat(Qt::TextFormat);
  binder.void_fun<Qt::TextFormat, &QStaticText::setTextFormat>("setTextFormat").create();
  // Qt::TextFormat textFormat() const;
  binder.fun<Qt::TextFormat, &QStaticText::textFormat>("textFormat").create();
  // void setTextWidth(qreal);
  binder.void_fun<qreal, &QStaticText::setTextWidth>("setTextWidth").create();
  // qreal textWidth() const;
  binder.fun<qreal, &QStaticText::textWidth>("textWidth").create();
  // void setTextOption(const QTextOption &);
  binder.void_fun<const QTextOption &, &QStaticText::setTextOption>("setTextOption").create();
  // QTextOption textOption() const;
  binder.fun<QTextOption, &QStaticText::textOption>("textOption").create();
  // QSizeF size() const;
  binder.fun<QSizeF, &QStaticText::size>("size").create();
  // void prepare(const QTransform &, const QFont &);
  binder.void_fun<const QTransform &, const QFont &, &QStaticText::prepare>("prepare").create();
  // void setPerformanceHint(QStaticText::PerformanceHint);
  binder.void_fun<QStaticText::PerformanceHint, &QStaticText::setPerformanceHint>("setPerformanceHint").create();
  // QStaticText::PerformanceHint performanceHint() const;
  binder.fun<QStaticText::PerformanceHint, &QStaticText::performanceHint>("performanceHint").create();
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
  binder.void_fun<QStaticText &, QStaticText &, &swap>("swap").create();
}

