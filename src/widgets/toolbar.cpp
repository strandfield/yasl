// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/toolbar.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/qclass.h"

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

  Class tool_bar = ns.Class("ToolBar").setId(script::Type::QToolBar)
    .setBase(script::Type::QWidget).get();

  binding::QClass<QToolBar> binder{ tool_bar, &QToolBar::staticMetaObject };

  // QToolBar(const QString &, QWidget *);
  binder.ctors().add<const QString &, QWidget *>();
  // QToolBar(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QToolBar();
  binder.add_dtor();
  // void setMovable(bool);
  binder.add_void_fun<bool, &QToolBar::setMovable>("setMovable");
  // bool isMovable() const;
  binder.add_fun<bool, &QToolBar::isMovable>("isMovable");
  // void setAllowedAreas(Qt::ToolBarAreas);
  binder.add_void_fun<Qt::ToolBarAreas, &QToolBar::setAllowedAreas>("setAllowedAreas");
  // Qt::ToolBarAreas allowedAreas() const;
  binder.add_fun<Qt::ToolBarAreas, &QToolBar::allowedAreas>("allowedAreas");
  // bool isAreaAllowed(Qt::ToolBarArea) const;
  binder.add_fun<bool, Qt::ToolBarArea, &QToolBar::isAreaAllowed>("isAreaAllowed");
  // void setOrientation(Qt::Orientation);
  binder.add_void_fun<Qt::Orientation, &QToolBar::setOrientation>("setOrientation");
  // Qt::Orientation orientation() const;
  binder.add_fun<Qt::Orientation, &QToolBar::orientation>("orientation");
  // void clear();
  binder.add_void_fun<&QToolBar::clear>("clear");
  // QAction * addAction(const QString &);
  binder.add_fun<QAction *, const QString &, &QToolBar::addAction>("addAction");
  // QAction * addAction(const QIcon &, const QString &);
  binder.add_fun<QAction *, const QIcon &, const QString &, &QToolBar::addAction>("addAction");
  // QAction * addAction(const QString &, const QObject *, const char *);
  /// TODO: QAction * addAction(const QString &, const QObject *, const char *);
  // QAction * addAction(const QIcon &, const QString &, const QObject *, const char *);
  /// TODO: QAction * addAction(const QIcon &, const QString &, const QObject *, const char *);
  // QAction * addSeparator();
  binder.add_fun<QAction *, &QToolBar::addSeparator>("addSeparator");
  // QAction * insertSeparator(QAction *);
  binder.add_fun<QAction *, QAction *, &QToolBar::insertSeparator>("insertSeparator");
  // QAction * addWidget(QWidget *);
  binder.add_fun<QAction *, QWidget *, &QToolBar::addWidget>("addWidget");
  // QAction * insertWidget(QAction *, QWidget *);
  binder.add_fun<QAction *, QAction *, QWidget *, &QToolBar::insertWidget>("insertWidget");
  // QRect actionGeometry(QAction *) const;
  binder.add_fun<QRect, QAction *, &QToolBar::actionGeometry>("actionGeometry");
  // QAction * actionAt(const QPoint &) const;
  binder.add_fun<QAction *, const QPoint &, &QToolBar::actionAt>("actionAt");
  // QAction * actionAt(int, int) const;
  binder.add_fun<QAction *, int, int, &QToolBar::actionAt>("actionAt");
  // QAction * toggleViewAction() const;
  binder.add_fun<QAction *, &QToolBar::toggleViewAction>("toggleViewAction");
  // QSize iconSize() const;
  binder.add_fun<QSize, &QToolBar::iconSize>("iconSize");
  // Qt::ToolButtonStyle toolButtonStyle() const;
  binder.add_fun<Qt::ToolButtonStyle, &QToolBar::toolButtonStyle>("toolButtonStyle");
  // QWidget * widgetForAction(QAction *) const;
  binder.add_fun<QWidget *, QAction *, &QToolBar::widgetForAction>("widgetForAction");
  // bool isFloatable() const;
  binder.add_fun<bool, &QToolBar::isFloatable>("isFloatable");
  // void setFloatable(bool);
  binder.add_void_fun<bool, &QToolBar::setFloatable>("setFloatable");
  // bool isFloating() const;
  binder.add_fun<bool, &QToolBar::isFloating>("isFloating");
  // void setIconSize(const QSize &);
  binder.add_void_fun<const QSize &, &QToolBar::setIconSize>("setIconSize");
  // void setToolButtonStyle(Qt::ToolButtonStyle);
  binder.add_void_fun<Qt::ToolButtonStyle, &QToolBar::setToolButtonStyle>("setToolButtonStyle");
  // void actionTriggered(QAction *);
  binder.sigs().add<QAction *>("actionTriggered", "actionTriggered(QAction *)");
  // void movableChanged(bool);
  binder.sigs().add<bool>("movableChanged", "movableChanged(bool)");
  // void allowedAreasChanged(Qt::ToolBarAreas);
  binder.sigs().add<Qt::ToolBarAreas>("allowedAreasChanged", "allowedAreasChanged(Qt::ToolBarAreas)");
  // void orientationChanged(Qt::Orientation);
  binder.sigs().add<Qt::Orientation>("orientationChanged", "orientationChanged(Qt::Orientation)");
  // void iconSizeChanged(const QSize &);
  binder.sigs().add<const QSize &>("iconSizeChanged", "iconSizeChanged(const QSize &)");
  // void toolButtonStyleChanged(Qt::ToolButtonStyle);
  binder.sigs().add<Qt::ToolButtonStyle>("toolButtonStyleChanged", "toolButtonStyleChanged(Qt::ToolButtonStyle)");
  // void topLevelChanged(bool);
  binder.sigs().add<bool>("topLevelChanged", "topLevelChanged(bool)");
  // void visibilityChanged(bool);
  binder.sigs().add<bool>("visibilityChanged", "visibilityChanged(bool)");

  tool_bar.engine()->registerQtType(&QToolBar::staticMetaObject, tool_bar.id());
}


void register_toolbar_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_tool_bar_class(ns);
  binding::Namespace binder{ ns };

}

