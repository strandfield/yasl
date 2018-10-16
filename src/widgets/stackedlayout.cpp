// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/widgets/stackedlayout.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/binding/newfunction.h"
#include "yasl/binding/qclass.h"

#include "yasl/core/rect.h"
#include "yasl/core/size.h"
#include "yasl/widgets/layout.h"
#include "yasl/widgets/stackedlayout.h"
#include "yasl/widgets/widget.h"

#include <script/classbuilder.h>
#include <script/enumbuilder.h>

static void register_stacked_layout_stacking_mode_enum(script::Class stacked_layout)
{
  using namespace script;

  Enum stacking_mode = stacked_layout.Enum("StackingMode").setId(script::Type::QStackedLayoutStackingMode).get();

  stacking_mode.addValue("StackOne", QStackedLayout::StackOne);
  stacking_mode.addValue("StackAll", QStackedLayout::StackAll);
}


static void register_stacked_layout_class(script::Namespace ns)
{
  using namespace script;

  Class stacked_layout = ns.Class("StackedLayout").setId(script::Type::QStackedLayout)
    .setBase(script::Type::QLayout).get();

  register_stacked_layout_stacking_mode_enum(stacked_layout);
  binding::QClass<QStackedLayout> binder{ stacked_layout, &QStackedLayout::staticMetaObject };

  // QStackedLayout();
  binder.ctors().add_default();
  // QStackedLayout(QWidget *);
  binder.ctors().ctor<QWidget *>().create();
  // QStackedLayout(QLayout *);
  binder.ctors().ctor<QLayout *>().create();
  // ~QStackedLayout();
  binder.add_dtor();
  // int addWidget(QWidget *);
  binder.fun<int, QWidget *, &QStackedLayout::addWidget>("addWidget").create();
  // int insertWidget(int, QWidget *);
  binder.fun<int, int, QWidget *, &QStackedLayout::insertWidget>("insertWidget").create();
  // QWidget * currentWidget() const;
  binder.fun<QWidget *, &QStackedLayout::currentWidget>("currentWidget").create();
  // int currentIndex() const;
  binder.fun<int, &QStackedLayout::currentIndex>("currentIndex").create();
  // QWidget * widget(int) const;
  binder.fun<QWidget *, int, &QStackedLayout::widget>("widget").create();
  // int count() const;
  binder.fun<int, &QStackedLayout::count>("count").create();
  // QStackedLayout::StackingMode stackingMode() const;
  binder.fun<QStackedLayout::StackingMode, &QStackedLayout::stackingMode>("stackingMode").create();
  // void setStackingMode(QStackedLayout::StackingMode);
  binder.void_fun<QStackedLayout::StackingMode, &QStackedLayout::setStackingMode>("setStackingMode").create();
  // void addItem(QLayoutItem *);
  /// TODO: void addItem(QLayoutItem *);
  // QSize sizeHint() const;
  binder.fun<QSize, &QStackedLayout::sizeHint>("sizeHint").create();
  // QSize minimumSize() const;
  binder.fun<QSize, &QStackedLayout::minimumSize>("minimumSize").create();
  // QLayoutItem * itemAt(int) const;
  /// TODO: QLayoutItem * itemAt(int) const;
  // QLayoutItem * takeAt(int);
  /// TODO: QLayoutItem * takeAt(int);
  // void setGeometry(const QRect &);
  binder.void_fun<const QRect &, &QStackedLayout::setGeometry>("setGeometry").create();
  // bool hasHeightForWidth() const;
  binder.fun<bool, &QStackedLayout::hasHeightForWidth>("hasHeightForWidth").create();
  // int heightForWidth(int) const;
  binder.fun<int, int, &QStackedLayout::heightForWidth>("heightForWidth").create();
  // void widgetRemoved(int);
  binder.void_fun<int, &QStackedLayout::widgetRemoved>("widgetRemoved").create();
  // void currentChanged(int);
  binder.void_fun<int, &QStackedLayout::currentChanged>("currentChanged").create();
  // void setCurrentIndex(int);
  binder.void_fun<int, &QStackedLayout::setCurrentIndex>("setCurrentIndex").create();
  // void setCurrentWidget(QWidget *);
  binder.void_fun<QWidget *, &QStackedLayout::setCurrentWidget>("setCurrentWidget").create();

  stacked_layout.engine()->registerQtType(&QStackedLayout::staticMetaObject, stacked_layout.id());
}


void register_stackedlayout_file(script::Namespace widgets)
{
  using namespace script;

  Namespace ns = widgets;

  register_stacked_layout_class(ns);
  binding::Namespace binder{ ns };

  // QStackedLayout& newStackedLayout();
  NewFunction(binder).add<QStackedLayout>("newStackedLayout");
  // QStackedLayout& newStackedLayout(QWidget*);
  NewFunction(binder).add<QStackedLayout, QWidget*>("newStackedLayout");
  // QStackedLayout& newStackedLayout(QLayout*);
  NewFunction(binder).add<QStackedLayout, QLayout*>("newStackedLayout");
}

