// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/toolbutton.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/widgets/toolbutton.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_tool_button_tool_button_popup_mode_enum(script::Class tool_button)
{
  using namespace script;

  Enum tool_button_popup_mode = tool_button.Enum("ToolButtonPopupMode").setId(script::Type::QToolButtonToolButtonPopupMode).get();

  tool_button_popup_mode.addValue("DelayedPopup", QToolButton::DelayedPopup);
  tool_button_popup_mode.addValue("MenuButtonPopup", QToolButton::MenuButtonPopup);
  tool_button_popup_mode.addValue("InstantPopup", QToolButton::InstantPopup);
}


static void register_tool_button_class(script::Namespace ns)
{
  using namespace script;

  Class tool_button = ns.Class("ToolButton").setId(script::Type::QToolButton)
    .setBase(script::Type::QAbstractButton).get();

  register_tool_button_tool_button_popup_mode_enum(tool_button);
  binding::QClass<QToolButton> binder{ tool_button, &QToolButton::staticMetaObject };

  // QToolButton(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QToolButton();
  binder.add_dtor();
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QToolButton::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QToolButton::minimumSizeHint>("minimumSizeHint");
  // Qt::ToolButtonStyle toolButtonStyle() const;
  binder.add_fun<Qt::ToolButtonStyle, &QToolButton::toolButtonStyle>("toolButtonStyle");
  // Qt::ArrowType arrowType() const;
  binder.add_fun<Qt::ArrowType, &QToolButton::arrowType>("arrowType");
  // void setArrowType(Qt::ArrowType);
  binder.add_void_fun<Qt::ArrowType, &QToolButton::setArrowType>("setArrowType");
  // void setMenu(QMenu *);
  /// TODO: void setMenu(QMenu *);
  // QMenu * menu() const;
  /// TODO: QMenu * menu() const;
  // void setPopupMode(QToolButton::ToolButtonPopupMode);
  binder.add_void_fun<QToolButton::ToolButtonPopupMode, &QToolButton::setPopupMode>("setPopupMode");
  // QToolButton::ToolButtonPopupMode popupMode() const;
  binder.add_fun<QToolButton::ToolButtonPopupMode, &QToolButton::popupMode>("popupMode");
  // QAction * defaultAction() const;
  /// TODO: QAction * defaultAction() const;
  // void setAutoRaise(bool);
  binder.add_void_fun<bool, &QToolButton::setAutoRaise>("setAutoRaise");
  // bool autoRaise() const;
  binder.add_fun<bool, &QToolButton::autoRaise>("autoRaise");
  // void showMenu();
  binder.add_void_fun<&QToolButton::showMenu>("showMenu");
  // void setToolButtonStyle(Qt::ToolButtonStyle);
  binder.add_void_fun<Qt::ToolButtonStyle, &QToolButton::setToolButtonStyle>("setToolButtonStyle");
  // void setDefaultAction(QAction *);
  /// TODO: void setDefaultAction(QAction *);

  tool_button.engine()->registerQtType(&QToolButton::staticMetaObject, tool_button.id());
}


void register_toolbutton_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_tool_button_class(ns);
  binding::Namespace binder{ ns };

}

