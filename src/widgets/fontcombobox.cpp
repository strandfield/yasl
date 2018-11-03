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

  Enum font_filter = font_combo_box.Enum("FontFilter").setId(script::Type::QFontComboBoxFontFilter).get();

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

  Class font_combo_box = ns.Class("FontComboBox").setId(script::Type::QFontComboBox)
    .setBase(script::Type::QComboBox).get();

  register_font_combo_box_font_filter_enum(font_combo_box);
  binding::ClassBinder<QFontComboBox> binder{ font_combo_box, &QFontComboBox::staticMetaObject };

  // QFontComboBox(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QFontComboBox();
  binder.dtor().create();
  // void setWritingSystem(QFontDatabase::WritingSystem);
  binder.void_fun<QFontDatabase::WritingSystem, &QFontComboBox::setWritingSystem>("setWritingSystem").create();
  // QFontDatabase::WritingSystem writingSystem() const;
  binder.fun<QFontDatabase::WritingSystem, &QFontComboBox::writingSystem>("writingSystem").create();
  // void setFontFilters(QFontComboBox::FontFilters);
  binder.void_fun<QFontComboBox::FontFilters, &QFontComboBox::setFontFilters>("setFontFilters").create();
  // QFontComboBox::FontFilters fontFilters() const;
  binder.fun<QFontComboBox::FontFilters, &QFontComboBox::fontFilters>("fontFilters").create();
  // QFont currentFont() const;
  binder.fun<QFont, &QFontComboBox::currentFont>("currentFont").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QFontComboBox::sizeHint>("sizeHint").create();
  // void setCurrentFont(const QFont &);
  binder.void_fun<const QFont &, &QFontComboBox::setCurrentFont>("setCurrentFont").create();
  // void currentFontChanged(const QFont &);
  binder.sigs().add<const QFont &>("currentFontChanged", "currentFontChanged(const QFont &)");

  font_combo_box.engine()->registerQtType(&QFontComboBox::staticMetaObject, font_combo_box.id());
}


void register_fontcombobox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_font_combo_box_class(ns);
  binding::Namespace binder{ ns };

  // QFlags<QFontComboBox::FontFilters::enum_type> operator|(QFontComboBox::FontFilters::enum_type, QFontComboBox::FontFilters::enum_type);
  /// TODO: QFlags<QFontComboBox::FontFilters::enum_type> operator|(QFontComboBox::FontFilters::enum_type, QFontComboBox::FontFilters::enum_type);
  // QFlags<QFontComboBox::FontFilters::enum_type> operator|(QFontComboBox::FontFilters::enum_type, QFlags<QFontComboBox::FontFilters::enum_type>);
  /// TODO: QFlags<QFontComboBox::FontFilters::enum_type> operator|(QFontComboBox::FontFilters::enum_type, QFlags<QFontComboBox::FontFilters::enum_type>);
  // QIncompatibleFlag operator|(QFontComboBox::FontFilters::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QFontComboBox::FontFilters::enum_type, int);
  // QFontComboBox& newFontComboBox(QWidget*);
  NewFunction(binder).add<QFontComboBox, QWidget*>("newFontComboBox");
}

