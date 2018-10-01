// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/errormessage.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_error_message_class(script::Namespace ns)
{
  using namespace script;

  Class error_message = ns.Class("ErrorMessage").setId(script::Type::QErrorMessage)
    .setBase(script::Type::QDialog).get();

  binding::QClass<QErrorMessage> binder{ error_message, &QErrorMessage::staticMetaObject };

  // QErrorMessage(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QErrorMessage();
  binder.add_dtor();
  // void showMessage(const QString &);
  binder.add_void_fun<const QString &, &QErrorMessage::showMessage>("showMessage");
  // void showMessage(const QString &, const QString &);
  binder.add_void_fun<const QString &, const QString &, &QErrorMessage::showMessage>("showMessage");

  error_message.engine()->registerQtType(&QErrorMessage::staticMetaObject, error_message.id());
}


void register_errormessage_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_error_message_class(ns);
  binding::Namespace binder{ ns };

}

