// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/tabwidget.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/enums.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/widgets/tabwidget.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_tab_widget_tab_position_enum(script::Class tab_widget)
{
  using namespace script;

  Enum tab_position = tab_widget.newEnum("TabPosition").setId(script::Type::QTabWidgetTabPosition).get();

  tab_position.addValue("North", QTabWidget::North);
  tab_position.addValue("South", QTabWidget::South);
  tab_position.addValue("West", QTabWidget::West);
  tab_position.addValue("East", QTabWidget::East);
}


static void register_tab_widget_tab_shape_enum(script::Class tab_widget)
{
  using namespace script;

  Enum tab_shape = tab_widget.newEnum("TabShape").setId(script::Type::QTabWidgetTabShape).get();

  tab_shape.addValue("Rounded", QTabWidget::Rounded);
  tab_shape.addValue("Triangular", QTabWidget::Triangular);
}


static void register_tab_widget_class(script::Namespace ns)
{
  using namespace script;

  Class tab_widget = ns.newClass("TabWidget").setId(script::Type::QTabWidget)
    .setBase(script::Type::QWidget).get();

  register_tab_widget_tab_position_enum(tab_widget);
  register_tab_widget_tab_shape_enum(tab_widget);

  // QTabWidget(QWidget * = (QWidget*)nullptr);
  bind::constructor<QTabWidget, QWidget *>(tab_widget)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QTabWidget();
  bind::destructor<QTabWidget>(tab_widget).create();
  // int addTab(QWidget *, const QString &);
  bind::member_function<QTabWidget, int, QWidget *, const QString &, &QTabWidget::addTab>(tab_widget, "addTab").create();
  // int addTab(QWidget *, const QIcon &, const QString &);
  bind::member_function<QTabWidget, int, QWidget *, const QIcon &, const QString &, &QTabWidget::addTab>(tab_widget, "addTab").create();
  // int insertTab(int, QWidget *, const QString &);
  bind::member_function<QTabWidget, int, int, QWidget *, const QString &, &QTabWidget::insertTab>(tab_widget, "insertTab").create();
  // int insertTab(int, QWidget *, const QIcon &, const QString &);
  bind::member_function<QTabWidget, int, int, QWidget *, const QIcon &, const QString &, &QTabWidget::insertTab>(tab_widget, "insertTab").create();
  // void removeTab(int);
  bind::void_member_function<QTabWidget, int, &QTabWidget::removeTab>(tab_widget, "removeTab").create();
  // bool isTabEnabled(int) const;
  bind::member_function<QTabWidget, bool, int, &QTabWidget::isTabEnabled>(tab_widget, "isTabEnabled").create();
  // void setTabEnabled(int, bool);
  bind::void_member_function<QTabWidget, int, bool, &QTabWidget::setTabEnabled>(tab_widget, "setTabEnabled").create();
  // QString tabText(int) const;
  bind::member_function<QTabWidget, QString, int, &QTabWidget::tabText>(tab_widget, "tabText").create();
  // void setTabText(int, const QString &);
  bind::void_member_function<QTabWidget, int, const QString &, &QTabWidget::setTabText>(tab_widget, "setTabText").create();
  // QIcon tabIcon(int) const;
  bind::member_function<QTabWidget, QIcon, int, &QTabWidget::tabIcon>(tab_widget, "tabIcon").create();
  // void setTabIcon(int, const QIcon &);
  bind::void_member_function<QTabWidget, int, const QIcon &, &QTabWidget::setTabIcon>(tab_widget, "setTabIcon").create();
  // void setTabToolTip(int, const QString &);
  bind::void_member_function<QTabWidget, int, const QString &, &QTabWidget::setTabToolTip>(tab_widget, "setTabToolTip").create();
  // QString tabToolTip(int) const;
  bind::member_function<QTabWidget, QString, int, &QTabWidget::tabToolTip>(tab_widget, "tabToolTip").create();
  // void setTabWhatsThis(int, const QString &);
  bind::void_member_function<QTabWidget, int, const QString &, &QTabWidget::setTabWhatsThis>(tab_widget, "setTabWhatsThis").create();
  // QString tabWhatsThis(int) const;
  bind::member_function<QTabWidget, QString, int, &QTabWidget::tabWhatsThis>(tab_widget, "tabWhatsThis").create();
  // int currentIndex() const;
  bind::member_function<QTabWidget, int, &QTabWidget::currentIndex>(tab_widget, "currentIndex").create();
  // QWidget * currentWidget() const;
  bind::member_function<QTabWidget, QWidget *, &QTabWidget::currentWidget>(tab_widget, "currentWidget").create();
  // QWidget * widget(int) const;
  bind::member_function<QTabWidget, QWidget *, int, &QTabWidget::widget>(tab_widget, "widget").create();
  // int indexOf(QWidget *) const;
  bind::member_function<QTabWidget, int, QWidget *, &QTabWidget::indexOf>(tab_widget, "indexOf").create();
  // int count() const;
  bind::member_function<QTabWidget, int, &QTabWidget::count>(tab_widget, "count").create();
  // QTabWidget::TabPosition tabPosition() const;
  bind::member_function<QTabWidget, QTabWidget::TabPosition, &QTabWidget::tabPosition>(tab_widget, "tabPosition").create();
  // void setTabPosition(QTabWidget::TabPosition);
  bind::void_member_function<QTabWidget, QTabWidget::TabPosition, &QTabWidget::setTabPosition>(tab_widget, "setTabPosition").create();
  // bool tabsClosable() const;
  bind::member_function<QTabWidget, bool, &QTabWidget::tabsClosable>(tab_widget, "tabsClosable").create();
  // void setTabsClosable(bool);
  bind::void_member_function<QTabWidget, bool, &QTabWidget::setTabsClosable>(tab_widget, "setTabsClosable").create();
  // bool isMovable() const;
  bind::member_function<QTabWidget, bool, &QTabWidget::isMovable>(tab_widget, "isMovable").create();
  // void setMovable(bool);
  bind::void_member_function<QTabWidget, bool, &QTabWidget::setMovable>(tab_widget, "setMovable").create();
  // QTabWidget::TabShape tabShape() const;
  bind::member_function<QTabWidget, QTabWidget::TabShape, &QTabWidget::tabShape>(tab_widget, "tabShape").create();
  // void setTabShape(QTabWidget::TabShape);
  bind::void_member_function<QTabWidget, QTabWidget::TabShape, &QTabWidget::setTabShape>(tab_widget, "setTabShape").create();
  // QSize sizeHint() const;
  bind::member_function<QTabWidget, QSize, &QTabWidget::sizeHint>(tab_widget, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QTabWidget, QSize, &QTabWidget::minimumSizeHint>(tab_widget, "minimumSizeHint").create();
  // int heightForWidth(int) const;
  bind::member_function<QTabWidget, int, int, &QTabWidget::heightForWidth>(tab_widget, "heightForWidth").create();
  // bool hasHeightForWidth() const;
  bind::member_function<QTabWidget, bool, &QTabWidget::hasHeightForWidth>(tab_widget, "hasHeightForWidth").create();
  // void setCornerWidget(QWidget *, Qt::Corner = Qt::TopRightCorner);
  bind::void_member_function<QTabWidget, QWidget *, Qt::Corner, &QTabWidget::setCornerWidget>(tab_widget, "setCornerWidget")
    .apply(bind::default_arguments(Qt::TopRightCorner)).create();
  // QWidget * cornerWidget(Qt::Corner = Qt::TopRightCorner) const;
  bind::member_function<QTabWidget, QWidget *, Qt::Corner, &QTabWidget::cornerWidget>(tab_widget, "cornerWidget")
    .apply(bind::default_arguments(Qt::TopRightCorner)).create();
  // Qt::TextElideMode elideMode() const;
  bind::member_function<QTabWidget, Qt::TextElideMode, &QTabWidget::elideMode>(tab_widget, "elideMode").create();
  // void setElideMode(Qt::TextElideMode);
  bind::void_member_function<QTabWidget, Qt::TextElideMode, &QTabWidget::setElideMode>(tab_widget, "setElideMode").create();
  // QSize iconSize() const;
  bind::member_function<QTabWidget, QSize, &QTabWidget::iconSize>(tab_widget, "iconSize").create();
  // void setIconSize(const QSize &);
  bind::void_member_function<QTabWidget, const QSize &, &QTabWidget::setIconSize>(tab_widget, "setIconSize").create();
  // bool usesScrollButtons() const;
  bind::member_function<QTabWidget, bool, &QTabWidget::usesScrollButtons>(tab_widget, "usesScrollButtons").create();
  // void setUsesScrollButtons(bool);
  bind::void_member_function<QTabWidget, bool, &QTabWidget::setUsesScrollButtons>(tab_widget, "setUsesScrollButtons").create();
  // bool documentMode() const;
  bind::member_function<QTabWidget, bool, &QTabWidget::documentMode>(tab_widget, "documentMode").create();
  // void setDocumentMode(bool);
  bind::void_member_function<QTabWidget, bool, &QTabWidget::setDocumentMode>(tab_widget, "setDocumentMode").create();
  // bool tabBarAutoHide() const;
  bind::member_function<QTabWidget, bool, &QTabWidget::tabBarAutoHide>(tab_widget, "tabBarAutoHide").create();
  // void setTabBarAutoHide(bool);
  bind::void_member_function<QTabWidget, bool, &QTabWidget::setTabBarAutoHide>(tab_widget, "setTabBarAutoHide").create();
  // void clear();
  bind::void_member_function<QTabWidget, &QTabWidget::clear>(tab_widget, "clear").create();
  // QTabBar * tabBar() const;
  /// TODO: QTabBar * tabBar() const;
  // void setCurrentIndex(int);
  bind::void_member_function<QTabWidget, int, &QTabWidget::setCurrentIndex>(tab_widget, "setCurrentIndex").create();
  // void setCurrentWidget(QWidget *);
  bind::void_member_function<QTabWidget, QWidget *, &QTabWidget::setCurrentWidget>(tab_widget, "setCurrentWidget").create();
  // void currentChanged(int);
  bind::signal<QTabWidget, int>(tab_widget, "currentChanged", "currentChanged(int)");
  // void tabCloseRequested(int);
  bind::signal<QTabWidget, int>(tab_widget, "tabCloseRequested", "tabCloseRequested(int)");
  // void tabBarClicked(int);
  bind::signal<QTabWidget, int>(tab_widget, "tabBarClicked", "tabBarClicked(int)");
  // void tabBarDoubleClicked(int);
  bind::signal<QTabWidget, int>(tab_widget, "tabBarDoubleClicked", "tabBarDoubleClicked(int)");

  bind::link(tab_widget, &QTabWidget::staticMetaObject);
}


void register_tabwidget_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_tab_widget_class(ns);

  // QTabWidget& newTabWidget(QWidget*);
  bind::new_function<QTabWidget, QWidget*>(ns, "newTabWidget");
}

