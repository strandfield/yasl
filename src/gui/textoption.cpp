// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/textoption.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"

#include "yasl/core/enums.h"
#include "yasl/core/flags.h"

#include <script/class.h>
#include <script/classbuilder.h>
#include <script/enumbuilder.h>
#include <script/namespace.h>

static void register_text_option_flag_enum(script::Class text_option)
{
  using namespace script;

  Enum flag = text_option.Enum("Flag").setId(script::Type::QTextOptionFlag).get();

  flag.addValue("AddSpaceForLineAndParagraphSeparators", QTextOption::AddSpaceForLineAndParagraphSeparators);
  flag.addValue("IncludeTrailingSpaces", QTextOption::IncludeTrailingSpaces);
  flag.addValue("ShowDocumentTerminator", QTextOption::ShowDocumentTerminator);
  flag.addValue("ShowLineAndParagraphSeparators", QTextOption::ShowLineAndParagraphSeparators);
  flag.addValue("ShowTabsAndSpaces", QTextOption::ShowTabsAndSpaces);
  flag.addValue("SuppressColors", QTextOption::SuppressColors);

  register_qflags_type<QTextOption::Flag>(text_option, "Flags", script::Type::QTextOptionFlags);
}

static void register_text_option_tab_type_enum(script::Class text_option)
{
  using namespace script;

  Enum tab_type = text_option.Enum("TabType").setId(script::Type::QTextOptionTabType).get();

  tab_type.addValue("CenterTab", QTextOption::CenterTab);
  tab_type.addValue("DelimiterTab", QTextOption::DelimiterTab);
  tab_type.addValue("LeftTab", QTextOption::LeftTab);
  tab_type.addValue("RightTab", QTextOption::RightTab);
}

static void register_text_option_wrap_mode_enum(script::Class text_option)
{
  using namespace script;

  Enum wrap_mode = text_option.Enum("WrapMode").setId(script::Type::QTextOptionWrapMode).get();

  wrap_mode.addValue("ManualWrap", QTextOption::ManualWrap);
  wrap_mode.addValue("NoWrap", QTextOption::NoWrap);
  wrap_mode.addValue("WordWrap", QTextOption::WordWrap);
  wrap_mode.addValue("WrapAnywhere", QTextOption::WrapAnywhere);
  wrap_mode.addValue("WrapAtWordBoundaryOrAnywhere", QTextOption::WrapAtWordBoundaryOrAnywhere);
}

static void register_text_option_class(script::Namespace ns)
{
  using namespace script;

  Class text_option = ns.Class("TextOption").setId(script::Type::QTextOption).get();

  register_text_option_flag_enum(text_option);
  register_text_option_tab_type_enum(text_option);
  register_text_option_wrap_mode_enum(text_option);
  binding::Class<QTextOption> binder{ text_option };

  // ~QTextOption();
  binder.add_dtor();
  // QTextOption();
  binder.ctors().add_default();
  // QTextOption(Qt::Alignment);
  binder.ctors().add<Qt::Alignment>();
  // QTextOption(const QTextOption &);
  binder.ctors().add<const QTextOption &>();
  // QTextOption & operator=(const QTextOption &);
  binder.operators().assign<const QTextOption &>();
  // void setAlignment(Qt::Alignment);
  binder.add_void_fun<Qt::Alignment, &QTextOption::setAlignment>("setAlignment");
  // Qt::Alignment alignment() const;
  binder.add_fun<Qt::Alignment, &QTextOption::alignment>("alignment");
  // void setTextDirection(Qt::LayoutDirection);
  binder.add_void_fun<Qt::LayoutDirection, &QTextOption::setTextDirection>("setTextDirection");
  // Qt::LayoutDirection textDirection() const;
  binder.add_fun<Qt::LayoutDirection, &QTextOption::textDirection>("textDirection");
  // void setWrapMode(QTextOption::WrapMode);
  binder.add_void_fun<QTextOption::WrapMode, &QTextOption::setWrapMode>("setWrapMode");
  // QTextOption::WrapMode wrapMode() const;
  binder.add_fun<QTextOption::WrapMode, &QTextOption::wrapMode>("wrapMode");
  // void setFlags(QTextOption::Flags);
  binder.add_void_fun<QTextOption::Flags, &QTextOption::setFlags>("setFlags");
  // QTextOption::Flags flags() const;
  binder.add_fun<QTextOption::Flags, &QTextOption::flags>("flags");
  // void setTabStop(qreal);
  binder.add_void_fun<qreal, &QTextOption::setTabStop>("setTabStop");
  // qreal tabStop() const;
  binder.add_fun<qreal, &QTextOption::tabStop>("tabStop");
  // void setTabStopDistance(qreal);
  binder.add_void_fun<qreal, &QTextOption::setTabStopDistance>("setTabStopDistance");
  // qreal tabStopDistance() const;
  binder.add_fun<qreal, &QTextOption::tabStopDistance>("tabStopDistance");
  // void setTabArray(const QList<qreal> &);
  binder.add_void_fun<const QList<qreal> &, &QTextOption::setTabArray>("setTabArray");
  // QList<qreal> tabArray() const;
  binder.add_fun<QList<qreal>, &QTextOption::tabArray>("tabArray");
  // void setTabs(const QList<QTextOption::Tab> &);
  binder.add_void_fun<const QList<QTextOption::Tab> &, &QTextOption::setTabs>("setTabs");
  // QList<QTextOption::Tab> tabs() const;
  binder.add_fun<QList<QTextOption::Tab>, &QTextOption::tabs>("tabs");
  // void setUseDesignMetrics(bool);
  binder.add_void_fun<bool, &QTextOption::setUseDesignMetrics>("setUseDesignMetrics");
  // bool useDesignMetrics() const;
  binder.add_fun<bool, &QTextOption::useDesignMetrics>("useDesignMetrics");
}

void register_textoption_file(script::Namespace root)
{
  using namespace script;

  register_text_option_class(root);
  binding::Namespace binder{ root };

  // QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QTextOption::Flags::enum_type);
  binder.operators().or<QFlags<QTextOption::Flags::enum_type>, QTextOption::Flags::enum_type, QTextOption::Flags::enum_type>();
  // QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QFlags<QTextOption::Flags::enum_type>);
  binder.operators().or<QFlags<QTextOption::Flags::enum_type>, QTextOption::Flags::enum_type, QFlags<QTextOption::Flags::enum_type>>();
  // QIncompatibleFlag operator|(QTextOption::Flags::enum_type, int);
  binder.operators().or<QIncompatibleFlag, QTextOption::Flags::enum_type, int>();
}

