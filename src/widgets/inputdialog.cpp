// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/inputdialog.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"
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

  Enum input_dialog_option = input_dialog.Enum("InputDialogOption").setId(script::Type::QInputDialogInputDialogOption).get();

  register_qflags_type<QInputDialog::InputDialogOption>(input_dialog, "InputDialogOptions", script::Type::QInputDialogInputDialogOptions);
  input_dialog_option.addValue("NoButtons", QInputDialog::NoButtons);
  input_dialog_option.addValue("UseListViewForComboBoxItems", QInputDialog::UseListViewForComboBoxItems);
  input_dialog_option.addValue("UsePlainTextEditForTextInput", QInputDialog::UsePlainTextEditForTextInput);
}


static void register_input_dialog_input_mode_enum(script::Class input_dialog)
{
  using namespace script;

  Enum input_mode = input_dialog.Enum("InputMode").setId(script::Type::QInputDialogInputMode).get();

  input_mode.addValue("TextInput", QInputDialog::TextInput);
  input_mode.addValue("IntInput", QInputDialog::IntInput);
  input_mode.addValue("DoubleInput", QInputDialog::DoubleInput);
}


static void register_input_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class input_dialog = ns.Class("InputDialog").setId(script::Type::QInputDialog)
    .setBase(script::Type::QDialog).get();

  register_input_dialog_input_dialog_option_enum(input_dialog);
  register_input_dialog_input_mode_enum(input_dialog);
  binding::ClassBinder<QInputDialog> binder{ input_dialog, &QInputDialog::staticMetaObject };

  // QInputDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QInputDialog(QWidget *, Qt::WindowFlags);
  // ~QInputDialog();
  binder.dtor().create();
  // void setInputMode(QInputDialog::InputMode);
  binder.void_fun<QInputDialog::InputMode, &QInputDialog::setInputMode>("setInputMode").create();
  // QInputDialog::InputMode inputMode() const;
  binder.fun<QInputDialog::InputMode, &QInputDialog::inputMode>("inputMode").create();
  // void setLabelText(const QString &);
  binder.void_fun<const QString &, &QInputDialog::setLabelText>("setLabelText").create();
  // QString labelText() const;
  binder.fun<QString, &QInputDialog::labelText>("labelText").create();
  // void setOption(QInputDialog::InputDialogOption, bool);
  binder.void_fun<QInputDialog::InputDialogOption, bool, &QInputDialog::setOption>("setOption")
    .apply(binding::default_arguments(true)).create();
  // bool testOption(QInputDialog::InputDialogOption) const;
  binder.fun<bool, QInputDialog::InputDialogOption, &QInputDialog::testOption>("testOption").create();
  // void setOptions(QInputDialog::InputDialogOptions);
  binder.void_fun<QInputDialog::InputDialogOptions, &QInputDialog::setOptions>("setOptions").create();
  // QInputDialog::InputDialogOptions options() const;
  binder.fun<QInputDialog::InputDialogOptions, &QInputDialog::options>("options").create();
  // void setTextValue(const QString &);
  binder.void_fun<const QString &, &QInputDialog::setTextValue>("setTextValue").create();
  // QString textValue() const;
  binder.fun<QString, &QInputDialog::textValue>("textValue").create();
  // void setTextEchoMode(QLineEdit::EchoMode);
  binder.void_fun<QLineEdit::EchoMode, &QInputDialog::setTextEchoMode>("setTextEchoMode").create();
  // QLineEdit::EchoMode textEchoMode() const;
  binder.fun<QLineEdit::EchoMode, &QInputDialog::textEchoMode>("textEchoMode").create();
  // void setComboBoxEditable(bool);
  binder.void_fun<bool, &QInputDialog::setComboBoxEditable>("setComboBoxEditable").create();
  // bool isComboBoxEditable() const;
  binder.fun<bool, &QInputDialog::isComboBoxEditable>("isComboBoxEditable").create();
  // void setComboBoxItems(const QStringList &);
  /// TODO: void setComboBoxItems(const QStringList &);
  // QStringList comboBoxItems() const;
  /// TODO: QStringList comboBoxItems() const;
  // void setIntValue(int);
  binder.void_fun<int, &QInputDialog::setIntValue>("setIntValue").create();
  // int intValue() const;
  binder.fun<int, &QInputDialog::intValue>("intValue").create();
  // void setIntMinimum(int);
  binder.void_fun<int, &QInputDialog::setIntMinimum>("setIntMinimum").create();
  // int intMinimum() const;
  binder.fun<int, &QInputDialog::intMinimum>("intMinimum").create();
  // void setIntMaximum(int);
  binder.void_fun<int, &QInputDialog::setIntMaximum>("setIntMaximum").create();
  // int intMaximum() const;
  binder.fun<int, &QInputDialog::intMaximum>("intMaximum").create();
  // void setIntRange(int, int);
  binder.void_fun<int, int, &QInputDialog::setIntRange>("setIntRange").create();
  // void setIntStep(int);
  binder.void_fun<int, &QInputDialog::setIntStep>("setIntStep").create();
  // int intStep() const;
  binder.fun<int, &QInputDialog::intStep>("intStep").create();
  // void setDoubleValue(double);
  binder.void_fun<double, &QInputDialog::setDoubleValue>("setDoubleValue").create();
  // double doubleValue() const;
  binder.fun<double, &QInputDialog::doubleValue>("doubleValue").create();
  // void setDoubleMinimum(double);
  binder.void_fun<double, &QInputDialog::setDoubleMinimum>("setDoubleMinimum").create();
  // double doubleMinimum() const;
  binder.fun<double, &QInputDialog::doubleMinimum>("doubleMinimum").create();
  // void setDoubleMaximum(double);
  binder.void_fun<double, &QInputDialog::setDoubleMaximum>("setDoubleMaximum").create();
  // double doubleMaximum() const;
  binder.fun<double, &QInputDialog::doubleMaximum>("doubleMaximum").create();
  // void setDoubleRange(double, double);
  binder.void_fun<double, double, &QInputDialog::setDoubleRange>("setDoubleRange").create();
  // void setDoubleDecimals(int);
  binder.void_fun<int, &QInputDialog::setDoubleDecimals>("setDoubleDecimals").create();
  // int doubleDecimals() const;
  binder.fun<int, &QInputDialog::doubleDecimals>("doubleDecimals").create();
  // void setOkButtonText(const QString &);
  binder.void_fun<const QString &, &QInputDialog::setOkButtonText>("setOkButtonText").create();
  // QString okButtonText() const;
  binder.fun<QString, &QInputDialog::okButtonText>("okButtonText").create();
  // void setCancelButtonText(const QString &);
  binder.void_fun<const QString &, &QInputDialog::setCancelButtonText>("setCancelButtonText").create();
  // QString cancelButtonText() const;
  binder.fun<QString, &QInputDialog::cancelButtonText>("cancelButtonText").create();
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QInputDialog::minimumSizeHint>("minimumSizeHint").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QInputDialog::sizeHint>("sizeHint").create();
  // void setVisible(bool);
  binder.void_fun<bool, &QInputDialog::setVisible>("setVisible").create();
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
  // void setDoubleStep(double);
  binder.void_fun<double, &QInputDialog::setDoubleStep>("setDoubleStep").create();
  // double doubleStep() const;
  binder.fun<double, &QInputDialog::doubleStep>("doubleStep").create();
  // void textValueChanged(const QString &);
  binder.sigs().add<const QString &>("textValueChanged", "textValueChanged(const QString &)");
  // void textValueSelected(const QString &);
  binder.sigs().add<const QString &>("textValueSelected", "textValueSelected(const QString &)");
  // void intValueChanged(int);
  binder.sigs().add<int>("intValueChanged", "intValueChanged(int)");
  // void intValueSelected(int);
  binder.sigs().add<int>("intValueSelected", "intValueSelected(int)");
  // void doubleValueChanged(double);
  binder.sigs().add<double>("doubleValueChanged", "doubleValueChanged(double)");
  // void doubleValueSelected(double);
  binder.sigs().add<double>("doubleValueSelected", "doubleValueSelected(double)");
  // void done(int);
  binder.void_fun<int, &QInputDialog::done>("done").create();

  input_dialog.engine()->registerQtType(&QInputDialog::staticMetaObject, input_dialog.id());
}


void register_inputdialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_input_dialog_class(ns);
  binding::Namespace binder{ ns };

  // QInputDialog::InputDialogOptions operator|(QInputDialog::InputDialogOption, QInputDialog::InputDialogOption);
  binder.operators().or<QInputDialog::InputDialogOptions, QInputDialog::InputDialogOption, QInputDialog::InputDialogOption>();
  // QInputDialog::InputDialogOptions operator|(QInputDialog::InputDialogOption, QInputDialog::InputDialogOptions);
  binder.operators().or<QInputDialog::InputDialogOptions, QInputDialog::InputDialogOption, QInputDialog::InputDialogOptions>();
  // QIncompatibleFlag operator|(QInputDialog::InputDialogOptions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QInputDialog::InputDialogOptions::enum_type, int);
}

