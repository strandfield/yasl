// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/statictext.h"

#include "yasl/binding2/class.h"
#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"

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

  Enum performance_hint = static_text.newEnum("PerformanceHint").setId(script::Type::QStaticTextPerformanceHint).get();

  performance_hint.addValue("ModerateCaching", QStaticText::ModerateCaching);
  performance_hint.addValue("AggressiveCaching", QStaticText::AggressiveCaching);
}


static void register_static_text_class(script::Namespace ns)
{
  using namespace script;

  Class static_text = ns.newClass("StaticText").setId(script::Type::QStaticText).get();

  register_static_text_performance_hint_enum(static_text);

  // QStaticText();
  bind::default_constructor<QStaticText>(static_text).create();
  // QStaticText(const QString &);
  bind::constructor<QStaticText, const QString &>(static_text).create();
  // QStaticText(const QStaticText &);
  bind::constructor<QStaticText, const QStaticText &>(static_text).create();
  // QStaticText & operator=(QStaticText &&);
  bind::memop_assign<QStaticText, QStaticText &&>(static_text);
  // QStaticText & operator=(const QStaticText &);
  bind::memop_assign<QStaticText, const QStaticText &>(static_text);
  // ~QStaticText();
  bind::destructor<QStaticText>(static_text).create();
  // void swap(QStaticText &);
  bind::void_member_function<QStaticText, QStaticText &, &QStaticText::swap>(static_text, "swap").create();
  // void setText(const QString &);
  bind::void_member_function<QStaticText, const QString &, &QStaticText::setText>(static_text, "setText").create();
  // QString text() const;
  bind::member_function<QStaticText, QString, &QStaticText::text>(static_text, "text").create();
  // void setTextFormat(Qt::TextFormat);
  bind::void_member_function<QStaticText, Qt::TextFormat, &QStaticText::setTextFormat>(static_text, "setTextFormat").create();
  // Qt::TextFormat textFormat() const;
  bind::member_function<QStaticText, Qt::TextFormat, &QStaticText::textFormat>(static_text, "textFormat").create();
  // void setTextWidth(qreal);
  bind::void_member_function<QStaticText, qreal, &QStaticText::setTextWidth>(static_text, "setTextWidth").create();
  // qreal textWidth() const;
  bind::member_function<QStaticText, qreal, &QStaticText::textWidth>(static_text, "textWidth").create();
  // void setTextOption(const QTextOption &);
  bind::void_member_function<QStaticText, const QTextOption &, &QStaticText::setTextOption>(static_text, "setTextOption").create();
  // QTextOption textOption() const;
  bind::member_function<QStaticText, QTextOption, &QStaticText::textOption>(static_text, "textOption").create();
  // QSizeF size() const;
  bind::member_function<QStaticText, QSizeF, &QStaticText::size>(static_text, "size").create();
  // void prepare(const QTransform &, const QFont &);
  bind::void_member_function<QStaticText, const QTransform &, const QFont &, &QStaticText::prepare>(static_text, "prepare")
    .apply(bind::default_arguments(QFont(), QTransform())).create();
  // void setPerformanceHint(QStaticText::PerformanceHint);
  bind::void_member_function<QStaticText, QStaticText::PerformanceHint, &QStaticText::setPerformanceHint>(static_text, "setPerformanceHint").create();
  // QStaticText::PerformanceHint performanceHint() const;
  bind::member_function<QStaticText, QStaticText::PerformanceHint, &QStaticText::performanceHint>(static_text, "performanceHint").create();
  // bool operator==(const QStaticText &) const;
  bind::memop_eq<QStaticText, const QStaticText &>(static_text);
  // bool operator!=(const QStaticText &) const;
  bind::memop_neq<QStaticText, const QStaticText &>(static_text);
}


void register_statictext_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_static_text_class(ns);

  // void swap(QStaticText &, QStaticText &);
  bind::void_function<QStaticText &, QStaticText &, &swap>(ns, "swap").create();
}

