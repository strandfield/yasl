// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/abstractbutton.h"

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
  binder.void_fun<const QString &, &QAbstractButton::setText>("setText").create();
  // QString text() const;
  binder.fun<QString, &QAbstractButton::text>("text").create();
  // void setIcon(const QIcon &);
  binder.void_fun<const QIcon &, &QAbstractButton::setIcon>("setIcon").create();
  // QIcon icon() const;
  binder.fun<QIcon, &QAbstractButton::icon>("icon").create();
  // QSize iconSize() const;
  binder.fun<QSize, &QAbstractButton::iconSize>("iconSize").create();
  // void setShortcut(const QKeySequence &);
  binder.void_fun<const QKeySequence &, &QAbstractButton::setShortcut>("setShortcut").create();
  // QKeySequence shortcut() const;
  binder.fun<QKeySequence, &QAbstractButton::shortcut>("shortcut").create();
  // void setCheckable(bool);
  binder.void_fun<bool, &QAbstractButton::setCheckable>("setCheckable").create();
  // bool isCheckable() const;
  binder.fun<bool, &QAbstractButton::isCheckable>("isCheckable").create();
  // bool isChecked() const;
  binder.fun<bool, &QAbstractButton::isChecked>("isChecked").create();
  // void setDown(bool);
  binder.void_fun<bool, &QAbstractButton::setDown>("setDown").create();
  // bool isDown() const;
  binder.fun<bool, &QAbstractButton::isDown>("isDown").create();
  // void setAutoRepeat(bool);
  binder.void_fun<bool, &QAbstractButton::setAutoRepeat>("setAutoRepeat").create();
  // bool autoRepeat() const;
  binder.fun<bool, &QAbstractButton::autoRepeat>("autoRepeat").create();
  // void setAutoRepeatDelay(int);
  binder.void_fun<int, &QAbstractButton::setAutoRepeatDelay>("setAutoRepeatDelay").create();
  // int autoRepeatDelay() const;
  binder.fun<int, &QAbstractButton::autoRepeatDelay>("autoRepeatDelay").create();
  // void setAutoRepeatInterval(int);
  binder.void_fun<int, &QAbstractButton::setAutoRepeatInterval>("setAutoRepeatInterval").create();
  // int autoRepeatInterval() const;
  binder.fun<int, &QAbstractButton::autoRepeatInterval>("autoRepeatInterval").create();
  // void setAutoExclusive(bool);
  binder.void_fun<bool, &QAbstractButton::setAutoExclusive>("setAutoExclusive").create();
  // bool autoExclusive() const;
  binder.fun<bool, &QAbstractButton::autoExclusive>("autoExclusive").create();
  // QButtonGroup * group() const;
  /// TODO: QButtonGroup * group() const;
  // void setIconSize(const QSize &);
  binder.void_fun<const QSize &, &QAbstractButton::setIconSize>("setIconSize").create();
  // void animateClick(int);
  binder.void_fun<int, &QAbstractButton::animateClick>("animateClick").create();
  // void click();
  binder.void_fun<&QAbstractButton::click>("click").create();
  // void toggle();
  binder.void_fun<&QAbstractButton::toggle>("toggle").create();
  // void setChecked(bool);
  binder.void_fun<bool, &QAbstractButton::setChecked>("setChecked").create();
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


void register_abstractbutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_abstract_button_class(ns);
  binding::Namespace binder{ ns };

}

