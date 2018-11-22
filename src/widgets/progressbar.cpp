// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/progressbar.h"

#include "yasl/binding2/default_arguments.h"
#include "yasl/binding2/enum.h"
#include "yasl/binding2/namespace.h"
#include "yasl/binding2/newfunction.h"
#include "yasl/binding2/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/widgets/progressbar.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_progress_bar_direction_enum(script::Class progress_bar)
{
  using namespace script;

  Enum direction = progress_bar.newEnum("Direction").setId(script::Type::QProgressBarDirection).get();

  direction.addValue("TopToBottom", QProgressBar::TopToBottom);
  direction.addValue("BottomToTop", QProgressBar::BottomToTop);
}


static void register_progress_bar_class(script::Namespace ns)
{
  using namespace script;

  Class progress_bar = ns.newClass("ProgressBar").setId(script::Type::QProgressBar)
    .setBase(script::Type::QWidget).get();

  register_progress_bar_direction_enum(progress_bar);

  // QProgressBar(QWidget *);
  bind::constructor<QProgressBar, QWidget *>(progress_bar)
    .apply(bind::default_arguments((QWidget*)nullptr)).create();
  // ~QProgressBar();
  bind::destructor<QProgressBar>(progress_bar).create();
  // int minimum() const;
  bind::member_function<QProgressBar, int, &QProgressBar::minimum>(progress_bar, "minimum").create();
  // int maximum() const;
  bind::member_function<QProgressBar, int, &QProgressBar::maximum>(progress_bar, "maximum").create();
  // int value() const;
  bind::member_function<QProgressBar, int, &QProgressBar::value>(progress_bar, "value").create();
  // QString text() const;
  bind::member_function<QProgressBar, QString, &QProgressBar::text>(progress_bar, "text").create();
  // void setTextVisible(bool);
  bind::void_member_function<QProgressBar, bool, &QProgressBar::setTextVisible>(progress_bar, "setTextVisible").create();
  // bool isTextVisible() const;
  bind::member_function<QProgressBar, bool, &QProgressBar::isTextVisible>(progress_bar, "isTextVisible").create();
  // Qt::Alignment alignment() const;
  bind::member_function<QProgressBar, Qt::Alignment, &QProgressBar::alignment>(progress_bar, "alignment").create();
  // void setAlignment(Qt::Alignment);
  bind::void_member_function<QProgressBar, Qt::Alignment, &QProgressBar::setAlignment>(progress_bar, "setAlignment").create();
  // QSize sizeHint() const;
  bind::member_function<QProgressBar, QSize, &QProgressBar::sizeHint>(progress_bar, "sizeHint").create();
  // QSize minimumSizeHint() const;
  bind::member_function<QProgressBar, QSize, &QProgressBar::minimumSizeHint>(progress_bar, "minimumSizeHint").create();
  // Qt::Orientation orientation() const;
  bind::member_function<QProgressBar, Qt::Orientation, &QProgressBar::orientation>(progress_bar, "orientation").create();
  // void setInvertedAppearance(bool);
  bind::void_member_function<QProgressBar, bool, &QProgressBar::setInvertedAppearance>(progress_bar, "setInvertedAppearance").create();
  // bool invertedAppearance() const;
  bind::member_function<QProgressBar, bool, &QProgressBar::invertedAppearance>(progress_bar, "invertedAppearance").create();
  // void setTextDirection(QProgressBar::Direction);
  bind::void_member_function<QProgressBar, QProgressBar::Direction, &QProgressBar::setTextDirection>(progress_bar, "setTextDirection").create();
  // QProgressBar::Direction textDirection() const;
  bind::member_function<QProgressBar, QProgressBar::Direction, &QProgressBar::textDirection>(progress_bar, "textDirection").create();
  // void setFormat(const QString &);
  bind::void_member_function<QProgressBar, const QString &, &QProgressBar::setFormat>(progress_bar, "setFormat").create();
  // void resetFormat();
  bind::void_member_function<QProgressBar, &QProgressBar::resetFormat>(progress_bar, "resetFormat").create();
  // QString format() const;
  bind::member_function<QProgressBar, QString, &QProgressBar::format>(progress_bar, "format").create();
  // void reset();
  bind::void_member_function<QProgressBar, &QProgressBar::reset>(progress_bar, "reset").create();
  // void setRange(int, int);
  bind::void_member_function<QProgressBar, int, int, &QProgressBar::setRange>(progress_bar, "setRange").create();
  // void setMinimum(int);
  bind::void_member_function<QProgressBar, int, &QProgressBar::setMinimum>(progress_bar, "setMinimum").create();
  // void setMaximum(int);
  bind::void_member_function<QProgressBar, int, &QProgressBar::setMaximum>(progress_bar, "setMaximum").create();
  // void setValue(int);
  bind::void_member_function<QProgressBar, int, &QProgressBar::setValue>(progress_bar, "setValue").create();
  // void setOrientation(Qt::Orientation);
  bind::void_member_function<QProgressBar, Qt::Orientation, &QProgressBar::setOrientation>(progress_bar, "setOrientation").create();
  // void valueChanged(int);
  bind::signal<QProgressBar, int>(progress_bar, "valueChanged", "valueChanged(int)");

  bind::link(progress_bar, &QProgressBar::staticMetaObject);
}


void register_progressbar_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_progress_bar_class(ns);

  // QProgressBar& newProgressBar(QWidget*);
  bind::new_function<QProgressBar, QWidget*>(ns, "newProgressBar");
}

