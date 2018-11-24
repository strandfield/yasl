// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/pushbutton.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/widgets/menu.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_push_button_class(script::Namespace ns)
{
  using namespace script;

  Class push_button = ns.newClass("PushButton").setId(script::Type::QPushButton)
    .setBase(script::Type::QAbstractButton).get();


  // QPushButton(QWidget *);
  bind::constructor<QPushButton, QWidget *>(push_button)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QPushButton(const QString &, QWidget *);
  bind::constructor<QPushButton, const QString &, QWidget *>(push_button)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QPushButton(const QIcon &, const QString &, QWidget *);
  bind::constructor<QPushButton, const QIcon &, const QString &, QWidget *>(push_button)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QPushButton();
  bind::destructor<QPushButton>(push_button).create();
  // QSize sizeHint() const;
  bind::member_function<QPushButton, QSize, &QPushButton::sizeHint>(push_button, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QPushButton, QSize, &QPushButton::minimumSizeHint>(push_button, "minimumSizeHint").create();
  // bool autoDefault() const;
  bind::member_function<QPushButton, bool, &QPushButton::autoDefault>(push_button, "autoDefault").create();
  // void setAutoDefault(bool);
  bind::void_member_function<QPushButton, bool, &QPushButton::setAutoDefault>(push_button, "setAutoDefault").create();
  // bool isDefault() const;
  bind::member_function<QPushButton, bool, &QPushButton::isDefault>(push_button, "isDefault").create();
  // void setDefault(bool);
  bind::void_member_function<QPushButton, bool, &QPushButton::setDefault>(push_button, "setDefault").create();
  // void setMenu(QMenu *);
  bind::void_member_function<QPushButton, QMenu *, &QPushButton::setMenu>(push_button, "setMenu").create();
  // QMenu * menu() const;
  bind::member_function<QPushButton, QMenu *, &QPushButton::menu>(push_button, "menu").create();
  // void setFlat(bool);
  bind::void_member_function<QPushButton, bool, &QPushButton::setFlat>(push_button, "setFlat").create();
  // bool isFlat() const;
  bind::member_function<QPushButton, bool, &QPushButton::isFlat>(push_button, "isFlat").create();
  // void showMenu();
  bind::void_member_function<QPushButton, &QPushButton::showMenu>(push_button, "showMenu").create();
  // void clicked();
  bind::signal<QPushButton>(push_button, "clicked", "clicked()");

  bind::link(push_button, &QPushButton::staticMetaObject);
}


void register_pushbutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_push_button_class(ns);

  void register_newpushbutton_file(script::Namespace n); // defined in newpushbutton.cpp
  register_newpushbutton_file(widgets);
}

