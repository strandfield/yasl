// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/dial.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_dial_class(script::Namespace ns)
{
  using namespace script;

  Class dial = ns.Class("Dial").setId(script::Type::QDial)
    .setBase(script::Type::QAbstractSlider).get();

  binding::QClass<QDial> binder{ dial, &QDial::staticMetaObject };

  // QDial(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QDial();
  binder.add_dtor();
  // bool wrapping() const;
  binder.add_fun<bool, &QDial::wrapping>("wrapping");
  // int notchSize() const;
  binder.add_fun<int, &QDial::notchSize>("notchSize");
  // void setNotchTarget(double);
  binder.add_void_fun<double, &QDial::setNotchTarget>("setNotchTarget");
  // qreal notchTarget() const;
  binder.add_fun<qreal, &QDial::notchTarget>("notchTarget");
  // bool notchesVisible() const;
  binder.add_fun<bool, &QDial::notchesVisible>("notchesVisible");
  // void setNotchesVisible(bool);
  binder.add_void_fun<bool, &QDial::setNotchesVisible>("setNotchesVisible");
  // void setWrapping(bool);
  binder.add_void_fun<bool, &QDial::setWrapping>("setWrapping");

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

