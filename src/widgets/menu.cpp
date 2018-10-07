// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/menu.h"

#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"
#include "yasl/utils/ref.h"

#include "yasl/core/object.h"
#include "yasl/core/point.h"
#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/gui/icon.h"
#include "yasl/widgets/action.h"
#include "yasl/widgets/menu.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>

static void register_menu_class(script::Namespace ns)
{
  using namespace script;

  Class menu = ns.Class("Menu").setId(script::Type::QMenu)
    .setBase(script::Type::QWidget).get();

  register_ref_specialization(menu.engine(), script::Type::QMenu, script::Type::QMenuStar);
  binding::QClass<QMenu> binder{ menu, &QMenu::staticMetaObject };

  // QMenu(QWidget *);
  binder.ctors().add<QWidget *>();
  // QMenu(const QString &, QWidget *);
  binder.ctors().add<const QString &, QWidget *>();
  // ~QMenu();
  binder.add_dtor();
  // QAction * addAction(const QString &);
  binder.add_fun<QAction *, const QString &, &QMenu::addAction>("addAction");
  // QAction * addAction(const QIcon &, const QString &);
  binder.add_fun<QAction *, const QIcon &, const QString &, &QMenu::addAction>("addAction");
  // QAction * addAction(const QString &, const QObject *, const char *, const QKeySequence &);
  /// TODO: QAction * addAction(const QString &, const QObject *, const char *, const QKeySequence &);
  // QAction * addAction(const QIcon &, const QString &, const QObject *, const char *, const QKeySequence &);
  /// TODO: QAction * addAction(const QIcon &, const QString &, const QObject *, const char *, const QKeySequence &);
  // QAction * addMenu(QMenu *);
  binder.add_fun<QAction *, QMenu *, &QMenu::addMenu>("addMenu");
  // QMenu * addMenu(const QString &);
  binder.add_fun<QMenu *, const QString &, &QMenu::addMenu>("addMenu");
  // QMenu * addMenu(const QIcon &, const QString &);
  binder.add_fun<QMenu *, const QIcon &, const QString &, &QMenu::addMenu>("addMenu");
  // QAction * addSeparator();
  binder.add_fun<QAction *, &QMenu::addSeparator>("addSeparator");
  // QAction * addSection(const QString &);
  binder.add_fun<QAction *, const QString &, &QMenu::addSection>("addSection");
  // QAction * addSection(const QIcon &, const QString &);
  binder.add_fun<QAction *, const QIcon &, const QString &, &QMenu::addSection>("addSection");
  // QAction * insertMenu(QAction *, QMenu *);
  binder.add_fun<QAction *, QAction *, QMenu *, &QMenu::insertMenu>("insertMenu");
  // QAction * insertSeparator(QAction *);
  binder.add_fun<QAction *, QAction *, &QMenu::insertSeparator>("insertSeparator");
  // QAction * insertSection(QAction *, const QString &);
  binder.add_fun<QAction *, QAction *, const QString &, &QMenu::insertSection>("insertSection");
  // QAction * insertSection(QAction *, const QIcon &, const QString &);
  binder.add_fun<QAction *, QAction *, const QIcon &, const QString &, &QMenu::insertSection>("insertSection");
  // bool isEmpty() const;
  binder.add_fun<bool, &QMenu::isEmpty>("isEmpty");
  // void clear();
  binder.add_void_fun<&QMenu::clear>("clear");
  // void setTearOffEnabled(bool);
  binder.add_void_fun<bool, &QMenu::setTearOffEnabled>("setTearOffEnabled");
  // bool isTearOffEnabled() const;
  binder.add_fun<bool, &QMenu::isTearOffEnabled>("isTearOffEnabled");
  // bool isTearOffMenuVisible() const;
  binder.add_fun<bool, &QMenu::isTearOffMenuVisible>("isTearOffMenuVisible");
  // void showTearOffMenu();
  binder.add_void_fun<&QMenu::showTearOffMenu>("showTearOffMenu");
  // void showTearOffMenu(const QPoint &);
  binder.add_void_fun<const QPoint &, &QMenu::showTearOffMenu>("showTearOffMenu");
  // void hideTearOffMenu();
  binder.add_void_fun<&QMenu::hideTearOffMenu>("hideTearOffMenu");
  // void setDefaultAction(QAction *);
  binder.add_void_fun<QAction *, &QMenu::setDefaultAction>("setDefaultAction");
  // QAction * defaultAction() const;
  binder.add_fun<QAction *, &QMenu::defaultAction>("defaultAction");
  // void setActiveAction(QAction *);
  binder.add_void_fun<QAction *, &QMenu::setActiveAction>("setActiveAction");
  // QAction * activeAction() const;
  binder.add_fun<QAction *, &QMenu::activeAction>("activeAction");
  // void popup(const QPoint &, QAction *);
  binder.add_void_fun<const QPoint &, QAction *, &QMenu::popup>("popup");
  // QAction * exec();
  binder.add_fun<QAction *, &QMenu::exec>("exec");
  // QAction * exec(const QPoint &, QAction *);
  binder.add_fun<QAction *, const QPoint &, QAction *, &QMenu::exec>("exec");
  // static QAction * exec(QList<QAction *>, const QPoint &, QAction *, QWidget *);
  /// TODO: static QAction * exec(QList<QAction *>, const QPoint &, QAction *, QWidget *);
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QMenu::sizeHint>("sizeHint");
  // QRect actionGeometry(QAction *) const;
  binder.add_fun<QRect, QAction *, &QMenu::actionGeometry>("actionGeometry");
  // QAction * actionAt(const QPoint &) const;
  binder.add_fun<QAction *, const QPoint &, &QMenu::actionAt>("actionAt");
  // QAction * menuAction() const;
  binder.add_fun<QAction *, &QMenu::menuAction>("menuAction");
  // QString title() const;
  binder.add_fun<QString, &QMenu::title>("title");
  // void setTitle(const QString &);
  binder.add_void_fun<const QString &, &QMenu::setTitle>("setTitle");
  // QIcon icon() const;
  binder.add_fun<QIcon, &QMenu::icon>("icon");
  // void setIcon(const QIcon &);
  binder.add_void_fun<const QIcon &, &QMenu::setIcon>("setIcon");
  // void setNoReplayFor(QWidget *);
  binder.add_void_fun<QWidget *, &QMenu::setNoReplayFor>("setNoReplayFor");
  // QPlatformMenu * platformMenu();
  /// TODO: QPlatformMenu * platformMenu();
  // void setPlatformMenu(QPlatformMenu *);
  /// TODO: void setPlatformMenu(QPlatformMenu *);
  // bool separatorsCollapsible() const;
  binder.add_fun<bool, &QMenu::separatorsCollapsible>("separatorsCollapsible");
  // void setSeparatorsCollapsible(bool);
  binder.add_void_fun<bool, &QMenu::setSeparatorsCollapsible>("setSeparatorsCollapsible");
  // bool toolTipsVisible() const;
  binder.add_fun<bool, &QMenu::toolTipsVisible>("toolTipsVisible");
  // void setToolTipsVisible(bool);
  binder.add_void_fun<bool, &QMenu::setToolTipsVisible>("setToolTipsVisible");
  // void aboutToShow();
  binder.sigs().add("aboutToShow", "aboutToShow()");
  // void aboutToHide();
  binder.sigs().add("aboutToHide", "aboutToHide()");
  // void triggered(QAction *);
  binder.sigs().add<QAction *>("triggered", "triggered(QAction *)");
  // void hovered(QAction *);
  binder.sigs().add<QAction *>("hovered", "hovered(QAction *)");

  menu.engine()->registerQtType(&QMenu::staticMetaObject, menu.id());
}


void register_menu_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_menu_class(ns);
  binding::Namespace binder{ ns };

  // QMenu& newMenu(QWidget*);
  NewFunction(binder).add<QMenu, QWidget*>("newMenu");
  // QMenu& newMenu(const QString&, QWidget*);
  NewFunction(binder).add<QMenu, const QString&, QWidget*>("newMenu");
}

