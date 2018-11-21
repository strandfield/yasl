// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/dialog.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

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
  binding::ClassBinder<QDialog> binder{ dialog, &QDialog::staticMetaObject };

  // QDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QDialog(QWidget *, Qt::WindowFlags);
  // ~QDialog();
  binder.dtor().create();
  // int result() const;
  binder.fun<int, &QDialog::result>("result").create();
  // void setVisible(bool);
  binder.void_fun<bool, &QDialog::setVisible>("setVisible").create();
  // void setOrientation(Qt::Orientation);
  binder.void_fun<Qt::Orientation, &QDialog::setOrientation>("setOrientation").create();
  // Qt::Orientation orientation() const;
  binder.fun<Qt::Orientation, &QDialog::orientation>("orientation").create();
  // void setExtension(QWidget *);
  binder.void_fun<QWidget *, &QDialog::setExtension>("setExtension").create();
  // QWidget * extension() const;
  binder.fun<QWidget *, &QDialog::extension>("extension").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QDialog::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QDialog::minimumSizeHint>("minimumSizeHint").create();
  // void setSizeGripEnabled(bool);
  binder.void_fun<bool, &QDialog::setSizeGripEnabled>("setSizeGripEnabled").create();
  // bool isSizeGripEnabled() const;
  binder.fun<bool, &QDialog::isSizeGripEnabled>("isSizeGripEnabled").create();
  // void setModal(bool);
  binder.void_fun<bool, &QDialog::setModal>("setModal").create();
  // void setResult(int);
  binder.void_fun<int, &QDialog::setResult>("setResult").create();
  // void finished(int);
  binder.sigs().add<int>("finished", "finished(int)");
  // void accepted();
  binder.sigs().add("accepted", "accepted()");
  // void rejected();
  binder.sigs().add("rejected", "rejected()");
  // void open();
  binder.void_fun<&QDialog::open>("open").create();
  // int exec();
  binder.fun<int, &QDialog::exec>("exec").create();
  // void done(int);
  binder.void_fun<int, &QDialog::done>("done").create();
  // void accept();
  binder.void_fun<&QDialog::accept>("accept").create();
  // void reject();
  binder.void_fun<&QDialog::reject>("reject").create();
  // void showExtension(bool);
  binder.void_fun<bool, &QDialog::showExtension>("showExtension").create();

  dialog.engine()->registerQtType(&QDialog::staticMetaObject, dialog.id());
}


void register_dialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_dialog_class(ns);
  binding::Namespace binder{ ns };

}

