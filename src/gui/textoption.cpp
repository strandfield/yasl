// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/textoption.h"

#include "yasl/common/binding/class.h"
#include "yasl/common/enums.h"
#include "yasl/common/binding/namespace.h"
#include "yasl/core/flags.h"

#include "yasl/core/enums.h"
#include "yasl/gui/textoption.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_text_option_tab_type_enum(script::Class text_option)
{
  using namespace script;

  Enum tab_type = text_option.newEnum("TabType").setId(script::Type::QTextOptionTabType).get();

  tab_type.addValue("LeftTab", QTextOption::LeftTab);
  tab_type.addValue("RightTab", QTextOption::RightTab);
  tab_type.addValue("CenterTab", QTextOption::CenterTab);
  tab_type.addValue("DelimiterTab", QTextOption::DelimiterTab);
}


static void register_text_option_wrap_mode_enum(script::Class text_option)
{
  using namespace script;

  Enum wrap_mode = text_option.newEnum("WrapMode").setId(script::Type::QTextOptionWrapMode).get();

  wrap_mode.addValue("NoWrap", QTextOption::NoWrap);
  wrap_mode.addValue("WordWrap", QTextOption::WordWrap);
  wrap_mode.addValue("ManualWrap", QTextOption::ManualWrap);
  wrap_mode.addValue("WrapAnywhere", QTextOption::WrapAnywhere);
  wrap_mode.addValue("WrapAtWordBoundaryOrAnywhere", QTextOption::WrapAtWordBoundaryOrAnywhere);
}


static void register_text_option_flag_enum(script::Class text_option)
{
  using namespace script;

  Enum flag = text_option.newEnum("Flag").setId(script::Type::QTextOptionFlag).get();

  register_qflags_type<QTextOption::Flag>(text_option, "Flags", script::Type::QTextOptionFlags);
  flag.addValue("ShowTabsAndSpaces", QTextOption::ShowTabsAndSpaces);
  flag.addValue("ShowLineAndParagraphSeparators", QTextOption::ShowLineAndParagraphSeparators);
  flag.addValue("AddSpaceForLineAndParagraphSeparators", QTextOption::AddSpaceForLineAndParagraphSeparators);
  flag.addValue("SuppressColors", QTextOption::SuppressColors);
  flag.addValue("ShowDocumentTerminator", QTextOption::ShowDocumentTerminator);
  flag.addValue("IncludeTrailingSpaces", QTextOption::IncludeTrailingSpaces);
}


static void register_text_option_class(script::Namespace ns)
{
  using namespace script;

  Class text_option = ns.newClass("TextOption").setId(script::Type::QTextOption).get();

  register_text_option_tab_type_enum(text_option);
  register_text_option_wrap_mode_enum(text_option);
  register_text_option_flag_enum(text_option);

  // QTextOption();
  bind::default_constructor<QTextOption>(text_option).create();
  // QTextOption(Qt::Alignment);
  bind::constructor<QTextOption, Qt::Alignment>(text_option).create();
  // ~QTextOption();
  bind::destructor<QTextOption>(text_option).create();
  // QTextOption(const QTextOption &);
  bind::constructor<QTextOption, const QTextOption &>(text_option).create();
  // QTextOption & operator=(const QTextOption &);
  bind::memop_assign<QTextOption, const QTextOption &>(text_option);
  // void setAlignment(Qt::Alignment);
  bind::void_member_function<QTextOption, Qt::Alignment, &QTextOption::setAlignment>(text_option, "setAlignment").create();
  // Qt::Alignment alignment() const;
  bind::member_function<QTextOption, Qt::Alignment, &QTextOption::alignment>(text_option, "alignment").create();
  // void setTextDirection(Qt::LayoutDirection);
  bind::void_member_function<QTextOption, Qt::LayoutDirection, &QTextOption::setTextDirection>(text_option, "setTextDirection").create();
  // Qt::LayoutDirection textDirection() const;
  bind::member_function<QTextOption, Qt::LayoutDirection, &QTextOption::textDirection>(text_option, "textDirection").create();
  // void setWrapMode(QTextOption::WrapMode);
  bind::void_member_function<QTextOption, QTextOption::WrapMode, &QTextOption::setWrapMode>(text_option, "setWrapMode").create();
  // QTextOption::WrapMode wrapMode() const;
  bind::member_function<QTextOption, QTextOption::WrapMode, &QTextOption::wrapMode>(text_option, "wrapMode").create();
  // void setFlags(QTextOption::Flags);
  bind::void_member_function<QTextOption, QTextOption::Flags, &QTextOption::setFlags>(text_option, "setFlags").create();
  // QTextOption::Flags flags() const;
  bind::member_function<QTextOption, QTextOption::Flags, &QTextOption::flags>(text_option, "flags").create();
  // void setTabStop(qreal);
  bind::void_member_function<QTextOption, qreal, &QTextOption::setTabStop>(text_option, "setTabStop").create();
  // qreal tabStop() const;
  bind::member_function<QTextOption, qreal, &QTextOption::tabStop>(text_option, "tabStop").create();
  // void setTabArray(const QList<qreal> &);
  /// TODO: void setTabArray(const QList<qreal> &);
  // QList<qreal> tabArray() const;
  /// TODO: QList<qreal> tabArray() const;
  // void setTabs(const QList<QTextOption::Tab> &);
  /// TODO: void setTabs(const QList<QTextOption::Tab> &);
  // QList<QTextOption::Tab> tabs() const;
  /// TODO: QList<QTextOption::Tab> tabs() const;
  // void setUseDesignMetrics(bool);
  bind::void_member_function<QTextOption, bool, &QTextOption::setUseDesignMetrics>(text_option, "setUseDesignMetrics").create();
  // bool useDesignMetrics() const;
  bind::member_function<QTextOption, bool, &QTextOption::useDesignMetrics>(text_option, "useDesignMetrics").create();
}


void register_textoption_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_text_option_class(ns);

  // QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QTextOption::Flags::enum_type);
  /// TODO: QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QTextOption::Flags::enum_type);
  // QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QFlags<QTextOption::Flags::enum_type>);
  /// TODO: QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QFlags<QTextOption::Flags::enum_type>);
  // QIncompatibleFlag operator|(QTextOption::Flags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QTextOption::Flags::enum_type, int);
}

