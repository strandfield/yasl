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

  Enum color_group = palette.Enum("ColorGroup").setId(script::Type::QPaletteColorGroup).get();

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

  Enum color_role = palette.Enum("ColorRole").setId(script::Type::QPaletteColorRole).get();

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

  Class palette = ns.Class("Palette").setId(script::Type::QPalette).get();

  register_palette_color_group_enum(palette);
  register_palette_color_role_enum(palette);
  binding::Class<QPalette> binder{ palette };

  // QPalette();
  binder.ctors().default_ctor().create();
  // QPalette(const QColor &);
  binder.ctors().ctor<const QColor &>().create();
  // QPalette(Qt::GlobalColor);
  binder.ctors().ctor<Qt::GlobalColor>().create();
  // QPalette(const QColor &, const QColor &);
  binder.ctors().ctor<const QColor &, const QColor &>().create();
  // QPalette(const QPalette &);
  binder.ctors().ctor<const QPalette &>().create();
  // ~QPalette();
  binder.add_dtor();
  // QPalette & operator=(const QPalette &);
  binder.operators().assign<const QPalette &>();
  // QPalette(QPalette &&);
  binder.ctors().ctor<QPalette &&>().create();
  // QPalette & operator=(QPalette &&);
  binder.operators().assign<QPalette &&>();
  // void swap(QPalette &);
  binder.void_fun<QPalette &, &QPalette::swap>("swap").create();
  // QPalette::ColorGroup currentColorGroup() const;
  binder.fun<QPalette::ColorGroup, &QPalette::currentColorGroup>("currentColorGroup").create();
  // void setCurrentColorGroup(QPalette::ColorGroup);
  binder.void_fun<QPalette::ColorGroup, &QPalette::setCurrentColorGroup>("setCurrentColorGroup").create();
  // const QColor & color(QPalette::ColorGroup, QPalette::ColorRole) const;
  binder.fun<const QColor &, QPalette::ColorGroup, QPalette::ColorRole, &QPalette::color>("color").create();
  // const QBrush & brush(QPalette::ColorGroup, QPalette::ColorRole) const;
  binder.fun<const QBrush &, QPalette::ColorGroup, QPalette::ColorRole, &QPalette::brush>("brush").create();
  // void setColor(QPalette::ColorGroup, QPalette::ColorRole, const QColor &);
  binder.void_fun<QPalette::ColorGroup, QPalette::ColorRole, const QColor &, &QPalette::setColor>("setColor").create();
  // void setColor(QPalette::ColorRole, const QColor &);
  binder.void_fun<QPalette::ColorRole, const QColor &, &QPalette::setColor>("setColor").create();
  // void setBrush(QPalette::ColorRole, const QBrush &);
  binder.void_fun<QPalette::ColorRole, const QBrush &, &QPalette::setBrush>("setBrush").create();
  // bool isBrushSet(QPalette::ColorGroup, QPalette::ColorRole) const;
  binder.fun<bool, QPalette::ColorGroup, QPalette::ColorRole, &QPalette::isBrushSet>("isBrushSet").create();
  // void setBrush(QPalette::ColorGroup, QPalette::ColorRole, const QBrush &);
  binder.void_fun<QPalette::ColorGroup, QPalette::ColorRole, const QBrush &, &QPalette::setBrush>("setBrush").create();
  // bool isEqual(QPalette::ColorGroup, QPalette::ColorGroup) const;
  binder.fun<bool, QPalette::ColorGroup, QPalette::ColorGroup, &QPalette::isEqual>("isEqual").create();
  // const QColor & color(QPalette::ColorRole) const;
  binder.fun<const QColor &, QPalette::ColorRole, &QPalette::color>("color").create();
  // const QBrush & brush(QPalette::ColorRole) const;
  binder.fun<const QBrush &, QPalette::ColorRole, &QPalette::brush>("brush").create();
  // const QBrush & foreground() const;
  binder.fun<const QBrush &, &QPalette::foreground>("foreground").create();
  // const QBrush & windowText() const;
  binder.fun<const QBrush &, &QPalette::windowText>("windowText").create();
  // const QBrush & button() const;
  binder.fun<const QBrush &, &QPalette::button>("button").create();
  // const QBrush & light() const;
  binder.fun<const QBrush &, &QPalette::light>("light").create();
  // const QBrush & dark() const;
  binder.fun<const QBrush &, &QPalette::dark>("dark").create();
  // const QBrush & mid() const;
  binder.fun<const QBrush &, &QPalette::mid>("mid").create();
  // const QBrush & text() const;
  binder.fun<const QBrush &, &QPalette::text>("text").create();
  // const QBrush & base() const;
  binder.fun<const QBrush &, &QPalette::base>("base").create();
  // const QBrush & alternateBase() const;
  binder.fun<const QBrush &, &QPalette::alternateBase>("alternateBase").create();
  // const QBrush & toolTipBase() const;
  binder.fun<const QBrush &, &QPalette::toolTipBase>("toolTipBase").create();
  // const QBrush & toolTipText() const;
  binder.fun<const QBrush &, &QPalette::toolTipText>("toolTipText").create();
  // const QBrush & background() const;
  binder.fun<const QBrush &, &QPalette::background>("background").create();
  // const QBrush & window() const;
  binder.fun<const QBrush &, &QPalette::window>("window").create();
  // const QBrush & midlight() const;
  binder.fun<const QBrush &, &QPalette::midlight>("midlight").create();
  // const QBrush & brightText() const;
  binder.fun<const QBrush &, &QPalette::brightText>("brightText").create();
  // const QBrush & buttonText() const;
  binder.fun<const QBrush &, &QPalette::buttonText>("buttonText").create();
  // const QBrush & shadow() const;
  binder.fun<const QBrush &, &QPalette::shadow>("shadow").create();
  // const QBrush & highlight() const;
  binder.fun<const QBrush &, &QPalette::highlight>("highlight").create();
  // const QBrush & highlightedText() const;
  binder.fun<const QBrush &, &QPalette::highlightedText>("highlightedText").create();
  // const QBrush & link() const;
  binder.fun<const QBrush &, &QPalette::link>("link").create();
  // const QBrush & linkVisited() const;
  binder.fun<const QBrush &, &QPalette::linkVisited>("linkVisited").create();
  // bool operator==(const QPalette &) const;
  binder.operators().eq<const QPalette &>();
  // bool operator!=(const QPalette &) const;
  binder.operators().neq<const QPalette &>();
  // bool isCopyOf(const QPalette &) const;
  binder.fun<bool, const QPalette &, &QPalette::isCopyOf>("isCopyOf").create();
  // qint64 cacheKey() const;
  /// TODO: qint64 cacheKey() const;
  // QPalette resolve(const QPalette &) const;
  binder.fun<QPalette, const QPalette &, &QPalette::resolve>("resolve").create();
  // uint resolve() const;
  binder.fun<uint, &QPalette::resolve>("resolve").create();
  // void resolve(uint);
  binder.void_fun<uint, &QPalette::resolve>("resolve").create();
}


void register_palette_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_palette_class(ns);
  binding::Namespace binder{ ns };

  // void swap(QPalette &, QPalette &);
  binder.void_fun<QPalette &, QPalette &, &swap>("swap").create();
  // QDataStream & operator<<(QDataStream &, const QPalette &);
  binder.operators().put_to<QDataStream &, const QPalette &>();
  // QDataStream & operator>>(QDataStream &, QPalette &);
  binder.operators().read_from<QDataStream &, QPalette &>();
  // QDebug operator<<(QDebug, const QPalette &);
  /// TODO: QDebug operator<<(QDebug, const QPalette &);
}

