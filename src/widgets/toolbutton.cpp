// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/toolbutton.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/widgets/action.h"
#include "yasl/widgets/menu.h"
#include "yasl/widgets/toolbutton.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_tool_button_tool_button_popup_mode_enum(script::Class tool_button)
{
  using namespace script;

  Enum tool_button_popup_mode = tool_button.newEnum("ToolButtonPopupMode").setId(script::Type::QToolButtonToolButtonPopupMode).get();

  tool_button_popup_mode.addValue("DelayedPopup", QToolButton::DelayedPopup);
  tool_button_popup_mode.addValue("MenuButtonPopup", QToolButton::MenuButtonPopup);
  tool_button_popup_mode.addValue("InstantPopup", QToolButton::InstantPopup);
}


static void register_tool_button_class(script::Namespace ns)
{
  using namespace script;

  Class tool_button = ns.newClass("ToolButton").setId(script::Type::QToolButton)
    .setBase(script::Type::QAbstractButton).get();

  register_tool_button_tool_button_popup_mode_enum(tool_button);

  // QToolButton(QWidget *);
  bind::constructor<QToolButton, QWidget *>(tool_button)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QToolButton();
  bind::destructor<QToolButton>(tool_button).create();
  // QSize sizeHint() const;
  bind::member_function<QToolButton, QSize, &QToolButton::sizeHint>(tool_button, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QToolButton, QSize, &QToolButton::minimumSizeHint>(tool_button, "minimumSizeHint").create();
  // Qt::ToolButtonStyle toolButtonStyle() const;
  bind::member_function<QToolButton, Qt::ToolButtonStyle, &QToolButton::toolButtonStyle>(tool_button, "toolButtonStyle").create();
  // Qt::ArrowType arrowType() const;
  bind::member_function<QToolButton, Qt::ArrowType, &QToolButton::arrowType>(tool_button, "arrowType").create();
  // void setArrowType(Qt::ArrowType);
  bind::void_member_function<QToolButton, Qt::ArrowType, &QToolButton::setArrowType>(tool_button, "setArrowType").create();
  // void setMenu(QMenu *);
  bind::void_member_function<QToolButton, QMenu *, &QToolButton::setMenu>(tool_button, "setMenu").create();
  // QMenu * menu() const;
  bind::member_function<QToolButton, QMenu *, &QToolButton::menu>(tool_button, "menu").create();
  // void setPopupMode(QToolButton::ToolButtonPopupMode);
  bind::void_member_function<QToolButton, QToolButton::ToolButtonPopupMode, &QToolButton::setPopupMode>(tool_button, "setPopupMode").create();
  // QToolButton::ToolButtonPopupMode popupMode() const;
  bind::member_function<QToolButton, QToolButton::ToolButtonPopupMode, &QToolButton::popupMode>(tool_button, "popupMode").create();
  // QAction * defaultAction() const;
  bind::member_function<QToolButton, QAction *, &QToolButton::defaultAction>(tool_button, "defaultAction").create();
  // void setAutoRaise(bool);
  bind::void_member_function<QToolButton, bool, &QToolButton::setAutoRaise>(tool_button, "setAutoRaise").create();
  // bool autoRaise() const;
  bind::member_function<QToolButton, bool, &QToolButton::autoRaise>(tool_button, "autoRaise").create();
  // void showMenu();
  bind::void_member_function<QToolButton, &QToolButton::showMenu>(tool_button, "showMenu").create();
  // void setToolButtonStyle(Qt::ToolButtonStyle);
  bind::void_member_function<QToolButton, Qt::ToolButtonStyle, &QToolButton::setToolButtonStyle>(tool_button, "setToolButtonStyle").create();
  // void setDefaultAction(QAction *);
  bind::void_member_function<QToolButton, QAction *, &QToolButton::setDefaultAction>(tool_button, "setDefaultAction").create();
  // void triggered(QAction *);
  bind::signal<QToolButton, QAction *>(tool_button, "triggered", "triggered(QAction *)");

  bind::link(tool_button, &QToolButton::staticMetaObject);
}


void register_toolbutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_tool_button_class(ns);

  // QToolButton& newToolButton(QWidget*);
  bind::new_function<QToolButton, QWidget*>(ns, "newToolButton");
}

