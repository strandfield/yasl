// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/fontinfo.h"

#include "yasl/binding/class.h"
#include "yasl/binding/namespace.h"

#include "yasl/gui/font.h"
#include "yasl/gui/fontinfo.h"

#include <script/classbuilder.h>

static void register_font_info_class(script::Namespace ns)
{
  using namespace script;

  Class font_info = ns.Class("FontInfo").setId(script::Type::QFontInfo).get();

  binding::Class<QFontInfo> binder{ font_info };

  // QFontInfo(const QFont &);
  binder.ctors().ctor<const QFont &>().create();
  // QFontInfo(const QFontInfo &);
  binder.ctors().ctor<const QFontInfo &>().create();
  // ~QFontInfo();
  binder.add_dtor();
  // QFontInfo & operator=(const QFontInfo &);
  binder.operators().assign<const QFontInfo &>();
  // void swap(QFontInfo &);
  binder.void_fun<QFontInfo &, &QFontInfo::swap>("swap").create();
  // QString family() const;
  binder.fun<QString, &QFontInfo::family>("family").create();
  // QString styleName() const;
  binder.fun<QString, &QFontInfo::styleName>("styleName").create();
  // int pixelSize() const;
  binder.fun<int, &QFontInfo::pixelSize>("pixelSize").create();
  // int pointSize() const;
  binder.fun<int, &QFontInfo::pointSize>("pointSize").create();
  // qreal pointSizeF() const;
  binder.fun<qreal, &QFontInfo::pointSizeF>("pointSizeF").create();
  // bool italic() const;
  binder.fun<bool, &QFontInfo::italic>("italic").create();
  // QFont::Style style() const;
  binder.fun<QFont::Style, &QFontInfo::style>("style").create();
  // int weight() const;
  binder.fun<int, &QFontInfo::weight>("weight").create();
  // bool bold() const;
  binder.fun<bool, &QFontInfo::bold>("bold").create();
  // bool underline() const;
  binder.fun<bool, &QFontInfo::underline>("underline").create();
  // bool overline() const;
  binder.fun<bool, &QFontInfo::overline>("overline").create();
  // bool strikeOut() const;
  binder.fun<bool, &QFontInfo::strikeOut>("strikeOut").create();
  // bool fixedPitch() const;
  binder.fun<bool, &QFontInfo::fixedPitch>("fixedPitch").create();
  // QFont::StyleHint styleHint() const;
  binder.fun<QFont::StyleHint, &QFontInfo::styleHint>("styleHint").create();
  // bool rawMode() const;
  binder.fun<bool, &QFontInfo::rawMode>("rawMode").create();
  // bool exactMatch() const;
  binder.fun<bool, &QFontInfo::exactMatch>("exactMatch").create();
}


void register_fontinfo_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_info_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QFontInfo &, QFontInfo &);
  binder.void_fun<QFontInfo &, QFontInfo &, &swap>("swap").create();
}

