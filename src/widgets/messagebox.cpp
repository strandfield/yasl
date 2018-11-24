// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/messagebox.h"

#include "yasl/common/binding/default_arguments.h"
#include "yasl/common/enums.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/common/binding/qclass.h"
#include "yasl/core/flags.h"

#include "yasl/core/enums.h"
#include "yasl/core/object.h"
#include "yasl/gui/pixmap.h"
#include "yasl/widgets/messagebox.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_message_box_icon_enum(script::Class message_box)
{
  using namespace script;

  Enum icon = message_box.newEnum("Icon").setId(script::Type::QMessageBoxIcon).get();

  icon.addValue("NoIcon", QMessageBox::NoIcon);
  icon.addValue("Information", QMessageBox::Information);
  icon.addValue("Warning", QMessageBox::Warning);
  icon.addValue("Critical", QMessageBox::Critical);
  icon.addValue("Question", QMessageBox::Question);
}


static void register_message_box_button_role_enum(script::Class message_box)
{
  using namespace script;

  Enum button_role = message_box.newEnum("ButtonRole").setId(script::Type::QMessageBoxButtonRole).get();

  button_role.addValue("InvalidRole", QMessageBox::InvalidRole);
  button_role.addValue("AcceptRole", QMessageBox::AcceptRole);
  button_role.addValue("RejectRole", QMessageBox::RejectRole);
  button_role.addValue("DestructiveRole", QMessageBox::DestructiveRole);
  button_role.addValue("ActionRole", QMessageBox::ActionRole);
  button_role.addValue("HelpRole", QMessageBox::HelpRole);
  button_role.addValue("YesRole", QMessageBox::YesRole);
  button_role.addValue("NoRole", QMessageBox::NoRole);
  button_role.addValue("ResetRole", QMessageBox::ResetRole);
  button_role.addValue("ApplyRole", QMessageBox::ApplyRole);
  button_role.addValue("NRoles", QMessageBox::NRoles);
}


static void register_message_box_standard_button_enum(script::Class message_box)
{
  using namespace script;

  Enum standard_button = message_box.newEnum("StandardButton").setId(script::Type::QMessageBoxStandardButton).get();

  register_qflags_type<QMessageBox::StandardButton>(message_box, "StandardButtons", script::Type::QMessageBoxStandardButtons);
  standard_button.addValue("NoButton", QMessageBox::NoButton);
  standard_button.addValue("Ok", QMessageBox::Ok);
  standard_button.addValue("Save", QMessageBox::Save);
  standard_button.addValue("SaveAll", QMessageBox::SaveAll);
  standard_button.addValue("Open", QMessageBox::Open);
  standard_button.addValue("Yes", QMessageBox::Yes);
  standard_button.addValue("YesToAll", QMessageBox::YesToAll);
  standard_button.addValue("No", QMessageBox::No);
  standard_button.addValue("NoToAll", QMessageBox::NoToAll);
  standard_button.addValue("Abort", QMessageBox::Abort);
  standard_button.addValue("Retry", QMessageBox::Retry);
  standard_button.addValue("Ignore", QMessageBox::Ignore);
  standard_button.addValue("Close", QMessageBox::Close);
  standard_button.addValue("Cancel", QMessageBox::Cancel);
  standard_button.addValue("Discard", QMessageBox::Discard);
  standard_button.addValue("Help", QMessageBox::Help);
  standard_button.addValue("Apply", QMessageBox::Apply);
  standard_button.addValue("Reset", QMessageBox::Reset);
  standard_button.addValue("RestoreDefaults", QMessageBox::RestoreDefaults);
  standard_button.addValue("FirstButton", QMessageBox::FirstButton);
  standard_button.addValue("LastButton", QMessageBox::LastButton);
  standard_button.addValue("YesAll", QMessageBox::YesAll);
  standard_button.addValue("NoAll", QMessageBox::NoAll);
  standard_button.addValue("Default", QMessageBox::Default);
  standard_button.addValue("Escape", QMessageBox::Escape);
  standard_button.addValue("FlagMask", QMessageBox::FlagMask);
  standard_button.addValue("ButtonMask", QMessageBox::ButtonMask);
}


static void register_message_box_class(script::Namespace ns)
{
  using namespace script;

  Class message_box = ns.newClass("MessageBox").setId(script::Type::QMessageBox)
    .setBase(script::Type::QDialog).get();

  register_message_box_icon_enum(message_box);
  register_message_box_button_role_enum(message_box);
  register_message_box_standard_button_enum(message_box);

  // QMessageBox(QWidget *);
  bind::constructor<QMessageBox, QWidget *>(message_box)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // QMessageBox(QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *, Qt::WindowFlags);
  /// TODO: QMessageBox(QMessageBox::Icon, const QString &, const QString &, QMessageBox::StandardButtons, QWidget *, Qt::WindowFlags);
  // ~QMessageBox();
  bind::destructor<QMessageBox>(message_box).create();
  // void addButton(QAbstractButton *, QMessageBox::ButtonRole);
  /// TODO: void addButton(QAbstractButton *, QMessageBox::ButtonRole);
  // QPushButton * addButton(const QString &, QMessageBox::ButtonRole);
  /// TODO: QPushButton * addButton(const QString &, QMessageBox::ButtonRole);
  // QPushButton * addButton(QMessageBox::StandardButton);
  /// TODO: QPushButton * addButton(QMessageBox::StandardButton);
  // void removeButton(QAbstractButton *);
  /// TODO: void removeButton(QAbstractButton *);
  // void open(QObject *, const char *);
  /// TODO: void open(QObject *, const char *);
  // QList<QAbstractButton *> buttons() const;
  /// TODO: QList<QAbstractButton *> buttons() const;
  // QMessageBox::ButtonRole buttonRole(QAbstractButton *) const;
  /// TODO: QMessageBox::ButtonRole buttonRole(QAbstractButton *) const;
  // void setStandardButtons(QMessageBox::StandardButtons);
  bind::void_member_function<QMessageBox, QMessageBox::StandardButtons, &QMessageBox::setStandardButtons>(message_box, "setStandardButtons").create();
  // QMessageBox::StandardButtons standardButtons() const;
  bind::member_function<QMessageBox, QMessageBox::StandardButtons, &QMessageBox::standardButtons>(message_box, "standardButtons").create();
  // QMessageBox::StandardButton standardButton(QAbstractButton *) const;
  /// TODO: QMessageBox::StandardButton standardButton(QAbstractButton *) const;
  // QAbstractButton * button(QMessageBox::StandardButton) const;
  /// TODO: QAbstractButton * button(QMessageBox::StandardButton) const;
  // QPushButton * defaultButton() const;
  /// TODO: QPushButton * defaultButton() const;
  // void setDefaultButton(QPushButton *);
  /// TODO: void setDefaultButton(QPushButton *);
  // void setDefaultButton(QMessageBox::StandardButton);
  bind::void_member_function<QMessageBox, QMessageBox::StandardButton, &QMessageBox::setDefaultButton>(message_box, "setDefaultButton").create();
  // QAbstractButton * escapeButton() const;
  /// TODO: QAbstractButton * escapeButton() const;
  // void setEscapeButton(QAbstractButton *);
  /// TODO: void setEscapeButton(QAbstractButton *);
  // void setEscapeButton(QMessageBox::StandardButton);
  bind::void_member_function<QMessageBox, QMessageBox::StandardButton, &QMessageBox::setEscapeButton>(message_box, "setEscapeButton").create();
  // QAbstractButton * clickedButton() const;
  /// TODO: QAbstractButton * clickedButton() const;
  // QString text() const;
  bind::member_function<QMessageBox, QString, &QMessageBox::text>(message_box, "text").create();
  // void setText(const QString &);
  bind::void_member_function<QMessageBox, const QString &, &QMessageBox::setText>(message_box, "setText").create();
  // QMessageBox::Icon icon() const;
  bind::member_function<QMessageBox, QMessageBox::Icon, &QMessageBox::icon>(message_box, "icon").create();
  // void setIcon(QMessageBox::Icon);
  bind::void_member_function<QMessageBox, QMessageBox::Icon, &QMessageBox::setIcon>(message_box, "setIcon").create();
  // QPixmap iconPixmap() const;
  bind::member_function<QMessageBox, QPixmap, &QMessageBox::iconPixmap>(message_box, "iconPixmap").create();
  // void setIconPixmap(const QPixmap &);
  bind::void_member_function<QMessageBox, const QPixmap &, &QMessageBox::setIconPixmap>(message_box, "setIconPixmap").create();
  // Qt::TextFormat textFormat() const;
  bind::member_function<QMessageBox, Qt::TextFormat, &QMessageBox::textFormat>(message_box, "textFormat").create();
  // void setTextFormat(Qt::TextFormat);
  bind::void_member_function<QMessageBox, Qt::TextFormat, &QMessageBox::setTextFormat>(message_box, "setTextFormat").create();
  // void setTextInteractionFlags(Qt::TextInteractionFlags);
  /// TODO: void setTextInteractionFlags(Qt::TextInteractionFlags);
  // Qt::TextInteractionFlags textInteractionFlags() const;
  /// TODO: Qt::TextInteractionFlags textInteractionFlags() const;
  // void setCheckBox(QCheckBox *);
  /// TODO: void setCheckBox(QCheckBox *);
  // QCheckBox * checkBox() const;
  /// TODO: QCheckBox * checkBox() const;
  // static QMessageBox::StandardButton information(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton);
  bind::static_member_function<QMessageBox, QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton, &QMessageBox::information>(message_box, "information").create();
  // static QMessageBox::StandardButton question(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton);
  bind::static_member_function<QMessageBox, QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton, &QMessageBox::question>(message_box, "question").create();
  // static QMessageBox::StandardButton warning(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton);
  bind::static_member_function<QMessageBox, QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton, &QMessageBox::warning>(message_box, "warning").create();
  // static QMessageBox::StandardButton critical(QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton);
  bind::static_member_function<QMessageBox, QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButtons, QMessageBox::StandardButton, &QMessageBox::critical>(message_box, "critical").create();
  // static void about(QWidget *, const QString &, const QString &);
  bind::static_void_member_function<QMessageBox, QWidget *, const QString &, const QString &, &QMessageBox::about>(message_box, "about").create();
  // static void aboutQt(QWidget *, const QString &);
  bind::static_void_member_function<QMessageBox, QWidget *, const QString &, &QMessageBox::aboutQt>(message_box, "aboutQt").create();
  // QMessageBox(const QString &, const QString &, QMessageBox::Icon, int, int, int, QWidget *, Qt::WindowFlags);
  /// TODO: QMessageBox(const QString &, const QString &, QMessageBox::Icon, int, int, int, QWidget *, Qt::WindowFlags);
  // static QMessageBox::StandardButton information(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton);
  bind::static_member_function<QMessageBox, QMessageBox::StandardButton, QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton, &QMessageBox::information>(message_box, "information").create();
  // static int question(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton);
  bind::static_member_function<QMessageBox, int, QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton, &QMessageBox::question>(message_box, "question").create();
  // static int warning(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton);
  bind::static_member_function<QMessageBox, int, QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton, &QMessageBox::warning>(message_box, "warning").create();
  // static int critical(QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton);
  bind::static_member_function<QMessageBox, int, QWidget *, const QString &, const QString &, QMessageBox::StandardButton, QMessageBox::StandardButton, &QMessageBox::critical>(message_box, "critical").create();
  // QString buttonText(int) const;
  bind::member_function<QMessageBox, QString, int, &QMessageBox::buttonText>(message_box, "buttonText").create();
  // void setButtonText(int, const QString &);
  bind::void_member_function<QMessageBox, int, const QString &, &QMessageBox::setButtonText>(message_box, "setButtonText").create();
  // QString informativeText() const;
  bind::member_function<QMessageBox, QString, &QMessageBox::informativeText>(message_box, "informativeText").create();
  // void setInformativeText(const QString &);
  bind::void_member_function<QMessageBox, const QString &, &QMessageBox::setInformativeText>(message_box, "setInformativeText").create();
  // QString detailedText() const;
  bind::member_function<QMessageBox, QString, &QMessageBox::detailedText>(message_box, "detailedText").create();
  // void setDetailedText(const QString &);
  bind::void_member_function<QMessageBox, const QString &, &QMessageBox::setDetailedText>(message_box, "setDetailedText").create();
  // void setWindowTitle(const QString &);
  bind::void_member_function<QMessageBox, const QString &, &QMessageBox::setWindowTitle>(message_box, "setWindowTitle").create();
  // void setWindowModality(Qt::WindowModality);
  bind::void_member_function<QMessageBox, Qt::WindowModality, &QMessageBox::setWindowModality>(message_box, "setWindowModality").create();
  // static QPixmap standardIcon(QMessageBox::Icon);
  bind::static_member_function<QMessageBox, QPixmap, QMessageBox::Icon, &QMessageBox::standardIcon>(message_box, "standardIcon").create();
  // void buttonClicked(QAbstractButton *);
  /// TODO: void buttonClicked(QAbstractButton *);

  bind::link(message_box, &QMessageBox::staticMetaObject);
}


void register_messagebox_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_message_box_class(ns);

  // QFlags<QMessageBox::StandardButtons::enum_type> operator|(QMessageBox::StandardButtons::enum_type, QMessageBox::StandardButtons::enum_type);
  /// TODO: QFlags<QMessageBox::StandardButtons::enum_type> operator|(QMessageBox::StandardButtons::enum_type, QMessageBox::StandardButtons::enum_type);
  // QFlags<QMessageBox::StandardButtons::enum_type> operator|(QMessageBox::StandardButtons::enum_type, QFlags<QMessageBox::StandardButtons::enum_type>);
  /// TODO: QFlags<QMessageBox::StandardButtons::enum_type> operator|(QMessageBox::StandardButtons::enum_type, QFlags<QMessageBox::StandardButtons::enum_type>);
  // QIncompatibleFlag operator|(QMessageBox::StandardButtons::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QMessageBox::StandardButtons::enum_type, int);
}

