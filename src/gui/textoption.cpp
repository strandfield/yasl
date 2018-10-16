// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/gui/textoption.h"

#include "yasl/binding/class.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"

#include "yasl/core/enums.h"
#include "yasl/gui/textoption.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_text_option_tab_type_enum(script::Class text_option)
{
  using namespace script;

  Enum tab_type = text_option.Enum("TabType").setId(script::Type::QTextOptionTabType).get();

  tab_type.addValue("LeftTab", QTextOption::LeftTab);
  tab_type.addValue("RightTab", QTextOption::RightTab);
  tab_type.addValue("CenterTab", QTextOption::CenterTab);
  tab_type.addValue("DelimiterTab", QTextOption::DelimiterTab);
}


static void register_text_option_wrap_mode_enum(script::Class text_option)
{
  using namespace script;

  Enum wrap_mode = text_option.Enum("WrapMode").setId(script::Type::QTextOptionWrapMode).get();

  wrap_mode.addValue("NoWrap", QTextOption::NoWrap);
  wrap_mode.addValue("WordWrap", QTextOption::WordWrap);
  wrap_mode.addValue("ManualWrap", QTextOption::ManualWrap);
  wrap_mode.addValue("WrapAnywhere", QTextOption::WrapAnywhere);
  wrap_mode.addValue("WrapAtWordBoundaryOrAnywhere", QTextOption::WrapAtWordBoundaryOrAnywhere);
}


static void register_text_option_flag_enum(script::Class text_option)
{
  using namespace script;

  Enum flag = text_option.Enum("Flag").setId(script::Type::QTextOptionFlag).get();

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

  Class text_option = ns.Class("TextOption").setId(script::Type::QTextOption).get();

  register_text_option_tab_type_enum(text_option);
  register_text_option_wrap_mode_enum(text_option);
  register_text_option_flag_enum(text_option);
  binding::Class<QTextOption> binder{ text_option };

  // QTextOption();
  binder.ctors().add_default();
  // QTextOption(Qt::Alignment);
  binder.ctors().ctor<Qt::Alignment>().create();
  // ~QTextOption();
  binder.add_dtor();
  // QTextOption(const QTextOption &);
  binder.ctors().ctor<const QTextOption &>().create();
  // QTextOption & operator=(const QTextOption &);
  binder.operators().assign<const QTextOption &>();
  // void setAlignment(Qt::Alignment);
  binder.void_fun<Qt::Alignment, &QTextOption::setAlignment>("setAlignment").create();
  // Qt::Alignment alignment() const;
  binder.fun<Qt::Alignment, &QTextOption::alignment>("alignment").create();
  // void setTextDirection(Qt::LayoutDirection);
  binder.void_fun<Qt::LayoutDirection, &QTextOption::setTextDirection>("setTextDirection").create();
  // Qt::LayoutDirection textDirection() const;
  binder.fun<Qt::LayoutDirection, &QTextOption::textDirection>("textDirection").create();
  // void setWrapMode(QTextOption::WrapMode);
  binder.void_fun<QTextOption::WrapMode, &QTextOption::setWrapMode>("setWrapMode").create();
  // QTextOption::WrapMode wrapMode() const;
  binder.fun<QTextOption::WrapMode, &QTextOption::wrapMode>("wrapMode").create();
  // void setFlags(QTextOption::Flags);
  binder.void_fun<QTextOption::Flags, &QTextOption::setFlags>("setFlags").create();
  // QTextOption::Flags flags() const;
  binder.fun<QTextOption::Flags, &QTextOption::flags>("flags").create();
  // void setTabStop(qreal);
  binder.void_fun<qreal, &QTextOption::setTabStop>("setTabStop").create();
  // qreal tabStop() const;
  binder.fun<qreal, &QTextOption::tabStop>("tabStop").create();
  // void setTabStopDistance(qreal);
  binder.void_fun<qreal, &QTextOption::setTabStopDistance>("setTabStopDistance").create();
  // qreal tabStopDistance() const;
  binder.fun<qreal, &QTextOption::tabStopDistance>("tabStopDistance").create();
  // void setTabArray(const QList<qreal> &);
  /// TODO: void setTabArray(const QList<qreal> &);
  // QList<qreal> tabArray() const;
  /// TODO: QList<qreal> tabArray() const;
  // void setTabs(const QList<QTextOption::Tab> &);
  /// TODO: void setTabs(const QList<QTextOption::Tab> &);
  // QList<QTextOption::Tab> tabs() const;
  /// TODO: QList<QTextOption::Tab> tabs() const;
  // void setUseDesignMetrics(bool);
  binder.void_fun<bool, &QTextOption::setUseDesignMetrics>("setUseDesignMetrics").create();
  // bool useDesignMetrics() const;
  binder.fun<bool, &QTextOption::useDesignMetrics>("useDesignMetrics").create();
}


void register_textoption_file(script::Namespace gui)
{
  using namespace script;

  Namespace ns = gui;

  register_text_option_class(ns);
  binding::Namespace binder{ ns };

  // QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QTextOption::Flags::enum_type);
  /// TODO: QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QTextOption::Flags::enum_type);
  // QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QFlags<QTextOption::Flags::enum_type>);
  /// TODO: QFlags<QTextOption::Flags::enum_type> operator|(QTextOption::Flags::enum_type, QFlags<QTextOption::Flags::enum_type>);
  // QIncompatibleFlag operator|(QTextOption::Flags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(QTextOption::Flags::enum_type, int);
}

