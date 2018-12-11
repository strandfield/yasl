// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/colordialog.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"
#include "yasl/core/flags.h"

#include "yasl/core/object.h"
#include "yasl/gui/color.h"
#include "yasl/widgets/colordialog.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_color_dialog_color_dialog_option_enum(script::Class color_dialog)
{
  using namespace script;

  Enum color_dialog_option = color_dialog.newEnum("ColorDialogOption").setId(script::Type::QColorDialogColorDialogOption).get();

  register_qflags_type<QColorDialog::ColorDialogOption>(color_dialog, "ColorDialogOptions", script::Type::QColorDialogColorDialogOptions);

  color_dialog_option.addValue("ShowAlphaChannel", QColorDialog::ShowAlphaChannel);
  color_dialog_option.addValue("NoButtons", QColorDialog::NoButtons);
  color_dialog_option.addValue("DontUseNativeDialog", QColorDialog::DontUseNativeDialog);
}


static void register_color_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class color_dialog = ns.newClass("ColorDialog").setId(script::Type::QColorDialog)
    .setBase(script::Type::QDialog).get();

  register_color_dialog_color_dialog_option_enum(color_dialog);

  // QColorDialog(QWidget * = (QWidget*)nullptr);
  bind::constructor<QColorDialog, QWidget *>(color_dialog)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QColorDialog(const QColor &, QWidget * = (QWidget*)nullptr);
  bind::constructor<QColorDialog, const QColor &, QWidget *>(color_dialog)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QColorDialog();
  bind::destructor<QColorDialog>(color_dialog).create();
  // void setCurrentColor(const QColor &);
  bind::void_member_function<QColorDialog, const QColor &, &QColorDialog::setCurrentColor>(color_dialog, "setCurrentColor").create();
  // QColor currentColor() const;
  bind::member_function<QColorDialog, QColor, &QColorDialog::currentColor>(color_dialog, "currentColor").create();
  // QColor selectedColor() const;
  bind::member_function<QColorDialog, QColor, &QColorDialog::selectedColor>(color_dialog, "selectedColor").create();
  // void setOption(QColorDialog::ColorDialogOption, bool = true);
  bind::void_member_function<QColorDialog, QColorDialog::ColorDialogOption, bool, &QColorDialog::setOption>(color_dialog, "setOption")
    .apply(bind::default_arguments(true)).create();
  // bool testOption(QColorDialog::ColorDialogOption) const;
  bind::member_function<QColorDialog, bool, QColorDialog::ColorDialogOption, &QColorDialog::testOption>(color_dialog, "testOption").create();
  // void setOptions(QColorDialog::ColorDialogOptions);
  bind::void_member_function<QColorDialog, QColorDialog::ColorDialogOptions, &QColorDialog::setOptions>(color_dialog, "setOptions").create();
  // QColorDialog::ColorDialogOptions options() const;
  bind::member_function<QColorDialog, QColorDialog::ColorDialogOptions, &QColorDialog::options>(color_dialog, "options").create();
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void setVisible(bool);
  bind::void_member_function<QColorDialog, bool, &QColorDialog::setVisible>(color_dialog, "setVisible").create();
  // static QColor getColor(const QColor &, QWidget *, const QString &, QColorDialog::ColorDialogOptions);
  bind::static_member_function<QColorDialog, QColor, const QColor &, QWidget *, const QString &, QColorDialog::ColorDialogOptions, &QColorDialog::getColor>(color_dialog, "getColor").create();
  // static QRgb getRgba(QRgb, bool *, QWidget *);
  /// TODO: static QRgb getRgba(QRgb, bool *, QWidget *);
  // static int customCount();
  bind::static_member_function<QColorDialog, int, &QColorDialog::customCount>(color_dialog, "customCount").create();
  // static QColor customColor(int);
  bind::static_member_function<QColorDialog, QColor, int, &QColorDialog::customColor>(color_dialog, "customColor").create();
  // static void setCustomColor(int, QColor);
  bind::static_void_member_function<QColorDialog, int, QColor, &QColorDialog::setCustomColor>(color_dialog, "setCustomColor").create();
  // static QColor standardColor(int);
  bind::static_member_function<QColorDialog, QColor, int, &QColorDialog::standardColor>(color_dialog, "standardColor").create();
  // static void setStandardColor(int, QColor);
  bind::static_void_member_function<QColorDialog, int, QColor, &QColorDialog::setStandardColor>(color_dialog, "setStandardColor").create();
  // void currentColorChanged(const QColor &);
  bind::signal<QColorDialog, const QColor &>(color_dialog, "currentColorChanged", "currentColorChanged(const QColor &)");
  // void colorSelected(const QColor &);
  bind::signal<QColorDialog, const QColor &>(color_dialog, "colorSelected", "colorSelected(const QColor &)");

  bind::link(color_dialog, &QColorDialog::staticMetaObject);
}


void register_colordialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_color_dialog_class(ns);

  // QColorDialog::ColorDialogOptions operator|(QColorDialog::ColorDialogOption, QColorDialog::ColorDialogOption);
  bind::op_bitor<QColorDialog::ColorDialogOptions, QColorDialog::ColorDialogOption, QColorDialog::ColorDialogOption>(ns);
  // QColorDialog::ColorDialogOptions operator|(QColorDialog::ColorDialogOption, QColorDialog::ColorDialogOptions);
  bind::op_bitor<QColorDialog::ColorDialogOptions, QColorDialog::ColorDialogOption, QColorDialog::ColorDialogOptions>(ns);
  // QIncompatibleFlag operator|(QColorDialog::ColorDialogOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QColorDialog::ColorDialogOptions::enum_type, int);
}
