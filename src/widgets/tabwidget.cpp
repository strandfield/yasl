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
  binder.ctors().ctor<QWidget *>().create();
  // ~QTabWidget();
  binder.add_dtor();
  // int addTab(QWidget *, const QString &);
  binder.fun<int, QWidget *, const QString &, &QTabWidget::addTab>("addTab").create();
  // int addTab(QWidget *, const QIcon &, const QString &);
  binder.fun<int, QWidget *, const QIcon &, const QString &, &QTabWidget::addTab>("addTab").create();
  // int insertTab(int, QWidget *, const QString &);
  binder.fun<int, int, QWidget *, const QString &, &QTabWidget::insertTab>("insertTab").create();
  // int insertTab(int, QWidget *, const QIcon &, const QString &);
  binder.fun<int, int, QWidget *, const QIcon &, const QString &, &QTabWidget::insertTab>("insertTab").create();
  // void removeTab(int);
  binder.void_fun<int, &QTabWidget::removeTab>("removeTab").create();
  // bool isTabEnabled(int) const;
  binder.fun<bool, int, &QTabWidget::isTabEnabled>("isTabEnabled").create();
  // void setTabEnabled(int, bool);
  binder.void_fun<int, bool, &QTabWidget::setTabEnabled>("setTabEnabled").create();
  // QString tabText(int) const;
  binder.fun<QString, int, &QTabWidget::tabText>("tabText").create();
  // void setTabText(int, const QString &);
  binder.void_fun<int, const QString &, &QTabWidget::setTabText>("setTabText").create();
  // QIcon tabIcon(int) const;
  binder.fun<QIcon, int, &QTabWidget::tabIcon>("tabIcon").create();
  // void setTabIcon(int, const QIcon &);
  binder.void_fun<int, const QIcon &, &QTabWidget::setTabIcon>("setTabIcon").create();
  // void setTabToolTip(int, const QString &);
  binder.void_fun<int, const QString &, &QTabWidget::setTabToolTip>("setTabToolTip").create();
  // QString tabToolTip(int) const;
  binder.fun<QString, int, &QTabWidget::tabToolTip>("tabToolTip").create();
  // void setTabWhatsThis(int, const QString &);
  binder.void_fun<int, const QString &, &QTabWidget::setTabWhatsThis>("setTabWhatsThis").create();
  // QString tabWhatsThis(int) const;
  binder.fun<QString, int, &QTabWidget::tabWhatsThis>("tabWhatsThis").create();
  // int currentIndex() const;
  binder.fun<int, &QTabWidget::currentIndex>("currentIndex").create();
  // QWidget * currentWidget() const;
  binder.fun<QWidget *, &QTabWidget::currentWidget>("currentWidget").create();
  // QWidget * widget(int) const;
  binder.fun<QWidget *, int, &QTabWidget::widget>("widget").create();
  // int indexOf(QWidget *) const;
  binder.fun<int, QWidget *, &QTabWidget::indexOf>("indexOf").create();
  // int count() const;
  binder.fun<int, &QTabWidget::count>("count").create();
  // QTabWidget::TabPosition tabPosition() const;
  binder.fun<QTabWidget::TabPosition, &QTabWidget::tabPosition>("tabPosition").create();
  // void setTabPosition(QTabWidget::TabPosition);
  binder.void_fun<QTabWidget::TabPosition, &QTabWidget::setTabPosition>("setTabPosition").create();
  // bool tabsClosable() const;
  binder.fun<bool, &QTabWidget::tabsClosable>("tabsClosable").create();
  // void setTabsClosable(bool);
  binder.void_fun<bool, &QTabWidget::setTabsClosable>("setTabsClosable").create();
  // bool isMovable() const;
  binder.fun<bool, &QTabWidget::isMovable>("isMovable").create();
  // void setMovable(bool);
  binder.void_fun<bool, &QTabWidget::setMovable>("setMovable").create();
  // QTabWidget::TabShape tabShape() const;
  binder.fun<QTabWidget::TabShape, &QTabWidget::tabShape>("tabShape").create();
  // void setTabShape(QTabWidget::TabShape);
  binder.void_fun<QTabWidget::TabShape, &QTabWidget::setTabShape>("setTabShape").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QTabWidget::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QTabWidget::minimumSizeHint>("minimumSizeHint").create();
  // int heightForWidth(int) const;
  binder.fun<int, int, &QTabWidget::heightForWidth>("heightForWidth").create();
  // bool hasHeightForWidth() const;
  binder.fun<bool, &QTabWidget::hasHeightForWidth>("hasHeightForWidth").create();
  // void setCornerWidget(QWidget *, Qt::Corner);
  binder.void_fun<QWidget *, Qt::Corner, &QTabWidget::setCornerWidget>("setCornerWidget").create();
  // QWidget * cornerWidget(Qt::Corner) const;
  binder.fun<QWidget *, Qt::Corner, &QTabWidget::cornerWidget>("cornerWidget").create();
  // Qt::TextElideMode elideMode() const;
  binder.fun<Qt::TextElideMode, &QTabWidget::elideMode>("elideMode").create();
  // void setElideMode(Qt::TextElideMode);
  binder.void_fun<Qt::TextElideMode, &QTabWidget::setElideMode>("setElideMode").create();
  // QSize iconSize() const;
  binder.fun<QSize, &QTabWidget::iconSize>("iconSize").create();
  // void setIconSize(const QSize &);
  binder.void_fun<const QSize &, &QTabWidget::setIconSize>("setIconSize").create();
  // bool usesScrollButtons() const;
  binder.fun<bool, &QTabWidget::usesScrollButtons>("usesScrollButtons").create();
  // void setUsesScrollButtons(bool);
  binder.void_fun<bool, &QTabWidget::setUsesScrollButtons>("setUsesScrollButtons").create();
  // bool documentMode() const;
  binder.fun<bool, &QTabWidget::documentMode>("documentMode").create();
  // void setDocumentMode(bool);
  binder.void_fun<bool, &QTabWidget::setDocumentMode>("setDocumentMode").create();
  // bool tabBarAutoHide() const;
  binder.fun<bool, &QTabWidget::tabBarAutoHide>("tabBarAutoHide").create();
  // void setTabBarAutoHide(bool);
  binder.void_fun<bool, &QTabWidget::setTabBarAutoHide>("setTabBarAutoHide").create();
  // void clear();
  binder.void_fun<&QTabWidget::clear>("clear").create();
  // QTabBar * tabBar() const;
  /// TODO: QTabBar * tabBar() const;
  // void setCurrentIndex(int);
  binder.void_fun<int, &QTabWidget::setCurrentIndex>("setCurrentIndex").create();
  // void setCurrentWidget(QWidget *);
  binder.void_fun<QWidget *, &QTabWidget::setCurrentWidget>("setCurrentWidget").create();
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

