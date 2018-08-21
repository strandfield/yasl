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
  binder.ctors().add<const QFont &>();
  // QFontInfo(const QFontInfo &);
  binder.ctors().add<const QFontInfo &>();
  // ~QFontInfo();
  binder.add_dtor();
  // QFontInfo & operator=(const QFontInfo &);
  binder.operators().assign<const QFontInfo &>();
  // void swap(QFontInfo &);
  binder.add_void_fun<QFontInfo &, &QFontInfo::swap>("swap");
  // QString family() const;
  binder.add_fun<QString, &QFontInfo::family>("family");
  // QString styleName() const;
  binder.add_fun<QString, &QFontInfo::styleName>("styleName");
  // int pixelSize() const;
  binder.add_fun<int, &QFontInfo::pixelSize>("pixelSize");
  // int pointSize() const;
  binder.add_fun<int, &QFontInfo::pointSize>("pointSize");
  // qreal pointSizeF() const;
  binder.add_fun<qreal, &QFontInfo::pointSizeF>("pointSizeF");
  // bool italic() const;
  binder.add_fun<bool, &QFontInfo::italic>("italic");
  // QFont::Style style() const;
  binder.add_fun<QFont::Style, &QFontInfo::style>("style");
  // int weight() const;
  binder.add_fun<int, &QFontInfo::weight>("weight");
  // bool bold() const;
  binder.add_fun<bool, &QFontInfo::bold>("bold");
  // bool underline() const;
  binder.add_fun<bool, &QFontInfo::underline>("underline");
  // bool overline() const;
  binder.add_fun<bool, &QFontInfo::overline>("overline");
  // bool strikeOut() const;
  binder.add_fun<bool, &QFontInfo::strikeOut>("strikeOut");
  // bool fixedPitch() const;
  binder.add_fun<bool, &QFontInfo::fixedPitch>("fixedPitch");
  // QFont::StyleHint styleHint() const;
  binder.add_fun<QFont::StyleHint, &QFontInfo::styleHint>("styleHint");
  // bool rawMode() const;
  binder.add_fun<bool, &QFontInfo::rawMode>("rawMode");
  // bool exactMatch() const;
  binder.add_fun<bool, &QFontInfo::exactMatch>("exactMatch");
}


void register_fontinfo_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_info_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QFontInfo &, QFontInfo &);
  binder.add_void_fun<QFontInfo &, QFontInfo &, &swap>("swap");
}

