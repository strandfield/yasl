// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/toolbar.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/object.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/widgets/action.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_tool_bar_class(script::Namespace ns)
{
  using namespace script;

  Class tool_bar = ns.newClass("ToolBar").setId(script::Type::QToolBar)
    .setBase(script::Type::QWidget).get();


  // QToolBar(const QString &, QWidget * = (QWidget*)nullptr);
  bind::constructor<QToolBar, const QString &, QWidget *>(tool_bar)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QToolBar(QWidget * = (QWidget*)nullptr);
  bind::constructor<QToolBar, QWidget *>(tool_bar)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QToolBar();
  bind::destructor<QToolBar>(tool_bar).create();
  // void setMovable(bool);
  bind::void_member_function<QToolBar, bool, &QToolBar::setMovable>(tool_bar, "setMovable").create();
  // bool isMovable() const;
  bind::member_function<QToolBar, bool, &QToolBar::isMovable>(tool_bar, "isMovable").create();
  // void setAllowedAreas(Qt::ToolBarAreas);
  bind::void_member_function<QToolBar, Qt::ToolBarAreas, &QToolBar::setAllowedAreas>(tool_bar, "setAllowedAreas").create();
  // Qt::ToolBarAreas allowedAreas() const;
  bind::member_function<QToolBar, Qt::ToolBarAreas, &QToolBar::allowedAreas>(tool_bar, "allowedAreas").create();
  // bool isAreaAllowed(Qt::ToolBarArea) const;
  bind::member_function<QToolBar, bool, Qt::ToolBarArea, &QToolBar::isAreaAllowed>(tool_bar, "isAreaAllowed").create();
  // void setOrientation(Qt::Orientation);
  bind::void_member_function<QToolBar, Qt::Orientation, &QToolBar::setOrientation>(tool_bar, "setOrientation").create();
  // Qt::Orientation orientation() const;
  bind::member_function<QToolBar, Qt::Orientation, &QToolBar::orientation>(tool_bar, "orientation").create();
  // void clear();
  bind::void_member_function<QToolBar, &QToolBar::clear>(tool_bar, "clear").create();
  // QAction * addAction(const QString &);
  bind::member_function<QToolBar, QAction *, const QString &, &QToolBar::addAction>(tool_bar, "addAction").create();
  // QAction * addAction(const QIcon &, const QString &);
  bind::member_function<QToolBar, QAction *, const QIcon &, const QString &, &QToolBar::addAction>(tool_bar, "addAction").create();
  // QAction * addAction(const QString &, const QObject *, const char *);
  /// TODO: QAction * addAction(const QString &, const QObject *, const char *);
  // QAction * addAction(const QIcon &, const QString &, const QObject *, const char *);
  /// TODO: QAction * addAction(const QIcon &, const QString &, const QObject *, const char *);
  // QAction * addSeparator();
  bind::member_function<QToolBar, QAction *, &QToolBar::addSeparator>(tool_bar, "addSeparator").create();
  // QAction * insertSeparator(QAction *);
  bind::member_function<QToolBar, QAction *, QAction *, &QToolBar::insertSeparator>(tool_bar, "insertSeparator").create();
  // QAction * addWidget(QWidget *);
  bind::member_function<QToolBar, QAction *, QWidget *, &QToolBar::addWidget>(tool_bar, "addWidget").create();
  // QAction * insertWidget(QAction *, QWidget *);
  bind::member_function<QToolBar, QAction *, QAction *, QWidget *, &QToolBar::insertWidget>(tool_bar, "insertWidget").create();
  // QRect actionGeometry(QAction *) const;
  bind::member_function<QToolBar, QRect, QAction *, &QToolBar::actionGeometry>(tool_bar, "actionGeometry").create();
  // QAction * actionAt(const QPoint &) const;
  bind::member_function<QToolBar, QAction *, const QPoint &, &QToolBar::actionAt>(tool_bar, "actionAt").create();
  // QAction * actionAt(int, int) const;
  bind::member_function<QToolBar, QAction *, int, int, &QToolBar::actionAt>(tool_bar, "actionAt").create();
  // QAction * toggleViewAction() const;
  bind::member_function<QToolBar, QAction *, &QToolBar::toggleViewAction>(tool_bar, "toggleViewAction").create();
  // QSize iconSize() const;
  bind::member_function<QToolBar, QSize, &QToolBar::iconSize>(tool_bar, "iconSize").create();
  // Qt::ToolButtonStyle toolButtonStyle() const;
  bind::member_function<QToolBar, Qt::ToolButtonStyle, &QToolBar::toolButtonStyle>(tool_bar, "toolButtonStyle").create();
  // QWidget * widgetForAction(QAction *) const;
  bind::member_function<QToolBar, QWidget *, QAction *, &QToolBar::widgetForAction>(tool_bar, "widgetForAction").create();
  // bool isFloatable() const;
  bind::member_function<QToolBar, bool, &QToolBar::isFloatable>(tool_bar, "isFloatable").create();
  // void setFloatable(bool);
  bind::void_member_function<QToolBar, bool, &QToolBar::setFloatable>(tool_bar, "setFloatable").create();
  // bool isFloating() const;
  bind::member_function<QToolBar, bool, &QToolBar::isFloating>(tool_bar, "isFloating").create();
  // void setIconSize(const QSize &);
  bind::void_member_function<QToolBar, const QSize &, &QToolBar::setIconSize>(tool_bar, "setIconSize").create();
  // void setToolButtonStyle(Qt::ToolButtonStyle);
  bind::void_member_function<QToolBar, Qt::ToolButtonStyle, &QToolBar::setToolButtonStyle>(tool_bar, "setToolButtonStyle").create();
  // void actionTriggered(QAction *);
  bind::signal<QToolBar, QAction *>(tool_bar, "actionTriggered", "actionTriggered(QAction *)");
  // void movableChanged(bool);
  bind::signal<QToolBar, bool>(tool_bar, "movableChanged", "movableChanged(bool)");
  // void allowedAreasChanged(Qt::ToolBarAreas);
  bind::signal<QToolBar, Qt::ToolBarAreas>(tool_bar, "allowedAreasChanged", "allowedAreasChanged(Qt::ToolBarAreas)");
  // void orientationChanged(Qt::Orientation);
  bind::signal<QToolBar, Qt::Orientation>(tool_bar, "orientationChanged", "orientationChanged(Qt::Orientation)");
  // void iconSizeChanged(const QSize &);
  bind::signal<QToolBar, const QSize &>(tool_bar, "iconSizeChanged", "iconSizeChanged(const QSize &)");
  // void toolButtonStyleChanged(Qt::ToolButtonStyle);
  bind::signal<QToolBar, Qt::ToolButtonStyle>(tool_bar, "toolButtonStyleChanged", "toolButtonStyleChanged(Qt::ToolButtonStyle)");
  // void topLevelChanged(bool);
  bind::signal<QToolBar, bool>(tool_bar, "topLevelChanged", "topLevelChanged(bool)");
  // void visibilityChanged(bool);
  bind::signal<QToolBar, bool>(tool_bar, "visibilityChanged", "visibilityChanged(bool)");

  bind::link(tool_bar, &QToolBar::staticMetaObject);
}


void register_toolbar_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_tool_bar_class(ns);

  // QToolBar& newToolBar(const QString&, QWidget*);
  bind::new_function<QToolBar, const QString&, QWidget*>(ns, "newToolBar");
  // QToolBar& newToolBar(QWidget*);
  bind::new_function<QToolBar, QWidget*>(ns, "newToolBar");
}

