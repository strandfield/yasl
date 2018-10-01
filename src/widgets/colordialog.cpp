// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/colordialog.h"

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

  Enum color_dialog_option = color_dialog.Enum("ColorDialogOption").setId(script::Type::QColorDialogColorDialogOption).get();

  register_qflags_type<QColorDialog::ColorDialogOption>(color_dialog, "ColorDialogOptions", script::Type::QColorDialogColorDialogOptions);
  color_dialog_option.addValue("ShowAlphaChannel", QColorDialog::ShowAlphaChannel);
  color_dialog_option.addValue("NoButtons", QColorDialog::NoButtons);
  color_dialog_option.addValue("DontUseNativeDialog", QColorDialog::DontUseNativeDialog);
}


static void register_color_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class color_dialog = ns.Class("ColorDialog").setId(script::Type::QColorDialog)
    .setBase(script::Type::QDialog).get();

  register_color_dialog_color_dialog_option_enum(color_dialog);
  binding::QClass<QColorDialog> binder{ color_dialog, &QColorDialog::staticMetaObject };

  // QColorDialog(QWidget *);
  binder.ctors().add<QWidget *>();
  // QColorDialog(const QColor &, QWidget *);
  binder.ctors().add<const QColor &, QWidget *>();
  // ~QColorDialog();
  binder.add_dtor();
  // void setCurrentColor(const QColor &);
  binder.add_void_fun<const QColor &, &QColorDialog::setCurrentColor>("setCurrentColor");
  // QColor currentColor() const;
  binder.add_fun<QColor, &QColorDialog::currentColor>("currentColor");
  // QColor selectedColor() const;
  binder.add_fun<QColor, &QColorDialog::selectedColor>("selectedColor");
  // void setOption(QColorDialog::ColorDialogOption, bool);
  binder.add_void_fun<QColorDialog::ColorDialogOption, bool, &QColorDialog::setOption>("setOption");
  // bool testOption(QColorDialog::ColorDialogOption) const;
  binder.add_fun<bool, QColorDialog::ColorDialogOption, &QColorDialog::testOption>("testOption");
  // void setOptions(QColorDialog::ColorDialogOptions);
  binder.add_void_fun<QColorDialog::ColorDialogOptions, &QColorDialog::setOptions>("setOptions");
  // QColorDialog::ColorDialogOptions options() const;
  binder.add_fun<QColorDialog::ColorDialogOptions, &QColorDialog::options>("options");
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void setVisible(bool);
  binder.add_void_fun<bool, &QColorDialog::setVisible>("setVisible");
  // static QColor getColor(const QColor &, QWidget *, const QString &, QColorDialog::ColorDialogOptions);
  binder.add_static<QColor, const QColor &, QWidget *, const QString &, QColorDialog::ColorDialogOptions, &QColorDialog::getColor>("getColor");
  // static QRgb getRgba(QRgb, bool *, QWidget *);
  /// TODO: static QRgb getRgba(QRgb, bool *, QWidget *);
  // static int customCount();
  binder.add_static<int, &QColorDialog::customCount>("customCount");
  // static QColor customColor(int);
  binder.add_static<QColor, int, &QColorDialog::customColor>("customColor");
  // static void setCustomColor(int, QColor);
  binder.add_static_void_fun<int, QColor, &QColorDialog::setCustomColor>("setCustomColor");
  // static QColor standardColor(int);
  binder.add_static<QColor, int, &QColorDialog::standardColor>("standardColor");
  // static void setStandardColor(int, QColor);
  binder.add_static_void_fun<int, QColor, &QColorDialog::setStandardColor>("setStandardColor");
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

