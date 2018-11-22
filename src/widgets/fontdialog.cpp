// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/fontdialog.h"

#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"
#include "yasl/binding2/qclass.h"
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

  Enum font_dialog_option = font_dialog.newEnum("FontDialogOption").setId(script::Type::QFontDialogFontDialogOption).get();

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

  Class font_dialog = ns.newClass("FontDialog").setId(script::Type::QFontDialog)
    .setBase(script::Type::QDialog).get();

  register_font_dialog_font_dialog_option_enum(font_dialog);

  // QFontDialog(QWidget *);
  bind::constructor<QFontDialog, QWidget *>(font_dialog)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QFontDialog(const QFont &, QWidget *);
  bind::constructor<QFontDialog, const QFont &, QWidget *>(font_dialog)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QFontDialog();
  bind::destructor<QFontDialog>(font_dialog).create();
  // void setCurrentFont(const QFont &);
  bind::void_member_function<QFontDialog, const QFont &, &QFontDialog::setCurrentFont>(font_dialog, "setCurrentFont").create();
  // QFont currentFont() const;
  bind::member_function<QFontDialog, QFont, &QFontDialog::currentFont>(font_dialog, "currentFont").create();
  // QFont selectedFont() const;
  bind::member_function<QFontDialog, QFont, &QFontDialog::selectedFont>(font_dialog, "selectedFont").create();
  // void setOption(QFontDialog::FontDialogOption, bool);
  bind::void_member_function<QFontDialog, QFontDialog::FontDialogOption, bool, &QFontDialog::setOption>(font_dialog, "setOption")
    .apply(bind::default_arguments(true)).create();
  // bool testOption(QFontDialog::FontDialogOption) const;
  bind::member_function<QFontDialog, bool, QFontDialog::FontDialogOption, &QFontDialog::testOption>(font_dialog, "testOption").create();
  // void setOptions(QFontDialog::FontDialogOptions);
  bind::void_member_function<QFontDialog, QFontDialog::FontDialogOptions, &QFontDialog::setOptions>(font_dialog, "setOptions").create();
  // QFontDialog::FontDialogOptions options() const;
  bind::member_function<QFontDialog, QFontDialog::FontDialogOptions, &QFontDialog::options>(font_dialog, "options").create();
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void setVisible(bool);
  bind::void_member_function<QFontDialog, bool, &QFontDialog::setVisible>(font_dialog, "setVisible").create();
  // static QFont getFont(bool *, QWidget *);
  /// TODO: static QFont getFont(bool *, QWidget *);
  // static QFont getFont(bool *, const QFont &, QWidget *, const QString &, QFontDialog::FontDialogOptions);
  /// TODO: static QFont getFont(bool *, const QFont &, QWidget *, const QString &, QFontDialog::FontDialogOptions);
  // void currentFontChanged(const QFont &);
  bind::signal<QFontDialog, const QFont &>(font_dialog, "currentFontChanged", "currentFontChanged(const QFont &)");
  // void fontSelected(const QFont &);
  bind::signal<QFontDialog, const QFont &>(font_dialog, "fontSelected", "fontSelected(const QFont &)");

  bind::link(font_dialog, &QFontDialog::staticMetaObject);
}


void register_fontdialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_font_dialog_class(ns);

  // QFontDialog::FontDialogOptions operator|(QFontDialog::FontDialogOption, QFontDialog::FontDialogOption);
  bind::op_bitor<QFontDialog::FontDialogOptions, QFontDialog::FontDialogOption, QFontDialog::FontDialogOption>(ns);
  // QFontDialog::FontDialogOptions operator|(QFontDialog::FontDialogOption, QFontDialog::FontDialogOptions);
  bind::op_bitor<QFontDialog::FontDialogOptions, QFontDialog::FontDialogOption, QFontDialog::FontDialogOptions>(ns);
  // QIncompatibleFlag operator|(QFontDialog::FontDialogOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QFontDialog::FontDialogOptions::enum_type, int);
}

