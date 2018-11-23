// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/action.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"
#include "yasl/binding/ref.h"
#include "yasl/core/listspecializations.h"

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

  Enum menu_role = action.newEnum("MenuRole").setId(script::Type::QActionMenuRole).get();

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

  Enum priority = action.newEnum("Priority").setId(script::Type::QActionPriority).get();

  priority.addValue("LowPriority", QAction::LowPriority);
  priority.addValue("NormalPriority", QAction::NormalPriority);
  priority.addValue("HighPriority", QAction::HighPriority);
}


static void register_action_action_event_enum(script::Class action)
{
  using namespace script;

  Enum action_event = action.newEnum("ActionEvent").setId(script::Type::QActionActionEvent).get();

  action_event.addValue("Trigger", QAction::Trigger);
  action_event.addValue("Hover", QAction::Hover);
}


static void register_action_class(script::Namespace ns)
{
  using namespace script;

  Class action = ns.newClass("Action").setId(script::Type::QAction)
    .setBase(script::Type::QObject).get();

  bind::register_ref_specialization(action.engine(), script::Type::QAction, script::Type::QActionStar);
  bind::register_proxy_specialization<QAction*>(action.engine()->getTemplate(Engine::ProxyTemplate), script::Type::ProxyQAction);
  register_list_specialization<QAction*>(action.engine(), script::Type::QListQAction);
  register_action_menu_role_enum(action);
  register_action_priority_enum(action);
  register_action_action_event_enum(action);

  // QAction(QObject *);
  bind::constructor<QAction, QObject *>(action)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // QAction(const QString &, QObject *);
  bind::constructor<QAction, const QString &, QObject *>(action)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // QAction(const QIcon &, const QString &, QObject *);
  bind::constructor<QAction, const QIcon &, const QString &, QObject *>(action)
    .apply(bind::default_arguments((QObject*)nullptr)).create();
  // ~QAction();
  bind::destructor<QAction>(action).create();
  // void setActionGroup(QActionGroup *);
  /// TODO: void setActionGroup(QActionGroup *);
  // QActionGroup * actionGroup() const;
  /// TODO: QActionGroup * actionGroup() const;
  // void setIcon(const QIcon &);
  bind::void_member_function<QAction, const QIcon &, &QAction::setIcon>(action, "setIcon").create();
  // QIcon icon() const;
  bind::member_function<QAction, QIcon, &QAction::icon>(action, "icon").create();
  // void setText(const QString &);
  bind::void_member_function<QAction, const QString &, &QAction::setText>(action, "setText").create();
  // QString text() const;
  bind::member_function<QAction, QString, &QAction::text>(action, "text").create();
  // void setIconText(const QString &);
  bind::void_member_function<QAction, const QString &, &QAction::setIconText>(action, "setIconText").create();
  // QString iconText() const;
  bind::member_function<QAction, QString, &QAction::iconText>(action, "iconText").create();
  // void setToolTip(const QString &);
  bind::void_member_function<QAction, const QString &, &QAction::setToolTip>(action, "setToolTip").create();
  // QString toolTip() const;
  bind::member_function<QAction, QString, &QAction::toolTip>(action, "toolTip").create();
  // void setStatusTip(const QString &);
  bind::void_member_function<QAction, const QString &, &QAction::setStatusTip>(action, "setStatusTip").create();
  // QString statusTip() const;
  bind::member_function<QAction, QString, &QAction::statusTip>(action, "statusTip").create();
  // void setWhatsThis(const QString &);
  bind::void_member_function<QAction, const QString &, &QAction::setWhatsThis>(action, "setWhatsThis").create();
  // QString whatsThis() const;
  bind::member_function<QAction, QString, &QAction::whatsThis>(action, "whatsThis").create();
  // void setPriority(QAction::Priority);
  bind::void_member_function<QAction, QAction::Priority, &QAction::setPriority>(action, "setPriority").create();
  // QAction::Priority priority() const;
  bind::member_function<QAction, QAction::Priority, &QAction::priority>(action, "priority").create();
  // QMenu * menu() const;
  bind::member_function<QAction, QMenu *, &QAction::menu>(action, "menu").create();
  // void setMenu(QMenu *);
  bind::void_member_function<QAction, QMenu *, &QAction::setMenu>(action, "setMenu").create();
  // void setSeparator(bool);
  bind::void_member_function<QAction, bool, &QAction::setSeparator>(action, "setSeparator").create();
  // bool isSeparator() const;
  bind::member_function<QAction, bool, &QAction::isSeparator>(action, "isSeparator").create();
  // void setShortcut(const QKeySequence &);
  bind::void_member_function<QAction, const QKeySequence &, &QAction::setShortcut>(action, "setShortcut").create();
  // QKeySequence shortcut() const;
  bind::member_function<QAction, QKeySequence, &QAction::shortcut>(action, "shortcut").create();
  // void setShortcuts(const QList<QKeySequence> &);
  /// TODO: void setShortcuts(const QList<QKeySequence> &);
  // void setShortcuts(QKeySequence::StandardKey);
  bind::void_member_function<QAction, QKeySequence::StandardKey, &QAction::setShortcuts>(action, "setShortcuts").create();
  // QList<QKeySequence> shortcuts() const;
  /// TODO: QList<QKeySequence> shortcuts() const;
  // void setShortcutContext(Qt::ShortcutContext);
  bind::void_member_function<QAction, Qt::ShortcutContext, &QAction::setShortcutContext>(action, "setShortcutContext").create();
  // Qt::ShortcutContext shortcutContext() const;
  bind::member_function<QAction, Qt::ShortcutContext, &QAction::shortcutContext>(action, "shortcutContext").create();
  // void setAutoRepeat(bool);
  bind::void_member_function<QAction, bool, &QAction::setAutoRepeat>(action, "setAutoRepeat").create();
  // bool autoRepeat() const;
  bind::member_function<QAction, bool, &QAction::autoRepeat>(action, "autoRepeat").create();
  // void setFont(const QFont &);
  bind::void_member_function<QAction, const QFont &, &QAction::setFont>(action, "setFont").create();
  // QFont font() const;
  bind::member_function<QAction, QFont, &QAction::font>(action, "font").create();
  // void setCheckable(bool);
  bind::void_member_function<QAction, bool, &QAction::setCheckable>(action, "setCheckable").create();
  // bool isCheckable() const;
  bind::member_function<QAction, bool, &QAction::isCheckable>(action, "isCheckable").create();
  // QVariant data() const;
  bind::member_function<QAction, QVariant, &QAction::data>(action, "data").create();
  // void setData(const QVariant &);
  bind::void_member_function<QAction, const QVariant &, &QAction::setData>(action, "setData").create();
  // bool isChecked() const;
  bind::member_function<QAction, bool, &QAction::isChecked>(action, "isChecked").create();
  // bool isEnabled() const;
  bind::member_function<QAction, bool, &QAction::isEnabled>(action, "isEnabled").create();
  // bool isVisible() const;
  bind::member_function<QAction, bool, &QAction::isVisible>(action, "isVisible").create();
  // void activate(QAction::ActionEvent);
  bind::void_member_function<QAction, QAction::ActionEvent, &QAction::activate>(action, "activate").create();
  // bool showStatusText(QWidget *);
  bind::member_function<QAction, bool, QWidget *, &QAction::showStatusText>(action, "showStatusText")
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // void setMenuRole(QAction::MenuRole);
  bind::void_member_function<QAction, QAction::MenuRole, &QAction::setMenuRole>(action, "setMenuRole").create();
  // QAction::MenuRole menuRole() const;
  bind::member_function<QAction, QAction::MenuRole, &QAction::menuRole>(action, "menuRole").create();
  // void setIconVisibleInMenu(bool);
  bind::void_member_function<QAction, bool, &QAction::setIconVisibleInMenu>(action, "setIconVisibleInMenu").create();
  // bool isIconVisibleInMenu() const;
  bind::member_function<QAction, bool, &QAction::isIconVisibleInMenu>(action, "isIconVisibleInMenu").create();
  // QWidget * parentWidget() const;
  bind::member_function<QAction, QWidget *, &QAction::parentWidget>(action, "parentWidget").create();
  // QList<QWidget *> associatedWidgets() const;
  /// TODO: QList<QWidget *> associatedWidgets() const;
  // QList<QGraphicsWidget *> associatedGraphicsWidgets() const;
  /// TODO: QList<QGraphicsWidget *> associatedGraphicsWidgets() const;
  // void trigger();
  bind::void_member_function<QAction, &QAction::trigger>(action, "trigger").create();
  // void hover();
  bind::void_member_function<QAction, &QAction::hover>(action, "hover").create();
  // void setChecked(bool);
  bind::void_member_function<QAction, bool, &QAction::setChecked>(action, "setChecked").create();
  // void toggle();
  bind::void_member_function<QAction, &QAction::toggle>(action, "toggle").create();
  // void setEnabled(bool);
  bind::void_member_function<QAction, bool, &QAction::setEnabled>(action, "setEnabled").create();
  // void setDisabled(bool);
  bind::void_member_function<QAction, bool, &QAction::setDisabled>(action, "setDisabled").create();
  // void setVisible(bool);
  bind::void_member_function<QAction, bool, &QAction::setVisible>(action, "setVisible").create();
  // void changed();
  bind::signal<QAction>(action, "changed", "changed()");
  // void triggered(bool);
  bind::signal<QAction, bool>(action, "triggered", "triggered(bool)");
  // void hovered();
  bind::signal<QAction>(action, "hovered", "hovered()");
  // void toggled(bool);
  bind::signal<QAction, bool>(action, "toggled", "toggled(bool)");

  bind::link(action, &QAction::staticMetaObject);
}


void register_action_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_action_class(ns);

  // QDebug operator<<(QDebug, const QAction *);
  /// TODO: QDebug operator<<(QDebug, const QAction *);
  // QAction& newAction(QObject*);
  bind::new_function<QAction, QObject*>(ns, "newAction");
  // QAction& newAction(const QString&, QObject*);
  bind::new_function<QAction, const QString&, QObject*>(ns, "newAction");
  // QAction& newAction(const QIcon&, const QString&, QObject*);
  bind::new_function<QAction, const QIcon&, const QString&, QObject*>(ns, "newAction");
}

