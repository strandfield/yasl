// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/fontinfo.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/binding/namespace.h"

#include "yasl/gui/font.h"
#include "yasl/gui/fontinfo.h"

#include <script/classbuilder.h>

static void register_font_info_class(script::Namespace ns)
{
  using namespace script;

  Class font_info = ns.newClass("FontInfo").setId(script::Type::QFontInfo).get();


  // QFontInfo(const QFont &);
  bind::constructor<QFontInfo, const QFont &>(font_info).create();
  // QFontInfo(const QFontInfo &);
  bind::constructor<QFontInfo, const QFontInfo &>(font_info).create();
  // ~QFontInfo();
  bind::destructor<QFontInfo>(font_info).create();
  // QFontInfo & operator=(const QFontInfo &);
  bind::memop_assign<QFontInfo, const QFontInfo &>(font_info);
  // void swap(QFontInfo &);
  bind::void_member_function<QFontInfo, QFontInfo &, &QFontInfo::swap>(font_info, "swap").create();
  // QString family() const;
  bind::member_function<QFontInfo, QString, &QFontInfo::family>(font_info, "family").create();
  // QString styleName() const;
  bind::member_function<QFontInfo, QString, &QFontInfo::styleName>(font_info, "styleName").create();
  // int pixelSize() const;
  bind::member_function<QFontInfo, int, &QFontInfo::pixelSize>(font_info, "pixelSize").create();
  // int pointSize() const;
  bind::member_function<QFontInfo, int, &QFontInfo::pointSize>(font_info, "pointSize").create();
  // qreal pointSizeF() const;
  bind::member_function<QFontInfo, qreal, &QFontInfo::pointSizeF>(font_info, "pointSizeF").create();
  // bool italic() const;
  bind::member_function<QFontInfo, bool, &QFontInfo::italic>(font_info, "italic").create();
  // QFont::Style style() const;
  bind::member_function<QFontInfo, QFont::Style, &QFontInfo::style>(font_info, "style").create();
  // int weight() const;
  bind::member_function<QFontInfo, int, &QFontInfo::weight>(font_info, "weight").create();
  // bool bold() const;
  bind::member_function<QFontInfo, bool, &QFontInfo::bold>(font_info, "bold").create();
  // bool underline() const;
  bind::member_function<QFontInfo, bool, &QFontInfo::underline>(font_info, "underline").create();
  // bool overline() const;
  bind::member_function<QFontInfo, bool, &QFontInfo::overline>(font_info, "overline").create();
  // bool strikeOut() const;
  bind::member_function<QFontInfo, bool, &QFontInfo::strikeOut>(font_info, "strikeOut").create();
  // bool fixedPitch() const;
  bind::member_function<QFontInfo, bool, &QFontInfo::fixedPitch>(font_info, "fixedPitch").create();
  // QFont::StyleHint styleHint() const;
  bind::member_function<QFontInfo, QFont::StyleHint, &QFontInfo::styleHint>(font_info, "styleHint").create();
  // bool rawMode() const;
  bind::member_function<QFontInfo, bool, &QFontInfo::rawMode>(font_info, "rawMode").create();
  // bool exactMatch() const;
  bind::member_function<QFontInfo, bool, &QFontInfo::exactMatch>(font_info, "exactMatch").create();
}


void register_fontinfo_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_font_info_class(ns);

}
