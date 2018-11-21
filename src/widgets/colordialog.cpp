// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/colordialog.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
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
  binding::ClassBinder<QColorDialog> binder{ color_dialog, &QColorDialog::staticMetaObject };

  // QColorDialog(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QColorDialog(const QColor &, QWidget *);
  binder.ctor<const QColor &, QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QColorDialog();
  binder.dtor().create();
  // void setCurrentColor(const QColor &);
  binder.void_fun<const QColor &, &QColorDialog::setCurrentColor>("setCurrentColor").create();
  // QColor currentColor() const;
  binder.fun<QColor, &QColorDialog::currentColor>("currentColor").create();
  // QColor selectedColor() const;
  binder.fun<QColor, &QColorDialog::selectedColor>("selectedColor").create();
  // void setOption(QColorDialog::ColorDialogOption, bool);
  binder.void_fun<QColorDialog::ColorDialogOption, bool, &QColorDialog::setOption>("setOption")
    .apply(binding::default_arguments(true)).create();
  // bool testOption(QColorDialog::ColorDialogOption) const;
  binder.fun<bool, QColorDialog::ColorDialogOption, &QColorDialog::testOption>("testOption").create();
  // void setOptions(QColorDialog::ColorDialogOptions);
  binder.void_fun<QColorDialog::ColorDialogOptions, &QColorDialog::setOptions>("setOptions").create();
  // QColorDialog::ColorDialogOptions options() const;
  binder.fun<QColorDialog::ColorDialogOptions, &QColorDialog::options>("options").create();
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void setVisible(bool);
  binder.void_fun<bool, &QColorDialog::setVisible>("setVisible").create();
  // static QColor getColor(const QColor &, QWidget *, const QString &, QColorDialog::ColorDialogOptions);
  binder.static_fun<QColor, const QColor &, QWidget *, const QString &, QColorDialog::ColorDialogOptions, &QColorDialog::getColor>("getColor").create();
  // static QRgb getRgba(QRgb, bool *, QWidget *);
  /// TODO: static QRgb getRgba(QRgb, bool *, QWidget *);
  // static int customCount();
  binder.static_fun<int, &QColorDialog::customCount>("customCount").create();
  // static QColor customColor(int);
  binder.static_fun<QColor, int, &QColorDialog::customColor>("customColor").create();
  // static void setCustomColor(int, QColor);
  binder.static_void_fun<int, QColor, &QColorDialog::setCustomColor>("setCustomColor").create();
  // static QColor standardColor(int);
  binder.static_fun<QColor, int, &QColorDialog::standardColor>("standardColor").create();
  // static void setStandardColor(int, QColor);
  binder.static_void_fun<int, QColor, &QColorDialog::setStandardColor>("setStandardColor").create();
  // void currentColorChanged(const QColor &);
  binder.sigs().add<const QColor &>("currentColorChanged", "currentColorChanged(const QColor &)");
  // void colorSelected(const QColor &);
  binder.sigs().add<const QColor &>("colorSelected", "colorSelected(const QColor &)");

  color_dialog.engine()->registerQtType(&QColorDialog::staticMetaObject, color_dialog.id());
}


void register_colordialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_color_dialog_class(ns);
  binding::Namespace binder{ ns };

  // QColorDialog::ColorDialogOptions operator|(QColorDialog::ColorDialogOption, QColorDialog::ColorDialogOption);
  binder.operators().or<QColorDialog::ColorDialogOptions, QColorDialog::ColorDialogOption, QColorDialog::ColorDialogOption>();
  // QColorDialog::ColorDialogOptions operator|(QColorDialog::ColorDialogOption, QColorDialog::ColorDialogOptions);
  binder.operators().or<QColorDialog::ColorDialogOptions, QColorDialog::ColorDialogOption, QColorDialog::ColorDialogOptions>();
  // QIncompatibleFlag operator|(QColorDialog::ColorDialogOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QColorDialog::ColorDialogOptions::enum_type, int);
}

