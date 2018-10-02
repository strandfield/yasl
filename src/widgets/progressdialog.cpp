// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/progressdialog.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/object.h"
#include "yasl/core/size.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_progress_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class progress_dialog = ns.Class("ProgressDialog").setId(script::Type::QProgressDialog)
    .setBase(script::Type::QDialog).get();

  binding::QClass<QProgressDialog> binder{ progress_dialog, &QProgressDialog::staticMetaObject };

  // QProgressDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QProgressDialog(QWidget *, Qt::WindowFlags);
  // QProgressDialog(const QString &, const QString &, int, int, QWidget *, Qt::WindowFlags);
  /// TODO: QProgressDialog(const QString &, const QString &, int, int, QWidget *, Qt::WindowFlags);
  // ~QProgressDialog();
  binder.add_dtor();
  // void setLabel(QLabel *);
  /// TODO: void setLabel(QLabel *);
  // void setCancelButton(QPushButton *);
  /// TODO: void setCancelButton(QPushButton *);
  // void setBar(QProgressBar *);
  /// TODO: void setBar(QProgressBar *);
  // bool wasCanceled() const;
  binder.add_fun<bool, &QProgressDialog::wasCanceled>("wasCanceled");
  // int minimum() const;
  binder.add_fun<int, &QProgressDialog::minimum>("minimum");
  // int maximum() const;
  binder.add_fun<int, &QProgressDialog::maximum>("maximum");
  // int value() const;
  binder.add_fun<int, &QProgressDialog::value>("value");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QProgressDialog::sizeHint>("sizeHint");
  // QString labelText() const;
  binder.add_fun<QString, &QProgressDialog::labelText>("labelText");
  // int minimumDuration() const;
  binder.add_fun<int, &QProgressDialog::minimumDuration>("minimumDuration");
  // void setAutoReset(bool);
  binder.add_void_fun<bool, &QProgressDialog::setAutoReset>("setAutoReset");
  // bool autoReset() const;
  binder.add_fun<bool, &QProgressDialog::autoReset>("autoReset");
  // void setAutoClose(bool);
  binder.add_void_fun<bool, &QProgressDialog::setAutoClose>("setAutoClose");
  // bool autoClose() const;
  binder.add_fun<bool, &QProgressDialog::autoClose>("autoClose");
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void cancel();
  binder.add_void_fun<&QProgressDialog::cancel>("cancel");
  // void reset();
  binder.add_void_fun<&QProgressDialog::reset>("reset");
  // void setMaximum(int);
  binder.add_void_fun<int, &QProgressDialog::setMaximum>("setMaximum");
  // void setMinimum(int);
  binder.add_void_fun<int, &QProgressDialog::setMinimum>("setMinimum");
  // void setRange(int, int);
  binder.add_void_fun<int, int, &QProgressDialog::setRange>("setRange");
  // void setValue(int);
  binder.add_void_fun<int, &QProgressDialog::setValue>("setValue");
  // void setLabelText(const QString &);
  binder.add_void_fun<const QString &, &QProgressDialog::setLabelText>("setLabelText");
  // void setCancelButtonText(const QString &);
  binder.add_void_fun<const QString &, &QProgressDialog::setCancelButtonText>("setCancelButtonText");
  // void setMinimumDuration(int);
  binder.add_void_fun<int, &QProgressDialog::setMinimumDuration>("setMinimumDuration");
  // void canceled();
  binder.sigs().add("canceled", "canceled()");

  progress_dialog.engine()->registerQtType(&QProgressDialog::staticMetaObject, progress_dialog.id());
}


void register_progressdialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_progress_dialog_class(ns);
  binding::Namespace binder{ ns };

}

