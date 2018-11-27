// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/abstractbutton.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/keysequence.h"

#include <script/classbuilder.h>

static void register_abstract_button_class(script::Namespace ns)
{
  using namespace script;

  Class abstract_button = ns.newClass("AbstractButton").setId(script::Type::QAbstractButton)
    .setBase(script::Type::QWidget).get();


  // ~QAbstractButton();
  bind::destructor<QAbstractButton>(abstract_button).create();
  // void setText(const QString &);
  bind::void_member_function<QAbstractButton, const QString &, &QAbstractButton::setText>(abstract_button, "setText").create();
  // QString text() const;
  bind::member_function<QAbstractButton, QString, &QAbstractButton::text>(abstract_button, "text").create();
  // void setIcon(const QIcon &);
  bind::void_member_function<QAbstractButton, const QIcon &, &QAbstractButton::setIcon>(abstract_button, "setIcon").create();
  // QIcon icon() const;
  bind::member_function<QAbstractButton, QIcon, &QAbstractButton::icon>(abstract_button, "icon").create();
  // QSize iconSize() const;
  bind::member_function<QAbstractButton, QSize, &QAbstractButton::iconSize>(abstract_button, "iconSize").create();
  // void setShortcut(const QKeySequence &);
  bind::void_member_function<QAbstractButton, const QKeySequence &, &QAbstractButton::setShortcut>(abstract_button, "setShortcut").create();
  // QKeySequence shortcut() const;
  bind::member_function<QAbstractButton, QKeySequence, &QAbstractButton::shortcut>(abstract_button, "shortcut").create();
  // void setCheckable(bool);
  bind::void_member_function<QAbstractButton, bool, &QAbstractButton::setCheckable>(abstract_button, "setCheckable").create();
  // bool isCheckable() const;
  bind::member_function<QAbstractButton, bool, &QAbstractButton::isCheckable>(abstract_button, "isCheckable").create();
  // bool isChecked() const;
  bind::member_function<QAbstractButton, bool, &QAbstractButton::isChecked>(abstract_button, "isChecked").create();
  // void setDown(bool);
  bind::void_member_function<QAbstractButton, bool, &QAbstractButton::setDown>(abstract_button, "setDown").create();
  // bool isDown() const;
  bind::member_function<QAbstractButton, bool, &QAbstractButton::isDown>(abstract_button, "isDown").create();
  // void setAutoRepeat(bool);
  bind::void_member_function<QAbstractButton, bool, &QAbstractButton::setAutoRepeat>(abstract_button, "setAutoRepeat").create();
  // bool autoRepeat() const;
  bind::member_function<QAbstractButton, bool, &QAbstractButton::autoRepeat>(abstract_button, "autoRepeat").create();
  // void setAutoRepeatDelay(int);
  bind::void_member_function<QAbstractButton, int, &QAbstractButton::setAutoRepeatDelay>(abstract_button, "setAutoRepeatDelay").create();
  // int autoRepeatDelay() const;
  bind::member_function<QAbstractButton, int, &QAbstractButton::autoRepeatDelay>(abstract_button, "autoRepeatDelay").create();
  // void setAutoRepeatInterval(int);
  bind::void_member_function<QAbstractButton, int, &QAbstractButton::setAutoRepeatInterval>(abstract_button, "setAutoRepeatInterval").create();
  // int autoRepeatInterval() const;
  bind::member_function<QAbstractButton, int, &QAbstractButton::autoRepeatInterval>(abstract_button, "autoRepeatInterval").create();
  // void setAutoExclusive(bool);
  bind::void_member_function<QAbstractButton, bool, &QAbstractButton::setAutoExclusive>(abstract_button, "setAutoExclusive").create();
  // bool autoExclusive() const;
  bind::member_function<QAbstractButton, bool, &QAbstractButton::autoExclusive>(abstract_button, "autoExclusive").create();
  // QButtonGroup * group() const;
  /// TODO: QButtonGroup * group() const;
  // void setIconSize(const QSize &);
  bind::void_member_function<QAbstractButton, const QSize &, &QAbstractButton::setIconSize>(abstract_button, "setIconSize").create();
  // void animateClick(int = 100);
  bind::void_member_function<QAbstractButton, int, &QAbstractButton::animateClick>(abstract_button, "animateClick")
    .apply(bind::default_arguments(100)).create();
  // void click();
  bind::void_member_function<QAbstractButton, &QAbstractButton::click>(abstract_button, "click").create();
  // void toggle();
  bind::void_member_function<QAbstractButton, &QAbstractButton::toggle>(abstract_button, "toggle").create();
  // void setChecked(bool);
  bind::void_member_function<QAbstractButton, bool, &QAbstractButton::setChecked>(abstract_button, "setChecked").create();
  // void pressed();
  bind::signal<QAbstractButton>(abstract_button, "pressed", "pressed()");
  // void released();
  bind::signal<QAbstractButton>(abstract_button, "released", "released()");
  // void clicked(bool);
  bind::signal<QAbstractButton, bool>(abstract_button, "clicked", "clicked(bool)");
  // void toggled(bool);
  bind::signal<QAbstractButton, bool>(abstract_button, "toggled", "toggled(bool)");

  bind::link(abstract_button, &QAbstractButton::staticMetaObject);
}


void register_abstractbutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_abstract_button_class(ns);

}

