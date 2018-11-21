// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/toolbar.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
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

  Class tool_bar = ns.newClass("ToolBar").setId(script::Type::QToolBar)
    .setBase(script::Type::QWidget).get();

  binding::ClassBinder<QToolBar> binder{ tool_bar, &QToolBar::staticMetaObject };

  // QToolBar(const QString &, QWidget *);
  binder.ctor<const QString &, QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // QToolBar(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QToolBar();
  binder.dtor().create();
  // void setMovable(bool);
  binder.void_fun<bool, &QToolBar::setMovable>("setMovable").create();
  // bool isMovable() const;
  binder.fun<bool, &QToolBar::isMovable>("isMovable").create();
  // void setAllowedAreas(Qt::ToolBarAreas);
  binder.void_fun<Qt::ToolBarAreas, &QToolBar::setAllowedAreas>("setAllowedAreas").create();
  // Qt::ToolBarAreas allowedAreas() const;
  binder.fun<Qt::ToolBarAreas, &QToolBar::allowedAreas>("allowedAreas").create();
  // bool isAreaAllowed(Qt::ToolBarArea) const;
  binder.fun<bool, Qt::ToolBarArea, &QToolBar::isAreaAllowed>("isAreaAllowed").create();
  // void setOrientation(Qt::Orientation);
  binder.void_fun<Qt::Orientation, &QToolBar::setOrientation>("setOrientation").create();
  // Qt::Orientation orientation() const;
  binder.fun<Qt::Orientation, &QToolBar::orientation>("orientation").create();
  // void clear();
  binder.void_fun<&QToolBar::clear>("clear").create();
  // QAction * addAction(const QString &);
  binder.fun<QAction *, const QString &, &QToolBar::addAction>("addAction").create();
  // QAction * addAction(const QIcon &, const QString &);
  binder.fun<QAction *, const QIcon &, const QString &, &QToolBar::addAction>("addAction").create();
  // QAction * addAction(const QString &, const QObject *, const char *);
  /// TODO: QAction * addAction(const QString &, const QObject *, const char *);
  // QAction * addAction(const QIcon &, const QString &, const QObject *, const char *);
  /// TODO: QAction * addAction(const QIcon &, const QString &, const QObject *, const char *);
  // QAction * addSeparator();
  binder.fun<QAction *, &QToolBar::addSeparator>("addSeparator").create();
  // QAction * insertSeparator(QAction *);
  binder.fun<QAction *, QAction *, &QToolBar::insertSeparator>("insertSeparator").create();
  // QAction * addWidget(QWidget *);
  binder.fun<QAction *, QWidget *, &QToolBar::addWidget>("addWidget").create();
  // QAction * insertWidget(QAction *, QWidget *);
  binder.fun<QAction *, QAction *, QWidget *, &QToolBar::insertWidget>("insertWidget").create();
  // QRect actionGeometry(QAction *) const;
  binder.fun<QRect, QAction *, &QToolBar::actionGeometry>("actionGeometry").create();
  // QAction * actionAt(const QPoint &) const;
  binder.fun<QAction *, const QPoint &, &QToolBar::actionAt>("actionAt").create();
  // QAction * actionAt(int, int) const;
  binder.fun<QAction *, int, int, &QToolBar::actionAt>("actionAt").create();
  // QAction * toggleViewAction() const;
  binder.fun<QAction *, &QToolBar::toggleViewAction>("toggleViewAction").create();
  // QSize iconSize() const;
  binder.fun<QSize, &QToolBar::iconSize>("iconSize").create();
  // Qt::ToolButtonStyle toolButtonStyle() const;
  binder.fun<Qt::ToolButtonStyle, &QToolBar::toolButtonStyle>("toolButtonStyle").create();
  // QWidget * widgetForAction(QAction *) const;
  binder.fun<QWidget *, QAction *, &QToolBar::widgetForAction>("widgetForAction").create();
  // bool isFloatable() const;
  binder.fun<bool, &QToolBar::isFloatable>("isFloatable").create();
  // void setFloatable(bool);
  binder.void_fun<bool, &QToolBar::setFloatable>("setFloatable").create();
  // bool isFloating() const;
  binder.fun<bool, &QToolBar::isFloating>("isFloating").create();
  // void setIconSize(const QSize &);
  binder.void_fun<const QSize &, &QToolBar::setIconSize>("setIconSize").create();
  // void setToolButtonStyle(Qt::ToolButtonStyle);
  binder.void_fun<Qt::ToolButtonStyle, &QToolBar::setToolButtonStyle>("setToolButtonStyle").create();
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

  // QToolBar& newToolBar(const QString&, QWidget*);
  NewFunction(binder).add<QToolBar, const QString&, QWidget*>("newToolBar");
  // QToolBar& newToolBar(QWidget*);
  NewFunction(binder).add<QToolBar, QWidget*>("newToolBar");
}

