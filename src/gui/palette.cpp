// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/palette.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/datastream.h"
#include "yasl/core/enums.h"
#include "yasl/gui/brush.h"
#include "yasl/gui/color.h"
#include "yasl/gui/palette.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_palette_color_group_enum(script::Class palette)
{
  using namespace script;

  Enum color_group = palette.newEnum("ColorGroup").setId(script::Type::QPaletteColorGroup).get();

  color_group.addValue("Active", QPalette::Active);
  color_group.addValue("Disabled", QPalette::Disabled);
  color_group.addValue("Inactive", QPalette::Inactive);
  color_group.addValue("NColorGroups", QPalette::NColorGroups);
  color_group.addValue("Current", QPalette::Current);
  color_group.addValue("All", QPalette::All);
  color_group.addValue("Normal", QPalette::Normal);
}


static void register_palette_color_role_enum(script::Class palette)
{
  using namespace script;

  Enum color_role = palette.newEnum("ColorRole").setId(script::Type::QPaletteColorRole).get();

  color_role.addValue("WindowText", QPalette::WindowText);
  color_role.addValue("Button", QPalette::Button);
  color_role.addValue("Light", QPalette::Light);
  color_role.addValue("Midlight", QPalette::Midlight);
  color_role.addValue("Dark", QPalette::Dark);
  color_role.addValue("Mid", QPalette::Mid);
  color_role.addValue("Text", QPalette::Text);
  color_role.addValue("BrightText", QPalette::BrightText);
  color_role.addValue("ButtonText", QPalette::ButtonText);
  color_role.addValue("Base", QPalette::Base);
  color_role.addValue("Window", QPalette::Window);
  color_role.addValue("Shadow", QPalette::Shadow);
  color_role.addValue("Highlight", QPalette::Highlight);
  color_role.addValue("HighlightedText", QPalette::HighlightedText);
  color_role.addValue("Link", QPalette::Link);
  color_role.addValue("LinkVisited", QPalette::LinkVisited);
  color_role.addValue("AlternateBase", QPalette::AlternateBase);
  color_role.addValue("NoRole", QPalette::NoRole);
  color_role.addValue("ToolTipBase", QPalette::ToolTipBase);
  color_role.addValue("ToolTipText", QPalette::ToolTipText);
  color_role.addValue("NColorRoles", QPalette::NColorRoles);
  color_role.addValue("Foreground", QPalette::Foreground);
  color_role.addValue("Background", QPalette::Background);
}


static void register_palette_class(script::Namespace ns)
{
  using namespace script;

  Class palette = ns.newClass("Palette").setId(script::Type::QPalette).get();

  register_palette_color_group_enum(palette);
  register_palette_color_role_enum(palette);

  // QPalette();
  bind::default_constructor<QPalette>(palette).create();
  // QPalette(const QColor &);
  bind::constructor<QPalette, const QColor &>(palette).create();
  // QPalette(Qt::GlobalColor);
  bind::constructor<QPalette, Qt::GlobalColor>(palette).create();
  // QPalette(const QColor &, const QColor &);
  bind::constructor<QPalette, const QColor &, const QColor &>(palette).create();
  // QPalette(const QPalette &);
  bind::constructor<QPalette, const QPalette &>(palette).create();
  // ~QPalette();
  bind::destructor<QPalette>(palette).create();
  // QPalette & operator=(const QPalette &);
  bind::memop_assign<QPalette, const QPalette &>(palette);
  // QPalette(QPalette &&);
  bind::constructor<QPalette, QPalette &&>(palette).create();
  // QPalette & operator=(QPalette &&);
  bind::memop_assign<QPalette, QPalette &&>(palette);
  // void swap(QPalette &);
  bind::void_member_function<QPalette, QPalette &, &QPalette::swap>(palette, "swap").create();
  // QPalette::ColorGroup currentColorGroup() const;
  bind::member_function<QPalette, QPalette::ColorGroup, &QPalette::currentColorGroup>(palette, "currentColorGroup").create();
  // void setCurrentColorGroup(QPalette::ColorGroup);
  bind::void_member_function<QPalette, QPalette::ColorGroup, &QPalette::setCurrentColorGroup>(palette, "setCurrentColorGroup").create();
  // const QColor & color(QPalette::ColorGroup, QPalette::ColorRole) const;
  bind::member_function<QPalette, const QColor &, QPalette::ColorGroup, QPalette::ColorRole, &QPalette::color>(palette, "color").create();
  // const QBrush & brush(QPalette::ColorGroup, QPalette::ColorRole) const;
  bind::member_function<QPalette, const QBrush &, QPalette::ColorGroup, QPalette::ColorRole, &QPalette::brush>(palette, "brush").create();
  // void setColor(QPalette::ColorGroup, QPalette::ColorRole, const QColor &);
  bind::void_member_function<QPalette, QPalette::ColorGroup, QPalette::ColorRole, const QColor &, &QPalette::setColor>(palette, "setColor").create();
  // void setColor(QPalette::ColorRole, const QColor &);
  bind::void_member_function<QPalette, QPalette::ColorRole, const QColor &, &QPalette::setColor>(palette, "setColor").create();
  // void setBrush(QPalette::ColorRole, const QBrush &);
  bind::void_member_function<QPalette, QPalette::ColorRole, const QBrush &, &QPalette::setBrush>(palette, "setBrush").create();
  // bool isBrushSet(QPalette::ColorGroup, QPalette::ColorRole) const;
  bind::member_function<QPalette, bool, QPalette::ColorGroup, QPalette::ColorRole, &QPalette::isBrushSet>(palette, "isBrushSet").create();
  // void setBrush(QPalette::ColorGroup, QPalette::ColorRole, const QBrush &);
  bind::void_member_function<QPalette, QPalette::ColorGroup, QPalette::ColorRole, const QBrush &, &QPalette::setBrush>(palette, "setBrush").create();
  // bool isEqual(QPalette::ColorGroup, QPalette::ColorGroup) const;
  bind::member_function<QPalette, bool, QPalette::ColorGroup, QPalette::ColorGroup, &QPalette::isEqual>(palette, "isEqual").create();
  // const QColor & color(QPalette::ColorRole) const;
  bind::member_function<QPalette, const QColor &, QPalette::ColorRole, &QPalette::color>(palette, "color").create();
  // const QBrush & brush(QPalette::ColorRole) const;
  bind::member_function<QPalette, const QBrush &, QPalette::ColorRole, &QPalette::brush>(palette, "brush").create();
  // const QBrush & foreground() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::foreground>(palette, "foreground").create();
  // const QBrush & windowText() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::windowText>(palette, "windowText").create();
  // const QBrush & button() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::button>(palette, "button").create();
  // const QBrush & light() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::light>(palette, "light").create();
  // const QBrush & dark() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::dark>(palette, "dark").create();
  // const QBrush & mid() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::mid>(palette, "mid").create();
  // const QBrush & text() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::text>(palette, "text").create();
  // const QBrush & base() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::base>(palette, "base").create();
  // const QBrush & alternateBase() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::alternateBase>(palette, "alternateBase").create();
  // const QBrush & toolTipBase() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::toolTipBase>(palette, "toolTipBase").create();
  // const QBrush & toolTipText() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::toolTipText>(palette, "toolTipText").create();
  // const QBrush & background() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::background>(palette, "background").create();
  // const QBrush & window() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::window>(palette, "window").create();
  // const QBrush & midlight() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::midlight>(palette, "midlight").create();
  // const QBrush & brightText() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::brightText>(palette, "brightText").create();
  // const QBrush & buttonText() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::buttonText>(palette, "buttonText").create();
  // const QBrush & shadow() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::shadow>(palette, "shadow").create();
  // const QBrush & highlight() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::highlight>(palette, "highlight").create();
  // const QBrush & highlightedText() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::highlightedText>(palette, "highlightedText").create();
  // const QBrush & link() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::link>(palette, "link").create();
  // const QBrush & linkVisited() const;
  bind::member_function<QPalette, const QBrush &, &QPalette::linkVisited>(palette, "linkVisited").create();
  // bool operator==(const QPalette &) const;
  bind::memop_eq<QPalette, const QPalette &>(palette);
  // bool operator!=(const QPalette &) const;
  bind::memop_neq<QPalette, const QPalette &>(palette);
  // bool isCopyOf(const QPalette &) const;
  bind::member_function<QPalette, bool, const QPalette &, &QPalette::isCopyOf>(palette, "isCopyOf").create();
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // QPalette resolve(const QPalette &) const;
  bind::member_function<QPalette, QPalette, const QPalette &, &QPalette::resolve>(palette, "resolve").create();
  // uint resolve() const;
  bind::member_function<QPalette, uint, &QPalette::resolve>(palette, "resolve").create();
  // void resolve(uint);
  bind::void_member_function<QPalette, uint, &QPalette::resolve>(palette, "resolve").create();
}


void register_palette_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_palette_class(ns);

  // void swap(QPalette &, QPalette &);
  bind::void_function<QPalette &, QPalette &, &swap>(ns, "swap").create();
  // QDataStream & operator<<(QDataStream &, const QPalette &);
  bind::op_put_to<QDataStream &, const QPalette &>(ns);
  // QDataStream & operator>>(QDataStream &, QPalette &);
  bind::op_read_from<QDataStream &, QPalette &>(ns);
  // QDebug operator<<(QDebug, const QPalette &);
  /// TODO: QDebug operator<<(QDebug, const QPalette &);
}

