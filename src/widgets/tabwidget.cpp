// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/tabwidget.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

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

  Enum tab_position = tab_widget.Enum("TabPosition").setId(script::Type::QTabWidgetTabPosition).get();

  tab_position.addValue("North", QTabWidget::North);
  tab_position.addValue("South", QTabWidget::South);
  tab_position.addValue("West", QTabWidget::West);
  tab_position.addValue("East", QTabWidget::East);
}


static void register_tab_widget_tab_shape_enum(script::Class tab_widget)
{
  using namespace script;

  Enum tab_shape = tab_widget.Enum("TabShape").setId(script::Type::QTabWidgetTabShape).get();

  tab_shape.addValue("Rounded", QTabWidget::Rounded);
  tab_shape.addValue("Triangular", QTabWidget::Triangular);
}


static void register_tab_widget_class(script::Namespace ns)
{
  using namespace script;

  Class tab_widget = ns.Class("TabWidget").setId(script::Type::QTabWidget)
    .setBase(script::Type::QWidget).get();

  register_tab_widget_tab_position_enum(tab_widget);
  register_tab_widget_tab_shape_enum(tab_widget);
  binding::QClass<QTabWidget> binder{ tab_widget, &QTabWidget::staticMetaObject };

  // QTabWidget(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QTabWidget();
  binder.add_dtor();
  // int addTab(QWidget *, const QString &);
  binder.add_fun<int, QWidget *, const QString &, &QTabWidget::addTab>("addTab");
  // int addTab(QWidget *, const QIcon &, const QString &);
  binder.add_fun<int, QWidget *, const QIcon &, const QString &, &QTabWidget::addTab>("addTab");
  // int insertTab(int, QWidget *, const QString &);
  binder.add_fun<int, int, QWidget *, const QString &, &QTabWidget::insertTab>("insertTab");
  // int insertTab(int, QWidget *, const QIcon &, const QString &);
  binder.add_fun<int, int, QWidget *, const QIcon &, const QString &, &QTabWidget::insertTab>("insertTab");
  // void removeTab(int);
  binder.add_void_fun<int, &QTabWidget::removeTab>("removeTab");
  // bool isTabEnabled(int) const;
  binder.add_fun<bool, int, &QTabWidget::isTabEnabled>("isTabEnabled");
  // void setTabEnabled(int, bool);
  binder.add_void_fun<int, bool, &QTabWidget::setTabEnabled>("setTabEnabled");
  // QString tabText(int) const;
  binder.add_fun<QString, int, &QTabWidget::tabText>("tabText");
  // void setTabText(int, const QString &);
  binder.add_void_fun<int, const QString &, &QTabWidget::setTabText>("setTabText");
  // QIcon tabIcon(int) const;
  binder.add_fun<QIcon, int, &QTabWidget::tabIcon>("tabIcon");
  // void setTabIcon(int, const QIcon &);
  binder.add_void_fun<int, const QIcon &, &QTabWidget::setTabIcon>("setTabIcon");
  // void setTabToolTip(int, const QString &);
  binder.add_void_fun<int, const QString &, &QTabWidget::setTabToolTip>("setTabToolTip");
  // QString tabToolTip(int) const;
  binder.add_fun<QString, int, &QTabWidget::tabToolTip>("tabToolTip");
  // void setTabWhatsThis(int, const QString &);
  binder.add_void_fun<int, const QString &, &QTabWidget::setTabWhatsThis>("setTabWhatsThis");
  // QString tabWhatsThis(int) const;
  binder.add_fun<QString, int, &QTabWidget::tabWhatsThis>("tabWhatsThis");
  // int currentIndex() const;
  binder.add_fun<int, &QTabWidget::currentIndex>("currentIndex");
  // QWidget * currentWidget() const;
  binder.add_fun<QWidget *, &QTabWidget::currentWidget>("currentWidget");
  // QWidget * widget(int) const;
  binder.add_fun<QWidget *, int, &QTabWidget::widget>("widget");
  // int indexOf(QWidget *) const;
  binder.add_fun<int, QWidget *, &QTabWidget::indexOf>("indexOf");
  // int count() const;
  binder.add_fun<int, &QTabWidget::count>("count");
  // QTabWidget::TabPosition tabPosition() const;
  binder.add_fun<QTabWidget::TabPosition, &QTabWidget::tabPosition>("tabPosition");
  // void setTabPosition(QTabWidget::TabPosition);
  binder.add_void_fun<QTabWidget::TabPosition, &QTabWidget::setTabPosition>("setTabPosition");
  // bool tabsClosable() const;
  binder.add_fun<bool, &QTabWidget::tabsClosable>("tabsClosable");
  // void setTabsClosable(bool);
  binder.add_void_fun<bool, &QTabWidget::setTabsClosable>("setTabsClosable");
  // bool isMovable() const;
  binder.add_fun<bool, &QTabWidget::isMovable>("isMovable");
  // void setMovable(bool);
  binder.add_void_fun<bool, &QTabWidget::setMovable>("setMovable");
  // QTabWidget::TabShape tabShape() const;
  binder.add_fun<QTabWidget::TabShape, &QTabWidget::tabShape>("tabShape");
  // void setTabShape(QTabWidget::TabShape);
  binder.add_void_fun<QTabWidget::TabShape, &QTabWidget::setTabShape>("setTabShape");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QTabWidget::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QTabWidget::minimumSizeHint>("minimumSizeHint");
  // int heightForWidth(int) const;
  binder.add_fun<int, int, &QTabWidget::heightForWidth>("heightForWidth");
  // bool hasHeightForWidth() const;
  binder.add_fun<bool, &QTabWidget::hasHeightForWidth>("hasHeightForWidth");
  // void setCornerWidget(QWidget *, Qt::Corner);
  binder.add_void_fun<QWidget *, Qt::Corner, &QTabWidget::setCornerWidget>("setCornerWidget");
  // QWidget * cornerWidget(Qt::Corner) const;
  binder.add_fun<QWidget *, Qt::Corner, &QTabWidget::cornerWidget>("cornerWidget");
  // Qt::TextElideMode elideMode() const;
  binder.add_fun<Qt::TextElideMode, &QTabWidget::elideMode>("elideMode");
  // void setElideMode(Qt::TextElideMode);
  binder.add_void_fun<Qt::TextElideMode, &QTabWidget::setElideMode>("setElideMode");
  // QSize iconSize() const;
  binder.add_fun<QSize, &QTabWidget::iconSize>("iconSize");
  // void setIconSize(const QSize &);
  binder.add_void_fun<const QSize &, &QTabWidget::setIconSize>("setIconSize");
  // bool usesScrollButtons() const;
  binder.add_fun<bool, &QTabWidget::usesScrollButtons>("usesScrollButtons");
  // void setUsesScrollButtons(bool);
  binder.add_void_fun<bool, &QTabWidget::setUsesScrollButtons>("setUsesScrollButtons");
  // bool documentMode() const;
  binder.add_fun<bool, &QTabWidget::documentMode>("documentMode");
  // void setDocumentMode(bool);
  binder.add_void_fun<bool, &QTabWidget::setDocumentMode>("setDocumentMode");
  // bool tabBarAutoHide() const;
  binder.add_fun<bool, &QTabWidget::tabBarAutoHide>("tabBarAutoHide");
  // void setTabBarAutoHide(bool);
  binder.add_void_fun<bool, &QTabWidget::setTabBarAutoHide>("setTabBarAutoHide");
  // void clear();
  binder.add_void_fun<&QTabWidget::clear>("clear");
  // QTabBar * tabBar() const;
  /// TODO: QTabBar * tabBar() const;
  // void setCurrentIndex(int);
  binder.add_void_fun<int, &QTabWidget::setCurrentIndex>("setCurrentIndex");
  // void setCurrentWidget(QWidget *);
  binder.add_void_fun<QWidget *, &QTabWidget::setCurrentWidget>("setCurrentWidget");
  // void currentChanged(int);
  binder.sigs().add<int>("currentChanged", "currentChanged(int)");
  // void tabCloseRequested(int);
  binder.sigs().add<int>("tabCloseRequested", "tabCloseRequested(int)");
  // void tabBarClicked(int);
  binder.sigs().add<int>("tabBarClicked", "tabBarClicked(int)");
  // void tabBarDoubleClicked(int);
  binder.sigs().add<int>("tabBarDoubleClicked", "tabBarDoubleClicked(int)");

  tab_widget.engine()->registerQtType(&QTabWidget::staticMetaObject, tab_widget.id());
}


void register_tabwidget_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_tab_widget_class(ns);
  binding::Namespace binder{ ns };

  // QTabWidget& newTabWidget(QWidget*);
  NewFunction(binder).add<QTabWidget, QWidget*>("newTabWidget");
}

