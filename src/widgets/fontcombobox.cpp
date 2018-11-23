// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/fontcombobox.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/size.h"
#include "yasl/gui/font.h"
#include "yasl/gui/fontdatabase.h"
#include "yasl/widgets/fontcombobox.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_font_combo_box_font_filter_enum(script::Class font_combo_box)
{
  using namespace script;

  Enum font_filter = font_combo_box.newEnum("FontFilter").setId(script::Type::QFontComboBoxFontFilter).get();

  register_qflags_type<QFontComboBox::FontFilter>(font_combo_box, "FontFilters", script::Type::QFontComboBoxFontFilters);
  font_filter.addValue("AllFonts", QFontComboBox::AllFonts);
  font_filter.addValue("ScalableFonts", QFontComboBox::ScalableFonts);
  font_filter.addValue("NonScalableFonts", QFontComboBox::NonScalableFonts);
  font_filter.addValue("MonospacedFonts", QFontComboBox::MonospacedFonts);
  font_filter.addValue("ProportionalFonts", QFontComboBox::ProportionalFonts);
}


static void register_font_combo_box_class(script::Namespace ns)
{
  using namespace script;

  Class font_combo_box = ns.newClass("FontComboBox").setId(script::Type::QFontComboBox)
    .setBase(script::Type::QComboBox).get();

  register_font_combo_box_font_filter_enum(font_combo_box);

  // QFontComboBox(QWidget *);
  bind::constructor<QFontComboBox, QWidget *>(font_combo_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QFontComboBox();
  bind::destructor<QFontComboBox>(font_combo_box).create();
  // void setWritingSystem(QFontDatabase::WritingSystem);
  bind::void_member_function<QFontComboBox, QFontDatabase::WritingSystem, &QFontComboBox::setWritingSystem>(font_combo_box, "setWritingSystem").create();
  // QFontDatabase::WritingSystem writingSystem() const;
  bind::member_function<QFontComboBox, QFontDatabase::WritingSystem, &QFontComboBox::writingSystem>(font_combo_box, "writingSystem").create();
  // void setFontFilters(QFontComboBox::FontFilters);
  bind::void_member_function<QFontComboBox, QFontComboBox::FontFilters, &QFontComboBox::setFontFilters>(font_combo_box, "setFontFilters").create();
  // QFontComboBox::FontFilters fontFilters() const;
  bind::member_function<QFontComboBox, QFontComboBox::FontFilters, &QFontComboBox::fontFilters>(font_combo_box, "fontFilters").create();
  // QFont currentFont() const;
  bind::member_function<QFontComboBox, QFont, &QFontComboBox::currentFont>(font_combo_box, "currentFont").create();
  // QSize sizeHint() const;
  bind::member_function<QFontComboBox, QSize, &QFontComboBox::sizeHint>(font_combo_box, "sizeHint").create();
  // void setCurrentFont(const QFont &);
  bind::void_member_function<QFontComboBox, const QFont &, &QFontComboBox::setCurrentFont>(font_combo_box, "setCurrentFont").create();
  // void currentFontChanged(const QFont &);
  bind::signal<QFontComboBox, const QFont &>(font_combo_box, "currentFontChanged", "currentFontChanged(const QFont &)");

  bind::link(font_combo_box, &QFontComboBox::staticMetaObject);
}


void register_fontcombobox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_font_combo_box_class(ns);

  // QFlags<QFontComboBox::FontFilters::enum_type> operator|(QFontComboBox::FontFilters::enum_type, QFontComboBox::FontFilters::enum_type);
  /// TODO: QFlags<QFontComboBox::FontFilters::enum_type> operator|(QFontComboBox::FontFilters::enum_type, QFontComboBox::FontFilters::enum_type);
  // QFlags<QFontComboBox::FontFilters::enum_type> operator|(QFontComboBox::FontFilters::enum_type, QFlags<QFontComboBox::FontFilters::enum_type>);
  /// TODO: QFlags<QFontComboBox::FontFilters::enum_type> operator|(QFontComboBox::FontFilters::enum_type, QFlags<QFontComboBox::FontFilters::enum_type>);
  // QIncompatibleFlag operator|(QFontComboBox::FontFilters::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QFontComboBox::FontFilters::enum_type, int);
  // QFontComboBox& newFontComboBox(QWidget*);
  bind::new_function<QFontComboBox, QWidget*>(ns, "newFontComboBox");
}

