// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/abstractbutton.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/keysequence.h"

#include <script/classbuilder.h>

static void register_abstract_button_class(script::Namespace ns)
{
  using namespace script;

  Class abstract_button = ns.Class("AbstractButton").setId(script::Type::QAbstractButton)
    .setBase(script::Type::QWidget).get();

  binding::QClass<QAbstractButton> binder{ abstract_button, &QAbstractButton::staticMetaObject };

  // ~QAbstractButton();
  binder.add_dtor();
  // void setText(const QString &);
  binder.add_void_fun<const QString &, &QAbstractButton::setText>("setText");
  // QString text() const;
  binder.add_fun<QString, &QAbstractButton::text>("text");
  // void setIcon(const QIcon &);
  binder.add_void_fun<const QIcon &, &QAbstractButton::setIcon>("setIcon");
  // QIcon icon() const;
  binder.add_fun<QIcon, &QAbstractButton::icon>("icon");
  // QSize iconSize() const;
  binder.add_fun<QSize, &QAbstractButton::iconSize>("iconSize");
  // void setShortcut(const QKeySequence &);
  binder.add_void_fun<const QKeySequence &, &QAbstractButton::setShortcut>("setShortcut");
  // QKeySequence shortcut() const;
  binder.add_fun<QKeySequence, &QAbstractButton::shortcut>("shortcut");
  // void setCheckable(bool);
  binder.add_void_fun<bool, &QAbstractButton::setCheckable>("setCheckable");
  // bool isCheckable() const;
  binder.add_fun<bool, &QAbstractButton::isCheckable>("isCheckable");
  // bool isChecked() const;
  binder.add_fun<bool, &QAbstractButton::isChecked>("isChecked");
  // void setDown(bool);
  binder.add_void_fun<bool, &QAbstractButton::setDown>("setDown");
  // bool isDown() const;
  binder.add_fun<bool, &QAbstractButton::isDown>("isDown");
  // void setAutoRepeat(bool);
  binder.add_void_fun<bool, &QAbstractButton::setAutoRepeat>("setAutoRepeat");
  // bool autoRepeat() const;
  binder.add_fun<bool, &QAbstractButton::autoRepeat>("autoRepeat");
  // void setAutoRepeatDelay(int);
  binder.add_void_fun<int, &QAbstractButton::setAutoRepeatDelay>("setAutoRepeatDelay");
  // int autoRepeatDelay() const;
  binder.add_fun<int, &QAbstractButton::autoRepeatDelay>("autoRepeatDelay");
  // void setAutoRepeatInterval(int);
  binder.add_void_fun<int, &QAbstractButton::setAutoRepeatInterval>("setAutoRepeatInterval");
  // int autoRepeatInterval() const;
  binder.add_fun<int, &QAbstractButton::autoRepeatInterval>("autoRepeatInterval");
  // void setAutoExclusive(bool);
  binder.add_void_fun<bool, &QAbstractButton::setAutoExclusive>("setAutoExclusive");
  // bool autoExclusive() const;
  binder.add_fun<bool, &QAbstractButton::autoExclusive>("autoExclusive");
  // QButtonGroup * group() const;
  /// TODO: QButtonGroup * group() const;
  // void setIconSize(const QSize &);
  binder.add_void_fun<const QSize &, &QAbstractButton::setIconSize>("setIconSize");
  // void animateClick(int);
  binder.add_void_fun<int, &QAbstractButton::animateClick>("animateClick");
  // void click();
  binder.add_void_fun<&QAbstractButton::click>("click");
  // void toggle();
  binder.add_void_fun<&QAbstractButton::toggle>("toggle");
  // void setChecked(bool);
  binder.add_void_fun<bool, &QAbstractButton::setChecked>("setChecked");
  // void pressed();
  binder.sigs().add("pressed", "pressed()");
  // void released();
  binder.sigs().add("released", "released()");
  // void clicked(bool);
  binder.sigs().add<bool>("clicked", "clicked(bool)");
  // void toggled(bool);
  binder.sigs().add<bool>("toggled", "toggled(bool)");

  abstract_button.engine()->registerQtType(&QAbstractButton::staticMetaObject, abstract_button.id());
}


void register_abstractbutton_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_abstract_button_class(ns);
  binding::Namespace binder{ ns };

}

