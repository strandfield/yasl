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

  Enum dialog_code = dialog.Enum("DialogCode").setId(script::Type::QDialogDialogCode).get();

  dialog_code.addValue("Rejected", QDialog::Rejected);
  dialog_code.addValue("Accepted", QDialog::Accepted);
}


static void register_dialog_class(script::Namespace ns)
{
  using namespace script;

  Class dialog = ns.Class("Dialog").setId(script::Type::QDialog)
    .setBase(script::Type::QWidget).get();

  register_dialog_dialog_code_enum(dialog);
  binding::QClass<QDialog> binder{ dialog, &QDialog::staticMetaObject };

  // QDialog(QWidget *, Qt::WindowFlags);
  /// TODO: QDialog(QWidget *, Qt::WindowFlags);
  // ~QDialog();
  binder.add_dtor();
  // int result() const;
  binder.add_fun<int, &QDialog::result>("result");
  // void setVisible(bool);
  binder.add_void_fun<bool, &QDialog::setVisible>("setVisible");
  // void setOrientation(Qt::Orientation);
  binder.add_void_fun<Qt::Orientation, &QDialog::setOrientation>("setOrientation");
  // Qt::Orientation orientation() const;
  binder.add_fun<Qt::Orientation, &QDialog::orientation>("orientation");
  // void setExtension(QWidget *);
  binder.add_void_fun<QWidget *, &QDialog::setExtension>("setExtension");
  // QWidget * extension() const;
  binder.add_fun<QWidget *, &QDialog::extension>("extension");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QDialog::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QDialog::minimumSizeHint>("minimumSizeHint");
  // void setSizeGripEnabled(bool);
  binder.add_void_fun<bool, &QDialog::setSizeGripEnabled>("setSizeGripEnabled");
  // bool isSizeGripEnabled() const;
  binder.add_fun<bool, &QDialog::isSizeGripEnabled>("isSizeGripEnabled");
  // void setModal(bool);
  binder.add_void_fun<bool, &QDialog::setModal>("setModal");
  // void setResult(int);
  binder.add_void_fun<int, &QDialog::setResult>("setResult");
  // void finished(int);
  binder.sigs().add<int>("finished", "finished(int)");
  // void accepted();
  binder.sigs().add("accepted", "accepted()");
  // void rejected();
  binder.sigs().add("rejected", "rejected()");
  // void open();
  binder.add_void_fun<&QDialog::open>("open");
  // int exec();
  binder.add_fun<int, &QDialog::exec>("exec");
  // void done(int);
  binder.add_void_fun<int, &QDialog::done>("done");
  // void accept();
  binder.add_void_fun<&QDialog::accept>("accept");
  // void reject();
  binder.add_void_fun<&QDialog::reject>("reject");
  // void showExtension(bool);
  binder.add_void_fun<bool, &QDialog::showExtension>("showExtension");

  dialog.engine()->registerQtType(&QDialog::staticMetaObject, dialog.id());
}


void register_dialog_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_dialog_class(ns);
  binding::Namespace binder{ ns };

}

