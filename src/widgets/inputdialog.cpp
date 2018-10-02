// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/inputdialog.h"

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
  binding::QClass<QInputDialog> binder{ input_dialog, &QInputDialog::staticMetaObject };

  // QInputDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QInputDialog(QWidget *, Qt::WindowFlags);
  // ~QInputDialog();
  binder.add_dtor();
  // void setInputMode(QInputDialog::InputMode);
  binder.add_void_fun<QInputDialog::InputMode, &QInputDialog::setInputMode>("setInputMode");
  // QInputDialog::InputMode inputMode() const;
  binder.add_fun<QInputDialog::InputMode, &QInputDialog::inputMode>("inputMode");
  // void setLabelText(const QString &);
  binder.add_void_fun<const QString &, &QInputDialog::setLabelText>("setLabelText");
  // QString labelText() const;
  binder.add_fun<QString, &QInputDialog::labelText>("labelText");
  // void setOption(QInputDialog::InputDialogOption, bool);
  binder.add_void_fun<QInputDialog::InputDialogOption, bool, &QInputDialog::setOption>("setOption");
  // bool testOption(QInputDialog::InputDialogOption) const;
  binder.add_fun<bool, QInputDialog::InputDialogOption, &QInputDialog::testOption>("testOption");
  // void setOptions(QInputDialog::InputDialogOptions);
  binder.add_void_fun<QInputDialog::InputDialogOptions, &QInputDialog::setOptions>("setOptions");
  // QInputDialog::InputDialogOptions options() const;
  binder.add_fun<QInputDialog::InputDialogOptions, &QInputDialog::options>("options");
  // void setTextValue(const QString &);
  binder.add_void_fun<const QString &, &QInputDialog::setTextValue>("setTextValue");
  // QString textValue() const;
  binder.add_fun<QString, &QInputDialog::textValue>("textValue");
  // void setTextEchoMode(QLineEdit::EchoMode);
  binder.add_void_fun<QLineEdit::EchoMode, &QInputDialog::setTextEchoMode>("setTextEchoMode");
  // QLineEdit::EchoMode textEchoMode() const;
  binder.add_fun<QLineEdit::EchoMode, &QInputDialog::textEchoMode>("textEchoMode");
  // void setComboBoxEditable(bool);
  binder.add_void_fun<bool, &QInputDialog::setComboBoxEditable>("setComboBoxEditable");
  // bool isComboBoxEditable() const;
  binder.add_fun<bool, &QInputDialog::isComboBoxEditable>("isComboBoxEditable");
  // void setComboBoxItems(const QStringList &);
  /// TODO: void setComboBoxItems(const QStringList &);
  // QStringList comboBoxItems() const;
  /// TODO: QStringList comboBoxItems() const;
  // void setIntValue(int);
  binder.add_void_fun<int, &QInputDialog::setIntValue>("setIntValue");
  // int intValue() const;
  binder.add_fun<int, &QInputDialog::intValue>("intValue");
  // void setIntMinimum(int);
  binder.add_void_fun<int, &QInputDialog::setIntMinimum>("setIntMinimum");
  // int intMinimum() const;
  binder.add_fun<int, &QInputDialog::intMinimum>("intMinimum");
  // void setIntMaximum(int);
  binder.add_void_fun<int, &QInputDialog::setIntMaximum>("setIntMaximum");
  // int intMaximum() const;
  binder.add_fun<int, &QInputDialog::intMaximum>("intMaximum");
  // void setIntRange(int, int);
  binder.add_void_fun<int, int, &QInputDialog::setIntRange>("setIntRange");
  // void setIntStep(int);
  binder.add_void_fun<int, &QInputDialog::setIntStep>("setIntStep");
  // int intStep() const;
  binder.add_fun<int, &QInputDialog::intStep>("intStep");
  // void setDoubleValue(double);
  binder.add_void_fun<double, &QInputDialog::setDoubleValue>("setDoubleValue");
  // double doubleValue() const;
  binder.add_fun<double, &QInputDialog::doubleValue>("doubleValue");
  // void setDoubleMinimum(double);
  binder.add_void_fun<double, &QInputDialog::setDoubleMinimum>("setDoubleMinimum");
  // double doubleMinimum() const;
  binder.add_fun<double, &QInputDialog::doubleMinimum>("doubleMinimum");
  // void setDoubleMaximum(double);
  binder.add_void_fun<double, &QInputDialog::setDoubleMaximum>("setDoubleMaximum");
  // double doubleMaximum() const;
  binder.add_fun<double, &QInputDialog::doubleMaximum>("doubleMaximum");
  // void setDoubleRange(double, double);
  binder.add_void_fun<double, double, &QInputDialog::setDoubleRange>("setDoubleRange");
  // void setDoubleDecimals(int);
  binder.add_void_fun<int, &QInputDialog::setDoubleDecimals>("setDoubleDecimals");
  // int doubleDecimals() const;
  binder.add_fun<int, &QInputDialog::doubleDecimals>("doubleDecimals");
  // void setOkButtonText(const QString &);
  binder.add_void_fun<const QString &, &QInputDialog::setOkButtonText>("setOkButtonText");
  // QString okButtonText() const;
  binder.add_fun<QString, &QInputDialog::okButtonText>("okButtonText");
  // void setCancelButtonText(const QString &);
  binder.add_void_fun<const QString &, &QInputDialog::setCancelButtonText>("setCancelButtonText");
  // QString cancelButtonText() const;
  binder.add_fun<QString, &QInputDialog::cancelButtonText>("cancelButtonText");
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QInputDialog::minimumSizeHint>("minimumSizeHint");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QInputDialog::sizeHint>("sizeHint");
  // void setVisible(bool);
  binder.add_void_fun<bool, &QInputDialog::setVisible>("setVisible");
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
  binder.add_void_fun<double, &QInputDialog::setDoubleStep>("setDoubleStep");
  // double doubleStep() const;
  binder.add_fun<double, &QInputDialog::doubleStep>("doubleStep");
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
  binder.add_void_fun<int, &QInputDialog::done>("done");

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

