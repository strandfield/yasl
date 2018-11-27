// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/dial.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_dial_class(script::Namespace ns)
{
  using namespace script;

  Class dial = ns.newClass("Dial").setId(script::Type::QDial)
    .setBase(script::Type::QAbstractSlider).get();


  // QDial(QWidget * = (QWidget*)nullptr);
  bind::constructor<QDial, QWidget *>(dial)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QDial();
  bind::destructor<QDial>(dial).create();
  // bool wrapping() const;
  bind::member_function<QDial, bool, &QDial::wrapping>(dial, "wrapping").create();
  // int notchSize() const;
  bind::member_function<QDial, int, &QDial::notchSize>(dial, "notchSize").create();
  // void setNotchTarget(double);
  bind::void_member_function<QDial, double, &QDial::setNotchTarget>(dial, "setNotchTarget").create();
  // qreal notchTarget() const;
  bind::member_function<QDial, qreal, &QDial::notchTarget>(dial, "notchTarget").create();
  // bool notchesVisible() const;
  bind::member_function<QDial, bool, &QDial::notchesVisible>(dial, "notchesVisible").create();
  // void setNotchesVisible(bool);
  bind::void_member_function<QDial, bool, &QDial::setNotchesVisible>(dial, "setNotchesVisible").create();
  // void setWrapping(bool);
  bind::void_member_function<QDial, bool, &QDial::setWrapping>(dial, "setWrapping").create();

  bind::link(dial, &QDial::staticMetaObject);
}


void register_dial_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_dial_class(ns);

  // QDial& newDial(QWidget* = (QWidget*)nullptr);
  bind::new_function<QDial, QWidget*>(ns, "newDial");
}

