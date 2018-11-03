// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/radiobutton.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_radio_button_class(script::Namespace ns)
{
  using namespace script;

  Class radio_button = ns.Class("RadioButton").setId(script::Type::QRadioButton)
    .setBase(script::Type::QAbstractButton).get();

  binding::ClassBinder<QRadioButton> binder{ radio_button, &QRadioButton::staticMetaObject };

  // QRadioButton(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QRadioButton(const QString &, QWidget *);
  binder.ctor<const QString &, QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QRadioButton();
  binder.dtor().create();

  radio_button.engine()->registerQtType(&QRadioButton::staticMetaObject, radio_button.id());
}


void register_radiobutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_radio_button_class(ns);
  binding::Namespace binder{ ns };

  // QRadioButton& newRadioButton(QWidget*);
  NewFunction(binder).add<QRadioButton, QWidget*>("newRadioButton");
  // QRadioButton& newRadioButton(const QString&, QWidget*);
  NewFunction(binder).add<QRadioButton, const QString&, QWidget*>("newRadioButton");
}

