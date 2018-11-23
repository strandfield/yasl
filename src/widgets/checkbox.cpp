// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/checkbox.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "checkbox.inc"
#include "yasl/core/enums.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_check_box_class(script::Namespace ns)
{
  using namespace script;

  Class check_box = ns.newClass("CheckBox").setId(script::Type::QCheckBox)
    .setBase(script::Type::QAbstractButton).get();


  // QCheckBox(QWidget *);
  bind::constructor<QCheckBox, QWidget *>(check_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QCheckBox(const QString &, QWidget *);
  bind::constructor<QCheckBox, const QString &, QWidget *>(check_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QCheckBox();
  bind::destructor<QCheckBox>(check_box).create();
  // void setTristate(bool);
  bind::void_member_function<QCheckBox, bool, &QCheckBox::setTristate>(check_box, "setTristate")
    .apply(bind::default_arguments(true)).create();
  // bool isTristate() const;
  bind::member_function<QCheckBox, bool, &QCheckBox::isTristate>(check_box, "isTristate").create();
  // Qt::CheckState checkState() const;
  bind::member_function<QCheckBox, Qt::CheckState, &QCheckBox::checkState>(check_box, "checkState").create();
  // void setCheckState(Qt::CheckState);
  bind::void_member_function<QCheckBox, Qt::CheckState, &QCheckBox::setCheckState>(check_box, "setCheckState").create();
  // void stateChanged(int);
  bind::signal<QCheckBox, int>(check_box, "stateChanged", "stateChanged(int)");

  bind::link(check_box, &QCheckBox::staticMetaObject);
}


void register_checkbox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_check_box_class(ns);

  register_newcheckbox_functions(widgets);
}

