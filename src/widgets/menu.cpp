// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/menu.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/newfunction.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/common/ref.h"

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

  Class menu = ns.newClass("Menu").setId(script::Type::QMenu)
    .setBase(script::Type::QWidget).get();

  register_ref_specialization(menu.engine(), script::Type::QMenu, script::Type::QMenuStar);

  // QMenu(QWidget *);
  bind::constructor<QMenu, QWidget *>(menu)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QMenu(const QString &, QWidget *);
  bind::constructor<QMenu, const QString &, QWidget *>(menu)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QMenu();
  bind::destructor<QMenu>(menu).create();
  // QAction * addAction(const QString &);
  bind::member_function<QMenu, QAction *, const QString &, &QMenu::addAction>(menu, "addAction").create();
  // QAction * addAction(const QIcon &, const QString &);
  bind::member_function<QMenu, QAction *, const QIcon &, const QString &, &QMenu::addAction>(menu, "addAction").create();
  // QAction * addAction(const QString &, const QObject *, const char *, const QKeySequence &);
  /// TODO: QAction * addAction(const QString &, const QObject *, const char *, const QKeySequence &);
  // QAction * addAction(const QIcon &, const QString &, const QObject *, const char *, const QKeySequence &);
  /// TODO: QAction * addAction(const QIcon &, const QString &, const QObject *, const char *, const QKeySequence &);
  // QAction * addMenu(QMenu *);
  bind::member_function<QMenu, QAction *, QMenu *, &QMenu::addMenu>(menu, "addMenu").create();
  // QMenu * addMenu(const QString &);
  bind::member_function<QMenu, QMenu *, const QString &, &QMenu::addMenu>(menu, "addMenu").create();
  // QMenu * addMenu(const QIcon &, const QString &);
  bind::member_function<QMenu, QMenu *, const QIcon &, const QString &, &QMenu::addMenu>(menu, "addMenu").create();
  // QAction * addSeparator();
  bind::member_function<QMenu, QAction *, &QMenu::addSeparator>(menu, "addSeparator").create();
  // QAction * addSection(const QString &);
  bind::member_function<QMenu, QAction *, const QString &, &QMenu::addSection>(menu, "addSection").create();
  // QAction * addSection(const QIcon &, const QString &);
  bind::member_function<QMenu, QAction *, const QIcon &, const QString &, &QMenu::addSection>(menu, "addSection").create();
  // QAction * insertMenu(QAction *, QMenu *);
  bind::member_function<QMenu, QAction *, QAction *, QMenu *, &QMenu::insertMenu>(menu, "insertMenu").create();
  // QAction * insertSeparator(QAction *);
  bind::member_function<QMenu, QAction *, QAction *, &QMenu::insertSeparator>(menu, "insertSeparator").create();
  // QAction * insertSection(QAction *, const QString &);
  bind::member_function<QMenu, QAction *, QAction *, const QString &, &QMenu::insertSection>(menu, "insertSection").create();
  // QAction * insertSection(QAction *, const QIcon &, const QString &);
  bind::member_function<QMenu, QAction *, QAction *, const QIcon &, const QString &, &QMenu::insertSection>(menu, "insertSection").create();
  // bool isEmpty() const;
  bind::member_function<QMenu, bool, &QMenu::isEmpty>(menu, "isEmpty").create();
  // void clear();
  bind::void_member_function<QMenu, &QMenu::clear>(menu, "clear").create();
  // void setTearOffEnabled(bool);
  bind::void_member_function<QMenu, bool, &QMenu::setTearOffEnabled>(menu, "setTearOffEnabled").create();
  // bool isTearOffEnabled() const;
  bind::member_function<QMenu, bool, &QMenu::isTearOffEnabled>(menu, "isTearOffEnabled").create();
  // bool isTearOffMenuVisible() const;
  bind::member_function<QMenu, bool, &QMenu::isTearOffMenuVisible>(menu, "isTearOffMenuVisible").create();
  // void showTearOffMenu();
  bind::void_member_function<QMenu, &QMenu::showTearOffMenu>(menu, "showTearOffMenu").create();
  // void showTearOffMenu(const QPoint &);
  bind::void_member_function<QMenu, const QPoint &, &QMenu::showTearOffMenu>(menu, "showTearOffMenu").create();
  // void hideTearOffMenu();
  bind::void_member_function<QMenu, &QMenu::hideTearOffMenu>(menu, "hideTearOffMenu").create();
  // void setDefaultAction(QAction *);
  bind::void_member_function<QMenu, QAction *, &QMenu::setDefaultAction>(menu, "setDefaultAction").create();
  // QAction * defaultAction() const;
  bind::member_function<QMenu, QAction *, &QMenu::defaultAction>(menu, "defaultAction").create();
  // void setActiveAction(QAction *);
  bind::void_member_function<QMenu, QAction *, &QMenu::setActiveAction>(menu, "setActiveAction").create();
  // QAction * activeAction() const;
  bind::member_function<QMenu, QAction *, &QMenu::activeAction>(menu, "activeAction").create();
  // void popup(const QPoint &, QAction *);
  bind::void_member_function<QMenu, const QPoint &, QAction *, &QMenu::popup>(menu, "popup")
    .apply(bind::default_arguments((QAction*)nullptr)).create();
  // QAction * exec();
  bind::member_function<QMenu, QAction *, &QMenu::exec>(menu, "exec").create();
  // QAction * exec(const QPoint &, QAction *);
  bind::member_function<QMenu, QAction *, const QPoint &, QAction *, &QMenu::exec>(menu, "exec")
    .apply(bind::default_arguments((QAction*)nullptr)).create();
  // static QAction * exec(QList<QAction *>, const QPoint &, QAction *, QWidget *);
  /// TODO: static QAction * exec(QList<QAction *>, const QPoint &, QAction *, QWidget *);
  // QSize sizeHint() const;
  bind::member_function<QMenu, QSize, &QMenu::sizeHint>(menu, "sizeHint").create();
  // QRect actionGeometry(QAction *) const;
  bind::member_function<QMenu, QRect, QAction *, &QMenu::actionGeometry>(menu, "actionGeometry").create();
  // QAction * actionAt(const QPoint &) const;
  bind::member_function<QMenu, QAction *, const QPoint &, &QMenu::actionAt>(menu, "actionAt").create();
  // QAction * menuAction() const;
  bind::member_function<QMenu, QAction *, &QMenu::menuAction>(menu, "menuAction").create();
  // QString title() const;
  bind::member_function<QMenu, QString, &QMenu::title>(menu, "title").create();
  // void setTitle(const QString &);
  bind::void_member_function<QMenu, const QString &, &QMenu::setTitle>(menu, "setTitle").create();
  // QIcon icon() const;
  bind::member_function<QMenu, QIcon, &QMenu::icon>(menu, "icon").create();
  // void setIcon(const QIcon &);
  bind::void_member_function<QMenu, const QIcon &, &QMenu::setIcon>(menu, "setIcon").create();
  // void setNoReplayFor(QWidget *);
  bind::void_member_function<QMenu, QWidget *, &QMenu::setNoReplayFor>(menu, "setNoReplayFor").create();
  // QPlatformMenu * platformMenu();
  /// TODO: QPlatformMenu * platformMenu();
  // void setPlatformMenu(QPlatformMenu *);
  /// TODO: void setPlatformMenu(QPlatformMenu *);
  // bool separatorsCollapsible() const;
  bind::member_function<QMenu, bool, &QMenu::separatorsCollapsible>(menu, "separatorsCollapsible").create();
  // void setSeparatorsCollapsible(bool);
  bind::void_member_function<QMenu, bool, &QMenu::setSeparatorsCollapsible>(menu, "setSeparatorsCollapsible").create();
  // bool toolTipsVisible() const;
  bind::member_function<QMenu, bool, &QMenu::toolTipsVisible>(menu, "toolTipsVisible").create();
  // void setToolTipsVisible(bool);
  bind::void_member_function<QMenu, bool, &QMenu::setToolTipsVisible>(menu, "setToolTipsVisible").create();
  // void aboutToShow();
  bind::signal<QMenu>(menu, "aboutToShow", "aboutToShow()");
  // void aboutToHide();
  bind::signal<QMenu>(menu, "aboutToHide", "aboutToHide()");
  // void triggered(QAction *);
  bind::signal<QMenu, QAction *>(menu, "triggered", "triggered(QAction *)");
  // void hovered(QAction *);
  bind::signal<QMenu, QAction *>(menu, "hovered", "hovered(QAction *)");

  bind::link(menu, &QMenu::staticMetaObject);
}


void register_menu_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_menu_class(ns);

  // QMenu& newMenu(QWidget*);
  bind::new_function<QMenu, QWidget*>(ns, "newMenu");
  // QMenu& newMenu(const QString&, QWidget*);
  bind::new_function<QMenu, const QString&, QWidget*>(ns, "newMenu");
}

