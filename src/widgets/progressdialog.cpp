// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/progressdialog.h"

#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/object.h"
#include "yasl/core/size.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_progress_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class progress_dialog = ns.newClass("ProgressDialog").setId(script::Type::QProgressDialog)
    .setBase(script::Type::QDialog).get();


  // QProgressDialog(QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  /// TODO: QProgressDialog(QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  // QProgressDialog(const QString &, const QString &, int, int, QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  /// TODO: QProgressDialog(const QString &, const QString &, int, int, QWidget * = (QWidget*)nullptr, Qt::WindowFlags = Qt::WindowFlags());
  // ~QProgressDialog();
  bind::destructor<QProgressDialog>(progress_dialog).create();
  // void setLabel(QLabel *);
  /// TODO: void setLabel(QLabel *);
  // void setCancelButton(QPushButton *);
  /// TODO: void setCancelButton(QPushButton *);
  // void setBar(QProgressBar *);
  /// TODO: void setBar(QProgressBar *);
  // bool wasCanceled() const;
  bind::member_function<QProgressDialog, bool, &QProgressDialog::wasCanceled>(progress_dialog, "wasCanceled").create();
  // int minimum() const;
  bind::member_function<QProgressDialog, int, &QProgressDialog::minimum>(progress_dialog, "minimum").create();
  // int maximum() const;
  bind::member_function<QProgressDialog, int, &QProgressDialog::maximum>(progress_dialog, "maximum").create();
  // int value() const;
  bind::member_function<QProgressDialog, int, &QProgressDialog::value>(progress_dialog, "value").create();
  // QSize sizeHint() const;
  bind::member_function<QProgressDialog, QSize, &QProgressDialog::sizeHint>(progress_dialog, "sizeHint").create();
  // QString labelText() const;
  bind::member_function<QProgressDialog, QString, &QProgressDialog::labelText>(progress_dialog, "labelText").create();
  // int minimumDuration() const;
  bind::member_function<QProgressDialog, int, &QProgressDialog::minimumDuration>(progress_dialog, "minimumDuration").create();
  // void setAutoReset(bool);
  bind::void_member_function<QProgressDialog, bool, &QProgressDialog::setAutoReset>(progress_dialog, "setAutoReset").create();
  // bool autoReset() const;
  bind::member_function<QProgressDialog, bool, &QProgressDialog::autoReset>(progress_dialog, "autoReset").create();
  // void setAutoClose(bool);
  bind::void_member_function<QProgressDialog, bool, &QProgressDialog::setAutoClose>(progress_dialog, "setAutoClose").create();
  // bool autoClose() const;
  bind::member_function<QProgressDialog, bool, &QProgressDialog::autoClose>(progress_dialog, "autoClose").create();
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // void cancel();
  bind::void_member_function<QProgressDialog, &QProgressDialog::cancel>(progress_dialog, "cancel").create();
  // void reset();
  bind::void_member_function<QProgressDialog, &QProgressDialog::reset>(progress_dialog, "reset").create();
  // void setMaximum(int);
  bind::void_member_function<QProgressDialog, int, &QProgressDialog::setMaximum>(progress_dialog, "setMaximum").create();
  // void setMinimum(int);
  bind::void_member_function<QProgressDialog, int, &QProgressDialog::setMinimum>(progress_dialog, "setMinimum").create();
  // void setRange(int, int);
  bind::void_member_function<QProgressDialog, int, int, &QProgressDialog::setRange>(progress_dialog, "setRange").create();
  // void setValue(int);
  bind::void_member_function<QProgressDialog, int, &QProgressDialog::setValue>(progress_dialog, "setValue").create();
  // void setLabelText(const QString &);
  bind::void_member_function<QProgressDialog, const QString &, &QProgressDialog::setLabelText>(progress_dialog, "setLabelText").create();
  // void setCancelButtonText(const QString &);
  bind::void_member_function<QProgressDialog, const QString &, &QProgressDialog::setCancelButtonText>(progress_dialog, "setCancelButtonText").create();
  // void setMinimumDuration(int);
  bind::void_member_function<QProgressDialog, int, &QProgressDialog::setMinimumDuration>(progress_dialog, "setMinimumDuration").create();
  // void canceled();
  bind::signal<QProgressDialog>(progress_dialog, "canceled", "canceled()");

  bind::link(progress_dialog, &QProgressDialog::staticMetaObject);
}


void register_progressdialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_progress_dialog_class(ns);

}

