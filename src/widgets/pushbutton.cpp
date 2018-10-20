// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/pushbutton.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/widgets/menu.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_push_button_class(script::Namespace ns)
{
  using namespace script;

  Class push_button = ns.Class("PushButton").setId(script::Type::QPushButton)
    .setBase(script::Type::QAbstractButton).get();

  binding::QClass<QPushButton> binder{ push_button, &QPushButton::staticMetaObject };

  // QPushButton(QWidget *);
  binder.ctors().ctor<QWidget *>()
    .addDefaultArgument(binding::default_argument(push_button.engine(), (QWidget*)nullptr)).create();
  // QPushButton(const QString &, QWidget *);
  binder.ctors().ctor<const QString &, QWidget *>()
    .addDefaultArgument(binding::default_argument(push_button.engine(), (QWidget*)nullptr)).create();
  // QPushButton(const QIcon &, const QString &, QWidget *);
  binder.ctors().ctor<const QIcon &, const QString &, QWidget *>()
    .addDefaultArgument(binding::default_argument(push_button.engine(), (QWidget*)nullptr)).create();
  // ~QPushButton();
  binder.add_dtor();
  // QSize sizeHint() const;
  binder.fun<QSize, &QPushButton::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QPushButton::minimumSizeHint>("minimumSizeHint").create();
  // bool autoDefault() const;
  binder.fun<bool, &QPushButton::autoDefault>("autoDefault").create();
  // void setAutoDefault(bool);
  binder.void_fun<bool, &QPushButton::setAutoDefault>("setAutoDefault").create();
  // bool isDefault() const;
  binder.fun<bool, &QPushButton::isDefault>("isDefault").create();
  // void setDefault(bool);
  binder.void_fun<bool, &QPushButton::setDefault>("setDefault").create();
  // void setMenu(QMenu *);
  binder.void_fun<QMenu *, &QPushButton::setMenu>("setMenu").create();
  // QMenu * menu() const;
  binder.fun<QMenu *, &QPushButton::menu>("menu").create();
  // void setFlat(bool);
  binder.void_fun<bool, &QPushButton::setFlat>("setFlat").create();
  // bool isFlat() const;
  binder.fun<bool, &QPushButton::isFlat>("isFlat").create();
  // void showMenu();
  binder.void_fun<&QPushButton::showMenu>("showMenu").create();
  // void clicked();
  binder.sigs().add("clicked", "clicked()");

  push_button.engine()->registerQtType(&QPushButton::staticMetaObject, push_button.id());
}


void register_pushbutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_push_button_class(ns);
  binding::Namespace binder{ ns };

  void register_newpushbutton_file(script::Namespace n); // defined in newpushbutton.cpp
  register_newpushbutton_file(widgets);
}

