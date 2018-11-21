// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/dial.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_dial_class(script::Namespace ns)
{
  using namespace script;

  Class dial = ns.newClass("Dial").setId(script::Type::QDial)
    .setBase(script::Type::QAbstractSlider).get();

  binding::ClassBinder<QDial> binder{ dial, &QDial::staticMetaObject };

  // QDial(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QDial();
  binder.dtor().create();
  // bool wrapping() const;
  binder.fun<bool, &QDial::wrapping>("wrapping").create();
  // int notchSize() const;
  binder.fun<int, &QDial::notchSize>("notchSize").create();
  // void setNotchTarget(double);
  binder.void_fun<double, &QDial::setNotchTarget>("setNotchTarget").create();
  // qreal notchTarget() const;
  binder.fun<qreal, &QDial::notchTarget>("notchTarget").create();
  // bool notchesVisible() const;
  binder.fun<bool, &QDial::notchesVisible>("notchesVisible").create();
  // void setNotchesVisible(bool);
  binder.void_fun<bool, &QDial::setNotchesVisible>("setNotchesVisible").create();
  // void setWrapping(bool);
  binder.void_fun<bool, &QDial::setWrapping>("setWrapping").create();

  dial.engine()->registerQtType(&QDial::staticMetaObject, dial.id());
}


void register_dial_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_dial_class(ns);
  binding::Namespace binder{ ns };

  // QDial& newDial(QWidget*);
  NewFunction(binder).add<QDial, QWidget*>("newDial");
}

