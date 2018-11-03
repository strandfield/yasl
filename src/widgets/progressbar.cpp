// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/progressbar.h"

#include "yasl/binding/default_arguments.h"
#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/enums.h"
#include "yasl/core/size.h"
#include "yasl/widgets/progressbar.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_progress_bar_direction_enum(script::Class progress_bar)
{
  using namespace script;

  Enum direction = progress_bar.Enum("Direction").setId(script::Type::QProgressBarDirection).get();

  direction.addValue("TopToBottom", QProgressBar::TopToBottom);
  direction.addValue("BottomToTop", QProgressBar::BottomToTop);
}


static void register_progress_bar_class(script::Namespace ns)
{
  using namespace script;

  Class progress_bar = ns.Class("ProgressBar").setId(script::Type::QProgressBar)
    .setBase(script::Type::QWidget).get();

  register_progress_bar_direction_enum(progress_bar);
  binding::ClassBinder<QProgressBar> binder{ progress_bar, &QProgressBar::staticMetaObject };

  // QProgressBar(QWidget *);
  binder.ctor<QWidget *>()
    .apply(binding::default_arguments((QWidget*)nullptr)).create();
  // ~QProgressBar();
  binder.dtor().create();
  // int minimum() const;
  binder.fun<int, &QProgressBar::minimum>("minimum").create();
  // int maximum() const;
  binder.fun<int, &QProgressBar::maximum>("maximum").create();
  // int value() const;
  binder.fun<int, &QProgressBar::value>("value").create();
  // QString text() const;
  binder.fun<QString, &QProgressBar::text>("text").create();
  // void setTextVisible(bool);
  binder.void_fun<bool, &QProgressBar::setTextVisible>("setTextVisible").create();
  // bool isTextVisible() const;
  binder.fun<bool, &QProgressBar::isTextVisible>("isTextVisible").create();
  // Qt::Alignment alignment() const;
  binder.fun<Qt::Alignment, &QProgressBar::alignment>("alignment").create();
  // void setAlignment(Qt::Alignment);
  binder.void_fun<Qt::Alignment, &QProgressBar::setAlignment>("setAlignment").create();
  // QSize sizeHint() const;
  binder.fun<QSize, &QProgressBar::sizeHint>("sizeHint").create();
  // QSize minimumSizeHint() const;
  binder.fun<QSize, &QProgressBar::minimumSizeHint>("minimumSizeHint").create();
  // Qt::Orientation orientation() const;
  binder.fun<Qt::Orientation, &QProgressBar::orientation>("orientation").create();
  // void setInvertedAppearance(bool);
  binder.void_fun<bool, &QProgressBar::setInvertedAppearance>("setInvertedAppearance").create();
  // bool invertedAppearance() const;
  binder.fun<bool, &QProgressBar::invertedAppearance>("invertedAppearance").create();
  // void setTextDirection(QProgressBar::Direction);
  binder.void_fun<QProgressBar::Direction, &QProgressBar::setTextDirection>("setTextDirection").create();
  // QProgressBar::Direction textDirection() const;
  binder.fun<QProgressBar::Direction, &QProgressBar::textDirection>("textDirection").create();
  // void setFormat(const QString &);
  binder.void_fun<const QString &, &QProgressBar::setFormat>("setFormat").create();
  // void resetFormat();
  binder.void_fun<&QProgressBar::resetFormat>("resetFormat").create();
  // QString format() const;
  binder.fun<QString, &QProgressBar::format>("format").create();
  // void reset();
  binder.void_fun<&QProgressBar::reset>("reset").create();
  // void setRange(int, int);
  binder.void_fun<int, int, &QProgressBar::setRange>("setRange").create();
  // void setMinimum(int);
  binder.void_fun<int, &QProgressBar::setMinimum>("setMinimum").create();
  // void setMaximum(int);
  binder.void_fun<int, &QProgressBar::setMaximum>("setMaximum").create();
  // void setValue(int);
  binder.void_fun<int, &QProgressBar::setValue>("setValue").create();
  // void setOrientation(Qt::Orientation);
  binder.void_fun<Qt::Orientation, &QProgressBar::setOrientation>("setOrientation").create();
  // void valueChanged(int);
  binder.sigs().add<int>("valueChanged", "valueChanged(int)");

  progress_bar.engine()->registerQtType(&QProgressBar::staticMetaObject, progress_bar.id());
}


void register_progressbar_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_progress_bar_class(ns);
  binding::Namespace binder{ ns };

  // QProgressBar& newProgressBar(QWidget*);
  NewFunction(binder).add<QProgressBar, QWidget*>("newProgressBar");
}

