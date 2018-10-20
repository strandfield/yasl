// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/action.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"
#include "yasl/core/listspecializations.h"
#include "yasl/utils/ref.h"

#include "yasl/core/enums.h"
#include "yasl/core/object.h"
#include "yasl/core/variant.h"
#include "yasl/gui/font.h"
#include "yasl/gui/icon.h"
#include "yasl/gui/keysequence.h"
#include "yasl/widgets/action.h"
#include "yasl/widgets/menu.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_action_menu_role_enum(script::Class action)
{
  using namespace script;

  Enum menu_role = action.Enum("MenuRole").setId(script::Type::QActionMenuRole).get();

  menu_role.addValue("NoRole", QAction::NoRole);
  menu_role.addValue("TextHeuristicRole", QAction::TextHeuristicRole);
  menu_role.addValue("ApplicationSpecificRole", QAction::ApplicationSpecificRole);
  menu_role.addValue("AboutQtRole", QAction::AboutQtRole);
  menu_role.addValue("AboutRole", QAction::AboutRole);
  menu_role.addValue("PreferencesRole", QAction::PreferencesRole);
  menu_role.addValue("QuitRole", QAction::QuitRole);
}


static void register_action_priority_enum(script::Class action)
{
  using namespace script;

  Enum priority = action.Enum("Priority").setId(script::Type::QActionPriority).get();

  priority.addValue("LowPriority", QAction::LowPriority);
  priority.addValue("NormalPriority", QAction::NormalPriority);
  priority.addValue("HighPriority", QAction::HighPriority);
}


static void register_action_action_event_enum(script::Class action)
{
  using namespace script;

  Enum action_event = action.Enum("ActionEvent").setId(script::Type::QActionActionEvent).get();

  action_event.addValue("Trigger", QAction::Trigger);
  action_event.addValue("Hover", QAction::Hover);
}


static void register_action_class(script::Namespace ns)
{
  using namespace script;

  Class action = ns.Class("Action").setId(script::Type::QAction)
    .setBase(script::Type::QObject).get();

  register_ref_specialization(action.engine(), script::Type::QAction, script::Type::QActionStar);
  register_ptr_specialization<QAction*>(action.engine()->getTemplate(Engine::PtrTemplate), script::Type::PtrQAction);
  register_list_specialization<QAction*>(action.engine(), script::Type::QListQAction);
  register_action_menu_role_enum(action);
  register_action_priority_enum(action);
  register_action_action_event_enum(action);
  binding::QClass<QAction> binder{ action, &QAction::staticMetaObject };

  // QAction(QObject *);
  binder.ctors().ctor<QObject *>()
    .addDefaultArgument(binding::default_argument(action.engine(), (QObject*)nullptr)).create();
  // QAction(const QString &, QObject *);
  binder.ctors().ctor<const QString &, QObject *>()
    .addDefaultArgument(binding::default_argument(action.engine(), (QObject*)nullptr)).create();
  // QAction(const QIcon &, const QString &, QObject *);
  binder.ctors().ctor<const QIcon &, const QString &, QObject *>()
    .addDefaultArgument(binding::default_argument(action.engine(), (QObject*)nullptr)).create();
  // ~QAction();
  binder.add_dtor();
  // void setActionGroup(QActionGroup *);
  /// TODO: void setActionGroup(QActionGroup *);
  // QActionGroup * actionGroup() const;
  /// TODO: QActionGroup * actionGroup() const;
  // void setIcon(const QIcon &);
  binder.void_fun<const QIcon &, &QAction::setIcon>("setIcon").create();
  // QIcon icon() const;
  binder.fun<QIcon, &QAction::icon>("icon").create();
  // void setText(const QString &);
  binder.void_fun<const QString &, &QAction::setText>("setText").create();
  // QString text() const;
  binder.fun<QString, &QAction::text>("text").create();
  // void setIconText(const QString &);
  binder.void_fun<const QString &, &QAction::setIconText>("setIconText").create();
  // QString iconText() const;
  binder.fun<QString, &QAction::iconText>("iconText").create();
  // void setToolTip(const QString &);
  binder.void_fun<const QString &, &QAction::setToolTip>("setToolTip").create();
  // QString toolTip() const;
  binder.fun<QString, &QAction::toolTip>("toolTip").create();
  // void setStatusTip(const QString &);
  binder.void_fun<const QString &, &QAction::setStatusTip>("setStatusTip").create();
  // QString statusTip() const;
  binder.fun<QString, &QAction::statusTip>("statusTip").create();
  // void setWhatsThis(const QString &);
  binder.void_fun<const QString &, &QAction::setWhatsThis>("setWhatsThis").create();
  // QString whatsThis() const;
  binder.fun<QString, &QAction::whatsThis>("whatsThis").create();
  // void setPriority(QAction::Priority);
  binder.void_fun<QAction::Priority, &QAction::setPriority>("setPriority").create();
  // QAction::Priority priority() const;
  binder.fun<QAction::Priority, &QAction::priority>("priority").create();
  // QMenu * menu() const;
  binder.fun<QMenu *, &QAction::menu>("menu").create();
  // void setMenu(QMenu *);
  binder.void_fun<QMenu *, &QAction::setMenu>("setMenu").create();
  // void setSeparator(bool);
  binder.void_fun<bool, &QAction::setSeparator>("setSeparator").create();
  // bool isSeparator() const;
  binder.fun<bool, &QAction::isSeparator>("isSeparator").create();
  // void setShortcut(const QKeySequence &);
  binder.void_fun<const QKeySequence &, &QAction::setShortcut>("setShortcut").create();
  // QKeySequence shortcut() const;
  binder.fun<QKeySequence, &QAction::shortcut>("shortcut").create();
  // void setShortcuts(const QList<QKeySequence> &);
  /// TODO: void setShortcuts(const QList<QKeySequence> &);
  // void setShortcuts(QKeySequence::StandardKey);
  binder.void_fun<QKeySequence::StandardKey, &QAction::setShortcuts>("setShortcuts").create();
  // QList<QKeySequence> shortcuts() const;
  /// TODO: QList<QKeySequence> shortcuts() const;
  // void setShortcutContext(Qt::ShortcutContext);
  binder.void_fun<Qt::ShortcutContext, &QAction::setShortcutContext>("setShortcutContext").create();
  // Qt::ShortcutContext shortcutContext() const;
  binder.fun<Qt::ShortcutContext, &QAction::shortcutContext>("shortcutContext").create();
  // void setAutoRepeat(bool);
  binder.void_fun<bool, &QAction::setAutoRepeat>("setAutoRepeat").create();
  // bool autoRepeat() const;
  binder.fun<bool, &QAction::autoRepeat>("autoRepeat").create();
  // void setFont(const QFont &);
  binder.void_fun<const QFont &, &QAction::setFont>("setFont").create();
  // QFont font() const;
  binder.fun<QFont, &QAction::font>("font").create();
  // void setCheckable(bool);
  binder.void_fun<bool, &QAction::setCheckable>("setCheckable").create();
  // bool isCheckable() const;
  binder.fun<bool, &QAction::isCheckable>("isCheckable").create();
  // QVariant data() const;
  binder.fun<QVariant, &QAction::data>("data").create();
  // void setData(const QVariant &);
  binder.void_fun<const QVariant &, &QAction::setData>("setData").create();
  // bool isChecked() const;
  binder.fun<bool, &QAction::isChecked>("isChecked").create();
  // bool isEnabled() const;
  binder.fun<bool, &QAction::isEnabled>("isEnabled").create();
  // bool isVisible() const;
  binder.fun<bool, &QAction::isVisible>("isVisible").create();
  // void activate(QAction::ActionEvent);
  binder.void_fun<QAction::ActionEvent, &QAction::activate>("activate").create();
  // bool showStatusText(QWidget *);
  binder.fun<bool, QWidget *, &QAction::showStatusText>("showStatusText")
    .addDefaultArgument(binding::default_argument(action.engine(), (QWidget*)nullptr)).create();
  // void setMenuRole(QAction::MenuRole);
  binder.void_fun<QAction::MenuRole, &QAction::setMenuRole>("setMenuRole").create();
  // QAction::MenuRole menuRole() const;
  binder.fun<QAction::MenuRole, &QAction::menuRole>("menuRole").create();
  // void setIconVisibleInMenu(bool);
  binder.void_fun<bool, &QAction::setIconVisibleInMenu>("setIconVisibleInMenu").create();
  // bool isIconVisibleInMenu() const;
  binder.fun<bool, &QAction::isIconVisibleInMenu>("isIconVisibleInMenu").create();
  // void setShortcutVisibleInContextMenu(bool);
  binder.void_fun<bool, &QAction::setShortcutVisibleInContextMenu>("setShortcutVisibleInContextMenu").create();
  // bool isShortcutVisibleInContextMenu() const;
  binder.fun<bool, &QAction::isShortcutVisibleInContextMenu>("isShortcutVisibleInContextMenu").create();
  // QWidget * parentWidget() const;
  binder.fun<QWidget *, &QAction::parentWidget>("parentWidget").create();
  // QList<QWidget *> associatedWidgets() const;
  /// TODO: QList<QWidget *> associatedWidgets() const;
  // QList<QGraphicsWidget *> associatedGraphicsWidgets() const;
  /// TODO: QList<QGraphicsWidget *> associatedGraphicsWidgets() const;
  // void trigger();
  binder.void_fun<&QAction::trigger>("trigger").create();
  // void hover();
  binder.void_fun<&QAction::hover>("hover").create();
  // void setChecked(bool);
  binder.void_fun<bool, &QAction::setChecked>("setChecked").create();
  // void toggle();
  binder.void_fun<&QAction::toggle>("toggle").create();
  // void setEnabled(bool);
  binder.void_fun<bool, &QAction::setEnabled>("setEnabled").create();
  // void setDisabled(bool);
  binder.void_fun<bool, &QAction::setDisabled>("setDisabled").create();
  // void setVisible(bool);
  binder.void_fun<bool, &QAction::setVisible>("setVisible").create();
  // void changed();
  binder.sigs().add("changed", "changed()");
  // void triggered(bool);
  binder.sigs().add<bool>("triggered", "triggered(bool)");
  // void hovered();
  binder.sigs().add("hovered", "hovered()");
  // void toggled(bool);
  binder.sigs().add<bool>("toggled", "toggled(bool)");

  action.engine()->registerQtType(&QAction::staticMetaObject, action.id());
}


void register_action_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_action_class(ns);
  binding::Namespace binder{ ns };

  // QDebug operator<<(QDebug, const QAction *);
  /// TODO: QDebug operator<<(QDebug, const QAction *);
  // QAction& newAction(QObject*);
  NewFunction(binder).add<QAction, QObject*>("newAction");
  // QAction& newAction(const QString&, QObject*);
  NewFunction(binder).add<QAction, const QString&, QObject*>("newAction");
  // QAction& newAction(const QIcon&, const QString&, QObject*);
  NewFunction(binder).add<QAction, const QIcon&, const QString&, QObject*>("newAction");
}

