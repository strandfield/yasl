// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/dialog.h"

#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"
#include "yasl/binding2/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_dialog_dialog_code_enum(script::Class dialog)
{
  using namespace script;

  Enum dialog_code = dialog.newEnum("DialogCode").setId(script::Type::QDialogDialogCode).get();

  dialog_code.addValue("Rejected", QDialog::Rejected);
  dialog_code.addValue("Accepted", QDialog::Accepted);
}


static void register_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class dialog = ns.newClass("Dialog").setId(script::Type::QDialog)
    .setBase(script::Type::QWidget).get();

  register_dialog_dialog_code_enum(dialog);

  // QDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QDialog(QWidget *, Qt::WindowFlags);
  // ~QDialog();
  bind::destructor<QDialog>(dialog).create();
  // int result() const;
  bind::member_function<QDialog, int, &QDialog::result>(dialog, "result").create();
  // void setVisible(bool);
  bind::void_member_function<QDialog, bool, &QDialog::setVisible>(dialog, "setVisible").create();
  // void setOrientation(Qt::Orientation);
  bind::void_member_function<QDialog, Qt::Orientation, &QDialog::setOrientation>(dialog, "setOrientation").create();
  // Qt::Orientation orientation() const;
  bind::member_function<QDialog, Qt::Orientation, &QDialog::orientation>(dialog, "orientation").create();
  // void setExtension(QWidget *);
  bind::void_member_function<QDialog, QWidget *, &QDialog::setExtension>(dialog, "setExtension").create();
  // QWidget * extension() const;
  bind::member_function<QDialog, QWidget *, &QDialog::extension>(dialog, "extension").create();
  // QSize sizeHint() const;
  bind::member_function<QDialog, QSize, &QDialog::sizeHint>(dialog, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QDialog, QSize, &QDialog::minimumSizeHint>(dialog, "minimumSizeHint").create();
  // void setSizeGripEnabled(bool);
  bind::void_member_function<QDialog, bool, &QDialog::setSizeGripEnabled>(dialog, "setSizeGripEnabled").create();
  // bool isSizeGripEnabled() const;
  bind::member_function<QDialog, bool, &QDialog::isSizeGripEnabled>(dialog, "isSizeGripEnabled").create();
  // void setModal(bool);
  bind::void_member_function<QDialog, bool, &QDialog::setModal>(dialog, "setModal").create();
  // void setResult(int);
  bind::void_member_function<QDialog, int, &QDialog::setResult>(dialog, "setResult").create();
  // void finished(int);
  bind::signal<QDialog, int>(dialog, "finished", "finished(int)");
  // void accepted();
  bind::signal<QDialog>(dialog, "accepted", "accepted()");
  // void rejected();
  bind::signal<QDialog>(dialog, "rejected", "rejected()");
  // void open();
  bind::void_member_function<QDialog, &QDialog::open>(dialog, "open").create();
  // int exec();
  bind::member_function<QDialog, int, &QDialog::exec>(dialog, "exec").create();
  // void done(int);
  bind::void_member_function<QDialog, int, &QDialog::done>(dialog, "done").create();
  // void accept();
  bind::void_member_function<QDialog, &QDialog::accept>(dialog, "accept").create();
  // void reject();
  bind::void_member_function<QDialog, &QDialog::reject>(dialog, "reject").create();
  // void showExtension(bool);
  bind::void_member_function<QDialog, bool, &QDialog::showExtension>(dialog, "showExtension").create();

  bind::link(dialog, &QDialog::staticMetaObject);
}


void register_dialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_dialog_class(ns);

}

