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

  Class progress_dialog = ns.newClass("ProgressDialog").setId(script::Type::QProgressDialog)
    .setBase(script::Type::QDialog).get();

  binding::ClassBinder<QProgressDialog> binder{ progress_dialog, &QProgressDialog::staticMetaObject };

  // QProgressDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QProgressDialog(QWidget *, Qt::WindowFlags);
  // QProgressDialog(const QString &, const QString &, int, int, QWidget *, Qt::WindowFlags);
  /// TODO: QProgressDialog(const QString &, const QString &, int, int, QWidget *, Qt::WindowFlags);
  // ~QProgressDialog();
  binder.dtor().create();
  // void setLabel(QLabel *);
  /// TODO: void setLabel(QLabel *);
  // void setCancelButton(QPushButton *);
  /// TODO: void setCancelButton(QPushButton *);
  // void setBar(QProgressBar *);
  /// TODO: void setBar(QProgressBar *);
  // bool wasCanceled() const;
  binder.fun<bool, &QProgressDialog::wasCanceled>("wasCanceled").create();
  // int minimum() const;
  binder.fun<int, &QProgressDialog::minimum>("minimum").create();
  // int maximum() const;
  binder.fun<int, &QProgressDialog::maximum>("maximum").create();
  // int value() const;
  binder.fun<int, &QProgressDialog::value>("value").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QProgressDialog::sizeHint>("sizeHint").create();
  // QString labelText() const;
  binder.fun<QString, &QProgressDialog::labelText>("labelText").create();
  // int minimumDuration() const;
  binder.fun<int, &QProgressDialog::minimumDuration>("minimumDuration").create();
  // void setAutoReset(bool);
  binder.void_fun<bool, &QProgressDialog::setAutoReset>("setAutoReset").create();
  // bool autoReset() const;
  binder.fun<bool, &QProgressDialog::autoReset>("autoReset").create();
  // void setAutoClose(bool);
  binder.void_fun<bool, &QProgressDialog::setAutoClose>("setAutoClose").create();
  // bool autoClose() const;
  binder.fun<bool, &QProgressDialog::autoClose>("autoClose").create();
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void cancel();
  binder.void_fun<&QProgressDialog::cancel>("cancel").create();
  // void reset();
  binder.void_fun<&QProgressDialog::reset>("reset").create();
  // void setMaximum(int);
  binder.void_fun<int, &QProgressDialog::setMaximum>("setMaximum").create();
  // void setMinimum(int);
  binder.void_fun<int, &QProgressDialog::setMinimum>("setMinimum").create();
  // void setRange(int, int);
  binder.void_fun<int, int, &QProgressDialog::setRange>("setRange").create();
  // void setValue(int);
  binder.void_fun<int, &QProgressDialog::setValue>("setValue").create();
  // void setLabelText(const QString &);
  binder.void_fun<const QString &, &QProgressDialog::setLabelText>("setLabelText").create();
  // void setCancelButtonText(const QString &);
  binder.void_fun<const QString &, &QProgressDialog::setCancelButtonText>("setCancelButtonText").create();
  // void setMinimumDuration(int);
  binder.void_fun<int, &QProgressDialog::setMinimumDuration>("setMinimumDuration").create();
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

