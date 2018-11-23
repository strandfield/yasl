// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/inputdialog.h"

#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"
#include "yasl/binding2/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/object.h"
#include "yasl/core/size.h"
#include "yasl/widgets/inputdialog.h"
#include "yasl/widgets/lineedit.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_input_dialog_input_dialog_option_enum(script::Class input_dialog)
{
  using namespace script;

  Enum input_dialog_option = input_dialog.newEnum("InputDialogOption").setId(script::Type::QInputDialogInputDialogOption).get();

  register_qflags_type<QInputDialog::InputDialogOption>(input_dialog, "InputDialogOptions", script::Type::QInputDialogInputDialogOptions);
  input_dialog_option.addValue("NoButtons", QInputDialog::NoButtons);
  input_dialog_option.addValue("UseListViewForComboBoxItems", QInputDialog::UseListViewForComboBoxItems);
  input_dialog_option.addValue("UsePlainTextEditForTextInput", QInputDialog::UsePlainTextEditForTextInput);
}


static void register_input_dialog_input_mode_enum(script::Class input_dialog)
{
  using namespace script;

  Enum input_mode = input_dialog.newEnum("InputMode").setId(script::Type::QInputDialogInputMode).get();

  input_mode.addValue("TextInput", QInputDialog::TextInput);
  input_mode.addValue("IntInput", QInputDialog::IntInput);
  input_mode.addValue("DoubleInput", QInputDialog::DoubleInput);
}


static void register_input_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class input_dialog = ns.newClass("InputDialog").setId(script::Type::QInputDialog)
    .setBase(script::Type::QDialog).get();

  register_input_dialog_input_dialog_option_enum(input_dialog);
  register_input_dialog_input_mode_enum(input_dialog);

  // QInputDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QInputDialog(QWidget *, Qt::WindowFlags);
  // ~QInputDialog();
  bind::destructor<QInputDialog>(input_dialog).create();
  // void setInputMode(QInputDialog::InputMode);
  bind::void_member_function<QInputDialog, QInputDialog::InputMode, &QInputDialog::setInputMode>(input_dialog, "setInputMode").create();
  // QInputDialog::InputMode inputMode() const;
  bind::member_function<QInputDialog, QInputDialog::InputMode, &QInputDialog::inputMode>(input_dialog, "inputMode").create();
  // void setLabelText(const QString &);
  bind::void_member_function<QInputDialog, const QString &, &QInputDialog::setLabelText>(input_dialog, "setLabelText").create();
  // QString labelText() const;
  bind::member_function<QInputDialog, QString, &QInputDialog::labelText>(input_dialog, "labelText").create();
  // void setOption(QInputDialog::InputDialogOption, bool);
  bind::void_member_function<QInputDialog, QInputDialog::InputDialogOption, bool, &QInputDialog::setOption>(input_dialog, "setOption")
    .apply(bind::default_arguments(true)).create();
  // bool testOption(QInputDialog::InputDialogOption) const;
  bind::member_function<QInputDialog, bool, QInputDialog::InputDialogOption, &QInputDialog::testOption>(input_dialog, "testOption").create();
  // void setOptions(QInputDialog::InputDialogOptions);
  bind::void_member_function<QInputDialog, QInputDialog::InputDialogOptions, &QInputDialog::setOptions>(input_dialog, "setOptions").create();
  // QInputDialog::InputDialogOptions options() const;
  bind::member_function<QInputDialog, QInputDialog::InputDialogOptions, &QInputDialog::options>(input_dialog, "options").create();
  // void setTextValue(const QString &);
  bind::void_member_function<QInputDialog, const QString &, &QInputDialog::setTextValue>(input_dialog, "setTextValue").create();
  // QString textValue() const;
  bind::member_function<QInputDialog, QString, &QInputDialog::textValue>(input_dialog, "textValue").create();
  // void setTextEchoMode(QLineEdit::EchoMode);
  bind::void_member_function<QInputDialog, QLineEdit::EchoMode, &QInputDialog::setTextEchoMode>(input_dialog, "setTextEchoMode").create();
  // QLineEdit::EchoMode textEchoMode() const;
  bind::member_function<QInputDialog, QLineEdit::EchoMode, &QInputDialog::textEchoMode>(input_dialog, "textEchoMode").create();
  // void setComboBoxEditable(bool);
  bind::void_member_function<QInputDialog, bool, &QInputDialog::setComboBoxEditable>(input_dialog, "setComboBoxEditable").create();
  // bool isComboBoxEditable() const;
  bind::member_function<QInputDialog, bool, &QInputDialog::isComboBoxEditable>(input_dialog, "isComboBoxEditable").create();
  // void setComboBoxItems(const QStringList &);
  /// TODO: void setComboBoxItems(const QStringList &);
  // QStringList comboBoxItems() const;
  /// TODO: QStringList comboBoxItems() const;
  // void setIntValue(int);
  bind::void_member_function<QInputDialog, int, &QInputDialog::setIntValue>(input_dialog, "setIntValue").create();
  // int intValue() const;
  bind::member_function<QInputDialog, int, &QInputDialog::intValue>(input_dialog, "intValue").create();
  // void setIntMinimum(int);
  bind::void_member_function<QInputDialog, int, &QInputDialog::setIntMinimum>(input_dialog, "setIntMinimum").create();
  // int intMinimum() const;
  bind::member_function<QInputDialog, int, &QInputDialog::intMinimum>(input_dialog, "intMinimum").create();
  // void setIntMaximum(int);
  bind::void_member_function<QInputDialog, int, &QInputDialog::setIntMaximum>(input_dialog, "setIntMaximum").create();
  // int intMaximum() const;
  bind::member_function<QInputDialog, int, &QInputDialog::intMaximum>(input_dialog, "intMaximum").create();
  // void setIntRange(int, int);
  bind::void_member_function<QInputDialog, int, int, &QInputDialog::setIntRange>(input_dialog, "setIntRange").create();
  // void setIntStep(int);
  bind::void_member_function<QInputDialog, int, &QInputDialog::setIntStep>(input_dialog, "setIntStep").create();
  // int intStep() const;
  bind::member_function<QInputDialog, int, &QInputDialog::intStep>(input_dialog, "intStep").create();
  // void setDoubleValue(double);
  bind::void_member_function<QInputDialog, double, &QInputDialog::setDoubleValue>(input_dialog, "setDoubleValue").create();
  // double doubleValue() const;
  bind::member_function<QInputDialog, double, &QInputDialog::doubleValue>(input_dialog, "doubleValue").create();
  // void setDoubleMinimum(double);
  bind::void_member_function<QInputDialog, double, &QInputDialog::setDoubleMinimum>(input_dialog, "setDoubleMinimum").create();
  // double doubleMinimum() const;
  bind::member_function<QInputDialog, double, &QInputDialog::doubleMinimum>(input_dialog, "doubleMinimum").create();
  // void setDoubleMaximum(double);
  bind::void_member_function<QInputDialog, double, &QInputDialog::setDoubleMaximum>(input_dialog, "setDoubleMaximum").create();
  // double doubleMaximum() const;
  bind::member_function<QInputDialog, double, &QInputDialog::doubleMaximum>(input_dialog, "doubleMaximum").create();
  // void setDoubleRange(double, double);
  bind::void_member_function<QInputDialog, double, double, &QInputDialog::setDoubleRange>(input_dialog, "setDoubleRange").create();
  // void setDoubleDecimals(int);
  bind::void_member_function<QInputDialog, int, &QInputDialog::setDoubleDecimals>(input_dialog, "setDoubleDecimals").create();
  // int doubleDecimals() const;
  bind::member_function<QInputDialog, int, &QInputDialog::doubleDecimals>(input_dialog, "doubleDecimals").create();
  // void setOkButtonText(const QString &);
  bind::void_member_function<QInputDialog, const QString &, &QInputDialog::setOkButtonText>(input_dialog, "setOkButtonText").create();
  // QString okButtonText() const;
  bind::member_function<QInputDialog, QString, &QInputDialog::okButtonText>(input_dialog, "okButtonText").create();
  // void setCancelButtonText(const QString &);
  bind::void_member_function<QInputDialog, const QString &, &QInputDialog::setCancelButtonText>(input_dialog, "setCancelButtonText").create();
  // QString cancelButtonText() const;
  bind::member_function<QInputDialog, QString, &QInputDialog::cancelButtonText>(input_dialog, "cancelButtonText").create();
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // QSize minimumSizeHint() const;
  bind::member_function<QInputDialog, QSize, &QInputDialog::minimumSizeHint>(input_dialog, "minimumSizeHint").create();
  // QSize sizeHint() const;
  bind::member_function<QInputDialog, QSize, &QInputDialog::sizeHint>(input_dialog, "sizeHint").create();
  // void setVisible(bool);
  bind::void_member_function<QInputDialog, bool, &QInputDialog::setVisible>(input_dialog, "setVisible").create();
  // static QString getText(QWidget *, const QString &, const QString &, QLineEdit::EchoMode, const QString &, bool *, Qt::WindowFlags, Qt::InputMethodHints);
  /// TODO: static QString getText(QWidget *, const QString &, const QString &, QLineEdit::EchoMode, const QString &, bool *, Qt::WindowFlags, Qt::InputMethodHints);
  // static QString getMultiLineText(QWidget *, const QString &, const QString &, const QString &, bool *, Qt::WindowFlags, Qt::InputMethodHints);
  /// TODO: static QString getMultiLineText(QWidget *, const QString &, const QString &, const QString &, bool *, Qt::WindowFlags, Qt::InputMethodHints);
  // static QString getItem(QWidget *, const QString &, const QString &, const QStringList &, int, bool, bool *, Qt::WindowFlags, Qt::InputMethodHints);
  /// TODO: static QString getItem(QWidget *, const QString &, const QString &, const QStringList &, int, bool, bool *, Qt::WindowFlags, Qt::InputMethodHints);
  // static int getInt(QWidget *, const QString &, const QString &, int, int, int, int, bool *, Qt::WindowFlags);
  /// TODO: static int getInt(QWidget *, const QString &, const QString &, int, int, int, int, bool *, Qt::WindowFlags);
  // static double getDouble(QWidget *, const QString &, const QString &, double, double, double, int, bool *, Qt::WindowFlags);
  /// TODO: static double getDouble(QWidget *, const QString &, const QString &, double, double, double, int, bool *, Qt::WindowFlags);
  // static double getDouble(QWidget *, const QString &, const QString &, double, double, double, int, bool *, Qt::WindowFlags, double);
  /// TODO: static double getDouble(QWidget *, const QString &, const QString &, double, double, double, int, bool *, Qt::WindowFlags, double);
  // void textValueChanged(const QString &);
  bind::signal<QInputDialog, const QString &>(input_dialog, "textValueChanged", "textValueChanged(const QString &)");
  // void textValueSelected(const QString &);
  bind::signal<QInputDialog, const QString &>(input_dialog, "textValueSelected", "textValueSelected(const QString &)");
  // void intValueChanged(int);
  bind::signal<QInputDialog, int>(input_dialog, "intValueChanged", "intValueChanged(int)");
  // void intValueSelected(int);
  bind::signal<QInputDialog, int>(input_dialog, "intValueSelected", "intValueSelected(int)");
  // void doubleValueChanged(double);
  bind::signal<QInputDialog, double>(input_dialog, "doubleValueChanged", "doubleValueChanged(double)");
  // void doubleValueSelected(double);
  bind::signal<QInputDialog, double>(input_dialog, "doubleValueSelected", "doubleValueSelected(double)");
  // void done(int);
  bind::void_member_function<QInputDialog, int, &QInputDialog::done>(input_dialog, "done").create();

  bind::link(input_dialog, &QInputDialog::staticMetaObject);
}


void register_inputdialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_input_dialog_class(ns);

  // QInputDialog::InputDialogOptions operator|(QInputDialog::InputDialogOption, QInputDialog::InputDialogOption);
  bind::op_bitor<QInputDialog::InputDialogOptions, QInputDialog::InputDialogOption, QInputDialog::InputDialogOption>(ns);
  // QInputDialog::InputDialogOptions operator|(QInputDialog::InputDialogOption, QInputDialog::InputDialogOptions);
  bind::op_bitor<QInputDialog::InputDialogOptions, QInputDialog::InputDialogOption, QInputDialog::InputDialogOptions>(ns);
  // QIncompatibleFlag operator|(QInputDialog::InputDialogOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QInputDialog::InputDialogOptions::enum_type, int);
}

