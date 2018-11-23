// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/errormessage.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_error_message_class(script::Namespace ns)
{
  using namespace script;

  Class error_message = ns.newClass("ErrorMessage").setId(script::Type::QErrorMessage)
    .setBase(script::Type::QDialog).get();


  // QErrorMessage(QWidget *);
  bind::constructor<QErrorMessage, QWidget *>(error_message)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QErrorMessage();
  bind::destructor<QErrorMessage>(error_message).create();
  // void showMessage(const QString &);
  bind::void_member_function<QErrorMessage, const QString &, &QErrorMessage::showMessage>(error_message, "showMessage").create();
  // void showMessage(const QString &, const QString &);
  bind::void_member_function<QErrorMessage, const QString &, const QString &, &QErrorMessage::showMessage>(error_message, "showMessage").create();

  bind::link(error_message, &QErrorMessage::staticMetaObject);
}


void register_errormessage_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_error_message_class(ns);

}

