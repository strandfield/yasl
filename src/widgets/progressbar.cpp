// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/progressbar.h"

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
  binding::QClass<QProgressBar> binder{ progress_bar, &QProgressBar::staticMetaObject };

  // QProgressBar(QWidget *);
  binder.ctors().add<QWidget *>();
  // ~QProgressBar();
  binder.add_dtor();
  // int minimum() const;
  binder.add_fun<int, &QProgressBar::minimum>("minimum");
  // int maximum() const;
  binder.add_fun<int, &QProgressBar::maximum>("maximum");
  // int value() const;
  binder.add_fun<int, &QProgressBar::value>("value");
  // QString text() const;
  binder.add_fun<QString, &QProgressBar::text>("text");
  // void setTextVisible(bool);
  binder.add_void_fun<bool, &QProgressBar::setTextVisible>("setTextVisible");
  // bool isTextVisible() const;
  binder.add_fun<bool, &QProgressBar::isTextVisible>("isTextVisible");
  // Qt::Alignment alignment() const;
  binder.add_fun<Qt::Alignment, &QProgressBar::alignment>("alignment");
  // void setAlignment(Qt::Alignment);
  binder.add_void_fun<Qt::Alignment, &QProgressBar::setAlignment>("setAlignment");
  // QSize sizeHint() const;
  binder.add_fun<QSize, &QProgressBar::sizeHint>("sizeHint");
  // QSize minimumSizeHint() const;
  binder.add_fun<QSize, &QProgressBar::minimumSizeHint>("minimumSizeHint");
  // Qt::Orientation orientation() const;
  binder.add_fun<Qt::Orientation, &QProgressBar::orientation>("orientation");
  // void setInvertedAppearance(bool);
  binder.add_void_fun<bool, &QProgressBar::setInvertedAppearance>("setInvertedAppearance");
  // bool invertedAppearance() const;
  binder.add_fun<bool, &QProgressBar::invertedAppearance>("invertedAppearance");
  // void setTextDirection(QProgressBar::Direction);
  binder.add_void_fun<QProgressBar::Direction, &QProgressBar::setTextDirection>("setTextDirection");
  // QProgressBar::Direction textDirection() const;
  binder.add_fun<QProgressBar::Direction, &QProgressBar::textDirection>("textDirection");
  // void setFormat(const QString &);
  binder.add_void_fun<const QString &, &QProgressBar::setFormat>("setFormat");
  // void resetFormat();
  binder.add_void_fun<&QProgressBar::resetFormat>("resetFormat");
  // QString format() const;
  binder.add_fun<QString, &QProgressBar::format>("format");
  // void reset();
  binder.add_void_fun<&QProgressBar::reset>("reset");
  // void setRange(int, int);
  binder.add_void_fun<int, int, &QProgressBar::setRange>("setRange");
  // void setMinimum(int);
  binder.add_void_fun<int, &QProgressBar::setMinimum>("setMinimum");
  // void setMaximum(int);
  binder.add_void_fun<int, &QProgressBar::setMaximum>("setMaximum");
  // void setValue(int);
  binder.add_void_fun<int, &QProgressBar::setValue>("setValue");
  // void setOrientation(Qt::Orientation);
  binder.add_void_fun<Qt::Orientation, &QProgressBar::setOrientation>("setOrientation");
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

