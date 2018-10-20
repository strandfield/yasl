// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/menu.h"

#include "yasl/binding/default_arguments.h"
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
  binder.ctors().ctor<QWidget *>()
    .addDefaultArgument(binding::default_argument(menu.engine(), (QWidget*)nullptr)).create();
  // QMenu(const QString &, QWidget *);
  binder.ctors().ctor<const QString &, QWidget *>()
    .addDefaultArgument(binding::default_argument(menu.engine(), (QWidget*)nullptr)).create();
  // ~QMenu();
  binder.add_dtor();
  // QAction * addAction(const QString &);
  binder.fun<QAction *, const QString &, &QMenu::addAction>("addAction").create();
  // QAction * addAction(const QIcon &, const QString &);
  binder.fun<QAction *, const QIcon &, const QString &, &QMenu::addAction>("addAction").create();
  // QAction * addAction(const QString &, const QObject *, const char *, const QKeySequence &);
  /// TODO: QAction * addAction(const QString &, const QObject *, const char *, const QKeySequence &);
  // QAction * addAction(const QIcon &, const QString &, const QObject *, const char *, const QKeySequence &);
  /// TODO: QAction * addAction(const QIcon &, const QString &, const QObject *, const char *, const QKeySequence &);
  // QAction * addMenu(QMenu *);
  binder.fun<QAction *, QMenu *, &QMenu::addMenu>("addMenu").create();
  // QMenu * addMenu(const QString &);
  binder.fun<QMenu *, const QString &, &QMenu::addMenu>("addMenu").create();
  // QMenu * addMenu(const QIcon &, const QString &);
  binder.fun<QMenu *, const QIcon &, const QString &, &QMenu::addMenu>("addMenu").create();
  // QAction * addSeparator();
  binder.fun<QAction *, &QMenu::addSeparator>("addSeparator").create();
  // QAction * addSection(const QString &);
  binder.fun<QAction *, const QString &, &QMenu::addSection>("addSection").create();
  // QAction * addSection(const QIcon &, const QString &);
  binder.fun<QAction *, const QIcon &, const QString &, &QMenu::addSection>("addSection").create();
  // QAction * insertMenu(QAction *, QMenu *);
  binder.fun<QAction *, QAction *, QMenu *, &QMenu::insertMenu>("insertMenu").create();
  // QAction * insertSeparator(QAction *);
  binder.fun<QAction *, QAction *, &QMenu::insertSeparator>("insertSeparator").create();
  // QAction * insertSection(QAction *, const QString &);
  binder.fun<QAction *, QAction *, const QString &, &QMenu::insertSection>("insertSection").create();
  // QAction * insertSection(QAction *, const QIcon &, const QString &);
  binder.fun<QAction *, QAction *, const QIcon &, const QString &, &QMenu::insertSection>("insertSection").create();
  // bool isEmpty() const;
  binder.fun<bool, &QMenu::isEmpty>("isEmpty").create();
  // void clear();
  binder.void_fun<&QMenu::clear>("clear").create();
  // void setTearOffEnabled(bool);
  binder.void_fun<bool, &QMenu::setTearOffEnabled>("setTearOffEnabled").create();
  // bool isTearOffEnabled() const;
  binder.fun<bool, &QMenu::isTearOffEnabled>("isTearOffEnabled").create();
  // bool isTearOffMenuVisible() const;
  binder.fun<bool, &QMenu::isTearOffMenuVisible>("isTearOffMenuVisible").create();
  // void showTearOffMenu();
  binder.void_fun<&QMenu::showTearOffMenu>("showTearOffMenu").create();
  // void showTearOffMenu(const QPoint &);
  binder.void_fun<const QPoint &, &QMenu::showTearOffMenu>("showTearOffMenu").create();
  // void hideTearOffMenu();
  binder.void_fun<&QMenu::hideTearOffMenu>("hideTearOffMenu").create();
  // void setDefaultAction(QAction *);
  binder.void_fun<QAction *, &QMenu::setDefaultAction>("setDefaultAction").create();
  // QAction * defaultAction() const;
  binder.fun<QAction *, &QMenu::defaultAction>("defaultAction").create();
  // void setActiveAction(QAction *);
  binder.void_fun<QAction *, &QMenu::setActiveAction>("setActiveAction").create();
  // QAction * activeAction() const;
  binder.fun<QAction *, &QMenu::activeAction>("activeAction").create();
  // void popup(const QPoint &, QAction *);
  binder.void_fun<const QPoint &, QAction *, &QMenu::popup>("popup")
    .addDefaultArgument(binding::default_argument(menu.engine(), (QAction*)nullptr)).create();
  // QAction * exec();
  binder.fun<QAction *, &QMenu::exec>("exec").create();
  // QAction * exec(const QPoint &, QAction *);
  binder.fun<QAction *, const QPoint &, QAction *, &QMenu::exec>("exec")
    .addDefaultArgument(binding::default_argument(menu.engine(), (QAction*)nullptr)).create();
  // static QAction * exec(QList<QAction *>, const QPoint &, QAction *, QWidget *);
  /// TODO: static QAction * exec(QList<QAction *>, const QPoint &, QAction *, QWidget *);
  // QSize sizeHint() const;
  binder.fun<QSize, &QMenu::sizeHint>("sizeHint").create();
  // QRect actionGeometry(QAction *) const;
  binder.fun<QRect, QAction *, &QMenu::actionGeometry>("actionGeometry").create();
  // QAction * actionAt(const QPoint &) const;
  binder.fun<QAction *, const QPoint &, &QMenu::actionAt>("actionAt").create();
  // QAction * menuAction() const;
  binder.fun<QAction *, &QMenu::menuAction>("menuAction").create();
  // QString title() const;
  binder.fun<QString, &QMenu::title>("title").create();
  // void setTitle(const QString &);
  binder.void_fun<const QString &, &QMenu::setTitle>("setTitle").create();
  // QIcon icon() const;
  binder.fun<QIcon, &QMenu::icon>("icon").create();
  // void setIcon(const QIcon &);
  binder.void_fun<const QIcon &, &QMenu::setIcon>("setIcon").create();
  // void setNoReplayFor(QWidget *);
  binder.void_fun<QWidget *, &QMenu::setNoReplayFor>("setNoReplayFor").create();
  // QPlatformMenu * platformMenu();
  /// TODO: QPlatformMenu * platformMenu();
  // void setPlatformMenu(QPlatformMenu *);
  /// TODO: void setPlatformMenu(QPlatformMenu *);
  // bool separatorsCollapsible() const;
  binder.fun<bool, &QMenu::separatorsCollapsible>("separatorsCollapsible").create();
  // void setSeparatorsCollapsible(bool);
  binder.void_fun<bool, &QMenu::setSeparatorsCollapsible>("setSeparatorsCollapsible").create();
  // bool toolTipsVisible() const;
  binder.fun<bool, &QMenu::toolTipsVisible>("toolTipsVisible").create();
  // void setToolTipsVisible(bool);
  binder.void_fun<bool, &QMenu::setToolTipsVisible>("setToolTipsVisible").create();
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

