// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/fontdialog.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/object.h"
#include "yasl/gui/font.h"
#include "yasl/widgets/fontdialog.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_font_dialog_font_dialog_option_enum(script::Class font_dialog)
{
  using namespace script;

  Enum font_dialog_option = font_dialog.Enum("FontDialogOption").setId(script::Type::QFontDialogFontDialogOption).get();

  register_qflags_type<QFontDialog::FontDialogOption>(font_dialog, "FontDialogOptions", script::Type::QFontDialogFontDialogOptions);
  font_dialog_option.addValue("NoButtons", QFontDialog::NoButtons);
  font_dialog_option.addValue("DontUseNativeDialog", QFontDialog::DontUseNativeDialog);
  font_dialog_option.addValue("ScalableFonts", QFontDialog::ScalableFonts);
  font_dialog_option.addValue("NonScalableFonts", QFontDialog::NonScalableFonts);
  font_dialog_option.addValue("MonospacedFonts", QFontDialog::MonospacedFonts);
  font_dialog_option.addValue("ProportionalFonts", QFontDialog::ProportionalFonts);
}


static void register_font_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class font_dialog = ns.Class("FontDialog").setId(script::Type::QFontDialog)
    .setBase(script::Type::QDialog).get();

  register_font_dialog_font_dialog_option_enum(font_dialog);
  binding::QClass<QFontDialog> binder{ font_dialog, &QFontDialog::staticMetaObject };

  // QFontDialog(QWidget *);
  binder.ctors().add<QWidget *>();
  // QFontDialog(const QFont &, QWidget *);
  binder.ctors().add<const QFont &, QWidget *>();
  // ~QFontDialog();
  binder.add_dtor();
  // void setCurrentFont(const QFont &);
  binder.add_void_fun<const QFont &, &QFontDialog::setCurrentFont>("setCurrentFont");
  // QFont currentFont() const;
  binder.add_fun<QFont, &QFontDialog::currentFont>("currentFont");
  // QFont selectedFont() const;
  binder.add_fun<QFont, &QFontDialog::selectedFont>("selectedFont");
  // void setOption(QFontDialog::FontDialogOption, bool);
  binder.add_void_fun<QFontDialog::FontDialogOption, bool, &QFontDialog::setOption>("setOption");
  // bool testOption(QFontDialog::FontDialogOption) const;
  binder.add_fun<bool, QFontDialog::FontDialogOption, &QFontDialog::testOption>("testOption");
  // void setOptions(QFontDialog::FontDialogOptions);
  binder.add_void_fun<QFontDialog::FontDialogOptions, &QFontDialog::setOptions>("setOptions");
  // QFontDialog::FontDialogOptions options() const;
  binder.add_fun<QFontDialog::FontDialogOptions, &QFontDialog::options>("options");
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void setVisible(bool);
  binder.add_void_fun<bool, &QFontDialog::setVisible>("setVisible");
  // static QFont getFont(bool *, QWidget *);
  /// TODO: static QFont getFont(bool *, QWidget *);
  // static QFont getFont(bool *, const QFont &, QWidget *, const QString &, QFontDialog::FontDialogOptions);
  /// TODO: static QFont getFont(bool *, const QFont &, QWidget *, const QString &, QFontDialog::FontDialogOptions);
  // void currentFontChanged(const QFont &);
  binder.sigs().add<const QFont &>("currentFontChanged", "currentFontChanged(const QFont &)");
  // void fontSelected(const QFont &);
  binder.sigs().add<const QFont &>("fontSelected", "fontSelected(const QFont &)");

  font_dialog.engine()->registerQtType(&QFontDialog::staticMetaObject, font_dialog.id());
}


void register_fontdialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_font_dialog_class(ns);
  binding::Namespace binder{ ns };

  // QFontDialog::FontDialogOptions operator|(QFontDialog::FontDialogOption, QFontDialog::FontDialogOption);
  binder.operators().or<QFontDialog::FontDialogOptions, QFontDialog::FontDialogOption, QFontDialog::FontDialogOption>();
  // QFontDialog::FontDialogOptions operator|(QFontDialog::FontDialogOption, QFontDialog::FontDialogOptions);
  binder.operators().or<QFontDialog::FontDialogOptions, QFontDialog::FontDialogOption, QFontDialog::FontDialogOptions>();
  // QIncompatibleFlag operator|(QFontDialog::FontDialogOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QFontDialog::FontDialogOptions::enum_type, int);
}

