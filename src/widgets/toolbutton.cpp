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
  binding::ClassBinder<QToolButton> binder{ tool_button, &QToolButton::staticMetaObject };

  // QToolButton(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QToolButton();
  binder.dtor().create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QToolButton::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QToolButton::minimumSizeHint>("minimumSizeHint").create();
  // Qt::ToolButtonStyle toolButtonStyle() const;
  binder.fun<Qt::ToolButtonStyle, &QToolButton::toolButtonStyle>("toolButtonStyle").create();
  // Qt::ArrowType arrowType() const;
  binder.fun<Qt::ArrowType, &QToolButton::arrowType>("arrowType").create();
  // void setArrowType(Qt::ArrowType);
  binder.void_fun<Qt::ArrowType, &QToolButton::setArrowType>("setArrowType").create();
  // void setMenu(QMenu *);
  binder.void_fun<QMenu *, &QToolButton::setMenu>("setMenu").create();
  // QMenu * menu() const;
  binder.fun<QMenu *, &QToolButton::menu>("menu").create();
  // void setPopupMode(QToolButton::ToolButtonPopupMode);
  binder.void_fun<QToolButton::ToolButtonPopupMode, &QToolButton::setPopupMode>("setPopupMode").create();
  // QToolButton::ToolButtonPopupMode popupMode() const;
  binder.fun<QToolButton::ToolButtonPopupMode, &QToolButton::popupMode>("popupMode").create();
  // QAction * defaultAction() const;
  binder.fun<QAction *, &QToolButton::defaultAction>("defaultAction").create();
  // void setAutoRaise(bool);
  binder.void_fun<bool, &QToolButton::setAutoRaise>("setAutoRaise").create();
  // bool autoRaise() const;
  binder.fun<bool, &QToolButton::autoRaise>("autoRaise").create();
  // void showMenu();
  binder.void_fun<&QToolButton::showMenu>("showMenu").create();
  // void setToolButtonStyle(Qt::ToolButtonStyle);
  binder.void_fun<Qt::ToolButtonStyle, &QToolButton::setToolButtonStyle>("setToolButtonStyle").create();
  // void setDefaultAction(QAction *);
  binder.void_fun<QAction *, &QToolButton::setDefaultAction>("setDefaultAction").create();
  // void triggered(QAction *);
  binder.sigs().add<QAction *>("triggered", "triggered(QAction *)");

  tool_button.engine()->registerQtType(&QToolButton::staticMetaObject, tool_button.id());
}


void register_toolbutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_tool_button_class(ns);
  binding::Namespace binder{ ns };

  // QToolButton& newToolButton(QWidget*);
  NewFunction(binder).add<QToolButton, QWidget*>("newToolButton");
}

