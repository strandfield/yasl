// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/action.h"

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
  binder.ctors().add<QObject *>();
  // QAction(const QString &, QObject *);
  binder.ctors().add<const QString &, QObject *>();
  // QAction(const QIcon &, const QString &, QObject *);
  binder.ctors().add<const QIcon &, const QString &, QObject *>();
  // ~QAction();
  binder.add_dtor();
  // void setActionGroup(QActionGroup *);
  /// TODO: void setActionGroup(QActionGroup *);
  // QActionGroup * actionGroup() const;
  /// TODO: QActionGroup * actionGroup() const;
  // void setIcon(const QIcon &);
  binder.add_void_fun<const QIcon &, &QAction::setIcon>("setIcon");
  // QIcon icon() const;
  binder.add_fun<QIcon, &QAction::icon>("icon");
  // void setText(const QString &);
  binder.add_void_fun<const QString &, &QAction::setText>("setText");
  // QString text() const;
  binder.add_fun<QString, &QAction::text>("text");
  // void setIconText(const QString &);
  binder.add_void_fun<const QString &, &QAction::setIconText>("setIconText");
  // QString iconText() const;
  binder.add_fun<QString, &QAction::iconText>("iconText");
  // void setToolTip(const QString &);
  binder.add_void_fun<const QString &, &QAction::setToolTip>("setToolTip");
  // QString toolTip() const;
  binder.add_fun<QString, &QAction::toolTip>("toolTip");
  // void setStatusTip(const QString &);
  binder.add_void_fun<const QString &, &QAction::setStatusTip>("setStatusTip");
  // QString statusTip() const;
  binder.add_fun<QString, &QAction::statusTip>("statusTip");
  // void setWhatsThis(const QString &);
  binder.add_void_fun<const QString &, &QAction::setWhatsThis>("setWhatsThis");
  // QString whatsThis() const;
  binder.add_fun<QString, &QAction::whatsThis>("whatsThis");
  // void setPriority(QAction::Priority);
  binder.add_void_fun<QAction::Priority, &QAction::setPriority>("setPriority");
  // QAction::Priority priority() const;
  binder.add_fun<QAction::Priority, &QAction::priority>("priority");
  // QMenu * menu() const;
  binder.add_fun<QMenu *, &QAction::menu>("menu");
  // void setMenu(QMenu *);
  binder.add_void_fun<QMenu *, &QAction::setMenu>("setMenu");
  // void setSeparator(bool);
  binder.add_void_fun<bool, &QAction::setSeparator>("setSeparator");
  // bool isSeparator() const;
  binder.add_fun<bool, &QAction::isSeparator>("isSeparator");
  // void setShortcut(const QKeySequence &);
  binder.add_void_fun<const QKeySequence &, &QAction::setShortcut>("setShortcut");
  // QKeySequence shortcut() const;
  binder.add_fun<QKeySequence, &QAction::shortcut>("shortcut");
  // void setShortcuts(const QList<QKeySequence> &);
  /// TODO: void setShortcuts(const QList<QKeySequence> &);
  // void setShortcuts(QKeySequence::StandardKey);
  binder.add_void_fun<QKeySequence::StandardKey, &QAction::setShortcuts>("setShortcuts");
  // QList<QKeySequence> shortcuts() const;
  /// TODO: QList<QKeySequence> shortcuts() const;
  // void setShortcutContext(Qt::ShortcutContext);
  binder.add_void_fun<Qt::ShortcutContext, &QAction::setShortcutContext>("setShortcutContext");
  // Qt::ShortcutContext shortcutContext() const;
  binder.add_fun<Qt::ShortcutContext, &QAction::shortcutContext>("shortcutContext");
  // void setAutoRepeat(bool);
  binder.add_void_fun<bool, &QAction::setAutoRepeat>("setAutoRepeat");
  // bool autoRepeat() const;
  binder.add_fun<bool, &QAction::autoRepeat>("autoRepeat");
  // void setFont(const QFont &);
  binder.add_void_fun<const QFont &, &QAction::setFont>("setFont");
  // QFont font() const;
  binder.add_fun<QFont, &QAction::font>("font");
  // void setCheckable(bool);
  binder.add_void_fun<bool, &QAction::setCheckable>("setCheckable");
  // bool isCheckable() const;
  binder.add_fun<bool, &QAction::isCheckable>("isCheckable");
  // QVariant data() const;
  binder.add_fun<QVariant, &QAction::data>("data");
  // void setData(const QVariant &);
  binder.add_void_fun<const QVariant &, &QAction::setData>("setData");
  // bool isChecked() const;
  binder.add_fun<bool, &QAction::isChecked>("isChecked");
  // bool isEnabled() const;
  binder.add_fun<bool, &QAction::isEnabled>("isEnabled");
  // bool isVisible() const;
  binder.add_fun<bool, &QAction::isVisible>("isVisible");
  // void activate(QAction::ActionEvent);
  binder.add_void_fun<QAction::ActionEvent, &QAction::activate>("activate");
  // bool showStatusText(QWidget *);
  binder.add_fun<bool, QWidget *, &QAction::showStatusText>("showStatusText");
  // void setMenuRole(QAction::MenuRole);
  binder.add_void_fun<QAction::MenuRole, &QAction::setMenuRole>("setMenuRole");
  // QAction::MenuRole menuRole() const;
  binder.add_fun<QAction::MenuRole, &QAction::menuRole>("menuRole");
  // void setIconVisibleInMenu(bool);
  binder.add_void_fun<bool, &QAction::setIconVisibleInMenu>("setIconVisibleInMenu");
  // bool isIconVisibleInMenu() const;
  binder.add_fun<bool, &QAction::isIconVisibleInMenu>("isIconVisibleInMenu");
  // void setShortcutVisibleInContextMenu(bool);
  binder.add_void_fun<bool, &QAction::setShortcutVisibleInContextMenu>("setShortcutVisibleInContextMenu");
  // bool isShortcutVisibleInContextMenu() const;
  binder.add_fun<bool, &QAction::isShortcutVisibleInContextMenu>("isShortcutVisibleInContextMenu");
  // QWidget * parentWidget() const;
  binder.add_fun<QWidget *, &QAction::parentWidget>("parentWidget");
  // QList<QWidget *> associatedWidgets() const;
  /// TODO: QList<QWidget *> associatedWidgets() const;
  // QList<QGraphicsWidget *> associatedGraphicsWidgets() const;
  /// TODO: QList<QGraphicsWidget *> associatedGraphicsWidgets() const;
  // void trigger();
  binder.add_void_fun<&QAction::trigger>("trigger");
  // void hover();
  binder.add_void_fun<&QAction::hover>("hover");
  // void setChecked(bool);
  binder.add_void_fun<bool, &QAction::setChecked>("setChecked");
  // void toggle();
  binder.add_void_fun<&QAction::toggle>("toggle");
  // void setEnabled(bool);
  binder.add_void_fun<bool, &QAction::setEnabled>("setEnabled");
  // void setDisabled(bool);
  binder.add_void_fun<bool, &QAction::setDisabled>("setDisabled");
  // void setVisible(bool);
  binder.add_void_fun<bool, &QAction::setVisible>("setVisible");
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

