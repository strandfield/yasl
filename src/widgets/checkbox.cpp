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

  Class check_box = ns.Class("CheckBox").setId(script::Type::QCheckBox)
    .setBase(script::Type::QAbstractButton).get();

  binding::QClass<QCheckBox> binder{ check_box, &QCheckBox::staticMetaObject };

  // QCheckBox(QWidget *);
  binder.ctors().ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QCheckBox(const QString &, QWidget *);
  binder.ctors().ctor<const QString &, QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QCheckBox();
  binder.add_dtor();
  // void setTristate(bool);
  binder.void_fun<bool, &QCheckBox::setTristate>("setTristate")
    .apply(binding::default_arguments(true)).create();
  // bool isTristate() const;
  binder.fun<bool, &QCheckBox::isTristate>("isTristate").create();
  // Qt::CheckState checkState() const;
  binder.fun<Qt::CheckState, &QCheckBox::checkState>("checkState").create();
  // void setCheckState(Qt::CheckState);
  binder.void_fun<Qt::CheckState, &QCheckBox::setCheckState>("setCheckState").create();
  // void stateChanged(int);
  binder.sigs().add<int>("stateChanged", "stateChanged(int)");

  check_box.engine()->registerQtType(&QCheckBox::staticMetaObject, check_box.id());
}


void register_checkbox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_check_box_class(ns);
  binding::Namespace binder{ ns };

  register_newcheckbox_functions(widgets);
}

